// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the self-contained shape
// mesh provider TU (Render_ShapeDataFloatMP): ShapeDataFloatMP owns the float shape it records and attaches it to
// its ShapeMeshProvider part once the shape is done.
// Queue unit sfr_render_05 is split along its original sources (05h Render_ShapeDataFloatMP).
// MS2-UNIT: sfr_render_05h
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142678490-0x1426787e0 .text$mn
// MS2-RANGE: 0x142688b70-0x142688cf0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_shapedatafloatmp.h"

namespace Scaleform { namespace Render {

// @0x142678490
ShapeDataFloatMP::ShapeDataFloatMP() : ShapeMeshProvider()
{
    pData = *SF_HEAP_AUTO_NEW(this) ShapeDataFloat();
}

// terminates the recorded shape and builds the draw layers from it
// @0x1426786e0
void ShapeDataFloatMP::CountLayers()
{
    pData->EndShape();
    AttachShape(pData);
}

}} // namespace Scaleform::Render

// MS2-PIN: ??_7?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f010
// MS2-PIN: ??_7?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@6B@ 0x14318f130
// MS2-PIN: ??_7MeshProvider_KeySupport@Render@Scaleform@@6B?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@2@@ 0x14318f1b0
// MS2-PIN: ??_7MeshProvider_KeySupport@Render@Scaleform@@6BMeshProvider@12@@ 0x14318f1b8
// MS2-PIN: ??_7MeshProvider_RCImpl@Render@Scaleform@@6B?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@2@@ 0x14318f138
// MS2-PIN: ??_7MeshProvider_RCImpl@Render@Scaleform@@6BMeshProvider@12@@ 0x14318f140
// MS2-PIN: ??_7MeshProvider@Render@Scaleform@@6B@ 0x14318f0c0
// MS2-PIN: ??_7ShapeDataInterface@Render@Scaleform@@6B@ 0x14317b678
// MS2-PIN: ??_7ShapeMeshProvider@Render@Scaleform@@6B?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@2@@ 0x14318f2a8
// MS2-PIN: ??_7ShapeMeshProvider@Render@Scaleform@@6BMeshProvider@12@@ 0x14318f2b0
// MS2-PIN: ??_7ShapeDataFloat@Render@Scaleform@@6B@ 0x14317bb98
// MS2-PIN: ??_7ShapeDataFloatMP@Render@Scaleform@@6B?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@2@@ 0x143191b40
// MS2-PIN: ??_7ShapeDataFloatMP@Render@Scaleform@@6BMeshProvider@12@@ 0x143191b48
// MS2-PIN: ??_7?$ShapeDataFloatTempl@V?$Array@E$01UArrayDefaultPolicy@Scaleform@@@Scaleform@@@Render@Scaleform@@6B@ 0x14317bb40
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142688b70 ; vtslot
// MS2-PIN: ??_G?$RefCountBase@VShapeDataInterface@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142688bd0 ; vtslot
// MS2-PIN: ??_GShapeDataInterface@Render@Scaleform@@UEAAPEAXI@Z 0x142688c30 ; vtslot
// MS2-PIN: ??_G?$RefCountBase@VMeshProvider_RCImpl@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x142688c90 ; vtslot
