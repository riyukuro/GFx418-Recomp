// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_MsgFormat (formatters,
// the "{n:options}" parser, the printf-style FormatF front end and SPrintF).
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02q
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425ae810-0x1425b3380 .text$mn
#include <ctype.h>
#include <stdlib.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"
#include "ms2/scaleform/kernel/sf_msgformat.h"

namespace Scaleform {

bool IsSpace(StringDataPtr str);

unsigned FmtResource::Reflect(const TAttrs*& attrs) const
{
    attrs = 0;
    return 0;
}

// ---- SwitchFormatter -----------------------------------------------------------------------------------------------

// "sw:<n>:<text>:<n>:<text>...:<default>" picks the text whose number equals the argument
class SwitchFormatter : public Formatter
{
public:
    class ValueType
    {
    public:
        typedef int Type;

        ValueType() : Value(0) { }
        ValueType(int value) : Value(value) { }

        int GetValue() const { return Value; }
        void SetValue(int value) { Value = value; }
        operator int() const { return GetValue(); }
        ValueType& operator=(int value)
        {
            SetValue(value);
            return *this;
        }

    private:
        int Value;
    };

    SwitchFormatter(MsgFormat& f, const ValueType& v);

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;

private:
    SwitchFormatter& operator=(const SwitchFormatter&);

    int                      Value;
    Hash<int, StringDataPtr> StringSet;
    StringDataPtr            StrValue;
    StringDataPtr            DefaultStrValue;
};

SwitchFormatter::SwitchFormatter(MsgFormat& f, const ValueType& v) : Formatter(f), Value(v)
{
}

// numbers and texts alternate; a token that is not a number ends the list as the default
void SwitchFormatter::Parse(const StringDataPtr& str)
{
    StringDataPtr rest = str;
    StringDataPtr cur;
    enum State { stNumber, stStr };
    State state = stNumber;
    int   number = 0;

    do
    {
        cur = rest.GetNextToken();
        rest.TrimLeft(cur.GetSize() + 1);

        if (state == stNumber)
        {
            const char* s = cur.ToCStr();
            if (!cur.IsEmpty() && s && isdigit(s[0]))
            {
                number = atoi(s);
                state = stStr;
            }
            else
            {
                DefaultStrValue = cur;
                break;
            }
        }
        else
        {
            StringSet.Add(number, cur);
            state = stNumber;
        }
    } while (!rest.IsEmpty());
}

void SwitchFormatter::Convert()
{
    if (Converted())
        return;
    if (!StringSet.Get(Value, &StrValue))
        StrValue = DefaultStrValue;
    SetConverted();
}

StringDataPtr SwitchFormatter::GetResult() const
{
    return StrValue;
}

UPInt SwitchFormatter::GetSize() const
{
    return StrValue.GetSize();
}

// ---- Formatter -----------------------------------------------------------------------------------------------------

Formatter::~Formatter()
{
}

void Formatter::Parse(const StringDataPtr&)
{
}

Formatter::requirements_t Formatter::GetRequirements() const
{
    return rtNone;
}

void Formatter::SetPrevStr(const StringDataPtr&)
{
}

StringDataPtr Formatter::GetPrevStr() const
{
    return StringDataPtr();
}

void Formatter::SetNextStr(const StringDataPtr&)
{
}

StringDataPtr Formatter::GetNextStr() const
{
    return StringDataPtr();
}

Formatter::ParentRef Formatter::GetParentRef() const
{
    return prNone;
}

unsigned char Formatter::GetParentPos() const
{
    return 0;
}

void Formatter::SetParent(const FmtResource&)
{
}

void Formatter::SetParentRef(ParentRef)
{
}

void Formatter::SetParentPos(unsigned char)
{
}

// ---- StrFormatter --------------------------------------------------------------------------------------------------

StrFormatter::StrFormatter(const char* v) : Value(v)
{
}

StrFormatter::StrFormatter(const StringDataPtr& v) : Value(v)
{
}

StrFormatter::StrFormatter(const String& v) : Value(v)
{
}

StrFormatter::StrFormatter(MsgFormat& f, const char* v) : Formatter(f), Value(v)
{
}

StrFormatter::StrFormatter(MsgFormat& f, const StringDataPtr& v) : Formatter(f), Value(v)
{
}

StrFormatter::StrFormatter(MsgFormat& f, const String& v) : Formatter(f), Value(v)
{
}

// a named option replaces this formatter with the locale's one
void StrFormatter::Parse(const StringDataPtr& str)
{
    StringDataPtr token = str.GetNextToken();
    Formatter*    impl = 0;

    if (HasParent() && GetParent().GetLocaleProvider())
    {
        FormatterFactory::Args args(GetParent(), token, ResourceFormatter::ValueType(Value.ToCStr()));
        impl = GetParent().GetLocaleProvider()->MakeFormatter(args);
    }

    if (impl)
    {
        StringDataPtr implParams = str.GetTrimLeft(token.GetSize() + 1);
        if (implParams.GetSize() > 0)
            impl->Parse(implParams);
        GetParent().ReplaceFormatter(this, impl, true);
    }
}

void StrFormatter::Convert()
{
    SetConverted();
}

StringDataPtr StrFormatter::GetResult() const
{
    return StringDataPtr(Value);
}

UPInt StrFormatter::GetSize() const
{
    return Value.GetSize();
}

// ---- BoolFormatter -------------------------------------------------------------------------------------------------

BoolFormatter::BoolFormatter(MsgFormat& f, bool v) : Formatter(f), Value(v), SwitchStmt(false)
{
}

void BoolFormatter::Parse(const StringDataPtr& str)
{
    StringDataPtr token = str.GetNextToken();
    Formatter*    impl = 0;
    const char*   s = token.ToCStr();

    if (!s || token.IsEmpty())
        return;

    if (s[0] == 's' && s[1] == 'w')
    {
        // "sw:<if true>:<if false>"
        StringDataPtr rest = str.GetTrimLeft(token.GetSize() + 1);
        result = rest.GetNextToken();
        if (!Value)
        {
            rest.TrimLeft(result.GetSize() + 1);
            result = rest.GetNextToken();
        }
        SwitchStmt = true;
    }
    else if (GetParent().GetLocaleProvider())
    {
        FormatterFactory::Args args(GetParent(), token, ResourceFormatter::ValueType(Value));
        impl = GetParent().GetLocaleProvider()->MakeFormatter(args);
    }

    if (impl)
    {
        StringDataPtr implParams = str.GetTrimLeft(token.GetSize() + 1);
        if (!implParams.IsEmpty())
            impl->Parse(implParams);
        GetParent().ReplaceFormatter(this, impl, true);
    }
}

void BoolFormatter::Convert()
{
    if (Converted())
        return;
    if (!SwitchStmt)
        result = (Value ? StringDataPtr("true", 4) : StringDataPtr("false", 5));
    SetConverted();
}

StringDataPtr BoolFormatter::GetResult() const
{
    return result;
}

UPInt BoolFormatter::GetSize() const
{
    return result.GetSize();
}

// ---- NumericBase ---------------------------------------------------------------------------------------------------

// puts a UTF-8 encoded character in front of value_ptr; 0 when it does not fit after buff
char* AppendCharLeft(char* buff, char* value_ptr, UInt32 ucs_char)
{
    if (ucs_char)
    {
        value_ptr -= UTF8Util::GetEncodeCharSize(ucs_char);
        if (buff > value_ptr)
            return 0;
        SPInt index = 0;
        UTF8Util::EncodeChar(value_ptr, &index, ucs_char);
    }
    return value_ptr;
}

NumericBase::NumericBase()
    : Precision(1), Width(1), PrefixChar(' '), SeparatorChar('\0'), ShowSign(false), BigLetters(true),
      BlankPrefix(false), AlignLeft(false), SharpSign(false), ValueStr(0)
{
}

// the printf flag characters, then width[.precision]
void NumericBase::ReadPrintFormat(StringDataPtr token)
{
    if (token.IsEmpty())
        return;
    const char* s = token.ToCStr();
    if (s == 0)
        return;

    switch (*s)
    {
    case '-':
        SetAlignLeft();
        ReadPrintFormat(token.TrimLeft(1));
        break;
    case ' ':
        SetBlankPrefix();
        ReadPrintFormat(token.TrimLeft(1));
        break;
    case '.':
        SetPrecision(0);   // "." alone means precision 0
        SetPrecision(ReadInteger(token.TrimLeft(1), Precision));
        break;
    case '+':
        SetShowSign();
        ReadPrintFormat(token.TrimLeft(1));
        break;
    case '#':
        SetSharpSign();
        ReadPrintFormat(token.TrimLeft(1));
        break;
    case '0':
        SetPrefixChar('0');
        ReadPrintFormat(token.TrimLeft(1));
        break;
    default:
        ReadWidth(token);
    }
}

void NumericBase::ReadWidth(StringDataPtr token)
{
    if (token.IsEmpty())
        return;
    SPInt pos = token.FindChar('.');
    SetWidth(ReadInteger(token, Width));
    if (pos >= 0)
    {
        SetPrecision(0);
        SetPrecision(ReadInteger(token.TrimLeft(1), Precision));
    }
}

// digits are written right to left in front of ValueStr, never before buff; groups of three get SeparatorChar
void NumericBase::ULongLong2String(char* buff, UInt64 value, bool separator, unsigned base)
{
    const char*   chars;
    UInt64        quotient = value;
    unsigned char rem;
    unsigned      sepLeft = (separator && base == 10 && SeparatorChar ? 3 : 1000);

    if (BigLetters)
        chars = "0123456789ABCDEF";
    else
        chars = "0123456789abcdef";

    if (base < 2 || base > 16)
        return;

    do
    {
        if (buff == ValueStr)
            return;
        rem = static_cast<unsigned char>(quotient % base);
        quotient /= base;
        if (!sepLeft)
        {
            sepLeft = 3;
            *--ValueStr = SeparatorChar;
        }
        --sepLeft;
        *--ValueStr = chars[rem];
    } while (quotient != 0);
}

void NumericBase::ULong2String(char* buff, UInt32 value, bool separator, unsigned base)
{
    const char*   chars;
    UInt32        quotient = value;
    unsigned char rem;
    unsigned      sepLeft = (separator && base == 10 && SeparatorChar ? 3 : 1000);

    if (BigLetters)
        chars = "0123456789ABCDEF";
    else
        chars = "0123456789abcdef";

    if (base < 2 || base > 16)
        return;

    do
    {
        if (buff == ValueStr)
            return;
        rem = static_cast<unsigned char>(quotient % base);
        quotient /= base;
        if (!sepLeft)
        {
            sepLeft = 3;
            *--ValueStr = SeparatorChar;
        }
        --sepLeft;
        *--ValueStr = chars[rem];
    } while (quotient != 0);
}

// ---- LongFormatter -------------------------------------------------------------------------------------------------

LongFormatter::LongFormatter(int v) : Base(10), SignedValue(true), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(unsigned int v) : Base(10), SignedValue(false), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(long v) : Base(10), SignedValue(true), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(unsigned long v) : Base(10), SignedValue(false), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(SInt64 v) : Base(10), SignedValue(true), IsLongLong(true), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(UInt64 v) : Base(10), SignedValue(false), IsLongLong(true), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(MsgFormat& f, int v)
    : Formatter(f), Base(10), SignedValue(true), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(MsgFormat& f, unsigned int v)
    : Formatter(f), Base(10), SignedValue(false), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(MsgFormat& f, long v)
    : Formatter(f), Base(10), SignedValue(true), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(MsgFormat& f, unsigned long v)
    : Formatter(f), Base(10), SignedValue(false), IsLongLong(false), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(MsgFormat& f, SInt64 v)
    : Formatter(f), Base(10), SignedValue(true), IsLongLong(true), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

LongFormatter::LongFormatter(MsgFormat& f, UInt64 v)
    : Formatter(f), Base(10), SignedValue(false), IsLongLong(true), Value(v)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
}

// options: printf flags/width, "base:<n>", "o", "x"/"X", "sw:..." (switch), "sep:<c>", or a locale option
void LongFormatter::Parse(const StringDataPtr& str)
{
    StringDataPtr rest = str;
    StringDataPtr token;
    Formatter*    impl = 0;

    while (!rest.IsEmpty())
    {
        token = rest.GetNextToken();
        const char* s = token.ToCStr();
        if (!s || token.IsEmpty())
            return;
        rest.TrimLeft(token.GetSize() + 1);

        if (isdigit(s[0]))
        {
            ReadPrintFormat(token);
            continue;
        }

        switch (s[0])
        {
        case '#':
        case '+':
        case '-':
        case '.':
        case ' ':
            ReadPrintFormat(token);
            break;
        case 'b':
            if (SFstrncmp(s, "base", 4) == 0)
                SetBase(ReadInteger(rest, 10));
            break;
        case 'o':
            SetBase(8);
            ReadPrintFormat(rest.GetNextToken());
            break;
        case 'x':
            SetBigLetters(false);
        case 'X':
            SetBase(16);
            ReadPrintFormat(rest.GetNextToken());
            break;
        case 's':
            if (s[1] == 'w')
            {
                impl = new (GetParent().GetMemoryPool())
                    SwitchFormatter(GetParent(), static_cast<SwitchFormatter::ValueType::Type>(Value));
                rest.TrimLeft(rest.GetSize());
            }
            else if (SFstrncmp(s, "sep", 3) == 0)
            {
                StringDataPtr sep = rest.GetNextToken();
                if (!sep.IsEmpty())
                    SeparatorChar = *sep.ToCStr();
                rest.TrimLeft(sep.GetSize());
            }
            break;
        default:
            if (GetParent().GetLocaleProvider())
            {
                FormatterFactory::Args args(GetParent(), rest, ResourceFormatter::ValueType(static_cast<UPInt>(Value)));
                impl = GetParent().GetLocaleProvider()->MakeFormatter(args);
            }
        }
    }

    if (impl)
    {
        StringDataPtr implParams = str.GetTrimLeft(token.GetSize() + 1);
        if (!implParams.IsEmpty())
            impl->Parse(implParams);
        GetParent().ReplaceFormatter(this, impl, true);
    }
}

void LongFormatter::Convert()
{
    if (Converted())
        return;

    // precision 0 prints nothing for 0
    if (!(Precision == 0 && Value == 0))
    {
        if (IsLongLong)
            ULongLong2String(Buff, Alg::Abs(Value), true, Base);
        else if (SignedValue)
            ULong2String(Buff, Alg::Abs(static_cast<SInt32>(Value)), true, Base);
        else
            ULong2String(Buff, static_cast<UInt32>(Value), true, Base);
    }

    for (UPInt i = GetSizeInternal(); i < Precision; ++i)
        *--ValueStr = '0';

    if (Precision == 0)
        PrefixChar = ' ';

    if (Value < 0)
    {
        // zero padding goes between the sign and the digits
        if (PrefixChar == '0')
        {
            for (UPInt i = GetSizeInternal(); i < static_cast<UPInt>(Width - ((ShowSign || BlankPrefix) ? 1 : 0)); ++i)
                *--ValueStr = PrefixChar;
        }
        AppendSignCharLeft(Value < 0);
    }
    else if (Base == 8 || Base == 16)
    {
        if (Value != 0 && SharpSign)
        {
            if (Base == 16)
                *--ValueStr = (BigLetters ? 'X' : 'x');
            *--ValueStr = '0';
        }
    }

    if (BlankPrefix && !ShowSign)
    {
        PrefixChar = ' ';
        if (SignedValue && Value >= 0)
            *--ValueStr = ' ';
    }

    // the width padding: blanks for decimal, PrefixChar for the other bases
    const UPInt size = GetSizeInternal();
    if (AlignLeft)
    {
        if (size < Width)
        {
            char* p = Buff + sizeof(Buff) - 1 - Width;
            memmove(p, ValueStr, size);
            ValueStr = p;
            p += size;
            for (UPInt i = size; i < Width; ++i)
            {
                if (Base != 10)
                    *p++ = PrefixChar;
                else
                    *p++ = ' ';
            }
        }
    }
    else
    {
        for (UPInt i = size; i < Width; ++i)
        {
            if (Base != 10)
                *--ValueStr = PrefixChar;
            else
                *--ValueStr = ' ';
        }
    }

    SetConverted();
}

StringDataPtr LongFormatter::GetResult() const
{
    return StringDataPtr(ValueStr, GetSize());
}

UPInt LongFormatter::GetSize() const
{
    return GetSizeInternal();
}

void LongFormatter::InitString(char* pbuffer, UPInt size) const
{
    if (Converted())
        memcpy(pbuffer, ValueStr, size);
}

// the locale's sign characters when there is one, ASCII otherwise
void LongFormatter::AppendSignCharLeft(bool negative)
{
    if (HasParent() && GetParent().GetLocaleProvider())
    {
        const Locale& locale = GetParent().GetLocaleProvider()->GetLocale();
        if (negative)
            ValueStr = AppendCharLeft(Buff, ValueStr, locale.GetNegativeSign());
        else if (ShowSign)
            ValueStr = AppendCharLeft(Buff, ValueStr, locale.GetPositiveSign());
    }
    else
    {
        if (negative)
            *--ValueStr = '-';
        else if (ShowSign)
            *--ValueStr = '+';
    }
}

// ---- DoubleFormatter -----------------------------------------------------------------------------------------------

DoubleFormatter::DoubleFormatter(Double v) : Type(FmtDecimal), Value(v), Len(0)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
    SetPrecision(6);
}

DoubleFormatter::DoubleFormatter(MsgFormat& f, Double v) : Formatter(f), Type(FmtDecimal), Value(v), Len(0)
{
    ValueStr = (Buff + sizeof(Buff) - 1);
    Buff[sizeof(Buff) - 1] = '\0';
    SetPrecision(6);
}

// options: printf flags/width, "f", "e"/"E", "g"/"G", "sw:..." (switch on the rounded value), "sep:<c>", or a
// locale option
void DoubleFormatter::Parse(const StringDataPtr& str)
{
    StringDataPtr rest = str;
    StringDataPtr token;
    Formatter*    impl = 0;

    while (!rest.IsEmpty())
    {
        token = rest.GetNextToken();
        const char* s = token.ToCStr();
        if (!s || token.IsEmpty())
            return;
        rest.TrimLeft(token.GetSize() + 1);

        if (isdigit(s[0]))
        {
            ReadPrintFormat(token);
            continue;
        }

        switch (s[0])
        {
        case '-':
        case '+':
        case ' ':
        case '#':
        case '.':
            ReadPrintFormat(token);
            break;
        case 'f':
            Type = FmtDecimal;
            ReadPrintFormat(rest.GetNextToken());
            break;
        case 'e':
            SetBigLetters(false);
        case 'E':
            Type = FmtScientific;
            ReadPrintFormat(rest.GetNextToken());
            break;
        case 'g':
            SetBigLetters(false);
        case 'G':
            Type = FmtSignificant;
            ReadPrintFormat(rest.GetNextToken());
            break;
        case 's':
            if (s[1] == 'w')
            {
                impl = new (GetParent().GetMemoryPool()) SwitchFormatter(GetParent(), Alg::IRound(Value));
                rest.TrimLeft(rest.GetSize());
            }
            else if (SFstrncmp(s, "sep", 3) == 0)
            {
                StringDataPtr sep = rest.GetNextToken();
                if (!sep.IsEmpty())
                    SeparatorChar = *sep.ToCStr();
            }
            break;
        default:
            if (GetParent().GetLocaleProvider())
            {
                FormatterFactory::Args args(GetParent(), rest, ResourceFormatter::ValueType(Alg::IRound(Value)));
                impl = GetParent().GetLocaleProvider()->MakeFormatter(args);
            }
        }
    }

    if (impl)
    {
        StringDataPtr implParams = str.GetTrimLeft(token.GetSize() + 1);
        if (!implParams.IsEmpty())
            impl->Parse(implParams);
        GetParent().ReplaceFormatter(this, impl, true);
    }
}

// builds a printf format from the options ("%%+#- 0%d.%df" -> "%+#- 05.2f") and lets the CRT do the digits
void DoubleFormatter::Convert()
{
    if (Converted())
        return;

    char f = ' ';
    switch (Type)
    {
    case FmtDecimal:
        f = 'f';
        break;
    case FmtScientific:
        f = BigLetters ? 'E' : 'e';
        break;
    case FmtSignificant:
        f = BigLetters ? 'G' : 'g';
        break;
    };

    char  fmt[32];
    char  format[32];
    char* p = fmt;

    *p++ = '%';
    *p++ = '%';
    if (ShowSign)
        *p++ = '+';
    if (SharpSign)
        *p++ = '#';
    if (BlankPrefix)
        *p++ = ' ';
    if (AlignLeft)
        *p++ = '-';
    if (PrefixChar == '0')
        *p++ = PrefixChar;

    if (Width != 1)
    {
        *p++ = '%';
        *p++ = 'd';
        *p++ = '.';
        *p++ = '%';
        *p++ = 'd';
        *p++ = f;
        *p++ = '\0';
        SFsprintf(format, sizeof(format), fmt, Width, Precision);
    }
    else
    {
        *p++ = '.';
        *p++ = '%';
        *p++ = 'd';
        *p++ = f;
        *p++ = '\0';
        SFsprintf(format, sizeof(format), fmt, Precision);
    }

    Len = SFsprintf(Buff, sizeof(Buff), format, Value);

    // a locale decimal comma becomes a point
    for (ValueStr = Buff; *ValueStr != 0; ++ValueStr)
    {
        if (*ValueStr == ',')
        {
            *ValueStr = '.';
            break;
        }
    }

    ValueStr = Buff;
    SetConverted();
}

StringDataPtr DoubleFormatter::GetResult() const
{
    return StringDataPtr(ValueStr, GetSize());
}

UPInt DoubleFormatter::GetSize() const
{
    return Len;
}

void DoubleFormatter::InitString(char* pbuffer, UPInt size) const
{
    if (Converted())
        memcpy(pbuffer, ValueStr, size);
}

void DoubleFormatter::AppendSignCharLeft(bool negative, bool show_sign)
{
    if (HasParent() && GetParent().GetLocaleProvider())
    {
        const Locale& locale = GetParent().GetLocaleProvider()->GetLocale();
        if (negative)
            ValueStr = AppendCharLeft(Buff, ValueStr, locale.GetNegativeSign());
        else if (show_sign)
            ValueStr = AppendCharLeft(Buff, ValueStr, locale.GetPositiveSign());
    }
    else
    {
        if (negative)
            *--ValueStr = '-';
        else if (show_sign)
            *--ValueStr = '+';
    }
}

// ---- ResourceFormatter ---------------------------------------------------------------------------------------------

ResourceFormatter::ValueType::ValueType(UPInt rc) : IsString(false), RC_Provider(0)
{
    Resource.RLong = rc;
}

ResourceFormatter::ValueType::ValueType(UPInt rc, const ResouceProvider& provider)
    : IsString(false), RC_Provider(&provider)
{
    Resource.RLong = rc;
}

ResourceFormatter::ValueType::ValueType(int rc) : IsString(true), RC_Provider(0)
{
    Resource.RStr = reinterpret_cast<const char*>(static_cast<SPInt>(rc));
}

ResourceFormatter::ValueType::ValueType(int rc, const ResouceProvider& provider)
    : IsString(true), RC_Provider(&provider)
{
    Resource.RStr = reinterpret_cast<const char*>(static_cast<SPInt>(rc));
}

ResourceFormatter::ValueType::ValueType(const char* rc) : IsString(true), RC_Provider(0)
{
    Resource.RStr = rc;
}

ResourceFormatter::ValueType::ValueType(const char* rc, const ResouceProvider& provider)
    : IsString(true), RC_Provider(&provider)
{
    Resource.RStr = rc;
}

// without an explicit provider the locale's default one is used
ResourceFormatter::ResourceFormatter(MsgFormat& f, const ResourceFormatter::ValueType& v)
    : Formatter(f), Value(v), pRP(0)
{
    pRP = v.GetResouceProvider();
    if (!pRP && GetParent().GetLocaleProvider())
        pRP = GetParent().GetLocaleProvider()->GetDefaultRCProvider();
}

ResourceFormatter::~ResourceFormatter()
{
}

StringDataPtr ResourceFormatter::MakeString(const TAttrs& attrs) const
{
    if (pRP)
        return pRP->MakeString(Value, attrs);
    return StringDataPtr();
}

void ResourceFormatter::Parse(const StringDataPtr& str)
{
    StringDataPtr implParams;
    StringDataPtr token = str.GetNextToken();
    Formatter*    impl = 0;

    if (GetParent().GetLocaleProvider())
    {
        FormatterFactory::Args args(GetParent(), token, Value);
        impl = GetParent().GetLocaleProvider()->MakeFormatter(args);
    }

    implParams = str.GetTrimLeft(token.GetSize() + 1);
    if (impl)
    {
        if (implParams.GetSize() > 0)
            impl->Parse(implParams);
        GetParent().ReplaceFormatter(static_cast<Formatter*>(this), static_cast<Formatter*>(impl), true);
    }
}

void ResourceFormatter::Convert()
{
    if (!Converted())
    {
        Result = MakeString(TAttrs());
        SetConverted();
    }
}

StringDataPtr ResourceFormatter::GetResult() const
{
    return Result;
}

UPInt ResourceFormatter::GetSize() const
{
    return Result.GetSize();
}

// ---- MsgFormat -----------------------------------------------------------------------------------------------------

enum
{
    NotInitializedFmtrInd = 0xFFFF
};

MsgFormat::MsgFormat(const MsgFormat::Sink& r)
    : EscapeChar('%'), FirstArgNum(0), NonPosParamNum(0), UnboundFmtrInd(NotInitializedFmtrInd), StrSize(0),
      pLocaleProvider(0), Result(r)
{
}

MsgFormat::MsgFormat(const MsgFormat::Sink& r, const LocaleProvider& loc)
    : EscapeChar('%'), FirstArgNum(0), NonPosParamNum(0), UnboundFmtrInd(NotInitializedFmtrInd), StrSize(0),
      pLocaleProvider(&loc), Result(r)
{
}

// the pool formatters are destroyed in place; their memory goes with the pool unless it spilled to the heap
MsgFormat::~MsgFormat()
{
    const UPInt count = Data.GetSize();
    for (UPInt i = 0; i < count; ++i)
    {
        fmt_record& rec = Data[i];
        if (rec.GetType() == eFmtType && rec.GetValue().Formatter.Allocated)
        {
            Formatter* formatter = rec.GetValue().Formatter.Formatter;
            if (formatter)
            {
                formatter->~Formatter();
                operator delete(formatter, GetMemoryPool());
            }
        }
    }
}

void MsgFormat::AddStringRecord(const StringDataPtr& str)
{
    fmt_value value;
    value.String.Str = str.ToCStr();
    value.String.Len = static_cast<unsigned char>(str.GetSize());
    Data.PushBack(fmt_record(eStrType, value));
}

void MsgFormat::AddFormatterRecord(Formatter* f, bool allocated)
{
    fmt_value value;
    value.Formatter.Formatter = f;
    value.Formatter.Allocated = allocated;
    Data.PushBack(fmt_record(eFmtType, value));
}

// Splits fmt into literal and "{...}" parameter records. "{n:opts}" is positional (argument n), "{opts}" takes the next
// non-positional argument; the escape character makes the next character literal.
void MsgFormat::Parse(const char* fmt)
{
    enum { stInitial, stParam } state = stInitial;
    const char* str = fmt;
    const char* str_ptr = fmt;
    UnboundFmtrInd = NotInitializedFmtrInd;
    bool escape = false;

    if (!fmt)
        return;

    NonPosParamNum = 0;

    while (*str)
    {
        switch (state)
        {
        case stInitial:
            if (escape)
            {
                escape = false;
                ++str;
            }
            else if (*str == '{')
            {
                if (str_ptr != str)
                    AddStringRecord(StringDataPtr(str_ptr, str - str_ptr));
                str_ptr = ++str;
                state = stParam;
            }
            else if (*str == GetEscapeChar() && *(str + 1) != 0)
            {
                if (str_ptr != str)
                    AddStringRecord(StringDataPtr(str_ptr, str - str_ptr));
                str_ptr = ++str;
                escape = true;
            }
            else
            {
                ++str;
            }
            break;
        case stParam:
            if (*str == '}')
            {
                if (str_ptr != str)
                {
                    int arg_num = 0xFF;

                    while (isspace(*str_ptr))
                        ++str_ptr;

                    if (isdigit(*str_ptr))
                    {
                        arg_num = atoi(str_ptr);
                        for (; *str_ptr && *str_ptr != ':' && *str_ptr != '}'; ++str_ptr)
                        {
                        }
                        if (*str_ptr && *str_ptr == ':')
                            ++str_ptr;
                    }
                    else
                    {
                        ++NonPosParamNum;
                    }

                    fmt_value value;
                    value.String.Str = str_ptr;
                    value.String.Len = static_cast<unsigned char>(str - str_ptr);
                    value.String.ArgNum = static_cast<unsigned char>(arg_num);
                    Data.PushBack(fmt_record(eParamStrType, value));

                    if (UnboundFmtrInd == NotInitializedFmtrInd)
                        UnboundFmtrInd = static_cast<UInt16>(Data.GetSize() - 1);
                }
                str_ptr = ++str;
                state = stInitial;
            }
            else
            {
                ++str;
            }
        }
    }

    if (state == stInitial)
    {
        if (str_ptr != str)
        {
            fmt_value value;
            value.String.Str = str_ptr;
            value.String.Len = static_cast<unsigned char>(str - str_ptr);
            Data.PushBack(fmt_record(eStrType, value));
        }
    }
}

// printf-style formatting: each conversion becomes a pool formatter with the flag text as its options
void MsgFormat::FormatF(const StringDataPtr& fmt, va_list argList)
{
    enum FieldType { ftNone, ftInt, ftLong, ftDouble, ftString, ftPointer };

    if (fmt.IsEmpty())
        return;

    StringDataPtr cur_fmt = fmt;
    FieldType     fieldType = ftNone;

    while (!cur_fmt.IsEmpty())
    {
        SPInt pos = cur_fmt.FindChar('%');

        if (pos < 0)
        {
            AddStringRecord(cur_fmt);
            break;
        }
        else
        {
            UPInt upos = UPInt(pos);

            if (cur_fmt.GetSize() > upos + 1)
            {
                ++upos;
                const char* str = cur_fmt.ToCStr();

                if (str[upos] != '%')
                {
                    union DataType
                    {
                        int      v_sint;
                        SInt64   v_sint64;
                        unsigned v_uint;
                        UInt64   v_uint64;
                        Double   v_double;
                        char*    v_str;
                    };

                    DataType                          data;
                    unsigned                          base = 10;
                    bool                              bigLetters = false;
                    bool                              unsigned_type = false;
                    DoubleFormatter::PresentationType dpType = DoubleFormatter::FmtDecimal;

                    if (upos > 0)
                        AddStringRecord(cur_fmt.GetTrimRight(cur_fmt.GetSize() - pos));

                    UPInt startPos = upos;
                    data.v_uint = 0;

                    enum prefix_t { prefix_none, prefix_h, prefix_l, prefix_I };
                    prefix_t prefix = prefix_none;
                    unsigned prefix_size = 0;

                    for (; upos < cur_fmt.GetSize(); ++upos)
                    {
                        switch (str[upos])
                        {
                        case 'c':
                            break;
                        case 'C':
                            break;
                        case 'h':
                            prefix = prefix_h;
                            ++prefix_size;
                            break;
                        case 'l':
                            prefix = prefix_l;
                            ++prefix_size;
                            break;
                        case 'I':
                            prefix = prefix_I;
                            ++prefix_size;
                            break;
                        case 's':
                            fieldType = ftString;
                            data.v_str = va_arg(argList, char*);
                            break;
                        case 'S':
                            break;
                        case 'd':
                        case 'i':
                            if (prefix == prefix_l)
                            {
                                fieldType = ftLong;
                                data.v_sint64 = va_arg(argList, int);
                            }
                            else
                            {
                                fieldType = ftInt;
                                data.v_sint = va_arg(argList, int);
                            }
                            break;
                        case 'n':
                            fieldType = ftInt;
                            data.v_sint = *va_arg(argList, int*);
                            break;
                        case 'u':
                            if (prefix == prefix_l)
                            {
                                fieldType = ftLong;
                                unsigned_type = true;
                                data.v_uint = va_arg(argList, unsigned);
                            }
                            else
                            {
                                fieldType = ftInt;
                                unsigned_type = true;
                                data.v_uint = va_arg(argList, unsigned);
                            }
                            break;
                        case 'o':
                            fieldType = ftInt;
                            base = 8;
                            unsigned_type = true;
                            data.v_uint = va_arg(argList, unsigned);
                            break;
                        case 'X':
                            bigLetters = true;
                        case 'x':
                            fieldType = ftInt;
                            unsigned_type = true;
                            data.v_uint = va_arg(argList, unsigned);
                            base = 16;
                            break;
                        case 'p':
                            fieldType = ftInt;
                            unsigned_type = true;
                            data.v_uint = *va_arg(argList, unsigned*);
                            base = 16;
                            break;
                        case 'E':
                            bigLetters = true;
                        case 'e':
                            dpType = DoubleFormatter::FmtScientific;
                            fieldType = ftDouble;
                            data.v_double = va_arg(argList, double);
                            break;
                        case 'G':
                            bigLetters = true;
                        case 'g':
                            dpType = DoubleFormatter::FmtSignificant;
                            fieldType = ftDouble;
                            data.v_double = va_arg(argList, double);
                            break;
                        case 'f':
                            dpType = DoubleFormatter::FmtDecimal;
                            fieldType = ftDouble;
                            data.v_double = va_arg(argList, double);
                            break;
                        default:
                            break;
                        }

                        if (fieldType != ftNone)
                            break;
                    }

                    switch (fieldType)
                    {
                    case ftInt:
                        {
                            LongFormatter* pf = 0;
                            StringDataPtr  attr(cur_fmt.ToCStr() + startPos, upos - startPos - prefix_size);
                            if (unsigned_type)
                                pf = new (GetMemoryPool()) LongFormatter(data.v_uint);
                            else
                                pf = new (GetMemoryPool()) LongFormatter(data.v_sint);
                            pf->SetBase(base);
                            pf->SetBigLetters(bigLetters);
                            pf->Parse(attr);
                            AddFormatterRecord(pf, true);
                        }
                        break;
                    case ftLong:
                        {
                            LongFormatter* pf = 0;
                            StringDataPtr  attr(cur_fmt.ToCStr() + startPos, upos - startPos - prefix_size);
                            if (unsigned_type)
                                pf = new (GetMemoryPool()) LongFormatter(data.v_uint64);
                            else
                                pf = new (GetMemoryPool()) LongFormatter(data.v_sint64);
                            pf->SetBase(base);
                            pf->SetBigLetters(bigLetters);
                            pf->Parse(attr);
                            AddFormatterRecord(pf, true);
                        }
                        break;
                    case ftDouble:
                        {
                            DoubleFormatter* pf = new (GetMemoryPool()) DoubleFormatter(data.v_double);
                            StringDataPtr    attr(cur_fmt.ToCStr() + startPos, upos - startPos);
                            pf->SetBigLetters(bigLetters);
                            pf->SetType(dpType);
                            pf->Parse(attr);
                            AddFormatterRecord(pf, true);
                        }
                        break;
                    case ftString:
                        {
                            StrFormatter* pf = new (GetMemoryPool()) StrFormatter(data.v_str);
                            AddFormatterRecord(pf, true);
                        }
                    case ftPointer:
                        break;
                    case ftNone:
                        break;
                    };
                }
                else
                {
                    // "%%" is a literal '%'
                    AddStringRecord(cur_fmt.GetTrimRight(cur_fmt.GetSize() - pos - 1));
                }
            }
            else
            {
                AddStringRecord(cur_fmt);
            }

            pos = upos;
            cur_fmt.TrimLeft(pos + 1);
        }
    }

    MakeString();
}

bool MsgFormat::ReplaceFormatter(Formatter* oldf, Formatter* newf, bool allocated)
{
    const UPInt count = Data.GetSize();
    for (UPInt i = 0; i < count; ++i)
    {
        fmt_record& rec = Data[i];
        if (rec.GetType() == eFmtType && rec.GetValue().Formatter.Formatter == oldf)
        {
            fmt_value value;
            value.Formatter.Formatter = newf;
            value.Formatter.Allocated = allocated;
            rec = fmt_record(eFmtType, value);
            return true;
        }
    }
    return false;
}

// finds the next parameter record for the current argument number (DataInd); UnboundFmtrInd skips the leading
// records that are already bound
bool MsgFormat::NextFormatter()
{
    bool        shiftUnbound = true;
    const UPInt count = Data.GetSize();

    DataInd = -1;
    for (UPInt i = UnboundFmtrInd; i < count; ++i)
    {
        const fmt_record& rec = Data[i];
        if (rec.GetType() == eParamStrType)
        {
            str_ptr sp = rec.GetValue().String;
            if (sp.ArgNum == GetFirstArgNum())
            {
                if (shiftUnbound)
                    ++UnboundFmtrInd;
                DataInd = i;
                return true;
            }
            else if (shiftUnbound)
            {
                shiftUnbound = false;
            }
        }
        else if (shiftUnbound)
        {
            ++UnboundFmtrInd;
        }
    }
    return false;
}

void MsgFormat::Bind(Formatter* formatter, const bool allocated)
{
    const fmt_record& rec = Data[DataInd];
    str_ptr           sp = rec.GetValue().String;
    fmt_value         value;

    value.Formatter.Formatter = formatter;
    value.Formatter.Allocated = allocated;
    Data[DataInd] = fmt_record(eFmtType, value);

    if (sp.Len > 0)
        formatter->Parse(StringDataPtr(sp.Str, sp.Len));
}

// the non-positional parameters are bound one per level of recursion to a stack ResourceFormatter (resource 0), so
// the string is made while they are all alive
void MsgFormat::BindNonPos()
{
    FmtInfo<ResourceFormatter::ValueType>::formatter fr(*this, ResourceFormatter::ValueType(0));

    if (NextFormatter())
        Bind(&fr, false);

    if (--NonPosParamNum)
        BindNonPos();
    else
        MakeString();
}

// Converts formatter record ind after giving it what it asked for: the nearest non-blank text before it (rtPrevStrSS
// stops at a formatter that wants the next text), the text after it, or another formatter.
void MsgFormat::Evaluate(UPInt ind)
{
    if (Data[ind].GetType() != eFmtType)
        return;

    Formatter&                formatter = *Data[ind].GetValue().Formatter.Formatter;
    Formatter::requirements_t req = formatter.GetRequirements();

    if (req == Formatter::rtNone)
    {
        if (!formatter.Converted())
            formatter.Convert();
        return;
    }

    if (req & Formatter::rtPrevStrSS)
    {
        UPInt       prev_ind = ind - 1;
        const UPInt overflow = 0U - 1;
        bool        found = false;

        for (; prev_ind != overflow && !found; --prev_ind)
        {
            switch (Data[prev_ind].GetType())
            {
            case eStrType:
                {
                    const str_ptr& sp = Data[prev_ind].GetValue().String;
                    StringDataPtr  str(sp.Str, sp.Len);
                    if (IsSpace(str))
                        break;
                    formatter.SetPrevStr(str);
                }
                found = true;
                break;
            case eFmtType:
                {
                    const Formatter& other = *Data[prev_ind].GetValue().Formatter.Formatter;
                    if (other.GetRequirements() & Formatter::rtNextStr)
                    {
                        formatter.SetPrevStr(StringDataPtr("stub"));
                        found = true;
                        break;
                    }
                    if ((other.GetRequirements() & Formatter::rtParent) && other.GetParentRef() == Formatter::prNext)
                    {
                        formatter.SetPrevStr(StringDataPtr("stub"));
                        found = true;
                        break;
                    }
                    Evaluate(prev_ind);
                    if (IsSpace(other.GetResult()))
                        break;
                    formatter.SetPrevStr(other.GetResult());
                }
                found = true;
                break;
            default:
                break;
            };
        }

        if (!found)
            formatter.SetPrevStr(StringDataPtr());
    }

    if (req & Formatter::rtPrevStr)
    {
        UPInt       prev_ind = ind - 1;
        const UPInt overflow = 0U - 1;
        bool        found = false;

        for (; prev_ind != overflow && !found; --prev_ind)
        {
            switch (Data[prev_ind].GetType())
            {
            case eStrType:
                {
                    const str_ptr& sp = Data[prev_ind].GetValue().String;
                    StringDataPtr  str(sp.Str, sp.Len);
                    if (IsSpace(str))
                        break;
                    formatter.SetPrevStr(str);
                }
                found = true;
                break;
            case eFmtType:
                {
                    const Formatter& other = *Data[prev_ind].GetValue().Formatter.Formatter;
                    if (other.GetRequirements() & Formatter::rtNextStr)
                    {
                        // a cycle; only the query is left in the release build
                    }
                    Evaluate(prev_ind);
                    if (IsSpace(other.GetResult()))
                        break;
                    formatter.SetPrevStr(other.GetResult());
                }
                found = true;
                break;
            default:
                break;
            };
        }

        if (!found)
            formatter.SetPrevStr(StringDataPtr());
    }

    if (req & Formatter::rtNextStr)
    {
        UPInt       next_ind = ind + 1;
        bool        found = false;
        const UPInt count = Data.GetSize();

        for (; next_ind < count && !found; ++next_ind)
        {
            switch (Data[next_ind].GetType())
            {
            case eStrType:
                {
                    const str_ptr& sp = Data[next_ind].GetValue().String;
                    StringDataPtr  str(sp.Str, sp.Len);
                    if (IsSpace(str))
                        break;
                    formatter.SetNextStr(str);
                }
                found = true;
                break;
            case eFmtType:
                {
                    const Formatter& other = *Data[next_ind].GetValue().Formatter.Formatter;
                    if (other.GetRequirements() & Formatter::rtPrevStr)
                    {
                        // a cycle; only the query is left in the release build
                    }
                    Evaluate(next_ind);
                    if (IsSpace(other.GetResult()))
                        break;
                    formatter.SetNextStr(other.GetResult());
                }
                found = true;
                break;
            default:
                break;
            };
        }

        if (!found)
            formatter.SetNextStr(StringDataPtr());
    }

    if (req & Formatter::rtParent)
    {
        UPInt       parent_ind = ind;
        const UPInt overflow = 0U - 1;
        bool        found = false;

        switch (formatter.GetParentRef())
        {
        case Formatter::prPrev:
            for (--parent_ind; parent_ind != overflow && !found; --parent_ind)
            {
                if (Data[parent_ind].GetType() == eFmtType)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                const Formatter& parent = *Data[parent_ind].GetValue().Formatter.Formatter;
                if (parent.GetRequirements() & Formatter::rtNextStr)
                {
                }
                Evaluate(parent_ind);
                formatter.SetParent(parent);
            }
            break;
        case Formatter::prNext:
            for (++parent_ind; parent_ind < Data.GetSize() && !found; ++parent_ind)
            {
                if (Data[parent_ind].GetType() == eFmtType)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                Formatter& parent = *Data[parent_ind].GetValue().Formatter.Formatter;
                if (parent.GetRequirements() & Formatter::rtPrevStr)
                {
                }
                Evaluate(parent_ind);
                formatter.SetParent(parent);
            }
            break;
        case Formatter::prPos:
            {
                const unsigned char wanted = formatter.GetParentPos();
                unsigned char       cur = 0;
                const UPInt         count = Data.GetSize();

                for (parent_ind = 0; parent_ind < count && !found; ++parent_ind)
                {
                    if (Data[parent_ind].GetType() == eFmtType)
                    {
                        if (cur == wanted)
                        {
                            found = true;
                            break;
                        }
                        else
                            ++cur;
                    }
                }
                if (found)
                {
                    Formatter& parent = *Data[parent_ind].GetValue().Formatter.Formatter;
                    Evaluate(parent_ind);
                    formatter.SetParent(parent);
                }
            }
            break;
        case Formatter::prNone:
            break;
        };
    }

    if (!formatter.Converted())
        formatter.Convert();
}

// converts everything, sums the size and writes the text to the sink
void MsgFormat::MakeString()
{
    StrSize = 0;
    const UPInt count = Data.GetSize();

    for (UPInt i = 0; i < count; ++i)
    {
        const fmt_value& value = Data[i].GetValue();
        switch (Data[i].GetType())
        {
        case eStrType:
            StrSize += value.String.Len;
            break;
        case eFmtType:
            {
                Evaluate(i);
                const Formatter* const fr = value.Formatter.Formatter;
                if (fr)
                    StrSize += fr->GetSize();
            }
            break;
        case eParamStrType:
            break;
        default:
            break;
        }
    }

    switch (Result.Type)
    {
    case Sink::tStr:
        Result.SinkData.pStr->AssignString(*this, GetStrSize());
        break;
    case Sink::tStrBuffer:
        {
            StringBuffer& buffer = *Result.SinkData.pStrBuffer;
            const UPInt   n = Data.GetSize();

            buffer.Reserve(buffer.GetSize() + GetStrSize());
            for (UPInt i = 0; i < n; ++i)
            {
                const fmt_value& value = Data[i].GetValue();
                switch (Data[i].GetType())
                {
                case eStrType:
                    buffer.AppendString(value.String.Str, value.String.Len);
                    break;
                case eFmtType:
                    {
                        const Formatter* const fr = value.Formatter.Formatter;
                        if (fr)
                        {
                            StringDataPtr r = fr->GetResult();
                            buffer.AppendString(r.ToCStr(), r.GetSize());
                        }
                    }
                    break;
                default:
                    break;
                }
            }
        }
        break;
    case Sink::tDataPtr:
        {
            const Sink::StrDataType& str = Result.SinkData.DataPtr;
            char*                    s = const_cast<char*>(str.pStr);
            InitString(s, str.Size);
            const UPInt size = Alg::Min(str.Size - 1, GetStrSize());
            s[size] = '\0';
        }
    };
}

// copies the text into pbuffer, at most size bytes, no terminator
void MsgFormat::InitString(char* pbuffer, UPInt size) const
{
    UPInt       left = size;
    UPInt       n = 0;
    const UPInt count = Data.GetSize();

    for (UPInt i = 0; left != 0 && i < count; ++i)
    {
        const fmt_value& value = Data[i].GetValue();
        switch (Data[i].GetType())
        {
        case eStrType:
            n = Alg::Min(left, UPInt(value.String.Len));
            memcpy(pbuffer, value.String.Str, n);
            left -= n;
            pbuffer += n;
            break;
        case eFmtType:
            {
                const Formatter* const fr = value.Formatter.Formatter;
                if (fr)
                {
                    StringDataPtr r = fr->GetResult();
                    n = Alg::Min(left, r.GetSize());
                    memcpy(pbuffer, r.ToCStr(), n);
                    left -= n;
                    pbuffer += n;
                }
            }
            break;
        default:
            break;
        }
    }
}

// true when s is empty or only Unicode white space
bool IsSpace(StringDataPtr s)
{
    UInt32      c = 0;
    const char* p = s.ToCStr();
    const char* end = p + s.GetSize();

    if (p != end)
    {
        do
        {
            c = UTF8Util::DecodeNextChar(&p);
            if (c == 0 || !SFiswspace(static_cast<wchar_t>(c)))
                return false;
        } while (p < end);
    }
    return true;
}

UPInt SPrintF(const MsgFormat::Sink& result, const char* fmt, ...)
{
    MsgFormat parsed(result);
    va_list   argList;
    va_start(argList, fmt);
    parsed.FormatF(StringDataPtr(fmt), argList);
    va_end(argList);
    return parsed.GetStrSize();
}

int ReadInteger(StringDataPtr& str, int defaultValue, char separator)
{
    StringDataPtr token = str.GetNextToken(separator);
    const char*   s = token.ToCStr();

    if (!token.IsEmpty() && s && isdigit(s[0]))
    {
        UPInt i = 1;
        for (; i < token.GetSize() && isdigit(s[i]); ++i)
        {
        }
        str.TrimLeft(i);
        return atoi(s);
    }
    return defaultValue;
}

void MsgFormat::FinishFormatD()
{
    if (NonPosParamNum)
    {
        SetFirstArgNum(0xFF);
        BindNonPos();
    }
    else
    {
        MakeString();
    }
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??$add@UNodeRef@?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@@?$HashSetBase@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@H$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAXAEBUNodeRef@?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@1@_K@Z 0x1425ae810
// MS2-PIN: ??0BoolFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@_N@Z 0x1425ae9b0
// MS2-PIN: ??0DoubleFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@N@Z 0x1425ae9e0
// MS2-PIN: ??0DoubleFormatter@Scaleform@@QEAA@N@Z 0x1425aea50
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@H@Z 0x1425aeac0
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@I@Z 0x1425aeb40
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@J@Z 0x1425aebc0
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@K@Z 0x1425aec40
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@_K@Z 0x1425aed30
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@H@Z 0x1425aedb0
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@I@Z 0x1425aee30
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@J@Z 0x1425aeeb0
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@K@Z 0x1425aef30
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@_J@Z 0x1425aefb0
// MS2-PIN: ??0LongFormatter@Scaleform@@QEAA@_K@Z 0x1425af020
// MS2-PIN: ??0MsgFormat@Scaleform@@QEAA@AEBVSink@01@@Z 0x1425af0a0
// MS2-PIN: ??0ResourceFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@AEBVValueType@01@@Z 0x1425af1f0
// MS2-PIN: ??0StrFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@AEBVString@1@@Z 0x1425af260
// MS2-PIN: ??0StrFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@AEBVStringDataPtr@1@@Z 0x1425af2a0
// MS2-PIN: ??0StrFormatter@Scaleform@@QEAA@AEAVMsgFormat@1@PEBD@Z 0x1425af2d0
// MS2-PIN: ??1?$HashSetBase@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@H$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAA@XZ 0x1425af4b0
// MS2-PIN: ??1Formatter@Scaleform@@UEAA@XZ 0x1425af520
// MS2-PIN: ??1MsgFormat@Scaleform@@UEAA@XZ 0x1425af530
// MS2-PIN: ??_GBoolFormatter@Scaleform@@UEAAPEAXI@Z 0x1425af640
// MS2-PIN: ??_GDoubleFormatter@Scaleform@@UEAAPEAXI@Z 0x1425af670
// MS2-PIN: ??_GFmtResource@Scaleform@@UEAAPEAXI@Z 0x1425af6b0
// MS2-PIN: ??_GFormatter@Scaleform@@UEAAPEAXI@Z 0x1425af6e0
// MS2-PIN: ??_GLongFormatter@Scaleform@@UEAAPEAXI@Z 0x1425af710
// MS2-PIN: ??_GMsgFormat@Scaleform@@UEAAPEAXI@Z 0x1425af750
// MS2-PIN: ??_GResourceFormatter@Scaleform@@UEAAPEAXI@Z 0x1425af790
// MS2-PIN: ??_GStrFormatter@Scaleform@@UEAAPEAXI@Z 0x1425af7c0
// MS2-PIN: ??_GSwitchFormatter@Scaleform@@UEAAPEAXI@Z 0x1425af7f0
// MS2-PIN: ?AddFormatterRecord@MsgFormat@Scaleform@@AEAAXPEAVFormatter@2@_N@Z 0x1425af840
// MS2-PIN: ?AddStringRecord@MsgFormat@Scaleform@@AEAAXAEBVStringDataPtr@2@@Z 0x1425af880
// MS2-PIN: ?AppendCharLeft@Scaleform@@YAPEADPEAD0K@Z 0x1425af8c0
// MS2-PIN: ?AppendSignCharLeft@DoubleFormatter@Scaleform@@AEAAX_N0@Z 0x1425af930
// MS2-PIN: ?AppendSignCharLeft@LongFormatter@Scaleform@@AEAAX_N@Z 0x1425afa00
// MS2-PIN: ?Bind@MsgFormat@Scaleform@@AEAAXPEAVFormatter@2@_N@Z 0x1425afab0
// MS2-PIN: ?BindNonPos@MsgFormat@Scaleform@@AEAAXXZ 0x1425afb70
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@H$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1425afd40
// MS2-PIN: ?Convert@BoolFormatter@Scaleform@@UEAAXXZ 0x1425afd90
// MS2-PIN: ?Convert@DoubleFormatter@Scaleform@@UEAAXXZ 0x1425afe00
// MS2-PIN: ?Convert@LongFormatter@Scaleform@@UEAAXXZ 0x1425affb0
// MS2-PIN: ?Convert@ResourceFormatter@Scaleform@@UEAAXXZ 0x1425b0370
// MS2-PIN: ?Evaluate@MsgFormat@Scaleform@@AEAAX_K@Z 0x1425b04e0
// MS2-PIN: ?FinishFormatD@MsgFormat@Scaleform@@QEAAXXZ 0x1425b0bd0
// MS2-PIN: ?FormatF@MsgFormat@Scaleform@@QEAAXAEBVStringDataPtr@2@PEAD@Z 0x1425b0bf0
// MS2-PIN: ?GetResult@DoubleFormatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b1460
// MS2-PIN: ?GetResult@LongFormatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b1490
// MS2-PIN: ?GetSize@DoubleFormatter@Scaleform@@UEBA_KXZ 0x1425b1530
// MS2-PIN: ?GetSize@LongFormatter@Scaleform@@UEBA_KXZ 0x1425b1540
// MS2-PIN: ?InitString@LongFormatter@Scaleform@@UEBAXPEAD_K@Z 0x1425b15a0
// MS2-PIN: ?InitString@MsgFormat@Scaleform@@EEBAXPEAD_K@Z 0x1425b15c0
// MS2-PIN: ?IsSpace@Scaleform@@YA_NVStringDataPtr@1@@Z 0x1425b16c0
// MS2-PIN: ?MakeString@MsgFormat@Scaleform@@AEAAXXZ 0x1425b1750
// MS2-PIN: ?MakeString@ResourceFormatter@Scaleform@@AEBA?AVStringDataPtr@2@AEBUTAttrs@FmtResource@2@@Z 0x1425b1920
// MS2-PIN: ?NextFormatter@MsgFormat@Scaleform@@AEAA_NXZ 0x1425b1960
// MS2-PIN: ?Parse@BoolFormatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b19f0
// MS2-PIN: ?Parse@DoubleFormatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b1b70
// MS2-PIN: ?Parse@LongFormatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b1eb0
// MS2-PIN: ?Parse@MsgFormat@Scaleform@@QEAAXPEBD@Z 0x1425b2210
// MS2-PIN: ?Parse@ResourceFormatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b24c0
// MS2-PIN: ?Parse@StrFormatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b2590
// MS2-PIN: ?Parse@SwitchFormatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b2650
// MS2-PIN: ?PushBack@?$StackArray@Vfmt_record@MsgFormat@Scaleform@@$0BA@V?$ArrayPOD@Vfmt_record@MsgFormat@Scaleform@@$01UArrayDefaultPolicy@3@@3@@MsgFormat@Scaleform@@QEAAXAEBVfmt_record@23@@Z 0x1425b27a0
// MS2-PIN: ?ReadInteger@Scaleform@@YAHAEAVStringDataPtr@1@HD@Z 0x1425b2860
// MS2-PIN: ?ReadPrintFormat@NumericBase@Scaleform@@IEAAXVStringDataPtr@2@@Z 0x1425b2910
// MS2-PIN: ?ReadWidth@NumericBase@Scaleform@@IEAAXVStringDataPtr@2@@Z 0x1425b2ad0
// MS2-PIN: ?ReplaceFormatter@MsgFormat@Scaleform@@QEAA_NPEAVFormatter@2@0_N@Z 0x1425b2ba0
// MS2-PIN: ?Reserve@?$ArrayDataBase@Vfmt_record@MsgFormat@Scaleform@@U?$AllocatorGH_POD@Vfmt_record@MsgFormat@Scaleform@@$01@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x1425b2c30
// MS2-PIN: ?SPrintF@Scaleform@@YA_KAEBVSink@MsgFormat@1@PEBDZZ 0x1425b2cd0
// MS2-PIN: ?ULong2String@NumericBase@Scaleform@@IEAAXPEADK_NI@Z 0x1425b2e40
// MS2-PIN: ?ULongLong2String@NumericBase@Scaleform@@IEAAXPEAD_K_NI@Z 0x1425b2ef0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@H$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@HVStringDataPtr@Scaleform@@V?$FixedSizeHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425b2fb0
// MS2-PIN: ??1ResourceFormatter@Scaleform@@UEAA@XZ 0x1425af610
// MS2-PIN: ??_EDoubleFormatter@Scaleform@@WBI@EAAPEAXI@Z 0x1425af61c
// MS2-PIN: ??_ELongFormatter@Scaleform@@WBI@EAAPEAXI@Z 0x1425af628
// MS2-PIN: ?Reflect@FmtResource@Scaleform@@UEBAIAEAPEBUTAttrs@12@@Z 0x1425b2b90
// MS2-PIN: ?Parse@Formatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b1ea0
// MS2-PIN: ?GetRequirements@Formatter@Scaleform@@UEBAEXZ 0x1425b1430
// MS2-PIN: ?SetPrevStr@Formatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b2e30
// MS2-PIN: ?GetPrevStr@Formatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b1420
// MS2-PIN: ?SetNextStr@Formatter@Scaleform@@UEAAXAEBVStringDataPtr@2@@Z 0x1425b2df0
// MS2-PIN: ?GetNextStr@Formatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b13f0
// MS2-PIN: ?GetParentRef@Formatter@Scaleform@@UEBA?AW4ParentRef@12@XZ 0x1425b1410
// MS2-PIN: ?GetParentPos@Formatter@Scaleform@@UEBAEXZ 0x1425b1400
// MS2-PIN: ?SetParent@Formatter@Scaleform@@UEAAXAEBVFmtResource@2@@Z 0x1425b2e00
// MS2-PIN: ?SetParentRef@Formatter@Scaleform@@MEAAXW4ParentRef@12@@Z 0x1425b2e20
// MS2-PIN: ?SetParentPos@Formatter@Scaleform@@MEAAXE@Z 0x1425b2e10
// MS2-PIN: ?Convert@StrFormatter@Scaleform@@UEAAXXZ 0x1425b03e0
// MS2-PIN: ?GetResult@StrFormatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b14e0
// MS2-PIN: ?GetSize@StrFormatter@Scaleform@@UEBA_KXZ 0x1425b1560
// MS2-PIN: ?GetResult@BoolFormatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b1440
// MS2-PIN: ?GetSize@BoolFormatter@Scaleform@@UEBA_KXZ 0x1425b1520
// MS2-PIN: ?GetResult@ResourceFormatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b14c0
// MS2-PIN: ?GetSize@ResourceFormatter@Scaleform@@UEBA_KXZ 0x1425b1550
// MS2-PIN: ?Convert@SwitchFormatter@Scaleform@@UEAAXXZ 0x1425b03f0
// MS2-PIN: ?GetResult@SwitchFormatter@Scaleform@@UEBA?AVStringDataPtr@2@XZ 0x1425b1500
// MS2-PIN: ?GetSize@SwitchFormatter@Scaleform@@UEBA_KXZ 0x1425b1570
// MS2-PIN: ?InitString@DoubleFormatter@Scaleform@@UEBAXPEAD_K@Z 0x1425b1580
// MS2-PIN: ??_7FmtResource@Scaleform@@6B@ 0x1431893f0
// MS2-PIN: ??_7Formatter@Scaleform@@6B@ 0x143189400
// MS2-PIN: ??_7StrFormatter@Scaleform@@6B@ 0x143189480
// MS2-PIN: ??_7BoolFormatter@Scaleform@@6B@ 0x143189500
// MS2-PIN: ??_7LongFormatter@Scaleform@@6BFormatter@1@@ 0x143189580
// MS2-PIN: ??_7LongFormatter@Scaleform@@6BInitStruct@String@1@@ 0x143189600
// MS2-PIN: ??_7DoubleFormatter@Scaleform@@6BFormatter@1@@ 0x143189610
// MS2-PIN: ??_7DoubleFormatter@Scaleform@@6BInitStruct@String@1@@ 0x143189690
// MS2-PIN: ??_7ResourceFormatter@Scaleform@@6B@ 0x1431896a0
// MS2-PIN: ??_7MsgFormat@Scaleform@@6B@ 0x143189720
// MS2-PIN: ??_7SwitchFormatter@Scaleform@@6B@ 0x143189730
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
