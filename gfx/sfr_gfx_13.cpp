// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx statics of one translation unit with unknown CU name:
// the Random seed, the Render State interface singletons, the AS2 Point/Rectangle NaN parameter arrays, ATL module
// initialisers and the member-pointer tables of the video AS3 natives.
// MS2-UNIT: sfr_gfx_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14014cc20-0x14014ce60 .text$di
// MS2-RANGE: 0x140157e80-0x140157faf .text$di
// MS2-RANGE: 0x142c98f10-0x142c99d55 .text$mn
#include "../include/gfx/gfx_input.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include <atlbase.h>
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

// The video AS3 natives' member-pointer statics: one 16-byte (multiple-inheritance) member pointer per native, each
// converted from the native's own class (exe 0x143b27438..0x143b27798, set by one initialiser each). The natives'
// class is not recovered; they are reached through a stand-in class whose members are the exe addresses.
#pragma pointers_to_members(full_generality, multiple_inheritance)
class VideoNativesOwner;
class VideoNatives
{
public:
    void m_1400141b0();
    void m_140012d90();
    void m_1400141d0();
    void m_1400141f0();
    void m_140014210();
    void m_140014230();
    void m_140014250();
    void m_1400192e0();
    void m_140017f20();
    void m_140014270();
    void m_1400142a0();
    void m_1400142c0();
    void m_140019470();
    void m_1400142e0();
    void m_140014340();
    void m_1400143c0();
    void m_1400143e0();
    void m_140014400();
    void m_140014440();
    void m_140014460();
    void m_140014580();
    void m_1400145a0();
    void m_1400145c0();
    void m_1400145e0();
    void m_140014600();
    void m_140014620();
    void m_140014640();
    void m_140014660();
    void m_140014680();
    void m_140012da0();
    void m_1400146a0();
    void m_1400146c0();
    void m_140012db0();
    void m_1400146f0();
    void m_140012dc0();
    void m_140014700();
    void m_140012dd0();
    void m_140014710();
    void m_140012df0();
    void m_140014730();
    void m_140019660();
    void m_140014770();
    void m_1400147d0();
    void m_1400147f0();
    void m_140014810();
    void m_140014b50();
    void m_14001a330();
    void m_14001a360();
    void m_14001a390();
    void m_14001a3c0();
    void m_14001a060();
    void m_14001a070();
    void m_14001a3f0();
    void m_14001a410();
    void m_14001a460();
};
typedef void (VideoNativesOwner::*NativePmf)();

static NativePmf s_pmf_143b274d8 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400141b0);
static NativePmf s_pmf_143b27518 = reinterpret_cast<NativePmf>(&VideoNatives::m_140012d90);
static NativePmf s_pmf_143b276a8 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400141d0);
static NativePmf s_pmf_143b27698 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400141f0);
static NativePmf s_pmf_143b27458 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014210);
static NativePmf s_pmf_143b27478 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014230);
static NativePmf s_pmf_143b276c8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014250);
static NativePmf s_pmf_143b27528 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400192e0);
static NativePmf s_pmf_143b27678 = reinterpret_cast<NativePmf>(&VideoNatives::m_140017f20);
static NativePmf s_pmf_143b274f8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014270);
static NativePmf s_pmf_143b27448 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400142a0);
static NativePmf s_pmf_143b274c8 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400142c0);
static NativePmf s_pmf_143b27548 = reinterpret_cast<NativePmf>(&VideoNatives::m_140019470);
static NativePmf s_pmf_143b27708 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400142e0);
static NativePmf s_pmf_143b274b8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014340);
static NativePmf s_pmf_143b275f8 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400143c0);
static NativePmf s_pmf_143b27488 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400143e0);
static NativePmf s_pmf_143b27628 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014400);
static NativePmf s_pmf_143b27558 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014440);
static NativePmf s_pmf_143b276f8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014460);
static NativePmf s_pmf_143b276d8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014580);
static NativePmf s_pmf_143b27648 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400145a0);
static NativePmf s_pmf_143b27538 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400145c0);
static NativePmf s_pmf_143b27618 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400145e0);
static NativePmf s_pmf_143b27498 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014600);
static NativePmf s_pmf_143b27688 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014620);
static NativePmf s_pmf_143b274a8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014640);
static NativePmf s_pmf_143b27598 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014660);
static NativePmf s_pmf_143b275d8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014680);
static NativePmf s_pmf_143b276e8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140012da0);
static NativePmf s_pmf_143b276b8 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400146a0);
static NativePmf s_pmf_143b27578 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400146c0);
static NativePmf s_pmf_143b27568 = reinterpret_cast<NativePmf>(&VideoNatives::m_140012db0);
static NativePmf s_pmf_143b275c8 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400146f0);
static NativePmf s_pmf_143b27468 = reinterpret_cast<NativePmf>(&VideoNatives::m_140012dc0);
static NativePmf s_pmf_143b275a8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014700);
static NativePmf s_pmf_143b27508 = reinterpret_cast<NativePmf>(&VideoNatives::m_140012dd0);
static NativePmf s_pmf_143b27658 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014710);
static NativePmf s_pmf_143b274e8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140012df0);
static NativePmf s_pmf_143b27438 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014730);
static NativePmf s_pmf_143b275e8 = reinterpret_cast<NativePmf>(&VideoNatives::m_140019660);
static NativePmf s_pmf_143b27638 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014770);
static NativePmf s_pmf_143b275b8 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400147d0);
static NativePmf s_pmf_143b27608 = reinterpret_cast<NativePmf>(&VideoNatives::m_1400147f0);
static NativePmf s_pmf_143b27588 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014810);
static NativePmf s_pmf_143b27668 = reinterpret_cast<NativePmf>(&VideoNatives::m_140014b50);
namespace Scaleform { namespace Render {
#pragma optimize("", off)
Matrix3x4<float> g_identity3x4;   // 0x142c99a90
Matrix4x4<float> g_identity4x4;   // 0x142c99ad0
#pragma optimize("", on)
}}
static NativePmf s_pmf_143b27798 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a330);
static NativePmf s_pmf_143b27778 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a360);
static NativePmf s_pmf_143b27758 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a390);
static NativePmf s_pmf_143b27728 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a3c0);
static NativePmf s_pmf_143b27738 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a060);
static NativePmf s_pmf_143b27748 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a070);
static NativePmf s_pmf_143b27768 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a3f0);
static NativePmf s_pmf_143b27718 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a410);
static NativePmf s_pmf_143b27788 = reinterpret_cast<NativePmf>(&VideoNatives::m_14001a460);
// MS2-FUNCTIONAL: the exe builds each member-pointer static through a temporary copied as two qwords, ours copies it as one movups (no source form found that reproduces the two-qword copy); the Matrix3x4/4x4 Identity initialisers are constant-folded by our optimiser unless built unoptimised, so they call SetIdentity instead of the exe inline stores

// the CRT's per-thread error-mode toggle, run once at start-up (exe 0x140157f94; result kept for later queries)
extern "C" bool FUN_1429a8910(int mode, int flags);
static bool s_crtStartup = FUN_1429a8910(0, 0xe00);

// MS2-PIN: ??__E_AtlComModule@ATL@@YAXXZ 0x140157f54
// MS2-PIN: ??__E_AtlWinModule@ATL@@YAXXZ 0x140157f74
// MS2-PIN: ??_7Interface@StateData@Render@Scaleform@@6B@ 0x14318f0a8
// MS2-PIN: ??_7Interface_Value@StateData@Render@Scaleform@@6B@ 0x143192128
// MS2-PIN: ??_7Interface_RefCountImpl@StateData@Render@Scaleform@@6B@ 0x143192140
// MS2-PIN: ??_7Interface@MaskNodeState@Render@Scaleform@@6B@ 0x143192110
// MS2-PIN: ??__Es_pmf_143b274d8@@YAXXZ 0x142c98f10
// MS2-PIN: ??__Es_pmf_143b27518@@YAXXZ 0x142c98f50
// MS2-PIN: ??__Es_pmf_143b276a8@@YAXXZ 0x142c98f90
// MS2-PIN: ??__Es_pmf_143b27698@@YAXXZ 0x142c98fd0
// MS2-PIN: ??__Es_pmf_143b27458@@YAXXZ 0x142c99010
// MS2-PIN: ??__Es_pmf_143b27478@@YAXXZ 0x142c99050
// MS2-PIN: ??__Es_pmf_143b276c8@@YAXXZ 0x142c99090
// MS2-PIN: ??__Es_pmf_143b27528@@YAXXZ 0x142c990d0
// MS2-PIN: ??__Es_pmf_143b27678@@YAXXZ 0x142c99110
// MS2-PIN: ??__Es_pmf_143b274f8@@YAXXZ 0x142c99150
// MS2-PIN: ??__Es_pmf_143b27448@@YAXXZ 0x142c99190
// MS2-PIN: ??__Es_pmf_143b274c8@@YAXXZ 0x142c991d0
// MS2-PIN: ??__Es_pmf_143b27548@@YAXXZ 0x142c99210
// MS2-PIN: ??__Es_pmf_143b27708@@YAXXZ 0x142c99250
// MS2-PIN: ??__Es_pmf_143b274b8@@YAXXZ 0x142c99290
// MS2-PIN: ??__Es_pmf_143b275f8@@YAXXZ 0x142c992d0
// MS2-PIN: ??__Es_pmf_143b27488@@YAXXZ 0x142c99310
// MS2-PIN: ??__Es_pmf_143b27628@@YAXXZ 0x142c99350
// MS2-PIN: ??__Es_pmf_143b27558@@YAXXZ 0x142c99390
// MS2-PIN: ??__Es_pmf_143b276f8@@YAXXZ 0x142c993d0
// MS2-PIN: ??__Es_pmf_143b276d8@@YAXXZ 0x142c99410
// MS2-PIN: ??__Es_pmf_143b27648@@YAXXZ 0x142c99450
// MS2-PIN: ??__Es_pmf_143b27538@@YAXXZ 0x142c99490
// MS2-PIN: ??__Es_pmf_143b27618@@YAXXZ 0x142c994d0
// MS2-PIN: ??__Es_pmf_143b27498@@YAXXZ 0x142c99510
// MS2-PIN: ??__Es_pmf_143b27688@@YAXXZ 0x142c99550
// MS2-PIN: ??__Es_pmf_143b274a8@@YAXXZ 0x142c99590
// MS2-PIN: ??__Es_pmf_143b27598@@YAXXZ 0x142c995d0
// MS2-PIN: ??__Es_pmf_143b275d8@@YAXXZ 0x142c99610
// MS2-PIN: ??__Es_pmf_143b276e8@@YAXXZ 0x142c99650
// MS2-PIN: ??__Es_pmf_143b276b8@@YAXXZ 0x142c99690
// MS2-PIN: ??__Es_pmf_143b27578@@YAXXZ 0x142c996d0
// MS2-PIN: ??__Es_pmf_143b27568@@YAXXZ 0x142c99710
// MS2-PIN: ??__Es_pmf_143b275c8@@YAXXZ 0x142c99750
// MS2-PIN: ??__Es_pmf_143b27468@@YAXXZ 0x142c99790
// MS2-PIN: ??__Es_pmf_143b275a8@@YAXXZ 0x142c997d0
// MS2-PIN: ??__Es_pmf_143b27508@@YAXXZ 0x142c99810
// MS2-PIN: ??__Es_pmf_143b27658@@YAXXZ 0x142c99850
// MS2-PIN: ??__Es_pmf_143b274e8@@YAXXZ 0x142c99890
// MS2-PIN: ??__Es_pmf_143b27438@@YAXXZ 0x142c998d0
// MS2-PIN: ??__Es_pmf_143b275e8@@YAXXZ 0x142c99910
// MS2-PIN: ??__Es_pmf_143b27638@@YAXXZ 0x142c99950
// MS2-PIN: ??__Es_pmf_143b275b8@@YAXXZ 0x142c99990
// MS2-PIN: ??__Es_pmf_143b27608@@YAXXZ 0x142c999d0
// MS2-PIN: ??__Es_pmf_143b27588@@YAXXZ 0x142c99a10
// MS2-PIN: ??__Es_pmf_143b27668@@YAXXZ 0x142c99a50
// MS2-PIN: ??__Es_pmf_143b27798@@YAXXZ 0x142c99b20
// MS2-PIN: ??__Es_pmf_143b27778@@YAXXZ 0x142c99b60
// MS2-PIN: ??__Es_pmf_143b27758@@YAXXZ 0x142c99ba0
// MS2-PIN: ??__Es_pmf_143b27728@@YAXXZ 0x142c99be0
// MS2-PIN: ??__Es_pmf_143b27738@@YAXXZ 0x142c99c20
// MS2-PIN: ??__Es_pmf_143b27748@@YAXXZ 0x142c99c60
// MS2-PIN: ??__Es_pmf_143b27768@@YAXXZ 0x142c99ca0
// MS2-PIN: ??__Es_pmf_143b27718@@YAXXZ 0x142c99ce0
// MS2-PIN: ??__Es_pmf_143b27788@@YAXXZ 0x142c99d20
// MS2-PIN: ??__Eg_identity3x4@Render@Scaleform@@YAXXZ 0x142c99a90
// MS2-PIN: ??__Eg_identity4x4@Render@Scaleform@@YAXXZ 0x142c99ad0
