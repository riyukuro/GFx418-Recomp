// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 from ResizeNoConstruct to the
// XML classes: the value setters and conversions, member setters, IME, Sound and XML objects.
// MS2-UNIT: sfr_as2_07
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14297f2c0-0x14297f3d0 .text$mn
// MS2-RANGE: 0x14297fba0-0x14297fed0 .text$mn
// MS2-RANGE: 0x142980240-0x1429803d0 .text$mn
// MS2-RANGE: 0x1429804c0-0x142980570 .text$mn
// MS2-RANGE: 0x1429814c0-0x142981600 .text$mn
// MS2-RANGE: 0x142981650-0x142981670 .text$mn
// MS2-RANGE: 0x142981b70-0x142981bb0 .text$mn
// MS2-RANGE: 0x142981bc0-0x142981bf0 .text$mn
// MS2-RANGE: 0x142981d80-0x142981f00 .text$mn
// MS2-RANGE: 0x142982ba0-0x142982d20 .text$mn
// MS2-RANGE: 0x142986790-0x142986d60 .text$mn
// MS2-RANGE: 0x142987280-0x1429872b0 .text$mn
// MS2-RANGE: 0x142988690-0x142988a30 .text$mn
// MS2-RANGE: 0x142988b60-0x142988f30 .text$mn
// MS2-RANGE: 0x1429891c0-0x142989320 .text$mn
// MS2-RANGE: 0x142989390-0x142989480 .text$mn
// MS2-RANGE: 0x142989d20-0x142989e90 .text$mn
// MS2-RANGE: 0x14298a260-0x14298a5a0 .text$mn
// MS2-RANGE: 0x14298b9f0-0x14298ba60 .text$mn
// MS2-RANGE: 0x14298bb20-0x14298bb90 .text$mn
// MS2-RANGE: 0x14298c9e0-0x14298ca20 .text$mn
// MS2-RANGE: 0x14298cc30-0x14298cc70 .text$mn
// MS2-RANGE: 0x14298cc80-0x14298cce0 .text$mn
// MS2-RANGE: 0x14298dc00-0x14298dee0 .text$mn
// MS2-RANGE: 0x14298ee10-0x14298ee70 .text$mn
// MS2-RANGE: 0x14298fe50-0x14298fe90 .text$mn
// MS2-RANGE: 0x142990240-0x1429902c0 .text$mn
// MS2-RANGE: 0x142990960-0x142990c30 .text$mn
// MS2-RANGE: 0x142990c40-0x142990cc0 .text$mn
// MS2-RANGE: 0x142990d00-0x142990dd0 .text$mn
// MS2-RANGE: 0x142990e40-0x142990ea0 .text$mn
// MS2-RANGE: 0x142990f20-0x142991140 .text$mn
// MS2-RANGE: 0x142991190-0x1429912d0 .text$mn
// MS2-RANGE: 0x142991660-0x142991850 .text$mn
// MS2-RANGE: 0x142991c60-0x142991d30 .text$mn
// MS2-RANGE: 0x142991e10-0x142991e70 .text$mn
// MS2-RANGE: 0x1429923c0-0x142992670 .text$mn
// MS2-RANGE: 0x142992680-0x142992830 .text$mn
// MS2-RANGE: 0x142992900-0x142992a20 .text$mn
// MS2-RANGE: 0x142992b00-0x142992c40 .text$mn
// MS2-RANGE: 0x142992e30-0x142992ee0 .text$mn
// MS2-RANGE: 0x142994160-0x142994190 .text$mn
// MS2-RANGE: 0x1429944d0-0x142994710 .text$mn
// MS2-RANGE: 0x1429947f0-0x142994a00 .text$mn
// MS2-RANGE: 0x142994bb0-0x142994e00 .text$mn
// MS2-RANGE: 0x142994e10-0x142994e90 .text$mn
// MS2-RANGE: 0x142994fe0-0x1429950f0 .text$mn
// MS2-RANGE: 0x142995100-0x142995180 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_event.h"
#include "../include/render/render_matrix4x4.h"
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_msgformat.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

namespace Scaleform { namespace GFx { namespace AS2 {

// The script number of a string: hex "0x..", octal "0..", else decimal; false unless the whole string was used.
SF_NOINLINE bool StringToNumber(Number* result, const char* str);

// The out-of-line watchpoint table helpers the exe calls (COMDATs of other units).
void WatchpointHash_Destruct(ASStringHash_GC<Object::Watchpoint>* phash); // exe 0x1429246b0
// GetCaseCheck / RemoveCaseCheck of the watchpoint table (exe 0x142949eb0 / 0x14297cae0).
const Object::Watchpoint* WatchpointHash_GetCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                                      bool caseSensitive);
// The watchpoint hash's findIndexAlt (exact / ignoring case) and add, COMDATs the exe calls out of line.
SPInt WatchpointHash_FindIndex(const ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key); // exe 0x142917220
SPInt WatchpointHash_FindIndexNoCase(const ASStringHash_GC<Object::Watchpoint>* phash,
                                     const ASStringNoCaseKey& key); // exe 0x142916e60
void WatchpointHash_Add(ASStringHash_GC<Object::Watchpoint>* phash, void* pheapAddr,
                        const ASStringHash_GC<Object::Watchpoint>::NodeType::NodeRef& key, UPInt h); // exe 0x142916110

typedef ASStringHash_GC<Object::Watchpoint>::SetType WatchpointSet;

// Hash::SetCaseCheck of the watchpoint table, inline in the exe around the out-of-line findIndexAlt and add.
inline void WatchpointHash_SetCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                        const Object::Watchpoint& value, bool caseSensitive)
{
    SPInt index;
    if (caseSensitive)
        index = WatchpointHash_FindIndex(phash, key);
    else
    {
        ASStringNoCaseKey ikey(key);
        index = WatchpointHash_FindIndexNoCase(phash, ikey);
    }
    WatchpointSet::Iterator it = index >= 0 ? WatchpointSet::Iterator(reinterpret_cast<WatchpointSet*>(phash), index)
                                            : WatchpointSet::Iterator(0, 0);
    if (it != reinterpret_cast<WatchpointSet*>(phash)->End())
        it->Second = value;
    else
    {
        ASStringHash_GC<Object::Watchpoint>::NodeType::NodeRef e(key, value);
        WatchpointHash_Add(phash, phash, e, e.GetHash());
    }
}
void WatchpointHash_RemoveCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                    bool caseSensitive);

// GetCaseCheck / RemoveCaseCheck of the registered class table (exe 0x142949f60 / 0x14297cd20).
FunctionRef* ClassHash_GetCaseCheck(ASStringHash<FunctionRef>* phash, const ASString& key, bool caseSensitive);
void         ClassHash_RemoveCaseCheck(ASStringHash<FunctionRef>* phash, const ASString& key, bool caseSensitive);

// The member table's findIndexAlt ignoring case (exe COMDAT 0x142917040).
SPInt MemberHash_FindIndexNoCase(const ASStringHash_GC<Member>* phash, const ASStringNoCaseKey& key);
typedef ASStringHash_GC<Member>::SetType MemberSet;

// Find / FindCaseInsensitive / FindCaseCheck of the member table.
inline MemberSet::Iterator MemberHash_Find(ASStringHash_GC<Member>* phash, const ASString& key)
{
    SPInt index = MemberHash_FindIndex(phash, key);
    if (index >= 0)
        return MemberSet::Iterator(reinterpret_cast<MemberSet*>(phash), index);
    return MemberSet::Iterator(0, 0);
}
inline MemberSet::Iterator MemberHash_FindNoCase(ASStringHash_GC<Member>* phash, const ASString& key)
{
    ASStringNoCaseKey ikey(key);
    SPInt index = MemberHash_FindIndexNoCase(phash, ikey);
    if (index >= 0)
        return MemberSet::Iterator(reinterpret_cast<MemberSet*>(phash), index);
    return MemberSet::Iterator(0, 0);
}
inline MemberSet::Iterator MemberHash_FindCaseCheck(ASStringHash_GC<Member>* phash, const ASString& key,
                                                    bool caseSensitive)
{
    return caseSensitive ? MemberHash_Find(phash, key) : MemberHash_FindNoCase(phash, key);
}

// The value SetMemberRaw stores for __proto__ / __resolve (they live outside the member table); exe 0x143a51b50.
extern const Value Object_NotsetVal;

// @0x14297fba0
void Value::SetAsCharacter(InteractiveObject* pchar)
{
    SetAsCharacterHandle(pchar ? pchar->GetCharacterHandle() : 0);
}

// @0x14297fc00
void Value::SetAsCharacterHandle(CharacterHandle* pchar)
{
    if (T.Type != CHARACTER || V.pCharHandle != pchar)
    {
        DropRefs();
        T.Type        = CHARACTER;
        V.pCharHandle = pchar;
        if (pchar)
            pchar->AddRef();
    }
}

// @0x14297fc40
void Value::SetAsFunction(const FunctionRefBase& func)
{
    if (T.Type != FUNCTION || V.FunctionValue.Function != func.Function)
    {
        DropRefs();
        T.Type = FUNCTION;
        V.FunctionValue.Init(func);
    }
}

// @0x14297fcb0
void Value::SetAsObject(Object* pobj)
{
    if (pobj && pobj->IsFunction())
        SetAsFunction(pobj->ToFunction());
    else if (T.Type != OBJECT || V.pObjectValue != pobj)
    {
        DropRefs();
        T.Type         = OBJECT;
        V.pObjectValue = pobj;
        if (pobj)
            pobj->AddRef();
    }
}

// @0x14297fdb0
void Value::SetAsObjectInterface(ObjectInterface* pobj)
{
    if (pobj->IsASCharacter())
        SetAsCharacter(pobj->ToCharacter());
    else
        SetAsObject(pobj->ToASObject());
}

// @0x14297fe60
void Value::SetAsResolveHandler(const FunctionRefBase& func)
{
    DropRefs();
    T.Type = RESOLVEHANDLER;
    V.FunctionValue.Init(func);
}

// @0x1429889c0
bool Object::SetMemberFlags(ASStringContext* psc, const ASString& name, const UByte flags)
{
    Member member;
    if (FindMember(psc, name, &member))
    {
        member.mValue.T.PropFlags = flags;
        Members.Set(name, member);
        return true;
    }
    return false;
}

// @0x142988930
bool AvmCharacter::SetMemberFlags(ASStringContext* psc, const ASString& name, const UByte flags)
{
    Ptr<Object> obj = GetASObject();
    return obj ? obj->SetMemberFlags(psc, name, flags) : false;
}

// @0x14298dcb0
void AvmCharacter::Set__proto__(ASStringContext* psc, Object* protoObj)
{
    Ptr<Object> obj = GetASObject();
    if (obj)
        obj->Set__proto__(psc, protoObj);
    pProto = protoObj;
}

// @0x1429926f0
bool AvmCharacter::Unwatch(ASStringContext* psc, const ASString& prop)
{
    Ptr<Object> obj = GetASObject();
    return obj ? obj->Unwatch(psc, prop) : false;
}

// @0x142994660
void AvmCharacter::VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags,
                                const ObjectInterface*) const
{
    Ptr<Object> obj = GetASObject();
    if (obj)
        obj->VisitMembers(psc, pvisitor, visitFlags, this);
}

// @0x142994bb0
bool AvmCharacter::Watch(ASStringContext* psc, const ASString& prop, const FunctionRef& callback, const Value& userData)
{
    Ptr<Object> obj = GetASObject();
    return obj ? obj->Watch(psc, prop, callback, userData) : false;
}

// @0x14298a480
void AvmCharacter::SetProtoToPrototypeOf(ObjectInterface* psrcObj)
{
    Value            prototype;
    ASStringContext* psc = GetASEnvironment()->GetSC();
    if (psrcObj->GetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), &prototype))
        Set__proto__(psc, prototype.ToObject(NULL));
}

// @0x14298dd70
void MovieClipObject::Set__proto__(ASStringContext* psc, Object* protoObj)
{
    Object::Set__proto__(psc, protoObj);
    // The proto is reset to 0 on unload.
    if (protoObj && protoObj->GetObjectType() != Object_MovieClipObject)
    {
        // Any button handler name on the new prototype chain.
        struct MemberVisitor : ObjectInterface::MemberVisitor
        {
            Ptr<MovieClipObject> obj;
            ASStringContext*     pStringContext;

            MemberVisitor(ASStringContext* psc, MovieClipObject* _obj) : obj(_obj), pStringContext(psc) {}

            // @0x142994160
            virtual void Visit(const ASString& name, const Value& val, UByte flags)
            {
                SF_UNUSED2(val, flags);
                if (GetButtonEventNameMask(pStringContext, name) != 0)
                    obj->HasButtonHandlers = true;
            }
        } visitor(psc, this);
        pProto->VisitMembers(psc, &visitor,
                             ObjectInterface::VisitMember_Prototype | ObjectInterface::VisitMember_DontEnum |
                                 ObjectInterface::VisitMember_NamesOnly);
    }
}

// @0x142994e10
void AmpMarker::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Amp));
}

// @0x142994e50
void AsBroadcaster::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_AsBroadcaster));
}

// @0x142992680
bool GlobalContext::UnregisterClassA(ASStringContext* psc, const ASString& className)
{
    if (!ClassHash_GetCaseCheck(&RegisteredClasses, className, psc->IsCaseSensitive()))
        return false;
    ClassHash_RemoveCaseCheck(&RegisteredClasses, className, psc->IsCaseSensitive());
    return true;
}

// MS2-FUNCTIONAL the exe keeps this in r10 across the IsLeapYear call (callee register use known in its TU)
// @0x142992900
void DateObject::UpdateGMT()
{
    Time  = LTime - LocalOffset;
    Date  = LDate - LocalOffset;
    JDate = LJDate;
    Year  = LYear;
    if (Time >= 86400000 || Time < 0)
    {
        int days = (Time + 864000000) / 86400000 - 10;
        JDate += days;
        Time -= days * 86400000;
        if (JDate >= (Date_IsLeapYear(Year) ? 366 : 365))
        {
            JDate -= IsLeapYear(Year) ? 366 : 365;
            Year++;
        }
        else if (JDate < 0)
        {
            // The exe adds only the leap day here (not the length of the previous year).
            Year--;
            JDate += IsLeapYear(Year);
        }
    }
}

// MS2-FUNCTIONAL the exe keeps this in r10 across the IsLeapYear call (callee register use known in its TU)
// @0x142992b00
void DateObject::UpdateLocal()
{
    LTime  = Time + LocalOffset;
    LDate  = Date + LocalOffset;
    LJDate = JDate;
    LYear  = Year;
    if (LTime >= 86400000 || LTime < 0)
    {
        int days = (LTime + 864000000) / 86400000 - 10;
        LJDate += days;
        LTime -= days * 86400000;
        if (LJDate >= (Date_IsLeapYear(LYear) ? 366 : 365))
        {
            LJDate -= IsLeapYear(LYear) ? 366 : 365;
            LYear++;
        }
        else if (LJDate < 0)
        {
            LYear--;
            LJDate += IsLeapYear(LYear) ? 366 : 365;
        }
    }
}

// @0x142994fe0
void DateObject::commonInit(Environment* penv)
{
    Date        = 0;
    Time        = 0;
    Year        = 0;
    JDate       = 0;
    LDate       = 0;
    LTime       = 0;
    LYear       = 0;
    LJDate      = 0;
    LocalOffset = 0;
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Date));
}

// @0x142995040
void MouseObject::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Mouse));
}

// @0x142995080
void MovieClipLoader::commonInit(Environment* penv)
{
    ASStringContext* psc = penv->GetSC();
    Set__proto__(psc, penv->GetPrototype(ASBuiltin_MovieClipLoader));
    // AsBroadcaster::Initialize, its InitializeProto inlined.
    ObjectInterface* pobj = this;
    if (pobj)
        NameFunction::AddConstMembers(pobj, psc, AsBroadcasterProto::FunctionTable, PropFlags::PropFlag_DontEnum);
    AsBroadcaster::InitializeInstance(psc, pobj);
}

// @0x142995100
void Selection::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_Selection));
}

// @0x142995140
void StringObject::commonInit(Environment* penv)
{
    Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_String));
}

// @0x142986790
bool MovieClipObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    SetMemberCommon(penv->GetSC(), name, val);
    return Object::SetMember(penv, name, val, flags);
}

// @0x142987280
bool SharedObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    if (name == "data")
        return true;
    return Object::SetMember(penv, name, val, flags);
}

static inline UserEventHandler* GetUserEventHandler(MovieImpl* pmovie)
{
    return *(UserEventHandler**)((UByte*)pmovie + 0x230);
}

// @0x142980240
void MouseCtorFunction::SetCursorType(const FnCall& fn)
{
    fn.Result->SetUndefined();
    unsigned   cursorShape = MouseCursorEvent::ARROW;
    unsigned   mouseIndex  = 0;
    MovieImpl* proot       = fn.Env->GetTarget()->GetMovieImpl();
    if (fn.NArgs > 0)
        cursorShape = (unsigned)fn.Arg(0).ToNumber(fn.Env);
    if (fn.NArgs >= 2)
        mouseIndex = (unsigned)fn.Arg(1).ToNumber(fn.Env);
    if (GetUserEventHandler(proot))
    {
        GetUserEventHandler(proot)->HandleEvent(
            (Movie*)proot, MouseCursorEvent((MouseCursorEvent::CursorShapeType)cursorShape, mouseIndex));
    }
    else
        fn.Env->LogScriptWarning("No user event handler interface is installed; Mouse.setCursorType failed.");
}

// @0x142980380
bool MouseCtorFunction::SetCursorType(MovieImpl* proot, unsigned mouseIndex, unsigned cursorType)
{
    if (GetUserEventHandler(proot))
    {
        MouseCursorEvent evt(Event::DoSetMouseCursor, mouseIndex);
        evt.mCursorShape = cursorType;
        GetUserEventHandler(proot)->HandleEvent((Movie*)proot, evt);
        return true;
    }
    return false;
}

// @0x1429891c0
void MovieRoot::SetMovie(MovieImpl* pmovie)
{
    pMovieImpl     = pmovie;
    pGlobalContext = *SF_HEAP_NEW(pmovie->GetMovieHeap()) GlobalContext(pmovie);
}

// @0x1429804c0
void SharedObject::SetDataObject(Environment* penv, Object* pobj)
{
    Object::SetMember(penv, penv->CreateConstString("data"), Value(pobj));
}

// @0x142989250
bool SharedObject::SetNameAndLocalPath(const String& name, const String& localPath)
{
    const char* pstr;
    for (UInt32 c = name.GetFirstCharAt(0, &pstr); c; c = name.GetNextChar(&pstr))
    {
        switch (c)
        {
        case '~': case '%': case '&': case '\\': case ';': case ':': case '"': case '\'':
        case ',': case '<': case '>': case '?': case '#':
            return false;
        }
        if (SFiswspace((wchar_t)c))
            return false;
    }
    Name      = name;
    LocalPath = localPath;
    return true;
}

// @0x142989390
void AvmSprite::SetNoFill()
{
    DrawingContext* pdc = GetDrawingContext();
    AcquirePath(true);
    pdc->SetNoFill();
}

// @0x142989400
void AvmSprite::SetNoLine()
{
    DrawingContext* pdc = GetDrawingContext();
    if (!pdc->NoLine())
    {
        AcquirePath(false);
        pdc->SetNoLine();
    }
}

// @0x142992540
void MovieClipObject::TrackMemberButtonHandler(ASStringContext* psc, const ASString& name, bool deleteFlag)
{
    if (name.GetSize() > 2 && name[0] == 'o' && name[1] == 'n')
    {
        Value val;
        if (GetMemberRaw(psc, name, &val))
        {
            // Already set: setting it again changes nothing.
            if (!deleteFlag)
                return;
        }
        else
        {
            if (deleteFlag)
                return;
        }
        UInt16 bemask;
        if ((bemask = GetButtonEventNameMask(psc, name)) != 0)
        {
            if (deleteFlag)
                ButtonEventMask &= ~bemask;
            else
                ButtonEventMask |= bemask;
        }
    }
}

// @0x142988690
void MovieClipObject::SetMemberCommon(ASStringContext* psc, const ASString& name, const Value& val)
{
    Ptr<Sprite> spr = pSprite;
    // The root clip takes no button handlers.
    if (!spr || spr->GetTopParent() != spr)
        TrackMemberButtonHandler(psc, name);

    if (spr && name.IsBuiltin())
    {
        AvmCharacter* avmSpr =
            static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(spr->GetAvmObjImpl()));
        if (name == psc->GetBuiltin(ASBuiltin_rendererString))
        {
            spr->SetRendererString(val.ToString(avmSpr->GetASEnvironment()));
        }
        else if (name == psc->GetBuiltin(ASBuiltin_rendererFloat))
        {
            spr->SetRendererFloat((float)val.ToNumber(avmSpr->GetASEnvironment()));
        }
        else if (name == psc->GetBuiltin(ASBuiltin_rendererMatrix))
        {
            Ptr<Object> pobj = val.ToObject(avmSpr->GetASEnvironment());
            if (pobj)
            {
                if (pobj->GetObjectType() == Object_Array)
                {
                    ArrayObject* parr = static_cast<ArrayObject*>(pobj.GetPtr());
                    float        matrix[16];
                    unsigned     count = parr->GetSize();
                    if ((int)count > 16)
                        count = 16;
                    for (unsigned i = 0; i < count; ++i)
                        matrix[i] = (float)parr->GetElementPtr(i)->ToNumber(avmSpr->GetASEnvironment());
                    spr->SetRendererMatrix(matrix, count);
                }
            }
        }
    }
}

// @0x142988b60
bool MovieClipObject::SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val, const PropFlags& flags)
{
    SetMemberCommon(psc, name, val);
    return Object::SetMemberRaw(psc, name, val, flags);
}

// MS2-FUNCTIONAL the exe merges both case lookups into one iterator slot and converts this back from the
// object pointer with a null test (cmove); the rest differs in register choice only
// @0x1429867f0
bool Object::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    static const Value notsetVal(Value::UNSET);
    PropFlags _flags;

    MemberSet::Iterator it = MemberHash_FindCaseCheck(&Members, name, penv->IsCaseSensitive());
    Member*             pmember;
    if (it == MemberSet::Iterator(0, 0))
    {
        // A property set through the prototype chain runs the prototype's setter.
        for (Object* pproto = Get__proto__(); pproto != 0; pproto = pproto->Get__proto__())
        {
            if (pproto->ArePropertiesSet)
            {
                MemberSet::Iterator protoit =
                    MemberHash_FindCaseCheck(&pproto->Members, name, penv->IsCaseSensitive());
                if (protoit != MemberSet::Iterator(0, 0))
                {
                    if (protoit->Second.mValue.IsProperty())
                        it = protoit;
                    break;
                }
            }
        }
    }
    if (it != MemberSet::Iterator(0, 0))
    {
        pmember = &(*it).Second;
        _flags  = pmember->GetMemberFlags();
        if (_flags.GetReadOnly())
            return false;
        if (pmember->mValue.IsProperty())
        {
            Value propVal = pmember->mValue;
            // A character's script object passes the character as this.
            Ptr<InteractiveObject> paschar = GetASCharacter();
            if (paschar)
                propVal.SetPropertyValue(penv, AS2::ToAvmCharacter(paschar), val);
            else
                propVal.SetPropertyValue(penv, this, val);
            return true;
        }
    }
    else
    {
        _flags  = flags;
        pmember = 0;
    }

    Value        newVal;
    const Value* pval = &val;

    if (penv && pWatchpoints)
    {
        if (InvokeWatchpoint(penv, name, val, &newVal))
            pval = &newVal;
    }

    if (!pmember)
        return SetMemberRaw(penv->GetSC(), name, *pval, _flags);

    if (val.IsProperty())
        ArePropertiesSet = true;

    if (penv->IsCaseSensitive())
    {
        if (name == penv->GetBuiltin(ASBuiltin___proto__))
        {
            if (val.IsSet())
            {
                Set__proto__(penv->GetSC(), val.ToObject(penv));
                penv->InvalidateOptAdvanceList();
            }
            pval = &notsetVal;
        }
        else if (name == penv->GetBuiltin(ASBuiltin___resolve))
        {
            if (val.IsSet())
                ResolveHandler = val.ToFunction(penv);
            pval = &notsetVal;
        }
        else if (name == penv->GetBuiltin(ASBuiltin_onEnterFrame))
            penv->InvalidateOptAdvanceList();
    }
    else
    {
        name.ResolveLowercase();
        if (penv->GetBuiltin(ASBuiltin___proto__).GetNode()->pLower == name.GetNode()->pLower)
        {
            if (val.IsSet())
            {
                Set__proto__(penv->GetSC(), val.ToObject(penv));
                penv->InvalidateOptAdvanceList();
            }
            pval = &notsetVal;
        }
        else if (penv->GetBuiltin(ASBuiltin___resolve).GetNode()->pLower == name.GetNode()->pLower)
        {
            if (val.IsSet())
                ResolveHandler = val.ToFunction(penv);
            pval = &notsetVal;
        }
        else if (name == penv->GetBuiltin(ASBuiltin_onEnterFrame))
            penv->InvalidateOptAdvanceList();
    }
    pmember->mValue = *pval;
    return true;
}

// @0x1429947f0
void Object::VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags,
                          const ObjectInterface* instance) const
{
    ASStringHash_GC<Member>::ConstIterator it = Members.Begin();
    while (it != Members.End())
    {
        const PropFlags& memberFlags = it->Second.GetMemberFlags();
        if (!memberFlags.GetDontEnum() || (visitFlags & VisitMember_DontEnum))
        {
            const Value& value = it->Second.GetMemberValue();
            if (value.IsSet())
                pvisitor->Visit(it->First, value, memberFlags.Flags);
            else
            {
                // An unset value is fetched through the instance the visit started on.
                Value value;
                if (!(visitFlags & VisitMember_NamesOnly))
                {
                    ObjectInterface* pobj =
                        const_cast<ObjectInterface*>(instance ? instance : static_cast<const ObjectInterface*>(this));
                    pobj->GetMemberRaw(psc, it->First, &value);
                }
                pvisitor->Visit(it->First, value, memberFlags.Flags);
            }
        }
        ++it;
    }

    if ((visitFlags & VisitMember_Prototype) && pProto)
        pProto->VisitMembers(psc, pvisitor, visitFlags, instance ? instance : this);
}

// @0x142988bb0
bool Object::SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val, const PropFlags& flags)
{
    const Value*      pval = &val;
    MemberSet::Iterator it;

    // An array stored as _listeners marks the object for the listener leak check.
    if (!IsListenerSet && val.IsObject() && name == psc->GetBuiltin(ASBuiltin__listeners))
    {
        Object* pobject = val.ToObject(0);
        if (pobject && pobject->GetObjectType() == Object_Array)
            IsListenerSet = true;
    }

    if (psc->IsCaseSensitive())
    {
        if (name == psc->GetBuiltin(ASBuiltin___proto__))
        {
            if (val.IsSet())
            {
                Set__proto__(psc, val.ToObject(0));
                psc->InvalidateOptAdvanceList();
            }
            pval = &Object_NotsetVal;
        }
        else if (name == psc->GetBuiltin(ASBuiltin___resolve))
        {
            if (val.IsSet())
                ResolveHandler = val.ToFunction(0);
            pval = &Object_NotsetVal;
        }
        else if (name == psc->GetBuiltin(ASBuiltin_onEnterFrame))
            psc->InvalidateOptAdvanceList();
        SPInt index = MemberHash_FindIndex(&Members, name);
        it = MemberSet::Iterator(index < 0 ? 0 : reinterpret_cast<MemberSet*>(&Members), index < 0 ? 0 : index);
    }
    else
    {
        name.ResolveLowercase();
        if (psc->GetBuiltin(ASBuiltin___proto__).GetNode()->pLower == name.GetNode()->pLower)
        {
            if (val.IsSet())
            {
                Set__proto__(psc, val.ToObject(0));
                psc->InvalidateOptAdvanceList();
            }
            pval = &Object_NotsetVal;
        }
        else if (psc->GetBuiltin(ASBuiltin___resolve).GetNode()->pLower == name.GetNode()->pLower)
        {
            if (val.IsSet())
                ResolveHandler = val.ToFunction(0);
            pval = &Object_NotsetVal;
        }
        else if (name == psc->GetBuiltin(ASBuiltin_onEnterFrame))
            psc->InvalidateOptAdvanceList();
        ASStringNoCaseKey ikey(name);
        it = MemberSet::Iterator(reinterpret_cast<MemberSet*>(&Members), MemberHash_FindIndexNoCase(&Members, ikey));
        if (it.GetIndex() < 0)
            it = MemberSet::Iterator(0, 0);
    }

    if (val.IsProperty())
        ArePropertiesSet = true;

    if (!it.IsEnd())
        it->Second.mValue = *pval;
    else
        Members.Set(name, Member(*pval, flags));
    return true;
}

// @0x142982ba0
bool ArrayObject::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    int idx;
    if (penv->GetBuiltin(ASBuiltin_length).CompareBuiltIn_CaseCheck(name, penv->IsCaseSensitive()))
    {
        int nlen = val.ToInt32(0);
        Resize(nlen < 0 ? 0 : nlen);
        LengthValueOverriden = true;
        // The length value itself is kept as a member.
        return Object::SetMember(penv, name, val, flags);
    }
    else if ((idx = ParseIndex(name)) >= 0)
    {
        LengthValueOverriden = false;
        if (idx >= (int)Elements.GetSize())
            Resize(idx + 1);
        if (Elements[idx] == 0)
            Elements[idx] = SF_HEAP_NEW(penv->GetHeap()) Value();
        *Elements[idx] = val;
        return true;
    }
    return Object::SetMember(penv, name, val, flags);
}

// @0x1429944d0
void ArrayObject::VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags,
                               const ObjectInterface* instance) const
{
    // The members first: for..in pushes everything and pops it back, so the elements come out first.
    Object::VisitMembers(psc, pvisitor, visitFlags, instance);

    UPInt i, n = Elements.GetSize();
    UPInt n1   = (n > ASBuiltinConst_DigitMax_) ? (ASBuiltinConst_DigitMax_ + 1) : n;

    for (i = 0; i < n1; ++i)
    {
        if (!Elements[i])
            continue;
        pvisitor->Visit(psc->GetBuiltin((ASBuiltinType)(ASBuiltin_0 + i)), *Elements[i], 0);
    }
    for (; i < n; ++i)
    {
        if (!Elements[i])
            continue;

        LongFormatter f(i);
        f.Convert();
        StringDataPtr result = f.GetResult();

        pvisitor->Visit(psc->CreateString(result.ToCStr(), result.GetSize()), *Elements[i], 0);
    }
}

// @0x14298a260
void Value::SetPropertyValue(Environment* penv, ObjectInterface* pthis, const Value& val)
{
    if (T.Type == PROPERTY && penv)
    {
        if (V.pProperty->SetterMethod.Function)
        {
            Value result;
            penv->Push(val);
            V.pProperty->SetterMethod.Invoke(FnCall(&result, pthis, penv, 1, penv->GetTopIndex()));
            penv->Drop1();
        }
        else if (penv->IsVerboseActionErrors())
            penv->LogScriptError("Setter method is null.");
    }
}

// MS2-FUNCTIONAL the exe keeps the constructor function in a register across Set_constructor (unity build)
// @0x14298a3d0
void FunctionObject::SetProtoAndCtor(ASStringContext* psc, Object* pprototype)
{
    Set__proto__(psc, pprototype);
    FunctionRef ctor = pprototype->Get_constructor(psc);
    if (!ctor.IsNull())
        Set_constructor(psc, ctor);
}

// MS2-FUNCTIONAL register permutation (rbx / rsi / rdi)
// @0x14298a520
void FunctionObject::SetPrototype(ASStringContext* psc, Object* pprototype)
{
    SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_prototype), Value(pprototype));
}

// @0x14298dc00
void ObjectInterface::Set__constructor__(ASStringContext* psc, const FunctionRef& ctorFunc)
{
    SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin___constructor__), Value(ctorFunc),
                 PropFlags(PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum));
}

// @0x14298de30
void ObjectInterface::Set_constructor(ASStringContext* psc, const FunctionRef& ctorFunc)
{
    SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_constructor), Value(ctorFunc),
                 PropFlags(PropFlags::PropFlag_DontDelete | PropFlags::PropFlag_DontEnum));
}

// @0x142990240
void Value::StringConcat(Environment* penv, const ASString& str)
{
    ASString result(ToString(penv) + str);
    DropRefs();
    T.Type        = STRING;
    V.pStringNode = result.GetNode();
    V.pStringNode->AddRef();
}

// @0x142990a10
bool StringToNumber(Number* result, const char* str)
{
    char*  tail = 0;
    size_t len  = strlen(str);
    if (str[0] == '0' && SFtolower(str[1]) == 'x')
        *result = (Number)strtol(str, &tail, 0);
    else if (strcspn(str, ".eE") != len)
        *result = SFstrtod(str, &tail);
    else
    {
        const char* p    = str;
        int         sign = 1;
        if (*p == '-')
        {
            sign = -1;
            p++;
            len--;
        }
        else if (*p == '+')
        {
            p++;
            len--;
        }
        if (*p == '0' && strspn(p, "01234567") == len)
            *result = (Number)(strtol(p, &tail, 8) * sign);
        else
            *result = SFstrtod(p, &tail) * sign;
    }
    return tail != str && *tail == 0;
}

// @0x142990be0
void Value::Sub(Environment* penv, int v2)
{
    Number v1 = ToNumber(penv);
    if (T.Type >= STRING)
        DropRefs();
    T.Type         = NUMBER;
    NV.NumberValue = v1 - (Number)v2;
}

// @0x142990c60
Object* ObjectInterface::ToASObject()
{
    return IsASObject() ? static_cast<Object*>(this) : 0;
}

// @0x142990c90
const Object* ObjectInterface::ToASObject() const
{
    return IsASObject() ? static_cast<const Object*>(this) : 0;
}

// @0x142990d60
AvmCharacter* Value::ToAvmCharacter(const Environment* penv) const
{
    InteractiveObject* pchar = ToCharacter(penv);
    return pchar ? GFx::AS2::ToAvmCharacter(pchar) : 0;
}

// @0x142990f20
bool Value::ToBool(const Environment* penv) const
{
    if (T.Type == STRING)
    {
        if (V.pStringNode->Size == 0)
            return false;
        if (penv->GetVersion() <= 6)
        {
            Number num;
            if (!StringToNumber(&num, V.pStringNode->pData) || NumberUtil::IsNaN(num))
                return false;
            return num != 0;
        }
        return true;
    }
    else if (T.Type == NUMBER)
    {
        if (NumberUtil::IsNaN(NV.NumberValue))
            return false;
        return NV.NumberValue != 0;
    }
    else if (T.Type == INTEGER)
        return NV.Int32Value != 0;
    else if (T.Type == BOOLEAN)
        return V.BooleanValue;
    else if (T.Type == OBJECT)
        return V.pObjectValue != 0;
    else if (T.Type == CHARACTER)
        return ToCharacter(penv) != 0;
    else if (T.Type == FUNCTION)
        return V.FunctionValue.Function != 0;
    else if (T.Type == FUNCTIONNAME)
        return true;
    return false;
}

// @0x1429910b0
InteractiveObject* Value::ToCharacter(const Environment* penv) const
{
    if (T.Type == CHARACTER && penv && V.pCharHandle)
    {
        DisplayObject* pdisp = V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
        if (pdisp)
            return pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
    }
    return 0;
}

// @0x142991110
ASString Value::ToDebugString(Environment* penv) const
{
    return ToStringImpl(penv, -1, 1);
}

// @0x142991210
SInt32 Value::ToInt32(Environment* penv) const
{
    if (T.Type == INTEGER)
        return NV.Int32Value;

    Number v = ToNumber(penv);
    if (NumberUtil::IsNaNOrInfinity(v) || v == 0)
        return 0;
    if (v >= -2147483648.0 && v <= 2147483647.0)
        return (SInt32)v;

    UInt32 uv = (UInt32)fmod(floor(fabs(v)), 4294967296.0);
    if (v < 0)
        return -(SInt32)uv;
    return (SInt32)uv;
}

// MS2-FUNCTIONAL the exe keeps the null test of the delete after the size check
// @0x142992780
bool Object::Unwatch(ASStringContext* psc, const ASString& prop)
{
    if (pWatchpoints && WatchpointHash_GetCaseCheck(pWatchpoints, prop, psc->IsCaseSensitive()))
    {
        WatchpointHash_RemoveCaseCheck(pWatchpoints, prop, psc->IsCaseSensitive());
        ASStringHash_GC<Watchpoint>* pwatchpoints = pWatchpoints;
        if (pwatchpoints->GetSet().GetSize() == 0)
        {
            if (pwatchpoints)
            {
                WatchpointHash_Destruct(pwatchpoints);
                SF_FREE(pwatchpoints);
            }
            pWatchpoints = 0;
        }
        return true;
    }
    return false;
}

// @0x142991c60
FunctionRef Value::ToResolveHandler() const
{
    if (T.Type == RESOLVEHANDLER)
        return V.FunctionValue;
    return FunctionRef();
}

// @0x1429923c0
ASString Value::ToStringVersioned(Environment* penv, unsigned version) const
{
    if (IsUndefined())
    {
        if (version > 0 && version <= 6)
            return penv->GetBuiltin(ASBuiltin_empty_);
        return penv->GetBuiltin(ASBuiltin_undefined);
    }
    return ToStringImpl(penv, -1, 0);
}

// @0x142992440
UInt32 Value::ToUInt32(Environment* penv) const
{
    if (T.Type == INTEGER)
        return NV.UInt32Value;

    Number v = ToNumber(penv);
    if (NumberUtil::IsNaNOrInfinity(v) || v == 0)
        return 0;
    if (v >= 0 && v <= 4294967295.0)
        return (UInt32)v;

    UInt32 uv = (UInt32)fmod(floor(fabs(v)), 4294967296.0);
    if (v < 0)
        uv = 0u - uv;
    return uv;
}


// @0x142981b70
void Value::SetInt_Call(int val)
{
    SetInt(val);
}

// @0x142981bc0
void Environment::SetInvalidTarget(InteractiveObject* ptarget)
{
    Target          = ptarget;
    IsInvalidTarget = true;
    StringContext.UpdateVersion(ptarget->GetVersion());
}

// @0x142981650
void AvmSprite::SetHasButtonHandlers(bool has)
{
    MovieClipObject* pobj = GetMovieClipObject();
    if (pobj)
        pobj->HasButtonHandlers = has;
}

// @0x142981d80
bool MovieRoot::SetLevelMovie(int level, Sprite* psprite)
{
    pMovieImpl->SetLevelMovie(level, psprite);
    return true;
}

// @0x142981da0
void AvmSprite::SetLineStyle(float lineWidth, unsigned rgba, bool hinting, unsigned scaling, unsigned caps,
                             unsigned joins, float miterLimit)
{
    DrawingContext* pdc = GetDrawingContext();
    pdc->ChangeLineStyle(Render::PixelsToTwips(lineWidth), rgba, hinting, scaling, caps, joins, miterLimit);
}

// @0x142981df0
void Environment::SetLocal(const ASString& varname, const Value& val)
{
    if (LocalFrames.GetSize() == 0)
        return;
    if (!LocalFrames[LocalFrames.GetSize() - 1])
        return;

    Value* pvalue = const_cast<Value*>(FindLocal(varname));
    if (!pvalue)
        AddLocal(varname, val);
    else
        *pvalue = val;
}

// @0x142981e70
void FunctionRefBase::SetLocalFrame(LocalFrame* localFrame, bool weakRef)
{
    if (pLocalFrame && !(Flags & FuncRef_Weak))
        pLocalFrame->Release();
    pLocalFrame = localFrame;
    if (weakRef)
        Flags |= FuncRef_Weak;
    else
        Flags &= ~FuncRef_Weak;
    if (pLocalFrame && !(Flags & FuncRef_Weak))
        pLocalFrame->AddRef();
}

// @0x14298b9f0
void Value::SetString_Call(const ASString& str)
{
    SetString(str);
}

// @0x14298ba30
void Environment::SetTarget(InteractiveObject* ptarget)
{
    Target          = ptarget;
    IsInvalidTarget = false;
    StringContext.UpdateVersion(ptarget->GetVersion());
}

// @0x14298bb20
void Environment::SetTargetOnConstruct(InteractiveObject* ptarget)
{
    SetTarget(ptarget);
    StringContext.pContext = (!ptarget ? 0 : ToAvmCharacter(ptarget))->GetGC();
}

// @0x14298fe50
Sprite* AvmSprite::SpriteGetTarget_Call(const FnCall& fn)
{
    return SpriteGetTarget(fn);
}

// @0x14298c9e0
void Value::SetUInt_Call(unsigned val)
{
    SetUInt(val);
}

// @0x14298cc30
void BooleanObject::SetValue(Environment* penv, const Value& v)
{
    BValue = v.ToBool(penv);
}

// @0x14298cc50
void NumberObject::SetValue(Environment* penv, const Value& v)
{
    NumberValue = v.ToNumber(penv);
}

// @0x14298cc80
void StringObject::SetValue(Environment* penv, const Value& v)
{
    ASString s(v.ToString(penv));
    sValue = s.ToCStr();
}

// @0x142990c40
void FnCall::ThisPtrError_Call(const char* pclassName) const
{
    ThisPtrError(pclassName);
}

// @0x142990d00
AvmCharacter* ObjectInterface::ToAvmCharacter()
{
    return IsASCharacter() ? static_cast<AvmCharacter*>(this) : 0;
}

// @0x142990d30
const AvmCharacter* ObjectInterface::ToAvmCharacter() const
{
    return IsASCharacter() ? static_cast<const AvmCharacter*>(this) : 0;
}

// @0x142990e40
const AvmSprite* ObjectInterface::ToAvmSprite() const
{
    return GetObjectType() == Object_Sprite ? static_cast<const AvmSprite*>(this) : 0;
}

// @0x142990e70
AvmSprite* ObjectInterface::ToAvmSprite()
{
    return GetObjectType() == Object_Sprite ? static_cast<AvmSprite*>(this) : 0;
}

// @0x142991080
const InteractiveObject* ObjectInterface::ToCharacter() const
{
    return IsASCharacter() ? static_cast<const AvmCharacter*>(this)->GetDispObj() : 0;
}

// @0x142991190
FunctionRef Value::ToFunction_Call(const Environment* penv) const
{
    switch (T.Type)
    {
    case FUNCTION:
        return V.FunctionValue;
    case FUNCTIONNAME:
        return ResolveFunctionName(penv);
    }
    return FunctionRef();
}

// @0x142991810
ObjectInterface* Value::ToObjectInterface_Call(const Environment* penv) const
{
    return ToObjectInterface(penv);
}

// @0x142991d00
Sprite* ObjectInterface::ToSprite_Call()
{
    return ToSprite();
}

// @0x142991050
InteractiveObject* ObjectInterface::ToCharacter_Call()
{
    return ToCharacter();
}

// @0x142991cd0
const Sprite* ObjectInterface::ToSprite() const
{
    return GetObjectType() == Object_Sprite
               ? static_cast<const Sprite*>(static_cast<const AvmCharacter*>(this)->GetDispObj())
               : 0;
}

// @0x142991e10
const char* NumberObject::ToString_Call(int radix)
{
    return ToString(radix);
}


// @0x1429814c0
void ArrayObject::SetElement(int i, const Value& val)
{
    if (i >= 0 && i < GetSize())
    {
        LengthValueOverriden = false;
        if (!Elements[i])
            Elements[i] = SF_HEAP_AUTO_NEW(this) Value();
        *Elements[i] = val;
    }
}

// @0x142981560
void ArrayObject::SetElementSafe(int i, const Value& val)
{
    LengthValueOverriden = false;
    if (i >= GetSize())
        Resize(i + 1);
    if (!Elements[i])
        Elements[i] = SF_HEAP_AUTO_NEW(this) Value();
    *Elements[i] = val;
}

// @0x14298ee10
void ArrayObject::ShallowCopyFrom(const ArrayObject& ao)
{
    ArrayObjectElements_Resize(&Elements, ao.Elements.GetSize());
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
        Elements[i] = ao.Elements[i];
}

// @0x142990960
ASString StringProto::StringSubstring(const ASString& self, int start, int length)
{
    if (length == 0)
        return ASString(self.GetManager()->GetEmptyStringNode());

    if (start < 0)
        start = 0;

    int utf8Len = self.GetLength();
    if (start >= utf8Len)
        return ASString(self.GetManager()->GetEmptyStringNode());

    if (length < 0 || start + length > utf8Len)
        length = utf8Len - start;

    return ASString(self.SubstringNode(start, start + length));
}

// @0x142990b70
void Value::Sub_Call(Environment* penv, const Value& v)
{
    Number lhs = ToNumber(penv);
    Number rhs = v.ToNumber(penv);
    SetNumber(lhs - rhs);
}

// @0x142992e30
void ValidateRect(ASRect* r)
{
    if (NumberUtil::IsNaN(r->x1))
        r->x1 = 0;
    if (NumberUtil::IsNaN(r->x2))
        r->x2 = 0;
    if (NumberUtil::IsNaN(r->y1))
        r->y1 = 0;
    if (NumberUtil::IsNaN(r->y2))
        r->y2 = 0;
}

// @0x142989d20
void PointObject::SetProperties_Call(ASStringContext* psc, const Value params[Point_NumProperties])
{
    SetProperties(psc, params);
}

// MS2-FUNCTIONAL the exe stores the number of the temporary value before its type
// @0x142989db0
void PointObject::SetProperties(Environment* penv, const GASPoint& pt)
{
    SetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_x), Value(pt.x));
    SetMemberRaw(penv->GetSC(), penv->GetBuiltin(ASBuiltin_y), Value(pt.y));
}


// @0x142991660
Object* Value::ToObject(const Environment* penv) const
{
    switch (T.Type)
    {
    case OBJECT:
        return V.pObjectValue;

    case FUNCTION:
        if (!V.FunctionValue.IsNull())
            return V.FunctionValue.GetObjectPtr();
        break;
    case FUNCTIONNAME:
        {
            FunctionRef funcRef = ResolveFunctionName(penv);
            if (!funcRef.IsNull())
                return funcRef.GetObjectPtr();
        }
        break;
    case PROPERTY:
        if (IsProperty())
        {
            InteractiveObject* ptarget = penv->GetTarget();
            AvmCharacter*      paschar = ptarget ? AS2::ToAvmCharacter(ptarget) : 0;
            if (paschar)
            {
                Value val;
                if (GetPropertyValue(const_cast<Environment*>(penv), paschar, &val))
                    return val.ToObject(penv);
            }
        }
        break;
    default:;
    }
    return 0;
}


// MS2-FUNCTIONAL the exe builds the found / end iterator in one temporary (no cmov) and stores the new table's
// null pointer as an immediate
// @0x142994c50
bool Object::Watch(ASStringContext* psc, const ASString& prop, const FunctionRef& callback, const Value& userData)
{
    Watchpoint wp;
    wp.Callback = callback;
    wp.UserData = userData;
    if (pWatchpoints == 0)
        pWatchpoints = SF_HEAP_NEW(psc->GetHeap()) ASStringHash_GC<Watchpoint>();

    WatchpointHash_SetCaseCheck(pWatchpoints, prop, wp, psc->IsCaseSensitive());
    return true;
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// @0x14297f2c0
template void GFx::ASStringHash_GC<GFx::AS2::Member>::Set(const GFx::ASString&, const GFx::AS2::Member&);

// @0x142992500
template GFx::AS2::Value* GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Top(unsigned) const;

// @0x1429925f0
template<> void Render::Matrix4F::Transpose()
{
    Matrix4F matDest(NoInit);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            matDest.M[j][i] = M[i][j];
    *this = matDest;
}

} // namespace Scaleform
// MS2-PIN: ??_7FnCall@AS2@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7?$LogBase@VFnCall@AS2@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x1431b5018
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PIN: ??_7MemberVisitor@ObjectInterface@AS2@GFx@Scaleform@@6B@ 0x143215400
// MS2-PIN: ??_7GlobalContext@AS2@GFx@Scaleform@@6B@ 0x143215af8
// MS2-PIN: ??_7?$RefCountBaseNTS@VGlobalContext@AS2@GFx@Scaleform@@$0BED@@Scaleform@@6B@ 0x143183600
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$0BED@@Scaleform@@6B@ 0x143183600
