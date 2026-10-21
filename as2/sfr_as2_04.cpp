// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 function reference assignment
// and the out-of-line hash table helpers (grow, clear) of the AS2 member, watchpoint and prototype tables.
// MS2-UNIT: sfr_as2_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292bab0-0x14292bae0 .text$mn
// MS2-RANGE: 0x14292e120-0x14292e180 .text$mn
// MS2-RANGE: 0x14292e180-0x14292e650 .text$mn
// MS2-RANGE: 0x142931710-0x142931870 .text$mn
// MS2-RANGE: 0x142932010-0x142932040 .text$mn
// MS2-RANGE: 0x142932180-0x1429321c0 .text$mn
// MS2-RANGE: 0x1429339a0-0x142933bd0 .text$mn
// MS2-RANGE: 0x142933d80-0x142933e20 .text$mn
// MS2-RANGE: 0x142934060-0x142934390 .text$mn
// MS2-RANGE: 0x142934390-0x1429343e0 .text$mn
// MS2-RANGE: 0x1429345d0-0x142934610 .text$mn
// MS2-RANGE: 0x142934a00-0x142934a80 .text$mn
// MS2-RANGE: 0x142935200-0x142935580 .text$mn
// MS2-RANGE: 0x142935680-0x142935820 .text$mn
// MS2-RANGE: 0x142935b50-0x142935c70 .text$mn
// MS2-RANGE: 0x142936620-0x142936680 .text$mn
// MS2-RANGE: 0x1429367a0-0x1429367e0 .text$mn
// MS2-RANGE: 0x142936880-0x1429368c0 .text$mn
// MS2-RANGE: 0x142936bc0-0x142936c80 .text$mn
// MS2-RANGE: 0x142936e10-0x142936e90 .text$mn
// MS2-RANGE: 0x142937170-0x142937290 .text$mn
// MS2-RANGE: 0x142937380-0x1429373c0 .text$mn
// MS2-RANGE: 0x142937470-0x1429374f0 .text$mn
// MS2-RANGE: 0x142937e20-0x142937ea0 .text$mn
// MS2-RANGE: 0x142938180-0x1429381f0 .text$mn
// MS2-RANGE: 0x142938830-0x142938850 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_stringhash.h"

namespace Scaleform { namespace GFx {

// @0x142935540
bool ASConstString::CompareBuiltIn_CaseInsensitive(const ASConstString& str) const
{
    str.ResolveLowercase();
    return pNode->pLower == str.pNode->pLower;
}

namespace AS2 {

// @0x142931790
void FunctionRefBase::Assign(const FunctionRefBase& orig)
{
    if (this == &orig)
        return;

    FunctionObject* pprev = Function;
    if (!(Flags & FuncRef_Internal) && pprev && pprev != orig.Function)
        pprev->Release();
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && orig.Function && pprev != orig.Function)
        orig.Function->AddRef();

    if (orig.pLocalFrame)
        SetLocalFrame(orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
    else
    {
        // SetLocalFrame(0), inlined.
        if (pLocalFrame && !(Flags & FuncRef_Weak))
            pLocalFrame->Release();
        Flags &= ~FuncRef_Weak;
        pLocalFrame = 0;
    }
}

// Value::ToStringVersioned (exe 0x1429923c0), which the exe inlines here.
static SF_FORCEINLINE ASString Value_ToStringVersioned(const Value& val, Environment* penv, unsigned version)
{
    if (val.IsUndefined())
    {
        if (version > 0 && version <= 6)
            return penv->GetBuiltin(ASBuiltin_empty_);
        else
            return penv->GetBuiltin(ASBuiltin_undefined);
    }
    return val.ToString(penv);
}

// Value::StringConcat (exe 0x142990240), which the exe inlines in Add: this as a string followed by str.
static SF_FORCEINLINE void Value_StringConcat(Value* pval, Environment* penv, const ASString& str)
{
    ASString tempstr(pval->ToString(penv) + str);
    pval->DropRefs();
    pval->T.Type        = Value::STRING;
    pval->V.pStringNode = tempstr.GetNode();
    pval->V.pStringNode->AddRef();
}

// @0x14292e120
bool MovieClipObject::ActsAsButton() const
{
    if ((ButtonEventMask != 0) || HasButtonHandlers)
        return true;
    // 4.1.18 asks the type of the first prototype on every step.
    for (Object* pproto = pProto; pproto != 0; pproto = pproto->pProto)
    {
        if (pProto->GetObjectType() == Object_MovieClipObject)
            return static_cast<MovieClipObject*>(pproto)->ActsAsButton();
    }
    return false;
}

// @0x14292e180
void Value::Add(Environment* penv, const Value& v)
{
    Value pv1, pv2;

    pv1 = ToPrimitive(penv);
    pv2 = v.ToPrimitive(penv);

    if (pv1.T.Type == STRING || pv2.T.Type == STRING)
    {
        unsigned version = penv->GetVersion();

        pv1.ConvertToStringVersioned(penv, version);
        Value_StringConcat(&pv1, penv, Value_ToStringVersioned(pv2, penv, version));
        SetString(pv1.ToString(penv));
    }
    else
    {
        SetNumber(pv1.ToNumber(penv) + pv2.ToNumber(penv));
    }
}

// @0x14292e460
void Value::Add(Environment* penv, int v2)
{
    Value pv1;

    pv1 = ToPrimitive(penv);

    if (pv1.T.Type == STRING)
    {
        unsigned version = penv->GetVersion();

        pv1.ConvertToStringVersioned(penv, version);
        Value_StringConcat(&pv1, penv, Value_ToStringVersioned(Value(v2), penv, version));
        SetString(pv1.ToString(penv));
    }
    else
    {
        SetNumber(pv1.ToNumber(penv) + (Number)v2);
    }
}

// MS2-FUNCTIONAL register allocation of the operand types and the ToNumber call order
// @0x142935200
Value Value::Compare(Environment* penv, const Value& v, int action) const
{
    if (action == 0)
        return Value(IsEqual(penv, v));

    // ECMA-262 11.8.5.
    Value pv1    = ToPrimitive(penv);
    Value pv2    = v.ToPrimitive(penv);
    bool  result = false;
    if (pv1.IsString() && pv2.IsString())
    {
        if (action < 0)
            return (pv1.ToString(penv) < pv2.ToString(penv));
        else
            return (pv1.ToString(penv) > pv2.ToString(penv));
    }
    if (penv->GetVersion() > 6 && (pv1.IsUndefined() || pv2.IsUndefined()))
        return Value();

    // Both orders reduce to val1 < val2.
    Number val1 = pv1.ToNumber(penv);
    Number val2 = pv2.ToNumber(penv);
    if (action > 0)
    {
        Number t = val1;
        val1     = val2;
        val2     = t;
    }

    if (NumberUtil::IsNaN(val1) || NumberUtil::IsNaN(val2))
        return Value();
    if (val1 == val2)
        result = false;
    else if (NumberUtil::IsNEGATIVE_ZERO(val1) && NumberUtil::IsPOSITIVE_ZERO(val2))
        result = false;
    else if (NumberUtil::IsNEGATIVE_ZERO(val2) && NumberUtil::IsPOSITIVE_ZERO(val1))
        result = false;
    else if (NumberUtil::IsPOSITIVE_INFINITY(val1))
        result = false;
    else if (NumberUtil::IsPOSITIVE_INFINITY(val2))
        result = true;
    else if (NumberUtil::IsNEGATIVE_INFINITY(val2))
        result = false;
    else if (NumberUtil::IsNEGATIVE_INFINITY(val1))
        result = true;
    else
        result = (val1 < val2);
    return Value(result);
}

// MS2-FUNCTIONAL the exe tail-calls AddToFreeList from the inlined iterator destructor
// @0x142934390
void MovieRoot::ActionQueueType::Clear()
{
    ActionQueueIterator iter(this);
    while (iter.getNext())
        ;
}

// @0x1429345d0
void Environment::ClearThrowing()
{
    ThrowingValue.SetUnset();
    Unrolling = false;
}

// @0x142933d80
void Environment::CheckTryBlocks(int pc, int* plocalTryBlockCount)
{
    int localTryBlockCount = *plocalTryBlockCount;
    if (localTryBlockCount > 0)
    {
        for (; TryBlocks.GetSize() > 0 && localTryBlockCount >= 0; --localTryBlockCount)
        {
            const TryDescr& tryDescr = TryBlocks[TryBlocks.GetSize() - 1];
            if ((unsigned)pc < tryDescr.TryBeginPC || (unsigned)pc >= tryDescr.TryBeginPC + tryDescr.GetTrySize())
            {
                --(*plocalTryBlockCount);
                TryBlocks_Resize(&TryBlocks, TryBlocks.GetSize() - 1);
            }
            else
                break;
        }
    }
}

// @0x142937e20
ASString StringProto::CreateStringFromCStr(ASStringContext* psc, const char* start, const char* end)
{
    int len = (end == 0) ? (int)strlen(start) : int(end - start);
    if (len < 0)
        len = 0;
    if (len > 0)
        return psc->CreateString(start, len);
    return psc->GetBuiltin(ASBuiltin_empty_);
}

// @0x142938180
void Environment::DeclareLocal(const ASString& varname)
{
    UPInt nframes = LocalFrames.GetSize();
    if (nframes && LocalFrames[nframes - 1])
    {
        if (!FindLocal(varname))
            AddLocal(varname, Value());
    }
}

// @0x142938830
bool AvmSprite::DeleteMember(ASStringContext* psc, const ASString& name)
{
    if (AvmCharacter::DeleteMember(psc, name))
        return true;
    return false;
}

// @0x142935b50
void Value::ConvertToNumber(Environment* penv)
{
    SetNumber(ToNumber(penv));
}

// @0x142935b90
void Value::ConvertToString(Environment* penv)
{
    ASString str = ToString(penv);
    DropRefs();
    T.Type        = STRING;
    V.pStringNode = str.GetNode();
    V.pStringNode->AddRef();
}

// @0x142935be0
void Value::ConvertToStringVersioned(Environment* penv, unsigned version)
{
    ASString str = Value_ToStringVersioned(*this, penv, version);
    DropRefs();
    T.Type        = STRING;
    V.pStringNode = str.GetNode();
    V.pStringNode->AddRef();
}

// @0x142934a00
void BooleanObject::CommonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Boolean));
}

// @0x142934a40
void NumberObject::CommonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Number));
}

// The instances the constructor functions create for new.
// @0x142936620
ActionBufferData* ActionBufferData::CreateNew()
{
    return SF_NEW ActionBufferData();
}

// @0x1429367a0
Object* ArrayCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ArrayObject(penv);
}

// @0x142936880
Object* AsFunctionObject::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) Object(penv);
}

// @0x142936bc0
Object* ColorMatrixFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ColorMatrixFilterObject(penv);
}

// @0x142936c00
Object* ColorTransformCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ColorTransformObject(penv);
}

// @0x142936c40
Object* DateCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) DateObject(penv);
}

// @0x142936e10
Object* GASLoadVarsLoaderCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) LoadVarsObject(penv);
}

// @0x142936e50
Object* GASMatrixCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) MatrixObject(penv);
}

// @0x142937170
Object* ObjectCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) Object(penv);
}

// @0x1429371b0
Object* PointCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) PointObject(penv);
}

// @0x1429371f0
Object* RectangleCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) RectangleObject(penv);
}

// @0x142937240
Object* SharedObjectCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) SharedObject(penv);
}

// @0x142937380
Object* StyleSheetCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) StyleSheetObject(penv);
}

// @0x142937470
Object* TextFormatCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) TextFormatObject(penv);
}

// @0x1429374b0
Object* TransformCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) TransformObject(penv);
}

// @0x142932010
void GASSharedObjectLoader::Begin()
{
    ObjectPtrArray_Resize(&ObjectStack, 0);
    ObjectPtrArray_PushBack(&ObjectStack, pData);
}

// @0x142932180
bool AsBroadcaster::BroadcastMessage(Environment* penv, ObjectInterface* pthis, const ASString& eventName, int nArgs,
                                     int firstArgBottomIndex)
{
    if (!pthis)
        return false;
    class LocalInvokeCallback : public InvokeCallback
    {
    public:
        int NArgs;
        int FirstArgBottomIndex;

        LocalInvokeCallback(int nargs, int firstArg) : NArgs(nargs), FirstArgBottomIndex(firstArg) {}

        virtual void Invoke(Environment* penv, ObjectInterface* pthis, const FunctionRef& method)
        {
            Value result;
            method.Invoke(FnCall(&result, pthis, penv, NArgs, FirstArgBottomIndex));
        }
    } callback(nArgs, firstArgBottomIndex);
    BroadcastMessageWithCallback(penv, pthis, eventName, &callback);
    return true;
}

// @0x142935680
void ArrayObject::Concat(Environment* penv, const Value& val)
{
    RecursionGuard rg(this);
    if (RecursionLimitReached())
        return;

    MemoryHeap* pheap = penv->GetHeap();
    Object*     pobj  = val.ToObject(penv);
    if (pobj && pobj->GetObjectType() == ObjectInterface::Object_Array)
    {
        ArrayObject* parray = (ArrayObject*)pobj;
        if (parray->Elements.GetSize())
        {
            unsigned oldSize = (unsigned)Elements.GetSize();
            Resize((int)(oldSize + parray->Elements.GetSize()));
            for (UPInt i = 0; i < parray->Elements.GetSize(); i++)
                Elements[oldSize + i] = SF_HEAP_NEW(pheap) Value(*parray->Elements[i]);
        }
    }
    else
        Elements.PushBack(SF_HEAP_NEW(pheap) Value(val));
}

// @0x142931710
void ArrayObject::ArrayLength(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, Array);
    ArrayObject* pthis = (ArrayObject*)fn.ThisPtr;
    fn.Result->SetInt(pthis->GetSize());
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// Growth of the AS2 hash tables (one more entry).
typedef HashNode<GFx::AS2::ASBuiltinType, Ptr<GFx::AS2::Object>, FixedSizeHash<GFx::AS2::ASBuiltinType> >
    MS2_AS2PrototypeNode;
template void HashSetBase<MS2_AS2PrototypeNode, MS2_AS2PrototypeNode::NodeHashF, MS2_AS2PrototypeNode::NodeAltHashF,
                          AllocatorLH<GFx::AS2::ASBuiltinType, 2>,
                          HashsetNodeEntry<MS2_AS2PrototypeNode, MS2_AS2PrototypeNode::NodeHashF> >::CheckExpand(void*);

// The string keyed sets: ASStringHash<U> (plain entries) and ASStringHash_GC<U> (collector entries).
#define MS2_AS2_STRING_SET(U, E)                                                                                     \
    HashSetBase<HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,                                                \
                HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeHashF,                                     \
                HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeAltHashF,                                  \
                AllocatorLH<GFx::ASString, GFx::StatMV_ASString_Mem>,                                                \
                E<HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,                                              \
                  HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeHashF> >

template void MS2_AS2_STRING_SET(GFx::AS2::MovieRoot::InvokeAliasInfo, HashsetNodeEntry)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::Object::Watchpoint, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::Member, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::SharedObjectPtr, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::Value, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void decltype(StringHashLH<GFx::AS2::MovieClipLoader::ProgressDesc>::mHash)::BaseType::CheckExpand(void*);

// Clearing (destroys every entry and frees the table).
template void MS2_AS2_STRING_SET(char, HashsetNodeEntry)::Clear();
// @0x1429340f0
// MS2-FUNCTIONAL cl inlines the node destructor that the exe calls out of line (~HashNode<ASString, FunctionRef>, 0x142924490)
template void MS2_AS2_STRING_SET(GFx::AS2::FunctionRef, HashsetNodeEntry)::Clear();
template void MS2_AS2_STRING_SET(GFx::AS2::Member, GFx::HashsetNodeEntry_GC)::Clear();
// @0x142934220
// MS2-FUNCTIONAL cl inlines the ArrayDataBase<Value, LH 323> destructor that the exe calls out of line (0x142924420)
template void decltype(HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, GFx::EventIdHashFunctor,
                              GFx::AS2::StatMV_ActionScript_Mem>::mHash)::BaseType::Clear();
// @0x1429342b0
// MS2-FUNCTIONAL register allocation differs (key / value String release order kept)
template void HashsetCachedNodeEntry<HashNode<String, String, String::NoCaseHashFunctor>,
                                     HashNode<String, String, String::NoCaseHashFunctor>::NodeHashF>::Clear();
template void GFx::HashsetNodeEntry_GC<HashNode<GFx::ASString, GFx::AS2::Object::Watchpoint, GFx::ASStringHashFunctor>,
                                       HashNode<GFx::ASString, GFx::AS2::Object::Watchpoint,
                                                GFx::ASStringHashFunctor>::NodeHashF>::Clear();
template void GFx::HashsetNodeEntry_GC<HashNode<GFx::ASString, GFx::AS2::Member, GFx::ASStringHashFunctor>,
                                       HashNode<GFx::ASString, GFx::AS2::Member, GFx::ASStringHashFunctor>::NodeHashF>::Clear();

} // namespace Scaleform

// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@W4ASBuiltinType@AS2@GFx@Scaleform@@V?$Ptr@VObject@AS2@GFx@Scaleform@@@4@V?$FixedSizeHash@W4ASBuiltinType@AS2@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@W4ASBuiltinType@AS2@GFx@Scaleform@@$01@2@V?$HashsetNodeEntry@U?$HashNode@W4ASBuiltinType@AS2@GFx@Scaleform@@V?$Ptr@VObject@AS2@GFx@Scaleform@@@4@V?$FixedSizeHash@W4ASBuiltinType@AS2@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1429339a0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1429339f0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UWatchpoint@Object@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@UWatchpoint@Object@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933a40
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933a90
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VSharedObjectPtr@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VSharedObjectPtr@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933ae0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933b30
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$StringLH_HashNode@UProgressDesc@MovieClipLoader@AS2@GFx@Scaleform@@UNoCaseHashFunctor@String@5@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UProgressDesc@MovieClipLoader@AS2@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$StringLH_HashNode@UProgressDesc@MovieClipLoader@AS2@GFx@Scaleform@@UNoCaseHashFunctor@String@5@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x142933b80
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@DUASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@DUASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x142934060
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x1429340f0
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXXZ 0x142934180
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VEventId@GFx@Scaleform@@$0BED@@2@V?$HashsetCachedNodeEntry@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x142934220
// MS2-PIN: ?Clear@?$HashsetCachedNodeEntry@U?$HashNode@VString@Scaleform@@V12@UNoCaseHashFunctor@12@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAAXXZ 0x1429342b0
// MS2-PIN: ?Clear@?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@UWatchpoint@Object@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@Scaleform@@QEAAXXZ 0x142934320
// MS2-PIN: ?Clear@?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@Scaleform@@QEAAXXZ 0x142934350
// MS2-PIN: ??_7SharedObjectPtr@AS2@GFx@Scaleform@@6B@ 0x14321dd78
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
// MS2-PIN: ??_7LocalInvokeCallback@?1??BroadcastMessage@AsBroadcaster@AS2@GFx@Scaleform@@SA_NPEAVEnvironment@345@PEAVObjectInterface@345@AEBVASString@45@HH@Z@6B@ 0x143221850
// MS2-PIN: ??_7ActionBufferData@AS2@GFx@Scaleform@@6B@ 0x1432153b8
// MS2-PIN: ??_7?$RefCountBase@VActionBufferData@AS2@GFx@Scaleform@@$0BAI@@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BAI@@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b5018
