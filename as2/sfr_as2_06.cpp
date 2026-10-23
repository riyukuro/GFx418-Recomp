// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 array element storage and
// the script runtime entry points from Init to Reset.
// MS2-UNIT: sfr_as2_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14295d700-0x14295d840 .text$mn
// MS2-RANGE: 0x14295d970-0x14295da40 .text$mn
// MS2-RANGE: 0x14295e1b0-0x14295e2b0 .text$mn
// MS2-RANGE: 0x142961720-0x142961830 .text$mn
// MS2-RANGE: 0x142961d40-0x142961d80 .text$mn
// MS2-RANGE: 0x142961ef0-0x142961fe0 .text$mn
// MS2-RANGE: 0x142961fe0-0x142962010 .text$mn
// MS2-RANGE: 0x142962010-0x1429620d0 .text$mn
// MS2-RANGE: 0x1429623a0-0x142962410 .text$mn
// MS2-RANGE: 0x142962bb0-0x142962c90 .text$mn
// MS2-RANGE: 0x142965510-0x142965560 .text$mn
// MS2-RANGE: 0x142965c80-0x142965ce0 .text$mn
// MS2-RANGE: 0x142965d10-0x142965da0 .text$mn
// MS2-RANGE: 0x142965db0-0x142965e50 .text$mn
// MS2-RANGE: 0x142966270-0x142966370 .text$mn
// MS2-RANGE: 0x142967390-0x1429673e0 .text$mn
// MS2-RANGE: 0x1429673e0-0x142967430 .text$mn
// MS2-RANGE: 0x142967430-0x1429674a0 .text$mn
// MS2-RANGE: 0x142967b90-0x142967bf0 .text$mn
// MS2-RANGE: 0x142967d10-0x142967e00 .text$mn
// MS2-RANGE: 0x142967e00-0x142967f60 .text$mn
// MS2-RANGE: 0x142967f60-0x142967fc0 .text$mn
// MS2-RANGE: 0x142967fc0-0x1429680b0 .text$mn
// MS2-RANGE: 0x1429680b0-0x142968210 .text$mn
// MS2-RANGE: 0x142968210-0x142968280 .text$mn
// MS2-RANGE: 0x142968280-0x142968370 .text$mn
// MS2-RANGE: 0x142968370-0x1429684d0 .text$mn
// MS2-RANGE: 0x1429684d0-0x142968560 .text$mn
// MS2-RANGE: 0x142968560-0x142968610 .text$mn
// MS2-RANGE: 0x142968f90-0x142969000 .text$mn
// MS2-RANGE: 0x14296b820-0x14296b850 .text$mn
// MS2-RANGE: 0x14296bba0-0x14296bbb0 .text$mn
// MS2-RANGE: 0x14296e790-0x14296e870 .text$mn
// MS2-RANGE: 0x14296efd0-0x14296f070 .text$mn
// MS2-RANGE: 0x14296f070-0x14296f0c0 .text$mn
// MS2-RANGE: 0x14296f1b0-0x14296f260 .text$mn
// MS2-RANGE: 0x14296f2b0-0x14296f390 .text$mn
// MS2-RANGE: 0x14296f390-0x14296f3d0 .text$mn
// MS2-RANGE: 0x14296f640-0x14296f770 .text$mn
// MS2-RANGE: 0x14296f770-0x14296f870 .text$mn
// MS2-RANGE: 0x142971a50-0x142971ac0 .text$mn
// MS2-RANGE: 0x142971ba0-0x142971c50 .text$mn
// MS2-RANGE: 0x142971c50-0x142971cc0 .text$mn
// MS2-RANGE: 0x142972330-0x142972410 .text$mn
// MS2-RANGE: 0x142972410-0x142972490 .text$mn
// MS2-RANGE: 0x142973040-0x142973080 .text$mn
// MS2-RANGE: 0x14297c970-0x14297ca60 .text$mn
// MS2-RANGE: 0x14297ca70-0x14297cae0 .text$mn
// MS2-RANGE: 0x14297d0d0-0x14297d1e0 .text$mn
// MS2-RANGE: 0x14297d1e0-0x14297d330 .text$mn
// MS2-RANGE: 0x14297d4b0-0x14297d550 .text$mn
// MS2-RANGE: 0x14297d550-0x14297d5f0 .text$mn
// MS2-RANGE: 0x14297d5f0-0x14297d690 .text$mn
// MS2-RANGE: 0x14297d730-0x14297d7d0 .text$mn
// MS2-RANGE: 0x14297d7d0-0x14297d870 .text$mn
// MS2-RANGE: 0x14297d870-0x14297d910 .text$mn
// MS2-RANGE: 0x14297d910-0x14297d9b0 .text$mn
// MS2-RANGE: 0x14297d9b0-0x14297da50 .text$mn
// MS2-RANGE: 0x14297da50-0x14297daf0 .text$mn
// MS2-RANGE: 0x14297daf0-0x14297db90 .text$mn
// MS2-RANGE: 0x14297db90-0x14297dc30 .text$mn
// MS2-RANGE: 0x14297dcd0-0x14297dd70 .text$mn
// MS2-RANGE: 0x14297dfb0-0x14297e060 .text$mn
// MS2-RANGE: 0x14297e060-0x14297e0e0 .text$mn
// MS2-RANGE: 0x14297e0e0-0x14297e1b0 .text$mn
// MS2-RANGE: 0x14297e230-0x14297e2b0 .text$mn
// MS2-RANGE: 0x14297e2b0-0x14297e330 .text$mn
// MS2-RANGE: 0x14297e330-0x14297e3f0 .text$mn
// MS2-RANGE: 0x14297e3f0-0x14297e450 .text$mn
// MS2-RANGE: 0x14297e450-0x14297e500 .text$mn
// MS2-RANGE: 0x14297e500-0x14297e5a0 .text$mn
// MS2-RANGE: 0x14297e5a0-0x14297e640 .text$mn
// MS2-RANGE: 0x1429752b0-0x142975740 .text$mn
// MS2-RANGE: 0x142973080-0x142973500 .text$mn
// MS2-RANGE: 0x142973a80-0x142973f20 .text$mn
// MS2-RANGE: 0x142973f20-0x142974460 .text$mn
// MS2-RANGE: 0x142974460-0x142974910 .text$mn
// MS2-RANGE: 0x142974910-0x142974d70 .text$mn
// MS2-RANGE: 0x142974d70-0x1429752b0 .text$mn
// MS2-RANGE: 0x1429763c0-0x142976900 .text$mn
// MS2-RANGE: 0x142976be0-0x142977070 .text$mn
// MS2-RANGE: 0x142977070-0x1429775b0 .text$mn
// MS2-RANGE: 0x142977ad0-0x142977db0 .text$mn
// MS2-RANGE: 0x142978240-0x142978780 .text$mn
// MS2-RANGE: 0x142978dd0-0x142979260 .text$mn
// MS2-RANGE: 0x1429797e0-0x142979d00 .text$mn
// MS2-RANGE: 0x14297a4a0-0x14297a960 .text$mn
// MS2-RANGE: 0x14297aca0-0x14297b190 .text$mn
// MS2-RANGE: 0x14297bf80-0x14297c400 .text$mn
// MS2-RANGE: 0x142976900-0x142976be0 .text$mn
// MS2-RANGE: 0x142979d00-0x142979fe0 .text$mn
// MS2-RANGE: 0x14297c400-0x14297c6e0 .text$mn
// MS2-RANGE: 0x142977db0-0x142978240 .text$mn
// MS2-RANGE: 0x142975f30-0x1429763c0 .text$mn
// MS2-RANGE: 0x142975740-0x142975c20 .text$mn
// MS2-RANGE: 0x14295d1c0-0x14295d320 .text$mn
// MS2-RANGE: 0x142973500-0x142973a80 .text$mn
// MS2-RANGE: 0x1429775b0-0x142977ad0 .text$mn
// MS2-RANGE: 0x142979260-0x1429797e0 .text$mn
// MS2-RANGE: 0x142979fe0-0x14297a4a0 .text$mn
// MS2-RANGE: 0x142978780-0x142978a90 .text$mn
// MS2-RANGE: 0x142963400-0x1429635f0 .text$mn
// MS2-RANGE: 0x142969450-0x1429694e0 .text$mn
// MS2-RANGE: 0x14296c220-0x14296c430 .text$mn
// MS2-RANGE: 0x14296cb80-0x14296cbf0 .text$mn
// MS2-RANGE: 0x14296cbf0-0x14296cd30 .text$mn
// MS2-RANGE: 0x14296cd30-0x14296ce70 .text$mn
// MS2-RANGE: 0x142971d70-0x142972190 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_timer.h"
#include "../include/gfx/gfx_input.h"
#include "../include/render/render_twips.h"

// Stores *value under key in the hash at owner+0x10 and releases the passed reference (a folded hash set; the
// prototype table of GlobalContext here). Defined in sfr_video_01.
void FUN_14000c280(void* owner, unsigned key, void** value);

namespace Scaleform { namespace GFx {

class FunctionHandler;

namespace AS2 {

// Function object around a host FunctionHandler (GFx::Value::CreateFunction). Only what this unit needs.
class UserDefinedFunctionObject : public FunctionObject
{
protected:
    Ptr<FunctionHandler> pContext;  // +0x68
    void*                pUserData; // +0x70

public:
    // Through super the handler runs on the real this, then the super drops its alternate prototype
    // (exe 0x142963aa0).
    virtual void Invoke(const FnCall& fn, LocalFrame*, const char*);

    // Hands the call to the handler (exe 0x142964390).
    void InvokeImpl(const FnCall& fn);
};

// @0x142961720
void ArrayObject::InitArray(const FnCall& fn)
{
    Value index;
    for (int i = 0; i < fn.NArgs; i++)
    {
        index.SetInt(i);
        SetMember(fn.Env, index.ToString(fn.Env), fn.Arg(i));
    }
}

// MS2-FUNCTIONAL jump offsets of the inlined Object::HasMember
// @0x14295d700
bool ArrayObject::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    int idx;
    if ((idx = ParseIndex(name)) >= 0)
    {
        if (idx >= (int)Elements.GetSize() || Elements[idx] == 0 || Elements[idx]->IsUndefined() ||
            Elements[idx]->IsNull())
            return false;
        return true;
    }
    return Object::HasMember(psc, name, inclPrototypes);
}

// MS2-FUNCTIONAL the exe keeps the copied member's type in a register and skips its destructor on the not found path
// @0x14295d970
bool Object::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    Member member;
    if (MemberHash_Get(&Members, name, &member))
        return true;
    else if (inclPrototypes && pProto)
        return pProto->HasMember(psc, name, true);
    return false;
}

// @0x142962010
void ArrayObject::InsertEmpty(int start, int count)
{
    int i;
    int oldSize = (int)Elements.GetSize();
    Elements.Resize(oldSize + count);
    if (oldSize)
    {
        for (i = (int)Elements.GetSize() - 1; i >= start + count; --i)
            Elements[i] = Elements[i - count];
    }
    for (i = 0; i < count; i++)
        Elements[start + i] = 0;
}

// @0x142966270
void ArrayObject::JoinToString(Environment* penv, StringBuffer* pbuffer, const char* pdelimiter) const
{
    pbuffer->Clear();
    Value undefinedValue;
    for (unsigned i = 0; i < Elements.GetSize(); i++)
    {
        if (i)
            pbuffer->AppendString(pdelimiter);
        if (Elements[i])
        {
            ASString s(Elements[i]->ToString(penv));
            pbuffer->AppendString(s.ToCStr());
        }
        else
        {
            ASString s(undefinedValue.ToString(penv));
            pbuffer->AppendString(s.ToCStr());
        }
    }
}

// @0x142971ba0
void ArrayObject::PushBack(const Value& val)
{
    Elements.PushBack(SF_HEAP_AUTO_NEW(this) Value(val));
}

// @0x142971c50
void ArrayObject::PushBack()
{
    Elements.PushBack(0);
}

// @0x1429684d0
void ArrayObject::MakeDeepCopy(MemoryHeap* pheap)
{
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
    {
        if (Elements[i])
        {
            Value* pval = SF_HEAP_NEW(pheap) Value(*Elements[i]);
            Elements[i] = pval;
        }
    }
}

// @0x142968560
void ArrayObject::MakeDeepCopyFrom(MemoryHeap* pheap, const ArrayObject& ao)
{
    Elements.Resize(ao.Elements.GetSize());
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
    {
        if (ao.Elements[i])
        {
            Value* pval = SF_HEAP_NEW(pheap) Value(*ao.Elements[i]);
            Elements[i] = pval;
        }
    }
}

// noinline: the exe calls it out of line from AsBroadcaster::RemoveListener.
// @0x14297d0d0
__declspec(noinline) void ArrayObject::RemoveElements(int start, int count)
{
    if (Elements.GetSize())
    {
        int i;
        for (i = 0; i < count; i++)
            delete Elements[start + i];
        for (i = start + count; i < (int)Elements.GetSize(); i++)
        {
            Elements[i - count] = Elements[i];
            Elements[i]         = 0;
        }
        Elements.Resize(Elements.GetSize() - count);
    }
}

// @0x14297e330
void ArrayObject::Resize(int size)
{
    if (size < 0)
        size = 0;
    UPInt i;
    UPInt newSize = (UPInt)size;
    UPInt oldSize = Elements.GetSize();
    for (i = newSize; i < oldSize; i++)
        delete Elements[i];
    Elements.Resize(newSize);
    for (i = oldSize; i < newSize; i++)
        Elements[i] = 0;
}

// @0x14296f1b0
void ArrayObject::PopFront_Call()
{
    PopFront();
}

// @0x142961d40
bool AsBroadcaster::Initialize(ASStringContext* psc, ObjectInterface* pobj)
{
    InitializeProto(psc, pobj);
    return InitializeInstance(psc, pobj);
}

// noinline: Initialize tail-calls it.
// @0x142961ef0
__declspec(noinline) bool AsBroadcaster::InitializeInstance(ASStringContext* psc, ObjectInterface* pobj)
{
    if (!pobj)
        return false;
    Ptr<ArrayObject> ao = *SF_HEAP_NEW(psc->GetHeap()) ArrayObject(psc);
    pobj->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin__listeners), Value(ao), PropFlags::PropFlag_DontEnum);
    return true;
}

// The out-of-line copy of Value::ToObjectInterface (exe 0x142991810), which the header inlines.
ObjectInterface* Value_ToObjectInterface(const Value* pval, const Environment* penv);

// @0x14297d1e0
bool AsBroadcaster::RemoveListener(Environment* penv, ObjectInterface* pthis, ObjectInterface* plistener)
{
    if (!pthis || !plistener)
        return false;

    Value listeners;
    if (pthis->GetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin__listeners), &listeners))
    {
        Object* pobj = listeners.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object_Array)
        {
            Ptr<ArrayObject> parray = static_cast<ArrayObject*>(pobj);
            for (int i = (int)parray->GetSize() - 1; i >= 0; --i)
            {
                Value* pelem = parray->GetElementPtr(i);
                if (pelem && Value_ToObjectInterface(pelem, penv) == plistener)
                {
                    parray->RemoveElements(i, 1);
                    return true;
                }
            }
        }
    }
    return false;
}

// @0x142961fe0
bool AsBroadcaster::InitializeProto(ASStringContext* psc, ObjectInterface* pobj)
{
    if (!pobj)
        return false;
    NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    return true;
}

// @0x14296b820
void AvmCharacter::OnEventLoad()
{
    OnEvent(EventId::Event_Load);
}

// @0x14296bba0
void AvmCharacter::OnEventUnload()
{
}

__forceinline void ActionLogger::LogScriptMessageVarg(LogMessageId messageType, const char* pfmt, va_list argList)
{
    if (!pLog)
        return;
    if (UseSuffix)
    {
        char  fmtBuffer[256];
        UPInt len = strlen(pfmt);
        Format(StringDataPtr(fmtBuffer, sizeof(fmtBuffer)), "{0} : {1}\n",
               StringDataPtr(pfmt, (pfmt[len - 1] == '\n' ? len - 1 : len)), LogSuffix);
        pLog->LogMessageVarg(messageType, fmtBuffer, argList);
    }
    else
        pLog->LogMessageVarg(messageType, pfmt, argList);
}

// @0x142967d10
void ActionLogger::LogScriptError(const char* pfmt, ...)
{
    va_list argList;
    va_start(argList, pfmt);
    LogScriptMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    va_end(argList);
}

// @0x142968280
void ActionLogger::LogScriptWarning(const char* pfmt, ...)
{
    va_list argList;
    va_start(argList, pfmt);
    LogScriptMessageVarg(LogChannel_Script | LogMessage_Warning, pfmt, argList);
    va_end(argList);
}

// @0x142967fc0
void ActionLogger::LogScriptMessage(const char* pfmt, ...)
{
    va_list argList;
    va_start(argList, pfmt);
    LogScriptMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    va_end(argList);
}

// @0x142967e00
void Environment::LogScriptError(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (pASLogger)
        pASLogger->LogScriptMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    else if (Target->GetLog())
        Target->GetLog()->LogMessageVarg(LogChannel_Script | LogMessage_Error, pfmt, argList);
    va_end(argList);
}

// @0x142968370
void Environment::LogScriptWarning(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (pASLogger)
        pASLogger->LogScriptMessageVarg(LogChannel_Script | LogMessage_Warning, pfmt, argList);
    else if (Target->GetLog())
        Target->GetLog()->LogMessageVarg(LogChannel_Script | LogMessage_Warning, pfmt, argList);
    va_end(argList);
}

// @0x1429680b0
void Environment::LogScriptMessage(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (pASLogger)
        pASLogger->LogScriptMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    else if (Target->GetLog())
        Target->GetLog()->LogMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    va_end(argList);
}

// @0x142973040
bool ArrayObject::RecursionLimitReached_Call() const
{
    return RecursionLimitReached();
}

// Both operands are converted before the store (the inline Mul converts the right one first).
// @0x142968f90
void Value::Mul_Call(Environment* penv, const Value& v)
{
    Number lhs = ToNumber(penv);
    Number rhs = v.ToNumber(penv);
    SetNumber(lhs * rhs);
}

// @0x142965c80
bool IsLeapYear(int y)
{
    return 0 == (y % 4) && ((y % 100) || 0 == (y % 400));
}

// @0x142965db0
bool IsRectValid(const ASRect& r)
{
    return !NumberUtil::IsNaN(r.x1) && !NumberUtil::IsNaN(r.y1) && !NumberUtil::IsNaN(r.x2) &&
           !NumberUtil::IsNaN(r.y2);
}

// @0x1429623a0
bool Object::InstanceOf(Environment* penv, const Object* prototype, bool inclInterfaces) const
{
    for (const Object* proto = this; proto != 0; proto = proto->pProto)
    {
        if (inclInterfaces)
        {
            if (proto->DoesImplement(penv, prototype))
                return true;
        }
        else
        {
            if (proto == prototype)
                return true;
        }
    }
    return false;
}

// @0x142965510
bool CFunctionObject::IsEqual(const FunctionObject& f) const
{
    return f.IsCFunction() && pFunction == static_cast<const CFunctionObject&>(f).pFunction;
}

// @0x142965d10
bool Environment::IsPath(const ASString& varPath)
{
    if (varPath.GetHashFlags() & ASString::Flag_PathCheck)
        return 1;
    const char* pstr = varPath.ToCStr();
    if (strchr(pstr, ':') != 0 || strchr(pstr, '/') != 0 || strchr(pstr, '.') != 0)
    {
        varPath.SetPathFlags(ASString::Flag_PathCheck | 0);
        return 1;
    }
    else
    {
        varPath.SetPathFlags(ASString::Flag_PathCheck | ASString::Flag_IsNotPath);
        return 0;
    }
}

// @0x142967390
Value* Environment::LocalRegisterPtr(unsigned reg)
{
    if (reg >= LocalRegister.GetSize())
    {
        LogError("Invalid local register %d, stack only has %d entries", reg, (int)LocalRegister.GetSize());
        return &GlobalRegister[0];
    }
    return &LocalRegister[LocalRegister.GetSize() - reg - 1];
}

// @0x142972410
void Environment::PushTryBlock(const TryDescr& descr)
{
    TryBlocks.PushBack(descr);
}

// MS2-FUNCTIONAL instruction scheduling (the exe loads the size before the array address)
// @0x14296f390
Environment::TryDescr Environment::PopTryBlock()
{
    return TryBlocks.Pop();
}


// MS2-FUNCTIONAL register choice: the exe keeps the builtin offset in edx and adds the table base to it.
// @0x14296f770
Value Environment::PrimitiveToTempObject(int index)
{
    ASBuiltinType ctorName;

    const Value& top = Top(index);
    switch (top.GetType())
    {
    case Value::BOOLEAN:
        ctorName = ASBuiltin_Boolean;
        break;
    case Value::STRING:
        ctorName = ASBuiltin_String;
        break;
    default:
        if (top.IsNumber())
            ctorName = ASBuiltin_Number;
        else
            return Value();
    }

    Ptr<Object> obj = *OperatorNew(GetBuiltin(ctorName), 1, GetTopIndex() - index);
    return Value(obj);
}

// @0x14296f640
Value Environment::PrimitiveToTempObject(const Value& v)
{
    ASBuiltinType ctorName;

    switch (v.GetType())
    {
    case Value::BOOLEAN:
        ctorName = ASBuiltin_Boolean;
        break;
    case Value::STRING:
        ctorName = ASBuiltin_String;
        break;
    default:
        if (v.IsNumber())
            ctorName = ASBuiltin_Number;
        else
            return Value();
    }

    Push(v);
    Ptr<Object> obj = *OperatorNew(GetBuiltin(ctorName), 1, GetTopIndex());
    Drop1();
    return Value(obj);
}


// @0x14296e790
int MovieRoot::ParseLevelName(const char* pname, const char** ptail, bool caseSensitive)
{
    if (pname[0] >= '0' && pname[0] <= '9')
    {
        char* pend = 0;
        int   level = (int)strtol(pname, &pend, 10);
        *ptail    = pend;
        return level;
    }
    if (!pname || pname[0] != '_')
        return -1;

    if (caseSensitive)
    {
        if (pname[1] != 'l' || pname[2] != 'e' || pname[3] != 'v' || pname[4] != 'e' || pname[5] != 'l')
            return -1;
    }
    else
    {
        if ((pname[1] != 'l' && pname[1] != 'L') || (pname[2] != 'e' && pname[2] != 'E') ||
            (pname[3] != 'v' && pname[3] != 'V') || (pname[4] != 'e' && pname[4] != 'E') ||
            (pname[5] != 'l' && pname[5] != 'L'))
            return -1;
    }
    if (pname[6] < '0' || pname[6] > '9')
        return -1;

    char* pend  = 0;
    int   level = (int)strtol(pname + 6, &pend, 10);
    *ptail    = pend;
    return level;
}


// noinline: CFunctionObject::Invoke calls it out of line.
// @0x14297dfb0
__declspec(noinline) void SuperObject::ResetAltProto()
{
    if (!SavedProto)
        return;
    SuperProto = SavedProto;
    SavedProto = 0;
    pProto     = SuperProto;
}


// MS2-FUNCTIONAL the exe inlines the hash FindAlt (calling findIndexAlt out of line); ours keeps FindAlt out of line.
// @0x14297c970
bool GlobalContext::RegisterClassA(ASStringContext* psc, const ASString& className, const FunctionRef& ctorFunction)
{
    RegisteredClasses.SetCaseCheck(className, ctorFunction, psc->IsCaseSensitive());
    return true;
}


// @0x14295e1b0
void GASPrototypeBase::Init(Object* pthis, ASStringContext* psc, const FunctionRef& constructor)
{
    SetConstructor(pthis, psc, constructor);
    Constructor->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), Value(pthis),
                              PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete);
}


// @0x142962bb0
void CFunctionObject::Invoke(const FnCall& fn, LocalFrame*, const char*)
{
    if (!pFunction)
        return;
    ObjectInterface* pthis = fn.ThisPtr;
    if (pthis && pthis->IsSuper())
    {
        ObjectInterface* prealThis = static_cast<SuperObject*>(pthis)->RealThis;
        FnCall           fn2(fn.Result, prealThis, fn.Env, fn.NArgs, fn.FirstArgBottomIndex);
        pFunction(fn2);
        static_cast<SuperObject*>(pthis)->ResetAltProto();
    }
    else
        pFunction(fn);
}


// @0x142963aa0
void UserDefinedFunctionObject::Invoke(const FnCall& fn, LocalFrame*, const char*)
{
    if (!pContext)
        return;
    ObjectInterface* pthis = fn.ThisPtr;
    if (pthis && pthis->IsSuper())
    {
        ObjectInterface* prealThis = static_cast<SuperObject*>(pthis)->RealThis;
        FnCall           fn2(fn.Result, prealThis, fn.Env, fn.NArgs, fn.FirstArgBottomIndex);
        InvokeImpl(fn2);
        static_cast<SuperObject*>(pthis)->ResetAltProto();
    }
    else
        InvokeImpl(fn);
}

// Built-in class registration: the constructor function, its prototype stored in the context's prototype table
// (the table takes over the passed reference) and the constructor published as a member of the global object or
// of a package object.

static SF_FORCEINLINE void SetBuiltinPrototype(GlobalContext* pgc, ASBuiltinType type, Object* proto)
{
    ::FUN_14000c280(pgc, type, reinterpret_cast<void**>(&proto));
}

// The common registration: a CtorFunctionType constructor, a ProtoType prototype on the parent type's prototype,
// the constructor published under the type's name in ptarget.
template<class CtorFunctionType, class ProtoType>
static SF_FORCEINLINE FunctionRef RegisterBuiltinClass(GlobalContext* pgc, ASBuiltinType type, ASBuiltinType parentType,
                                               Object* ptarget)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) CtorFunctionType(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) ProtoType(&sc, pgc->GetPrototype(parentType), ctor);
    SetBuiltinPrototype(pgc, type, proto);
    ptarget->SetMemberRaw(&sc, sc.GetBuiltin(type), Value(ctor));
    return ctor;
}

// The filter classes derive from BitmapFilter: it is registered first unless the registry knows the name.
static SF_FORCEINLINE void RegisterBitmapFilterBase(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    if (!pgc->GetBuiltinClassRegistrar(sc.GetBuiltin(ASBuiltin_BitmapFilter)))
        BitmapFilterCtorFunction::Register(pgc);
}

// MS2-FUNCTIONAL the exe inlines the BooleanCtorFunction and BooleanProto ctors (sfr_as2_03)
// @0x1429752b0
FunctionRef BooleanCtorFunction::Register(GlobalContext* pgc)
{
    ASStringContext sc(pgc, 8);
    FunctionRef     ctor(*SF_HEAP_NEW(pgc->pHeap) BooleanCtorFunction(&sc));
    Ptr<Object>     proto = SF_HEAP_NEW(pgc->pHeap) BooleanProto(&sc, pgc->GetPrototype(ASBuiltin_Object), ctor);
    SetBuiltinPrototype(pgc, ASBuiltin_Boolean, proto);
    pgc->pGlobal->SetMemberRaw(&sc, sc.GetBuiltin(ASBuiltin_Boolean), Value(ctor));
    return ctor;
}

// MS2-FUNCTIONAL the exe inlines the AmpMarkerCtorFunction and AmpMarkerProto ctors (sfr_as2_03)
// @0x142973080
FunctionRef AmpMarkerCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<AmpMarkerCtorFunction, AmpMarkerProto>(pgc, ASBuiltin_Amp, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the AsBroadcasterCtorFunction and AsBroadcasterProto ctors (sfr_as2_03)
// @0x142973a80
FunctionRef AsBroadcasterCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<AsBroadcasterCtorFunction, AsBroadcasterProto>(pgc, ASBuiltin_AsBroadcaster, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the BevelFilterCtorFunction and BevelFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142973f20
FunctionRef BevelFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<BevelFilterCtorFunction, BevelFilterProto>(pgc, ASBuiltin_BevelFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the BitmapDataCtorFunction and BitmapDataProto ctors (sfr_as2_03)
// @0x142974460
FunctionRef BitmapDataCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<BitmapDataCtorFunction, BitmapDataProto>(pgc, ASBuiltin_BitmapData, ASBuiltin_Object, pgc->FlashDisplayPackage);
}

// MS2-FUNCTIONAL the exe inlines the BitmapFilterCtorFunction and BitmapFilterProto ctors (sfr_as2_03)
// @0x142974910
FunctionRef BitmapFilterCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<BitmapFilterCtorFunction, BitmapFilterProto>(pgc, ASBuiltin_BitmapFilter, ASBuiltin_Object, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the BlurFilterCtorFunction and BlurFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142974d70
FunctionRef BlurFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<BlurFilterCtorFunction, BlurFilterProto>(pgc, ASBuiltin_BlurFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the ColorMatrixFilterCtorFunction and ColorMatrixFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x1429763c0
FunctionRef ColorMatrixFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<ColorMatrixFilterCtorFunction, ColorMatrixFilterProto>(pgc, ASBuiltin_ColorMatrixFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the DateCtorFunction and DateProto ctors (sfr_as2_03)
// @0x142976be0
FunctionRef DateCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<DateCtorFunction, DateProto>(pgc, ASBuiltin_Date, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the DropShadowFilterCtorFunction and DropShadowFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142977070
FunctionRef DropShadowFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<DropShadowFilterCtorFunction, DropShadowFilterProto>(pgc, ASBuiltin_DropShadowFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the GASLoadVarsLoaderCtorFunction ctor (sfr_as2_03)
// @0x142977ad0
FunctionRef GASLoadVarsLoaderCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<GASLoadVarsLoaderCtorFunction, LoadVarsProto>(pgc, ASBuiltin_LoadVars, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the GlowFilterCtorFunction and GlowFilterProto ctors and GetBuiltinClassRegistrar (sfr_as2_03)
// @0x142978240
FunctionRef GlowFilterCtorFunction::Register(GlobalContext* pgc)
{
    RegisterBitmapFilterBase(pgc);
    return RegisterBuiltinClass<GlowFilterCtorFunction, GlowFilterProto>(pgc, ASBuiltin_GlowFilter, ASBuiltin_BitmapFilter, pgc->FlashFiltersPackage);
}

// MS2-FUNCTIONAL the exe inlines the MovieClipLoaderCtorFunction and MovieClipLoaderProto ctors (sfr_as2_03)
// @0x142978dd0
FunctionRef MovieClipLoaderCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<MovieClipLoaderCtorFunction, MovieClipLoaderProto>(pgc, ASBuiltin_MovieClipLoader, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the PointCtorFunction and PointProto ctors (sfr_as2_03)
// @0x1429797e0
FunctionRef PointCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<PointCtorFunction, PointProto>(pgc, ASBuiltin_Point, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the SharedObjectCtorFunction and SharedObjectProto ctors (sfr_as2_03)
// @0x14297a4a0
FunctionRef SharedObjectCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<SharedObjectCtorFunction, SharedObjectProto>(pgc, ASBuiltin_SharedObject, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the StringCtorFunction and StringProto ctors (sfr_as2_03)
// @0x14297aca0
FunctionRef StringCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<StringCtorFunction, StringProto>(pgc, ASBuiltin_String, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the TextSnapshotCtorFunction and TextSnapshotProto ctors (sfr_as2_03)
// @0x14297bf80
FunctionRef TextSnapshotCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<TextSnapshotCtorFunction, TextSnapshotProto>(pgc, ASBuiltin_TextSnapshot, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ColorTransformCtorFunction ctor
// @0x142976900
FunctionRef ColorTransformCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ColorTransformCtorFunction, ColorTransformProto>(pgc, ASBuiltin_ColorTransform, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the RectangleCtorFunction ctor
// @0x142979d00
FunctionRef RectangleCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<RectangleCtorFunction, RectangleProto>(pgc, ASBuiltin_Rectangle, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the TransformCtorFunction ctor
// @0x14297c400
FunctionRef TransformCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<TransformCtorFunction, TransformProto>(pgc, ASBuiltin_Transform, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the GASMatrixCtorFunction and MatrixProto ctors (sfr_as2_03)
// @0x142977db0
FunctionRef GASMatrixCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<GASMatrixCtorFunction, MatrixProto>(pgc, ASBuiltin_Matrix, ASBuiltin_Object, pgc->FlashGeomPackage);
}

// MS2-FUNCTIONAL the exe inlines the ColorCtorFunction and ColorProto ctors (sfr_as2_03)
// @0x142975f30
FunctionRef ColorCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ColorCtorFunction, ColorProto>(pgc, ASBuiltin_Color, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ButtonCtorFunction and ButtonProto ctors (sfr_as2_03)
// @0x142975740
FunctionRef ButtonCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ButtonCtorFunction, ButtonProto>(pgc, ASBuiltin_Button, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ArrayCtorFunction and ArrayProto ctors (sfr_as2_03)
// @0x142973500
FunctionRef ArrayCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ArrayCtorFunction, ArrayProto>(pgc, ASBuiltin_Array, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the ExternalInterfaceCtorFunction and ExternalInterfaceProto ctors (sfr_as2_03)
// @0x1429775b0
FunctionRef ExternalInterfaceCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<ExternalInterfaceCtorFunction, ExternalInterfaceProto>(pgc, ASBuiltin_ExternalInterface, ASBuiltin_Object,
                                                                                      pgc->FlashExternalPackage);
}

// MS2-FUNCTIONAL the exe inlines the NumberCtorFunction and NumberProto ctors (sfr_as2_03)
// @0x142979260
FunctionRef NumberCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<NumberCtorFunction, NumberProto>(pgc, ASBuiltin_Number, ASBuiltin_Object, pgc->pGlobal);
}

// MS2-FUNCTIONAL the exe inlines the SelectionCtorFunction ctor (sfr_as2_03)
// @0x142979fe0
FunctionRef SelectionCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<SelectionCtorFunction, SelectionProto>(pgc, ASBuiltin_Selection, ASBuiltin_Object, pgc->pGlobal);
}

// MovieImpl keeps one MouseState per mouse (4, 0x50 bytes each) at +0x1260, not recovered in gfx_movieimpl.h
// yet; null past the last one (the exe still reads through it).
static inline const MouseState* GetMovieMouseState(MovieImpl* proot, unsigned mouseIndex)
{
    if (mouseIndex >= 4)
        return 0;
    return reinterpret_cast<const MouseState*>(reinterpret_cast<const UByte*>(proot) + 0x1260) + mouseIndex;
}

// @0x14296cb80
void MouseCtorFunction::OnMouseMove(Environment* penv, unsigned mouseIndex) const
{
    NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseMove);
}

// @0x14296c220
void MouseCtorFunction::OnMouseDown(Environment* penv, unsigned mouseIndex, unsigned button,
                                    InteractiveObject* ptarget) const
{
    bool dblClick = false;
    if (penv->CheckExtensions())
    {
        UInt32 ticks = (UInt32)(Timer::GetTicks() / 1000);
        Render::PointF pos = GetMovieMouseState(penv->GetTarget()->GetMovieImpl(), mouseIndex)->GetLastPosition();
        SInt32 x = (SInt32)Render::TwipsToPixels(pos.x);
        SInt32 y = (SInt32)Render::TwipsToPixels(pos.y);
        // A second click within 300 ms at the same pixel.
        if (ticks <= LastClickTime + 300 && LastMousePos[0] == x && LastMousePos[1] == y)
            dblClick = true;
        LastMousePos[0] = x;
        LastMousePos[1] = y;
        LastClickTime   = ticks;
    }
    if (ptarget)
    {
        ASString path = ptarget->GetCharacterHandle()->NamePath;
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseDown, &path, button, 0, dblClick);
    }
    else
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseDown, 0, button, 0, dblClick);
}

// @0x14296cbf0
void MouseCtorFunction::OnMouseUp(Environment* penv, unsigned mouseIndex, unsigned button,
                                  InteractiveObject* ptarget) const
{
    if (ptarget)
    {
        ASString path = ptarget->GetCharacterHandle()->NamePath;
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseUp, &path, button);
    }
    else
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseUp, 0, button);
}

// @0x14296cd30
void MouseCtorFunction::OnMouseWheel(Environment* penv, unsigned mouseIndex, int sdelta,
                                     InteractiveObject* ptarget) const
{
    if (ptarget)
    {
        ASString path = ptarget->GetCharacterHandle()->NamePath;
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseWheel, &path, 0, sdelta);
    }
    else
        NotifyListeners(penv, mouseIndex, ASBuiltin_onMouseWheel, 0, 0, sdelta);
}

bool MouseCtorFunction::IsEmpty() const
{
    return pListenersArray && pListenersArray->GetSize() == 0;
}

// @0x142969450
void MouseCtorFunction::NotifyListeners(Environment* penv, unsigned mouseIndex, ASBuiltinType eventName,
                                        const ASString* ptargetName, unsigned button, int delta,
                                        bool dblClick) const
{
    LocalInvokeCallback callback(mouseIndex, eventName, ptargetName, button, delta, dblClick);
    AsBroadcaster::BroadcastMessageWithCallback(penv, const_cast<MouseCtorFunction*>(this),
                                                penv->GetBuiltin(eventName), &callback);
}

// MS2-FUNCTIONAL frame layout (exe keeps an rbp frame) and register allocation
// @0x142963400
void MouseCtorFunction::LocalInvokeCallback::Invoke(Environment* penv, ObjectInterface* pthis,
                                                    const FunctionRef& method)
{
    int nargs = PushListenersParams(penv, MouseIndex, EventName, Value(method), pTargetName, Button, Delta,
                                    DblClick);
    if (nargs < 0)
        return;
    Value result;
    method.Invoke(FnCall(&result, pthis, penv, nargs, penv->GetTopIndex()));
    penv->Drop(nargs);
}

// MS2-FUNCTIONAL event compare folding and FunctionRef temporary scheduling
// @0x142971d70
int MouseCtorFunction::PushListenersParams(Environment* penv, unsigned mouseIndex, ASBuiltinType eventName,
                                           const Value& method, const ASString* ptargetName, unsigned button,
                                           int delta, bool dblClick)
{
    int  nargs     = 0;
    // Without extensions (or for a method taking no arguments) only the standard arguments.
    bool noExtArgs = !penv->CheckExtensions();
    if (penv->CheckExtensions() && button != 0 &&
        (eventName == ASBuiltin_onMouseDown || eventName == ASBuiltin_onMouseUp))
    {
        // An extended button other than the left one only reaches methods that declare arguments.
        FunctionRef func = method.ToFunction(penv);
        if (func.IsNull())
            return -1;
        if (func->GetNumArgs() <= 0)
        {
            if (button > 1)
                return -1;
            noExtArgs = true;
        }
    }
    if (penv->CheckExtensions() && !noExtArgs)
    {
        if (eventName == ASBuiltin_onMouseDown && dblClick)
        {
            penv->Push(dblClick);
            nargs = 1;
        }
        Render::PointF pos = GetMovieMouseState(penv->GetTarget()->GetMovieImpl(), mouseIndex)->GetLastPosition();
        penv->Push(Number(Render::TwipsToPixels(floor(pos.y + 0.5))));
        penv->Push(Number(Render::TwipsToPixels(floor(pos.x + 0.5))));
        penv->Push(Value((int)mouseIndex));
        nargs += 3;
    }
    if (eventName != ASBuiltin_onMouseMove)
    {
        if (ptargetName && (eventName == ASBuiltin_onMouseWheel || !noExtArgs))
        {
            penv->Push(*ptargetName);
            ++nargs;
        }
        else if (nargs)
        {
            penv->Push(Value(Value::NULLTYPE));
            ++nargs;
        }
    }
    if (eventName == ASBuiltin_onMouseDown || eventName == ASBuiltin_onMouseUp)
    {
        if (button && !noExtArgs)
        {
            penv->Push(Number(button));
            ++nargs;
        }
        else if (nargs)
        {
            penv->Push(Value(Value::NULLTYPE));
            ++nargs;
        }
    }
    else if (eventName == ASBuiltin_onMouseWheel)
    {
        penv->Push(Value(delta));
        ++nargs;
    }
    return nargs;
}

// MS2-FUNCTIONAL the exe inlines the MathProto ctor (sfr_as2_03)
// @0x142978780
FunctionRef MathCtorFunction::Register(GlobalContext* pgc)
{
    return RegisterBuiltinClass<MathCtorFunction, MathProto>(pgc, ASBuiltin_Math, ASBuiltin_Object, pgc->pGlobal);
}

// @0x14295d1c0
void TransformCtorFunction::GlobalCtor(const FnCall& fn)
{
    if (fn.NArgs < 1)
        return;
    InteractiveObject* ptarget = fn.Env->FindTargetByValue(fn.Arg(0));
    if (!ptarget)
    {
        fn.Result->SetUndefined();
        return;
    }
    Ptr<TransformObject> ptransform;
    if (fn.ThisPtr && fn.ThisPtr->GetObjectType() == Object::Object_Transform && !fn.ThisPtr->IsBuiltinPrototype())
        ptransform = static_cast<TransformObject*>(fn.ThisPtr);
    else
        ptransform = *SF_HEAP_NEW(fn.Env->GetHeap()) TransformObject(fn.Env);
    ptransform->SetTarget(ptarget);
    fn.Result->SetAsObject(ptransform.GetPtr());
}


}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx {

// The function call's script channels read the target's log directly.
// @0x142967f60
template<>
void LogBase<AS2::FnCall>::LogScriptMessage(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    Log* plog = static_cast<const AS2::FnCall*>(this)->Env->Target->GetLog();
    if (plog)
        plog->LogMessageVarg(LogChannel_Script | LogMessage_Text, pfmt, argList);
    va_end(argList);
}

// The environment's action trace: the movie's verbose-action flag (MovieImpl::Flags bit 2), then the target's log.
// @0x142967430
template<>
void LogBase<AS2::Environment>::LogAction(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    InteractiveObject* ptarget = static_cast<const AS2::Environment*>(this)->Target;
    if ((UByte)(ptarget->GetMovieImpl()->Flags >> 2) & 1)
    {
        Log* plog = ptarget->GetLog();
        if (plog)
            plog->LogMessageVarg(Log_Action, pfmt, argList);
    }
    va_end(argList);
}

// @0x142968210
template<>
void LogBase<AS2::FnCall>::LogScriptWarning(const char* pfmt, ...) const
{
    va_list argList;
    va_start(argList, pfmt);
    if (P_IsVerboseActionErrors())
    {
        Log* plog = static_cast<const AS2::FnCall*>(this)->Env->Target->GetLog();
        if (plog)
            plog->LogMessageVarg(Log_ScriptWarning, pfmt, argList);
    }
    va_end(argList);
}

}} // namespace Scaleform::GFx

namespace Scaleform {

// @0x14296f070
template void GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Pop(unsigned);
// @0x14296efd0
template void GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Pop3();
// @0x142967c30
template void GFx::LogBase<GFx::Stream>::LogParseAction(const char*, ...) const;

// The page switches of the call stack (those of the value stack are elsewhere in the exe, 0x140006a40 /
// 0x140006cf0).
// @0x142972330
template<>
void GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::PushPage()
{
    Page* pnewPage;
    if (pReserved)
    {
        pnewPage  = pReserved;
        pReserved = pReserved->pNext;
    }
    else
        pnewPage = (Page*)SF_HEAP_AUTO_ALLOC(this, sizeof(Page));
    if (pnewPage)
    {
        Pages.PushBack(pnewPage);
        pPrevPageTop = pPageEnd - 1;
        pPageEnd     = pnewPage->Values + 32;
        pPageStart   = pnewPage->Values;
        pCurrent     = pnewPage->Values;
    }
    else
        pCurrent--;
}

// @0x14296f2b0
template<>
void GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::PopPage()
{
    if (Pages.GetSize() > 1)
    {
        Page* plast  = Pages.Back();
        plast->pNext = pReserved;
        pReserved    = plast;
        Pages.PopBack();
        Page* ptop   = Pages.Back();
        pPageStart   = ptop->Values;
        pPageEnd     = ptop->Values + 32;
        pCurrent     = pPageEnd - 1;
        pPrevPageTop = Pages.GetSize() > 1 ? &Pages[Pages.GetSize() - 2]->Values[32 - 1] : pPageStart;
    }
    else
    {
        pCurrent++;
        Construct<Ptr<GFx::AS2::FunctionObject> >(pCurrent);
    }
}

// @0x1429673e0
template void GFx::LogBase<GFx::AS2::ActionLogger>::LogAction(const char*, ...) const;

// LogError functional (pinned at the end): Environment::GetLog (exe 0x14294b210) is out of line here, the exe
// inlines Target->GetLog()
template void GFx::LogBase<GFx::AS2::Environment>::LogError(const char*, ...) const;

// The out-of-line array growth of the AS2 containers.
// @0x14297d4b0
template void ArrayDataBase<GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Page*,
                            AllocatorLH<GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Page*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d5f0
template void ArrayDataBase<GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::Page*,
                            AllocatorLH<GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::Page*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d7d0
template void ArrayDataBase<Ptr<GFx::AS2::Object>, AllocatorLH<Ptr<GFx::AS2::Object>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d870
template void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d9b0
template void ArrayDataBase<GFx::AS2::ArraySortFunctor, AllocatorGH<GFx::AS2::ArraySortFunctor, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297da50
template void ArrayDataBase<GFx::AS2::Value, AllocatorGH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                        UPInt);
// @0x14297daf0
template void ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                        UPInt);
// @0x14297db90
template void ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297dcd0
template void ArrayDataBase<bool, AllocatorLH<bool, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// TryBlocks_Resize
// @0x14297e060
template void ArrayBase<ArrayData<GFx::AS2::Environment::TryDescr, AllocatorLH<GFx::AS2::Environment::TryDescr, 2>,
                                  ArrayDefaultPolicy> >::Resize(UPInt);
// ArrayObjectElements_Resize (pinned at the end)
template void ArrayData<GFx::AS2::Value*, AllocatorLH<GFx::AS2::Value*, GFx::AS2::StatMV_ActionScript_Mem>,
                        ArrayDefaultPolicy>::Resize(UPInt);
// (pinned at the end)
template void ArrayData<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::Resize(UPInt);
// @0x14297d910
template void ArrayDataBase<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297e450
template void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// @0x14297e500
template void ArrayDataBase<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// RemoveAt functional (pinned at the end): cl inlines the ResizeNoConstruct of Clear, the exe tail-calls it
template void ArrayBase<ArrayData<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                                  ArrayDefaultPolicy> >::RemoveAt(UPInt);
// @0x14297d730
template void ArrayDataBase<GFx::AS2::Environment::TryDescr, AllocatorLH<GFx::AS2::Environment::TryDescr, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297e3f0
template void ArrayDataBase<GFx::AS2::Environment::TryDescr, AllocatorLH<GFx::AS2::Environment::TryDescr, Stat_Default_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// @0x14297d550
template void ArrayDataBase<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                             UPInt);
// @0x142971a50
template void ArrayData<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::PushBack(
    GFx::AS2::Object* const&);
// @0x14297e0e0
template void ArrayBase<ArrayData<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, Stat_Default_Mem>, ArrayDefaultPolicy> >::Resize(
    UPInt);
// @0x14297e5a0
template void ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);

} // namespace Scaleform
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14297ca70
// MS2-PIN: ?Resize@?$ArrayData@PEAVValue@AS2@GFx@Scaleform@@U?$AllocatorLH@PEAVValue@AS2@GFx@Scaleform@@$0BED@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e2b0
// MS2-PIN: ?Resize@?$ArrayData@PEAVObject@AS2@GFx@Scaleform@@U?$AllocatorGH@PEAVObject@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e230
// MS2-PIN: ?LogError@?$LogBase@VEnvironment@AS2@GFx@Scaleform@@@GFx@Scaleform@@QEBAXPEBDZZ 0x142967b90
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b4de0
// MS2-PIN: ??_7ColorTransformCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432193a0
// MS2-PIN: ??_7ColorTransformCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219428
// MS2-PIN: ??_7RectangleCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x1432197b0
// MS2-PIN: ??_7RectangleCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219838
// MS2-PIN: ??_7TransformCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143219bc0
// MS2-PIN: ??_7TransformCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219c48
// MS2-PIN: ??_7GASMatrixCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218f90
// MS2-PIN: ??_7GASMatrixCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143219018
// MS2-PIN: ??_7ColorCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143218b80
// MS2-PIN: ??_7ColorCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143218c08
// MS2-PIN: ??_7ButtonCtorFunction@AS2@GFx@Scaleform@@6B?$ASRefCountBase@VObject@AS2@GFx@Scaleform@@@123@@ 0x143217f28
// MS2-PIN: ??_7ButtonCtorFunction@AS2@GFx@Scaleform@@6BObjectInterface@123@@ 0x143217fb0
// MS2-PIN: ??_7InvokeCallback@AsBroadcaster@AS2@GFx@Scaleform@@6B@ 0x14321bdb8
// MS2-PIN: ??_7LocalInvokeCallback@MouseCtorFunction@AS2@GFx@Scaleform@@6B@ 0x14321ccf8
