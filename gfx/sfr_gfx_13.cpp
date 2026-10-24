// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx statics of one translation unit with unknown CU name:
// the Random seed, the Render State interface singletons, the AS2 Point/Rectangle NaN parameter arrays, ATL module
// initialisers and the member-pointer tables of the video AS3 natives.
// MS2-UNIT: sfr_gfx_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14014cc20-0x14014ce60 .text$di
// MS2-RANGE: 0x140157e80-0x140157faf .text$di
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include <atlbase.h>
#include "../kernel/sf_random.h"
#include "../kernel/sf_timer.h"
#include "../include/render/render_states.h"
#include "../include/gfx/gfx_asutils.h"

namespace Scaleform { namespace Alg {
extern Random::Generator Random_Generator1;
// the shared generator's seeding, run here because its definition lives in the Random unit (exe 0x14014cc20)
static struct Random_Generator1_Seed
{
    Random_Generator1_Seed() { Random_Generator1.SeedRandom(Timer::GetTicksMs()); }
} s_random_generator1_seed;
}}

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
const Value Rectangle_NaNParams[Rectangle_NumProperties] = { Value(NumberUtil::NaN()), Value(NumberUtil::NaN()), Value(NumberUtil::NaN()), Value(NumberUtil::NaN()) };
}}}

// the CRT's per-thread error-mode toggle, run once at start-up (exe 0x140157f94; result kept for later queries)
extern "C" bool FUN_1429a8910(int mode, int flags);
static bool s_crtStartup = FUN_1429a8910(0, 0xe00);

// MS2-PIN: ??__E_AtlComModule@ATL@@YAXXZ 0x140157f54
// MS2-PIN: ??__E_AtlWinModule@ATL@@YAXXZ 0x140157f74
// MS2-PIN: ??_7Interface@StateData@Render@Scaleform@@6B@ 0x14318f0a8
// MS2-PIN: ??_7Interface_Value@StateData@Render@Scaleform@@6B@ 0x143192128
// MS2-PIN: ??_7Interface_RefCountImpl@StateData@Render@Scaleform@@6B@ 0x143192140
// MS2-PIN: ??_7Interface@MaskNodeState@Render@Scaleform@@6B@ 0x143192110
