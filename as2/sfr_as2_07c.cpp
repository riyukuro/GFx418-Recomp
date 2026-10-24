// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 System.IME (gap recovery of
// sfr_as2_07): the class functions over the movie's IME manager, the listener broadcasts, the object, its prototype
// and the class object.
// MS2-UNIT: sfr_as2_07c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142998ee0-0x14299b650 .text$mn

// The exe calls Value::~Value out of line throughout this file.
#define MS2_AS2_VALUE_DTOR_CALL
#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_ime.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/gfx_imemanager.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieimplstates.h"

void FUN_14000c280(void* owner, unsigned key, void** value);
namespace Scaleform { namespace GFx { namespace AS2 { class FnCall; class Value; }}}
Scaleform::GFx::AS2::Value* FUN_1429316c0(const Scaleform::GFx::AS2::FnCall* pfn, int n);

namespace Scaleform { namespace GFx { namespace AS2 {

namespace {

// fn.Arg(n) through the exe's out-of-line FnCall::Arg (sfr_as2_04e): the exe calls it without seeing its body.
SF_FORCEINLINE Value& ImeArg(const FnCall& fn, int n)
{
    return *::FUN_1429316c0(&fn, n);
}

static SF_FORCEINLINE void SetBuiltinPrototype(GlobalContext* pgc, ASBuiltinType type, Object* proto)
{
    ::FUN_14000c280(pgc, type, reinterpret_cast<void**>(&proto));
}

// Calls System.IME.<event> on the listeners: with HasString the one argument is *pstr, null when it is empty.
template<bool HasString>
SF_FORCEINLINE void BroadcastToIme(Environment* penv, const char* pevent, const ASString* pstr)
{
    ASStringContext* psc = penv->GetSC();
    Value            imeCtorVal, systemPackage;
    ASString         systemStr = psc->pContext->GetStringManager()->CreateConstString("System");
    if (psc->pContext->pGlobal->GetMemberRaw(psc, systemStr, &systemPackage))
    {
        Object* psystem = systemPackage.ToObject(penv);
        if (psystem->GetMemberRaw(psc, psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin_Ime), &imeCtorVal))
        {
            Object* pimeObj = imeCtorVal.ToObject(penv);
            if (pimeObj)
            {
                ObjectInterface* pime = pimeObj;
                if (pime)
                {
                    if (HasString)
                    {
                        if (pstr->GetSize() != 0)
                            penv->Push(Value(*pstr));
                        else
                            penv->Push(Value::NULLTYPE);
                    }
                    AsBroadcaster::BroadcastMessage(penv, pime,
                                                    psc->pContext->GetStringManager()->CreateConstString(pevent),
                                                    HasString ? 1 : 0, penv->GetTopIndex());
                    if (HasString)
                        penv->Drop(1);
                }
            }
        }
    }
}

// The prototype methods: none of them does anything.
// @0x142998ee0
static void GFx_FuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

} // namespace

// @0x142998f00
void GASImeCtorFunction::DoConversion(const FnCall&)
{
}

// "UNKNOWN" without an IME manager.
// @0x142998f10
void GASImeCtorFunction::GetConversionMode(const FnCall& fn)
{
    if (!fn.Env)
        return;
    Ptr<IMEManagerBase> pime   = fn.Env->GetMovieImpl()->GetIMEManager();
    ASString            result = fn.Env->GetSC()->pContext->GetStringManager()->CreateConstString("UNKNOWN");
    if (pime)
        result = pime->GetConversionMode();
    fn.Result->SetString(result);
}

// @0x142998fe0
void GASImeCtorFunction::GetEnabled(const FnCall& fn)
{
    if (!fn.Env)
        return;
    Ptr<IMEManagerBase> pime = fn.Env->GetMovieImpl()->GetIMEManager();
    if (pime)
        fn.Result->SetBool(pime->GetEnabled());
}

// MS2-FUNCTIONAL: register allocation (the exe reloads the ASString node from the stack)
// @0x142999050
void GASImeCtorFunction::SetCompositionString(const FnCall& fn)
{
    if (!fn.Env)
        return;
    Ptr<IMEManagerBase> pime   = fn.Env->GetMovieImpl()->GetIMEManager();
    bool                result = false;
    if (pime)
    {
        Environment* penv = fn.Env;
        ASString     str  = ImeArg(fn, 0).ToString(penv);
        result            = pime->SetCompositionString(str.ToCStr());
    }
    fn.Result->SetBool(result);
}

// @0x142999120
void GASImeCtorFunction::SetConversionMode(const FnCall& fn)
{
    if (!fn.Env)
        return;
    Ptr<IMEManagerBase> pime   = fn.Env->GetMovieImpl()->GetIMEManager();
    bool                result = false;
    if (pime)
        result = pime->SetConversionMode((UInt32)ImeArg(fn, 0).ToNumber(fn.Env));
    fn.Result->SetBool(result);
}

// @0x1429991d0
void GASImeCtorFunction::SetEnabled(const FnCall& fn)
{
    if (!fn.Env)
        return;
    Ptr<IMEManagerBase> pime   = fn.Env->GetMovieImpl()->GetIMEManager();
    bool                result = false;
    if (pime)
        result = pime->SetEnabled(ImeArg(fn, 0).ToBool(fn.Env));
    fn.Result->SetBool(result);
}

// SendLangBarMessage(clip, command, message).
// MS2-FUNCTIONAL: the exe reloads fn.Env after each FnCall::Arg call; same calls
// @0x142999270
void GASImeCtorFunction::SendLangBarMessage(const FnCall& fn)
{
    if (!fn.Env)
        return;
    Ptr<IMEManagerBase> pime = fn.Env->GetMovieImpl()->GetIMEManager();
    if (pime && fn.NArgs == 3 && ImeArg(fn, 0).GetType() == Value::CHARACTER)
    {
        Environment*       penv    = fn.Env;
        InteractiveObject* pclip   = ImeArg(fn, 0).ToCharacter(penv);
        ASString           command = ImeArg(fn, 1).ToString(penv);
        ASString           message = ImeArg(fn, 2).ToString(penv);
        pime->SendLangBarMessage(pclip, command, message);
    }
    fn.Result->SetUndefined();
}

// The collector traversal of System.IME.prototype.
template void Prototype<GASIme>::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector* prcc) const;
template void Prototype<GASIme>::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector* prcc) const;
template void Prototype<GASIme>::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector* prcc) const;

// @0x142999670
GASIme::GASIme(Environment* penv) : Object(penv)
{
    commonInit(penv);
}

// @0x1429996e0
GASImeCtorFunction::GASImeCtorFunction(ASStringContext* psc) : CFunctionObject(psc, ObjectProto::GlobalCtor)
{
    AsBroadcaster::Initialize(psc, this);
    NameFunction::AddConstMembers(this, psc, StaticFunctionTable,
                                  PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete |
                                      PropFlags::PropFlag_DontEnum);
    for (int i = 0; GASNumberConstTable[i].Name; i++)
    {
        static_cast<ObjectInterface*>(this)->SetMemberRaw(
            psc, psc->pContext->GetStringManager()->CreateConstString(GASNumberConstTable[i].Name),
            Value(GASNumberConstTable[i].Number),
            PropFlags(PropFlags::PropFlag_ReadOnly | PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum));
    }
}

// MS2-FUNCTIONAL: the exe inlines Object::Set__proto__ (a virtual SetMemberRaw); same members
// @0x142999830
GASImeProto::GASImeProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor)
    : Prototype<GASIme>(psc, pprototype, constructor)
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142999be0
void GASIme::BroadcastOnDisplayStatusWindow(Environment* penv)
{
    BroadcastToIme<false>(penv, "onDisplayStatusWindow", 0);
}

// @0x142999d80
void GASIme::BroadcastOnIMEComposition(Environment* penv, const ASString& pString)
{
    BroadcastToIme<true>(penv, "onIMEComposition", &pString);
}

// @0x142999fd0
void GASIme::BroadcastOnRemoveStatusWindow(Environment* penv)
{
    BroadcastToIme<false>(penv, "onRemoveStatusWindow", 0);
}

// @0x14299a170
void GASIme::BroadcastOnSetConversionMode(Environment* penv, const ASString& pString)
{
    BroadcastToIme<true>(penv, "onSetConversionStatus", &pString);
}

// @0x14299a3c0
void GASIme::BroadcastOnSetCurrentInputLang(Environment* penv, const ASString& pString)
{
    BroadcastToIme<true>(penv, "onSetCurrentInputLanguage", &pString);
}

// @0x14299a610
void GASIme::BroadcastOnSetIMEName(Environment* penv, const ASString& pString)
{
    BroadcastToIme<true>(penv, "onSetIMEName", &pString);
}

// @0x14299a860
void GASIme::BroadcastOnSetSupportedIMEs(Environment* penv, const ASString& pString)
{
    BroadcastToIme<true>(penv, "onSetSupportedIMEs", &pString);
}

// @0x14299aab0
void GASIme::BroadcastOnSetSupportedLanguages(Environment* penv, const ASString& pString)
{
    BroadcastToIme<true>(penv, "onSetSupportedLanguages", &pString);
}

// @0x14299ad00
void GASIme::BroadcastOnSwitchLanguage(Environment* penv, const ASString& pString)
{
    BroadcastToIme<true>(penv, "onSwitchLanguage", &pString);
}

// @0x14299afa0
template void Prototype<GASIme>::Finalize_GC();

// "constructor" and "__constructor__" are answered by the prototype part.
// @0x14299b000
template<>
bool Prototype<GASIme>::GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val)
{
    // The builtins come through GlobalContext::GetStringManager here (not inlined into this file).
    bool isConstructor2 = psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin___constructor__)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive());
    if (isConstructor2 || psc->pContext->GetStringManager()->GetBuiltin(ASBuiltin_constructor)
                              .CompareBuiltIn_CaseCheck(name, psc->IsCaseSensitive()))
    {
        return GetMemberRawConstructor(this, psc, name, val, isConstructor2);
    }
    return GASIme::GetMemberRaw(psc, name, val);
}

// @0x14299b120
void GASImeProto::GlobalCtor(const FnCall& fn)
{
    Ptr<GASIme> pime = *SF_NEW GASIme(fn.Env);
    fn.Result->SetAsObject(pime.GetPtr());
}

// MS2-FUNCTIONAL: the exe inlines the GASImeCtorFunction and GASImeProto ctors and the prototype store
// @0x14299b200
FunctionRef GASImeCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) GASImeCtorFunction(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) GASImeProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Ime, proto);
    pgc->SystemPackage->SetMemberRaw(&sc, pgc->GetStringManager()->GetBuiltin(ASBuiltin_Ime), Value(ctor));
    return ctor;
}

// @0x14299b610
void GASIme::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Ime));
}

const NameFunction GASImeProto::FunctionTable[] = {
    { "addListener", &GFx_FuncStub },
    { "doConversion", &GFx_FuncStub },
    { "getConversionMode", &GFx_FuncStub },
    { "getEnabled", &GFx_FuncStub },
    { "setCompositionString", &GFx_FuncStub },
    { "setConversionMode", &GFx_FuncStub },
    { "setEnabled", &GFx_FuncStub },
    { "removeListener", &GFx_FuncStub },
    { 0, 0 }
};

const NameFunction GASImeCtorFunction::StaticFunctionTable[] = {
    { "doConversion", &GASImeCtorFunction::DoConversion },
    { "getConversionMode", &GASImeCtorFunction::GetConversionMode },
    { "getEnabled", &GASImeCtorFunction::GetEnabled },
    { "setCompositionString", &GASImeCtorFunction::SetCompositionString },
    { "setConversionMode", &GASImeCtorFunction::SetConversionMode },
    { "setEnabled", &GASImeCtorFunction::SetEnabled },
    { "SendLangBarMessage", &GASImeCtorFunction::SendLangBarMessage },
    { 0, 0 }
};

const NameNumber GASImeCtorFunction::GASNumberConstTable[] = {
    { "ALPHANUMERIC_FULL", 0 },
    { "ALPHANUMERIC_HALF", 1 },
    { "CHINESE", 2 },
    { "JAPANESE_HIRAGANA", 4 },
    { "JAPANESE_KATAKANA_FULL", 8 },
    { "JAPANESE_KATAKANA_HALF", 16 },
    { "KOREAN", 32 },
    { "UNKNOWN", 64 },
    { 0, 0 }
};

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??$ForEachChild_GC@UMarkInCycleFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VGASIme@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x1429993b0
// MS2-PIN: ??$ForEachChild_GC@UReleaseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VGASIme@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x142999470
// MS2-PIN: ??$ForEachChild_GC@UScanInUseFunctor@?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@@?$Prototype@VGASIme@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@IEBAXPEAV?$RefCountCollector@$0BED@@123@@Z 0x142999580
// MS2-PIN: ??_G?$Prototype@VGASIme@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x1429999f0
// MS2-PIN: ??_GGASIme@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x142999a80
// MS2-PIN: ??_GGASImeCtorFunction@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x142999ae0
// MS2-PIN: ??_GGASImeProto@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x142999b40
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7GASIme@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143223340
// MS2-PIN: ??_7GASIme@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223388
// MS2-PIN: ??_7?$Prototype@VGASIme@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143223430
// MS2-PIN: ??_7?$Prototype@VGASIme@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223478
// MS2-PIN: ??_7?$Prototype@VGASIme@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143223520
// MS2-PIN: ??_7GASImeProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143223528
// MS2-PIN: ??_7GASImeProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143223570
// MS2-PIN: ??_7GASImeProto@AS2@GFx@Scaleform@@6B@ 0x143223618
// MS2-PIN: ??_7GASImeCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143223620
// MS2-PIN: ??_7GASImeCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432236a8
