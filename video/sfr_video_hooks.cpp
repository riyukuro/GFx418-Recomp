// Hook-only TU for the units built with cl 17.00 (// MS2-TOOLSET: vc11: sfr_cri_01, sfr_video_*), which cannot include
// hook/ms2hook.h (C++17). No MS2-UNIT line, so progress.py ignores it; the DLL build compiles it with 19.16. Each
// registration binds the compiled definition by its mangled name with /alternatename (the sfr_sf_hooks.cpp style), so
// the ABI is the compiled one; the name strings, lengths and hashes are the ones the units registered themselves.
#include "hook/ms2hook.h"

// sfr_cri_01
extern "C" void ms2_video_hook_0(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_0=?GetTime@SwfVideoSyncObject@AS3@GFx@Scaleform@@UEAAXPEA_K0@Z")
MS2_REPLACE_IMPL(0x140025D30, (void (*)())&ms2_video_hook_0, "SwfVideoSyncObject::GetTime", 276, 0xC89B171E);
extern "C" void ms2_video_hook_1(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_1=?OpenUrl@VideoProviderNetStream@AS3@GFx@Scaleform@@QEAAXPEBDAEAVASVM@234@@Z")
MS2_REPLACE_IMPL(0x140026720, (void (*)())&ms2_video_hook_1, "VideoProviderNetStream::OpenUrl", 1338, 0x121B5725);

// sfr_video_01
extern "C" void ms2_video_hook_2(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_2=?FUN_140002ab0@@YAXPEAX@Z")
MS2_REPLACE_IMPL(0x140002AB0, (void (*)())&ms2_video_hook_2, "FUN_140002ab0", 68, 0x22F2F390);
extern "C" void ms2_video_hook_3(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_3=?FUN_140002e80@@YAPEAXPEAX@Z")
MS2_REPLACE_IMPL(0x140002E80, (void (*)())&ms2_video_hook_3, "FUN_140002e80", 140, 0x5B0FC81D);
extern "C" void ms2_video_hook_4(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_4=?FUN_14000b120@@YAXPEAPEAX@Z")
MS2_REPLACE_IMPL(0x14000B120, (void (*)())&ms2_video_hook_4, "FUN_14000b120", 151, 0x2FA9FB59);
extern "C" void ms2_video_hook_5(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_5=?FUN_14000b3b0@@YAXPEA_KPEAX_K@Z")
MS2_REPLACE_IMPL(0x14000B3B0, (void (*)())&ms2_video_hook_5, "FUN_14000b3b0", 373, 0x43C35EF0);
extern "C" void ms2_video_hook_6(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_6=?FUN_14000b6e0@@YAXPEA_KPEAXPEBI_K@Z")
MS2_REPLACE_IMPL(0x14000B6E0, (void (*)())&ms2_video_hook_6, "FUN_14000b6e0", 519, 0xCD214316);
extern "C" void ms2_video_hook_7(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_7=?FUN_14000b9e0@@YAXPEA_KPEAXPEAPEAX_K@Z")
MS2_REPLACE_IMPL(0x14000B9E0, (void (*)())&ms2_video_hook_7, "FUN_14000b9e0", 519, 0x13C8EE9C);
extern "C" void ms2_video_hook_8(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_8=?FUN_14000bbf0@@YAXPEAPEAX@Z")
MS2_REPLACE_IMPL(0x14000BBF0, (void (*)())&ms2_video_hook_8, "FUN_14000bbf0", 48, 0x2BDC02A7);
extern "C" void ms2_video_hook_9(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_9=?FUN_14000cbd0@@YAPEAXPEAVVideoProviderNetStream@AS2@GFx@Scaleform@@I@Z")
MS2_REPLACE_IMPL(0x14000CBD0, (void (*)())&ms2_video_hook_9, "FUN_14000cbd0", 55, 0xF2F45D2B);
extern "C" void ms2_video_hook_10(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_10=?FUN_14000cee0@@YAPEAVCFunctionObject@AS2@GFx@Scaleform@@PEAV1234@I@Z")
MS2_REPLACE_IMPL(0x14000CEE0, (void (*)())&ms2_video_hook_10, "FUN_14000cee0", 55, 0xD65AF946);
extern "C" void ms2_video_hook_11(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_11=?FUN_140007ff0@@YAPEAVFunctionRef@AS2@GFx@Scaleform@@PEAVObjectInterface@234@PEAV1234@PEAVASStringContext@234@@Z")
MS2_REPLACE_IMPL(0x140007FF0, (void (*)())&ms2_video_hook_11, "FUN_140007ff0", 126, 0x9AAB9CE7);
extern "C" void ms2_video_hook_12(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_12=?FUN_14000e1e0@AS2@GFx@Scaleform@@YAPEAVObject@123@PEAV4123@PEAVASStringContext@123@0AEBVFunctionRef@123@@Z")
MS2_REPLACE_IMPL(0x14000E1E0, (void (*)())&ms2_video_hook_12, "FUN_14000e1e0", 196, 0x4DBA2484);
extern "C" void ms2_video_hook_13(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_13=?FUN_140009e20@AS2@GFx@Scaleform@@YAPEAVObject@123@PEAV4123@PEAVASStringContext@123@0AEBVFunctionRef@123@@Z")
MS2_REPLACE_IMPL(0x140009E20, (void (*)())&ms2_video_hook_13, "FUN_140009e20", 129, 0x4DD78CE3);
extern "C" void ms2_video_hook_14(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_14=?FUN_14000ae30@AS2@GFx@Scaleform@@YAPEAVObject@123@PEAV4123@PEAVASStringContext@123@0AEBVFunctionRef@123@@Z")
MS2_REPLACE_IMPL(0x14000AE30, (void (*)())&ms2_video_hook_14, "FUN_14000ae30", 106, 0xED9D13A6);
extern "C" void ms2_video_hook_15(void);
#pragma comment(linker, "/alternatename:ms2_video_hook_15=?FUN_14000cf20@AS2@GFx@Scaleform@@YA?AVFunctionRef@123@PEAVGlobalContext@123@@Z")
MS2_REPLACE_IMPL(0x14000CF20, (void (*)())&ms2_video_hook_15, "FUN_14000cf20", 797, 0x7DC142D2);
