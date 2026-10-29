// Type vocabulary and Ghidra pseudo-op helpers for the CRI vendor-code units transcribed from the decompile
// (sfr_cri_07). Self-contained: does not depend on cri_decomp.h.
#ifndef MS2_CRI_VENDOR_SHIM_H
#define MS2_CRI_VENDOR_SHIM_H
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <emmintrin.h>
typedef unsigned char cri_u1; typedef unsigned short cri_u2; typedef unsigned int cri_u4; typedef unsigned __int64 cri_u8;
typedef unsigned char undefined; typedef unsigned char undefined1; typedef unsigned short undefined2; typedef unsigned int undefined4;
typedef unsigned __int64 undefined8; typedef unsigned char byte; typedef unsigned int uint; typedef unsigned short ushort; typedef unsigned char uchar;
typedef unsigned long ulong; typedef unsigned int dword; typedef __int64 longlong; typedef unsigned __int64 ulonglong; typedef signed char sbyte;
struct V16 { unsigned char b[16]; };
struct V8 { unsigned char b[8]; };
static inline V16 psraw(V16 v, int n) { V16 r; _mm_storeu_si128((__m128i*)r.b, _mm_srai_epi16(_mm_loadu_si128((const __m128i*)v.b), n)); return r; }
// Partial-width views of Ghidra's 128-bit vector temporaries (bytes [offset, offset+size)).
template <int N> struct CriVecPart
{
    unsigned char* p;
    operator unsigned __int64() const { unsigned __int64 v = 0; memcpy(&v, p, N < 8 ? N : 8); return v; }
    CriVecPart& operator=(unsigned __int64 v) { memcpy(p, &v, N < 8 ? N : 8); return *this; }
    CriVecPart& operator=(const V16& v) { memcpy(p, v.b, N < 16 ? N : 16); return *this; }
};
struct cri_addr
{
    void* p;
    template <typename T> operator T*() const { return (T*)p; }
    operator __int64() const { return (__int64)p; }
    template <typename T> bool operator==(T* o) const { return p == (void*)o; }
    template <typename T> bool operator!=(T* o) const { return p != (void*)o; }
};
// The data globals are declared with Ghidra's scalar types (extern "C" int DAT_x) while the tables behind them are
// larger; laundering the address through a volatile keeps /Ox from bounding the fill loops by the declared size.
static inline void* cri_launder(void* p) { void* volatile q = p; return q; }
// maker functions, not brace-init: the units also build with VC9 (C++03)
static inline cri_addr cri_mkaddr(void* p) { cri_addr a; a.p = p; return a; }
template <int N> static inline CriVecPart<N> cri_mkpart(unsigned char* p) { CriVecPart<N> r; r.p = p; return r; }
#define CRI_ADDR(x) (cri_mkaddr(cri_launder((void*)&(x))))
#define CRI_PART(vec, offset, size) (cri_mkpart<size>((vec).b + (offset)))
#define CRI_IPART(var, offset, size) (cri_mkpart<size>((unsigned char*)&(var) + (offset)))

#include <math.h>
#include <intrin.h>
typedef unsigned __int64 uint3, uint5, uint6, uint7, unkuint9, unkuint10;
typedef __int64 int3, int5, int6, int7;
typedef cri_u8 cri_code(...);
static inline __m128i cri_ld(const V16& v) { return _mm_loadu_si128((const __m128i*)v.b); }
static inline __m128i cri_ld(const V8& v) { return _mm_loadl_epi64((const __m128i*)v.b); }
template <typename T> static inline __m128i cri_ld(const T& v) { return _mm_cvtsi64_si128((__int64)v); }
struct CriVec : V16
{
    CriVec() {}
    CriVec(const V16& v) : V16(v) {}
    template <typename T> operator T() const { T r; memcpy(&r, b, sizeof(T) < 16 ? sizeof(T) : 16); return r; }
};
static inline CriVec cri_st16(__m128i x) { V16 r; _mm_storeu_si128((__m128i*)r.b, x); return CriVec(r); }
static inline V8 cri_st8(__m128i x) { V8 r; _mm_storel_epi64((__m128i*)r.b, x); return r; }
#define CRI_BIN(name, op) \
    static inline CriVec name(const V16& a, const V16& b) { return cri_st16(op(cri_ld(a), cri_ld(b))); } \
    static inline V8 name(const V8& a, const V8& b) { return cri_st8(op(cri_ld(a), cri_ld(b))); } \
    template <typename A, typename B> static inline CriVec name(const A& a, const B& b) { return cri_st16(op(cri_ld(a), cri_ld(b))); }
CRI_BIN(pavgb, _mm_avg_epu8)
CRI_BIN(pavgw, _mm_avg_epu16)
CRI_BIN(paddusw, _mm_adds_epu16)
CRI_BIN(paddsw, _mm_adds_epi16)
CRI_BIN(psubsw, _mm_subs_epi16)
CRI_BIN(packsswb, _mm_packs_epi16)
CRI_BIN(packssdw, _mm_packs_epi32)
CRI_BIN(pmaddwd, _mm_madd_epi16)
CRI_BIN(pmulhw, _mm_mulhi_epi16)
// PSHUFLW / PSHUFHW never read the destination: the unshuffled half is the source's. Ghidra's pseudo-op still passes the
// destination register (often an uninitialized in_XMMn), so `d` is ignored.
template <typename S> static inline CriVec cri_shufw(const S& src, int order, int base)
{
    V16 sv = cri_st16(cri_ld(src)); V16 r = sv;
    for (int i = 0; i < 4; ++i) memcpy(r.b + (base + i) * 2, sv.b + (base + ((order >> (2 * i)) & 3)) * 2, 2);
    return CriVec(r);
}
template <typename A, typename S> static inline CriVec pshuflw(const A&, const S& src, int order) { return cri_shufw(src, order, 0); }
template <typename A, typename S> static inline CriVec pshufhw(const A&, const S& src, int order) { return cri_shufw(src, order, 4); }

static inline void cri_get128(const V16& v, unsigned __int64& lo, unsigned __int64& hi) { memcpy(&lo, v.b, 8); memcpy(&hi, v.b + 8, 8); }
static inline V16 cri_set128(unsigned __int64 lo, unsigned __int64 hi) { V16 r; memcpy(r.b, &lo, 8); memcpy(r.b + 8, &hi, 8); return r; }
static inline V16 operator<<(const V16& v, int n)
{
    unsigned __int64 lo, hi; cri_get128(v, lo, hi);
    if (n >= 128) return cri_set128(0, 0);
    if (n >= 64) return cri_set128(0, lo << (n - 64));
    if (n == 0) return v;
    return cri_set128(lo << n, (hi << n) | (lo >> (64 - n)));
}
static inline V16 operator>>(const V16& v, int n)
{
    unsigned __int64 lo, hi; cri_get128(v, lo, hi);
    if (n >= 128) return cri_set128(0, 0);
    if (n >= 64) return cri_set128(hi >> (n - 64), 0);
    if (n == 0) return v;
    return cri_set128((lo >> n) | (hi << (64 - n)), hi >> n);
}
static inline V16 operator|(const V16& a, const V16& b) { unsigned __int64 al, ah, bl, bh; cri_get128(a, al, ah); cri_get128(b, bl, bh); return cri_set128(al | bl, ah | bh); }
static inline V16 operator&(const V16& a, const V16& b) { unsigned __int64 al, ah, bl, bh; cri_get128(a, al, ah); cri_get128(b, bl, bh); return cri_set128(al & bl, ah & bh); }
static inline V16 operator^(const V16& a, const V16& b) { unsigned __int64 al, ah, bl, bh; cri_get128(a, al, ah); cri_get128(b, bl, bh); return cri_set128(al ^ bl, ah ^ bh); }
template <int N> static inline unsigned __int64 cri_lowbits(unsigned __int64 v) { return N >= 8 ? v : (v & ((1ull << (8 * N)) - 1)); }
template <typename T> static inline unsigned __int64 cri_as_u64(const T& v) { return (unsigned __int64)v; }
static inline unsigned __int64 cri_as_u64(const V16& v) { unsigned __int64 r; memcpy(&r, v.b, 8); return r; }
static inline unsigned __int64 cri_as_u64(const V8& v) { unsigned __int64 r; memcpy(&r, v.b, 8); return r; }
#define CRI_CONCAT(X, Y) static inline unsigned __int64 CONCAT##X##Y(unsigned __int64 a, unsigned __int64 b) { return (Y >= 8 ? 0 : (a << (8 * Y))) | cri_lowbits<Y>(b); }
CRI_CONCAT(1,1)
CRI_CONCAT(1,2)
CRI_CONCAT(1,3)
CRI_CONCAT(2,1)
CRI_CONCAT(2,2)
CRI_CONCAT(3,1)
CRI_CONCAT(4,4)
CRI_CONCAT(1,4)
CRI_CONCAT(1,5)
CRI_CONCAT(1,6)
CRI_CONCAT(1,7)
CRI_CONCAT(1,8)
CRI_CONCAT(1,9)
CRI_CONCAT(2,3)
CRI_CONCAT(2,4)
CRI_CONCAT(2,5)
CRI_CONCAT(2,6)
CRI_CONCAT(2,7)
CRI_CONCAT(2,8)
CRI_CONCAT(3,2)
CRI_CONCAT(3,3)
CRI_CONCAT(3,4)
CRI_CONCAT(3,5)
CRI_CONCAT(3,6)
CRI_CONCAT(3,7)
CRI_CONCAT(4,1)
CRI_CONCAT(4,2)
CRI_CONCAT(4,3)
CRI_CONCAT(4,5)
CRI_CONCAT(4,6)
CRI_CONCAT(5,1)
CRI_CONCAT(5,2)
CRI_CONCAT(5,3)
CRI_CONCAT(5,4)
CRI_CONCAT(5,5)
CRI_CONCAT(6,1)
CRI_CONCAT(6,2)
CRI_CONCAT(6,3)
CRI_CONCAT(6,4)
CRI_CONCAT(7,1)
CRI_CONCAT(7,2)
CRI_CONCAT(7,3)
CRI_CONCAT(8,1)
CRI_CONCAT(8,2)
CRI_CONCAT(9,1)

template <typename T> static inline V16 cri_zext16(const T& v) { V16 r = {}; unsigned __int64 q = cri_as_u64(v); memcpy(r.b, &q, 8); return r; }
template <typename T> static inline V16 cri_sext16(const T& v) { V16 r; __int64 q = (__int64)cri_as_u64(v); memcpy(r.b, &q, 8); __int64 hi = q < 0 ? -1 : 0; memcpy(r.b + 8, &hi, 8); return r; }
#define CRI_ZEXT(X) template <typename T> static inline V16 ZEXT##X##16(const T& v) { return cri_zext16(v); }
#define CRI_SEXT(X) template <typename T> static inline V16 SEXT##X##16(const T& v) { return cri_sext16(v); }
CRI_ZEXT(2) CRI_ZEXT(4) CRI_ZEXT(5) CRI_ZEXT(6) CRI_ZEXT(7) CRI_ZEXT(8)
CRI_SEXT(4) CRI_SEXT(8)
static inline V16 ZEXT812(unsigned __int64 v) { return cri_zext16(v); }
template <typename T> static inline unsigned __int64 cri_sub(const T& v, int off, int n) { unsigned __int64 q = cri_as_u64(v); return cri_lowbits<8>(q >> (8 * off)) & (n >= 8 ? ~0ull : ((1ull << (8 * n)) - 1)); }
static inline unsigned __int64 cri_sub(const V16& v, int off, int n) { unsigned __int64 r = 0; memcpy(&r, v.b + off, n > 8 ? 8 : n); return r; }
#define SUB158(v, o) cri_sub((v), (o), 8)
#define SUB1510(v, o) cri_sub((v), (o), 10)
#define SUB1512(v, o) cri_sub((v), (o), 12)
#define SUB169(v, o) cri_sub((v), (o), 9)
#define SUB1610(v, o) cri_sub((v), (o), 10)
#define SUB1611(v, o) cri_sub((v), (o), 11)
#define SUB1613(v, o) cri_sub((v), (o), 13)
#define SUB82(v, o) cri_sub((v), (o), 2)
#define POPCOUNT(x) ((cri_u4)__popcnt64((unsigned __int64)(x)))

struct cri_any
{
    cri_u8 v;
    cri_any() : v(0) {}
    template <typename T> cri_any(T* p) : v((cri_u8)p) {}
    template <typename T> cri_any(T x) : v((cri_u8)(__int64)x) {}
    template <typename T> operator T() const { return (T)v; }
};

#endif
