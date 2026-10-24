// Recovered Scaleform 4.1.18 kernel: the MsgFormat value formatters (only what the recovered units use).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The formatter members are out of line in the kernel MsgFormat unit; until it is recovered they bind to the exe:
//   Formatter::~Formatter 0x1425af520, LongFormatter::LongFormatter(unsigned) 0x1425aee30,
//   LongFormatter::GetSize 0x1425b1540, LongFormatter::InitString 0x1425b15a0.
#ifndef MS2_SF_INC_KERNEL_MSGFORMAT_H
#define MS2_SF_INC_KERNEL_MSGFORMAT_H

#include "sf_string.h"
#include "sf_stackmempool.h"

namespace Scaleform {

class MsgFormat;

// Root of the format resources (vftable only).
class FmtResource
{
public:
    struct TAttrs
    {
        TAttrs() : Num(0), Attrs(0) {}
        unsigned Num;
        UPInt*   Attrs;
    };

    virtual ~FmtResource() {}
    virtual unsigned Reflect(const TAttrs*& attrs) const;
};

// One argument formatter: +8 owning MsgFormat, +0x10 converted flag.
class Formatter : public FmtResource
{
public:
    typedef UByte requirements_t;
    enum ParentRef { prNone, prPrev, prNext, prPos };

    Formatter() : pParentFmt(0), IsConverted(false) {}
    Formatter(MsgFormat& f) : pParentFmt(&f), IsConverted(false) {}
    virtual ~Formatter();

    virtual void           Parse(const StringDataPtr& str);
    virtual void           Convert() = 0;
    virtual StringDataPtr  GetResult() const = 0;
    virtual UPInt          GetSize() const = 0;
    virtual requirements_t GetRequirements() const;
    virtual void           SetPrevStr(const StringDataPtr& ptr);
    virtual StringDataPtr  GetPrevStr() const;
    virtual void           SetNextStr(const StringDataPtr& ptr);
    virtual StringDataPtr  GetNextStr() const;
    virtual ParentRef      GetParentRef() const;
    virtual unsigned char  GetParentPos() const;
    virtual void           SetParent(const FmtResource& r);
protected:
    virtual void           SetParentRef(ParentRef r);
    virtual void           SetParentPos(unsigned char pos);

private:
    MsgFormat* pParentFmt;
    bool       IsConverted;
};

// Shared numeric options (as laid out by the exe: +0 precision/width bits, +4 prefix, +5 separator, +6 flag bits;
// the 4.1.18 constructor initialises four flag bits, BigLetters = bit 0 set).
class NumericBase
{
public:
    void SetBigLetters(bool flag = true) { BigLetters = flag; }
    void SetPrecision(unsigned prec = 1) { Precision = prec; }
    // The converted text.
    const char* ToCStr() const { return ValueStr; }

protected:
    unsigned Precision:5;
    unsigned Width:5;
    char     PrefixChar;
    char     SeparatorChar;
    bool     BigLetters:1;
    bool     BlankPrefix:1;
    bool     AlignLeft:1;
    bool     SharpSign:1;
    char*    ValueStr;
};

// Integer formatter (0x60 bytes): Formatter +0, String::InitStruct +0x18, NumericBase +0x20, base/sign bits +0x30,
// value +0x38, digit buffer +0x40.
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

    LongFormatter& SetBase(unsigned base)       { Base = base; return *this; }
    LongFormatter& SetBigLetters(bool flag = true)
    {
        NumericBase::SetBigLetters(flag);
        return *this;
    }

private:
    LongFormatter& operator=(const LongFormatter&);

    unsigned     Base:5;
    const bool   SignedValue:1;
    bool         IsLongLong:1;
    const SInt64 Value;
    char         Buff[29];
};

} // namespace Scaleform

namespace Scaleform {

// Floating-point formatter (CRT sprintf); only the constructor is used here (exe 0x1425ae9e0).
class DoubleFormatter : public Formatter, public NumericBase, public String::InitStruct
{
public:
    enum PresentationType { FmtDecimal, FmtScientific, FmtSignificant };

    DoubleFormatter(MsgFormat& f, double v);
    // (appended for the AS3 Number natives, sfr_as3_03) exe 0x1425aea50
    DoubleFormatter(double v);

    DoubleFormatter& SetType(PresentationType ptype)    { Type = ptype; return *this; }
    DoubleFormatter& SetPrecision(unsigned prec = 1)    { NumericBase::SetPrecision(prec); return *this; }

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;
    virtual void          InitString(char* pbuffer, UPInt size) const;

private:
    DoubleFormatter& operator=(const DoubleFormatter&);

    int          Type;          // +0x30
    const double Value;         // +0x38
    UPInt        Len;           // +0x40
    char         Buff[347 + 1]; // +0x48
};

// String formatter (0x28 bytes): Formatter +0, the text +0x18. Constructors out of line (exe 0x1425af2d0,
// 0x1425af2a0).
class StrFormatter : public Formatter
{
public:
    StrFormatter(MsgFormat& f, const char* v);
    StrFormatter(MsgFormat& f, const StringDataPtr& v);
    // (appended for the font manager, sfr_gfx_07g) exe 0x1425af260
    StrFormatter(MsgFormat& f, const String& v);

    virtual void          Parse(const StringDataPtr& str);
    virtual void          Convert();
    virtual StringDataPtr GetResult() const;
    virtual UPInt         GetSize() const;

private:
    StringDataPtr Value;
};

template<typename T> struct FmtInfo {};
template<> struct FmtInfo<const char*> { typedef StrFormatter formatter; };
template<> struct FmtInfo<StringDataPtr> { typedef StrFormatter formatter; };
template<> struct FmtInfo<int>    { typedef LongFormatter formatter; };
template<> struct FmtInfo<float>  { typedef DoubleFormatter formatter; };
template<> struct FmtInfo<double> { typedef DoubleFormatter formatter; };
template<> struct FmtInfo<String> { typedef StrFormatter formatter; }; // (sfr_gfx_07g)
// (appended, sfr15)
template<> struct FmtInfo<long>          { typedef LongFormatter formatter; };
template<> struct FmtInfo<unsigned long> { typedef LongFormatter formatter; };
template<> struct FmtInfo<unsigned int>  { typedef LongFormatter formatter; }; // (sfr15)
template<> struct FmtInfo<unsigned short> { typedef LongFormatter formatter; }; // (sfr_gfx_08j) LongFormatter(MsgFormat&, int)

// The "{n}" message formatter (0x3f0 bytes). Out of line in the kernel MsgFormat unit (exe: ctor 0x1425af0a0,
// dtor 0x1425af530, Parse 0x1425b2210, FinishFormatD 0x1425b0bd0, NextFormatter 0x1425b1960, Bind 0x1425afab0).
// The record array between +0x40 and +0x1e0 is only touched out of line, so it is kept opaque here.
class MsgFormat : String::InitStruct
{
public:
    // Where the formatted text goes.
    class Sink
    {
        friend class MsgFormat;

    public:
        Sink(String& str) : Type(tStr) { SinkData.pStr = &str; }
        Sink(const StringDataPtr& strData) : Type(tDataPtr)
        {
            SinkData.DataPtr.pStr = strData.ToCStr();
            SinkData.DataPtr.Size = strData.GetSize();
        }

    private:
        enum DataType { tStr, tStrBuffer, tDataPtr };
        struct StrDataType
        {
            const char* pStr;
            UPInt       Size;
        };
        union SinkDataType
        {
            String*     pStr;
            void*       pStrBuffer;
            StrDataType DataPtr;
        };

        DataType     Type;
        SinkDataType SinkData;
    };

    typedef StackMemPool<> MemoryPoolType;

    MsgFormat(const Sink& r);
    ~MsgFormat();

    void Parse(const char* fmt);
    void FinishFormatD();

    MemoryPoolType& GetMemoryPool() { return MemPool; }
    UPInt           GetStrSize() const { return StrSize; }

    // Binds v to every parameter that refers to the current argument number.
    template<typename T>
    void FormatD1(const T& v)
    {
        while (NextFormatter())
            Bind(new (GetMemoryPool()) typename FmtInfo<T>::formatter(*this, v), true);
        ++FirstArgNum;
    }

private:
    bool NextFormatter();
    void Bind(Formatter* formatter, const bool allocated);

    virtual void InitString(char* pbuffer, UPInt size) const;

    MsgFormat& operator=(const MsgFormat&);

    UByte          EscapeChar;      // +0x08
    UByte          FirstArgNum;     // +0x09
    UInt16         NonPosParamNum;
    UInt16         UnboundFmtrInd;
    UPInt          StrSize;         // +0x10
    SPInt          DataInd;
    const void*    pLocaleProvider; // +0x20
    const Sink     Result;          // +0x28
    UPInt          Data[0x34];      // +0x40 record array (size, dynamic array, 16 in-object records)
    MemoryPoolType MemPool;         // +0x1e0
};

// Formats fmt with "{n}" parameters into result; returns the formatted length.
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

template<typename T1, typename T2, typename T3, typename T4>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1, const T2& v2, const T3& v3,
                    const T4& v4)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FormatD1(v2);
    f.FormatD1(v3);
    f.FormatD1(v4);
    f.FinishFormatD();
    return f.GetStrSize();
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1, const T2& v2, const T3& v3,
                    const T4& v4, const T5& v5, const T6& v6)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FormatD1(v2);
    f.FormatD1(v3);
    f.FormatD1(v4);
    f.FormatD1(v5);
    f.FormatD1(v6);
    f.FinishFormatD();
    return f.GetStrSize();
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1, const T2& v2, const T3& v3,
                    const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FormatD1(v2);
    f.FormatD1(v3);
    f.FormatD1(v4);
    f.FormatD1(v5);
    f.FormatD1(v6);
    f.FormatD1(v7);
    f.FormatD1(v8);
    f.FinishFormatD();
    return f.GetStrSize();
}

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8,
         typename T9>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1, const T2& v2, const T3& v3,
                    const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8, const T9& v9)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FormatD1(v2);
    f.FormatD1(v3);
    f.FormatD1(v4);
    f.FormatD1(v5);
    f.FormatD1(v6);
    f.FormatD1(v7);
    f.FormatD1(v8);
    f.FormatD1(v9);
    f.FinishFormatD();
    return f.GetStrSize();
}

// (appended for the font manager, sfr_gfx_07g) one and three parameters
template<typename T1>
inline UPInt Format(const MsgFormat::Sink& result, const char* fmt, const T1& v1)
{
    MsgFormat f(result);
    f.Parse(fmt);
    f.FormatD1(v1);
    f.FinishFormatD();
    return f.GetStrSize();
}

// (appended, sfr15) v formatted on its own ("{0}")
template<typename T>
inline String AsString(const T& v)
{
    String result;
    Format(result, "{0}", v);
    return result;
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

} // namespace Scaleform

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::DoubleFormatter) == 0x1a8, "DoubleFormatter size");
static_assert(sizeof(Scaleform::LongFormatter) == 0x60, "LongFormatter size");
static_assert(sizeof(Scaleform::StrFormatter) == 0x28, "StrFormatter size");

#endif
