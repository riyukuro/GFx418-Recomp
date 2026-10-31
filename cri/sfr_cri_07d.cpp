// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware, written from the
// executable: the rows of the /Od CRI thread obj (0x1400677f0-0x140068490) that only byte-match as C. VS2008 /Od keeps
// a value loaded for a compare after a call in r11 when it compiles C and in rax when it compiles C++, so the exe obj
// was C. The rest of that obj stays in sfr_cri_07 (its __try blocks and globals would need a full C port first). This
// unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1 cl with /TC, cmake/ms2-unit-profiles.cmake): C89 declarations at the
// top of each block, and the parameter types of the sfr_cri_07 declarations, so a C++ compile (clang-cl) mangles every
// name as they do. Every function is a behaviour-equivalent transcription.
// MS2-UNIT: sfr_cri_07d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140067ac0-0x140067bf0 .text$mn
// MS2-RANGE: 0x140068190-0x140068280 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <windows.h>
#include <string.h>

typedef unsigned int cri_u4;
typedef unsigned __int64 cri_u8;
typedef __int64 longlong;
typedef cri_u8 cri_code(cri_u8);

void FUN_140067e00(int *, cri_u4);
cri_u8 FUN_140068200(cri_u8);
cri_u8 FUN_140068210(longlong);
void FUN_140068380(LPCRITICAL_SECTION);
cri_u4 FUN_1400683d0(LPCRITICAL_SECTION);
cri_u4 FUN_140068430(LPCRITICAL_SECTION);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// stop a CRI worker thread: signal it until it exits, then close its event, lock and thread handles and clear the
// 0x78-byte thread record
// @0x140067ac0
#pragma function(memset)                      // the exe obj calls memset here
void FUN_140067ac0(void *arg1)
{
  DWORD loc_14;
  BOOL loc_18;

  if (*(int *)((longlong)arg1 + 4) != 0) {
    FUN_140067e00((int *)arg1,*(cri_u4 *)((longlong)arg1 + 0x60));
  }
  for (;;) {
    *(cri_u4 *)((longlong)arg1 + 0x68) = 1;
    SetEvent(*(HANDLE *)((longlong)arg1 + 0x10));
    loc_18 = GetExitCodeThread(*(HANDLE *)((longlong)arg1 + 8),&loc_14);
    if (loc_18 == 0) break;
    if (loc_14 != 0x103) break;
    Sleep(10);
  }
  WaitForSingleObject(*(HANDLE *)((longlong)arg1 + 8),0xffffffff);
  ResetEvent(*(HANDLE *)((longlong)arg1 + 0x10));
  if (*(longlong *)((longlong)arg1 + 0x10) != 0) {
    CloseHandle(*(HANDLE *)((longlong)arg1 + 0x10));
    *(cri_u8 *)((longlong)arg1 + 0x10) = 0;
  }
  if (*(longlong *)((longlong)arg1 + 0x18) != 0) {
    FUN_140068380((LPCRITICAL_SECTION)(*(cri_u8 *)((longlong)arg1 + 0x18)));
    *(cri_u8 *)((longlong)arg1 + 0x18) = 0;
  }
  if (*(longlong *)((longlong)arg1 + 8) != 0) {
    CloseHandle(*(HANDLE *)((longlong)arg1 + 8));
    *(cri_u8 *)((longlong)arg1 + 8) = 0;
  }
  memset(arg1,0,0x78);
  return;
}

// the CRI worker thread's entry point (FUN_1400678d0 starts it with _beginthreadex): mark it running, then wait for
// its event and run the queued job until the stop flag is set
// @0x140068190
cri_u8 FUN_140068190(longlong arg1)
{
  longlong l_v1 = arg1;

  *(cri_u4 *)((char *)l_v1 + 100) = 1;
  for (;;) {
    WaitForSingleObject(*(HANDLE *)((char *)l_v1 + 0x10),0xffffffff);
    ResetEvent(*(HANDLE *)((char *)l_v1 + 0x10));
    if (*(int *)((char *)l_v1 + 0x68) != 0) break;
    FUN_140068200(l_v1);
    FUN_140068210(l_v1);
  }
  return 0;
}

// @0x140068200
cri_u8 FUN_140068200(cri_u8 arg1)
{
  return arg1;
}

// run the thread record's pending job (callback at +0x50 with the argument at +0x58) under its lock
// @0x140068210
cri_u8 FUN_140068210(longlong arg1)
{
  FUN_1400683d0((LPCRITICAL_SECTION)(*(cri_u8 *)((char *)arg1 + 0x18)));
  if (*(int *)(arg1 + 4) == 1) {
    if (*(longlong *)((char *)arg1 + 0x50) != 0) {
      (**(cri_code **)((char *)arg1 + 0x50))(*(cri_u8 *)((char *)arg1 + 0x58));
    }
    *(cri_u4 *)(arg1 + 4) = 0;
  }
  FUN_140068430((LPCRITICAL_SECTION)(*(cri_u8 *)((char *)arg1 + 0x18)));
  return 0;
}
#pragma optimize("", on)
