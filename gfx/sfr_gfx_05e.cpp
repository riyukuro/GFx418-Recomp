// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_ASUtils (escape/unescape of the
// AS2 and AS3 builtins, ECMA white space skipping, and the NumberUtil number <-> text conversions). The AS3 entry points
// share a stack Formatter that buffers 512 bytes before appending to the result string.
// MS2-UNIT: sfr_gfx_05e
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425e3750-0x1425e38a0 .text$mn
// MS2-RANGE: 0x1425e38a0-0x1425e4f80 .text$mn

#include <string.h>

#include "../include/gfx/gfx_asutils.h"
#include "../include/kernel/sf_std.h"
#include "../include/kernel/sf_utf8util.h"

namespace Scaleform { namespace GFx {

namespace ASUtils {

// Hex digit for a nibble, upper case.
static inline char UpperHexDigit(unsigned n)
{
    return char(n + (n <= 9 ? '0' : 'A' - 10));
}

// @0x1425e3920
void EscapeWithMask(const char* psrc, UPInt length, String* pescapedStr, const unsigned* escapeMask)
{
    char        buf[256];
    char*       pbuf = buf;
    char* const endp = buf + sizeof(buf) - 1;

    for (unsigned i = 0; i < length; ++i)
    {
        unsigned ch = (unsigned char)psrc[i];
        if (pbuf + 4 >= endp)
        {
            *pbuf = 0;
            *pescapedStr += buf;
            pbuf = buf;
        }
        if (ch < 128 && (escapeMask[ch / 32] & (1u << (ch % 32))))
            *pbuf++ = char(ch);
        else
        {
            *pbuf++ = '%';
            *pbuf++ = UpperHexDigit(ch / 16);
            *pbuf++ = UpperHexDigit(ch % 16);
        }
    }
    *pbuf = 0;
    *pescapedStr += buf;
}

// Letters and digits pass.
// @0x1425e38a0
void Escape(const char* psrc, UPInt length, String* pescapedStr)
{
    static const unsigned alnum[] = { 0x00000000, 0x03FF0000, 0x07FFFFFE, 0x07FFFFFE };
    EscapeWithMask(psrc, length, pescapedStr, alnum);
}

// Letters, digits and the path characters . / : \ pass.
// @0x1425e38b0
void EscapePath(const char* psrc, UPInt length, String* pescapedStr)
{
    static const unsigned pathChars[] = { 0x00000000, 0x07FFC000, 0x17FFFFFE, 0x07FFFFFE };
    EscapeWithMask(psrc, length, pescapedStr, pathChars);
}

// @0x1425e4d00
void Unescape(const char* psrc, UPInt length, String* punescapedStr)
{
    char              buf[256];
    const char* const end  = psrc + length;
    char*             pbuf = buf;
    char* const       endp = buf + sizeof(buf) - 1;

    while (psrc < end)
    {
        int ch = (unsigned char)*psrc++;
        if (pbuf + 1 >= endp)
        {
            *pbuf = 0;
            *punescapedStr += buf;
            pbuf = buf;
        }
        if (ch == '%')
        {
            int hi = SFtoupper((unsigned char)*psrc++);
            int lo = SFtoupper((unsigned char)*psrc++);
            hi = (hi - '0' > 9) ? hi - 'A' + 10 : hi - '0';
            lo = (lo - '0' > 9) ? lo - 'A' + 10 : lo - '0';
            if (hi < 16 && lo < 16)
                *pbuf++ = char(hi * 16 + lo);
        }
        else
            *pbuf++ = char(ch);
    }
    *pbuf = 0;
    *punescapedStr += buf;
}

// @0x1425e3e20
bool IsWhiteSpace(UInt32 c)
{
    return c == ' ' || (c >= '\t' && c <= '\r') || (c >= 0x2000 && c <= 0x200b) || c == 0x2028 || c == 0x2029 ||
           c == 0x205f || c == 0x3000;
}

// @0x1425e4050
UInt32 SkipWhiteSpace(const String& str)
{
    UInt32 i   = 0;
    UInt32 len = (UInt32)str.GetLength();
    while (i < len && IsWhiteSpace(str.GetCharAt(i)))
        ++i;
    return i;
}

// @0x1425e40f0
const char* SkipWhiteSpace(const char* str, UPInt len)
{
    const char* end = str + len;
    const char* cur = str;
    while (cur < end)
    {
        if (!IsWhiteSpace(UTF8Util::DecodeNextChar_Advance0(&str)))
            break;
        cur = str;
    }
    return cur;
}

namespace AS3 {

class Formatter
{
public:
    Formatter() : Endp(Buf + sizeof(Buf) - 1), pBuf(Buf) {}

    void EscapeWithMask(const char* psrc, UPInt length, String& escapedStr, const unsigned* escapeMask);
    bool Unescape(const char* psrc, UPInt length, String& unescapedStr);

private:
    static bool InMask(int ch, const unsigned* mask) { return (mask[ch / 32] & (1u << (ch % 32))) != 0; }
    static char HexDigit(UByte n) { return n < 10 ? char(n + '0') : char(n + 'A' - 10); }
    void WriteHexByte(UByte v)
    {
        *pBuf++ = HexDigit(v >> 4);
        *pBuf++ = HexDigit(v & 0xF);
    }
    // Reads up to maxDigits hex digits; psrc is left unchanged unless all of them were present.
    UInt16 ReadHex(const char*& psrc, const char* end, UByte maxDigits);

    char        Buf[512];
    char* const Endp;
    char*       pBuf;
};

// @0x1425e3a50
// MS2-FUNCTIONAL: pBuf reloads and the hex digit branches scheduled differently
void Formatter::EscapeWithMask(const char* psrc, UPInt length, String& escapedStr, const unsigned* escapeMask)
{
    const char* end = psrc + length;

    pBuf = Buf;
    while (psrc < end)
    {
        int ch = (int)UTF8Util::DecodeNextChar_Advance0(&psrc);
        // %uXXXX is the longest output of one character.
        if (pBuf + 7 >= Endp)
        {
            *pBuf = 0;
            escapedStr += Buf;
            pBuf = Buf;
        }
        if (ch < 128 && InMask(ch, escapeMask))
            *pBuf++ = char(ch);
        else
        {
            *pBuf++ = '%';
            if (ch & 0xFF00)
            {
                *pBuf++ = 'u';
                WriteHexByte(UByte((UInt16)ch >> 8));
            }
            WriteHexByte(UByte(ch));
        }
    }
    *pBuf = 0;
    escapedStr += Buf;
}

// @0x1425e3f40
// MS2-FUNCTIONAL: digit classification order differs
UInt16 Formatter::ReadHex(const char*& psrc, const char* end, UByte maxDigits)
{
    const char* start = psrc;
    const char* p     = start;
    UInt16      value = 0;

    for (int i = 0; i < maxDigits; ++i)
    {
        p = psrc;
        if (p >= end)
            break;
        char c = *p;
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')))
            break;
        p = ++psrc;
        UByte digit;
        if (c >= '0' && c <= '9')
            digit = UByte(c - '0');
        else if (c >= 'A' && c <= 'F')
            digit = UByte(c - 'A' + 10);
        else if (c >= 'a' && c <= 'f')
            digit = UByte(c - 'a' + 10);
        else
            digit = 0;
        value = UInt16((value << 4) | digit);
    }
    if (p - start < maxDigits)
        psrc = start;
    return value;
}

// @0x1425e4e30
// MS2-FUNCTIONAL: pBuf reload placement differs
bool Formatter::Unescape(const char* psrc, UPInt length, String& unescapedStr)
{
    const char* end = psrc + length;

    pBuf = Buf;
    while (psrc < end)
    {
        char ch = *psrc++;
        // One UTF-8 sequence is at most six bytes.
        if (pBuf + 7 >= Endp)
        {
            *pBuf = 0;
            unescapedStr += Buf;
            pBuf = Buf;
        }
        if (ch == '%')
        {
            const char* digits = psrc;
            UInt16      code   = ReadHex(psrc, end, *psrc == 'u' ? 4 : 2);
            if (psrc == digits)
                return false;
            SPInt pos = pBuf - Buf;
            UTF8Util::EncodeChar(Buf, &pos, code);
            pBuf = Buf + pos;
        }
        else
            *pBuf++ = ch;
    }
    *pBuf = 0;
    // Embedded zero characters are part of the result.
    unescapedStr.AppendString(Buf, pBuf - Buf);
    return true;
}

// Mask bits: mask[c / 32] & (1 << (c % 32)) set for the 7-bit characters that are copied unescaped.
static unsigned EscapeMask[]             = { 0x00000000, 0x03FFEC00, 0x87FFFFFF, 0x07FFFFFE };
static unsigned EncodeURIMask[]          = { 0x00000000, 0xAFFFFFDA, 0x87FFFFFF, 0x47FFFFFE };
static unsigned EncodeURIComponentMask[] = { 0x00000000, 0x03FF6782, 0x87FFFFFE, 0x47FFFFFE };

// @0x1425e3750
void EncodeURI(const char* psrc, UPInt length, String& escapedStr)
{
    Formatter f;
    f.EscapeWithMask(psrc, length, escapedStr, EncodeURIMask);
}

// @0x1425e37c0
void EncodeURIComponent(const char* psrc, UPInt length, String& escapedStr)
{
    Formatter f;
    f.EscapeWithMask(psrc, length, escapedStr, EncodeURIComponentMask);
}

// @0x1425e3830
void Escape(const char* psrc, UPInt length, String& escapedStr)
{
    Formatter f;
    f.EscapeWithMask(psrc, length, escapedStr, EscapeMask);
}

// @0x1425e38c0
void EscapeWithMask(const char* psrc, UPInt length, String& escapedStr, const unsigned* escapeMask)
{
    Formatter f;
    f.EscapeWithMask(psrc, length, escapedStr, escapeMask);
}

// @0x1425e4ad0
// MS2-FUNCTIONAL: inlined Formatter::Unescape scheduled differently
bool Unescape(const char* psrc, UPInt length, String& unescapedStr)
{
    Formatter f;
    return f.Unescape(psrc, length, unescapedStr);
}

} // namespace AS3

} // namespace ASUtils

namespace NumberUtil {

// IEEE 754 bit patterns, little endian.
static const UByte NaNBits[8]              = { 0, 0, 0, 0, 0, 0, 0xF8, 0xFF };
static const UByte PositiveInfinityBits[8] = { 0, 0, 0, 0, 0, 0, 0xF0, 0x7F };
static const UByte NegativeInfinityBits[8] = { 0, 0, 0, 0, 0, 0, 0xF0, 0xFF };
static const UByte MinValueBits[8]         = { 0, 0, 0, 0, 0, 0, 0x10, 0x00 };
static const UByte MaxValueBits[8]         = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x7F };
static const UByte NegativeZeroBits[8]     = { 0, 0, 0, 0, 0, 0, 0, 0x80 };
static const UByte PositiveZeroBits[8]     = { 0, 0, 0, 0, 0, 0, 0, 0 };

static inline Double FromBits(const UByte* bits)
{
    Double d;
    memcpy(&d, bits, sizeof(d));
    return d;
}

// @0x1425e3ee0
Double SF_CDECL NaN() { return FromBits(NaNBits); }
// @0x1425e3f00
Double SF_CDECL POSITIVE_INFINITY() { return FromBits(PositiveInfinityBits); }
// @0x1425e3ea0
Double SF_CDECL NEGATIVE_INFINITY() { return FromBits(NegativeInfinityBits); }
// @0x1425e3e80
Double SF_CDECL MIN_VALUE() { return FromBits(MinValueBits); }
// @0x1425e3e60
Double SF_CDECL MAX_VALUE() { return FromBits(MaxValueBits); }
// @0x1425e3f20
Double SF_CDECL POSITIVE_ZERO() { return FromBits(PositiveZeroBits); }
// @0x1425e3ec0
Double SF_CDECL NEGATIVE_ZERO() { return FromBits(NegativeZeroBits); }

// @0x1425e3e00
bool IsPOSITIVE_ZERO(Double v) { return memcmp(&v, PositiveZeroBits, sizeof(v)) == 0; }
// @0x1425e3de0
bool IsNEGATIVE_ZERO(Double v) { return memcmp(&v, NegativeZeroBits, sizeof(v)) == 0; }

// @0x1425e3bf0
const char* IntToString(SInt32 value, char destStr[], size_t destStrSize)
{
    size_t   last = destStrSize - 1;
    char*    p    = destStr + last;
    unsigned i, n = (unsigned)(value < 0 ? -value : value);

    *p = 0;
    for (i = 0; i < last; ++i)
    {
        *--p = char('0' + n % 10);
        n /= 10;
        if (n == 0)
            break;
    }
    if (i < last && value < 0)
        *--p = '-';
    return p;
}

// @0x1425e3c80
// MS2-FUNCTIONAL: binary loop register allocation differs
const char* IntToString(SInt32 value, char destStr[], size_t destStrSize, int radix)
{
    size_t last = destStrSize - 1;
    char*  p    = destStr + last;
    *p = 0;

    unsigned n = (unsigned)value;
    if (radix == 16)
    {
        for (unsigned i = 0; i < last; ++i)
        {
            UByte d = UByte(n & 0xF);
            *--p = char(d + (d <= 9 ? '0' : 'a' - 10));
            n >>= 4;
            if (n == 0)
                break;
        }
    }
    else if (radix == 8)
    {
        for (unsigned i = 0; i < last; ++i)
        {
            *--p = char('0' + (n & 7));
            n >>= 3;
            if (n == 0)
                break;
        }
    }
    else if (radix == 2)
    {
        // All 32 bits are written; the result starts at the highest set bit ("0" for zero).
        char*    highest = 0;
        unsigned bit     = 1;
        for (unsigned i = 0; i < 32 && i < last; ++i)
        {
            --p;
            if (n & bit)
            {
                *p      = '1';
                highest = p;
            }
            else
                *p = '0';
            bit <<= 1;
            if (bit == 0)
                bit = 1;
        }
        p = highest ? highest : destStr + destStrSize - 2;
    }
    else
        return IntToString(value, destStr, destStrSize);
    return p;
}

// @0x1425e4810
// MS2-FUNCTIONAL: radix dispatch order differs
const char* ToString(Double value, char destStr[], size_t destStrSize, int radix)
{
    static const char* const formats[] = { "%.1g", "%.2g", "%.3g",  "%.4g",  "%.5g",  "%.6g",  "%.7g",
                                           "%.8g", "%.9g", "%.10g", "%.11g", "%.12g", "%.13g", "%.14g" };
    const char* format = formats[13];
    if (radix <= 0)
    {
        format = formats[(radix >= -14 ? -radix : 14) - 1];
        radix  = 10;
    }

    if (IsNaNOrInfinity(value))
    {
        if (IsNaN(value))
            strcpy_s(destStr, destStrSize, "NaN");
        else if (IsPOSITIVE_INFINITY(value))
            strcpy_s(destStr, destStrSize, "Infinity");
        else if (IsNEGATIVE_INFINITY(value))
            strcpy_s(destStr, destStrSize, "-Infinity");
        return destStr;
    }

    SInt32 ival = (SInt32)value;
    if (radix != 10)
        return IntToString(ival, destStr, destStrSize, radix);
    if ((Double)ival == value)
        return IntToString(ival, destStr, destStrSize);
    SFsprintf(destStr, destStrSize, format, value);
    // A locale may have printed a decimal comma.
    for (char* s = destStr; *s; ++s)
    {
        if (*s == ',' || *s == '.')
        {
            *s = '.';
            break;
        }
    }
    return destStr;
}

// Value of a digit in radix 36 (-1: not a digit).
static inline SInt32 DigitValue(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    return -1;
}

// @0x1425e4360
// MS2-FUNCTIONAL: rounding switch laid out differently
Double StringToInt(const char* str, UInt32 strLen, SInt32 radix, UInt32* endIndex)
{
    SInt32  sign = 1;
    UInt32& pos  = *endIndex;
    pos = 0;

    // radix 0 means 10 with an optional 0x prefix; 16 also accepts the prefix.
    bool allowPrefix = true;
    if (radix == 0)
        radix = 10;
    else if (radix < 2 || radix > 36)
        return NaN();
    else if (radix != 16)
        allowPrefix = false;

    pos = (UInt32)UTF8Util::GetByteIndex(ASUtils::SkipWhiteSpace(str), str, strLen);
    if (pos == strLen)
        return 0;

    if (str[pos] == '-')
    {
        sign = -1;
        ++pos;
    }
    else if (str[pos] == '+')
        ++pos;

    if (allowPrefix && strLen - pos > 1)
    {
        if (str[pos] == '0' && (str[pos + 1] == 'x' || str[pos + 1] == 'X'))
        {
            radix = 16;
            pos += 2;
            if (strLen == pos)
                return NaN();
        }
    }

    UInt32 first  = pos;
    Double result = 0;
    SInt32 digit  = 0;
    while (pos < strLen)
    {
        digit = DigitValue(str[pos]);
        if (digit >= radix || digit < 0)
            break;
        result = result * radix + digit;
        ++pos;
    }
    if (pos == first)
        return NaN();

    // Power-of-two radixes are exact: above 53 bits reparse the top 53 bits and round the rest to nearest even.
    if (result >= 9007199254740992.0 && (radix == 2 || radix == 8 || radix == 16))
    {
        SInt32 bitsPerDigit = 1;
        if (radix == 8)
            bitsPerDigit = 3;
        else if (radix == 16)
            bitsPerDigit = 4;

        while (first < strLen && str[first] == '0')
            ++first;

        result = 0;
        UInt32 count;
        for (count = 0; first < strLen && count * bitsPerDigit <= 52; ++count)
        {
            digit = DigitValue(str[first++]);
            if (digit >= radix || digit < 0)
            {
                digit = 0;
                break;
            }
            result = result * radix + digit;
        }

        if (count * bitsPerDigit > 52)
        {
            bool   sticky = false;
            bool   lsb    = false;
            bool   half   = false;
            UInt32 shift  = 0;

            if (radix == 16)
            {
                lsb   = (digit & 1) != 0;
                digit = first < strLen ? DigitValue(str[first]) : -1;
                if (digit != -1 && digit < radix)
                {
                    shift += bitsPerDigit;
                    half   = (digit & 8) != 0;
                    sticky = (digit & 3) != 0;
                }
                else
                    sticky = lsb;
            }
            else if (radix == 8)
            {
                digit = first < strLen ? DigitValue(str[first]) : -1;
                if (digit == -1 || digit >= radix)
                    digit = 0;
                shift += bitsPerDigit;
                lsb  = (digit & 2) != 0;
                half = (digit & 1) != 0;
            }
            else if (radix == 2)
            {
                lsb   = (digit & 1) != 0;
                digit = first < strLen ? DigitValue(str[first]) : -1;
                if (digit == -1 || digit >= radix)
                    digit = 0;
                shift += bitsPerDigit;
                half = (digit & 1) != 0;
            }

            while (++first < strLen)
            {
                digit = DigitValue(str[first]);
                if (digit == -1 || digit >= radix)
                    break;
                sticky |= (digit != 0);
                shift += bitsPerDigit;
            }
            bool roundUp = half && (lsb || sticky);
            result += roundUp ? 1.0 : 0.0;
            result *= (1 << shift);
        }
    }
    return result * sign;
}

// @0x1425e4190
Double StringToDouble(const char* str, UInt32 strLen, UInt32* endIndex)
{
    UInt32& pos = *endIndex;
    pos = 0;
    pos = (UInt32)UTF8Util::GetByteIndex(ASUtils::SkipWhiteSpace(str), str, strLen);

    // Unlike parseInt, white space alone is NaN.
    UInt32 rest = strLen - pos;
    if (rest == 0)
        return NaN();

    const char* p    = str + pos;
    char*       tail = 0;
    if (rest > 1)
    {
        switch (*p)
        {
        case 'I':
            if (strncmp(p, "Infinity", 8) == 0)
            {
                pos += 8;
                return POSITIVE_INFINITY();
            }
            break;
        case '+':
            if (strncmp(p, "+Infinity", 9) == 0)
            {
                pos += 9;
                return POSITIVE_INFINITY();
            }
            break;
        case '-':
            if (strncmp(p, "-Infinity", 9) == 0)
            {
                pos += 9;
                return NEGATIVE_INFINITY();
            }
            break;
        }
    }

    double value = SFstrtod(p, &tail);
    pos += (UInt32)(tail - p);
    return tail != p ? value : NaN();
}

} // namespace NumberUtil

}} // namespace Scaleform::GFx
