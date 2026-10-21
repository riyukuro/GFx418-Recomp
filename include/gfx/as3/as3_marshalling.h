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
#include "GFx/GFx_ASUtils.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// Default value of a result or an omitted argument.
template <typename T> struct ThunkDefault { static T Get(VM&) { return T(); } };
template <> struct ThunkDefault<Value::Number> { static Value::Number Get(VM&) { return NumberUtil::NaN(); } };
template <> struct ThunkDefault<ASString>
{
    static ASString Get(VM& vm) { return vm.GetStringManager().CreateEmptyString(); }
};

// Argument conversion from an AS3 value.
inline void ThunkReadArg(Value::Number& to, const Value& v) { v.Convert2Number(to); }
inline void ThunkReadArg(SInt32& to, const Value& v) { v.Convert2Int32(to); }
inline void ThunkReadArg(UInt32& to, const Value& v) { v.Convert2UInt32(to); }

// Storing a result.
inline void ThunkStoreResult(Value& to, Value::Number v) { to.AssignUnsafe(v); }
inline void ThunkStoreResult(Value& to, SInt32 v) { to.AssignUnsafe(v); }
inline void ThunkStoreResult(Value& to, UInt32 v) { to.AssignUnsafe(v); }
inline void ThunkStoreResult(Value& to, bool v) { to.AssignUnsafe(v); }
inline void ThunkStoreResult(Value& to, const ASString& v) { to.AssignUnsafe(v); }
template <typename T> inline void ThunkStoreResult(Value& to, const SPtr<T>& v) { to.AssignUnsafe(SPtr<T>(v)); }

// The unboxed result and arguments of one thunk call. The result starts at its default, the arguments at the given
// defaults and are converted from argv while no exception is pending; the destructor stores the result unless the
// call raised an exception. A "const Value" result is a setter's: the method gets the result value itself and
// nothing is stored.
template <typename R>
struct ThunkArgs0
{
    ThunkArgs0(VM& vm, Value& result) : vm(vm), result(result), r(ThunkDefault<R>::Get(this->vm)) {}
    ~ThunkArgs0() { if (!vm.IsException()) ThunkStoreResult(result, r); }

    VM&     vm;
    Value&  result;
    R       r;
};

template <>
struct ThunkArgs0<const Value>
{
    ThunkArgs0(VM& vm, Value& result) : vm(vm), r(result) {}

    VM&             vm;
    const Value&    r;
};

template <typename R, typename A0>
struct ThunkArgs1 : public ThunkArgs0<R>
{
    ThunkArgs1(VM& vm, Value& result, unsigned argc, const Value* argv, const A0& d0)
        : ThunkArgs0<R>(vm, result), a0(d0)
    {
        if (argc > 0)
            ThunkReadArg(a0, argv[0]);
    }

    A0      a0;
};

template <typename R, typename A0, typename A1>
struct ThunkArgs2 : public ThunkArgs1<R, A0>
{
    ThunkArgs2(VM& vm, Value& result, unsigned argc, const Value* argv, const A0& d0, const A1& d1)
        : ThunkArgs1<R, A0>(vm, result, argc, argv, d0), a1(d1)
    {
        if (!vm.IsException() && argc > 1)
            ThunkReadArg(a1, argv[1]);
    }

    A1      a1;
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
    ThunkArgs1<R, A0> args(vm, result, argc, argv, ThunkDefault<A0>::Get(vm));
    if (!vm.IsException())
        (self.*Method)(args.r, args.a0);
}

template <typename T, size_t N, typename R, typename A0, typename A1>
void ThunkFunc2<T, N, R, A0, A1>::Func(const ThunkInfo&, VM& vm, const Value& obj, Value& result, unsigned argc,
                                       const Value* argv)
{
    T& self = static_cast<T&>(*obj.GetObject());
    ThunkArgs2<R, A0, A1> args(vm, result, argc, argv, ThunkDefault<A0>::Get(vm), ThunkDefault<A1>::Get(vm));
    if (!vm.IsException())
        (self.*Method)(args.r, args.a0, args.a1);
}

}}} // namespace Scaleform::GFx::AS3

#endif
