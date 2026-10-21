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

}} // namespace Scaleform::UTF8Util

#endif
