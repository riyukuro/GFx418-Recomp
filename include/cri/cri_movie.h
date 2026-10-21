// Recovered CRI Movie (Sofdec 2) PC x64 3.07.01 public interface, as far as the exe's code uses it (sfr lane: the
// middleware the Scaleform video player sits on). Written from the exe; names follow the exe's mangled symbols.
// The library itself was built with VS2008 SP1 (Rich header: Utc1500 build 30729), so our VS2017 rebuild of it can
// only be functional. Shared header of the src/ms2/scaleform units: append, do not reorder.
#ifndef MS2_CRI_MOVIE_H
#define MS2_CRI_MOVIE_H

typedef signed char        CriSint8;
typedef unsigned char      CriUint8;
typedef signed short       CriSint16;
typedef unsigned short     CriUint16;
typedef signed long        CriSint32;
typedef unsigned long      CriUint32;
typedef signed __int64     CriSint64;
typedef unsigned __int64   CriUint64;
typedef float              CriFloat32;
typedef char               CriChar8;
typedef CriSint32          CriBool;

#define CRIAPI __cdecl

// Status of a call; every C++ entry point takes one by reference (default: CriMv::ErrorContainer).
typedef enum {
    CRIERR_OK                        = 0,
    CRIERR_NG                        = -1,
    CRIERR_INVALID_PARAMETER         = -2,
    CRIERR_FAILED_TO_ALLOCATE_MEMORY = -3,
    CRIERR_UNSAFE_FUNCTION_CALL      = -4,
    CRIERR_FUNCTION_NOT_IMPLEMENTED  = -5,
    CRIERR_LIBRARY_NOT_INITIALIZED   = -6,
    CRIERR_ENUM_BE_SINT32            = 0x7FFFFFFF
} CriError;

// Heap module (C interface).
extern "C" {
void CRIAPI criHeap_Initialize(void);
void CRIAPI criHeap_Finalize(void);
}

namespace CriMv {
    extern CriError ErrorContainer;

    void      CRIAPI Initialize(CriError& err = CriMv::ErrorContainer);
    void      CRIAPI InitializeFrame32bitARGB(void);
    void      CRIAPI Finalize(CriError& err = CriMv::ErrorContainer);
    CriUint32 CRIAPI CalcMovieHandleWork(CriUint32 max_num, CriError& err = CriMv::ErrorContainer);
    void      CRIAPI SetupMovieHandleWork(CriUint32 max_num, void* work, CriUint32 work_size,
                                          CriError& err = CriMv::ErrorContainer);
}

#endif
