// Recovered Scaleform 4.1.18 kernel: UTF-8 decoding.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_KERNEL_UTF8UTIL_H
#define MS2_SF_KERNEL_UTF8UTIL_H

#include "sf_types.h"

namespace Scaleform { namespace UTF8Util {

// Decodes one code point and always moves past it, the terminating 0 included.
UInt32 SF_STDCALL DecodeNextChar_Advance0(const char** putf8Buffer);

// Same, but stays on the terminating 0.
inline UInt32 DecodeNextChar(const char** putf8Buffer)
{
    UInt32 ch = DecodeNextChar_Advance0(putf8Buffer);
    if (ch == 0)
        (*putf8Buffer)--;
    return ch;
}

// Number of code points in the first length bytes (-1: up to the terminating 0).
SPInt SF_STDCALL GetLength(const char* putf8str, SPInt length = -1);

// Decodes into pbuff, which must hold GetLength()+1 characters; returns the character count.
UPInt SF_STDCALL DecodeString(wchar_t* pbuff, const char* putf8str, SPInt bytesLen = -1);

// Encodes one code point at buffer + *offset and advances *offset (exe 0x1425a7170).
void SF_STDCALL EncodeChar(char* buffer, SPInt* offset, UInt32 ucsCharacter);

// Byte offset of code point index in the first length bytes (exe 0x1425a7590).
SPInt SF_STDCALL GetByteIndex(SPInt index, const char* putf8str, SPInt length = -1);

}} // namespace Scaleform::UTF8Util

#endif
