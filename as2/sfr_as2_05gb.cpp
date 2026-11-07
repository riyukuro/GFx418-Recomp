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

// The strings of the holder are at least one (ArrayDataCC::Resize, inlined in the exe).
typedef ArrayDataCC<ASString, AllocatorLH<ASString, 0x147>, ArrayDefaultPolicy> Sfr05gbStringData;
static SF_FORCEINLINE void Sfr05gb_ResizeStringArray(MovieImpl::ReturnValueHolder* h, unsigned n)
{
    Sfr05gbStringData& d       = reinterpret_cast<Sfr05gbStringData&>(h->StringArray);
    const UPInt        newSize = Alg::Max(1u, n);
    const UPInt        oldSize = d.Size;
    d.ResizeNoConstruct(&d, newSize);
    if (newSize > oldSize)
        AllocatorLH<ASString, 0x147>::ConstructArray(d.Data + oldSize, newSize - oldSize, d.DefaultValue);
}

// The shared generator, unless the movie runs under a test stream: recording writes each value out as "random",
// playing back reads it in.
// @0x142953f50
UInt32 Math::GetNextRandom(MovieImpl* proot)
{
    UInt32      rnd;
    TestStream* pts = proot->GetStateBag()->GetTestStream();
    if (pts)
    {
        if (pts->TestStatus == TestStream::Record)
        {
            rnd = Alg::Random::NextRandom();
            LongFormatter f(rnd);
            f.Convert();
            pts->SetParameter("random", f.ToCStr());
        }
        else
        {
            String value;
            pts->GetParameter("random", &value);
            rnd = (UInt32)strtoul(value.ToCStr(), NULL, 10);
        }
    }
    else
        rnd = Alg::Random::NextRandom();
    return rnd;
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
// BitmapFilterObject::CreateFromDesc, inlined into GetStandardMember in the exe.
static SF_FORCEINLINE BitmapFilterObject* Sfr05gbCreateFromDesc(Environment* penv, ASStringContext* psc, const Render::Filter& filter)
{
    BitmapFilterObject* pobj;
    int                 type;
    switch (filter.GetFilterType())
    {
    case Render::Filter_Blur:        type = ASBuiltin_BlurFilter; break;
    case Render::Filter_Shadow:      type = ASBuiltin_DropShadowFilter; break;
    case Render::Filter_Glow:        type = ASBuiltin_GlowFilter; break;
    case Render::Filter_Bevel:       type = ASBuiltin_BevelFilter; break;
    case Render::Filter_ColorMatrix: type = ASBuiltin_ColorMatrixFilter; break;
    default:
        return 0;
    }
    pobj = static_cast<BitmapFilterObject*>(penv->OperatorNew(psc->pContext->FlashFiltersPackage, penv->GetBuiltin(type)));
    if (pobj)
        *pobj->GetFilter() = filter;
    return pobj;
}

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
// MS2-FUNCTIONAL 8 bytes: in the vectorised url copy the exe orders pand/pandn differently in unrolled lanes 3-4 (lanes 1-2 match); no source form found
// @0x142955080
bool AvmCharacter::GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const
{
    if (opcodeFlag && (unsigned)index > M_BuiltInProperty_End)
    {
        GetASEnvironment()->LogScriptError("Invalid GetProperty query, property number %d", index);
        return 0;
    }

    if (index == M_InvalidMember)
        return 0;
    if (!((index <= M_LastBitMaskMember) && (GetStandardMemberBitMask() & (1 << index))))
        return 0;

    switch (index)
    {
    case M_x:
    {
        val->SetNumber(pDispObj->GetX());
        return 1;
    }
    case M_y:
    {
        val->SetNumber(pDispObj->GetY());
        return 1;
    }
    case M_xscale:
    {
        val->SetNumber(pDispObj->GetXScale());
        return 1;
    }
    case M_yscale:
    {
        val->SetNumber(pDispObj->GetYScale());
        return 1;
    }
    case M_width:
    {
        val->SetNumber(pDispObj->GetWidth());
        return 1;
    }
    case M_height:
    {
        val->SetNumber(pDispObj->GetHeight());
        return 1;
    }
    case M_rotation:
    {
        val->SetNumber(pDispObj->GetRotation());
        return 1;
    }
    case M_alpha:
    {
        val->SetNumber(pDispObj->GetAlpha());
        return 1;
    }
    case M_visible:
    {
        val->SetBool(pDispObj->GetVisible());
        return 1;
    }
    case M_blendMode:
    {
        val->SetString(GetASEnvironment()->CreateString(BlendModeNames[pDispObj->GetBlendMode()]));
        return 1;
    }
    case M_name:
    {
        val->SetString(pDispObj->GetName());
        return 1;
    }
    case M_enabled:
    {
        val->SetBool((pDispObj->Flags & InteractiveObject::Mask_Enabled) != 0);
        return 1;
    }
    case M_trackAsMenu:
    {
        val->SetBool((pDispObj->Flags & InteractiveObject::Mask_TrackAsMenu) != 0);
        return 1;
    }
    case M_target:
    {
        StringBuffer       path;
        Ptr<DisplayObject> ptop = GetTopParent();
        PrependNamePath(path, pDispObj, ptop);
        val->SetString(GetASEnvironment()->CreateString(path.ToCStr(), path.GetSize()));
        return 1;
    }
    case M_parent:
    {
        if (pDispObj->GetParent())
            val->SetAsCharacter(pDispObj->GetParent());
        else
            val->SetUndefined();
        return 1;
    }
    case M_droptarget:
    {
        val->SetUndefined();
        MovieImpl*         proot    = GetASEnvironment()->GetTarget()->GetMovieImpl();
        Render::PointF     mousePos = proot->MouseLastPosition;
        InteractiveObject* ptopCh   = proot->GetTopMostEntity(mousePos, 0, true, pDispObj);
        StringBuffer       name;
        for (const DisplayObject* p = ptopCh; p != 0; p = p->GetParent())
        {
            ASString cname = p->GetName();
            name.Insert(cname.ToCStr(), 0);
            name.Insert("/", 0);
        }
        val->SetString(GetASEnvironment()->CreateString(name.ToCStr(), name.GetSize()));
        return 1;
    }
    case M_url:
    {
        ArrayPOD<char> buf;
        const char*    purl = pDispObj->GetResourceMovieDef()->GetFileURL();
        UPInt          len  = purl ? strlen(purl) : 0;
        buf.Resize(len + 1);
        for (UPInt i = 0; i < len; ++i)
            buf[i] = (purl[i] == '\\') ? '/' : purl[i];
        buf[len] = 0;
        String escaped;
        ASUtils::EscapePath(&buf[0], len, &escaped);
        val->SetString(GetASEnvironment()->CreateString(escaped));
        return 1;
    }
    case M_highquality:
    {
        val->SetBool(true);
        return 1;
    }
    case M_quality:
    {
        val->SetString(GetASEnvironment()->CreateString("HIGH"));
        return 1;
    }
    case M_focusrect:
    {
        const unsigned f = pDispObj->Flags & InteractiveObject::Mask_FocusRect;
        if (f)
            val->SetBool(f == InteractiveObject::Mask_FocusRect);
        else
            val->SetNull();
        return 1;
    }
    case M_soundbuftime:
    {
        val->SetNumber(0.0);
        return 1;
    }
    case M_xmouse:
    {
        val->SetNumber(pDispObj->GetMouseX());
        return 1;
    }
    case M_ymouse:
    {
        val->SetNumber(pDispObj->GetMouseY());
        return 1;
    }
    case M_tabEnabled:
    {
        const unsigned f = pDispObj->Flags & InteractiveObject::Mask_TabEnabled;
        if (f)
            val->SetBool(f == InteractiveObject::Mask_TabEnabled);
        else
            val->SetUndefined();
        return 1;
    }
    case M_tabIndex:
        val->SetNumber((Number)pDispObj->TabIndex);
        return 1;
    case M_useHandCursor:
    {
        const unsigned f = pDispObj->Flags & InteractiveObject::Mask_UseHandCursor;
        if (!f)
            return 0;
        val->SetBool(f == InteractiveObject::Mask_UseHandCursor);
        return 1;
    }
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
                BitmapFilterObject* pfilterobj = Sfr05gbCreateFromDesc(penv, psc, *f);
                if (pfilterobj)
                {
                    {
                        Value v(pfilterobj);
                        parr->PushBack(v);
                    }
                    pfilterobj->Release();
                }
            }
        }
        val->SetAsObject(parr);
    }
        return 1;

    case M_edgeaaMode:
    {
        switch (pDispObj->GetRenderNode()->GetEdgeAAMode())
        {
        case Render::EdgeAA_On:      val->SetNumber(1); break;
        case Render::EdgeAA_Off:     val->SetNumber(2); break;
        case Render::EdgeAA_Disable: val->SetNumber(3); break;
        default:                     val->SetNumber(0); break;
        }
        return 1;
    }

    default:
        break;
    }

    return 0;
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
// @0x142955c50
bool AvmSprite::GetStandardMember(StandardMember index, Value* val, bool opcodeFlag) const
{
    if (AvmCharacter::GetStandardMember(index, val, opcodeFlag))
        return true;
    switch (index)
    {
    case M_currentframe:
        val->SetInt_Call(GetSprite()->GetCurrentFrame() + 1);
        return true;
    case M_totalframes:
        val->SetInt_Call(GetSprite()->pDef->GetFrameCount());
        return true;
    case M_framesloaded:
        val->SetInt_Call(GetSprite()->GetLoadingFrame());
        return true;
    case M_lockroot:
        val->SetBool((GetSprite()->Flags & Sprite::Flags_LockRoot) != 0);
        return true;
    case M_focusEnabled:
        SetBool3W(val, GetSprite()->FocusEnabled);
        return true;
    case M_tabChildren:
        SetBool3W(val, *reinterpret_cast<const SByte*>(&Unrecovered_1f8));
        return true;
    case M_hitArea:
        if (GetSprite()->pHitAreaHandle)
        {
            val->SetAsCharacterHandle(GetSprite()->pHitAreaHandle);
            return true;
        }
        else
            val->SetUndefined();
        break;
    case M_scale9Grid:
    {
        if (GetASEnvironment()->GetVersion() >= 8)
        {
            if (GetSprite()->HasScale9Grid())
            {
                RectF                sg   = GetSprite()->GetScale9Grid();
                Environment*         penv = const_cast<Environment*>(GetASEnvironment());
                Ptr<RectangleObject> rect = *SF_HEAP_NEW(penv->GetHeap()) RectangleObject(penv);
                ASRect gr(Render::TwipsToPixels(sg.x1), Render::TwipsToPixels(sg.y1),
                          Render::TwipsToPixels(sg.x2), Render::TwipsToPixels(sg.y2));
                rect->SetProperties(penv, gr);
                val->SetAsObject(rect);
            }
            else
                val->SetUndefined();
            return true;
        }
        break;
    }
    case M_scrollRect:
    {
        if (GetASEnvironment()->GetVersion() >= 8)
        {
            if (GetSprite()->pScrollRect)
            {
                Render::RectD        r    = GetSprite()->pScrollRect->Rectangle;
                Environment*         penv = const_cast<Environment*>(GetASEnvironment());
                Ptr<RectangleObject> rect = *SF_HEAP_NEW(penv->GetHeap()) RectangleObject(penv);
                ASRect gr(Render::TwipsToPixels(r.x1), Render::TwipsToPixels(r.y1),
                          Render::TwipsToPixels(r.x2), Render::TwipsToPixels(r.y2));
                rect->SetProperties(penv, gr);
                val->SetAsObject(rect);
            }
            else
                val->SetUndefined();
            return true;
        }
        break;
    }
    case M_hitTestDisable:
        if (GetASEnvironment()->CheckExtensions())
        {
            val->SetBool((static_cast<const InteractiveObject*>(GetSprite())->Flags & InteractiveObject::Mask_HitTestDisable) != 0);
            return true;
        }
        break;
    default:
        break;
    }
    return false;
}

// count elements of the AS2 array at the path from index on, into the host's array of ints, doubles, floats,
// strings (kept alive by the movie's return value holder), wide strings (in its character buffer) or values.
// Missing elements give 0 (NULL for strings). False when the path is not an array.
// MS2-FUNCTIONAL 6 bytes: the first level scan's index copy is in r9 in the exe, r8 here (the rest matches); no source form found
// @0x142957270
bool MovieRoot::GetVariableArray(SetArrayTypeArg type, const char* ppathToVar, unsigned index, void* pdata,
                                 unsigned count)
{
    if (!Sfr05gb_GetLevelMovie(pMovieImpl, 0))
        return false;
    AvmDisplayObjBase* pavm = Sfr05gb_GetLevelMovie(pMovieImpl, 0)->GetAvmObjImpl();
    Environment* penv = static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(pavm))->GetASEnvironment();
    ASString path(penv->CreateString(ppathToVar));

    Value retVal;
    if (penv->GetVariable(path, &retVal) && retVal.IsObject())
    {
        Object* pobj = retVal.ToObject(penv);
        if (pobj && pobj->GetObjectType() == Object::Object_Array)
        {
            MovieImpl::ReturnValueHolder* rvHolder = pMovieImpl->GetRetValHolder();
            rvHolder->StringArrayPos = 0;
            Sfr05gb_ResizeStringArray(rvHolder, 0);

            ArrayObject* parray  = static_cast<ArrayObject*>(pobj);
            unsigned     arrSize = parray->GetSize();
            switch (type)
            {
            case 0: // SA_Int
            {
                int* parr = static_cast<int*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    Value* pval = parray->GetElementPtr(i + index);
                    if (pval)
                        parr[i] = (int)pval->ToNumber(penv);
                    else
                        parr[i] = 0;
                }
            }
            break;
            case 2: // SA_Float
            {
                float* parr = static_cast<float*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    Value* pval = parray->GetElementPtr(i + index);
                    if (pval)
                        parr[i] = (float)pval->ToNumber(penv);
                    else
                        parr[i] = 0;
                }
            }
            break;
            case 1: // SA_Double
            {
                Double* parr = static_cast<Double*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    Value* pval = parray->GetElementPtr(i + index);
                    if (pval)
                        parr[i] = (Double)pval->ToNumber(penv);
                    else
                        parr[i] = 0;
                }
            }
            break;
            case 5: // SA_Value
            {
                GFx::Value* parr = static_cast<GFx::Value*>(pdata);
                for (unsigned i = 0, n = Alg::Min(arrSize, count); i < n; ++i)
                {
                    Value*      pval     = parray->GetElementPtr(i + index);
                    GFx::Value* pdestVal = &parr[i];
                    pdestVal->SetUndefined();
                    if (pval)
                        ASValue2GFxValue(penv, *pval, pdestVal);
                }
            }
            break;
            case 3: // SA_String
            {
                const char** parr = static_cast<const char**>(pdata);
                unsigned     n    = Alg::Min(arrSize, count);
                Sfr05gb_ResizeStringArray(rvHolder, n);
                for (unsigned i = 0; i < n; ++i)
                {
                    Value* pval = parray->GetElementPtr(i + index);
                    if (pval)
                    {
                        ASString str = pval->ToString(penv);
                        parr[i]      = str.ToCStr();
                        rvHolder->StringArray[rvHolder->StringArrayPos++] = str;
                    }
                    else
                        parr[i] = NULL;
                }
            }
            break;
            case 4: // SA_StringW
            {
                const wchar_t** parr = static_cast<const wchar_t**>(pdata);
                unsigned        i, bufSize = 0;
                unsigned        n = Alg::Min(arrSize, count);
                Sfr05gb_ResizeStringArray(rvHolder, n);
                for (i = 0; i < arrSize; ++i)
                {
                    Value* pval = parray->GetElementPtr(i + index);
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

                for (i = 0; i < n; ++i)
                {
                    const char* psrcStr  = rvHolder->StringArray[i].ToCStr();
                    wchar_t*    pwdstStr = pwBuffer;
                    UInt32      code;
                    while ((code = UTF8Util::DecodeNextChar(&psrcStr)) != 0)
                    {
                        *pwBuffer++ = (wchar_t)code;
                    }
                    *pwBuffer++ = 0;

                    parr[i] = pwdstStr;
                }
                Sfr05gb_ResizeStringArray(rvHolder, 0);
            }
            break;
            }
            return true;
        }
    }
    return false;
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

}}} // namespace Scaleform::GFx::AS2
// The out-of-line CompareBuiltIn_CaseCheck the exe calls (sfr_video_01).
bool FUN_14000a090(Scaleform::GFx::ASStringNode** left, Scaleform::GFx::ASStringNode** right, bool caseSensitive);
namespace Scaleform { namespace GFx { namespace AS2 {

static SF_FORCEINLINE bool Sfr05gb_CompareBuiltIn_CaseCheck(const ASString& builtin, const ASString& str,
                                                            bool caseSensitive)
{
    return ::FUN_14000a090(reinterpret_cast<ASStringNode**>(const_cast<ASString*>(&builtin)),
                           reinterpret_cast<ASStringNode**>(const_cast<ASString*>(&str)), caseSensitive);
}

// Environment::GetTopLocalFrame (0x142956740, sfr_as2_05), inlined here in the exe.
static SF_FORCEINLINE LocalFrame* Sfr05gb_GetTopLocalFrame(const Environment* penv, int off)
{
    if (penv->LocalFrames.GetSize() - off > 0)
        return penv->LocalFrames[penv->LocalFrames.GetSize() - off - 1];
    return 0;
}

// Value::ToObjectInterface with Value::ToAvmCharacter and Value::ToCharacter (sfr_as2_07)
// inlined, as the exe has them here (penv is this, so no null test).
static SF_FORCEINLINE ObjectInterface* Sfr05gb_ToObjectInterface(const Value& v, const Environment* penv)
{
    if (v.GetType() == Value::CHARACTER)
    {
        InteractiveObject* pchar = 0;
        if (v.V.pCharHandle)
        {
            DisplayObject* pdisp = v.V.pCharHandle->ResolveCharacter(penv->GetTarget()->GetMovieImpl());
            if (pdisp)
                pchar = pdisp->IsInteractiveObject() ? static_cast<InteractiveObject*>(pdisp) : 0;
        }
        AvmCharacter* pavm = pchar ? AS2::ToAvmCharacter(pchar) : 0;
        return pavm;
    }
    return v.ToObject(penv);
}

// WithStackEntry::GetObjectInterface (0x1429540c0, sfr_as2_05), inlined here in the exe.
static SF_FORCEINLINE ObjectInterface* Sfr05gb_GetObjectInterface(const WithStackEntry& e)
{
    bool               isObject = e.IsObject != 0;
    InteractiveObject* pch      = e.pCharacter;
    if (isObject)
        return e.pObject;
    if (!pch)
        return 0;
    return AS2::ToAvmCharacter(pch);
}

// Environment::FindLocal(name, pvalue) (SDK inline): copies a found local out.
static SF_FORCEINLINE bool Sfr05gb_FindLocal(const Environment* penv, const ASString& varname, Value* pvalue)
{
    const Value* pval = penv->FindLocal(varname);
    if (pval && pvalue)
    {
        *pvalue = *pval;
        return true;
    }
    return (pval != NULL);
}

// A plain name through the scope chain: the with stack (innermost first; a dead entry ends the lookup), the locals
// ("arguments" made on first use from SWF5, "super" from SWF6, cached as a local), "this", the target's members,
// _global/_root/_levelN and the members of _global. The owner, when asked for, is 0 until something is found.
// MS2-FUNCTIONAL 1910 vs 1907 bytes: at the "arguments" and "super" checks the exe sets r8b (version > 6) before building the builtin's address and reuses the version compare; cl here sets it after and compares again (3 bytes). No source form found
// @0x142957b10
bool Environment::GetVariableRaw(const GetVarParams& params) const
{
    if (!params.pResult)
        return false;

    if (params.pOwnerValue)
        *params.pOwnerValue = Value(0);
    if (params.pWithStack)
    {
        for (int i = (int)params.pWithStack->GetSize() - 1; i >= 0; i--)
        {
            ObjectInterface* obj = Sfr05gb_GetObjectInterface((*params.pWithStack)[i]);

            if (obj == NULL)
                return false;

            if (obj && obj->GetMember(const_cast<Environment*>(this), params.VarName, params.pResult))
            {
                if (params.pOwnerValue)
                {
                    if (obj->IsASCharacter())
                        params.pOwnerValue->SetAsCharacter(obj->ToCharacter_Call());
                    else
                        params.pOwnerValue->SetAsObject(obj->ToASObject());
                }
                return true;
            }
        }
    }

    if (!(params.ExcludeFlags & Sfr05gb_IgnoreLocals))
    {
        if (Sfr05gb_FindLocal(this, params.VarName, params.pResult))
        {
            return true;
        }
        else if (GetVersion() >= 5)
        {
            if (Sfr05gb_CompareBuiltIn_CaseCheck(GetBuiltin(ASBuiltin_arguments), params.VarName, IsCaseSensitive()))
            {
                LocalFrame* pLocFr = Sfr05gb_GetTopLocalFrame(this, 0);
                if (pLocFr)
                {
                    Environment*     penv = const_cast<Environment*>(this);
                    ASStringContext* psc  = penv->GetSC();

                    Ptr<ArrayObject> pargArray = *SF_HEAP_NEW(GetHeap()) ArrayObject(penv);
                    pargArray->Resize(pLocFr->NArgs);
                    for (int i = 0; i < pLocFr->NArgs; i++)
                        pargArray->SetElement(i, *pLocFr->Env->Bottom(pLocFr->FirstArgBottomIndex - i));

                    penv->AddLocal(psc->GetBuiltin(ASBuiltin_arguments), Value(pargArray.GetPtr()));
                    pargArray->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_callee), pLocFr->Callee,
                                            PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete |
                                                PropFlags::PropFlag_ReadOnly);
                    pargArray->SetMemberRaw(psc, psc->GetBuiltin(ASBuiltin_caller), pLocFr->Caller,
                                            PropFlags::PropFlag_DontEnum | PropFlags::PropFlag_DontDelete |
                                                PropFlags::PropFlag_ReadOnly);
                    params.pResult->SetAsObject(pargArray);
                    return true;
                }
            }
            else if (GetVersion() >= 6)
            {
                if (Sfr05gb_CompareBuiltIn_CaseCheck(GetBuiltin(ASBuiltin_super), params.VarName, IsCaseSensitive()))
                {
                    LocalFrame* pLocFr = Sfr05gb_GetTopLocalFrame(this, 0);
                    if (pLocFr && pLocFr->SuperThis)
                    {
                        ObjectInterface* const iobj = pLocFr->SuperThis;
                        Ptr<Object>            superObj;
                        Ptr<Object>            proto = iobj->Get__proto__();

                        if (proto)
                        {
                            Value thisVal;
                            FindAndGetVariableRaw(GetVarParams(GetBuiltin(ASBuiltin_this), &thisVal, params.pWithStack));

                            FunctionRef __ctor__ = proto->Get__constructor__(const_cast<Environment*>(this)->GetSC());
                            superObj = *SF_HEAP_NEW(GetHeap())
                                SuperObject(proto->Get__proto__(), Sfr05gb_ToObjectInterface(thisVal, this), __ctor__);

                            params.pResult->SetAsObject(superObj);
                            const_cast<Environment*>(this)->SetLocal(GetBuiltin(ASBuiltin_super), *params.pResult);
                            return true;
                        }
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
    if (AS2::ToAvmCharacter(Target)->GetMemberRaw(const_cast<Environment*>(this)->GetSC(), params.VarName, params.pResult))
    {
        if (params.pOwnerValue)
            *params.pOwnerValue = Target;
        return true;
    }

    Object* pglobal = StringContext.pContext->pGlobal;
    if (!(params.ExcludeFlags & Sfr05gb_IgnoreContainers))
    {
        if (params.VarName.GetLength() > 0 && params.VarName[0] == '_')
        {
            Bool3W rv = CheckGlobalAndLevels(params);
            if (rv.IsDefined())
                return rv.IsTrue();
        }
    }

    if (pglobal && pglobal->GetMember(const_cast<Environment*>(this), params.VarName, params.pResult))
    {
        if (params.pOwnerValue)
            *params.pOwnerValue = pglobal;
        return true;
    }

    if (!(params.ExcludeFlags & Sfr05gb_NoLogOutput))
        LogAction("GetVariableRaw(\"%s\") failed, returning UNDEFINED.\n", params.VarName.ToCStr());
    return false;
}

}}} // namespace Scaleform::GFx::AS2
