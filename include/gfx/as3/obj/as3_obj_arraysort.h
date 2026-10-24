// Recovered Scaleform GFx 4.1.18 AS3 Array.sort helpers: the sort records (key, element, index) and the
// SparseArray::ForEach visitors that collect them. Our own declarations from the exe. Used by Array.sort and
// sortOn (sfr_as3_03); the collectors' vftables, sdtors and operator() bodies lie in sfr_as3_01c's range.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_OBJ_ARRAYSORT_H
#define MS2_SF_GFX_AS3_OBJ_ARRAYSORT_H

#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"     // (sfr24) the collectors' VM calls

namespace Scaleform {
// A sort key and the index of the element it came from (same as sfr_as3_20).
template <typename F, typename S>
struct Pair
{
    Pair(const F& f, const S& s) : First(f), Second(s) {}

    F First;
    S Second;
};

// The sorts swap a pair member by member (the exe's Alg::Swap overload for pairs; declared here, after the sort
// templates, it is found by argument-dependent lookup and wins over the generic Alg::Swap).
template <typename F, typename S>
inline void Swap(Pair<F, S>& l, Pair<F, S>& r)
{
    Alg::Swap(l.First, r.First);
    Alg::Swap(l.Second, r.Second);
}
}

namespace Scaleform { namespace GFx { namespace AS3
{
    // A sort key, the element and its index.
    template <typename T1, typename T2, typename T3>
    struct Triple : public Pair<T1, T2>
    {
        Triple(const T1& f, const T2& s, const T3& t) : Pair<T1, T2>(f, s), Third(t) {}

        T3 Third;
    };

    typedef Triple<ASString, const Value*, UInt32>      StringValueTriple;
    typedef Triple<Value::Number, const Value*, UInt32> NumberValueTriple;
    typedef Pair<const Value*, UInt32>                  ValuePtrPair;

    // SparseArray::ForEach visitors. vftables 0x143141580/0x143141590/0x1431415a0,
    // operator() 0x1423f1ec0/0x1423f1d70/0x1423f1cb0.
    class ValuePtrCollector : public ArrayFunc
    {
    public:
        ValuePtrCollector(ArrayDH<ValuePtrPair>& p) : Pairs(p) {}

        virtual void operator()(UInt32 ind, const Value& v) { Pairs.PushBack(ValuePtrPair(&v, ind)); }

    private:
        ValuePtrCollector& operator=(const ValuePtrCollector&);

        ArrayDH<ValuePtrPair>& Pairs;
    };

    class Value2StrCollector : public ArrayFunc
    {
    public:
        Value2StrCollector(VM& vm, ArrayDH<StringValueTriple>& p) : Vm(vm), Pairs(p) {}

        virtual void operator()(UInt32 ind, const Value& v)
        {
            ASString str = Vm.GetStringManager().CreateEmptyString();
            if (!v.Convert2String(str))
                return;
            Pairs.PushBack(StringValueTriple(str, &v, ind));
        }

    private:
        Value2StrCollector& operator=(const Value2StrCollector&);

        VM&                         Vm;
        ArrayDH<StringValueTriple>& Pairs;
    };

    class Value2NumberCollector : public ArrayFunc
    {
    public:
        Value2NumberCollector(ArrayDH<NumberValueTriple>& p) : Pairs(p) {}

        virtual void operator()(UInt32 ind, const Value& v)
        {
            Value::Number num;
            if (!v.Convert2Number(num))
                return;
            Pairs.PushBack(NumberValueTriple(num, &v, ind));
        }

    private:
        Value2NumberCollector& operator=(const Value2NumberCollector&);

        ArrayDH<NumberValueTriple>& Pairs;
    };

    // (appended, sfr22) the Array.sort/sortOn orderings of element pointers; Compare in sfr_as3_03, the sort
    // instantiations in sfr_as3_01c.
    // ordering by a script compare function. 0x10 bytes: the VM and the function (no descending flag in 4.1).
    class CompareValuePtr
    {
    public:
        CompareValuePtr(VM& vm, const Value& f) : Vm(vm), Func(f) {}

        bool operator()(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) < 0; }
        bool Equal(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) == 0; }

        int Compare(const Value& a, const Value& b) const;

    private:
        CompareValuePtr& operator=(const CompareValuePtr&);

        VM&          Vm;
        const Value& Func;
    };

    // sortOn: the field names and their option bits. 0x18 bytes, passed by value.
    class CompareOn
    {
    public:
        CompareOn(VM& vm, const ArrayDH<Value>& names, const ArrayDH<UInt32>& flags)
            : Vm(vm), Names(names), Flags(flags) {}

        bool operator()(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) < 0; }
        bool Equal(const ValuePtrPair& a, const ValuePtrPair& b) const { return Compare(*a.First, *b.First) == 0; }

        int Compare(const Value& a, const Value& b) const;

    private:
        CompareOn& operator=(const CompareOn&);

        VM&                     Vm;
        const ArrayDH<Value>&   Names;
        const ArrayDH<UInt32>&  Flags;
    };
}}} // namespace Scaleform::GFx::AS3

#endif
