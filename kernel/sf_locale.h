// Recovered Scaleform GFx 4.1.18: number/sign conventions of a locale, as read by the MsgFormat formatters. The exe
// links no locale implementation; MsgFormat only reaches one through a caller-supplied LocaleProvider.
#ifndef MS2_SF_KERNEL_LOCALE_H
#define MS2_SF_KERNEL_LOCALE_H

#include "ms2/scaleform/kernel/sf_string.h"

namespace Scaleform {

class Locale
{
public:
    Locale();

    const String& GetEnglishName() const { return EnglishName; }
    const String& GetNativeName() const { return NativeName; }
    const String& GetGrouping() const { return Grouping; }
    UInt32        GetGroupSeparator() const { return GroupSeparator; }
    UInt32        GetDecimalSeparator() const { return DecimalSeparator; }
    UInt32        GetPositiveSign() const { return PositiveSign; }
    UInt32        GetNegativeSign() const { return NegativeSign; }
    UInt32        GetExponentialSign() const { return ExponentialSign; }

protected:
    void SetEnglishName(const String& name) { EnglishName = name; }
    void SetNativeName(const String& name) { NativeName = name; }
    void SetGrouping(const String& value) { Grouping = value; }
    void SetGroupSeparator(UInt32 value) { GroupSeparator = value; }
    void SetDecimalSeparator(UInt32 value) { DecimalSeparator = value; }
    void SetPositiveSign(UInt32 value) { PositiveSign = value; }
    void SetNegativeSign(UInt32 value) { NegativeSign = value; }
    void SetExponentialSign(UInt32 value) { ExponentialSign = value; }

private:
    String EnglishName;        // +0x00
    String NativeName;
    String Grouping;
    UInt32 GroupSeparator;     // +0x18 (UCS-4 code points)
    UInt32 DecimalSeparator;
    UInt32 PositiveSign;       // +0x20
    UInt32 NegativeSign;       // +0x24
    UInt32 ExponentialSign;
};

}  // namespace Scaleform

#endif
