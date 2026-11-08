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
#include "../include/gfx/text_stylesheet.h" // Text::StyleManager complete: StyleSheetObject's implicit destructor calls ~StyleManager

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
static MovieSlots418::AlignType Stage_ParseAlign(const ASString& alignStr)
{
    MovieSlots418::AlignType align;
    unsigned char1 = 0, char2 = 0;
    unsigned len = alignStr.GetLength();
    if (len >= 1)
    {
        char1 = alignStr.GetCharAt(0);
        if (len >= 2)
            char2 = alignStr.GetCharAt(1);
    }
    if ((char1 == 'T' && char2 == 'L') || (char1 == 'L' && char2 == 'T'))
        align = MovieSlots418::Align_TopLeft;
    else if ((char1 == 'T' && char2 == 'R') || (char1 == 'R' && char2 == 'T'))
        align = MovieSlots418::Align_TopRight;
    else if ((char1 == 'B' && char2 == 'L') || (char1 == 'L' && char2 == 'B'))
        align = MovieSlots418::Align_BottomLeft;
    else if ((char1 == 'B' && char2 == 'R') || (char1 == 'R' && char2 == 'B'))
        align = MovieSlots418::Align_BottomRight;
    else if (char1 == 'T')
        align = MovieSlots418::Align_TopCenter;
    else if (char1 == 'B')
        align = MovieSlots418::Align_BottomCenter;
    else if (char1 == 'L')
        align = MovieSlots418::Align_CenterLeft;
    else if (char1 == 'R')
        align = MovieSlots418::Align_CenterRight;
    else
        align = MovieSlots418::Align_Center;
    return align;
}

// scaleMode and align go to the view of the movie (onResize fires on a switch to noScale); the rest is a plain
// member.
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
    else if (ConstName_CompareCaseCheck(psc->CreateConstString("align"), name, psc->IsCaseSensitive()))
    {
        ASString align(val.ToString(penv).ToUpperNode());
        MovieSlots418::AlignType a = Stage_ParseAlign(align);
        AsMovieSlots(pMovieRoot)->SetViewAlignment(a);
        return true;
    }
    return Object::SetMember(penv, name, val, flags);
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

// MovieRoot::GetLevelMovie as the SDK writes it (the exe inlines it): the level search through the root.
static SF_FORCEINLINE InteractiveObject* RootLevelMovie(const MovieRoot* proot, int level)
{
    for (unsigned i = 0; i < proot->pMovieImpl->MovieLevelsSize; i++)
    {
        if (proot->pMovieImpl->pMovieLevels[i].Level == level)
            return proot->pMovieImpl->pMovieLevels[i].pSprite;
    }
    return 0;
}

// The script environment of _level0 (it must exist).
static SF_FORCEINLINE Environment* Level0Env(const MovieImpl* pmovieImpl)
{
    AvmDisplayObjBase* pavm = FindLevelMovie(pmovieImpl, 0)->GetAvmObjImpl();
    return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
}

// Writes count host values of one type into the array at path from index on, growing it as needed; a missing
// or non-array variable becomes a new Array.
// The string cases name the ASString (str) and pass Value(str): the exe merges its AddRef and the Value's into one
// add 2 after the Value stores. Passing Value(CreateString(..)) gives two incs around them.
// @0x14298d1e0
bool MovieRoot::SetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index, const void* pdata,
                                 unsigned count, SetVarTypeArg setType)
{
    if (!RootLevelMovie(this, 0))
        return false;

    Environment* penv = Level0Env(pMovieImpl);
    ASString     path(penv->CreateString(ppathToVar));

    Ptr<ArrayObject> parray;
    Value            retVal;
    if (penv->GetVariable(path, &retVal) && retVal.IsObject())
    {
        Object* pobj = retVal.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object::Object_Array)
            parray = static_cast<ArrayObject*>(pobj);
    }

    if (!parray)
        parray = *SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) ArrayObject(Level0Env(pMovieImpl));
    if (count + index > unsigned(parray->GetSize()))
        parray->Resize(count + index);

    switch (type)
    {
    case Movie::SA_Int:
        {
            const int* parr = static_cast<const int*>(pdata);
            for (unsigned i = 0; i < count; ++i)
                parray->SetElement(i + index, Value(parr[i]));
            break;
        }
    case Movie::SA_Float:
        {
            const float* parr = static_cast<const float*>(pdata);
            for (unsigned i = 0; i < count; ++i)
                parray->SetElement(i + index, Value(Number(parr[i])));
            break;
        }
    case Movie::SA_Double:
        {
            const Double* parr = static_cast<const Double*>(pdata);
            for (unsigned i = 0; i < count; ++i)
                parray->SetElement(i + index, Value(Number(parr[i])));
            break;
        }
    case Movie::SA_Value:
        {
            const GFx::Value* parr = static_cast<const GFx::Value*>(pdata);
            for (unsigned i = 0; i < count; ++i)
            {
                Value asVal;
                Value2ASValue(parr[i], &asVal);
                parray->SetElement(i + index, asVal);
            }
            break;
        }
    case Movie::SA_String:
        {
            const char* const* parr = static_cast<const char* const*>(pdata);
            for (unsigned i = 0; i < count; ++i)
            {
                ASString str(GetStringManager()->CreateString(parr[i]));
                parray->SetElement(i + index, Value(str));
            }
            break;
        }
    case Movie::SA_StringW:
        {
            const wchar_t* const* parr = static_cast<const wchar_t* const*>(pdata);
            for (unsigned i = 0; i < count; ++i)
            {
                ASString str(GetStringManager()->CreateString(parr[i]));
                parray->SetElement(i + index, Value(str));
            }
            break;
        }
    }

    Value val;
    val.SetAsObject(parray);

    bool setResult = static_cast<AvmCharacter*>(
                         static_cast<AvmInteractiveObjBase*>(FindLevelMovie(pMovieImpl, 0)->GetAvmObjImpl()))
                         ->GetASEnvironment()
                         ->SetVariable(path, val, 0, (setType == Movie::SV_Normal));

    if ((!setResult && (setType != Movie::SV_Normal)) || (setType == Movie::SV_Permanent))
        AddStickyVariable(path, val, setType);
    return setResult;
}

// Resizes the array at path; a missing or non-array variable becomes a new Array of that size.
// @0x14298d760
bool MovieRoot::SetVariableArraySize(const char* ppathToVar, unsigned count, SetVarTypeArg setType)
{
    if (!RootLevelMovie(this, 0))
        return false;

    Environment* penv = Level0Env(pMovieImpl);
    ASString     path(penv->CreateString(ppathToVar));

    Ptr<ArrayObject> parray;
    Value            retVal;
    if (penv->GetVariable(path, &retVal) && retVal.IsObject())
    {
        Object* pobj = retVal.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object::Object_Array)
        {
            parray = static_cast<ArrayObject*>(pobj);
            if (count != unsigned(parray->GetSize()))
                parray->Resize(count);
            return true;
        }
    }

    parray = *SF_HEAP_NEW(pMovieImpl->GetMovieHeap()) ArrayObject(Level0Env(pMovieImpl));
    parray->Resize(count);
    Value val;
    val.SetAsObject(parray);

    bool setResult = static_cast<AvmCharacter*>(
                         static_cast<AvmInteractiveObjBase*>(FindLevelMovie(pMovieImpl, 0)->GetAvmObjImpl()))
                         ->GetASEnvironment()
                         ->SetVariable(path, val, 0, (setType == Movie::SV_Normal));

    if ((!setResult && (setType != Movie::SV_Normal)) || (setType == Movie::SV_Permanent))
        AddStickyVariable(path, val, setType);
    return setResult;
}

}}} // namespace Scaleform::GFx::AS2
