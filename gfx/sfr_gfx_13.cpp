// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scaleform GFx statics of one translation unit with unknown CU name:
// the Random seed, the Render State interface singletons, the AS2 Point/Rectangle NaN parameter arrays, ATL module
// initialisers and the member-pointer tables of the video AS3 natives.
// MS2-UNIT: sfr_gfx_13
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14014cc20-0x14014ce60 .text$di
// MS2-RANGE: 0x140157e80-0x140157faf .text$di
// MS2-RANGE: 0x142c98f10-0x142c99d55 .text$mn
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

// The video AS3 natives' member-pointer statics: one 16-byte (multiple-inheritance) member pointer per native, each
// built (exe 0x143b27438..0x143b27798, set by one initialiser each). The natives'
// class is not recovered; each holds the code pointer of the free native (sfr_video_02) with a zero adjustor.
#pragma pointers_to_members(full_generality, multiple_inheritance)
class VideoNativesOwner;
namespace Scaleform { namespace GFx { namespace AS3 { class Object; class Value; }}}
// the natives themselves (sfr_video_02)
void FUN_140012d90(void*, double*);
void FUN_140012da0(void*, bool*);
void FUN_140012db0(void*, double*);
void FUN_140012dc0(void*, double*);
void FUN_140012dd0(void*, double*);
void FUN_140012df0(void*, double*);
void FUN_1400141b0(Scaleform::GFx::AS3::Object*);
void FUN_1400141d0(void*, const void*, double);
void FUN_1400141f0(Scaleform::GFx::AS3::Object*);
void FUN_140014210(Scaleform::GFx::AS3::Object*);
void FUN_140014230(Scaleform::GFx::AS3::Object*);
void FUN_140014250(Scaleform::GFx::AS3::Object*);
void FUN_140014270(void*, double*);
void FUN_1400142a0(Scaleform::GFx::AS3::Object*);
void FUN_1400142c0(Scaleform::GFx::AS3::Object*);
void FUN_140014340(void*, double*);
void FUN_1400143c0(Scaleform::GFx::AS3::Object*);
void FUN_1400143e0(Scaleform::GFx::AS3::Object*);
void FUN_140014400(void*, void*, char);
void FUN_140014440(void*);
void FUN_140014460(void*, void*, int, const Scaleform::GFx::AS3::Value*);
void FUN_140014580(Scaleform::GFx::AS3::Object*);
void FUN_1400145a0(Scaleform::GFx::AS3::Object*);
void FUN_1400145c0(Scaleform::GFx::AS3::Object*);
void FUN_1400145e0(Scaleform::GFx::AS3::Object*);
void FUN_140014600(void*);
void FUN_140014620(Scaleform::GFx::AS3::Object*, const void*, double);
void FUN_140014640(Scaleform::GFx::AS3::Object*);
void FUN_140014660(Scaleform::GFx::AS3::Object*);
void FUN_140014680(void*);
void FUN_1400146a0(void*, const void*, bool);
void FUN_1400146c0(void*, double*);
void FUN_1400146f0(void*, const void*, double);
void FUN_140014700(void*, const void*, double);
void FUN_140014710(void*, const void*, double);
void FUN_140014730(void*, void*, double);
void FUN_1400147d0(void*, const void*, double);
void FUN_1400147f0(void*, const void*, double);
void FUN_140014810(void*, const void*, double);
void FUN_140014b50(Scaleform::GFx::AS3::Object*);
void FUN_140017f20(void*, void*, void*);
void FUN_1400192e0(void*, unsigned __int64*);
void FUN_140019470(void*, unsigned __int64*);
void FUN_140019660(void*, unsigned __int64*);
void FUN_14001a060(void*, int*);
void FUN_14001a070(void*, int*);
void FUN_14001a330(void*, unsigned*);
void FUN_14001a360(void*, void*, unsigned);
void FUN_14001a390(void*, unsigned char*);
void FUN_14001a3c0(void*, void*, unsigned char);
void FUN_14001a3f0(Scaleform::GFx::AS3::Object*);
void FUN_14001a410(void*, void*, void*);
void FUN_14001a460(void*);
namespace Scaleform { namespace GFx { namespace AS2 {
void FUN_1400142e0(void*, void*, void*);
void FUN_140014770(void*, void*, void*);
}}}
typedef void (VideoNativesOwner::*NativePmf)();
// a member pointer to a free native: code pointer and a zero adjustor
struct NativePmfBits { void* fn; int adjust; };
template <class F> static __forceinline NativePmf MakeNativePmf(F fn)
{
    NativePmfBits bits = { reinterpret_cast<void*>(fn), 0 };
    return *reinterpret_cast<const NativePmf*>(&bits);
}

static NativePmf s_pmf_143b274d8 = MakeNativePmf(&FUN_1400141b0);
static NativePmf s_pmf_143b27518 = MakeNativePmf(&FUN_140012d90);
static NativePmf s_pmf_143b276a8 = MakeNativePmf(&FUN_1400141d0);
static NativePmf s_pmf_143b27698 = MakeNativePmf(&FUN_1400141f0);
static NativePmf s_pmf_143b27458 = MakeNativePmf(&FUN_140014210);
static NativePmf s_pmf_143b27478 = MakeNativePmf(&FUN_140014230);
static NativePmf s_pmf_143b276c8 = MakeNativePmf(&FUN_140014250);
static NativePmf s_pmf_143b27528 = MakeNativePmf(&FUN_1400192e0);
static NativePmf s_pmf_143b27678 = MakeNativePmf(&FUN_140017f20);
static NativePmf s_pmf_143b274f8 = MakeNativePmf(&FUN_140014270);
static NativePmf s_pmf_143b27448 = MakeNativePmf(&FUN_1400142a0);
static NativePmf s_pmf_143b274c8 = MakeNativePmf(&FUN_1400142c0);
static NativePmf s_pmf_143b27548 = MakeNativePmf(&FUN_140019470);
static NativePmf s_pmf_143b27708 = MakeNativePmf(&Scaleform::GFx::AS2::FUN_1400142e0);
static NativePmf s_pmf_143b274b8 = MakeNativePmf(&FUN_140014340);
static NativePmf s_pmf_143b275f8 = MakeNativePmf(&FUN_1400143c0);
static NativePmf s_pmf_143b27488 = MakeNativePmf(&FUN_1400143e0);
static NativePmf s_pmf_143b27628 = MakeNativePmf(&FUN_140014400);
static NativePmf s_pmf_143b27558 = MakeNativePmf(&FUN_140014440);
static NativePmf s_pmf_143b276f8 = MakeNativePmf(&FUN_140014460);
static NativePmf s_pmf_143b276d8 = MakeNativePmf(&FUN_140014580);
static NativePmf s_pmf_143b27648 = MakeNativePmf(&FUN_1400145a0);
static NativePmf s_pmf_143b27538 = MakeNativePmf(&FUN_1400145c0);
static NativePmf s_pmf_143b27618 = MakeNativePmf(&FUN_1400145e0);
static NativePmf s_pmf_143b27498 = MakeNativePmf(&FUN_140014600);
static NativePmf s_pmf_143b27688 = MakeNativePmf(&FUN_140014620);
static NativePmf s_pmf_143b274a8 = MakeNativePmf(&FUN_140014640);
static NativePmf s_pmf_143b27598 = MakeNativePmf(&FUN_140014660);
static NativePmf s_pmf_143b275d8 = MakeNativePmf(&FUN_140014680);
static NativePmf s_pmf_143b276e8 = MakeNativePmf(&FUN_140012da0);
static NativePmf s_pmf_143b276b8 = MakeNativePmf(&FUN_1400146a0);
static NativePmf s_pmf_143b27578 = MakeNativePmf(&FUN_1400146c0);
static NativePmf s_pmf_143b27568 = MakeNativePmf(&FUN_140012db0);
static NativePmf s_pmf_143b275c8 = MakeNativePmf(&FUN_1400146f0);
static NativePmf s_pmf_143b27468 = MakeNativePmf(&FUN_140012dc0);
static NativePmf s_pmf_143b275a8 = MakeNativePmf(&FUN_140014700);
static NativePmf s_pmf_143b27508 = MakeNativePmf(&FUN_140012dd0);
static NativePmf s_pmf_143b27658 = MakeNativePmf(&FUN_140014710);
static NativePmf s_pmf_143b274e8 = MakeNativePmf(&FUN_140012df0);
static NativePmf s_pmf_143b27438 = MakeNativePmf(&FUN_140014730);
static NativePmf s_pmf_143b275e8 = MakeNativePmf(&FUN_140019660);
static NativePmf s_pmf_143b27638 = MakeNativePmf(&Scaleform::GFx::AS2::FUN_140014770);
static NativePmf s_pmf_143b275b8 = MakeNativePmf(&FUN_1400147d0);
static NativePmf s_pmf_143b27608 = MakeNativePmf(&FUN_1400147f0);
static NativePmf s_pmf_143b27588 = MakeNativePmf(&FUN_140014810);
static NativePmf s_pmf_143b27668 = MakeNativePmf(&FUN_140014b50);
namespace Scaleform { namespace Render {
// this unit's dynamic initialisers of the identity matrices construct Matrix3x4<float>::Identity / Matrix4x4<float>::Identity
// (0x143aee540 / 0x143aee570) in place: the matrices themselves are the template statics, so each initialiser is an empty object
// (no second matrix storage at those addresses)
struct Identity3x4Init { Identity3x4Init() { new (&Matrix3x4<float>::Identity) Matrix3x4<float>(); } };
struct Identity4x4Init { Identity4x4Init() { new (&Matrix4x4<float>::Identity) Matrix4x4<float>(); } };
Identity3x4Init g_identity3x4;   // 0x142c99a90
Identity4x4Init g_identity4x4;   // 0x142c99ad0
}}
static NativePmf s_pmf_143b27798 = MakeNativePmf(&FUN_14001a330);
static NativePmf s_pmf_143b27778 = MakeNativePmf(&FUN_14001a360);
static NativePmf s_pmf_143b27758 = MakeNativePmf(&FUN_14001a390);
static NativePmf s_pmf_143b27728 = MakeNativePmf(&FUN_14001a3c0);
static NativePmf s_pmf_143b27738 = MakeNativePmf(&FUN_14001a060);
static NativePmf s_pmf_143b27748 = MakeNativePmf(&FUN_14001a070);
static NativePmf s_pmf_143b27768 = MakeNativePmf(&FUN_14001a3f0);
static NativePmf s_pmf_143b27718 = MakeNativePmf(&FUN_14001a410);
static NativePmf s_pmf_143b27788 = MakeNativePmf(&FUN_14001a460);
// MS2-FUNCTIONAL: the exe builds each member-pointer static through a temporary copied as two qwords, ours copies it as one movups (no source form found that reproduces the two-qword copy); the Matrix3x4/4x4 Identity initialisers are constant-folded by our optimiser unless built unoptimised, so they call SetIdentity instead of the exe inline stores

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

#ifndef MS2_HOOK_DLL
// MS2: boot tag 92: the natives read each member pointer through the exe-address global DAT_<va> (data_cri / stubs),
// which these statics never filled: mirror the code pointer of each (all adjustors are 0) after they are built.
extern void* DAT_143b274d8;
extern void* DAT_143b27518;
extern void* DAT_143b276a8;
extern void* DAT_143b27698;
extern void* DAT_143b27458;
extern void* DAT_143b27478;
extern void* DAT_143b276c8;
extern void* DAT_143b27528;
extern void* DAT_143b27678;
extern void* DAT_143b274f8;
extern void* DAT_143b27448;
extern void* DAT_143b274c8;
extern void* DAT_143b27548;
extern void* DAT_143b27708;
extern void* DAT_143b274b8;
extern void* DAT_143b275f8;
extern void* DAT_143b27488;
extern void* DAT_143b27628;
extern void* DAT_143b27558;
extern void* DAT_143b276f8;
extern void* DAT_143b276d8;
extern void* DAT_143b27648;
extern void* DAT_143b27538;
extern void* DAT_143b27618;
extern void* DAT_143b27498;
extern void* DAT_143b27688;
extern void* DAT_143b274a8;
extern void* DAT_143b27598;
extern void* DAT_143b275d8;
extern void* DAT_143b276e8;
extern void* DAT_143b276b8;
extern void* DAT_143b27578;
extern void* DAT_143b27568;
extern void* DAT_143b275c8;
extern void* DAT_143b27468;
extern void* DAT_143b275a8;
extern void* DAT_143b27508;
extern void* DAT_143b27658;
extern void* DAT_143b274e8;
extern void* DAT_143b27438;
extern void* DAT_143b275e8;
extern void* DAT_143b27638;
extern void* DAT_143b275b8;
extern void* DAT_143b27608;
extern void* DAT_143b27588;
extern void* DAT_143b27668;
extern void* DAT_143b27798;
extern void* DAT_143b27778;
extern void* DAT_143b27758;
extern void* DAT_143b27728;
extern void* DAT_143b27738;
extern void* DAT_143b27748;
extern void* DAT_143b27768;
extern void* DAT_143b27718;
extern void* DAT_143b27788;
static struct PmfMirror { PmfMirror() {
    DAT_143b274d8 = *reinterpret_cast<void* const*>(&s_pmf_143b274d8);
    DAT_143b27518 = *reinterpret_cast<void* const*>(&s_pmf_143b27518);
    DAT_143b276a8 = *reinterpret_cast<void* const*>(&s_pmf_143b276a8);
    DAT_143b27698 = *reinterpret_cast<void* const*>(&s_pmf_143b27698);
    DAT_143b27458 = *reinterpret_cast<void* const*>(&s_pmf_143b27458);
    DAT_143b27478 = *reinterpret_cast<void* const*>(&s_pmf_143b27478);
    DAT_143b276c8 = *reinterpret_cast<void* const*>(&s_pmf_143b276c8);
    DAT_143b27528 = *reinterpret_cast<void* const*>(&s_pmf_143b27528);
    DAT_143b27678 = *reinterpret_cast<void* const*>(&s_pmf_143b27678);
    DAT_143b274f8 = *reinterpret_cast<void* const*>(&s_pmf_143b274f8);
    DAT_143b27448 = *reinterpret_cast<void* const*>(&s_pmf_143b27448);
    DAT_143b274c8 = *reinterpret_cast<void* const*>(&s_pmf_143b274c8);
    DAT_143b27548 = *reinterpret_cast<void* const*>(&s_pmf_143b27548);
    DAT_143b27708 = *reinterpret_cast<void* const*>(&s_pmf_143b27708);
    DAT_143b274b8 = *reinterpret_cast<void* const*>(&s_pmf_143b274b8);
    DAT_143b275f8 = *reinterpret_cast<void* const*>(&s_pmf_143b275f8);
    DAT_143b27488 = *reinterpret_cast<void* const*>(&s_pmf_143b27488);
    DAT_143b27628 = *reinterpret_cast<void* const*>(&s_pmf_143b27628);
    DAT_143b27558 = *reinterpret_cast<void* const*>(&s_pmf_143b27558);
    DAT_143b276f8 = *reinterpret_cast<void* const*>(&s_pmf_143b276f8);
    DAT_143b276d8 = *reinterpret_cast<void* const*>(&s_pmf_143b276d8);
    DAT_143b27648 = *reinterpret_cast<void* const*>(&s_pmf_143b27648);
    DAT_143b27538 = *reinterpret_cast<void* const*>(&s_pmf_143b27538);
    DAT_143b27618 = *reinterpret_cast<void* const*>(&s_pmf_143b27618);
    DAT_143b27498 = *reinterpret_cast<void* const*>(&s_pmf_143b27498);
    DAT_143b27688 = *reinterpret_cast<void* const*>(&s_pmf_143b27688);
    DAT_143b274a8 = *reinterpret_cast<void* const*>(&s_pmf_143b274a8);
    DAT_143b27598 = *reinterpret_cast<void* const*>(&s_pmf_143b27598);
    DAT_143b275d8 = *reinterpret_cast<void* const*>(&s_pmf_143b275d8);
    DAT_143b276e8 = *reinterpret_cast<void* const*>(&s_pmf_143b276e8);
    DAT_143b276b8 = *reinterpret_cast<void* const*>(&s_pmf_143b276b8);
    DAT_143b27578 = *reinterpret_cast<void* const*>(&s_pmf_143b27578);
    DAT_143b27568 = *reinterpret_cast<void* const*>(&s_pmf_143b27568);
    DAT_143b275c8 = *reinterpret_cast<void* const*>(&s_pmf_143b275c8);
    DAT_143b27468 = *reinterpret_cast<void* const*>(&s_pmf_143b27468);
    DAT_143b275a8 = *reinterpret_cast<void* const*>(&s_pmf_143b275a8);
    DAT_143b27508 = *reinterpret_cast<void* const*>(&s_pmf_143b27508);
    DAT_143b27658 = *reinterpret_cast<void* const*>(&s_pmf_143b27658);
    DAT_143b274e8 = *reinterpret_cast<void* const*>(&s_pmf_143b274e8);
    DAT_143b27438 = *reinterpret_cast<void* const*>(&s_pmf_143b27438);
    DAT_143b275e8 = *reinterpret_cast<void* const*>(&s_pmf_143b275e8);
    DAT_143b27638 = *reinterpret_cast<void* const*>(&s_pmf_143b27638);
    DAT_143b275b8 = *reinterpret_cast<void* const*>(&s_pmf_143b275b8);
    DAT_143b27608 = *reinterpret_cast<void* const*>(&s_pmf_143b27608);
    DAT_143b27588 = *reinterpret_cast<void* const*>(&s_pmf_143b27588);
    DAT_143b27668 = *reinterpret_cast<void* const*>(&s_pmf_143b27668);
    DAT_143b27798 = *reinterpret_cast<void* const*>(&s_pmf_143b27798);
    DAT_143b27778 = *reinterpret_cast<void* const*>(&s_pmf_143b27778);
    DAT_143b27758 = *reinterpret_cast<void* const*>(&s_pmf_143b27758);
    DAT_143b27728 = *reinterpret_cast<void* const*>(&s_pmf_143b27728);
    DAT_143b27738 = *reinterpret_cast<void* const*>(&s_pmf_143b27738);
    DAT_143b27748 = *reinterpret_cast<void* const*>(&s_pmf_143b27748);
    DAT_143b27768 = *reinterpret_cast<void* const*>(&s_pmf_143b27768);
    DAT_143b27718 = *reinterpret_cast<void* const*>(&s_pmf_143b27718);
    DAT_143b27788 = *reinterpret_cast<void* const*>(&s_pmf_143b27788);
} } s_pmfMirror;
#endif
