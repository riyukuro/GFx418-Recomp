// Recovered Scaleform 4.1.18 GFx AS2: the action execution environment (paged value stack, registers, target,
// call stack, try blocks, local frames), native call frames (FnCall) and the global context.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_ACTION_H
#define MS2_SF_GFX_AS2_ACTION_H

#include "as2_object.h"
#include "../gfx_asstringhash.h"
#include "../gfx_log.h"
#include "../gfx_types.h"

namespace Scaleform { namespace GFx {

template<class T> class ASStringHash;

namespace AS2 {

enum ASBuiltinType : int;

// The log of the action interpreter with the movie's verbosity switches.
class ActionLogger : public LogBase<ActionLogger>
{
public:
    Log*        pLog;                // +0x08
    bool        VerboseAction;       // +0x10
    bool        VerboseActionErrors; // +0x11
    bool        UseSuffix;           // +0x12 LogSuffix follows every message
    const char* LogSuffix;           // +0x18

    Log*         GetLog() const { return pLog; }
    bool         IsVerboseAction() const { return VerboseAction; }
    virtual bool IsVerboseActionErrors() const { return VerboseActionErrors; }

    // Sends the message to pLog, with " : LogSuffix" appended when UseSuffix is set.
    void LogScriptMessageVarg(LogMessageId messageType, const char* pfmt, va_list argList);
    void LogScriptError(const char* pfmt, ...);   // exe 0x142967d10
    void LogScriptWarning(const char* pfmt, ...); // exe 0x142968280
    void LogScriptMessage(const char* pfmt, ...); // exe 0x142967fc0
};

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

    // Destroys every element down to the bottom one, then frees the pages (exe 0x142924c60 for Value).
    ~PagedStack()
    {
        Pop(GetTopIndex());
        pCurrent->~T();
        Page* plast  = Pages.Back();
        plast->pNext = pReserved;
        pReserved    = plast;
        while (pReserved)
        {
            Page* pnext = pReserved->pNext;
            SF_FREE(pReserved);
            pReserved = pnext;
        }
    }

    // Index of the top element counted from the bottom of the stack.
    unsigned GetTopIndex() const { return ((unsigned)Pages.GetSize() - 1) * PageSize + (unsigned)(pCurrent - pPageStart); }

    T* Top0() { return pCurrent; }

    // Moves to the first element of the next page: the reserved page or a new one (exe 0x140006a40 for Value).
    void PushPage();
    // Back to the top of the previous page; on the bottom page one undefined element is left (exe 0x140006cf0 for
    // Value).
    void PopPage();

    void Push(const T& val)
    {
        pCurrent++;
        if (pCurrent >= pPageEnd)
            PushPage();
        Construct<T>(pCurrent, val);
    }
    void Pop1()
    {
        pCurrent->~T();
        if (--pCurrent < pPageStart)
            PopPage();
    }
    void Pop(unsigned n)
    {
        for (; n; n--)
            Pop1();
    }

    // Element at a distance from the top, 0 past the bottom.
    T* Top(unsigned dist)
    {
        T* p = 0;
        if (dist <= GetTopIndex())
        {
            unsigned offset = GetTopIndex() - dist;
            p = &Pages[offset / PageSize]->Values[offset % PageSize];
        }
        return p;
    }
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

    Value& Top(int dist) { return *Stack.Top((unsigned)dist); }
    Value* Bottom(int offset) { return Stack.Bottom((unsigned)offset); }
    int    GetTopIndex() const { return (int)Stack.GetTopIndex(); }
    void   Push(const Value& val) { Stack.Push(val); }
    void   Drop1() { Stack.Pop1(); }
    // Pops n values.
    void   Drop(int n)
    {
        while (n--)
            Stack.Pop1();
    }

    ASStringContext* GetSC() { return &StringContext; }
    unsigned         GetVersion() const { return StringContext.GetVersion(); }
    // Ends the unrolling of a throw (exe 0x1429345d0).
    void ClearThrowing();
    // Drops the try blocks pc has left; *plocalTryBlockCount counts those of the running action buffer (exe
    // 0x142933d80).
    void CheckTryBlocks(int pc, int* plocalTryBlockCount);

    // Local variables of the innermost function frame.
    const Value* FindLocal(const ASString& varname) const;      // exe 0x142944690
    void         AddLocal(const ASString& varname, const Value& val); // exe 0x14292ff50 (it must not exist yet)
    void         DeclareLocal(const ASString& varname);         // exe 0x142938180 (undefined unless it exists)
    // The movie enabled the Scaleform extensions to ActionScript.
    inline bool CheckExtensions() const;
    inline MemoryHeap* GetHeap() const;
    inline Object*     GetPrototype(ASBuiltinType type) const;
    // Collector of the target's movie, 0 without a target.
    inline ASRefCountCollector* GetCollector(); // as2_avmcharacter.h
    InteractiveObject* GetTarget() const { return Target; }
    AvmCharacter*      GetAvmTarget() const; // exe 0x142949840 (0 without a target)
    Log*               GetLog() const;       // exe 0x14294b210
    MovieImpl*         GetMovieImpl() const; // exe 0x142953ee0
    MovieRoot*         GetAS2Root() const;   // exe 0x142949080
    // The off-th function frame from the innermost one, 0 past the outermost (exe 0x142956740).
    LocalFrame*        GetTopLocalFrame(int off = 0) const;
    // The character a value names (a character, or a target path string), 0 if none (exe 0x142944f40).
    InteractiveObject* FindTargetByValue(const Value& val);
    // The constructor of a builtin class from _global, null if it is not a function (exe 0x14294a0f0).
    FunctionRef        GetConstructor(ASBuiltinType className);

    // Script error channel (exe 0x142967e00).
    void LogScriptError(const char* pfmt, ...) const;
    // Script warning channel (exe 0x142968370).
    void LogScriptWarning(const char* pfmt, ...) const;
    // Script message channel (exe 0x1429680b0).
    void LogScriptMessage(const char* pfmt, ...) const;

    // Local register reg counted from the top of the register array; global register 0 (after an error) when
    // out of range (exe 0x142967390).
    Value*          LocalRegisterPtr(unsigned reg);
    // Enters a try block (exe 0x142972410).
    void            PushTryBlock(const TryDescr& descr);
    // Takes the innermost try block off (exe 0x14296f390).
    TryDescr        PopTryBlock();
    // The name is a target path (has ':', '/' or '.'); the answer is cached in the string (exe 0x142965d10).
    static bool     IsPath(const ASString& varPath);
    // A Boolean / String / Number object wrapping the primitive at a distance from the top (or the given one),
    // undefined for other types (exe 0x14296f770 / 0x14296f640).
    Value           PrimitiveToTempObject(int index);
    Value           PrimitiveToTempObject(const Value& v);

    // new <className>(args) looked up in the package object (exe 0x14296e520); the other one in _global.
    Object*        OperatorNew(Object* ppackageObj, const ASString& className, int nargs = 0, int argsTopOff = -1);
    inline Object* OperatorNew(const ASString& className, int nargs = 0, int argsTopOff = -1);
    inline const ASString& GetBuiltin(int btype) const;
    inline ASString        CreateString(const char* pstr, UPInt length) const;
    inline ASString        CreateString(const char* pstr) const; // as2_movieroot.h
    inline ASString        CreateString(const String& str) const; // as2_movieroot.h
};

// A try block entered by the running code. 0x10 bytes.
struct Environment::TryDescr
{
    const UByte* pTryBlock;     // +0x00 the ActionTry record
    unsigned     TryBeginPC;    // +0x08
    unsigned     TopStackIndex; // +0x0c

    TryDescr() { TopStackIndex = 0; }

    unsigned GetTrySize() const { return pTryBlock[1] | (((UInt16)pTryBlock[2]) << 8); }
};

// The out-of-line Resize of the try block array (exe 0x14297e060, a COMDAT the exe calls where cl inlines it).
void TryBlocks_Resize(ArrayLH<Environment::TryDescr, Stat_Default_Mem>* ptryBlocks, UPInt newSize);

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

    // The arguments are the nargs stack values from firstArgBottomIndex down.
    FnCall(Value* res, ObjectInterface* pthis, Environment* penv, int nargs, int firstArgBottomIndex)
        : Result(res), ThisPtr(pthis), Env(penv), NArgs(nargs), FirstArgBottomIndex(firstArgBottomIndex)
    {
    }

    Log* GetLog() const; // exe 0x14294b230

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

    HashUncachedLH<ASBuiltinType, Ptr<Object>, FixedSizeHash<ASBuiltinType> > Prototypes; // +0x10 builtin prototypes
    ASStringHash<FunctionRef> RegisteredClasses; // +0x18 class constructors by name (Object.registerClass)
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

    // The builtin prototype of the type (exe 0x142954ba0).
    Object* GetPrototype(ASBuiltinType type);

    ASRefCountCollector* GetGC();                     // exe 0x14294afc0 (0 without a movie)
    StringManager*       GetStringManager() const;    // exe 0x1429561c0

    // Registers the builtin class of the name on first use; its constructor function (exe 0x14297ea30).
    FunctionObject* ResolveFunctionName(const ASString& functionName);

    // The constructor registered for the class name (exe 0x142944c60).
    bool FindRegisteredClass(ASStringContext* psc, const ASString& className, FunctionRef* pctorFunction);
};

enum { StatMD_ASBinaryData_Mem = 0x108 };

// The bytes of an action block (DoAction, a function body or a clip event), shared by the buffers running it.
// 0x28 bytes.
class ActionBufferData : public RefCountBase<ActionBufferData, StatMD_ASBinaryData_Mem>
{
protected:
    ActionBufferData() : pBuffer(0), BufferLen(0), SwdHandle(0), SWFFileOffset(0) {}

public:
    ~ActionBufferData()
    {
        if (pBuffer)
            SF_FREE(pBuffer);
    }

    static ActionBufferData* CreateNew(); // exe 0x142936620

protected:
    UByte*   pBuffer;       // +0x10
    unsigned BufferLen;     // +0x18
    UInt32   SwdHandle;     // +0x1c
    UInt32   SWFFileOffset; // +0x20
};

SF_FORCEINLINE void FunctionRefBase::DropRefs()
{
    if (!(Flags & FuncRef_Internal) && Function)
        Function->Release();
    Function = 0;
    if (!(Flags & FuncRef_Weak) && pLocalFrame)
        pLocalFrame->Release();
    pLocalFrame = 0;
}

inline bool Environment::CheckExtensions() const
{
    return StringContext.pContext->CheckExtensions();
}

inline MemoryHeap* Environment::GetHeap() const
{
    return StringContext.pContext->pHeap;
}

inline MemoryHeap* ASStringContext::GetHeap() const
{
    return pContext->pHeap;
}

inline Object* Environment::GetPrototype(ASBuiltinType type) const
{
    return StringContext.pContext->GetPrototype(type);
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
