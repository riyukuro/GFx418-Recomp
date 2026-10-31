// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware, the CRI ERR error
// callback layer (its own /Od obj in the exe, between sfr_cri_07's support layer and its SIMD kernels), written from the
// executable. The CRI library was built with VS2008 SP1, and so is this unit (MS2-TOOLSET: vc9,
// cmake/ms2-unit-profiles.cmake): keep it C++03 (no auto, decltype, variadic templates, brace-init or nullptr). Every
// function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_07b
// MS2-TOOLSET: vc9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1400b0940-0x1400b0a10 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "../include/cri/cri_vendor_shim.h"
extern "C" const char* _DAT_143d68ac0;
extern "C" longlong DAT_143d68ac8;
extern "C" volatile int DAT_143d68ad0;   // the error level; volatile only gives the exe's mov eax / cmp eax,-1 read
extern "C" void* PTR_FUN_143a4a5c0;

typedef cri_u8 (*cri07b_errcb)(cri_u8 obj, const char *msg);

cri_u8 FUN_1400b09d0(cri_u8, const char *);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// Sets the CRI ERR callback and its user object; no callback selects the default one (FUN_1400b09d0).
// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400b0940
void FUN_1400b0940(cri07b_errcb func, cri_u8 obj)
{
  _DAT_143d68ac0 = "\nCRI ERR/PCx64 Ver.1.01 Build:Jan 13 2012 18:29:30\n";
  if (func == NULL) {
    PTR_FUN_143a4a5c0 = (void *)FUN_1400b09d0;
    DAT_143d68ac8 = obj;
  }
  else {
    DAT_143d68ac8 = obj;
    PTR_FUN_143a4a5c0 = (void *)func;
  }
}

// Reports a CRI error message to the callback unless the error level is -1.
// MS2-FUNCTIONAL: transcribed from the decompile of the CRI vendor cri_code (VS2008 build, our toolset differs).
// @0x1400b09a0
void FUN_1400b09a0(const char *msg)
{
  if (DAT_143d68ad0 != -1) {
    (*(cri07b_errcb)PTR_FUN_143a4a5c0)(DAT_143d68ac8, msg);
  }
}

// The default CRI ERR callback: ignores the message.
// MS2-FUNCTIONAL: the exe loads obj into rax before loading msg (a dead read, likely the C /Od code for an `obj;`
// statement); cl's C++ /Od emits nothing for `obj;`, and a volatile read goes through a stack temporary.
// @0x1400b09d0
cri_u8 FUN_1400b09d0(cri_u8 obj, const char *msg)
{
  obj;
  return (cri_u8)msg;
}
#pragma optimize("", on)
