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
GlobalContext::ClassRegEntry* FUN_140001bd0(ASStringHash<GlobalContext::ClassRegEntry>* phash, const ASString& key);

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

} // namespace

// MS2-FUNCTIONAL: the exe inlines the ObjectProto ctor
// @0x142975c20
FunctionRef CapabilitiesCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<CapabilitiesCtorFunction, ObjectProto>(pgc, ASBuiltin_Capabilities, ASBuiltin_Object,
                                                                       pgc->SystemPackage);
}

// MS2-FUNCTIONAL: the exe inlines the StageProto ctor
// @0x14297a960
FunctionRef StageCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) StageCtorFunction(&sc, pgc->pMovieRoot));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) StageProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Stage, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Stage), Value(ctor));
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
