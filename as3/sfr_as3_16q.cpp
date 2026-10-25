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

// MS2-FUNCTIONAL 0x1424ddb80: performs the AVM display object's reference cleanup before restoring its base state.
// @0x1424ddb80
Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj() = default;

// MS2-FUNCTIONAL 0x1424ddce0: releases the sprite's AVM-owned children and then tears down its display object bases.
// @0x1424ddce0
Scaleform::GFx::AS3::AvmSprite::~AvmSprite() = default;

// MS2-PIN: ??_7AvmDisplayObjBase@GFx@Scaleform@@6B@ 0x14317bf80
