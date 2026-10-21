// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_UTF8Util (UTF-8 decoding
// and encoding, including the exe's bounded *Safe variants). Our own source, written from the exe (the leaked SDK copies
// were only used to name things). Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a66b0-0x1425a7e50 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"

namespace Scaleform { namespace UTF8Util {

SPInt SF_STDCALL GetLength(const char* utf8, SPInt length)
{
    const char* p = utf8;
    SPInt       len = 0;
    if (length != -1)
    {
        while (p - utf8 < length)
        {
            DecodeNextChar_Advance0(&p);    // zeros inside the length count as characters
            len++;
        }
    }
    else
    {
        while (DecodeNextChar_Advance0(&p) != 0)
            len++;
    }
    return len;
}

UInt32 SF_STDCALL GetCharAt(SPInt index, const char* utf8, SPInt length)
{
    const char* p = utf8;
    UInt32      ch = 0;
    if (length != -1)
    {
        while (p - utf8 < length)
        {
            ch = DecodeNextChar_Advance0(&p);
            if (index == 0)
                return ch;
            index--;
        }
        return ch;
    }
    do
    {
        ch = DecodeNextChar_Advance0(&p);
        index--;
        if (ch == 0)
            return 0;
    } while (index >= 0);
    return ch;
}

SPInt SF_STDCALL GetByteIndex(SPInt index, const char* utf8, SPInt length)
{
    const char* p = utf8;
    if (length != -1)
    {
        while (p - utf8 < length && index > 0)
        {
            DecodeNextChar_Advance0(&p);
            index--;
        }
        return p - utf8;
    }
    while (index > 0)
    {
        UInt32 ch = DecodeNextChar_Advance0(&p);
        index--;
        if (ch == 0)
            break;
    }
    return p - utf8;
}

int SF_STDCALL GetEncodeCharSize(UInt32 ch)
{
    if (ch <= 0x7F)
        return 1;
    if (ch <= 0x7FF)
        return 2;
    if (ch <= 0xFFFF)
        return 3;
    if (ch <= 0x1FFFFF)
        return 4;
    if (ch <= 0x3FFFFFF)
        return 5;
    if (ch <= 0x7FFFFFFF)
        return 6;
    return 0;
}

// one continuation byte (10xxxxxx) into ch: a zero ends the input, any other byte makes the sequence invalid
#define SF_UTF8_TRAIL(ch, shift)                \
    c = **utf8Buffer;                           \
    if (c == 0)                                 \
        return 0;                               \
    if ((c & 0xC0) != 0x80)                     \
        return 0xFFFD;                          \
    (*utf8Buffer)++;                            \
    ch |= (UInt32)(c & 0x3F) << (shift)

UInt32 SF_STDCALL DecodeNextChar_Advance0(const char** utf8Buffer)
{
    char   c = *(*utf8Buffer)++;
    UInt32 ch;
    if (c == 0)
        return 0;
    if ((c & 0x80) == 0)
        return c;
    if ((c & 0xE0) == 0xC0)
    {
        ch = (UInt32)(c & 0x1F) << 6;
        SF_UTF8_TRAIL(ch, 0);
        if (ch < 0x80)
            return 0xFFFD;      // overlong
        return ch;
    }
    if ((c & 0xF0) == 0xE0)
    {
        ch = (UInt32)(c & 0x0F) << 12;
        SF_UTF8_TRAIL(ch, 6);
        SF_UTF8_TRAIL(ch, 0);
        if (ch < 0x800)
            return 0xFFFD;
        return ch;
    }
    if ((c & 0xF8) == 0xF0)
    {
        ch = (UInt32)(c & 0x07) << 18;
        SF_UTF8_TRAIL(ch, 12);
        SF_UTF8_TRAIL(ch, 6);
        SF_UTF8_TRAIL(ch, 0);
        if (ch < 0x10000)
            return 0xFFFD;
        return ch;
    }
    if ((c & 0xFC) == 0xF8)
    {
        ch = (UInt32)(c & 0x03) << 24;
        SF_UTF8_TRAIL(ch, 18);
        SF_UTF8_TRAIL(ch, 12);
        SF_UTF8_TRAIL(ch, 6);
        SF_UTF8_TRAIL(ch, 0);
        if (ch < 0x200000)
            return 0xFFFD;
        return ch;
    }
    if ((c & 0xFE) == 0xFC)
    {
        ch = (UInt32)(c & 0x01) << 30;
        SF_UTF8_TRAIL(ch, 24);
        SF_UTF8_TRAIL(ch, 18);
        SF_UTF8_TRAIL(ch, 12);
        SF_UTF8_TRAIL(ch, 6);
        SF_UTF8_TRAIL(ch, 0);
        if (ch < 0x4000000)
            return 0xFFFD;
        return ch;
    }
    return 0xFFFD;
}

#undef SF_UTF8_TRAIL

#undef SF_UTF8_TRAIL

void SF_STDCALL EncodeChar(char* buffer, SPInt* offset, UInt32 ch)
{
    if (ch <= 0x7F)
    {
        buffer[(*offset)++] = (char)ch;
    }
    else if (ch <= 0x7FF)
    {
        buffer[(*offset)++] = (char)(0xC0 | (ch >> 6));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0xFFFF)
    {
        buffer[(*offset)++] = (char)(0xE0 | (ch >> 12));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0x1FFFFF)
    {
        buffer[(*offset)++] = (char)(0xF0 | (ch >> 18));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 12) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0x3FFFFFF)
    {
        buffer[(*offset)++] = (char)(0xF8 | (ch >> 24));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 18) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 12) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0x7FFFFFFF)
    {
        buffer[(*offset)++] = (char)(0xFC | (ch >> 30));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 24) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 18) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 12) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
}

SPInt SF_STDCALL GetEncodeStringSize(const wchar_t* chars, SPInt length)
{
    SPInt size = 0;
    if (length != -1)
    {
        for (int i = 0; i < length; i++)
            size += GetEncodeCharSize(chars[i]);
    }
    else
    {
        for (int i = 0; chars[i] != 0; i++)
            size += GetEncodeCharSize(chars[i]);
    }
    return size;
}

void SF_STDCALL EncodeString(char* buff, const wchar_t* chars, SPInt length)
{
    SPInt ofs = 0;
    if (length != -1)
    {
        for (int i = 0; i < length; i++)
            EncodeChar(buff, &ofs, chars[i]);
    }
    else
    {
        for (int i = 0; chars[i] != 0; i++)
            EncodeChar(buff, &ofs, chars[i]);
    }
    buff[ofs] = 0;
}

// EncodeString into at most buffSize bytes; the terminator goes after the last character that fit
void SF_STDCALL EncodeStringSafe(char* buff, UPInt buffSize, const wchar_t* chars, SPInt length)
{
    if (buffSize == 0 || chars == NULL)
        return;
    SPInt ofs = 0;
    if (length != -1)
    {
        for (int i = 0; i < length && ofs < (SPInt)buffSize; i++)
            EncodeCharSafe(buff, buffSize - ofs, &ofs, *chars++);
    }
    else
    {
        while (ofs < (SPInt)buffSize && *chars != 0)
            EncodeCharSafe(buff, buffSize - ofs, &ofs, *chars++);
    }
    buff[ofs] = 0;
}

// EncodeChar that writes nothing when the character does not fit into the buffSize bytes left (never inlined in the exe)
SF_NOINLINE void SF_STDCALL EncodeCharSafe(char* buffer, UPInt buffSize, SPInt* offset, UInt32 ch)
{
    if (ch <= 0x7F)
    {
        if (buffSize < 1)
            return;
        buffer[(*offset)++] = (char)ch;
    }
    else if (ch <= 0x7FF)
    {
        if (buffSize < 2)
            return;
        buffer[(*offset)++] = (char)(0xC0 | (ch >> 6));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0xFFFF)
    {
        if (buffSize < 3)
            return;
        buffer[(*offset)++] = (char)(0xE0 | (ch >> 12));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0x1FFFFF)
    {
        if (buffSize < 4)
            return;
        buffer[(*offset)++] = (char)(0xF0 | (ch >> 18));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 12) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0x3FFFFFF)
    {
        if (buffSize < 5)
            return;
        buffer[(*offset)++] = (char)(0xF8 | (ch >> 24));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 18) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 12) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
    else if (ch <= 0x7FFFFFFF)
    {
        if (buffSize < 6)
            return;
        buffer[(*offset)++] = (char)(0xFC | (ch >> 30));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 24) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 18) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 12) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | ((ch >> 6) & 0x3F));
        buffer[(*offset)++] = (char)(0x80 | (ch & 0x3F));
    }
}

UPInt SF_STDCALL DecodeString(wchar_t* buff, const char* utf8, SPInt bytesLen)
{
    wchar_t* start = buff;
    if (bytesLen == -1)
    {
        for (;;)
        {
            UInt32 ch = DecodeNextChar_Advance0(&utf8);
            if (ch == 0)
                break;
            if (ch >= 0xFFFF)
                ch = 0xFFFD;
            *buff++ = (wchar_t)ch;
        }
    }
    else
    {
        const char* s = utf8;
        while (s - utf8 < bytesLen)
        {
            UInt32 ch = DecodeNextChar_Advance0(&s);
            if (ch >= 0xFFFF)
                ch = 0xFFFD;
            *buff++ = (wchar_t)ch;
        }
    }
    *buff = 0;
    return buff - start;
}

// DecodeString that stops after buffSize characters (the terminator goes one past them)
UPInt SF_STDCALL DecodeStringSafe(wchar_t* buff, UPInt buffSize, const char* utf8, SPInt bytesLen)
{
    if (buffSize == 0)
        return 0;
    wchar_t* start = buff;
    wchar_t* end = buff + buffSize;
    if (bytesLen == -1)
    {
        for (; buff < end; buff++)
        {
            UInt32 ch = DecodeNextChar_Advance0(&utf8);
            if (ch == 0)
                break;
            if (ch >= 0xFFFF)
                ch = 0xFFFD;
            *buff = (wchar_t)ch;
        }
    }
    else
    {
        const char* s = utf8;
        while (s - utf8 < bytesLen)
        {
            if (buff >= end)
                break;
            UInt32 ch = DecodeNextChar_Advance0(&s);
            if (ch >= 0xFFFF)
                ch = 0xFFFD;
            *buff++ = (wchar_t)ch;
        }
    }
    *buff = 0;
    return buff - start;
}

}}  // namespace Scaleform::UTF8Util
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ?DecodeNextChar_Advance0@UTF8Util@Scaleform@@YAKPEAPEBD@Z 0x1425a66b0
// MS2-PIN: ?DecodeString@UTF8Util@Scaleform@@YA_KPEA_WPEBD_J@Z 0x1425a6a00
// MS2-PIN: ?DecodeStringSafe@UTF8Util@Scaleform@@YA_KPEA_W_KPEBD_J@Z 0x1425a6da0
// MS2-PIN: ?EncodeChar@UTF8Util@Scaleform@@YAXPEADPEA_JK@Z 0x1425a7170
// MS2-PIN: ?EncodeCharSafe@UTF8Util@Scaleform@@YAXPEAD_KPEA_JK@Z 0x1425a7280
// MS2-PIN: ?EncodeString@UTF8Util@Scaleform@@YAXPEADPEB_W_J@Z 0x1425a73c0
// MS2-PIN: ?EncodeStringSafe@UTF8Util@Scaleform@@YAXPEAD_KPEB_W_J@Z 0x1425a74c0
// MS2-PIN: ?GetByteIndex@UTF8Util@Scaleform@@YA_J_JPEBD0@Z 0x1425a7590
// MS2-PIN: ?GetCharAt@UTF8Util@Scaleform@@YAK_JPEBD0@Z 0x1425a7770
// MS2-PIN: ?GetEncodeCharSize@UTF8Util@Scaleform@@YAHK@Z 0x1425a7b50
// MS2-PIN: ?GetEncodeStringSize@UTF8Util@Scaleform@@YA_JPEB_W_J@Z 0x1425a7bb0
// MS2-PIN: ?GetLength@UTF8Util@Scaleform@@YA_JPEBD_J@Z 0x1425a7c50
