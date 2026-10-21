// Recovered Scaleform 4.1.18 kernel: the MsgFormat value formatters (only what the recovered units use).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// The formatter members are out of line in the kernel MsgFormat unit; until it is recovered they bind to the exe:
//   Formatter::~Formatter 0x1425af520, LongFormatter::LongFormatter(unsigned) 0x1425aee30,
//   LongFormatter::GetSize 0x1425b1540, LongFormatter::InitString 0x1425b15a0.
#ifndef MS2_SF_INC_KERNEL_MSGFORMAT_H
#define MS2_SF_INC_KERNEL_MSGFORMAT_H

#include "sf_string.h"

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

#endif
