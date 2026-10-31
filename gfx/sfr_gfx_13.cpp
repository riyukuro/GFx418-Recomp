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
#include <atlbase.h>
#include <atlstr.h>
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

