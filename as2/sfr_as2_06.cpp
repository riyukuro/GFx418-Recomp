// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 array element storage and
// the script runtime entry points from Init to Reset.
// MS2-UNIT: sfr_as2_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14295d700-0x14295d840 .text$mn
// MS2-RANGE: 0x14295d970-0x14295da40 .text$mn
// MS2-RANGE: 0x142961720-0x142961830 .text$mn
// MS2-RANGE: 0x142961d40-0x142961d80 .text$mn
// MS2-RANGE: 0x142961ef0-0x142961fe0 .text$mn
// MS2-RANGE: 0x142961fe0-0x142962010 .text$mn
// MS2-RANGE: 0x142962010-0x1429620d0 .text$mn
// MS2-RANGE: 0x1429623a0-0x142962410 .text$mn
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

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/kernel/sf_msgformat.h"

namespace Scaleform { namespace GFx { namespace AS2 {

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


// @0x14297dfb0
void SuperObject::ResetAltProto()
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
