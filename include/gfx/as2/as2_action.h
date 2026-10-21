// Recovered Scaleform 4.1.18 GFx AS2: the action execution environment (paged value stack, registers, target,
// call stack, try blocks, local frames), native call frames (FnCall) and the global context.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_ACTION_H
#define MS2_SF_GFX_AS2_ACTION_H

#include "as2_object.h"
#include "../gfx_log.h"
#include "../gfx_types.h"

namespace Scaleform { namespace GFx {

template<class T> class ASStringHash;

namespace AS2 {

class ActionLogger;
enum ASBuiltinType : int;

// Stack growing in pages of PageSize elements; elements stay in place when pages are added. 0x40 bytes.
template<class T, int PageSize = 32>
class PagedStack : public NewOverrideBase<StatMV_ActionScript_Mem>
{
public:
    struct Page
    {
        T     Values[PageSize];
        Page* pNext;
    };

    T*    pCurrent;     // +0x00 top element
    T*    pPageStart;   // +0x08
    T*    pPageEnd;     // +0x10
    T*    pPrevPageTop; // +0x18
    ArrayLH<Page*, Stat_Default_Mem> Pages; // +0x20
    Page* pReserved;    // +0x38

    // Index of the top element counted from the bottom of the stack.
    unsigned GetTopIndex() const { return ((unsigned)Pages.GetSize() - 1) * PageSize + (unsigned)(pCurrent - pPageStart); }

    T* Top0() { return pCurrent; }

    // Element at an index counted from the bottom, 0 past the top.
    T* Bottom(unsigned offset)
    {
        T* p = 0;
        if (offset <= GetTopIndex())
            p = &Pages[offset / PageSize]->Values[offset % PageSize];
        return p;
    }
};

// Script execution context of a target character. 0x198 bytes.
class Environment : public LogBase<Environment>, public NewOverrideBase<StatMV_ActionScript_Mem>
{
public:
    struct TryDescr;

    PagedStack<Value, 32>                     Stack;                 // +0x08
    Value                                     GlobalRegister[4];     // +0x48
    ArrayLH<Value, Stat_Default_Mem>          LocalRegister;         // +0xc8
    InteractiveObject*                        Target;                // +0xe0
    ASStringContext                           StringContext;         // +0xe8
    PagedStack<Ptr<FunctionObject>, 32>       CallStack;             // +0xf8
    ActionLogger*                             pASLogger;             // +0x138
    ArrayLH<TryDescr, Stat_Default_Mem>       TryBlocks;             // +0x140
    Value                                     ThrowingValue;         // +0x158
    int                                       ExecutionNestingLevel; // +0x178
    UInt16                                    FuncCallNestingLevel;  // +0x17c
    bool                                      Unrolling : 1;         // +0x17e
    bool                                      IsInvalidTarget : 1;
    ArrayLH<Ptr<LocalFrame>, Stat_Default_Mem> LocalFrames;          // +0x180

    Value* Bottom(int offset) { return Stack.Bottom((unsigned)offset); }

    ASStringContext* GetSC() { return &StringContext; }
    // The movie enabled the Scaleform extensions to ActionScript.
    inline bool CheckExtensions() const;
    inline MemoryHeap* GetHeap() const;
    InteractiveObject* GetTarget() const { return Target; }

    // Script error channel (exe 0x142967e00).
    void LogScriptError(const char* pfmt, ...) const;

    // new <className>(args) looked up in the package object (exe 0x14296e520); the other one in _global.
    Object*        OperatorNew(Object* ppackageObj, const ASString& className, int nargs = 0, int argsTopOff = -1);
    inline Object* OperatorNew(const ASString& className, int nargs = 0, int argsTopOff = -1);
    inline const ASString& GetBuiltin(int btype) const;
    inline ASString        CreateString(const char* pstr, UPInt length) const;
    inline ASString        CreateString(const char* pstr) const; // as2_movieroot.h
};

// Arguments, this and result slot of a native call. 0x40 bytes.
class FnCall : public LogBase<FnCall>
{
public:
    Value*           Result;              // +0x08
    ObjectInterface* ThisPtr;             // +0x10
    FunctionRef      ThisFunctionRef;     // +0x18
    Environment*     Env;                 // +0x30
    int              NArgs;               // +0x38
    int              FirstArgBottomIndex; // +0x3c

    // Argument n (0 = first), read from the environment stack below the first argument.
    Value& Arg(int n) const { return *Env->Bottom(FirstArgBottomIndex - n); }

    // This is a script object of the given type.
    bool CheckThisPtr(unsigned type) const { return ThisPtr && ThisPtr->GetObjectType() == (int)type; }
    void ThisPtrError(const char* pclassName) const
    {
        Env->LogScriptError("Error: Null or invalid 'this' is used for a method of %s class.\n", pclassName);
    }
};

// Bails out of a native method when this is not of the class.
#define MS2_AS2_CHECK_THIS(fn, cls)                          \
    if (!(fn).CheckThisPtr(ObjectInterface::Object_##cls))   \
    {                                                        \
        (fn).ThisPtrError(#cls);                             \
        return;                                              \
    }

// Activation frame of a script function. 0x88 bytes.
class LocalFrame : public ASRefCountBase<LocalFrame>
{
public:
    ASStringHash_GC<Value> Variables;           // +0x20
    Ptr<LocalFrame>        PrevFrame;           // +0x28
    ObjectInterface*       SuperThis;           // +0x30
    Environment*           Env;                 // +0x38
    int                    NArgs;               // +0x40
    int                    FirstArgBottomIndex; // +0x44
    Value                  Callee;              // +0x48
    Value                  Caller;              // +0x68

private:
    // The variables, the previous frame, callee and caller (defined in sfr_as2_02).
    template<class Functor> void ForEachChild_GC(Collector* prcc) const;
};

// Per movie AS2 state: builtin prototypes, registered classes, the _global object. 0x78 bytes.
class GlobalContext : public RefCountBaseNTS<GlobalContext, StatMV_ActionScript_Mem>
{
public:
    struct ClassRegEntry;

    void*              Prototypes;             // +0x10 HashUncachedLH<ASBuiltinType, Ptr<Object>>
    void*              RegisteredClasses;      // +0x18 ASStringHash<FunctionRef>
    void*              BuiltinClassesRegistry; // +0x20 ASStringHash<ClassRegEntry>
    MovieImpl*         pMovieRoot;             // +0x28
    MemoryHeap*        pHeap;                  // +0x30
    Object*            FlashGeomPackage;       // +0x38
    Object*            SystemPackage;          // +0x40
    Object*            FlashExternalPackage;   // +0x48
    Object*            FlashDisplayPackage;    // +0x50
    Object*            FlashFiltersPackage;    // +0x58
    Ptr<Object>        pGlobal;                // +0x60
    Bool3W             GFxExtensions;          // +0x68
    void*              StandardMemberMap;      // +0x70 ASStringHash<char>

    bool CheckExtensions() const { return GFxExtensions.IsTrue(); }
};

inline bool Environment::CheckExtensions() const
{
    return StringContext.pContext->CheckExtensions();
}

inline MemoryHeap* Environment::GetHeap() const
{
    return StringContext.pContext->pHeap;
}

inline Object* Environment::OperatorNew(const ASString& className, int nargs, int argsTopOff)
{
    return OperatorNew(StringContext.pContext->pGlobal, className, nargs, argsTopOff);
}

inline const ASString& Environment::GetBuiltin(int btype) const
{
    return StringContext.GetBuiltin(btype);
}

inline ASString Environment::CreateString(const char* pstr, UPInt length) const
{
    return StringContext.CreateString(pstr, length);
}

}}} // namespace Scaleform::GFx::AS2

#endif
