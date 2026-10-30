// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware, the decoder's
// output-callback helpers at 0x140054170-0x140054250 (the block output callbacks and the two "which callback is set"
// tests). In the exe they are their own obj, just before sfr_cri_06: FUN_14005ae00 in 06 reloads its registers around
// FUN_140054210/FUN_140054230, which VC9 does not do for a callee in the same TU. Written from the executable. The CRI
// library was built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9, cmake/ms2-unit-profiles.cmake): keep it
// C++03 (no auto, decltype, variadic templates, brace-init or nullptr). Every function is a behaviour-equivalent
// transcription.
// MS2-UNIT: sfr_cri_06a
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140054170-0x140054250 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/cri/cri_vendor_shim.h"
// The exe takes these table addresses with a plain lea, and VC9 keeps the fill loops at their full length, so the
// launder (and its stack spill) is only needed where clang could bound a loop by the scalar declaration.
#if defined(__clang__)
#define CRI_FILL_ADDR(x) CRI_ADDR(x)
#else
#define CRI_FILL_ADDR(x) (&(x))
#endif
// A big-endian stream word as the CRI bit reader loads it: the first byte sign-extended, 32-bit shifts.
#define CRI06_BE32(a, b, c, d) ((((((int)(signed char)(a) << 8) | (b)) << 8 | (c)) << 8) | (d))
// A byte-stream chunk as FUN_140069020 splits it: data pointer and a 32-bit size, 16 bytes on the stack.
// Typed by its fields rather than as a byte array, which the exe would not guard with a /GS cookie.
struct cri06_chunk { cri_u1* data; int size; };
struct cri06_plane3 { cri_u8 p0; cri_u8 p1; cri_u8 p2; cri_u4 s0; cri_u4 s1; cri_u4 s2; };
struct cri06_plane1 { cri_u8 p; uint w; uint f; uint h; };
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
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
extern "C" unsigned char DAT_1431baa20;
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
extern "C" unsigned char DAT_1431bba40;
extern "C" unsigned char DAT_1431bba50;
extern "C" unsigned char DAT_1431bba60;
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
extern "C" unsigned long long DAT_143a4a5e8;
extern "C" int DAT_143badb84;
extern "C" int DAT_143badb88;
extern "C" unsigned char DAT_143badbb8;
extern "C" int DAT_143badbdc;
extern "C" int DAT_143badc00;
extern "C" int DAT_143badf80;
extern "C" int DAT_143c49100;
extern "C" int DAT_143c494e8;
extern "C" int DAT_143c494f8;
extern "C" int DAT_143c49500;
extern "C" __declspec(align(16)) unsigned char DAT_143d49580[0x400];
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
extern "C" __declspec(align(16)) unsigned char DAT_143d4a340[0x80];
extern "C" unsigned char DAT_143d4a3bc;
extern "C" unsigned char DAT_143d4a3bd;
extern "C" unsigned char DAT_143d4a3be;
extern "C" unsigned char DAT_143d4a3bf;
extern "C" int DAT_143d4a3c0;
extern "C" int DAT_143d4a3c4;
extern "C" __declspec(align(16)) unsigned char DAT_143d4a400[0x80];
extern "C" unsigned char DAT_143d4a47c;
extern "C" unsigned char DAT_143d4a47d;
extern "C" unsigned char DAT_143d4a47e;
extern "C" unsigned char DAT_143d4a47f;
extern "C" __declspec(align(16)) unsigned char DAT_143d4a480[0x400];
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
extern "C" unsigned int DAT_143d74a80;    // uint32 entries (FUN_14005e720 builds it)
extern "C" int DAT_143d74a84;
extern "C" int DAT_143db4a84;
extern "C" unsigned char DAT_143db4ac0;
extern "C" int DAT_143db4ac1;
extern "C" unsigned short DAT_143dc4b00;  // u16 entries
extern "C" int DAT_143dc4b02;
extern "C" unsigned short DAT_143e44b00;  // u16 entries
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

cri_u8 FUN_140047750(cri_any = cri_any());
void FUN_1400479e0();
void FUN_1400493c0();
void FUN_14004de60(cri_any = cri_any());
void FUN_14004dfc0(cri_any = cri_any());
cri_u4 FUN_14004ff50(cri_any = cri_any(), cri_any = cri_any());
DWORD FUN_1400501f0();   // sfr_cri_05b
void FUN_140050520();   // sfr_cri_05b
void FUN_140050670();   // sfr_cri_05b
void FUN_140054080();   // sfr_cri_05b
void FUN_140050210(longlong, cri_u4);   // sfr_cri_05b
void FUN_140050310(cri_any = cri_any());
longlong FUN_140050730();   // sfr_cri_05b
cri_u8 FUN_140050820(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140051d90(cri_any = cri_any());
cri_u4 FUN_140051ec0(cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140052010(longlong *a1, int a2, int a3);   // sfr_cri_05b
int FUN_140052950(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u1 FUN_140053000(cri_any = cri_any());
void FUN_140054170(cri_any = cri_any());
int FUN_140054210(cri_any = cri_any());
int FUN_140054230(cri_any = cri_any());
void FUN_140054250(cri_any = cri_any());
void FUN_140054320(cri_any = cri_any());
void FUN_140054490(cri_u8);
void FUN_1400544b0();
void FUN_1400544e0(cri_any = cri_any());
void FUN_1400545f0(cri_any = cri_any());
void FUN_140054820(cri_any = cri_any());
void FUN_1400549b0(cri_any = cri_any());
void FUN_140054a40(cri_any = cri_any());
void FUN_140054a80(cri_any = cri_any());
void FUN_140054b60(cri_any = cri_any());
longlong FUN_140054cf0(cri_any = cri_any(), cri_any = cri_any());
longlong FUN_140055410(cri_any = cri_any(), cri_any = cri_any());
void FUN_140055510(longlong, void *, int);
longlong FUN_140055550(cri_any = cri_any(), cri_any = cri_any());
longlong FUN_140057fe0(cri_any = cri_any(), cri_any = cri_any());
longlong FUN_1400584e0(cri_any = cri_any(), cri_any = cri_any());
void FUN_140058b10(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
longlong FUN_140058c50(cri_any = cri_any(), cri_any = cri_any());
uint FUN_140058e00(cri_any = cri_any(), cri_any = cri_any());
cri_u4 FUN_140059030(cri_u8, cri_u8);
void FUN_140059090();
void FUN_140059170(cri_any = cri_any());
void FUN_140059290();
void FUN_1400593f0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140059810(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140059c40(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005a1b0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005a4b0();
void FUN_14005a530();
void FUN_14005a820();
void FUN_14005a900();
void FUN_14005a980();
void FUN_14005aa60();
void FUN_14005ae00(cri_any = cri_any());
void FUN_14005aea0();
void FUN_14005aee0(cri_any = cri_any());
void FUN_14005af00(cri_u8 *, int);
void FUN_14005af20();
cri_u4 FUN_14005af30(longlong, cri_u4);
void FUN_14005af70(longlong, cri_u8, cri_u8);
void FUN_14005afd0(longlong, cri_u8 *);
cri_u4 FUN_14005b040();
void FUN_14005b090(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b0b0();
ulonglong FUN_14005b0d0(ulonglong);
void FUN_14005b0f0(cri_any = cri_any());
void FUN_14005b110(cri_any = cri_any());
void FUN_14005b130(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b150(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b170(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b190(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b1b0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b1d0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b200(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b220(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_14005b240(cri_u8, cri_u8);
void FUN_14005b260(cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b280(cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b2a0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b2c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b2e0(cri_any = cri_any());
void FUN_14005b300(cri_u8, cri_u8);
void FUN_14005b390(longlong, cri_u8, void *);
void FUN_14005b560(cri_any = cri_any());
void FUN_14005b580(cri_any = cri_any());
void FUN_14005b5c0(cri_any = cri_any());
void FUN_14005b650(cri_any = cri_any());
void FUN_14005b6d0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14005b810(cri_any = cri_any());
void FUN_14005b860(longlong);
void FUN_14005b8a0(longlong);
cri_u8 FUN_14005b8c0(cri_any = cri_any());
void FUN_14005dc70(cri_any = cri_any(), cri_any = cri_any());
void FUN_14005e5b0(longlong, void *);
void FUN_14005e600(longlong, cri_u4 *);
void FUN_14005e650(longlong, int *, cri_u4 *, cri_u4 *);
void FUN_14005e6c0(longlong, cri_u4 *, cri_u4 *);
void FUN_14005e720();
void FUN_14005ebc0();
void FUN_14005ebd0(cri_any = cri_any(), cri_any = cri_any());
void FUN_14005fe40(cri_any = cri_any(), cri_any = cri_any());
void FUN_140061080(cri_any = cri_any(), cri_any = cri_any());
void FUN_1400616c0(cri_any = cri_any(), cri_any = cri_any());
void FUN_140061ce0(cri_any = cri_any(), cri_any = cri_any());
void FUN_1400622f0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_1400623f0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_1400624c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_1400625c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140062690(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_1400627a0();
void FUN_1400627f0(cri_any = cri_any());
cri_u4 FUN_140062820();
int FUN_140062830();
int FUN_140062860();
int FUN_140062890();
void FUN_1400628d0();
ulonglong FUN_140062900(longlong);
void FUN_140062910(longlong);
void FUN_140062920(longlong);
void FUN_140062950(cri_any = cri_any());
cri_u8 FUN_140062a40(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140062ab0(cri_any = cri_any());
cri_u8 FUN_140062ae0(cri_any = cri_any(), cri_any = cri_any());
int FUN_140062bc0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140062c10(cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_1400630c0();
void FUN_1400630d0();
void FUN_1400633e0();
void FUN_140063730();
void FUN_140063aa0();
void FUN_140063b60();
void FUN_140063cb0();
cri_u8 FUN_140063eb0(cri_any = cri_any());
cri_u2 * FUN_140064070(cri_any = cri_any());
void FUN_140064360();
void FUN_140064440();
void FUN_140064510();
void FUN_140064640();
void FUN_140064760();
void FUN_1400649a0();
longlong FUN_140064ae0(cri_any = cri_any());
longlong FUN_140064be0(cri_any = cri_any());
longlong FUN_140064c30(cri_any = cri_any());
longlong FUN_140064c90(cri_any = cri_any());
void FUN_140064ce0();
void FUN_140064d00();
void FUN_140064d20();
void FUN_140064d40();
void FUN_140064d60(longlong);
void FUN_140064d90(cri_any = cri_any());
void FUN_140064dd0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void * FUN_140064eb0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void * FUN_140064ed0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void * FUN_140064ef0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void * FUN_140064f10(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140064f70(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140065000(cri_any = cri_any());
void FUN_140065030(cri_any = cri_any());
void FUN_140065060(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void * FUN_1400653b0(cri_any = cri_any(), cri_any = cri_any());
void FUN_140065410(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_140065450(cri_any = cri_any(), cri_any = cri_any());
void FUN_140065660(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140065770();
void FUN_140065790();
void FUN_1400657a0(cri_any = cri_any());
void FUN_1400657e0();
void FUN_140065800();
void FUN_140065900(void *);
int FUN_140065940(int);
void FUN_1400659a0(const cri_u1 *, cri_u1 *);
void FUN_1400659f0();
void FUN_140065a20(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140065e70(cri_any = cri_any(), cri_any = cri_any());
void FUN_140066180(cri_any = cri_any());
void FUN_140066320(cri_any = cri_any());
void FUN_140066370(cri_any = cri_any());
void FUN_1400663b0(cri_any = cri_any());
void FUN_1400663d0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_1400677f0(cri_any = cri_any());
void FUN_140067840(cri_any = cri_any());
cri_u8 FUN_140067890(cri_any = cri_any(), cri_any = cri_any());
void FUN_140067a90(cri_any = cri_any());
cri_u4 FUN_140067f40(cri_any = cri_any());
cri_u8 FUN_1400682e0(cri_any = cri_any(), cri_any = cri_any());
cri_u8 FUN_140068380(cri_any = cri_any());
void FUN_140069020(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14006aa90(cri_any = cri_any());
void FUN_14006aaa0(V16 *, V16 *, int);
longlong FUN_14006b0d0(cri_any = cri_any());
longlong FUN_140073c80(cri_any = cri_any());
longlong FUN_14007ba60(cri_any = cri_any());
longlong FUN_140083350(cri_any = cri_any());
void FUN_140089fe0(cri_any = cri_any(), cri_any = cri_any());
void FUN_14008a3c0(cri_any = cri_any());
void FUN_14008a970(cri_any = cri_any(), cri_any = cri_any());
void FUN_14008ab40(cri_any = cri_any());
void FUN_14008c780(cri_any = cri_any());
void FUN_14008c820(cri_any = cri_any());
void FUN_14008d2a0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14008e570(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_14008fa50(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140090080(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140090730(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_1400927c0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140092850(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_1400928e0(cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any(), cri_any = cri_any());
void FUN_140093cf0();
void FUN_140095250();
void FUN_140095450(cri_any = cri_any());
void FUN_142ccb4f0(cri_any = cri_any());
void FUN_142ccb500(cri_any = cri_any());

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054170
void FUN_140054170(cri_any cri_p0)
{
  longlong arg1 = cri_p0;
  uint bit;
  longlong i;
  V16 **src;
  V16 *dst;
  longlong n;
  
  i = 0;
  bit = 1;
  src = (V16 **)((char *)arg1 + 0x1980);
  dst = (V16 *)((char *)arg1 + 0x780);
  n = 6;
  do {
    if ((*(uint *)((char *)arg1 + 0x71c) & bit) != 0) {
      FUN_14006aaa0(*src,dst,((char *)arg1)[i + 0xc6c]);
    }
    dst = dst + 8;
    i = i + 1;
    src = src + 1;
    bit = _rotl(bit,1);
    n = n + -1;
  } while (n != 0);
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
void thunk_FUN_140054080()
{
  FUN_140054080();   // the exe's thunk is a jmp to FUN_140054080 (sfr_cri_05b)
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054210
int FUN_140054210(cri_any cri_p0)
{
  longlong arg1 = cri_p0;
  return *(cri_code **)((char *)arg1 + 0x1bc8) == (cri_code *)FUN_140054170;
}

// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x140054230
int FUN_140054230(cri_any cri_p0)
{
  longlong arg1 = cri_p0;
  return *(cri_code **)((char *)arg1 + 0x1bc8) == (cri_code *)FUN_1400541f0;
}

void FUN_140054250(cri_any cri_p0);

void FUN_140054320(cri_any cri_p0);

void FUN_140054490(cri_u8 arg1);

void FUN_1400544b0();

void FUN_1400544e0(cri_any cri_p0);

void FUN_140054590(void* pCtx, int nIndex, cri_u8 a3, cri_u8 a4, cri_u8 a5);

void FUN_1400545c0(void* pCtx, cri_u8 a2, cri_u4 a3);

void FUN_1400545d0(void* pCtx, cri_u8* pOut, cri_u4* pCount);

void FUN_1400545f0(cri_any cri_p0);

void FUN_140054820(cri_any cri_p0);

void FUN_1400549b0(cri_any cri_p0);

void FUN_140054a40(cri_any cri_p0);

void FUN_140054a80(cri_any cri_p0);

void FUN_140054b60(cri_any cri_p0);

longlong FUN_140054cf0(cri_any cri_p0, cri_any cri_p1);

longlong FUN_140055410(cri_any cri_p0, cri_any cri_p1);

void FUN_140055510(longlong arg1, void *arg2, int arg3);

longlong FUN_140055550(cri_any cri_p0, cri_any cri_p1);

longlong FUN_140057fe0(cri_any cri_p0, cri_any cri_p1);

longlong FUN_1400584e0(cri_any cri_p0, cri_any cri_p1);

void FUN_140058b10(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

longlong FUN_140058c50(cri_any cri_p0, cri_any cri_p1);

uint FUN_140058e00(cri_any cri_p0, cri_any cri_p1);

cri_u4 FUN_140059030(cri_u8 arg1, cri_u8 arg2);

void FUN_140059090();

struct cri06_block { const short* coef; cri_u1* dst; int stride; };

void FUN_140059170(cri_any cri_p0);

void FUN_140059290();

void FUN_1400593f0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4);

void FUN_140059810(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4);

void FUN_140059c40(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4);

void FUN_14005a1b0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4);

void FUN_14005a4b0();

void FUN_14005a530();

void FUN_14005a820();

void FUN_14005a900();

void FUN_14005a980();

void FUN_14005aa60();

void FUN_14005ae00(cri_any cri_p0);

void FUN_14005aea0();

void FUN_14005aee0(cri_any cri_p0);

void FUN_14005af00(cri_u8 *arg1, int arg2);

void FUN_14005af20();

cri_u4 FUN_14005af30(longlong arg1, cri_u4 arg2);

void FUN_14005af70(longlong arg1, cri_u8 arg2, cri_u8 arg3);

void FUN_14005afd0(longlong arg1, cri_u8 *arg2);

cri_u4 FUN_14005b040();

void FUN_14005b090(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_14005b0b0();

ulonglong FUN_14005b0d0(ulonglong arg1);

void FUN_14005b0f0(cri_any cri_p0);

void FUN_14005b110(cri_any cri_p0);

void FUN_14005b130(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3);

void FUN_14005b150(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3);

void FUN_14005b170(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3);

void FUN_14005b190(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_14005b1b0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3);

void FUN_14005b1d0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3, cri_any cri_p4);

void FUN_14005b200(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_14005b220(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

cri_u8 FUN_14005b240(cri_u8 arg1, cri_u8 arg2);

void FUN_14005b260(cri_any cri_p0, cri_any cri_p1);

void FUN_14005b280(cri_any cri_p0, cri_any cri_p1);

void FUN_14005b2a0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3);

void FUN_14005b2c0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_14005b2e0(cri_any cri_p0);

void FUN_14005b300(cri_u8 arg1, cri_u8 arg2);

void FUN_14005b390(longlong arg1, cri_u8 arg2, void *arg3);

void FUN_14005b560(cri_any cri_p0);

void FUN_14005b580(cri_any cri_p0);

void FUN_14005b5c0(cri_any cri_p0);

void FUN_14005b650(cri_any cri_p0);

void FUN_14005b6d0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2, cri_any cri_p3);

void FUN_14005b810(cri_any cri_p0);

void FUN_14005b860(longlong arg1);

void FUN_14005b8a0(longlong arg1);

cri_u8 FUN_14005b8c0(cri_any cri_p0);

void FUN_14005dc70(cri_any cri_p0, cri_any cri_p1);

void FUN_14005e5b0(longlong arg1, void *arg2);

void FUN_14005e600(longlong arg1, cri_u4 *arg2);

void FUN_14005e650(longlong arg1, int *arg2, cri_u4 *arg3, cri_u4 *arg4);

void FUN_14005e6c0(longlong arg1, cri_u4 *arg2, cri_u4 *arg3);

void FUN_14005e720();

void FUN_14005ebc0();

void FUN_14005ebd0(cri_any cri_p0, cri_any cri_p1);

void FUN_14005fe40(cri_any cri_p0, cri_any cri_p1);

void FUN_140061080(cri_any cri_p0, cri_any cri_p1);

void FUN_1400616c0(cri_any cri_p0, cri_any cri_p1);

void FUN_140061ce0(cri_any cri_p0, cri_any cri_p1);

void FUN_1400622f0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_1400623f0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_1400624c0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_1400625c0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_140062690(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_1400627a0();

void FUN_1400627f0(cri_any cri_p0);

cri_u4 FUN_140062820();

int FUN_140062830();

int FUN_140062860();

int FUN_140062890();

cri_u4 thunk_FUN_14005b040();

void FUN_1400628d0();

void thunk_FUN_14005b0b0(cri_any cri_unused, ...);

ulonglong FUN_140062900(longlong arg1);

void FUN_140062910(longlong arg1);

void FUN_140062920(longlong arg1);

void FUN_140062950(cri_any cri_p0);

cri_u8 FUN_140062a40(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_140062ab0(cri_any cri_p0);

cri_u8 FUN_140062ae0(cri_any cri_p0, cri_any cri_p1);

int FUN_140062bc0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_140062c10(cri_any cri_p0, cri_any cri_p1);

cri_u8 FUN_1400630c0();

void FUN_1400630d0();
void FUN_1400633e0();
void FUN_140063730();
void FUN_140063aa0();

void FUN_140063b60();

void FUN_140063cb0();
cri_u8 FUN_140063eb0(cri_any cri_p0);

cri_u2 * FUN_140064070(cri_any cri_p0);

void FUN_140064360();

void FUN_140064440();

void FUN_140064510();

void FUN_140064640();

void FUN_140064760();
void thunk_FUN_140064760();

void FUN_1400649a0();

longlong FUN_140064ae0(cri_any cri_p0);

longlong FUN_140064be0(cri_any cri_p0);

longlong FUN_140064c30(cri_any cri_p0);

longlong FUN_140064c90(cri_any cri_p0);

void FUN_140064ce0();

void FUN_140064d00();

void FUN_140064d20();

void FUN_140064d40();

void FUN_140064d60(longlong arg1);

void FUN_140064d90(cri_any cri_p0);

void FUN_140064dd0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);
void * FUN_140064eb0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void * FUN_140064ed0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void * FUN_140064ef0(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void * FUN_140064f10(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_140064f70(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void thunk_FUN_140050520();

void thunk_FUN_140050670();

void FUN_140065000(cri_any cri_p0);

void FUN_140065030(cri_any cri_p0);

void FUN_140065060(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void * FUN_1400653b0(cri_any cri_p0, cri_any cri_p1);

void FUN_1400653f0(cri_any cri_p0);

void FUN_140065410(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

cri_u8 FUN_140065450(cri_any cri_p0, cri_any cri_p1);

void FUN_140065660(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_140065770();

void FUN_140065790();

void FUN_1400657a0(cri_any cri_p0);

void FUN_1400657e0();

void FUN_140065800();

void FUN_140065900(void *arg1);

int FUN_140065940(int arg1);

void FUN_1400659a0(const cri_u1 *arg1, cri_u1 *arg2);

void FUN_1400659f0();

// cvtps2dq: float to int under the current MXCSR rounding (round to nearest by default), not a truncating cast.
static inline int cri06_cvtps(float f) { return _mm_cvtss_si32(_mm_set_ss(f)); }

void FUN_140065a20(cri_any cri_p0, cri_any cri_p1, cri_any cri_p2);

void FUN_140065e70(cri_any cri_p0, cri_any cri_p1);

void FUN_140065fc0(char *ctx, int mask);


// ---- MPEG IDCT-store / motion-compensation leaves (no .pdata) of the tables at DAT_1431bab50 / DAT_1431bab60 ----
// The MC leaves share (src, dst, off, stride, h): src and dst rows are `stride` apart, `off` selects the second
// reference row; pavgb rounding is (a + b + 1) >> 1.

static inline cri_u1 cri06_avg(int a, int b) { return (cri_u1)((a + b + 1) >> 1); }


void FUN_1400590c0(const cri06_block* rec);

void FUN_1400592c0(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_140059340(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_1400593b0(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_140059570(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_140059700(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_1400597b0(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_140059ac0(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_140059b80(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_140059c10(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_140059dd0(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_14005a070(const cri_u1* src, cri_u1* dst, int off, int stride, int h);

void FUN_14005a140(const cri_u1* src, cri_u1* dst, int off, int stride, int h);
