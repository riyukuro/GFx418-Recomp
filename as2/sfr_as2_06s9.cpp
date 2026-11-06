// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 builtin-class registration of
// sfr_as2_06 (gap recovery, lane sfr24): System.capabilities, Stage, TextField (with TextField.StyleSheet registered
// for first use), TextField.StyleSheet and TextFormat.
// MS2-UNIT: sfr_as2_06s9
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142975c20-0x142975f25 .text$mn
// MS2-RANGE: 0x14297a960-0x14297ac97 .text$mn
// MS2-RANGE: 0x14297b190-0x14297bf75 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"

// The context's prototype table store: takes over the reference in *value (exe 0x14000c280).
void FUN_14000c280(void* owner, unsigned key, void** value);

namespace Scaleform { namespace GFx { namespace AS2 {

// The folded ASStringHash<ClassRegEntry>::Get (exe 0x140001bd0).
}}} // namespace Scaleform::GFx::AS2
// ASStringHash<GlobalContext::ClassRegEntry>::Get, defined with plain pointer parameters in sfr_video_04.
void* FUN_140001bd0(void* phash, void* pkey);
namespace Scaleform { namespace GFx { namespace AS2 {

// System.capabilities (defined in sfr_as2_03h): only its constructor is called here.
class CapabilitiesCtorFunction : public CFunctionObject
{
public:
    CapabilitiesCtorFunction(ASStringContext* psc); // exe 0x142919ee0

    static FunctionRef Register(GlobalContext* pgc);
};

namespace {

// The constructor a builtin prototype links to.
struct PrototypeConstructorOf : public GASPrototypeBase
{
    static const FunctionRef& Get(GASPrototypeBase* pproto)
    {
        return static_cast<PrototypeConstructorOf*>(pproto)->Constructor;
    }
};

// The prototype goes to the context's prototype table, which takes over the passed reference.
SF_FORCEINLINE void SetBuiltinPrototype(GlobalContext* pgc, ASBuiltinType type, Object* proto)
{
    ::FUN_14000c280(pgc, type, reinterpret_cast<void**>(&proto));
}

// The constructor, its ProtoType prototype on the parent type's prototype, the constructor published under the
// type's name in ptarget.
template<class CtorFunctionType, class ProtoType>
SF_FORCEINLINE FunctionRef RegisterBuiltinClass(GlobalContext* pgc, ASBuiltinType type, ASBuiltinType parentType,
                                                ObjectInterface* ptarget)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) CtorFunctionType(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) ProtoType(&sc, pgc->GetPrototype(parentType), ctor);
    SetBuiltinPrototype(pgc, type, proto);
    ptarget->SetMemberRaw(&sc, sc.GetBuiltin(type), Value(ctor));
    return ctor;
}

// A builtin class created on first use: its registration function under the type's name, and the name published
// in pdest as a function name value until then.
SF_FORCEINLINE void AddBuiltinClassRegistry(GlobalContext* pgc, ASStringContext* psc, Object* pdest,
                                            ASBuiltinType type, GlobalContext::ClassRegEntry::RegisterFunc func)
{
    const ASString& name = psc->GetBuiltin(type);
    if (::FUN_140001bd0(&pgc->BuiltinClassesRegistry, (void*)&name))
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

} // namespace

// ASStringContext::GetGC through GlobalContext::GetGC, both inlined: the movie's collector, 0 without one.
static __forceinline ASRefCountCollector* GcG(GlobalContext* p)
{
    return p->pMovieRoot ? ((MovieRoot*)p->pMovieRoot->pASMovieRoot)->GetASGC() : 0;
}
static __forceinline ASRefCountCollector* GcN(ASStringContext* psc)
{
    return psc->pContext ? GcG(psc->pContext) : 0;
}
// The exe inlines the ObjectProto ctor in Register, down to the Object base and its Set__proto__.
__forceinline Object::Object(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : ASRefCountBase<Object>(GcN(psc)), pWatchpoints(0), ArePropertiesSet(false), IsListenerSet(false)
{
    // Object::Set__proto__ (0x140007ba0), inlined.
    if (!pProto)
        static_cast<ObjectInterface*>(this)->SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}
// Object::Object(ASStringContext*) (0x14291f6f0), inlined.
__forceinline Object::Object(ASStringContext* psc, ObjectInlineCtorTag)
    : ASRefCountBase<Object>(GcN(psc)), pWatchpoints(0), ArePropertiesSet(false), IsListenerSet(false)
{
    pProto = 0;
}
// StageObject(psc, pprototype) with Object(psc) and Set__proto__ inlined; the exe calls Object::SetMemberRaw directly here.
__forceinline StageObject::StageObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    if (!pProto)
        Object::SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}

__forceinline ObjectProto::ObjectProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor,
                                       ObjectInlineCtorTag)
    : Prototype<Object>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// @0x142975c20
FunctionRef CapabilitiesCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) CapabilitiesCtorFunction(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap)
        ObjectProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, ASBuiltin_Capabilities, proto);
    pgc->SystemPackage->SetMemberRaw(
        &sc, ((MovieRoot*)pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin_Capabilities),
        Value(ctor));
    return ctor;
}

__forceinline StageProto::StageProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor, ObjectInlineCtorTag)
    : Prototype<StageObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{ InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum)); }

// The exe inlines the StageProto ctor down to Object(psc).
// @0x14297a960
FunctionRef StageCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) StageCtorFunction(&sc, pgc->pMovieRoot));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) StageProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, ASBuiltin_Stage, proto);
    pgc->pGlobal->SetMemberRaw(&sc, ((MovieRoot*)pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin_Stage), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL: the exe inlines the StyleSheetCtorFunction and StyleSheetProto ctors
// @0x14297b190
FunctionRef StyleSheetCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) StyleSheetCtorFunction(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) StyleSheetProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_StyleSheet, proto);
    // A member of the TextField class.
    FunctionRef textFieldCtor = PrototypeConstructorOf::Get(
        static_cast<TextFieldProto*>(pgc->GetPrototype(ASBuiltin_TextField)));
    textFieldCtor->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_StyleSheet), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL: the exe inlines the TextFieldCtorFunction ctor
// @0x14297b6b0
FunctionRef TextFieldCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) TextFieldCtorFunction(&sc));
    Ptr<Object>     proto = *SF_HEAP_NEW(pgc->pHeap) TextFieldProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_TextField, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_TextField), Value(ctor));
    AddBuiltinClassRegistry(pgc, &sc, ctor.GetObjectPtr(), ASBuiltin_StyleSheet, StyleSheetCtorFunction::Register);
    return ctor;
}

// MS2-FUNCTIONAL: the exe inlines the TextFormatCtorFunction and TextFormatProto ctors
// @0x14297ba70
FunctionRef TextFormatCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<TextFormatCtorFunction, TextFormatProto>(pgc, ASBuiltin_TextFormat, ASBuiltin_Object,
                                                                         pgc->pGlobal);
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@6B@ 0x143215370
// MS2-PIN: ??_7ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215410
// MS2-PIN: ??_7?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@AS2@GFx@Scaleform@@6B@ 0x1432154b8
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432154d0
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215518
// MS2-PIN: ??_7GASPrototypeBase@AS2@GFx@Scaleform@@6B@ 0x1431b5028
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143215f60
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215fa8
// MS2-PIN: ??_7?$Prototype@VObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x143216050
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216058
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432160a0
// MS2-PIN: ??_7ObjectProto@AS2@GFx@Scaleform@@6B@ 0x143216148
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321a6f0
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a600
// MS2-PIN: ??_7?$Prototype@VStageObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a648
// MS2-PIN: ??_7StageObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a510
// MS2-PIN: ??_7StageObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a558
// MS2-PIN: ??_7StageProto@AS2@GFx@Scaleform@@6B@ 0x14321a7e8
// MS2-PIN: ??_7StageProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a6f8
// MS2-PIN: ??_7StageProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a740
