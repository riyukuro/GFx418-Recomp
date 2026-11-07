// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// the event dispatch of a character, onClipEvent handlers first, then the on<Event> method.
// MS2-UNIT: sfr_as2_05s
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142940160-0x142940997 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_keyboardstate.h"
#include "../include/gfx/gfx_movieimpl.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// Inlined in the exe; defined here as in sfr_as2_06n (as2_action.h only declares it).
inline bool Environment::IsVerboseAction() const
{
    return (GetTarget()->GetMovieImpl()->Flags & MovieImpl::Flag_VerboseAction) != 0;
}

namespace {

struct SetLocalFrameInline05sTag {};

// FunctionRefBase::SetLocalFrame (exe 0x142981e70), expanded in place as the exe has it here (as in sfr_as2_05j).
SF_FORCEINLINE void FunctionRefSetLocalFrame(FunctionRefBase* p, LocalFrame* localFrame, bool weakRef)
{
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->Release();
    p->pLocalFrame = localFrame;
    if (weakRef)
        p->Flags |= FunctionRefBase::FuncRef_Weak;
    else
        p->Flags &= ~FunctionRefBase::FuncRef_Weak;
    if (p->pLocalFrame && !(p->Flags & FunctionRefBase::FuncRef_Weak))
        p->pLocalFrame->AddRef();
}

struct ValueAccess : Value
{
    using Value::ResolveFunctionName;
};

// Value::ToFunction with the FunctionRef copy's SetLocalFrame expanded.
SF_FORCEINLINE FunctionRef ValueToFunction(const Value& v, const Environment* penv)
{
    if (v.GetType() == Value::FUNCTION)
        return FunctionRef(v.V.FunctionValue, SetLocalFrameInline05sTag());
    else if (v.GetType() == Value::FUNCTIONNAME)
        return static_cast<const ValueAccess&>(v).ResolveFunctionName(penv);
    return FunctionRef();
}

inline const char* NamePathOf(DisplayObject* pdispObj)
{
    return pdispObj->GetCharacterHandle()->NamePath.ToCStr();
}

} // namespace

// FunctionRefBase::Init(orig) with the SetLocalFrame call expanded.
template<class Tag>
SF_FORCEINLINE FunctionRef::FunctionRef(const FunctionRefBase& orig, Tag)
{
    Flags    = 0;
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && Function)
        Function->AddRef();
    pLocalFrame = 0;
    if (orig.pLocalFrame)
        FunctionRefSetLocalFrame(this, orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
}

// With the GFx extensions the method gets the button, the roll-over count or the key flag, and the mouse as
// arguments; a nested roll over / out of another mouse only reaches a method taking two or more arguments.
// MS2-FUNCTIONAL: GetMovieImpl, ToFunction with SetLocalFrame and the Value releases are inlined as in the exe; the
// frame is 8 bytes smaller and rbx is pushed where the exe saves it to its home slot
// @0x142940160
bool AvmCharacter::ExecuteEvent(const EventId& id)
{
    // Keep the environment and its target alive during the calls.
    Ptr<InteractiveObject> thisPtr(GetDispObj());
    Environment*           env = GetASEnvironment();
    Ptr<InteractiveObject> targetPtr(env->GetTarget());

    if (id.Id == EventId::Event_KeyDown || id.Id == EventId::Event_KeyUp)
    {
        // Key.getAscii() / Key.getCode() see the key inside onClipEvent(keyDown / keyUp).
        if (MovieImpl* proot = env->GetTarget()->GetMovieImpl())
            proot->GetKeyboardState(id.KeyboardIndex)->UpdateListeners(id);
    }

    int   handlerFoundCnt = 0;
    Value method;

    if (HasClipEventHandler(id) && id.RollOverCnt == 0)
    {
        InvokeClipEventHandlers(env, id);
        ++handlerFoundCnt;
    }

    ASString methodName(env->GetBuiltin(EventId_GetFunctionNameBuiltinType(id)));
    if (methodName.GetSize() > 0 && GetMemberRaw(env->GetSC(), methodName, &method))
    {
        if (method.IsProperty())
        {
            Value actualMethod;
            method.GetPropertyValue(env, this, &actualMethod);
            method = actualMethod;
        }
        if (!method.IsNull())
        {
            if (env->CheckExtensions())
            {
                bool handlerFound = true;
                if (id.RollOverCnt != 0)
                {
                    FunctionRef mfref = ValueToFunction(method, env);
                    if (!mfref.IsNull() && mfref->GetNumArgs() < 2)
                        handlerFound = false;
                }

                if (handlerFound)
                {
                    ++handlerFoundCnt;
                    if (env->IsVerboseAction())
                        env->LogAction("\n!!! ExecuteEvent started '%s' = %p for %s\n", methodName.ToCStr(),
                                       ValueToFunction(method, env).GetObjectPtr(), NamePathOf(pDispObj));

                    int nArgs = 1;
                    env->Push(Value(int(id.ButtonId)));
                    if (id.Id == EventId::Event_RollOver || id.Id == EventId::Event_RollOut ||
                        id.Id == EventId::Event_DragOver || id.Id == EventId::Event_DragOut ||
                        id.Id == EventId::Event_DragOverAux || id.Id == EventId::Event_DragOutAux)
                    {
                        env->Push(Value(int(id.RollOverCnt)));
                        ++nArgs;
                    }
                    else if (id.Id == EventId::Event_Press || id.Id == EventId::Event_Release ||
                             id.Id == EventId::Event_PressAux || id.Id == EventId::Event_ReleaseAux)
                    {
                        // negative when the keyboard was used, 0 for the mouse
                        env->Push(Value(id.KeyCode == 0 ? 0 : -1));
                        ++nArgs;
                    }
                    env->Push(Value(int(id.MouseIndex)));
                    ++nArgs;
                    GAS_Invoke(method, NULL, this, env, nArgs, env->GetTopIndex(), methodName.ToCStr());
                    env->Drop(nArgs);

                    if (env->IsVerboseAction())
                        env->LogAction("!!! ExecuteEvent finished '%s' = %p for %s\n\n", methodName.ToCStr(),
                                       ValueToFunction(method, env).GetObjectPtr(), NamePathOf(pDispObj));
                }
            }
            else if (id.RollOverCnt == 0)
            {
                ++handlerFoundCnt;
                if (env->IsVerboseAction())
                    env->LogAction("\n!!! ExecuteEvent started '%s' = %p for %s\n", methodName.ToCStr(),
                                   ValueToFunction(method, env).GetObjectPtr(), NamePathOf(pDispObj));

                GAS_Invoke(method, NULL, this, env, 0, env->GetTopIndex() + 1, NULL);

                if (env->IsVerboseAction())
                    env->LogAction("!!! ExecuteEvent finished '%s' = %p for %s\n\n", methodName.ToCStr(),
                                   ValueToFunction(method, env).GetObjectPtr(), NamePathOf(pDispObj));
            }
        }
    }
    return handlerFoundCnt != 0;
}

}}} // namespace Scaleform::GFx::AS2
