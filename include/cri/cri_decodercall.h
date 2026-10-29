// criDecoderCall / criDecoderCallVoid for sfr_cri_03: call slot `offset` of a CRI decoder interface wrapper
// ({object, vtable}) with the object as the first argument, or return `fallback` when the wrapper, its table or the
// slot is null. A fixed-arity overload set (0-5 forwarded arguments) instead of a variadic template: the unit also
// builds with VC9 (`// MS2-TOOLSET: vc9`), which is C++03.
#ifndef MS2_CRI_DECODERCALL_H
#define MS2_CRI_DECODERCALL_H
#include "cri_movie.h"

template <typename Result>
static inline Result criDecoderCall(void* wrapper, size_t offset, Result fallback)
{
    if (!wrapper)
        return fallback;
    void** object = (void**)wrapper;
    if (!object[1])
        return fallback;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (!target)
        return fallback;
    typedef Result (*Callback)(void*);
    return ((Callback)target)(object[0]);
}

static inline void criDecoderCallVoid(void* wrapper, size_t offset)
{
    if (!wrapper)
        return;
    void** object = (void**)wrapper;
    if (!object[1])
        return;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (target)
    {
        typedef void (*Callback)(void*);
        ((Callback)target)(object[0]);
    }
}

template <typename Result, typename A0>
static inline Result criDecoderCall(void* wrapper, size_t offset, Result fallback, A0 a0)
{
    if (!wrapper)
        return fallback;
    void** object = (void**)wrapper;
    if (!object[1])
        return fallback;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (!target)
        return fallback;
    typedef Result (*Callback)(void*, A0);
    return ((Callback)target)(object[0], a0);
}

template <typename A0>
static inline void criDecoderCallVoid(void* wrapper, size_t offset, A0 a0)
{
    if (!wrapper)
        return;
    void** object = (void**)wrapper;
    if (!object[1])
        return;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (target)
    {
        typedef void (*Callback)(void*, A0);
        ((Callback)target)(object[0], a0);
    }
}

template <typename Result, typename A0, typename A1>
static inline Result criDecoderCall(void* wrapper, size_t offset, Result fallback, A0 a0, A1 a1)
{
    if (!wrapper)
        return fallback;
    void** object = (void**)wrapper;
    if (!object[1])
        return fallback;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (!target)
        return fallback;
    typedef Result (*Callback)(void*, A0, A1);
    return ((Callback)target)(object[0], a0, a1);
}

template <typename A0, typename A1>
static inline void criDecoderCallVoid(void* wrapper, size_t offset, A0 a0, A1 a1)
{
    if (!wrapper)
        return;
    void** object = (void**)wrapper;
    if (!object[1])
        return;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (target)
    {
        typedef void (*Callback)(void*, A0, A1);
        ((Callback)target)(object[0], a0, a1);
    }
}

template <typename Result, typename A0, typename A1, typename A2>
static inline Result criDecoderCall(void* wrapper, size_t offset, Result fallback, A0 a0, A1 a1, A2 a2)
{
    if (!wrapper)
        return fallback;
    void** object = (void**)wrapper;
    if (!object[1])
        return fallback;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (!target)
        return fallback;
    typedef Result (*Callback)(void*, A0, A1, A2);
    return ((Callback)target)(object[0], a0, a1, a2);
}

template <typename A0, typename A1, typename A2>
static inline void criDecoderCallVoid(void* wrapper, size_t offset, A0 a0, A1 a1, A2 a2)
{
    if (!wrapper)
        return;
    void** object = (void**)wrapper;
    if (!object[1])
        return;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (target)
    {
        typedef void (*Callback)(void*, A0, A1, A2);
        ((Callback)target)(object[0], a0, a1, a2);
    }
}

template <typename Result, typename A0, typename A1, typename A2, typename A3>
static inline Result criDecoderCall(void* wrapper, size_t offset, Result fallback, A0 a0, A1 a1, A2 a2, A3 a3)
{
    if (!wrapper)
        return fallback;
    void** object = (void**)wrapper;
    if (!object[1])
        return fallback;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (!target)
        return fallback;
    typedef Result (*Callback)(void*, A0, A1, A2, A3);
    return ((Callback)target)(object[0], a0, a1, a2, a3);
}

template <typename A0, typename A1, typename A2, typename A3>
static inline void criDecoderCallVoid(void* wrapper, size_t offset, A0 a0, A1 a1, A2 a2, A3 a3)
{
    if (!wrapper)
        return;
    void** object = (void**)wrapper;
    if (!object[1])
        return;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (target)
    {
        typedef void (*Callback)(void*, A0, A1, A2, A3);
        ((Callback)target)(object[0], a0, a1, a2, a3);
    }
}

template <typename Result, typename A0, typename A1, typename A2, typename A3, typename A4>
static inline Result criDecoderCall(void* wrapper, size_t offset, Result fallback, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4)
{
    if (!wrapper)
        return fallback;
    void** object = (void**)wrapper;
    if (!object[1])
        return fallback;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (!target)
        return fallback;
    typedef Result (*Callback)(void*, A0, A1, A2, A3, A4);
    return ((Callback)target)(object[0], a0, a1, a2, a3, a4);
}

template <typename A0, typename A1, typename A2, typename A3, typename A4>
static inline void criDecoderCallVoid(void* wrapper, size_t offset, A0 a0, A1 a1, A2 a2, A3 a3, A4 a4)
{
    if (!wrapper)
        return;
    void** object = (void**)wrapper;
    if (!object[1])
        return;
    void* target = *(void**)((CriUint8*)object[1] + offset);
    if (target)
    {
        typedef void (*Callback)(void*, A0, A1, A2, A3, A4);
        ((Callback)target)(object[0], a0, a1, a2, a3, a4);
    }
}

#endif
