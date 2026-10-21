// Recovered Scaleform GFx 4.1.18: MsgFormat, the "{n:options}" / printf-style message formatter of the Kernel
// (SF_MsgFormat, exe 0x1425ae810..0x1425b3380). A format string is split into records (literal text, parameter text,
// bound formatters); each argument is wrapped in a Formatter allocated from the MsgFormat's own stack pool, and the
// result goes to a Sink (String, StringBuffer or a fixed char buffer).
// Layouts from the exe: Formatter 0x18, LongFormatter 0x60, DoubleFormatter 0x1a8, MsgFormat 0x3f8. The include/kernel
// copy used by sfr_gfx_02 describes the same LongFormatter.
#ifndef MS2_SF_KERNEL_MSGFORMAT_H
#define MS2_SF_KERNEL_MSGFORMAT_H

#include <stdarg.h>
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_hash.h"
#include "ms2/scaleform/kernel/sf_locale.h"
#include "ms2/scaleform/kernel/sf_stackmempool.h"

namespace Scaleform {

template<typename T> struct FmtInfo;
class MsgFormat;

// anything that can describe itself through numeric attributes (plural forms etc.)
class FmtResource
{
public:
    virtual ~FmtResource() { }

    struct TAttrs
    {
        TAttrs() : Num(0), Attrs(0) { }
        unsigned Num;
        UPInt*   Attrs;
    };

    virtual unsigned Reflect(const TAttrs*& attrs) const;
};

// One argument converter. A formatter may ask for its neighbours' text or for another formatter (GetRequirements) before
// it is converted.
class Formatter : public FmtResource
{
public:
    enum requirement_t
    {
        rtNone      = 0,
        rtPrevStr   = 1,
        rtPrevStrSS = 2,   // previous text across a sentence separator
        rtNextStr   = 4,
        rtParent    = 8
    };
    typedef UInt8 requirements_t;

    enum ParentRef { prNone, prPrev, prNext, prPos };

    Formatter() : pParentFmt(0), IsConverted(false) { }
    Formatter(MsgFormat& f) : pParentFmt(&f), IsConverted(false) { }
    virtual ~Formatter();

    virtual void           Parse(const StringDataPtr& str);
    virtual void           Convert() = 0;
    virtual StringDataPtr  GetResult() const = 0;
    virtual UPInt          GetSize() const = 0;
    virtual requirements_t GetRequirements() const;

    bool Converted() const { return IsConverted; }

    virtual void          SetPrevStr(const StringDataPtr& ptr);
    virtual StringDataPtr GetPrevStr() const;
    virtual void          SetNextStr(const StringDataPtr& ptr);
    virtual StringDataPtr GetNextStr() const;
    virtual ParentRef     GetParentRef() const;
    virtual unsigned char GetParentPos() const;
    virtual void          SetParent(const FmtResource&);

protected:
    bool             HasParent() const { return pParentFmt != 0; }
    MsgFormat&       GetParent() { return *pParentFmt; }
    const MsgFormat& GetParent() const { return *pParentFmt; }

    virtual void SetParentRef(ParentRef);
    virtual void SetParentPos(unsigned char);

    void SetConverted(bool value = true) { IsConverted = value; }

private:
    Formatter& operator=(const Formatter&);

    MsgFormat* pParentFmt;    // +0x08
    bool       IsConverted;   // +0x10
};

// a string argument; a named option is handed to the locale's formatter factory
class StrFormatter : public Formatter
{
public:
    StrFormatter(const char* v);
    StrFormatter(const StringDataPtr& v);
    StrFormatter(const String& v);
    StrFormatter(MsgFormat& f, const char* v);
    StrFormatter(MsgFormat& f, const StringDataPtr& v);
    StrFormatter(MsgFormat& f, const String& v);

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;

private:
    StrFormatter& operator=(const StrFormatter&);

    const StringDataPtr Value;
};

template<> struct FmtInfo<const char*>          { typedef StrFormatter formatter; };
template<> struct FmtInfo<char*>                { typedef StrFormatter formatter; };
template<> struct FmtInfo<const unsigned char*> { typedef StrFormatter formatter; };
template<> struct FmtInfo<unsigned char*>       { typedef StrFormatter formatter; };
template<> struct FmtInfo<const signed char*>   { typedef StrFormatter formatter; };
template<> struct FmtInfo<signed char*>         { typedef StrFormatter formatter; };
template<int N> struct FmtInfo<const char[N]>          { typedef StrFormatter formatter; };
template<int N> struct FmtInfo<char[N]>                { typedef StrFormatter formatter; };
template<int N> struct FmtInfo<const unsigned char[N]> { typedef StrFormatter formatter; };
template<int N> struct FmtInfo<unsigned char[N]>       { typedef StrFormatter formatter; };
template<int N> struct FmtInfo<const signed char[N]>   { typedef StrFormatter formatter; };
template<int N> struct FmtInfo<signed char[N]>         { typedef StrFormatter formatter; };
template<> struct FmtInfo<const StringDataPtr> { typedef StrFormatter formatter; };
template<> struct FmtInfo<StringDataPtr>       { typedef StrFormatter formatter; };
template<> struct FmtInfo<const String>        { typedef StrFormatter formatter; };
template<> struct FmtInfo<String>              { typedef StrFormatter formatter; };
template<> struct FmtInfo<const StringLH>      { typedef StrFormatter formatter; };
template<> struct FmtInfo<StringLH>            { typedef StrFormatter formatter; };
template<> struct FmtInfo<const StringDH>      { typedef StrFormatter formatter; };
template<> struct FmtInfo<StringDH>            { typedef StrFormatter formatter; };

// "true"/"false", or "sw:<if true>:<if false>"
class BoolFormatter : public Formatter
{
public:
    BoolFormatter(MsgFormat& f, bool v);

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;

private:
    BoolFormatter& operator=(const BoolFormatter&);

    bool          Value:1;
    bool          SwitchStmt:1;
    StringDataPtr result;
};

template<> struct FmtInfo<bool> { typedef BoolFormatter formatter; };

// printf-like options shared by the number formatters. The digits are written backwards from the end of the
// formatter's buffer; ValueStr is the current start.
class NumericBase
{
public:
    NumericBase();

    char* ToCStr() const { return ValueStr; }

    void SetPrecision(unsigned prec = 1) { Precision = prec; }
    void SetWidth(unsigned width = 1) { Width = width; }
    void SetShowSign(bool flag = true) { ShowSign = flag; }
    void SetPrefixChar(char prefix = ' ') { PrefixChar = prefix; }
    void SetSeparatorChar(char sep = ',') { SeparatorChar = sep; }
    void SetBigLetters(bool flag = true) { BigLetters = flag; }
    void SetBlankPrefix(bool flag = true) { BlankPrefix = flag; }
    void SetAlignLeft(bool flag = true) { AlignLeft = flag; }
    void SetSharpSign(bool flag = true) { SharpSign = flag; }

protected:
    void ReadPrintFormat(StringDataPtr token);
    void ReadWidth(StringDataPtr token);
    void ULongLong2String(char* buff, UInt64 value, bool separator, unsigned base = 10);
    void ULong2String(char* buff, UInt32 value, bool separator, unsigned base = 10);

    unsigned Precision:5;       // +0 bits 0-4
    unsigned Width:5;           // +0 bits 5-9
    char     PrefixChar:7;      // +4
    char     SeparatorChar:7;   // +5 bits 0-6
    bool     ShowSign:1;        // +5 bit 7 (MSVC packs same-size bit fields)
    bool     BigLetters:1;      // +6 bit 0
    bool     BlankPrefix:1;
    bool     AlignLeft:1;
    bool     SharpSign:1;
    char*    ValueStr;          // +8
};

class LongFormatter : public Formatter, public NumericBase, public String::InitStruct
{
public:
    LongFormatter(int v);
    LongFormatter(unsigned int v);
    LongFormatter(long v);
    LongFormatter(unsigned long v);
    LongFormatter(SInt64 v);
    LongFormatter(UInt64 v);
    LongFormatter(MsgFormat& f, int v);
    LongFormatter(MsgFormat& f, unsigned int v);
    LongFormatter(MsgFormat& f, long v);
    LongFormatter(MsgFormat& f, unsigned long v);
    LongFormatter(MsgFormat& f, SInt64 v);
    LongFormatter(MsgFormat& f, UInt64 v);

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;
    virtual void          InitString(char* pbuffer, UPInt size) const;

    LongFormatter& SetPrecision(unsigned prec = 1) { NumericBase::SetPrecision(prec); return *this; }
    LongFormatter& SetWidth(unsigned width = 1) { NumericBase::SetWidth(width); return *this; }
    LongFormatter& SetShowSign(bool flag = true) { NumericBase::SetShowSign(flag); return *this; }
    LongFormatter& SetBase(unsigned base) { Base = base; return *this; }
    LongFormatter& SetPrefixChar(char prefix = ' ') { NumericBase::SetPrefixChar(prefix); return *this; }
    LongFormatter& SetSeparatorChar(char sep = ',') { NumericBase::SetSeparatorChar(sep); return *this; }
    LongFormatter& SetBigLetters(bool flag = true) { NumericBase::SetBigLetters(flag); return *this; }

private:
    void           AppendSignCharLeft(bool negative);
    LongFormatter& operator=(const LongFormatter&);
    UPInt          GetSizeInternal() const { return Buff + sizeof(Buff) - 1 - ValueStr; }

    unsigned     Base:5;           // +0x30
    const bool   SignedValue:1;    // +0x34
    bool         IsLongLong:1;
    const SInt64 Value;            // +0x38
    char         Buff[29];         // +0x40, 64-bit value with separators
};

template<> struct FmtInfo<char>               { typedef LongFormatter formatter; };
template<> struct FmtInfo<unsigned char>      { typedef LongFormatter formatter; };
template<> struct FmtInfo<signed char>        { typedef LongFormatter formatter; };
template<> struct FmtInfo<short>              { typedef LongFormatter formatter; };
template<> struct FmtInfo<unsigned short>     { typedef LongFormatter formatter; };
template<> struct FmtInfo<int>                { typedef LongFormatter formatter; };
template<> struct FmtInfo<unsigned int>       { typedef LongFormatter formatter; };
template<> struct FmtInfo<long>               { typedef LongFormatter formatter; };
template<> struct FmtInfo<unsigned long>      { typedef LongFormatter formatter; };
template<> struct FmtInfo<SInt64>             { typedef LongFormatter formatter; };
template<> struct FmtInfo<UInt64>             { typedef LongFormatter formatter; };

// floating point through the CRT sprintf
class DoubleFormatter : public Formatter, public NumericBase, public String::InitStruct
{
public:
    enum PresentationType { FmtDecimal, FmtScientific, FmtSignificant };

    DoubleFormatter(Double v);
    DoubleFormatter(MsgFormat& f, Double v);

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;
    virtual void          InitString(char* pbuffer, UPInt size) const;

    DoubleFormatter& SetType(PresentationType ptype) { Type = ptype; return *this; }
    DoubleFormatter& SetPrecision(unsigned prec = 1) { NumericBase::SetPrecision(prec); return *this; }
    DoubleFormatter& SetWidth(unsigned width = 1) { NumericBase::SetWidth(width); return *this; }
    DoubleFormatter& SetShowSign(bool flag = true) { NumericBase::SetShowSign(flag); return *this; }
    DoubleFormatter& SetPrefixChar(char prefix = ' ') { NumericBase::SetPrefixChar(prefix); return *this; }
    DoubleFormatter& SetSeparatorChar(char sep = ',') { NumericBase::SetSeparatorChar(sep); return *this; }
    DoubleFormatter& SetBigLetters(bool flag = true) { NumericBase::SetBigLetters(flag); return *this; }
    DoubleFormatter& SetAlignLeft(bool flag = true) { NumericBase::SetAlignLeft(flag); return *this; }

private:
    DoubleFormatter& operator=(const DoubleFormatter&);
    void             AppendSignCharLeft(bool negative, bool show_sign = false);

    PresentationType Type;        // +0x30
    const Double     Value;       // +0x38
    UPInt            Len;         // +0x40
    char             Buff[347 + 1];   // +0x48, room for DBL_MAX in %f
};

template<> struct FmtInfo<float>  { typedef DoubleFormatter formatter; };
template<> struct FmtInfo<double> { typedef DoubleFormatter formatter; };

class ResouceProvider;

// an argument that names a resource (number or string id) of a ResouceProvider
class ResourceFormatter : public Formatter
{
public:
    class ValueType
    {
    public:
        ValueType(UPInt rc);
        ValueType(UPInt rc, const ResouceProvider& provider);
        explicit ValueType(int rc);
        explicit ValueType(int rc, const ResouceProvider& provider);
        ValueType(const char* rc);
        ValueType(const char* rc, const ResouceProvider& provider);

        bool        IsStrResource() const { return IsString; }
        const char* GetStrResource() const { return Resource.RStr; }
        UPInt       GetLongResource() const { return Resource.RLong; }

        const ResouceProvider* GetResouceProvider() const { return RC_Provider; }
        void                   SetResouceProvider(const ResouceProvider* rp) { RC_Provider = rp; }

    private:
        ValueType& operator=(const ValueType&);

        union ResourceType
        {
            const char* RStr;
            UPInt       RLong;
        };
        ResourceType           Resource;
        const bool             IsString;
        const ResouceProvider* RC_Provider;
    };

    ResourceFormatter(MsgFormat& f, const ValueType& v);
    virtual ~ResourceFormatter();

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;

private:
    StringDataPtr      MakeString(const TAttrs& attrs) const;
    ResourceFormatter& operator=(const ResourceFormatter&);

    const ValueType        Value;
    const ResouceProvider* pRP;
    StringDataPtr          Result;
};

template<> struct FmtInfo<ResourceFormatter::ValueType> { typedef ResourceFormatter formatter; };

class ResouceProvider : public NewOverrideBase<Stat_Default_Mem>
{
public:
    ResouceProvider(const ResouceProvider* next = 0) : nextRP(next) { }
    virtual ~ResouceProvider() { }

    virtual unsigned      Reflect(const ResourceFormatter::ValueType& rc, const FmtResource::TAttrs** attrs) const = 0;
    virtual StringDataPtr MakeString(const ResourceFormatter::ValueType& rc, const FmtResource::TAttrs& attrs) const = 0;

protected:
    const ResouceProvider* GetNext() const { return nextRP; }

private:
    const ResouceProvider* nextRP;
};

// makes the formatter for a named option ("{0:plural:...}")
class FormatterFactory
{
public:
    virtual ~FormatterFactory() { }

    struct Args
    {
        Args(MsgFormat& f, const StringDataPtr& n, const ResourceFormatter::ValueType& v) : Fmt(f), Name(n), Value(v) { }

        MsgFormat&                          Fmt;
        const StringDataPtr&                Name;
        const ResourceFormatter::ValueType& Value;

    private:
        Args& operator=(const Args&);
    };

    virtual Formatter* MakeFormatter(const Args& args) const = 0;
};

class LocaleProvider : public FormatterFactory
{
public:
    virtual ~LocaleProvider() { }

    virtual const Locale&    GetLocale() const = 0;
    virtual ResouceProvider* GetDefaultRCProvider() const = 0;
};

class MsgFormat : String::InitStruct
{
public:
    // where the formatted text goes
    class Sink
    {
        friend class MsgFormat;

    public:
        Sink(String& str) : Type(tStr), SinkData(str) { }
        Sink(StringBuffer& buffer) : Type(tStrBuffer), SinkData(buffer) { }
        Sink(const StringDataPtr& strData) : Type(tDataPtr), SinkData(strData) { }
        template<typename T, int N>
        Sink(const T (&v)[N]) : Type(tDataPtr), SinkData(StringDataPtr(v, N)) { }

    private:
        enum DataType { tStr, tStrBuffer, tDataPtr };

        struct StrDataType
        {
            const char* pStr;
            UPInt       Size;
        };
        union SinkDataType
        {
        public:
            SinkDataType(String& str) : pStr(&str) { }
            SinkDataType(StringBuffer& buffer) : pStrBuffer(&buffer) { }
            SinkDataType(const StringDataPtr& strData)
            {
                DataPtr.pStr = strData.ToCStr();
                DataPtr.Size = strData.GetSize();
            }

            String*       pStr;
            StringBuffer* pStrBuffer;
            StrDataType   DataPtr;
        };

        DataType     Type;
        SinkDataType SinkData;
    };

    MsgFormat(const Sink& r);
    MsgFormat(const Sink& r, const LocaleProvider& loc);
    ~MsgFormat();

    typedef UInt8          ArgNumType;
    typedef StackMemPool<> MemoryPoolType;

    void Parse(const char* fmt);
    void FormatF(const StringDataPtr& fmt, va_list argList);
    bool ReplaceFormatter(Formatter* oldf, Formatter* newf, bool allocated);

    ArgNumType            GetFirstArgNum() const { return FirstArgNum; }
    void                  SetFirstArgNum(ArgNumType num) { FirstArgNum = num; }
    const LocaleProvider* GetLocaleProvider() const { return pLocaleProvider; }
    MemoryPoolType&       GetMemoryPool() { return MemPool; }
    UPInt                 GetStrSize() const { return StrSize; }

    UInt8 GetEscapeChar() const { return EscapeChar; }
    void  SetEscapeChar(UInt8 c) { EscapeChar = c; }

    // binds v to every parameter that refers to the current argument number
    template<typename T>
    void FormatD1(const T& v)
    {
        while (NextFormatter())
            Bind(new (GetMemoryPool()) typename FmtInfo<T>::formatter(*this, v), true);
        ++FirstArgNum;
    }
    void FinishFormatD();

private:
    enum ERecType { eStrType, eParamStrType, eFmtType };

    struct str_ptr
    {
        const char*   Str;
        unsigned char Len;
        unsigned char ArgNum;
    };
    struct fmt_ptr
    {
        Scaleform::Formatter* Formatter;
        bool                  Allocated;   // lives in the pool, destroyed with the MsgFormat
    };
    union fmt_value
    {
        str_ptr String;
        fmt_ptr Formatter;
    };
    class fmt_record
    {
    public:
        fmt_record(ERecType type, const fmt_value& value) : RecType(type), RecValue(value) { }

        ERecType         GetType() const { return RecType; }
        const fmt_value& GetValue() const { return RecValue; }

    private:
        ERecType  RecType;
        fmt_value RecValue;
    };

    bool NextFormatter();
    void Bind(Formatter* formatter, const bool allocated);
    void BindNonPos();
    void MakeString();
    void Evaluate(UPInt ind);
    void AddStringRecord(const StringDataPtr& str);
    void AddFormatterRecord(Formatter* f, bool allocated);

    virtual void InitString(char* pbuffer, UPInt size) const;

    MsgFormat& operator=(const MsgFormat&);

    // the first SS elements live in the object, the rest in an Array
    template<typename T, UPInt SS = 8, class DA = Array<T> >
    class StackArray
    {
    public:
        typedef T ValueType;

        StackArray() : Size(0) { }

        UPInt GetSize() const { return Size; }

        void PushBack(const ValueType& val)
        {
            if (Size < SS)
                *reinterpret_cast<ValueType*>(StaticArray + Size * sizeof(T)) = val;
            else
                DynamicArray.PushBack(val);
            ++Size;
        }

        ValueType& operator[](UPInt index)
        {
            if (index < SS)
                return *reinterpret_cast<ValueType*>(StaticArray + index * sizeof(T));
            return DynamicArray[index - SS];
        }
        const ValueType& operator[](UPInt index) const
        {
            if (index < SS)
                return *reinterpret_cast<const ValueType*>(StaticArray + index * sizeof(T));
            return DynamicArray[index - SS];
        }

    private:
        UPInt Size;
        DA    DynamicArray;
        char  StaticArray[SS * sizeof(T)];
    };

    typedef StackArray<fmt_record, 16, ArrayPOD<fmt_record> > DataType;

    UInt8                 EscapeChar;        // +0x08
    UInt8                 FirstArgNum;
    UInt16                NonPosParamNum;
    UInt16                UnboundFmtrInd;
    UPInt                 StrSize;           // +0x10
    SPInt                 DataInd;
    const LocaleProvider* pLocaleProvider;   // +0x20
    const Sink            Result;            // +0x28
    DataType              Data;              // +0x40
    MemoryPoolType        MemPool;           // +0x1e0
};

template<typename T>
struct FmtInfo
{
};

UPInt SPrintF(const MsgFormat::Sink& result, const char* fmt, ...);

// Formats fmt with "{n}" parameters into result; returns the formatted length.
template<typename T1>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FinishFormatD();
    return f.GetStrSize();
}

template<typename T1, typename T2>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1, const T2& v2)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FormatD1(v2);
    f.FinishFormatD();
    return f.GetStrSize();
}

template<typename T1, typename T2, typename T3>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1, const T2& v2, const T3& v3)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FormatD1(v2);
    f.FormatD1(v3);
    f.FinishFormatD();
    return f.GetStrSize();
}

// leading digits of the next token of str (default when there are none); str moves past them
int ReadInteger(StringDataPtr& str, int defaultValue, char separator = ':');

}  // namespace Scaleform

#endif
