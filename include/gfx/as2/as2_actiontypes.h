// Recovered Scaleform 4.1.18 GFx AS2: the basic ActionScript 2 VM types (number type, native function signature,
// the cycle-collecting reference count base of every AS2 heap object, the string context).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// Layouts follow the exe (AS2_All, sfr_as2_*): the AS2 GC count word sits at +0x18 (bits 0-25 count, 26 delayed
// release, 27 in list, 28-30 state, 31 buffered), unlike the AS3 collector of include/gfx/as3/as3_gc.h.
#ifndef MS2_SF_GFX_AS2_ACTIONTYPES_H
#define MS2_SF_GFX_AS2_ACTIONTYPES_H

#include "../../kernel/sf_refcount.h"
#include "../../kernel/sf_array.h"
#include "../gfx_asstring.h"

// The exe compiles all of AS2 as one unity build (AS2_All), so callers see what the callees do: a call like
// Value::ToStringImpl is known not to keep the address of its result, and the caller folds the reference count
// traffic on the returned string. Split into units we tell the compiler the same through noalias. Only put this on
// declarations whose exe call sites show the effect (byte-matched callers).
#define MS2_AS2_SCU __declspec(noalias)

namespace Scaleform { namespace GFx {

class InteractiveObject;
class DisplayObject;
class MovieImpl;
class Sprite;

namespace AS2 {

enum { StatMV_ActionScript_Mem = 0x143 };

class Value;
class Object;
class ObjectInterface;
class FnCall;
class Environment;
class GlobalContext;
class ASStringContext;
class ASRefCountCollector;
class StringManager;
class FunctionObject;
class LocalFrame;
class MovieRoot;
class AvmCharacter;
class AvmSprite;

typedef double Number;
typedef void (*CFunctionPtr)(const FnCall& fn);

// One entry of a native method table ({0, 0} terminated).
struct NameFunction
{
    const char*  Name;
    CFunctionPtr Function;

    // Adds every entry of pfunctions to pobj as a C function member.
    static void AddConstMembers(ObjectInterface* pobj, ASStringContext* psc, const NameFunction* pfunctions,
                                UByte flags = 0);
};

struct NameNumber
{
    const char* Name;
    int         Number;
};

template<int Stat> class RefCountCollector;

// Base of all garbage collected AS2 objects: vftable { ExecuteForEachChild_GC, Finalize_GC, dtor }.
template<int Stat = Stat_Default_Mem>
class RefCountBaseGC : public NewOverrideBase<Stat>
{
    friend class RefCountCollector<Stat>;

public:
    typedef RefCountCollector<Stat> Collector;

    enum OperationGC
    {
        Operation_Release,
        Operation_MarkInCycle,
        Operation_ScanInUse
    };

protected:
    enum
    {
        Flag_Buffered       = 0x80000000u,
        Mask_State          = 0x7,
        Shift_State         = 28,
        Flag_InList         = 0x08000000,
        Flag_DelayedRelease = 0x04000000,
        Mask_RefCount       = 0x03FFFFFF
    };

    enum States
    {
        State_InUse   = 0,
        State_InCycle = 1,
        State_Garbage = 2,
        State_Root    = 3,
        State_Removed = 4
    };

    union
    {
        Collector*      pRCC;  // +0x08 owning collector while not in a work list
        RefCountBaseGC* pNext; //       work list link
    };
    union
    {
        UInt32          RootIndex; // +0x10 slot in the root buffer
        RefCountBaseGC* pPrev;
    };
    UInt32 RefCount; // +0x18

    unsigned Decrement() { return (--RefCount) & Mask_RefCount; }
    bool     IsRefCntZero() const { return (RefCount & Mask_RefCount) == 0; }

    virtual void ExecuteForEachChild_GC(Collector*, OperationGC) const {}
    virtual void Finalize_GC() = 0;

    // Frees the object once the count reached zero (out of line, exe 0x1425925f0 for Stat 0x143).
    void ReleaseInternal();

    void     Increment() { ++RefCount; }
    unsigned GetRefCnt() const { return RefCount & Mask_RefCount; }

    void   SetInList()                { RefCount |= Flag_InList; }
    bool   IsInList() const           { return (RefCount & Flag_InList) != 0; }
    void   SetDelayedRelease()        { RefCount |= Flag_DelayedRelease; }
    bool   IsDelayedRelease() const   { return (RefCount & Flag_DelayedRelease) != 0; }
    bool   IsBuffered() const         { return (RefCount & Flag_Buffered) != 0; }
    void   ClearBuffered()
    {
        RefCount &= ~Flag_Buffered;
        if (!IsInList())
            RootIndex = ~0u;
    }
    void   SetState(States c)         { RefCount = (RefCount & ~(Mask_State << Shift_State)) | (((UInt32)c & Mask_State) << Shift_State); }
    States GetState() const           { return (States)((RefCount >> Shift_State) & Mask_State); }
    bool   IsInState(States c) const  { return GetState() == c; }

    // The child visitors of the three collector passes (ForEachChild_GC<Functor> of every collectable class; the
    // collector itself is in as2_refcountcollector.h).
    struct ReleaseFunctor
    {
        SF_FORCEINLINE static void Call(Collector* prcc, RefCountBaseGC* pchild)
        {
            if (pchild->Decrement() == 0)
            {
                prcc->RemoveFromRoots(pchild);
                pchild->SetDelayedRelease();
                prcc->AddToList(pchild);
            }
            else
                pchild->ReleaseInternal();
        }
    };
    struct MarkInCycleFunctor
    {
        SF_FORCEINLINE static void Call(Collector* prcc, RefCountBaseGC* pchild)
        {
            pchild->Decrement();
            prcc->AddToList(pchild);
        }
    };
    struct ScanInUseFunctor
    {
        SF_FORCEINLINE static void Call(Collector* prcc, RefCountBaseGC* pchild)
        {
            pchild->Increment();
            if (!pchild->IsInState(State_InUse))
            {
                pchild->SetState(State_InUse);
                prcc->ReinsertToList(pchild);
            }
        }
    };

    template<class ClassImpl>
    void CallForEachChild(Collector* prcc, OperationGC op) const
    {
        switch (op)
        {
        case Operation_Release:
            static_cast<const ClassImpl*>(this)->template ForEachChild_GC<ReleaseFunctor>(prcc);
            break;
        case Operation_MarkInCycle:
            static_cast<const ClassImpl*>(this)->template ForEachChild_GC<MarkInCycleFunctor>(prcc);
            break;
        case Operation_ScanInUse:
            static_cast<const ClassImpl*>(this)->template ForEachChild_GC<ScanInUseFunctor>(prcc);
            break;
        default:;
        }
    }

public:
    RefCountBaseGC(Collector* prcc) : pRCC(prcc), RefCount(1) {}

    // Count + 1 and back to the in-use state.
    void AddRef()
    {
        RefCount = (RefCount + 1) & ~(Mask_State << Shift_State);
    }
    void Release()
    {
        if (IsRefCntZero())
            return;
        Decrement();
        ReleaseInternal();
    }

    Collector* GetCollector() { return pRCC; }

protected:
    virtual ~RefCountBaseGC() {}

private:
    RefCountBaseGC(const RefCountBaseGC&) {}
    RefCountBaseGC& operator=(const RefCountBaseGC&) { return *this; }
};

typedef RefCountBaseGC<StatMV_ActionScript_Mem> ASRefCountBaseType;

class ASRefCountCollector;

template<class T>
class ASRefCountBase : public ASRefCountBaseType
{
public:
    ASRefCountBase(ASRefCountCollector* pcc) : ASRefCountBaseType((Collector*)pcc) {}

private:
    ASRefCountBase(const ASRefCountBase&) : ASRefCountBaseType(0) {}
};

// String factory of a movie: the global context plus the SWF version (case sensitivity from SWF 7 on). 0x10 bytes.
class ASStringContext
{
public:
    ASStringContext(GlobalContext* pcontext = 0, unsigned version = 0)
    {
        pContext   = pcontext;
        SWFVersion = (UByte)version;
    }

    GlobalContext* pContext;   // +0x00
    UByte          SWFVersion; // +0x08

    void     UpdateVersion(unsigned version) { SWFVersion = (UByte)version; }
    unsigned GetVersion() const              { return (unsigned)SWFVersion; }
    bool     IsCaseSensitive() const         { return SWFVersion > 6; }

    inline MemoryHeap*       GetHeap() const;
    inline StringManager*    GetStringManager() const;
    inline const ASString&   GetBuiltin(int btype) const;
    inline ASString          CreateConstString(const char* pstr) const;
    inline ASString          CreateString(const char* pstr) const;
    inline ASString          CreateString(const wchar_t* pwstr) const;
    inline ASString          CreateString(const char* pstr, UPInt length) const;
    inline ASString          CreateString(const String& str) const;
    inline ASRefCountCollector* GetGC();
    inline MovieImpl*        GetMovieImpl();
};

}}} // namespace Scaleform::GFx::AS2

#endif
