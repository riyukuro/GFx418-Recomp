// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): AS3 display object teardown thunks.
// MS2-UNIT: sfr_as3_16q
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424ddb80-0x1424ddbee .text$mn
// MS2-RANGE: 0x1424ddce0-0x1424ddd4f .text$mn
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"

namespace Scaleform { namespace GFx { namespace AS3 {
void Sfr31ShutdownRegistered(UPInt self);
}}}

// Bridge the global call spelling used by the shared VM destructor to the AS3 helper defined in sfr_as3_19.
void Sfr31ShutdownRegistered(Scaleform::UPInt self)
{
    Scaleform::GFx::AS3::Sfr31ShutdownRegistered(self);
}

// The class name copy goes back to the global heap, then the counted AS3 object is released (SPtr: a pointer the
// collector marked with bit 0 only loses the mark).
// @0x1424ddb80
Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj()
{
    Memory::Free(const_cast<char*>(pClassName));
    if (UPInt p = reinterpret_cast<UPInt>(pAS3CollectiblePtr))
    {
        if (p & 1)
            pAS3CollectiblePtr = reinterpret_cast<Instances::fl_display::DisplayObject*>(p - 1);
        else
            reinterpret_cast<RefCountBaseGC<StatMV_ActionScript_Mem>*>(p)->Release();
    }
}

// MS2-FUNCTIONAL 0x1424ddce0: releases the sprite's AVM-owned children and then tears down its display object bases.
// @0x1424ddce0
Scaleform::GFx::AS3::AvmSprite::~AvmSprite() = default;

// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
// MS2-PIN: ??_7AvmDisplayObj@AS3@GFx@Scaleform@@6B@ 0x14317c160
// MS2-PIN: ??_7AvmInteractiveObj@AS3@GFx@Scaleform@@6BAvmDisplayObj@123@@ 0x14317ca60
