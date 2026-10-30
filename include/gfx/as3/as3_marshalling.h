// Recovered Scaleform GFx 4.1.18 AS3: the native method thunks. Our own declarations, written from the exe.
//
// Every native AS3 method is reached through a static ThunkFuncN<T, N, R, A0..>::Func (the ThunkInfo::Method of the
// ClassInfo method tables): it casts the "this" value to T, starts the result and the arguments at their defaults
// (Number: NaN), converts the passed arguments, calls the C++ method through the pointer-to-member ThunkFuncN::Method
// and stores the result unless the call raised an exception. Identical instances are folded by the linker, so one exe
// address stands for many <T, N> pairs.
//
// The exe's Method objects are 16 bytes ({function, int this-adjustment}, the multiple-inheritance representation)
// although every native class has single inheritance: the library was built with the general member-pointer
// representation, reproduced here with the pragma below (it applies to every includer).
#ifndef MS2_SF_GFX_AS3_MARSHALLING_H
#define MS2_SF_GFX_AS3_MARSHALLING_H

#pragma pointers_to_members(full_generality, multiple_inheritance)

#include "ms2/scaleform/include/gfx/as3/as3_vm.h"
#include "ms2/scaleform/include/gfx/gfx_asutils.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// The stored type of an argument passed by const reference.
template <typename T> struct ThunkClean { typedef T type; };
template <typename T> struct ThunkClean<const T&> { typedef T type; };

// Default value of a result or an omitted argument (pointers and SPtrs: NULL; Number: NaN).
template <typename T> struct ThunkDefault { SF_INLINE static T Get(StringManager&) { return T(); } };
template <> struct ThunkDefault<Value::Number> { SF_INLINE static Value::Number Get(StringManager&) { return NumberUtil::NaN(); } };
template <> struct ThunkDefault<Value> { SF_INLINE static Value Get(StringManager&) { return Value::GetUndefined(); } };
template <> struct ThunkDefault<ASString>
{
    SF_INLINE static ASString Get(StringManager& sm) { return sm.CreateEmptyString(); }
};

// Default of argument K of the native method <T, N>; a class specializes it for a method with its own defaults.
template <typename T, size_t N, int K, typename A>
struct ThunkMethodDefault
{
    SF_INLINE static typename ThunkClean<A>::type Get(StringManager& sm) { return ThunkDefault<typename ThunkClean<A>::type>::Get(sm); }
};

// Argument conversion from an AS3 value.
SF_INLINE void ThunkReadArg(Value::Number& to, const Value& v) { v.Convert2Number(to); }
SF_INLINE void ThunkReadArg(SInt32& to, const Value& v) { v.Convert2Int32(to); }
SF_INLINE void ThunkReadArg(UInt32& to, const Value& v) { v.Convert2UInt32(to); }
SF_INLINE void ThunkReadArg(bool& to, const Value& v) { to = v.Convert2Boolean(); }
SF_INLINE void ThunkReadArg(ASString& to, const Value& v)
{
    if (v.IsNull())
        to.SetNull();
    else
        v.Convert2String(to);
}
// An instance argument: the object itself (undefined: NULL).
template <typename T> SF_INLINE void ThunkReadArg(T*& to, const Value& v)
{
    if (v.IsUndefined())
        to = NULL;
    else
        to = static_cast<T*>(v.GetObject());
}

// Storing a result.
SF_INLINE void ThunkStoreResult(Value& to, Value::Number v) { to.AssignUnsafe(v); }
SF_INLINE void ThunkStoreResult(Value& to, SInt32 v) { to.AssignUnsafe(v); }
SF_INLINE void ThunkStoreResult(Value& to, UInt32 v) { to.AssignUnsafe(v); }
SF_INLINE void ThunkStoreResult(Value& to, bool v) { to.AssignUnsafe(v); }
SF_INLINE void ThunkStoreResult(Value& to, const ASString& v) { to.AssignUnsafe(v); }
template <typename T> SF_INLINE void ThunkStoreResult(Value& to, const SPtr<T>& v) { to.AssignUnsafe(SPtr<T>(v)); }

// The unboxed result and arguments of one thunk call. The result starts at its default, the arguments at the method's
// defaults (ThunkDefsN) and are converted from argv while no exception is pending; the destructor stores the result
// unless the call raised an exception. A "Value" result is the result value itself, a "const Value" result is a
// setter's (nothing is stored); "const Value&" and "Value" arguments refer to argv or to the default.
template <typename R>
struct ThunkArgs0
{
    SF_INLINE ThunkArgs0(VM& vm, Value& result) : vm(vm), result(result), r(ThunkDefault<R>::Get(this->vm.GetStringManager())) {}
    SF_INLINE ~ThunkArgs0() { if (!vm.IsException()) ThunkStoreResult(result, r); }

    VM&     vm;
    Value&  result;
    R       r;
};

template <>
struct ThunkArgs0<Value>
{
    SF_INLINE ThunkArgs0(VM& vm, Value& result) : vm(vm), r(result) {}

    VM&     vm;
    Value&  r;
};

template <>
struct ThunkArgs0<const Value>
{
    SF_INLINE ThunkArgs0(VM& vm, Value& result) : vm(vm), r(result) {}

    VM&             vm;
    const Value&    r;
};

template <typename A0>
struct ThunkDefs1
{
    SF_INLINE ThunkDefs1(A0 d0)
        : _0(d0)
    {
    }

    typename ThunkClean<A0>::type _0;
};

template <typename A0, typename A1>
struct ThunkDefs2 : public ThunkDefs1<A0>
{
    SF_INLINE ThunkDefs2(A0 d0, A1 d1)
        : ThunkDefs1<A0>(d0), _1(d1)
    {
    }

    typename ThunkClean<A1>::type _1;
};

template <typename A0, typename A1, typename A2>
struct ThunkDefs3 : public ThunkDefs2<A0, A1>
{
    SF_INLINE ThunkDefs3(A0 d0, A1 d1, A2 d2)
        : ThunkDefs2<A0, A1>(d0, d1), _2(d2)
    {
    }

    typename ThunkClean<A2>::type _2;
};

template <typename A0, typename A1, typename A2, typename A3>
struct ThunkDefs4 : public ThunkDefs3<A0, A1, A2>
{
    SF_INLINE ThunkDefs4(A0 d0, A1 d1, A2 d2, A3 d3)
        : ThunkDefs3<A0, A1, A2>(d0, d1, d2), _3(d3)
    {
    }

    typename ThunkClean<A3>::type _3;
};

template <typename A0, typename A1, typename A2, typename A3, typename A4>
struct ThunkDefs5 : public ThunkDefs4<A0, A1, A2, A3>
{
    SF_INLINE ThunkDefs5(A0 d0, A1 d1, A2 d2, A3 d3, A4 d4)
        : ThunkDefs4<A0, A1, A2, A3>(d0, d1, d2, d3), _4(d4)
    {
    }

    typename ThunkClean<A4>::type _4;
};

template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
struct ThunkDefs6 : public ThunkDefs5<A0, A1, A2, A3, A4>
{
    SF_INLINE ThunkDefs6(A0 d0, A1 d1, A2 d2, A3 d3, A4 d4, A5 d5)
        : ThunkDefs5<A0, A1, A2, A3, A4>(d0, d1, d2, d3, d4), _5(d5)
    {
    }

    typename ThunkClean<A5>::type _5;
};

// The variable argument list (argc, argv) has no defaults.
template <>
struct ThunkDefs2<unsigned, const Value*>
{
    SF_INLINE ThunkDefs2(unsigned, const Value*) {}
};

template <typename T, size_t N, typename A0>
inline ThunkDefs1<A0> ThunkMakeDefs1(StringManager& sm)
{
    return ThunkDefs1<A0>(
        ThunkMethodDefault<T, N, 0, A0>::Get(sm));
}

template <typename T, size_t N, typename A0, typename A1>
inline ThunkDefs2<A0, A1> ThunkMakeDefs2(StringManager& sm)
{
    return ThunkDefs2<A0, A1>(
        ThunkMethodDefault<T, N, 0, A0>::Get(sm),
        ThunkMethodDefault<T, N, 1, A1>::Get(sm));
}

template <typename T, size_t N, typename A0, typename A1, typename A2>
inline ThunkDefs3<A0, A1, A2> ThunkMakeDefs3(StringManager& sm)
{
    return ThunkDefs3<A0, A1, A2>(
        ThunkMethodDefault<T, N, 0, A0>::Get(sm),
        ThunkMethodDefault<T, N, 1, A1>::Get(sm),
        ThunkMethodDefault<T, N, 2, A2>::Get(sm));
}

template <typename T, size_t N, typename A0, typename A1, typename A2, typename A3>
inline ThunkDefs4<A0, A1, A2, A3> ThunkMakeDefs4(StringManager& sm)
{
    return ThunkDefs4<A0, A1, A2, A3>(
        ThunkMethodDefault<T, N, 0, A0>::Get(sm),
        ThunkMethodDefault<T, N, 1, A1>::Get(sm),
        ThunkMethodDefault<T, N, 2, A2>::Get(sm),
        ThunkMethodDefault<T, N, 3, A3>::Get(sm));
}

template <typename T, size_t N, typename A0, typename A1, typename A2, typename A3, typename A4>
inline ThunkDefs5<A0, A1, A2, A3, A4> ThunkMakeDefs5(StringManager& sm)
{
    return ThunkDefs5<A0, A1, A2, A3, A4>(
        ThunkMethodDefault<T, N, 0, A0>::Get(sm),
        ThunkMethodDefault<T, N, 1, A1>::Get(sm),
        ThunkMethodDefault<T, N, 2, A2>::Get(sm),
        ThunkMethodDefault<T, N, 3, A3>::Get(sm),
        ThunkMethodDefault<T, N, 4, A4>::Get(sm));
}

template <typename T, size_t N, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline ThunkDefs6<A0, A1, A2, A3, A4, A5> ThunkMakeDefs6(StringManager& sm)
{
    return ThunkDefs6<A0, A1, A2, A3, A4, A5>(
        ThunkMethodDefault<T, N, 0, A0>::Get(sm),
        ThunkMethodDefault<T, N, 1, A1>::Get(sm),
        ThunkMethodDefault<T, N, 2, A2>::Get(sm),
        ThunkMethodDefault<T, N, 3, A3>::Get(sm),
        ThunkMethodDefault<T, N, 4, A4>::Get(sm),
        ThunkMethodDefault<T, N, 5, A5>::Get(sm));
}

template <typename R, typename A0>
struct ThunkArgs1 : public ThunkArgs0<R>
{
    SF_INLINE ThunkArgs1(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs1<A0>& d)
        : ThunkArgs0<R>(vm, result), a0(d._0)
    {
        if (argc > 0)
            ThunkReadArg(a0, argv[0]);
    }

    typename ThunkClean<A0>::type a0;
};

template <typename R>
struct ThunkArgs1<R, const Value&> : public ThunkArgs0<R>
{
    SF_INLINE ThunkArgs1(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs1<const Value&>& d)
        : ThunkArgs0<R>(vm, result), a0(argc > 0 ? argv[0] : d._0)
    {
    }

    const Value& a0;
};

template <typename R>
struct ThunkArgs1<R, Value> : public ThunkArgs0<R>
{
    SF_INLINE ThunkArgs1(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs1<Value>& d)
        : ThunkArgs0<R>(vm, result), a0(argc > 0 ? argv[0] : d._0)
    {
    }

    const Value& a0;
};

template <typename R, typename A0, typename A1>
struct ThunkArgs2 : public ThunkArgs1<R, A0>
{
    ThunkArgs2(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs2<A0, A1>& d)
        : ThunkArgs1<R, A0>(vm, result, argc, argv, d), a1(d._1)
    {
        if (vm.IsException())
            return;
        if (argc > 1)
            ThunkReadArg(a1, argv[1]);
    }

    typename ThunkClean<A1>::type a1;
};

template <typename R, typename A0>
struct ThunkArgs2<R, A0, const Value&> : public ThunkArgs1<R, A0>
{
    ThunkArgs2(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs2<A0, const Value&>& d)
        : ThunkArgs1<R, A0>(vm, result, argc, argv, d), a1(argc > 1 ? argv[1] : d._1)
    {
    }

    const Value& a1;
};

template <typename R, typename A0>
struct ThunkArgs2<R, A0, Value> : public ThunkArgs1<R, A0>
{
    ThunkArgs2(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs2<A0, Value>& d)
        : ThunkArgs1<R, A0>(vm, result, argc, argv, d), a1(argc > 1 ? argv[1] : d._1)
    {
    }

    const Value& a1;
};

template <typename R, typename A0, typename A1, typename A2>
struct ThunkArgs3 : public ThunkArgs2<R, A0, A1>
{
    ThunkArgs3(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs3<A0, A1, A2>& d)
        : ThunkArgs2<R, A0, A1>(vm, result, argc, argv, d), a2(d._2)
    {
        if (vm.IsException())
            return;
        if (argc > 2)
            ThunkReadArg(a2, argv[2]);
    }

    typename ThunkClean<A2>::type a2;
};

template <typename R, typename A0, typename A1>
struct ThunkArgs3<R, A0, A1, const Value&> : public ThunkArgs2<R, A0, A1>
{
    ThunkArgs3(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs3<A0, A1, const Value&>& d)
        : ThunkArgs2<R, A0, A1>(vm, result, argc, argv, d), a2(argc > 2 ? argv[2] : d._2)
    {
    }

    const Value& a2;
};

template <typename R, typename A0, typename A1>
struct ThunkArgs3<R, A0, A1, Value> : public ThunkArgs2<R, A0, A1>
{
    ThunkArgs3(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs3<A0, A1, Value>& d)
        : ThunkArgs2<R, A0, A1>(vm, result, argc, argv, d), a2(argc > 2 ? argv[2] : d._2)
    {
    }

    const Value& a2;
};

template <typename R, typename A0, typename A1, typename A2, typename A3>
struct ThunkArgs4 : public ThunkArgs3<R, A0, A1, A2>
{
    ThunkArgs4(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs4<A0, A1, A2, A3>& d)
        : ThunkArgs3<R, A0, A1, A2>(vm, result, argc, argv, d), a3(d._3)
    {
        if (vm.IsException())
            return;
        if (argc > 3)
            ThunkReadArg(a3, argv[3]);
    }

    typename ThunkClean<A3>::type a3;
};

template <typename R, typename A0, typename A1, typename A2>
struct ThunkArgs4<R, A0, A1, A2, const Value&> : public ThunkArgs3<R, A0, A1, A2>
{
    ThunkArgs4(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs4<A0, A1, A2, const Value&>& d)
        : ThunkArgs3<R, A0, A1, A2>(vm, result, argc, argv, d), a3(argc > 3 ? argv[3] : d._3)
    {
    }

    const Value& a3;
};

template <typename R, typename A0, typename A1, typename A2>
struct ThunkArgs4<R, A0, A1, A2, Value> : public ThunkArgs3<R, A0, A1, A2>
{
    ThunkArgs4(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs4<A0, A1, A2, Value>& d)
        : ThunkArgs3<R, A0, A1, A2>(vm, result, argc, argv, d), a3(argc > 3 ? argv[3] : d._3)
    {
    }

    const Value& a3;
};

template <typename R, typename A0, typename A1, typename A2, typename A3, typename A4>
struct ThunkArgs5 : public ThunkArgs4<R, A0, A1, A2, A3>
{
    ThunkArgs5(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs5<A0, A1, A2, A3, A4>& d)
        : ThunkArgs4<R, A0, A1, A2, A3>(vm, result, argc, argv, d), a4(d._4)
    {
        if (vm.IsException())
            return;
        if (argc > 4)
            ThunkReadArg(a4, argv[4]);
    }

    typename ThunkClean<A4>::type a4;
};

template <typename R, typename A0, typename A1, typename A2, typename A3>
struct ThunkArgs5<R, A0, A1, A2, A3, const Value&> : public ThunkArgs4<R, A0, A1, A2, A3>
{
    ThunkArgs5(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs5<A0, A1, A2, A3, const Value&>& d)
        : ThunkArgs4<R, A0, A1, A2, A3>(vm, result, argc, argv, d), a4(argc > 4 ? argv[4] : d._4)
    {
    }

    const Value& a4;
};

template <typename R, typename A0, typename A1, typename A2, typename A3>
struct ThunkArgs5<R, A0, A1, A2, A3, Value> : public ThunkArgs4<R, A0, A1, A2, A3>
{
    ThunkArgs5(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs5<A0, A1, A2, A3, Value>& d)
        : ThunkArgs4<R, A0, A1, A2, A3>(vm, result, argc, argv, d), a4(argc > 4 ? argv[4] : d._4)
    {
    }

    const Value& a4;
};

template <typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
struct ThunkArgs6 : public ThunkArgs5<R, A0, A1, A2, A3, A4>
{
    ThunkArgs6(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs6<A0, A1, A2, A3, A4, A5>& d)
        : ThunkArgs5<R, A0, A1, A2, A3, A4>(vm, result, argc, argv, d), a5(d._5)
    {
        if (vm.IsException())
            return;
        if (argc > 5)
            ThunkReadArg(a5, argv[5]);
    }

    typename ThunkClean<A5>::type a5;
};

template <typename R, typename A0, typename A1, typename A2, typename A3, typename A4>
struct ThunkArgs6<R, A0, A1, A2, A3, A4, const Value&> : public ThunkArgs5<R, A0, A1, A2, A3, A4>
{
    ThunkArgs6(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs6<A0, A1, A2, A3, A4, const Value&>& d)
        : ThunkArgs5<R, A0, A1, A2, A3, A4>(vm, result, argc, argv, d), a5(argc > 5 ? argv[5] : d._5)
    {
    }

    const Value& a5;
};

template <typename R, typename A0, typename A1, typename A2, typename A3, typename A4>
struct ThunkArgs6<R, A0, A1, A2, A3, A4, Value> : public ThunkArgs5<R, A0, A1, A2, A3, A4>
{
    ThunkArgs6(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs6<A0, A1, A2, A3, A4, Value>& d)
        : ThunkArgs5<R, A0, A1, A2, A3, A4>(vm, result, argc, argv, d), a5(argc > 5 ? argv[5] : d._5)
    {
    }

    const Value& a5;
};

template <typename R>
struct ThunkArgs2<R, unsigned, const Value*> : public ThunkArgs0<R>
{
    ThunkArgs2(VM& vm, Value& result, unsigned argc, const Value* argv, const ThunkDefs2<unsigned, const Value*>&)
        : ThunkArgs0<R>(vm, result), a0(argc), a1(argv)
    {
    }

    unsigned        a0;
    const Value*    a1;
};

template <typename T, size_t N, typename R>
struct ThunkFunc0
{
    typedef void (T::*TMethod)(R&);
    static void Func(const ThunkInfo& ti, VM& vm, const Value& obj, Value& result, unsigned argc, const Value* argv);
    static const TMethod Method;
};

template <typename T, size_t N, typename R, typename A0>
struct ThunkFunc1
{
    typedef void (T::*TMethod)(R&, A0);
    static void Func(const ThunkInfo& ti, VM& vm, const Value& obj, Value& result, unsigned argc, const Value* argv);
    static const TMethod Method;
};

template <typename T, size_t N, typename R, typename A0, typename A1>
struct ThunkFunc2
{
    typedef void (T::*TMethod)(R&, A0, A1);
    static void Func(const ThunkInfo& ti, VM& vm, const Value& obj, Value& result, unsigned argc, const Value* argv);
    static const TMethod Method;
};

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2>
struct ThunkFunc3
{
    typedef void (T::*TMethod)(R&, A0, A1, A2);
    static void Func(const ThunkInfo& ti, VM& vm, const Value& obj, Value& result, unsigned argc, const Value* argv);
    static const TMethod Method;
};

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2, typename A3>
struct ThunkFunc4
{
    typedef void (T::*TMethod)(R&, A0, A1, A2, A3);
    static void Func(const ThunkInfo& ti, VM& vm, const Value& obj, Value& result, unsigned argc, const Value* argv);
    static const TMethod Method;
};

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2, typename A3, typename A4>
struct ThunkFunc5
{
    typedef void (T::*TMethod)(R&, A0, A1, A2, A3, A4);
    static void Func(const ThunkInfo& ti, VM& vm, const Value& obj, Value& result, unsigned argc, const Value* argv);
    static const TMethod Method;
};

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
struct ThunkFunc6
{
    typedef void (T::*TMethod)(R&, A0, A1, A2, A3, A4, A5);
    static void Func(const ThunkInfo& ti, VM& vm, const Value& obj, Value& result, unsigned argc, const Value* argv);
    static const TMethod Method;
};

// Variable arguments: the method gets the result value and (argc, argv) themselves.
template <typename T, size_t N>
struct ThunkFunc2<T, N, Value, unsigned, const Value*>
{
    typedef void (T::*TMethod)(Value&, unsigned, const Value*);
    static void Func(const ThunkInfo&, VM&, const Value& obj, Value& result, unsigned argc, const Value* argv)
    {
        T& self = static_cast<T&>(*obj.GetObject());
        (self.*Method)(result, argc, argv);
    }
    static const TMethod Method;
};

template <typename T, size_t N, typename R>
void ThunkFunc0<T, N, R>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned, const Value*)
{
    T& self = static_cast<T&>(*obj.GetObject());
    ThunkArgs0<R> args(vm, result);
    (self.*Method)(args.r);
}

template <typename T, size_t N, typename R, typename A0>
void ThunkFunc1<T, N, R, A0>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned argc,
    const Value* argv)
{
    T& self = static_cast<T&>(*obj.GetObject());
    ThunkArgs1<R, A0> args(vm, result, argc, argv, ThunkMakeDefs1<T, N, A0>(vm.GetStringManager()));
    if (vm.IsException())
        return;
    (self.*Method)(args.r, args.a0);
}

template <typename T, size_t N, typename R, typename A0, typename A1>
void ThunkFunc2<T, N, R, A0, A1>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned argc,
    const Value* argv)
{
    T& self = static_cast<T&>(*obj.GetObject());
    ThunkArgs2<R, A0, A1> args(vm, result, argc, argv, ThunkMakeDefs2<T, N, A0, A1>(vm.GetStringManager()));
    if (vm.IsException())
        return;
    (self.*Method)(args.r, args.a0, args.a1);
}

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2>
void ThunkFunc3<T, N, R, A0, A1, A2>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned argc,
    const Value* argv)
{
    T& self = static_cast<T&>(*obj.GetObject());
    const ThunkDefs3<A0, A1, A2> defs = ThunkMakeDefs3<T, N, A0, A1, A2>(vm.GetStringManager());
    ThunkArgs3<R, A0, A1, A2> args(vm, result, argc, argv, defs);
    if (vm.IsException())
        return;
    (self.*Method)(args.r, args.a0, args.a1, args.a2);
}

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2, typename A3>
void ThunkFunc4<T, N, R, A0, A1, A2, A3>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned argc,
    const Value* argv)
{
    T& self = static_cast<T&>(*obj.GetObject());
    const ThunkDefs4<A0, A1, A2, A3> defs = ThunkMakeDefs4<T, N, A0, A1, A2, A3>(vm.GetStringManager());
    ThunkArgs4<R, A0, A1, A2, A3> args(vm, result, argc, argv, defs);
    if (vm.IsException())
        return;
    (self.*Method)(args.r, args.a0, args.a1, args.a2, args.a3);
}

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2, typename A3, typename A4>
void ThunkFunc5<T, N, R, A0, A1, A2, A3, A4>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned argc,
    const Value* argv)
{
    T& self = static_cast<T&>(*obj.GetObject());
    const ThunkDefs5<A0, A1, A2, A3, A4> defs = ThunkMakeDefs5<T, N, A0, A1, A2, A3, A4>(vm.GetStringManager());
    ThunkArgs5<R, A0, A1, A2, A3, A4> args(vm, result, argc, argv, defs);
    if (vm.IsException())
        return;
    (self.*Method)(args.r, args.a0, args.a1, args.a2, args.a3, args.a4);
}

template <typename T, size_t N, typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
void ThunkFunc6<T, N, R, A0, A1, A2, A3, A4, A5>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned argc,
    const Value* argv)
{
    T& self = static_cast<T&>(*obj.GetObject());
    const ThunkDefs6<A0, A1, A2, A3, A4, A5> defs = ThunkMakeDefs6<T, N, A0, A1, A2, A3, A4, A5>(vm.GetStringManager());
    ThunkArgs6<R, A0, A1, A2, A3, A4, A5> args(vm, result, argc, argv, defs);
    if (vm.IsException())
        return;
    (self.*Method)(args.r, args.a0, args.a1, args.a2, args.a3, args.a4, args.a5);
}

}}} // namespace Scaleform::GFx::AS3

#endif
