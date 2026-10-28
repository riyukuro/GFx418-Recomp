// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware (YUV->RGB
// converters, MPEG-2 video decode kernels and the CRI support layer), written from the executable. The CRI library was
// built with VS2008 SP1 and can only be functional under our toolset; every function here is a behaviour-equivalent
// transcription of the decompile.
// MS2-UNIT: sfr_cri_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140054170-0x140066180 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/cri/cri_vendor_shim.h"
extern "C" const char* _DAT_143c494f0;
extern "C" cri_code* DAT_143e64b00;
extern "C" cri_code* DAT_143e64b08;
extern "C" cri_code* DAT_143e64b10;
extern "C" cri_code* DAT_143e64b18;
extern "C" cri_code* DAT_143e64b28;
extern "C" cri_code* DAT_143e64b30;
extern "C" cri_code* DAT_143e64b38;
extern "C" cri_code* DAT_143e64b40;
extern "C" cri_code* DAT_143e64b48;
extern "C" cri_code* DAT_143e64b50;
extern "C" cri_code* DAT_143e64b58;
extern "C" cri_code* DAT_143e64b68;
extern "C" cri_code* DAT_143e64b70;
extern "C" cri_code* DAT_143e64b78;
extern "C" cri_code* DAT_143e64b80;
extern "C" cri_code* DAT_143e64b90;
extern "C" cri_code* DAT_143e64b98;
extern "C" cri_code* DAT_143e64ba0;
extern "C" cri_code* DAT_143e64ba8;
extern "C" cri_u1* PTR_FUN_143a4a0d8;
extern "C" cri_u1* PTR_LAB_1431bab50[];
extern "C" cri_u1* PTR_LAB_1431bab60[];
extern "C" cri_u1* PTR_s_This_CFT_function_doesn_t_suppor_143a4a0c0;
extern "C" float* DAT_143d4ab80;
void FUN_1400662f0(char *ctx);
extern "C" int DAT_1431ba950;
extern "C" int DAT_1431ba990;
extern "C" unsigned char DAT_1431baa10;
extern "C" int DAT_1431baa20;
extern "C" int DAT_1431baa28;
extern "C" unsigned char DAT_1431baa30;
extern "C" unsigned char DAT_1431baa31;
extern "C" unsigned char DAT_1431baa32;
extern "C" unsigned char DAT_1431baa33;
extern "C" unsigned char DAT_1431baaf0;
extern "C" unsigned char DAT_1431baaf1;
extern "C" unsigned char DAT_1431baaf2;
extern "C" unsigned char DAT_1431baaf3;
extern "C" unsigned char DAT_1431bab30;
extern "C" unsigned char DAT_1431bab40;
extern "C" int DAT_1431bac00;
extern "C" int DAT_1431bac90;
extern "C" int DAT_1431bac98;
extern "C" int DAT_1431bacb8;
extern "C" int DAT_1431bace8;
extern "C" int DAT_1431bad00;
extern "C" int DAT_1431bad40;
extern "C" int DAT_1431bad90;
extern "C" int DAT_1431bada0;
extern "C" int DAT_1431bae28;
extern "C" int DAT_1431bae40;
extern "C" int DAT_1431baf40;
extern "C" int DAT_1431baf70;
extern "C" int DAT_1431bafa0;
extern "C" int DAT_1431bb320;
extern "C" int DAT_1431bb6b0;
extern "C" int DAT_1431bba40;
extern "C" unsigned char DAT_1431bba50;
extern "C" int DAT_1431bba60;
extern "C" int DAT_1431bbbd8;
extern "C" int DAT_1431bbbf8;
extern "C" int DAT_1431bbc18;
extern "C" int DAT_1431bbc38;
extern "C" int DAT_1431bbc58;
extern "C" int DAT_1431bbc78;
extern "C" int DAT_1431bbc90;
extern "C" int DAT_1431bbcd0;
extern "C" int DAT_143a488c0;
extern "C" int DAT_143a4a0c8;
extern "C" int DAT_143a4a0cc;
extern "C" int DAT_143a4a0d0;
extern "C" int DAT_143a4a5e8;
extern "C" int DAT_143badb84;
extern "C" int DAT_143badb88;
extern "C" int DAT_143badbbc;
extern "C" int DAT_143badbdc;
extern "C" int DAT_143badc00;
extern "C" int DAT_143badf80;
extern "C" int DAT_143c49100;
extern "C" int DAT_143c494e8;
extern "C" int DAT_143c494f8;
extern "C" int DAT_143c49500;
extern "C" int DAT_143d49580;
extern "C" int DAT_143d49680;
extern "C" int DAT_143d49780;
extern "C" int DAT_143d49880;
extern "C" unsigned char DAT_143d4997c;
extern "C" unsigned char DAT_143d4997d;
extern "C" unsigned char DAT_143d4997e;
extern "C" unsigned char DAT_143d4997f;
extern "C" int DAT_143d49980;
extern "C" int DAT_143d49d80;
extern "C" int DAT_143d49f00;
extern "C" int DAT_143d49f80;
extern "C" int DAT_143d49fb0;
extern "C" int DAT_143d4a080;
extern "C" int DAT_143d4a0c0;
extern "C" int DAT_143d4a0e0;
extern "C" int DAT_143d4a100;
extern "C" int DAT_143d4a130;
extern "C" int DAT_143d4a200;
extern "C" int DAT_143d4a204;
extern "C" int DAT_143d4a240;
extern "C" int DAT_143d4a248;
extern "C" int DAT_143d4a2c0;
extern "C" int DAT_143d4a2e0;
extern "C" int DAT_143d4a300;
extern "C" int DAT_143d4a320;
extern "C" int DAT_143d4a340;
extern "C" unsigned char DAT_143d4a3bc;
extern "C" unsigned char DAT_143d4a3bd;
extern "C" unsigned char DAT_143d4a3be;
extern "C" unsigned char DAT_143d4a3bf;
extern "C" int DAT_143d4a3c0;
extern "C" int DAT_143d4a3c4;
extern "C" int DAT_143d4a400;
extern "C" unsigned char DAT_143d4a47c;
extern "C" unsigned char DAT_143d4a47d;
extern "C" unsigned char DAT_143d4a47e;
extern "C" unsigned char DAT_143d4a47f;
extern "C" int DAT_143d4a480;
extern "C" int DAT_143d4a580;
extern "C" int DAT_143d4a680;
extern "C" int DAT_143d4a700;
extern "C" int DAT_143d4a780;
extern "C" unsigned char DAT_143d4a87c;
extern "C" unsigned char DAT_143d4a87d;
extern "C" unsigned char DAT_143d4a87e;
extern "C" unsigned char DAT_143d4a87f;
extern "C" int DAT_143d4a880;
extern "C" int DAT_143d4a8a4;
extern "C" int DAT_143d4a8c0;
extern "C" int DAT_143d4a8e0;
extern "C" int DAT_143d4aa80;
extern "C" int DAT_143d4aab0;
extern "C" int DAT_143d4ab90;
extern "C" int DAT_143d4abf8;
extern "C" int DAT_143d4adf8;
extern "C" unsigned char DAT_143d74a80;
extern "C" int DAT_143d74a84;
extern "C" int DAT_143db4a84;
extern "C" unsigned char DAT_143db4ac0;
extern "C" int DAT_143db4ac1;
extern "C" unsigned char DAT_143dc4b00;
extern "C" int DAT_143dc4b02;
extern "C" unsigned char DAT_143e44b00;
extern "C" int DAT_143e64b88;
extern "C" int DAT_143e64bc0;
extern "C" unsigned char DAT_143e64be0;
extern "C" unsigned char DAT_143e64be1;
extern "C" unsigned char DAT_143e64c00;
extern "C" int DAT_143e64c01;
extern "C" unsigned char DAT_143e65400;
extern "C" unsigned char DAT_143e65401;
extern "C" int DAT_143e65801;
extern "C" unsigned char DAT_143e65820;
extern "C" unsigned char DAT_143e65821;
extern "C" unsigned char DAT_143e66820;
extern "C" unsigned char DAT_143e66821;
extern "C" unsigned char DAT_143e66830;
extern "C" unsigned char DAT_143e66831;
extern "C" unsigned char DAT_143e66840;
extern "C" unsigned char DAT_143e66841;
extern "C" unsigned char DAT_143e668c0;
extern "C" int DAT_143e668c1;
extern "C" unsigned char DAT_143ee68c0;
extern "C" unsigned char DAT_143ee68c1;
extern "C" unsigned char DAT_143ee78c0;
extern "C" int DAT_143ee78c1;
extern "C" unsigned char DAT_143ee7cc0;
extern "C" int DAT_143ee7cc1;
extern "C" unsigned char DAT_143f67cc0;
extern "C" unsigned char DAT_143f67cc1;
extern "C" unsigned char DAT_143f680c0;
extern "C" unsigned char DAT_143f680c1;
extern "C" unsigned char DAT_143f68140;
extern "C" unsigned char DAT_143f68141;
extern "C" unsigned char DAT_143f68240;
extern "C" int DAT_143f68241;
extern "C" unsigned char DAT_143fe8240;
extern "C" unsigned char DAT_143fe8241;
extern "C" unsigned char DAT_143fe8260;
extern "C" unsigned char DAT_143fe8261;
extern "C" unsigned char DAT_143fe8262;
extern "C" unsigned char DAT_143fe8263;
extern "C" unsigned char DAT_143fe8268;
extern "C" unsigned char DAT_143fe8270;
extern "C" unsigned char DAT_143fe8278;
extern "C" unsigned char DAT_143fe8280;
extern "C" unsigned char DAT_143fe8288;
extern "C" unsigned char DAT_143fe8290;
extern "C" unsigned char DAT_143fe8298;
extern "C" unsigned char DAT_143fe82a0;
extern "C" int DAT_143fe82e0;
extern "C" int DAT_143fe83e0;
extern "C" int DAT_143fe8420;
extern "C" longlong _DAT_143d49900;
extern "C" longlong _DAT_143d49908;
extern "C" longlong _DAT_143d49910;
extern "C" longlong _DAT_143d49918;
extern "C" longlong _DAT_143d49920;
extern "C" longlong _DAT_143d49928;
extern "C" longlong _DAT_143d49930;
extern "C" longlong _DAT_143d49938;
extern "C" longlong _DAT_143d49940;
extern "C" longlong _DAT_143d49948;
extern "C" longlong _DAT_143d49950;
extern "C" longlong _DAT_143d49958;
extern "C" longlong _DAT_143d49960;
extern "C" longlong _DAT_143d49968;
extern "C" longlong _DAT_143d49970;
extern "C" int _DAT_143d49978;
extern "C" longlong _DAT_143d49d80;
extern "C" longlong _DAT_143d49d88;
extern "C" longlong _DAT_143d49d90;
extern "C" longlong _DAT_143d49d98;
extern "C" longlong _DAT_143d49da0;
extern "C" longlong _DAT_143d49da8;
extern "C" longlong _DAT_143d49db0;
extern "C" longlong _DAT_143d49db8;
extern "C" longlong _DAT_143d49dc0;
extern "C" longlong _DAT_143d49dc8;
extern "C" longlong _DAT_143d49dd0;
extern "C" longlong _DAT_143d49dd8;
extern "C" longlong _DAT_143d49de0;
extern "C" longlong _DAT_143d49de8;
extern "C" longlong _DAT_143d49df0;
extern "C" longlong _DAT_143d49df8;
extern "C" int _DAT_143d49e00;
extern "C" int _DAT_143d49e04;
extern "C" int _DAT_143d49e08;
extern "C" int _DAT_143d49e0c;
extern "C" int _DAT_143d49e10;
extern "C" int _DAT_143d49e14;
extern "C" int _DAT_143d49e18;
extern "C" int _DAT_143d49e1c;
extern "C" longlong _DAT_143d49e20;
extern "C" longlong _DAT_143d49e28;
extern "C" longlong _DAT_143d49e30;
extern "C" longlong _DAT_143d49e38;
extern "C" longlong _DAT_143d49e40;
extern "C" longlong _DAT_143d49e48;
extern "C" longlong _DAT_143d49e50;
extern "C" longlong _DAT_143d49e58;
extern "C" longlong _DAT_143d49e60;
extern "C" longlong _DAT_143d49e68;
extern "C" longlong _DAT_143d49e70;
extern "C" longlong _DAT_143d49e78;
extern "C" longlong _DAT_143d49e80;
extern "C" longlong _DAT_143d49e88;
extern "C" longlong _DAT_143d49e90;
extern "C" longlong _DAT_143d49e98;
extern "C" longlong _DAT_143d49ea0;
extern "C" longlong _DAT_143d49ea8;
extern "C" longlong _DAT_143d49eb0;
extern "C" longlong _DAT_143d49eb8;
extern "C" longlong _DAT_143d49ec0;
extern "C" longlong _DAT_143d49ec8;
extern "C" longlong _DAT_143d49ed0;
extern "C" longlong _DAT_143d49ed8;
extern "C" longlong _DAT_143d49ee0;
extern "C" longlong _DAT_143d49ee8;
extern "C" longlong _DAT_143d49ef0;
extern "C" longlong _DAT_143d49ef8;
extern "C" unsigned short _DAT_143d49f80;
extern "C" unsigned short _DAT_143d49f82;
extern "C" unsigned short _DAT_143d49f84;
extern "C" unsigned short _DAT_143d49f86;
extern "C" unsigned short _DAT_143d49f88;
extern "C" unsigned short _DAT_143d49f8a;
extern "C" unsigned short _DAT_143d49f8c;
extern "C" unsigned short _DAT_143d49f8e;
extern "C" unsigned short _DAT_143d49f90;
extern "C" unsigned short _DAT_143d49f92;
extern "C" unsigned short _DAT_143d49f94;
extern "C" unsigned short _DAT_143d49f96;
extern "C" unsigned short _DAT_143d49f98;
extern "C" unsigned short _DAT_143d49f9a;
extern "C" unsigned short _DAT_143d49f9c;
extern "C" unsigned short _DAT_143d49f9e;
extern "C" unsigned short _DAT_143d49fa0;
extern "C" unsigned short _DAT_143d49fa2;
extern "C" unsigned short _DAT_143d49fa4;
extern "C" unsigned short _DAT_143d49fa6;
extern "C" unsigned short _DAT_143d49fa8;
extern "C" unsigned short _DAT_143d49faa;
extern "C" unsigned short _DAT_143d49fac;
extern "C" unsigned short _DAT_143d49fae;
extern "C" unsigned short _DAT_143d4a080;
extern "C" unsigned short _DAT_143d4a082;
extern "C" unsigned short _DAT_143d4a084;
extern "C" unsigned short _DAT_143d4a086;
extern "C" unsigned short _DAT_143d4a088;
extern "C" unsigned short _DAT_143d4a08a;
extern "C" unsigned short _DAT_143d4a08c;
extern "C" unsigned short _DAT_143d4a08e;
extern "C" unsigned short _DAT_143d4a090;
extern "C" unsigned short _DAT_143d4a092;
extern "C" unsigned short _DAT_143d4a094;
extern "C" unsigned short _DAT_143d4a096;
extern "C" unsigned short _DAT_143d4a098;
extern "C" unsigned short _DAT_143d4a09a;
extern "C" unsigned short _DAT_143d4a09c;
extern "C" unsigned short _DAT_143d4a09e;
extern "C" unsigned short _DAT_143d4a0a0;
extern "C" unsigned short _DAT_143d4a0a2;
extern "C" unsigned short _DAT_143d4a0a4;
extern "C" unsigned short _DAT_143d4a0a6;
extern "C" unsigned short _DAT_143d4a0a8;
extern "C" unsigned short _DAT_143d4a0aa;
extern "C" unsigned short _DAT_143d4a0ac;
extern "C" unsigned short _DAT_143d4a0ae;
extern "C" unsigned short _DAT_143d4a0b0;
extern "C" unsigned short _DAT_143d4a0b2;
extern "C" unsigned short _DAT_143d4a0b4;
extern "C" unsigned short _DAT_143d4a0b6;
extern "C" unsigned short _DAT_143d4a0b8;
extern "C" unsigned short _DAT_143d4a0ba;
extern "C" unsigned short _DAT_143d4a0bc;
extern "C" unsigned short _DAT_143d4a0be;
extern "C" unsigned short _DAT_143d4a200;
extern "C" unsigned short _DAT_143d4a202;
extern "C" unsigned short _DAT_143d4a240;
extern "C" unsigned short _DAT_143d4a242;
extern "C" unsigned short _DAT_143d4a244;
extern "C" unsigned short _DAT_143d4a246;
extern "C" unsigned short _DAT_143d4a2c0;
extern "C" unsigned short _DAT_143d4a2c2;
extern "C" unsigned short _DAT_143d4a2c4;
extern "C" unsigned short _DAT_143d4a2c6;
extern "C" unsigned short _DAT_143d4a2c8;
extern "C" unsigned short _DAT_143d4a2ca;
extern "C" unsigned short _DAT_143d4a2cc;
extern "C" unsigned short _DAT_143d4a2ce;
extern "C" unsigned short _DAT_143d4a2d0;
extern "C" unsigned short _DAT_143d4a2d2;
extern "C" unsigned short _DAT_143d4a2d4;
extern "C" unsigned short _DAT_143d4a2d6;
extern "C" unsigned short _DAT_143d4a2d8;
extern "C" unsigned short _DAT_143d4a2da;
extern "C" unsigned short _DAT_143d4a2dc;
extern "C" unsigned short _DAT_143d4a2de;
extern "C" unsigned short _DAT_143d4a300;
extern "C" unsigned short _DAT_143d4a302;
extern "C" unsigned short _DAT_143d4a304;
extern "C" unsigned short _DAT_143d4a306;
extern "C" unsigned short _DAT_143d4a308;
extern "C" unsigned short _DAT_143d4a30a;
extern "C" unsigned short _DAT_143d4a30c;
extern "C" unsigned short _DAT_143d4a30e;
extern "C" unsigned short _DAT_143d4a310;
extern "C" unsigned short _DAT_143d4a312;
extern "C" unsigned short _DAT_143d4a314;
extern "C" unsigned short _DAT_143d4a316;
extern "C" unsigned short _DAT_143d4a318;
extern "C" unsigned short _DAT_143d4a31a;
extern "C" unsigned short _DAT_143d4a31c;
extern "C" unsigned short _DAT_143d4a31e;
extern "C" longlong _DAT_143d4a340;
extern "C" longlong _DAT_143d4a348;
extern "C" longlong _DAT_143d4a350;
extern "C" longlong _DAT_143d4a358;
extern "C" longlong _DAT_143d4a360;
extern "C" longlong _DAT_143d4a368;
extern "C" longlong _DAT_143d4a370;
extern "C" longlong _DAT_143d4a378;
extern "C" longlong _DAT_143d4a380;
extern "C" longlong _DAT_143d4a388;
extern "C" longlong _DAT_143d4a390;
extern "C" longlong _DAT_143d4a398;
extern "C" longlong _DAT_143d4a3a0;
extern "C" longlong _DAT_143d4a3a8;
extern "C" longlong _DAT_143d4a3b0;
extern "C" int _DAT_143d4a3b8;
extern "C" unsigned short _DAT_143d4a3c0;
extern "C" unsigned short _DAT_143d4a3c2;
extern "C" longlong _DAT_143d4a400;
extern "C" longlong _DAT_143d4a408;
extern "C" longlong _DAT_143d4a410;
extern "C" longlong _DAT_143d4a418;
extern "C" longlong _DAT_143d4a420;
extern "C" longlong _DAT_143d4a428;
extern "C" longlong _DAT_143d4a430;
extern "C" longlong _DAT_143d4a438;
extern "C" longlong _DAT_143d4a440;
extern "C" longlong _DAT_143d4a448;
extern "C" longlong _DAT_143d4a450;
extern "C" longlong _DAT_143d4a458;
extern "C" longlong _DAT_143d4a460;
extern "C" longlong _DAT_143d4a468;
extern "C" longlong _DAT_143d4a470;
extern "C" int _DAT_143d4a478;
extern "C" longlong _DAT_143d4a800;
extern "C" longlong _DAT_143d4a808;
extern "C" longlong _DAT_143d4a810;
extern "C" longlong _DAT_143d4a818;
extern "C" longlong _DAT_143d4a820;
extern "C" longlong _DAT_143d4a828;
extern "C" longlong _DAT_143d4a830;
extern "C" longlong _DAT_143d4a838;
extern "C" longlong _DAT_143d4a840;
extern "C" longlong _DAT_143d4a848;
extern "C" longlong _DAT_143d4a850;
extern "C" longlong _DAT_143d4a858;
extern "C" longlong _DAT_143d4a860;
extern "C" longlong _DAT_143d4a868;
extern "C" longlong _DAT_143d4a870;
extern "C" int _DAT_143d4a878;
extern "C" unsigned short _DAT_143d4a8a0;
extern "C" unsigned short _DAT_143d4a8a2;
extern "C" unsigned short _DAT_143d4a8bc;
extern "C" unsigned short _DAT_143d4a8be;
extern "C" unsigned short _DAT_143d4aa80;
extern "C" unsigned short _DAT_143d4aa82;
extern "C" unsigned short _DAT_143d4aa84;
extern "C" unsigned short _DAT_143d4aa86;
extern "C" unsigned short _DAT_143d4aa88;
extern "C" unsigned short _DAT_143d4aa8a;
extern "C" unsigned short _DAT_143d4aa8c;
extern "C" unsigned short _DAT_143d4aa8e;
extern "C" unsigned short _DAT_143d4aa90;
extern "C" unsigned short _DAT_143d4aa92;
extern "C" unsigned short _DAT_143d4aa94;
extern "C" unsigned short _DAT_143d4aa96;
extern "C" unsigned short _DAT_143d4aa98;
extern "C" unsigned short _DAT_143d4aa9a;
extern "C" unsigned short _DAT_143d4aa9c;
extern "C" unsigned short _DAT_143d4aa9e;
extern "C" unsigned short _DAT_143d4aaa0;
extern "C" unsigned short _DAT_143d4aaa2;
extern "C" unsigned short _DAT_143d4aaa4;
extern "C" unsigned short _DAT_143d4aaa6;
extern "C" unsigned short _DAT_143d4aaa8;
extern "C" unsigned short _DAT_143d4aaaa;
extern "C" unsigned short _DAT_143d4aaac;
extern "C" unsigned short _DAT_143d4aaae;
extern "C" unsigned short _DAT_143e65802;
extern "C" longlong DAT_143c490e0;
extern "C" longlong DAT_143c490f0;
extern "C" longlong DAT_143d749b8;
extern "C" longlong DAT_143d749c0;
extern "C" longlong DAT_143d749c8;
extern "C" longlong DAT_143d749d0;
extern "C" longlong DAT_143d749d8;
extern "C" longlong DAT_143d749e0;
extern "C" longlong DAT_143d749e8;
extern "C" longlong DAT_143d749f0;
extern "C" longlong DAT_143d749f8;
extern "C" longlong DAT_143d74a00;
extern "C" longlong DAT_143d74a08;
extern "C" longlong DAT_143d74a10;
extern "C" longlong DAT_143d74a18;
extern "C" longlong DAT_143d74a20;
extern "C" longlong DAT_143d74a28;
extern "C" longlong DAT_143d74a30;
extern "C" longlong DAT_143d74a38;
extern "C" longlong DAT_143d74a40;
extern "C" longlong DAT_143d74a48;
extern "C" longlong DAT_143d74a50;
extern "C" longlong DAT_143d74a58;
extern "C" longlong DAT_143d74a60;
extern "C" void* DAT_143c490f8;
extern "C" void* DAT_143fe8248;
extern "C" void* DAT_143fe8250;
extern "C" cri_u1 LAB_140054100;

cri_u8 FUN_140047750(cri_any = cri_any(), ...);
void FUN_1400479e0(cri_any = cri_any(), ...);
void FUN_1400493c0(cri_any = cri_any(), ...);
void FUN_14004de60(cri_any = cri_any(), ...);
void FUN_14004dfc0(cri_any = cri_any(), ...);
cri_u4 FUN_14004ff50(cri_any = cri_any(), cri_any = cri_any(), ...);
DWORD FUN_1400501f0(cri_any = cri_any(), ...);
void FUN_140050210(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140050310(cri_any = cri_any(), ...);
longlong FUN_140050730(cri_any = cri_any(), ...);
cri_u8 FUN_140050820(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
cri_u4 FUN_140051d90(cri_any = cri_any(), ...);
cri_u4 FUN_140051ec0(cri_any = cri_any(), cri_any = cri_any(), ...);
cri_u4 FUN_140052010(cri_any = cri_any(), cri_any = cri_any(), ...);
int FUN_140052950(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
cri_u1 FUN_140053000(cri_any = cri_any(), ...);
void FUN_140054170(cri_any = cri_any(), ...);
bool FUN_140054210(cri_any = cri_any(), ...);
bool FUN_140054230(cri_any = cri_any(), ...);
void FUN_140054250(cri_any = cri_any(), ...);
void FUN_140054320(cri_any = cri_any(), ...);
void FUN_140054490(cri_any = cri_any(), ...);
void FUN_1400544b0(cri_any = cri_any(), ...);
void FUN_1400544e0(cri_any = cri_any(), ...);
void FUN_1400545f0(cri_any = cri_any(), ...);
void FUN_140054820(cri_any = cri_any(), ...);
void FUN_1400549b0(cri_any = cri_any(), ...);
void FUN_140054a40(cri_any = cri_any(), ...);
void FUN_140054a80(cri_any = cri_any(), ...);
void FUN_140054b60(cri_any = cri_any(), ...);
longlong FUN_140054cf0(cri_any = cri_any(), cri_any = cri_any(), ...);
longlong FUN_140055410(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140055510(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
longlong FUN_140055550(cri_any = cri_any(), cri_any = cri_any(), ...);
longlong FUN_140057fe0(cri_any = cri_any(), cri_any = cri_any(), ...);
longlong FUN_1400584e0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140058b10(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
longlong FUN_140058c50(cri_any = cri_any(), cri_any = cri_any(), ...);
uint FUN_140058e00(cri_any = cri_any(), cri_any = cri_any(), ...);
ulonglong FUN_140059030(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140059090(cri_any = cri_any(), ...);
void FUN_140059170(cri_any = cri_any(), ...);
void FUN_140059290(cri_any = cri_any(), ...);
void FUN_1400593f0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140059810(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140059c40(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005a1b0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005a4b0(cri_any = cri_any(), ...);
void FUN_14005a530(cri_any = cri_any(), ...);
void FUN_14005a820(cri_any = cri_any(), ...);
void FUN_14005a900(cri_any = cri_any(), ...);
void FUN_14005a980(cri_any = cri_any(), ...);
void FUN_14005aa60(cri_any = cri_any(), ...);
void FUN_14005ae00(cri_any = cri_any(), ...);
void FUN_14005aea0(cri_any = cri_any(), ...);
void FUN_14005aee0(cri_any = cri_any(), ...);
void FUN_14005af00(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005af20(cri_any = cri_any(), ...);
cri_u4 FUN_14005af30(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005af70(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005afd0(cri_any = cri_any(), cri_any = cri_any(), ...);
cri_u4 FUN_14005b040(cri_any = cri_any(), ...);
void FUN_14005b090(cri_any = cri_any(), ...);
void FUN_14005b0b0(cri_any = cri_any(), ...);
ulonglong FUN_14005b0d0(cri_any = cri_any(), ...);
void FUN_14005b0f0(cri_any = cri_any(), ...);
void FUN_14005b110(cri_any = cri_any(), ...);
void FUN_14005b130(cri_any = cri_any(), ...);
void FUN_14005b150(cri_any = cri_any(), ...);
void FUN_14005b170(cri_any = cri_any(), ...);
void FUN_14005b190(cri_any = cri_any(), ...);
void FUN_14005b1b0(cri_any = cri_any(), ...);
void FUN_14005b1d0(cri_any = cri_any(), ...);
void FUN_14005b200(cri_any = cri_any(), ...);
void FUN_14005b220(cri_any = cri_any(), ...);
cri_u8 FUN_14005b240(cri_any = cri_any(), ...);
void FUN_14005b260(cri_any = cri_any(), ...);
void FUN_14005b280(cri_any = cri_any(), ...);
void FUN_14005b2a0(cri_any = cri_any(), ...);
void FUN_14005b2c0(cri_any = cri_any(), ...);
void FUN_14005b2e0(cri_any = cri_any(), ...);
void FUN_14005b300(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005b390(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005b560(cri_any = cri_any(), ...);
void FUN_14005b580(cri_any = cri_any(), ...);
void FUN_14005b5c0(cri_any = cri_any(), ...);
void FUN_14005b650(cri_any = cri_any(), ...);
void FUN_14005b6d0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005b810(cri_any = cri_any(), ...);
void FUN_14005b860(cri_any = cri_any(), ...);
void FUN_14005b8a0(cri_any = cri_any(), ...);
cri_u8 FUN_14005b8c0(cri_any = cri_any(), ...);
void FUN_14005dc70(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005e5b0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005e600(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005e650(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005e6c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005e720(cri_any = cri_any(), ...);
void FUN_14005ebc0(cri_any = cri_any(), ...);
void FUN_14005ebd0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14005fe40(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140061080(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400616c0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140061ce0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400622f0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400623f0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400624c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400625c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140062690(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400627a0(cri_any = cri_any(), ...);
void FUN_1400627f0(cri_any = cri_any(), ...);
cri_u4 FUN_140062820(cri_any = cri_any(), ...);
cri_u8 FUN_140062830(cri_any = cri_any(), ...);
cri_u8 FUN_140062860(cri_any = cri_any(), ...);
int FUN_140062890(cri_any = cri_any(), ...);
void FUN_1400628d0(cri_any = cri_any(), ...);
ulonglong FUN_140062900(cri_any = cri_any(), ...);
void FUN_140062910(cri_any = cri_any(), ...);
void FUN_140062920(cri_any = cri_any(), ...);
void FUN_140062950(cri_any = cri_any(), ...);
cri_u8 FUN_140062a40(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140062ab0(cri_any = cri_any(), ...);
cri_u8 FUN_140062ae0(cri_any = cri_any(), cri_any = cri_any(), ...);
int FUN_140062bc0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140062c10(cri_any = cri_any(), cri_any = cri_any(), ...);
cri_u8 FUN_1400630c0(cri_any = cri_any(), ...);
void FUN_1400630d0(cri_any = cri_any(), ...);
void FUN_1400633e0(cri_any = cri_any(), ...);
void FUN_140063730(cri_any = cri_any(), ...);
void FUN_140063aa0(cri_any = cri_any(), ...);
void FUN_140063b60(cri_any = cri_any(), ...);
void FUN_140063cb0(cri_any = cri_any(), ...);
cri_u8 FUN_140063eb0(cri_any = cri_any(), ...);
cri_u2 * FUN_140064070(cri_any = cri_any(), ...);
void FUN_140064360(cri_any = cri_any(), ...);
void FUN_140064440(cri_any = cri_any(), ...);
void FUN_140064510(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140064640(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140064760(cri_any = cri_any(), ...);
void FUN_1400649a0(cri_any = cri_any(), ...);
longlong FUN_140064ae0(cri_any = cri_any(), ...);
longlong FUN_140064be0(cri_any = cri_any(), ...);
longlong FUN_140064c30(cri_any = cri_any(), ...);
longlong FUN_140064c90(cri_any = cri_any(), ...);
void FUN_140064ce0(cri_any = cri_any(), ...);
void FUN_140064d00(cri_any = cri_any(), ...);
void FUN_140064d20(cri_any = cri_any(), ...);
void FUN_140064d40(cri_any = cri_any(), ...);
void FUN_140064d60(cri_any = cri_any(), ...);
void FUN_140064d90(cri_any = cri_any(), ...);
void FUN_140064dd0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void * FUN_140064eb0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void * FUN_140064ed0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void * FUN_140064ef0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void * FUN_140064f10(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140064f70(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140065000(cri_any = cri_any(), ...);
void FUN_140065030(cri_any = cri_any(), ...);
void FUN_140065060(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void * FUN_1400653b0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140065410(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
cri_u8 FUN_140065450(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140065660(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140065770(cri_any = cri_any(), ...);
void FUN_140065790(cri_any = cri_any(), ...);
void FUN_1400657a0(cri_any = cri_any(), ...);
void FUN_1400657e0(cri_any = cri_any(), ...);
void FUN_140065800(cri_any = cri_any(), ...);
void FUN_140065900(cri_any = cri_any(), ...);
int FUN_140065940(cri_any = cri_any(), ...);
void FUN_1400659a0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400659f0(cri_any = cri_any(), ...);
void FUN_140065a20(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140065e70(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140066180(cri_any = cri_any(), ...);
void FUN_140066320(cri_any = cri_any(), ...);
void FUN_140066370(cri_any = cri_any(), ...);
void FUN_1400663b0(cri_any = cri_any(), ...);
void FUN_1400663d0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400677f0(cri_any = cri_any(), ...);
void FUN_140067840(cri_any = cri_any(), ...);
cri_u8 FUN_140067890(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140067a90(cri_any = cri_any(), ...);
cri_u4 FUN_140067f40(cri_any = cri_any(), ...);
cri_u8 FUN_1400682e0(cri_any = cri_any(), cri_any = cri_any(), ...);
cri_u8 FUN_140068380(cri_any = cri_any(), ...);
void FUN_140069020(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14006aa90(cri_any = cri_any(), ...);
void FUN_14006aaa0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
longlong FUN_14006b0d0(cri_any = cri_any(), ...);
longlong FUN_140073c80(cri_any = cri_any(), ...);
longlong FUN_14007ba60(cri_any = cri_any(), ...);
longlong FUN_140083350(cri_any = cri_any(), ...);
void FUN_140089fe0(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14008a3c0(cri_any = cri_any(), ...);
void FUN_14008a970(cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14008ab40(cri_any = cri_any(), ...);
void FUN_14008c780(cri_any = cri_any(), ...);
void FUN_14008c820(cri_any = cri_any(), ...);
void FUN_14008d2a0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14008e570(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_14008fa50(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140090080(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140090730(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400927c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140092850(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_1400928e0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), ...);
void FUN_140093cf0(cri_any = cri_any(), ...);
void FUN_140095250(cri_any = cri_any(), ...);
void FUN_140095450(cri_any = cri_any(), ...);
void FUN_142ccb4f0(cri_any = cri_any(), ...);
void FUN_142ccb500(cri_any = cri_any(), ...);

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054170
void FUN_140054170(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  uint u_v1;
  cri_u8 *pu_v2;
  longlong l_v3;
  longlong l_v4;
  longlong l_v5;
  
  l_v3 = 0;
  u_v1 = 1;
  pu_v2 = (cri_u8 *)((char *)arg1 + 0x1980);
  l_v4 = arg1 + 0x780;
  l_v5 = 6;
  do {
    if ((*(uint *)((char *)arg1 + 0x71c) & u_v1) != 0) {
      FUN_14006aaa0(*pu_v2,l_v4,(int)*(char *)(l_v3 + 0xc6c + arg1));
    }
    l_v4 = l_v4 + 0x80;
    l_v3 = l_v3 + 1;
    pu_v2 = pu_v2 + 1;
    u_v1 = u_v1 << 1 | (uint)((int)u_v1 < 0);
    l_v5 = l_v5 + -1;
  } while (l_v5 != 0);
  return;
}

// The decoder's alternate output callback (FUN_140054250 stores it at +0x1bc8, compared as DAT_1400541f0; Ghidra made no
// function here): forwards the decoder's sample block at +0x19b0 to the block writer.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x1400541f0
void FUN_1400541f0(char *ctx)
{
  FUN_1400662f0(ctx + 0x19b0);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054200
void thunk_FUN_140054080(cri_any cri_unused, ...)
{
  FUN_14006aa90();
  FUN_140066320();
  FUN_140066180(&DAT_143fe82e0);
  FUN_1400659a0(&DAT_1431ba950,&DAT_143fe8420);
  FUN_1400659a0(&DAT_1431ba990,&DAT_143fe83e0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054210
bool FUN_140054210(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  return *(cri_code **)((char *)arg1 + 0x1bc8) == (cri_code *)FUN_140054170;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054230
bool FUN_140054230(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  return *(cri_u1 **)((char *)arg1 + 0x1bc8) == CRI_ADDR(FUN_1400541f0);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054250
void FUN_140054250(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  int i_v1;
  
  if (*(int *)((char *)arg1 + 0x1a78) != 0) {
    *(cri_u1 **)((char *)arg1 + 0x1bc8) = &LAB_140054100;
    return;
  }
  *(cri_u8 *)((char *)arg1 + 0x1bc8) = 0;
  if (*(int *)((char *)arg1 + 0x1a7c) == 1) {
    i_v1 = FUN_140062860();
    if (i_v1 != 0) {
      *(cri_u1 **)((char *)arg1 + 0x1bc8) = CRI_ADDR(FUN_1400541f0);
    }
  }
  else if (*(int *)((char *)arg1 + 0x1a7c) == 2) {
    i_v1 = FUN_140062830();
    if (i_v1 != 0) {
      *(cri_code **)((char *)arg1 + 0x1bc8) = (cri_code *)FUN_140054170;
    }
  }
  else {
    i_v1 = FUN_140062860();
    if (i_v1 != 0) {
      *(cri_u1 **)((char *)arg1 + 0x1bc8) = CRI_ADDR(FUN_1400541f0);
    }
    i_v1 = FUN_140062830();
    if ((i_v1 != 0) && (*(longlong *)((char *)arg1 + 0x1bc8) == 0)) {
      *(cri_code **)((char *)arg1 + 0x1bc8) = (cri_code *)FUN_140054170;
    }
  }
  if (*(longlong *)((char *)arg1 + 0x1bc8) == 0) {
    *(cri_u1 **)((char *)arg1 + 0x1bc8) = CRI_ADDR(FUN_1400541f0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054320
void FUN_140054320(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  cri_code *pc_v1;
  
  pc_v1 = *(cri_code **)((char *)arg1 + 0x1bc8);
  if (pc_v1 == (cri_code *)&LAB_140054100) {
    *(longlong *)((char *)arg1 + 0x1980) = arg1 + 0x780;
    *(longlong *)((char *)arg1 + 0x1988) = arg1 + 0x800;
    *(longlong *)((char *)arg1 + 0x1990) = arg1 + 0x880;
    *(longlong *)((char *)arg1 + 0x1998) = arg1 + 0x900;
    *(longlong *)((char *)arg1 + 0x19a0) = arg1 + 0x980;
    *(longlong *)((char *)arg1 + 0x19a8) = arg1 + 0xa00;
  }
  if (pc_v1 == (cri_code *)FUN_140054170) {
    *(longlong *)((char *)arg1 + 0x1980) = arg1 + 0x1380;
    *(longlong *)((char *)arg1 + 0x1988) = arg1 + 0x1400;
    *(longlong *)((char *)arg1 + 0x1990) = arg1 + 0x1480;
    *(longlong *)((char *)arg1 + 0x1998) = arg1 + 0x1500;
    *(longlong *)((char *)arg1 + 0x19a0) = arg1 + 0x1580;
    *(longlong *)((char *)arg1 + 0x19a8) = arg1 + 0x1600;
  }
  if (pc_v1 == (cri_code *)&FUN_1400541f0) {
    FUN_140065900(arg1 + 0x19b0);
    *(longlong *)((char *)arg1 + 0x19e8) = arg1 + 0xd80;
    *(longlong *)((char *)arg1 + 0x1980) = arg1 + 0x780;
    *(longlong *)((char *)arg1 + 0x1a18) = arg1 + 0x1380;
    *(longlong *)((char *)arg1 + 0x1988) = arg1 + 0x800;
    *(longlong **)((char *)arg1 + 0x19f0) = (longlong *)((char *)arg1 + 0x1980);
    *(longlong *)((char *)arg1 + 0x1990) = arg1 + 0x880;
    *(longlong *)((char *)arg1 + 0x1998) = arg1 + 0x900;
    *(longlong *)((char *)arg1 + 0x19a0) = arg1 + 0x980;
    *(longlong *)((char *)arg1 + 0x19a8) = arg1 + 0xa00;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054490
void FUN_140054490(cri_any cri_p0, ...)
{
  cri_u8 arg1 = cri_p0;
  FUN_140054250(arg1);  // the exe passes rcx through
  FUN_140054320(arg1);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400544b0
void FUN_1400544b0(cri_any cri_unused, ...)
{
  int i_v1;
  char *pc_v2;
  
  i_v1 = 0;
  pc_v2 = "";
  do {
    (&DAT_143fe8260)[pc_v2[-0x40]] = (char)i_v1;
    (&DAT_143fe82a0)[*pc_v2] = (char)i_v1;
    i_v1 = i_v1 + 1;
    pc_v2 = pc_v2 + 1;
  } while (i_v1 < 0x40);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400544e0
void FUN_1400544e0(cri_any cri_p0, ...)
{
  void *arg1 = cri_p0;
  memset(arg1,0,0xd58);
  *(cri_u4 *)((longlong)arg1 + 0x24c) = 1;
  *(cri_u4 *)((longlong)arg1 + 0x270) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xc78) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xc7c) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xc80) = 0;
  *(cri_u8 *)((longlong)arg1 + 0xc88) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xc90) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xc94) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xca0) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xc10) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xd14) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xd18) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xd28) = 0;
  *(cri_u4 *)((longlong)arg1 + 0x2d0) = 0;
  *(cri_u4 *)((longlong)arg1 + 0xd44) = 0;
  *(cri_u4 *)((longlong)arg1 + 0x274) = 0xff;
  *(cri_u4 *)((longlong)arg1 + 0x278) = 0xff;
  *(cri_u4 *)((longlong)arg1 + 0x27c) = 0xff;
  *(cri_u4 *)((longlong)arg1 + 0x2d4) = 1;
  return;
}

// The decoder table entries unit_140047430's FUN_1400478a0 stores by address (LAB_140054590/5c0/5d0; Ghidra made no
// functions here): set callback slot nIndex (0x18 bytes from +0x1be8), set the +0x1c48 pointer and count, and read
// the +0x1c48 pointer and the +0x1c54 count back.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x140054590
void FUN_140054590(void* pCtx, int nIndex, cri_u8 a3, cri_u8 a4, cri_u8 a5)
{
  cri_u8* pSlot = (cri_u8*)((cri_u1*)pCtx + 0x1be8 + (longlong)nIndex * 0x18);
  pSlot[2] = a5;
  pSlot[0] = a3;
  pSlot[1] = a4;
}

// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x1400545c0
void FUN_1400545c0(void* pCtx, cri_u8 a2, cri_u4 a3)
{
  *(cri_u8*)((cri_u1*)pCtx + 0x1c48) = a2;
  *(cri_u4*)((cri_u1*)pCtx + 0x1c50) = a3;
}

// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x1400545d0
void FUN_1400545d0(void* pCtx, cri_u8* pOut, cri_u4* pCount)
{
  if (pOut)
    *pOut = *(cri_u8*)((cri_u1*)pCtx + 0x1c48);
  if (pCount)
    *pCount = *(cri_u4*)((cri_u1*)pCtx + 0x1c54);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400545f0
void FUN_1400545f0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  *(cri_u4 *)((char *)arg1 + 0x1aa8) = *(cri_u4 *)((char *)arg1 + 0x6c4);
  *(cri_u4 *)((char *)arg1 + 0x1aac) = *(cri_u4 *)((char *)arg1 + 0x6c8);
  *(cri_u4 *)((char *)arg1 + 0x1ab0) = *(cri_u4 *)((char *)arg1 + 0x6cc);
  *(cri_u4 *)((char *)arg1 + 0x1ab4) = *(cri_u4 *)((char *)arg1 + 0x6d0);
  *(cri_u4 *)((char *)arg1 + 0x1ab8) = *(cri_u4 *)((char *)arg1 + 0x10);
  *(cri_u4 *)((char *)arg1 + 0x1abc) = *(cri_u4 *)((char *)arg1 + 0x2dc);
  *(cri_u4 *)((char *)arg1 + 0x1ac0) = *(cri_u4 *)((char *)arg1 + 0x2e0);
  *(cri_u4 *)((char *)arg1 + 0x1ac4) = *(cri_u4 *)(arg1 + 700);
  *(cri_u4 *)((char *)arg1 + 0x1ac8) = *(cri_u4 *)((char *)arg1 + 0x2c0);
  *(cri_u4 *)((char *)arg1 + 0x1acc) = *(cri_u4 *)((char *)arg1 + 0x2c4);
  *(cri_u4 *)((char *)arg1 + 0x1ad0) = *(cri_u4 *)((char *)arg1 + 0x2c8);
  *(cri_u4 *)((char *)arg1 + 0x1ad4) = *(cri_u4 *)((char *)arg1 + 0x2cc);
  *(cri_u4 *)((char *)arg1 + 0x1ad8) = *(cri_u4 *)((char *)arg1 + 0xcb4);
  *(cri_u4 *)((char *)arg1 + 0x1adc) = *(cri_u4 *)((char *)arg1 + 0xca4);
  *(cri_u4 *)((char *)arg1 + 0x1ae0) = *(cri_u4 *)((char *)arg1 + 0x318);
  *(cri_u4 *)((char *)arg1 + 0x1ae8) = 0;
  *(cri_u4 *)((char *)arg1 + 0x1ae4) = *(cri_u4 *)((char *)arg1 + 0x24c);
  *(cri_u4 *)((char *)arg1 + 0x1aec) = 1;
  *(cri_u4 *)((char *)arg1 + 0x1af0) = *(cri_u4 *)((char *)arg1 + 0x6d4);
  *(cri_u4 *)((char *)arg1 + 0x1af4) = *(cri_u4 *)((char *)arg1 + 0x6d8);
  *(cri_u2 *)((char *)arg1 + 0x1af8) = *(cri_u2 *)((char *)arg1 + 0x280);
  *(cri_u2 *)((char *)arg1 + 0x1afa) = *(cri_u2 *)((char *)arg1 + 0x284);
  *(cri_u1 *)((char *)arg1 + 0x1afc) =
       (&DAT_1431baa20)
       [(ulonglong)*(uint *)((char *)arg1 + 0x31c) +
        ((ulonglong)*(uint *)((char *)arg1 + 0x334) + (ulonglong)*(uint *)((char *)arg1 + 0x248) * 2) * 2];
  *(cri_u1 *)((char *)arg1 + 0x1afd) = *(cri_u1 *)((char *)arg1 + 0x33c);
  *(cri_u1 *)((char *)arg1 + 0x1afe) = *(cri_u1 *)((char *)arg1 + 0x31c);
  *(cri_u1 *)((char *)arg1 + 0x1aff) = *(cri_u1 *)((char *)arg1 + 0x334);
  *(cri_u1 *)((char *)arg1 + 0x1b00) = *(cri_u1 *)((char *)arg1 + 0xc0c);
  *(cri_u1 *)((char *)arg1 + 0x1b01) = *(cri_u1 *)((char *)arg1 + 0xc);
  *(cri_u1 *)((char *)arg1 + 0x1b02) = *(cri_u1 *)((char *)arg1 + 0x20);
  *(cri_u1 *)((char *)arg1 + 0x1b03) = *(cri_u1 *)((char *)arg1 + 0x264);
  *(cri_u1 *)((char *)arg1 + 0x1b04) = *(cri_u1 *)((char *)arg1 + 0x268);
  *(cri_u1 *)((char *)arg1 + 0x1b05) = *(cri_u1 *)((char *)arg1 + 0x244);
  *(cri_u1 *)((char *)arg1 + 0x1b06) = *(cri_u1 *)((char *)arg1 + 0x248);
  *(cri_u1 *)((char *)arg1 + 0x1b07) = *(cri_u1 *)((char *)arg1 + 0x260);
  *(cri_u1 *)((char *)arg1 + 0x1b08) = *(cri_u1 *)((char *)arg1 + 0x26c);
  *(cri_u1 *)((char *)arg1 + 0x1b09) = *(cri_u1 *)((char *)arg1 + 0x270);
  *(cri_u1 *)((char *)arg1 + 0x1b0a) = *(cri_u1 *)((char *)arg1 + 0x274);
  *(cri_u1 *)((char *)arg1 + 0x1b0b) = *(cri_u1 *)((char *)arg1 + 0x278);
  *(cri_u1 *)((char *)arg1 + 0x1b0c) = *(cri_u1 *)((char *)arg1 + 0x27c);
  *(cri_u4 *)((char *)arg1 + 0x1b10) = *(cri_u4 *)((char *)arg1 + 0xd24);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054820
void FUN_140054820(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  longlong l_v1;
  longlong l_v2;
  
  l_v1 = 0;
  do {
    l_v2 = l_v1 + 4;
    *(int *)(arg1 + 0x28 + (longlong)(char)(&DAT_1431baa30)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf0)[l_v1];
    *(int *)(arg1 + 0x35c + (longlong)(char)(&DAT_1431baa30)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf0)[l_v1];
    *(cri_u4 *)(arg1 + 300 + (longlong)(char)(&DAT_1431baa30)[l_v1] * 4) = 0x10;
    *(cri_u4 *)(arg1 + 0x460 + (longlong)(char)(&DAT_1431baa30)[l_v1] * 4) = 0x10;
    *(int *)(arg1 + 0x28 + (longlong)(char)(&DAT_1431baa31)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf1)[l_v1];
    *(int *)(arg1 + 0x35c + (longlong)(char)(&DAT_1431baa31)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf1)[l_v1];
    *(cri_u4 *)(arg1 + 300 + (longlong)(char)(&DAT_1431baa31)[l_v1] * 4) = 0x10;
    *(cri_u4 *)(arg1 + 0x460 + (longlong)(char)(&DAT_1431baa31)[l_v1] * 4) = 0x10;
    *(int *)(arg1 + 0x28 + (longlong)(char)(&DAT_1431baa32)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf2)[l_v1];
    *(int *)(arg1 + 0x35c + (longlong)(char)(&DAT_1431baa32)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf2)[l_v1];
    *(cri_u4 *)(arg1 + 300 + (longlong)(char)(&DAT_1431baa32)[l_v1] * 4) = 0x10;
    *(cri_u4 *)(arg1 + 0x460 + (longlong)(char)(&DAT_1431baa32)[l_v1] * 4) = 0x10;
    *(int *)(arg1 + 0x28 + (longlong)(char)(&DAT_1431baa33)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf3)[l_v1];
    *(int *)(arg1 + 0x35c + (longlong)(char)(&DAT_1431baa33)[l_v1] * 4) =
         (int)(char)(&DAT_1431baaf3)[l_v1];
    *(cri_u4 *)(arg1 + 300 + (longlong)(char)(&DAT_1431baa33)[l_v1] * 4) = 0x10;
    *(cri_u4 *)(arg1 + 0x460 + (longlong)(char)(&DAT_1431baa33)[l_v1] * 4) = 0x10;
    l_v1 = l_v2;
  } while (l_v2 < 0x40);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400549b0
void FUN_1400549b0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  uint u_v1;
  uint u_v2;
  int i_v3;
  
  u_v1 = *(int *)((char *)arg1 + 0x250) << 0xc | *(uint *)(arg1 + 4);
  u_v2 = *(int *)((char *)arg1 + 0x254) << 0xc | *(uint *)(arg1 + 8);
  *(uint *)((char *)arg1 + 0x6c4) = u_v1;
  *(uint *)((char *)arg1 + 0x6c8) = u_v2;
  u_v1 = u_v1 + 0xf >> 4;
  *(uint *)((char *)arg1 + 0x6cc) = u_v1;
  if (*(int *)((char *)arg1 + 0x248) == 1) {
    u_v2 = u_v2 + 0xf >> 4;
  }
  else {
    u_v2 = u_v2 + 0x1f >> 5;
    if (*(int *)((char *)arg1 + 0x318) == 3) {
      u_v2 = u_v2 * 2;
    }
  }
  *(uint *)((char *)arg1 + 0x6d0) = u_v2;
  i_v3 = u_v1 << 4;
  *(uint *)((char *)arg1 + 0xc00) = u_v2 << 4;
  *(int *)((char *)arg1 + 0xbfc) = i_v3;
  *(int *)((char *)arg1 + 0xc08) = (int)(u_v2 << 4) >> 1;
  *(int *)((char *)arg1 + 0xc04) = i_v3 >> 1;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054a40
void FUN_140054a40(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  if (((*(int *)((char *)arg1 + 0x248) != 1) && (*(int *)((char *)arg1 + 0x318) != 1)) &&
     (*(int *)((char *)arg1 + 0x318) != 2)) {
    *(uint *)((char *)arg1 + 0x238) = (*(int *)((char *)arg1 + 0x334) == 1) + 2;
    return;
  }
  *(cri_u4 *)((char *)arg1 + 0x238) = 1;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054a80
void FUN_140054a80(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  uint u_v1;
  int i_v2;
  longlong l_v3;
  uint u_v4;
  
  if (*(int *)((char *)arg1 + 0x318) == 3) {
    i_v2 = 0;
    *(cri_u4 *)((char *)arg1 + 0xc10) = 0;
  }
  else {
    *(int *)((char *)arg1 + 0xc10) = *(int *)((char *)arg1 + 0xc10) + 1;
    u_v1 = *(int *)((char *)arg1 + 0xc10) - 1;
    u_v4 = (int)u_v1 >> 0x1f;
    i_v2 = (u_v1 & 1 ^ u_v4) - u_v4;
  }
  *(int *)((char *)arg1 + 0xc0c) = i_v2;
  *(cri_u4 *)((char *)arg1 + 0x720) =
       *(cri_u4 *)(&DAT_1431bab30 + (ulonglong)*(uint *)((char *)arg1 + 0x314) * 4);
  l_v3 = (ulonglong)*(uint *)((char *)arg1 + 0x330) * 0x40;
  *(cri_u4 *)((char *)arg1 + 0x730) =
       *(cri_u4 *)(&DAT_1431bab40 + (ulonglong)*(uint *)((char *)arg1 + 0x314) * 4);
  *(cri_u8 *)((char *)arg1 + 0x734) = *(cri_u8 *)(&DAT_143fe8260 + l_v3);
  *(cri_u8 *)((char *)arg1 + 0x73c) = *(cri_u8 *)(&DAT_143fe8268 + l_v3);
  *(cri_u8 *)((char *)arg1 + 0x744) = *(cri_u8 *)(&DAT_143fe8270 + l_v3);
  *(cri_u8 *)((char *)arg1 + 0x74c) = *(cri_u8 *)(&DAT_143fe8278 + l_v3);
  *(cri_u8 *)((char *)arg1 + 0x754) = *(cri_u8 *)(&DAT_143fe8280 + l_v3);
  *(cri_u8 *)((char *)arg1 + 0x75c) = *(cri_u8 *)(&DAT_143fe8288 + l_v3);
  *(cri_u8 *)((char *)arg1 + 0x764) = *(cri_u8 *)(&DAT_143fe8290 + l_v3);
  *(cri_u8 *)((char *)arg1 + 0x76c) = *(cri_u8 *)(&DAT_143fe8298 + l_v3);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054b60
void FUN_140054b60(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  cri_u1 *pu_v1;
  longlong l_v2;
  longlong l_v3;
  cri_u1 *pu_v4;
  
  pu_v4 = (cri_u1 *)(arg1 + 300);
  l_v2 = 0;
  do {
    l_v3 = l_v2 + 4;
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8260)[l_v2] + 0xa80 + arg1) = pu_v4[-0x104];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8260)[l_v2] + 0xac0 + arg1) = *pu_v4;
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8260)[l_v2] + 0xb00 + arg1) = pu_v4[0x230];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8260)[l_v2] + 0xb40 + arg1) = pu_v4[0x334];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8261)[l_v2] + 0xa80 + arg1) = pu_v4[-0x100];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8261)[l_v2] + 0xac0 + arg1) = pu_v4[4];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8261)[l_v2] + 0xb00 + arg1) = pu_v4[0x234];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8261)[l_v2] + 0xb40 + arg1) = pu_v4[0x338];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8262)[l_v2] + 0xa80 + arg1) = pu_v4[-0xfc];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8262)[l_v2] + 0xac0 + arg1) = pu_v4[8];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8262)[l_v2] + 0xb00 + arg1) = pu_v4[0x238];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8262)[l_v2] + 0xb40 + arg1) = pu_v4[0x33c];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8263)[l_v2] + 0xa80 + arg1) = pu_v4[-0xf8];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8263)[l_v2] + 0xac0 + arg1) = pu_v4[0xc];
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8263)[l_v2] + 0xb00 + arg1) = pu_v4[0x23c];
    pu_v1 = pu_v4 + 0x340;
    pu_v4 = pu_v4 + 0x10;
    *(cri_u1 *)((longlong)(char)(&DAT_143fe8263)[l_v2] + 0xb40 + arg1) = *pu_v1;
    l_v2 = l_v3;
  } while (l_v3 < 0x40);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054cf0
longlong FUN_140054cf0(cri_any cri_p0, cri_any cri_p1, ...)
{
  uint *arg1 = cri_p0;
  ulonglong arg2 = cri_p1;
  cri_u1 *pu_v1;
  cri_u1 *pu_v2;
  cri_u1 u_v3;
  ulonglong u_v4;
  byte b_v5;
  uint u_v6;
  cri_u1 *pu_v7;
  cri_u1 *pu_v8;
  longlong l_v9;
  int i_v10;
  uint u_v11;
  ulonglong u_v12;
  uint u_v13;
  ulonglong u_v14;
  uint *pu_v15;
  longlong l_v16;
  
  arg1[0x329] = arg1[0x329] + 1;
  arg1[0x347] = 0;
  arg1[0x348] = 0;
  arg1[0x349] = 0;
  arg1[0x325] = 1;
  if (((arg1[0x1c2] != 0) && (arg1[0x1c2] != 0x40)) || (arg1[0x1c3] != 0)) {
    arg1[0x343] = arg1[0x343] + 1;
  }
  FUN_140054820(arg1);  // the exe passes rcx through
  pu_v7 = (cri_u1 *)(arg2 & 0xfffffffffffffffc);
  i_v10 = (int)arg2 * 8 + (int)pu_v7 * -8;
  b_v5 = (byte)i_v10;
  u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]) << (b_v5 & 0x1f);
  u_v13 = CONCAT31(CONCAT21(CONCAT11(pu_v7[4],pu_v7[5]),pu_v7[6]),pu_v7[7]);
  if (i_v10 == 0) {
    *arg1 = u_v11;
  }
  else {
    u_v6 = u_v13 >> (0x20 - b_v5 & 0x1f);
    u_v13 = u_v13 << (b_v5 & 0x1f);
    *arg1 = u_v6 | u_v11;
  }
  pu_v8 = pu_v7 + 0xc;
  u_v11 = CONCAT31(CONCAT21(CONCAT11(pu_v7[8],pu_v7[9]),pu_v7[10]),pu_v7[0xb]);
  if (i_v10 < 0x14) {
    i_v10 = i_v10 + 0xc;
    u_v6 = u_v13 << 0xc;
    arg1[1] = u_v13 >> 0x14;
  }
  else {
    i_v10 = i_v10 + -0x14;
    if (i_v10 == 0) {
      arg1[1] = u_v13 >> 0x14;
    }
    else {
      u_v6 = u_v11 >> (0xc - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[1] = (u_v6 | u_v13) >> 0x14;
    }
    u_v3 = *pu_v8;
    pu_v8 = pu_v7 + 0x10;
    u_v6 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,pu_v7[0xd]),pu_v7[0xe]),pu_v7[0xf]);
  }
  if (i_v10 < 0x14) {
    i_v10 = i_v10 + 0xc;
    u_v13 = u_v6 << 0xc;
    arg1[2] = u_v6 >> 0x14;
  }
  else {
    i_v10 = i_v10 + -0x14;
    if (i_v10 == 0) {
      arg1[2] = u_v6 >> 0x14;
    }
    else {
      u_v13 = u_v11 >> (0xc - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[2] = (u_v13 | u_v6) >> 0x14;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v13 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  if (i_v10 < 0x1c) {
    i_v10 = i_v10 + 4;
    u_v6 = u_v13 << 4;
    arg1[3] = u_v13 >> 0x1c;
  }
  else {
    i_v10 = i_v10 + -0x1c;
    if (i_v10 == 0) {
      arg1[3] = u_v13 >> 0x1c;
    }
    else {
      u_v6 = u_v11 >> (4 - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[3] = (u_v6 | u_v13) >> 0x1c;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v6 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  if (i_v10 < 0x1c) {
    i_v10 = i_v10 + 4;
    u_v13 = u_v6 << 4;
    arg1[4] = u_v6 >> 0x1c;
  }
  else {
    i_v10 = i_v10 + -0x1c;
    if (i_v10 == 0) {
      arg1[4] = u_v6 >> 0x1c;
    }
    else {
      u_v13 = u_v11 >> (4 - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[4] = (u_v13 | u_v6) >> 0x1c;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v13 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  if (i_v10 < 0xe) {
    i_v10 = i_v10 + 0x12;
    u_v6 = u_v13 << 0x12;
    arg1[5] = u_v13 >> 0xe;
  }
  else {
    i_v10 = i_v10 + -0xe;
    if (i_v10 == 0) {
      arg1[5] = u_v13 >> 0xe;
    }
    else {
      u_v6 = u_v11 >> (0x12 - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[5] = (u_v6 | u_v13) >> 0xe;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v6 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  if (i_v10 < 0x1f) {
    i_v10 = i_v10 + 1;
    u_v13 = u_v6 * 2;
    arg1[6] = u_v6 >> 0x1f;
  }
  else {
    i_v10 = i_v10 + -0x1f;
    if (i_v10 == 0) {
      arg1[6] = u_v6 >> 0x1f;
    }
    else {
      u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[6] = (u_v13 | u_v6) >> 0x1f;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v13 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  if (i_v10 < 0x16) {
    i_v10 = i_v10 + 10;
    u_v6 = u_v13 << 10;
    arg1[7] = u_v13 >> 0x16;
  }
  else {
    i_v10 = i_v10 + -0x16;
    if (i_v10 == 0) {
      arg1[7] = u_v13 >> 0x16;
    }
    else {
      u_v6 = u_v11 >> (10 - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[7] = (u_v6 | u_v13) >> 0x16;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v6 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  if (i_v10 < 0x1f) {
    i_v10 = i_v10 + 1;
    u_v13 = u_v6 * 2;
    arg1[8] = u_v6 >> 0x1f;
  }
  else {
    i_v10 = i_v10 + -0x1f;
    if (i_v10 == 0) {
      arg1[8] = u_v6 >> 0x1f;
    }
    else {
      u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[8] = (u_v13 | u_v6) >> 0x1f;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v13 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  if (i_v10 < 0x1f) {
    i_v10 = i_v10 + 1;
    u_v6 = u_v13 * 2;
    arg1[9] = u_v13 >> 0x1f;
  }
  else {
    i_v10 = i_v10 + -0x1f;
    if (i_v10 == 0) {
      arg1[9] = u_v13 >> 0x1f;
    }
    else {
      u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
      u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
      arg1[9] = (u_v6 | u_v13) >> 0x1f;
    }
    pu_v7 = pu_v8 + 1;
    u_v3 = *pu_v8;
    pu_v1 = pu_v8 + 2;
    pu_v2 = pu_v8 + 3;
    pu_v8 = pu_v8 + 4;
    u_v6 = u_v11;
    u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
  }
  u_v12 = (ulonglong)u_v11;
  l_v9 = 0x40;
  if (arg1[9] != 0) {
    pu_v15 = arg1 + 10;
    l_v16 = 0x40;
    do {
      if (i_v10 < 0x18) {
        i_v10 = i_v10 + 8;
        u_v11 = u_v6 >> 0x18;
        u_v6 = u_v6 << 8;
        *pu_v15 = u_v11;
      }
      else {
        i_v10 = i_v10 + -0x18;
        u_v11 = (uint)u_v12;
        if (i_v10 == 0) {
          *pu_v15 = u_v6 >> 0x18;
          u_v6 = u_v11;
        }
        else {
          *pu_v15 = (u_v11 >> (8 - (byte)i_v10 & 0x1f) | u_v6) >> 0x18;
          u_v6 = u_v11 << ((byte)i_v10 & 0x1f);
        }
        u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
        pu_v8 = pu_v8 + 4;
      }
      pu_v15 = pu_v15 + 1;
      l_v16 = l_v16 + -1;
    } while (l_v16 != 0);
  }
  if (i_v10 < 0x1f) {
    i_v10 = i_v10 + 1;
    u_v14 = (ulonglong)(u_v6 * 2);
    arg1[0x4a] = u_v6 >> 0x1f;
  }
  else {
    i_v10 = i_v10 + -0x1f;
    if (i_v10 == 0) {
      arg1[0x4a] = u_v6 >> 0x1f;
      u_v14 = u_v12;
    }
    else {
      arg1[0x4a] = ((uint)u_v12 >> (1 - (byte)i_v10 & 0x1f) | u_v6) >> 0x1f;
      u_v14 = (ulonglong)((uint)u_v12 << ((byte)i_v10 & 0x1f));
    }
    u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
    pu_v8 = pu_v8 + 4;
  }
  if (arg1[0x4a] != 0) {
    pu_v15 = arg1 + 0x4b;
    do {
      u_v11 = (uint)u_v14;
      if (i_v10 < 0x18) {
        i_v10 = i_v10 + 8;
        u_v4 = u_v14 >> 0x18;
        u_v14 = (ulonglong)(u_v11 << 8);
        *pu_v15 = (uint)u_v4;
      }
      else {
        i_v10 = i_v10 + -0x18;
        if (i_v10 == 0) {
          *pu_v15 = u_v11 >> 0x18;
          u_v14 = u_v12;
        }
        else {
          *pu_v15 = ((uint)u_v12 >> (8 - (byte)i_v10 & 0x1f) | u_v11) >> 0x18;
          u_v14 = (ulonglong)((uint)u_v12 << ((byte)i_v10 & 0x1f));
        }
        u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
        pu_v8 = pu_v8 + 4;
      }
      pu_v15 = pu_v15 + 1;
      l_v9 = l_v9 + -1;
    } while (l_v9 != 0);
  }
  FUN_1400549b0(arg1);
  FUN_140054b60(arg1);  // FUN_1400549b0 keeps rcx
  if (arg1[0x1b1] == 0) {
    arg1[0x343] = arg1[0x343] + 1;
  }
  if (arg1[0x1b2] == 0) {
    arg1[0x343] = arg1[0x343] + 1;
  }
  if ((arg1[3] == 0) || (4 < arg1[3])) {
    arg1[0x343] = arg1[0x343] + 1;
  }
  if ((arg1[4] == 0) || (8 < arg1[4])) {
    arg1[0x343] = arg1[0x343] + 1;
  }
  arg1[0x1c2] = 0x10;
  i_v10 = i_v10 + -0x39 + ((int)pu_v8 - (int)arg2) * 8;
  arg1[0x1c3] = 1;
  return (longlong)((int)(i_v10 + (i_v10 >> 0x1f & 7U)) >> 3) + arg2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140055410
longlong FUN_140055410(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  ulonglong arg2 = cri_p1;
  int i_v1;
  cri_u1 *pu_v2;
  uint u_v3;
  
  *(int *)((char *)arg1 + 0xca8) = *(int *)((char *)arg1 + 0xca8) + 1;
  *(cri_u4 *)((char *)arg1 + 0xc94) = 1;
  if (((*(int *)((char *)arg1 + 0x708) != 0) && (*(int *)((char *)arg1 + 0x708) != 0x80)) ||
     (*(int *)((char *)arg1 + 0x70c) != 0)) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  pu_v2 = (cri_u1 *)(arg2 & 0xfffffffffffffffc);
  i_v1 = (int)arg2 * 8 + (int)pu_v2 * -8;
  u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v2,pu_v2[1]),pu_v2[2]),pu_v2[3]) <<
          ((byte)i_v1 & 0x1f);
  if (i_v1 == 0) {
    *(uint *)((char *)arg1 + 0x22c) = u_v3;
  }
  else {
    *(uint *)((char *)arg1 + 0x22c) =
         CONCAT31(CONCAT21(CONCAT11(pu_v2[4],pu_v2[5]),pu_v2[6]),pu_v2[7]) >>
         (0x20 - (byte)i_v1 & 0x1f) | u_v3;
  }
  *(cri_u4 *)((char *)arg1 + 0x708) = 0;
  *(cri_u4 *)((char *)arg1 + 0x70c) = 0;
  i_v1 = i_v1 + -0x19 + (((int)pu_v2 + 8) - (int)arg2) * 8;
  return (longlong)((int)(i_v1 + (i_v1 >> 0x1f & 7U)) >> 3) + arg2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140055510
void FUN_140055510(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  void *arg2 = cri_p1;
  int arg3 = cri_p2;
  int i_v1;
  int i_v2;
  
  i_v1 = *(int *)((char *)arg1 + 0x1c54);
  i_v2 = *(int *)((char *)arg1 + 0x1c50) - i_v1;
  if (arg3 < i_v2) {
    i_v2 = arg3;
  }
  *(int *)((char *)arg1 + 0x1c54) = i_v1 + i_v2;
  memcpy((void *)((longlong)i_v1 + *(longlong *)((char *)arg1 + 0x1c48)),arg2,(longlong)i_v2);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140055550
longlong FUN_140055550(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  ulonglong arg2 = cri_p1;
  cri_u1 *pu_v1;
  cri_u1 *pu_v2;
  cri_u1 u_v3;
  ulonglong u_v4;
  byte b_v5;
  uint u_v6;
  cri_u1 *pu_v7;
  cri_u1 *pu_v8;
  int i_v9;
  int i_v10;
  uint u_v11;
  ulonglong u_v12;
  uint u_v13;
  uint u_v14;
  ulonglong u_v15;
  uint *pu_v16;
  longlong l_v17;
  longlong l_v18;
  
  *(int *)((char *)arg1 + 0xcb0) = *(int *)((char *)arg1 + 0xcb0) + 1;
  pu_v7 = (cri_u1 *)(arg2 & 0xfffffffffffffffc);
  i_v10 = (int)arg2 * 8 + (int)pu_v7 * -8;
  b_v5 = (byte)i_v10;
  u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]) << (b_v5 & 0x1f);
  u_v13 = CONCAT31(CONCAT21(CONCAT11(pu_v7[4],pu_v7[5]),pu_v7[6]),pu_v7[7]);
  if (i_v10 == 0) {
    *(uint *)((char *)arg1 + 0x234) = u_v11;
  }
  else {
    u_v6 = u_v13 >> (0x20 - b_v5 & 0x1f);
    u_v13 = u_v13 << (b_v5 & 0x1f);
    *(uint *)((char *)arg1 + 0x234) = u_v6 | u_v11;
  }
  pu_v8 = pu_v7 + 0xc;
  u_v11 = CONCAT31(CONCAT21(CONCAT11(pu_v7[8],pu_v7[9]),pu_v7[10]),pu_v7[0xb]);
  u_v12 = (ulonglong)u_v11;
  if (i_v10 < 0x1c) {
    i_v10 = i_v10 + 4;
    u_v15 = (ulonglong)(u_v13 << 4);
    *(uint *)((char *)arg1 + 0x240) = u_v13 >> 0x1c;
  }
  else {
    i_v10 = i_v10 + -0x1c;
    if (i_v10 == 0) {
      *(uint *)((char *)arg1 + 0x240) = u_v13 >> 0x1c;
      u_v15 = u_v12;
    }
    else {
      *(uint *)((char *)arg1 + 0x240) = (u_v11 >> (4 - (byte)i_v10 & 0x1f) | u_v13) >> 0x1c;
      u_v15 = (ulonglong)(u_v11 << ((byte)i_v10 & 0x1f));
    }
    u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v7[0xd]),pu_v7[0xe]),pu_v7[0xf]);
    pu_v8 = pu_v7 + 0x10;
  }
  u_v11 = (uint)u_v12;
  if (((*(int *)((char *)arg1 + 0x708) != 0) && (*(int *)((char *)arg1 + 0x708) != 0x10)) ||
     ((*(int *)((char *)arg1 + 0x70c) != 0 && (*(int *)((char *)arg1 + 0x70c) != *(int *)((char *)arg1 + 0x240)))))
  {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  i_v9 = *(int *)((char *)arg1 + 0xc94);
  if (((((i_v9 != 1) && (*(int *)((char *)arg1 + 0x240) == 1)) ||
       (((i_v9 != 1 && (*(int *)((char *)arg1 + 0x240) == 2)) ||
        ((i_v9 != 1 && (*(int *)((char *)arg1 + 0x240) == 5)))))) ||
      (((i_v9 != 3 && (*(int *)((char *)arg1 + 0x240) == 3)) ||
       ((((i_v9 != 3 && (*(int *)((char *)arg1 + 0x240) == 4)) ||
         ((i_v9 != 3 && (*(int *)((char *)arg1 + 0x240) == 7)))) ||
        ((i_v9 != 3 && (*(int *)((char *)arg1 + 0x240) == 8)))))))) ||
     (((i_v9 != 3 && (*(int *)((char *)arg1 + 0x240) == 9)) ||
      ((i_v9 != 3 && (*(int *)((char *)arg1 + 0x240) == 10)))))) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  u_v13 = (uint)u_v15;
  switch(*(cri_u4 *)((char *)arg1 + 0x240)) {
  case 1:
    if (i_v10 < 0x18) {
      i_v10 = i_v10 + 8;
      u_v13 = u_v13 << 8;
      *(int *)((char *)arg1 + 0x244) = (int)(u_v15 >> 0x18);
    }
    else {
      i_v10 = i_v10 + -0x18;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x244) = u_v13 >> 0x18;
      }
      else {
        u_v6 = u_v11 >> (8 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x244) = (u_v6 | u_v13) >> 0x18;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v6 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x248) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x248) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x248) = (u_v6 | u_v13) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v13 = u_v6 << 2;
      *(uint *)((char *)arg1 + 0x24c) = u_v6 >> 0x1e;
    }
    else {
      i_v10 = i_v10 + -0x1e;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x24c) = u_v6 >> 0x1e;
      }
      else {
        u_v13 = u_v11 >> (2 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x24c) = (u_v13 | u_v6) >> 0x1e;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v6 = u_v13 << 2;
      *(uint *)((char *)arg1 + 0x250) = u_v13 >> 0x1e;
    }
    else {
      i_v10 = i_v10 + -0x1e;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x250) = u_v13 >> 0x1e;
      }
      else {
        u_v6 = u_v11 >> (2 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x250) = (u_v6 | u_v13) >> 0x1e;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v13 = u_v6 << 2;
      *(uint *)((char *)arg1 + 0x254) = u_v6 >> 0x1e;
    }
    else {
      i_v10 = i_v10 + -0x1e;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x254) = u_v6 >> 0x1e;
      }
      else {
        u_v13 = u_v11 >> (2 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x254) = (u_v13 | u_v6) >> 0x1e;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x14) {
      i_v10 = i_v10 + 0xc;
      u_v6 = u_v13 << 0xc;
      *(uint *)(arg1 + 600) = u_v13 >> 0x14;
    }
    else {
      i_v10 = i_v10 + -0x14;
      if (i_v10 == 0) {
        *(uint *)(arg1 + 600) = u_v13 >> 0x14;
      }
      else {
        u_v6 = u_v11 >> (0xc - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)(arg1 + 600) = (u_v6 | u_v13) >> 0x14;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x18) {
      i_v10 = i_v10 + 8;
      u_v6 = u_v13 << 8;
      *(uint *)((char *)arg1 + 0x25c) = u_v13 >> 0x18;
    }
    else {
      i_v10 = i_v10 + -0x18;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x25c) = u_v13 >> 0x18;
      }
      else {
        u_v6 = u_v11 >> (8 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x25c) = (u_v6 | u_v13) >> 0x18;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x260) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x260) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x260) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v6 = u_v13 << 2;
      *(uint *)((char *)arg1 + 0x264) = u_v13 >> 0x1e;
    }
    else {
      i_v10 = i_v10 + -0x1e;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x264) = u_v13 >> 0x1e;
        u_v6 = u_v11;
      }
      else {
        *(uint *)((char *)arg1 + 0x264) = (u_v11 >> (2 - (byte)i_v10 & 0x1f) | u_v13) >> 0x1e;
        u_v6 = u_v11 << ((byte)i_v10 & 0x1f);
      }
      u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1b) {
      i_v10 = i_v10 + 5;
      *(uint *)((char *)arg1 + 0x268) = u_v6 >> 0x1b;
    }
    else {
      i_v10 = i_v10 + -0x1b;
      if (i_v10 == 0) {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x268) = u_v6 >> 0x1b;
      }
      else {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x268) = (u_v11 >> (5U - (char)i_v10 & 0x1f) | u_v6) >> 0x1b;
      }
    }
    if (*(int *)((char *)arg1 + 0x24c) != 1) {
      *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
      *(cri_u4 *)((char *)arg1 + 0x24c) = 1;
    }
    *(cri_u4 *)((char *)arg1 + 0x718) =
         *(cri_u4 *)(&DAT_1431baa10 + (ulonglong)*(uint *)((char *)arg1 + 0x24c) * 4);
    FUN_1400549b0(arg1);
    *(uint *)((char *)arg1 + 0x6d4) = *(int *)(arg1 + 600) << 0x12 | *(uint *)((char *)arg1 + 0x14);
    *(uint *)((char *)arg1 + 0x6d8) = *(int *)((char *)arg1 + 0x25c) << 10 | *(uint *)((char *)arg1 + 0x1c);
    break;
  case 2:
    if (i_v10 < 0x1d) {
      i_v10 = i_v10 + 3;
      u_v13 = u_v13 << 3;
      *(int *)((char *)arg1 + 0x26c) = (int)(u_v15 >> 0x1d);
    }
    else {
      i_v10 = i_v10 + -0x1d;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x26c) = u_v13 >> 0x1d;
      }
      else {
        u_v6 = u_v11 >> (3 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x26c) = (u_v6 | u_v13) >> 0x1d;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v6 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x270) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x270) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x270) = (u_v6 | u_v13) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (*(int *)((char *)arg1 + 0x270) != 0) {
      if (i_v10 < 0x18) {
        i_v10 = i_v10 + 8;
        u_v13 = u_v6 << 8;
        *(uint *)((char *)arg1 + 0x274) = u_v6 >> 0x18;
      }
      else {
        i_v10 = i_v10 + -0x18;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x274) = u_v6 >> 0x18;
        }
        else {
          u_v13 = u_v11 >> (8 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x274) = (u_v13 | u_v6) >> 0x18;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v13 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x18) {
        i_v10 = i_v10 + 8;
        u_v14 = u_v13 << 8;
        *(uint *)((char *)arg1 + 0x278) = u_v13 >> 0x18;
      }
      else {
        i_v10 = i_v10 + -0x18;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x278) = u_v13 >> 0x18;
        }
        else {
          u_v6 = u_v11 >> (8 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x278) = (u_v6 | u_v13) >> 0x18;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v14 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x18) {
        i_v10 = i_v10 + 8;
        u_v6 = u_v14 << 8;
        *(uint *)((char *)arg1 + 0x27c) = u_v14 >> 0x18;
      }
      else {
        i_v10 = i_v10 + -0x18;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x27c) = u_v14 >> 0x18;
          u_v6 = u_v11;
        }
        else {
          *(uint *)((char *)arg1 + 0x27c) = (u_v11 >> (8 - (byte)i_v10 & 0x1f) | u_v14) >> 0x18;
          u_v6 = u_v11 << ((byte)i_v10 & 0x1f);
        }
        u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
        pu_v8 = pu_v8 + 4;
      }
    }
    if (i_v10 < 0x12) {
      i_v10 = i_v10 + 0xe;
      u_v13 = u_v6 << 0xe;
      *(uint *)((char *)arg1 + 0x280) = u_v6 >> 0x12;
    }
    else {
      i_v10 = i_v10 + -0x12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x280) = u_v6 >> 0x12;
      }
      else {
        u_v13 = u_v11 >> (0xe - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x280) = (u_v13 | u_v6) >> 0x12;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v6 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v6 | u_v13) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x12) {
      i_v10 = i_v10 + 0xe;
      *(uint *)((char *)arg1 + 0x284) = u_v6 >> 0x12;
    }
    else {
      i_v10 = i_v10 + -0x12;
      if (i_v10 == 0) {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x284) = u_v6 >> 0x12;
      }
      else {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x284) = (u_v11 >> (0xeU - (char)i_v10 & 0x1f) | u_v6) >> 0x12;
      }
    }
    break;
  case 3:
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v11 = u_v13 * 2;
      *(int *)((char *)arg1 + 0x24) = (int)(u_v15 >> 0x1f);
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x24) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x24) = (u_v6 | u_v13) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    l_v18 = 0x40;
    if (*(int *)((char *)arg1 + 0x24) != 0) {
      pu_v16 = (uint *)((char *)arg1 + 0x28);
      l_v17 = l_v18;
      do {
        if (i_v10 < 0x18) {
          i_v10 = i_v10 + 8;
          u_v13 = u_v11 >> 0x18;
          u_v11 = u_v11 << 8;
          *pu_v16 = u_v13;
        }
        else {
          i_v10 = i_v10 + -0x18;
          u_v13 = (uint)u_v12;
          if (i_v10 == 0) {
            *pu_v16 = u_v11 >> 0x18;
            u_v11 = u_v13;
          }
          else {
            *pu_v16 = (u_v13 >> (8 - (byte)i_v10 & 0x1f) | u_v11) >> 0x18;
            u_v11 = u_v13 << ((byte)i_v10 & 0x1f);
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        pu_v16 = pu_v16 + 1;
        l_v17 = l_v17 + -1;
      } while (l_v17 != 0);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v11 * 2;
      *(uint *)((char *)arg1 + 0x128) = u_v11 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x128) = u_v11 >> 0x1f;
      }
      else {
        u_v6 = u_v13 >> (1 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x128) = (u_v6 | u_v11) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (*(int *)((char *)arg1 + 0x128) != 0) {
      pu_v16 = (uint *)(arg1 + 300);
      l_v17 = l_v18;
      do {
        if (i_v10 < 0x18) {
          i_v10 = i_v10 + 8;
          u_v11 = u_v13 >> 0x18;
          u_v13 = u_v13 << 8;
          *pu_v16 = u_v11;
        }
        else {
          i_v10 = i_v10 + -0x18;
          u_v11 = (uint)u_v12;
          if (i_v10 == 0) {
            *pu_v16 = u_v13 >> 0x18;
            u_v13 = u_v11;
          }
          else {
            *pu_v16 = (u_v11 >> (8 - (byte)i_v10 & 0x1f) | u_v13) >> 0x18;
            u_v13 = u_v11 << ((byte)i_v10 & 0x1f);
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        pu_v16 = pu_v16 + 1;
        l_v17 = l_v17 + -1;
      } while (l_v17 != 0);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v11 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x358) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x358) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x358) = (u_v6 | u_v13) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (*(int *)((char *)arg1 + 0x358) != 0) {
      pu_v16 = (uint *)((char *)arg1 + 0x35c);
      l_v17 = l_v18;
      do {
        if (i_v10 < 0x18) {
          i_v10 = i_v10 + 8;
          u_v13 = u_v11 >> 0x18;
          u_v11 = u_v11 << 8;
          *pu_v16 = u_v13;
        }
        else {
          i_v10 = i_v10 + -0x18;
          u_v13 = (uint)u_v12;
          if (i_v10 == 0) {
            *pu_v16 = u_v11 >> 0x18;
            u_v11 = u_v13;
          }
          else {
            *pu_v16 = (u_v13 >> (8 - (byte)i_v10 & 0x1f) | u_v11) >> 0x18;
            u_v11 = u_v13 << ((byte)i_v10 & 0x1f);
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        pu_v16 = pu_v16 + 1;
        l_v17 = l_v17 + -1;
      } while (l_v17 != 0);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v15 = (ulonglong)(u_v11 * 2);
      *(uint *)((char *)arg1 + 0x45c) = u_v11 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x45c) = u_v11 >> 0x1f;
        u_v15 = u_v12;
      }
      else {
        *(uint *)((char *)arg1 + 0x45c) = ((uint)u_v12 >> (1 - (byte)i_v10 & 0x1f) | u_v11) >> 0x1f;
        u_v15 = (ulonglong)((uint)u_v12 << ((byte)i_v10 & 0x1f));
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (*(int *)((char *)arg1 + 0x45c) != 0) {
      pu_v16 = (uint *)((char *)arg1 + 0x460);
      do {
        u_v11 = (uint)u_v15;
        if (i_v10 < 0x18) {
          i_v10 = i_v10 + 8;
          u_v4 = u_v15 >> 0x18;
          u_v15 = (ulonglong)(u_v11 << 8);
          *pu_v16 = (uint)u_v4;
        }
        else {
          i_v10 = i_v10 + -0x18;
          if (i_v10 == 0) {
            *pu_v16 = u_v11 >> 0x18;
            u_v15 = u_v12;
          }
          else {
            *pu_v16 = ((uint)u_v12 >> (8 - (byte)i_v10 & 0x1f) | u_v11) >> 0x18;
            u_v15 = (ulonglong)((uint)u_v12 << ((byte)i_v10 & 0x1f));
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        pu_v16 = pu_v16 + 1;
        l_v18 = l_v18 + -1;
      } while (l_v18 != 0);
    }
    FUN_140054b60(arg1);
    break;
  case 4:
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v13 * 2;
      *(int *)((char *)arg1 + 0x59c) = (int)(u_v15 >> 0x1f);
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x59c) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x59c) = (u_v6 | u_v13) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x18) {
      i_v10 = i_v10 + 8;
      u_v6 = u_v13 << 8;
      *(uint *)((char *)arg1 + 0x5a0) = u_v13 >> 0x18;
    }
    else {
      i_v10 = i_v10 + -0x18;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x5a0) = u_v13 >> 0x18;
      }
      else {
        u_v6 = u_v11 >> (8 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x5a0) = (u_v6 | u_v13) >> 0x18;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x5a4) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x5a4) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x5a4) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x19) {
      i_v10 = i_v10 + 7;
      u_v6 = u_v13 << 7;
      *(uint *)((char *)arg1 + 0x5a8) = u_v13 >> 0x19;
    }
    else {
      i_v10 = i_v10 + -0x19;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x5a8) = u_v13 >> 0x19;
      }
      else {
        u_v6 = u_v11 >> (7 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x5a8) = (u_v6 | u_v13) >> 0x19;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0xc) {
      i_v10 = i_v10 + 0x14;
      u_v6 = u_v13 << 0x14;
      *(uint *)((char *)arg1 + 0x5ac) = u_v13 >> 0xc;
    }
    else {
      i_v10 = i_v10 + -0xc;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x5ac) = u_v13 >> 0xc;
      }
      else {
        u_v6 = u_v11 >> (0x14 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x5ac) = (u_v6 | u_v13) >> 0xc;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 10) {
      i_v10 = i_v10 + 0x16;
      u_v6 = u_v13 << 0x16;
      *(uint *)((char *)arg1 + 0x5b0) = u_v13 >> 10;
    }
    else {
      i_v10 = i_v10 + -10;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x5b0) = u_v13 >> 10;
      }
      else {
        u_v6 = u_v11 >> (0x16 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x5b0) = (u_v6 | u_v13) >> 10;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 10) {
      i_v10 = i_v10 + 0x16;
      *(uint *)((char *)arg1 + 0x5b4) = u_v13 >> 10;
    }
    else {
      i_v10 = i_v10 + -10;
      if (i_v10 == 0) {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x5b4) = u_v13 >> 10;
      }
      else {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x5b4) = (u_v11 >> (0x16U - (char)i_v10 & 0x1f) | u_v13) >> 10;
      }
    }
    break;
  case 5:
    *(cri_u4 *)((char *)arg1 + 0x710) = 1;
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v13 = u_v13 << 2;
      *(int *)((char *)arg1 + 0x288) = (int)(u_v15 >> 0x1e);
    }
    else {
      i_v10 = i_v10 + -0x1e;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x288) = u_v13 >> 0x1e;
      }
      else {
        u_v6 = u_v11 >> (2 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x288) = (u_v6 | u_v13) >> 0x1e;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1c) {
      i_v10 = i_v10 + 4;
      u_v6 = u_v13 << 4;
      *(uint *)((char *)arg1 + 0x28c) = u_v13 >> 0x1c;
    }
    else {
      i_v10 = i_v10 + -0x1c;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x28c) = u_v13 >> 0x1c;
      }
      else {
        u_v6 = u_v11 >> (4 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x28c) = (u_v6 | u_v13) >> 0x1c;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (*(int *)((char *)arg1 + 0x288) == 1) {
      if (i_v10 < 0x12) {
        i_v10 = i_v10 + 0xe;
        u_v13 = u_v6 << 0xe;
        *(uint *)((char *)arg1 + 0x290) = u_v6 >> 0x12;
      }
      else {
        i_v10 = i_v10 + -0x12;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x290) = u_v6 >> 0x12;
        }
        else {
          u_v13 = u_v11 >> (0xe - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x290) = (u_v13 | u_v6) >> 0x12;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v13 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1f) {
        i_v10 = i_v10 + 1;
        u_v6 = u_v13 * 2;
        *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
      }
      else {
        i_v10 = i_v10 + -0x1f;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
        }
        else {
          u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x18) = (u_v6 | u_v13) >> 0x1f;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v6 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x12) {
        i_v10 = i_v10 + 0xe;
        u_v13 = u_v6 << 0xe;
        *(uint *)((char *)arg1 + 0x294) = u_v6 >> 0x12;
      }
      else {
        i_v10 = i_v10 + -0x12;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x294) = u_v6 >> 0x12;
        }
        else {
          u_v13 = u_v11 >> (0xe - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x294) = (u_v13 | u_v6) >> 0x12;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v13 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1b) {
        i_v10 = i_v10 + 5;
        u_v6 = u_v13 << 5;
        *(uint *)((char *)arg1 + 0x298) = u_v13 >> 0x1b;
      }
      else {
        i_v10 = i_v10 + -0x1b;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x298) = u_v13 >> 0x1b;
        }
        else {
          u_v6 = u_v11 >> (5 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x298) = (u_v6 | u_v13) >> 0x1b;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v6 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1b) {
        i_v10 = i_v10 + 5;
        u_v13 = u_v6 << 5;
        *(uint *)((char *)arg1 + 0x29c) = u_v6 >> 0x1b;
      }
      else {
        i_v10 = i_v10 + -0x1b;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x29c) = u_v6 >> 0x1b;
        }
        else {
          u_v13 = u_v11 >> (5 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x29c) = (u_v13 | u_v6) >> 0x1b;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v13 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1b) {
        i_v10 = i_v10 + 5;
        u_v6 = u_v13 << 5;
        *(uint *)((char *)arg1 + 0x2a0) = u_v13 >> 0x1b;
      }
      else {
        i_v10 = i_v10 + -0x1b;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x2a0) = u_v13 >> 0x1b;
        }
        else {
          u_v6 = u_v11 >> (5 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x2a0) = (u_v6 | u_v13) >> 0x1b;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v6 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1b) {
        i_v10 = i_v10 + 5;
        *(uint *)((char *)arg1 + 0x2a4) = u_v6 >> 0x1b;
      }
      else {
        i_v10 = i_v10 + -0x1b;
        if (i_v10 == 0) {
          pu_v8 = pu_v8 + 4;
          *(uint *)((char *)arg1 + 0x2a4) = u_v6 >> 0x1b;
        }
        else {
          pu_v8 = pu_v8 + 4;
          *(uint *)((char *)arg1 + 0x2a4) = (u_v11 >> (5U - (char)i_v10 & 0x1f) | u_v6) >> 0x1b;
        }
      }
    }
    else if (*(int *)((char *)arg1 + 0x288) == 3) {
      if (i_v10 < 0x1f) {
        i_v10 = i_v10 + 1;
        u_v13 = u_v6 * 2;
        *(uint *)((char *)arg1 + 0x2a8) = u_v6 >> 0x1f;
      }
      else {
        i_v10 = i_v10 + -0x1f;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x2a8) = u_v6 >> 0x1f;
        }
        else {
          u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x2a8) = (u_v13 | u_v6) >> 0x1f;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v13 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (*(int *)((char *)arg1 + 0x2a8) != 0) {
        if (i_v10 < 0x1f) {
          i_v10 = i_v10 + 1;
          u_v6 = u_v13 >> 0x1f;
          u_v13 = u_v13 * 2;
          *(uint *)((char *)arg1 + 0x2ac) = u_v6;
        }
        else {
          i_v10 = i_v10 + -0x1f;
          if (i_v10 == 0) {
            *(uint *)((char *)arg1 + 0x2ac) = u_v13 >> 0x1f;
            u_v13 = u_v11;
          }
          else {
            *(uint *)((char *)arg1 + 0x2ac) = (u_v11 >> (1 - (byte)i_v10 & 0x1f) | u_v13) >> 0x1f;
            u_v13 = u_v11 << ((byte)i_v10 & 0x1f);
          }
          u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
      }
      if (i_v10 < 0x1d) {
        i_v10 = i_v10 + 3;
        u_v6 = u_v13 << 3;
        *(uint *)((char *)arg1 + 0x2b0) = u_v13 >> 0x1d;
      }
      else {
        i_v10 = i_v10 + -0x1d;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x2b0) = u_v13 >> 0x1d;
        }
        else {
          u_v6 = u_v11 >> (3 - (byte)i_v10 & 0x1f);
          u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x2b0) = (u_v6 | u_v13) >> 0x1d;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v6 = u_v11;
        u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1d) {
        i_v10 = i_v10 + 3;
        *(uint *)((char *)arg1 + 0x2b4) = u_v6 >> 0x1d;
      }
      else {
        i_v10 = i_v10 + -0x1d;
        if (i_v10 == 0) {
          pu_v8 = pu_v8 + 4;
          *(uint *)((char *)arg1 + 0x2b4) = u_v6 >> 0x1d;
        }
        else {
          pu_v8 = pu_v8 + 4;
          *(uint *)((char *)arg1 + 0x2b4) = (u_v11 >> (3U - (char)i_v10 & 0x1f) | u_v6) >> 0x1d;
        }
      }
    }
    break;
  default:
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
    break;
  case 7:
    FUN_140054a40(arg1);
    i_v9 = 0;
    if (0 < *(int *)((char *)arg1 + 0x238)) {
      pu_v16 = (uint *)((char *)arg1 + 0x56c);
      do {
        u_v11 = (uint)u_v15;
        if (i_v10 < 0x10) {
          i_v10 = i_v10 + 0x10;
          u_v13 = u_v11 << 0x10;
          pu_v16[-3] = (uint)(u_v15 >> 0x10) & 0xffff;
        }
        else {
          i_v10 = i_v10 + -0x10;
          u_v13 = (uint)u_v12;
          if (i_v10 == 0) {
            pu_v16[-3] = u_v11 >> 0x10;
          }
          else {
            u_v6 = u_v13 >> (0x10 - (byte)i_v10 & 0x1f);
            u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
            pu_v16[-3] = (u_v6 | u_v11) >> 0x10;
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        if (i_v10 < 0x1f) {
          i_v10 = i_v10 + 1;
          u_v11 = u_v13 * 2;
          *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
        }
        else {
          i_v10 = i_v10 + -0x1f;
          u_v11 = (uint)u_v12;
          if (i_v10 == 0) {
            *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
          }
          else {
            u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
            u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
            *(uint *)((char *)arg1 + 0x18) = (u_v6 | u_v13) >> 0x1f;
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        if (i_v10 < 0x10) {
          i_v10 = i_v10 + 0x10;
          u_v13 = u_v11 << 0x10;
          *pu_v16 = u_v11 >> 0x10;
        }
        else {
          i_v10 = i_v10 + -0x10;
          u_v13 = (uint)u_v12;
          if (i_v10 == 0) {
            *pu_v16 = u_v11 >> 0x10;
          }
          else {
            u_v6 = u_v13 >> (0x10 - (byte)i_v10 & 0x1f);
            u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
            *pu_v16 = (u_v6 | u_v11) >> 0x10;
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        if (i_v10 < 0x1f) {
          i_v10 = i_v10 + 1;
          u_v15 = (ulonglong)(u_v13 * 2);
          *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
        }
        else {
          i_v10 = i_v10 + -0x1f;
          if (i_v10 == 0) {
            *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
            u_v15 = u_v12 & 0xffffffff;
          }
          else {
            u_v15 = (ulonglong)((uint)u_v12 << ((byte)i_v10 & 0x1f));
            *(uint *)((char *)arg1 + 0x18) = ((uint)u_v12 >> (1 - (byte)i_v10 & 0x1f) | u_v13) >> 0x1f
            ;
          }
          u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
          pu_v8 = pu_v8 + 4;
        }
        i_v9 = i_v9 + 1;
        pu_v16 = pu_v16 + 1;
      } while (i_v9 < *(int *)((char *)arg1 + 0x238));
    }
    break;
  case 8:
    if (i_v10 < 0x1c) {
      i_v10 = i_v10 + 4;
      u_v11 = u_v13 << 4;
      *(int *)((char *)arg1 + 0x304) = (int)(u_v15 >> 0x1c);
    }
    else {
      i_v10 = i_v10 + -0x1c;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x304) = u_v13 >> 0x1c;
      }
      else {
        u_v6 = u_v11 >> (4 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x304) = (u_v6 | u_v13) >> 0x1c;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1c) {
      i_v10 = i_v10 + 4;
      u_v13 = u_v11 << 4;
      *(uint *)((char *)arg1 + 0x308) = u_v11 >> 0x1c;
    }
    else {
      i_v10 = i_v10 + -0x1c;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x308) = u_v11 >> 0x1c;
      }
      else {
        u_v6 = u_v13 >> (4 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x308) = (u_v6 | u_v11) >> 0x1c;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1c) {
      i_v10 = i_v10 + 4;
      u_v11 = u_v13 << 4;
      *(uint *)((char *)arg1 + 0x30c) = u_v13 >> 0x1c;
    }
    else {
      i_v10 = i_v10 + -0x1c;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x30c) = u_v13 >> 0x1c;
      }
      else {
        u_v6 = u_v11 >> (4 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x30c) = (u_v6 | u_v13) >> 0x1c;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1c) {
      i_v10 = i_v10 + 4;
      u_v13 = u_v11 << 4;
      *(uint *)((char *)arg1 + 0x310) = u_v11 >> 0x1c;
    }
    else {
      i_v10 = i_v10 + -0x1c;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x310) = u_v11 >> 0x1c;
      }
      else {
        u_v6 = u_v13 >> (4 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x310) = (u_v6 | u_v11) >> 0x1c;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v11 = u_v13 << 2;
      *(uint *)((char *)arg1 + 0x314) = u_v13 >> 0x1e;
    }
    else {
      i_v10 = i_v10 + -0x1e;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x314) = u_v13 >> 0x1e;
      }
      else {
        u_v6 = u_v11 >> (2 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x314) = (u_v6 | u_v13) >> 0x1e;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v13 = u_v11 << 2;
      *(uint *)((char *)arg1 + 0x318) = u_v11 >> 0x1e;
    }
    else {
      i_v10 = i_v10 + -0x1e;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x318) = u_v11 >> 0x1e;
      }
      else {
        u_v6 = u_v13 >> (2 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x318) = (u_v6 | u_v11) >> 0x1e;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v11 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x31c) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x31c) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x31c) = (u_v6 | u_v13) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v11 * 2;
      *(uint *)(arg1 + 800) = u_v11 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)(arg1 + 800) = u_v11 >> 0x1f;
      }
      else {
        u_v6 = u_v13 >> (1 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)(arg1 + 800) = (u_v6 | u_v11) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v11 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x324) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x324) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x324) = (u_v6 | u_v13) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v11 * 2;
      *(uint *)((char *)arg1 + 0x328) = u_v11 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x328) = u_v11 >> 0x1f;
      }
      else {
        u_v6 = u_v13 >> (1 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x328) = (u_v6 | u_v11) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v11 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x32c) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x32c) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x32c) = (u_v6 | u_v13) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v11 * 2;
      *(uint *)((char *)arg1 + 0x330) = u_v11 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x330) = u_v11 >> 0x1f;
      }
      else {
        u_v6 = u_v13 >> (1 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x330) = (u_v6 | u_v11) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v11 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x334) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x334) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x334) = (u_v6 | u_v13) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v11 * 2;
      *(uint *)((char *)arg1 + 0x338) = u_v11 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v13 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x338) = u_v11 >> 0x1f;
      }
      else {
        u_v6 = u_v13 >> (1 - (byte)i_v10 & 0x1f);
        u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x338) = (u_v6 | u_v11) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v11 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x33c) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      u_v11 = (uint)u_v12;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x33c) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x33c) = (u_v6 | u_v13) >> 0x1f;
      }
      u_v12 = (ulonglong)CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    u_v13 = (uint)u_v12;
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v12 = (ulonglong)(u_v11 * 2);
      *(uint *)((char *)arg1 + 0x340) = u_v11 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x340) = u_v11 >> 0x1f;
      }
      else {
        u_v12 = (ulonglong)(u_v13 << ((byte)i_v10 & 0x1f));
        *(uint *)((char *)arg1 + 0x340) = (u_v13 >> (1 - (byte)i_v10 & 0x1f) | u_v11) >> 0x1f;
      }
      u_v13 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (*(int *)((char *)arg1 + 0x340) != 0) {
      u_v11 = (uint)u_v12;
      if (i_v10 < 0x1f) {
        i_v10 = i_v10 + 1;
        u_v11 = u_v11 * 2;
        *(int *)((char *)arg1 + 0x344) = (int)(u_v12 >> 0x1f);
      }
      else {
        i_v10 = i_v10 + -0x1f;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x344) = u_v11 >> 0x1f;
        }
        else {
          u_v6 = u_v13 >> (1 - (byte)i_v10 & 0x1f);
          u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x344) = (u_v6 | u_v11) >> 0x1f;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v11 = u_v13;
        u_v13 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1d) {
        i_v10 = i_v10 + 3;
        u_v6 = u_v11 << 3;
        *(uint *)((char *)arg1 + 0x348) = u_v11 >> 0x1d;
      }
      else {
        i_v10 = i_v10 + -0x1d;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x348) = u_v11 >> 0x1d;
        }
        else {
          u_v6 = u_v13 >> (3 - (byte)i_v10 & 0x1f);
          u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x348) = (u_v6 | u_v11) >> 0x1d;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v6 = u_v13;
        u_v13 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x1f) {
        i_v10 = i_v10 + 1;
        u_v11 = u_v6 * 2;
        *(uint *)((char *)arg1 + 0x34c) = u_v6 >> 0x1f;
      }
      else {
        i_v10 = i_v10 + -0x1f;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x34c) = u_v6 >> 0x1f;
        }
        else {
          u_v11 = u_v13 >> (1 - (byte)i_v10 & 0x1f);
          u_v13 = u_v13 << ((byte)i_v10 & 0x1f);
          *(uint *)((char *)arg1 + 0x34c) = (u_v11 | u_v6) >> 0x1f;
        }
        pu_v7 = pu_v8 + 1;
        u_v3 = *pu_v8;
        pu_v1 = pu_v8 + 2;
        pu_v2 = pu_v8 + 3;
        pu_v8 = pu_v8 + 4;
        u_v11 = u_v13;
        u_v13 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
      }
      if (i_v10 < 0x19) {
        i_v10 = i_v10 + 7;
        u_v6 = u_v11 << 7;
        *(uint *)((char *)arg1 + 0x350) = u_v11 >> 0x19;
      }
      else {
        i_v10 = i_v10 + -0x19;
        if (i_v10 == 0) {
          *(uint *)((char *)arg1 + 0x350) = u_v11 >> 0x19;
          u_v6 = u_v13;
        }
        else {
          *(uint *)((char *)arg1 + 0x350) = (u_v13 >> (7 - (byte)i_v10 & 0x1f) | u_v11) >> 0x19;
          u_v6 = u_v13 << ((byte)i_v10 & 0x1f);
        }
        u_v13 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
        pu_v8 = pu_v8 + 4;
      }
      if (i_v10 < 0x18) {
        i_v10 = i_v10 + 8;
        *(uint *)((char *)arg1 + 0x354) = u_v6 >> 0x18;
      }
      else {
        i_v10 = i_v10 + -0x18;
        if (i_v10 == 0) {
          pu_v8 = pu_v8 + 4;
          *(uint *)((char *)arg1 + 0x354) = u_v6 >> 0x18;
        }
        else {
          pu_v8 = pu_v8 + 4;
          *(uint *)((char *)arg1 + 0x354) = (u_v13 >> (8U - (char)i_v10 & 0x1f) | u_v6) >> 0x18;
        }
      }
    }
    FUN_1400549b0(arg1);
    FUN_140054a80(arg1);  // FUN_1400549b0 keeps rcx
    if (*(int *)((char *)arg1 + 0xc0c) == 0) {
      *(cri_u4 *)((char *)arg1 + 0x1c54) = 0;
    }
    break;
  case 9:
    *(cri_u4 *)((char *)arg1 + 0x714) = 1;
    if (i_v10 < 0x16) {
      i_v10 = i_v10 + 10;
      u_v13 = u_v13 << 10;
      *(int *)((char *)arg1 + 0x584) = (int)(u_v15 >> 0x16);
    }
    else {
      i_v10 = i_v10 + -0x16;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x584) = u_v13 >> 0x16;
      }
      else {
        u_v6 = u_v11 >> (10 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x584) = (u_v6 | u_v13) >> 0x16;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v6 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v6 | u_v13) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x11) {
      i_v10 = i_v10 + 0xf;
      u_v13 = u_v6 << 0xf;
      *(uint *)((char *)arg1 + 0x588) = u_v6 >> 0x11;
    }
    else {
      i_v10 = i_v10 + -0x11;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x588) = u_v6 >> 0x11;
      }
      else {
        u_v13 = u_v11 >> (0xf - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x588) = (u_v13 | u_v6) >> 0x11;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v6 = u_v13 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v13 >> 0x1f;
      }
      else {
        u_v6 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v6 | u_v13) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x11) {
      i_v10 = i_v10 + 0xf;
      u_v13 = u_v6 << 0xf;
      *(uint *)((char *)arg1 + 0x58c) = u_v6 >> 0x11;
    }
    else {
      i_v10 = i_v10 + -0x11;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x58c) = u_v6 >> 0x11;
      }
      else {
        u_v13 = u_v11 >> (0xf - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x58c) = (u_v13 | u_v6) >> 0x11;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v6 = u_v13 << 2;
      *(uint *)((char *)arg1 + 0x590) = u_v13 >> 0x1e;
    }
    else {
      i_v10 = i_v10 + -0x1e;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x590) = u_v13 >> 0x1e;
      }
      else {
        u_v6 = u_v11 >> (2 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x590) = (u_v6 | u_v13) >> 0x1e;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x594) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x594) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x594) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      *(uint *)((char *)arg1 + 0x598) = u_v13 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x598) = u_v13 >> 0x1f;
      }
      else {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x598) = (u_v11 >> (1U - (char)i_v10 & 0x1f) | u_v13) >> 0x1f;
      }
    }
    break;
  case 10:
    if (i_v10 < 0x1e) {
      i_v10 = i_v10 + 2;
      u_v13 = u_v13 << 2;
      *(int *)((char *)arg1 + 0x578) = (int)(u_v15 >> 0x1e);
    }
    else {
      i_v10 = i_v10 + -0x1e;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x578) = u_v13 >> 0x1e;
      }
      else {
        u_v6 = u_v11 >> (2 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x578) = (u_v6 | u_v13) >> 0x1e;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x16) {
      i_v10 = i_v10 + 10;
      u_v6 = u_v13 << 10;
      *(uint *)((char *)arg1 + 0x57c) = u_v13 >> 0x16;
    }
    else {
      i_v10 = i_v10 + -0x16;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x57c) = u_v13 >> 0x16;
      }
      else {
        u_v6 = u_v11 >> (10 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x57c) = (u_v6 | u_v13) >> 0x16;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v6 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x1f) {
      i_v10 = i_v10 + 1;
      u_v13 = u_v6 * 2;
      *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
    }
    else {
      i_v10 = i_v10 + -0x1f;
      if (i_v10 == 0) {
        *(uint *)((char *)arg1 + 0x18) = u_v6 >> 0x1f;
      }
      else {
        u_v13 = u_v11 >> (1 - (byte)i_v10 & 0x1f);
        u_v11 = u_v11 << ((byte)i_v10 & 0x1f);
        *(uint *)((char *)arg1 + 0x18) = (u_v13 | u_v6) >> 0x1f;
      }
      pu_v7 = pu_v8 + 1;
      u_v3 = *pu_v8;
      pu_v1 = pu_v8 + 2;
      pu_v2 = pu_v8 + 3;
      pu_v8 = pu_v8 + 4;
      u_v13 = u_v11;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v7),*pu_v1),*pu_v2);
    }
    if (i_v10 < 0x16) {
      i_v10 = i_v10 + 10;
      *(uint *)((char *)arg1 + 0x580) = u_v13 >> 0x16;
    }
    else {
      i_v10 = i_v10 + -0x16;
      if (i_v10 == 0) {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x580) = u_v13 >> 0x16;
      }
      else {
        pu_v8 = pu_v8 + 4;
        *(uint *)((char *)arg1 + 0x580) = (u_v11 >> (10U - (char)i_v10 & 0x1f) | u_v13) >> 0x16;
      }
    }
  }
  i_v10 = i_v10 + -0x39 + ((int)pu_v8 - (int)arg2) * 8;
  *(cri_u4 *)((char *)arg1 + 0x708) = 0;
  *(cri_u4 *)((char *)arg1 + 0x70c) = 0;
  return (longlong)((int)(i_v10 + (i_v10 >> 0x1f & 7U)) >> 3) + arg2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140057fe0
longlong FUN_140057fe0(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  ulonglong arg2 = cri_p1;
  byte b_v1;
  uint u_v2;
  uint u_v3;
  uint u_v4;
  int i_v5;
  cri_u1 *pu_v6;
  cri_u1 *pu_v7;
  int i_v8;
  
  *(int *)((char *)arg1 + 0xcb4) = *(int *)((char *)arg1 + 0xcb4) + 1;
  *(cri_u4 *)((char *)arg1 + 0xd1c) = 0;
  *(cri_u4 *)((char *)arg1 + 0xd20) = 0;
  *(cri_u4 *)((char *)arg1 + 0xd24) = 0;
  *(cri_u4 *)((char *)arg1 + 0xc94) = 2;
  if (((*(int *)((char *)arg1 + 0x708) != 0) && (*(int *)((char *)arg1 + 0x708) != 8)) ||
     (*(int *)((char *)arg1 + 0x70c) != 0)) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  pu_v6 = (cri_u1 *)(arg2 & 0xfffffffffffffffc);
  i_v8 = (int)arg2 * 8 + (int)pu_v6 * -8;
  b_v1 = (byte)i_v8;
  u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v6,pu_v6[1]),pu_v6[2]),pu_v6[3]) << (b_v1 & 0x1f);
  u_v4 = CONCAT31(CONCAT21(CONCAT11(pu_v6[4],pu_v6[5]),pu_v6[6]),pu_v6[7]);
  if (i_v8 == 0) {
    *(uint *)((char *)arg1 + 0x2b8) = u_v3;
  }
  else {
    u_v2 = u_v4 >> (0x20 - b_v1 & 0x1f);
    u_v4 = u_v4 << (b_v1 & 0x1f);
    *(uint *)((char *)arg1 + 0x2b8) = u_v2 | u_v3;
  }
  pu_v7 = pu_v6 + 0xc;
  u_v3 = CONCAT31(CONCAT21(CONCAT11(pu_v6[8],pu_v6[9]),pu_v6[10]),pu_v6[0xb]);
  if (i_v8 < 0x1f) {
    i_v8 = i_v8 + 1;
    u_v2 = u_v4 * 2;
    *(uint *)(arg1 + 700) = u_v4 >> 0x1f;
  }
  else {
    i_v8 = i_v8 + -0x1f;
    if (i_v8 == 0) {
      *(uint *)(arg1 + 700) = u_v4 >> 0x1f;
      u_v2 = u_v3;
    }
    else {
      *(uint *)(arg1 + 700) = (u_v3 >> (1 - (byte)i_v8 & 0x1f) | u_v4) >> 0x1f;
      u_v2 = u_v3 << ((byte)i_v8 & 0x1f);
    }
    u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v6[0xd]),pu_v6[0xe]),pu_v6[0xf]);
    pu_v7 = pu_v6 + 0x10;
  }
  if (i_v8 < 0x1b) {
    i_v8 = i_v8 + 5;
    u_v4 = u_v2 << 5;
    *(uint *)((char *)arg1 + 0x2c0) = u_v2 >> 0x1b;
  }
  else {
    i_v8 = i_v8 + -0x1b;
    if (i_v8 == 0) {
      *(uint *)((char *)arg1 + 0x2c0) = u_v2 >> 0x1b;
      u_v4 = u_v3;
    }
    else {
      *(uint *)((char *)arg1 + 0x2c0) = (u_v3 >> (5 - (byte)i_v8 & 0x1f) | u_v2) >> 0x1b;
      u_v4 = u_v3 << ((byte)i_v8 & 0x1f);
    }
    u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]);
    pu_v7 = pu_v7 + 4;
  }
  if (i_v8 < 0x1a) {
    i_v8 = i_v8 + 6;
    u_v2 = u_v4 << 6;
    *(uint *)((char *)arg1 + 0x2c4) = u_v4 >> 0x1a;
  }
  else {
    i_v8 = i_v8 + -0x1a;
    if (i_v8 == 0) {
      *(uint *)((char *)arg1 + 0x2c4) = u_v4 >> 0x1a;
      u_v2 = u_v3;
    }
    else {
      *(uint *)((char *)arg1 + 0x2c4) = (u_v3 >> (6 - (byte)i_v8 & 0x1f) | u_v4) >> 0x1a;
      u_v2 = u_v3 << ((byte)i_v8 & 0x1f);
    }
    u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]);
    pu_v7 = pu_v7 + 4;
  }
  if (i_v8 < 0x1f) {
    i_v8 = i_v8 + 1;
    u_v4 = u_v2 * 2;
    *(uint *)((char *)arg1 + 0x18) = u_v2 >> 0x1f;
  }
  else {
    i_v8 = i_v8 + -0x1f;
    if (i_v8 == 0) {
      *(uint *)((char *)arg1 + 0x18) = u_v2 >> 0x1f;
      u_v4 = u_v3;
    }
    else {
      *(uint *)((char *)arg1 + 0x18) = (u_v3 >> (1 - (byte)i_v8 & 0x1f) | u_v2) >> 0x1f;
      u_v4 = u_v3 << ((byte)i_v8 & 0x1f);
    }
    u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]);
    pu_v7 = pu_v7 + 4;
  }
  if (i_v8 < 0x1a) {
    i_v8 = i_v8 + 6;
    u_v2 = u_v4 << 6;
    *(uint *)((char *)arg1 + 0x2c8) = u_v4 >> 0x1a;
  }
  else {
    i_v8 = i_v8 + -0x1a;
    if (i_v8 == 0) {
      *(uint *)((char *)arg1 + 0x2c8) = u_v4 >> 0x1a;
      u_v2 = u_v3;
    }
    else {
      *(uint *)((char *)arg1 + 0x2c8) = (u_v3 >> (6 - (byte)i_v8 & 0x1f) | u_v4) >> 0x1a;
      u_v2 = u_v3 << ((byte)i_v8 & 0x1f);
    }
    u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]);
    pu_v7 = pu_v7 + 4;
  }
  if (i_v8 < 0x1a) {
    i_v8 = i_v8 + 6;
    u_v4 = u_v2 << 6;
    *(uint *)((char *)arg1 + 0x2cc) = u_v2 >> 0x1a;
  }
  else {
    i_v8 = i_v8 + -0x1a;
    if (i_v8 == 0) {
      *(uint *)((char *)arg1 + 0x2cc) = u_v2 >> 0x1a;
      u_v4 = u_v3;
    }
    else {
      *(uint *)((char *)arg1 + 0x2cc) = (u_v3 >> (6 - (byte)i_v8 & 0x1f) | u_v2) >> 0x1a;
      u_v4 = u_v3 << ((byte)i_v8 & 0x1f);
    }
    u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]);
    pu_v7 = pu_v7 + 4;
  }
  if (i_v8 < 0x1f) {
    i_v8 = i_v8 + 1;
    u_v2 = u_v4 * 2;
    *(uint *)((char *)arg1 + 0x2d0) = u_v4 >> 0x1f;
  }
  else {
    i_v8 = i_v8 + -0x1f;
    if (i_v8 == 0) {
      *(uint *)((char *)arg1 + 0x2d0) = u_v4 >> 0x1f;
      u_v2 = u_v3;
    }
    else {
      *(uint *)((char *)arg1 + 0x2d0) = (u_v3 >> (1 - (byte)i_v8 & 0x1f) | u_v4) >> 0x1f;
      u_v2 = u_v3 << ((byte)i_v8 & 0x1f);
    }
    u_v3 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]);
    pu_v7 = pu_v7 + 4;
  }
  i_v5 = (int)pu_v7;
  if (i_v8 < 0x1f) {
    i_v8 = i_v8 + 1;
    *(uint *)((char *)arg1 + 0x2d4) = u_v2 >> 0x1f;
  }
  else {
    i_v8 = i_v8 + -0x1f;
    if (i_v8 == 0) {
      i_v5 = i_v5 + 4;
      *(uint *)((char *)arg1 + 0x2d4) = u_v2 >> 0x1f;
    }
    else {
      i_v5 = i_v5 + 4;
      *(uint *)((char *)arg1 + 0x2d4) = (u_v3 >> (1U - (char)i_v8 & 0x1f) | u_v2) >> 0x1f;
    }
  }
  i_v8 = i_v8 + -0x39 + (i_v5 - (int)arg2) * 8;
  return (longlong)((int)(i_v8 + (i_v8 >> 0x1f & 7U)) >> 3) + arg2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400584e0
longlong FUN_1400584e0(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  ulonglong arg2 = cri_p1;
  int *pi_v1;
  uint u_v2;
  byte b_v3;
  uint u_v4;
  uint u_v5;
  uint u_v6;
  cri_u1 *pu_v7;
  cri_u1 *pu_v8;
  int i_v9;
  
  *(int *)((char *)arg1 + 0xcb8) = *(int *)((char *)arg1 + 0xcb8) + 1;
  *(cri_u4 *)((char *)arg1 + 0xc94) = 3;
  if (((*(int *)((char *)arg1 + 0x708) != 0) && (*(int *)((char *)arg1 + 0x708) != 4)) ||
     (*(int *)((char *)arg1 + 0x70c) != 0)) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  pu_v7 = (cri_u1 *)(arg2 & 0xfffffffffffffffc);
  i_v9 = (int)arg2 * 8 + (int)pu_v7 * -8;
  b_v3 = (byte)i_v9;
  u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v7,pu_v7[1]),pu_v7[2]),pu_v7[3]) << (b_v3 & 0x1f);
  u_v6 = CONCAT31(CONCAT21(CONCAT11(pu_v7[4],pu_v7[5]),pu_v7[6]),pu_v7[7]);
  if (i_v9 == 0) {
    *(uint *)((char *)arg1 + 0x2d8) = u_v5;
  }
  else {
    u_v4 = u_v6 >> (0x20 - b_v3 & 0x1f);
    u_v6 = u_v6 << (b_v3 & 0x1f);
    *(uint *)((char *)arg1 + 0x2d8) = u_v4 | u_v5;
  }
  pu_v8 = pu_v7 + 0xc;
  u_v5 = CONCAT31(CONCAT21(CONCAT11(pu_v7[8],pu_v7[9]),pu_v7[10]),pu_v7[0xb]);
  if (i_v9 < 0x16) {
    i_v9 = i_v9 + 10;
    u_v4 = u_v6 << 10;
    *(uint *)((char *)arg1 + 0x2dc) = u_v6 >> 0x16;
  }
  else {
    i_v9 = i_v9 + -0x16;
    if (i_v9 == 0) {
      *(uint *)((char *)arg1 + 0x2dc) = u_v6 >> 0x16;
      u_v4 = u_v5;
    }
    else {
      *(uint *)((char *)arg1 + 0x2dc) = (u_v5 >> (10 - (byte)i_v9 & 0x1f) | u_v6) >> 0x16;
      u_v4 = u_v5 << ((byte)i_v9 & 0x1f);
    }
    u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v7[0xd]),pu_v7[0xe]),pu_v7[0xf]);
    pu_v8 = pu_v7 + 0x10;
  }
  if (i_v9 < 0x1d) {
    i_v9 = i_v9 + 3;
    u_v6 = u_v4 << 3;
    *(uint *)((char *)arg1 + 0x2e0) = u_v4 >> 0x1d;
  }
  else {
    i_v9 = i_v9 + -0x1d;
    if (i_v9 == 0) {
      *(uint *)((char *)arg1 + 0x2e0) = u_v4 >> 0x1d;
      u_v6 = u_v5;
    }
    else {
      *(uint *)((char *)arg1 + 0x2e0) = (u_v5 >> (3 - (byte)i_v9 & 0x1f) | u_v4) >> 0x1d;
      u_v6 = u_v5 << ((byte)i_v9 & 0x1f);
    }
    u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
    pu_v8 = pu_v8 + 4;
  }
  if (i_v9 < 0x10) {
    i_v9 = i_v9 + 0x10;
    u_v4 = u_v6 << 0x10;
    *(uint *)((char *)arg1 + 0x2e4) = u_v6 >> 0x10;
  }
  else {
    i_v9 = i_v9 + -0x10;
    if (i_v9 == 0) {
      *(uint *)((char *)arg1 + 0x2e4) = u_v6 >> 0x10;
      u_v4 = u_v5;
    }
    else {
      *(uint *)((char *)arg1 + 0x2e4) = (u_v5 >> (0x10 - (byte)i_v9 & 0x1f) | u_v6) >> 0x10;
      u_v4 = u_v5 << ((byte)i_v9 & 0x1f);
    }
    u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
    pu_v8 = pu_v8 + 4;
  }
  u_v6 = *(uint *)((char *)arg1 + 0x2e0);
  if ((u_v6 == 0) || (3 < u_v6)) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  if ((u_v6 == 1) || (u_v6 == 2)) {
    *(int *)((char *)arg1 + 0xd1c) = *(int *)((char *)arg1 + 0xd1c) + 1;
    *(cri_u4 *)((char *)arg1 + 0xd20) = 0;
    u_v2 = *(int *)((char *)arg1 + 0xd1c) << 0x10;
  }
  else {
    *(int *)((char *)arg1 + 0xd20) = *(int *)((char *)arg1 + 0xd20) + 1;
    u_v2 = *(int *)((char *)arg1 + 0xd1c) * 0x10000 - 0x10000U | *(uint *)((char *)arg1 + 0xd20);
  }
  *(uint *)((char *)arg1 + 0xd24) = u_v2;
  if ((u_v6 == 2) || (u_v6 == 3)) {
    if (i_v9 < 0x1f) {
      i_v9 = i_v9 + 1;
      u_v2 = u_v4 * 2;
      *(uint *)((char *)arg1 + 0x2e8) = u_v4 >> 0x1f;
    }
    else {
      i_v9 = i_v9 + -0x1f;
      if (i_v9 == 0) {
        *(uint *)((char *)arg1 + 0x2e8) = u_v4 >> 0x1f;
        u_v2 = u_v5;
      }
      else {
        *(uint *)((char *)arg1 + 0x2e8) = (u_v5 >> (1 - (byte)i_v9 & 0x1f) | u_v4) >> 0x1f;
        u_v2 = u_v5 << ((byte)i_v9 & 0x1f);
      }
      u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (i_v9 < 0x1d) {
      i_v9 = i_v9 + 3;
      u_v4 = u_v2 << 3;
      *(uint *)((char *)arg1 + 0x2ec) = u_v2 >> 0x1d;
    }
    else {
      i_v9 = i_v9 + -0x1d;
      if (i_v9 == 0) {
        *(uint *)((char *)arg1 + 0x2ec) = u_v2 >> 0x1d;
        u_v4 = u_v5;
      }
      else {
        *(uint *)((char *)arg1 + 0x2ec) = (u_v5 >> (3 - (byte)i_v9 & 0x1f) | u_v2) >> 0x1d;
        u_v4 = u_v5 << ((byte)i_v9 & 0x1f);
      }
      u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (u_v6 == 3) {
      if (i_v9 < 0x1f) {
        i_v9 = i_v9 + 1;
        u_v2 = u_v4 * 2;
        *(uint *)((char *)arg1 + 0x2f0) = u_v4 >> 0x1f;
      }
      else {
        i_v9 = i_v9 + -0x1f;
        if (i_v9 == 0) {
          *(uint *)((char *)arg1 + 0x2f0) = u_v4 >> 0x1f;
          u_v2 = u_v5;
        }
        else {
          *(uint *)((char *)arg1 + 0x2f0) = (u_v5 >> (1 - (byte)i_v9 & 0x1f) | u_v4) >> 0x1f;
          u_v2 = u_v5 << ((byte)i_v9 & 0x1f);
        }
        u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
        pu_v8 = pu_v8 + 4;
      }
      if (0x1c < i_v9) {
        i_v9 = i_v9 + -0x1d;
        if (i_v9 != 0) {
          *(uint *)((char *)arg1 + 0x2f4) = (u_v5 >> (3 - (byte)i_v9 & 0x1f) | u_v2) >> 0x1d;
          u_v4 = u_v5 << ((byte)i_v9 & 0x1f);
          goto LAB_140058a79;
        }
        *(uint *)((char *)arg1 + 0x2f4) = u_v2 >> 0x1d;
        u_v4 = u_v5;
        goto LAB_140058a79;
      }
      i_v9 = i_v9 + 3;
      u_v4 = u_v2 << 3;
      *(uint *)((char *)arg1 + 0x2f4) = u_v2 >> 0x1d;
    }
  }
  while( true ) {
    if (i_v9 < 0x1f) {
      i_v9 = i_v9 + 1;
      u_v2 = u_v4 * 2;
      *(uint *)((char *)arg1 + 0x2f8) = u_v4 >> 0x1f;
    }
    else {
      i_v9 = i_v9 + -0x1f;
      if (i_v9 == 0) {
        *(uint *)((char *)arg1 + 0x2f8) = u_v4 >> 0x1f;
        u_v2 = u_v5;
      }
      else {
        *(uint *)((char *)arg1 + 0x2f8) = (u_v5 >> (1 - (byte)i_v9 & 0x1f) | u_v4) >> 0x1f;
        u_v2 = u_v5 << ((byte)i_v9 & 0x1f);
      }
      u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
    if (*(int *)((char *)arg1 + 0x2f8) == 0) break;
    if (i_v9 < 0x18) {
      i_v9 = i_v9 + 8;
      u_v4 = u_v2 << 8;
      *(uint *)((char *)arg1 + 0x2fc) = u_v2 >> 0x18;
    }
    else {
      i_v9 = i_v9 + -0x18;
      if (i_v9 == 0) {
        *(uint *)((char *)arg1 + 0x2fc) = u_v2 >> 0x18;
        u_v4 = u_v5;
      }
      else {
        *(uint *)((char *)arg1 + 0x2fc) = (u_v5 >> (8 - (byte)i_v9 & 0x1f) | u_v2) >> 0x18;
        u_v4 = u_v5 << ((byte)i_v9 & 0x1f);
      }
LAB_140058a79:
      u_v5 = CONCAT31(CONCAT21(CONCAT11(*pu_v8,pu_v8[1]),pu_v8[2]),pu_v8[3]);
      pu_v8 = pu_v8 + 4;
    }
  }
  pi_v1 = (int *)(arg1 + 0xcbc + (ulonglong)u_v6 * 4);
  *pi_v1 = *pi_v1 + 1;
  *(cri_u4 *)((char *)arg1 + 0x708) = 0x10;
  *(cri_u4 *)((char *)arg1 + 0x70c) = 8;
  i_v9 = i_v9 + -0x39 + ((int)pu_v8 - (int)arg2) * 8;
  return (longlong)((int)(i_v9 + (i_v9 >> 0x1f & 7U)) >> 3) + arg2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140058b10
void FUN_140058b10(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  void *arg2 = cri_p1;
  ulonglong arg3 = cri_p2;
  int i_v1;
  longlong *pl_v2;
  cri_code *pc_v3;
  longlong l_v4;
  // Two {ptr, len} out-structs at rsp+0x20 / rsp+0x30 in the exe; slots 0x30 and 0x40 take their address.
  __declspec(align(16)) cri_u8 frame_[0x20];
  void *&loc_38 = *(void **)(frame_ + 0);
  int &loc_30 = *(int *)(frame_ + 8);
  void *&loc_28 = *(void **)(frame_ + 16);
  int &loc_20 = *(int *)(frame_ + 24);
  
  i_v1 = *(int *)((char *)arg1 + 0xc94);
  l_v4 = (longlong)i_v1;
  pl_v2 = *(longlong **)(arg1 + 0x1be8 + l_v4 * 0x18);
  if (pl_v2 != (longlong *)0x0) {
    (**(cri_code **)(*pl_v2 + 0x30))(pl_v2,0,arg3,&loc_38);
    memcpy(loc_38,arg2,(longlong)loc_30);
    (**(cri_code **)(*pl_v2 + 0x40))(pl_v2,1,&loc_38);
    if (loc_30 < (int)arg3) {
      (**(cri_code **)(*pl_v2 + 0x30))(pl_v2,0,(int)arg3 - loc_30,&loc_28);
      memcpy(loc_28,(void *)((longlong)loc_30 + (longlong)arg2),(longlong)loc_20);
      (**(cri_code **)(*pl_v2 + 0x40))(pl_v2,1,&loc_28);
    }
    pc_v3 = *(cri_code **)(arg1 + (l_v4 * 3 + 0x37e) * 8);
    if (pc_v3 != (cri_code *)0x0) {
      (*pc_v3)(*(cri_u8 *)(arg1 + 0x1bf8 + l_v4 * 0x18),i_v1);
    }
  }
  if ((i_v1 == 3) && (*(longlong *)((char *)arg1 + 0x1c48) != 0)) {
    if (*(int *)((char *)arg1 + 0xc0c) != 0) {
      FUN_140055510(arg1,&DAT_1431baa28,8);
    }
    FUN_140055510(arg1,arg2,arg3 & 0xffffffff);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140058c50
longlong FUN_140058c50(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  ulonglong arg2 = cri_p1;
  byte b_v1;
  uint u_v2;
  cri_u1 *pu_v3;
  cri_u1 *pu_v4;
  int i_v5;
  uint u_v6;
  uint u_v7;
  int i_v8;
  int i_v9;
  
  *(int *)((char *)arg1 + 0xcac) = *(int *)((char *)arg1 + 0xcac) + 1;
  if (((*(int *)((char *)arg1 + 0x708) != 0) && (*(int *)((char *)arg1 + 0x708) != 0x20)) ||
     (*(int *)((char *)arg1 + 0x70c) != 0)) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  pu_v3 = (cri_u1 *)(arg2 & 0xfffffffffffffffc);
  i_v5 = (int)arg2 * 8 + (int)pu_v3 * -8;
  b_v1 = (byte)i_v5;
  u_v6 = CONCAT31(CONCAT21(CONCAT11(*pu_v3,pu_v3[1]),pu_v3[2]),pu_v3[3]) << (b_v1 & 0x1f);
  u_v7 = CONCAT31(CONCAT21(CONCAT11(pu_v3[4],pu_v3[5]),pu_v3[6]),pu_v3[7]);
  if (i_v5 == 0) {
    *(uint *)((char *)arg1 + 0x230) = u_v6;
  }
  else {
    u_v2 = u_v7 >> (0x20 - b_v1 & 0x1f);
    u_v7 = u_v7 << (b_v1 & 0x1f);
    *(uint *)((char *)arg1 + 0x230) = u_v2 | u_v6;
  }
  pu_v4 = pu_v3 + 0xc;
  i_v9 = 0;
  u_v6 = CONCAT31(CONCAT21(CONCAT11(pu_v3[8],pu_v3[9]),pu_v3[10]),pu_v3[0xb]);
  i_v8 = 0x28 - i_v5;
  do {
    u_v2 = u_v7 >> 8;
    if (8 < i_v5) {
      u_v2 = u_v2 | u_v6 >> ((byte)i_v8 & 0x1f);
    }
    if (u_v2 == 1) break;
    if (i_v5 + 8 < 0x20) {
      u_v7 = u_v7 << 8;
      i_v5 = i_v5 + 8;
      i_v8 = i_v8 + -8;
    }
    else {
      u_v7 = u_v6 << ((byte)(i_v5 + -0x18) & 0x1f);
      u_v6 = CONCAT31(CONCAT21(CONCAT11(*pu_v4,pu_v4[1]),pu_v4[2]),pu_v4[3]);
      pu_v4 = pu_v4 + 4;
      i_v5 = i_v5 + -0x18;
      i_v8 = i_v8 + 0x18;
    }
    i_v9 = i_v9 + 1;
  } while (i_v9 < 0x100000);
  FUN_140058b10(arg1,arg2,i_v9 + 4);
  i_v5 = i_v5 + -0x39 + ((int)pu_v4 - (int)arg2) * 8;
  return (longlong)((int)(i_v5 + (i_v5 >> 0x1f & 7U)) >> 3) + arg2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140058e00
uint FUN_140058e00(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  longlong *arg2 = cri_p1;
  int i_v1;
  longlong l_v2;
  // Slot 0x30 fills a {ptr, len @+8} struct at rsp+0x20 in the exe; loc_28/uStack_24 are its pointer halves.
  __declspec(align(16)) cri_u8 frame_[0x10];
  int &loc_28 = *(int *)(frame_ + 0);
  cri_u4 &uStack_24 = *(cri_u4 *)(frame_ + 4);
  cri_u1 loc_18 [16];
  
  *(cri_u4 *)((char *)arg1 + 0xd0c) = 0;
  *(cri_u4 *)((char *)arg1 + 0xd10) = 0;
  *(cri_u4 *)((char *)arg1 + 0x708) = 0;
  *(cri_u4 *)((char *)arg1 + 0x70c) = 0;
  i_v1 = FUN_140051d90(arg2);
  if (i_v1 != 0) {
    while( true ) {
      (**(cri_code **)(*arg2 + 0x30))(arg2,1,0x7fffffff,&loc_28);
      switch(i_v1) {
      case 4:
        l_v2 = FUN_1400584e0(arg1,CONCAT44(uStack_24,loc_28));
        break;
      default:
        goto switchD_140058e8d_caseD_5;
      case 8:
        l_v2 = FUN_140057fe0(arg1,CONCAT44(uStack_24,loc_28));
        break;
      case 0x10:
        l_v2 = FUN_140055550(arg1,CONCAT44(uStack_24,loc_28));
        break;
      case 0x20:
        l_v2 = FUN_140058c50(arg1,CONCAT44(uStack_24,loc_28));
        break;
      case 0x40:
        l_v2 = FUN_140054cf0(arg1,CONCAT44(uStack_24,loc_28));
        break;
      case 0x80:
        l_v2 = FUN_140055410(arg1,CONCAT44(uStack_24,loc_28));
      }
      if (l_v2 == 0) break;
      FUN_140069020(&loc_28,(int)l_v2 - loc_28,&loc_28,loc_18);
      (**(cri_code **)(*arg2 + 0x40))(arg2,0,&loc_28);
      (**(cri_code **)(*arg2 + 0x38))(arg2,1,loc_18);
      if ((*(int *)((char *)arg1 + 0xd0c) != 0) || (i_v1 = FUN_140051d90(arg2), i_v1 == 0))
      goto LAB_140058f60;
    }
switchD_140058e8d_caseD_5:
    (**(cri_code **)(*arg2 + 0x38))(arg2,1,&loc_28);
  }
LAB_140058f60:
  *(int *)((char *)arg1 + 0xd18) = *(int *)((char *)arg1 + 0xd18) + *(int *)((char *)arg1 + 0xd10);
  *(int *)((char *)arg1 + 0xd14) = *(int *)((char *)arg1 + 0xd14) + *(int *)((char *)arg1 + 0xd0c);
  return -(uint)(*(int *)((char *)arg1 + 0xd0c) != 0) & 0xfffffffe;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140059030
ulonglong FUN_140059030(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 arg1 = cri_p0;
  cri_u8 arg2 = cri_p1;
  int i_v1;
  uint u_v2;
  ulonglong u_v3;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    u_v3 = FUN_14005af30(0,0xff05020c);
    return u_v3;
  }
  u_v2 = FUN_140058e00(arg1,arg2);
  u_v3 = (ulonglong)u_v2;
  if (u_v2 == 0) {
    FUN_1400545f0(arg1);
  }
  return u_v3 & 0xffffffff;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140059090
void FUN_140059090(cri_any cri_unused, ...)
{
  int i_v1;
  
  i_v1 = FUN_140062830();
  if (i_v1 != 0) {
    DAT_143fe8250 = &PTR_LAB_1431bab50;
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140059170
void FUN_140059170(cri_any cri_p0, ...)
{
  longlong *arg1 = cri_p0;
  longlong *pl_v1;
  ulonglong *pu_v2;
  char *pc_v3;
  ulonglong u_v4;
  ulonglong u_v5;
  ulonglong u_v6;
  ulonglong u_v7;
  ulonglong *pu_v8;
  V16 au_v9;
  V16 au_v10;
  V16 au_v11;
  V16 au_v12;
  V16 au_v13;
  V16 au_v14;
  V16 au_v15;
  V16 au_v16;
  V16 au_v17;
  V16 au_v18;
  V16 au_v19;
  V16 au_v20;
  V16 au_v21;
  V16 au_v22;
  V16 au_v23;
  V16 au_v24;
  V16 au_v25;
  V16 au_v26;
  V16 au_v27;
  V16 au_v28;
  V16 au_v29;
  V16 au_v30;
  V16 au_v31;
  V16 au_v32;
  V16 au_v33;
  V16 au_v34;
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
  V16 au_v59;
  V16 au_v60;
  V16 au_v61;
  unkuint9 Var62;
  V16 au_v63;
  V16 au_v64;
  V16 au_v65;
  unkuint9 Var66;
  V16 au_v67;
  V16 au_v68;
  V16 au_v69;
  V16 au_v70;
  V16 au_v71;
  V16 au_v72;
  V16 au_v73;
  V16 au_v74;
  V16 au_v75;
  V16 au_v76;
  V16 au_v77;
  V16 au_v78;
  V16 au_v79;
  V16 au_v80;
  V16 au_v81;
  V16 au_v82;
  V16 au_v83;
  V16 au_v84;
  V16 au_v85;
  V16 au_v86;
  V16 au_v87;
  V16 au_v88;
  V16 au_v89;
  V16 au_v90;
  V16 au_v91;
  V16 au_v92;
  V16 au_v93;
  V16 au_v94;
  V16 au_v95;
  V16 au_v96;
  V16 au_v97;
  V16 au_v98;
  longlong l_v99;
  longlong l_v100;
  char *pc_v101;
  short *ps_v102;
  short s_v103;
  short s_v104;
  short s_v105;
  short s_v106;
  short s_v107;
  short s_v108;
  short s_v109;
  short s_v110;
  short s_v111;
  short s_v112;
  short s_v113;
  short s_v114;
  short s_v115;
  short s_v116;
  short s_v117;
  short s_v118;
  short s_v119;
  short s_v120;
  short s_v121;
  short s_v122;
  short s_v123;
  short s_v124;
  short s_v125;
  short s_v126;
  short s_v127;
  short s_v128;
  short s_v129;
  short s_v130;
  short s_v131;
  short s_v132;
  short s_v133;
  short s_v134;
  
  ps_v102 = (short *)*arg1;
  do {
    pl_v1 = arg1 + 2;
    l_v99 = (longlong)(int)*pl_v1;
    pu_v8 = (ulonglong *)arg1[1];
    arg1 = arg1 + 3;
    u_v4 = *(ulonglong *)(l_v99 + (longlong)pu_v8);
    u_v5 = *pu_v8;
    l_v100 = (longlong)((int)*pl_v1 * 2);
    CRI_PART(au_v15,8,6) = 0;
    CRI_PART(au_v15,0,8) = u_v4;
    au_v15.b[0xe] = (char)(u_v4 >> 0x38);
    CRI_PART(au_v23,8,4) = 0;
    CRI_PART(au_v23,0,8) = u_v4;
    au_v23.b[0xc] = (char)(u_v4 >> 0x30);
    CRI_PART(au_v23,13,2) = CRI_PART(au_v15,13,2);
    CRI_PART(au_v31,8,4) = 0;
    CRI_PART(au_v31,0,8) = u_v4;
    CRI_PART(au_v31,12,3) = CRI_PART(au_v23,12,3);
    CRI_PART(au_v39,8,2) = 0;
    CRI_PART(au_v39,0,8) = u_v4;
    au_v39.b[10] = (char)(u_v4 >> 0x28);
    CRI_PART(au_v39,11,4) = CRI_PART(au_v31,11,4);
    CRI_PART(au_v47,8,2) = 0;
    CRI_PART(au_v47,0,8) = u_v4;
    CRI_PART(au_v47,10,5) = CRI_PART(au_v39,10,5);
    au_v55.b[8] = (char)(u_v4 >> 0x20);
    CRI_PART(au_v55,0,8) = u_v4;
    CRI_PART(au_v55,9,6) = CRI_PART(au_v47,9,6);
    CRI_PART(au_v61,7,8) = 0;
    CRI_PART(au_v61,0,7) = CRI_PART(au_v55,8,7);
    Var62 = CONCAT81(SUB158(au_v61 << 0x40,7),(char)(u_v4 >> 0x18));
    CRI_PART(au_v83,9,6) = 0;
    CRI_PART(au_v83,0,9) = Var62;
    CRI_PART(au_v63,1,10) = SUB1510(au_v83 << 0x30,5);
    au_v63.b[0] = (char)(u_v4 >> 0x10);
    CRI_PART(au_v84,11,4) = 0;
    CRI_PART(au_v84,0,11) = au_v63;
    CRI_PART(au_v64,1,12) = SUB1512(au_v84 << 0x20,3);
    au_v64.b[0] = (char)(u_v4 >> 8);
    CRI_PART(au_v9,8,6) = 0;
    CRI_PART(au_v9,0,8) = u_v5;
    au_v9.b[0xe] = (char)(u_v5 >> 0x38);
    CRI_PART(au_v16,8,4) = 0;
    CRI_PART(au_v16,0,8) = u_v5;
    au_v16.b[0xc] = (char)(u_v5 >> 0x30);
    CRI_PART(au_v16,13,2) = CRI_PART(au_v9,13,2);
    CRI_PART(au_v24,8,4) = 0;
    CRI_PART(au_v24,0,8) = u_v5;
    CRI_PART(au_v24,12,3) = CRI_PART(au_v16,12,3);
    CRI_PART(au_v32,8,2) = 0;
    CRI_PART(au_v32,0,8) = u_v5;
    au_v32.b[10] = (char)(u_v5 >> 0x28);
    CRI_PART(au_v32,11,4) = CRI_PART(au_v24,11,4);
    CRI_PART(au_v40,8,2) = 0;
    CRI_PART(au_v40,0,8) = u_v5;
    CRI_PART(au_v40,10,5) = CRI_PART(au_v32,10,5);
    au_v48.b[8] = (char)(u_v5 >> 0x20);
    CRI_PART(au_v48,0,8) = u_v5;
    CRI_PART(au_v48,9,6) = CRI_PART(au_v40,9,6);
    CRI_PART(au_v65,7,8) = 0;
    CRI_PART(au_v65,0,7) = CRI_PART(au_v48,8,7);
    Var66 = CONCAT81(SUB158(au_v65 << 0x40,7),(char)(u_v5 >> 0x18));
    CRI_PART(au_v85,9,6) = 0;
    CRI_PART(au_v85,0,9) = Var66;
    CRI_PART(au_v67,1,10) = SUB1510(au_v85 << 0x30,5);
    au_v67.b[0] = (char)(u_v5 >> 0x10);
    CRI_PART(au_v86,11,4) = 0;
    CRI_PART(au_v86,0,11) = au_v67;
    au_v57.b[2] = (char)(u_v5 >> 8);
    CRI_PART(au_v57,0,2) = (ushort)u_v5;
    CRI_PART(au_v57,3,12) = SUB1512(au_v86 << 0x20,3);
    s_v103 = (ushort)(byte)u_v4 + ps_v102[8];
    s_v104 = CRI_PART(au_v64,0,2) + ps_v102[9];
    s_v105 = CRI_PART(au_v63,0,2) + ps_v102[10];
    s_v106 = (short)Var62 + ps_v102[0xb];
    s_v107 = CRI_PART(au_v55,8,2) + ps_v102[0xc];
    s_v108 = CRI_PART(au_v39,10,2) + ps_v102[0xd];
    s_v109 = CRI_PART(au_v23,12,2) + ps_v102[0xe];
    s_v110 = (CRI_PART(au_v15,13,2) >> 8) + ps_v102[0xf];
    s_v127 = ((ushort)u_v5 & 0xff) + *ps_v102;
    s_v128 = CRI_PART(au_v57,2,2) + ps_v102[1];
    s_v129 = CRI_PART(au_v67,0,2) + ps_v102[2];
    s_v130 = (short)Var66 + ps_v102[3];
    s_v131 = CRI_PART(au_v48,8,2) + ps_v102[4];
    s_v132 = CRI_PART(au_v32,10,2) + ps_v102[5];
    s_v133 = CRI_PART(au_v16,12,2) + ps_v102[6];
    s_v134 = (CRI_PART(au_v9,13,2) >> 8) + ps_v102[7];
    u_v4 = *(ulonglong *)(l_v100 + (longlong)pu_v8);
    pc_v101 = (char *)(l_v100 + (longlong)pu_v8);
    u_v5 = *(ulonglong *)(pc_v101 + l_v99);
    CRI_PART(au_v10,8,6) = 0;
    CRI_PART(au_v10,0,8) = u_v4;
    au_v10.b[0xe] = (char)(u_v4 >> 0x38);
    CRI_PART(au_v17,8,4) = 0;
    CRI_PART(au_v17,0,8) = u_v4;
    au_v17.b[0xc] = (char)(u_v4 >> 0x30);
    CRI_PART(au_v17,13,2) = CRI_PART(au_v10,13,2);
    CRI_PART(au_v25,8,4) = 0;
    CRI_PART(au_v25,0,8) = u_v4;
    CRI_PART(au_v25,12,3) = CRI_PART(au_v17,12,3);
    CRI_PART(au_v33,8,2) = 0;
    CRI_PART(au_v33,0,8) = u_v4;
    au_v33.b[10] = (char)(u_v4 >> 0x28);
    CRI_PART(au_v33,11,4) = CRI_PART(au_v25,11,4);
    CRI_PART(au_v41,8,2) = 0;
    CRI_PART(au_v41,0,8) = u_v4;
    CRI_PART(au_v41,10,5) = CRI_PART(au_v33,10,5);
    au_v49.b[8] = (char)(u_v4 >> 0x20);
    CRI_PART(au_v49,0,8) = u_v4;
    CRI_PART(au_v49,9,6) = CRI_PART(au_v41,9,6);
    CRI_PART(au_v68,7,8) = 0;
    CRI_PART(au_v68,0,7) = CRI_PART(au_v49,8,7);
    Var62 = CONCAT81(SUB158(au_v68 << 0x40,7),(char)(u_v4 >> 0x18));
    CRI_PART(au_v87,9,6) = 0;
    CRI_PART(au_v87,0,9) = Var62;
    CRI_PART(au_v69,1,10) = SUB1510(au_v87 << 0x30,5);
    au_v69.b[0] = (char)(u_v4 >> 0x10);
    CRI_PART(au_v88,11,4) = 0;
    CRI_PART(au_v88,0,11) = au_v69;
    CRI_PART(au_v70,1,12) = SUB1512(au_v88 << 0x20,3);
    au_v70.b[0] = (char)(u_v4 >> 8);
    pu_v2 = (ulonglong *)(pc_v101 + l_v100);
    s_v119 = (ushort)(byte)u_v4 + ps_v102[0x10];
    s_v120 = CRI_PART(au_v70,0,2) + ps_v102[0x11];
    s_v121 = CRI_PART(au_v69,0,2) + ps_v102[0x12];
    s_v122 = (short)Var62 + ps_v102[0x13];
    s_v123 = CRI_PART(au_v49,8,2) + ps_v102[0x14];
    s_v124 = CRI_PART(au_v33,10,2) + ps_v102[0x15];
    s_v125 = CRI_PART(au_v17,12,2) + ps_v102[0x16];
    s_v126 = (CRI_PART(au_v10,13,2) >> 8) + ps_v102[0x17];
    CRI_PART(au_v11,8,6) = 0;
    CRI_PART(au_v11,0,8) = u_v5;
    au_v11.b[0xe] = (char)(u_v5 >> 0x38);
    CRI_PART(au_v18,8,4) = 0;
    CRI_PART(au_v18,0,8) = u_v5;
    au_v18.b[0xc] = (char)(u_v5 >> 0x30);
    CRI_PART(au_v18,13,2) = CRI_PART(au_v11,13,2);
    CRI_PART(au_v26,8,4) = 0;
    CRI_PART(au_v26,0,8) = u_v5;
    CRI_PART(au_v26,12,3) = CRI_PART(au_v18,12,3);
    CRI_PART(au_v34,8,2) = 0;
    CRI_PART(au_v34,0,8) = u_v5;
    au_v34.b[10] = (char)(u_v5 >> 0x28);
    CRI_PART(au_v34,11,4) = CRI_PART(au_v26,11,4);
    CRI_PART(au_v42,8,2) = 0;
    CRI_PART(au_v42,0,8) = u_v5;
    CRI_PART(au_v42,10,5) = CRI_PART(au_v34,10,5);
    au_v50.b[8] = (char)(u_v5 >> 0x20);
    CRI_PART(au_v50,0,8) = u_v5;
    CRI_PART(au_v50,9,6) = CRI_PART(au_v42,9,6);
    CRI_PART(au_v71,7,8) = 0;
    CRI_PART(au_v71,0,7) = CRI_PART(au_v50,8,7);
    Var62 = CONCAT81(SUB158(au_v71 << 0x40,7),(char)(u_v5 >> 0x18));
    CRI_PART(au_v89,9,6) = 0;
    CRI_PART(au_v89,0,9) = Var62;
    CRI_PART(au_v72,1,10) = SUB1510(au_v89 << 0x30,5);
    au_v72.b[0] = (char)(u_v5 >> 0x10);
    CRI_PART(au_v90,11,4) = 0;
    CRI_PART(au_v90,0,11) = au_v72;
    au_v58.b[2] = (char)(u_v5 >> 8);
    CRI_PART(au_v58,0,2) = (ushort)u_v5;
    CRI_PART(au_v58,3,12) = SUB1512(au_v90 << 0x20,3);
    s_v111 = ps_v102[0x18];
    s_v112 = ps_v102[0x19];
    s_v113 = ps_v102[0x1a];
    s_v114 = ps_v102[0x1b];
    s_v115 = ps_v102[0x1c];
    s_v116 = ps_v102[0x1d];
    s_v117 = ps_v102[0x1e];
    s_v118 = ps_v102[0x1f];
    *(char *)pu_v8 = (0 < s_v127) * (s_v127 < 0x100) * (char)s_v127 - (0xff < s_v127);
    *(char *)((longlong)pu_v8 + 1) =
         (0 < s_v128) * (s_v128 < 0x100) * (char)s_v128 - (0xff < s_v128);
    *(char *)((longlong)pu_v8 + 2) =
         (0 < s_v129) * (s_v129 < 0x100) * (char)s_v129 - (0xff < s_v129);
    *(char *)((longlong)pu_v8 + 3) =
         (0 < s_v130) * (s_v130 < 0x100) * (char)s_v130 - (0xff < s_v130);
    *(char *)((longlong)pu_v8 + 4) =
         (0 < s_v131) * (s_v131 < 0x100) * (char)s_v131 - (0xff < s_v131);
    *(char *)((longlong)pu_v8 + 5) =
         (0 < s_v132) * (s_v132 < 0x100) * (char)s_v132 - (0xff < s_v132);
    *(char *)((longlong)pu_v8 + 6) =
         (0 < s_v133) * (s_v133 < 0x100) * (char)s_v133 - (0xff < s_v133);
    *(char *)((longlong)pu_v8 + 7) =
         (0 < s_v134) * (s_v134 < 0x100) * (char)s_v134 - (0xff < s_v134);
    pc_v3 = (char *)(l_v99 + (longlong)pu_v8);
    *pc_v3 = (0 < s_v103) * (s_v103 < 0x100) * (char)s_v103 - (0xff < s_v103);
    pc_v3[1] = (0 < s_v104) * (s_v104 < 0x100) * (char)s_v104 - (0xff < s_v104);
    pc_v3[2] = (0 < s_v105) * (s_v105 < 0x100) * (char)s_v105 - (0xff < s_v105);
    pc_v3[3] = (0 < s_v106) * (s_v106 < 0x100) * (char)s_v106 - (0xff < s_v106);
    pc_v3[4] = (0 < s_v107) * (s_v107 < 0x100) * (char)s_v107 - (0xff < s_v107);
    pc_v3[5] = (0 < s_v108) * (s_v108 < 0x100) * (char)s_v108 - (0xff < s_v108);
    pc_v3[6] = (0 < s_v109) * (s_v109 < 0x100) * (char)s_v109 - (0xff < s_v109);
    pc_v3[7] = (0 < s_v110) * (s_v110 < 0x100) * (char)s_v110 - (0xff < s_v110);
    s_v111 = ((ushort)u_v5 & 0xff) + s_v111;
    s_v112 = CRI_PART(au_v58,2,2) + s_v112;
    s_v113 = CRI_PART(au_v72,0,2) + s_v113;
    s_v114 = (short)Var62 + s_v114;
    s_v115 = CRI_PART(au_v50,8,2) + s_v115;
    s_v116 = CRI_PART(au_v34,10,2) + s_v116;
    s_v117 = CRI_PART(au_v18,12,2) + s_v117;
    s_v118 = (CRI_PART(au_v11,13,2) >> 8) + s_v118;
    *pc_v101 = (0 < s_v119) * (s_v119 < 0x100) * (char)s_v119 - (0xff < s_v119);
    pc_v101[1] = (0 < s_v120) * (s_v120 < 0x100) * (char)s_v120 - (0xff < s_v120);
    pc_v101[2] = (0 < s_v121) * (s_v121 < 0x100) * (char)s_v121 - (0xff < s_v121);
    pc_v101[3] = (0 < s_v122) * (s_v122 < 0x100) * (char)s_v122 - (0xff < s_v122);
    pc_v101[4] = (0 < s_v123) * (s_v123 < 0x100) * (char)s_v123 - (0xff < s_v123);
    pc_v101[5] = (0 < s_v124) * (s_v124 < 0x100) * (char)s_v124 - (0xff < s_v124);
    pc_v101[6] = (0 < s_v125) * (s_v125 < 0x100) * (char)s_v125 - (0xff < s_v125);
    pc_v101[7] = (0 < s_v126) * (s_v126 < 0x100) * (char)s_v126 - (0xff < s_v126);
    pc_v3 = pc_v101 + l_v99;
    *pc_v3 = (0 < s_v111) * (s_v111 < 0x100) * (char)s_v111 - (0xff < s_v111);
    pc_v3[1] = (0 < s_v112) * (s_v112 < 0x100) * (char)s_v112 - (0xff < s_v112);
    pc_v3[2] = (0 < s_v113) * (s_v113 < 0x100) * (char)s_v113 - (0xff < s_v113);
    pc_v3[3] = (0 < s_v114) * (s_v114 < 0x100) * (char)s_v114 - (0xff < s_v114);
    pc_v3[4] = (0 < s_v115) * (s_v115 < 0x100) * (char)s_v115 - (0xff < s_v115);
    pc_v3[5] = (0 < s_v116) * (s_v116 < 0x100) * (char)s_v116 - (0xff < s_v116);
    pc_v3[6] = (0 < s_v117) * (s_v117 < 0x100) * (char)s_v117 - (0xff < s_v117);
    pc_v3[7] = (0 < s_v118) * (s_v118 < 0x100) * (char)s_v118 - (0xff < s_v118);
    u_v4 = *pu_v2;
    u_v5 = *(ulonglong *)(l_v99 + (longlong)pu_v2);
    pc_v101 = pc_v101 + l_v100;
    u_v6 = *(ulonglong *)((longlong)pu_v2 + l_v100);
    u_v7 = *(ulonglong *)(l_v99 + (longlong)pu_v2 + l_v100);
    CRI_PART(au_v19,8,6) = 0;
    CRI_PART(au_v19,0,8) = u_v4;
    au_v19.b[0xe] = (char)(u_v4 >> 0x38);
    CRI_PART(au_v27,8,4) = 0;
    CRI_PART(au_v27,0,8) = u_v4;
    au_v27.b[0xc] = (char)(u_v4 >> 0x30);
    CRI_PART(au_v27,13,2) = CRI_PART(au_v19,13,2);
    CRI_PART(au_v35,8,4) = 0;
    CRI_PART(au_v35,0,8) = u_v4;
    CRI_PART(au_v35,12,3) = CRI_PART(au_v27,12,3);
    CRI_PART(au_v43,8,2) = 0;
    CRI_PART(au_v43,0,8) = u_v4;
    au_v43.b[10] = (char)(u_v4 >> 0x28);
    CRI_PART(au_v43,11,4) = CRI_PART(au_v35,11,4);
    CRI_PART(au_v51,8,2) = 0;
    CRI_PART(au_v51,0,8) = u_v4;
    CRI_PART(au_v51,10,5) = CRI_PART(au_v43,10,5);
    au_v56.b[8] = (char)(u_v4 >> 0x20);
    CRI_PART(au_v56,0,8) = u_v4;
    CRI_PART(au_v56,9,6) = CRI_PART(au_v51,9,6);
    CRI_PART(au_v73,7,8) = 0;
    CRI_PART(au_v73,0,7) = CRI_PART(au_v56,8,7);
    Var62 = CONCAT81(SUB158(au_v73 << 0x40,7),(char)(u_v4 >> 0x18));
    CRI_PART(au_v91,9,6) = 0;
    CRI_PART(au_v91,0,9) = Var62;
    CRI_PART(au_v74,1,10) = SUB1510(au_v91 << 0x30,5);
    au_v74.b[0] = (char)(u_v4 >> 0x10);
    CRI_PART(au_v92,11,4) = 0;
    CRI_PART(au_v92,0,11) = au_v74;
    CRI_PART(au_v75,1,12) = SUB1512(au_v92 << 0x20,3);
    au_v75.b[0] = (char)(u_v4 >> 8);
    s_v127 = (ushort)(byte)u_v4 + ps_v102[0x20];
    s_v128 = CRI_PART(au_v75,0,2) + ps_v102[0x21];
    s_v129 = CRI_PART(au_v74,0,2) + ps_v102[0x22];
    s_v130 = (short)Var62 + ps_v102[0x23];
    s_v131 = CRI_PART(au_v56,8,2) + ps_v102[0x24];
    s_v132 = CRI_PART(au_v43,10,2) + ps_v102[0x25];
    s_v133 = CRI_PART(au_v27,12,2) + ps_v102[0x26];
    s_v134 = (CRI_PART(au_v19,13,2) >> 8) + ps_v102[0x27];
    CRI_PART(au_v12,8,6) = 0;
    CRI_PART(au_v12,0,8) = u_v7;
    au_v12.b[0xe] = (char)(u_v7 >> 0x38);
    CRI_PART(au_v20,8,4) = 0;
    CRI_PART(au_v20,0,8) = u_v7;
    au_v20.b[0xc] = (char)(u_v7 >> 0x30);
    CRI_PART(au_v20,13,2) = CRI_PART(au_v12,13,2);
    CRI_PART(au_v28,8,4) = 0;
    CRI_PART(au_v28,0,8) = u_v7;
    CRI_PART(au_v28,12,3) = CRI_PART(au_v20,12,3);
    CRI_PART(au_v36,8,2) = 0;
    CRI_PART(au_v36,0,8) = u_v7;
    au_v36.b[10] = (char)(u_v7 >> 0x28);
    CRI_PART(au_v36,11,4) = CRI_PART(au_v28,11,4);
    CRI_PART(au_v44,8,2) = 0;
    CRI_PART(au_v44,0,8) = u_v7;
    CRI_PART(au_v44,10,5) = CRI_PART(au_v36,10,5);
    au_v52.b[8] = (char)(u_v7 >> 0x20);
    CRI_PART(au_v52,0,8) = u_v7;
    CRI_PART(au_v52,9,6) = CRI_PART(au_v44,9,6);
    CRI_PART(au_v76,7,8) = 0;
    CRI_PART(au_v76,0,7) = CRI_PART(au_v52,8,7);
    Var62 = CONCAT81(SUB158(au_v76 << 0x40,7),(char)(u_v7 >> 0x18));
    CRI_PART(au_v93,9,6) = 0;
    CRI_PART(au_v93,0,9) = Var62;
    CRI_PART(au_v77,1,10) = SUB1510(au_v93 << 0x30,5);
    au_v77.b[0] = (char)(u_v7 >> 0x10);
    CRI_PART(au_v94,11,4) = 0;
    CRI_PART(au_v94,0,11) = au_v77;
    au_v59.b[2] = (char)(u_v7 >> 8);
    CRI_PART(au_v59,0,2) = (ushort)u_v7;
    CRI_PART(au_v59,3,12) = SUB1512(au_v94 << 0x20,3);
    CRI_PART(au_v13,8,6) = 0;
    CRI_PART(au_v13,0,8) = u_v6;
    au_v13.b[0xe] = (char)(u_v6 >> 0x38);
    CRI_PART(au_v21,8,4) = 0;
    CRI_PART(au_v21,0,8) = u_v6;
    au_v21.b[0xc] = (char)(u_v6 >> 0x30);
    CRI_PART(au_v21,13,2) = CRI_PART(au_v13,13,2);
    CRI_PART(au_v29,8,4) = 0;
    CRI_PART(au_v29,0,8) = u_v6;
    CRI_PART(au_v29,12,3) = CRI_PART(au_v21,12,3);
    CRI_PART(au_v37,8,2) = 0;
    CRI_PART(au_v37,0,8) = u_v6;
    au_v37.b[10] = (char)(u_v6 >> 0x28);
    CRI_PART(au_v37,11,4) = CRI_PART(au_v29,11,4);
    CRI_PART(au_v45,8,2) = 0;
    CRI_PART(au_v45,0,8) = u_v6;
    CRI_PART(au_v45,10,5) = CRI_PART(au_v37,10,5);
    au_v53.b[8] = (char)(u_v6 >> 0x20);
    CRI_PART(au_v53,0,8) = u_v6;
    CRI_PART(au_v53,9,6) = CRI_PART(au_v45,9,6);
    CRI_PART(au_v78,7,8) = 0;
    CRI_PART(au_v78,0,7) = CRI_PART(au_v53,8,7);
    Var66 = CONCAT81(SUB158(au_v78 << 0x40,7),(char)(u_v6 >> 0x18));
    CRI_PART(au_v95,9,6) = 0;
    CRI_PART(au_v95,0,9) = Var66;
    CRI_PART(au_v79,1,10) = SUB1510(au_v95 << 0x30,5);
    au_v79.b[0] = (char)(u_v6 >> 0x10);
    CRI_PART(au_v96,11,4) = 0;
    CRI_PART(au_v96,0,11) = au_v79;
    CRI_PART(au_v80,1,12) = SUB1512(au_v96 << 0x20,3);
    au_v80.b[0] = (char)(u_v6 >> 8);
    s_v119 = (ushort)(byte)u_v6 + ps_v102[0x30];
    s_v120 = CRI_PART(au_v80,0,2) + ps_v102[0x31];
    s_v121 = CRI_PART(au_v79,0,2) + ps_v102[0x32];
    s_v122 = (short)Var66 + ps_v102[0x33];
    s_v123 = CRI_PART(au_v53,8,2) + ps_v102[0x34];
    s_v124 = CRI_PART(au_v37,10,2) + ps_v102[0x35];
    s_v125 = CRI_PART(au_v21,12,2) + ps_v102[0x36];
    s_v126 = (CRI_PART(au_v13,13,2) >> 8) + ps_v102[0x37];
    CRI_PART(au_v14,8,6) = 0;
    CRI_PART(au_v14,0,8) = u_v5;
    au_v14.b[0xe] = (char)(u_v5 >> 0x38);
    CRI_PART(au_v22,8,4) = 0;
    CRI_PART(au_v22,0,8) = u_v5;
    au_v22.b[0xc] = (char)(u_v5 >> 0x30);
    CRI_PART(au_v22,13,2) = CRI_PART(au_v14,13,2);
    CRI_PART(au_v30,8,4) = 0;
    CRI_PART(au_v30,0,8) = u_v5;
    CRI_PART(au_v30,12,3) = CRI_PART(au_v22,12,3);
    CRI_PART(au_v38,8,2) = 0;
    CRI_PART(au_v38,0,8) = u_v5;
    au_v38.b[10] = (char)(u_v5 >> 0x28);
    CRI_PART(au_v38,11,4) = CRI_PART(au_v30,11,4);
    CRI_PART(au_v46,8,2) = 0;
    CRI_PART(au_v46,0,8) = u_v5;
    CRI_PART(au_v46,10,5) = CRI_PART(au_v38,10,5);
    au_v54.b[8] = (char)(u_v5 >> 0x20);
    CRI_PART(au_v54,0,8) = u_v5;
    CRI_PART(au_v54,9,6) = CRI_PART(au_v46,9,6);
    CRI_PART(au_v81,7,8) = 0;
    CRI_PART(au_v81,0,7) = CRI_PART(au_v54,8,7);
    Var66 = CONCAT81(SUB158(au_v81 << 0x40,7),(char)(u_v5 >> 0x18));
    CRI_PART(au_v97,9,6) = 0;
    CRI_PART(au_v97,0,9) = Var66;
    CRI_PART(au_v82,1,10) = SUB1510(au_v97 << 0x30,5);
    au_v82.b[0] = (char)(u_v5 >> 0x10);
    CRI_PART(au_v98,11,4) = 0;
    CRI_PART(au_v98,0,11) = au_v82;
    au_v60.b[2] = (char)(u_v5 >> 8);
    CRI_PART(au_v60,0,2) = (ushort)u_v5;
    CRI_PART(au_v60,3,12) = SUB1512(au_v98 << 0x20,3);
    s_v103 = ((ushort)u_v5 & 0xff) + ps_v102[0x28];
    s_v104 = CRI_PART(au_v60,2,2) + ps_v102[0x29];
    s_v105 = CRI_PART(au_v82,0,2) + ps_v102[0x2a];
    s_v106 = (short)Var66 + ps_v102[0x2b];
    s_v107 = CRI_PART(au_v54,8,2) + ps_v102[0x2c];
    s_v108 = CRI_PART(au_v38,10,2) + ps_v102[0x2d];
    s_v109 = CRI_PART(au_v22,12,2) + ps_v102[0x2e];
    s_v110 = (CRI_PART(au_v14,13,2) >> 8) + ps_v102[0x2f];
    s_v111 = ((ushort)u_v7 & 0xff) + ps_v102[0x38];
    s_v112 = CRI_PART(au_v59,2,2) + ps_v102[0x39];
    s_v113 = CRI_PART(au_v77,0,2) + ps_v102[0x3a];
    s_v114 = (short)Var62 + ps_v102[0x3b];
    s_v115 = CRI_PART(au_v52,8,2) + ps_v102[0x3c];
    s_v116 = CRI_PART(au_v36,10,2) + ps_v102[0x3d];
    s_v117 = CRI_PART(au_v20,12,2) + ps_v102[0x3e];
    s_v118 = (CRI_PART(au_v12,13,2) >> 8) + ps_v102[0x3f];
    *pc_v101 = (0 < s_v127) * (s_v127 < 0x100) * (char)s_v127 - (0xff < s_v127);
    pc_v101[1] = (0 < s_v128) * (s_v128 < 0x100) * (char)s_v128 - (0xff < s_v128);
    pc_v101[2] = (0 < s_v129) * (s_v129 < 0x100) * (char)s_v129 - (0xff < s_v129);
    pc_v101[3] = (0 < s_v130) * (s_v130 < 0x100) * (char)s_v130 - (0xff < s_v130);
    pc_v101[4] = (0 < s_v131) * (s_v131 < 0x100) * (char)s_v131 - (0xff < s_v131);
    pc_v101[5] = (0 < s_v132) * (s_v132 < 0x100) * (char)s_v132 - (0xff < s_v132);
    pc_v101[6] = (0 < s_v133) * (s_v133 < 0x100) * (char)s_v133 - (0xff < s_v133);
    pc_v101[7] = (0 < s_v134) * (s_v134 < 0x100) * (char)s_v134 - (0xff < s_v134);
    pc_v3 = pc_v101 + l_v99;
    *pc_v3 = (0 < s_v103) * (s_v103 < 0x100) * (char)s_v103 - (0xff < s_v103);
    pc_v3[1] = (0 < s_v104) * (s_v104 < 0x100) * (char)s_v104 - (0xff < s_v104);
    pc_v3[2] = (0 < s_v105) * (s_v105 < 0x100) * (char)s_v105 - (0xff < s_v105);
    pc_v3[3] = (0 < s_v106) * (s_v106 < 0x100) * (char)s_v106 - (0xff < s_v106);
    pc_v3[4] = (0 < s_v107) * (s_v107 < 0x100) * (char)s_v107 - (0xff < s_v107);
    pc_v3[5] = (0 < s_v108) * (s_v108 < 0x100) * (char)s_v108 - (0xff < s_v108);
    pc_v3[6] = (0 < s_v109) * (s_v109 < 0x100) * (char)s_v109 - (0xff < s_v109);
    pc_v3[7] = (0 < s_v110) * (s_v110 < 0x100) * (char)s_v110 - (0xff < s_v110);
    pc_v101 = pc_v101 + l_v100;
    *pc_v101 = (0 < s_v119) * (s_v119 < 0x100) * (char)s_v119 - (0xff < s_v119);
    pc_v101[1] = (0 < s_v120) * (s_v120 < 0x100) * (char)s_v120 - (0xff < s_v120);
    pc_v101[2] = (0 < s_v121) * (s_v121 < 0x100) * (char)s_v121 - (0xff < s_v121);
    pc_v101[3] = (0 < s_v122) * (s_v122 < 0x100) * (char)s_v122 - (0xff < s_v122);
    pc_v101[4] = (0 < s_v123) * (s_v123 < 0x100) * (char)s_v123 - (0xff < s_v123);
    pc_v101[5] = (0 < s_v124) * (s_v124 < 0x100) * (char)s_v124 - (0xff < s_v124);
    pc_v101[6] = (0 < s_v125) * (s_v125 < 0x100) * (char)s_v125 - (0xff < s_v125);
    pc_v101[7] = (0 < s_v126) * (s_v126 < 0x100) * (char)s_v126 - (0xff < s_v126);
    pc_v101 = pc_v101 + l_v99;
    *pc_v101 = (0 < s_v111) * (s_v111 < 0x100) * (char)s_v111 - (0xff < s_v111);
    pc_v101[1] = (0 < s_v112) * (s_v112 < 0x100) * (char)s_v112 - (0xff < s_v112);
    pc_v101[2] = (0 < s_v113) * (s_v113 < 0x100) * (char)s_v113 - (0xff < s_v113);
    pc_v101[3] = (0 < s_v114) * (s_v114 < 0x100) * (char)s_v114 - (0xff < s_v114);
    pc_v101[4] = (0 < s_v115) * (s_v115 < 0x100) * (char)s_v115 - (0xff < s_v115);
    pc_v101[5] = (0 < s_v116) * (s_v116 < 0x100) * (char)s_v116 - (0xff < s_v116);
    pc_v101[6] = (0 < s_v117) * (s_v117 < 0x100) * (char)s_v117 - (0xff < s_v117);
    pc_v101[7] = (0 < s_v118) * (s_v118 < 0x100) * (char)s_v118 - (0xff < s_v118);
    ps_v102 = (short *)*arg1;
  } while (ps_v102 != (short *)0x0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140059290
void FUN_140059290(cri_any cri_unused, ...)
{
  int i_v1;
  
  i_v1 = FUN_140062830();
  if (i_v1 != 0) {
    DAT_143fe8248 = &PTR_LAB_1431bab60;
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400593f0
void FUN_1400593f0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4, ...)
{
  byte *arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  int arg3 = cri_p2;
  int arg4 = cri_p3;
  int arg5 = cri_p4;
  byte *pb_v1;
  byte *pb_v2;
  byte b_v3;
  byte b_v4;
  byte b_v5;
  byte b_v6;
  byte b_v7;
  byte b_v8;
  byte b_v9;
  byte b_v10;
  byte *pb_v11;
  byte *pb_v12;
  byte *pb_v13;
  byte *pb_v14;
  byte *pb_v15;
  byte *pb_v16;
  byte *pb_v17;
  byte *pb_v18;
  byte *pb_v19;
  byte *pb_v20;
  byte *pb_v21;
  byte *pb_v22;
  byte *pb_v23;
  byte *pb_v24;
  byte *pb_v25;
  byte *pb_v26;
  byte *pb_v27;
  byte *pb_v28;
  byte *pb_v29;
  byte *pb_v30;
  byte *pb_v31;
  byte *pb_v32;
  byte *pb_v33;
  byte *pb_v34;
  byte *pb_v35;
  byte *pb_v36;
  byte *pb_v37;
  byte *pb_v38;
  ulonglong u_v39;
  longlong l_v40;
  byte *pb_v41;
  char c_v42;
  char c_v43;
  char c_v44;
  char c_v45;
  char c_v46;
  char c_v47;
  char c_v48;
  char c_v49;
  byte b_v50;
  byte b_v51;
  byte b_v52;
  byte b_v53;
  byte b_v54;
  byte b_v55;
  byte b_v56;
  byte b_v57;
  byte b_v58;
  byte b_v59;
  byte b_v60;
  byte b_v61;
  byte b_v62;
  byte b_v63;
  byte b_v64;
  byte b_v65;
  byte b_v66;
  byte b_v67;
  byte b_v68;
  byte b_v69;
  byte b_v70;
  byte b_v71;
  byte b_v72;
  byte b_v73;
  cri_u1 u_v74;
  cri_u1 u_v75;
  cri_u1 u_v76;
  cri_u1 u_v77;
  cri_u1 u_v78;
  cri_u1 u_v79;
  cri_u1 u_v80;
  cri_u1 u_v81;
  
  if (arg3 == arg4) {
    l_v40 = (longlong)arg4;
    b_v3 = *arg1 ^ arg1[1];
    b_v4 = arg1[1] ^ arg1[2];
    b_v58 = arg1[2] ^ arg1[3];
    b_v59 = arg1[3] ^ arg1[4];
    b_v60 = arg1[4] ^ arg1[5];
    b_v61 = arg1[5] ^ arg1[6];
    b_v62 = arg1[6] ^ arg1[7];
    b_v63 = arg1[7] ^ arg1[8];
    b_v66 = pavgb(*arg1,arg1[1]);
    b_v67 = pavgb(arg1[1],arg1[2]);
    b_v68 = pavgb(arg1[2],arg1[3]);
    b_v69 = pavgb(arg1[3],arg1[4]);
    b_v70 = pavgb(arg1[4],arg1[5]);
    b_v71 = pavgb(arg1[5],arg1[6]);
    b_v72 = pavgb(arg1[6],arg1[7]);
    b_v73 = pavgb(arg1[7],arg1[8]);
    u_v74 = pavgb(0,0);
    u_v75 = pavgb(0,0);
    u_v76 = pavgb(0,0);
    u_v77 = pavgb(0,0);
    u_v78 = pavgb(0,0);
    u_v79 = pavgb(0,0);
    u_v80 = pavgb(0,0);
    u_v81 = pavgb(0,0);
    if (0 < arg5) {
      u_v39 = (ulonglong)((arg5 - 1U >> 1) + 1);
      do {
        pb_v41 = arg1 + l_v40;
        arg1 = pb_v41 + l_v40;
        b_v50 = pavgb(*pb_v41,pb_v41[1]);
        b_v51 = pavgb(pb_v41[1],pb_v41[2]);
        b_v52 = pavgb(pb_v41[2],pb_v41[3]);
        b_v53 = pavgb(pb_v41[3],pb_v41[4]);
        b_v54 = pavgb(pb_v41[4],pb_v41[5]);
        b_v55 = pavgb(pb_v41[5],pb_v41[6]);
        b_v56 = pavgb(pb_v41[6],pb_v41[7]);
        b_v57 = pavgb(pb_v41[7],pb_v41[8]);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v64 = *pb_v41 ^ pb_v41[1];
        b_v65 = pb_v41[1] ^ pb_v41[2];
        b_v5 = pb_v41[2] ^ pb_v41[3];
        b_v6 = pb_v41[3] ^ pb_v41[4];
        b_v7 = pb_v41[4] ^ pb_v41[5];
        b_v8 = pb_v41[5] ^ pb_v41[6];
        b_v9 = pb_v41[6] ^ pb_v41[7];
        b_v10 = pb_v41[7] ^ pb_v41[8];
        c_v42 = pavgb(b_v50,b_v66);
        c_v43 = pavgb(b_v51,b_v67);
        c_v44 = pavgb(b_v52,b_v68);
        c_v45 = pavgb(b_v53,b_v69);
        c_v46 = pavgb(b_v54,b_v70);
        c_v47 = pavgb(b_v55,b_v71);
        c_v48 = pavgb(b_v56,b_v72);
        c_v49 = pavgb(b_v57,b_v73);
        pavgb(0,u_v74);
        pavgb(0,u_v75);
        pavgb(0,u_v76);
        pavgb(0,u_v77);
        pavgb(0,u_v78);
        pavgb(0,u_v79);
        pavgb(0,u_v80);
        pavgb(0,u_v81);
        *arg2 = CONCAT17(c_v49 - ((b_v10 | b_v63) & (b_v57 ^ b_v73) & 1),
                            CONCAT16(c_v48 - ((b_v9 | b_v62) & (b_v56 ^ b_v72) & 1),
                                     CONCAT15(c_v47 - ((b_v8 | b_v61) & (b_v55 ^ b_v71) & 1),
                                              CONCAT14(c_v46 - ((b_v7 | b_v60) &
                                                                 (b_v54 ^ b_v70) & 1),
                                                       CONCAT13(c_v45 - ((b_v6 | b_v59) &
                                                                          (b_v53 ^ b_v69) & 1),
                                                                CONCAT12(c_v44 - ((b_v5 | b_v58)
                                                                                   & (b_v52 ^ 
                                                  b_v68) & 1),
                                                  CONCAT11(c_v43 - ((b_v65 | b_v4) &
                                                                     (b_v51 ^ b_v67) & 1),
                                                           c_v42 - ((b_v64 | b_v3) &
                                                                     (b_v50 ^ b_v66) & 1))))))));
        b_v66 = pavgb(*arg1,arg1[1]);
        b_v67 = pavgb(arg1[1],arg1[2]);
        b_v68 = pavgb(arg1[2],arg1[3]);
        b_v69 = pavgb(arg1[3],arg1[4]);
        b_v70 = pavgb(arg1[4],arg1[5]);
        b_v71 = pavgb(arg1[5],arg1[6]);
        b_v72 = pavgb(arg1[6],arg1[7]);
        b_v73 = pavgb(arg1[7],arg1[8]);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v3 = *arg1 ^ arg1[1];
        b_v4 = arg1[1] ^ arg1[2];
        b_v58 = arg1[2] ^ arg1[3];
        b_v59 = arg1[3] ^ arg1[4];
        b_v60 = arg1[4] ^ arg1[5];
        b_v61 = arg1[5] ^ arg1[6];
        b_v62 = arg1[6] ^ arg1[7];
        b_v63 = arg1[7] ^ arg1[8];
        u_v74 = 0;
        u_v75 = 0;
        u_v76 = 0;
        u_v77 = 0;
        u_v78 = 0;
        u_v79 = 0;
        u_v80 = 0;
        u_v81 = 0;
        c_v42 = pavgb(b_v66,b_v50);
        c_v43 = pavgb(b_v67,b_v51);
        c_v44 = pavgb(b_v68,b_v52);
        c_v45 = pavgb(b_v69,b_v53);
        c_v46 = pavgb(b_v70,b_v54);
        c_v47 = pavgb(b_v71,b_v55);
        c_v48 = pavgb(b_v72,b_v56);
        c_v49 = pavgb(b_v73,b_v57);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        *(cri_u8 *)((longlong)arg2 + l_v40) =
             CONCAT17(c_v49 - ((b_v63 | b_v10) & (b_v73 ^ b_v57) & 1),
                      CONCAT16(c_v48 - ((b_v62 | b_v9) & (b_v72 ^ b_v56) & 1),
                               CONCAT15(c_v47 - ((b_v61 | b_v8) & (b_v71 ^ b_v55) & 1),
                                        CONCAT14(c_v46 - ((b_v60 | b_v7) & (b_v70 ^ b_v54) & 1)
                                                 ,CONCAT13(c_v45 - ((b_v59 | b_v6) &
                                                                     (b_v69 ^ b_v53) & 1),
                                                           CONCAT12(c_v44 - ((b_v58 | b_v5) &
                                                                              (b_v68 ^ b_v52) & 1)
                                                                    ,CONCAT11(c_v43 - ((b_v4 | 
                                                  b_v65) & (b_v67 ^ b_v51) & 1),
                                                  c_v42 - ((b_v3 | b_v64) & (b_v66 ^ b_v50) & 1
                                                           ))))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v40 + l_v40);
        u_v39 = u_v39 - 1;
      } while (u_v39 != 0);
      return;
    }
  }
  else {
    pb_v41 = arg1 + arg3;
    if (0 < arg5) {
      l_v40 = (longlong)arg4;
      do {
        b_v3 = *arg1;
        pb_v18 = arg1 + 1;
        pb_v19 = arg1 + 2;
        pb_v20 = arg1 + 3;
        pb_v21 = arg1 + 4;
        pb_v22 = arg1 + 5;
        pb_v23 = arg1 + 6;
        pb_v24 = arg1 + 7;
        b_v4 = *pb_v41;
        pb_v32 = pb_v41 + 1;
        pb_v33 = pb_v41 + 2;
        pb_v34 = pb_v41 + 3;
        pb_v35 = pb_v41 + 4;
        pb_v36 = pb_v41 + 5;
        pb_v37 = pb_v41 + 6;
        pb_v38 = pb_v41 + 7;
        pb_v1 = pb_v41 + 1;
        pb_v25 = pb_v41 + 2;
        pb_v26 = pb_v41 + 3;
        pb_v27 = pb_v41 + 4;
        pb_v28 = pb_v41 + 5;
        pb_v29 = pb_v41 + 6;
        pb_v30 = pb_v41 + 7;
        pb_v31 = pb_v41 + 8;
        arg5 = arg5 + -1;
        pb_v41 = pb_v41 + l_v40;
        pb_v2 = arg1 + 1;
        pb_v11 = arg1 + 2;
        pb_v12 = arg1 + 3;
        pb_v13 = arg1 + 4;
        pb_v14 = arg1 + 5;
        pb_v15 = arg1 + 6;
        pb_v16 = arg1 + 7;
        pb_v17 = arg1 + 8;
        arg1 = arg1 + l_v40;
        b_v58 = pavgb(b_v4,*pb_v1);
        b_v59 = pavgb(*pb_v32,*pb_v25);
        b_v60 = pavgb(*pb_v33,*pb_v26);
        b_v61 = pavgb(*pb_v34,*pb_v27);
        b_v62 = pavgb(*pb_v35,*pb_v28);
        b_v63 = pavgb(*pb_v36,*pb_v29);
        b_v66 = pavgb(*pb_v37,*pb_v30);
        b_v67 = pavgb(*pb_v38,*pb_v31);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v68 = pavgb(b_v3,*pb_v2);
        b_v69 = pavgb(*pb_v18,*pb_v11);
        b_v70 = pavgb(*pb_v19,*pb_v12);
        b_v71 = pavgb(*pb_v20,*pb_v13);
        b_v72 = pavgb(*pb_v21,*pb_v14);
        b_v73 = pavgb(*pb_v22,*pb_v15);
        b_v64 = pavgb(*pb_v23,*pb_v16);
        b_v65 = pavgb(*pb_v24,*pb_v17);
        u_v74 = pavgb(0,0);
        u_v75 = pavgb(0,0);
        u_v76 = pavgb(0,0);
        u_v77 = pavgb(0,0);
        u_v78 = pavgb(0,0);
        u_v79 = pavgb(0,0);
        u_v80 = pavgb(0,0);
        u_v81 = pavgb(0,0);
        c_v42 = pavgb(b_v58,b_v68);
        c_v43 = pavgb(b_v59,b_v69);
        c_v44 = pavgb(b_v60,b_v70);
        c_v45 = pavgb(b_v61,b_v71);
        c_v46 = pavgb(b_v62,b_v72);
        c_v47 = pavgb(b_v63,b_v73);
        c_v48 = pavgb(b_v66,b_v64);
        c_v49 = pavgb(b_v67,b_v65);
        pavgb(0,u_v74);
        pavgb(0,u_v75);
        pavgb(0,u_v76);
        pavgb(0,u_v77);
        pavgb(0,u_v78);
        pavgb(0,u_v79);
        pavgb(0,u_v80);
        pavgb(0,u_v81);
        *arg2 = CONCAT17(c_v49 - ((*pb_v38 ^ *pb_v31 | *pb_v24 ^ *pb_v17) &
                                      (b_v67 ^ b_v65) & 1),
                            CONCAT16(c_v48 - ((*pb_v37 ^ *pb_v30 | *pb_v23 ^ *pb_v16) &
                                               (b_v66 ^ b_v64) & 1),
                                     CONCAT15(c_v47 - ((*pb_v36 ^ *pb_v29 | *pb_v22 ^ *pb_v15)
                                                        & (b_v63 ^ b_v73) & 1),
                                              CONCAT14(c_v46 - ((*pb_v35 ^ *pb_v28 |
                                                                 *pb_v21 ^ *pb_v14) &
                                                                 (b_v62 ^ b_v72) & 1),
                                                       CONCAT13(c_v45 - ((*pb_v34 ^ *pb_v27 |
                                                                          *pb_v20 ^ *pb_v13) &
                                                                          (b_v61 ^ b_v71) & 1),
                                                                CONCAT12(c_v44 - ((*pb_v33 ^
                                                                                    *pb_v26 |
                                                                                   *pb_v19 ^
                                                                                   *pb_v12) &
                                                                                   (b_v60 ^ b_v70)
                                                                                  & 1),
                                                                         CONCAT11(c_v43 - ((*
                                                  pb_v32 ^ *pb_v25 | *pb_v18 ^ *pb_v11) &
                                                  (b_v59 ^ b_v69) & 1),
                                                  c_v42 - ((b_v4 ^ *pb_v1 | b_v3 ^ *pb_v2) &
                                                            (b_v58 ^ b_v68) & 1))))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v40);
      } while (0 < arg5);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140059810
void FUN_140059810(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4, ...)
{
  byte *arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  int arg3 = cri_p2;
  int arg4 = cri_p3;
  int arg5 = cri_p4;
  byte *pb_v1;
  byte *pb_v2;
  byte *pb_v3;
  byte b_v4;
  byte b_v5;
  byte b_v6;
  byte b_v7;
  byte b_v8;
  byte b_v9;
  byte b_v10;
  byte b_v11;
  byte *pb_v12;
  byte *pb_v13;
  byte *pb_v14;
  byte *pb_v15;
  byte *pb_v16;
  byte *pb_v17;
  byte *pb_v18;
  byte *pb_v19;
  byte *pb_v20;
  byte *pb_v21;
  byte *pb_v22;
  byte *pb_v23;
  byte *pb_v24;
  byte *pb_v25;
  byte *pb_v26;
  byte *pb_v27;
  byte *pb_v28;
  byte *pb_v29;
  byte *pb_v30;
  byte *pb_v31;
  byte *pb_v32;
  byte *pb_v33;
  byte *pb_v34;
  byte *pb_v35;
  byte *pb_v36;
  byte *pb_v37;
  byte *pb_v38;
  byte *pb_v39;
  ulonglong u_v40;
  longlong l_v41;
  byte *pb_v42;
  byte *pb_v43;
  cri_u8 *pu_v44;
  char c_v45;
  char c_v46;
  char c_v47;
  char c_v48;
  char c_v49;
  char c_v50;
  char c_v51;
  char c_v52;
  byte b_v53;
  byte b_v54;
  byte b_v55;
  byte b_v56;
  byte b_v57;
  byte b_v58;
  byte b_v59;
  byte b_v60;
  byte b_v61;
  byte b_v62;
  byte b_v63;
  byte b_v64;
  byte b_v65;
  byte b_v66;
  byte b_v67;
  byte b_v68;
  byte b_v69;
  byte b_v70;
  byte b_v71;
  byte b_v72;
  byte b_v73;
  byte b_v74;
  byte b_v75;
  byte b_v76;
  cri_u1 u_v77;
  cri_u1 u_v78;
  cri_u1 u_v79;
  cri_u1 u_v80;
  cri_u1 u_v81;
  cri_u1 u_v82;
  cri_u1 u_v83;
  cri_u1 u_v84;
  
  if (arg3 == arg4) {
    l_v41 = (longlong)arg4;
    b_v61 = *arg1 ^ arg1[1];
    b_v62 = arg1[1] ^ arg1[2];
    b_v63 = arg1[2] ^ arg1[3];
    b_v64 = arg1[3] ^ arg1[4];
    b_v65 = arg1[4] ^ arg1[5];
    b_v66 = arg1[5] ^ arg1[6];
    b_v67 = arg1[6] ^ arg1[7];
    b_v68 = arg1[7] ^ arg1[8];
    b_v69 = pavgb(*arg1,arg1[1]);
    b_v70 = pavgb(arg1[1],arg1[2]);
    b_v71 = pavgb(arg1[2],arg1[3]);
    b_v72 = pavgb(arg1[3],arg1[4]);
    b_v73 = pavgb(arg1[4],arg1[5]);
    b_v74 = pavgb(arg1[5],arg1[6]);
    b_v75 = pavgb(arg1[6],arg1[7]);
    b_v76 = pavgb(arg1[7],arg1[8]);
    u_v77 = pavgb(0,0);
    u_v78 = pavgb(0,0);
    u_v79 = pavgb(0,0);
    u_v80 = pavgb(0,0);
    u_v81 = pavgb(0,0);
    u_v82 = pavgb(0,0);
    u_v83 = pavgb(0,0);
    u_v84 = pavgb(0,0);
    if (0 < arg5) {
      u_v40 = (ulonglong)((arg5 - 1U >> 1) + 1);
      pb_v43 = arg1 + l_v41;
      pu_v44 = arg2;
      do {
        pb_v42 = pb_v43 + l_v41;
        b_v53 = pavgb(*pb_v43,pb_v43[1]);
        b_v54 = pavgb(pb_v43[1],pb_v43[2]);
        b_v55 = pavgb(pb_v43[2],pb_v43[3]);
        b_v56 = pavgb(pb_v43[3],pb_v43[4]);
        b_v57 = pavgb(pb_v43[4],pb_v43[5]);
        b_v58 = pavgb(pb_v43[5],pb_v43[6]);
        b_v59 = pavgb(pb_v43[6],pb_v43[7]);
        b_v60 = pavgb(pb_v43[7],pb_v43[8]);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v4 = *pb_v43 ^ pb_v43[1];
        b_v5 = pb_v43[1] ^ pb_v43[2];
        b_v6 = pb_v43[2] ^ pb_v43[3];
        b_v7 = pb_v43[3] ^ pb_v43[4];
        b_v8 = pb_v43[4] ^ pb_v43[5];
        b_v9 = pb_v43[5] ^ pb_v43[6];
        b_v10 = pb_v43[6] ^ pb_v43[7];
        b_v11 = pb_v43[7] ^ pb_v43[8];
        c_v45 = pavgb(b_v53,b_v69);
        c_v46 = pavgb(b_v54,b_v70);
        c_v47 = pavgb(b_v55,b_v71);
        c_v48 = pavgb(b_v56,b_v72);
        c_v49 = pavgb(b_v57,b_v73);
        c_v50 = pavgb(b_v58,b_v74);
        c_v51 = pavgb(b_v59,b_v75);
        c_v52 = pavgb(b_v60,b_v76);
        pavgb(0,u_v77);
        pavgb(0,u_v78);
        pavgb(0,u_v79);
        pavgb(0,u_v80);
        pavgb(0,u_v81);
        pavgb(0,u_v82);
        pavgb(0,u_v83);
        pavgb(0,u_v84);
        *pu_v44 = CONCAT17(c_v52 - ((b_v11 | b_v68) & (b_v60 ^ b_v76) & 1),
                            CONCAT16(c_v51 - ((b_v10 | b_v67) & (b_v59 ^ b_v75) & 1),
                                     CONCAT15(c_v50 - ((b_v9 | b_v66) & (b_v58 ^ b_v74) & 1),
                                              CONCAT14(c_v49 - ((b_v8 | b_v65) &
                                                                 (b_v57 ^ b_v73) & 1),
                                                       CONCAT13(c_v48 - ((b_v7 | b_v64) &
                                                                          (b_v56 ^ b_v72) & 1),
                                                                CONCAT12(c_v47 - ((b_v6 | b_v63)
                                                                                   & (b_v55 ^ 
                                                  b_v71) & 1),
                                                  CONCAT11(c_v46 - ((b_v5 | b_v62) &
                                                                     (b_v54 ^ b_v70) & 1),
                                                           c_v45 - ((b_v4 | b_v61) &
                                                                     (b_v53 ^ b_v69) & 1))))))));
        pb_v43 = pb_v42 + l_v41;
        b_v69 = pavgb(*pb_v42,pb_v42[1]);
        b_v70 = pavgb(pb_v42[1],pb_v42[2]);
        b_v71 = pavgb(pb_v42[2],pb_v42[3]);
        b_v72 = pavgb(pb_v42[3],pb_v42[4]);
        b_v73 = pavgb(pb_v42[4],pb_v42[5]);
        b_v74 = pavgb(pb_v42[5],pb_v42[6]);
        b_v75 = pavgb(pb_v42[6],pb_v42[7]);
        b_v76 = pavgb(pb_v42[7],pb_v42[8]);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v61 = *pb_v42 ^ pb_v42[1];
        b_v62 = pb_v42[1] ^ pb_v42[2];
        b_v63 = pb_v42[2] ^ pb_v42[3];
        b_v64 = pb_v42[3] ^ pb_v42[4];
        b_v65 = pb_v42[4] ^ pb_v42[5];
        b_v66 = pb_v42[5] ^ pb_v42[6];
        b_v67 = pb_v42[6] ^ pb_v42[7];
        b_v68 = pb_v42[7] ^ pb_v42[8];
        u_v77 = 0;
        u_v78 = 0;
        u_v79 = 0;
        u_v80 = 0;
        u_v81 = 0;
        u_v82 = 0;
        u_v83 = 0;
        u_v84 = 0;
        c_v45 = pavgb(b_v69,b_v53);
        c_v46 = pavgb(b_v70,b_v54);
        c_v47 = pavgb(b_v71,b_v55);
        c_v48 = pavgb(b_v72,b_v56);
        c_v49 = pavgb(b_v73,b_v57);
        c_v50 = pavgb(b_v74,b_v58);
        c_v51 = pavgb(b_v75,b_v59);
        c_v52 = pavgb(b_v76,b_v60);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        *(cri_u8 *)((longlong)pu_v44 + l_v41) =
             CONCAT17(c_v52 - ((b_v68 | b_v11) & (b_v76 ^ b_v60) & 1),
                      CONCAT16(c_v51 - ((b_v67 | b_v10) & (b_v75 ^ b_v59) & 1),
                               CONCAT15(c_v50 - ((b_v66 | b_v9) & (b_v74 ^ b_v58) & 1),
                                        CONCAT14(c_v49 - ((b_v65 | b_v8) & (b_v73 ^ b_v57) & 1)
                                                 ,CONCAT13(c_v48 - ((b_v64 | b_v7) &
                                                                     (b_v72 ^ b_v56) & 1),
                                                           CONCAT12(c_v47 - ((b_v63 | b_v6) &
                                                                              (b_v71 ^ b_v55) & 1)
                                                                    ,CONCAT11(c_v46 - ((b_v62 | 
                                                  b_v5) & (b_v70 ^ b_v54) & 1),
                                                  c_v45 - ((b_v61 | b_v4) & (b_v69 ^ b_v53) & 1
                                                           ))))))));
        pu_v44 = (cri_u8 *)((longlong)pu_v44 + l_v41 + l_v41);
        u_v40 = u_v40 - 1;
      } while (u_v40 != 0);
    }
    pb_v43 = arg1 + l_v41 + 8;
    arg2 = arg2 + 1;
    b_v61 = arg1[8] ^ arg1[9];
    b_v62 = arg1[9] ^ arg1[10];
    b_v63 = arg1[10] ^ arg1[0xb];
    b_v64 = arg1[0xb] ^ arg1[0xc];
    b_v65 = arg1[0xc] ^ arg1[0xd];
    b_v66 = arg1[0xd] ^ arg1[0xe];
    b_v67 = arg1[0xe] ^ arg1[0xf];
    b_v68 = arg1[0xf] ^ arg1[0x10];
    b_v69 = pavgb(arg1[8],arg1[9]);
    b_v70 = pavgb(arg1[9],arg1[10]);
    b_v71 = pavgb(arg1[10],arg1[0xb]);
    b_v72 = pavgb(arg1[0xb],arg1[0xc]);
    b_v73 = pavgb(arg1[0xc],arg1[0xd]);
    b_v74 = pavgb(arg1[0xd],arg1[0xe]);
    b_v75 = pavgb(arg1[0xe],arg1[0xf]);
    b_v76 = pavgb(arg1[0xf],arg1[0x10]);
    u_v77 = pavgb(0,0);
    u_v78 = pavgb(0,0);
    u_v79 = pavgb(0,0);
    u_v80 = pavgb(0,0);
    u_v81 = pavgb(0,0);
    u_v82 = pavgb(0,0);
    u_v83 = pavgb(0,0);
    u_v84 = pavgb(0,0);
    if (0 < arg5) {
      u_v40 = (ulonglong)((arg5 - 1U >> 1) + 1);
      do {
        pb_v42 = pb_v43 + l_v41;
        b_v53 = pavgb(*pb_v43,pb_v43[1]);
        b_v54 = pavgb(pb_v43[1],pb_v43[2]);
        b_v55 = pavgb(pb_v43[2],pb_v43[3]);
        b_v56 = pavgb(pb_v43[3],pb_v43[4]);
        b_v57 = pavgb(pb_v43[4],pb_v43[5]);
        b_v58 = pavgb(pb_v43[5],pb_v43[6]);
        b_v59 = pavgb(pb_v43[6],pb_v43[7]);
        b_v60 = pavgb(pb_v43[7],pb_v43[8]);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v4 = *pb_v43 ^ pb_v43[1];
        b_v5 = pb_v43[1] ^ pb_v43[2];
        b_v6 = pb_v43[2] ^ pb_v43[3];
        b_v7 = pb_v43[3] ^ pb_v43[4];
        b_v8 = pb_v43[4] ^ pb_v43[5];
        b_v9 = pb_v43[5] ^ pb_v43[6];
        b_v10 = pb_v43[6] ^ pb_v43[7];
        b_v11 = pb_v43[7] ^ pb_v43[8];
        c_v45 = pavgb(b_v53,b_v69);
        c_v46 = pavgb(b_v54,b_v70);
        c_v47 = pavgb(b_v55,b_v71);
        c_v48 = pavgb(b_v56,b_v72);
        c_v49 = pavgb(b_v57,b_v73);
        c_v50 = pavgb(b_v58,b_v74);
        c_v51 = pavgb(b_v59,b_v75);
        c_v52 = pavgb(b_v60,b_v76);
        pavgb(0,u_v77);
        pavgb(0,u_v78);
        pavgb(0,u_v79);
        pavgb(0,u_v80);
        pavgb(0,u_v81);
        pavgb(0,u_v82);
        pavgb(0,u_v83);
        pavgb(0,u_v84);
        *arg2 = CONCAT17(c_v52 - ((b_v11 | b_v68) & (b_v60 ^ b_v76) & 1),
                            CONCAT16(c_v51 - ((b_v10 | b_v67) & (b_v59 ^ b_v75) & 1),
                                     CONCAT15(c_v50 - ((b_v9 | b_v66) & (b_v58 ^ b_v74) & 1),
                                              CONCAT14(c_v49 - ((b_v8 | b_v65) &
                                                                 (b_v57 ^ b_v73) & 1),
                                                       CONCAT13(c_v48 - ((b_v7 | b_v64) &
                                                                          (b_v56 ^ b_v72) & 1),
                                                                CONCAT12(c_v47 - ((b_v6 | b_v63)
                                                                                   & (b_v55 ^ 
                                                  b_v71) & 1),
                                                  CONCAT11(c_v46 - ((b_v5 | b_v62) &
                                                                     (b_v54 ^ b_v70) & 1),
                                                           c_v45 - ((b_v4 | b_v61) &
                                                                     (b_v53 ^ b_v69) & 1))))))));
        pb_v43 = pb_v42 + l_v41;
        b_v69 = pavgb(*pb_v42,pb_v42[1]);
        b_v70 = pavgb(pb_v42[1],pb_v42[2]);
        b_v71 = pavgb(pb_v42[2],pb_v42[3]);
        b_v72 = pavgb(pb_v42[3],pb_v42[4]);
        b_v73 = pavgb(pb_v42[4],pb_v42[5]);
        b_v74 = pavgb(pb_v42[5],pb_v42[6]);
        b_v75 = pavgb(pb_v42[6],pb_v42[7]);
        b_v76 = pavgb(pb_v42[7],pb_v42[8]);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v61 = *pb_v42 ^ pb_v42[1];
        b_v62 = pb_v42[1] ^ pb_v42[2];
        b_v63 = pb_v42[2] ^ pb_v42[3];
        b_v64 = pb_v42[3] ^ pb_v42[4];
        b_v65 = pb_v42[4] ^ pb_v42[5];
        b_v66 = pb_v42[5] ^ pb_v42[6];
        b_v67 = pb_v42[6] ^ pb_v42[7];
        b_v68 = pb_v42[7] ^ pb_v42[8];
        u_v77 = 0;
        u_v78 = 0;
        u_v79 = 0;
        u_v80 = 0;
        u_v81 = 0;
        u_v82 = 0;
        u_v83 = 0;
        u_v84 = 0;
        c_v45 = pavgb(b_v69,b_v53);
        c_v46 = pavgb(b_v70,b_v54);
        c_v47 = pavgb(b_v71,b_v55);
        c_v48 = pavgb(b_v72,b_v56);
        c_v49 = pavgb(b_v73,b_v57);
        c_v50 = pavgb(b_v74,b_v58);
        c_v51 = pavgb(b_v75,b_v59);
        c_v52 = pavgb(b_v76,b_v60);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        *(cri_u8 *)((longlong)arg2 + l_v41) =
             CONCAT17(c_v52 - ((b_v68 | b_v11) & (b_v76 ^ b_v60) & 1),
                      CONCAT16(c_v51 - ((b_v67 | b_v10) & (b_v75 ^ b_v59) & 1),
                               CONCAT15(c_v50 - ((b_v66 | b_v9) & (b_v74 ^ b_v58) & 1),
                                        CONCAT14(c_v49 - ((b_v65 | b_v8) & (b_v73 ^ b_v57) & 1)
                                                 ,CONCAT13(c_v48 - ((b_v64 | b_v7) &
                                                                     (b_v72 ^ b_v56) & 1),
                                                           CONCAT12(c_v47 - ((b_v63 | b_v6) &
                                                                              (b_v71 ^ b_v55) & 1)
                                                                    ,CONCAT11(c_v46 - ((b_v62 | 
                                                  b_v5) & (b_v70 ^ b_v54) & 1),
                                                  c_v45 - ((b_v61 | b_v4) & (b_v69 ^ b_v53) & 1
                                                           ))))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v41 + l_v41);
        u_v40 = u_v40 - 1;
      } while (u_v40 != 0);
      return;
    }
  }
  else {
    pb_v43 = arg1 + arg3;
    if (0 < arg5) {
      l_v41 = (longlong)arg4;
      do {
        arg5 = arg5 + -1;
        b_v61 = pavgb(*pb_v43,pb_v43[1]);
        b_v62 = pavgb(pb_v43[1],pb_v43[2]);
        b_v63 = pavgb(pb_v43[2],pb_v43[3]);
        b_v64 = pavgb(pb_v43[3],pb_v43[4]);
        b_v65 = pavgb(pb_v43[4],pb_v43[5]);
        b_v66 = pavgb(pb_v43[5],pb_v43[6]);
        b_v67 = pavgb(pb_v43[6],pb_v43[7]);
        b_v68 = pavgb(pb_v43[7],pb_v43[8]);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v69 = pavgb(*arg1,arg1[1]);
        b_v70 = pavgb(arg1[1],arg1[2]);
        b_v71 = pavgb(arg1[2],arg1[3]);
        b_v72 = pavgb(arg1[3],arg1[4]);
        b_v73 = pavgb(arg1[4],arg1[5]);
        b_v74 = pavgb(arg1[5],arg1[6]);
        b_v75 = pavgb(arg1[6],arg1[7]);
        b_v76 = pavgb(arg1[7],arg1[8]);
        u_v77 = pavgb(0,0);
        u_v78 = pavgb(0,0);
        u_v79 = pavgb(0,0);
        u_v80 = pavgb(0,0);
        u_v81 = pavgb(0,0);
        u_v82 = pavgb(0,0);
        u_v83 = pavgb(0,0);
        u_v84 = pavgb(0,0);
        c_v45 = pavgb(b_v61,b_v69);
        c_v46 = pavgb(b_v62,b_v70);
        c_v47 = pavgb(b_v63,b_v71);
        c_v48 = pavgb(b_v64,b_v72);
        c_v49 = pavgb(b_v65,b_v73);
        c_v50 = pavgb(b_v66,b_v74);
        c_v51 = pavgb(b_v67,b_v75);
        c_v52 = pavgb(b_v68,b_v76);
        pavgb(0,u_v77);
        pavgb(0,u_v78);
        pavgb(0,u_v79);
        pavgb(0,u_v80);
        pavgb(0,u_v81);
        pavgb(0,u_v82);
        pavgb(0,u_v83);
        pavgb(0,u_v84);
        *arg2 = CONCAT17(c_v52 - ((pb_v43[7] ^ pb_v43[8] | arg1[7] ^ arg1[8]) &
                                      (b_v68 ^ b_v76) & 1),
                            CONCAT16(c_v51 - ((pb_v43[6] ^ pb_v43[7] | arg1[6] ^ arg1[7]) &
                                               (b_v67 ^ b_v75) & 1),
                                     CONCAT15(c_v50 - ((pb_v43[5] ^ pb_v43[6] |
                                                        arg1[5] ^ arg1[6]) & (b_v66 ^ b_v74)
                                                       & 1),
                                              CONCAT14(c_v49 - ((pb_v43[4] ^ pb_v43[5] |
                                                                 arg1[4] ^ arg1[5]) &
                                                                 (b_v65 ^ b_v73) & 1),
                                                       CONCAT13(c_v48 - ((pb_v43[3] ^ pb_v43[4] |
                                                                          arg1[3] ^ arg1[4]) &
                                                                          (b_v64 ^ b_v72) & 1),
                                                                CONCAT12(c_v47 - ((pb_v43[2] ^
                                                                                    pb_v43[3] |
                                                                                   arg1[2] ^
                                                                                   arg1[3]) &
                                                                                   (b_v63 ^ b_v71)
                                                                                  & 1),
                                                                         CONCAT11(c_v46 - ((pb_v43
                                                  [1] ^ pb_v43[2] | arg1[1] ^ arg1[2]) &
                                                  (b_v62 ^ b_v70) & 1),
                                                  c_v45 - ((*pb_v43 ^ pb_v43[1] |
                                                            *arg1 ^ arg1[1]) &
                                                            (b_v61 ^ b_v69) & 1))))))));
        pb_v42 = arg1 + 8;
        pb_v19 = arg1 + 9;
        pb_v20 = arg1 + 10;
        pb_v21 = arg1 + 0xb;
        pb_v22 = arg1 + 0xc;
        pb_v23 = arg1 + 0xd;
        pb_v24 = arg1 + 0xe;
        pb_v25 = arg1 + 0xf;
        pb_v1 = pb_v43 + 8;
        pb_v33 = pb_v43 + 9;
        pb_v34 = pb_v43 + 10;
        pb_v35 = pb_v43 + 0xb;
        pb_v36 = pb_v43 + 0xc;
        pb_v37 = pb_v43 + 0xd;
        pb_v38 = pb_v43 + 0xe;
        pb_v39 = pb_v43 + 0xf;
        pb_v2 = pb_v43 + 9;
        pb_v26 = pb_v43 + 10;
        pb_v27 = pb_v43 + 0xb;
        pb_v28 = pb_v43 + 0xc;
        pb_v29 = pb_v43 + 0xd;
        pb_v30 = pb_v43 + 0xe;
        pb_v31 = pb_v43 + 0xf;
        pb_v32 = pb_v43 + 0x10;
        pb_v3 = arg1 + 9;
        pb_v12 = arg1 + 10;
        pb_v13 = arg1 + 0xb;
        pb_v14 = arg1 + 0xc;
        pb_v15 = arg1 + 0xd;
        pb_v16 = arg1 + 0xe;
        pb_v17 = arg1 + 0xf;
        pb_v18 = arg1 + 0x10;
        arg1 = arg1 + l_v41;
        pb_v43 = pb_v43 + l_v41;
        b_v61 = pavgb(*pb_v1,*pb_v2);
        b_v62 = pavgb(*pb_v33,*pb_v26);
        b_v63 = pavgb(*pb_v34,*pb_v27);
        b_v64 = pavgb(*pb_v35,*pb_v28);
        b_v65 = pavgb(*pb_v36,*pb_v29);
        b_v66 = pavgb(*pb_v37,*pb_v30);
        b_v67 = pavgb(*pb_v38,*pb_v31);
        b_v68 = pavgb(*pb_v39,*pb_v32);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        pavgb(0,0);
        b_v69 = pavgb(*pb_v42,*pb_v3);
        b_v70 = pavgb(*pb_v19,*pb_v12);
        b_v71 = pavgb(*pb_v20,*pb_v13);
        b_v72 = pavgb(*pb_v21,*pb_v14);
        b_v73 = pavgb(*pb_v22,*pb_v15);
        b_v74 = pavgb(*pb_v23,*pb_v16);
        b_v75 = pavgb(*pb_v24,*pb_v17);
        b_v76 = pavgb(*pb_v25,*pb_v18);
        u_v77 = pavgb(0,0);
        u_v78 = pavgb(0,0);
        u_v79 = pavgb(0,0);
        u_v80 = pavgb(0,0);
        u_v81 = pavgb(0,0);
        u_v82 = pavgb(0,0);
        u_v83 = pavgb(0,0);
        u_v84 = pavgb(0,0);
        c_v45 = pavgb(b_v61,b_v69);
        c_v46 = pavgb(b_v62,b_v70);
        c_v47 = pavgb(b_v63,b_v71);
        c_v48 = pavgb(b_v64,b_v72);
        c_v49 = pavgb(b_v65,b_v73);
        c_v50 = pavgb(b_v66,b_v74);
        c_v51 = pavgb(b_v67,b_v75);
        c_v52 = pavgb(b_v68,b_v76);
        pavgb(0,u_v77);
        pavgb(0,u_v78);
        pavgb(0,u_v79);
        pavgb(0,u_v80);
        pavgb(0,u_v81);
        pavgb(0,u_v82);
        pavgb(0,u_v83);
        pavgb(0,u_v84);
        arg2[1] = CONCAT17(c_v52 - ((*pb_v39 ^ *pb_v32 | *pb_v25 ^ *pb_v18) &
                                        (b_v68 ^ b_v76) & 1),
                              CONCAT16(c_v51 - ((*pb_v38 ^ *pb_v31 | *pb_v24 ^ *pb_v17) &
                                                 (b_v67 ^ b_v75) & 1),
                                       CONCAT15(c_v50 - ((*pb_v37 ^ *pb_v30 | *pb_v23 ^ *pb_v16
                                                          ) & (b_v66 ^ b_v74) & 1),
                                                CONCAT14(c_v49 - ((*pb_v36 ^ *pb_v29 |
                                                                   *pb_v22 ^ *pb_v15) &
                                                                   (b_v65 ^ b_v73) & 1),
                                                         CONCAT13(c_v48 - ((*pb_v35 ^ *pb_v28 |
                                                                            *pb_v21 ^ *pb_v14) &
                                                                            (b_v64 ^ b_v72) & 1),
                                                                  CONCAT12(c_v47 - ((*pb_v34 ^
                                                                                      *pb_v27 |
                                                                                     *pb_v20 ^
                                                                                     *pb_v13) &
                                                                                     (b_v63 ^ 
                                                  b_v71) & 1),
                                                  CONCAT11(c_v46 - ((*pb_v33 ^ *pb_v26 |
                                                                     *pb_v19 ^ *pb_v12) &
                                                                     (b_v62 ^ b_v70) & 1),
                                                           c_v45 - ((*pb_v1 ^ *pb_v2 |
                                                                     *pb_v42 ^ *pb_v3) &
                                                                     (b_v61 ^ b_v69) & 1))))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v41);
      } while (0 < arg5);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140059c40
void FUN_140059c40(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4, ...)
{
  byte *arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  int arg3 = cri_p2;
  int arg4 = cri_p3;
  uint arg5 = cri_p4;
  byte *pb_v1;
  byte *pb_v2;
  cri_u8 u_v3;
  byte b_v4;
  byte b_v5;
  byte b_v6;
  byte b_v7;
  byte b_v8;
  byte b_v9;
  byte b_v10;
  byte b_v11;
  longlong l_v12;
  ulonglong u_v13;
  byte *pb_v14;
  byte *pb_v15;
  longlong l_v16;
  char c_v17;
  char c_v18;
  char c_v19;
  char c_v20;
  char c_v21;
  char c_v22;
  char c_v23;
  char c_v24;
  cri_u1 u_v25;
  cri_u1 u_v26;
  cri_u1 u_v27;
  cri_u1 u_v28;
  cri_u1 u_v29;
  cri_u1 u_v30;
  cri_u1 u_v31;
  cri_u1 u_v32;
  byte b_v33;
  byte b_v34;
  byte b_v35;
  byte b_v36;
  byte b_v37;
  byte b_v38;
  byte b_v39;
  byte b_v40;
  byte b_v41;
  byte b_v42;
  byte b_v43;
  byte b_v44;
  byte b_v45;
  byte b_v46;
  byte b_v47;
  byte b_v48;
  cri_u1 u_v49;
  cri_u1 u_v50;
  cri_u1 u_v51;
  cri_u1 u_v52;
  cri_u1 u_v53;
  cri_u1 u_v54;
  cri_u1 u_v55;
  cri_u1 u_v56;
  byte b_v57;
  byte b_v58;
  byte b_v59;
  byte b_v60;
  byte b_v61;
  byte b_v62;
  byte b_v63;
  byte b_v64;
  cri_u1 u_v65;
  cri_u1 u_v66;
  cri_u1 u_v67;
  cri_u1 u_v68;
  cri_u1 u_v69;
  cri_u1 u_v70;
  cri_u1 u_v71;
  cri_u1 u_v72;
  
  pb_v14 = arg1 + arg3;
  if (arg3 == arg4) {
    b_v34 = *arg1 ^ arg1[1];
    b_v36 = arg1[1] ^ arg1[2];
    b_v38 = arg1[2] ^ arg1[3];
    b_v40 = arg1[3] ^ arg1[4];
    b_v42 = arg1[4] ^ arg1[5];
    b_v44 = arg1[5] ^ arg1[6];
    b_v46 = arg1[6] ^ arg1[7];
    b_v48 = arg1[7] ^ arg1[8];
    b_v57 = pavgb(*arg1,arg1[1]);
    b_v58 = pavgb(arg1[1],arg1[2]);
    b_v59 = pavgb(arg1[2],arg1[3]);
    b_v60 = pavgb(arg1[3],arg1[4]);
    b_v61 = pavgb(arg1[4],arg1[5]);
    b_v62 = pavgb(arg1[5],arg1[6]);
    b_v63 = pavgb(arg1[6],arg1[7]);
    b_v64 = pavgb(arg1[7],arg1[8]);
    u_v65 = pavgb(0,0);
    u_v66 = pavgb(0,0);
    u_v67 = pavgb(0,0);
    u_v68 = pavgb(0,0);
    u_v69 = pavgb(0,0);
    u_v70 = pavgb(0,0);
    u_v71 = pavgb(0,0);
    u_v72 = pavgb(0,0);
    if (0 < (int)arg5) {
      l_v12 = (longlong)arg4;
      u_v13 = (ulonglong)((arg5 - 1 >> 1) + 1);
      do {
        pb_v15 = pb_v14 + l_v12;
        b_v33 = pavgb(*pb_v14,pb_v14[1]);
        b_v35 = pavgb(pb_v14[1],pb_v14[2]);
        b_v37 = pavgb(pb_v14[2],pb_v14[3]);
        b_v39 = pavgb(pb_v14[3],pb_v14[4]);
        b_v41 = pavgb(pb_v14[4],pb_v14[5]);
        b_v43 = pavgb(pb_v14[5],pb_v14[6]);
        b_v45 = pavgb(pb_v14[6],pb_v14[7]);
        b_v47 = pavgb(pb_v14[7],pb_v14[8]);
        u_v49 = pavgb(0,0);
        u_v50 = pavgb(0,0);
        u_v51 = pavgb(0,0);
        u_v52 = pavgb(0,0);
        u_v53 = pavgb(0,0);
        u_v54 = pavgb(0,0);
        u_v55 = pavgb(0,0);
        u_v56 = pavgb(0,0);
        b_v4 = *pb_v14 ^ pb_v14[1];
        b_v5 = pb_v14[1] ^ pb_v14[2];
        b_v6 = pb_v14[2] ^ pb_v14[3];
        b_v7 = pb_v14[3] ^ pb_v14[4];
        b_v8 = pb_v14[4] ^ pb_v14[5];
        b_v9 = pb_v14[5] ^ pb_v14[6];
        b_v10 = pb_v14[6] ^ pb_v14[7];
        b_v11 = pb_v14[7] ^ pb_v14[8];
        u_v3 = *arg2;
        c_v17 = pavgb(b_v33,b_v57);
        c_v18 = pavgb(b_v35,b_v58);
        c_v19 = pavgb(b_v37,b_v59);
        c_v20 = pavgb(b_v39,b_v60);
        c_v21 = pavgb(b_v41,b_v61);
        c_v22 = pavgb(b_v43,b_v62);
        c_v23 = pavgb(b_v45,b_v63);
        c_v24 = pavgb(b_v47,b_v64);
        u_v25 = pavgb(u_v49,u_v65);
        u_v26 = pavgb(u_v50,u_v66);
        u_v27 = pavgb(u_v51,u_v67);
        u_v28 = pavgb(u_v52,u_v68);
        u_v29 = pavgb(u_v53,u_v69);
        u_v30 = pavgb(u_v54,u_v70);
        u_v31 = pavgb(u_v55,u_v71);
        u_v32 = pavgb(u_v56,u_v72);
        u_v65 = pavgb(c_v17 - ((b_v4 | b_v34) & (b_v33 ^ b_v57) & 1),(char)u_v3);
        u_v66 = pavgb(c_v18 - ((b_v5 | b_v36) & (b_v35 ^ b_v58) & 1),
                       (char)((ulonglong)u_v3 >> 8));
        u_v67 = pavgb(c_v19 - ((b_v6 | b_v38) & (b_v37 ^ b_v59) & 1),
                       (char)((ulonglong)u_v3 >> 0x10));
        u_v68 = pavgb(c_v20 - ((b_v7 | b_v40) & (b_v39 ^ b_v60) & 1),
                       (char)((ulonglong)u_v3 >> 0x18));
        u_v69 = pavgb(c_v21 - ((b_v8 | b_v42) & (b_v41 ^ b_v61) & 1),
                       (char)((ulonglong)u_v3 >> 0x20));
        u_v70 = pavgb(c_v22 - ((b_v9 | b_v44) & (b_v43 ^ b_v62) & 1),
                       (char)((ulonglong)u_v3 >> 0x28));
        u_v71 = pavgb(c_v23 - ((b_v10 | b_v46) & (b_v45 ^ b_v63) & 1),
                       (char)((ulonglong)u_v3 >> 0x30));
        u_v72 = pavgb(c_v24 - ((b_v11 | b_v48) & (b_v47 ^ b_v64) & 1),
                       (char)((ulonglong)u_v3 >> 0x38));
        pavgb(u_v25,0);
        pavgb(u_v26,0);
        pavgb(u_v27,0);
        pavgb(u_v28,0);
        pavgb(u_v29,0);
        pavgb(u_v30,0);
        pavgb(u_v31,0);
        pavgb(u_v32,0);
        *arg2 = CONCAT17(u_v72,CONCAT16(u_v71,CONCAT15(u_v70,CONCAT14(u_v69,CONCAT13(u_v68,
                                                  CONCAT12(u_v67,CONCAT11(u_v66,u_v65)))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v12);
        pb_v14 = pb_v15 + l_v12;
        b_v34 = *pb_v15 ^ pb_v15[1];
        b_v36 = pb_v15[1] ^ pb_v15[2];
        b_v38 = pb_v15[2] ^ pb_v15[3];
        b_v40 = pb_v15[3] ^ pb_v15[4];
        b_v42 = pb_v15[4] ^ pb_v15[5];
        b_v44 = pb_v15[5] ^ pb_v15[6];
        b_v46 = pb_v15[6] ^ pb_v15[7];
        b_v48 = pb_v15[7] ^ pb_v15[8];
        b_v57 = pavgb(*pb_v15,pb_v15[1]);
        b_v58 = pavgb(pb_v15[1],pb_v15[2]);
        b_v59 = pavgb(pb_v15[2],pb_v15[3]);
        b_v60 = pavgb(pb_v15[3],pb_v15[4]);
        b_v61 = pavgb(pb_v15[4],pb_v15[5]);
        b_v62 = pavgb(pb_v15[5],pb_v15[6]);
        b_v63 = pavgb(pb_v15[6],pb_v15[7]);
        b_v64 = pavgb(pb_v15[7],pb_v15[8]);
        u_v65 = pavgb(0,0);
        u_v66 = pavgb(0,0);
        u_v67 = pavgb(0,0);
        u_v68 = pavgb(0,0);
        u_v69 = pavgb(0,0);
        u_v70 = pavgb(0,0);
        u_v71 = pavgb(0,0);
        u_v72 = pavgb(0,0);
        u_v3 = *arg2;
        c_v17 = pavgb(b_v57,b_v33);
        c_v18 = pavgb(b_v58,b_v35);
        c_v19 = pavgb(b_v59,b_v37);
        c_v20 = pavgb(b_v60,b_v39);
        c_v21 = pavgb(b_v61,b_v41);
        c_v22 = pavgb(b_v62,b_v43);
        c_v23 = pavgb(b_v63,b_v45);
        c_v24 = pavgb(b_v64,b_v47);
        u_v49 = pavgb(u_v65,u_v49);
        u_v50 = pavgb(u_v66,u_v50);
        u_v51 = pavgb(u_v67,u_v51);
        u_v52 = pavgb(u_v68,u_v52);
        u_v53 = pavgb(u_v69,u_v53);
        u_v54 = pavgb(u_v70,u_v54);
        u_v55 = pavgb(u_v71,u_v55);
        u_v56 = pavgb(u_v72,u_v56);
        u_v25 = pavgb(c_v17 - ((b_v34 | b_v4) & (b_v57 ^ b_v33) & 1),(char)u_v3);
        u_v26 = pavgb(c_v18 - ((b_v36 | b_v5) & (b_v58 ^ b_v35) & 1),
                       (char)((ulonglong)u_v3 >> 8));
        u_v27 = pavgb(c_v19 - ((b_v38 | b_v6) & (b_v59 ^ b_v37) & 1),
                       (char)((ulonglong)u_v3 >> 0x10));
        u_v28 = pavgb(c_v20 - ((b_v40 | b_v7) & (b_v60 ^ b_v39) & 1),
                       (char)((ulonglong)u_v3 >> 0x18));
        u_v29 = pavgb(c_v21 - ((b_v42 | b_v8) & (b_v61 ^ b_v41) & 1),
                       (char)((ulonglong)u_v3 >> 0x20));
        u_v30 = pavgb(c_v22 - ((b_v44 | b_v9) & (b_v62 ^ b_v43) & 1),
                       (char)((ulonglong)u_v3 >> 0x28));
        u_v31 = pavgb(c_v23 - ((b_v46 | b_v10) & (b_v63 ^ b_v45) & 1),
                       (char)((ulonglong)u_v3 >> 0x30));
        u_v32 = pavgb(c_v24 - ((b_v48 | b_v11) & (b_v64 ^ b_v47) & 1),
                       (char)((ulonglong)u_v3 >> 0x38));
        pavgb(u_v49,0);
        pavgb(u_v50,0);
        pavgb(u_v51,0);
        pavgb(u_v52,0);
        pavgb(u_v53,0);
        pavgb(u_v54,0);
        pavgb(u_v55,0);
        pavgb(u_v56,0);
        *arg2 = CONCAT17(u_v32,CONCAT16(u_v31,CONCAT15(u_v30,CONCAT14(u_v29,CONCAT13(u_v28,
                                                  CONCAT12(u_v27,CONCAT11(u_v26,u_v25)))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v12);
        u_v13 = u_v13 - 1;
      } while (u_v13 != 0);
      return;
    }
  }
  else {
    u_v13 = (ulonglong)arg5;
    if (0 < (int)arg5) {
      l_v16 = (longlong)pb_v14 - (longlong)arg2;
      l_v12 = (longlong)arg1 - (longlong)arg2;
      do {
        pb_v1 = (byte *)(l_v16 + 1 + (longlong)arg2);
        pb_v14 = (byte *)(l_v16 + (longlong)arg2);
        pb_v15 = (byte *)(l_v12 + (longlong)arg2);
        pb_v2 = (byte *)(l_v12 + 1 + (longlong)arg2);
        b_v57 = pavgb(*pb_v14,*pb_v1);
        b_v58 = pavgb(pb_v14[1],pb_v1[1]);
        b_v59 = pavgb(pb_v14[2],pb_v1[2]);
        b_v60 = pavgb(pb_v14[3],pb_v1[3]);
        b_v61 = pavgb(pb_v14[4],pb_v1[4]);
        b_v62 = pavgb(pb_v14[5],pb_v1[5]);
        b_v63 = pavgb(pb_v14[6],pb_v1[6]);
        b_v64 = pavgb(pb_v14[7],pb_v1[7]);
        u_v25 = pavgb(0,0);
        u_v26 = pavgb(0,0);
        u_v27 = pavgb(0,0);
        u_v28 = pavgb(0,0);
        u_v29 = pavgb(0,0);
        u_v30 = pavgb(0,0);
        u_v31 = pavgb(0,0);
        u_v32 = pavgb(0,0);
        b_v34 = pavgb(*pb_v15,*pb_v2);
        b_v36 = pavgb(pb_v15[1],pb_v2[1]);
        b_v38 = pavgb(pb_v15[2],pb_v2[2]);
        b_v40 = pavgb(pb_v15[3],pb_v2[3]);
        b_v42 = pavgb(pb_v15[4],pb_v2[4]);
        b_v44 = pavgb(pb_v15[5],pb_v2[5]);
        b_v46 = pavgb(pb_v15[6],pb_v2[6]);
        b_v48 = pavgb(pb_v15[7],pb_v2[7]);
        u_v65 = pavgb(0,0);
        u_v66 = pavgb(0,0);
        u_v67 = pavgb(0,0);
        u_v68 = pavgb(0,0);
        u_v69 = pavgb(0,0);
        u_v70 = pavgb(0,0);
        u_v71 = pavgb(0,0);
        u_v72 = pavgb(0,0);
        c_v17 = pavgb(b_v57,b_v34);
        c_v18 = pavgb(b_v58,b_v36);
        c_v19 = pavgb(b_v59,b_v38);
        c_v20 = pavgb(b_v60,b_v40);
        c_v21 = pavgb(b_v61,b_v42);
        c_v22 = pavgb(b_v62,b_v44);
        c_v23 = pavgb(b_v63,b_v46);
        c_v24 = pavgb(b_v64,b_v48);
        u_v25 = pavgb(u_v25,u_v65);
        u_v26 = pavgb(u_v26,u_v66);
        u_v27 = pavgb(u_v27,u_v67);
        u_v28 = pavgb(u_v28,u_v68);
        u_v29 = pavgb(u_v29,u_v69);
        u_v30 = pavgb(u_v30,u_v70);
        u_v31 = pavgb(u_v31,u_v71);
        u_v32 = pavgb(u_v32,u_v72);
        u_v3 = *arg2;
        u_v65 = pavgb(c_v17 - ((*pb_v14 ^ *pb_v1 | *pb_v15 ^ *pb_v2) & (b_v57 ^ b_v34) & 1),
                       (char)u_v3);
        u_v66 = pavgb(c_v18 - ((pb_v14[1] ^ pb_v1[1] | pb_v15[1] ^ pb_v2[1]) &
                                 (b_v58 ^ b_v36) & 1),(char)((ulonglong)u_v3 >> 8));
        u_v67 = pavgb(c_v19 - ((pb_v14[2] ^ pb_v1[2] | pb_v15[2] ^ pb_v2[2]) &
                                 (b_v59 ^ b_v38) & 1),(char)((ulonglong)u_v3 >> 0x10));
        u_v68 = pavgb(c_v20 - ((pb_v14[3] ^ pb_v1[3] | pb_v15[3] ^ pb_v2[3]) &
                                 (b_v60 ^ b_v40) & 1),(char)((ulonglong)u_v3 >> 0x18));
        u_v69 = pavgb(c_v21 - ((pb_v14[4] ^ pb_v1[4] | pb_v15[4] ^ pb_v2[4]) &
                                 (b_v61 ^ b_v42) & 1),(char)((ulonglong)u_v3 >> 0x20));
        u_v70 = pavgb(c_v22 - ((pb_v14[5] ^ pb_v1[5] | pb_v15[5] ^ pb_v2[5]) &
                                 (b_v62 ^ b_v44) & 1),(char)((ulonglong)u_v3 >> 0x28));
        u_v71 = pavgb(c_v23 - ((pb_v14[6] ^ pb_v1[6] | pb_v15[6] ^ pb_v2[6]) &
                                 (b_v63 ^ b_v46) & 1),(char)((ulonglong)u_v3 >> 0x30));
        u_v72 = pavgb(c_v24 - ((pb_v14[7] ^ pb_v1[7] | pb_v15[7] ^ pb_v2[7]) &
                                 (b_v64 ^ b_v48) & 1),(char)((ulonglong)u_v3 >> 0x38));
        pavgb(u_v25,0);
        pavgb(u_v26,0);
        pavgb(u_v27,0);
        pavgb(u_v28,0);
        pavgb(u_v29,0);
        pavgb(u_v30,0);
        pavgb(u_v31,0);
        pavgb(u_v32,0);
        *arg2 = CONCAT17(u_v72,CONCAT16(u_v71,CONCAT15(u_v70,CONCAT14(u_v69,CONCAT13(u_v68,
                                                  CONCAT12(u_v67,CONCAT11(u_v66,u_v65)))))));
        arg2 = (cri_u8 *)((longlong)arg2 + (longlong)arg4);
        u_v13 = u_v13 - 1;
      } while (u_v13 != 0);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005a1b0
void FUN_14005a1b0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4, ...)
{
  byte *arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  int arg3 = cri_p2;
  int arg4 = cri_p3;
  uint arg5 = cri_p4;
  byte *pb_v1;
  byte *pb_v2;
  byte *pb_v3;
  cri_u8 u_v4;
  byte b_v5;
  byte b_v6;
  byte b_v7;
  byte b_v8;
  byte b_v9;
  byte b_v10;
  byte b_v11;
  byte b_v12;
  ulonglong u_v13;
  cri_u8 *pu_v14;
  byte *pb_v15;
  byte *pb_v16;
  longlong l_v17;
  char c_v18;
  char c_v19;
  char c_v20;
  char c_v21;
  char c_v22;
  char c_v23;
  char c_v24;
  char c_v25;
  cri_u1 u_v26;
  cri_u1 u_v27;
  cri_u1 u_v28;
  cri_u1 u_v29;
  cri_u1 u_v30;
  cri_u1 u_v31;
  cri_u1 u_v32;
  cri_u1 u_v33;
  byte b_v34;
  byte b_v35;
  byte b_v36;
  byte b_v37;
  byte b_v38;
  byte b_v39;
  byte b_v40;
  byte b_v41;
  byte b_v42;
  byte b_v43;
  byte b_v44;
  byte b_v45;
  byte b_v46;
  byte b_v47;
  byte b_v48;
  byte b_v49;
  cri_u1 u_v50;
  cri_u1 u_v51;
  cri_u1 u_v52;
  cri_u1 u_v53;
  cri_u1 u_v54;
  cri_u1 u_v55;
  cri_u1 u_v56;
  cri_u1 u_v57;
  byte b_v58;
  byte b_v59;
  byte b_v60;
  byte b_v61;
  byte b_v62;
  byte b_v63;
  byte b_v64;
  byte b_v65;
  cri_u1 u_v66;
  cri_u1 u_v67;
  cri_u1 u_v68;
  cri_u1 u_v69;
  cri_u1 u_v70;
  cri_u1 u_v71;
  cri_u1 u_v72;
  cri_u1 u_v73;
  
  if (arg3 == arg4) {
    pb_v16 = arg1 + arg3;
    b_v35 = *arg1 ^ arg1[1];
    b_v37 = arg1[1] ^ arg1[2];
    b_v39 = arg1[2] ^ arg1[3];
    b_v41 = arg1[3] ^ arg1[4];
    b_v43 = arg1[4] ^ arg1[5];
    b_v45 = arg1[5] ^ arg1[6];
    b_v47 = arg1[6] ^ arg1[7];
    b_v49 = arg1[7] ^ arg1[8];
    b_v58 = pavgb(*arg1,arg1[1]);
    b_v59 = pavgb(arg1[1],arg1[2]);
    b_v60 = pavgb(arg1[2],arg1[3]);
    b_v61 = pavgb(arg1[3],arg1[4]);
    b_v62 = pavgb(arg1[4],arg1[5]);
    b_v63 = pavgb(arg1[5],arg1[6]);
    b_v64 = pavgb(arg1[6],arg1[7]);
    b_v65 = pavgb(arg1[7],arg1[8]);
    u_v66 = pavgb(0,0);
    u_v67 = pavgb(0,0);
    u_v68 = pavgb(0,0);
    u_v69 = pavgb(0,0);
    u_v70 = pavgb(0,0);
    u_v71 = pavgb(0,0);
    u_v72 = pavgb(0,0);
    u_v73 = pavgb(0,0);
    if (0 < (int)arg5) {
      l_v17 = (longlong)arg4;
      u_v13 = (ulonglong)((arg5 - 1 >> 1) + 1);
      pu_v14 = arg2;
      do {
        pb_v15 = pb_v16 + l_v17;
        b_v34 = pavgb(*pb_v16,pb_v16[1]);
        b_v36 = pavgb(pb_v16[1],pb_v16[2]);
        b_v38 = pavgb(pb_v16[2],pb_v16[3]);
        b_v40 = pavgb(pb_v16[3],pb_v16[4]);
        b_v42 = pavgb(pb_v16[4],pb_v16[5]);
        b_v44 = pavgb(pb_v16[5],pb_v16[6]);
        b_v46 = pavgb(pb_v16[6],pb_v16[7]);
        b_v48 = pavgb(pb_v16[7],pb_v16[8]);
        u_v50 = pavgb(0,0);
        u_v51 = pavgb(0,0);
        u_v52 = pavgb(0,0);
        u_v53 = pavgb(0,0);
        u_v54 = pavgb(0,0);
        u_v55 = pavgb(0,0);
        u_v56 = pavgb(0,0);
        u_v57 = pavgb(0,0);
        b_v5 = *pb_v16 ^ pb_v16[1];
        b_v6 = pb_v16[1] ^ pb_v16[2];
        b_v7 = pb_v16[2] ^ pb_v16[3];
        b_v8 = pb_v16[3] ^ pb_v16[4];
        b_v9 = pb_v16[4] ^ pb_v16[5];
        b_v10 = pb_v16[5] ^ pb_v16[6];
        b_v11 = pb_v16[6] ^ pb_v16[7];
        b_v12 = pb_v16[7] ^ pb_v16[8];
        u_v4 = *pu_v14;
        c_v18 = pavgb(b_v34,b_v58);
        c_v19 = pavgb(b_v36,b_v59);
        c_v20 = pavgb(b_v38,b_v60);
        c_v21 = pavgb(b_v40,b_v61);
        c_v22 = pavgb(b_v42,b_v62);
        c_v23 = pavgb(b_v44,b_v63);
        c_v24 = pavgb(b_v46,b_v64);
        c_v25 = pavgb(b_v48,b_v65);
        u_v26 = pavgb(u_v50,u_v66);
        u_v27 = pavgb(u_v51,u_v67);
        u_v28 = pavgb(u_v52,u_v68);
        u_v29 = pavgb(u_v53,u_v69);
        u_v30 = pavgb(u_v54,u_v70);
        u_v31 = pavgb(u_v55,u_v71);
        u_v32 = pavgb(u_v56,u_v72);
        u_v33 = pavgb(u_v57,u_v73);
        u_v66 = pavgb(c_v18 - ((b_v5 | b_v35) & (b_v34 ^ b_v58) & 1),(char)u_v4);
        u_v67 = pavgb(c_v19 - ((b_v6 | b_v37) & (b_v36 ^ b_v59) & 1),
                       (char)((ulonglong)u_v4 >> 8));
        u_v68 = pavgb(c_v20 - ((b_v7 | b_v39) & (b_v38 ^ b_v60) & 1),
                       (char)((ulonglong)u_v4 >> 0x10));
        u_v69 = pavgb(c_v21 - ((b_v8 | b_v41) & (b_v40 ^ b_v61) & 1),
                       (char)((ulonglong)u_v4 >> 0x18));
        u_v70 = pavgb(c_v22 - ((b_v9 | b_v43) & (b_v42 ^ b_v62) & 1),
                       (char)((ulonglong)u_v4 >> 0x20));
        u_v71 = pavgb(c_v23 - ((b_v10 | b_v45) & (b_v44 ^ b_v63) & 1),
                       (char)((ulonglong)u_v4 >> 0x28));
        u_v72 = pavgb(c_v24 - ((b_v11 | b_v47) & (b_v46 ^ b_v64) & 1),
                       (char)((ulonglong)u_v4 >> 0x30));
        u_v73 = pavgb(c_v25 - ((b_v12 | b_v49) & (b_v48 ^ b_v65) & 1),
                       (char)((ulonglong)u_v4 >> 0x38));
        pavgb(u_v26,0);
        pavgb(u_v27,0);
        pavgb(u_v28,0);
        pavgb(u_v29,0);
        pavgb(u_v30,0);
        pavgb(u_v31,0);
        pavgb(u_v32,0);
        pavgb(u_v33,0);
        *pu_v14 = CONCAT17(u_v73,CONCAT16(u_v72,CONCAT15(u_v71,CONCAT14(u_v70,CONCAT13(u_v69,
                                                  CONCAT12(u_v68,CONCAT11(u_v67,u_v66)))))));
        pu_v14 = (cri_u8 *)((longlong)pu_v14 + l_v17);
        pb_v16 = pb_v15 + l_v17;
        b_v35 = *pb_v15 ^ pb_v15[1];
        b_v37 = pb_v15[1] ^ pb_v15[2];
        b_v39 = pb_v15[2] ^ pb_v15[3];
        b_v41 = pb_v15[3] ^ pb_v15[4];
        b_v43 = pb_v15[4] ^ pb_v15[5];
        b_v45 = pb_v15[5] ^ pb_v15[6];
        b_v47 = pb_v15[6] ^ pb_v15[7];
        b_v49 = pb_v15[7] ^ pb_v15[8];
        b_v58 = pavgb(*pb_v15,pb_v15[1]);
        b_v59 = pavgb(pb_v15[1],pb_v15[2]);
        b_v60 = pavgb(pb_v15[2],pb_v15[3]);
        b_v61 = pavgb(pb_v15[3],pb_v15[4]);
        b_v62 = pavgb(pb_v15[4],pb_v15[5]);
        b_v63 = pavgb(pb_v15[5],pb_v15[6]);
        b_v64 = pavgb(pb_v15[6],pb_v15[7]);
        b_v65 = pavgb(pb_v15[7],pb_v15[8]);
        u_v66 = pavgb(0,0);
        u_v67 = pavgb(0,0);
        u_v68 = pavgb(0,0);
        u_v69 = pavgb(0,0);
        u_v70 = pavgb(0,0);
        u_v71 = pavgb(0,0);
        u_v72 = pavgb(0,0);
        u_v73 = pavgb(0,0);
        u_v4 = *pu_v14;
        c_v18 = pavgb(b_v58,b_v34);
        c_v19 = pavgb(b_v59,b_v36);
        c_v20 = pavgb(b_v60,b_v38);
        c_v21 = pavgb(b_v61,b_v40);
        c_v22 = pavgb(b_v62,b_v42);
        c_v23 = pavgb(b_v63,b_v44);
        c_v24 = pavgb(b_v64,b_v46);
        c_v25 = pavgb(b_v65,b_v48);
        u_v50 = pavgb(u_v66,u_v50);
        u_v51 = pavgb(u_v67,u_v51);
        u_v52 = pavgb(u_v68,u_v52);
        u_v53 = pavgb(u_v69,u_v53);
        u_v54 = pavgb(u_v70,u_v54);
        u_v55 = pavgb(u_v71,u_v55);
        u_v56 = pavgb(u_v72,u_v56);
        u_v57 = pavgb(u_v73,u_v57);
        u_v26 = pavgb(c_v18 - ((b_v35 | b_v5) & (b_v58 ^ b_v34) & 1),(char)u_v4);
        u_v27 = pavgb(c_v19 - ((b_v37 | b_v6) & (b_v59 ^ b_v36) & 1),
                       (char)((ulonglong)u_v4 >> 8));
        u_v28 = pavgb(c_v20 - ((b_v39 | b_v7) & (b_v60 ^ b_v38) & 1),
                       (char)((ulonglong)u_v4 >> 0x10));
        u_v29 = pavgb(c_v21 - ((b_v41 | b_v8) & (b_v61 ^ b_v40) & 1),
                       (char)((ulonglong)u_v4 >> 0x18));
        u_v30 = pavgb(c_v22 - ((b_v43 | b_v9) & (b_v62 ^ b_v42) & 1),
                       (char)((ulonglong)u_v4 >> 0x20));
        u_v31 = pavgb(c_v23 - ((b_v45 | b_v10) & (b_v63 ^ b_v44) & 1),
                       (char)((ulonglong)u_v4 >> 0x28));
        u_v32 = pavgb(c_v24 - ((b_v47 | b_v11) & (b_v64 ^ b_v46) & 1),
                       (char)((ulonglong)u_v4 >> 0x30));
        u_v33 = pavgb(c_v25 - ((b_v49 | b_v12) & (b_v65 ^ b_v48) & 1),
                       (char)((ulonglong)u_v4 >> 0x38));
        pavgb(u_v50,0);
        pavgb(u_v51,0);
        pavgb(u_v52,0);
        pavgb(u_v53,0);
        pavgb(u_v54,0);
        pavgb(u_v55,0);
        pavgb(u_v56,0);
        pavgb(u_v57,0);
        *pu_v14 = CONCAT17(u_v33,CONCAT16(u_v32,CONCAT15(u_v31,CONCAT14(u_v30,CONCAT13(u_v29,
                                                  CONCAT12(u_v28,CONCAT11(u_v27,u_v26)))))));
        pu_v14 = (cri_u8 *)((longlong)pu_v14 + l_v17);
        u_v13 = u_v13 - 1;
      } while (u_v13 != 0);
    }
    pb_v16 = arg1 + (longlong)arg3 + 8;
    arg2 = arg2 + 1;
    b_v35 = arg1[8] ^ arg1[9];
    b_v37 = arg1[9] ^ arg1[10];
    b_v39 = arg1[10] ^ arg1[0xb];
    b_v41 = arg1[0xb] ^ arg1[0xc];
    b_v43 = arg1[0xc] ^ arg1[0xd];
    b_v45 = arg1[0xd] ^ arg1[0xe];
    b_v47 = arg1[0xe] ^ arg1[0xf];
    b_v49 = arg1[0xf] ^ arg1[0x10];
    b_v58 = pavgb(arg1[8],arg1[9]);
    b_v59 = pavgb(arg1[9],arg1[10]);
    b_v60 = pavgb(arg1[10],arg1[0xb]);
    b_v61 = pavgb(arg1[0xb],arg1[0xc]);
    b_v62 = pavgb(arg1[0xc],arg1[0xd]);
    b_v63 = pavgb(arg1[0xd],arg1[0xe]);
    b_v64 = pavgb(arg1[0xe],arg1[0xf]);
    b_v65 = pavgb(arg1[0xf],arg1[0x10]);
    u_v66 = pavgb(0,0);
    u_v67 = pavgb(0,0);
    u_v68 = pavgb(0,0);
    u_v69 = pavgb(0,0);
    u_v70 = pavgb(0,0);
    u_v71 = pavgb(0,0);
    u_v72 = pavgb(0,0);
    u_v73 = pavgb(0,0);
    if (0 < (int)arg5) {
      l_v17 = (longlong)arg4;
      u_v13 = (ulonglong)((arg5 - 1 >> 1) + 1);
      do {
        pb_v15 = pb_v16 + l_v17;
        b_v34 = pavgb(*pb_v16,pb_v16[1]);
        b_v36 = pavgb(pb_v16[1],pb_v16[2]);
        b_v38 = pavgb(pb_v16[2],pb_v16[3]);
        b_v40 = pavgb(pb_v16[3],pb_v16[4]);
        b_v42 = pavgb(pb_v16[4],pb_v16[5]);
        b_v44 = pavgb(pb_v16[5],pb_v16[6]);
        b_v46 = pavgb(pb_v16[6],pb_v16[7]);
        b_v48 = pavgb(pb_v16[7],pb_v16[8]);
        u_v50 = pavgb(0,0);
        u_v51 = pavgb(0,0);
        u_v52 = pavgb(0,0);
        u_v53 = pavgb(0,0);
        u_v54 = pavgb(0,0);
        u_v55 = pavgb(0,0);
        u_v56 = pavgb(0,0);
        u_v57 = pavgb(0,0);
        b_v5 = *pb_v16 ^ pb_v16[1];
        b_v6 = pb_v16[1] ^ pb_v16[2];
        b_v7 = pb_v16[2] ^ pb_v16[3];
        b_v8 = pb_v16[3] ^ pb_v16[4];
        b_v9 = pb_v16[4] ^ pb_v16[5];
        b_v10 = pb_v16[5] ^ pb_v16[6];
        b_v11 = pb_v16[6] ^ pb_v16[7];
        b_v12 = pb_v16[7] ^ pb_v16[8];
        u_v4 = *arg2;
        c_v18 = pavgb(b_v34,b_v58);
        c_v19 = pavgb(b_v36,b_v59);
        c_v20 = pavgb(b_v38,b_v60);
        c_v21 = pavgb(b_v40,b_v61);
        c_v22 = pavgb(b_v42,b_v62);
        c_v23 = pavgb(b_v44,b_v63);
        c_v24 = pavgb(b_v46,b_v64);
        c_v25 = pavgb(b_v48,b_v65);
        u_v26 = pavgb(u_v50,u_v66);
        u_v27 = pavgb(u_v51,u_v67);
        u_v28 = pavgb(u_v52,u_v68);
        u_v29 = pavgb(u_v53,u_v69);
        u_v30 = pavgb(u_v54,u_v70);
        u_v31 = pavgb(u_v55,u_v71);
        u_v32 = pavgb(u_v56,u_v72);
        u_v33 = pavgb(u_v57,u_v73);
        u_v66 = pavgb(c_v18 - ((b_v5 | b_v35) & (b_v34 ^ b_v58) & 1),(char)u_v4);
        u_v67 = pavgb(c_v19 - ((b_v6 | b_v37) & (b_v36 ^ b_v59) & 1),
                       (char)((ulonglong)u_v4 >> 8));
        u_v68 = pavgb(c_v20 - ((b_v7 | b_v39) & (b_v38 ^ b_v60) & 1),
                       (char)((ulonglong)u_v4 >> 0x10));
        u_v69 = pavgb(c_v21 - ((b_v8 | b_v41) & (b_v40 ^ b_v61) & 1),
                       (char)((ulonglong)u_v4 >> 0x18));
        u_v70 = pavgb(c_v22 - ((b_v9 | b_v43) & (b_v42 ^ b_v62) & 1),
                       (char)((ulonglong)u_v4 >> 0x20));
        u_v71 = pavgb(c_v23 - ((b_v10 | b_v45) & (b_v44 ^ b_v63) & 1),
                       (char)((ulonglong)u_v4 >> 0x28));
        u_v72 = pavgb(c_v24 - ((b_v11 | b_v47) & (b_v46 ^ b_v64) & 1),
                       (char)((ulonglong)u_v4 >> 0x30));
        u_v73 = pavgb(c_v25 - ((b_v12 | b_v49) & (b_v48 ^ b_v65) & 1),
                       (char)((ulonglong)u_v4 >> 0x38));
        pavgb(u_v26,0);
        pavgb(u_v27,0);
        pavgb(u_v28,0);
        pavgb(u_v29,0);
        pavgb(u_v30,0);
        pavgb(u_v31,0);
        pavgb(u_v32,0);
        pavgb(u_v33,0);
        *arg2 = CONCAT17(u_v73,CONCAT16(u_v72,CONCAT15(u_v71,CONCAT14(u_v70,CONCAT13(u_v69,
                                                  CONCAT12(u_v68,CONCAT11(u_v67,u_v66)))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v17);
        pb_v16 = pb_v15 + l_v17;
        b_v35 = *pb_v15 ^ pb_v15[1];
        b_v37 = pb_v15[1] ^ pb_v15[2];
        b_v39 = pb_v15[2] ^ pb_v15[3];
        b_v41 = pb_v15[3] ^ pb_v15[4];
        b_v43 = pb_v15[4] ^ pb_v15[5];
        b_v45 = pb_v15[5] ^ pb_v15[6];
        b_v47 = pb_v15[6] ^ pb_v15[7];
        b_v49 = pb_v15[7] ^ pb_v15[8];
        b_v58 = pavgb(*pb_v15,pb_v15[1]);
        b_v59 = pavgb(pb_v15[1],pb_v15[2]);
        b_v60 = pavgb(pb_v15[2],pb_v15[3]);
        b_v61 = pavgb(pb_v15[3],pb_v15[4]);
        b_v62 = pavgb(pb_v15[4],pb_v15[5]);
        b_v63 = pavgb(pb_v15[5],pb_v15[6]);
        b_v64 = pavgb(pb_v15[6],pb_v15[7]);
        b_v65 = pavgb(pb_v15[7],pb_v15[8]);
        u_v66 = pavgb(0,0);
        u_v67 = pavgb(0,0);
        u_v68 = pavgb(0,0);
        u_v69 = pavgb(0,0);
        u_v70 = pavgb(0,0);
        u_v71 = pavgb(0,0);
        u_v72 = pavgb(0,0);
        u_v73 = pavgb(0,0);
        u_v4 = *arg2;
        c_v18 = pavgb(b_v58,b_v34);
        c_v19 = pavgb(b_v59,b_v36);
        c_v20 = pavgb(b_v60,b_v38);
        c_v21 = pavgb(b_v61,b_v40);
        c_v22 = pavgb(b_v62,b_v42);
        c_v23 = pavgb(b_v63,b_v44);
        c_v24 = pavgb(b_v64,b_v46);
        c_v25 = pavgb(b_v65,b_v48);
        u_v50 = pavgb(u_v66,u_v50);
        u_v51 = pavgb(u_v67,u_v51);
        u_v52 = pavgb(u_v68,u_v52);
        u_v53 = pavgb(u_v69,u_v53);
        u_v54 = pavgb(u_v70,u_v54);
        u_v55 = pavgb(u_v71,u_v55);
        u_v56 = pavgb(u_v72,u_v56);
        u_v57 = pavgb(u_v73,u_v57);
        u_v26 = pavgb(c_v18 - ((b_v35 | b_v5) & (b_v58 ^ b_v34) & 1),(char)u_v4);
        u_v27 = pavgb(c_v19 - ((b_v37 | b_v6) & (b_v59 ^ b_v36) & 1),
                       (char)((ulonglong)u_v4 >> 8));
        u_v28 = pavgb(c_v20 - ((b_v39 | b_v7) & (b_v60 ^ b_v38) & 1),
                       (char)((ulonglong)u_v4 >> 0x10));
        u_v29 = pavgb(c_v21 - ((b_v41 | b_v8) & (b_v61 ^ b_v40) & 1),
                       (char)((ulonglong)u_v4 >> 0x18));
        u_v30 = pavgb(c_v22 - ((b_v43 | b_v9) & (b_v62 ^ b_v42) & 1),
                       (char)((ulonglong)u_v4 >> 0x20));
        u_v31 = pavgb(c_v23 - ((b_v45 | b_v10) & (b_v63 ^ b_v44) & 1),
                       (char)((ulonglong)u_v4 >> 0x28));
        u_v32 = pavgb(c_v24 - ((b_v47 | b_v11) & (b_v64 ^ b_v46) & 1),
                       (char)((ulonglong)u_v4 >> 0x30));
        u_v33 = pavgb(c_v25 - ((b_v49 | b_v12) & (b_v65 ^ b_v48) & 1),
                       (char)((ulonglong)u_v4 >> 0x38));
        pavgb(u_v50,0);
        pavgb(u_v51,0);
        pavgb(u_v52,0);
        pavgb(u_v53,0);
        pavgb(u_v54,0);
        pavgb(u_v55,0);
        pavgb(u_v56,0);
        pavgb(u_v57,0);
        *arg2 = CONCAT17(u_v33,CONCAT16(u_v32,CONCAT15(u_v31,CONCAT14(u_v30,CONCAT13(u_v29,
                                                  CONCAT12(u_v28,CONCAT11(u_v27,u_v26)))))));
        arg2 = (cri_u8 *)((longlong)arg2 + l_v17);
        u_v13 = u_v13 - 1;
      } while (u_v13 != 0);
      return;
    }
  }
  else {
    u_v13 = (ulonglong)arg5;
    if (0 < (int)arg5) {
      pb_v16 = arg1 + ((longlong)arg3 - (longlong)arg2);
      l_v17 = (longlong)arg1 - (longlong)arg2;
      do {
        pb_v2 = pb_v16 + 1 + (longlong)arg2;
        pb_v3 = (byte *)(l_v17 + 1 + (longlong)arg2);
        pb_v15 = pb_v16 + (longlong)arg2;
        pb_v1 = (byte *)(l_v17 + (longlong)arg2);
        b_v58 = pavgb(*pb_v15,*pb_v2);
        b_v59 = pavgb(pb_v15[1],pb_v2[1]);
        b_v60 = pavgb(pb_v15[2],pb_v2[2]);
        b_v61 = pavgb(pb_v15[3],pb_v2[3]);
        b_v62 = pavgb(pb_v15[4],pb_v2[4]);
        b_v63 = pavgb(pb_v15[5],pb_v2[5]);
        b_v64 = pavgb(pb_v15[6],pb_v2[6]);
        b_v65 = pavgb(pb_v15[7],pb_v2[7]);
        u_v26 = pavgb(0,0);
        u_v27 = pavgb(0,0);
        u_v28 = pavgb(0,0);
        u_v29 = pavgb(0,0);
        u_v30 = pavgb(0,0);
        u_v31 = pavgb(0,0);
        u_v32 = pavgb(0,0);
        u_v33 = pavgb(0,0);
        b_v35 = pavgb(*pb_v1,*pb_v3);
        b_v37 = pavgb(pb_v1[1],pb_v3[1]);
        b_v39 = pavgb(pb_v1[2],pb_v3[2]);
        b_v41 = pavgb(pb_v1[3],pb_v3[3]);
        b_v43 = pavgb(pb_v1[4],pb_v3[4]);
        b_v45 = pavgb(pb_v1[5],pb_v3[5]);
        b_v47 = pavgb(pb_v1[6],pb_v3[6]);
        b_v49 = pavgb(pb_v1[7],pb_v3[7]);
        u_v66 = pavgb(0,0);
        u_v67 = pavgb(0,0);
        u_v68 = pavgb(0,0);
        u_v69 = pavgb(0,0);
        u_v70 = pavgb(0,0);
        u_v71 = pavgb(0,0);
        u_v72 = pavgb(0,0);
        u_v73 = pavgb(0,0);
        c_v18 = pavgb(b_v58,b_v35);
        c_v19 = pavgb(b_v59,b_v37);
        c_v20 = pavgb(b_v60,b_v39);
        c_v21 = pavgb(b_v61,b_v41);
        c_v22 = pavgb(b_v62,b_v43);
        c_v23 = pavgb(b_v63,b_v45);
        c_v24 = pavgb(b_v64,b_v47);
        c_v25 = pavgb(b_v65,b_v49);
        u_v26 = pavgb(u_v26,u_v66);
        u_v27 = pavgb(u_v27,u_v67);
        u_v28 = pavgb(u_v28,u_v68);
        u_v29 = pavgb(u_v29,u_v69);
        u_v30 = pavgb(u_v30,u_v70);
        u_v31 = pavgb(u_v31,u_v71);
        u_v32 = pavgb(u_v32,u_v72);
        u_v33 = pavgb(u_v33,u_v73);
        u_v4 = *arg2;
        u_v66 = pavgb(c_v18 - ((*pb_v15 ^ *pb_v2 | *pb_v1 ^ *pb_v3) & (b_v58 ^ b_v35) & 1),
                       (char)u_v4);
        u_v67 = pavgb(c_v19 - ((pb_v15[1] ^ pb_v2[1] | pb_v1[1] ^ pb_v3[1]) &
                                 (b_v59 ^ b_v37) & 1),(char)((ulonglong)u_v4 >> 8));
        u_v68 = pavgb(c_v20 - ((pb_v15[2] ^ pb_v2[2] | pb_v1[2] ^ pb_v3[2]) &
                                 (b_v60 ^ b_v39) & 1),(char)((ulonglong)u_v4 >> 0x10));
        u_v69 = pavgb(c_v21 - ((pb_v15[3] ^ pb_v2[3] | pb_v1[3] ^ pb_v3[3]) &
                                 (b_v61 ^ b_v41) & 1),(char)((ulonglong)u_v4 >> 0x18));
        u_v70 = pavgb(c_v22 - ((pb_v15[4] ^ pb_v2[4] | pb_v1[4] ^ pb_v3[4]) &
                                 (b_v62 ^ b_v43) & 1),(char)((ulonglong)u_v4 >> 0x20));
        u_v71 = pavgb(c_v23 - ((pb_v15[5] ^ pb_v2[5] | pb_v1[5] ^ pb_v3[5]) &
                                 (b_v63 ^ b_v45) & 1),(char)((ulonglong)u_v4 >> 0x28));
        u_v72 = pavgb(c_v24 - ((pb_v15[6] ^ pb_v2[6] | pb_v1[6] ^ pb_v3[6]) &
                                 (b_v64 ^ b_v47) & 1),(char)((ulonglong)u_v4 >> 0x30));
        u_v73 = pavgb(c_v25 - ((pb_v15[7] ^ pb_v2[7] | pb_v1[7] ^ pb_v3[7]) &
                                 (b_v65 ^ b_v49) & 1),(char)((ulonglong)u_v4 >> 0x38));
        pavgb(u_v26,0);
        pavgb(u_v27,0);
        pavgb(u_v28,0);
        pavgb(u_v29,0);
        pavgb(u_v30,0);
        pavgb(u_v31,0);
        pavgb(u_v32,0);
        pavgb(u_v33,0);
        *arg2 = CONCAT17(u_v73,CONCAT16(u_v72,CONCAT15(u_v71,CONCAT14(u_v70,CONCAT13(u_v69,
                                                  CONCAT12(u_v68,CONCAT11(u_v67,u_v66)))))));
        pb_v15 = pb_v16 + 9 + (longlong)arg2;
        pb_v1 = pb_v16 + 8 + (longlong)arg2;
        pb_v2 = (byte *)(l_v17 + 8 + (longlong)arg2);
        pb_v3 = (byte *)(l_v17 + 9 + (longlong)arg2);
        b_v58 = pavgb(*pb_v1,*pb_v15);
        b_v59 = pavgb(pb_v1[1],pb_v15[1]);
        b_v60 = pavgb(pb_v1[2],pb_v15[2]);
        b_v61 = pavgb(pb_v1[3],pb_v15[3]);
        b_v62 = pavgb(pb_v1[4],pb_v15[4]);
        b_v63 = pavgb(pb_v1[5],pb_v15[5]);
        b_v64 = pavgb(pb_v1[6],pb_v15[6]);
        b_v65 = pavgb(pb_v1[7],pb_v15[7]);
        u_v26 = pavgb(0,0);
        u_v27 = pavgb(0,0);
        u_v28 = pavgb(0,0);
        u_v29 = pavgb(0,0);
        u_v30 = pavgb(0,0);
        u_v31 = pavgb(0,0);
        u_v32 = pavgb(0,0);
        u_v33 = pavgb(0,0);
        b_v35 = pavgb(*pb_v2,*pb_v3);
        b_v37 = pavgb(pb_v2[1],pb_v3[1]);
        b_v39 = pavgb(pb_v2[2],pb_v3[2]);
        b_v41 = pavgb(pb_v2[3],pb_v3[3]);
        b_v43 = pavgb(pb_v2[4],pb_v3[4]);
        b_v45 = pavgb(pb_v2[5],pb_v3[5]);
        b_v47 = pavgb(pb_v2[6],pb_v3[6]);
        b_v49 = pavgb(pb_v2[7],pb_v3[7]);
        u_v66 = pavgb(0,0);
        u_v67 = pavgb(0,0);
        u_v68 = pavgb(0,0);
        u_v69 = pavgb(0,0);
        u_v70 = pavgb(0,0);
        u_v71 = pavgb(0,0);
        u_v72 = pavgb(0,0);
        u_v73 = pavgb(0,0);
        c_v18 = pavgb(b_v58,b_v35);
        c_v19 = pavgb(b_v59,b_v37);
        c_v20 = pavgb(b_v60,b_v39);
        c_v21 = pavgb(b_v61,b_v41);
        c_v22 = pavgb(b_v62,b_v43);
        c_v23 = pavgb(b_v63,b_v45);
        c_v24 = pavgb(b_v64,b_v47);
        c_v25 = pavgb(b_v65,b_v49);
        u_v26 = pavgb(u_v26,u_v66);
        u_v27 = pavgb(u_v27,u_v67);
        u_v28 = pavgb(u_v28,u_v68);
        u_v29 = pavgb(u_v29,u_v69);
        u_v30 = pavgb(u_v30,u_v70);
        u_v31 = pavgb(u_v31,u_v71);
        u_v32 = pavgb(u_v32,u_v72);
        u_v33 = pavgb(u_v33,u_v73);
        u_v4 = arg2[1];
        u_v66 = pavgb(c_v18 - ((*pb_v1 ^ *pb_v15 | *pb_v2 ^ *pb_v3) & (b_v58 ^ b_v35) & 1),
                       (char)u_v4);
        u_v67 = pavgb(c_v19 - ((pb_v1[1] ^ pb_v15[1] | pb_v2[1] ^ pb_v3[1]) &
                                 (b_v59 ^ b_v37) & 1),(char)((ulonglong)u_v4 >> 8));
        u_v68 = pavgb(c_v20 - ((pb_v1[2] ^ pb_v15[2] | pb_v2[2] ^ pb_v3[2]) &
                                 (b_v60 ^ b_v39) & 1),(char)((ulonglong)u_v4 >> 0x10));
        u_v69 = pavgb(c_v21 - ((pb_v1[3] ^ pb_v15[3] | pb_v2[3] ^ pb_v3[3]) &
                                 (b_v61 ^ b_v41) & 1),(char)((ulonglong)u_v4 >> 0x18));
        u_v70 = pavgb(c_v22 - ((pb_v1[4] ^ pb_v15[4] | pb_v2[4] ^ pb_v3[4]) &
                                 (b_v62 ^ b_v43) & 1),(char)((ulonglong)u_v4 >> 0x20));
        u_v71 = pavgb(c_v23 - ((pb_v1[5] ^ pb_v15[5] | pb_v2[5] ^ pb_v3[5]) &
                                 (b_v63 ^ b_v45) & 1),(char)((ulonglong)u_v4 >> 0x28));
        u_v72 = pavgb(c_v24 - ((pb_v1[6] ^ pb_v15[6] | pb_v2[6] ^ pb_v3[6]) &
                                 (b_v64 ^ b_v47) & 1),(char)((ulonglong)u_v4 >> 0x30));
        u_v73 = pavgb(c_v25 - ((pb_v1[7] ^ pb_v15[7] | pb_v2[7] ^ pb_v3[7]) &
                                 (b_v65 ^ b_v49) & 1),(char)((ulonglong)u_v4 >> 0x38));
        pavgb(u_v26,0);
        pavgb(u_v27,0);
        pavgb(u_v28,0);
        pavgb(u_v29,0);
        pavgb(u_v30,0);
        pavgb(u_v31,0);
        pavgb(u_v32,0);
        pavgb(u_v33,0);
        arg2[1] = CONCAT17(u_v73,CONCAT16(u_v72,CONCAT15(u_v71,CONCAT14(u_v70,CONCAT13(u_v69
                                                  ,CONCAT12(u_v68,CONCAT11(u_v67,u_v66)))))));
        arg2 = (cri_u8 *)((longlong)arg2 + (longlong)arg4);
        u_v13 = u_v13 - 1;
      } while (u_v13 != 0);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005a4b0
void FUN_14005a4b0(cri_any cri_unused, ...)
{
  ushort u_v1;
  cri_u1 *pu_v2;
  longlong l_v3;
  longlong l_v4;
  int i_v5;
  ushort *pu_v6;
  ushort *pu_v7;
  
  pu_v2 = CRI_ADDR(DAT_143ee68c1);
  l_v3 = 0x800;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x24;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bac00);
  l_v3 = 0x23;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x800L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143ee68c0 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005a530
void FUN_14005a530(cri_any cri_unused, ...)
{
  ushort u_v1;
  cri_u1 *pu_v2;
  longlong l_v3;
  longlong l_v4;
  int i_v5;
  ushort *pu_v6;
  ushort *pu_v7;
  longlong l_v8;
  
  pu_v2 = CRI_ADDR(DAT_143fe8241);
  l_v3 = 4;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  l_v8 = 2;
  pu_v7 = CRI_ADDR(DAT_1431bac90);
  l_v3 = 2;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(4L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143fe8240 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v2 = CRI_ADDR(DAT_143e66841);
  l_v3 = 0x40;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bac98);
  l_v3 = 7;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x40L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143e66840 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v2 = CRI_ADDR(DAT_143f680c1);
  l_v3 = 0x40;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bacb8);
  l_v3 = 0xb;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x40L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143f680c0 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v2 = CRI_ADDR(DAT_143e65801);
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v8 = l_v8 + -1;
  } while (l_v8 != 0);
  l_v8 = 0x10;
  _DAT_143e65802 = 0x401;
  pu_v2 = CRI_ADDR(DAT_143e64be1);
  l_v3 = 0x10;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bace8);
  l_v3 = 5;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x10L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143e64be0 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v2 = CRI_ADDR(DAT_143f68141);
  l_v3 = 0x80;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bad00);
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x80L >> ((byte)u_v1 & 0x3f));
    l_v3 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143f68140 + (ulonglong)*pu_v7 * 2);
      for (; l_v3 != 0; l_v3 = l_v3 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v8 = l_v8 + -1;
  } while (l_v8 != 0);
  pu_v2 = CRI_ADDR(DAT_143f67cc1);
  l_v3 = 0x200;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bad40);
  l_v3 = 0x14;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x200L >> ((byte)u_v1 & 0x3f));
    l_v8 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143f67cc0 + (ulonglong)*pu_v7 * 2);
      for (; l_v8 != 0; l_v8 = l_v8 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v2 = CRI_ADDR(DAT_143e66831);
  l_v3 = 8;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x7f;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bad90);
  l_v3 = 3;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(8L >> ((byte)u_v1 & 0x3f));
    l_v8 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143e66830 + (ulonglong)*pu_v7 * 2);
      for (; l_v8 != 0; l_v8 = l_v8 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005a820
void FUN_14005a820(cri_any cri_unused, ...)
{
  ushort u_v1;
  cri_u1 *pu_v2;
  longlong l_v3;
  longlong l_v4;
  int i_v5;
  ushort *pu_v6;
  ushort *pu_v7;
  
  pu_v2 = CRI_ADDR(DAT_143e65821);
  l_v3 = 0x800;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x80;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bada0);
  l_v3 = 0x21;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x800L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143e65820 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v2 = CRI_ADDR(DAT_143e66821);
  l_v3 = 4;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x80;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bae28);
  l_v3 = 3;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(4L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143e66820 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005a900
void FUN_14005a900(cri_any cri_unused, ...)
{
  ushort u_v1;
  cri_u1 *pu_v2;
  longlong l_v3;
  longlong l_v4;
  int i_v5;
  ushort *pu_v6;
  ushort *pu_v7;
  
  pu_v2 = CRI_ADDR(DAT_143e65401);
  l_v3 = 0x200;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x80;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431bae40);
  l_v3 = 0x40;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x200L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143e65400 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005a980
void FUN_14005a980(cri_any cri_unused, ...)
{
  ushort u_v1;
  cri_u1 *pu_v2;
  longlong l_v3;
  longlong l_v4;
  int i_v5;
  ushort *pu_v6;
  ushort *pu_v7;
  longlong l_v8;
  
  pu_v2 = CRI_ADDR(DAT_143ee78c1);
  l_v3 = 0x200;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x80;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  l_v8 = 0xc;
  pu_v7 = CRI_ADDR(DAT_1431baf40);
  l_v3 = 0xc;
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x200L >> ((byte)u_v1 & 0x3f));
    l_v4 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143ee78c0 + (ulonglong)*pu_v7 * 2);
      for (; l_v4 != 0; l_v4 = l_v4 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v2 = CRI_ADDR(DAT_143e64c01);
  l_v3 = 0x400;
  do {
    pu_v2[-1] = 0;
    *pu_v2 = 0x80;
    pu_v2 = pu_v2 + 2;
    l_v3 = l_v3 + -1;
  } while (l_v3 != 0);
  pu_v7 = CRI_ADDR(DAT_1431baf70);
  do {
    u_v1 = pu_v7[1];
    i_v5 = (int)(0x400L >> ((byte)u_v1 & 0x3f));
    l_v3 = (longlong)i_v5;
    if (0 < i_v5) {
      pu_v6 = (ushort *)(&DAT_143e64c00 + (ulonglong)*pu_v7 * 2);
      for (; l_v3 != 0; l_v3 = l_v3 + -1) {
        *pu_v6 = u_v1;
        pu_v6 = pu_v6 + 1;
      }
    }
    pu_v7 = pu_v7 + 2;
    l_v8 = l_v8 + -1;
  } while (l_v8 != 0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005aa60
void FUN_14005aa60(cri_any cri_unused, ...)
{
  uint u_v1;
  uint u_v2;
  cri_u1 *pu_v3;
  longlong l_v4;
  longlong l_v5;
  longlong l_v6;
  ulonglong u_v7;
  uint u_v8;
  uint *pu_v9;
  uint *pu_v10;
  uint u_v11;
  longlong l_v12;
  uint u_v13;
  longlong l_v14;
  cri_u4 local_res8;
  
  pu_v3 = CRI_ADDR(DAT_143ee7cc1);
  l_v4 = 0x20000;
  do {
    pu_v3[-1] = 0;
    *pu_v3 = 0x80;
    pu_v3[1] = 0x80;
    pu_v3[2] = 0;
    pu_v3 = pu_v3 + 4;
    l_v4 = l_v4 + -1;
  } while (l_v4 != 0);
  pu_v9 = CRI_ADDR(DAT_1431bafa0);
  l_v4 = 0x70;
  do {
    u_v1 = pu_v9[1];
    u_v2 = *pu_v9;
    l_v14 = (longlong)(int)u_v2;
    CRI_IPART(local_res8,0,1) = (byte)u_v1;
    u_v13 = (uint)(0x20000L >> ((byte)local_res8 & 0x3f));
    l_v12 = (longlong)(int)u_v13;
    if (0 < (int)u_v13) {
      pu_v10 = (uint *)(&DAT_143ee7cc0 + l_v14 * 4);
      for (l_v5 = l_v12; l_v5 != 0; l_v5 = l_v5 + -1) {
        *pu_v10 = u_v1;
        pu_v10 = pu_v10 + 1;
      }
    }
    CRI_IPART(local_res8,2,1) = (char)(u_v1 >> 0x10);
    if (CRI_IPART(local_res8,2,1) == '\0') {
joined_r0x00014005ab78:
      if (0 < (int)u_v13) {
        pu_v10 = (uint *)(&DAT_143ee7cc0 + l_v14 * 4);
        for (; l_v12 != 0; l_v12 = l_v12 + -1) {
          *pu_v10 = u_v1;
          pu_v10 = pu_v10 + 1;
        }
      }
    }
    else {
      if (CRI_IPART(local_res8,2,1) != -0x7f) {
        if (0 < (int)u_v13) {
          pu_v10 = (uint *)(&DAT_143ee7cc0 + l_v14 * 4);
          for (l_v5 = l_v12; l_v5 != 0; l_v5 = l_v5 + -1) {
            *pu_v10 = u_v1;
            pu_v10 = pu_v10 + 1;
          }
        }
        CRI_IPART(local_res8,3,1) = (cri_u1)(u_v1 >> 0x18);
        CRI_IPART(local_res8,0,2) = (cri_u2)u_v1;
        CRI_IPART(local_res8,0,3) = CONCAT12(-CRI_IPART(local_res8,2,1),(cri_u2)local_res8);
        l_v14 = (longlong)(int)(u_v2 | u_v13);
        u_v1 = local_res8;
        goto joined_r0x00014005ab78;
      }
      u_v8 = 0;
      u_v11 = 0;
      local_res8 = u_v1;
      do {
        CRI_IPART(local_res8,0,2) = CONCAT11((char)u_v8,(byte)local_res8);
        if (0 < (int)u_v13 >> 6) {
          pu_v10 = (uint *)(&DAT_143ee7cc0 + (longlong)(int)(u_v11 >> 6 | u_v2) * 4);
          for (u_v7 = (ulonglong)(uint)((int)u_v13 >> 6); u_v7 != 0; u_v7 = u_v7 - 1) {
            *pu_v10 = local_res8;
            pu_v10 = pu_v10 + 1;
          }
        }
        u_v8 = u_v8 + 1;
        u_v11 = u_v11 + u_v13;
      } while (u_v8 < 0x40);
    }
    pu_v9 = pu_v9 + 2;
    l_v4 = l_v4 + -1;
  } while (l_v4 != 0);
  pu_v3 = CRI_ADDR(DAT_143e668c1);
  l_v4 = 0x20000;
  do {
    pu_v3[-1] = 0;
    *pu_v3 = 0x80;
    pu_v3[1] = 0x80;
    pu_v3[2] = 0;
    pu_v3 = pu_v3 + 4;
    l_v4 = l_v4 + -1;
  } while (l_v4 != 0);
  l_v14 = 0x71;
  pu_v9 = CRI_ADDR(DAT_1431bb320);
  l_v4 = 0x71;
  do {
    u_v1 = pu_v9[1];
    u_v2 = *pu_v9;
    l_v12 = (longlong)(int)u_v2;
    CRI_IPART(local_res8,0,1) = (byte)u_v1;
    u_v13 = (uint)(0x20000L >> ((byte)local_res8 & 0x3f));
    l_v5 = (longlong)(int)u_v13;
    if (0 < (int)u_v13) {
      pu_v10 = (uint *)(&DAT_143e668c0 + l_v12 * 4);
      for (l_v6 = l_v5; l_v6 != 0; l_v6 = l_v6 + -1) {
        *pu_v10 = u_v1;
        pu_v10 = pu_v10 + 1;
      }
    }
    CRI_IPART(local_res8,2,1) = (char)(u_v1 >> 0x10);
    if (CRI_IPART(local_res8,2,1) == '\0') {
joined_r0x00014005aca8:
      if (0 < (int)u_v13) {
        pu_v10 = (uint *)(&DAT_143e668c0 + l_v12 * 4);
        for (; l_v5 != 0; l_v5 = l_v5 + -1) {
          *pu_v10 = u_v1;
          pu_v10 = pu_v10 + 1;
        }
      }
    }
    else {
      if (CRI_IPART(local_res8,2,1) != -0x7f) {
        if (0 < (int)u_v13) {
          pu_v10 = (uint *)(&DAT_143e668c0 + l_v12 * 4);
          for (l_v6 = l_v5; l_v6 != 0; l_v6 = l_v6 + -1) {
            *pu_v10 = u_v1;
            pu_v10 = pu_v10 + 1;
          }
        }
        CRI_IPART(local_res8,3,1) = (cri_u1)(u_v1 >> 0x18);
        CRI_IPART(local_res8,0,2) = (cri_u2)u_v1;
        CRI_IPART(local_res8,0,3) = CONCAT12(-CRI_IPART(local_res8,2,1),(cri_u2)local_res8);
        l_v12 = (longlong)(int)(u_v2 | u_v13);
        u_v1 = local_res8;
        goto joined_r0x00014005aca8;
      }
      u_v8 = 0;
      u_v11 = 0;
      local_res8 = u_v1;
      do {
        CRI_IPART(local_res8,0,2) = CONCAT11((char)u_v8,(byte)local_res8);
        if (0 < (int)u_v13 >> 6) {
          pu_v10 = (uint *)(&DAT_143e668c0 + (longlong)(int)(u_v11 >> 6 | u_v2) * 4);
          for (u_v7 = (ulonglong)(uint)((int)u_v13 >> 6); u_v7 != 0; u_v7 = u_v7 - 1) {
            *pu_v10 = local_res8;
            pu_v10 = pu_v10 + 1;
          }
        }
        u_v8 = u_v8 + 1;
        u_v11 = u_v11 + u_v13;
      } while (u_v8 < 0x40);
    }
    pu_v9 = pu_v9 + 2;
    l_v4 = l_v4 + -1;
  } while (l_v4 != 0);
  pu_v3 = CRI_ADDR(DAT_143f68241);
  l_v4 = 0x20000;
  do {
    pu_v3[-1] = 0;
    *pu_v3 = 0x80;
    pu_v3[1] = 0x80;
    pu_v3[2] = 0;
    pu_v3 = pu_v3 + 4;
    l_v4 = l_v4 + -1;
  } while (l_v4 != 0);
  pu_v9 = CRI_ADDR(DAT_1431bb6b0);
  do {
    u_v1 = pu_v9[1];
    u_v2 = *pu_v9;
    l_v4 = (longlong)(int)u_v2;
    CRI_IPART(local_res8,0,1) = (byte)u_v1;
    u_v13 = (uint)(0x20000L >> ((byte)local_res8 & 0x3f));
    l_v12 = (longlong)(int)u_v13;
    if (0 < (int)u_v13) {
      pu_v10 = (uint *)(&DAT_143f68240 + l_v4 * 4);
      for (l_v5 = l_v12; l_v5 != 0; l_v5 = l_v5 + -1) {
        *pu_v10 = u_v1;
        pu_v10 = pu_v10 + 1;
      }
    }
    CRI_IPART(local_res8,2,1) = (char)(u_v1 >> 0x10);
    if (CRI_IPART(local_res8,2,1) == '\0') {
joined_r0x00014005adc8:
      if (0 < (int)u_v13) {
        pu_v10 = (uint *)(&DAT_143f68240 + l_v4 * 4);
        for (; l_v12 != 0; l_v12 = l_v12 + -1) {
          *pu_v10 = u_v1;
          pu_v10 = pu_v10 + 1;
        }
      }
    }
    else {
      if (CRI_IPART(local_res8,2,1) != -0x7f) {
        if (0 < (int)u_v13) {
          pu_v10 = (uint *)(&DAT_143f68240 + l_v4 * 4);
          for (l_v5 = l_v12; l_v5 != 0; l_v5 = l_v5 + -1) {
            *pu_v10 = u_v1;
            pu_v10 = pu_v10 + 1;
          }
        }
        CRI_IPART(local_res8,3,1) = (cri_u1)(u_v1 >> 0x18);
        CRI_IPART(local_res8,0,2) = (cri_u2)u_v1;
        CRI_IPART(local_res8,0,3) = CONCAT12(-CRI_IPART(local_res8,2,1),(cri_u2)local_res8);
        l_v4 = (longlong)(int)(u_v2 | u_v13);
        u_v1 = local_res8;
        goto joined_r0x00014005adc8;
      }
      u_v8 = 0;
      u_v11 = 0;
      local_res8 = u_v1;
      do {
        CRI_IPART(local_res8,0,2) = CONCAT11((char)u_v8,(byte)local_res8);
        if (0 < (int)u_v13 >> 6) {
          pu_v10 = (uint *)(&DAT_143f68240 + (longlong)(int)(u_v11 >> 6 | u_v2) * 4);
          for (u_v7 = (ulonglong)(uint)((int)u_v13 >> 6); u_v7 != 0; u_v7 = u_v7 - 1) {
            *pu_v10 = local_res8;
            pu_v10 = pu_v10 + 1;
          }
        }
        u_v8 = u_v8 + 1;
        u_v11 = u_v11 + u_v13;
      } while (u_v8 < 0x40);
    }
    pu_v9 = pu_v9 + 2;
    l_v14 = l_v14 + -1;
    if (l_v14 == 0) {
      return;
    }
  } while( true );
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005ae00
void FUN_14005ae00(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  int i_v1;
  
  if (*(int *)((char *)arg1 + 0x1a78) != 0) {
    *(cri_code **)((char *)arg1 + 0x1bd0) = (cri_code *)FUN_140083350;
    *(cri_code **)((char *)arg1 + 0x1bd8) = (cri_code *)FUN_14007ba60;
    return;
  }
  *(cri_u8 *)((char *)arg1 + 0x1bd0) = 0;
  i_v1 = FUN_140054210(arg1);  // the exe passes rcx through
  if (i_v1 == 0) {
    i_v1 = FUN_140054230(arg1);
    if (i_v1 != 0) {
      *(cri_code **)((char *)arg1 + 0x1bd0) = (cri_code *)FUN_140073c80;
      *(cri_code **)((char *)arg1 + 0x1bd8) = (cri_code *)FUN_14006b0d0;
      return;
    }
  }
  *(cri_code **)((char *)arg1 + 0x1bd0) = (cri_code *)FUN_140083350;
  *(cri_code **)((char *)arg1 + 0x1bd8) = (cri_code *)FUN_14007ba60;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005aea0
void FUN_14005aea0(cri_any cri_unused, ...)
{
  if (DAT_143c494e8 != 1) {
    DAT_143c494e8 = 1;
    FUN_14005a4b0();
    FUN_14005a530();
    FUN_14005a820();
    FUN_14005a900();
    FUN_14005a980();
    FUN_14005aa60();
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005aee0
void FUN_14005aee0(cri_any cri_p0, ...)
{
  cri_u8 *arg1 = cri_p0;
  *arg1 = 0;
  arg1[1] = 0;
  *(cri_u4 *)(arg1 + 2) = 0;
  *(cri_u4 *)((longlong)arg1 + 0x14) = 0;
  *(cri_u4 *)(arg1 + 3) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005af00
void FUN_14005af00(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 *arg1 = cri_p0;
  int arg2 = cri_p1;
  *(int *)(arg1 + 2) = arg2;
  if ((arg2 != 0) && ((cri_code *)*arg1 != (cri_code *)0x0)) {
    (*(cri_code *)*arg1)(arg1[1]);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005af20
void FUN_14005af20(cri_any cri_unused, ...)
{
  FUN_14005aee0(&DAT_143e64bc0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005af30
cri_u4 FUN_14005af30(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  cri_u4 arg2 = cri_p1;
  if (arg1 == 0) {
    FUN_14005af00(&DAT_143e64bc0,arg2);  // edx = arg2 in the exe
    return arg2;
  }
  FUN_14005af00(arg1 + 0x1a30,arg2);
  return arg2;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005af70
void FUN_14005af70(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  cri_u8 arg2 = cri_p1;
  cri_u8 arg3 = cri_p2;
  int i_v1;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    FUN_14005af30(0,0xff050203);
    return;
  }
  *(cri_u8 *)((char *)arg1 + 0x1a30) = arg2;
  *(cri_u8 *)((char *)arg1 + 0x1a38) = arg3;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005afd0
void FUN_14005afd0(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  int i_v1;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    FUN_14005af30(0,0xff050204);
    return;
  }
  *arg2 = *(cri_u8 *)((char *)arg1 + 0x1a30);
  arg2[1] = *(cri_u8 *)((char *)arg1 + 0x1a38);
  arg2[2] = *(cri_u8 *)((char *)arg1 + 0x1a40);
  arg2[3] = *(cri_u8 *)((char *)arg1 + 0x1a48);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b040
cri_u4 FUN_14005b040(cri_any cri_unused, ...)
{
  return DAT_143e64b88;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b090
void FUN_14005b090(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b80 != (cri_code *)0x0) {
    (*DAT_143e64b80)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b0b0
void FUN_14005b0b0(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b78 != (cri_code *)0x0) {
    (*DAT_143e64b78)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b0d0
// The exe tail-jumps to the hook (jmp rax) with rcx untouched: the hook gets the argument and its rax is the result.
ulonglong FUN_14005b0d0(cri_any cri_p0, ...)
{
  if (DAT_143e64b58 != (cri_code *)0x0) {
    return ((ulonglong (*)(ulonglong))DAT_143e64b58)((ulonglong)(longlong)cri_p0);
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b0f0
void FUN_14005b0f0(cri_any cri_p0, ...)
{
  if (DAT_143e64b50 != (cri_code *)0x0) {
    ((void (*)(ulonglong))DAT_143e64b50)((ulonglong)(longlong)cri_p0);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b110
void FUN_14005b110(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b28 != (cri_code *)0x0) {
    (*DAT_143e64b28)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b130
void FUN_14005b130(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b90 != (cri_code *)0x0) {
    (*DAT_143e64b90)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b150
void FUN_14005b150(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b08 != (cri_code *)0x0) {
    (*DAT_143e64b08)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b170
void FUN_14005b170(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b68 != (cri_code *)0x0) {
    (*DAT_143e64b68)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b190
void FUN_14005b190(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b10 != (cri_code *)0x0) {
    (*DAT_143e64b10)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b1b0
void FUN_14005b1b0(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b00 != (cri_code *)0x0) {
    (*DAT_143e64b00)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b1d0
void FUN_14005b1d0(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b98 != (cri_code *)0x0) {
    (*DAT_143e64b98)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b200
void FUN_14005b200(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b70 != (cri_code *)0x0) {
    (*DAT_143e64b70)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b220
void FUN_14005b220(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b40 != (cri_code *)0x0) {
    (*DAT_143e64b40)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b240
cri_u8 FUN_14005b240(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  cri_u8 u_v1;
  
  if (DAT_143e64b48 != (cri_code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00014005b24c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    u_v1 = (*DAT_143e64b48)((longlong)cri_p0,a2,a3,a4);
    return u_v1;
  }
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b260
void FUN_14005b260(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64ba0 != (cri_code *)0x0) {
    (*DAT_143e64ba0)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b280
void FUN_14005b280(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b18 != (cri_code *)0x0) {
    (*DAT_143e64b18)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b2a0
void FUN_14005b2a0(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64ba8 != (cri_code *)0x0) {
    (*DAT_143e64ba8)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b2c0
void FUN_14005b2c0(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b38 != (cri_code *)0x0) {
    (*DAT_143e64b38)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b2e0
void FUN_14005b2e0(cri_any cri_p0, ...)
{
  va_list ap; va_start(ap,cri_p0);
  cri_u8 a2 = va_arg(ap,cri_u8), a3 = va_arg(ap,cri_u8), a4 = va_arg(ap,cri_u8);  // rdx, r8, r9: the exe calls the hook with them untouched
  va_end(ap);
  if (DAT_143e64b30 != (cri_code *)0x0) {
    (*DAT_143e64b30)((longlong)cri_p0,a2,a3,a4);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b300
void FUN_14005b300(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 arg1 = cri_p0;
  cri_u8 arg2 = cri_p1;
  int i_v1;
  uint u_v2;
  cri_u8 u_v3;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    FUN_14005af30(0,0xff05020a);
    return;
  }
  u_v3 = 0xff030305;
  u_v2 = FUN_140051d90(arg2);
  if (u_v2 != 0) {
    while ((u_v2 & 0xcc) == 0) {
      i_v1 = FUN_140052010(arg2,1,4);
      if ((i_v1 != 4) || (u_v2 = FUN_140051d90(arg2), u_v2 == 0)) goto LAB_14005b36f;
    }
    u_v3 = 0;
  }
LAB_14005b36f:
  FUN_14005af30(arg1,u_v3);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b390
void FUN_14005b390(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  cri_u8 arg2 = cri_p1;
  void *arg3 = cri_p2;
  ushort u_v1;
  ushort u_v2;
  int i_v3;
  ulonglong u_v4;
  ulonglong u_v5;
  ulonglong u_v6;
  int i_v7;
  cri_u8 u_v8;
  
  i_v7 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v7 == 0) {
    u_v4 = *(ulonglong *)((longlong)arg3 + 0x50);
    if (((((u_v4 != 0) && (u_v5 = *(ulonglong *)((longlong)arg3 + 0x40), u_v5 != 0)) &&
         (u_v6 = *(ulonglong *)((longlong)arg3 + 0x48), u_v6 != 0)) &&
        ((((u_v4 & 0x7f) == 0 && ((u_v5 & 0x7f) == 0)) &&
         (((u_v6 & 0x7f) == 0 && ((u_v4 != u_v5 && (u_v4 != u_v6)))))))) &&
       ((u_v5 != u_v6 &&
        (((((u_v1 = *(ushort *)((longlong)arg3 + 0x5a), 0 < (short)u_v1 &&
            (u_v2 = *(ushort *)((longlong)arg3 + 0x58), 0 < (short)u_v2)) &&
           ((short)u_v1 < 0x4001)) && (((short)u_v2 < 0x4001 && ((u_v1 & 0x7f) == 0)))) &&
         ((u_v2 & 0x7f) == 0)))))) {
      memcpy((void *)((char *)arg1 + 0x1b28),arg3,0x78);
      i_v7 = *(int *)((char *)arg1 + 0x1a44);
      i_v3 = *(int *)((char *)arg1 + 0x1a48);
      *(cri_u8 *)((char *)arg1 + 0x1ba0) = *(cri_u8 *)((char *)arg1 + 0x1b68);
      *(cri_u8 *)((char *)arg1 + 0x1ba8) = *(cri_u8 *)((char *)arg1 + 0x1b70);
      *(cri_u8 *)((char *)arg1 + 0x1bb0) = *(cri_u8 *)((char *)arg1 + 0x1b78);
      *(cri_u8 *)((char *)arg1 + 0x1bb8) = *(cri_u8 *)((char *)arg1 + 0x1b80);
      *(cri_u4 *)((char *)arg1 + 0xd44) = *(cri_u4 *)((char *)arg1 + 0x1a78);
      FUN_14008c780(arg1);
      FUN_14008ab40(arg1);
      FUN_140054490(arg1);
      FUN_14005ae00(arg1);
      FUN_140089fe0(arg1,arg2);
      *(int *)((longlong)arg3 + 0x68) = *(int *)((char *)arg1 + 0x1a44) - i_v7;
      *(int *)((longlong)arg3 + 0x6c) = *(int *)((char *)arg1 + 0x1a48) - i_v3;
      *(cri_u2 *)((longlong)arg3 + 0x70) = *(cri_u2 *)((char *)arg1 + 0x1b98);
      *(int *)((char *)arg1 + 0xd28) = *(int *)((char *)arg1 + 0xd28) + 1;
      return;
    }
    u_v8 = 0xff050306;
  }
  else {
    u_v8 = 0xff050209;
    arg1 = 0;
  }
  FUN_14005af30(arg1,u_v8);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b560
void FUN_14005b560(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  cri_u4 u_v1;
  
  u_v1 = *(cri_u4 *)((char *)arg1 + 0x720);
  *(cri_u4 *)((char *)arg1 + 0x72c) = u_v1;
  *(cri_u4 *)((char *)arg1 + 0x728) = u_v1;
  *(cri_u4 *)((char *)arg1 + 0x724) = u_v1;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b580
void FUN_14005b580(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  *(cri_u8 *)((char *)arg1 + 0xb9c) = 0;
  *(cri_u8 *)((char *)arg1 + 0xba4) = 0;
  *(cri_u8 *)((char *)arg1 + 0xbac) = 0;
  *(cri_u8 *)((char *)arg1 + 0xbb4) = 0;
  *(cri_u8 *)((char *)arg1 + 0xbbc) = 0;
  *(cri_u8 *)((char *)arg1 + 0xbc4) = 0;
  *(cri_u8 *)((char *)arg1 + 0xbcc) = 0;
  *(cri_u8 *)((char *)arg1 + 0xbd4) = 0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b5c0
void FUN_14005b5c0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  int i_v1;
  
  i_v1 = *(int *)((char *)arg1 + 0x5f0);
  if (i_v1 == 1) {
    *(cri_u4 *)((char *)arg1 + 0xb90) = 1;
    *(cri_u4 *)((char *)arg1 + 0xb98) = 0;
    *(cri_u4 *)((char *)arg1 + 0xb94) = 1;
    *(uint *)((char *)arg1 + 0xb8c) = (*(uint *)((char *)arg1 + 0xb84) < 2) + 1;
  }
  else {
    if (i_v1 == 2) {
      *(cri_u4 *)((char *)arg1 + 0xb8c) = 1;
      *(cri_u4 *)((char *)arg1 + 0xb90) = 0;
      *(cri_u4 *)((char *)arg1 + 0xb94) = 0;
      *(cri_u4 *)((char *)arg1 + 0xb98) = 0;
      return;
    }
    if (i_v1 == 3) {
      *(cri_u4 *)((char *)arg1 + 0xb90) = 2;
      *(cri_u4 *)((char *)arg1 + 0xb98) = 1;
      *(cri_u4 *)((char *)arg1 + 0xb8c) = 1;
      *(cri_u4 *)((char *)arg1 + 0xb94) = 1;
      return;
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b650
void FUN_14005b650(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  int i_v1;
  
  i_v1 = *(int *)((char *)arg1 + 0x5f4);
  if (i_v1 == 1) {
    *(cri_u4 *)((char *)arg1 + 0xb90) = 1;
    *(cri_u4 *)((char *)arg1 + 0xb98) = 0;
  }
  else {
    if (i_v1 == 2) {
      *(cri_u4 *)((char *)arg1 + 0xb90) = 3;
      *(cri_u4 *)((char *)arg1 + 0xb98) = 0;
      *(cri_u4 *)((char *)arg1 + 0xb8c) = 2;
      *(cri_u4 *)((char *)arg1 + 0xb94) = 1;
      return;
    }
    if (i_v1 != 3) {
      return;
    }
    *(cri_u4 *)((char *)arg1 + 0xb90) = 2;
    *(cri_u4 *)((char *)arg1 + 0xb98) = 1;
  }
  *(cri_u4 *)((char *)arg1 + 0xb8c) = 1;
  *(cri_u4 *)((char *)arg1 + 0xb94) = 1;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b6d0
void FUN_14005b6d0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, ...)
{
  longlong arg1 = cri_p0;
  int arg2 = cri_p1;
  int arg3 = cri_p2;
  int arg4 = cri_p3;
  longlong l_v1;
  longlong l_v2;
  bool b_v3;
  int i_v4;
  int i_v5;
  int i_v6;
  
  l_v1 = (longlong)arg3 + (longlong)arg2 * 2;
  b_v3 = true;
  l_v2 = (longlong)arg4 + l_v1 * 2;
  i_v5 = *(int *)(arg1 + 0x60c + l_v2 * 4);
  i_v6 = 1 << ((char)*(cri_u4 *)
                       (arg1 + 0x304 + ((longlong)arg4 + (longlong)arg3 * 2) * 4) - 1U &
               0x1f);
  if ((i_v6 != 1) && (i_v5 != 0)) {
    if (i_v5 < 0) {
      i_v5 = (-1 - *(int *)(arg1 + 0x64c + l_v2 * 4)) - (-1 - i_v5) * i_v6;
    }
    else {
      i_v5 = *(int *)(arg1 + 0x64c + l_v2 * 4) + 1 + (i_v5 + -1) * i_v6;
    }
  }
  if (((*(int *)((char *)arg1 + 0xb94) == 1) && (arg4 == 1)) && (*(int *)((char *)arg1 + 0x318) == 3)) {
    i_v4 = *(int *)(arg1 + 0xba0 + l_v1 * 8) >> 1;
  }
  else {
    i_v4 = *(int *)(arg1 + 0xb9c + l_v2 * 4);
    b_v3 = false;
  }
  i_v4 = i_v4 + i_v5;
  *(int *)(arg1 + 0xbbc + l_v2 * 4) = i_v4;
  if (i_v4 < i_v6 * -0x10) {
    *(int *)(arg1 + 0xbbc + l_v2 * 4) = i_v4 + i_v6 * 0x20;
  }
  i_v5 = *(int *)(arg1 + 0xbbc + l_v2 * 4);
  if (i_v6 * 0x10 + -1 < i_v5) {
    *(int *)(arg1 + 0xbbc + l_v2 * 4) = i_v5 + i_v6 * -0x20;
  }
  i_v5 = *(int *)(arg1 + 0xbbc + l_v2 * 4);
  if (b_v3) {
    i_v5 = i_v5 * 2;
  }
  *(int *)(arg1 + 0xb9c + l_v2 * 4) = i_v5;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b810
void FUN_14005b810(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  uint u_v1;
  uint u_v2;
  
  if ((*(uint *)((char *)arg1 + 0x5e8) & 4) != 0) {
    *(cri_u4 *)((char *)arg1 + 0x71c) = 0x3f;
    return;
  }
  *(cri_u4 *)((char *)arg1 + 0x71c) = 0;
  if ((*(uint *)((char *)arg1 + 0x5e8) & 8) != 0) {
    u_v1 = 1;
    u_v2 = 5;
    do {
      if ((*(uint *)((char *)arg1 + 0x694) >> (u_v2 & 0x1f) & 1) != 0) {
        *(uint *)((char *)arg1 + 0x71c) = *(uint *)((char *)arg1 + 0x71c) | u_v1;
      }
      u_v2 = u_v2 - 1;
      u_v1 = u_v1 << 1 | (uint)((int)u_v1 < 0);
    } while (u_v2 < 0x80000000);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b860
void FUN_14005b860(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  int i_v1;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    FUN_14005af30(0,0xff050210);
    return;
  }
  *(cri_u4 *)((char *)arg1 + 0x1bc0) = 1;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b8a0
void FUN_14005b8a0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  if (*(int *)((char *)arg1 + 0x318) == 3) {
    FUN_14005b5c0(arg1);  // tail jmp keeps rcx
    return;
  }
  FUN_14005b650(arg1);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005b8c0
cri_u8 FUN_14005b8c0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  int *pi_v1;
  char c_v2;
  int i_v3;
  int i_v4;
  int i_v5;
  byte b_v6;
  int i_v7;
  uint u_v8;
  uint u_v9;
  uint u_v10;
  uint u_v11;
  int i_v12;
  cri_u8 u_v13;
  cri_u1 *pu_v14;
  
  i_v12 = *(int *)((char *)arg1 + 0xc94);
  *(cri_u4 *)((char *)arg1 + 0xc94) = 5;
  pi_v1 = (int *)(arg1 + 0xce4 + (ulonglong)*(uint *)((char *)arg1 + 0x2e0) * 4);
  *pi_v1 = *pi_v1 + 1;
  u_v8 = *(uint *)((char *)arg1 + 0xc7c);
  u_v9 = *(uint *)((char *)arg1 + 0xc80);
  i_v7 = *(int *)((char *)arg1 + 0xc78);
  pu_v14 = *(cri_u1 **)((char *)arg1 + 0xc88);
  i_v3 = *(int *)((char *)arg1 + 0x6f0);
  do {
    u_v10 = u_v8 >> 0x15;
    u_v11 = u_v10;
    if (0x15 < i_v7) {
      u_v11 = u_v10 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
    }
    if (u_v11 != 8) {
      u_v11 = u_v8 >> 0x15;
      if (0x15 < i_v7) {
        u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
      }
      c_v2 = (&DAT_143ee68c1)[(ulonglong)u_v11 * 2];
      *(int *)((char *)arg1 + 0x5e4) = (int)c_v2;
      if (c_v2 == 0x24) {
        *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
      }
      else {
        i_v7 = i_v7 + (char)(&DAT_143ee68c0)[(ulonglong)u_v11 * 2];
        if (i_v7 < 0x20) {
          u_v8 = u_v8 << ((&DAT_143ee68c0)[(ulonglong)u_v11 * 2] & 0x1f);
        }
        else {
          i_v7 = i_v7 + -0x20;
          u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
          u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
          pu_v14 = pu_v14 + 4;
        }
      }
      i_v4 = *(int *)((char *)arg1 + 0x5e4);
      if (i_v4 == 0x24) {
        *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
        goto LAB_14005dbf5;
      }
      if (i_v4 == 0x22) {
        *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
        goto LAB_14005dbf5;
      }
      *(int *)((char *)arg1 + 0x6f0) = *(int *)((char *)arg1 + 0x6f0) + i_v4;
      i_v4 = *(int *)((char *)arg1 + 0x6cc);
      i_v5 = *(int *)((char *)arg1 + 0x6f0);
      if (((i_v4 != 0) && (*(int *)((char *)arg1 + 0x6d0) != 0)) &&
         (*(int *)((char *)arg1 + 0x6d0) * i_v4 <= i_v5)) {
        *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
        goto LAB_14005dbf5;
      }
      if (i_v12 != 4) {
        if ((i_v4 != 0) && (i_v5 / i_v4 != i_v3 / i_v4)) {
          *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          goto LAB_14005dbf5;
        }
        if (1 < (uint)(i_v5 - i_v3)) {
          FUN_14005b560(arg1);
          if (*(int *)((char *)arg1 + 0x2e0) == 2) {
            FUN_14005b580(arg1);  // FUN_14005b560 keeps rcx
          }
          FUN_14008a970(arg1,i_v3);  // edx = r10d, the subtrahend of the test above
          FUN_14008c820(arg1);
        }
      }
      (**(cri_code **)((char *)arg1 + 0x1be0))(arg1);
      *(uint *)((char *)arg1 + 0x6f8) = *(uint *)((char *)arg1 + 0x6f0) % *(uint *)((char *)arg1 + 0x6cc);
      c_v2 = (char)i_v7;
      if ((*(int *)((char *)arg1 + 0x710) == 1) && (*(int *)((char *)arg1 + 0x288) == 2)) {
        u_v11 = u_v8 >> 0x1d;
        if (0x1d < i_v7) {
          u_v11 = u_v11 | u_v9 >> (0x3dU - c_v2 & 0x1f);
        }
        c_v2 = (&DAT_143e66831)[(ulonglong)u_v11 * 2];
        *(int *)((char *)arg1 + 0x5e8) = (int)c_v2;
        if (c_v2 == 0x7f) {
          *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
        }
        else {
          i_v7 = i_v7 + (char)(&DAT_143e66830)[(ulonglong)u_v11 * 2];
          if (i_v7 < 0x20) {
            u_v8 = u_v8 << ((&DAT_143e66830)[(ulonglong)u_v11 * 2] & 0x1f);
          }
          else {
            i_v7 = i_v7 + -0x20;
            u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
            u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
            pu_v14 = pu_v14 + 4;
          }
        }
      }
      else if ((*(int *)((char *)arg1 + 0x710) == 1) &&
              ((*(int *)((char *)arg1 + 0x288) == 1 && (*(int *)((char *)arg1 + 0x714) == 1)))) {
        i_v12 = *(int *)((char *)arg1 + 0x2e0);
        if (i_v12 == 1) {
          u_v11 = u_v8 >> 0x1c;
          if (0x1c < i_v7) {
            u_v11 = u_v11 | u_v9 >> (0x3cU - c_v2 & 0x1f);
          }
          c_v2 = (&DAT_143e64be1)[(ulonglong)u_v11 * 2];
          *(int *)((char *)arg1 + 0x5e8) = (int)c_v2;
          if (c_v2 == 0x7f) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
          else {
            i_v7 = i_v7 + (char)(&DAT_143e64be0)[(ulonglong)u_v11 * 2];
            if (i_v7 < 0x20) {
              u_v8 = u_v8 << ((&DAT_143e64be0)[(ulonglong)u_v11 * 2] & 0x1f);
            }
            else {
              i_v7 = i_v7 + -0x20;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
          }
        }
        else if (i_v12 == 2) {
          u_v11 = u_v8 >> 0x19;
          if (0x19 < i_v7) {
            u_v11 = u_v11 | u_v9 >> (0x39U - c_v2 & 0x1f);
          }
          c_v2 = (&DAT_143f68141)[(ulonglong)u_v11 * 2];
          *(int *)((char *)arg1 + 0x5e8) = (int)c_v2;
          if (c_v2 == 0x7f) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
          else {
            i_v7 = i_v7 + (char)(&DAT_143f68140)[(ulonglong)u_v11 * 2];
            if (i_v7 < 0x20) {
              u_v8 = u_v8 << ((&DAT_143f68140)[(ulonglong)u_v11 * 2] & 0x1f);
            }
            else {
              i_v7 = i_v7 + -0x20;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
          }
        }
        else if (i_v12 == 3) {
          u_v11 = u_v8 >> 0x17;
          if (0x17 < i_v7) {
            u_v11 = u_v11 | u_v9 >> (0x37U - c_v2 & 0x1f);
          }
          c_v2 = (&DAT_143f67cc1)[(ulonglong)u_v11 * 2];
          *(int *)((char *)arg1 + 0x5e8) = (int)c_v2;
          if (c_v2 == 0x7f) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
          else {
            i_v7 = i_v7 + (char)(&DAT_143f67cc0)[(ulonglong)u_v11 * 2];
            if (i_v7 < 0x20) {
              u_v8 = u_v8 << ((&DAT_143f67cc0)[(ulonglong)u_v11 * 2] & 0x1f);
            }
            else {
              i_v7 = i_v7 + -0x20;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
          }
        }
      }
      else {
        i_v12 = *(int *)((char *)arg1 + 0x2e0);
        if (i_v12 == 1) {
          u_v11 = u_v8 >> 0x1e;
          if (0x1e < i_v7) {
            u_v11 = u_v11 | u_v9 >> (0x3eU - c_v2 & 0x1f);
          }
          c_v2 = (&DAT_143fe8241)[(ulonglong)u_v11 * 2];
          *(int *)((char *)arg1 + 0x5e8) = (int)c_v2;
          if (c_v2 == 0x7f) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
          else {
            i_v7 = i_v7 + (char)(&DAT_143fe8240)[(ulonglong)u_v11 * 2];
            if (i_v7 < 0x20) {
              u_v8 = u_v8 << ((&DAT_143fe8240)[(ulonglong)u_v11 * 2] & 0x1f);
            }
            else {
              i_v7 = i_v7 + -0x20;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
          }
        }
        else if (i_v12 == 2) {
          u_v11 = u_v8 >> 0x1a;
          if (0x1a < i_v7) {
            u_v11 = u_v11 | u_v9 >> (0x3aU - c_v2 & 0x1f);
          }
          c_v2 = (&DAT_143e66841)[(ulonglong)u_v11 * 2];
          *(int *)((char *)arg1 + 0x5e8) = (int)c_v2;
          if (c_v2 == 0x7f) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
          else {
            i_v7 = i_v7 + (char)(&DAT_143e66840)[(ulonglong)u_v11 * 2];
            if (i_v7 < 0x20) {
              u_v8 = u_v8 << ((&DAT_143e66840)[(ulonglong)u_v11 * 2] & 0x1f);
            }
            else {
              i_v7 = i_v7 + -0x20;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
          }
        }
        else if (i_v12 == 3) {
          u_v11 = u_v8 >> 0x1a;
          if (0x1a < i_v7) {
            u_v11 = u_v11 | u_v9 >> (0x3aU - c_v2 & 0x1f);
          }
          c_v2 = (&DAT_143f680c1)[(ulonglong)u_v11 * 2];
          *(int *)((char *)arg1 + 0x5e8) = (int)c_v2;
          if (c_v2 == 0x7f) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
          else {
            i_v7 = i_v7 + (char)(&DAT_143f680c0)[(ulonglong)u_v11 * 2];
            if (i_v7 < 0x20) {
              u_v8 = u_v8 << ((&DAT_143f680c0)[(ulonglong)u_v11 * 2] & 0x1f);
            }
            else {
              i_v7 = i_v7 + -0x20;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
          }
        }
      }
      if (*(uint *)((char *)arg1 + 0x5e8) == 0x7f) {
        *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
      }
      else {
        if ((*(uint *)((char *)arg1 + 0x5e8) & 4) == 0) {
          FUN_14005b560(arg1);
        }
        if ((*(int *)((char *)arg1 + 0x324) == 0) && ((*(byte *)((char *)arg1 + 0x5e8) & 4) != 0)) {
          FUN_14005b580(arg1);
        }
        u_v13 = 0;
        i_v12 = 0;
        if (((*(int *)((char *)arg1 + 0x2e0) == 2) && ((*(uint *)((char *)arg1 + 0x5e8) & 0x20) == 0)) &&
           ((*(uint *)((char *)arg1 + 0x5e8) & 4) == 0)) {
          FUN_14005b580(arg1);
          i_v12 = (int)u_v13;
          *(int *)((char *)arg1 + 0x5fc) =
               (int)CONCAT71((int7)((ulonglong)u_v13 >> 8),*(int *)((char *)arg1 + 0x318) == 2);
        }
        u_v11 = *(uint *)((char *)arg1 + 0x5e8);
        if ((u_v11 & 8) == 0) {
          *(int *)((char *)arg1 + 0x694) = i_v12;
        }
        if ((u_v11 & 2) == 0) {
          *(uint *)((char *)arg1 + 0xc14) = (u_v11 & 1) << 3;
        }
        else if (*(int *)((char *)arg1 + 0x590) == 0) {
          *(cri_u4 *)((char *)arg1 + 0xc14) = 4;
        }
        else {
          if (i_v7 < 0x1e) {
            i_v7 = i_v7 + 2;
            u_v10 = u_v8 >> 0x1e;
            u_v8 = u_v8 << 2;
            *(uint *)((char *)arg1 + 0x5ec) = u_v10;
          }
          else {
            i_v7 = i_v7 + -0x1e;
            if (i_v7 == 0) {
              *(uint *)((char *)arg1 + 0x5ec) = u_v8 >> 0x1e;
              u_v8 = u_v9;
            }
            else {
              *(uint *)((char *)arg1 + 0x5ec) = (u_v9 >> (2 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1e;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
            }
            u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
            pu_v14 = pu_v14 + 4;
          }
          *(uint *)((char *)arg1 + 0xc14) =
               (uint)(byte)(&DAT_1431bba40)
                           [(ulonglong)*(uint *)((char *)arg1 + 0x5ec) +
                            (ulonglong)(*(int *)((char *)arg1 + 0x590) - 1) * 4];
        }
        b_v6 = (&DAT_1431bba50)[*(int *)((char *)arg1 + 0xc14)];
        *(cri_u4 *)((char *)arg1 + 0x5f0) = 2;
        *(cri_u4 *)((char *)arg1 + 0x5f4) = 1;
        *(uint *)((char *)arg1 + 0xb84) = (uint)b_v6;
        if (((u_v11 & 0x20) != 0) || ((u_v11 & 0x10) != 0)) {
          if (*(int *)((char *)arg1 + 0x318) == 3) {
            if (*(int *)(arg1 + 800) == i_v12) {
              if (i_v7 < 0x1e) {
                i_v7 = i_v7 + 2;
                u_v11 = u_v8 >> 0x1e;
                u_v8 = u_v8 << 2;
                *(uint *)((char *)arg1 + 0x5f0) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x1e;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x5f0) = u_v8 >> 0x1e;
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x5f0) = (u_v9 >> (2 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1e;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
          }
          else if (i_v7 < 0x1e) {
            i_v7 = i_v7 + 2;
            u_v11 = u_v8 >> 0x1e;
            u_v8 = u_v8 << 2;
            *(uint *)((char *)arg1 + 0x5f4) = u_v11;
          }
          else {
            i_v7 = i_v7 + -0x1e;
            if (i_v7 == 0) {
              *(uint *)((char *)arg1 + 0x5f4) = u_v8 >> 0x1e;
              u_v8 = u_v9;
            }
            else {
              *(uint *)((char *)arg1 + 0x5f4) = (u_v9 >> (2 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1e;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
            }
            u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
            pu_v14 = pu_v14 + 4;
          }
        }
        FUN_14005b8a0(arg1);
        if (((*(int *)((char *)arg1 + 0x318) == 3) && (*(int *)(arg1 + 800) == i_v12)) &&
           (((*(uint *)((char *)arg1 + 0x5e8) & 4) != 0 || ((*(uint *)((char *)arg1 + 0x5e8) & 8) != 0)))) {
          if (i_v7 < 0x1f) {
            i_v7 = i_v7 + 1;
            u_v11 = u_v8 >> 0x1f;
            u_v8 = u_v8 * 2;
            *(uint *)((char *)arg1 + 0x5f8) = u_v11;
          }
          else {
            i_v7 = i_v7 + -0x1f;
            if (i_v7 == 0) {
              *(uint *)((char *)arg1 + 0x5f8) = u_v8 >> 0x1f;
              u_v8 = u_v9;
            }
            else {
              *(uint *)((char *)arg1 + 0x5f8) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1f;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
            }
            u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
            pu_v14 = pu_v14 + 4;
          }
        }
        else {
          *(int *)((char *)arg1 + 0x5f8) = i_v12;
        }
        u_v11 = *(uint *)((char *)arg1 + 0x5e8);
        if ((u_v11 & 0x40) != 0) {
          if (i_v7 < 0x1b) {
            i_v7 = i_v7 + 5;
            u_v10 = u_v8 >> 0x1b;
            u_v8 = u_v8 << 5;
            *(uint *)((char *)arg1 + 0x5c4) = u_v10;
          }
          else {
            i_v7 = i_v7 + -0x1b;
            if (i_v7 == 0) {
              *(uint *)((char *)arg1 + 0x5c4) = u_v8 >> 0x1b;
              u_v8 = u_v9;
            }
            else {
              *(uint *)((char *)arg1 + 0x5c4) = (u_v9 >> (5 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1b;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
            }
            u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
            pu_v14 = pu_v14 + 4;
          }
          *(cri_u1 *)((char *)arg1 + 0x774) =
               (&DAT_1431bba60)
               [(ulonglong)*(uint *)((char *)arg1 + 0x328) * 0x20 + (ulonglong)*(uint *)((char *)arg1 + 0x5c4)
               ];
        }
        if (((u_v11 & 0x20) != 0) || (((u_v11 & 4) != 0 && (*(int *)((char *)arg1 + 0x324) != i_v12)))
           ) {
          if (*(int *)((char *)arg1 + 0xb8c) == 1) {
            if ((*(int *)((char *)arg1 + 0xb94) == 1) && (*(int *)((char *)arg1 + 0xb98) != 1)) {
              if (i_v7 < 0x1f) {
                i_v7 = i_v7 + 1;
                u_v11 = u_v8 >> 0x1f;
                u_v8 = u_v8 * 2;
                *(uint *)((char *)arg1 + 0x5fc) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x1f;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x5fc) = u_v8 >> 0x1f;
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x5fc) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1f;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x60c) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v3 = *(int *)((char *)arg1 + 0x304);
            if ((i_v3 != 1) && (*(int *)((char *)arg1 + 0x60c) != i_v12)) {
              b_v6 = (byte)(0x21 - i_v3);
              if (i_v7 < 0x21 - i_v3) {
                i_v7 = i_v7 + -1 + i_v3;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v3 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x64c) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v3;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x64c) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x64c) =
                       (u_v9 >> (((char)i_v3 - (byte)i_v7) - 1 & 0x1f) | u_v8) >> (b_v6 & 0x1f)
                  ;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x68c) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,0,0);
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x610) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x308);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x610) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x650) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x650) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x650) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v8) >>
                       (b_v6 & 0x1f);
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x690) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,0,1);
            *(cri_u4 *)((char *)arg1 + 0xbac) = *(cri_u4 *)((char *)arg1 + 0xb9c);
            *(cri_u4 *)((char *)arg1 + 0xbb0) = *(cri_u4 *)((char *)arg1 + 0xba0);
          }
          else {
            if (i_v7 < 0x1f) {
              i_v7 = i_v7 + 1;
              u_v11 = u_v8 * 2;
              *(uint *)((char *)arg1 + 0x5fc) = u_v8 >> 0x1f;
            }
            else {
              i_v7 = i_v7 + -0x1f;
              if (i_v7 == 0) {
                *(uint *)((char *)arg1 + 0x5fc) = u_v8 >> 0x1f;
                u_v11 = u_v9;
              }
              else {
                *(uint *)((char *)arg1 + 0x5fc) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1f;
                u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
              }
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
            u_v8 = u_v11 >> 0x15;
            if (0x15 < i_v7) {
              u_v8 = u_v8 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v8 * 2];
            *(int *)((char *)arg1 + 0x60c) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v8 * 2];
              if (i_v7 < 0x20) {
                u_v11 = u_v11 << ((&DAT_143e65820)[(ulonglong)u_v8 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v3 = *(int *)((char *)arg1 + 0x304);
            if ((i_v3 != 1) && (*(int *)((char *)arg1 + 0x60c) != i_v12)) {
              b_v6 = (byte)(0x21 - i_v3);
              if (i_v7 < 0x21 - i_v3) {
                i_v7 = i_v7 + -1 + i_v3;
                u_v8 = u_v11 >> (b_v6 & 0x1f);
                u_v11 = u_v11 << ((char)i_v3 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x64c) = u_v8;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v3;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x64c) = u_v11 >> (b_v6 & 0x1f);
                  u_v11 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x64c) =
                       (u_v9 >> (((char)i_v3 - (byte)i_v7) - 1 & 0x1f) | u_v11) >>
                       (b_v6 & 0x1f);
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v8 = u_v11 >> 0x1e;
              if (0x1e < i_v7) {
                u_v8 = u_v8 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v8 * 2];
              *(int *)((char *)arg1 + 0x68c) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v8 * 2];
                if (i_v7 < 0x20) {
                  u_v11 = u_v11 << ((&DAT_143e66820)[(ulonglong)u_v8 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,0,0);
            u_v8 = u_v11 >> 0x15;
            if (0x15 < i_v7) {
              u_v8 = u_v8 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v8 * 2];
            *(int *)((char *)arg1 + 0x610) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v8 * 2];
              if (i_v7 < 0x20) {
                u_v11 = u_v11 << ((&DAT_143e65820)[(ulonglong)u_v8 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x308);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x610) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v8 = u_v11 >> (b_v6 & 0x1f);
                u_v11 = u_v11 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x650) = u_v8;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x650) = u_v11 >> (b_v6 & 0x1f);
                  u_v11 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x650) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v11) >>
                       (b_v6 & 0x1f);
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v8 = u_v11 >> 0x1e;
              if (0x1e < i_v7) {
                u_v8 = u_v8 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v8 * 2];
              *(int *)((char *)arg1 + 0x690) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v8 * 2];
                if (i_v7 < 0x20) {
                  u_v11 = u_v11 << ((&DAT_143e66820)[(ulonglong)u_v8 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,0,1);
            if (i_v7 < 0x1f) {
              i_v7 = i_v7 + 1;
              u_v8 = u_v11 * 2;
              *(uint *)((char *)arg1 + 0x604) = u_v11 >> 0x1f;
            }
            else {
              i_v7 = i_v7 + -0x1f;
              if (i_v7 == 0) {
                *(uint *)((char *)arg1 + 0x604) = u_v11 >> 0x1f;
                u_v8 = u_v9;
              }
              else {
                *(uint *)((char *)arg1 + 0x604) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v11) >> 0x1f;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              }
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x61c) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x304);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x61c) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x65c) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x65c) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x65c) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v8) >>
                       (b_v6 & 0x1f);
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x68c) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,1,0,0);
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x620) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x308);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x620) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x660) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x660) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x660) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v8) >>
                       (b_v6 & 0x1f);
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x690) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,1,0,1);
          }
        }
        if ((*(byte *)((char *)arg1 + 0x5e8) & 0x10) != 0) {
          if (*(int *)((char *)arg1 + 0xb8c) == 1) {
            if ((*(int *)((char *)arg1 + 0xb94) == 1) && (*(int *)((char *)arg1 + 0xb98) != 1)) {
              if (i_v7 < 0x1f) {
                i_v7 = i_v7 + 1;
                u_v11 = u_v8 >> 0x1f;
                u_v8 = u_v8 * 2;
                *(uint *)((char *)arg1 + 0x600) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x1f;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x600) = u_v8 >> 0x1f;
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x600) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1f;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x614) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x30c);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x614) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x654) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x654) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x654) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v8) >>
                       (b_v6 & 0x1f);
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x68c) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,1,0);
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x618) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x310);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x618) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x658) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x658) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x658) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v8) >>
                       (b_v6 & 0x1f);
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x690) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,1,1);
            *(cri_u4 *)((char *)arg1 + 0xbb4) = *(cri_u4 *)((char *)arg1 + 0xba4);
            *(cri_u4 *)(arg1 + 3000) = *(cri_u4 *)((char *)arg1 + 0xba8);
          }
          else {
            if (i_v7 < 0x1f) {
              i_v7 = i_v7 + 1;
              u_v11 = u_v8 * 2;
              *(uint *)((char *)arg1 + 0x600) = u_v8 >> 0x1f;
            }
            else {
              i_v7 = i_v7 + -0x1f;
              if (i_v7 == 0) {
                *(uint *)((char *)arg1 + 0x600) = u_v8 >> 0x1f;
                u_v11 = u_v9;
              }
              else {
                *(uint *)((char *)arg1 + 0x600) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1f;
                u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
              }
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
            u_v8 = u_v11 >> 0x15;
            if (0x15 < i_v7) {
              u_v8 = u_v8 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v8 * 2];
            *(int *)((char *)arg1 + 0x614) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v8 * 2];
              if (i_v7 < 0x20) {
                u_v11 = u_v11 << ((&DAT_143e65820)[(ulonglong)u_v8 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x30c);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x614) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v8 = u_v11 >> (b_v6 & 0x1f);
                u_v11 = u_v11 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x654) = u_v8;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x654) = u_v11 >> (b_v6 & 0x1f);
                  u_v11 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x654) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v11) >>
                       (b_v6 & 0x1f);
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v8 = u_v11 >> 0x1e;
              if (0x1e < i_v7) {
                u_v8 = u_v8 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v8 * 2];
              *(int *)((char *)arg1 + 0x68c) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v8 * 2];
                if (i_v7 < 0x20) {
                  u_v11 = u_v11 << ((&DAT_143e66820)[(ulonglong)u_v8 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,1,0);
            u_v8 = u_v11 >> 0x15;
            if (0x15 < i_v7) {
              u_v8 = u_v8 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v8 * 2];
            *(int *)((char *)arg1 + 0x618) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v8 * 2];
              if (i_v7 < 0x20) {
                u_v11 = u_v11 << ((&DAT_143e65820)[(ulonglong)u_v8 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x310);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x618) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v8 = u_v11 >> (b_v6 & 0x1f);
                u_v11 = u_v11 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x658) = u_v8;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x658) = u_v11 >> (b_v6 & 0x1f);
                  u_v11 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x658) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v11) >>
                       (b_v6 & 0x1f);
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v8 = u_v11 >> 0x1e;
              if (0x1e < i_v7) {
                u_v8 = u_v8 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v8 * 2];
              *(int *)((char *)arg1 + 0x690) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v8 * 2];
                if (i_v7 < 0x20) {
                  u_v11 = u_v11 << ((&DAT_143e66820)[(ulonglong)u_v8 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v11 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,0,1,1);
            if (i_v7 < 0x1f) {
              i_v7 = i_v7 + 1;
              u_v8 = u_v11 * 2;
              *(uint *)((char *)arg1 + 0x608) = u_v11 >> 0x1f;
            }
            else {
              i_v7 = i_v7 + -0x1f;
              if (i_v7 == 0) {
                *(uint *)((char *)arg1 + 0x608) = u_v11 >> 0x1f;
                u_v8 = u_v9;
              }
              else {
                *(uint *)((char *)arg1 + 0x608) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v11) >> 0x1f;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              }
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x624) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x30c);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x624) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x664) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x664) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x664) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v8) >>
                       (b_v6 & 0x1f);
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x68c) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,1,1,0);
            u_v11 = u_v8 >> 0x15;
            if (0x15 < i_v7) {
              u_v11 = u_v11 | u_v9 >> (0x35U - (char)i_v7 & 0x1f);
            }
            c_v2 = (&DAT_143e65821)[(ulonglong)u_v11 * 2];
            *(int *)((char *)arg1 + 0x628) = (int)c_v2;
            if (c_v2 == -0x80) {
              *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
            }
            else {
              i_v7 = i_v7 + (char)(&DAT_143e65820)[(ulonglong)u_v11 * 2];
              if (i_v7 < 0x20) {
                u_v8 = u_v8 << ((&DAT_143e65820)[(ulonglong)u_v11 * 2] & 0x1f);
              }
              else {
                i_v7 = i_v7 + -0x20;
                u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            i_v12 = *(int *)((char *)arg1 + 0x310);
            if ((i_v12 != 1) && (*(int *)((char *)arg1 + 0x628) != 0)) {
              b_v6 = (byte)(0x21 - i_v12);
              if (i_v7 < 0x21 - i_v12) {
                i_v7 = i_v7 + -1 + i_v12;
                u_v11 = u_v8 >> (b_v6 & 0x1f);
                u_v8 = u_v8 << ((char)i_v12 - 1U & 0x1f);
                *(uint *)((char *)arg1 + 0x668) = u_v11;
              }
              else {
                i_v7 = i_v7 + -0x21 + i_v12;
                if (i_v7 == 0) {
                  *(uint *)((char *)arg1 + 0x668) = u_v8 >> (b_v6 & 0x1f);
                  u_v8 = u_v9;
                }
                else {
                  *(uint *)((char *)arg1 + 0x668) =
                       (u_v9 >> (((char)i_v12 - (byte)i_v7) - 1 & 0x1f) | u_v8) >>
                       (b_v6 & 0x1f);
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                }
                u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                pu_v14 = pu_v14 + 4;
              }
            }
            if (*(int *)((char *)arg1 + 0xb98) == 1) {
              u_v11 = u_v8 >> 0x1e;
              if (0x1e < i_v7) {
                u_v11 = u_v11 | u_v9 >> (0x3eU - (char)i_v7 & 0x1f);
              }
              c_v2 = (&DAT_143e66821)[(ulonglong)u_v11 * 2];
              *(int *)((char *)arg1 + 0x690) = (int)c_v2;
              if (c_v2 == -0x80) {
                *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
              }
              else {
                i_v7 = i_v7 + (char)(&DAT_143e66820)[(ulonglong)u_v11 * 2];
                if (i_v7 < 0x20) {
                  u_v8 = u_v8 << ((&DAT_143e66820)[(ulonglong)u_v11 * 2] & 0x1f);
                }
                else {
                  i_v7 = i_v7 + -0x20;
                  u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
                  u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
                  pu_v14 = pu_v14 + 4;
                }
              }
            }
            FUN_14005b6d0(arg1,1,1,1);
          }
        }
        if (((*(uint *)((char *)arg1 + 0x5e8) & 4) != 0) && (*(int *)((char *)arg1 + 0x324) != 0)) {
          if (i_v7 < 0x1f) {
            i_v7 = i_v7 + 1;
            u_v11 = u_v8 >> 0x1f;
            u_v8 = u_v8 * 2;
            *(uint *)((char *)arg1 + 0x18) = u_v11;
          }
          else {
            i_v7 = i_v7 + -0x1f;
            if (i_v7 == 0) {
              *(uint *)((char *)arg1 + 0x18) = u_v8 >> 0x1f;
              u_v8 = u_v9;
            }
            else {
              *(uint *)((char *)arg1 + 0x18) = (u_v9 >> (1 - (byte)i_v7 & 0x1f) | u_v8) >> 0x1f;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
            }
            u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
            pu_v14 = pu_v14 + 4;
          }
        }
        if ((*(uint *)((char *)arg1 + 0x5e8) & 8) != 0) {
          u_v11 = u_v8 >> 0x17;
          if (0x17 < i_v7) {
            u_v11 = u_v11 | u_v9 >> (0x37U - (char)i_v7 & 0x1f);
          }
          c_v2 = (&DAT_143e65401)[(ulonglong)u_v11 * 2];
          *(int *)((char *)arg1 + 0x694) = (int)c_v2;
          if (c_v2 == -0x80) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
          else {
            i_v7 = i_v7 + (char)(&DAT_143e65400)[(ulonglong)u_v11 * 2];
            if (i_v7 < 0x20) {
              u_v8 = u_v8 << ((&DAT_143e65400)[(ulonglong)u_v11 * 2] & 0x1f);
            }
            else {
              i_v7 = i_v7 + -0x20;
              u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
              u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
              pu_v14 = pu_v14 + 4;
            }
          }
          if (*(int *)((char *)arg1 + 0x694) == -0x80) {
            *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
          }
        }
      }
      goto LAB_14005dbf5;
    }
    if (i_v7 < 0x15) {
      i_v7 = i_v7 + 0xb;
      *(uint *)((char *)arg1 + 0x5e0) = u_v10;
      u_v8 = u_v8 << 0xb;
    }
    else {
      i_v7 = i_v7 + -0x15;
      if (i_v7 == 0) {
        *(uint *)((char *)arg1 + 0x5e0) = u_v10;
        u_v8 = u_v9;
      }
      else {
        *(uint *)((char *)arg1 + 0x5e0) = (u_v9 >> (0xb - (byte)i_v7 & 0x1f) | u_v8) >> 0x15;
        u_v8 = u_v9 << ((byte)i_v7 & 0x1f);
      }
      u_v9 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
      pu_v14 = pu_v14 + 4;
    }
    *(int *)((char *)arg1 + 0x6f0) = *(int *)((char *)arg1 + 0x6f0) + 0x21;
  } while (((*(int *)((char *)arg1 + 0x6cc) == 0) || (*(int *)((char *)arg1 + 0x6d0) == 0)) ||
          (*(int *)((char *)arg1 + 0x6f0) < *(int *)((char *)arg1 + 0x6d0) * *(int *)((char *)arg1 + 0x6cc)));
  *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
LAB_14005dbf5:
  if (*(int *)((char *)arg1 + 0xd0c) == 0) {
    FUN_14005b810(arg1);
    *(uint *)((char *)arg1 + 0xc7c) = u_v8;
    *(uint *)((char *)arg1 + 0xc80) = u_v9;
    *(int *)((char *)arg1 + 0xc78) = i_v7;
    *(cri_u1 **)((char *)arg1 + 0xc88) = pu_v14;
    *(cri_u4 *)((char *)arg1 + 0xc94) = 6;
    if ((*(byte *)((char *)arg1 + 0x5e8) & 4) == 0) {
      i_v7 = (**(cri_code **)((char *)arg1 + 0x1bd8))(arg1);  // the exe passes rcx = arg1 through (FUN_14005b810 leaves it intact)
    }
    else {
      i_v7 = (**(cri_code **)((char *)arg1 + 0x1bd0))(arg1);
    }
    if (i_v7 == 0) {
      return 0;
    }
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  return 0xffffffff;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005dc70
void FUN_14005dc70(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  longlong *arg2 = cri_p1;
  cri_u1 *pu_v1;
  cri_u1 *pu_v2;
  int *pi_v3;
  cri_u1 u_v4;
  byte b_v5;
  cri_u4 u_v6;
  uint u_v7;
  int i_v8;
  longlong *pl_v9;
  uint u_v10;
  uint u_v11;
  int i_v12;
  uint u_v13;
  cri_u1 *pu_v14;
  cri_u1 *pu_v15;
  cri_u1 loc_18 [16];
  
  *(cri_u4 *)((char *)arg1 + 0xc94) = 4;
  pi_v3 = (int *)(arg1 + 0xcd0 + (ulonglong)*(uint *)((char *)arg1 + 0x2e0) * 4);
  *pi_v3 = *pi_v3 + 1;
  *(cri_u4 *)((char *)arg1 + 0xb80) = 0;
  if (((*(int *)((char *)arg1 + 0x708) != 0) && (*(int *)((char *)arg1 + 0x708) != 1)) ||
     (*(int *)((char *)arg1 + 0x70c) != 0)) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
    return;
  }
  pl_v9 = arg2;
  FUN_14005b560(arg1);  // the exe passes rcx through
  FUN_14005b580(arg1);  // FUN_14005b560 keeps rcx
  (**(cri_code **)(*pl_v9 + 0x30))(arg2,1,0x7fffffff,arg1 + 0xd30);
  pu_v14 = (cri_u1 *)(*(ulonglong *)((char *)arg1 + 0xd30) & 0xfffffffffffffffc);
  i_v12 = *(int *)((char *)arg1 + 0xd30) * 8 + (int)pu_v14 * -8;
  b_v5 = (byte)i_v12;
  u_v10 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]) << (b_v5 & 0x1f)
  ;
  u_v11 = CONCAT31(CONCAT21(CONCAT11(pu_v14[4],pu_v14[5]),pu_v14[6]),pu_v14[7]);
  if (i_v12 == 0) {
    *(uint *)((char *)arg1 + 0x5b8) = u_v10;
  }
  else {
    u_v7 = u_v11 >> (0x20 - b_v5 & 0x1f);
    u_v11 = u_v11 << (b_v5 & 0x1f);
    *(uint *)((char *)arg1 + 0x5b8) = u_v7 | u_v10;
  }
  pu_v15 = pu_v14 + 0xc;
  u_v10 = CONCAT31(CONCAT21(CONCAT11(pu_v14[8],pu_v14[9]),pu_v14[10]),pu_v14[0xb]);
  if (0xaf0 < *(uint *)((char *)arg1 + 0x6c8)) {
    if (i_v12 < 0x1d) {
      i_v12 = i_v12 + 3;
      u_v7 = u_v11 >> 0x1d;
      u_v11 = u_v11 << 3;
      *(uint *)((char *)arg1 + 0x5bc) = u_v7;
    }
    else {
      i_v12 = i_v12 + -0x1d;
      if (i_v12 == 0) {
        *(uint *)((char *)arg1 + 0x5bc) = u_v11 >> 0x1d;
        u_v11 = u_v10;
      }
      else {
        *(uint *)((char *)arg1 + 0x5bc) = (u_v10 >> (3 - (byte)i_v12 & 0x1f) | u_v11) >> 0x1d;
        u_v11 = u_v10 << ((byte)i_v12 & 0x1f);
      }
      u_v10 = CONCAT31(CONCAT21(CONCAT11(*pu_v15,pu_v14[0xd]),pu_v14[0xe]),pu_v14[0xf]);
      pu_v15 = pu_v14 + 0x10;
    }
  }
  if ((*(int *)((char *)arg1 + 0x710) == 1) && (*(int *)((char *)arg1 + 0x288) == 0)) {
    if (i_v12 < 0x19) {
      i_v12 = i_v12 + 7;
      u_v7 = u_v11 >> 0x19;
      u_v11 = u_v11 << 7;
      *(uint *)((char *)arg1 + 0x5c0) = u_v7;
    }
    else {
      i_v12 = i_v12 + -0x19;
      if (i_v12 == 0) {
        *(uint *)((char *)arg1 + 0x5c0) = u_v11 >> 0x19;
        u_v11 = u_v10;
      }
      else {
        *(uint *)((char *)arg1 + 0x5c0) = (u_v10 >> (7 - (byte)i_v12 & 0x1f) | u_v11) >> 0x19;
        u_v11 = u_v10 << ((byte)i_v12 & 0x1f);
      }
      u_v10 = CONCAT31(CONCAT21(CONCAT11(*pu_v15,pu_v15[1]),pu_v15[2]),pu_v15[3]);
      pu_v15 = pu_v15 + 4;
    }
  }
  if (i_v12 < 0x1b) {
    i_v12 = i_v12 + 5;
    u_v7 = u_v11 << 5;
    *(uint *)((char *)arg1 + 0x5c4) = u_v11 >> 0x1b;
  }
  else {
    i_v12 = i_v12 + -0x1b;
    if (i_v12 == 0) {
      *(uint *)((char *)arg1 + 0x5c4) = u_v11 >> 0x1b;
    }
    else {
      u_v7 = u_v10 >> (5 - (byte)i_v12 & 0x1f);
      u_v10 = u_v10 << ((byte)i_v12 & 0x1f);
      *(uint *)((char *)arg1 + 0x5c4) = (u_v7 | u_v11) >> 0x1b;
    }
    pu_v14 = pu_v15 + 1;
    u_v4 = *pu_v15;
    pu_v1 = pu_v15 + 2;
    pu_v2 = pu_v15 + 3;
    pu_v15 = pu_v15 + 4;
    u_v7 = u_v10;
    u_v10 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v14),*pu_v1),*pu_v2);
  }
  *(cri_u1 *)((char *)arg1 + 0x774) =
       (&DAT_1431bba60)
       [(ulonglong)*(uint *)((char *)arg1 + 0x328) * 0x20 + (ulonglong)*(uint *)((char *)arg1 + 0x5c4)];
  if ((int)u_v7 < 0) {
    if (i_v12 < 0x1f) {
      i_v12 = i_v12 + 1;
      u_v11 = u_v7 * 2;
      *(uint *)((char *)arg1 + 0x5c8) = u_v7 >> 0x1f;
    }
    else {
      i_v12 = i_v12 + -0x1f;
      if (i_v12 == 0) {
        *(uint *)((char *)arg1 + 0x5c8) = u_v7 >> 0x1f;
      }
      else {
        u_v11 = u_v10 >> (1 - (byte)i_v12 & 0x1f);
        u_v10 = u_v10 << ((byte)i_v12 & 0x1f);
        *(uint *)((char *)arg1 + 0x5c8) = (u_v11 | u_v7) >> 0x1f;
      }
      pu_v14 = pu_v15 + 1;
      u_v4 = *pu_v15;
      pu_v1 = pu_v15 + 2;
      pu_v2 = pu_v15 + 3;
      pu_v15 = pu_v15 + 4;
      u_v11 = u_v10;
      u_v10 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v14),*pu_v1),*pu_v2);
    }
    if (i_v12 < 0x1f) {
      i_v12 = i_v12 + 1;
      u_v7 = u_v11 * 2;
      *(uint *)((char *)arg1 + 0x5cc) = u_v11 >> 0x1f;
    }
    else {
      i_v12 = i_v12 + -0x1f;
      if (i_v12 == 0) {
        *(uint *)((char *)arg1 + 0x5cc) = u_v11 >> 0x1f;
      }
      else {
        u_v7 = u_v10 >> (1 - (byte)i_v12 & 0x1f);
        u_v10 = u_v10 << ((byte)i_v12 & 0x1f);
        *(uint *)((char *)arg1 + 0x5cc) = (u_v7 | u_v11) >> 0x1f;
      }
      pu_v14 = pu_v15 + 1;
      u_v4 = *pu_v15;
      pu_v1 = pu_v15 + 2;
      pu_v2 = pu_v15 + 3;
      pu_v15 = pu_v15 + 4;
      u_v7 = u_v10;
      u_v10 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v14),*pu_v1),*pu_v2);
    }
    if (i_v12 < 0x19) {
      i_v12 = i_v12 + 7;
      *(uint *)((char *)arg1 + 0x5d0) = u_v7 >> 0x19;
      u_v7 = u_v7 << 7;
    }
    else {
      i_v12 = i_v12 + -0x19;
      if (i_v12 == 0) {
        *(uint *)((char *)arg1 + 0x5d0) = u_v7 >> 0x19;
      }
      else {
        u_v11 = u_v10 >> (7 - (byte)i_v12 & 0x1f);
        u_v10 = u_v10 << ((byte)i_v12 & 0x1f);
        *(uint *)((char *)arg1 + 0x5d0) = (u_v11 | u_v7) >> 0x19;
      }
      pu_v14 = pu_v15 + 1;
      u_v4 = *pu_v15;
      pu_v1 = pu_v15 + 2;
      pu_v2 = pu_v15 + 3;
      pu_v15 = pu_v15 + 4;
      u_v7 = u_v10;
      u_v10 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v14),*pu_v1),*pu_v2);
    }
    while ((int)u_v7 < 0) {
      if (i_v12 < 0x1f) {
        i_v12 = i_v12 + 1;
        u_v11 = u_v7 * 2;
        *(uint *)((char *)arg1 + 0x5d4) = u_v7 >> 0x1f;
      }
      else {
        i_v12 = i_v12 + -0x1f;
        if (i_v12 == 0) {
          *(uint *)((char *)arg1 + 0x5d4) = u_v7 >> 0x1f;
        }
        else {
          u_v11 = u_v10 >> (1 - (byte)i_v12 & 0x1f);
          u_v10 = u_v10 << ((byte)i_v12 & 0x1f);
          *(uint *)((char *)arg1 + 0x5d4) = (u_v11 | u_v7) >> 0x1f;
        }
        pu_v14 = pu_v15 + 1;
        u_v4 = *pu_v15;
        pu_v1 = pu_v15 + 2;
        pu_v2 = pu_v15 + 3;
        pu_v15 = pu_v15 + 4;
        u_v11 = u_v10;
        u_v10 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v14),*pu_v1),*pu_v2);
      }
      if (i_v12 < 0x18) {
        i_v12 = i_v12 + 8;
        u_v7 = u_v11 << 8;
        *(uint *)((char *)arg1 + 0x5d8) = u_v11 >> 0x18;
      }
      else {
        i_v12 = i_v12 + -0x18;
        if (i_v12 == 0) {
          *(uint *)((char *)arg1 + 0x5d8) = u_v11 >> 0x18;
        }
        else {
          u_v7 = u_v10 >> (8 - (byte)i_v12 & 0x1f);
          u_v10 = u_v10 << ((byte)i_v12 & 0x1f);
          *(uint *)((char *)arg1 + 0x5d8) = (u_v7 | u_v11) >> 0x18;
        }
        pu_v14 = pu_v15 + 1;
        u_v4 = *pu_v15;
        pu_v1 = pu_v15 + 2;
        pu_v2 = pu_v15 + 3;
        pu_v15 = pu_v15 + 4;
        u_v7 = u_v10;
        u_v10 = CONCAT31(CONCAT21(CONCAT11(u_v4,*pu_v14),*pu_v1),*pu_v2);
      }
    }
  }
  if (i_v12 < 0x1f) {
    u_v13 = i_v12 + 1;
    u_v11 = u_v7 * 2;
    *(uint *)((char *)arg1 + 0x5d4) = u_v7 >> 0x1f;
  }
  else {
    u_v13 = i_v12 - 0x1f;
    if (u_v13 == 0) {
      *(uint *)((char *)arg1 + 0x5d4) = u_v7 >> 0x1f;
      u_v11 = u_v10;
    }
    else {
      *(uint *)((char *)arg1 + 0x5d4) = (u_v10 >> (1 - (byte)u_v13 & 0x1f) | u_v7) >> 0x1f;
      u_v11 = u_v10 << ((byte)u_v13 & 0x1f);
    }
    u_v10 = CONCAT31(CONCAT21(CONCAT11(*pu_v15,pu_v15[1]),pu_v15[2]),pu_v15[3]);
    pu_v15 = pu_v15 + 4;
  }
  u_v7 = *(uint *)((char *)arg1 + 0x5b8) & 0xff;
  *(uint *)((char *)arg1 + 0x6ec) = u_v7;
  if (*(uint *)((char *)arg1 + 0x6c8) < 0xaf1) {
    *(uint *)((char *)arg1 + 0x6f4) = u_v7 - 1;
  }
  else {
    *(uint *)((char *)arg1 + 0x6f4) = *(int *)((char *)arg1 + 0x5bc) * 0x80 + -1 + u_v7;
  }
  i_v12 = *(int *)((char *)arg1 + 0x6cc);
  i_v8 = i_v12 * *(int *)((char *)arg1 + 0x6f4) + -1;
  *(int *)((char *)arg1 + 0x6f0) = i_v8;
  if (((i_v12 == 0) || (*(int *)((char *)arg1 + 0x6d0) == 0)) ||
     (i_v8 < *(int *)((char *)arg1 + 0x6d0) * i_v12)) {
    do {
      u_v7 = u_v13 & 7;
      i_v12 = (((int)((u_v13 - u_v7) + 7) >> 3) - *(int *)((char *)arg1 + 0xd30)) + -8 + (int)pu_v15;
      if (*(int *)((char *)arg1 + 0xd38) - i_v12 < 0x801) {
        FUN_140069020(arg1 + 0xd30,i_v12,arg1 + 0xd30,loc_18);
        (**(cri_code **)(*arg2 + 0x40))(arg2,0,arg1 + 0xd30);
        (**(cri_code **)(*arg2 + 0x38))(arg2,1,loc_18);
        (**(cri_code **)(*arg2 + 0x30))(arg2,1,0x7fffffff,arg1 + 0xd30);
        pu_v14 = (cri_u1 *)(*(ulonglong *)((char *)arg1 + 0xd30) & 0xfffffffffffffffc);
        i_v12 = *(int *)((char *)arg1 + 0xd30) * 8 + (int)pu_v14 * -8;
        u_v13 = i_v12 + u_v7;
        pu_v15 = pu_v14 + 8;
        u_v10 = CONCAT31(CONCAT21(CONCAT11(pu_v14[4],pu_v14[5]),pu_v14[6]),pu_v14[7]);
        if ((int)u_v13 < 0x20) {
          u_v11 = (CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]) <<
                   ((byte)i_v12 & 0x1f)) << (sbyte)u_v7;
        }
        else {
          u_v13 = u_v13 - 0x20;
          u_v11 = u_v10 << ((byte)u_v13 & 0x1f);
          u_v10 = CONCAT31(CONCAT21(CONCAT11(*pu_v15,pu_v14[9]),pu_v14[10]),pu_v14[0xb]);
          pu_v15 = pu_v14 + 0xc;
        }
      }
      *(uint *)((char *)arg1 + 0xc7c) = u_v11;
      *(uint *)((char *)arg1 + 0xc80) = u_v10;
      *(uint *)((char *)arg1 + 0xc78) = u_v13;
      *(cri_u1 **)((char *)arg1 + 0xc88) = pu_v15;
      i_v12 = FUN_14005b8c0(arg1);  // rcx = rbx = arg1 in the exe
      if (i_v12 == 0) {
        (**(cri_code **)((char *)arg1 + 0x1bc8))(arg1);
        FUN_14008a3c0(arg1);
      }
      u_v11 = *(uint *)((char *)arg1 + 0xc7c);
      u_v10 = *(uint *)((char *)arg1 + 0xc80);
      u_v13 = *(uint *)((char *)arg1 + 0xc78);
      pu_v15 = *(cri_u1 **)((char *)arg1 + 0xc88);
      if ((i_v12 != 0) || (*(int *)((char *)arg1 + 0x1bc0) != 0)) break;
      u_v7 = u_v11 >> 9;
      if (9 < (int)u_v13) {
        u_v7 = u_v7 | u_v10 >> (0x29U - (char)u_v13 & 0x1f);
      }
    } while (u_v7 != 0);
    u_v6 = 0;
    if (((*(int *)((char *)arg1 + 0x6cc) != 0) && (*(int *)((char *)arg1 + 0x6d0) != 0)) &&
       (u_v6 = 0,
       *(int *)((char *)arg1 + 0x6f0) != *(int *)((char *)arg1 + 0x6d0) * *(int *)((char *)arg1 + 0x6cc) + -1)) {
      u_v6 = 1;
    }
    *(cri_u4 *)((char *)arg1 + 0x708) = u_v6;
    *(cri_u4 *)((char *)arg1 + 0x70c) = 0;
  }
  else {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  FUN_140069020(arg1 + 0xd30,
                (((int)(u_v13 + 7) >> 3) - *(int *)((char *)arg1 + 0xd30)) + -8 + (int)pu_v15,
                arg1 + 0xd30,loc_18);
  (**(cri_code **)(*arg2 + 0x40))(arg2,0,arg1 + 0xd30);
  (**(cri_code **)(*arg2 + 0x38))(arg2,1,loc_18);
  if (*(int *)((char *)arg1 + 0xb80) != 0) {
    *(int *)((char *)arg1 + 0xd0c) = *(int *)((char *)arg1 + 0xd0c) + 1;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005e5b0
void FUN_14005e5b0(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  void *arg2 = cri_p1;
  int i_v1;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    FUN_14005af30(0,0xff05020c);
    return;
  }
  memcpy(arg2,(void *)((char *)arg1 + 0x1aa8),0x80);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005e600
void FUN_14005e600(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  cri_u4 *arg2 = cri_p1;
  int i_v1;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    FUN_14005af30(0,0xff05020d);
    return;
  }
  *arg2 = *(cri_u4 *)((char *)arg1 + 0x6d4);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005e650
void FUN_14005e650(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, ...)
{
  longlong arg1 = cri_p0;
  int *arg2 = cri_p1;
  cri_u4 *arg3 = cri_p2;
  cri_u4 *arg4 = cri_p3;
  int i_v1;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 == 0) {
    *arg2 = *(int *)((char *)arg1 + 0x6d8) << 0xb;
    *arg3 = *(cri_u4 *)((char *)arg1 + 0x2e4);
    *arg4 = 0xffffffff;
  }
  else {
    FUN_14005af30(0,0xff05020f);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005e6c0
void FUN_14005e6c0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  cri_u4 *arg2 = cri_p1;
  cri_u4 *arg3 = cri_p2;
  int i_v1;
  
  i_v1 = FUN_140047750(arg1);  // the exe passes rcx through (the handle check returns -1 for 0)
  if (i_v1 != 0) {
    FUN_14005af30(0,0xff05020e);
    return;
  }
  *arg2 = *(cri_u4 *)((char *)arg1 + 0x2d0);
  *arg3 = *(cri_u4 *)((char *)arg1 + 0x2d4);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005e720
void FUN_14005e720(cri_any cri_unused, ...)
{
  longlong l_v1;
  short *ps_v2;
  short *ps_v3;
  int i_v4;
  longlong l_v5;
  int i_v6;
  int *pi_v7;
  cri_u1 *pu_v8;
  double d_v9;
  double d_v10;
  double d_v11;
  
  i_v4 = -0x80;
  ps_v2 = CRI_ADDR(DAT_143e44b00);
  do {
    i_v6 = -0x80;
    l_v5 = 0x100;
    ps_v3 = ps_v2;
    do {
      d_v9 = floor((double)i_v6 * 0.813 * 2.0 + (double)i_v4 * 0.392 * 2.0 + 0.5);
      ps_v2 = ps_v3 + 1;
      i_v6 = i_v6 + 1;
      l_v5 = l_v5 + -1;
      *ps_v3 = (short)(longlong)d_v9 + 0x134;
      ps_v3 = ps_v2;
    } while (l_v5 != 0);
    i_v4 = i_v4 + 1;
  } while ((longlong)ps_v2 < ((longlong)&DAT_143e64b00));
  i_v4 = -0x10;
  ps_v2 = CRI_ADDR(DAT_143dc4b02);
  pu_v8 = CRI_ADDR(DAT_143db4ac1);
  pi_v7 = CRI_ADDR(DAT_143d74a84);
  do {
    i_v6 = -0x7f;
    d_v9 = (double)i_v4 * 1.164;
    l_v5 = 0;
    do {
      d_v10 = (double)(i_v6 + -1) * 1.596 + d_v9;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      d_v11 = (double)(i_v6 + -1) * 2.017 + d_v9;
      pi_v7[-1] = ((uint)(longlong)d_v10 & 0xff) << 0x10;
      if (0.0 <= d_v11) {
        if (d_v11 <= 255.0) {
          d_v11 = d_v11 + 0.5;
        }
        else {
          d_v11 = 255.0;
        }
      }
      else {
        d_v11 = 0.0;
      }
      pu_v8[l_v5 + -1] = (char)(longlong)d_v11;
      d_v10 = (double)i_v6 * 1.596 + d_v9;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      d_v11 = (double)i_v6 * 2.017 + d_v9;
      *pi_v7 = ((uint)(longlong)d_v10 & 0xff) << 0x10;
      if (0.0 <= d_v11) {
        if (d_v11 <= 255.0) {
          d_v11 = d_v11 + 0.5;
        }
        else {
          d_v11 = 255.0;
        }
      }
      else {
        d_v11 = 0.0;
      }
      pu_v8[l_v5] = (char)(longlong)d_v11;
      d_v10 = (double)(i_v6 + 1) * 1.596 + d_v9;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      d_v11 = (double)(i_v6 + 1) * 2.017 + d_v9;
      pi_v7[1] = ((uint)(longlong)d_v10 & 0xff) << 0x10;
      if (0.0 <= d_v11) {
        if (d_v11 <= 255.0) {
          d_v11 = d_v11 + 0.5;
        }
        else {
          d_v11 = 255.0;
        }
      }
      else {
        d_v11 = 0.0;
      }
      pu_v8[l_v5 + 1] = (char)(longlong)d_v11;
      d_v10 = (double)(i_v6 + 2) * 1.596 + d_v9;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      d_v11 = (double)(i_v6 + 2) * 2.017 + d_v9;
      pi_v7[2] = ((uint)(longlong)d_v10 & 0xff) << 0x10;
      if (0.0 <= d_v11) {
        if (d_v11 <= 255.0) {
          d_v11 = d_v11 + 0.5;
        }
        else {
          d_v11 = 255.0;
        }
      }
      else {
        d_v11 = 0.0;
      }
      l_v1 = l_v5 + 4;
      pi_v7 = pi_v7 + 4;
      i_v6 = i_v6 + 4;
      pu_v8[l_v5 + 2] = (char)(longlong)d_v11;
      l_v5 = l_v1;
    } while (l_v1 < 0x100);
    d_v9 = d_v9 * 2.0;
    i_v6 = -0x133;
    l_v5 = 0x100;
    ps_v3 = ps_v2;
    do {
      d_v10 = (d_v9 - (double)(i_v6 + -1)) * 0.5;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      ps_v3[-1] = (short)(longlong)d_v10 << 8;
      d_v10 = (d_v9 - (double)i_v6) * 0.5;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      *ps_v3 = (short)(longlong)d_v10 << 8;
      d_v10 = (d_v9 - (double)(i_v6 + 1)) * 0.5;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      ps_v3[1] = (short)(longlong)d_v10 << 8;
      d_v10 = (d_v9 - (double)(i_v6 + 2)) * 0.5;
      if (0.0 <= d_v10) {
        if (d_v10 <= 255.0) {
          d_v10 = d_v10 + 0.5;
        }
        else {
          d_v10 = 255.0;
        }
      }
      else {
        d_v10 = 0.0;
      }
      ps_v2 = ps_v3 + 4;
      i_v6 = i_v6 + 4;
      l_v5 = l_v5 + -1;
      ps_v3[2] = (short)(longlong)d_v10 << 8;
      ps_v3 = ps_v2;
    } while (l_v5 != 0);
    i_v4 = i_v4 + 1;
    pu_v8 = pu_v8 + 0x100;
  } while ((longlong)pi_v7 < ((longlong)&DAT_143db4a84));
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005ebc0
void FUN_14005ebc0(cri_any cri_unused, ...)
{
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005ebd0
void FUN_14005ebd0(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 *arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  byte *pb_v1;
  byte *pb_v2;
  byte b_v3;
  byte b_v4;
  byte b_v5;
  int i_v6;
  int i_v7;
  int i_v8;
  int i_v9;
  uint u_v10;
  uint u_v11;
  uint u_v12;
  byte *pb_v13;
  ulonglong u_v14;
  byte *pb_v15;
  ulonglong u_v16;
  int i_v17;
  uint u_v18;
  byte *pb_v19;
  byte *pb_v20;
  byte *pb_v21;
  uint *pu_v22;
  uint *pu_v23;
  byte *pb_v24;
  byte *pb_v25;
  byte *pb_v26;
  uint u_v27;
  int i_v28;
  longlong l_v29;
  longlong l_v30;
  longlong l_v31;
  uint u_v32;
  uint u_v33;
  byte *pb_v34;
  uint *pu_v35;
  uint *pu_v36;
  ulonglong u_v37;
  uint u_v38;
  byte *pb_v39;
  byte *loc_f8;
  byte *loc_f0;
  byte *loc_e8;
  byte *loc_e0;
  byte *loc_d0;
  byte *loc_c8;
  uint *loc_c0;
  byte *loc_b8;
  byte *loc_b0;
  uint *loc_a0;
  byte *loc_80;
  byte *loc_70;
  ulonglong loc_60;
  
  FUN_1400627f0("cft_c_Ycc420plnToArgb8888Int2smp");
  u_v18 = *(uint *)(arg2 + 1);
  i_v6 = *(int *)((longlong)arg1 + 0x1c);
  pb_v24 = (byte *)*arg1;
  pb_v19 = (byte *)arg1[1];
  pb_v34 = (byte *)arg1[2];
  pu_v23 = (uint *)*arg2;
  u_v38 = u_v18 & 1;
  u_v10 = u_v38 + u_v18 >> 1;
  u_v11 = *(int *)(arg1 + 3) - u_v18;
  u_v27 = *(int *)(arg1 + 3) * 4 - u_v18;
  u_v12 = i_v6 - u_v10;
  i_v7 = *(int *)(arg2 + 2);
  u_v32 = i_v7 + u_v18 * -4;
  i_v17 = 0;
  while( true ) {
    i_v28 = *(int *)((longlong)arg2 + 0xc);
    if (2 < i_v28) {
      i_v28 = 2;
    }
    if (i_v28 <= i_v17) break;
    if (u_v10 - 1 != 0) {
      u_v37 = (ulonglong)(u_v10 - 1);
      pb_v25 = pb_v19;
      pu_v36 = pu_v23;
      pb_v13 = pb_v24;
      pb_v20 = pb_v34;
      do {
        b_v3 = *pb_v13;
        pu_v23 = pu_v36 + 2;
        pb_v24 = pb_v13 + 2;
        pb_v19 = pb_v25 + 1;
        pb_v34 = pb_v20 + 1;
        *pu_v36 = (uint)(ushort)(&DAT_143dc4b00)
                                 [(ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(*pb_v25,*pb_v20)] +
                                  (ulonglong)b_v3 * 0x400] |
                   (&DAT_143d74a80)[CONCAT11(b_v3,*pb_v20)] |
                   (uint)(byte)(&DAT_143db4ac0)[CONCAT11(b_v3,*pb_v25)] | 0xff000000;
        u_v16 = (ulonglong)(uint)((int)(*pb_v19 + 1 + (uint)*pb_v25) >> 1);
        l_v31 = (ulonglong)pb_v13[1] * 0x100;
        u_v14 = (ulonglong)(uint)((int)(*pb_v20 + 1 + (uint)*pb_v34) >> 1);
        u_v37 = u_v37 - 1;
        pu_v36[1] = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)(ushort)(&DAT_143e44b00)[u_v16 * 0x100 + u_v14] +
                                    (ulonglong)pb_v13[1] * 0x400] |
                     (&DAT_143d74a80)[l_v31 + u_v14] |
                     (uint)(byte)(&DAT_143db4ac0)[l_v31 + u_v16] | 0xff000000;
        pb_v25 = pb_v19;
        pu_v36 = pu_v23;
        pb_v13 = pb_v24;
        pb_v20 = pb_v34;
      } while (u_v37 != 0);
    }
    b_v3 = *pb_v24;
    b_v4 = *pb_v19;
    b_v5 = *pb_v34;
    pu_v36 = pu_v23 + 1;
    pb_v25 = pb_v24 + 1;
    *pu_v23 = (uint)(ushort)(&DAT_143dc4b00)
                             [(ulonglong)b_v3 * 0x400 +
                              (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v4,b_v5)]] |
               (&DAT_143d74a80)[CONCAT11(b_v3,b_v5)] |
               (uint)(byte)(&DAT_143db4ac0)[CONCAT11(b_v3,b_v4)] | 0xff000000;
    if (u_v38 == 0) {
      b_v3 = *pb_v25;
      pb_v25 = pb_v24 + 2;
      pu_v36 = pu_v23 + 2;
      pu_v23[1] = (uint)(ushort)(&DAT_143dc4b00)
                                 [(ulonglong)b_v3 * 0x400 +
                                  (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v4,b_v5)]] |
                   (&DAT_143d74a80)[CONCAT11(b_v3,b_v5)] |
                   (uint)(byte)(&DAT_143db4ac0)[CONCAT11(b_v3,b_v4)] | 0xff000000;
    }
    pb_v24 = pb_v25 + u_v11;
    l_v31 = (ulonglong)u_v12 + 1;
    pb_v19 = pb_v19 + l_v31;
    pb_v34 = pb_v34 + l_v31;
    i_v17 = i_v17 + 1;
    pu_v23 = pu_v36 + (u_v32 >> 2);
  }
  pb_v34 = (byte *)arg1[2];
  u_v37 = (ulonglong)(longlong)*(int *)(arg2 + 2) >> 2;
  loc_a0 = pu_v23 + u_v37 * 2;
  pu_v36 = pu_v23 + u_v37;
  loc_c0 = pu_v23 + u_v37 * 3;
  i_v28 = *(int *)(arg1 + 3);
  pb_v25 = (byte *)arg1[1];
  pb_v19 = pb_v24 + i_v28;
  i_v8 = *(int *)((longlong)arg1 + 0x1c);
  loc_d0 = pb_v25 + i_v8;
  loc_b8 = pb_v24 + i_v28 * 2;
  loc_b0 = pb_v24 + i_v28 * 3;
  i_v9 = *(int *)(arg1 + 4);
  loc_c8 = pb_v25 + i_v8 * 2;
  loc_e0 = pb_v25 + i_v8 * 3;
  loc_e8 = pb_v34 + i_v9;
  i_v28 = i_v17 + 3;
  loc_f0 = pb_v34 + i_v9 * 2;
  loc_f8 = pb_v34 + i_v9 * 3;
  if (i_v28 < *(int *)((longlong)arg2 + 0xc)) {
    u_v37 = (ulonglong)(i_v7 * 4 + u_v18 * -4);
    l_v31 = (ulonglong)(i_v6 * 2 - u_v10) + 1;
    do {
      if (u_v10 - 1 != 0) {
        loc_60 = (ulonglong)(u_v10 - 1);
        pb_v13 = pb_v19;
        pu_v22 = pu_v23;
        pb_v20 = pb_v24;
        loc_80 = pb_v25;
        loc_70 = pb_v34;
        do {
          pb_v24 = pb_v20 + 2;
          pu_v23 = pu_v22 + 2;
          u_v33 = (int)((uint)*loc_c8 + (uint)*loc_c8 * 2 + 4 +
                        (uint)*loc_80 + (uint)*loc_80 * 4) >> 3;
          l_v29 = (ulonglong)*pb_v20 * 0x100;
          u_v18 = (int)((uint)*loc_70 + (uint)*loc_70 * 4 + 4 +
                        (uint)*loc_f0 + (uint)*loc_f0 * 2) >> 3;
          pb_v15 = loc_c8 + 1;
          pb_v25 = loc_80 + 1;
          *pu_v22 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)
                                    (ushort)(&DAT_143e44b00)
                                            [(ulonglong)u_v33 * 0x100 + (ulonglong)u_v18] +
                                    (ulonglong)*pb_v20 * 0x400] |
                     (&DAT_143d74a80)[l_v29 + (ulonglong)u_v18] |
                     (uint)(byte)(&DAT_143db4ac0)[l_v29 + (ulonglong)u_v33] | 0xff000000;
          u_v16 = (ulonglong)
                   (((int)((uint)*pb_v25 + (uint)*pb_v25 * 4 + 4 +
                          (uint)*pb_v15 + (uint)*pb_v15 * 2) >> 3) + 1 + u_v33 >> 1);
          pb_v39 = loc_f0 + 1;
          pb_v34 = loc_70 + 1;
          l_v29 = (ulonglong)pb_v20[1] * 0x100;
          u_v14 = (ulonglong)
                   (((int)((uint)loc_f0[1] + (uint)loc_f0[1] * 2 + 4 +
                          (uint)loc_70[1] + (uint)loc_70[1] * 4) >> 3) + 1 + u_v18 >> 1);
          pu_v22[1] = (uint)(ushort)(&DAT_143dc4b00)
                                     [(ulonglong)(ushort)(&DAT_143e44b00)[u_v16 * 0x100 + u_v14] +
                                      (ulonglong)pb_v20[1] * 0x400] |
                       (&DAT_143d74a80)[l_v29 + u_v14] |
                       (uint)(byte)(&DAT_143db4ac0)[l_v29 + u_v16] | 0xff000000;
          l_v29 = (ulonglong)*pb_v13 * 0x100;
          u_v33 = (int)((uint)*loc_d0 * 7 + 4 + (uint)*loc_e0) >> 3;
          pb_v19 = pb_v13 + 2;
          pu_v22 = pu_v36 + 1;
          u_v18 = (int)((uint)*loc_e8 * 7 + 4 + (uint)*loc_f8) >> 3;
          *pu_v36 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)
                                    (ushort)(&DAT_143e44b00)
                                            [(ulonglong)u_v33 * 0x100 + (ulonglong)u_v18] +
                                    (ulonglong)*pb_v13 * 0x400] |
                     (&DAT_143d74a80)[l_v29 + (ulonglong)u_v18] |
                     (uint)(byte)(&DAT_143db4ac0)[l_v29 + (ulonglong)u_v33] | 0xff000000;
          pb_v1 = loc_d0 + 1;
          pb_v2 = loc_e0 + 1;
          pb_v26 = loc_e8 + 1;
          u_v16 = (ulonglong)
                   (((int)((uint)loc_d0[1] * 7 + 4 + (uint)loc_e0[1]) >> 3) + 1 + u_v33 >> 1);
          pb_v21 = loc_f8 + 1;
          l_v29 = (ulonglong)pb_v13[1] * 0x100;
          u_v14 = (ulonglong)
                   (((int)((uint)*pb_v26 * 7 + 4 + (uint)loc_f8[1]) >> 3) + 1 + u_v18 >> 1);
          pu_v36 = pu_v36 + 2;
          *pu_v22 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)(ushort)(&DAT_143e44b00)[u_v16 * 0x100 + u_v14] +
                                    (ulonglong)pb_v13[1] * 0x400] |
                     (&DAT_143d74a80)[l_v29 + u_v14] |
                     (uint)(byte)(&DAT_143db4ac0)[l_v29 + u_v16] | 0xff000000;
          pb_v13 = loc_b8 + 1;
          l_v29 = (ulonglong)*loc_b8 * 0x100;
          u_v33 = (int)((uint)*loc_c8 * 7 + 4 + (uint)*loc_80) >> 3;
          u_v18 = (int)((uint)*loc_f0 * 7 + 4 + (uint)*loc_70) >> 3;
          pu_v22 = loc_a0 + 1;
          *loc_a0 = (uint)(ushort)(&DAT_143dc4b00)
                                    [(ulonglong)
                                     (ushort)(&DAT_143e44b00)
                                             [(ulonglong)u_v33 * 0x100 + (ulonglong)u_v18] +
                                     (ulonglong)*loc_b8 * 0x400] |
                      (&DAT_143d74a80)[l_v29 + (ulonglong)u_v18] |
                      (uint)(byte)(&DAT_143db4ac0)[l_v29 + (ulonglong)u_v33] | 0xff000000;
          loc_b8 = loc_b8 + 2;
          l_v29 = (ulonglong)*pb_v13 * 0x100;
          u_v16 = (ulonglong)
                   (((int)((uint)*pb_v15 * 7 + 4 + (uint)*pb_v25) >> 3) + 1 + u_v33 >> 1);
          u_v14 = (ulonglong)
                   (((int)((uint)*pb_v39 * 7 + 4 + (uint)*pb_v34) >> 3) + 1 + u_v18 >> 1);
          loc_a0 = loc_a0 + 2;
          *pu_v22 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)(ushort)(&DAT_143e44b00)[u_v16 * 0x100 + u_v14] +
                                    (ulonglong)*pb_v13 * 0x400] | (&DAT_143d74a80)[l_v29 + u_v14]
                     | (uint)(byte)(&DAT_143db4ac0)[l_v29 + u_v16] | 0xff000000;
          pb_v13 = loc_b0 + 1;
          u_v33 = (int)((uint)*loc_e0 + (uint)*loc_e0 * 4 + 4 +
                        (uint)*loc_d0 + (uint)*loc_d0 * 2) >> 3;
          l_v29 = (ulonglong)*loc_b0 * 0x100;
          u_v18 = (int)((uint)*loc_e8 + (uint)*loc_e8 * 2 + 4 +
                        (uint)*loc_f8 + (uint)*loc_f8 * 4) >> 3;
          pu_v22 = loc_c0 + 1;
          *loc_c0 = (uint)(ushort)(&DAT_143dc4b00)
                                    [(ulonglong)
                                     (ushort)(&DAT_143e44b00)
                                             [(ulonglong)u_v33 * 0x100 + (ulonglong)u_v18] +
                                     (ulonglong)*loc_b0 * 0x400] |
                      (&DAT_143d74a80)[l_v29 + (ulonglong)u_v18] |
                      (uint)(byte)(&DAT_143db4ac0)[l_v29 + (ulonglong)u_v33] | 0xff000000;
          loc_b0 = loc_b0 + 2;
          u_v16 = (ulonglong)
                   (((int)((uint)*pb_v2 + (uint)*pb_v2 * 4 + 4 + (uint)*pb_v1 + (uint)*pb_v1 * 2
                          ) >> 3) + 1 + u_v33 >> 1);
          l_v29 = (ulonglong)*pb_v13 * 0x100;
          u_v14 = (ulonglong)
                   (((int)((uint)*pb_v21 + (uint)*pb_v21 * 4 + 4 +
                          (uint)*pb_v26 + (uint)*pb_v26 * 2) >> 3) + 1 + u_v18 >> 1);
          loc_c0 = loc_c0 + 2;
          *pu_v22 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)(ushort)(&DAT_143e44b00)[u_v16 * 0x100 + u_v14] +
                                    (ulonglong)*pb_v13 * 0x400] | (&DAT_143d74a80)[l_v29 + u_v14]
                     | (uint)(byte)(&DAT_143db4ac0)[l_v29 + u_v16] | 0xff000000;
          loc_60 = loc_60 - 1;
          pb_v13 = pb_v19;
          pu_v22 = pu_v23;
          pb_v20 = pb_v24;
          loc_f8 = pb_v21;
          loc_f0 = pb_v39;
          loc_e8 = pb_v26;
          loc_e0 = pb_v2;
          loc_d0 = pb_v1;
          loc_c8 = pb_v15;
          loc_80 = pb_v25;
          loc_70 = pb_v34;
        } while (loc_60 != 0);
      }
      pu_v22 = pu_v23 + 1;
      pb_v13 = pb_v24 + 1;
      u_v18 = (int)((uint)*loc_c8 + (uint)*loc_c8 * 2 + 4 + (uint)*pb_v25 + (uint)*pb_v25 * 4
                    ) >> 3;
      u_v14 = (ulonglong)
               (uint)((int)((uint)*pb_v34 + (uint)*pb_v34 * 4 + 4 +
                           (uint)*loc_f0 + (uint)*loc_f0 * 2) >> 3);
      l_v29 = (ulonglong)u_v18 * 0x100 + u_v14;
      l_v30 = (ulonglong)*pb_v24 * 0x100;
      *pu_v23 = (uint)(ushort)(&DAT_143dc4b00)
                               [(ulonglong)*pb_v24 * 0x400 +
                                (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                 (&DAT_143d74a80)[u_v14 + l_v30] |
                 (uint)(byte)(&DAT_143db4ac0)[l_v30 + (ulonglong)u_v18] | 0xff000000;
      if (u_v38 == 0) {
        b_v3 = *pb_v13;
        pb_v13 = pb_v24 + 2;
        l_v30 = (ulonglong)b_v3 * 0x100;
        pu_v22 = pu_v23 + 2;
        pu_v23[1] = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)b_v3 * 0x400 +
                                    (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                     (&DAT_143d74a80)[u_v14 + l_v30] |
                     (uint)(byte)(&DAT_143db4ac0)[l_v30 + (ulonglong)u_v18] | 0xff000000;
      }
      pu_v35 = pu_v36 + 1;
      pb_v20 = pb_v19 + 1;
      u_v14 = (ulonglong)(uint)((int)((uint)*loc_d0 * 7 + 4 + (uint)*loc_e0) >> 3);
      u_v16 = (ulonglong)(uint)((int)((uint)*loc_e8 * 7 + 4 + (uint)*loc_f8) >> 3);
      l_v29 = u_v14 * 0x100 + u_v16;
      l_v30 = (ulonglong)*pb_v19 * 0x100;
      *pu_v36 = (uint)(ushort)(&DAT_143dc4b00)
                               [(ulonglong)*pb_v19 * 0x400 +
                                (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                 (&DAT_143d74a80)[u_v16 + l_v30] | (uint)(byte)(&DAT_143db4ac0)[l_v30 + u_v14] |
                 0xff000000;
      if (u_v38 == 0) {
        b_v3 = *pb_v20;
        pb_v20 = pb_v19 + 2;
        l_v30 = (ulonglong)b_v3 * 0x100;
        pu_v35 = pu_v36 + 2;
        pu_v36[1] = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)b_v3 * 0x400 +
                                    (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                     (&DAT_143d74a80)[u_v16 + l_v30] |
                     (uint)(byte)(&DAT_143db4ac0)[l_v30 + u_v14] | 0xff000000;
      }
      pu_v23 = loc_a0 + 1;
      pb_v24 = loc_b8 + 1;
      u_v14 = (ulonglong)(uint)((int)((uint)*loc_c8 * 7 + 4 + (uint)*pb_v25) >> 3);
      u_v16 = (ulonglong)(uint)((int)((uint)*loc_f0 * 7 + 4 + (uint)*pb_v34) >> 3);
      l_v29 = u_v14 * 0x100 + u_v16;
      l_v30 = (ulonglong)*loc_b8 * 0x100;
      *loc_a0 = (uint)(ushort)(&DAT_143dc4b00)
                                [(ulonglong)*loc_b8 * 0x400 +
                                 (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                  (&DAT_143d74a80)[u_v16 + l_v30] | (uint)(byte)(&DAT_143db4ac0)[l_v30 + u_v14]
                  | 0xff000000;
      if (u_v38 == 0) {
        b_v3 = *pb_v24;
        pb_v24 = loc_b8 + 2;
        l_v30 = (ulonglong)b_v3 * 0x100;
        pu_v23 = loc_a0 + 2;
        loc_a0[1] = (uint)(ushort)(&DAT_143dc4b00)
                                    [(ulonglong)b_v3 * 0x400 +
                                     (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                      (&DAT_143d74a80)[u_v16 + l_v30] |
                      (uint)(byte)(&DAT_143db4ac0)[l_v30 + u_v14] | 0xff000000;
      }
      pb_v19 = loc_b0 + 1;
      u_v18 = (int)((uint)*loc_e0 + (uint)*loc_e0 * 4 + 4 +
                    (uint)*loc_d0 + (uint)*loc_d0 * 2) >> 3;
      u_v14 = (ulonglong)
               (uint)((int)((uint)*loc_e8 + (uint)*loc_e8 * 2 + 4 +
                           (uint)*loc_f8 + (uint)*loc_f8 * 4) >> 3);
      l_v29 = (ulonglong)u_v18 * 0x100 + u_v14;
      l_v30 = (ulonglong)*loc_b0 * 0x100;
      pu_v36 = loc_c0 + 1;
      *loc_c0 = (uint)(ushort)(&DAT_143dc4b00)
                                [(ulonglong)*loc_b0 * 0x400 +
                                 (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                  (&DAT_143d74a80)[u_v14 + l_v30] |
                  (uint)(byte)(&DAT_143db4ac0)[(ulonglong)u_v18 + l_v30] | 0xff000000;
      if (u_v38 == 0) {
        b_v3 = *pb_v19;
        pb_v19 = loc_b0 + 2;
        l_v30 = (ulonglong)b_v3 * 0x100;
        pu_v36 = loc_c0 + 2;
        loc_c0[1] = (uint)(ushort)(&DAT_143dc4b00)
                                    [(ulonglong)b_v3 * 0x400 +
                                     (ulonglong)(ushort)(&DAT_143e44b00)[l_v29]] |
                      (&DAT_143d74a80)[u_v14 + l_v30] |
                      (uint)(byte)(&DAT_143db4ac0)[(ulonglong)u_v18 + l_v30] | 0xff000000;
      }
      loc_b8 = pb_v24 + u_v27;
      loc_b0 = pb_v19 + u_v27;
      pb_v24 = pb_v13 + u_v27;
      pb_v19 = pb_v20 + u_v27;
      i_v28 = i_v28 + 4;
      loc_f0 = loc_f0 + l_v31;
      loc_d0 = loc_d0 + l_v31;
      loc_e0 = loc_e0 + l_v31;
      loc_e8 = loc_e8 + l_v31;
      loc_f8 = loc_f8 + l_v31;
      pb_v25 = pb_v25 + l_v31;
      loc_c8 = loc_c8 + l_v31;
      pb_v34 = pb_v34 + l_v31;
      loc_c0 = (uint *)((longlong)pu_v36 + u_v37);
      loc_a0 = (uint *)((longlong)pu_v23 + u_v37);
      pu_v23 = (uint *)((longlong)pu_v22 + u_v37);
      pu_v36 = (uint *)((longlong)pu_v35 + u_v37);
      i_v17 = i_v17 + 4;
    } while (i_v28 < *(int *)((longlong)arg2 + 0xc));
  }
  if (i_v17 < *(int *)((longlong)arg2 + 0xc)) {
    l_v31 = (ulonglong)u_v12 + 1;
    do {
      if (u_v10 - 1 != 0) {
        u_v37 = (ulonglong)(u_v10 - 1);
        pu_v36 = pu_v23;
        pb_v19 = pb_v24;
        pb_v13 = pb_v34;
        pb_v20 = pb_v25;
        do {
          b_v3 = *pb_v19;
          pu_v23 = pu_v36 + 2;
          pb_v24 = pb_v19 + 2;
          pb_v25 = pb_v20 + 1;
          pb_v34 = pb_v13 + 1;
          *pu_v36 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(*pb_v20,*pb_v13)]
                                    + (ulonglong)b_v3 * 0x400] |
                     (&DAT_143d74a80)[CONCAT11(b_v3,*pb_v13)] |
                     (uint)(byte)(&DAT_143db4ac0)[CONCAT11(b_v3,*pb_v20)] | 0xff000000;
          u_v16 = (ulonglong)(uint)((int)(*pb_v25 + 1 + (uint)*pb_v20) >> 1);
          l_v29 = (ulonglong)pb_v19[1] * 0x100;
          u_v14 = (ulonglong)(uint)((int)(*pb_v13 + 1 + (uint)*pb_v34) >> 1);
          u_v37 = u_v37 - 1;
          pu_v36[1] = (uint)(ushort)(&DAT_143dc4b00)
                                     [(ulonglong)(ushort)(&DAT_143e44b00)[u_v16 * 0x100 + u_v14] +
                                      (ulonglong)pb_v19[1] * 0x400] |
                       (&DAT_143d74a80)[l_v29 + u_v14] |
                       (uint)(byte)(&DAT_143db4ac0)[l_v29 + u_v16] | 0xff000000;
          pu_v36 = pu_v23;
          pb_v19 = pb_v24;
          pb_v13 = pb_v34;
          pb_v20 = pb_v25;
        } while (u_v37 != 0);
      }
      b_v3 = *pb_v24;
      b_v4 = *pb_v25;
      b_v5 = *pb_v34;
      pu_v36 = pu_v23 + 1;
      pb_v19 = pb_v24 + 1;
      *pu_v23 = (uint)(ushort)(&DAT_143dc4b00)
                               [(ulonglong)b_v3 * 0x400 +
                                (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v4,b_v5)]] |
                 (&DAT_143d74a80)[CONCAT11(b_v3,b_v5)] |
                 (uint)(byte)(&DAT_143db4ac0)[CONCAT11(b_v3,b_v4)] | 0xff000000;
      if (u_v38 == 0) {
        b_v3 = *pb_v19;
        pb_v19 = pb_v24 + 2;
        pu_v36 = pu_v23 + 2;
        pu_v23[1] = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)b_v3 * 0x400 +
                                    (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v4,b_v5)]] |
                     (&DAT_143d74a80)[CONCAT11(b_v3,b_v5)] |
                     (uint)(byte)(&DAT_143db4ac0)[CONCAT11(b_v3,b_v4)] | 0xff000000;
      }
      pu_v23 = (uint *)((longlong)pu_v36 + ((ulonglong)u_v32 & 0xfffffffffffffffc));
      i_v17 = i_v17 + 1;
      pb_v25 = pb_v25 + l_v31;
      pb_v34 = pb_v34 + l_v31;
      pb_v24 = pb_v19 + u_v11;
    } while (i_v17 < *(int *)((longlong)arg2 + 0xc));
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x14005fe40
void FUN_14005fe40(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 *arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  byte *pb_v1;
  byte b_v2;
  byte b_v3;
  byte b_v4;
  ushort u_v5;
  int i_v6;
  int i_v7;
  uint u_v8;
  uint u_v9;
  ulonglong u_v10;
  int i_v11;
  byte *pb_v12;
  cri_u1 *pu_v13;
  byte *pb_v14;
  byte *pb_v15;
  byte *pb_v16;
  byte *pb_v17;
  cri_u1 *pu_v18;
  cri_u1 *pu_v19;
  byte *pb_v20;
  cri_u1 *pu_v21;
  uint u_v22;
  uint u_v23;
  longlong l_v24;
  longlong l_v25;
  longlong l_v26;
  uint u_v27;
  cri_u1 *pu_v28;
  uint u_v29;
  uint u_v30;
  cri_u1 *pu_v31;
  byte *pb_v32;
  byte *pb_v33;
  ulonglong u_v34;
  byte *pb_v35;
  uint u_v36;
  byte *pb_v37;
  uint u_v38;
  byte *pb_v39;
  int local_res20;
  byte *loc_f0;
  byte *loc_e8;
  byte *loc_e0;
  byte *loc_d8;
  byte *loc_c8;
  cri_u1 *loc_c0;
  byte *loc_b8;
  byte *loc_b0;
  byte *loc_a0;
  byte *loc_98;
  byte *loc_90;
  cri_u1 *loc_88;
  ulonglong loc_60;
  
  FUN_1400627f0("cft_c_Ycc420plnToRgb888Int2smp");
  u_v29 = *(uint *)(arg2 + 1);
  i_v6 = *(int *)((longlong)arg1 + 0x1c);
  pb_v15 = (byte *)*arg1;
  pb_v12 = (byte *)arg1[1];
  pb_v33 = (byte *)arg1[2];
  pu_v18 = (cri_u1 *)*arg2;
  u_v36 = u_v29 & 1;
  u_v38 = *(int *)(arg1 + 3) - u_v29;
  u_v22 = *(int *)(arg1 + 3) * 4 - u_v29;
  u_v27 = u_v36 + u_v29 >> 1;
  u_v8 = i_v6 - u_v27;
  u_v9 = *(int *)(arg2 + 2) * 4 + u_v29 * -3;
  u_v29 = *(int *)(arg2 + 2) + u_v29 * -3;
  local_res20 = 0;
  while( true ) {
    i_v11 = *(int *)((longlong)arg2 + 0xc);
    if (2 < i_v11) {
      i_v11 = 2;
    }
    if (i_v11 <= local_res20) break;
    if (u_v27 - 1 != 0) {
      u_v34 = (ulonglong)(u_v27 - 1);
      pb_v16 = pb_v12;
      pb_v14 = pb_v15;
      pu_v19 = pu_v18;
      pb_v32 = pb_v33;
      do {
        b_v2 = *pb_v32;
        b_v3 = *pb_v14;
        u_v5 = (&DAT_143e44b00)[CONCAT11(*pb_v16,b_v2)];
        pu_v18 = pu_v19 + 6;
        *pu_v19 = (&DAT_143db4ac0)[CONCAT11(b_v3,*pb_v16)];
        pb_v15 = pb_v14 + 2;
        pu_v19[1] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v5) * 2 + 1);
        pb_v12 = pb_v16 + 1;
        pb_v33 = pb_v32 + 1;
        pu_v19[2] = *(cri_u1 *)
                      ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
        b_v2 = pb_v14[1];
        u_v23 = (int)(*pb_v12 + 1 + (uint)*pb_v16) >> 1;
        u_v10 = (ulonglong)(uint)((int)(*pb_v32 + 1 + (uint)*pb_v33) >> 1);
        l_v25 = (ulonglong)b_v2 * 0x100;
        u_v5 = (&DAT_143e44b00)[(ulonglong)u_v23 * 0x100 + u_v10];
        u_v34 = u_v34 - 1;
        pu_v19[3] = (&DAT_143db4ac0)[l_v25 + (ulonglong)u_v23];
        pu_v19[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
        pu_v19[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v25 + u_v10) * 4 + 2);
        pb_v16 = pb_v12;
        pb_v14 = pb_v15;
        pu_v19 = pu_v18;
        pb_v32 = pb_v33;
      } while (u_v34 != 0);
    }
    b_v2 = *pb_v12;
    b_v3 = *pb_v15;
    b_v4 = *pb_v33;
    u_v5 = (&DAT_143e44b00)[CONCAT11(b_v2,b_v4)];
    *pu_v18 = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v2)];
    pu_v19 = pu_v18 + 3;
    pb_v16 = pb_v15 + 1;
    pu_v18[1] = *(cri_u1 *)
                  ((longlong)&DAT_143dc4b00 + ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v5) * 2 + 1)
    ;
    pu_v18[2] = *(cri_u1 *)
                  ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v4) * 4 + 2);
    if (u_v36 == 0) {
      b_v3 = *pb_v16;
      u_v5 = (&DAT_143e44b00)[CONCAT11(b_v2,b_v4)];
      pb_v16 = pb_v15 + 2;
      pu_v19 = pu_v18 + 6;
      pu_v18[3] = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v2)];
      pu_v18[4] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v5) * 2 + 1);
      pu_v18[5] = *(cri_u1 *)
                    ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v4) * 4 + 2);
    }
    pb_v15 = pb_v16 + u_v38;
    l_v25 = (ulonglong)u_v8 + 1;
    pb_v12 = pb_v12 + l_v25;
    pb_v33 = pb_v33 + l_v25;
    pu_v18 = pu_v19 + u_v29;
    local_res20 = local_res20 + 1;
  }
  i_v11 = *(int *)(arg2 + 2);
  loc_98 = (byte *)arg1[1];
  loc_90 = (byte *)arg1[2];
  pu_v19 = pu_v18 + i_v11;
  i_v7 = *(int *)(arg1 + 3);
  pu_v28 = pu_v18 + i_v11 * 2;
  pb_v12 = pb_v15 + i_v7;
  pu_v31 = pu_v18 + i_v11 * 3;
  i_v11 = *(int *)((longlong)arg1 + 0x1c);
  loc_c8 = loc_98 + i_v11;
  loc_b8 = pb_v15 + i_v7 * 2;
  loc_b0 = pb_v15 + i_v7 * 3;
  i_v7 = *(int *)(arg1 + 4);
  loc_a0 = loc_98 + i_v11 * 2;
  loc_d8 = loc_98 + i_v11 * 3;
  loc_e8 = loc_90 + i_v7;
  loc_f0 = loc_90 + i_v7 * 2;
  i_v11 = local_res20 + 3;
  loc_e0 = loc_90 + i_v7 * 3;
  if (i_v11 < *(int *)((longlong)arg2 + 0xc)) {
    l_v25 = (ulonglong)(i_v6 * 2 - u_v27) + 1;
    do {
      if (u_v27 - 1 != 0) {
        loc_60 = (ulonglong)(u_v27 - 1);
        pu_v21 = pu_v19;
        pb_v33 = pb_v15;
        pu_v13 = pu_v18;
        pb_v16 = pb_v12;
        loc_c0 = pu_v28;
        loc_88 = pu_v31;
        do {
          b_v2 = *pb_v33;
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v30 = (int)((uint)*loc_98 + (uint)*loc_98 * 4 + 4 +
                        (uint)*loc_a0 + (uint)*loc_a0 * 2) >> 3;
          pb_v15 = pb_v33 + 2;
          u_v23 = (int)((uint)*loc_f0 + (uint)*loc_f0 * 2 + 4 +
                        (uint)*loc_90 + (uint)*loc_90 * 4) >> 3;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v30 * 0x100 + (ulonglong)u_v23];
          pb_v39 = loc_98 + 1;
          *pu_v13 = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v30];
          pu_v13[1] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          pb_v14 = loc_a0 + 1;
          pu_v13[2] = *(cri_u1 *)
                        ((longlong)&DAT_143d74a80 + (l_v26 + (ulonglong)u_v23) * 4 + 2);
          b_v2 = pb_v33[1];
          pb_v37 = loc_f0 + 1;
          u_v30 = ((int)((uint)*pb_v39 + (uint)*pb_v39 * 4 + 4 +
                         (uint)*pb_v14 + (uint)*pb_v14 * 2) >> 3) + 1 + u_v30 >> 1;
          pb_v35 = loc_90 + 1;
          u_v34 = (ulonglong)
                   (((int)((uint)loc_90[1] + (uint)loc_90[1] * 4 + 4 +
                          (uint)*pb_v37 + (uint)*pb_v37 * 2) >> 3) + 1 + u_v23 >> 1);
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v30 * 0x100 + u_v34];
          pu_v18 = pu_v13 + 6;
          pu_v13[3] = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v30];
          pu_v13[4] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          pu_v13[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v26 + u_v34) * 4 + 2);
          b_v2 = *pb_v16;
          l_v26 = (ulonglong)b_v2 * 0x100;
          pb_v12 = pb_v16 + 2;
          u_v23 = (int)((uint)*loc_c8 * 7 + 4 + (uint)*loc_d8) >> 3;
          u_v30 = (int)((uint)*loc_e8 * 7 + 4 + (uint)*loc_e0) >> 3;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v23 * 0x100 + (ulonglong)u_v30];
          *pu_v21 = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v23];
          pu_v21[1] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          pu_v21[2] = *(cri_u1 *)
                        ((longlong)&DAT_143d74a80 + (l_v26 + (ulonglong)u_v30) * 4 + 2);
          b_v2 = pb_v16[1];
          pb_v32 = loc_c8 + 1;
          pb_v1 = loc_d8 + 1;
          u_v23 = ((int)((uint)loc_c8[1] * 7 + 4 + (uint)loc_d8[1]) >> 3) + 1 + u_v23 >> 1;
          pb_v20 = loc_e8 + 1;
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v34 = (ulonglong)
                   (((int)((uint)loc_e8[1] * 7 + 4 + (uint)loc_e0[1]) >> 3) + 1 + u_v30 >> 1);
          pb_v17 = loc_e0 + 1;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v23 * 0x100 + u_v34];
          pu_v19 = pu_v21 + 6;
          pu_v21[3] = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v23];
          pu_v21[4] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          pu_v21[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v26 + u_v34) * 4 + 2);
          b_v2 = *loc_b8;
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v23 = (int)((uint)*loc_a0 * 7 + 4 + (uint)*loc_98) >> 3;
          u_v30 = (int)((uint)*loc_f0 * 7 + 4 + (uint)*loc_90) >> 3;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v23 * 0x100 + (ulonglong)u_v30];
          *loc_c0 = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v23];
          loc_c0[1] = *(cri_u1 *)
                         ((longlong)&DAT_143dc4b00 +
                         ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          loc_c0[2] = *(cri_u1 *)
                         ((longlong)&DAT_143d74a80 + (l_v26 + (ulonglong)u_v30) * 4 + 2);
          b_v2 = loc_b8[1];
          loc_b8 = loc_b8 + 2;
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v23 = ((int)((uint)*pb_v14 * 7 + 4 + (uint)*pb_v39) >> 3) + 1 + u_v23 >> 1;
          u_v34 = (ulonglong)
                   (((int)((uint)*pb_v37 * 7 + 4 + (uint)*pb_v35) >> 3) + 1 + u_v30 >> 1);
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v23 * 0x100 + u_v34];
          pu_v28 = loc_c0 + 6;
          loc_c0[3] = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v23];
          loc_c0[4] = *(cri_u1 *)
                         ((longlong)&DAT_143dc4b00 +
                         ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          loc_c0[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v26 + u_v34) * 4 + 2);
          b_v2 = *loc_b0;
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v30 = (int)((uint)*loc_d8 + (uint)*loc_d8 * 4 + 4 +
                        (uint)*loc_c8 + (uint)*loc_c8 * 2) >> 3;
          u_v23 = (int)((uint)*loc_e8 + (uint)*loc_e8 * 2 + 4 +
                        (uint)*loc_e0 + (uint)*loc_e0 * 4) >> 3;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v30 * 0x100 + (ulonglong)u_v23];
          *loc_88 = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v30];
          loc_88[1] = *(cri_u1 *)
                         ((longlong)&DAT_143dc4b00 +
                         ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          loc_88[2] = *(cri_u1 *)
                         ((longlong)&DAT_143d74a80 + (l_v26 + (ulonglong)u_v23) * 4 + 2);
          b_v2 = loc_b0[1];
          loc_b0 = loc_b0 + 2;
          u_v30 = ((int)((uint)*pb_v32 + (uint)*pb_v32 * 2 + 4 +
                         (uint)*pb_v1 + (uint)*pb_v1 * 4) >> 3) + 1 + u_v30 >> 1;
          u_v34 = (ulonglong)
                   (((int)((uint)*pb_v17 + (uint)*pb_v17 * 4 + 4 +
                          (uint)*pb_v20 + (uint)*pb_v20 * 2) >> 3) + 1 + u_v23 >> 1);
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v30 * 0x100 + u_v34];
          pu_v31 = loc_88 + 6;
          loc_88[3] = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v30];
          loc_88[4] = *(cri_u1 *)
                         ((longlong)&DAT_143dc4b00 +
                         ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          loc_88[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v26 + u_v34) * 4 + 2);
          loc_60 = loc_60 - 1;
          pu_v21 = pu_v19;
          pb_v33 = pb_v15;
          pu_v13 = pu_v18;
          pb_v16 = pb_v12;
          loc_f0 = pb_v37;
          loc_e8 = pb_v20;
          loc_e0 = pb_v17;
          loc_d8 = pb_v1;
          loc_c8 = pb_v32;
          loc_c0 = pu_v28;
          loc_a0 = pb_v14;
          loc_98 = pb_v39;
          loc_90 = pb_v35;
          loc_88 = pu_v31;
        } while (loc_60 != 0);
      }
      b_v2 = *pb_v15;
      pu_v21 = pu_v18 + 3;
      pb_v33 = pb_v15 + 1;
      u_v23 = (int)((uint)*loc_98 + (uint)*loc_98 * 4 + 4 +
                    (uint)*loc_a0 + (uint)*loc_a0 * 2) >> 3;
      u_v34 = (ulonglong)
               (uint)((int)((uint)*loc_f0 + (uint)*loc_f0 * 2 + 4 +
                           (uint)*loc_90 + (uint)*loc_90 * 4) >> 3);
      l_v26 = (ulonglong)u_v23 * 0x100 + u_v34;
      l_v24 = (ulonglong)b_v2 * 0x100;
      u_v5 = (&DAT_143e44b00)[l_v26];
      *pu_v18 = (&DAT_143db4ac0)[l_v24 + (ulonglong)u_v23];
      pu_v18[1] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
      pu_v18[2] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v34 + l_v24) * 4 + 2);
      if (u_v36 == 0) {
        b_v2 = *pb_v33;
        u_v5 = (&DAT_143e44b00)[l_v26];
        l_v26 = (ulonglong)b_v2 * 0x100;
        pb_v33 = pb_v15 + 2;
        *pu_v21 = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v23];
        pu_v18[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
        pu_v21 = pu_v18 + 6;
        pu_v18[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v34 + l_v26) * 4 + 2);
      }
      b_v2 = *pb_v12;
      pu_v13 = pu_v19 + 3;
      pb_v16 = pb_v12 + 1;
      u_v34 = (ulonglong)(uint)((int)((uint)*loc_c8 * 7 + 4 + (uint)*loc_d8) >> 3);
      u_v10 = (ulonglong)(uint)((int)((uint)*loc_e8 * 7 + 4 + (uint)*loc_e0) >> 3);
      l_v26 = u_v34 * 0x100 + u_v10;
      l_v24 = (ulonglong)b_v2 * 0x100;
      u_v5 = (&DAT_143e44b00)[l_v26];
      *pu_v19 = (&DAT_143db4ac0)[l_v24 + u_v34];
      pu_v19[1] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
      pu_v19[2] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v10 + l_v24) * 4 + 2);
      if (u_v36 == 0) {
        b_v2 = *pb_v16;
        u_v5 = (&DAT_143e44b00)[l_v26];
        l_v26 = (ulonglong)b_v2 * 0x100;
        pb_v16 = pb_v12 + 2;
        *pu_v13 = (&DAT_143db4ac0)[l_v26 + u_v34];
        pu_v19[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
        pu_v13 = pu_v19 + 6;
        pu_v19[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v10 + l_v26) * 4 + 2);
      }
      b_v2 = *loc_b8;
      pu_v18 = pu_v28 + 3;
      pb_v15 = loc_b8 + 1;
      u_v34 = (ulonglong)(uint)((int)((uint)*loc_a0 * 7 + 4 + (uint)*loc_98) >> 3);
      u_v10 = (ulonglong)(uint)((int)((uint)*loc_f0 * 7 + 4 + (uint)*loc_90) >> 3);
      l_v26 = u_v34 * 0x100 + u_v10;
      l_v24 = (ulonglong)b_v2 * 0x100;
      u_v5 = (&DAT_143e44b00)[l_v26];
      *pu_v28 = (&DAT_143db4ac0)[l_v24 + u_v34];
      pu_v28[1] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
      pu_v28[2] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v10 + l_v24) * 4 + 2);
      if (u_v36 == 0) {
        b_v2 = *pb_v15;
        u_v5 = (&DAT_143e44b00)[l_v26];
        l_v26 = (ulonglong)b_v2 * 0x100;
        pb_v15 = loc_b8 + 2;
        *pu_v18 = (&DAT_143db4ac0)[l_v26 + u_v34];
        pu_v28[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
        pu_v18 = pu_v28 + 6;
        pu_v28[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v10 + l_v26) * 4 + 2);
      }
      b_v2 = *loc_b0;
      pu_v19 = pu_v31 + 3;
      pb_v12 = loc_b0 + 1;
      u_v23 = (int)((uint)*loc_d8 + (uint)*loc_d8 * 4 + 4 +
                    (uint)*loc_c8 + (uint)*loc_c8 * 2) >> 3;
      u_v34 = (ulonglong)
               (uint)((int)((uint)*loc_e8 + (uint)*loc_e8 * 2 + 4 +
                           (uint)*loc_e0 + (uint)*loc_e0 * 4) >> 3);
      l_v26 = (ulonglong)u_v23 * 0x100 + u_v34;
      l_v24 = (ulonglong)b_v2 * 0x100;
      u_v5 = (&DAT_143e44b00)[l_v26];
      *pu_v31 = (&DAT_143db4ac0)[l_v24 + (ulonglong)u_v23];
      pu_v31[1] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
      pu_v31[2] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v34 + l_v24) * 4 + 2);
      if (u_v36 == 0) {
        b_v2 = *pb_v12;
        u_v5 = (&DAT_143e44b00)[l_v26];
        l_v26 = (ulonglong)b_v2 * 0x100;
        pb_v12 = loc_b0 + 2;
        *pu_v19 = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v23];
        pu_v31[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
        pu_v19 = pu_v31 + 6;
        pu_v31[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (u_v34 + l_v26) * 4 + 2);
      }
      loc_b8 = pb_v15 + u_v22;
      loc_b0 = pb_v12 + u_v22;
      pb_v15 = pb_v33 + u_v22;
      pb_v12 = pb_v16 + u_v22;
      loc_c8 = loc_c8 + l_v25;
      loc_d8 = loc_d8 + l_v25;
      loc_e8 = loc_e8 + l_v25;
      loc_f0 = loc_f0 + l_v25;
      loc_e0 = loc_e0 + l_v25;
      loc_98 = loc_98 + l_v25;
      loc_a0 = loc_a0 + l_v25;
      loc_90 = loc_90 + l_v25;
      pu_v28 = pu_v18 + u_v9;
      pu_v31 = pu_v19 + u_v9;
      i_v11 = i_v11 + 4;
      pu_v18 = pu_v21 + u_v9;
      pu_v19 = pu_v13 + u_v9;
      local_res20 = local_res20 + 4;
    } while (i_v11 < *(int *)((longlong)arg2 + 0xc));
  }
  if (local_res20 < *(int *)((longlong)arg2 + 0xc)) {
    l_v25 = (ulonglong)u_v8 + 1;
    do {
      if (u_v27 - 1 != 0) {
        u_v34 = (ulonglong)(u_v27 - 1);
        pb_v12 = pb_v15;
        pu_v19 = pu_v18;
        pb_v33 = loc_90;
        pb_v16 = loc_98;
        do {
          b_v2 = *pb_v33;
          b_v3 = *pb_v12;
          u_v5 = (&DAT_143e44b00)[CONCAT11(*pb_v16,b_v2)];
          pu_v18 = pu_v19 + 6;
          *pu_v19 = (&DAT_143db4ac0)[CONCAT11(b_v3,*pb_v16)];
          pb_v15 = pb_v12 + 2;
          pu_v19[1] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          loc_98 = pb_v16 + 1;
          loc_90 = pb_v33 + 1;
          pu_v19[2] = *(cri_u1 *)
                        ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
          b_v2 = pb_v12[1];
          u_v8 = (int)(*loc_98 + 1 + (uint)*pb_v16) >> 1;
          u_v10 = (ulonglong)(uint)((int)(*pb_v33 + 1 + (uint)*loc_90) >> 1);
          l_v26 = (ulonglong)b_v2 * 0x100;
          u_v5 = (&DAT_143e44b00)[(ulonglong)u_v8 * 0x100 + u_v10];
          u_v34 = u_v34 - 1;
          pu_v19[3] = (&DAT_143db4ac0)[l_v26 + (ulonglong)u_v8];
          pu_v19[4] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v5) * 2 + 1);
          pu_v19[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v26 + u_v10) * 4 + 2);
          pb_v12 = pb_v15;
          pu_v19 = pu_v18;
          pb_v33 = loc_90;
          pb_v16 = loc_98;
        } while (u_v34 != 0);
      }
      b_v2 = *loc_98;
      b_v3 = *pb_v15;
      b_v4 = *loc_90;
      u_v5 = (&DAT_143e44b00)[CONCAT11(b_v2,b_v4)];
      *pu_v18 = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v2)];
      pu_v19 = pu_v18 + 3;
      pb_v12 = pb_v15 + 1;
      pu_v18[1] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v5) * 2 + 1);
      pu_v18[2] = *(cri_u1 *)
                    ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v4) * 4 + 2);
      if (u_v36 == 0) {
        b_v3 = *pb_v12;
        u_v5 = (&DAT_143e44b00)[CONCAT11(b_v2,b_v4)];
        pb_v12 = pb_v15 + 2;
        pu_v19 = pu_v18 + 6;
        pu_v18[3] = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v2)];
        pu_v18[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v5) * 2 + 1);
        pu_v18[5] = *(cri_u1 *)
                      ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v4) * 4 + 2);
      }
      local_res20 = local_res20 + 1;
      loc_98 = loc_98 + l_v25;
      pb_v15 = pb_v12 + u_v38;
      loc_90 = loc_90 + l_v25;
      pu_v18 = pu_v19 + u_v29;
    } while (local_res20 < *(int *)((longlong)arg2 + 0xc));
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140061080
void FUN_140061080(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 *arg1 = cri_p0;
  longlong *arg2 = cri_p1;
  byte b_v1;
  byte b_v2;
  byte b_v3;
  int i_v4;
  ushort u_v5;
  longlong l_v6;
  uint u_v7;
  uint u_v8;
  uint u_v9;
  uint *pu_v10;
  uint *pu_v11;
  byte *pb_v12;
  byte *pb_v13;
  ulonglong u_v14;
  uint u_v15;
  longlong l_v16;
  ulonglong u_v17;
  longlong l_v18;
  ulonglong u_v19;
  byte *pb_v20;
  byte *pb_v21;
  uint *pu_v22;
  uint *pu_v23;
  byte *pb_v24;
  byte *pb_v25;
  byte *pb_v26;
  int local_res8;
  ulonglong loc_60;
  
  FUN_1400627f0("cft_c_Ycc420plnToArgb8888Prg");
  i_v4 = (int)arg2[2];
  pu_v11 = (uint *)*arg2;
  pb_v12 = (byte *)*arg1;
  pb_v25 = (byte *)arg1[1];
  pb_v26 = (byte *)arg1[2];
  pb_v20 = pb_v12 + *(int *)(arg1 + 3);
  u_v15 = *(uint *)(arg2 + 1);
  pu_v23 = pu_v11 + ((int)(i_v4 + (i_v4 >> 0x1f & 3U)) >> 2);
  u_v8 = u_v15 & 1;
  u_v9 = *(int *)(arg1 + 3) * 2 - u_v15;
  u_v7 = u_v8 + u_v15 >> 1;
  if (1 < *(int *)((longlong)arg2 + 0xc)) {
    l_v6 = (ulonglong)(*(int *)((longlong)arg1 + 0x1c) - u_v7) + 1;
    u_v14 = (ulonglong)((i_v4 + u_v15 * -2) * 2) & 0xfffffffffffffffc;
    local_res8 = 1;
    do {
      if (u_v7 - 1 != 0) {
        loc_60 = (ulonglong)(u_v7 - 1);
        pu_v10 = pu_v11;
        pb_v13 = pb_v12;
        pb_v21 = pb_v20;
        pu_v22 = pu_v23;
        pb_v24 = pb_v25;
        do {
          b_v1 = *pb_v24;
          b_v2 = *pb_v26;
          l_v16 = (ulonglong)*pb_v13 * 0x100;
          pb_v25 = pb_v24 + 1;
          pb_v12 = pb_v13 + 2;
          pu_v11 = pu_v10 + 2;
          pb_v20 = pb_v21 + 2;
          *pu_v10 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)*pb_v13 * 0x400 +
                                    (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v1,b_v2)]] |
                     (&DAT_143d74a80)[(ulonglong)b_v2 + l_v16] |
                     (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v16] | 0xff000000;
          l_v16 = (ulonglong)*pb_v21 * 0x100;
          *pu_v22 = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)*pb_v21 * 0x400 +
                                    (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v1,b_v2)]] |
                     (&DAT_143d74a80)[(ulonglong)b_v2 + l_v16] |
                     (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v16] | 0xff000000;
          u_v15 = (int)(*pb_v25 + 1 + (uint)*pb_v24) >> 1;
          l_v16 = (ulonglong)pb_v13[1] * 0x100;
          u_v17 = (ulonglong)(uint)((int)(*pb_v26 + 1 + (uint)pb_v26[1]) >> 1);
          l_v18 = (ulonglong)u_v15 * 0x100 + u_v17;
          pu_v10[1] = (uint)(ushort)(&DAT_143dc4b00)
                                     [(ulonglong)pb_v13[1] * 0x400 +
                                      (ulonglong)(ushort)(&DAT_143e44b00)[l_v18]] |
                       (&DAT_143d74a80)[u_v17 + l_v16] |
                       (uint)(byte)(&DAT_143db4ac0)[(ulonglong)u_v15 + l_v16] | 0xff000000;
          l_v16 = (ulonglong)pb_v21[1] * 0x100;
          pu_v23 = pu_v22 + 2;
          pb_v26 = pb_v26 + 1;
          loc_60 = loc_60 - 1;
          pu_v22[1] = (uint)(ushort)(&DAT_143dc4b00)
                                     [(ulonglong)pb_v21[1] * 0x400 +
                                      (ulonglong)(ushort)(&DAT_143e44b00)[l_v18]] |
                       (&DAT_143d74a80)[u_v17 + l_v16] |
                       (uint)(byte)(&DAT_143db4ac0)[(ulonglong)u_v15 + l_v16] | 0xff000000;
          pu_v10 = pu_v11;
          pb_v13 = pb_v12;
          pb_v21 = pb_v20;
          pu_v22 = pu_v23;
          pb_v24 = pb_v25;
        } while (loc_60 != 0);
      }
      b_v1 = *pb_v25;
      b_v2 = *pb_v26;
      l_v16 = (ulonglong)*pb_v12 * 0x100;
      u_v5 = CONCAT11(b_v1,b_v2);
      pu_v22 = pu_v23 + 1;
      pb_v13 = pb_v12 + 1;
      pu_v10 = pu_v11 + 1;
      pb_v21 = pb_v20 + 1;
      *pu_v11 = (uint)(ushort)(&DAT_143dc4b00)
                               [(ulonglong)*pb_v12 * 0x400 +
                                (ulonglong)(ushort)(&DAT_143e44b00)[u_v5]] |
                 (&DAT_143d74a80)[(ulonglong)b_v2 + l_v16] |
                 (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v16] | 0xff000000;
      l_v16 = (ulonglong)*pb_v20 * 0x100;
      *pu_v23 = (uint)(ushort)(&DAT_143dc4b00)
                               [(ulonglong)*pb_v20 * 0x400 +
                                (ulonglong)(ushort)(&DAT_143e44b00)[u_v5]] |
                 (&DAT_143d74a80)[(ulonglong)b_v2 + l_v16] |
                 (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v16] | 0xff000000;
      if (u_v8 == 0) {
        b_v3 = *pb_v13;
        pb_v13 = pb_v12 + 2;
        l_v16 = (ulonglong)b_v3 * 0x100;
        pu_v10 = pu_v11 + 2;
        pb_v21 = pb_v20 + 2;
        pu_v11[1] = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)b_v3 * 0x400 +
                                    (ulonglong)(ushort)(&DAT_143e44b00)[u_v5]] |
                     (&DAT_143d74a80)[(ulonglong)b_v2 + l_v16] |
                     (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v16] | 0xff000000;
        l_v16 = (ulonglong)pb_v20[1] * 0x100;
        pu_v22 = pu_v23 + 2;
        pu_v23[1] = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)pb_v20[1] * 0x400 +
                                    (ulonglong)(ushort)(&DAT_143e44b00)[u_v5]] |
                     (&DAT_143d74a80)[(ulonglong)b_v2 + l_v16] |
                     (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v16] | 0xff000000;
      }
      pb_v12 = pb_v13 + u_v9;
      pb_v20 = pb_v21 + u_v9;
      local_res8 = local_res8 + 2;
      pb_v25 = pb_v25 + l_v6;
      pb_v26 = pb_v26 + l_v6;
      pu_v11 = (uint *)((longlong)pu_v10 + u_v14);
      pu_v23 = (uint *)((longlong)pu_v22 + u_v14);
    } while (local_res8 < *(int *)((longlong)arg2 + 0xc));
  }
  if ((*(byte *)((longlong)arg2 + 0xc) & 1) != 0) {
    if (u_v7 - 1 != 0) {
      u_v14 = (ulonglong)(u_v7 - 1);
      pu_v23 = pu_v11;
      pb_v20 = pb_v12;
      pb_v13 = pb_v25;
      pb_v21 = pb_v26;
      do {
        l_v6 = (ulonglong)*pb_v20 * 0x100;
        pu_v11 = pu_v23 + 2;
        pb_v12 = pb_v20 + 2;
        pb_v25 = pb_v13 + 1;
        pb_v26 = pb_v21 + 1;
        *pu_v23 = (uint)(ushort)(&DAT_143dc4b00)
                                 [(ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(*pb_v13,*pb_v21)] +
                                  (ulonglong)*pb_v20 * 0x400] |
                   (&DAT_143d74a80)[(ulonglong)*pb_v21 + l_v6] |
                   (uint)(byte)(&DAT_143db4ac0)[(ulonglong)*pb_v13 + l_v6] | 0xff000000;
        u_v19 = (ulonglong)(uint)((int)(*pb_v25 + 1 + (uint)*pb_v13) >> 1);
        u_v17 = (ulonglong)(uint)((int)(*pb_v21 + 1 + (uint)*pb_v26) >> 1);
        l_v6 = (ulonglong)pb_v20[1] * 0x100;
        u_v14 = u_v14 - 1;
        pu_v23[1] = (uint)(ushort)(&DAT_143dc4b00)
                                   [(ulonglong)(ushort)(&DAT_143e44b00)[u_v19 * 0x100 + u_v17] +
                                    (ulonglong)pb_v20[1] * 0x400] |
                     (&DAT_143d74a80)[u_v17 + l_v6] | (uint)(byte)(&DAT_143db4ac0)[u_v19 + l_v6]
                     | 0xff000000;
        pu_v23 = pu_v11;
        pb_v20 = pb_v12;
        pb_v13 = pb_v25;
        pb_v21 = pb_v26;
      } while (u_v14 != 0);
    }
    b_v1 = *pb_v25;
    b_v2 = *pb_v26;
    l_v6 = (ulonglong)*pb_v12 * 0x100;
    *pu_v11 = (uint)(ushort)(&DAT_143dc4b00)
                             [(ulonglong)*pb_v12 * 0x400 +
                              (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v1,b_v2)]] |
               (&DAT_143d74a80)[(ulonglong)b_v2 + l_v6] |
               (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v6] | 0xff000000;
    if (u_v8 == 0) {
      l_v6 = (ulonglong)pb_v12[1] * 0x100;
      pu_v11[1] = (uint)(ushort)(&DAT_143dc4b00)
                                 [(ulonglong)pb_v12[1] * 0x400 +
                                  (ulonglong)(ushort)(&DAT_143e44b00)[CONCAT11(b_v1,b_v2)]] |
                   (&DAT_143d74a80)[(ulonglong)b_v2 + l_v6] |
                   (uint)(byte)(&DAT_143db4ac0)[(ulonglong)b_v1 + l_v6] | 0xff000000;
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400616c0
void FUN_1400616c0(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 *arg1 = cri_p0;
  cri_u8 *arg2 = cri_p1;
  byte b_v1;
  byte b_v2;
  byte b_v3;
  ushort u_v4;
  ushort u_v5;
  longlong l_v6;
  uint u_v7;
  uint u_v8;
  cri_u1 *pu_v9;
  cri_u1 *pu_v10;
  cri_u1 *pu_v11;
  cri_u1 *pu_v12;
  ulonglong u_v13;
  uint u_v14;
  longlong l_v15;
  uint u_v16;
  longlong l_v17;
  uint u_v18;
  ulonglong u_v19;
  byte *pb_v20;
  byte *pb_v21;
  byte *pb_v22;
  byte *pb_v23;
  byte *pb_v24;
  byte *pb_v25;
  byte *pb_v26;
  int local_res8;
  ulonglong loc_58;
  
  FUN_1400627f0("cft_c_Ycc420plnToRgb888Prg");
  u_v8 = *(uint *)(arg2 + 1);
  pb_v21 = (byte *)*arg1;
  pu_v12 = (cri_u1 *)*arg2;
  pb_v24 = (byte *)arg1[1];
  pb_v26 = (byte *)arg1[2];
  pb_v23 = pb_v21 + *(int *)(arg1 + 3);
  pu_v10 = pu_v12 + *(int *)(arg2 + 2);
  u_v7 = u_v8 & 1;
  u_v18 = u_v7 + u_v8 >> 1;
  u_v16 = *(int *)(arg2 + 2) * 2 + u_v8 * -3;
  u_v8 = *(int *)(arg1 + 3) * 2 - u_v8;
  if (1 < *(int *)((longlong)arg2 + 0xc)) {
    l_v6 = (ulonglong)(*(int *)((longlong)arg1 + 0x1c) - u_v18) + 1;
    local_res8 = 1;
    do {
      loc_58 = (ulonglong)(u_v18 - 1);
      pu_v9 = pu_v10;
      pu_v11 = pu_v12;
      pb_v20 = pb_v21;
      pb_v22 = pb_v23;
      pb_v25 = pb_v24;
      if (u_v18 - 1 != 0) {
        do {
          b_v1 = *pb_v24;
          b_v2 = *pb_v21;
          b_v3 = *pb_v26;
          pb_v25 = pb_v24 + 1;
          u_v4 = (&DAT_143e44b00)[CONCAT11(b_v1,b_v3)];
          *pu_v12 = (&DAT_143db4ac0)[CONCAT11(b_v2,b_v1)];
          pb_v20 = pb_v21 + 2;
          pu_v11 = pu_v12 + 6;
          pb_v22 = pb_v23 + 2;
          pu_v12[1] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v4) * 2 + 1);
          pu_v12[2] = *(cri_u1 *)
                        ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v2,b_v3) * 4 + 2);
          u_v4 = (&DAT_143e44b00)[CONCAT11(b_v1,b_v3)];
          b_v2 = *pb_v23;
          *pu_v10 = (&DAT_143db4ac0)[CONCAT11(b_v2,b_v1)];
          pu_v10[1] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v4) * 2 + 1);
          pu_v10[2] = *(cri_u1 *)
                        ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v2,b_v3) * 4 + 2);
          b_v1 = pb_v21[1];
          u_v14 = (int)(*pb_v24 + 1 + (uint)*pb_v25) >> 1;
          l_v15 = (ulonglong)b_v1 * 0x100;
          u_v13 = (ulonglong)(uint)((int)(*pb_v26 + 1 + (uint)pb_v26[1]) >> 1);
          l_v17 = (ulonglong)u_v14 * 0x100 + u_v13;
          u_v4 = (&DAT_143e44b00)[l_v17];
          pu_v12[3] = (&DAT_143db4ac0)[l_v15 + (ulonglong)u_v14];
          pu_v12[4] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v1 * 0x400 + (ulonglong)u_v4) * 2 + 1);
          pu_v12[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v15 + u_v13) * 4 + 2);
          b_v1 = pb_v23[1];
          u_v4 = (&DAT_143e44b00)[l_v17];
          l_v15 = (ulonglong)b_v1 * 0x100;
          pu_v10[3] = (&DAT_143db4ac0)[l_v15 + (ulonglong)u_v14];
          pu_v10[4] = *(cri_u1 *)
                        ((longlong)&DAT_143dc4b00 +
                        ((ulonglong)b_v1 * 0x400 + (ulonglong)u_v4) * 2 + 1);
          pu_v9 = pu_v10 + 6;
          pb_v26 = pb_v26 + 1;
          loc_58 = loc_58 - 1;
          pu_v10[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v15 + u_v13) * 4 + 2);
          pu_v10 = pu_v9;
          pu_v12 = pu_v11;
          pb_v21 = pb_v20;
          pb_v23 = pb_v22;
          pb_v24 = pb_v25;
        } while (loc_58 != 0);
      }
      b_v1 = *pb_v25;
      b_v2 = *pb_v26;
      b_v3 = *pb_v20;
      u_v5 = CONCAT11(b_v1,b_v2);
      u_v4 = (&DAT_143e44b00)[u_v5];
      *pu_v11 = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v1)];
      pu_v11[1] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v4) * 2 + 1);
      pu_v10 = pu_v9 + 3;
      pb_v21 = pb_v20 + 1;
      pu_v12 = pu_v11 + 3;
      pu_v11[2] = *(cri_u1 *)
                    ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
      b_v3 = *pb_v22;
      u_v4 = (&DAT_143e44b00)[u_v5];
      pb_v23 = pb_v22 + 1;
      *pu_v9 = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v1)];
      pu_v9[1] = *(cri_u1 *)
                   ((longlong)&DAT_143dc4b00 + ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v4) * 2 + 1
                   );
      pu_v9[2] = *(cri_u1 *)
                   ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
      if (u_v7 == 0) {
        b_v3 = *pb_v21;
        u_v4 = (&DAT_143e44b00)[u_v5];
        pb_v21 = pb_v20 + 2;
        pu_v12 = pu_v11 + 6;
        pb_v23 = pb_v22 + 2;
        pu_v11[3] = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v1)];
        pu_v11[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v4) * 2 + 1);
        pu_v11[5] = *(cri_u1 *)
                      ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
        b_v3 = pb_v22[1];
        u_v4 = (&DAT_143e44b00)[u_v5];
        pu_v10 = pu_v9 + 6;
        pu_v9[3] = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v1)];
        pu_v9[4] = *(cri_u1 *)
                     ((longlong)&DAT_143dc4b00 +
                     ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v4) * 2 + 1);
        pu_v9[5] = *(cri_u1 *)
                     ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
      }
      local_res8 = local_res8 + 2;
      pb_v21 = pb_v21 + u_v8;
      pb_v23 = pb_v23 + u_v8;
      pu_v12 = pu_v12 + u_v16;
      pu_v10 = pu_v10 + u_v16;
      pb_v24 = pb_v25 + l_v6;
      pb_v26 = pb_v26 + l_v6;
    } while (local_res8 < *(int *)((longlong)arg2 + 0xc));
  }
  if ((*(byte *)((longlong)arg2 + 0xc) & 1) != 0) {
    if (u_v18 - 1 != 0) {
      u_v13 = (ulonglong)(u_v18 - 1);
      pu_v10 = pu_v12;
      pb_v23 = pb_v21;
      pb_v25 = pb_v24;
      pb_v20 = pb_v26;
      do {
        b_v1 = *pb_v20;
        b_v2 = *pb_v23;
        u_v4 = (&DAT_143e44b00)[CONCAT11(*pb_v25,b_v1)];
        pu_v12 = pu_v10 + 6;
        *pu_v10 = (&DAT_143db4ac0)[CONCAT11(b_v2,*pb_v25)];
        pb_v21 = pb_v23 + 2;
        pu_v10[1] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v2 * 0x400 + (ulonglong)u_v4) * 2 + 1);
        pb_v24 = pb_v25 + 1;
        pb_v26 = pb_v20 + 1;
        pu_v10[2] = *(cri_u1 *)
                      ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v2,b_v1) * 4 + 2);
        b_v1 = pb_v23[1];
        u_v8 = (int)(*pb_v25 + 1 + (uint)*pb_v24) >> 1;
        u_v19 = (ulonglong)(uint)((int)(*pb_v20 + 1 + (uint)*pb_v26) >> 1);
        l_v6 = (ulonglong)b_v1 * 0x100;
        u_v4 = (&DAT_143e44b00)[(ulonglong)u_v8 * 0x100 + u_v19];
        u_v13 = u_v13 - 1;
        pu_v10[3] = (&DAT_143db4ac0)[l_v6 + (ulonglong)u_v8];
        pu_v10[4] = *(cri_u1 *)
                      ((longlong)&DAT_143dc4b00 +
                      ((ulonglong)b_v1 * 0x400 + (ulonglong)u_v4) * 2 + 1);
        pu_v10[5] = *(cri_u1 *)((longlong)&DAT_143d74a80 + (l_v6 + u_v19) * 4 + 2);
        pu_v10 = pu_v12;
        pb_v23 = pb_v21;
        pb_v25 = pb_v24;
        pb_v20 = pb_v26;
      } while (u_v13 != 0);
    }
    b_v1 = *pb_v24;
    b_v2 = *pb_v26;
    b_v3 = *pb_v21;
    u_v4 = (&DAT_143e44b00)[CONCAT11(b_v1,b_v2)];
    *pu_v12 = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v1)];
    pu_v12[1] = *(cri_u1 *)
                  ((longlong)&DAT_143dc4b00 + ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v4) * 2 + 1)
    ;
    pu_v12[2] = *(cri_u1 *)
                  ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
    if (u_v7 == 0) {
      b_v3 = pb_v21[1];
      u_v4 = (&DAT_143e44b00)[CONCAT11(b_v1,b_v2)];
      pu_v12[3] = (&DAT_143db4ac0)[CONCAT11(b_v3,b_v1)];
      pu_v12[4] = *(cri_u1 *)
                    ((longlong)&DAT_143dc4b00 +
                    ((ulonglong)b_v3 * 0x400 + (ulonglong)u_v4) * 2 + 1);
      pu_v12[5] = *(cri_u1 *)
                    ((longlong)&DAT_143d74a80 + (ulonglong)CONCAT11(b_v3,b_v2) * 4 + 2);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140061ce0
void FUN_140061ce0(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 *arg1 = cri_p0;
  longlong *arg2 = cri_p1;
  byte *pb_v1;
  byte *pb_v2;
  byte *pb_v3;
  byte b_v4;
  byte b_v5;
  byte b_v6;
  int i_v7;
  longlong l_v8;
  uint u_v9;
  uint u_v10;
  uint u_v11;
  int i_v12;
  byte *pb_v13;
  uint *pu_v14;
  uint *pu_v15;
  uint *pu_v16;
  uint u_v17;
  int i_v18;
  byte *pb_v19;
  uint u_v20;
  byte *pb_v21;
  byte *pb_v22;
  uint *pu_v23;
  uint u_v24;
  ulonglong u_v25;
  byte *pb_v26;
  byte *pb_v27;
  byte *pb_v28;
  byte *pb_v29;
  uint u_v30;
  uint *pu_v31;
  uint *pu_v32;
  uint u_v33;
  uint *pu_v34;
  uint *pu_v35;
  byte *loc_d8;
  byte *loc_d0;
  byte *loc_c8;
  byte *loc_c0;
  byte *loc_b8;
  byte *loc_b0;
  byte *loc_80;
  ulonglong loc_78;
  
  FUN_1400627f0("cft_c_Ycc420plnToYcc422pix2Int2smp");
  l_v8 = arg2[2];
  pb_v28 = (byte *)*arg1;
  pb_v26 = (byte *)arg1[1];
  pb_v22 = (byte *)arg1[2];
  pu_v16 = (uint *)*arg2;
  u_v20 = *(uint *)(arg2 + 1) & 1;
  u_v24 = (int)arg2[1] + u_v20;
  u_v33 = *(int *)(arg1 + 3) - u_v24;
  u_v30 = u_v24 >> 1;
  u_v9 = *(int *)((longlong)arg1 + 0x1c) - u_v30;
  u_v17 = (int)l_v8 + u_v24 * -2;
  u_v10 = *(int *)(arg1 + 3) * 4 - u_v24;
  u_v11 = *(int *)((longlong)arg1 + 0x1c) * 2 - u_v30;
  i_v18 = 0;
  while( true ) {
    i_v12 = *(int *)((longlong)arg2 + 0xc);
    if (2 < *(int *)((longlong)arg2 + 0xc)) {
      i_v12 = 2;
    }
    if (i_v12 <= i_v18) break;
    if (u_v24 >> 1 != 0) {
      u_v25 = (ulonglong)u_v30;
      pu_v35 = pu_v16;
      do {
        b_v4 = *pb_v22;
        b_v5 = *pb_v26;
        pb_v21 = pb_v28 + 1;
        b_v6 = *pb_v28;
        pu_v16 = pu_v35 + 1;
        pb_v26 = pb_v26 + 1;
        pb_v22 = pb_v22 + 1;
        pb_v28 = pb_v28 + 2;
        u_v25 = u_v25 - 1;
        *pu_v35 = ((uint)b_v4 << 0x10 | (uint)b_v5) << 8 | (uint)*pb_v21 << 0x10 | (uint)b_v6;
        pu_v35 = pu_v16;
      } while (u_v25 != 0);
    }
    if (u_v20 != 0) {
      *(char *)((longlong)pu_v16 + -2) = (char)pu_v16[-1];
    }
    pb_v26 = pb_v26 + u_v9;
    pb_v22 = pb_v22 + u_v9;
    pb_v28 = pb_v28 + u_v33;
    i_v18 = i_v18 + 1;
    pu_v16 = pu_v16 + (u_v17 >> 2);
  }
  pb_v22 = (byte *)arg1[1];
  pb_v21 = (byte *)arg1[2];
  i_v12 = (int)((int)arg2[2] + ((int)arg2[2] >> 0x1f & 3U)) >> 2;
  pu_v35 = pu_v16 + i_v12;
  pu_v23 = pu_v16 + i_v12 * 2;
  pu_v14 = pu_v16 + i_v12 * 3;
  i_v12 = *(int *)(arg1 + 3);
  pb_v26 = pb_v28 + i_v12;
  pb_v27 = pb_v28 + i_v12 * 2;
  loc_80 = pb_v28 + i_v12 * 3;
  i_v12 = *(int *)((longlong)arg1 + 0x1c);
  loc_b8 = pb_v22 + i_v12;
  loc_d0 = pb_v22 + i_v12 * 2;
  i_v7 = *(int *)(arg1 + 4);
  loc_d8 = pb_v22 + i_v12 * 3;
  loc_c0 = pb_v21 + i_v7;
  loc_b0 = pb_v21 + i_v7 * 2;
  loc_c8 = pb_v21 + i_v7 * 3;
  i_v12 = i_v18 + 3;
  if (i_v12 < *(int *)((longlong)arg2 + 0xc)) {
    u_v25 = (ulonglong)(((int)l_v8 * 2 - u_v24) * 2) & 0xfffffffffffffffc;
    do {
      if (u_v30 != 0) {
        loc_78 = (ulonglong)u_v30;
        pu_v15 = pu_v16;
        pb_v19 = pb_v27;
        pb_v29 = pb_v26;
        pu_v31 = pu_v23;
        pu_v32 = pu_v14;
        pu_v34 = pu_v35;
        do {
          pb_v1 = pb_v28 + 1;
          b_v4 = *pb_v28;
          pb_v28 = pb_v28 + 2;
          pu_v16 = pu_v15 + 1;
          pb_v26 = pb_v29 + 2;
          pu_v35 = pu_v34 + 1;
          pb_v27 = pb_v19 + 2;
          pu_v23 = pu_v31 + 1;
          *pu_v15 = (((int)((uint)*pb_v21 + (uint)*pb_v21 * 4 + 4 +
                            (uint)*loc_b0 + (uint)*loc_b0 * 2) >> 3) << 0x10 |
                     (int)((uint)*loc_d0 + (uint)*loc_d0 * 2 + 4 +
                          (uint)*pb_v22 + (uint)*pb_v22 * 4) >> 3) << 8 | (uint)*pb_v1 << 0x10 |
                     (uint)b_v4;
          *pu_v34 = (((int)((uint)*loc_c0 * 7 + 4 + (uint)*loc_c8) >> 3) << 0x10 |
                     (int)((uint)*loc_b8 * 7 + 4 + (uint)*loc_d8) >> 3) << 8 |
                     (uint)pb_v29[1] << 0x10 | (uint)*pb_v29;
          pb_v13 = loc_80 + 2;
          *pu_v31 = (((int)((uint)*loc_b0 * 7 + 4 + (uint)*pb_v21) >> 3) << 0x10 |
                     (int)((uint)*loc_d0 * 7 + 4 + (uint)*pb_v22) >> 3) << 8 |
                     (uint)pb_v19[1] << 0x10 | (uint)*pb_v19;
          loc_d0 = loc_d0 + 1;
          loc_b0 = loc_b0 + 1;
          b_v4 = *loc_c8;
          loc_c8 = loc_c8 + 1;
          pu_v14 = pu_v32 + 1;
          pb_v1 = loc_c0 + 1;
          pb_v22 = pb_v22 + 1;
          pb_v21 = pb_v21 + 1;
          pb_v2 = loc_d8 + 1;
          pb_v3 = loc_b8 + 1;
          loc_78 = loc_78 - 1;
          *pu_v32 = (((int)((uint)b_v4 + (uint)b_v4 * 4 + 4 +
                            (uint)*loc_c0 + (uint)*loc_c0 * 2) >> 3) << 0x10 |
                     (int)((uint)*loc_d8 + (uint)*loc_d8 * 4 + 4 +
                          (uint)*loc_b8 + (uint)*loc_b8 * 2) >> 3) << 8 |
                     (uint)loc_80[1] << 0x10 | (uint)*loc_80;
          pu_v15 = pu_v16;
          pb_v19 = pb_v27;
          pb_v29 = pb_v26;
          pu_v31 = pu_v23;
          pu_v32 = pu_v14;
          pu_v34 = pu_v35;
          loc_d8 = pb_v2;
          loc_c0 = pb_v1;
          loc_b8 = pb_v3;
          loc_80 = pb_v13;
        } while (loc_78 != 0);
      }
      if (u_v20 != 0) {
        *(char *)((longlong)pu_v16 + -2) = (char)pu_v16[-1];
        *(char *)((longlong)pu_v35 + -2) = (char)pu_v35[-1];
        *(char *)((longlong)pu_v23 + -2) = (char)pu_v23[-1];
        *(char *)((longlong)pu_v14 + -2) = (char)pu_v14[-1];
      }
      i_v12 = i_v12 + 4;
      loc_80 = loc_80 + u_v10;
      loc_b8 = loc_b8 + u_v11;
      loc_d0 = loc_d0 + u_v11;
      loc_d8 = loc_d8 + u_v11;
      loc_c0 = loc_c0 + u_v11;
      loc_b0 = loc_b0 + u_v11;
      loc_c8 = loc_c8 + u_v11;
      pb_v26 = pb_v26 + u_v10;
      pb_v27 = pb_v27 + u_v10;
      pu_v23 = (uint *)((longlong)pu_v23 + u_v25);
      pu_v14 = (uint *)((longlong)pu_v14 + u_v25);
      i_v18 = i_v18 + 4;
      pb_v28 = pb_v28 + u_v10;
      pb_v22 = pb_v22 + u_v11;
      pb_v21 = pb_v21 + u_v11;
      pu_v16 = (uint *)((longlong)pu_v16 + u_v25);
      pu_v35 = (uint *)((longlong)pu_v35 + u_v25);
    } while (i_v12 < *(int *)((longlong)arg2 + 0xc));
  }
  if (i_v18 < *(int *)((longlong)arg2 + 0xc)) {
    do {
      if (u_v30 != 0) {
        u_v25 = (ulonglong)u_v30;
        pu_v35 = pu_v16;
        do {
          b_v4 = *pb_v21;
          b_v5 = *pb_v22;
          pb_v26 = pb_v28 + 1;
          b_v6 = *pb_v28;
          pu_v16 = pu_v35 + 1;
          pb_v22 = pb_v22 + 1;
          pb_v21 = pb_v21 + 1;
          pb_v28 = pb_v28 + 2;
          u_v25 = u_v25 - 1;
          *pu_v35 = ((uint)b_v4 << 0x10 | (uint)b_v5) << 8 | (uint)*pb_v26 << 0x10 | (uint)b_v6
          ;
          pu_v35 = pu_v16;
        } while (u_v25 != 0);
      }
      if (u_v20 != 0) {
        *(char *)((longlong)pu_v16 + -2) = (char)pu_v16[-1];
      }
      i_v18 = i_v18 + 1;
      pb_v28 = pb_v28 + u_v33;
      pb_v22 = pb_v22 + u_v9;
      pb_v21 = pb_v21 + u_v9;
      pu_v16 = (uint *)((longlong)pu_v16 + ((ulonglong)u_v17 & 0xfffffffffffffffc));
    } while (i_v18 < *(int *)((longlong)arg2 + 0xc));
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400622f0
void FUN_1400622f0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  longlong arg2 = cri_p1;
  longlong arg3 = cri_p2;
  cri_u8 u_v1;
  int i_v2;
  // Two plane descriptors passed by address: dst {3 ptrs, 3 ints} at rsp+0x40, src {ptr, 3 ints} at rsp+0x20 in the exe.
  __declspec(align(16)) cri_u8 frame_[0x48];
  cri_u8 &loc_58 = *(cri_u8 *)(frame_ + 0);
  uint &loc_50 = *(uint *)(frame_ + 8);
  uint &loc_4c = *(uint *)(frame_ + 12);
  uint &loc_48 = *(uint *)(frame_ + 16);
  cri_u8 &loc_38 = *(cri_u8 *)(frame_ + 32);
  cri_u8 &loc_30 = *(cri_u8 *)(frame_ + 40);
  cri_u8 &loc_28 = *(cri_u8 *)(frame_ + 48);
  cri_u4 &loc_20 = *(cri_u4 *)(frame_ + 56);
  cri_u4 &loc_1c = *(cri_u4 *)(frame_ + 60);
  cri_u4 &loc_18 = *(cri_u4 *)(frame_ + 64);
  
  loc_38 = *(cri_u8 *)(arg1 + 8);
  u_v1 = *(cri_u8 *)(arg3 + 8);
  loc_30 = *(cri_u8 *)((char *)arg1 + 0x20);
  loc_28 = *(cri_u8 *)((char *)arg1 + 0x38);
  loc_20 = *(cri_u4 *)((char *)arg1 + 0x18);
  loc_1c = *(cri_u4 *)((char *)arg1 + 0x30);
  loc_18 = *(cri_u4 *)((char *)arg1 + 0x48);
  loc_58 = *(cri_u8 *)(arg2 + 8);
  loc_50 = *(uint *)((char *)arg2 + 0x10);
  loc_4c = *(uint *)((char *)arg2 + 0x14);
  loc_48 = *(uint *)((char *)arg2 + 0x18);
  i_v2 = FUN_140062820();
  if (i_v2 != 0) {
    FUN_1400927c0(&loc_38,&loc_58,&DAT_143a488c0,u_v1);
    return;
  }
  i_v2 = FUN_140062860();
  if ((((i_v2 != 0) &&
       ((((byte)loc_58 | (byte)loc_28 | (byte)loc_30 | (byte)loc_38) & 0xf) == 0)) &&
      ((loc_4c & 3) == 0)) &&
     (((loc_50 & 0xf) == 0 &&
      ((int)((loc_50 + 0xf & 0xfffffff0) << 2) <=
       (int)((loc_48 ^ (int)loc_48 >> 0x1f) - ((int)loc_48 >> 0x1f)))))) {
    FUN_14008d2a0(&loc_38,&loc_58,&DAT_143a488c0,u_v1);
    return;
  }
  FUN_14005ebd0(&loc_38,&loc_58);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400623f0
void FUN_1400623f0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  longlong arg2 = cri_p1;
  longlong arg3 = cri_p2;
  cri_u8 u_v1;
  int i_v2;
  // Two plane descriptors passed by address: dst {3 ptrs, 3 ints} at rsp+0x40, src {ptr, 3 ints} at rsp+0x20 in the exe.
  __declspec(align(16)) cri_u8 frame_[0x48];
  cri_u8 &loc_58 = *(cri_u8 *)(frame_ + 0);
  uint &loc_50 = *(uint *)(frame_ + 8);
  uint &loc_4c = *(uint *)(frame_ + 12);
  uint &loc_48 = *(uint *)(frame_ + 16);
  cri_u8 &loc_38 = *(cri_u8 *)(frame_ + 32);
  cri_u8 &loc_30 = *(cri_u8 *)(frame_ + 40);
  cri_u8 &loc_28 = *(cri_u8 *)(frame_ + 48);
  cri_u4 &loc_20 = *(cri_u4 *)(frame_ + 56);
  cri_u4 &loc_1c = *(cri_u4 *)(frame_ + 60);
  cri_u4 &loc_18 = *(cri_u4 *)(frame_ + 64);
  
  loc_38 = *(cri_u8 *)(arg1 + 8);
  u_v1 = *(cri_u8 *)(arg3 + 8);
  loc_30 = *(cri_u8 *)((char *)arg1 + 0x20);
  loc_28 = *(cri_u8 *)((char *)arg1 + 0x38);
  loc_20 = *(cri_u4 *)((char *)arg1 + 0x18);
  loc_1c = *(cri_u4 *)((char *)arg1 + 0x30);
  loc_18 = *(cri_u4 *)((char *)arg1 + 0x48);
  loc_58 = *(cri_u8 *)(arg2 + 8);
  loc_50 = *(uint *)((char *)arg2 + 0x10);
  loc_4c = *(uint *)((char *)arg2 + 0x14);
  loc_48 = *(uint *)((char *)arg2 + 0x18);
  i_v2 = FUN_140062860();
  if ((((i_v2 != 0) &&
       ((((byte)loc_58 | (byte)loc_28 | (byte)loc_30 | (byte)loc_38) & 0xf) == 0)) &&
      ((loc_4c & 3) == 0)) &&
     (((loc_50 & 0xf) == 0 &&
      ((int)((loc_50 + 0xf & 0xfffffff0) * 3) <=
       (int)((loc_48 ^ (int)loc_48 >> 0x1f) - ((int)loc_48 >> 0x1f)))))) {
    FUN_14008e570(&loc_38,&loc_58,&DAT_143a488c0,u_v1);
    return;
  }
  FUN_14005fe40(&loc_38,&loc_58);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400624c0
void FUN_1400624c0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  longlong arg2 = cri_p1;
  longlong arg3 = cri_p2;
  cri_u8 u_v1;
  int i_v2;
  // Two plane descriptors passed by address: dst {3 ptrs, 3 ints} at rsp+0x40, src {ptr, 3 ints} at rsp+0x20 in the exe.
  __declspec(align(16)) cri_u8 frame_[0x48];
  cri_u8 &loc_58 = *(cri_u8 *)(frame_ + 0);
  uint &loc_50 = *(uint *)(frame_ + 8);
  uint &loc_4c = *(uint *)(frame_ + 12);
  uint &loc_48 = *(uint *)(frame_ + 16);
  cri_u8 &loc_38 = *(cri_u8 *)(frame_ + 32);
  cri_u8 &loc_30 = *(cri_u8 *)(frame_ + 40);
  cri_u8 &loc_28 = *(cri_u8 *)(frame_ + 48);
  cri_u4 &loc_20 = *(cri_u4 *)(frame_ + 56);
  cri_u4 &loc_1c = *(cri_u4 *)(frame_ + 60);
  cri_u4 &loc_18 = *(cri_u4 *)(frame_ + 64);
  
  loc_38 = *(cri_u8 *)(arg1 + 8);
  u_v1 = *(cri_u8 *)(arg3 + 8);
  loc_30 = *(cri_u8 *)((char *)arg1 + 0x20);
  loc_28 = *(cri_u8 *)((char *)arg1 + 0x38);
  loc_20 = *(cri_u4 *)((char *)arg1 + 0x18);
  loc_1c = *(cri_u4 *)((char *)arg1 + 0x30);
  loc_18 = *(cri_u4 *)((char *)arg1 + 0x48);
  loc_58 = *(cri_u8 *)(arg2 + 8);
  loc_50 = *(uint *)((char *)arg2 + 0x10);
  loc_4c = *(uint *)((char *)arg2 + 0x14);
  loc_48 = *(uint *)((char *)arg2 + 0x18);
  i_v2 = FUN_140062820();
  if (i_v2 != 0) {
    FUN_140092850(&loc_38,&loc_58,&DAT_143a488c0,u_v1);
    return;
  }
  i_v2 = FUN_140062860();
  if ((((i_v2 != 0) &&
       ((((byte)loc_58 | (byte)loc_28 | (byte)loc_30 | (byte)loc_38) & 0xf) == 0)) &&
      ((loc_4c & 3) == 0)) &&
     (((loc_50 & 0xf) == 0 &&
      ((int)((loc_50 + 0xf & 0xfffffff0) << 2) <=
       (int)((loc_48 ^ (int)loc_48 >> 0x1f) - ((int)loc_48 >> 0x1f)))))) {
    FUN_14008fa50(&loc_38,&loc_58,&DAT_143a488c0,u_v1);
    return;
  }
  FUN_140061080(&loc_38,&loc_58);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400625c0
void FUN_1400625c0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  longlong arg2 = cri_p1;
  longlong arg3 = cri_p2;
  cri_u8 u_v1;
  int i_v2;
  // Two plane descriptors passed by address: dst {3 ptrs, 3 ints} at rsp+0x40, src {ptr, 3 ints} at rsp+0x20 in the exe.
  __declspec(align(16)) cri_u8 frame_[0x48];
  cri_u8 &loc_58 = *(cri_u8 *)(frame_ + 0);
  uint &loc_50 = *(uint *)(frame_ + 8);
  uint &loc_4c = *(uint *)(frame_ + 12);
  uint &loc_48 = *(uint *)(frame_ + 16);
  cri_u8 &loc_38 = *(cri_u8 *)(frame_ + 32);
  cri_u8 &loc_30 = *(cri_u8 *)(frame_ + 40);
  cri_u8 &loc_28 = *(cri_u8 *)(frame_ + 48);
  cri_u4 &loc_20 = *(cri_u4 *)(frame_ + 56);
  cri_u4 &loc_1c = *(cri_u4 *)(frame_ + 60);
  cri_u4 &loc_18 = *(cri_u4 *)(frame_ + 64);
  
  loc_38 = *(cri_u8 *)(arg1 + 8);
  u_v1 = *(cri_u8 *)(arg3 + 8);
  loc_30 = *(cri_u8 *)((char *)arg1 + 0x20);
  loc_28 = *(cri_u8 *)((char *)arg1 + 0x38);
  loc_20 = *(cri_u4 *)((char *)arg1 + 0x18);
  loc_1c = *(cri_u4 *)((char *)arg1 + 0x30);
  loc_18 = *(cri_u4 *)((char *)arg1 + 0x48);
  loc_58 = *(cri_u8 *)(arg2 + 8);
  loc_50 = *(uint *)((char *)arg2 + 0x10);
  loc_4c = *(uint *)((char *)arg2 + 0x14);
  loc_48 = *(uint *)((char *)arg2 + 0x18);
  i_v2 = FUN_140062860();
  if ((((i_v2 != 0) &&
       ((((byte)loc_58 | (byte)loc_28 | (byte)loc_30 | (byte)loc_38) & 0xf) == 0)) &&
      ((loc_4c & 3) == 0)) &&
     (((loc_50 & 0xf) == 0 &&
      ((int)((loc_50 + 0xf & 0xfffffff0) * 3) <=
       (int)((loc_48 ^ (int)loc_48 >> 0x1f) - ((int)loc_48 >> 0x1f)))))) {
    FUN_140090080(&loc_38,&loc_58,&DAT_143a488c0,u_v1);
    return;
  }
  FUN_1400616c0(&loc_38,&loc_58);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062690
void FUN_140062690(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  longlong arg2 = cri_p1;
  cri_u8 *arg3 = cri_p2;
  cri_u8 u_v1;
  cri_u8 u_v2;
  int i_v3;
  // Two plane descriptors passed by address: dst {3 ptrs, 3 ints} at rsp+0x40, src {ptr, 3 ints} at rsp+0x20 in the exe.
  __declspec(align(16)) cri_u8 frame_[0x48];
  cri_u8 &loc_58 = *(cri_u8 *)(frame_ + 0);
  uint &loc_50 = *(uint *)(frame_ + 8);
  uint &loc_4c = *(uint *)(frame_ + 12);
  uint &loc_48 = *(uint *)(frame_ + 16);
  cri_u8 &loc_38 = *(cri_u8 *)(frame_ + 32);
  cri_u8 &loc_30 = *(cri_u8 *)(frame_ + 40);
  cri_u8 &loc_28 = *(cri_u8 *)(frame_ + 48);
  cri_u4 &loc_20 = *(cri_u4 *)(frame_ + 56);
  cri_u4 &loc_1c = *(cri_u4 *)(frame_ + 60);
  cri_u4 &loc_18 = *(cri_u4 *)(frame_ + 64);
  
  loc_38 = *(cri_u8 *)(arg1 + 8);
  u_v1 = *arg3;
  u_v2 = arg3[1];
  loc_30 = *(cri_u8 *)((char *)arg1 + 0x20);
  loc_28 = *(cri_u8 *)((char *)arg1 + 0x38);
  loc_20 = *(cri_u4 *)((char *)arg1 + 0x18);
  loc_1c = *(cri_u4 *)((char *)arg1 + 0x30);
  loc_18 = *(cri_u4 *)((char *)arg1 + 0x48);
  loc_58 = *(cri_u8 *)(arg2 + 8);
  loc_50 = *(uint *)((char *)arg2 + 0x10);
  loc_4c = *(uint *)((char *)arg2 + 0x14);
  loc_48 = *(uint *)((char *)arg2 + 0x18);
  i_v3 = FUN_140062820();
  if (i_v3 != 0) {
    FUN_1400928e0(&loc_38,&loc_58,u_v1,u_v2);
    return;
  }
  i_v3 = FUN_140062860();
  if ((((i_v3 != 0) &&
       ((((byte)loc_58 | (byte)loc_28 | (byte)loc_30 | (byte)loc_38) & 0xf) == 0)) &&
      ((loc_4c & 3) == 0)) &&
     (((loc_50 & 0xf) == 0 &&
      ((int)((loc_50 + 0xf & 0xfffffff0) * 2) <=
       (int)((loc_48 ^ (int)loc_48 >> 0x1f) - ((int)loc_48 >> 0x1f)))))) {
    FUN_140090730(&loc_38,&loc_58,u_v1,u_v2);
    return;
  }
  FUN_140061ce0(&loc_38,&loc_58);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400627a0
void FUN_1400627a0(cri_any cri_unused, ...)
{
  _DAT_143c494f0 = "\nCRI CFT/PCx64 Ver.2.26 Build:Jan 13 2012 18:30:45\n";
  FUN_1400493c0();
  FUN_14005e720();
  FUN_14005ebc0();
  FUN_1400479e0();
  FUN_140095250();
  FUN_140093cf0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400627f0
void FUN_1400627f0(cri_any cri_p0, ...)
{
  cri_u1 *arg1 = cri_p0;
  PTR_s_This_CFT_function_doesn_t_suppor_143a4a0c0 = arg1;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062820
cri_u4 FUN_140062820(cri_any cri_unused, ...)
{
  return DAT_143c494f8;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062830
cri_u8 FUN_140062830(cri_any cri_unused, ...)
{
  if (DAT_143a4a0c8 == -1) {
    DAT_143a4a0c8 = 1;
  }
  return DAT_143a4a0c8;  // the exe returns the cached flag in eax (FUN_140059090 spins forever on 0)
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062860
cri_u8 FUN_140062860(cri_any cri_unused, ...)
{
  if (DAT_143a4a0cc == -1) {
    DAT_143a4a0cc = 1;
  }
  return DAT_143a4a0cc;  // the exe returns the cached flag in eax (FUN_140059090 spins forever on 0)
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062890
int FUN_140062890(cri_any cri_unused, ...)
{
  if (DAT_143a4a0d0 == -1) {
    DAT_143a4a0d0 = 1;
  }
  return DAT_143a4a0d0;  // the exe returns the flag in eax (FUN_14004bf40 in sfr_cri_04 tests it)
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400628c0
cri_u4 thunk_FUN_14005b040(cri_any cri_unused, ...)
{
  return DAT_143e64b88;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400628d0
void FUN_1400628d0(cri_any cri_unused, ...)
{
  FUN_14005b090(0x80,&DAT_143c49500,0x100080);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400628f0
void thunk_FUN_14005b0b0(cri_any cri_unused, ...)
{
  FUN_14005b0b0();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062900
ulonglong FUN_140062900(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  return FUN_14005b0d0(*(ulonglong *)((char *)arg1 + 0x18f8));
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062910
void FUN_140062910(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  FUN_14005b0f0(*(ulonglong *)((char *)arg1 + 0x1848));
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062920
void FUN_140062920(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  if (arg1 == 0) {
    FUN_14005b110();
    return;
  }
  FUN_14005b110(*(cri_u8 *)((char *)arg1 + 0x1848));
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062950
void FUN_140062950(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  cri_u1 auStack_d8 [32];
  cri_u4 loc_b8;
  cri_u4 loc_b4;
  cri_u4 loc_b0;
  cri_u4 loc_ac;
  int loc_a8;
  cri_u1 loc_a4 [12];
  cri_u1 loc_98 [128];
  ulonglong loc_18;
  
  loc_18 = DAT_143a4a5e8 ^ (ulonglong)auStack_d8;
  FUN_14005b260(*(cri_u8 *)((char *)arg1 + 0x1848),loc_98);
  FUN_14005b280(*(cri_u8 *)((char *)arg1 + 0x1848),&loc_b4);
  FUN_14005b2a0(*(cri_u8 *)((char *)arg1 + 0x1848),&loc_a8,&loc_ac,loc_a4);
  FUN_14005b2c0(*(cri_u8 *)((char *)arg1 + 0x1848),&loc_b8,&loc_b0);
  memcpy((void *)((char *)arg1 + 0x1598),loc_98,0x80);
  *(cri_u4 *)((char *)arg1 + 0x16d4) = loc_b4;
  *(int *)((char *)arg1 + 0x16d8) = (int)(loc_a8 + (loc_a8 >> 0x1f & 0x7ffU)) >> 0xb;
  *(cri_u4 *)((char *)arg1 + 0x16e8) = loc_ac;
  *(cri_u4 *)((char *)arg1 + 0x16e0) = loc_b8;
  *(cri_u4 *)((char *)arg1 + 0x16e4) = loc_b0;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062a40
cri_u8 FUN_140062a40(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  cri_u8 arg2 = cri_p1;
  cri_u8 arg3 = cri_p2;
  int i_v1;
  
  i_v1 = FUN_14005b040();
  if ((i_v1 != 0) && (*(int *)((char *)arg1 + 0x15d4) == 1)) {
    FUN_14005b190(*(cri_u8 *)((char *)arg1 + 0x1848),arg2,arg3);
    return 0;
  }
  return 0xffffffff;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062ab0
void FUN_140062ab0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  int i_v1;
  
  i_v1 = FUN_14005b040();
  if ((i_v1 != 0) && (*(longlong *)((char *)arg1 + 0x1848) != 0)) {
    FUN_14005b2e0();
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062ae0
cri_u8 FUN_140062ae0(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  cri_u8 arg2 = cri_p1;
  int i_v1;
  cri_u8 *pu_v2;
  
  i_v1 = FUN_14005b040();
  if (i_v1 == 0) {
    return 0xffffffff;
  }
  pu_v2 = (cri_u8 *)((char *)arg1 + 0x1860);
  i_v1 = 0;
  do {
    FUN_14005b1d0(*(cri_u8 *)((char *)arg1 + 0x1848),i_v1,pu_v2[-1],*pu_v2,pu_v2[1]);
    i_v1 = i_v1 + 1;
    pu_v2 = pu_v2 + 3;
  } while (i_v1 < 4);
  FUN_14005b200(*(cri_u8 *)((char *)arg1 + 0x1848),*(cri_u8 *)((char *)arg1 + 0x18b8),
                *(cri_u4 *)((char *)arg1 + 0x18c0));
  i_v1 = FUN_14005b240(*(cri_u8 *)((char *)arg1 + 0x1848),arg2);
  if (i_v1 != 0) {
    return 0xfffffffe;
  }
  FUN_14005b220(*(cri_u8 *)((char *)arg1 + 0x1848),0,arg1 + 0x18c4);
  FUN_140062950(arg1);
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062bc0
int FUN_140062bc0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  char *arg1 = cri_p0;
  longlong arg2 = cri_p1;
  longlong arg3 = cri_p2;
  longlong l_v1;
  char *pc_v2;
  cri_u1 in_ZF;
  
  l_v1 = 6;
  pc_v2 = "2.080";
  do {
    if (l_v1 == 0) break;
    l_v1 = l_v1 + -1;
    in_ZF = *pc_v2 == *arg1;
    pc_v2 = pc_v2 + 1;
    arg1 = arg1 + 1;
  } while ((bool)in_ZF);
  if (((bool)in_ZF) && (arg2 == 0x1900)) {
    return -(uint)(arg3 != 0x80);
  }
  return -1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140062c10
void FUN_140062c10(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  longlong *arg2 = cri_p1;
  cri_u1 *pu_v1;
  cri_u1 *pu_v2;
  cri_u1 u_v3;
  short s_v4;
  int i_v5;
  uint u_v6;
  int i_v7;
  uint u_v8;
  cri_u1 *pu_v9;
  cri_u1 *pu_v10;
  uint u_v11;
  uint u_v12;
  uint u_v13;
  ulonglong u_v15;
  cri_u1 loc_28 [16];
  ulonglong u_v14;
  
  (**(cri_code **)(*arg2 + 0x30))(arg2,1,0x7fffffff,arg1 + 0x1800);
  pu_v9 = (cri_u1 *)(*(ulonglong *)((char *)arg1 + 0x1800) & 0xfffffffffffffffc);
  i_v7 = *(int *)((char *)arg1 + 0x1800) * 8 + (int)pu_v9 * -8;
  pu_v10 = pu_v9 + 8;
  u_v8 = i_v7 + *(int *)((char *)arg1 + 0x1810);
  u_v11 = CONCAT31(CONCAT21(CONCAT11(pu_v9[4],pu_v9[5]),pu_v9[6]),pu_v9[7]);
  if ((int)u_v8 < 0x20) {
    u_v12 = (CONCAT31(CONCAT21(CONCAT11(*pu_v9,pu_v9[1]),pu_v9[2]),pu_v9[3]) <<
             ((byte)i_v7 & 0x1f)) << ((byte)*(int *)((char *)arg1 + 0x1810) & 0x1f);
  }
  else {
    u_v8 = u_v8 - 0x20;
    u_v12 = u_v11 << ((byte)u_v8 & 0x1f);
    u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v10,pu_v9[9]),pu_v9[10]),pu_v9[0xb]);
    pu_v10 = pu_v9 + 0xc;
  }
  u_v14 = (ulonglong)u_v12;
  while( true ) {
    u_v12 = (uint)(u_v14 >> 9);
    if (9 < (int)u_v8) {
      u_v12 = u_v12 | u_v11 >> (0x29U - (char)u_v8 & 0x1f);
    }
    if (u_v12 == 0) break;
    i_v7 = *(int *)((char *)arg1 + 0x1794);
    while( true ) {
      do {
        u_v15 = u_v14 >> 0x14;
        if (0x14 < (int)u_v8) {
          u_v15 = (ulonglong)((uint)u_v15 | u_v11 >> (0x34U - (char)u_v8 & 0x1f));
        }
        if ((u_v15 & 0xffffff00) == 0) {
          s_v4 = *(short *)(DAT_143d74a30 + u_v15 * 2);
        }
        else {
          s_v4 = *(short *)(DAT_143d749f0 + (u_v15 >> 6) * 2);
        }
        u_v12 = (uint)s_v4;
        u_v8 = u_v8 + (u_v12 & 0xf);
        if ((int)u_v8 < 0x20) {
          u_v13 = (int)u_v14 << (sbyte)(u_v12 & 0xf);
        }
        else {
          u_v8 = u_v8 - 0x20;
          u_v13 = u_v11 << ((byte)u_v8 & 0x1f);
          u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v10,pu_v10[1]),pu_v10[2]),pu_v10[3]);
          pu_v10 = pu_v10 + 4;
        }
        u_v14 = (ulonglong)u_v13;
        u_v6 = (u_v12 >> 2 & 0xff) >> 2;
      } while (u_v6 == 0x22);
      if (u_v6 != 0x23) break;
      *(int *)((char *)arg1 + 0x1794) = *(int *)((char *)arg1 + 0x1794) + 0x21;
    }
    if (u_v6 == 0x24) break;
    *(int *)((char *)arg1 + 0x1794) = *(int *)((char *)arg1 + 0x1794) + u_v6;
    *(uint *)((char *)arg1 + 0x17a4) = u_v12 >> 10;
    if (*(int *)((char *)arg1 + 0x17a0) < *(int *)((char *)arg1 + 0x1794)) break;
    i_v7 = *(int *)((char *)arg1 + 0x1794) - i_v7;
    *(int *)((char *)arg1 + 0x179c) = *(int *)((char *)arg1 + 0x179c) + i_v7;
    i_v5 = *(int *)((char *)arg1 + 0x179c);
    while (*(int *)((char *)arg1 + 0x15a0) <= i_v5) {
      *(int *)((char *)arg1 + 0x179c) = *(int *)((char *)arg1 + 0x179c) - *(int *)((char *)arg1 + 0x15a0);
      *(int *)((char *)arg1 + 0x1798) = *(int *)((char *)arg1 + 0x1798) + 1;
      i_v5 = *(int *)((char *)arg1 + 0x179c);
    }
    if (i_v7 == -2) break;
    *(uint *)((char *)arg1 + 0x1280) = u_v13;
    *(uint *)((char *)arg1 + 0x1284) = u_v11;
    *(uint *)((char *)arg1 + 0x1288) = u_v8;
    *(cri_u1 **)((char *)arg1 + 0x1290) = pu_v10;
    (**(cri_code **)((char *)arg1 + 0x1700))(arg1);
    (**(cri_code **)((char *)arg1 + 0x1710))(arg1);
    if (*(int *)((char *)arg1 + 0x18f0) != 0) break;
    *(int *)((char *)arg1 + 0x1830) = *(int *)((char *)arg1 + 0x1830) + -1;
    if (*(int *)((char *)arg1 + 0x1830) < 1) {
      *(cri_u4 *)((char *)arg1 + 0x1830) = *(cri_u4 *)((char *)arg1 + 0x1580);
      (**(cri_code **)((char *)arg1 + 0x1588))(*(cri_u8 *)((char *)arg1 + 0x1590));
    }
    pu_v10 = *(cri_u1 **)((char *)arg1 + 0x1290);
    if (*(int *)((char *)arg1 + 0x1288) == 0x1f) {
      pu_v9 = pu_v10 + 1;
      u_v3 = *pu_v10;
      u_v8 = 0;
      pu_v1 = pu_v10 + 2;
      pu_v2 = pu_v10 + 3;
      pu_v10 = pu_v10 + 4;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(u_v3,*pu_v9),*pu_v1),*pu_v2);
      u_v12 = *(uint *)((char *)arg1 + 0x1284);
    }
    else {
      u_v8 = *(int *)((char *)arg1 + 0x1288) + 1;
      u_v12 = *(int *)((char *)arg1 + 0x1280) * 2;
      u_v11 = *(uint *)((char *)arg1 + 0x1284);
    }
    u_v14 = (ulonglong)u_v12;
    if (-1 < *(int *)((char *)arg1 + 0x1280)) break;
    u_v12 = u_v8 & 7;
    i_v7 = (((int)((u_v8 - u_v12) + 7) >> 3) - *(int *)((char *)arg1 + 0x1800)) + -8 + (int)pu_v10;
    if (*(int *)((char *)arg1 + 0x1808) - i_v7 < 0x801) {
      FUN_140069020(arg1 + 0x1800,i_v7,arg1 + 0x1800,loc_28);
      (**(cri_code **)(*arg2 + 0x40))(arg2,0,arg1 + 0x1800);
      (**(cri_code **)(*arg2 + 0x38))(arg2,1,loc_28);
      (**(cri_code **)(*arg2 + 0x30))(arg2,1,0x7fffffff,arg1 + 0x1800);
      pu_v9 = (cri_u1 *)(*(ulonglong *)((char *)arg1 + 0x1800) & 0xfffffffffffffffc);
      i_v7 = *(int *)((char *)arg1 + 0x1800) * 8 + (int)pu_v9 * -8;
      u_v8 = i_v7 + u_v12;
      pu_v10 = pu_v9 + 8;
      u_v11 = CONCAT31(CONCAT21(CONCAT11(pu_v9[4],pu_v9[5]),pu_v9[6]),pu_v9[7]);
      if ((int)u_v8 < 0x20) {
        u_v14 = (ulonglong)
                 (uint)((CONCAT31(CONCAT21(CONCAT11(*pu_v9,pu_v9[1]),pu_v9[2]),pu_v9[3]) <<
                        ((byte)i_v7 & 0x1f)) << (sbyte)u_v12);
      }
      else {
        u_v8 = u_v8 - 0x20;
        u_v14 = (ulonglong)(u_v11 << ((byte)u_v8 & 0x1f));
        u_v11 = CONCAT31(CONCAT21(CONCAT11(*pu_v10,pu_v9[9]),pu_v9[10]),pu_v9[0xb]);
        pu_v10 = pu_v9 + 0xc;
      }
    }
  }
  FUN_140069020(arg1 + 0x1800,
                (((int)(u_v8 + 7) >> 3) - *(int *)((char *)arg1 + 0x1800)) + -8 + (int)pu_v10,
                arg1 + 0x1800,loc_28);
  (**(cri_code **)(*arg2 + 0x40))(arg2,0,arg1 + 0x1800);
  (**(cri_code **)(*arg2 + 0x38))(arg2,1,loc_28);
  FUN_140051d90(arg2);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400630c0
cri_u8 FUN_1400630c0(cri_any cri_unused, ...)
{
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400630d0
void FUN_1400630d0(cri_any cri_unused, ...)
{
  ushort u_v1;
  ushort u_v2;
  longlong l_v3;
  short s_v4;
  int i_v5;
  ushort *pu_v6;
  cri_u2 *pu_v7;
  ushort *pu_v8;
  
  pu_v8 = CRI_ADDR(DAT_143d4a8e0);
  i_v5 = 0x21;
  pu_v7 = CRI_ADDR(DAT_143d4a880);
  for (l_v3 = 0x10; l_v3 != 0; l_v3 = l_v3 + -1) {
    *pu_v7 = 0x240;
    pu_v7 = pu_v7 + 1;
  }
  _DAT_143d4a8a0 = 0x23b;
  _DAT_143d4a8a2 = 0x23b;
  pu_v7 = CRI_ADDR(DAT_143d4a8a4);
  for (l_v3 = 0xc; l_v3 != 0; l_v3 = l_v3 + -1) {
    *pu_v7 = 0x240;
    pu_v7 = pu_v7 + 1;
  }
  _DAT_143d4a8bc = 0x22b;
  _DAT_143d4a8be = 0x22b;
  pu_v7 = CRI_ADDR(DAT_143d4a8c0);
  for (l_v3 = 0x10; l_v3 != 0; l_v3 = l_v3 + -1) {
    *pu_v7 = 0x240;
    pu_v7 = pu_v7 + 1;
  }
  do {
    s_v4 = (short)i_v5;
    i_v5 = i_v5 + -1;
    pu_v6 = pu_v8 + 2;
    u_v1 = s_v4 << 4;
    *pu_v8 = u_v1 | 0x440d;
    pu_v8[1] = u_v1 | 0x40c;
    pu_v8 = pu_v6;
  } while (0x15 < i_v5);
  i_v5 = 0x15;
  do {
    s_v4 = (short)i_v5;
    i_v5 = i_v5 + -1;
    pu_v8 = pu_v6 + 4;
    u_v1 = s_v4 << 4;
    u_v2 = u_v1 | 0x40b;
    u_v1 = u_v1 | 0x440c;
    *pu_v6 = u_v1;
    pu_v6[1] = u_v1;
    pu_v6[2] = u_v2;
    pu_v6[3] = u_v2;
    pu_v6 = pu_v8;
  } while (0xf < i_v5);
  i_v5 = 0xf;
  do {
    s_v4 = (short)i_v5;
    i_v5 = i_v5 + -1;
    pu_v6 = pu_v8 + 0x10;
    u_v1 = s_v4 << 4;
    u_v2 = u_v1 | 0x409;
    u_v1 = u_v1 | 0x440a;
    *pu_v8 = u_v1;
    pu_v8[1] = u_v1;
    pu_v8[2] = u_v1;
    pu_v8[3] = u_v1;
    pu_v8[4] = u_v1;
    pu_v8[5] = u_v1;
    pu_v8[6] = u_v1;
    pu_v8[7] = u_v1;
    pu_v8[8] = u_v2;
    pu_v8[9] = u_v2;
    pu_v8[10] = u_v2;
    pu_v8[0xb] = u_v2;
    pu_v8[0xc] = u_v2;
    pu_v8[0xd] = u_v2;
    pu_v8[0xe] = u_v2;
    pu_v8[0xf] = u_v2;
    pu_v8 = pu_v6;
  } while (9 < i_v5);
  i_v5 = 9;
  do {
    u_v1 = (short)i_v5 << 4;
    i_v5 = i_v5 + -1;
    pu_v8 = pu_v6;
    for (l_v3 = 0x10; l_v3 != 0; l_v3 = l_v3 + -1) {
      *pu_v8 = u_v1 | 0x4409;
      pu_v8 = pu_v8 + 1;
    }
    pu_v8 = pu_v6 + 0x10;
    pu_v6 = pu_v6 + 0x20;
    for (l_v3 = 0x10; l_v3 != 0; l_v3 = l_v3 + -1) {
      *pu_v8 = u_v1 | 0x408;
      pu_v8 = pu_v8 + 1;
    }
  } while (7 < i_v5);
  _DAT_143d4a240 = 0x240;
  _DAT_143d4a242 = 0x240;
  _DAT_143d4a244 = 0x240;
  _DAT_143d4a246 = 0x240;
  i_v5 = 7;
  pu_v8 = CRI_ADDR(DAT_143d4a248);
  do {
    s_v4 = (short)i_v5;
    i_v5 = i_v5 + -1;
    pu_v6 = pu_v8 + 2;
    u_v1 = s_v4 << 4;
    *pu_v8 = u_v1 | 0x4407;
    pu_v8[1] = u_v1 | 0x406;
    pu_v8 = pu_v6;
  } while (5 < i_v5);
  i_v5 = 5;
  do {
    s_v4 = (short)i_v5;
    i_v5 = i_v5 + -1;
    pu_v8 = pu_v6 + 4;
    u_v1 = s_v4 << 4;
    u_v2 = u_v1 | 0x405;
    u_v1 = u_v1 | 0x4406;
    *pu_v6 = u_v1;
    pu_v6[1] = u_v1;
    pu_v6[2] = u_v2;
    pu_v6[3] = u_v2;
    pu_v6 = pu_v8;
  } while (3 < i_v5);
  i_v5 = 3;
  do {
    pu_v6 = pu_v8;
    s_v4 = (short)i_v5;
    i_v5 = i_v5 + -1;
    u_v1 = s_v4 << 4;
    u_v2 = u_v1 | 0x404;
    u_v1 = u_v1 | 0x4405;
    *pu_v6 = u_v1;
    pu_v6[1] = u_v1;
    pu_v6[2] = u_v1;
    pu_v6[3] = u_v1;
    pu_v6[4] = u_v2;
    pu_v6[5] = u_v2;
    pu_v6[6] = u_v2;
    pu_v6[7] = u_v2;
    pu_v8 = pu_v6 + 8;
  } while (1 < i_v5);
  for (l_v3 = 0x10; l_v3 != 0; l_v3 = l_v3 + -1) {
    *pu_v8 = 0x4413;
    pu_v8 = pu_v8 + 1;
  }
  pu_v8 = pu_v6 + 0x18;
  for (l_v3 = 0x10; l_v3 != 0; l_v3 = l_v3 + -1) {
    *pu_v8 = 0x412;
    pu_v8 = pu_v8 + 1;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400633e0
void FUN_1400633e0(cri_any cri_unused, ...)
{
  short s_v1;
  ushort u_v2;
  ushort u_v3;
  int i_v4;
  ushort *pu_v5;
  ushort *pu_v6;
  
  _DAT_143d4aa90 = 0x23b;
  _DAT_143d4aa80 = 0x240;
  _DAT_143d4aa82 = 0x240;
  _DAT_143d4aa84 = 0x240;
  _DAT_143d4aa86 = 0x240;
  _DAT_143d4aa9e = 0x22b;
  _DAT_143d4aa88 = 0x240;
  _DAT_143d4aa8a = 0x240;
  _DAT_143d4aa8c = 0x240;
  _DAT_143d4aa8e = 0x240;
  _DAT_143d4aa92 = 0x240;
  _DAT_143d4aa94 = 0x240;
  _DAT_143d4aa96 = 0x240;
  _DAT_143d4aa98 = 0x240;
  _DAT_143d4aa9a = 0x240;
  _DAT_143d4aa9c = 0x240;
  _DAT_143d4aaa0 = 0x240;
  _DAT_143d4aaa2 = 0x240;
  _DAT_143d4aaa4 = 0x240;
  _DAT_143d4aaa6 = 0x240;
  _DAT_143d4aaa8 = 0x240;
  _DAT_143d4aaaa = 0x240;
  _DAT_143d4aaac = 0x240;
  _DAT_143d4aaae = 0x240;
  i_v4 = 0x21;
  pu_v5 = CRI_ADDR(DAT_143d4aab0);
  do {
    s_v1 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v6 = pu_v5 + 1;
    *pu_v5 = s_v1 << 4 | 0xb;
    pu_v5 = pu_v6;
  } while (0x15 < i_v4);
  i_v4 = 0x15;
  do {
    s_v1 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v5 = pu_v6 + 2;
    u_v2 = s_v1 << 4;
    *pu_v6 = u_v2 | 10;
    pu_v6[1] = u_v2 | 0xa80b;
    pu_v6 = pu_v5;
  } while (0xf < i_v4);
  i_v4 = 0xf;
  do {
    s_v1 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v6 = pu_v5 + 8;
    u_v2 = s_v1 << 4;
    *pu_v5 = u_v2 | 8;
    pu_v5[1] = u_v2 | 0xa00b;
    u_v3 = u_v2 | 0xa809;
    pu_v5[2] = u_v2 | 0x880a;
    pu_v5[3] = u_v2 | 0x880a;
    pu_v5[4] = u_v3;
    pu_v5[5] = u_v3;
    pu_v5[6] = u_v3;
    pu_v5[7] = u_v3;
    pu_v5 = pu_v6;
  } while (9 < i_v4);
  i_v4 = 9;
  do {
    s_v1 = (short)i_v4;
    i_v4 = i_v4 + -1;
    u_v2 = s_v1 << 4;
    *pu_v6 = u_v2 | 7;
    pu_v6[1] = u_v2 | 7;
    pu_v6[2] = u_v2 | 0xa00a;
    pu_v6[3] = u_v2 | 0xa00a;
    u_v3 = u_v2 | 0xa808;
    u_v2 = u_v2 | 0x8809;
    pu_v6[4] = u_v2;
    pu_v6[5] = u_v2;
    pu_v6[6] = u_v2;
    pu_v6[7] = u_v2;
    pu_v6[8] = u_v3;
    pu_v6[9] = u_v3;
    pu_v6[10] = u_v3;
    pu_v6[0xb] = u_v3;
    pu_v6[0xc] = u_v3;
    pu_v6[0xd] = u_v3;
    pu_v6[0xe] = u_v3;
    pu_v6[0xf] = u_v3;
    pu_v6 = pu_v6 + 0x10;
  } while (7 < i_v4);
  _DAT_143d4a200 = 0x240;
  _DAT_143d4a202 = 0x240;
  i_v4 = 7;
  pu_v5 = CRI_ADDR(DAT_143d4a204);
  do {
    s_v1 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v6 = pu_v5 + 1;
    *pu_v5 = s_v1 << 4 | 5;
    pu_v5 = pu_v6;
  } while (5 < i_v4);
  i_v4 = 5;
  do {
    s_v1 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v5 = pu_v6 + 2;
    u_v2 = s_v1 << 4;
    *pu_v6 = u_v2 | 4;
    pu_v6[1] = u_v2 | 0xa805;
    pu_v6 = pu_v5;
  } while (3 < i_v4);
  i_v4 = 3;
  do {
    pu_v6 = pu_v5;
    s_v1 = (short)i_v4;
    i_v4 = i_v4 + -1;
    u_v2 = s_v1 << 4;
    *pu_v6 = u_v2 | 3;
    pu_v6[1] = u_v2 | 0x8805;
    pu_v6[2] = u_v2 | 0xa804;
    pu_v6[3] = u_v2 | 0xa804;
    pu_v5 = pu_v6 + 4;
  } while (1 < i_v4);
  pu_v6[4] = 0x11;
  pu_v6[5] = 0x11;
  pu_v6[6] = 0xa014;
  pu_v6[7] = 0xa014;
  pu_v6[8] = 0x8813;
  pu_v6[9] = 0x8813;
  pu_v6[10] = 0x8813;
  pu_v6[0xb] = 0x8813;
  pu_v6[0xc] = 0xa812;
  pu_v6[0xd] = 0xa812;
  pu_v6[0xe] = 0xa812;
  pu_v6[0xf] = 0xa812;
  pu_v6[0x10] = 0xa812;
  pu_v6[0x11] = 0xa812;
  pu_v6[0x12] = 0xa812;
  pu_v6[0x13] = 0xa812;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140063730
void FUN_140063730(cri_any cri_unused, ...)
{
  ushort u_v1;
  short s_v2;
  ushort u_v3;
  int i_v4;
  ushort *pu_v5;
  ushort *pu_v6;
  
  _DAT_143d49f90 = 0x23b;
  _DAT_143d49f80 = 0x240;
  _DAT_143d49f82 = 0x240;
  _DAT_143d49f84 = 0x240;
  _DAT_143d49f86 = 0x240;
  _DAT_143d49f9e = 0x22b;
  _DAT_143d49f88 = 0x240;
  _DAT_143d49f8a = 0x240;
  _DAT_143d49f8c = 0x240;
  _DAT_143d49f8e = 0x240;
  _DAT_143d49f92 = 0x240;
  _DAT_143d49f94 = 0x240;
  _DAT_143d49f96 = 0x240;
  _DAT_143d49f98 = 0x240;
  _DAT_143d49f9a = 0x240;
  _DAT_143d49f9c = 0x240;
  _DAT_143d49fa0 = 0x240;
  _DAT_143d49fa2 = 0x240;
  _DAT_143d49fa4 = 0x240;
  _DAT_143d49fa6 = 0x240;
  _DAT_143d49fa8 = 0x240;
  _DAT_143d49faa = 0x240;
  _DAT_143d49fac = 0x240;
  _DAT_143d49fae = 0x240;
  i_v4 = 0x21;
  pu_v5 = CRI_ADDR(DAT_143d49fb0);
  do {
    s_v2 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v6 = pu_v5 + 1;
    *pu_v5 = s_v2 << 4 | 0xb;
    pu_v5 = pu_v6;
  } while (0x15 < i_v4);
  i_v4 = 0x15;
  do {
    s_v2 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v5 = pu_v6 + 2;
    u_v1 = s_v2 << 4 | 10;
    *pu_v6 = u_v1;
    pu_v6[1] = u_v1;
    pu_v6 = pu_v5;
  } while (0xf < i_v4);
  i_v4 = 0xf;
  do {
    s_v2 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v6 = pu_v5 + 8;
    u_v1 = s_v2 << 4;
    *pu_v5 = u_v1 | 8;
    pu_v5[1] = u_v1 | 8;
    pu_v5[2] = u_v1 | 0x900b;
    pu_v5[3] = u_v1 | 0x980b;
    pu_v5[4] = u_v1 | 0xb00a;
    pu_v5[5] = u_v1 | 0xb00a;
    pu_v5[6] = u_v1 | 0xb80a;
    pu_v5[7] = u_v1 | 0xb80a;
    pu_v5 = pu_v6;
  } while (9 < i_v4);
  i_v4 = 9;
  do {
    s_v2 = (short)i_v4;
    i_v4 = i_v4 + -1;
    u_v3 = s_v2 << 4;
    *pu_v6 = u_v3 | 7;
    pu_v6[1] = u_v3 | 7;
    pu_v6[2] = u_v3 | 0xa00b;
    pu_v6[3] = u_v3 | 0xa80b;
    pu_v6[4] = u_v3 | 0x900a;
    pu_v6[5] = u_v3 | 0x900a;
    pu_v6[6] = u_v3 | 0x980a;
    pu_v6[7] = u_v3 | 0x980a;
    u_v1 = u_v3 | 0xb009;
    u_v3 = u_v3 | 0xb809;
    pu_v6[8] = u_v1;
    pu_v6[9] = u_v1;
    pu_v6[10] = u_v1;
    pu_v6[0xb] = u_v1;
    pu_v6[0xc] = u_v3;
    pu_v6[0xd] = u_v3;
    pu_v6[0xe] = u_v3;
    pu_v6[0xf] = u_v3;
    pu_v6 = pu_v6 + 0x10;
  } while (7 < i_v4);
  _DAT_143d4a3c0 = 0x240;
  _DAT_143d4a3c2 = 0x240;
  i_v4 = 7;
  pu_v5 = CRI_ADDR(DAT_143d4a3c4);
  do {
    s_v2 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v6 = pu_v5 + 1;
    *pu_v5 = s_v2 << 4 | 5;
    pu_v5 = pu_v6;
  } while (5 < i_v4);
  i_v4 = 5;
  do {
    s_v2 = (short)i_v4;
    i_v4 = i_v4 + -1;
    pu_v5 = pu_v6 + 2;
    u_v1 = s_v2 << 4 | 4;
    *pu_v6 = u_v1;
    pu_v6[1] = u_v1;
    pu_v6 = pu_v5;
  } while (3 < i_v4);
  i_v4 = 3;
  do {
    pu_v6 = pu_v5;
    s_v2 = (short)i_v4;
    i_v4 = i_v4 + -1;
    u_v1 = s_v2 << 4;
    *pu_v6 = u_v1 | 3;
    pu_v6[1] = u_v1 | 3;
    pu_v6[2] = u_v1 | 0xb005;
    pu_v6[3] = u_v1 | 0xb805;
    pu_v5 = pu_v6 + 4;
  } while (1 < i_v4);
  pu_v6[4] = 0x11;
  pu_v6[5] = 0x11;
  pu_v6[6] = 0xa015;
  pu_v6[7] = 0xa815;
  pu_v6[8] = 0x9014;
  pu_v6[9] = 0x9014;
  pu_v6[10] = 0x9814;
  pu_v6[0xb] = 0x9814;
  pu_v6[0xc] = 0xb013;
  pu_v6[0xd] = 0xb013;
  pu_v6[0xe] = 0xb013;
  pu_v6[0xf] = 0xb013;
  pu_v6[0x10] = 0xb813;
  pu_v6[0x11] = 0xb813;
  pu_v6[0x12] = 0xb813;
  pu_v6[0x13] = 0xb813;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140063aa0
void FUN_140063aa0(cri_any cri_unused, ...)
{
  longlong l_v1;
  cri_u2 *pu_v2;
  
  _DAT_143d4a300 = 0x1106;
  _DAT_143d4a302 = 0x1205;
  _DAT_143d4a304 = 0x1a05;
  _DAT_143d4a306 = 0x105;
  _DAT_143d4a308 = 0x803;
  _DAT_143d4a30a = 0x803;
  _DAT_143d4a30c = 0x803;
  _DAT_143d4a30e = 0x803;
  _DAT_143d4a310 = 0x202;
  _DAT_143d4a312 = 0x202;
  _DAT_143d4a314 = 0x202;
  _DAT_143d4a316 = 0x202;
  _DAT_143d4a318 = 0x202;
  _DAT_143d4a31a = 0x202;
  _DAT_143d4a31c = 0x202;
  _DAT_143d4a31e = 0x202;
  pu_v2 = CRI_ADDR(DAT_143d4a320);
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0xa01;
    pu_v2 = pu_v2 + 1;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140063b60
void FUN_140063b60(cri_any cri_unused, ...)
{
  longlong l_v1;
  cri_u2 *pu_v2;
  
  _DAT_143d4a080 = 0x1f00;
  _DAT_143d4a082 = 0x1106;
  _DAT_143d4a084 = 0x1606;
  _DAT_143d4a086 = 0x1a06;
  _DAT_143d4a088 = 0x1e05;
  _DAT_143d4a08a = 0x1e05;
  _DAT_143d4a08c = 0x105;
  _DAT_143d4a08e = 0x105;
  _DAT_143d4a090 = 0x804;
  _DAT_143d4a092 = 0x804;
  _DAT_143d4a094 = 0x804;
  _DAT_143d4a096 = 0x804;
  _DAT_143d4a098 = 0xa04;
  _DAT_143d4a09a = 0xa04;
  _DAT_143d4a09c = 0xa04;
  _DAT_143d4a09e = 0xa04;
  _DAT_143d4a0a0 = 0x403;
  _DAT_143d4a0a2 = 0x403;
  _DAT_143d4a0a4 = 0x403;
  _DAT_143d4a0a6 = 0x403;
  _DAT_143d4a0a8 = 0x403;
  _DAT_143d4a0aa = 0x403;
  _DAT_143d4a0ac = 0x403;
  _DAT_143d4a0ae = 0x403;
  _DAT_143d4a0b0 = 0x603;
  _DAT_143d4a0b2 = 0x603;
  _DAT_143d4a0b4 = 0x603;
  _DAT_143d4a0b6 = 0x603;
  _DAT_143d4a0b8 = 0x603;
  _DAT_143d4a0ba = 0x603;
  _DAT_143d4a0bc = 0x603;
  _DAT_143d4a0be = 0x603;
  pu_v2 = CRI_ADDR(DAT_143d4a0c0);
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0xc02;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = CRI_ADDR(DAT_143d4a0e0);
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0xe02;
    pu_v2 = pu_v2 + 1;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140063cb0
void FUN_140063cb0(cri_any cri_unused, ...)
{
  ushort u_v1;
  ushort u_v2;
  int i_v3;
  longlong l_v4;
  ushort *pu_v5;
  ushort *pu_v6;
  cri_u2 *pu_v7;
  
  pu_v7 = CRI_ADDR(DAT_143d4a100);
  for (l_v4 = 0x18; l_v4 != 0; l_v4 = l_v4 + -1) {
    *pu_v7 = 0x7f;
    pu_v7 = pu_v7 + 1;
  }
  i_v3 = 0x10;
  pu_v5 = CRI_ADDR(DAT_143d4a130);
  do {
    u_v1 = (ushort)i_v3;
    pu_v6 = pu_v5 + 2;
    *pu_v5 = u_v1 & 0xff | 0xb00;
    i_v3 = i_v3 + -1;
    pu_v5[1] = -u_v1 & 0xff | 0xb00;
    pu_v5 = pu_v6;
  } while (10 < i_v3);
  i_v3 = 10;
  do {
    u_v2 = (ushort)i_v3;
    pu_v5 = pu_v6 + 4;
    u_v1 = u_v2 & 0xff | 0xa00;
    *pu_v6 = u_v1;
    pu_v6[1] = u_v1;
    i_v3 = i_v3 + -1;
    u_v1 = -u_v2 & 0xff | 0xa00;
    pu_v6[2] = u_v1;
    pu_v6[3] = u_v1;
    pu_v6 = pu_v5;
  } while (7 < i_v3);
  i_v3 = 7;
  do {
    pu_v6 = pu_v5;
    u_v2 = (ushort)i_v3;
    u_v1 = u_v2 & 0xff | 0x800;
    *pu_v6 = u_v1;
    pu_v6[1] = u_v1;
    pu_v6[2] = u_v1;
    pu_v6[3] = u_v1;
    pu_v6[4] = u_v1;
    pu_v6[5] = u_v1;
    pu_v6[6] = u_v1;
    pu_v6[7] = u_v1;
    i_v3 = i_v3 + -1;
    u_v1 = -u_v2 & 0xff | 0x800;
    pu_v6[8] = u_v1;
    pu_v6[9] = u_v1;
    pu_v6[10] = u_v1;
    pu_v6[0xb] = u_v1;
    pu_v6[0xc] = u_v1;
    pu_v6[0xd] = u_v1;
    pu_v6[0xe] = u_v1;
    pu_v6[0xf] = u_v1;
    pu_v5 = pu_v6 + 0x10;
  } while (4 < i_v3);
  _DAT_143d4a2c0 = 0x7f;
  _DAT_143d4a2c2 = 0x7f;
  for (l_v4 = 0x10; l_v4 != 0; l_v4 = l_v4 + -1) {
    *pu_v5 = 0x704;
    pu_v5 = pu_v5 + 1;
  }
  pu_v5 = pu_v6 + 0x20;
  for (l_v4 = 0x10; l_v4 != 0; l_v4 = l_v4 + -1) {
    *pu_v5 = 0x7fc;
    pu_v5 = pu_v5 + 1;
  }
  _DAT_143d4a2c4 = 0x503;
  _DAT_143d4a2c6 = 0x5fd;
  _DAT_143d4a2c8 = 0x402;
  _DAT_143d4a2ca = 0x402;
  _DAT_143d4a2cc = 0x4fe;
  _DAT_143d4a2ce = 0x4fe;
  _DAT_143d4a2d0 = 0x301;
  _DAT_143d4a2d2 = 0x301;
  _DAT_143d4a2d4 = 0x301;
  _DAT_143d4a2d6 = 0x301;
  _DAT_143d4a2d8 = 0x3ff;
  _DAT_143d4a2da = 0x3ff;
  _DAT_143d4a2dc = 0x3ff;
  _DAT_143d4a2de = 0x3ff;
  pu_v7 = CRI_ADDR(DAT_143d4a2e0);
  for (l_v4 = 0x10; l_v4 != 0; l_v4 = l_v4 + -1) {
    *pu_v7 = 0x100;
    pu_v7 = pu_v7 + 1;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140063eb0
cri_u8 FUN_140063eb0(cri_any cri_p0, ...)
{
  cri_u2 *arg1 = cri_p0;
  *arg1 = 0;
  arg1[1] = 0;
  arg1[2] = 0xe709;
  arg1[3] = 0xdb09;
  arg1[4] = 0xfb09;
  arg1[5] = 0xf709;
  arg1[6] = 0xef09;
  arg1[7] = 0xdf09;
  arg1[8] = 0xba08;
  arg1[9] = 0xba08;
  arg1[10] = 0xb608;
  arg1[0xb] = 0xb608;
  arg1[0xc] = 0xae08;
  arg1[0xd] = 0xae08;
  arg1[0xe] = 0x9e08;
  arg1[0xf] = 0x9e08;
  arg1[0x10] = 0x7908;
  arg1[0x11] = 0x7908;
  arg1[0x12] = 0x7508;
  arg1[0x13] = 0x7508;
  arg1[0x14] = 0x6d08;
  arg1[0x15] = 0x6d08;
  arg1[0x16] = 0x5d08;
  arg1[0x17] = 0x5d08;
  arg1[0x18] = 0xa608;
  arg1[0x19] = 0xa608;
  arg1[0x1a] = 0x9a08;
  arg1[0x1b] = 0x9a08;
  arg1[0x1c] = 0x6508;
  arg1[0x1d] = 0x6508;
  arg1[0x1e] = 0x5908;
  arg1[0x1f] = 0x5908;
  arg1[0x20] = 0xeb08;
  arg1[0x21] = 0xeb08;
  arg1[0x22] = 0xd708;
  arg1[0x23] = 0xd708;
  arg1[0x24] = 0xf308;
  arg1[0x25] = 0xf308;
  arg1[0x26] = 53000;
  arg1[0x27] = 53000;
  arg1[0x28] = 0xaa08;
  arg1[0x29] = 0xaa08;
  arg1[0x2a] = 0x9608;
  arg1[0x2b] = 0x9608;
  arg1[0x2c] = 0xb208;
  arg1[0x2d] = 0xb208;
  arg1[0x2e] = 0x8e08;
  arg1[0x2f] = 0x8e08;
  arg1[0x30] = 0x6908;
  arg1[0x31] = 0x6908;
  arg1[0x32] = 0x5508;
  arg1[0x33] = 0x5508;
  arg1[0x34] = 0x7108;
  arg1[0x35] = 0x7108;
  arg1[0x36] = 0x4d08;
  arg1[0x37] = 0x4d08;
  arg1[0x38] = 0xe308;
  arg1[0x39] = 0xe308;
  arg1[0x3a] = 0xd308;
  arg1[0x3b] = 0xd308;
  arg1[0x3c] = 0xcb08;
  arg1[0x3d] = 0xcb08;
  arg1[0x3e] = 0xc708;
  arg1[0x3f] = 0xc708;
  return (cri_u8)(arg1 + 0x40);
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064070
cri_u2 * FUN_140064070(cri_any cri_p0, ...)
{
  cri_u2 *arg1 = cri_p0;
  longlong l_v1;
  cri_u2 *pu_v2;
  
  *arg1 = 0xa207;
  arg1[1] = 0xa207;
  arg1[2] = 0xa207;
  arg1[3] = 0xa207;
  arg1[4] = 0x9207;
  arg1[5] = 0x9207;
  arg1[6] = 0x9207;
  arg1[7] = 0x9207;
  arg1[8] = 0x8a07;
  arg1[9] = 0x8a07;
  arg1[10] = 0x8a07;
  arg1[0xb] = 0x8a07;
  arg1[0xc] = 0x8607;
  arg1[0xd] = 0x8607;
  arg1[0xe] = 0x8607;
  arg1[0xf] = 0x8607;
  arg1[0x10] = 0x6107;
  arg1[0x11] = 0x6107;
  arg1[0x12] = 0x6107;
  arg1[0x13] = 0x6107;
  arg1[0x14] = 0x5107;
  arg1[0x15] = 0x5107;
  arg1[0x16] = 0x5107;
  arg1[0x17] = 0x5107;
  arg1[0x18] = 0x4907;
  arg1[0x19] = 0x4907;
  arg1[0x1a] = 0x4907;
  arg1[0x1b] = 0x4907;
  arg1[0x1c] = 0x4507;
  arg1[0x1d] = 0x4507;
  arg1[0x1e] = 0x4507;
  arg1[0x1f] = 0x4507;
  arg1[0x20] = 0xff06;
  arg1[0x21] = 0xff06;
  arg1[0x22] = 0xff06;
  arg1[0x23] = 0xff06;
  arg1[0x24] = 0xff06;
  arg1[0x25] = 0xff06;
  arg1[0x26] = 0xff06;
  arg1[0x27] = 0xff06;
  arg1[0x28] = 0xc306;
  arg1[0x29] = 0xc306;
  arg1[0x2a] = 0xc306;
  arg1[0x2b] = 0xc306;
  arg1[0x2c] = 0xc306;
  arg1[0x2d] = 0xc306;
  arg1[0x2e] = 0xc306;
  arg1[0x2f] = 0xc306;
  arg1[0x30] = 0x2406;
  arg1[0x31] = 0x2406;
  arg1[0x32] = 0x2406;
  arg1[0x33] = 0x2406;
  arg1[0x34] = 0x2406;
  arg1[0x35] = 0x2406;
  arg1[0x36] = 0x2406;
  arg1[0x37] = 0x2406;
  arg1[0x38] = 0x1806;
  arg1[0x39] = 0x1806;
  arg1[0x3a] = 0x1806;
  arg1[0x3b] = 0x1806;
  arg1[0x3c] = 0x1806;
  arg1[0x3d] = 0x1806;
  arg1[0x3e] = 0x1806;
  arg1[0x3f] = 0x1806;
  pu_v2 = arg1 + 0x40;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0xbe05;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x50;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x8205;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x60;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x7d05;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x70;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x4105;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x80;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x3805;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x90;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x3405;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0xa0;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x2c05;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0xb0;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x1c05;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0xc0;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x2805;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0xd0;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x1405;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0xe0;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x3005;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0xf0;
  for (l_v1 = 0x10; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0xc05;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x100;
  for (l_v1 = 0x20; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x2004;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x120;
  for (l_v1 = 0x20; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x1004;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x140;
  for (l_v1 = 0x20; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x804;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x160;
  for (l_v1 = 0x20; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x404;
    pu_v2 = pu_v2 + 1;
  }
  pu_v2 = arg1 + 0x180;
  for (l_v1 = 0x40; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x3c03;
    pu_v2 = pu_v2 + 1;
  }
  return arg1 + 0x1c0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064360
void FUN_140064360(cri_any cri_unused, ...)
{
  DAT_143d4a3bc = 0x76;
  DAT_143d4a3bd = 0x76;
  _DAT_143d4a340 = 0x1212121212121212;
  _DAT_143d4a348 = 0x1212121212121212;
  _DAT_143d4a350 = 0x1212121212121212;
  _DAT_143d4a358 = 0x1212121212121212;
  DAT_143d4a3be = 0x87;
  _DAT_143d4a360 = 0x2222222222222222;
  _DAT_143d4a368 = 0x2222222222222222;
  _DAT_143d4a370 = 0x2222222222222222;
  _DAT_143d4a378 = 0x2222222222222222;
  DAT_143d4a3bf = 0x87;
  _DAT_143d4a380 = 0x303030303030303;
  _DAT_143d4a388 = 0x303030303030303;
  _DAT_143d4a390 = 0x3333333333333333;
  _DAT_143d4a398 = 0x3333333333333333;
  _DAT_143d4a3a0 = 0x4343434343434343;
  _DAT_143d4a3a8 = 0x4343434343434343;
  _DAT_143d4a3b0 = 0x5454545454545454;
  _DAT_143d4a3b8 = 0x65656565;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064440
void FUN_140064440(cri_any cri_unused, ...)
{
  DAT_143d4a47c = 0x66;
  DAT_143d4a47d = 0x66;
  _DAT_143d4a400 = 0x202020202020202;
  _DAT_143d4a408 = 0x202020202020202;
  _DAT_143d4a410 = 0x202020202020202;
  _DAT_143d4a418 = 0x202020202020202;
  DAT_143d4a47e = 0x77;
  _DAT_143d4a420 = 0x1212121212121212;
  _DAT_143d4a428 = 0x1212121212121212;
  _DAT_143d4a430 = 0x1212121212121212;
  _DAT_143d4a438 = 0x1212121212121212;
  DAT_143d4a47f = 0x88;
  _DAT_143d4a440 = 0x2222222222222222;
  _DAT_143d4a448 = 0x2222222222222222;
  _DAT_143d4a450 = 0x2222222222222222;
  _DAT_143d4a458 = 0x2222222222222222;
  _DAT_143d4a460 = 0x3333333333333333;
  _DAT_143d4a468 = 0x3333333333333333;
  _DAT_143d4a470 = 0x4444444444444444;
  _DAT_143d4a478 = 0x55555555;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064510
void FUN_140064510(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 arg1 = cri_p0;
  cri_u4 arg2 = cri_p1;
  int i_v1;
  
  i_v1 = CONCAT31((int3)((uint)arg2 >> 8),0x12);
  memset(&DAT_143d4a480,i_v1,0x100);
  i_v1 = CONCAT31((int3)((uint)i_v1 >> 8),0x22);
  memset(&DAT_143d4a580,i_v1,0x100);
  i_v1 = CONCAT31((int3)((uint)i_v1 >> 8),3);
  memset(&DAT_143d4a680,i_v1,0x80);
  i_v1 = CONCAT31((int3)((uint)i_v1 >> 8),0x33);
  memset(&DAT_143d4a700,i_v1,0x80);
  memset(&DAT_143d4a780,CONCAT31((int3)((uint)i_v1 >> 8),0x43),0x80);
  _DAT_143d4a840 = 0x6565656565656565;
  _DAT_143d4a848 = 0x6565656565656565;
  _DAT_143d4a850 = 0x6565656565656565;
  _DAT_143d4a858 = 0x6565656565656565;
  _DAT_143d4a800 = 0x5454545454545454;
  _DAT_143d4a860 = 0x7676767676767676;
  _DAT_143d4a868 = 0x7676767676767676;
  _DAT_143d4a870 = 0x8787878787878787;
  _DAT_143d4a808 = 0x5454545454545454;
  _DAT_143d4a810 = 0x5454545454545454;
  _DAT_143d4a818 = 0x5454545454545454;
  _DAT_143d4a820 = 0x5454545454545454;
  _DAT_143d4a878 = 0x98989898;
  _DAT_143d4a828 = 0x5454545454545454;
  _DAT_143d4a830 = 0x5454545454545454;
  _DAT_143d4a838 = 0x5454545454545454;
  DAT_143d4a87c = 0xa9;
  DAT_143d4a87d = 0xa9;
  DAT_143d4a87e = 0xb9;
  DAT_143d4a87f = 0xb9;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064640
void FUN_140064640(cri_any cri_p0, cri_any cri_p1, ...)
{
  cri_u8 arg1 = cri_p0;
  cri_u4 arg2 = cri_p1;
  int i_v1;
  
  i_v1 = CONCAT31((int3)((uint)arg2 >> 8),2);
  memset(&DAT_143d49580,i_v1,0x100);
  i_v1 = CONCAT31((int3)((uint)i_v1 >> 8),0x12);
  memset(&DAT_143d49680,i_v1,0x100);
  i_v1 = CONCAT31((int3)((uint)i_v1 >> 8),0x22);
  memset(&DAT_143d49780,i_v1,0x100);
  memset(&DAT_143d49880,CONCAT31((int3)((uint)i_v1 >> 8),0x33),0x80);
  _DAT_143d49940 = 0x5555555555555555;
  _DAT_143d49948 = 0x5555555555555555;
  _DAT_143d49950 = 0x5555555555555555;
  _DAT_143d49958 = 0x5555555555555555;
  _DAT_143d49900 = 0x4444444444444444;
  _DAT_143d49960 = 0x6666666666666666;
  _DAT_143d49968 = 0x6666666666666666;
  _DAT_143d49970 = 0x7777777777777777;
  _DAT_143d49908 = 0x4444444444444444;
  _DAT_143d49910 = 0x4444444444444444;
  _DAT_143d49918 = 0x4444444444444444;
  _DAT_143d49920 = 0x4444444444444444;
  _DAT_143d49978 = 0x88888888;
  _DAT_143d49928 = 0x4444444444444444;
  _DAT_143d49930 = 0x4444444444444444;
  _DAT_143d49938 = 0x4444444444444444;
  DAT_143d4997c = 0x99;
  DAT_143d4997d = 0x99;
  DAT_143d4997e = 0xaa;
  DAT_143d4997f = 0xba;
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064760
void FUN_140064760(cri_any cri_unused, ...)
{
  longlong l_v1;
  cri_u4 *pu_v2;
  
  _DAT_143d49d80 = 0;
  _DAT_143d49d88 = 0;
  _DAT_143d49d90 = 0x6404000064040;
  _DAT_143d49d98 = 0x6404000064040;
  _DAT_143d49da0 = 0x8020200080202;
  _DAT_143d49e00 = 0x9010d;
  _DAT_143d49da8 = 0x8010900080109;
  _DAT_143d49e04 = 0x90600;
  _DAT_143d49db0 = 0x8040000080400;
  _DAT_143d49e08 = 0x9010c;
  _DAT_143d49db8 = 0x8010800080108;
  _DAT_143d49e0c = 0x9010b;
  _DAT_143d49dc0 = 0x7010700070107;
  _DAT_143d49dc8 = 0x7010700070107;
  _DAT_143d49dd0 = 0x7010600070106;
  _DAT_143d49dd8 = 0x7010600070106;
  _DAT_143d49de0 = 0x7020100070201;
  _DAT_143d49de8 = 0x7020100070201;
  _DAT_143d49df0 = 0x7010500070105;
  _DAT_143d49df8 = 0x7010500070105;
  _DAT_143d49e20 = 0x6030000060300;
  _DAT_143d49e28 = 0x6030000060300;
  _DAT_143d49e30 = 0x6030000060300;
  _DAT_143d49e38 = 0x6030000060300;
  _DAT_143d49e10 = 0x90203;
  _DAT_143d49e40 = 0x6010400060104;
  _DAT_143d49e48 = 0x6010400060104;
  _DAT_143d49e50 = 0x6010400060104;
  _DAT_143d49e58 = 0x6010400060104;
  _DAT_143d49e14 = 0x90301;
  _DAT_143d49e60 = 0x6010300060103;
  _DAT_143d49e68 = 0x6010300060103;
  _DAT_143d49e70 = 0x6010300060103;
  _DAT_143d49e78 = 0x6010300060103;
  _DAT_143d49e18 = 0x90500;
  _DAT_143d49e80 = 0x5020000050200;
  _DAT_143d49e88 = 0x5020000050200;
  _DAT_143d49e90 = 0x5020000050200;
  _DAT_143d49e98 = 0x5020000050200;
  _DAT_143d49ea0 = 0x5020000050200;
  _DAT_143d49ea8 = 0x5020000050200;
  _DAT_143d49eb0 = 0x5020000050200;
  _DAT_143d49eb8 = 0x5020000050200;
  _DAT_143d49ec0 = 0x5010200050102;
  _DAT_143d49ec8 = 0x5010200050102;
  _DAT_143d49ed0 = 0x5010200050102;
  _DAT_143d49ed8 = 0x5010200050102;
  _DAT_143d49ee0 = 0x5010200050102;
  _DAT_143d49ee8 = 0x5010200050102;
  _DAT_143d49ef0 = 0x5010200050102;
  _DAT_143d49ef8 = 0x5010200050102;
  _DAT_143d49e1c = 0x9010a;
  pu_v2 = CRI_ADDR(DAT_143d49f00);
  for (l_v1 = 0x20; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x40101;
    pu_v2 = pu_v2 + 1;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064990
void thunk_FUN_140064760(cri_any cri_unused, ...)
{
  longlong l_v1;
  cri_u4 *pu_v2;
  
  _DAT_143d49d80 = 0;
  _DAT_143d49d88 = 0;
  _DAT_143d49d90 = 0x6404000064040;
  _DAT_143d49d98 = 0x6404000064040;
  _DAT_143d49da0 = 0x8020200080202;
  _DAT_143d49e00 = 0x9010d;
  _DAT_143d49da8 = 0x8010900080109;
  _DAT_143d49e04 = 0x90600;
  _DAT_143d49db0 = 0x8040000080400;
  _DAT_143d49e08 = 0x9010c;
  _DAT_143d49db8 = 0x8010800080108;
  _DAT_143d49e0c = 0x9010b;
  _DAT_143d49dc0 = 0x7010700070107;
  _DAT_143d49dc8 = 0x7010700070107;
  _DAT_143d49dd0 = 0x7010600070106;
  _DAT_143d49dd8 = 0x7010600070106;
  _DAT_143d49de0 = 0x7020100070201;
  _DAT_143d49de8 = 0x7020100070201;
  _DAT_143d49df0 = 0x7010500070105;
  _DAT_143d49df8 = 0x7010500070105;
  _DAT_143d49e20 = 0x6030000060300;
  _DAT_143d49e28 = 0x6030000060300;
  _DAT_143d49e30 = 0x6030000060300;
  _DAT_143d49e38 = 0x6030000060300;
  _DAT_143d49e10 = 0x90203;
  _DAT_143d49e40 = 0x6010400060104;
  _DAT_143d49e48 = 0x6010400060104;
  _DAT_143d49e50 = 0x6010400060104;
  _DAT_143d49e58 = 0x6010400060104;
  _DAT_143d49e14 = 0x90301;
  _DAT_143d49e60 = 0x6010300060103;
  _DAT_143d49e68 = 0x6010300060103;
  _DAT_143d49e70 = 0x6010300060103;
  _DAT_143d49e78 = 0x6010300060103;
  _DAT_143d49e18 = 0x90500;
  _DAT_143d49e80 = 0x5020000050200;
  _DAT_143d49e88 = 0x5020000050200;
  _DAT_143d49e90 = 0x5020000050200;
  _DAT_143d49e98 = 0x5020000050200;
  _DAT_143d49ea0 = 0x5020000050200;
  _DAT_143d49ea8 = 0x5020000050200;
  _DAT_143d49eb0 = 0x5020000050200;
  _DAT_143d49eb8 = 0x5020000050200;
  _DAT_143d49ec0 = 0x5010200050102;
  _DAT_143d49ec8 = 0x5010200050102;
  _DAT_143d49ed0 = 0x5010200050102;
  _DAT_143d49ed8 = 0x5010200050102;
  _DAT_143d49ee0 = 0x5010200050102;
  _DAT_143d49ee8 = 0x5010200050102;
  _DAT_143d49ef0 = 0x5010200050102;
  _DAT_143d49ef8 = 0x5010200050102;
  _DAT_143d49e1c = 0x9010a;
  pu_v2 = CRI_ADDR(DAT_143d49f00);
  for (l_v1 = 0x20; l_v1 != 0; l_v1 = l_v1 + -1) {
    *pu_v2 = 0x40101;
    pu_v2 = pu_v2 + 1;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400649a0
void FUN_1400649a0(cri_any cri_unused, ...)
{
  DAT_143d74a30 = CRI_ADDR(DAT_143d4a880);
  DAT_143d749f0 = CRI_ADDR(DAT_143d4a240);
  DAT_143d74a00 = CRI_ADDR(DAT_143d4aa80);
  DAT_143d749f8 = CRI_ADDR(DAT_143d4a200);
  DAT_143d749e0 = CRI_ADDR(DAT_143d49f80);
  DAT_143d749d8 = CRI_ADDR(DAT_143d4a3c0);
  DAT_143d749d0 = CRI_ADDR(DAT_143d4a300);
  DAT_143d74a08 = CRI_ADDR(DAT_143d4a080);
  DAT_143d74a38 = CRI_ADDR(DAT_143d4a100);
  DAT_143d749c8 = CRI_ADDR(DAT_143d4a2c0);
  DAT_143d74a20 = CRI_ADDR(DAT_143d49980);
  DAT_143d749e8 = CRI_ADDR(DAT_143d4a340);
  DAT_143d74a28 = CRI_ADDR(DAT_143d4a400);
  DAT_143d74a48 = CRI_ADDR(DAT_143d4a480);
  DAT_143d74a18 = CRI_ADDR(DAT_143d49580);
  DAT_143d74a50 = CRI_ADDR(DAT_1431bbbd8);
  DAT_143d749c0 = CRI_ADDR(DAT_1431bbbf8);
  DAT_143d749b8 = CRI_ADDR(DAT_1431bbc18);
  DAT_143d74a58 = CRI_ADDR(DAT_1431bbc38);
  DAT_143d74a10 = CRI_ADDR(DAT_1431bbc58);
  DAT_143d74a40 = CRI_ADDR(DAT_1431bbc78);
  DAT_143d74a60 = CRI_ADDR(DAT_143d49d80);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064ae0
longlong FUN_140064ae0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  DAT_143d74a60 = arg1 + -0x200;
  FUN_140064dd0(DAT_143d74a60,&DAT_143d49d80,0x80);
  DAT_143d74a40 = arg1 + -0x210;
  FUN_140064dd0(DAT_143d74a40,&DAT_1431bbc78,4);
  DAT_143d74a10 = arg1 + -0x230;
  FUN_140064dd0(DAT_143d74a10,&DAT_1431bbc58,8);
  DAT_143d74a58 = arg1 + -0x250;
  FUN_140064dd0(DAT_143d74a58,&DAT_1431bbc38,8);
  DAT_143d749b8 = arg1 + -0x270;
  FUN_140064dd0(DAT_143d749b8,&DAT_1431bbc18,8);
  DAT_143d749c0 = arg1 + -0x290;
  FUN_140064dd0(DAT_143d749c0,&DAT_1431bbbf8,8);
  arg1 = arg1 + -0x2b0;
  DAT_143d74a50 = arg1;
  FUN_140064dd0(arg1,&DAT_1431bbbd8,8);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064be0
longlong FUN_140064be0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  DAT_143d749e8 = arg1 + -0x80;
  FUN_140064dd0(DAT_143d749e8,&DAT_143d4a340,0x20);
  arg1 = arg1 + -0x100;
  DAT_143d74a28 = arg1;
  FUN_140064dd0(arg1,&DAT_143d4a400,0x20);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064c30
longlong FUN_140064c30(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  DAT_143d74a38 = arg1 + -0x100;
  FUN_140064dd0(DAT_143d74a38,&DAT_143d4a100,0x40);
  arg1 = arg1 + -0x140;
  DAT_143d749c8 = arg1;
  FUN_140064dd0(arg1,&DAT_143d4a2c0,0x10);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064c90
longlong FUN_140064c90(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  DAT_143d749d0 = arg1 + -0x40;
  FUN_140064dd0(DAT_143d749d0,&DAT_143d4a300,0x10);
  arg1 = arg1 + -0xc0;
  DAT_143d74a08 = arg1;
  FUN_140064dd0(arg1,&DAT_143d4a080,0x20);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064ce0
void FUN_140064ce0(cri_any cri_unused, ...)
{
  FUN_1400630d0();
  FUN_1400633e0();
  FUN_140063730();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064d00
void FUN_140064d00(cri_any cri_unused, ...)
{
  FUN_140063aa0();
  FUN_140063b60();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064d20
void FUN_140064d20(cri_any cri_unused, ...)
{
  cri_u8 u_v1;
  
  u_v1 = FUN_140063eb0(&DAT_143d49980);
  FUN_140064070(u_v1);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064d40
void FUN_140064d40(cri_any cri_unused, ...)
{
  FUN_140064360();
  FUN_140064440();
  FUN_140064510();
  FUN_140064640();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064d60
void FUN_140064d60(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  cri_u8 u_v1;
  
  u_v1 = FUN_140064ae0(arg1 + 0x5b0);
  u_v1 = FUN_140064be0(u_v1);
  u_v1 = FUN_140064c30(u_v1);
  FUN_140064c90(u_v1);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064d90
void FUN_140064d90(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  FUN_140064ce0();
  FUN_140064d00();
  FUN_140063cb0();
  FUN_140064d20();
  FUN_140064d40();
  FUN_140064760();
  FUN_1400649a0();
  if (arg1 != 0) {
    FUN_140064d60(arg1);
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064dd0
void FUN_140064dd0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  cri_u4 *arg1 = cri_p0;
  cri_u4 *arg2 = cri_p1;
  ulonglong arg3 = cri_p2;
  cri_u4 u_v1;
  cri_u4 u_v2;
  cri_u4 u_v3;
  ulonglong u_v4;
  ulonglong u_v5;
  
  u_v5 = (ulonglong)((uint)arg3 & 0xf);
  u_v4 = arg3 & 0xf;
  while (u_v4 != 0) {
    u_v1 = *arg2;
    arg2 = arg2 + 1;
    *arg1 = u_v1;
    u_v5 = u_v5 - 1;
    arg1 = arg1 + 1;
    u_v4 = u_v5;
  }
  for (arg3 = arg3 >> 4; arg3 != 0; arg3 = arg3 - 1) {
    u_v1 = arg2[1];
    u_v2 = arg2[2];
    u_v3 = arg2[3];
    *arg1 = *arg2;
    arg1[1] = u_v1;
    arg1[2] = u_v2;
    arg1[3] = u_v3;
    u_v1 = arg2[5];
    u_v2 = arg2[6];
    u_v3 = arg2[7];
    arg1[4] = arg2[4];
    arg1[5] = u_v1;
    arg1[6] = u_v2;
    arg1[7] = u_v3;
    u_v1 = arg2[9];
    u_v2 = arg2[10];
    u_v3 = arg2[0xb];
    arg1[8] = arg2[8];
    arg1[9] = u_v1;
    arg1[10] = u_v2;
    arg1[0xb] = u_v3;
    u_v1 = arg2[0xd];
    u_v2 = arg2[0xe];
    u_v3 = arg2[0xf];
    arg1[0xc] = arg2[0xc];
    arg1[0xd] = u_v1;
    arg1[0xe] = u_v2;
    arg1[0xf] = u_v3;
    arg1 = arg1 + 0x10;
    arg2 = arg2 + 0x10;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064eb0
void * FUN_140064eb0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  void *arg1 = cri_p0;
  void *arg2 = cri_p1;
  size_t arg3 = cri_p2;
  memcpy(arg1,arg2,arg3);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064ed0
void * FUN_140064ed0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  void *arg1 = cri_p0;
  void *arg2 = cri_p1;
  size_t arg3 = cri_p2;
  memcpy(arg1,arg2,arg3);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064ef0
void * FUN_140064ef0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  void *arg1 = cri_p0;
  void *arg2 = cri_p1;
  size_t arg3 = cri_p2;
  memcpy(arg1,arg2,arg3);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064f10
void * FUN_140064f10(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  void *arg1 = cri_p0;
  void *arg2 = cri_p1;
  size_t arg3 = cri_p2;
  memcpy(arg1,arg2,arg3);
  return arg1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064f70
void FUN_140064f70(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  cri_u4 arg2 = cri_p1;
  ulonglong arg3 = cri_p2;
  ulonglong u_v1;
  cri_u4 *pu_v2;
  ulonglong u_v3;
  
  pu_v2 = (cri_u4 *)(arg1 + arg3 * 4);
  u_v3 = (ulonglong)((uint)arg3 & 0xf);
  u_v1 = arg3 & 0xf;
  while (u_v1 != 0) {
    pu_v2 = pu_v2 + -1;
    *pu_v2 = arg2;
    u_v3 = u_v3 - 1;
    u_v1 = u_v3;
  }
  for (arg3 = arg3 >> 4; arg3 != 0; arg3 = arg3 - 1) {
    pu_v2[-1] = arg2;
    pu_v2[-2] = arg2;
    pu_v2[-3] = arg2;
    pu_v2[-4] = arg2;
    pu_v2[-5] = arg2;
    pu_v2[-6] = arg2;
    pu_v2[-7] = arg2;
    pu_v2[-8] = arg2;
    pu_v2[-9] = arg2;
    pu_v2[-10] = arg2;
    pu_v2[-0xb] = arg2;
    pu_v2[-0xc] = arg2;
    pu_v2[-0xd] = arg2;
    pu_v2[-0xe] = arg2;
    pu_v2[-0xf] = arg2;
    pu_v2 = pu_v2 + -0x10;
    *pu_v2 = arg2;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064fe0
void thunk_FUN_140050520(cri_any cri_unused, ...)
{
  int i_v1;
  cri_u4 u_v2;
  longlong l_v3;
  cri_u4 *pu_v4;
  ulonglong u_v5;
  uint u_v6;
  ulonglong u_v7;
  
  DAT_143c49100 = DAT_143c49100 + 1;
  if ((DAT_143c49100 == 1) && (i_v1 = FUN_1400501f0(), 1 < i_v1)) {
    DAT_143c490f8 = (void*)FUN_1400682e0(&DAT_143badb88,0x30);  // edx = 0x30 in the exe
    DAT_143c490f0 = CRI_ADDR(DAT_143badf80);
    memset(&DAT_143badf80,0,0x9b100);
    DAT_143c490e0 = CRI_ADDR(DAT_143badc00);
    memset(&DAT_143badc00,0,0x300);
    DAT_143badbdc = 3;
    FUN_1400677f0();
    u_v5 = 0;
    DAT_143badb84 = DAT_143badbdc;
    if (0 < DAT_143badbdc) {
      pu_v4 = CRI_ADDR(DAT_143badbbc);
      u_v7 = u_v5;
      while( true ) {
        l_v3 = FUN_140067890(DAT_143c490e0 + (longlong)(int)u_v7 * 0x20 + 2,0x7c);
        *(longlong *)(u_v5 + (longlong)DAT_143c490e0) = l_v3;
        if (l_v3 == 0) break;
        pu_v4[-1] = 0xffffffff;
        u_v2 = FUN_140067f40(l_v3);
        u_v6 = (int)u_v7 + 1;
        u_v7 = (ulonglong)u_v6;
        *pu_v4 = u_v2;
        u_v5 = u_v5 + 0x100;
        pu_v4 = pu_v4 + 3;
        if (DAT_143badbdc <= (int)u_v6) {
          return;
        }
      }
      FUN_14004ff50(0,0xff030602);
    }
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140064ff0
void thunk_FUN_140050670(cri_any cri_unused, ...)
{
  int i_v1;
  longlong l_v2;
  longlong l_v3;
  longlong l_v4;
  
  DAT_143c49100 = DAT_143c49100 + -1;
  if (DAT_143c49100 == 0) {
    i_v1 = FUN_1400501f0();
    if (i_v1 < 2) {
      return;
    }
    if (DAT_143c490f8 != 0) {
      FUN_140068380(DAT_143c490f8);  // rcx = the handle just tested
      DAT_143c490f8 = 0;
    }
    l_v4 = (longlong)(DAT_143badbdc + -1);
    if (-1 < DAT_143badbdc + -1) {
      l_v3 = l_v4 << 8;
      l_v2 = DAT_143c490e0;
      do {
        if (*(longlong *)(l_v3 + l_v2) != 0) {
          FUN_140067a90(*(longlong *)(l_v3 + l_v2));  // rcx = the slot just tested
          l_v2 = DAT_143c490e0;
          *(cri_u8 *)(l_v3 + DAT_143c490e0) = 0;
        }
        l_v3 = l_v3 + -0x100;
        l_v4 = l_v4 + -1;
      } while (-1 < l_v4);
    }
    FUN_140067840();
  }
  if (DAT_143c49100 < 0) {
    DAT_143c49100 = 0;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065000
void FUN_140065000(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  longlong l_v1;
  
  l_v1 = FUN_140050730();
  *(longlong *)((char *)arg1 + 0x18f8) = l_v1;
  if (l_v1 != 0) {
    FUN_140050210(l_v1,*(cri_u4 *)((char *)arg1 + 0x1574));
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065030
void FUN_140065030(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  if (*(longlong *)((char *)arg1 + 0x18f8) != 0) {
    FUN_140050310();
    *(cri_u8 *)((char *)arg1 + 0x18f8) = 0;
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065060
void FUN_140065060(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  longlong *arg2 = cri_p1;
  int *arg3 = cri_p2;
  cri_u1 u_v1;
  cri_u1 u_v2;
  cri_u1 u_v3;
  cri_u1 u_v4;
  int i_v5;
  int i_v6;
  byte b_v7;
  int i_v8;
  int i_v9;
  uint u_v10;
  uint u_v11;
  int i_v12;
  cri_u1 *pu_v13;
  cri_u1 *pu_v14;
  uint u_v15;
  cri_u1 loc_48 [16];
  
  arg3[3] = -1;
  *arg3 = 0;
  arg3[1] = 0;
  arg3[2] = 0;
  arg3[5] = 0;
  arg3[4] = -1;
  i_v5 = *(int *)((char *)arg1 + 0x162c);
  i_v6 = *(int *)((char *)arg1 + 0x1630);
  *(cri_u4 *)((char *)arg1 + 0x18ec) = 0;
  *(cri_u4 *)((char *)arg1 + 0x1830) = *(cri_u4 *)((char *)arg1 + 0x1580);
  (**(cri_code **)(*arg2 + 0x30))(arg2,1,0x7fffffff,arg1 + 0x1800);
  pu_v13 = (cri_u1 *)(*(ulonglong *)((char *)arg1 + 0x1800) & 0xfffffffffffffffc);
  i_v12 = *(int *)((char *)arg1 + 0x1800) * 8 + (int)pu_v13 * -8;
  b_v7 = (byte)i_v12;
  u_v15 = CONCAT31(CONCAT21(CONCAT11(*pu_v13,pu_v13[1]),pu_v13[2]),pu_v13[3]) << (b_v7 & 0x1f)
  ;
  u_v10 = CONCAT31(CONCAT21(CONCAT11(pu_v13[4],pu_v13[5]),pu_v13[6]),pu_v13[7]);
  if (i_v12 != 0) {
    u_v15 = u_v10 >> (0x20 - b_v7 & 0x1f) | u_v15;
    u_v10 = u_v10 << (b_v7 & 0x1f);
  }
  u_v1 = pu_v13[9];
  u_v2 = pu_v13[8];
  i_v8 = (u_v15 & 0xff) - 1;
  pu_v14 = pu_v13 + 0xc;
  u_v3 = pu_v13[10];
  u_v4 = pu_v13[0xb];
  *(int *)((char *)arg1 + 0x1798) = i_v8;
  *(cri_u4 *)((char *)arg1 + 0x179c) = 0xffffffff;
  u_v15 = CONCAT31(CONCAT21(CONCAT11(u_v2,u_v1),u_v3),u_v4);
  *(int *)((char *)arg1 + 0x1794) = *(int *)((char *)arg1 + 0x15a0) * i_v8 + -1;
  if (i_v12 < 0x1b) {
    i_v12 = i_v12 + 5;
    u_v11 = u_v10 << 5;
    *(uint *)((char *)arg1 + 0x1748) = u_v10 >> 0x1b;
  }
  else {
    i_v12 = i_v12 + -0x1b;
    if (i_v12 == 0) {
      *(uint *)((char *)arg1 + 0x1748) = u_v10 >> 0x1b;
      u_v11 = u_v15;
    }
    else {
      *(uint *)((char *)arg1 + 0x1748) = (u_v15 >> (5 - (byte)i_v12 & 0x1f) | u_v10) >> 0x1b;
      u_v11 = u_v15 << ((byte)i_v12 & 0x1f);
    }
    u_v15 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v13[0xd]),pu_v13[0xe]),pu_v13[0xf]);
    pu_v14 = pu_v13 + 0x10;
  }
  FUN_142ccb4f0(arg1 + 0x174c);
  FUN_142ccb4f0(arg1 + 6000);
  FUN_142ccb500(arg1);
  if ((int)u_v11 < 0) {
    i_v8 = i_v12 + 7;
    do {
      i_v9 = i_v8 + 9;
      if (i_v12 + 9 < 0x20) {
        u_v11 = u_v11 << 9;
        i_v12 = i_v12 + 9;
      }
      else {
        i_v9 = i_v8 + -0x17;
        u_v11 = u_v15 << ((byte)(i_v12 + -0x17) & 0x1f);
        u_v15 = CONCAT31(CONCAT21(CONCAT11(*pu_v14,pu_v14[1]),pu_v14[2]),pu_v14[3]);
        pu_v14 = pu_v14 + 4;
        i_v12 = i_v12 + -0x17;
      }
      if (*(int *)((char *)arg1 + 0x1808) <=
          ((i_v9 >> 3) - *(int *)((char *)arg1 + 0x1800)) + -8 + (int)pu_v14) {
        return;
      }
      i_v8 = i_v9;
    } while ((int)u_v11 < 0);
  }
  i_v8 = (int)pu_v14;
  u_v15 = i_v12 + 1;
  if (0x1f < (int)u_v15) {
    u_v15 = i_v12 - 0x1f;
    i_v8 = i_v8 + 4;
  }
  *(uint *)((char *)arg1 + 0x1810) = u_v15 & 7;
  FUN_140069020(arg1 + 0x1800,
                (((int)((u_v15 - (u_v15 & 7)) + 7) >> 3) - *(int *)((char *)arg1 + 0x1800)) + -8 +
                i_v8,arg1 + 0x1800,loc_48);
  (**(cri_code **)(*arg2 + 0x40))(arg2,0,arg1 + 0x1800);
  (**(cri_code **)(*arg2 + 0x38))(arg2,1,loc_48);
  (**(cri_code **)((char *)arg1 + 0x16f0))(arg1,arg2);
  if (*(int *)((char *)arg1 + 0x17a0) <= *(int *)((char *)arg1 + 0x1794)) {
    arg3[5] = 1;
  }
  *arg3 = *(int *)((char *)arg1 + 0x162c) - i_v5;
  arg3[1] = *(int *)((char *)arg1 + 0x1630) - i_v6;
  arg3[2] = *(int *)((char *)arg1 + 0x18ec);
  FUN_1400663d0(arg1,arg3 + 3,arg3 + 4);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400653b0
void * FUN_1400653b0(cri_any cri_p0, cri_any cri_p1, ...)
{
  void *arg1 = cri_p0;
  int arg2 = cri_p1;
  void *_Dst;
  
  _Dst = (void *)((longlong)arg2 * 0x1980 + (longlong)arg1);
  memcpy(_Dst,arg1,0x1900);
  FUN_14004de60(_Dst);
  FUN_14004dfc0(_Dst);
  return _Dst;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065410
void FUN_140065410(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  cri_u4 arg2 = cri_p1;
  int arg3 = cri_p2;
  if (arg1 != 0) {
    *(cri_u4 *)((char *)arg1 + 0x18dc) = arg2;
    *(int *)((char *)arg1 + 0x1794) = arg3;
    *(int *)((char *)arg1 + 0x1798) = arg3 / *(int *)((char *)arg1 + 0x15a0);
    *(int *)((char *)arg1 + 0x179c) = arg3 % *(int *)((char *)arg1 + 0x15a0);
    (**(cri_code **)((char *)arg1 + 0x18d0))(arg1,arg3 % *(int *)((char *)arg1 + 0x15a0),arg3);  // the exe leaves rcx = arg1, edx = the idiv remainder, r8d = arg3
  }
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065450
cri_u8 FUN_140065450(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  longlong *arg2 = cri_p1;
  uint u_v1;
  int i_v2;
  cri_u8 u_v3;
  ulonglong u_v4;
  uint u_v5;
  int i_v6;
  // one frame (exe rsp+0x20..0x72): &loc_68 and loc_58 are out-structs, &loc_40 is the FUN_140050820 context
  __declspec(align(16)) cri_u8 frame_[0x58];
  longlong &loc_68 = *(longlong *)(frame_ + 0);
  int &loc_60 = *(int *)(frame_ + 8);
  cri_u1 (&loc_58)[8] = *(cri_u1 (*)[8])(frame_ + 16);
  int &loc_50 = *(int *)(frame_ + 24);
  int &loc_44 = *(int *)(frame_ + 36);
  longlong &loc_40 = *(longlong *)(frame_ + 40);
  cri_u1 **&loc_38 = *(cri_u1 ** *)(frame_ + 48);
  cri_u4 &loc_30 = *(cri_u4 *)(frame_ + 56);
  cri_u4 &loc_2c = *(cri_u4 *)(frame_ + 60);
  cri_u4 &loc_28 = *(cri_u4 *)(frame_ + 64);
  int &loc_24 = *(int *)(frame_ + 68);
  int &loc_20 = *(int *)(frame_ + 72);
  int &loc_1c = *(int *)(frame_ + 76);
  cri_u2 &loc_18 = *(cri_u2 *)(frame_ + 80);
  
  FUN_140066370(arg1);  // the exe passes rcx through
  if (*(longlong *)((char *)arg1 + 0x18f8) != 0) {
    FUN_140050210(*(longlong *)((char *)arg1 + 0x18f8),*(cri_u4 *)((char *)arg1 + 0x1574));
    loc_38 = &PTR_FUN_143a4a0d8;
    loc_2c = *(cri_u4 *)((char *)arg1 + 0x17a0);
    loc_28 = *(cri_u4 *)((char *)arg1 + 0x159c);
    loc_30 = 1;
    loc_40 = arg1;
    u_v3 = FUN_140050820(*(cri_u8 *)((char *)arg1 + 0x18f8),arg2,arg1 + 0x1638,&loc_40);
    if (loc_24 != 0) {
      *(int *)((char *)arg1 + 0x162c) = *(int *)((char *)arg1 + 0x162c) + loc_20;
      *(int *)((char *)arg1 + 0x1630) = *(int *)((char *)arg1 + 0x1630) + loc_1c;
      *(cri_u2 *)((char *)arg1 + 0x16a8) = loc_18;
      return u_v3;
    }
  }
  i_v6 = 0;
  *(cri_u2 *)((char *)arg1 + 0x16a8) = 0;
  i_v2 = *(int *)((char *)arg1 + 0x18f0);
  u_v1 = 0x101;
  while( true ) {
    if (i_v2 != 0) {
      return 0;
    }
    i_v2 = FUN_140052950(arg1,0xffffffff,arg2);
    if (i_v2 != 0) {
      u_v3 = FUN_14004ff50(arg1,i_v2);
      return u_v3;
    }
    (**(cri_code **)(*arg2 + 0x30))(arg2,1,0x7fffffff,&loc_68);
    (**(cri_code **)(*arg2 + 0x38))(arg2,1,&loc_68);
    if ((loc_60 < 4) || (u_v4 = FUN_140053000(loc_68), (u_v4 & 1) == 0)) break;
    u_v5 = *(byte *)(loc_68 + 3) | 0x100;
    if (u_v5 < u_v1) {
      *(int *)((char *)arg1 + 0x162c) = *(int *)((char *)arg1 + 0x162c) + 1;
      break;
    }
    *(short *)((char *)arg1 + 0x16a8) = *(short *)((char *)arg1 + 0x16a8) + 1;
    FUN_140065060(arg1,arg2,loc_58);
    i_v6 = i_v6 + loc_50;
    if (loc_44 != 0) break;
    i_v2 = *(int *)((char *)arg1 + 0x18f0);
    loc_44 = 0;
    u_v1 = u_v5;
  }
  if (*(int *)((char *)arg1 + 0x1794) != *(int *)((char *)arg1 + 0x17a0)) {
    *(int *)((char *)arg1 + 0x162c) = *(int *)((char *)arg1 + 0x162c) + 1;
    *(int *)((char *)arg1 + 0x1794) = *(int *)((char *)arg1 + 0x17a0) + 1;
    *(cri_u4 *)((char *)arg1 + 0x179c) = 0;
    *(cri_u4 *)((char *)arg1 + 0x1798) = *(cri_u4 *)((char *)arg1 + 0x15a4);
    (**(cri_code **)((char *)arg1 + 0x18d0))(arg1);
  }
  if (i_v6 == 0) {
    return 0;
  }
  *(int *)((char *)arg1 + 0x162c) = *(int *)((char *)arg1 + 0x162c) + i_v6;
  return 0;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065660
void FUN_140065660(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  cri_u8 arg2 = cri_p1;
  int *arg3 = cri_p2;
  int i_v1;
  ulonglong u_v2;
  int local_res8 [2];
  int local_res18 [2];
  // FUN_140065060 fills one 6-int struct at rsp+0x20 in the exe.
  __declspec(align(16)) cri_u8 frame_[0x18];
  int &loc_28 = *(int *)(frame_ + 0);
  int &loc_24 = *(int *)(frame_ + 4);
  int &loc_20 = *(int *)(frame_ + 8);
  int &loc_1c = *(int *)(frame_ + 12);
  int &loc_18 = *(int *)(frame_ + 16);
  int &loc_14 = *(int *)(frame_ + 20);
  
  *arg3 = 0;
  arg3[1] = 0;
  arg3[2] = 0;
  arg3[3] = -1;
  arg3[4] = -1;
  arg3[5] = 0;
  u_v2 = FUN_140051ec0(arg2,local_res18);
  if ((u_v2 & 1) == 0) {
    return;
  }
  FUN_1400663b0(arg1);
  do {
    FUN_140065060(arg1,arg2,&loc_28);
    arg3[1] = arg3[1] + loc_24;
    *arg3 = *arg3 + loc_28;
    arg3[2] = arg3[2] + loc_20;
    i_v1 = loc_20 + loc_28;
    if (i_v1 != 0) {
      *(int *)((char *)arg1 + 0x162c) = *(int *)((char *)arg1 + 0x162c) + i_v1;
      if (*(int *)((char *)arg1 + 0x1544) == 0) {
LAB_140065742:
        arg3[5] = loc_14;
        arg3[3] = loc_1c;
        arg3[4] = loc_18;
        return;
      }
      *(int *)((char *)arg1 + 0x1630) = *(int *)((char *)arg1 + 0x1630) + i_v1;
    }
    if ((((loc_14 != 0) || (*(int *)((char *)arg1 + 0x18f0) != 0)) ||
        (i_v1 = FUN_140052950(arg1,0xffffffff,arg2), i_v1 != 0)) ||
       (FUN_140051ec0(arg2,local_res8), local_res18[0] != local_res8[0])) goto LAB_140065742;
  } while( true );
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065770
void FUN_140065770(cri_any cri_unused, ...)
{
  FUN_140059090();
  FUN_140059290();
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065790
void FUN_140065790(cri_any cri_unused, ...)
{
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400657a0
void FUN_1400657a0(cri_any cri_p0, ...)
{
  longlong arg1 = cri_p0;
  *(cri_u8 *)((char *)arg1 + 0x16b0) = *(cri_u8 *)((char *)arg1 + 0x1678);
  *(cri_u8 *)((char *)arg1 + 0x16b8) = *(cri_u8 *)((char *)arg1 + 0x1680);
  *(cri_u8 *)((char *)arg1 + 0x16c0) = *(cri_u8 *)((char *)arg1 + 0x1688);
  *(cri_u8 *)((char *)arg1 + 0x16c8) = *(cri_u8 *)((char *)arg1 + 0x1690);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400657e0
void FUN_1400657e0(cri_any cri_unused, ...)
{
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065800
void FUN_140065800(cri_any cri_unused, ...)
{
  double d_v1;
  double *pd_v2;
  double *pd_v3;
  double *pd_v4;
  
  pd_v4 = (double *)&DAT_1431bbc90;
  pd_v2 = (double *)&DAT_143d4abf8;
  do {
    d_v1 = *pd_v4;
    pd_v3 = pd_v2 + 8;
    pd_v4 = pd_v4 + 1;
    *pd_v2 = d_v1 * 0.4903926402016152;
    pd_v2[1] = d_v1 * 0.46193976625564337;
    pd_v2[2] = d_v1 * 0.4157348061512726;
    pd_v2[-1] = d_v1 * 0.3535533905932738;
    pd_v2[3] = d_v1 * 0.3535533905932738;
    pd_v2[5] = d_v1 * 0.1913417161825449;
    pd_v2[4] = d_v1 * 0.2777851165098011;
    pd_v2[6] = d_v1 * 0.09754516100806414;
    pd_v2 = pd_v3;
  } while ((longlong)pd_v3 < ((longlong)&DAT_143d4adf8));
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065900
void FUN_140065900(cri_any cri_p0, ...)
{
  void *arg1 = cri_p0;
  memset(arg1,0,0x78);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065940
int FUN_140065940(cri_any cri_p0, ...)
{
  int arg1 = cri_p0;
  int i_v1;
  uint u_v2;
  uint u_v3;
  uint u_v4;
  uint u_v5;
  
  u_v4 = arg1 >> 0x1f & 7;
  u_v2 = arg1 + u_v4;
  u_v5 = (int)u_v2 >> 0x1f & 3;
  u_v3 = ((int)u_v2 >> 3) + u_v5;
  i_v1 = ((u_v3 & 3) - u_v5) + (((u_v2 & 7) - u_v4) + ((int)u_v3 >> 2) * 8) * 4;
  if ((i_v1 < 0) || (0xff < i_v1)) {
    FUN_140095450(0xff040003);
  }
  return i_v1;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400659a0
void FUN_1400659a0(cri_any cri_p0, cri_any cri_p1, ...)
{
  longlong arg1 = cri_p0;
  cri_u1 *arg2 = cri_p1;
  cri_u1 u_v1;
  cri_u1 *pu_v2;
  longlong l_v3;
  
  l_v3 = 0x40;
  pu_v2 = arg2;
  do {
    u_v1 = FUN_140065940((int)(char)pu_v2[arg1 - (longlong)arg2]);
    l_v3 = l_v3 + -1;
    *pu_v2 = u_v1;
    pu_v2 = pu_v2 + 1;
  } while (l_v3 != 0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400659f0
void FUN_1400659f0(cri_any cri_unused, ...)
{
  DAT_143d4ab80 = CRI_ADDR(DAT_143d4ab90);
  memcpy(&DAT_143d4ab90,&DAT_1431bbcd0,0x50);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065a20
void FUN_140065a20(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, ...)
{
  longlong arg1 = cri_p0;
  longlong arg2 = cri_p1;
  longlong arg3 = cri_p2;
  V16 au_v1;
  V16 au_v2;
  float *pf_v3;
  float *pf_v4;
  longlong l_v5;
  cri_u8 *pu_v6;
  longlong l_v7;
  float *pf_v8;
  float f_v9;
  float f_v10;
  float f_v11;
  float f_v12;
  float f_v13;
  float f_v14;
  float f_v19;
  float f_v20;
  float f_v21;
  float f_v22;
  float f_v23;
  float f_v24;
  V16 au_v15;
  V16 au_v16;
  V16 au_v17;
  V16 au_v18;
  V16 au_v25;
  V16 au_v26;
  float f_v27;
  float f_v28;
  float f_v29;
  float f_v30;
  float f_v31;
  float f_v32;
  float f_v33;
  float f_v34;
  float f_v35;
  float f_v36;
  float f_v37;
  float f_v38;
  float f_v39;
  float f_v40;
  float f_v41;
  float f_v42;
  float f_v43;
  float f_v44;
  float f_v45;
  float f_v46;
  float f_v47;
  float f_v48;
  float f_v49;
  float f_v50;
  float f_v51;
  float f_v52;
  float f_v53;
  float f_v54;
  float f_v55;
  float f_v56;
  float f_v57;
  float f_v58;
  float f_v59;
  float f_v60;
  float f_v61;
  float f_v62;
  
  pf_v3 = DAT_143d4ab80;
  l_v7 = 2;
  pf_v4 = (float *)((char *)arg1 + 0x40);
  l_v5 = 2;
  pf_v8 = (float *)((char *)arg3 + 0x60);
  do {
    f_v55 = *pf_v3;
    f_v56 = pf_v3[1];
    f_v57 = pf_v3[2];
    f_v58 = pf_v3[3];
    f_v14 = pf_v3[4];
    f_v20 = pf_v3[5];
    f_v22 = pf_v3[6];
    f_v24 = pf_v3[7];
    f_v59 = pf_v4[8] + pf_v4[-8];
    f_v60 = pf_v4[9] + pf_v4[-7];
    f_v61 = pf_v4[10] + pf_v4[-6];
    f_v62 = pf_v4[0xb] + pf_v4[-5];
    f_v9 = pf_v4[-0x10] - *pf_v4;
    f_v10 = pf_v4[-0xf] - pf_v4[1];
    f_v11 = pf_v4[-0xe] - pf_v4[2];
    f_v12 = pf_v4[-0xd] - pf_v4[3];
    f_v27 = *pf_v4 + pf_v4[-0x10];
    f_v29 = pf_v4[1] + pf_v4[-0xf];
    f_v31 = pf_v4[2] + pf_v4[-0xe];
    f_v33 = pf_v4[3] + pf_v4[-0xd];
    f_v39 = f_v55 * (pf_v4[-8] - pf_v4[8]) - f_v59;
    f_v40 = f_v56 * (pf_v4[-7] - pf_v4[9]) - f_v60;
    f_v41 = f_v57 * (pf_v4[-6] - pf_v4[10]) - f_v61;
    f_v42 = f_v58 * (pf_v4[-5] - pf_v4[0xb]) - f_v62;
    f_v13 = f_v9 - f_v39;
    f_v19 = f_v10 - f_v40;
    f_v21 = f_v11 - f_v41;
    f_v23 = f_v12 - f_v42;
    f_v39 = f_v39 + f_v9;
    f_v40 = f_v40 + f_v10;
    f_v41 = f_v41 + f_v11;
    f_v42 = f_v42 + f_v12;
    f_v43 = f_v27 - f_v59;
    f_v44 = f_v29 - f_v60;
    f_v45 = f_v31 - f_v61;
    f_v46 = f_v33 - f_v62;
    f_v59 = f_v59 + f_v27;
    f_v60 = f_v60 + f_v29;
    f_v61 = f_v61 + f_v31;
    f_v62 = f_v62 + f_v33;
    f_v35 = pf_v4[4] - pf_v4[-4];
    f_v36 = pf_v4[5] - pf_v4[-3];
    f_v37 = pf_v4[6] - pf_v4[-2];
    f_v38 = pf_v4[7] - pf_v4[-1];
    f_v47 = pf_v4[-4] + pf_v4[4];
    f_v49 = pf_v4[-3] + pf_v4[5];
    f_v51 = pf_v4[-2] + pf_v4[6];
    f_v53 = pf_v4[-1] + pf_v4[7];
    f_v9 = pf_v4[-0xc] - pf_v4[0xc];
    f_v10 = pf_v4[-0xb] - pf_v4[0xd];
    f_v11 = pf_v4[-10] - pf_v4[0xe];
    f_v12 = pf_v4[-9] - pf_v4[0xf];
    f_v28 = pf_v4[0xc] + pf_v4[-0xc];
    f_v30 = pf_v4[0xd] + pf_v4[-0xb];
    f_v32 = pf_v4[0xe] + pf_v4[-10];
    f_v34 = pf_v4[0xf] + pf_v4[-9];
    f_v48 = f_v47 + f_v28;
    f_v50 = f_v49 + f_v30;
    f_v52 = f_v51 + f_v32;
    f_v54 = f_v53 + f_v34;
    f_v27 = (f_v35 - f_v9) * pf_v3[0x10];
    f_v29 = (f_v36 - f_v10) * pf_v3[0x11];
    f_v31 = (f_v37 - f_v11) * pf_v3[0x12];
    f_v33 = (f_v38 - f_v12) * pf_v3[0x13];
    f_v9 = (pf_v3[0xc] * f_v9 - f_v27) - f_v48;
    f_v10 = (pf_v3[0xd] * f_v10 - f_v29) - f_v50;
    f_v11 = (pf_v3[0xe] * f_v11 - f_v31) - f_v52;
    f_v12 = (pf_v3[0xf] * f_v12 - f_v33) - f_v54;
    pf_v8[-0x18] = f_v48 + f_v59;
    f_v28 = f_v55 * (f_v28 - f_v47) - f_v9;
    f_v30 = f_v56 * (f_v30 - f_v49) - f_v10;
    f_v32 = f_v57 * (f_v32 - f_v51) - f_v11;
    f_v34 = f_v58 * (f_v34 - f_v53) - f_v12;
    pf_v8[-0x10] = f_v50 + f_v60;
    f_v55 = (f_v14 * f_v35 - f_v27) - f_v28;
    f_v56 = (f_v20 * f_v36 - f_v29) - f_v30;
    f_v57 = (f_v22 * f_v37 - f_v31) - f_v32;
    f_v58 = (f_v24 * f_v38 - f_v33) - f_v34;
    *(float *)((arg3 - arg1) + (longlong)pf_v4) = f_v52 + f_v61;
    *pf_v8 = f_v54 + f_v62;
    pf_v8[-0x17] = f_v9 + f_v39;
    pf_v8[-0xf] = f_v10 + f_v40;
    pf_v8[-7] = f_v11 + f_v41;
    pf_v8[1] = f_v12 + f_v42;
    pf_v8[-0x16] = f_v28 + f_v13;
    pf_v8[-0xe] = f_v30 + f_v19;
    pf_v8[-6] = f_v32 + f_v21;
    pf_v8[2] = f_v34 + f_v23;
    pf_v8[-0x15] = f_v55 + f_v43;
    pf_v4 = pf_v4 + 0x20;
    l_v5 = l_v5 + -1;
    pf_v8[-0xd] = f_v56 + f_v44;
    pf_v8[-5] = f_v57 + f_v45;
    pf_v8[3] = f_v58 + f_v46;
    pf_v8[-0x14] = f_v43 - f_v55;
    pf_v8[-0xc] = f_v44 - f_v56;
    pf_v8[-4] = f_v45 - f_v57;
    pf_v8[4] = f_v46 - f_v58;
    pf_v8[-0x13] = f_v13 - f_v28;
    pf_v8[-0xb] = f_v19 - f_v30;
    pf_v8[-3] = f_v21 - f_v32;
    pf_v8[5] = f_v23 - f_v34;
    pf_v8[-0x12] = f_v39 - f_v9;
    pf_v8[-10] = f_v40 - f_v10;
    pf_v8[-2] = f_v41 - f_v11;
    pf_v8[6] = f_v42 - f_v12;
    pf_v8[-0x11] = f_v59 - f_v48;
    pf_v8[-9] = f_v60 - f_v50;
    pf_v8[-1] = f_v61 - f_v52;
    pf_v8[7] = f_v62 - f_v54;
    pf_v8 = pf_v8 + 0x20;
  } while (l_v5 != 0);
  pf_v4 = (float *)((char *)arg3 + 0x80);
  pu_v6 = (cri_u8 *)((char *)arg2 + 0x20);
  do {
    f_v47 = pf_v4[0x10] + pf_v4[-0x10];
    f_v48 = pf_v4[0x11] + pf_v4[-0xf];
    f_v49 = pf_v4[0x12] + pf_v4[-0xe];
    f_v50 = pf_v4[0x13] + pf_v4[-0xd];
    f_v55 = pf_v4[-0x20] - *pf_v4;
    f_v56 = pf_v4[-0x1f] - pf_v4[1];
    f_v57 = pf_v4[-0x1e] - pf_v4[2];
    f_v58 = pf_v4[-0x1d] - pf_v4[3];
    f_v9 = *pf_v4 + pf_v4[-0x20];
    f_v10 = pf_v4[1] + pf_v4[-0x1f];
    f_v11 = pf_v4[2] + pf_v4[-0x1e];
    f_v12 = pf_v4[3] + pf_v4[-0x1d];
    f_v39 = *pf_v3 * (pf_v4[-0x10] - pf_v4[0x10]) - f_v47;
    f_v40 = pf_v3[1] * (pf_v4[-0xf] - pf_v4[0x11]) - f_v48;
    f_v41 = pf_v3[2] * (pf_v4[-0xe] - pf_v4[0x12]) - f_v49;
    f_v42 = pf_v3[3] * (pf_v4[-0xd] - pf_v4[0x13]) - f_v50;
    f_v14 = f_v55 - f_v39;
    f_v20 = f_v56 - f_v40;
    f_v22 = f_v57 - f_v41;
    f_v24 = f_v58 - f_v42;
    f_v39 = f_v39 + f_v55;
    f_v40 = f_v40 + f_v56;
    f_v41 = f_v41 + f_v57;
    f_v42 = f_v42 + f_v58;
    f_v43 = f_v9 - f_v47;
    f_v44 = f_v10 - f_v48;
    f_v45 = f_v11 - f_v49;
    f_v46 = f_v12 - f_v50;
    f_v47 = f_v47 + f_v9;
    f_v48 = f_v48 + f_v10;
    f_v49 = f_v49 + f_v11;
    f_v50 = f_v50 + f_v12;
    f_v27 = pf_v4[8] - pf_v4[-8];
    f_v29 = pf_v4[9] - pf_v4[-7];
    f_v31 = pf_v4[10] - pf_v4[-6];
    f_v33 = pf_v4[0xb] - pf_v4[-5];
    f_v28 = pf_v4[-8] + pf_v4[8];
    f_v32 = pf_v4[-7] + pf_v4[9];
    f_v35 = pf_v4[-6] + pf_v4[10];
    f_v37 = pf_v4[-5] + pf_v4[0xb];
    f_v55 = pf_v4[-0x18] - pf_v4[0x18];
    f_v56 = pf_v4[-0x17] - pf_v4[0x19];
    f_v57 = pf_v4[-0x16] - pf_v4[0x1a];
    f_v58 = pf_v4[-0x15] - pf_v4[0x1b];
    f_v13 = pf_v4[0x18] + pf_v4[-0x18];
    f_v19 = pf_v4[0x19] + pf_v4[-0x17];
    f_v21 = pf_v4[0x1a] + pf_v4[-0x16];
    f_v23 = pf_v4[0x1b] + pf_v4[-0x15];
    f_v30 = f_v28 + f_v13;
    f_v34 = f_v32 + f_v19;
    f_v36 = f_v35 + f_v21;
    f_v38 = f_v37 + f_v23;
    f_v9 = (f_v27 - f_v55) * pf_v3[0x10];
    f_v10 = (f_v29 - f_v56) * pf_v3[0x11];
    f_v11 = (f_v31 - f_v57) * pf_v3[0x12];
    f_v12 = (f_v33 - f_v58) * pf_v3[0x13];
    f_v55 = (pf_v3[0xc] * f_v55 - f_v9) - f_v30;
    f_v56 = (pf_v3[0xd] * f_v56 - f_v10) - f_v34;
    f_v57 = (pf_v3[0xe] * f_v57 - f_v11) - f_v36;
    f_v58 = (pf_v3[0xf] * f_v58 - f_v12) - f_v38;
    f_v13 = *pf_v3 * (f_v13 - f_v28) - f_v55;
    f_v19 = pf_v3[1] * (f_v19 - f_v32) - f_v56;
    f_v21 = pf_v3[2] * (f_v21 - f_v35) - f_v57;
    f_v23 = pf_v3[3] * (f_v23 - f_v37) - f_v58;
    f_v9 = (pf_v3[4] * f_v27 - f_v9) - f_v13;
    f_v10 = (pf_v3[5] * f_v29 - f_v10) - f_v19;
    f_v11 = (pf_v3[6] * f_v31 - f_v11) - f_v21;
    f_v12 = (pf_v3[7] * f_v33 - f_v12) - f_v23;
    CRI_PART(au_v15,0,4) = (int)(f_v30 + f_v47);
    CRI_PART(au_v15,4,4) = (int)(f_v34 + f_v48);
    CRI_PART(au_v15,8,4) = (int)(f_v36 + f_v49);
    CRI_PART(au_v15,12,4) = (int)(f_v38 + f_v50);
    CRI_PART(au_v16,4,4) = (int)(f_v56 + f_v40);
    CRI_PART(au_v16,0,4) = (int)(f_v55 + f_v39);
    CRI_PART(au_v16,8,4) = (int)(f_v57 + f_v41);
    CRI_PART(au_v16,12,4) = (int)(f_v58 + f_v42);
    au_v16 = packssdw(au_v15,au_v16);
    pu_v6[-4] = CRI_PART(au_v16,0,8);
    pu_v6[-2] = CRI_PART(au_v16,8,8);
    CRI_PART(au_v25,0,4) = (int)(f_v43 - f_v9);
    CRI_PART(au_v25,4,4) = (int)(f_v44 - f_v10);
    CRI_PART(au_v25,8,4) = (int)(f_v45 - f_v11);
    CRI_PART(au_v25,12,4) = (int)(f_v46 - f_v12);
    CRI_PART(au_v17,0,4) = (int)(f_v13 + f_v14);
    CRI_PART(au_v17,4,4) = (int)(f_v19 + f_v20);
    CRI_PART(au_v17,8,4) = (int)(f_v21 + f_v22);
    CRI_PART(au_v17,12,4) = (int)(f_v23 + f_v24);
    CRI_PART(au_v26,4,4) = (int)(f_v10 + f_v44);
    CRI_PART(au_v26,0,4) = (int)(f_v9 + f_v43);
    CRI_PART(au_v26,8,4) = (int)(f_v11 + f_v45);
    CRI_PART(au_v26,12,4) = (int)(f_v12 + f_v46);
    au_v16 = packssdw(au_v17,au_v26);
    *pu_v6 = CRI_PART(au_v16,0,8);
    CRI_PART(au_v1,4,4) = (int)(f_v20 - f_v19);
    CRI_PART(au_v1,0,4) = (int)(f_v14 - f_v13);
    CRI_PART(au_v1,8,4) = (int)(f_v22 - f_v21);
    CRI_PART(au_v1,12,4) = (int)(f_v24 - f_v23);
    au_v26 = packssdw(au_v25,au_v1);
    pu_v6[2] = CRI_PART(au_v16,8,8);
    pu_v6[4] = CRI_PART(au_v26,0,8);
    CRI_PART(au_v18,0,4) = (int)(f_v39 - f_v55);
    CRI_PART(au_v18,4,4) = (int)(f_v40 - f_v56);
    CRI_PART(au_v18,8,4) = (int)(f_v41 - f_v57);
    CRI_PART(au_v18,12,4) = (int)(f_v42 - f_v58);
    pu_v6[6] = CRI_PART(au_v26,8,8);
    CRI_PART(au_v2,4,4) = (int)(f_v48 - f_v34);
    CRI_PART(au_v2,0,4) = (int)(f_v47 - f_v30);
    CRI_PART(au_v2,8,4) = (int)(f_v49 - f_v36);
    CRI_PART(au_v2,12,4) = (int)(f_v50 - f_v38);
    au_v16 = packssdw(au_v18,au_v2);
    pu_v6[8] = CRI_PART(au_v16,0,8);
    pf_v4 = pf_v4 + 4;
    l_v7 = l_v7 + -1;
    pu_v6[10] = CRI_PART(au_v16,8,8);
    pu_v6 = pu_v6 + 1;
  } while (l_v7 != 0);
  return;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140065e70
void FUN_140065e70(cri_any cri_p0, cri_any cri_p1, ...)
{
  char *arg1 = cri_p0;
  int arg2 = cri_p1;
  cri_u8 u_v1;
  uint *pu_v2;
  uint u_v3;
  float *pf_v4;
  longlong *pl_v5;
  longlong l_v6;
  float f_v7;
  
  u_v1 = *(cri_u8 *)((char *)arg1 + 0x68);
  pf_v4 = *(float **)((char *)arg1 + 0x38);
  pl_v5 = *(longlong **)((char *)arg1 + 0x40);
  l_v6 = 6;
  do {
    if (arg2 < 0) {
      if (*arg1 == '\0') {
        f_v7 = *pf_v4;
        pu_v2 = (uint *)*pl_v5;
        if (0.0 <= f_v7) {
          f_v7 = f_v7 + 0.5;
        }
        else {
          f_v7 = f_v7 - 0.5;
        }
        u_v3 = (int)(short)(int)f_v7 << 0x10 | (int)f_v7 & 0xffffU;
        pu_v2[0x1f] = u_v3;
        pu_v2[0x1e] = u_v3;
        pu_v2[0x1d] = u_v3;
        pu_v2[0x1c] = u_v3;
        pu_v2[0x1b] = u_v3;
        pu_v2[0x1a] = u_v3;
        pu_v2[0x19] = u_v3;
        pu_v2[0x18] = u_v3;
        pu_v2[0x17] = u_v3;
        pu_v2[0x16] = u_v3;
        pu_v2[0x15] = u_v3;
        pu_v2[0x14] = u_v3;
        pu_v2[0x13] = u_v3;
        pu_v2[0x12] = u_v3;
        pu_v2[0x11] = u_v3;
        pu_v2[0x10] = u_v3;
        pu_v2[0xf] = u_v3;
        pu_v2[0xe] = u_v3;
        pu_v2[0xd] = u_v3;
        pu_v2[0xc] = u_v3;
        pu_v2[0xb] = u_v3;
        pu_v2[10] = u_v3;
        pu_v2[9] = u_v3;
        pu_v2[8] = u_v3;
        pu_v2[7] = u_v3;
        pu_v2[6] = u_v3;
        pu_v2[5] = u_v3;
        pu_v2[4] = u_v3;
        pu_v2[3] = u_v3;
        pu_v2[2] = u_v3;
        pu_v2[1] = u_v3;
        *pu_v2 = u_v3;
      }
      else {
        FUN_140065a20(pf_v4,*pl_v5,u_v1);
      }
    }
    arg2 = arg2 * 2;
    pf_v4 = pf_v4 + 0x40;
    pl_v5 = pl_v5 + 1;
    arg1 = arg1 + 1;
    l_v6 = l_v6 + -1;
  } while (l_v6 != 0);
  return;
}

// The float-to-short sibling of FUN_140065e70 (reached from sfr_cri_07's LAB_140066300/LAB_140066310; no .pdata): for
// each of the 6 blocks whose bit is set in mask (bit 31 first), the block's first sample is rounded half away from 0
// into the block's output.
// MS2-FUNCTIONAL: written from the exe (VS2008 build, our toolset differs).
// @0x140065fc0
void FUN_140065fc0(char *ctx, int mask)
{
  float *src = *(float **)((char *)ctx + 0x38);
  short **dst = *(short ***)((char *)ctx + 0x40);
  for (int i = 0; i < 6; i++) {
    if (((uint)mask << i & 0x80000000u) != 0) {
      float v = src[i * 0x40];
      if (v > 0.0f) {
        *dst[i] = (short)(int)((double)v + 0.5);
      }
      else if (v < 0.0f) {
        *dst[i] = (short)(int)((double)v - 0.5);
      }
      else {
        *dst[i] = 0;
      }
    }
  }
}


// ---- MPEG IDCT-store / motion-compensation leaves (no .pdata) of the tables at DAT_1431bab50 / DAT_1431bab60 ----
// The MC leaves share (src, dst, off, stride, h): src and dst rows are `stride` apart, `off` selects the second
// reference row; pavgb rounding is (a + b + 1) >> 1.

static inline cri_u1 cri06_avg(int a, int b) { return (cri_u1)((a + b + 1) >> 1); }

struct cri06_block { const short* coef; cri_u1* dst; int stride; };

// MS2-FUNCTIONAL: scalar form of the SSE2 store (packuswb of each 8x8 coefficient block into its destination).
// @0x1400590c0
void FUN_1400590c0(const cri06_block* rec)
{
  do {
    for (int r = 0; r < 8; ++r)
      for (int c = 0; c < 8; ++c) {
        int v = rec->coef[r * 8 + c];
        rec->dst[r * rec->stride + c] = (cri_u1)(v < 0 ? 0 : v > 255 ? 255 : v);
      }
    ++rec;
  } while (rec->coef);
}

// MS2-FUNCTIONAL: 8-wide block copy (8 rows when h == 8, else 4).
// @0x1400592c0
void FUN_1400592c0(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  int rows = h == 8 ? 8 : 4;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < 8; ++j) dst[i * stride + j] = src[i * stride + j];
}

// MS2-FUNCTIONAL: 8-wide vertical half-pel average of src and src + off.
// @0x140059340
void FUN_140059340(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 8; ++j) dst[i * stride + j] = cri06_avg(src[i * stride + j], src[off + i * stride + j]);
}

// MS2-FUNCTIONAL: 8-wide horizontal half-pel average.
// @0x1400593b0
void FUN_1400593b0(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 8; ++j) dst[i * stride + j] = cri06_avg(src[i * stride + j], src[i * stride + j + 1]);
}

// MS2-FUNCTIONAL: 16-wide block copy (16 rows when h == 16, else 8).
// @0x140059570
void FUN_140059570(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  int rows = h == 16 ? 16 : 8;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < 16; ++j) dst[i * stride + j] = src[i * stride + j];
}

// MS2-FUNCTIONAL: 16-wide vertical half-pel average of src and src + off.
// @0x140059700
void FUN_140059700(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 16; ++j) dst[i * stride + j] = cri06_avg(src[i * stride + j], src[off + i * stride + j]);
}

// MS2-FUNCTIONAL: 16-wide horizontal half-pel average.
// @0x1400597b0
void FUN_1400597b0(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 16; ++j) dst[i * stride + j] = cri06_avg(src[i * stride + j], src[i * stride + j + 1]);
}

// MS2-FUNCTIONAL: 8-wide bidirectional average into dst (8 rows when h == 8, else 4).
// @0x140059ac0
void FUN_140059ac0(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  int rows = h == 8 ? 8 : 4;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < 8; ++j) dst[i * stride + j] = cri06_avg(src[i * stride + j], dst[i * stride + j]);
}

// MS2-FUNCTIONAL: 8-wide vertical half-pel average, then averaged into dst.
// @0x140059b80
void FUN_140059b80(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 8; ++j)
      dst[i * stride + j] = cri06_avg(cri06_avg(src[i * stride + j], src[off + i * stride + j]), dst[i * stride + j]);
}

// MS2-FUNCTIONAL: 8-wide average of src + 1 into dst (the exe reads only the right-hand sample).
// @0x140059c10
void FUN_140059c10(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 8; ++j) dst[i * stride + j] = cri06_avg(src[i * stride + j + 1], dst[i * stride + j]);
}

// MS2-FUNCTIONAL: 16-wide bidirectional average into dst (16 rows when h == 16, else 8).
// @0x140059dd0
void FUN_140059dd0(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  int rows = h == 16 ? 16 : 8;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < 16; ++j) dst[i * stride + j] = cri06_avg(src[i * stride + j], dst[i * stride + j]);
}

// MS2-FUNCTIONAL: 16-wide vertical half-pel average, then averaged into dst.
// @0x14005a070
void FUN_14005a070(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 16; ++j)
      dst[i * stride + j] = cri06_avg(cri06_avg(src[i * stride + j], src[off + i * stride + j]), dst[i * stride + j]);
}

// MS2-FUNCTIONAL: 16-wide horizontal half-pel average, then averaged into dst.
// @0x14005a140
void FUN_14005a140(const cri_u1* src, cri_u1* dst, int off, int stride, int h)
{
  (void)off;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < 16; ++j)
      dst[i * stride + j] = cri06_avg(cri06_avg(src[i * stride + j], src[i * stride + j + 1]), dst[i * stride + j]);
}
