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
#include "../include/render/text_styledtext.h"

// The context's prototype table store: takes over the reference in *value (exe 0x14000c280).
void FUN_14000c280(void* owner, unsigned key, void** value);

namespace Scaleform { namespace GFx { namespace AS2 {

// The folded ASStringHash<ClassRegEntry>::Get (exe 0x140001bd0).
}}} // namespace Scaleform::GFx::AS2
// ASStringHash<GlobalContext::ClassRegEntry>::Get, defined with plain pointer parameters in sfr_video_04.
void* FUN_140001bd0(void* phash, void* pkey);

namespace Scaleform { namespace GFx { namespace Text {

// Text::StyleManager as far as the StyleSheet prototype builds one (as in sfr_as2_03d): the destructor and the
// lookups are sfr_gfx_06g's (vftable 0x14316a738).
class StyleManager : public Render::Text::StyleManagerBase
{
public:
    StyleManager() : Styles(0), TempType(CSS_None), State(0) {}
    ~StyleManager();

    virtual const Render::Text::Style* GetStyle(KeyType type, const String& name) const;
    virtual const Render::Text::Style* GetStyle(KeyType type, const char* name, UPInt len = SF_MAX_UPINT) const;
    virtual const Render::Text::Style* GetStyle(KeyType type, const wchar_t* name, UPInt len = SF_MAX_UPINT) const;

private:
    void*    Styles;   // +8 StyleHash
    KeyType  TempType; // +0x10 StyleKey TempKey
    StringLH TempName; // +0x18
    UPInt    TempHash; // +0x20
    int      State;    // +0x28
};

}}} // namespace Scaleform::GFx::Text
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
    static const FunctionRef& Get(GASPrototypeBase& proto)
    {
        return static_cast<PrototypeConstructorOf&>(proto).Constructor;
    }
};

struct SetLocalFrameInlineTag {};

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it in the copy below.
SF_FORCEINLINE void FunctionRefSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (weakRef)
        p->Flags |= FunctionRefBase::FuncRef_Weak;
    else
        p->Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->AddRef();
}

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

// FunctionRefBase::Init(orig) with the SetLocalFrame call expanded (TextField's constructor copied in
// StyleSheetCtorFunction::Register).
template<class Tag>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, Tag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        FunctionRefSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

// FunctionObject(psc) with Object(psc) inlined.
__forceinline FunctionObject::FunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
}
// CFunctionObject(psc, func) (0x142919df0) inlined, with its Set__proto__ (a virtual __proto__ store).
__forceinline CFunctionObject::CFunctionObject(ASStringContext* psc, CFunctionPtr func, ObjectInlineCtorTag)
    : FunctionObject(psc, ObjectInlineCtorTag()), pFunction(func)
{
    Object* pprototype = psc->pContext->GetPrototype(ASBuiltin_Function);
    if (!pProto)
        static_cast<ObjectInterface*>(this)->SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}
__forceinline StyleSheetCtorFunction::StyleSheetCtorFunction(ASStringContext* psc, ObjectInlineCtorTag)
    : CFunctionObject(psc, GlobalCtor, ObjectInlineCtorTag())
{
}
// StyleSheetObject(psc, pprototype) with Object(psc) inlined.
__forceinline StyleSheetObject::StyleSheetObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    ::new (CSS.Data) Text::StyleManager();
    if (!pProto)
        static_cast<ObjectInterface*>(this)->SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}
__forceinline StyleSheetProto::StyleSheetProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor,
                                               ObjectInlineCtorTag)
    : Prototype<StyleSheetObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// The exe inlines the StyleSheetCtorFunction and StyleSheetProto ctors down to Object(psc).
// MS2-FUNCTIONAL: register allocation floor (1317 vs 1307 bytes): the exe keeps zero in rdi and the
// ObjectInterface vptr in rdx across the inlined CtorFunction Object(psc), so its byte/word zero stores
// use dil/di; same instructions and order otherwise.
// @0x14297b190
FunctionRef StyleSheetCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) StyleSheetCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap)
        StyleSheetProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, ASBuiltin_StyleSheet, proto);
    // A member of the TextField class.
    FunctionRef textFieldCtor(
        PrototypeConstructorOf::Get(*static_cast<TextFieldProto*>(pgc->GetPrototype(ASBuiltin_TextField))),
        SetLocalFrameInlineTag());
    textFieldCtor->SetMemberRaw(
        &sc, ((MovieRoot*)pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin_StyleSheet),
        Value(ctor));
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

__forceinline TextFormatCtorFunction::TextFormatCtorFunction(ASStringContext* psc, ObjectInlineCtorTag)
    : CFunctionObject(psc, GlobalCtor, ObjectInlineCtorTag())
{
}
// TextFormatObject(psc, pprototype) (sfr_as2_03b) with Object(psc) inlined.
__forceinline TextFormatObject::TextFormatObject(ASStringContext* psc, Object* pprototype, ObjectInlineCtorTag)
    : Object(psc, ObjectInlineCtorTag())
{
    ::new (mTextFormat.Data) Render::Text::TextFormat(psc->GetHeap());
    ::new (mParagraphFormat.Data) Render::Text::ParagraphFormat();
    if (!pProto)
        static_cast<ObjectInterface*>(this)->SetMemberRaw(
            psc, ((MovieRoot*)psc->pContext->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin___proto__),
            Value(Value::UNSET), PropFlags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete));
    pProto = pprototype;
}
__forceinline TextFormatProto::TextFormatProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor,
                                               ObjectInlineCtorTag)
    : Prototype<TextFormatObject>(psc, pprototype, constructor, ObjectInlineCtorTag())
{
    InitFunctionMembers(this, psc, FunctionTable, PropFlags(PropFlags::PropFlag_DontEnum));
}

// The exe inlines the TextFormatCtorFunction and TextFormatProto ctors down to Object(psc).
// MS2-FUNCTIONAL: register allocation floor (1295 vs 1285 bytes), the same one as StyleSheet's Register:
// in the inlined CtorFunction Object(psc) the exe keeps zero in rdi and both vptrs in rdx/r8 across the
// GcN chain; same instructions and order otherwise.
// @0x14297ba70
FunctionRef TextFormatCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) TextFormatCtorFunction(&sc, ObjectInlineCtorTag()));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap)
        TextFormatProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor, ObjectInlineCtorTag());
    SetBuiltinPrototype(pgc, ASBuiltin_TextFormat, proto);
    pgc->pGlobal->SetMemberRaw(&sc, ((MovieRoot*)pgc->pMovieRoot->pASMovieRoot)->GetStringManager()->GetBuiltin(ASBuiltin_TextFormat),
                               Value(ctor));
    return ctor;
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
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x1432174e8
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432173f8
// MS2-PIN: ??_7?$Prototype@VStyleSheetObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217440
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B@ 0x14321d868
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d778
// MS2-PIN: ??_7?$Prototype@VTextFormatObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d7c0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7StyleManagerBase@Text@Render@Scaleform@@6B@ 0x14316a718
// MS2-PIN: ??_7StyleManager@Text@GFx@Scaleform@@6B@ 0x14316a738
// MS2-PIN: ??_7StyleSheetCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432175e8
// MS2-PIN: ??_7StyleSheetCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217670
// MS2-PIN: ??_7StyleSheetObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143217308
// MS2-PIN: ??_7StyleSheetObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217350
// MS2-PIN: ??_7StyleSheetProto@AS2@GFx@Scaleform@@6B@ 0x1432175e0
// MS2-PIN: ??_7StyleSheetProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432174f0
// MS2-PIN: ??_7StyleSheetProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217538
// MS2-PIN: ??_7TextFormatCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d968
// MS2-PIN: ??_7TextFormatCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d9f0
// MS2-PIN: ??_7TextFormatObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d688
// MS2-PIN: ??_7TextFormatObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d6d0
// MS2-PIN: ??_7TextFormatProto@AS2@GFx@Scaleform@@6B@ 0x14321d960
// MS2-PIN: ??_7TextFormatProto@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321d870
// MS2-PIN: ??_7TextFormatProto@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321d8b8
