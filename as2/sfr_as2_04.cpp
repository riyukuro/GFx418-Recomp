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
// MS2-RANGE: 0x1429343e0-0x1429343e5 .text$mn
// MS2-RANGE: 0x1429345c0-0x1429345c3 .text$mn
// MS2-RANGE: 0x1429345d0-0x142934610 .text$mn
// MS2-RANGE: 0x142934a00-0x142934a80 .text$mn
// MS2-RANGE: 0x142935200-0x142935680 .text$mn
// MS2-RANGE: 0x142935680-0x142935820 .text$mn
// MS2-RANGE: 0x142935b50-0x142935dc0 .text$mn
// MS2-RANGE: 0x142936620-0x142936680 .text$mn
// MS2-RANGE: 0x142936790-0x1429367a0 .text$mn
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
// MS2-RANGE: 0x14296e6c0-0x14296e731 .text$mn
// MS2-RANGE: 0x14291c320-0x14291c3fb .text$mn
// MS2-RANGE: 0x142937bc0-0x142937c98 .text$mn
// MS2-RANGE: 0x142901280-0x142901406 .text$mn   (SharedObjectProto::GetSize, from sfr_as2_02)
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

// The node dtor is declared, so the FunctionRef node one can be kept out of line below.
#define MS2_SF_HASHNODE_DTOR
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
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_value.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/kernel/sf_std.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_loadqueueentry.h"
#include "../include/gfx/as2/as2_intervaltimer.h"
#include "../include/gfx/gfx_assupport.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_stringhash.h"
#include "../include/render/render_twips.h"
#include "../include/gfx/as2/as2_hashaccess.h"
#include "../include/gfx/text_stylesheet.h" // Text::StyleManager complete: StyleSheetObject's implicit destructor calls ~StyleManager

// The object stack's PushBack stays out of line (0x142971a50).
namespace Scaleform {
template<> SF_NOINLINE void ArrayData<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::PushBack(
    GFx::AS2::Object* const& val);
// The event handler hash's Clear calls the Value array destructor out of line (0x142924420, sfr_as2_03).
template<> ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, 323>, ArrayDefaultPolicy>::~ArrayDataBase();
// The FunctionRef set's Clear calls the node dtor out of line (0x142924490, sfr_as2_03).
template<> inline SF_NOINLINE HashNode<GFx::ASString, GFx::AS2::FunctionRef, GFx::ASStringHashFunctor>::~HashNode() {}
}

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

// MS2-FUNCTIONAL: LTCG keeps the pv1/pv2 type bytes in sil/r14b across the ToString/ToNumber calls and reuses them in
// the Value dtors (our cl reloads them), and the two ToPrimitive results sit in swapped frame slots
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

    Number val1, val2;
    if (action < 0)
    {
        val1 = pv1.ToNumber(penv);
        val2 = pv2.ToNumber(penv);
    }
    else
    {
        val2 = pv1.ToNumber(penv);
        val1 = pv2.ToNumber(penv);
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
                (reinterpret_cast<TryBlocksData*>(&TryBlocks)->*&TryBlocksData::Resize)(TryBlocks.GetSize() - 1);
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

// AmpMarker is not constructible.
// @0x142936790
Object* AmpMarkerCtorFunction::CreateNewObject(Environment*) const
{
    return 0;
}

// @0x1429367a0
Object* ArrayCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ArrayObject(penv);
}

// The exe inlines the AsBroadcaster ctor here.
inline AsBroadcaster::AsBroadcaster(Environment* penv, ObjectInlineCtorTag)
    : Object(penv)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_AsBroadcaster));
}

// @0x1429367e0
Object* AsBroadcasterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) AsBroadcaster(penv, ObjectInlineCtorTag());
}

// @0x142936880
Object* AsFunctionObject::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) Object(penv);
}

// @0x1429368c0
Object* BevelFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) BevelFilterObject(penv, ObjectInlineCtorTag());
}

// "new BitmapData" without arguments makes no object.
// @0x142936930
Object* BitmapDataCtorFunction::CreateNewObject(Environment*) const
{
    return 0;
}

// @0x142936940
Object* BlurFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) BlurFilterObject(penv, ObjectInlineCtorTag());
}

// The exe inlines the BooleanObject ctor here.
inline BooleanObject::BooleanObject(Environment* penv, ObjectInlineCtorTag)
    : Object(penv), BValue(false)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Boolean));
}

// @0x1429369b0
Object* BooleanCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) BooleanObject(penv, ObjectInlineCtorTag());
}

// @0x142936a50
Object* ButtonCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ButtonObject(penv);
}

// The exe inlines the ColorObject ctor here.
inline ColorObject::ColorObject(Environment* penv, InteractiveObject* ptarget, ObjectInlineCtorTag)
    : Object(penv), pCharacter(ptarget)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Color));
}

// @0x142936b10
Object* ColorCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ColorObject(penv, 0, ObjectInlineCtorTag());
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

// @0x142936c80
Object* DropShadowFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) DropShadowFilterObject(penv, ObjectInlineCtorTag());
}

// The exe inlines the ExternalInterface ctor here.
inline ExternalInterface::ExternalInterface(Environment* penv, ObjectInlineCtorTag)
    : Object(penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_ExternalInterface));
}

// @0x142936cf0
Object* ExternalInterfaceCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) ExternalInterface(penv, ObjectInlineCtorTag());
}

// The exe inlines the CFunctionObject ctor, and its FunctionObject base ctor, here.
inline FunctionObject::FunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : Object(psc)
{
}

inline CFunctionObject::CFunctionObject(ASStringContext* psc, ObjectInlineCtorTag)
    : FunctionObject(psc, ObjectInlineCtorTag()), pFunction(0)
{
}

// @0x142936d90
Object* FunctionCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) CFunctionObject(penv->GetSC(), ObjectInlineCtorTag());
}

// @0x142936e00
Object* FunctionObject::CreateNewObject(Environment*) const
{
    return 0;
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

// @0x142936e90
Object* GlowFilterCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) GlowFilterObject(penv, ObjectInlineCtorTag());
}

// @0x142936f30
Object* MovieClipCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) MovieClipObject(penv);
}

// The exe inlines the MovieClipLoader ctor here.
inline MovieClipLoader::MovieClipLoader(Environment* penv, ObjectInlineCtorTag)
    : Object(penv)
{
    ASStringContext* psc = penv->GetSC();
    static_cast<ObjectInterface*>(this)->Set__proto__(psc, penv->GetPrototype(ASBuiltin_MovieClipLoader));
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
}

// @0x142936ff0
Object* MovieClipLoaderCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) MovieClipLoader(penv, ObjectInlineCtorTag());
}

// The exe inlines the NumberObject ctor here.
inline NumberObject::NumberObject(Environment* penv, ObjectInlineCtorTag)
    : Object(penv), NumberValue(0)
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Number));
}

// @0x1429370c0
Object* NumberCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) NumberObject(penv, ObjectInlineCtorTag());
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

// The exe inlines the StringObject ctor here.
inline StringObject::StringObject(Environment* penv, ObjectInlineCtorTag)
    : Object(penv), sValue(penv->GetBuiltin(ASBuiltin_empty_))
{
    static_cast<ObjectInterface*>(this)->Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_String));
}

// @0x142937290
Object* StringCtorFunction::CreateNewObject(Environment* penv) const
{
    StringObject* pobj = SF_HEAP_NEW(penv->GetHeap()) StringObject(penv, ObjectInlineCtorTag());
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

// The exe inlines the TextFieldObject ctor here.
inline TextFieldObject::TextFieldObject(Environment* penv, ObjectInlineCtorTag)
    : Object(penv), pIMECompositionStringStyles(0)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_TextField));
}

// @0x1429373c0
Object* TextFieldCtorFunction::CreateNewObject(Environment* penv) const
{
    return SF_HEAP_NEW(penv->GetHeap()) TextFieldObject(penv, ObjectInlineCtorTag());
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
    (reinterpret_cast<ArrayData<Object*, AllocatorGH<Object*, 2>, ArrayDefaultPolicy>*>(&ObjectStack)->*&ArrayData<Object*, AllocatorGH<Object*, 2>, ArrayDefaultPolicy>::Resize)(0);
    ObjectStack.PushBack(pData);
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

// SharedObject.getSize() (from sfr_as2_02: in the exe it inlines ComputeSizeInBytes, so it shares its TU)
// @0x142901280
void SharedObjectProto::GetSize(const FnCall& fn)
{
    MS2_AS2_CHECK_THIS(fn, SharedObject);
    SharedObject* pthis = static_cast<SharedObject*>(fn.ThisPtr);
    if (!pthis)
        return;
    fn.Result->SetInt((int)pthis->ComputeSizeInBytes(fn.Env));
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
MS2_AS2_HASH_FINDINDEX(Value)

typedef ASStringHash_GC<Value>::SetType ValueSet;

// FindAlt / Find / FindCaseInsensitive / FindCaseCheck of the local variable table.
template <class K>
static SF_FORCEINLINE ValueSet::Iterator ValueHash_FindAlt(ASStringHash_GC<Value>* phash, const K& key)
{
    SPInt index = HashFindIndex(phash, key);
    if (index >= 0)
        return ValueSet::Iterator(reinterpret_cast<ValueSet*>(phash), index);
    return ValueSet::Iterator(0, 0);
}
static SF_FORCEINLINE ValueSet::Iterator ValueHash_Find(ASStringHash_GC<Value>* phash, const ASString& key)
{
    return ValueHash_FindAlt(phash, key);
}
static SF_FORCEINLINE ValueSet::Iterator ValueHash_FindNoCase(ASStringHash_GC<Value>* phash, const ASString& key)
{
    ASStringNoCaseKey ikey(key);
    return ValueHash_FindAlt(phash, ikey);
}
static SF_FORCEINLINE ValueSet::Iterator ValueHash_FindCaseCheck(ASStringHash_GC<Value>* phash, const ASString& key,
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
SF_NOINLINE void MovieRoot::ActionQueueType::AddToFreeList(ActionEntry* pentry)
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

// The host's callback behind a function value: FunctionHandler (gfx_asimemanager.h).

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

// @0x14296e6c0
void GFxAS2LoadQueueEntry::PConstruct(CharacterHandle* pchar, int level)
{
    pCharacter = pchar;
    Level      = level;
}

// @0x14291c320
GFxAS2LoadQueueEntry::GFxAS2LoadQueueEntry(int level, const String& url, LoadMethod method, bool loadingVars,
                                           bool quietOpen)
    : LoadQueueEntry(url, method, loadingVars, quietOpen)
{
    PConstruct(0, level);
    Type = LoadType((loadingVars ? LT_LoadText : (url.ToCStr() ? LT_LoadMovie : LT_UnloadMovie)) | LTF_LevelFlag);
}

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
        ptarget = 0;
    if (ptarget)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            GFxAS2LoadQueueEntry(ptarget->GetCharacterHandle(), purl, method, false, false, LoadQueueEntry::InlineCtorTag());
    else if (level != -1)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) GFxAS2LoadQueueEntry(level, purl, method);
    if (pentry)
    {
        pentry->MovieClipLoaderHolder.SetAsObject(pmovieClipLoader);
        AddMovieLoadQueueEntry(pentry);
    }
}

// @0x142930a10
void MovieRoot::AddVarLoadQueueEntry(InteractiveObject* ptarget, const char* purl, LoadQueueEntry::LoadMethod method)
{
    if (!ptarget)
        return;
    GFxAS2LoadQueueEntry* pentry  = 0;
    int                   level   = -1;
    Sprite*               psprite = ptarget->IsSprite() ? static_cast<Sprite*>(ptarget) : 0;
    if (psprite && (level = static_cast<AvmSpriteBase&>(*AvmSprite::FromSprite(psprite)).GetLevel()) != -1)
        ptarget = 0;
    if (ptarget)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            GFxAS2LoadQueueEntry(ptarget->GetCharacterHandle(), purl, method, true, false, LoadQueueEntry::InlineCtorTag());
    else if (level != -1)
        pentry = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) GFxAS2LoadQueueEntry(level, purl, method, true);
    if (pentry)
    {
        if (Ptr<State>(*pMovieImpl->GetStateBag()->GetStateAddRef(State::State_TaskManager)))
            AddLoadQueueEntryMT(pentry);
        else
            pMovieImpl->AddLoadQueueEntry(pentry);
    }
}

// @0x142934610
InteractiveObject* AvmCharacter::CloneDisplayObject(const ASString& newname, int depth, const ObjectInterface* psource)
{
    InteractiveObject* pparent = pDispObj->GetParent();
    Sprite*            psprite = pparent->IsSprite() ? static_cast<Sprite*>(pparent) : 0;
    if (!psprite)
        return 0;
    if (depth < 0 || depth > 0x7efffffd)
        return 0;
    CharPosInfo pos(ResourceId(pDispObj->Id), depth, 1, pDispObj->GetCxform(), 1, pDispObj->GetMatrix(), 0,
                    pDispObj->GetRatio(), pDispObj->ClipDepth);
    DisplayObjectBase* pnewch = psprite->AddDisplayObject(pos, newname, 0, psource, ~0u, 1, 0, pDispObj);
    if (pnewch)
        return pnewch->IsInteractiveObject() ? static_cast<InteractiveObject*>(pnewch) : 0;
    return 0;
}

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

// The leading-character test and strtod of the SDK's GAS_ParseNumber.
static SF_FORCEINLINE bool ArraySortParseNumber(const char* str, Number* retVal)
{
    if (str && *str)
    {
        if ((*str >= '0' && *str <= '9') || *str == '+' || *str == '-' || *str == '.')
        {
            char* end;
            *retVal = (Number)Scaleform::SFstrtod(str, &end);
            if (end == 0 || *end == 0)
                return true;
        }
    }
    return false;
}

// @0x142934a80
int ArraySortFunctor::Compare(const Value* a, const Value* b) const
{
    Value dummy;
    if (a == 0)
        a = &dummy;
    if (b == 0)
        b = &dummy;
    int cmpVal = 0;
    if (!Func.IsNull())
    {
        Value retVal;
        Env->Push(*b);
        Env->Push(*a);
        FnCall fn(&retVal, This, Env, 2, Env->GetTopIndex());
        Func.Invoke(fn);
        Env->Drop(2);
        if (fn.Result)
        {
            cmpVal = fn.Result->ToInt32(Env);
            return (Flags & ArrayObject::SortFlags_Descending) ? -cmpVal : cmpVal;
        }
    }
    else
    {
        bool   numericA = false;
        bool   numericB = false;
        Number valA     = 0;
        Number valB     = 0;
        if (Flags & ArrayObject::SortFlags_Numeric)
        {
            if (a->IsNumber())
            {
                valA     = a->ToNumber(Env);
                numericA = true;
            }
            else
            {
                ASString sa(a->ToString(Env));
                numericA = ArraySortParseNumber(sa.ToCStr(), &valA);
            }
            if (b->IsNumber())
            {
                valB     = b->ToNumber(Env);
                numericB = true;
            }
            else
            {
                ASString sb(b->ToString(Env));
                numericB = ArraySortParseNumber(sb.ToCStr(), &valB);
            }
        }
        if (numericA && numericB)
        {
            if (valA < valB)
                cmpVal = -1;
            if (valB < valA)
                cmpVal = 1;
            return (Flags & ArrayObject::SortFlags_Descending) ? -cmpVal : cmpVal;
        }
        else
        {
            ASString sa(a->ToString(Env));
            ASString sb(b->ToString(Env));
            if (Flags & ArrayObject::SortFlags_Locale)
                cmpVal = sa.LocaleCompare_CaseCheck(sb.ToCStr(), sb.GetLength(),
                                                    (Flags & ArrayObject::SortFlags_CaseInsensitive) == 0);
            else
                cmpVal = (Flags & ArrayObject::SortFlags_CaseInsensitive) ? String::CompareNoCase(sa.ToCStr(), sb.ToCStr())
                                                                           : strcmp(sa.ToCStr(), sb.ToCStr());
            return (Flags & ArrayObject::SortFlags_Descending) ? -cmpVal : cmpVal;
        }
    }
    return 0;
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

// The storage of an undefined Value without a destructor (the exe destroys no fallback value in
// ArraySortOnFunctor::Compare). The members are private so that /GS does not take it for a buffer.
class ArraySortUndefined
{
    UByte  Type;
    UInt64 V, V1, V2;
public:
    void         SetUndefined() { Type = Value::UNDEFINED; }
    const Value* Get() const { return reinterpret_cast<const Value*>(this); }
};

// MS2-FUNCTIONAL regalloc: the exe returns 0 through its zero register (mov eax,ebp), ours xor eax,eax
// @0x142934f90
int ArraySortOnFunctor::Compare(const Value* a, const Value* b) const
{
    // The undefined value (Value::Value() sets only the type), kept without a destructor as in the exe.
    ArraySortUndefined dummy;
    dummy.SetUndefined();
    if (a == 0)
        a = dummy.Get();
    if (b == 0)
        b = dummy.Get();
    int              cmpVal = 0;
    unsigned         i;
    ASStringContext* psc = Env->GetSC();
    // The first field the two objects differ in decides.
    for (i = 0; i < FunctorArray.GetSize(); i++)
    {
        ObjectInterface* objA = ArraySortToObject(a, Env);
        ObjectInterface* objB = ArraySortToObject(b, Env);
        if (objA && objB)
        {
            Value           valA;
            Value           valB;
            const ASString& fieldName = (*FieldArray)[i];
            if (objA->GetMemberRaw(psc, fieldName, &valA) && objB->GetMemberRaw(psc, fieldName, &valB))
            {
                cmpVal = FunctorArray[i].Compare(&valA, &valB);
                if (cmpVal)
                    return cmpVal;
            }
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

// @0x1429360e0
Sprite* MovieRoot::CreateEmptyLevelMovie(LoadStates* pls, int level)
{
    ResourceKey key = MovieDataDef::CreateMovieFileKey("", 0, 0, 0, 0);
    MemoryHeap* pheap = pMovieImpl->GetMovieHeap();
    Ptr<MovieDataDef> pdataDef =
        *SF_HEAP_NEW(pheap ? pheap : Memory::GetGlobalHeap()) MovieDataDef(key, MovieDataDef::MT_Empty, "", pheap);
    Ptr<MovieDefImpl> pdefImpl;
    if (pdataDef)
    {
        pdataDef->InitEmptyMovieDef();
        pls->SetRelativePathForDataDef(pdataDef);
        pdefImpl = *SF_HEAP_NEW(pMovieImpl->GetMovieHeap())
            MovieDefImpl(pdataDef, pls->pBindStates, pls->pLoaderImpl, 0, pMovieImpl->pStateBag->GetDelegate(),
                         pMovieImpl->GetMovieHeap(), true);
    }
    if (!pdefImpl)
        return NULL;
    CharacterCreateInfo ccinfo;
    ccinfo.pCharDef     = pdataDef;
    ccinfo.pBindDefImpl = pdefImpl;
    ccinfo.pResource    = 0;
    Sprite* psprite = static_cast<Sprite*>(pASSupport->CreateCharacterInstance(
        pMovieImpl, ccinfo, 0, ResourceId(), CharacterDef::Sprite));
    psprite->SetLoadedSeparately();
    AvmSprite::FromSprite(psprite)->SetLevel(level);
    pMovieImpl->SetLevelMovie(level, psprite);
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
        : FunctionObject(psc, ObjectInlineCtorTag()), pContext(pfc), pUserData(puserData)
    {
        Set__proto__(psc, psc->pContext->GetPrototype(ASBuiltin_Function));
    }
    virtual ~UserDefinedFunctionObject();                                    // exe 0x142926060 (sfr_as2_03)

    virtual Environment* GetEnvironment(const FnCall& fn, Ptr<InteractiveObject>*) { return fn.Env; }
    virtual void         Invoke(const FnCall& fn, LocalFrame*, const char*); // exe 0x142963aa0 (sfr_as2_06)
    virtual bool         IsNull() const { return !pContext; }
    virtual bool         IsEqual(const FunctionObject&) const { return false; }
    virtual int          GetNumArgs() const { return -1; }
};

// MS2-FUNCTIONAL: instruction scheduling (the exe sets the heap Alloc align arg r8d before the undefined-Value type store; ours after it); same behavior
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
    if ((UByte)(name.GetHashFlags() >> 29) & 1)
        return true;
    if (name.GetLength() != 0 && name.GetCharAt(0) == '_')
    {
        ASString lower(name.ToLowerNode());
        if ((UByte)(lower.GetHashFlags() >> 28) & 1)
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
    return obj && obj->DeleteMember(psc, name);
}

// @0x142937bc0
Value StageCtorFunction::CreateRectangleObject(Environment* penv, const Render::RectF& rect)
{
    Value result;
    Ptr<Object> obj =
        *penv->OperatorNew(penv->GetSC()->pContext->FlashGeomPackage, penv->GetBuiltin(ASBuiltin_Rectangle));
    ASRect r(rect.x1, rect.y1, rect.x2, rect.y2);
    static_cast<RectangleObject*>(obj.GetPtr())->SetProperties(penv, r);
    result.SetAsObject(obj);
    return result;
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
// The node dtor is called out of line (~HashNode<ASString, FunctionRef> is SF_NOINLINE above, as in the exe).
template void MS2_AS2_STRING_SET(GFx::AS2::FunctionRef, HashsetNodeEntry)::Clear();
template void MS2_AS2_STRING_SET(GFx::AS2::Member, GFx::HashsetNodeEntry_GC)::Clear();
// @0x142934220
template void decltype(HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, GFx::EventIdHashFunctor,
                              GFx::AS2::StatMV_ActionScript_Mem>::mHash)::BaseType::Clear();
// @0x1429342b0
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
// MS2-PIN: ??_7?$RefCountBase@VWideStringStorage@MovieImpl@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x14317ca40
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7SizeVisitor@?1??ComputeSizeInBytes@SharedObject@AS2@GFx@Scaleform@@QEAA_KPEAVEnvironment@345@@Z@6B@ 0x1432227e8
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
namespace Scaleform { namespace GFx { namespace AS2 {

// IntervalTimer's vftable slots 4 and 5 (vftable 0x14321bd70).
// @0x1429343e0
void IntervalTimer::Clear()
{
    Active = false;
}

// This build never clears a timer per movie definition: no timer is ever owned by the unloaded definition.
// @0x1429345c0
bool IntervalTimer::ClearFor(MovieImpl*, MovieDefImpl*)
{
    return false;
}

}}} // namespace Scaleform::GFx::AS2

// MS2-PIN: ??_7UserDefinedFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143221ff8
// MS2-PIN: ??_7UserDefinedFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143222080
// MS2-PIN: ??_GUserDefinedFunctionObject@AS2@GFx@Scaleform@@UEAAPEAXI@Z 0x14292da40
// MS2-PIN: ??_7LoadQueueEntry@GFx@Scaleform@@6B@ 0x14317c9d8
// MS2-PIN: ??_7GFxAS2LoadQueueEntry@AS2@GFx@Scaleform@@6B@ 0x143217748
// The vftables of the objects whose ctors CreateNewObject inlines (out of line in sfr_as2_03).
// MS2-PIN: ??_7AsBroadcaster@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321bdc8
// MS2-PIN: ??_7AsBroadcaster@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321be10
// MS2-PIN: ??_7BevelFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f848
// MS2-PIN: ??_7BevelFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f890
// MS2-PIN: ??_7BlurFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f438
// MS2-PIN: ??_7BlurFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f480
// MS2-PIN: ??_7BooleanObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b550
// MS2-PIN: ??_7BooleanObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b598
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432156f0
// MS2-PIN: ??_7CFunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215778
// MS2-PIN: ??_7ColorObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432188a0
// MS2-PIN: ??_7ColorObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432188e8
// MS2-PIN: ??_7DropShadowFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ec18
// MS2-PIN: ??_7DropShadowFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ec60
// MS2-PIN: ??_7ExternalInterface@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321ce68
// MS2-PIN: ??_7ExternalInterface@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321ceb0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432155c0
// MS2-PIN: ??_7FunctionObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143215648
// MS2-PIN: ??_7GlowFilterObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321f028
// MS2-PIN: ??_7GlowFilterObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321f070
// MS2-PIN: ??_7MovieClipLoader@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143216a50
// MS2-PIN: ??_7MovieClipLoader@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143216ac0
// MS2-PIN: ??_7NumberObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321b140
// MS2-PIN: ??_7NumberObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321b188
// MS2-PIN: ??_7RefCountImpl@Scaleform@@6B@ 0x142dc9d58
// MS2-PIN: ??_7RefCountImplCore@Scaleform@@6B@ 0x142dc9d48
// MS2-PIN: ??_7StringObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x14321a920
// MS2-PIN: ??_7StringObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x14321a968
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218490
// MS2-PIN: ??_7TextFieldObject@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x1432184d8
