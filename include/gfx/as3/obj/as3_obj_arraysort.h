// Recovered Scaleform GFx 4.1.18 AS3 Array.sort helpers: the sort records (key, element, index) and the
// SparseArray::ForEach visitors that collect them. Our own declarations from the exe. Used by Array.sort and
// sortOn (sfr_as3_03); the collectors' vftables, sdtors and operator() bodies lie in sfr_as3_01c's range.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_OBJ_ARRAYSORT_H
#define MS2_SF_GFX_AS3_OBJ_ARRAYSORT_H

#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform {
// A sort key and the index of the element it came from (same as sfr_as3_20).
template <typename F, typename S>
struct Pair
{
    Pair(const F& f, const S& s) : First(f), Second(s) {}

    F First;
    S Second;
};
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
}}} // namespace Scaleform::GFx::AS3

#endif
