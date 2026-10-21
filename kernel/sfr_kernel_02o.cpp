// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18, GFx_LoaderUtil. In this licensed
// build the evaluation check is an empty function; the Loader constructors still call it (0x14258c17a, 0x14258c7b5).
// It was linked between HeapPT_AllocLite and HeapPT_SysAllocMapper, inside the address range of queue unit
// sfr_kernel_02.
// Our own source, written from the exe.
// MS2-UNIT: sfr_kernel_02o
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142644190-0x1426441a0 .text$mn

void GFx_ValidateEvaluation();

void GFx_ValidateEvaluation() { }

// MS2-PIN: ?GFx_ValidateEvaluation@@YAXXZ 0x142644190
