// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 constructors, destructors and
// assignments of the script values, objects and prototypes (the out-of-line copies the unity build emitted).
// MS2-UNIT: sfr_as2_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142923cb0-0x142923dd0 .text$mn
// MS2-RANGE: 0x1429237f0-0x142923a90 .text$mn
// MS2-RANGE: 0x1429267a0-0x142926a00 .text$mn
// MS2-RANGE: 0x142923e70-0x142923f30 .text$mn
// MS2-RANGE: 0x142923fd0-0x142924040 .text$mn
// MS2-RANGE: 0x1429181f0-0x142918270 .text$mn
// MS2-RANGE: 0x142925350-0x1429253d0 .text$mn
// MS2-RANGE: 0x1429241f0-0x142924490 .text$mn
// MS2-RANGE: 0x142924520-0x142924d20 .text$mn
// MS2-RANGE: 0x142925ae0-0x142925be0 .text$mn
// MS2-RANGE: 0x142926100-0x142926190 .text$mn
// MS2-RANGE: 0x14291f670-0x14291f8d0 .text$mn
// MS2-RANGE: 0x142919d70-0x142919da0 .text$mn
// MS2-RANGE: 0x142919df0-0x142919ee0 .text$mn
// MS2-RANGE: 0x14291c090-0x14291c0b0 .text$mn
// MS2-RANGE: 0x142919a00-0x142919af0 .text$mn
// MS2-RANGE: 0x142917ed0-0x1429180c0 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/as2/as2_value.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x14291c090
FunctionObject::FunctionObject(ASStringContext* psc)
    : Object(psc)
{
}

// @0x14291f670
Object::Object(ASRefCountCollector* pcc)
    : ASRefCountBase<Object>(pcc), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    pProto = 0;
}

// @0x14291f6f0
SF_NOINLINE Object::Object(ASStringContext* psc)
    : ASRefCountBase<Object>(psc->GetGC()), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    pProto = 0;
}

// @0x14291f790
Object::Object(ASStringContext* psc, Object* pprototype)
    : ASRefCountBase<Object>(psc->GetGC()), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    Set__proto__(psc, pprototype);
}

// @0x14291f810
Object::Object(Environment* penv)
    : ASRefCountBase<Object>(penv->GetCollector()), pWatchpoints(0), ArePropertiesSet(false),
      IsListenerSet(false)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Object));
}

// @0x142919d70
CFunctionObject::CFunctionObject(ASStringContext* psc)
    : FunctionObject(psc), pFunction(0)
{
}

// @0x142919df0
CFunctionObject::CFunctionObject(ASStringContext* psc, CFunctionPtr func)
    : FunctionObject(psc), pFunction(func)
{
    Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Function));
}

// @0x142919e70
CFunctionObject::CFunctionObject(ASStringContext* psc, Object* pprototype, CFunctionPtr func)
    : FunctionObject(psc), pFunction(func)
{
    Set__proto__(psc, pprototype);
}

// @0x142919a00
BooleanObject::BooleanObject(Environment* penv)
    : Object(penv), BValue(false)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Boolean));
}

// @0x142919a70
BooleanObject::BooleanObject(Environment* penv, bool v)
    : Object(penv), BValue(v)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Boolean));
}

// @0x142917ed0
ArrayObject::ArrayObject(ASStringContext* psc, Object* pprototype)
    : Object(psc), LogPtr(0), RecursionCount(0), LengthValueOverriden(false)
{
    Set__proto__(psc, pprototype);
}

// @0x142917f70
ArrayObject::ArrayObject(ASStringContext* psc)
    : Object(psc), LogPtr(0), RecursionCount(0), LengthValueOverriden(false)
{
    Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Array));
}

// @0x142918010
ArrayObject::ArrayObject(Environment* penv)
    : Object(penv), LogPtr(penv->GetTarget()->GetLog()), RecursionCount(0), LengthValueOverriden(false)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Array));
}

// @0x1429237f0
Value::Value(const Value& v)
{
    T.Type = v.T.Type;
    switch (v.T.Type)
    {
    case BOOLEAN:
        V.BooleanValue = v.V.BooleanValue;
        break;
    case STRING:
    case FUNCTIONNAME:
        V.pStringNode = v.V.pStringNode;
        V.pStringNode->AddRef();
        break;
    case NUMBER:
        NV.NumberValue = v.NV.NumberValue;
        break;
    case INTEGER:
        NV.Int32Value = v.NV.Int32Value;
        break;
    case OBJECT:
        if (v.V.pObjectValue)
        {
            if (v.V.pObjectValue->IsFunction())
            {
                T.Type = FUNCTION;
                V.FunctionValue.Init(v.V.pObjectValue->ToFunction());
            }
            else
            {
                V.pObjectValue = v.V.pObjectValue;
                V.pObjectValue->AddRef();
            }
        }
        else
            V.pObjectValue = 0;
        break;
    case CHARACTER:
        V.pCharHandle = v.V.pCharHandle;
        if (V.pCharHandle)
            V.pCharHandle->AddRef();
        break;
    case FUNCTION:
    case RESOLVEHANDLER:
        V.FunctionValue.Init(v.V.FunctionValue);
        break;
    case PROPERTY:
        V.pProperty = v.V.pProperty;
        V.pProperty->AddRef();
        break;
    default:
        break;
    }
}

// @0x142923cb0
Value::Value(Object* pobj)
{
    if (pobj && pobj->IsFunction())
    {
        T.Type = FUNCTION;
        V.FunctionValue.Init(pobj->ToFunction());
    }
    else
    {
        T.Type         = OBJECT;
        V.pObjectValue = pobj;
        if (pobj)
            pobj->AddRef();
    }
}

// @0x1429267a0
void Value::operator=(const Value& v)
{
    if (T.Type >= STRING)
        DropRefs();

    // The same copy as the copy constructor.
    T.Type = v.T.Type;
    switch (v.T.Type)
    {
    case BOOLEAN:
        V.BooleanValue = v.V.BooleanValue;
        break;
    case STRING:
    case FUNCTIONNAME:
        V.pStringNode = v.V.pStringNode;
        V.pStringNode->AddRef();
        break;
    case NUMBER:
        NV.NumberValue = v.NV.NumberValue;
        break;
    case INTEGER:
        NV.Int32Value = v.NV.Int32Value;
        break;
    case OBJECT:
        if (v.V.pObjectValue)
        {
            if (v.V.pObjectValue->IsFunction())
            {
                T.Type = FUNCTION;
                V.FunctionValue.Init(v.V.pObjectValue->ToFunction());
            }
            else
            {
                V.pObjectValue = v.V.pObjectValue;
                V.pObjectValue->AddRef();
            }
        }
        else
            V.pObjectValue = 0;
        break;
    case CHARACTER:
        V.pCharHandle = v.V.pCharHandle;
        if (V.pCharHandle)
            V.pCharHandle->AddRef();
        break;
    case FUNCTION:
    case RESOLVEHANDLER:
        V.FunctionValue.Init(v.V.FunctionValue);
        break;
    case PROPERTY:
        V.pProperty = v.V.pProperty;
        V.pProperty->AddRef();
        break;
    default:
        break;
    }
}

// @0x142923e70
ValueProperty::ValueProperty(ASRefCountCollector* pcc, const FunctionRef& getterMethod,
                             const FunctionRef& setterMethod)
    : ASRefCountBase<ValueProperty>(pcc), GetterMethod(getterMethod), SetterMethod(setterMethod)
{
}

// @0x142923fd0
Object::Watchpoint::Watchpoint(const Watchpoint& o) : Callback(o.Callback), UserData(o.UserData)
{
}

// @0x1429181f0
ArraySortFunctor::ArraySortFunctor(const ArraySortFunctor& src)
    : This(src.This), Flags(src.Flags), Func(src.Func), Env(src.Env), LogPtr(src.LogPtr)
{
}

// @0x142925350
ArraySortFunctor::~ArraySortFunctor()
{
}

// @0x142926100
void Object::Watchpoint::Destruct_Call()
{
    this->~Watchpoint();
}

// @0x142925ae0
MovieRoot::InvokeAliasInfo::~InvokeAliasInfo()
{
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// The out-of-line destructors of the AS2 arrays, hashes and stacks.
template ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<Ptr<GFx::AS2::Object>, AllocatorLH<Ptr<GFx::AS2::Object>, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
// MS2-FUNCTIONAL cl inlines ~ArraySortFunctor (defined above), the exe calls it
// @0x1429242d0
template ArrayDataBase<GFx::AS2::ArraySortFunctor, AllocatorGH<GFx::AS2::ArraySortFunctor, 2>,
                       ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<GFx::AS2::Value, AllocatorGH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::~ArrayDataBase();
template ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>,
                       ArrayDefaultPolicy>::~ArrayDataBase();

typedef HashNode<GFx::AS2::Object*, GFx::AS2::Object*, IdentityHash<GFx::AS2::Object*> > MS2_AS2ObjectIdentityNode;
template HashSetBase<MS2_AS2ObjectIdentityNode, MS2_AS2ObjectIdentityNode::NodeHashF,
                     MS2_AS2ObjectIdentityNode::NodeAltHashF, AllocatorGH<GFx::AS2::Object*>,
                     HashsetNodeEntry<MS2_AS2ObjectIdentityNode, MS2_AS2ObjectIdentityNode::NodeHashF> >::~HashSetBase();
typedef HashNode<GFx::ASString, char, GFx::ASStringHashFunctor> MS2_AS2StandardMemberNode;
template decltype(HashLH<GFx::ASString, char, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem, MS2_AS2StandardMemberNode,
                         HashsetNodeEntry<MS2_AS2StandardMemberNode, MS2_AS2StandardMemberNode::NodeHashF> >::mHash)::
    BaseType::~HashSetBase();
typedef HashNode<GFx::ASString, GFx::AS2::MovieRoot::InvokeAliasInfo, GFx::ASStringHashFunctor> MS2_AS2InvokeAliasNode;
// MS2-FUNCTIONAL cl inlines ~InvokeAliasInfo (defined above), the exe calls it
// @0x142924610
template decltype(HashLH<GFx::ASString, GFx::AS2::MovieRoot::InvokeAliasInfo, GFx::ASStringHashFunctor,
                         GFx::StatMV_ASString_Mem, MS2_AS2InvokeAliasNode,
                         HashsetNodeEntry<MS2_AS2InvokeAliasNode, MS2_AS2InvokeAliasNode::NodeHashF> >::mHash)::
    BaseType::~HashSetBase();
typedef HashNode<GFx::ASString, GFx::AS2::FunctionRef, GFx::ASStringHashFunctor> MS2_AS2FunctionRefNode;
// MS2-FUNCTIONAL the exe calls the node dtor out of line (0x142924490)
// @0x142924770
template decltype(HashLH<GFx::ASString, GFx::AS2::FunctionRef, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem,
                         MS2_AS2FunctionRefNode,
                         HashsetNodeEntry<MS2_AS2FunctionRefNode, MS2_AS2FunctionRefNode::NodeHashF> >::mHash)::
    BaseType::~HashSetBase();

// The collected string hashes (ASStringHash_GC<U>).
#define MS2_AS2_STRING_HASH_GC_DTOR(U)                                                                           \
    template decltype(HashLH<GFx::ASString, U, GFx::ASStringHashFunctor, GFx::StatMV_ASString_Mem,                 \
                             HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,                                 \
                             GFx::HashsetNodeEntry_GC<HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,        \
                                                      HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeHashF> >::mHash)::BaseType::~HashSetBase();

MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::Object::Watchpoint)
MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::Member)
MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::SharedObjectPtr)
MS2_AS2_STRING_HASH_GC_DTOR(GFx::AS2::Value)
// MS2-FUNCTIONAL cl inlines the handler array dtor (instantiated above), the exe calls it
// @0x142924a20
template decltype(HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, GFx::EventIdHashFunctor,
                         GFx::AS2::StatMV_ActionScript_Mem>::mHash)::BaseType::~HashSetBase();
template decltype(StringHashLH<GFx::AS2::MovieClipLoader::ProgressDesc>::mHash)::BaseType::~HashSetBase();

// MS2-FUNCTIONAL the Ptr release is inlined differently (the exe calls ReleaseInternal from two sites)
// @0x142924b70
template GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::~PagedStack();
// MS2-FUNCTIONAL register allocation of the pop loop (the exe reloads the top pointer each iteration)
// @0x142924c60
template GFx::AS2::PagedStack<GFx::AS2::Value, 32>::~PagedStack();

} // namespace Scaleform
// MS2-PIN: ??1?$ArrayDataBase@VArraySortFunctor@AS2@GFx@Scaleform@@U?$AllocatorGH@VArraySortFunctor@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1429242d0
// MS2-PIN: ??1?$ArrayDataBase@VValue@AS2@GFx@Scaleform@@U?$AllocatorLH@VValue@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x1429243b0
// MS2-PIN: ??1?$ArrayDataBase@VValue@AS2@GFx@Scaleform@@U?$AllocatorLH@VValue@AS2@GFx@Scaleform@@$0BED@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAA@XZ 0x142924420
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x142924610
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x142924770
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VEventId@GFx@Scaleform@@$0BED@@2@V?$HashsetCachedNodeEntry@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x142924a20
// MS2-PIN: ??1?$PagedStack@V?$Ptr@VFunctionObject@AS2@GFx@Scaleform@@@Scaleform@@$0CA@@AS2@GFx@Scaleform@@QEAA@XZ 0x142924b70
// MS2-PIN: ??1?$PagedStack@VValue@AS2@GFx@Scaleform@@$0CA@@AS2@GFx@Scaleform@@QEAA@XZ 0x142924c60
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS2@GFx@Scaleform@@6B@ 0x143215370
// MS2-PIN: ??_7?$ASRefCountBase@UValueProperty@AS2@GFx@Scaleform@@@AS2@GFx@Scaleform@@6B@ 0x1432153d0
// MS2-PIN: ??_7ValueProperty@AS2@GFx@Scaleform@@6B@ 0x1432153e8
// MS2-PIN: ??_7ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215410
// MS2-PIN: ??_7?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@AS2@GFx@Scaleform@@6B@ 0x1432154b8
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432154d0
// MS2-PIN: ??_7Object@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215518
// MS2-PIN: ??_7BooleanObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b550
// MS2-PIN: ??_7BooleanObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b598
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
// MS2-PIN: ??_7ArrayObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ad30
// MS2-PIN: ??_7ArrayObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ad78
