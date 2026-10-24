// Recovered Scaleform 4.1.18 GFx AS2: the Array object (elements kept natively as heap Values; a null
// element is an unset hole).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_ARRAYOBJECT_H
#define MS2_SF_GFX_AS2_ARRAYOBJECT_H

#include "as2_action.h"
#include "as2_objectproto.h"

namespace Scaleform { namespace GFx { namespace AS2 {

typedef ArrayLH<Value*, StatMV_ActionScript_Mem> ArrayObjectElements;

// The out-of-line Resize of the element array (exe 0x14297e2b0, a COMDAT the exe calls where cl inlines it).
void ArrayObjectElements_Resize(ArrayObjectElements* pelements, UPInt newSize);

template<class T>
inline void ArrayObject_Swap(T& a, T& b)
{
    T temp(a);
    a = b;
    b = temp;
}

// Array instance. 0x98 bytes.
class ArrayObject : public Object
{
public:
    enum SortFlags
    {
        SortFlags_CaseInsensitive    = 1,
        SortFlags_Descending         = 2,
        SortFlags_UniqueSort         = 4,
        SortFlags_ReturnIndexedArray = 8,
        SortFlags_Numeric            = 16,
        SortFlags_Locale             = 1024
    };

    ArrayObject(Environment* penv); // exe 0x142918010
    ArrayObject(ASStringContext* psc); // exe 0x142917f70
    virtual ~ArrayObject(); // exe 0x1429252e0

    // Object_Array (exe 0x142954130).
    virtual ObjectType GetObjectType() const;
    // An index name clears the element (exe 0x1429385f0).
    virtual bool DeleteMember(ASStringContext* psc, const ASString& name);

    // Elements by index name, "length" from the element count (exe 0x1429530b0).
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);
    // An index name is a member when the element is set, not undefined or null (exe 0x14295d700).
    virtual bool HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes);
    // "length" resizes, an index name sets the element (exe 0x142982ba0).
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
    // The members, then the elements by index name (exe 0x1429944d0).
    virtual void VisitMembers(ASStringContext* psc, MemberVisitor* pvisitor, unsigned visitFlags = 0,
                              const ObjectInterface* instance = 0) const;

    // The index a member name spells (only digits), -1 for any other name.
    static int ParseIndex(const ASString& name)
    {
        const char* p = name.ToCStr();
        while (*p && *p >= '0' && *p <= '9')
            p++;
        if (*p)
            return -1;
        return atoi(name.ToCStr());
    }

    int          GetSize() const { return (unsigned)Elements.GetSize(); }
    Value*       GetElementPtr(int i) { return Elements[i]; }
    const Value* GetElementPtr(int i) const { return Elements[i]; }

    void Resize(int newSize);                     // exe 0x14297e330
    void SetElement(int i, const Value& val);     // exe 0x1429814c0
    void SetElementSafe(int i, const Value& val); // exe 0x142981560 (grows the array to i + 1)
    // The element pointers of ao, shared with it (exe 0x14298ee10).
    void ShallowCopyFrom(const ArrayObject& ao);
    void PushBack(const Value& val);              // exe 0x142971ba0
    void PushBack();                              // exe 0x142971c50 (an empty hole)
    void PopFront_Call();                         // exe 0x14296f1b0, the out-of-line copy of PopFront
    void RemoveElements(int start, int count);    // exe 0x14297d0d0
    void InsertEmpty(int start, int count);       // exe 0x142962010
    void JoinToString(Environment* penv, StringBuffer* pbuffer, const char* pdelimiter) const; // exe 0x142966270
    // The elements joined with "," (exe 0x1429565d0).
    virtual const char* GetTextValue(Environment* penv = 0) const;
    void Concat(Environment* penv, const Value& val);                                         // exe 0x142935680
    // The elements copied to new heap values (exe 0x1429684d0); from another array (exe 0x142968560).
    void MakeDeepCopy(MemoryHeap* pheap);
    void MakeDeepCopyFrom(MemoryHeap* pheap, const ArrayObject& ao);

    void PopBack()
    {
        if (Elements.GetSize())
            Resize((int)(Elements.GetSize() - 1));
    }
    void PopFront()
    {
        if (Elements.GetSize())
        {
            if (Value* pfirst = Elements[0])
            {
                pfirst->~Value();
                Memory::Free(pfirst);
            }
            for (unsigned i = 1; i < Elements.GetSize(); i++)
                Elements[i - 1] = Elements[i];
            Elements[Elements.GetSize() - 1] = 0;
            ArrayObjectElements_Resize(&Elements, Elements.GetSize() - 1);
        }
    }
    void Reverse()
    {
        int i = 0;
        int j = (int)Elements.GetSize() - 1;
        while (i < j)
        {
            ArrayObject_Swap(Elements[i], Elements[j]);
            ++i;
            --j;
        }
    }

    // toString of an array nested in itself stops here.
    bool RecursionLimitReached() const
    {
        if (RecursionCount >= 255)
        {
            LogPtr->LogMessageById(LogChannel_Script | LogMessage_Error, "256 levels of recursion is reached\n");
            return true;
        }
        return false;
    }
    bool RecursionLimitReached_Call() const; // exe 0x142973040, the out-of-line copy of RecursionLimitReached

    static void ArrayLength(const FnCall& fn);
    static void ArrayConcat(const FnCall& fn);
    static void ArrayJoin(const FnCall& fn);
    static void ArrayPop(const FnCall& fn);
    static void ArrayPush(const FnCall& fn);
    static void ArrayReverse(const FnCall& fn);
    static void ArrayShift(const FnCall& fn);
    static void ArraySlice(const FnCall& fn);
    static void ArraySort(const FnCall& fn);
    static void ArraySortOn(const FnCall& fn);
    static void ArraySplice(const FnCall& fn);
    static void ArrayToString(const FnCall& fn);
    static void ArrayUnshift(const FnCall& fn);
    static void ArrayValueOf(const FnCall& fn);

    Log* const                                  LogPtr;               // +0x68
    ArrayObjectElements                         Elements;             // +0x70
    mutable StringLH                            StringValue;          // +0x88
    mutable int                                 RecursionCount;       // +0x90
    bool                                        LengthValueOverriden; // +0x94

protected:
    // The object and every element (defined in sfr_as2_02).
    template<class Functor> void ForEachChild_GC(Collector* prcc) const;

    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const; // exe 0x142941160
    virtual void Finalize_GC(); // exe 0x142942b40

    // An array with the given __proto__ (exe 0x142917ed0).
    ArrayObject(ASStringContext* psc, Object* pprototype);

    friend class ArrayCtorFunction;
    // The elements from the arguments of a constructor call (exe 0x142961720).
    void InitArray(const FnCall& fn);
};

// Counts one level of nested toString for the guarded array while alive.
class RecursionGuard
{
public:
    RecursionGuard(const ArrayObject* pthis) : ThisPtr(pthis) { ThisPtr->RecursionCount++; }
    ~RecursionGuard() { ThisPtr->RecursionCount--; }

private:
    const ArrayObject* ThisPtr;
};

// Order of Array.sort: a script compare function or the sort flags. 0x38 bytes.
class ArraySortFunctor
{
public:
    ArraySortFunctor() {}
    ArraySortFunctor(ObjectInterface* pthis, int flags, const FunctionRef& func, Environment* penv,
                     const Log* plog = 0)
        : This(pthis), Flags(flags), Func(func), Env(penv), LogPtr(plog)
    {
    }
    ArraySortFunctor(const ArraySortFunctor& src); // exe 0x1429181f0
    ~ArraySortFunctor();                           // exe 0x142925350

    // Negative when a sorts before b (exe 0x142934a80).
    int  Compare(const Value* a, const Value* b) const;
    bool operator()(const Value* a, const Value* b) const { return Compare(a, b) < 0; }

private:
    ObjectInterface* This;   // +0x00
    int              Flags;  // +0x08
    FunctionRef      Func;   // +0x10
    Environment*     Env;    // +0x28
    const Log*       LogPtr; // +0x30
};

// Order of Array.sortOn: one ArraySortFunctor per field name, compared in turn. 0x38 bytes.
class ArraySortOnFunctor
{
public:
    ArraySortOnFunctor(ObjectInterface* pthis, const ArrayCC<ASString>* fields, Environment* penv, const Log* plog)
        : This(pthis), FieldArray(fields), Env(penv), LogPtr(plog)
    {
    }
    // The per-field functors the caller fills in.
    Array<ArraySortFunctor>& GetFunctorArray() { return FunctorArray; }
    ArraySortOnFunctor(const ArraySortOnFunctor& src); // exe 0x142918270
    ArraySortOnFunctor(ObjectInterface* pthis, const ArrayCC<ASString>* fields, const Array<int>& flags,
                       Environment* penv, const Log* plog); // exe 0x142918330

    // Negative when a sorts before b (exe 0x142934f90).
    int  Compare(const Value* a, const Value* b) const;
    bool operator()(const Value* a, const Value* b) const { return Compare(a, b) < 0; }

private:
    ObjectInterface*                                    This;         // +0x00
    const ArrayCC<ASString>*                            FieldArray;   // +0x08 the field names
    Environment*                                        Env;          // +0x10
    const Log*                                          LogPtr;       // +0x18
    Array<ArraySortFunctor>                             FunctorArray; // +0x20
};

// Array.prototype.
class ArrayProto : public Prototype<ArrayObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213250

    ArrayProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x1429180c0
};

// The Array class.
class ArrayCtorFunction : public CFunctionObject
{
public:
    // (appended for sfr_as2_06) The sort flag constants (CASEINSENSITIVE, ...) as members (exe 0x142917d80).
    ArrayCtorFunction(ASStringContext* psc);
    static const NameNumber SortFlagTable[]; // exe 0x1432131e0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429367a0

    // new Array(n) / Array(n) has n holes, any other arguments are the elements; a new array when called as
    // a function (exe 0x1429584b0).
    static void GlobalCtor(const FnCall& fn);

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Array" (exe 0x142973500).
    static FunctionRef Register(GlobalContext* pgc);
};

}}} // namespace Scaleform::GFx::AS2

#endif
