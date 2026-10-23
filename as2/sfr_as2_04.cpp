// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 function reference assignment
// and the out-of-line hash table helpers (grow, clear) of the AS2 member, watchpoint and prototype tables.
// MS2-UNIT: sfr_as2_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14292a680-0x14292a6ab .text$mn
// MS2-RANGE: 0x14292bab0-0x14292bae0 .text$mn
// MS2-RANGE: 0x14292e120-0x14292e180 .text$mn
// MS2-RANGE: 0x14292e180-0x14292e650 .text$mn
// MS2-RANGE: 0x142931710-0x142931870 .text$mn
// MS2-RANGE: 0x142932010-0x142932040 .text$mn
// MS2-RANGE: 0x142932180-0x142932290 .text$mn
// MS2-RANGE: 0x1429339a0-0x142933bd0 .text$mn
// MS2-RANGE: 0x142933d80-0x142933e20 .text$mn
// MS2-RANGE: 0x142934060-0x142934390 .text$mn
// MS2-RANGE: 0x142934390-0x1429343e0 .text$mn
// MS2-RANGE: 0x1429345d0-0x142934610 .text$mn
// MS2-RANGE: 0x142934a00-0x142934a80 .text$mn
// MS2-RANGE: 0x142935200-0x142935680 .text$mn
// MS2-RANGE: 0x142935680-0x142935820 .text$mn
// MS2-RANGE: 0x142935b50-0x142935dc0 .text$mn
// MS2-RANGE: 0x142936620-0x142936680 .text$mn
// MS2-RANGE: 0x1429367a0-0x1429374f0 .text$mn
// MS2-RANGE: 0x14292f250-0x14292f430 .text$mn
// MS2-RANGE: 0x14292f5b0-0x14292f740 .text$mn
// MS2-RANGE: 0x142937d60-0x142937f90 .text$mn
// MS2-RANGE: 0x142938180-0x1429381f0 .text$mn
// MS2-RANGE: 0x142938830-0x142938850 .text$mn
// MS2-RANGE: 0x14292ff50-0x142930089 .text$mn
// MS2-RANGE: 0x142930910-0x142930a10 .text$mn
// MS2-RANGE: 0x142925190-0x14292522c .text$mn
// MS2-RANGE: 0x1429385f0-0x142938830 .text$mn
// MS2-RANGE: 0x142956060-0x142956070 .text$mn
// MS2-RANGE: 0x142932040-0x142932180 .text$mn
// MS2-RANGE: 0x142937f90-0x142938020 .text$mn
// MS2-RANGE: 0x14292dc70-0x14292df89 .text$mn
// MS2-RANGE: 0x142935dc0-0x142935e8a .text$mn
// MS2-RANGE: 0x142993810-0x1429938c2 .text$mn
// MS2-RANGE: 0x1429362c0-0x142936357 .text$mn
// MS2-RANGE: 0x1429360e0-0x1429362b3 .text$mn
// MS2-RANGE: 0x142935ea0-0x1429360d3 .text$mn
// MS2-RANGE: 0x14292e650-0x14292e6d3 .text$mn
// MS2-RANGE: 0x142934820-0x1429349a0 .text$mn
// MS2-RANGE: 0x142936360-0x142936506 .text$mn
// MS2-RANGE: 0x1429431a0-0x1429431cc .text$mn
// MS2-RANGE: 0x14292da40-0x14292dad4 .text$mn
// MS2-RANGE: 0x14292f740-0x14292f951 .text$mn
// MS2-RANGE: 0x142930a10-0x142930c30 .text$mn
// MS2-RANGE: 0x142934610-0x142934820 .text$mn
// MS2-RANGE: 0x1429381f0-0x1429384e1 .text$mn
// MS2-RANGE: 0x142934a80-0x142934f87 .text$mn
// MS2-RANGE: 0x142934f90-0x1429351fd .text$mn

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
#include "../include/gfx/gfx_value.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/kernel/sf_std.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/render/render_twips.h"

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

// The Button and MovieClip instances made by new are only used here.
inline ButtonObject::ButtonObject(Environment* penv)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Button));
}

inline MovieClipObject::MovieClipObject(Environment* penv)
    : Object(penv), ButtonEventMask(0), HasButtonHandlers(false)
{
    MovieClipObject::Set__proto__(penv->GetSC(), penv->GetSC()->pContext->GetActualPrototype(penv, ASBuiltin_MovieClip));
}

// @0x1429367a0
Object* ArrayCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ArrayObject(penv);
}

// MS2-FUNCTIONAL the exe inlines the AsBroadcaster(Environment*) ctor (sfr_as2_03)
// @0x1429367e0
Object* AsBroadcasterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) AsBroadcaster(penv);
}

// @0x142936880
Object* AsFunctionObject::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) Object(penv);
}

// MS2-FUNCTIONAL the exe inlines the BevelFilterObject(Environment*) ctor (sfr_as2_03)
// @0x1429368c0
Object* BevelFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) BevelFilterObject(penv);
}

// MS2-FUNCTIONAL the exe inlines the BlurFilterObject(Environment*) ctor (sfr_as2_03)
// @0x142936940
Object* BlurFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) BlurFilterObject(penv);
}

// MS2-FUNCTIONAL the exe inlines the BooleanObject(Environment*) ctor (sfr_as2_03)
// @0x1429369b0
Object* BooleanCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) BooleanObject(penv);
}

// @0x142936a50
Object* ButtonCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ButtonObject(penv);
}

// MS2-FUNCTIONAL the exe inlines the ColorObject(Environment*) ctor (sfr_as2_03)
// @0x142936b10
Object* ColorCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ColorObject(penv, 0);
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

// MS2-FUNCTIONAL the exe inlines the DropShadowFilterObject(Environment*) ctor (sfr_as2_03)
// @0x142936c80
Object* DropShadowFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) DropShadowFilterObject(penv);
}

// MS2-FUNCTIONAL the exe inlines the ExternalInterface(Environment*) ctor (sfr_as2_03)
// @0x142936cf0
Object* ExternalInterfaceCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ExternalInterface(penv);
}

// MS2-FUNCTIONAL the exe inlines the CFunctionObject(ASStringContext*) ctor (sfr_as2_03)
// @0x142936d90
Object* FunctionCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) CFunctionObject(penv->GetSC());
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

// MS2-FUNCTIONAL the exe inlines the GlowFilterObject(Environment*) ctor (sfr_as2_03)
// @0x142936e90
Object* GlowFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) GlowFilterObject(penv);
}

// @0x142936f30
Object* MovieClipCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) MovieClipObject(penv);
}

// MS2-FUNCTIONAL the exe inlines the MovieClipLoader(Environment*) ctor (sfr_as2_03)
// @0x142936ff0
Object* MovieClipLoaderCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) MovieClipLoader(penv);
}

// MS2-FUNCTIONAL the exe inlines the NumberObject(Environment*) ctor (sfr_as2_03)
// @0x1429370c0
Object* NumberCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) NumberObject(penv);
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

// MS2-FUNCTIONAL the exe inlines the StringObject(Environment*) ctor (sfr_as2_03)
// @0x142937290
Object* StringCtorFunction::CreateNewObject(Environment* penv) const
{
    StringObject* pobj = SF_HEAP_NEW(penv->GetHeap()) StringObject(penv);
    // length is computed by GetMemberRaw; the unset member only keeps its slot
    ASStringContext* psc = penv->GetSC();
    pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_length), Value(Value::UNSET), PropFlags());
    return pobj;
}

// @0x142937380
Object* StyleSheetCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) StyleSheetObject(penv);
}

// MS2-FUNCTIONAL the exe inlines the TextFieldObject(Environment*) ctor (sfr_as2_03)
// @0x1429373c0
Object* TextFieldCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) TextFieldObject(penv);
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

// The AS2 text field's part of the movie (only the broadcast native so far).
class AvmTextField : public AvmCharacter
{
public:
    // Sends the event named by the first argument to the listeners of the text field.
    static void BroadcastMessage(const FnCall& fn);

    virtual void CloneInternalData(const InteractiveObject* src);
    virtual void CopyPhysicalProperties(const InteractiveObject* poldChar);
};

// @0x1429321c0
void AvmTextField::BroadcastMessage(const FnCall& fn)
{
    ASString eventName = fn.Arg(0).ToString(fn.Env);
    AsBroadcaster::BroadcastMessage(fn.Env, fn.ThisPtr, eventName, fn.NArgs - 1, fn.Env->GetTopIndex() - 1);
}

// @0x142935580
UPInt SharedObject::ComputeSizeInBytes(Environment* penv)
{
    // Adds up the names and values of the visited members, objects recursively.
    class SizeVisitor : public MemberVisitor
    {
    public:
        Environment* pEnv;
        UPInt        Size;

        SizeVisitor(Environment* penv) : pEnv(penv), Size(0) {}

        // @0x142993810
        virtual void Visit(const ASString& name, const Value& val, UByte flags)
        {
            SF_UNUSED(flags);
            Size += name.GetSize();
            switch (val.GetType())
            {
            case Value::NUMBER:
            case Value::INTEGER:
                Size += 4;
                break;
            case Value::STRING:
                Size += val.ToString(pEnv).GetSize();
                break;
            case Value::OBJECT:
                val.ToObject(pEnv)->VisitMembers(pEnv->GetSC(), this, 0, 0);
                break;
            default:;
            }
        }
    };

    Value data;
    GetMemberRaw(penv->GetSC(), penv->CreateConstString("data"), &data);
    Object*     pdata = data.ToObject(penv);
    SizeVisitor visitor(penv);
    pdata->VisitMembers(penv->GetSC(), &visitor, 0, 0);
    return visitor.Size;
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

// @0x14292f250
void GASPrototypeBase::AddInterface(ASStringContext* psc, int index, FunctionObject* ctor)
{
    if (!pInterfaces && !ctor)
    {
        // The first call only sizes the array: index is the number of interfaces.
        pInterfaces = SF_HEAP_NEW(psc->GetHeap()) InterfacesArray(index);
    }
    else
    {
        Value prototype;
        if (ctor->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), &prototype))
        {
            Ptr<Object> pproto = prototype.ToObject(0);
            (*pInterfaces)[index] = pproto;
        }
    }
}

// @0x14292f5b0
bool AsBroadcaster::AddListener(Environment* penv, ObjectInterface* pthis, ObjectInterface* plistener)
{
    if (!pthis || !plistener)
        return false;

    Value listenersVal;
    if (pthis->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin__listeners), &listenersVal))
    {
        Object* pobj = listenersVal.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object_Array)
        {
            Ptr<ArrayObject> plisteners = static_cast<ArrayObject*>(pobj);
            for (unsigned i = 0, n = plisteners->GetSize(); i < n; ++i)
            {
                Value* pelem = plisteners->GetElementPtr(i);
                if (pelem && pelem->ToObjectInterface_Call(penv) == plistener)
                    return false;
            }
            Value listener;
            listener.SetAsObjectInterface(plistener);
            plisteners->PushBack(listener);
        }
    }
    return true;
}


// The findIndexAlt of the local variable table, exact and ignoring case (exe COMDATs 0x1429173d0 / 0x142917130,
// called where cl inlines them).
SPInt ValueHash_FindIndex(const ASStringHash_GC<Value>* phash, const ASString& key);
SPInt ValueHash_FindIndexNoCase(const ASStringHash_GC<Value>* phash, const ASStringNoCaseKey& key);

typedef ASStringHash_GC<Value>::SetType ValueSet;

// Find / FindCaseInsensitive / FindCaseCheck of the local variable table.
inline ValueSet::Iterator ValueHash_Find(ASStringHash_GC<Value>* phash, const ASString& key)
{
    SPInt index = ValueHash_FindIndex(phash, key);
    if (index >= 0)
        return ValueSet::Iterator(reinterpret_cast<ValueSet*>(phash), index);
    return ValueSet::Iterator(0, 0);
}
inline ValueSet::Iterator ValueHash_FindNoCase(ASStringHash_GC<Value>* phash, const ASString& key)
{
    ASStringNoCaseKey ikey(key);
    SPInt index = ValueHash_FindIndexNoCase(phash, ikey);
    if (index >= 0)
        return ValueSet::Iterator(reinterpret_cast<ValueSet*>(phash), index);
    return ValueSet::Iterator(0, 0);
}
inline ValueSet::Iterator ValueHash_FindCaseCheck(ASStringHash_GC<Value>* phash, const ASString& key,
                                                  bool caseSensitive)
{
    return caseSensitive ? ValueHash_Find(phash, key) : ValueHash_FindNoCase(phash, key);
}

// The exe keeps it out of line (DeclareLocal calls it).
// @0x14292ff50
SF_NOINLINE void Environment::AddLocal(const ASString& varname, const Value& val)
{
    Ptr<LocalFrame> plocalFrame = LocalFrames[LocalFrames.GetSize() - 1];
    if (plocalFrame)
    {
        ASStringHash_GC<Value>* pvars = &plocalFrame->Variables;
        ValueSet::Iterator it = ValueHash_FindCaseCheck(pvars, varname, IsCaseSensitive());
        if (it != reinterpret_cast<ValueSet*>(pvars)->End())
            it->Second = val;
        else
        {
            ASStringHash_GC<Value>::NodeType::NodeRef e(varname, val);
            reinterpret_cast<ValueSet*>(pvars)->Add(pvars, e);
        }
    }
}

}}} // namespace Scaleform::GFx::AS2

// Instantiated out of line in sfr_as2_07 (exe 0x14297e710).
extern template void Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,
                                              Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value, 2>,
                                              Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// Instantiated out of line in sfr_as2_03 (exe 0x142924340).
extern template Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,
                                         Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value, 2>,
                                         Scaleform::ArrayDefaultPolicy>::~ArrayDataBase();

namespace Scaleform { namespace GFx { namespace AS2 {

// The exe keeps it out of line (AddToFreeList calls it).
// @0x142925190
SF_NOINLINE MovieRoot::ActionEntry::~ActionEntry()
{
}

// @0x142930910
void MovieRoot::ActionQueueType::AddToFreeList(ActionEntry* pentry)
{
    pentry->Type          = ActionEntry::Entry_None;
    pentry->pActionBuffer = 0;
    pentry->pCharacter    = 0;
    pentry->Function.DropRefs();
    pentry->FunctionParams.Clear();
    if (FreeEntriesCount < FreeEntriesLimit)
    {
        pentry->pNextEntry = pFreeEntry;
        ++FreeEntriesCount;
        pFreeEntry = pentry;
    }
    else
    {
        pentry->~ActionEntry();
        SF_FREE(pentry);
    }
}

// @0x1429385f0
bool ArrayObject::DeleteMember(ASStringContext* psc, const ASString& name)
{
    if (name.GetSize() > 0 && isdigit(name.ToCStr()[0]))
    {
        int idx;
        if ((idx = ParseIndex(name)) < 0)
            return false;
        SetElement(idx, Value());
        return true;
    }
    return Object::DeleteMember(psc, name);
}

// @0x142932040
void AvmSprite::BeginBitmapFill(FillType fillType, ImageResource* pimageRes, const Render::Matrix2F& mtx)
{
    AcquirePath(true)->BeginBitmapFill(fillType, pimageRes, mtx);
}

// @0x1429320c0
Render::ComplexFill* AvmSprite::BeginFill()
{
    DrawingContext*      pdc   = AcquirePath(true);
    Render::ComplexFill* pfill = pdc->CreateNewComplexFill();
    pdc->BeginFill();
    return pfill;
}

// @0x142932120
void AvmSprite::BeginFill(unsigned rgba)
{
    AcquirePath(true)->BeginSolidFill(rgba);
}

// @0x142937f90
void AvmSprite::CurveTo(float cx, float cy, float ax, float ay)
{
    DrawingContext* pdc = GetDrawingContext();
    pdc->CurveTo(Render::PixelsToTwips(cx), Render::PixelsToTwips(cy), Render::PixelsToTwips(ax),
                 Render::PixelsToTwips(ay));
    GetSprite()->InvalidateHitResult();
}

} // namespace AS2

inline MovieImpl::WideStringStorage::WideStringStorage(ASStringNode* pnode) : pNode(pnode)
{
    pNode->AddRef();
    UTF8Util::DecodeString(pData, pNode->pData, pNode->Size);
}

inline MovieImpl::WideStringStorage::~WideStringStorage()
{
    pNode->Release();
}

// The host's callback behind a function value (only the reference count is needed here).
class FunctionHandler : public RefCountBase<FunctionHandler, Stat_Default_Mem>
{
public:
    virtual ~FunctionHandler() {}
};

namespace AS2 {

// @0x14292dc70
void MovieRoot::ASValue2GFxValue(Environment* penv, const Value& v, GFx::Value* pdestVal) const
{
    typedef GFx::Value::ObjectInterface HostObjectInterface;

    // The host type: the one the host asked for, else the closest to the script type.
    int type;
    if (pdestVal->Type & GFx::Value::VTC_ConvertBit)
        type = pdestVal->Type & 0xf;
    else
    {
        switch (v.GetType())
        {
        case Value::UNDEFINED: type = GFx::Value::VT_Undefined; break;
        case Value::BOOLEAN:   type = GFx::Value::VT_Boolean; break;
        case Value::NULLTYPE:  type = GFx::Value::VT_Null; break;
        case Value::NUMBER:
        case Value::INTEGER:   type = GFx::Value::VT_Number; break;
        case Value::OBJECT:
        case Value::FUNCTION:  type = GFx::Value::VT_Object; break;
        case Value::CHARACTER: type = GFx::Value::VT_DisplayObject; break;
        default:               type = GFx::Value::VT_String; break;
        }
    }
    if (pdestVal->IsManagedValue())
        pdestVal->ReleaseManagedValue();

    switch (type)
    {
    case GFx::Value::VT_Undefined:
    case GFx::Value::VT_Null:
        pdestVal->Type = GFx::Value::ValueType(type);
        break;
    case GFx::Value::VT_Boolean:
        pdestVal->Type          = GFx::Value::VT_Boolean;
        pdestVal->mValue.BValue = v.ToBool(penv);
        break;
    case GFx::Value::VT_Int:
        pdestVal->Type          = GFx::Value::VT_Int;
        pdestVal->mValue.IValue = (SInt32)v.ToNumber(penv);
        break;
    case GFx::Value::VT_UInt:
        pdestVal->Type           = GFx::Value::VT_UInt;
        pdestVal->mValue.UIValue = (UInt32)v.ToNumber(penv);
        break;
    case GFx::Value::VT_Number:
        pdestVal->Type          = GFx::Value::VT_Number;
        pdestVal->mValue.NValue = v.ToNumber(penv);
        break;
    case GFx::Value::VT_String:
    {
        // The host shares the string node.
        ASString      str   = v.ToString(penv);
        ASStringNode* pnode = str.GetNode();
        pdestVal->mValue.pData      = pnode;
        pdestVal->Type              = GFx::Value::ValueType(GFx::Value::VT_String | GFx::Value::VTC_ManagedBit);
        pdestVal->pObjectInterface  = (HostObjectInterface*)pMovieImpl->pObjectInterface;
        ((HostObjectInterface*)pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, pnode);
        break;
    }
    case GFx::Value::VT_StringW:
    {
        // A wide copy, kept alive by the host's reference.
        ASString      str   = v.ToString(penv);
        ASStringNode* pnode = str.GetNode();
        unsigned      len   = str.GetLength();
        void*    pmem = pMovieImpl->GetMovieHeap()->Alloc(
            sizeof(MovieImpl::WideStringStorage) - 1 + sizeof(wchar_t) * (len + 1));
        pdestVal->Type = GFx::Value::ValueType(GFx::Value::VT_StringW | GFx::Value::VTC_ManagedBit);
        Ptr<MovieImpl::WideStringStorage> pwstr = *::new (pmem) MovieImpl::WideStringStorage(pnode);
        wchar_t* pdata = pwstr->pData;
        pdestVal->mValue.pStringW  = pdata;
        pdestVal->pObjectInterface = (HostObjectInterface*)pMovieImpl->pObjectInterface;
        ((HostObjectInterface*)pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, pdata);
        break;
    }
    case GFx::Value::VT_Object:
    {
        // Arrays keep their own host type.
        ObjectInterface*      pobj    = v.ToObjectInterface_Call(penv);
        GFx::Value::ValueType objType = GFx::Value::VT_Object;
        if (pobj->IsASObject() && pobj->ToASObject()->GetObjectType() == Object::Object_Array)
            objType = GFx::Value::VT_Array;
        pdestVal->mValue.pData     = pobj;
        pdestVal->Type             = GFx::Value::ValueType(objType | GFx::Value::VTC_ManagedBit);
        pdestVal->pObjectInterface = (HostObjectInterface*)pMovieImpl->pObjectInterface;
        ((HostObjectInterface*)pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, pobj);
        break;
    }
    case GFx::Value::VT_DisplayObject:
    {
        // Characters go by their handle.
        InteractiveObject* pch = v.ToObjectInterface_Call(penv)->ToCharacter_Call();
        pdestVal->Type = GFx::Value::ValueType(GFx::Value::VT_DisplayObject | GFx::Value::VTC_ManagedBit);
        CharacterHandle* phandle   = pch->GetCharacterHandle();
        pdestVal->mValue.pData     = phandle;
        pdestVal->pObjectInterface = (HostObjectInterface*)pMovieImpl->pObjectInterface;
        ((HostObjectInterface*)pMovieImpl->pObjectInterface)->ObjectAddRef(pdestVal, phandle);
        break;
    }
    default:;
    }
}

// The environment of _level0, through its AS2 character.
static inline Environment* GetLevel0Environment(MovieImpl* pmovieImpl)
{
    AvmDisplayObjBase* pavm = pmovieImpl->pMainMovie->GetAvmObjImpl();
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
}

// A queued AS2 load: the target clip or level and the objects to notify. 0xc8 bytes.
class GFxAS2LoadQueueEntry : public LoadQueueEntry
{
public:
    struct HolderType
    {
        Value             ASObj;
        Ptr<RefCountImpl> Loader;
    };

    int                  Level;                 // +0x28
    Ptr<CharacterHandle> pCharacter;            // +0x30
    Value                MovieClipLoaderHolder; // +0x38
    Value                LoadVarsHolder;        // +0x58
    HolderType           XMLHolder;             // +0x78
    HolderType           CSSHolder;             // +0xa0

    GFxAS2LoadQueueEntry(CharacterHandle* pchar, const String& url, LoadMethod method, bool loadingVars = false,
                         bool quietOpen = false)
        : LoadQueueEntry(url, method, loadingVars, quietOpen)
    {
        PConstruct(pchar, -1);
    }
    // A load into _level<level> (exe 0x14291c320).
    GFxAS2LoadQueueEntry(int level, const String& url, LoadMethod method, bool loadingVars = false,
                         bool quietOpen = false);

    void PConstruct(CharacterHandle* pchar, int level); // exe 0x14296e6c0
};

// MS2-FUNCTIONAL the exe inlines the LoadQueueEntry ctor (out of line elsewhere) into the clip entry
// @0x14292f740
void MovieRoot::AddLoadQueueEntry(InteractiveObject* ptarget, const char* purl, LoadQueueEntry::LoadMethod method,
                                  MovieClipLoader* pmovieClipLoader)
{
    if (!ptarget)
        return;
    GFxAS2LoadQueueEntry* pentry  = 0;
    int                   level   = -1;
    Sprite*               psprite = ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0;
    if (psprite && (level = static_cast<AvmSpriteBase&>(*AvmSprite::FromSprite(psprite)).GetLevel()) != -1)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) GFxAS2LoadQueueEntry(level, String(purl), method);
    else
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            GFxAS2LoadQueueEntry(ptarget->GetCharacterHandle(), String(purl), method);
    if (pentry)
    {
        pentry->MovieClipLoaderHolder.SetAsObject(pmovieClipLoader);
        AddMovieLoadQueueEntry(pentry);
    }
}

// MS2-FUNCTIONAL the exe inlines the LoadQueueEntry ctor (out of line elsewhere) into the clip entry
// @0x142930a10
void MovieRoot::AddVarLoadQueueEntry(InteractiveObject* ptarget, const char* purl, LoadQueueEntry::LoadMethod method)
{
    if (!ptarget)
        return;
    GFxAS2LoadQueueEntry* pentry  = 0;
    int                   level   = -1;
    Sprite*               psprite = ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0;
    if (psprite && (level = static_cast<AvmSpriteBase&>(*AvmSprite::FromSprite(psprite)).GetLevel()) != -1)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) GFxAS2LoadQueueEntry(level, String(purl), method, true);
    else
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            GFxAS2LoadQueueEntry(ptarget->GetCharacterHandle(), String(purl), method, true);
    if (pentry)
    {
        if (Ptr<State>(*pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager)))
            AddLoadQueueEntryMT(pentry);
        else
            pMovieImpl->AddLoadQueueEntry(pentry);
    }
}

// MS2-FUNCTIONAL regalloc/stack layout (exe reloads pDispObj per call, 0x100 frame)
// @0x142934610
InteractiveObject* AvmCharacter::CloneDisplayObject(const ASString& newname, int depth, const ObjectInterface* psource)
{
    InteractiveObject* pparent = GetDispObj()->GetParent();
    Sprite*            psprite = pparent->IsSprite() ? static_cast<Sprite*>(pparent) : 0;
    if (!psprite || depth < 0 || depth > 0x7efffffd)
        return 0;
    CharPosInfo pos(ResourceId(GetDispObj()->Id), depth, 1, GetDispObj()->GetCxform(), 1, GetDispObj()->GetMatrix(),
                    0, GetDispObj()->GetRatio(), GetDispObj()->ClipDepth);
    DisplayObjectBase* pnewch = psprite->AddDisplayObject(pos, newname, 0, psource, ~0u, 1, 0, GetDispObj());
    return (pnewch && pnewch->IsInteractiveObject()) ? static_cast<InteractiveObject*>(pnewch) : 0;
}

// MS2-FUNCTIONAL regalloc: the exe loads the string manager through r9, not rcx
// @0x142937d60
void MovieRoot::CreateString(GFx::Value* pvalue, const char* pstring)
{
    Environment* penv = GetLevel0Environment(pMovieImpl);
    ASString     str  = penv->CreateString(pstring);
    ASValue2GFxValue(penv, Value(str), pvalue);
}

// MS2-FUNCTIONAL regalloc: the exe loads the string manager through r9, not rcx
// @0x142937ea0
void MovieRoot::CreateStringW(GFx::Value* pvalue, const wchar_t* pstring)
{
    Environment* penv = GetLevel0Environment(pMovieImpl);
    ASString     str  = penv->GetSC()->CreateString(pstring);
    pvalue->SetConvertStringW();
    ASValue2GFxValue(penv, Value(str), pvalue);
}

// @0x1429381f0
void LoadVarsProto::DefaultOnData(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, LoadVars);
    LoadVarsObject* pobj = static_cast<LoadVarsObject*>(fn.ThisPtr);
    String src(fn.Arg(0).ToString(fn.Env).ToCStr());
    ASString data = fn.Arg(0).ToString(fn.Env);
    String   str(data.ToCStr());
    bool         loaded = LoadVariables(fn.Env, pobj, str);
    Environment* penv   = fn.Env;
    penv->Push(loaded);
    AsBroadcaster::BroadcastMessage(penv, pobj, penv->CreateConstString("onLoad"), 1, penv->GetTopIndex());
    penv->Drop1();
}

// A number value, or a string that parses as a whole as one (+, -, . or a digit first).
static SF_FORCEINLINE bool ArraySortGetNumber(const Value* pval, Environment* penv, Number* pnum)
{
    if (pval->IsNumber())
    {
        *pnum = pval->ToNumber(penv);
        return true;
    }
    ASString    str = pval->ToString(penv);
    const char* p   = str.ToCStr();
    if (p && ((*p >= '0' && *p <= '9') || *p == '+' || *p == '-' || *p == '.'))
    {
        char* tail = 0;
        *pnum      = Scaleform::SFstrtod(p, &tail);
        if (!tail || !*tail)
            return true;
    }
    return false;
}

// @0x142934a80
int ArraySortFunctor::Compare(const Value* a, const Value* b) const
{
    Value        undefined;
    const Value* pa = a ? a : &undefined;
    const Value* pb = b ? b : &undefined;
    if (!Func.IsNull())
    {
        // The script function: compare(a, b).
        Value result;
        Env->Push(*pb);
        Env->Push(*pa);
        FnCall fn(&result, This, Env, 2, Env->GetTopIndex());
        Func.Invoke(fn);
        Env->Drop(2);
        if (!fn.Result)
            return 0;
        int ret = fn.Result->ToInt32(Env);
        return (Flags & ArrayObject::SortFlags_Descending) ? -ret : ret;
    }
    if (Flags & ArrayObject::SortFlags_Numeric)
    {
        Number na = 0, nb = 0;
        bool   aIsNum = ArraySortGetNumber(pa, Env, &na);
        bool   bIsNum = ArraySortGetNumber(pb, Env, &nb);
        if (aIsNum && bIsNum)
        {
            int ret = 0;
            if (nb > na)
                ret = -1;
            if (na > nb)
                ret = 1;
            return (Flags & ArrayObject::SortFlags_Descending) ? -ret : ret;
        }
    }
    ASString sa = pa->ToString(Env);
    ASString sb = pb->ToString(Env);
    int      ret;
    if (Flags & ArrayObject::SortFlags_Locale)
        ret = sa.LocaleCompare_CaseCheck(sb.ToCStr(), sb.GetLength(),
                                         !(Flags & ArrayObject::SortFlags_CaseInsensitive));
    else if (Flags & ArrayObject::SortFlags_CaseInsensitive)
        ret = String::CompareNoCase(sa.ToCStr(), sb.ToCStr());
    else
        ret = strcmp(sa.ToCStr(), sb.ToCStr());
    return (Flags & ArrayObject::SortFlags_Descending) ? -ret : ret;
}

// The object of a value, the script object of a character included (Value::ToObjectInterface with the character
// lookup expanded, as the exe has it here).
static SF_FORCEINLINE ObjectInterface* ArraySortToObject(const Value* pval, const Environment* penv)
{
    if (pval->GetType() == Value::CHARACTER)
    {
        InteractiveObject* pchar = 0;
        if (penv && pval->V.pCharHandle)
        {
            DisplayObject* pdisp = pval->V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
            if (pdisp)
                pchar = pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
        }
        return pchar ? ToAvmCharacter(pchar) : 0;
    }
    return pval->ToObject(penv);
}

// MS2-FUNCTIONAL the exe drops the dtor of the undefined fallback value (and saves other registers)
// @0x142934f90
int ArraySortOnFunctor::Compare(const Value* a, const Value* b) const
{
    const Value      undefined;
    const Value*     pa  = a ? a : &undefined;
    const Value*     pb  = b ? b : &undefined;
    ASStringContext* psc = Env->GetSC();
    // The first field the two objects differ in decides.
    for (unsigned i = 0; i < FunctorArray.GetSize(); i++)
    {
        ObjectInterface* pobjA = ArraySortToObject(pa, Env);
        ObjectInterface* pobjB = ArraySortToObject(pb, Env);
        if (!pobjA || !pobjB)
            continue;
        const ASString& field = (*FieldArray)[i];
        Value           va, vb;
        if (pobjA->GetMemberRaw(psc, field, &va) && pobjB->GetMemberRaw(psc, field, &vb))
        {
            int ret = FunctorArray[i].Compare(&va, &vb);
            if (ret)
                return ret;
        }
    }
    return 0;
}

// MS2-FUNCTIONAL regalloc: the exe loads the global context through r9, not rdx
// @0x142935dc0
void MovieRoot::CreateArray(GFx::Value* pvalue)
{
    Environment* penv = GetLevel0Environment(pMovieImpl);
    Ptr<Object>  pobj = *penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Array));
    Value        val(pobj);
    ASValue2GFxValue(penv, val, pvalue);
}

// The script object of pfilter's type (new flash.filters.<class>) with the base state of pfilter; 0 for the types
// without a class.
// @0x1429362c0
Object* CreateFilterObject(Environment* penv, const Render::Filter* pfilter)
{
    int className;
    switch (pfilter->GetFilterType())
    {
    case Render::Filter_Blur:        className = ASBuiltin_BlurFilter; break;
    case Render::Filter_Shadow:      className = ASBuiltin_DropShadowFilter; break;
    case Render::Filter_Glow:        className = ASBuiltin_GlowFilter; break;
    case Render::Filter_Bevel:       className = ASBuiltin_BevelFilter; break;
    case Render::Filter_ColorMatrix: className = ASBuiltin_ColorMatrixFilter; break;
    default:
        return 0;
    }
    BitmapFilterObject* pobj = static_cast<BitmapFilterObject*>(
        penv->OperatorNew(penv->GetSC()->pContext->FlashFiltersPackage, penv->GetBuiltin(className)));
    if (pobj)
        *pobj->GetFilter() = *pfilter;
    return pobj;
}

// MS2-FUNCTIONAL regalloc: the exe keeps the zero / result in rdi and the data def in rbx (swapped)
// @0x1429360e0
Sprite* MovieRoot::CreateEmptyLevelMovie(LoadStates* pls, int level)
{
    Sprite* psprite = 0;
    ResourceKey key = MovieDataDef::CreateMovieFileKey("", 0, 0, 0, 0);
    MemoryHeap* pheap = pMovieImpl->GetMovieHeap();
    Ptr<MovieDataDef> pdataDef =
        *SF_HEAP_NEW(pheap ? pheap : Memory::GetGlobalHeap()) MovieDataDef(key, MovieDataDef::MT_Empty, "", pheap);
    if (pdataDef)
    {
        pdataDef->InitEmptyMovieDef();
        pls->SetRelativePathForDataDef(pdataDef);
        Ptr<MovieDefImpl> pdefImpl = *SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            MovieDefImpl(pdataDef, pls->pBindStates, pls->pLoaderImpl, 0, pMovieImpl->pStateBag->GetDelegate(),
                         pMovieImpl->GetMovieHeap(), true);
        if (pdefImpl)
        {
            CharacterCreateInfo ccinfo;
            ccinfo.pCharDef     = pdataDef;
            ccinfo.pBindDefImpl = pdefImpl;
            ccinfo.pResource    = 0;
            psprite = static_cast<Sprite*>(pASSupport->CreateCharacterInstance(
                pMovieImpl, ccinfo, 0, ResourceId(), CharacterDef::Sprite));
            psprite->SetLoadedSeparately();
            AvmSprite::FromSprite(psprite)->SetLevel(level);
            pMovieImpl->SetLevelMovie(level, psprite);
        }
    }
    return psprite;
}

// Function object around a host FunctionHandler (sfr_as2_06 calls it). 0x78 bytes. Its deleting dtor (exe
// 0x14292da40) is functional only: the exe inlines ~FunctionObject, defined out of line in sfr_as2_03.
class UserDefinedFunctionObject : public FunctionObject
{
protected:
    Ptr<FunctionHandler> pContext;  // +0x68
    void*                pUserData; // +0x70

    virtual void Finalize_GC()
    {
        pContext.Clear();
        Object::Finalize_GC();
    }

public:
    UserDefinedFunctionObject(ASStringContext* psc, FunctionHandler* pfc, void* puserData)
        : FunctionObject(psc), pContext(pfc), pUserData(puserData)
    {
        Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Function));
    }

    virtual Environment* GetEnvironment(const FnCall& fn, Ptr<InteractiveObject>*) { return fn.Env; }
    virtual void         Invoke(const FnCall& fn, LocalFrame*, const char*); // exe 0x142963aa0 (sfr_as2_06)
    virtual bool         IsNull() const { return !pContext; }
    virtual bool         IsEqual(const FunctionObject&) const { return false; }
    virtual int          GetNumArgs() const { return -1; }
};

// @0x142936360
void MovieRoot::CreateFunction(GFx::Value* pvalue, FunctionHandler* pfc, void* puserData)
{
    Environment* penv = GetLevel0Environment(pMovieImpl);
    Value        val;
    Ptr<FunctionObject> pfunc =
        *SF_HEAP_NEW(penv->GetHeap()) UserDefinedFunctionObject(penv->GetSC(), pfc, puserData);
    {
        FunctionRef fref(pfunc);
        val.DropRefs();
        val.T.Type = Value::FUNCTION;
        val.V.FunctionValue.Init(fref);
    }
    ASValue2GFxValue(penv, val, pvalue);
}

// @0x14292e650
void AvmSprite::AddActionBuffer(ActionBuffer* pbuffer, ActionPriority::Priority prio)
{
    MovieRoot::ActionEntry* pe = GetAS2Root()->InsertEmptyAction(prio);
    if (pe)
    {
        InteractiveObject* pchar = pDispObj;
        pe->Type          = MovieRoot::ActionEntry::Entry_Buffer;
        pe->pCharacter    = pchar;
        pe->pActionBuffer = pbuffer;
        pe->mEventId.Id   = EventId::Event_Invalid;
    }
}

// The exe's out-of-line event handler table assignment (defined in sfr_as2_03).
void FUN_142926340(HashLH<EventId, ArrayLH<Value, StatMV_ActionScript_Mem>, EventIdHashFunctor, StatMV_ActionScript_Mem>* pthis,
                   const HashLH<EventId, ArrayLH<Value, StatMV_ActionScript_Mem>, EventIdHashFunctor, StatMV_ActionScript_Mem>& src);

// The script side of a button (only the clone hooks so far).
class AvmButton : public AvmCharacter
{
public:
    virtual void CloneInternalData(const InteractiveObject* src);
    virtual void CopyPhysicalProperties(const InteractiveObject* poldChar);
};

// The event handlers of src's script side replace this one's.
inline void CopyEventHandlers(AvmCharacter* pthis, const InteractiveObject* src)
{
    const AvmCharacter* psrc = !src ? 0 : static_cast<const AvmCharacter*>(src->GetAvmIntObj());
    FUN_142926340(&pthis->EventHandlers, psrc->EventHandlers);
}

// @0x142934820
void AvmButton::CloneInternalData(const InteractiveObject* src)
{
    CopyEventHandlers(this, src);
}

// @0x142934870
void AvmCharacter::CloneInternalData(const InteractiveObject* src)
{
    CopyEventHandlers(this, src);
}

// @0x1429348c0
void AvmSprite::CloneInternalData(const InteractiveObject* src)
{
    const AvmCharacter* psrc = !src ? 0 : static_cast<const AvmCharacter*>(src->GetAvmIntObj());
    FUN_142926340(&EventHandlers, psrc->EventHandlers);
    if (src->IsSprite() && src->HasAvmObject() && src->GetAvmIntObj()->ActsAsButton())
    {
        MovieClipObject* pobj = GetMovieClipObject();
        if (pobj)
            pobj->HasButtonHandlers = true;
    }
}

// @0x142934950
void AvmTextField::CloneInternalData(const InteractiveObject* src)
{
    CopyEventHandlers(this, src);
}

// @0x142935c70
void AvmButton::CopyPhysicalProperties(const InteractiveObject* poldChar)
{
    CopyEventHandlers(this, poldChar);
}

// @0x142935cc0
void AvmCharacter::CopyPhysicalProperties(const InteractiveObject* poldChar)
{
    CopyEventHandlers(this, poldChar);
}

// @0x142935d10
void AvmSprite::CopyPhysicalProperties(const InteractiveObject* poldChar)
{
    CopyEventHandlers(this, poldChar);
}

// @0x142935d60
void AvmTextField::CopyPhysicalProperties(const InteractiveObject* poldChar)
{
    CopyEventHandlers(this, poldChar);
}

// A name that may spell a standard member: flagged so, or "_..." whose lowercase twin is flagged.
static inline bool MayBeStandardMember(const ASString& name)
{
    if ((name.GetHashFlags() >> 29) & 1)
        return true;
    if (name.GetLength() != 0 && name.GetCharAt(0) == '_')
    {
        ASString lower(name.ToLowerNode());
        if ((lower.GetHashFlags() >> 28) & 1)
            return true;
    }
    return false;
}

// @0x142956060
unsigned AvmCharacter::GetStandardMemberBitMask() const
{
    return 0;
}

// A standard property only resets the clip's setting (useHandCursor); other names go to the AS object.
// MS2-FUNCTIONAL the exe tests the string flags with shr/and byte and orders the member branches differently
// @0x1429386e0
SF_NOINLINE bool AvmCharacter::DeleteMember(ASStringContext* psc, const ASString& name)
{
    if (MayBeStandardMember(name))
    {
        StandardMember member = GetStandardMemberConstant(name);
        if (member != M_InvalidMember && member <= M_LastBitMaskMember &&
            (GetStandardMemberBitMask() & (1u << member)))
        {
            switch (member)
            {
            case M_useHandCursor:
                pDispObj->Flags &= ~InteractiveObject::Mask_UseHandCursor;
                return true;
            default:
                return false;
            }
        }
    }
    Ptr<Object> obj = GetASObject();
    return obj ? obj->DeleteMember(psc, name) : false;
}
}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The host side of AS2 values (GFx::Value object calls); only the members recovered so far.
class AS2ValueObjectInterface : public Value::ObjectInterface
{
private:
    virtual bool CreateEmptyMovieClip(void* pdata, Value* pmc, const char* instanceName, SInt32 depth);
};

// A new empty clip in the clip pdata (a free depth above the used ones when depth is negative); *pmc gets it.
// @0x142935ea0
bool AS2ValueObjectInterface::CreateEmptyMovieClip(void* pdata, Value* pmc, const char* instanceName, SInt32 depth)
{
    DisplayObject* pchar = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pchar || !pchar->IsSprite())
        return false;
    AS2::MovieRoot*   proot   = static_cast<AS2::MovieRoot*>(pMovieRoot->pASMovieRoot);
    AS2::Environment* penv    = AS2::GetLevel0Environment(proot->pMovieImpl);
    Sprite*           psprite = static_cast<Sprite*>(pchar);
    if (depth < 0)
    {
        depth = psprite->mDisplayList.GetLargestDepthInUse() - 16383;
        if (depth < 0)
            depth = 0;
    }
    CharPosInfo pos(ResourceId(ResourceId::IdType_InternalConstant | 1), depth + 16384, 1, Render::Cxform::Identity,
                    1, Render::Matrix2F::Identity);
    if (pos.Depth < 0 || pos.Depth > 0x7efffffd)
        return false;
    Ptr<DisplayObjectBase> newch = psprite->AddDisplayObject(pos, penv->CreateString(instanceName), 0, 0, ~0u, 1, 0, 0);
    if (newch)
    {
        newch->SetAcceptAnimMoves(false);
        AS2::Value val(static_cast<InteractiveObject*>(newch.GetPtr()));
        proot->ASValue2GFxValue(penv, val, pmc);
    }
    return true;
}

}} // namespace Scaleform::GFx

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
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7ButtonObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143217c48
// MS2-PIN: ??_7ButtonObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217c90
// MS2-PIN: ??_7MovieClipObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216640
// MS2-PIN: ??_7MovieClipObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216688
// MS2-PIN: ??_7WideStringStorage@MovieImpl@GFx@Scaleform@@6B@ 0x14317ca48
// MS2-PIN: ??_7?$RefCountBase@VWideStringStorage@MovieImpl@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x14318ccd8
// MS2-PIN: ??_7SizeVisitor@?1??ComputeSizeInBytes@SharedObject@AS2@GFx@Scaleform@@QEAA_KPEAVEnvironment@345@@Z@6B@ 0x1432227e8
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7UserDefinedFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143221ff8
// MS2-PIN: ??_7UserDefinedFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143222080
// MS2-PIN: ??_GUserDefinedFunctionObject@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14292da40
// MS2-PIN: ??_7LoadQueueEntry@GFx@Scaleform@@6B@ 0x14317c9d8
// MS2-PIN: ??_7GFxAS2LoadQueueEntry@AS2@GFx@Scaleform@@6B@ 0x143217748
