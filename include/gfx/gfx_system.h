// Recovered Scaleform 4.1.18 GFx: System, the library's start-up/shut-down front end over the kernel System. Init and
// Destroy are out of line (sfr_gfx_01f: 0x14258c790, 0x14258c680); Init(SysAllocBase*) is an /Od COMDAT of the game code
// (gfxservice: 0x1418074e0).
#ifndef MS2_SF_GFX_SYSTEM_H
#define MS2_SF_GFX_SYSTEM_H

#include "ms2/scaleform/kernel/sf_system.h"

namespace Scaleform { namespace GFx {

class System : public Scaleform::System
{
public:
    static void SF_CDECL Init(const MemoryHeap::HeapDesc& rootHeapDesc, SysAllocBase* psysAlloc);
    SF_EXPORT static void SF_CDECL Init(SysAllocBase* psysAlloc) { Init(MemoryHeap::RootHeapDesc(), psysAlloc); }
    static void SF_CDECL Destroy();
};

}} // namespace Scaleform::GFx

#endif
