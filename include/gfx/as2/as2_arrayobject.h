// Recovered Scaleform 4.1.18 GFx AS2: the Array object (elements kept natively as heap Values; a null
// element is an unset hole).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_ARRAYOBJECT_H
#define MS2_SF_GFX_AS2_ARRAYOBJECT_H

#include "as2_action.h"

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

    int          GetSize() const { return (unsigned)Elements.GetSize(); }
    Value*       GetElementPtr(int i) { return Elements[i]; }
    const Value* GetElementPtr(int i) const { return Elements[i]; }

    void Resize(int newSize);                     // exe 0x14297e330
    void SetElement(int i, const Value& val);     // exe 0x1429814c0
    void PushBack(const Value& val);              // exe 0x142971ba0
    void PushBack();                              // exe 0x142971c50 (an empty hole)
    void PopFront_Call();                         // exe 0x14296f1b0, the out-of-line copy of PopFront
    void RemoveElements(int start, int count);    // exe 0x14297d0d0
    void InsertEmpty(int start, int count);       // exe 0x142962010
    void JoinToString(Environment* penv, StringBuffer* pbuffer, const char* pdelimiter) const; // exe 0x142966270
    void Concat(Environment* penv, const Value& val);                                         // exe 0x142935680

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

    // toString of an array nested in itself stops here (out of line at exe 0x142973040).
    bool RecursionLimitReached() const
    {
        if (RecursionCount >= 255)
        {
            LogPtr->LogMessageById(LogChannel_Script | LogMessage_Error, "256 levels of recursion is reached\n");
            return true;
        }
        return false;
    }

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

}}} // namespace Scaleform::GFx::AS2

#endif
