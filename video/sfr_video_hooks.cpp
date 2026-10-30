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
