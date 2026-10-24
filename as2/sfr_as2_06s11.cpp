// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 GlobalContext::Init of
// sfr_as2_06 (gap recovery, lane sfr24): the _global object, the Object / Function / MovieClip / Key classes made up
// front, the global functions, every other builtin class registered for first use (in _global or its package) and
// the _global members hidden from enumeration.
// MS2-UNIT: sfr_as2_06s11
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14295e2b0-0x14296153f .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_ime.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_movieroot.h"

// The hash add of HashUncachedLH<ASBuiltinType, Ptr<Object>> (exe 0x14000b9e0, defined in sfr_video_01).
void FUN_14000b9e0(Scaleform::UPInt* tableRef, void* owner, void** pair, Scaleform::UPInt hash);

namespace Scaleform { namespace GFx { namespace AS2 {

// The folded ASStringHash<ClassRegEntry>::Get (exe 0x140001bd0).
GlobalContext::ClassRegEntry* FUN_140001bd0(ASStringHash<GlobalContext::ClassRegEntry>* phash, const ASString& key);

// The _global functions (sfr_as2_01; setInterval / setTimeout and updateAfterEvent are not recovered as names).
void FUN_1428f6de0(const FnCall& fn); // trace
void FUN_1428f70b0(const FnCall& fn); // parseInt
void FUN_1428f73b0(const FnCall& fn); // parseFloat
void FUN_1428f74a0(const FnCall& fn); // ifFrameLoaded
void FUN_1428f7580(const FnCall& fn); // isNaN
void FUN_1428f7650(const FnCall& fn); // isFinite
void FUN_1428f7ed0(const FnCall& fn); // escape
void FUN_1428f8020(const FnCall& fn); // unescape
void FUN_1428f8170(const FnCall& fn); // escapeSpecialHTML
void FUN_1428f83d0(const FnCall& fn); // unescapeSpecialHTML
void FUN_1428f8530(const FnCall& fn); // updateAfterEvent (does nothing)
void FUN_1428fbb70(const FnCall& fn); // setInterval
void FUN_1428fbb80(const FnCall& fn); // clearInterval
void FUN_1428fbc40(const FnCall& fn); // setTimeout
void FUN_1428fbc50(const FnCall& fn); // clearTimeout
void FUN_1428f8540(const FnCall& fn); // imecommand
void FUN_1428f9f50(const FnCall& fn); // setIMECandidateListStyle
void FUN_1428fafd0(const FnCall& fn); // getInputLanguage
void FUN_1428fa7a0(const FnCall& fn); // getIMECandidateListStyle
void FUN_1428f7740(const FnCall& fn); // ASSetPropFlags
void FUN_1428f7d30(const FnCall& fn); // ASnative

// System.capabilities (defined in sfr_as2_03h): only its registration is referenced here.
class CapabilitiesCtorFunction : public CFunctionObject
{
public:
    static FunctionRef Register(GlobalContext* pgc);
};

// The _global object: an Object that knows its context.
class GASGlobalObject : public Object
{
public:
    GlobalContext* pContext; // +0x68
    GASGlobalObject(GlobalContext* pcontext); // exe 0x14291c160
};

namespace {

// The functions of _global (exe 0x143a51180).
const NameFunction GlobalStaticFunctions[] =
{
    { "trace",                    FUN_1428f6de0 },
    { "parseInt",                 FUN_1428f70b0 },
    { "parseFloat",               FUN_1428f73b0 },
    { "ifFrameLoaded",            FUN_1428f74a0 },
    { "isNaN",                    FUN_1428f7580 },
    { "isFinite",                 FUN_1428f7650 },
    { "escape",                   FUN_1428f7ed0 },
    { "unescape",                 FUN_1428f8020 },
    { "escapeSpecialHTML",        FUN_1428f8170 },
    { "unescapeSpecialHTML",      FUN_1428f83d0 },
    { "updateAfterEvent",         FUN_1428f8530 },
    { "setInterval",              FUN_1428fbb70 },
    { "clearInterval",            FUN_1428fbb80 },
    { "setTimeout",               FUN_1428fbc40 },
    { "clearTimeout",             FUN_1428fbc50 },
    { "imecommand",               FUN_1428f8540 },
    { "setIMECandidateListStyle", FUN_1428f9f50 },
    { "getInputLanguage",         FUN_1428fafd0 },
    { "getIMECandidateListStyle", FUN_1428fa7a0 },
    { "ASSetPropFlags",          FUN_1428f7740 },
    { "ASnative",                 FUN_1428f7d30 },
    { 0, 0 }
};

// The prototype goes to the context's prototype table under the type.
SF_FORCEINLINE void AddBuiltinPrototype(GlobalContext* pgc, ASBuiltinType type, Object* proto)
{
    Ptr<Object>   pproto  = proto;
    ASBuiltinType key     = type;
    void*         pair[2] = { &key, &pproto };
    ::FUN_14000b9e0(reinterpret_cast<UPInt*>(&pgc->Prototypes), &pgc->Prototypes, pair,
                    FixedSizeHash<ASBuiltinType>()(key));
}

// A builtin class created on first use: its registration function under the type's name, and the name published
// in pdest as a function name value until then.
SF_FORCEINLINE void AddBuiltinClassRegistry(GlobalContext* pgc, ASStringContext* psc, Object* pdest,
                                            ASBuiltinType type, GlobalContext::ClassRegEntry::RegisterFunc func)
{
    const ASString& name = psc->GetBuiltin(type);
    if (FUN_140001bd0(&pgc->BuiltinClassesRegistry, name))
        return;
    {
        GlobalContext::ClassRegEntry entry;
        entry.Register = func;
        pgc->BuiltinClassesRegistry.Add(name, entry);
    }

    Value fname;
    fname.T.Type        = Value::FUNCTIONNAME;
    fname.V.pStringNode = psc->GetBuiltin(type).GetNode();
    fname.V.pStringNode->AddRef();
    pdest->SetMemberRaw(psc, name, fname);
}

// Marks every member it is shown DontEnum.
struct HideMembersVisitor : public ObjectInterface::MemberVisitor
{
    Ptr<Object>      pObj;
    ASStringContext* pSC;

    HideMembersVisitor(Object* pobj, ASStringContext* psc) : pObj(pobj), pSC(psc) {}

    virtual void Visit(const ASString& name, const Value&, UByte flags)
    {
        pObj->SetMemberFlags(pSC, name, UByte(flags | PropFlags::PropFlag_DontEnum));
    }
};

} // namespace

// MS2-FUNCTIONAL: the exe inlines the Object, Function, MovieClip and Key constructors and prototypes, the C function
// values and InitStandardMembers.
// @0x14295e2b0
void GlobalContext::Init(MovieImpl* proot)
{
    pMovieRoot = proot;
    pHeap      = proot->GetMovieHeap();

    ASStringContext sc(this, 8);

    if (!pGlobal)
        pGlobal = *SF_HEAP_NEW(pHeap) GASGlobalObject(this);

    // Object and Function first: each constructor's __proto__ is Function.prototype.
    FunctionRef objCtor(*SF_HEAP_NEW(pHeap) ObjectCtorFunction(&sc));
    FunctionRef functionCtor(*SF_HEAP_NEW(pHeap) FunctionCtorFunction(&sc));
    Ptr<Object> objProto      = *SF_HEAP_NEW(pHeap) ObjectProto(&sc, objCtor);
    Ptr<Object> functionProto = *SF_HEAP_NEW(pHeap) FunctionProto(&sc, objProto, functionCtor, true);
    objCtor->Set__proto__(&sc, functionProto);
    functionCtor->Set__proto__(&sc, functionProto);
    AddBuiltinPrototype(this, ASBuiltin_Object, objProto);
    AddBuiltinPrototype(this, ASBuiltin_Function, functionProto);

    FunctionRef movieClipCtor(*SF_HEAP_NEW(pHeap) MovieClipCtorFunction(&sc));
    FunctionRef keyCtor(*SF_HEAP_NEW(pHeap) KeyCtorFunction(&sc, proot));
    Ptr<Object> keyProto = *SF_HEAP_NEW(pHeap) KeyProto(&sc, objProto, keyCtor);
    AddBuiltinPrototype(this, ASBuiltin_Key, keyProto);

    Ptr<Object> movieClipProto = *SF_HEAP_NEW(pHeap) MovieClipProto(&sc, objProto, movieClipCtor);
    AddBuiltinPrototype(this, ASBuiltin_MovieClip, movieClipProto);

    NameFunction::AddConstMembers(pGlobal, &sc, GlobalStaticFunctions);

    pGlobal->SetConstMemberRaw(&sc, "imecommand", Value(&sc, FUN_1428f8540));
    pGlobal->SetConstMemberRaw(&sc, "setIMECandidateListStyle", Value(&sc, FUN_1428f9f50));
    pGlobal->SetConstMemberRaw(&sc, "getInputLanguage", Value(&sc, FUN_1428fafd0));
    pGlobal->SetConstMemberRaw(&sc, "getIMECandidateListStyle", Value(&sc, FUN_1428fa7a0));

    pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Object), Value(objCtor));
    pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Function), Value(functionCtor));
    pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_MovieClip), Value(movieClipCtor));
    pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Key), Value(keyCtor));

    // The rest is made when a movie first names it.
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Math, MathCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Array, ArrayCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Number, NumberCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_String, StringCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Boolean, BooleanCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Color, ColorCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Button, ButtonCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_MovieClipLoader, MovieClipLoaderCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_LoadVars, GASLoadVarsLoaderCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Stage, StageCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Selection, SelectionCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_AsBroadcaster, AsBroadcasterCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Mouse, MouseCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_TextField, TextFieldCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_TextFormat, TextFormatCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_TextSnapshot, TextSnapshotCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Date, DateCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_SharedObject, SharedObjectCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, pGlobal, ASBuiltin_Amp, AmpMarkerCtorFunction::Register);

    FlashGeomPackage = AddPackage(&sc, pGlobal, objProto, "flash.geom");
    AddBuiltinClassRegistry(this, &sc, FlashGeomPackage, ASBuiltin_Transform, TransformCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashGeomPackage, ASBuiltin_Matrix, GASMatrixCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashGeomPackage, ASBuiltin_Point, PointCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashGeomPackage, ASBuiltin_Rectangle, RectangleCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashGeomPackage, ASBuiltin_ColorTransform,
                            ColorTransformCtorFunction::Register);

    SystemPackage = AddPackage(&sc, pGlobal, objProto, "System");
    AddBuiltinClassRegistry(this, &sc, SystemPackage, ASBuiltin_Capabilities, CapabilitiesCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, SystemPackage, ASBuiltin_Ime, GASImeCtorFunction::Register);

    FlashExternalPackage = AddPackage(&sc, pGlobal, objProto, "flash.external");
    AddBuiltinClassRegistry(this, &sc, FlashExternalPackage, ASBuiltin_ExternalInterface,
                            ExternalInterfaceCtorFunction::Register);

    FlashDisplayPackage = AddPackage(&sc, pGlobal, objProto, "flash.display");
    AddBuiltinClassRegistry(this, &sc, FlashDisplayPackage, ASBuiltin_BitmapData, BitmapDataCtorFunction::Register);

    FlashFiltersPackage = AddPackage(&sc, pGlobal, objProto, "flash.filters");
    AddBuiltinClassRegistry(this, &sc, FlashFiltersPackage, ASBuiltin_BitmapFilter,
                            BitmapFilterCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashFiltersPackage, ASBuiltin_DropShadowFilter,
                            DropShadowFilterCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashFiltersPackage, ASBuiltin_GlowFilter, GlowFilterCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashFiltersPackage, ASBuiltin_BlurFilter, BlurFilterCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashFiltersPackage, ASBuiltin_BevelFilter,
                            BevelFilterCtorFunction::Register);
    AddBuiltinClassRegistry(this, &sc, FlashFiltersPackage, ASBuiltin_ColorMatrixFilter,
                            ColorMatrixFilterCtorFunction::Register);

    InitStandardMembers();

    // Nothing set up so far shows in a for..in over _global.
    HideMembersVisitor visitor(pGlobal, &sc);
    pGlobal->VisitMembers(&sc, &visitor, ObjectInterface::VisitMember_DontEnum);
}

}}} // namespace Scaleform::GFx::AS2
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7MovieClipCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216920
// MS2-PIN: ??_7MovieClipCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432169a8
