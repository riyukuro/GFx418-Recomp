// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 gap functions of sfr_as2_06
// (lane sfr36): Stage.scaleMode / Stage.align setters, MovieRoot::SetVariableArray and SetVariableArraySize.
// MS2-UNIT: sfr_as2_06t
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429872b0-0x1429876f4 .text$mn
// MS2-RANGE: 0x14298d1e0-0x14298d73c .text$mn
// MS2-RANGE: 0x14298d760-0x14298da65 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_movieimplstates.h"
#include "../include/gfx/gfx_movieslots.h"
#include "../include/gfx/gfx_player.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// A property name against a constant one in the case mode of the movie; both lowercase twins are resolved,
// the constant's first.
static SF_FORCEINLINE bool ConstName_CompareCaseCheck(const ASString& constName, const ASString& name,
                                                      bool caseSensitive)
{
    if (caseSensitive)
        return constName == name;
    constName.ResolveLowercase();
    name.ResolveLowercase();
    return constName.GetNode()->pLower == name.GetNode()->pLower;
}

// A constant against a value string, always without case.
static SF_FORCEINLINE bool ConstName_CompareNoCase(const ASString& constName, const ASString& str)
{
    constName.ResolveLowercase();
    str.ResolveLowercase();
    return constName.GetNode()->pLower == str.GetNode()->pLower;
}

// The view alignment named by the first two letters of an uppercased Stage.align string.
static MovieSlots418::AlignType Stage_ParseAlign(const ASString& align)
{
    unsigned len = align.GetLength();
    if (len == 0)
        return MovieSlots418::Align_Center;
    unsigned long c0 = align.GetCharAt(0);
    unsigned long c1 = 0;
    if (len > 1)
        c1 = align.GetCharAt(1);
    switch (c0)
    {
    case 'T':
        if (c1 == 'L') return MovieSlots418::Align_TopLeft;
        if (c1 == 'R') return MovieSlots418::Align_TopRight;
        return MovieSlots418::Align_TopCenter;
    case 'L':
        if (c1 == 'T') return MovieSlots418::Align_TopLeft;
        if (c1 == 'B') return MovieSlots418::Align_BottomLeft;
        return MovieSlots418::Align_CenterLeft;
    case 'R':
        if (c1 == 'T') return MovieSlots418::Align_TopRight;
        if (c1 == 'B') return MovieSlots418::Align_BottomRight;
        return MovieSlots418::Align_CenterRight;
    case 'B':
        if (c1 == 'L') return MovieSlots418::Align_BottomLeft;
        if (c1 == 'R') return MovieSlots418::Align_BottomRight;
        return MovieSlots418::Align_BottomCenter;
    default:
        return MovieSlots418::Align_Center;
    }
}

// scaleMode and align go to the view of the movie (onResize fires on a switch to noScale); the rest is a plain
// member.
// MS2-FUNCTIONAL: the align letter tests are laid out as a branch tree in the exe
// @0x1429872b0
bool StageCtorFunction::SetMember(Environment* penv, const ASString& name, const Value& val, const PropFlags& flags)
{
    ASStringContext* psc = penv->GetSC();
    if (ConstName_CompareCaseCheck(psc->CreateConstString("scaleMode"), name, psc->IsCaseSensitive()))
    {
        ASString mode = val.ToString(penv);
        MovieSlots418::ScaleModeType oldMode = AsMovieSlots(pMovieRoot)->GetViewScaleMode();
        MovieSlots418::ScaleModeType newMode;
        if (ConstName_CompareNoCase(psc->CreateConstString("noScale"), mode))
            newMode = MovieSlots418::SM_NoScale;
        else if (ConstName_CompareNoCase(psc->CreateConstString("exactFit"), mode))
            newMode = MovieSlots418::SM_ExactFit;
        else if (ConstName_CompareNoCase(psc->CreateConstString("noBorder"), mode))
            newMode = MovieSlots418::SM_NoBorder;
        else
            newMode = MovieSlots418::SM_ShowAll;
        AsMovieSlots(pMovieRoot)->SetViewScaleMode(newMode);
        if (oldMode != newMode && newMode == MovieSlots418::SM_NoScale)
            NotifyOnResize(penv);
        return true;
    }
    if (!ConstName_CompareCaseCheck(psc->CreateConstString("align"), name, psc->IsCaseSensitive()))
        return Object::SetMember(penv, name, val, flags);
    ASString align(val.ToString(penv).ToUpperNode());
    AsMovieSlots(pMovieRoot)->SetViewAlignment(Stage_ParseAlign(align));
    return true;
}

// The movie loaded as _level<level>, 0 if none.
static SF_FORCEINLINE InteractiveObject* FindLevelMovie(const MovieImpl* pmovieImpl, int level)
{
    for (unsigned i = 0; i < pmovieImpl->MovieLevelsSize; i++)
    {
        if (pmovieImpl->pMovieLevels[i].Level == level)
            return pmovieImpl->pMovieLevels[i].pSprite;
    }
    return 0;
}

// The script environment of _level0 (it must exist).
static SF_FORCEINLINE Environment* Level0Env(const MovieImpl* pmovieImpl)
{
    AvmDisplayObjBase* pavm = FindLevelMovie(pmovieImpl, 0)->GetAvmObjImpl();
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
}

// The Array the path names, else a new one; the caller holds a reference.
static SF_FORCEINLINE ArrayObject* MovieRoot_FindOrNewArray(MovieImpl* pmovieImpl, Environment* penv,
                                                            const ASString& path, Value* pcur)
{
    Object* pobj;
    if (penv->GetVariable(path, pcur) && pcur->IsObject() && (pobj = pcur->ToObject(penv)) != 0 &&
        pobj->GetObjectType() == Object::Object_Array)
    {
        pobj->AddRef();
        return static_cast<ArrayObject*>(pobj);
    }
    return SF_HEAP_NEW(pmovieImpl->GetMovieHeap()) ArrayObject(Level0Env(pmovieImpl));
}

// Stores the array under the path on _level0, or (sticky / permanent) keeps it until the target exists.
static SF_FORCEINLINE bool MovieRoot_StoreArray(MovieRoot* proot, const ASString& path, ArrayObject* parray,
                                                MovieRoot::SetVarTypeArg setType)
{
    Value asval;
    asval.SetAsObject(parray);
    bool ok = Level0Env(proot->pMovieImpl)->SetVariable(path, asval, 0, setType == Movie::SV_Normal);
    if ((!ok && setType != Movie::SV_Normal) || setType == Movie::SV_Permanent)
        proot->AddStickyVariable(path, asval, setType);
    return ok;
}

// Writes count host values of one type into the array at path from index on, growing it as needed; a missing
// or non-array variable becomes a new Array.
// MS2-FUNCTIONAL: the level lookups and the value releases are inlined differently
// @0x14298d1e0
bool MovieRoot::SetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index, const void* pdata,
                                 unsigned count, SetVarTypeArg setType)
{
    if (!FindLevelMovie(pMovieImpl, 0))
        return false;
    Environment* penv = Level0Env(pMovieImpl);
    ASString     path(penv->CreateString(ppathToVar));
    Value        cur;
    ArrayObject* parray = MovieRoot_FindOrNewArray(pMovieImpl, penv, path, &cur);
    if ((unsigned)parray->GetSize() < index + count)
        parray->Resize((int)(index + count));
    switch (type)
    {
    case Movie::SA_Int:
        for (unsigned i = 0; i < count; i++)
            parray->SetElement((int)(index + i), Value((int)static_cast<const int*>(pdata)[i]));
        break;
    case Movie::SA_Double:
        for (unsigned i = 0; i < count; i++)
            parray->SetElement((int)(index + i), Value((Number) static_cast<const double*>(pdata)[i]));
        break;
    case Movie::SA_Float:
        for (unsigned i = 0; i < count; i++)
            parray->SetElement((int)(index + i), Value((Number) static_cast<const float*>(pdata)[i]));
        break;
    case Movie::SA_String:
        for (unsigned i = 0; i < count; i++)
        {
            ASString str(GetStringManager()->CreateString(static_cast<const char* const*>(pdata)[i]));
            parray->SetElement((int)(index + i), Value(str));
        }
        break;
    case Movie::SA_StringW:
        for (unsigned i = 0; i < count; i++)
        {
            ASString str(GetStringManager()->CreateString(static_cast<const wchar_t* const*>(pdata)[i]));
            parray->SetElement((int)(index + i), Value(str));
        }
        break;
    case Movie::SA_Value:
        for (unsigned i = 0; i < count; i++)
        {
            Value asval;
            Value2ASValue(static_cast<const GFx::Value*>(pdata)[i], &asval);
            parray->SetElement((int)(index + i), asval);
        }
        break;
    }
    bool ok = MovieRoot_StoreArray(this, path, parray, setType);
    parray->Release();
    return ok;
}

// Resizes the array at path; a missing or non-array variable becomes a new Array of that size.
// MS2-FUNCTIONAL: the level lookups and the value releases are inlined differently
// @0x14298d760
bool MovieRoot::SetVariableArraySize(const char* ppathToVar, unsigned count, SetVarTypeArg setType)
{
    if (!FindLevelMovie(pMovieImpl, 0))
        return false;
    Environment* penv = Level0Env(pMovieImpl);
    ASString     path(penv->CreateString(ppathToVar));
    Value        cur;
    Object*      pobj;
    ArrayObject* parray;
    bool         ok;
    if (penv->GetVariable(path, &cur) && cur.IsObject() && (pobj = cur.ToObject(penv)) != 0 &&
        pobj->GetObjectType() == Object::Object_Array)
    {
        parray = static_cast<ArrayObject*>(pobj);
        parray->AddRef();
        if (count != (unsigned)parray->GetSize())
            parray->Resize((int)count);
        ok = true;
    }
    else
    {
        parray = SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) ArrayObject(Level0Env(pMovieImpl));
        parray->Resize((int)count);
        ok = MovieRoot_StoreArray(this, path, parray, setType);
    }
    if (parray)
        parray->Release();
    return ok;
}

}}} // namespace Scaleform::GFx::AS2
