// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx statics of one translation unit with unknown CU name:
// the Random seed, the Render State interface singletons, the AS2 Point/Rectangle NaN parameter arrays, ATL module
// initialisers. The video AS3 natives' member pointers and the matrix identities are in sfr_gfx_13v.
// MS2-UNIT: sfr_gfx_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14014cc20-0x14014ce60 .text$di
// MS2-RANGE: 0x140157e80-0x140157faf .text$di
// MS2-RANGE: 0x142685ef0-0x142685ef3 .text$mn
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#pragma inline_depth(0)
#include <atlbase.h>
#pragma inline_depth()
// The exe's InitializeCAtlStringMgr initialiser inlines the initializer's ctor but tail-calls GetInstance.
#pragma inline_depth(1)
#include <atlstr.h>
#pragma inline_depth()
#include <stdlib.h>
#include "../kernel/sf_random.h"
#include "../kernel/sf_timer.h"
#include "../include/render/render_states.h"
#include "../include/render/render_matrix2x4.h"
#include "../include/render/render_matrix4x4.h"
#include "../include/gfx/gfx_asutils.h"

namespace Scaleform { namespace Alg {
extern Random::Generator Random_Generator1;
// the shared generator's seeding, run here because its definition lives in the Random unit (exe 0x14014cc20)
static struct Random_Generator1_Seed
{
    Random_Generator1_Seed() { Random_Generator1.SeedRandom(Timer::GetTicksMs()); }
} s_random_generator1_seed;
}}

// Exit-time teardown of constant-initialized statics whose destructors the exe emitted in sfr_atexit_01: the statics
// need no constructor, so this unit's initialisers only register each destructor with atexit.
namespace Scaleform { namespace GFx {
void FUN_142cc9520();
void FUN_142cc9530();
void FUN_142cca410();
void FUN_142cca4d0();
void FUN_142cc95f0();
void FUN_142cc9610();
void FUN_142cc9630();
void FUN_142cc9650();
void FUN_142cc9670();
void FUN_142cc9690();
void FUN_142cc96b0();
void FUN_142cc96d0();
void FUN_142cc96f0();
void FUN_142cc98d0();
void FUN_142cca370();
}}
struct AtexitRegistration
{
    AtexitRegistration(void (*dtor)()) { atexit(dtor); }
};

// An initialiser that only calls an empty out-of-line function (exe 0x14014cc40 -> 0x142685ef0).
// @0x142685ef0
// MS2-FUNCTIONAL: the exe's body is the 3-byte `ret 0` encoding, ours the 1-byte `ret`
extern "C" __declspec(noinline) void FUN_142685ef0() {}
static struct EmptyInit
{
    EmptyInit() { FUN_142685ef0(); }
} s_emptyInit;
// the FontResourceCreator static (0x143a2f430) and the system-font KeyInterface instance (0x143a2f690)
static AtexitRegistration s_atexit_143a2f430(&Scaleform::GFx::FUN_142cc9520);
static AtexitRegistration s_atexit_143a2f690(&Scaleform::GFx::FUN_142cc9530);
// the render vertex formats' Ptr<SystemVertexFormat> slots and a static Ptr<> (dtors in sfr_atexit_01). Not in the hook
// DLL: the exe registers its own copies, and a second exit-time release would underflow the shared statics.
#ifndef MS2_HOOK_DLL
static AtexitRegistration s_atexit_143a2f978(&Scaleform::GFx::FUN_142cc95f0);   // Image9GridVertex::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fb98(&Scaleform::GFx::FUN_142cc9610);   // VertexXY16f::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fbb0(&Scaleform::GFx::FUN_142cc9630);   // VertexXY16fAlpha::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fb80(&Scaleform::GFx::FUN_142cc9650);   // VertexXY16i::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fbe0(&Scaleform::GFx::FUN_142cc9670);   // VertexXY16iAlpha::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fbc8(&Scaleform::GFx::FUN_142cc9690);   // VertexXY16iC32::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fbf8(&Scaleform::GFx::FUN_142cc96b0);   // VertexXY16iCF32::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fc10(&Scaleform::GFx::FUN_142cc96d0);   // VertexXY16iInstance::Format.pSysFormat
static AtexitRegistration s_atexit_143a2fc28(&Scaleform::GFx::FUN_142cc96f0);   // VertexXY16iUV::Format.pSysFormat
static AtexitRegistration s_atexit_143a30338(&Scaleform::GFx::FUN_142cc98d0);   // ImageGlyphVertex::Format.pSysFormat
#endif

namespace Scaleform { namespace Render {
BlendState::Interface BlendState::InterfaceImpl(State_BlendMode);
FilterState::Interface FilterState::InterfaceImpl(State_Filter);
Internal_MaskOwnerState::Interface Internal_MaskOwnerState::InterfaceImpl(State_Internal_MaskOwner);
MaskNodeState::Interface MaskNodeState::InterfaceImpl;
ProjectionMatrix3DState::Interface ProjectionMatrix3DState::InterfaceImpl(State_ProjectionMatrix3D);
Scale9State::Interface Scale9State::InterfaceImpl(State_Scale9);
ViewMatrix3DState::Interface ViewMatrix3DState::InterfaceImpl(State_ViewMatrix3D);
static StateData::Interface_Value s_noneInterface(State_None);
}}

namespace Scaleform { namespace GFx { namespace AS2 {
const Value Point_NanParams[Point_NumProperties] = { Value(NumberUtil::NaN()), Value(NumberUtil::NaN()) };
}}}
// AS2 Point_DefaultParams, Value[2] at 0x143a51b70
#ifndef MS2_HOOK_DLL   // as above
static AtexitRegistration s_atexit_143a51b70(&Scaleform::GFx::FUN_142cca370);
#endif
// AS2 Rectangle_DefaultParams, Value[4] at 0x143a51bb0
static AtexitRegistration s_atexit_143a51bb0(&Scaleform::GFx::FUN_142cca410);
namespace Scaleform { namespace GFx { namespace AS2 {
const Value Rectangle_NaNParams[Rectangle_NumProperties] = { Value(NumberUtil::NaN()), Value(NumberUtil::NaN()), Value(NumberUtil::NaN()), Value(NumberUtil::NaN()) };
}}}
// AS2 Object_NotsetVal (0x143a51b50)
static AtexitRegistration s_atexit_143a51b50(&Scaleform::GFx::FUN_142cca4d0);


// MFC appmodul's _afxInitAppState = (char)AfxInitialize(FALSE, _MFC_VER), run once at start-up (exe 0x140157f94)
int AfxInitialize(int bDLL, unsigned long dwVersion);
static char s_crtStartup = (char)AfxInitialize(0, 0xe00);

// MS2-PIN: ??__Es_emptyInit@@YAXXZ 0x14014cc40
// MS2-PIN: ??__Es_atexit_143a2f430@@YAXXZ 0x14014cc50
// MS2-PIN: ??__Es_atexit_143a2f690@@YAXXZ 0x14014cc60
// MS2-PIN: ??__Es_atexit_143a51bb0@@YAXXZ 0x140157ec0
// MS2-PIN: ??__Es_atexit_143a51b50@@YAXXZ 0x140157f40
// MS2-PIN: ??__EInitializeCAtlStringMgr@ATLImplementationDetails@ATL@@YAXXZ 0x140157f4c
// MS2-PIN: ??__E_AtlComModule@ATL@@YAXXZ 0x140157f54
// MS2-PIN: ??__E_AtlWinModule@ATL@@YAXXZ 0x140157f74
// MS2-PIN: ??_7Interface@StateData@Render@Scaleform@@6B@ 0x14318f0a8
// MS2-PIN: ??_7Interface_Value@StateData@Render@Scaleform@@6B@ 0x143192128
// MS2-PIN: ??_7Interface_RefCountImpl@StateData@Render@Scaleform@@6B@ 0x143192140
// MS2-PIN: ??_7Interface@MaskNodeState@Render@Scaleform@@6B@ 0x143192110
// MS2-RANGE: 0x14014ce60-0x14014ceec .text$di
// MS2-RANGE: 0x14014d0f0-0x14014d0fc .text$di
// MS2-RANGE: 0x140157e70-0x140157e7c .text$di
// MS2-FUNCTIONAL 0x142cca4e8: the header-generated ??__F_AtlComModule tail-jumps to ~CAtlComModule; the exe inlines that dtor (Term()). Both atexit thunks come from <atlbase.h>'s selectany definition, which this TU compiles under inline_depth(0) so the ??__E initialisers keep their ctors out of line, as in the exe.
// MS2-FUNCTIONAL 0x142cca508: same for ??__F_AtlWinModule (the exe inlines ~CAtlWinModule: AtlWinModuleTerm plus the critical-section/field resets).
// MS2-RANGE: 0x142cca4e8-0x142cca54c .text$yd
// MS2-PIN: ??__Es_atexit_143a2f978@@YAXXZ 0x14014ce60
// MS2-PIN: ??__Es_atexit_143a2fb98@@YAXXZ 0x14014ce70
// MS2-PIN: ??__Es_atexit_143a2fbb0@@YAXXZ 0x14014ce80
// MS2-PIN: ??__Es_atexit_143a2fb80@@YAXXZ 0x14014ce90
// MS2-PIN: ??__Es_atexit_143a2fbe0@@YAXXZ 0x14014cea0
// MS2-PIN: ??__Es_atexit_143a2fbc8@@YAXXZ 0x14014ceb0
// MS2-PIN: ??__Es_atexit_143a2fbf8@@YAXXZ 0x14014cec0
// MS2-PIN: ??__Es_atexit_143a2fc10@@YAXXZ 0x14014ced0
// MS2-PIN: ??__Es_atexit_143a2fc28@@YAXXZ 0x14014cee0
// MS2-PIN: ??__Es_atexit_143a30338@@YAXXZ 0x14014d0f0
// MS2-PIN: ??__Es_atexit_143a51b70@@YAXXZ 0x140157e70
// MS2-PIN: ??__F_AtlComModule@ATL@@YAXXZ 0x142cca4e8
// MS2-PIN: ??__F_AtlWinModule@ATL@@YAXXZ 0x142cca508

// RasterGlyphVertex::Format.pSysFormat (0x143a2fe50+0x10). The Format itself is a data blob in data_data_game, so its
// own ??__E has nothing to hang on; registered here like the other vertex formats (dtor in sfr_atexit_01).
#ifndef MS2_HOOK_DLL
namespace Scaleform { namespace GFx { void FUN_142cc9870(); }}
static AtexitRegistration s_atexit_143a2fe60(&Scaleform::GFx::FUN_142cc9870);
#endif
// MS2-RANGE: 0x14014d0c0-0x14014d0cc .text$di
// MS2-RANGE: 0x142cc9570-0x142cc957f .text$yd
// MS2-RANGE: 0x142cc9580-0x142cc958f .text$yd
// MS2-RANGE: 0x142cc9590-0x142cc959f .text$yd
// MS2-RANGE: 0x142cc95a0-0x142cc95af .text$yd
// MS2-RANGE: 0x142cc95b0-0x142cc95bf .text$yd
// MS2-RANGE: 0x142cc95c0-0x142cc95cf .text$yd
// MS2-RANGE: 0x142cc95d0-0x142cc95df .text$yd
// MS2-RANGE: 0x142cc95e0-0x142cc95ef .text$yd
// MS2-PIN: ??__Es_atexit_143a2fe60@@YAXXZ 0x14014d0c0
// MS2-PIN: ??__F?InterfaceImpl@BlendState@Render@Scaleform@@2VInterface_Value@StateData@23@A@@YAXXZ 0x142cc9570
// MS2-PIN: ??__F?InterfaceImpl@FilterState@Render@Scaleform@@2VInterface_RefCountImpl@StateData@23@A@@YAXXZ 0x142cc9580
// MS2-PIN: ??__F?InterfaceImpl@Internal_MaskOwnerState@Render@Scaleform@@2VInterface_Value@StateData@23@A@@YAXXZ 0x142cc9590
// MS2-PIN: ??__F?InterfaceImpl@MaskNodeState@Render@Scaleform@@2VInterface@123@A@@YAXXZ 0x142cc95a0
// MS2-PIN: ??__F?InterfaceImpl@ProjectionMatrix3DState@Render@Scaleform@@2VInterface_RefCountImpl@StateData@23@A@@YAXXZ 0x142cc95b0
// MS2-PIN: ??__F?InterfaceImpl@Scale9State@Render@Scaleform@@2VInterface_RefCountImpl@StateData@23@A@@YAXXZ 0x142cc95c0
// MS2-PIN: ??__F?InterfaceImpl@ViewMatrix3DState@Render@Scaleform@@2VInterface_RefCountImpl@StateData@23@A@@YAXXZ 0x142cc95d0
// MS2-PIN: ??__Fs_noneInterface@Render@Scaleform@@YAXXZ 0x142cc95e0
