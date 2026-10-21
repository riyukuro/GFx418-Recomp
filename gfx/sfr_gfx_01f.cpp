// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Loader, the GFx::System
// start-up/shut-down forwarders (built on the kernel tree's System, whose HeapDesc is MemoryHeap::HeapDesc).
// Sixth source of queue unit sfr_gfx_01 (the unit spans several original GFx sources).
// MS2-UNIT: sfr_gfx_01f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14258c680-0x14258c690 .text$mn
// MS2-RANGE: 0x14258c790-0x14258c7a0 .text$mn

#include "ms2/scaleform/kernel/sf_system.h"

namespace Scaleform { namespace GFx {

// The library's System: the kernel System plus the GFx evaluation check (empty in this build).
class System : public Scaleform::System
{
public:
    static void SF_CDECL Init(const MemoryHeap::HeapDesc& rootHeapDesc, SysAllocBase* psysAlloc);
    static void SF_CDECL Destroy();
};

// @0x14258c790
void System::Init(const MemoryHeap::HeapDesc& rootHeapDesc, SysAllocBase* psysAlloc)
{
    Scaleform::System::Init(rootHeapDesc, psysAlloc);
}

// @0x14258c680
void System::Destroy()
{
    Scaleform::System::Destroy();
}

}} // namespace Scaleform::GFx

// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
