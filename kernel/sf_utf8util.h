// Recovered Scaleform GFx 4.1.18: UTF-8 helpers (bodies in sfr_kernel_02e). Lengths are in characters, sizes in bytes;
// -1 means "up to the terminating zero".
#ifndef MS2_SF_KERNEL_UTF8UTIL_H
#define MS2_SF_KERNEL_UTF8UTIL_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform { namespace UTF8Util {

SPInt  SF_STDCALL GetLength(const char* utf8, SPInt length = -1);
UInt32 SF_STDCALL GetCharAt(SPInt index, const char* utf8, SPInt length = -1);
SPInt  SF_STDCALL GetByteIndex(SPInt index, const char* utf8, SPInt length = -1);
SPInt  SF_STDCALL GetEncodeStringSize(const wchar_t* chars, SPInt length = -1);
void   SF_STDCALL EncodeString(char* buff, const wchar_t* chars, SPInt length = -1);
// bounded variants of the exe (not in the later SDKs): never write past buffSize, always terminate
void   SF_STDCALL EncodeCharSafe(char* buff, UPInt buffSize, SPInt* index, UInt32 ucsCharacter);
void   SF_STDCALL EncodeStringSafe(char* buff, UPInt buffSize, const wchar_t* chars, SPInt length = -1);
UPInt  SF_STDCALL DecodeString(wchar_t* buff, const char* utf8, SPInt bytesLen = -1);
UPInt  SF_STDCALL DecodeStringSafe(wchar_t* buff, UPInt buffSize, const char* utf8, SPInt bytesLen = -1);
int    SF_STDCALL GetEncodeCharSize(UInt32 ucsCharacter);
void   SF_STDCALL EncodeChar(char* buffer, SPInt* offset, UInt32 ucsCharacter);
// decodes one character and always advances past it (also past a terminating zero)
UInt32 SF_STDCALL DecodeNextChar_Advance0(const char** utf8Buffer);

// like DecodeNextChar_Advance0, but stays on a terminating zero
inline UInt32 DecodeNextChar(const char** utf8Buffer)
{
    UInt32 ch = DecodeNextChar_Advance0(utf8Buffer);
    if (ch == 0)
        (*utf8Buffer)--;
    return ch;
}

}}  // namespace Scaleform::UTF8Util

#endif
