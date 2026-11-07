// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): CRI MvCore / Sofdec vendor middleware, written from the
// executable: the rows of the /Od CRI thread obj (0x1400677f0-0x140068490) that only byte-match as C. VS2008 /Od keeps
// a value loaded for a compare after a call in r11 when it compiles C and in rax when it compiles C++, so the exe obj
// was C. The rest of that obj stays in sfr_cri_07 (its __try blocks and globals would need a full C port first). This
// unit is C (MS2-TOOLSET: vc9c, the VS2008 SP1 cl with /TC, cmake/ms2-unit-profiles.cmake): C89 declarations at the
// top of each block, and the parameter types of the sfr_cri_07 declarations, so a C++ compile (clang-cl) mangles every
// name as they do. Every function is a behaviour-equivalent transcription. The unit also holds the C row of sfr_cri_06b's
// /O2 plane-group obj (mpvm2v_CopyPicAtr), outside the /Od pragma.
// MS2-UNIT: sfr_cri_07d
// MS2-TOOLSET: vc9c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1400678d0-0x140067a90 .text$mn
// MS2-RANGE: 0x140067ac0-0x140067bf0 .text$mn
// MS2-RANGE: 0x140068190-0x140068280 .text$mn
// MS2-RANGE: 0x140062950-0x140062a40 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include <windows.h>
#include <string.h>
#include <process.h>

typedef unsigned int cri_u4;
typedef unsigned __int64 cri_u8;
typedef __int64 longlong;
typedef cri_u8 cri_code(cri_u8);

// sfr_cri_07 defines these with C linkage (extern "C"), so the clang-cl C++ compile declares them so too
#ifdef __cplusplus
#define CRI_C_LINKAGE extern "C"
#else
#define CRI_C_LINKAGE
#endif

CRI_C_LINKAGE void cridlg_EndInvoke(int *, cri_u4);
cri_u8 FUN_140068200(cri_u8);
cri_u8 FUN_140068210(longlong);
CRI_C_LINKAGE void cridlg_assert(const char *);
CRI_C_LINKAGE cri_u8 CRICRS_Create(longlong, int);
CRI_C_LINKAGE void CRICRS_Destroy(LPCRITICAL_SECTION);
cri_u8 FUN_140068190(longlong);
CRI_C_LINKAGE cri_u4 CRICRS_Enter(LPCRITICAL_SECTION);
CRI_C_LINKAGE cri_u4 CRICRS_Leave(LPCRITICAL_SECTION);

#pragma optimize("", off)                    // this exe CRI obj was built without optimization (/Od)
// create a CRI worker thread record in the caller's work area (4-byte aligned, at least 0x7c bytes): its wait event,
// its lock and its thread; wait until the thread runs, and return the record, or 0 on failure. The local names fix the
// /Od stack slots: VS2008 orders them by name, and work/tid give the exe's.
// @0x1400678d0
#pragma function(memset)                      // the exe obj calls memset here
cri_u8 cridlg_Create(longlong arg1, cri_u4 arg2)
{
  cri_u4 tid;
  cri_u4 *work;

  if (arg1 == 0) {
    cridlg_assert("NULL pointer is passed.");
    return 0;
  }
  if ((cri_u8)(int)arg2 < 0x7c) {
    cridlg_assert("Work area size is too short.");
    return 0;
  }
  work = (cri_u4 *)(arg1 + 3U & 0xfffffffffffffffc);
  memset(work,0,0x78);
  *(HANDLE *)(work + 4) = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
  if (*(longlong *)(work + 4) == 0) {
    cridlg_assert("E2004112601 : Can not create wait event.");
    return 0;
  }
  *(cri_u8 *)(work + 6) = CRICRS_Create((longlong)(work + 8),0x30);
  if (*(longlong *)(work + 6) == 0) {
    cridlg_assert("E2004112602 : Can not create critical section.");
    CloseHandle(*(HANDLE *)(work + 4));
    return 0;
  }
  *(uintptr_t *)(work + 2) =
      _beginthreadex((void *)0x0,0,(unsigned (__stdcall *)(void *))FUN_140068190,work,0,&tid);
  if (*(longlong *)(work + 2) == 0) {
    cridlg_assert("E2004112603 : Can not create thread.");
    CloseHandle(*(HANDLE *)(work + 4));
    CRICRS_Destroy((LPCRITICAL_SECTION)(*(cri_u8 *)(work + 6)));
    return 0;
  }
  for (;;) {
    if (work[0x19] != 0) break;
    Sleep(10);
  }
  work[0x1b] = GetThreadPriority(*(HANDLE *)(work + 2));
  *(cri_u8 *)((char *)work + 0x70) = 0xffffffffffffffff;
  *work = 1;
  return (cri_u8)work;
}

// stop a CRI worker thread: signal it until it exits, then close its event, lock and thread handles and clear the
// 0x78-byte thread record
// @0x140067ac0
#pragma function(memset)                      // the exe obj calls memset here
void FUN_140067ac0(void *arg1)
{
  DWORD loc_14;
  BOOL loc_18;

  if (*(int *)((longlong)arg1 + 4) != 0) {
    cridlg_EndInvoke((int *)arg1,*(cri_u4 *)((longlong)arg1 + 0x60));
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
    CRICRS_Destroy((LPCRITICAL_SECTION)(*(cri_u8 *)((longlong)arg1 + 0x18)));
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
  CRICRS_Enter((LPCRITICAL_SECTION)(*(cri_u8 *)((char *)arg1 + 0x18)));
  if (*(int *)(arg1 + 4) == 1) {
    if (*(longlong *)((char *)arg1 + 0x50) != 0) {
      (**(cri_code **)((char *)arg1 + 0x50))(*(cri_u8 *)((char *)arg1 + 0x58));
    }
    *(cri_u4 *)(arg1 + 4) = 0;
  }
  CRICRS_Leave((LPCRITICAL_SECTION)(*(cri_u8 *)((char *)arg1 + 0x18)));
  return 0;
}
#pragma optimize("", on)

// ==== sfr_cri_06b's plane-group obj (/O2) ============================================================================
// cri_any is the vendor shim's untyped argument word: a plain cri_u8 here, and in a C++ compile a one-word struct of the
// same name, so the names mangle as sfr_cri_06b's declarations do
#ifdef __cplusplus
struct cri_any
{
    cri_u8 v;
    cri_any(cri_u8 x) : v(x) {}
    cri_any(void *p) : v((cri_u8)p) {}
    operator cri_u8() const { return v; }
};
#else
typedef cri_u8 cri_any;
#endif
typedef unsigned char cri_u1;

CRI_C_LINKAGE void M2V_GetPicAtr(cri_any, cri_any);
CRI_C_LINKAGE void M2V_GetBitRate(cri_any, cri_any);
CRI_C_LINKAGE void M2V_GetVbvBufSiz(cri_any, cri_any, cri_any, cri_any);
CRI_C_LINKAGE void M2V_GetLinkFlg(cri_any, cri_any, cri_any);
// the C names bind to sfr_cri_06's C++ definitions, and the C++ callers' name to the C definition below
#ifndef MS2_HOOK_DLL
#endif

// copy the decoder's picture attributes, bit rate, VBV buffer size and link flags into the handle. As C++ the struct
// argument word moves the 0x16d8 load past the 0x16d4 store; the exe obj was C.
// @0x140062950
CRI_C_LINKAGE void mpvm2v_CopyPicAtr(cri_any cri_p0)
{
  longlong arg1 = (longlong)(cri_u8)cri_p0;
  cri_u4 loc_b8;
  cri_u4 loc_b4;
  cri_u4 loc_b0;
  cri_u4 loc_ac;
  int loc_a8;
  cri_u4 loc_a4;
  cri_u1 loc_98 [128];

  M2V_GetPicAtr(*(cri_u8 *)((char *)arg1 + 0x1848),(cri_any)(void *)loc_98);
  M2V_GetBitRate(*(cri_u8 *)((char *)arg1 + 0x1848),(cri_any)(void *)&loc_b4);
  M2V_GetVbvBufSiz(*(cri_u8 *)((char *)arg1 + 0x1848),(cri_any)(void *)&loc_a8,(cri_any)(void *)&loc_ac,
                   (cri_any)(void *)&loc_a4);
  M2V_GetLinkFlg(*(cri_u8 *)((char *)arg1 + 0x1848),(cri_any)(void *)&loc_b8,(cri_any)(void *)&loc_b0);
  memcpy((void *)((char *)arg1 + 0x1598),loc_98,0x80);
  *(cri_u4 *)((char *)arg1 + 0x16d4) = loc_b4;
  *(int *)((char *)arg1 + 0x16d8) = loc_a8 / 0x800;
  *(cri_u4 *)((char *)arg1 + 0x16e8) = loc_ac;
  *(cri_u4 *)((char *)arg1 + 0x16e0) = loc_b8;
  *(cri_u4 *)((char *)arg1 + 0x16e4) = loc_b0;
}
