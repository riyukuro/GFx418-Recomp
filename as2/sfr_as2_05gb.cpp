// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// Math's random source and the GetStandardMember of characters, buttons and clips, and
// the root's GetVariableArray and the
// environment's GetVariableRaw.
// MS2-UNIT: sfr_as2_05gb
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142953f50-0x142954073 .text$mn
// MS2-RANGE: 0x142954ed0-0x14295507e .text$mn
// MS2-RANGE: 0x142955080-0x142955bbf .text$mn
// MS2-RANGE: 0x142955c50-0x142955fd4 .text$mn
// MS2-RANGE: 0x142957270-0x14295797b .text$mn
// MS2-RANGE: 0x142957b10-0x142958283 .text$mn
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358

#include <stdlib.h>
#include <string.h>
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/gfx_asutils.h"
#include "../include/gfx/gfx_button.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/gfx_sprite.h"
#include "../include/render/render_filters.h"
#include "../include/render/render_twips.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_utf8util.h"
#include "../kernel/sf_random.h"

namespace Scaleform { namespace GFx {
// The return value holder of the movie (as sfr_gfx_01i defines it).
struct MovieImpl::ReturnValueHolder : public NewOverrideBase<0x147>   // StatMV_Other_Mem
{
    char*                     CharBuffer;       // +0x00
    unsigned                  CharBufferSize;   // +0x08
    ArrayCC<ASString, 0x147>  StringArray;      // +0x10 (default value +0x28)
    unsigned                  StringArrayPos;   // +0x30

    ReturnValueHolder(ASStringManager* pstrMgr)
        : CharBuffer(0), CharBufferSize(0), StringArray(pstrMgr->CreateConstString("")), StringArrayPos(0) {}
    ~ReturnValueHolder()
    {
        if (CharBuffer)
            SF_FREE(CharBuffer);
    }
};
}} // namespace Scaleform::GFx

namespace Scaleform { namespace GFx { namespace AS2 {

// The movie loaded as _level<level>, 0 if none.
static SF_FORCEINLINE InteractiveObject* Sfr05gb_GetLevelMovie(const MovieImpl* pmovieImpl, int level)
{
    for (unsigned i = 0; i < pmovieImpl->MovieLevelsSize; i++)
    {
        if (pmovieImpl->pMovieLevels[i].Level == level)
            return pmovieImpl->pMovieLevels[i].pSprite;
    }
    return 0;
}

// The strings of the holder are at least one.
static inline void Sfr05gb_ResizeStringArray(MovieImpl::ReturnValueHolder* h, unsigned n)
{
    h->StringArray.Resize(Alg::Max(1u, n));
}

// The shared generator, unless the movie runs under a test stream: recording writes each value out as "random",
// playing back reads it in.
// @0x142953f50
UInt32 Math::GetNextRandom(MovieImpl* proot)
{
    TestStream* pts = proot->GetStateBag()->GetTestStream();
    if (pts)
    {
        if (pts->TestStatus == TestStream::Record)
        {
            UInt32 rnd = Alg::Random::NextRandom();
            LongFormatter f(rnd);
            f.Convert();
            pts->SetParameter("random", f.ToCStr());
            return rnd;
        }
        String value;
        pts->GetParameter("random", &value);
        return (UInt32)strtoul(value.ToCStr(), NULL, 10);
    }
    return Alg::Random::NextRandom();
}

// The script side of a button (partial local copy; the other units carry their own).
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    Ptr<ButtonObject> ASButtonObj; // +0x38

    virtual bool GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const;
};

namespace {

// The blendMode names by Render::BlendMode (0 and 1 are both "normal"); the exe's table is at 0x143a51a40.
const char* const BlendModeNames[] = {"normal",     "normal", "layer",      "multiply", "screen",
                                      "lighten",    "darken", "difference", "add",      "subtract",
                                      "invert",     "alpha",  "erase",      "overlay",  "hardlight"};

// The slash path of pchar: its name and those of its parents up to (not including) ptop, each after a "/".
SF_FORCEINLINE void PrependNamePath(StringBuffer& path, const DisplayObject* pchar, const DisplayObject* ptop)
{
    for (; pchar && pchar != ptop; pchar = pchar->GetParent())
    {
        ASString name = pchar->GetName();
        path.Insert(name.ToCStr(), 0);
        path.Insert("/", 0);
    }
}

// A Bool3W (0 undefined, 1 true, 2 false) as a value.
SF_FORCEINLINE void SetBool3W(Value* val, SByte b)
{
    if (b)
        val->SetBool(b == 1);
    else
        val->SetUndefined();
}

} // namespace

// The built-in properties every character has, by number; false for those this one does not have or that need
// the subclass (currentframe, totalframes, framesloaded, cacheAsBitmap, lockroot).
// MS2-FUNCTIONAL the url copy is a plain loop here (vectorised in the exe); local blendMode table
// @0x142955080
bool AvmCharacter::GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const
{
    if (opcodeFlag && (unsigned)index > M_BuiltInProperty_End)
    {
        GetASEnvironment()->LogScriptError("Invalid GetProperty query, property number %d", index);
        return false;
    }
    if (index == M_InvalidMember || index > M_LastBitMaskMember)
        return false;
    if (!((GetStandardMemberBitMask() >> index) & 1))
        return false;

    switch (index)
    {
    case M_x:
        val->SetNumber(pDispObj->GetX());
        break;
    case M_y:
        val->SetNumber(pDispObj->GetY());
        break;
    case M_xscale:
        val->SetNumber(pDispObj->GetXScale());
        break;
    case M_yscale:
        val->SetNumber(pDispObj->GetYScale());
        break;
    case M_alpha:
        val->SetNumber(pDispObj->GetAlpha());
        break;
    case M_visible:
        val->SetBool(pDispObj->GetVisible());
        break;
    case M_width:
        val->SetNumber(pDispObj->GetWidth());
        break;
    case M_height:
        val->SetNumber(pDispObj->GetHeight());
        break;
    case M_rotation:
        val->SetNumber(pDispObj->GetRotation());
        break;
    case M_target:
    {
        StringBuffer       path;
        Ptr<DisplayObject> ptop = GetTopParent();
        PrependNamePath(path, pDispObj, ptop);
        val->SetString(GetASEnvironment()->CreateString(path.ToCStr(), path.GetSize()));
        break;
    }
    case M_name:
        val->SetString(pDispObj->GetName());
        break;
    case M_droptarget:
    {
        val->SetUndefined();
        MovieImpl*     proot = GetASEnvironment()->GetMovieImpl();
        Render::PointF mouse = proot->MouseLastPosition;
        StringBuffer   path;
        PrependNamePath(path, proot->GetTopMostEntity(mouse, 0, true, pDispObj), NULL);
        val->SetString(GetASEnvironment()->CreateString(path.ToCStr(), path.GetSize()));
        break;
    }
    case M_url:
    {
        ArrayPOD<char> buf;
        const char*    purl = pDispObj->GetResourceMovieDef()->GetFileURL();
        const UPInt    len  = purl ? strlen(purl) : 0;
        buf.Resize(len + 1);
        for (UPInt i = 0; i < len; ++i)
            buf[i] = purl[i] == '\\' ? '/' : purl[i];
        buf[len] = 0;
        String escaped;
        ASUtils::EscapePath(buf.GetDataPtr(), len, &escaped);
        val->SetString(GetASEnvironment()->CreateString(escaped));
        break;
    }
    case M_highquality:
        val->SetBool(true);
        break;
    case M_focusrect:
    {
        const unsigned f = pDispObj->Flags & InteractiveObject::Mask_FocusRect;
        if (!f)
            val->SetNull();
        else
            val->SetBool(f == InteractiveObject::Mask_FocusRect);
        break;
    }
    case M_soundbuftime:
        val->SetNumber(0);
        break;
    case M_quality:
        val->SetString(GetASEnvironment()->CreateString("HIGH"));
        break;
    case M_xmouse:
        val->SetNumber(pDispObj->GetMouseX());
        break;
    case M_ymouse:
        val->SetNumber(pDispObj->GetMouseY());
        break;
    case M_parent:
        if (pDispObj->GetParent())
            val->SetAsCharacter(pDispObj->GetParent());
        else
            val->SetUndefined();
        break;
    case M_blendMode:
        val->SetString(GetASEnvironment()->CreateString(BlendModeNames[pDispObj->GetBlendMode()]));
        break;
    case M_filters:
    {
        Environment*     penv = const_cast<Environment*>(GetASEnvironment());
        ASStringContext* psc  = penv->GetSC();
        Ptr<ArrayObject> parr = *SF_HEAP_NEW(psc->GetHeap()) ArrayObject(psc);
        if (const Render::FilterSet* filters = pDispObj->GetFilters())
        {
            for (unsigned i = 0; i < filters->GetFilterCount(); ++i)
            {
                const Render::Filter* f = filters->GetFilter(i);
                if (!f)
                    continue;
                int builtin;
                switch (f->GetFilterType())
                {
                case Render::Filter_Blur:        builtin = ASBuiltin_BlurFilter; break;
                case Render::Filter_Shadow:      builtin = ASBuiltin_DropShadowFilter; break;
                case Render::Filter_Glow:        builtin = ASBuiltin_GlowFilter; break;
                case Render::Filter_Bevel:       builtin = ASBuiltin_BevelFilter; break;
                case Render::Filter_ColorMatrix: builtin = ASBuiltin_ColorMatrixFilter; break;
                default:                         builtin = -1; break;
                }
                if (builtin < 0)
                    continue;
                Ptr<Object> pobj = *penv->OperatorNew(psc->pContext->FlashFiltersPackage, penv->GetBuiltin(builtin));
                if (!pobj)
                    continue;
                *static_cast<BitmapFilterObject*>(pobj.GetPtr())->GetFilter() = *f;
                parr->PushBack(Value(pobj));
            }
        }
        val->SetAsObject(parr);
        break;
    }
    case M_enabled:
        val->SetBool((pDispObj->Flags & InteractiveObject::Mask_Enabled) != 0);
        break;
    case M_trackAsMenu:
        val->SetBool((pDispObj->Flags & InteractiveObject::Mask_TrackAsMenu) != 0);
        break;
    case M_tabEnabled:
    {
        const unsigned f = pDispObj->Flags & InteractiveObject::Mask_TabEnabled;
        if (!f)
            val->SetUndefined();
        else
            val->SetBool(f == InteractiveObject::Mask_TabEnabled);
        break;
    }
    case M_tabIndex:
        val->SetNumber(pDispObj->TabIndex);
        break;
    case M_useHandCursor:
    {
        const unsigned f = pDispObj->Flags & InteractiveObject::Mask_UseHandCursor;
        if (!f)
            return false;
        val->SetBool(f == InteractiveObject::Mask_UseHandCursor);
        return true;
    }
    case M_edgeaaMode:
        switch (pDispObj->GetRenderNode()->GetEdgeAAMode())
        {
        case Render::EdgeAA_On:      val->SetNumber(1); break;
        case Render::EdgeAA_Off:     val->SetNumber(2); break;
        case Render::EdgeAA_Disable: val->SetNumber(3); break;
        default:                     val->SetNumber(0); break;
        }
        break;
    default:
        return false;
    }
    return true;
}

// The common members, then scale9Grid (SWF 8) as a Rectangle in pixels and the hitTestDisable extension.
// @0x142954ed0
bool AvmButton::GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const
{
    if (AvmCharacter::GetStandardMember(index, val, opcodeFlag))
        return true;
    switch (index)
    {
    case M_scale9Grid:
        if (GetASEnvironment()->GetVersion() >= 8)
        {
            if (pDispObj->HasScale9Grid())
            {
                Environment*         penv = const_cast<Environment*>(GetASEnvironment());
                RectF                sg   = pDispObj->GetScale9Grid();
                Ptr<RectangleObject> rect = *SF_HEAP_NEW(penv->GetHeap()) RectangleObject(penv);
                rect->SetProperties(penv, ASRect(Render::TwipsToPixels(sg.x1), Render::TwipsToPixels(sg.y1),
                                                 Render::TwipsToPixels(sg.x2), Render::TwipsToPixels(sg.y2)));
                val->SetAsObject(rect);
            }
            else
                val->SetUndefined();
            return true;
        }
        break;
    case M_hitTestDisable:
        if (GetASEnvironment()->CheckExtensions())
        {
            val->SetBool((pDispObj->Flags & InteractiveObject::Mask_HitTestDisable) != 0);
            return true;
        }
        break;
    default:
        break;
    }
    return false;
}

// The common members, then the clip's frames, lockroot, focusEnabled, tabChildren, scale9Grid and scrollRect (SWF 8,
// as Rectangles in pixels), hitArea and the hitTestDisable extension.
// MS2-FUNCTIONAL the exe shares one SetInt_Call tail for the frame members; here each case calls it
// @0x142955c50
bool AvmSprite::GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const
{
    if (AvmCharacter::GetStandardMember(index, val, opcodeFlag))
        return true;
    int frame;
    switch (index)
    {
    case M_currentframe:
        frame = GetSprite()->GetCurrentFrame() + 1;
        break;
    case M_totalframes:
        frame = GetSprite()->pDef->GetFrameCount();
        break;
    case M_framesloaded:
        frame = GetSprite()->GetLoadingFrame();
        break;
    case M_lockroot:
        val->SetBool((GetSprite()->Flags & Sprite::Flags_LockRoot) != 0);
        return true;
    case M_focusEnabled:
        SetBool3W(val, GetSprite()->FocusEnabled);
        return true;
    case M_tabChildren:
        SetBool3W(val, *reinterpret_cast<const SByte*>(&Unrecovered_1f8));
        return true;
    case M_scale9Grid:
    {
        if (GetASEnvironment()->GetVersion() < 8)
            return false;
        if (!GetSprite()->HasScale9Grid())
        {
            val->SetUndefined();
            return true;
        }
        RectF                sg   = GetSprite()->GetScale9Grid();
        Environment*         penv = const_cast<Environment*>(GetASEnvironment());
        Ptr<RectangleObject> rect = *SF_HEAP_NEW(penv->GetHeap()) RectangleObject(penv);
        rect->SetProperties(penv, ASRect(Render::TwipsToPixels(sg.x1), Render::TwipsToPixels(sg.y1),
                                         Render::TwipsToPixels(sg.x2), Render::TwipsToPixels(sg.y2)));
        val->SetAsObject(rect);
        return true;
    }
    case M_hitArea:
        if (GetSprite()->pHitAreaHandle)
        {
            val->SetAsCharacterHandle(GetSprite()->pHitAreaHandle);
            return true;
        }
        val->SetUndefined();
        return false;
    case M_scrollRect:
    {
        if (GetASEnvironment()->GetVersion() < 8)
            return false;
        if (!GetSprite()->pScrollRect)
        {
            val->SetUndefined();
            return true;
        }
        const Render::RectD  r    = GetSprite()->pScrollRect->Rectangle;
        Environment*         penv = const_cast<Environment*>(GetASEnvironment());
        Ptr<RectangleObject> rect = *SF_HEAP_NEW(penv->GetHeap()) RectangleObject(penv);
        rect->SetProperties(penv, ASRect(Render::TwipsToPixels(r.x1), Render::TwipsToPixels(r.y1),
                                         Render::TwipsToPixels(r.x2), Render::TwipsToPixels(r.y2)));
        val->SetAsObject(rect);
        return true;
    }
    case M_hitTestDisable:
        if (!GetASEnvironment()->CheckExtensions())
            return false;
        val->SetBool((GetSprite()->Flags & InteractiveObject::Mask_HitTestDisable) != 0);
        return true;
    default:
        return false;
    }
    val->SetInt_Call(frame);
    return true;
}

// count elements of the AS2 array at the path from index on, into the host's array of ints, doubles, floats,
// strings (kept alive by the movie's return value holder), wide strings (in its character buffer) or values.
// Missing elements give 0 (NULL for strings). False when the path is not an array.
// MS2-FUNCTIONAL a 4.1.18 virtual of the root; register allocation differs
// @0x142957270
bool MovieRoot::GetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index, void* pdata,
                                 unsigned count)
{
    if (!Sfr05gb_GetLevelMovie(pMovieImpl, 0))
        return false;
    AvmDisplayObjBase* pavm = Sfr05gb_GetLevelMovie(pMovieImpl, 0)->GetAvmObjImpl();
    Environment* penv = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
    ASString path(penv->CreateString(ppathToVar));
    Value    retVal;
    if (!penv->GetVariable(path, &retVal) || !retVal.IsObject())
        return false;
    Object* pobj = retVal.ToObject(penv);
    if (!pobj || pobj->GetObjectType() != Object::Object_Array)
        return false;

    ArrayObject*                  parray   = static_cast<ArrayObject*>(pobj);
    MovieImpl::ReturnValueHolder* rvHolder = pMovieImpl->GetRetValHolder();
    rvHolder->StringArrayPos = 0;
    Sfr05gb_ResizeStringArray(rvHolder, 0);
    const unsigned arrSize = parray->GetSize();
    switch (type)
    {
    case 0: // SA_Int
    {
        int*           parr = static_cast<int*>(pdata);
        const unsigned n    = Alg::Min(arrSize, count);
        for (unsigned i = 0; i < n; ++i)
        {
            const Value* pval = parray->GetElementPtr(i + index);
            parr[i] = pval ? (int)pval->ToNumber(penv) : 0;
        }
        break;
    }
    case 1: // SA_Double
    {
        Double*        parr = static_cast<Double*>(pdata);
        const unsigned n    = Alg::Min(arrSize, count);
        for (unsigned i = 0; i < n; ++i)
        {
            const Value* pval = parray->GetElementPtr(i + index);
            parr[i] = pval ? pval->ToNumber(penv) : 0.0;
        }
        break;
    }
    case 2: // SA_Float
    {
        float*         parr = static_cast<float*>(pdata);
        const unsigned n    = Alg::Min(arrSize, count);
        for (unsigned i = 0; i < n; ++i)
        {
            const Value* pval = parray->GetElementPtr(i + index);
            parr[i] = pval ? (float)pval->ToNumber(penv) : 0.0f;
        }
        break;
    }
    case 3: // SA_String
    {
        const char**   parr = static_cast<const char**>(pdata);
        const unsigned n    = Alg::Min(arrSize, count);
        Sfr05gb_ResizeStringArray(rvHolder, n);
        for (unsigned i = 0; i < n; ++i)
        {
            const Value* pval = parray->GetElementPtr(i + index);
            if (pval)
            {
                ASString str = pval->ToString(penv);
                parr[i]      = str.ToCStr();
                rvHolder->StringArray[rvHolder->StringArrayPos++] = str;
            }
            else
                parr[i] = NULL;
        }
        break;
    }
    case 4: // SA_StringW
    {
        const wchar_t** parr    = static_cast<const wchar_t**>(pdata);
        unsigned        bufSize = 0;
        const unsigned  n       = Alg::Min(arrSize, count);
        Sfr05gb_ResizeStringArray(rvHolder, n);
        for (unsigned i = 0; i < arrSize; ++i)
        {
            const Value* pval = parray->GetElementPtr(i + index);
            if (pval)
            {
                ASString str             = pval->ToString(penv);
                rvHolder->StringArray[i] = str;
                bufSize += str.GetLength() + 1;
            }
        }
        const unsigned size = (bufSize * unsigned(sizeof(wchar_t)) + 4095) & ~4095u;
        if (rvHolder->CharBufferSize < size ||
            (rvHolder->CharBufferSize > size && rvHolder->CharBufferSize - size > 4096))
        {
            if (rvHolder->CharBuffer)
                rvHolder->CharBuffer = static_cast<char*>(SF_REALLOC(rvHolder->CharBuffer, size, 0x147));
            else
                rvHolder->CharBuffer = static_cast<char*>(SF_ALLOC(size, 0x147));
            rvHolder->CharBufferSize = size;
        }
        wchar_t* pwBuffer = reinterpret_cast<wchar_t*>(rvHolder->CharBuffer);
        for (unsigned i = 0; i < n; ++i)
        {
            const char* psrcStr  = rvHolder->StringArray[i].ToCStr();
            wchar_t*    pwdstStr = pwBuffer;
            UInt32      code;
            while ((code = UTF8Util::DecodeNextChar(&psrcStr)) != 0)
                *pwBuffer++ = wchar_t(code);
            *pwBuffer++ = 0;
            parr[i]     = pwdstStr;
        }
        Sfr05gb_ResizeStringArray(rvHolder, 0);
        break;
    }
    case 5: // SA_Value
    {
        GFx::Value*    parr = static_cast<GFx::Value*>(pdata);
        const unsigned n    = Alg::Min(arrSize, count);
        for (unsigned i = 0; i < n; ++i)
        {
            const Value* pval     = parray->GetElementPtr(i + index);
            GFx::Value*  pdestVal = &parr[i];
            pdestVal->SetUndefined();
            if (pval)
                ASValue2GFxValue(penv, *pval, pdestVal);
        }
        break;
    }
    }
    return true;
}

// The movie logs every action (LogAction's check; as sfr_as2_06n).
inline bool Environment::IsVerboseAction() const
{
    return (GetTarget()->GetMovieImpl()->Flags & MovieImpl::Flag_VerboseAction) != 0;
}

// GetVarParams::ExcludeFlags.
enum
{
    Sfr05gb_IgnoreLocals     = 0x1,
    Sfr05gb_IgnoreContainers = 0x2,
    Sfr05gb_NoLogOutput      = 0x4
};

// A plain name through the scope chain: the with stack (innermost first; a dead entry ends the lookup), the locals
// ("arguments" made on first use from SWF5, "super" from SWF6, cached as a local), "this", the target's members,
// _global/_root/_levelN and the members of _global. The owner, when asked for, is 0 until something is found.
// MS2-FUNCTIONAL a 4.1.18 member of the environment; register allocation and block order differ
// @0x142957b10
bool Environment::GetVariableRaw(const GetVarParams& params) const
{
    if (!params.pResult)
        return false;
    Environment*     penv = const_cast<Environment*>(this);
    ASStringContext* psc  = penv->GetSC();

    if (params.pOwnerValue)
        *params.pOwnerValue = Value(0);
    if (params.pWithStack)
    {
        for (int i = (int)params.pWithStack->GetSize() - 1; i >= 0; i--)
        {
            ObjectInterface* obj = (*params.pWithStack)[i].GetObjectInterface();
            if (!obj)
                return false;
            if (obj->GetMember(penv, params.VarName, params.pResult))
            {
                if (params.pOwnerValue)
                {
                    if (obj->IsASCharacter())
                        params.pOwnerValue->SetAsCharacter(obj->ToCharacter());
                    else
                        params.pOwnerValue->SetAsObject(obj->ToASObject());
                }
                return true;
            }
        }
    }

    if (!(params.ExcludeFlags & Sfr05gb_IgnoreLocals))
    {
        if (const Value* plocal = FindLocal(params.VarName))
        {
            *params.pResult = *plocal;
            return true;
        }
        if (GetVersion() >= 5)
        {
            if (GetBuiltin(ASBuiltin_arguments).CompareBuiltIn_CaseCheck(params.VarName, IsCaseSensitive()))
            {
                if (LocalFrame* plocFr = GetTopLocalFrame(0))
                {
                    Ptr<ArrayObject> pargArray = *SF_HEAP_NEW(GetHeap()) ArrayObject(penv);
                    pargArray->Resize(plocFr->NArgs);
                    for (int i = 0; i < plocFr->NArgs; i++)
                        pargArray->SetElement(i, *plocFr->Env->Bottom(plocFr->FirstArgBottomIndex - i));
                    penv->AddLocal(psc->GetBuiltin(ASBuiltin_arguments), Value(pargArray.GetPtr()));
                    const PropFlags flags(PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete |
                                          PropFlags::PropFlag_ReadOnly);
                    pargArray->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_callee), plocFr->Callee, flags);
                    pargArray->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_caller), plocFr->Caller, flags);
                    params.pResult->SetAsObject(pargArray);
                    return true;
                }
            }
            else if (GetVersion() >= 6 &&
                     GetBuiltin(ASBuiltin_super).CompareBuiltIn_CaseCheck(params.VarName, IsCaseSensitive()))
            {
                LocalFrame* plocFr = GetTopLocalFrame(0);
                if (plocFr && plocFr->SuperThis)
                {
                    if (Ptr<Object> proto = plocFr->SuperThis->Get__proto__())
                    {
                        Value thisVal;
                        FindAndGetVariableRaw(GetVarParams(GetBuiltin(ASBuiltin_this), &thisVal, params.pWithStack));
                        FunctionRef ctor     = proto->Get__constructor__(psc);
                        Ptr<Object> superObj = *SF_HEAP_NEW(GetHeap())
                            SuperObject(proto->Get__proto__(), thisVal.ToObjectInterface(this), ctor);
                        params.pResult->SetAsObject(superObj);
                        penv->SetLocal(GetBuiltin(ASBuiltin_super), *params.pResult);
                        return true;
                    }
                }
            }
        }
        if (GetBuiltin(ASBuiltin_this).CompareBuiltIn_CaseCheck(params.VarName, IsCaseSensitive()))
        {
            params.pResult->SetAsCharacter(Target);
            return true;
        }
    }

    if (!Target)
        return false;
    if (GetAvmTarget()->GetMemberRaw(psc, params.VarName, params.pResult))
    {
        if (params.pOwnerValue)
            *params.pOwnerValue = Value(Target);
        return true;
    }
    Object* pglobal = StringContext.pContext->pGlobal;
    if (!(params.ExcludeFlags & Sfr05gb_IgnoreContainers) && params.VarName.GetLength() > 0 &&
        params.VarName.ToCStr()[0] == '_')
    {
        Bool3W rv = CheckGlobalAndLevels(params);
        if (rv.IsDefined())
            return rv.IsTrue();
    }
    if (pglobal && pglobal->GetMember(penv, params.VarName, params.pResult))
    {
        if (params.pOwnerValue)
            *params.pOwnerValue = Value(pglobal);
        return true;
    }
    if (!(params.ExcludeFlags & Sfr05gb_NoLogOutput))
        LogAction("GetVariableRaw(\"%s\") failed, returning UNDEFINED.\n", params.VarName.ToCStr());
    return false;
}

}}} // namespace Scaleform::GFx::AS2
