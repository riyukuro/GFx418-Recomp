// Recovered Scaleform GFx 4.1.18 (MapleStory2.exe KMS2_DEV x64): access to exe data arrays from the hook DLL.
// Exe data (symbols-manual `data` rows) are absolute symbols in the DLL. An indexed access compiles __ImageBase-relative
// (ADDR32NB relocation), which link.exe cannot apply to an absolute symbol (LNK2016), so SF_EXE_DATA(a) takes the address
// through a volatile local: it is formed RIP-relatively and indexed in a register. Code using it is functional, not exact
// (the exe indexes off __ImageBase).
#ifndef MS2_SF_KERNEL_EXEDATA_H
#define MS2_SF_KERNEL_EXEDATA_H

namespace Scaleform {
template <class T> __forceinline T* SF_ExeData(T* p) { T* volatile q = p; return q; }
} // namespace Scaleform
#define SF_EXE_DATA(a)      (::Scaleform::SF_ExeData(a))

#endif
