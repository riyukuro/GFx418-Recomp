// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_WString (WStringBuffer).
// Our own source, written from the exe (the leaked SDK copies were only used to name things and to compare layouts).
// Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425a7e50-0x1425a8280 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_wstring.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_utf8util.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include <string.h>

namespace Scaleform {

// the exe sizes the copy one character longer than the source (Length ends up source length + 1)
WStringBuffer::WStringBuffer(const WStringBuffer& other) : pText(0), Length(0)
{
    if (other.pText && Resize(other.Length + 1))
        memcpy(pText, other.pText, (other.Length + 1) * sizeof(wchar_t));
}

WStringBuffer::~WStringBuffer()
{
    if (pText != Reserved.pBuffer && pText)
        SF_FREE(pText);
}

WStringBuffer& WStringBuffer::operator=(const WStringBuffer& other)
{
    SetString(other.pText, other.Length);
    return *this;
}

WStringBuffer& WStringBuffer::operator=(const String& str)
{
    UPInt length = str.GetLength();
    if (Resize(length) && length)
        UTF8Util::DecodeString(pText, str.ToCStr(), str.GetSize());
    return *this;
}

WStringBuffer& WStringBuffer::operator=(const char* utf8)
{
    UPInt length = UTF8Util::GetLength(utf8);
    if (Resize(length) && length)
        UTF8Util::DecodeString(pText, utf8);
    return *this;
}

WStringBuffer& WStringBuffer::operator=(const wchar_t* str)
{
    UPInt length = 0;
    for (const wchar_t* p = str; *p; p++)
        length++;
    SetString(str, length);
    return *this;
}

bool WStringBuffer::Resize(UPInt length)
{
    if (length > Length && length >= Reserved.Size)
    {
        wchar_t* text = (wchar_t*)SF_ALLOC((length + 1) * sizeof(wchar_t), Stat_Default_Mem);
        if (text)
        {
            if (pText)
                memcpy(text, pText, (Length + 1) * sizeof(wchar_t));
            text[length] = 0;
            if (pText != Reserved.pBuffer && pText)
                SF_FREE(pText);
            pText = text;
            Length = length;
            return true;
        }
        return false;
    }
    if (pText)
        pText[length] = 0;
    Length = length;
    return true;
}

void WStringBuffer::SetString(const char* utf8, UPInt bytes)
{
    if (bytes == SF_MAX_UPINT)
        bytes = SFstrlen(utf8);
    if (Resize(UTF8Util::GetLength(utf8, bytes)) && bytes)
        UTF8Util::DecodeString(pText, utf8, bytes);
}

void WStringBuffer::SetString(const wchar_t* str, UPInt length)
{
    if (length == SF_MAX_UPINT)
        length = SFwcslen(str);
    if (Resize(length) && length)
        memcpy(pText, str, (length + 1) * sizeof(wchar_t));
}

void WStringBuffer::StripTrailingNewLines()
{
    SPInt len = (SPInt)Length;
    if (len > 0 && pText[len - 1] == 0)
        len--;
    for (SPInt i = len - 1; i >= 0; i--)
    {
        if (pText[i] != L'\n' && pText[i] != L'\r')
            break;
        Length--;
        pText[i] = 0;
    }
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0WStringBuffer@Scaleform@@QEAA@AEBV01@@Z 0x1425a7e50
// MS2-PIN: ??1WStringBuffer@Scaleform@@QEAA@XZ 0x1425a7eb0
// MS2-PIN: ??4WStringBuffer@Scaleform@@QEAAAEAV01@AEBV01@@Z 0x1425a7ed0
// MS2-PIN: ??4WStringBuffer@Scaleform@@QEAAAEAV01@AEBVString@1@@Z 0x1425a7f40
// MS2-PIN: ??4WStringBuffer@Scaleform@@QEAAAEAV01@PEBD@Z 0x1425a7fb0
// MS2-PIN: ??4WStringBuffer@Scaleform@@QEAAAEAV01@PEB_W@Z 0x1425a8010
// MS2-PIN: ?Resize@WStringBuffer@Scaleform@@QEAA_N_K@Z 0x1425a8090
// MS2-PIN: ?SetString@WStringBuffer@Scaleform@@QEAAXPEBD_K@Z 0x1425a8160
// MS2-PIN: ?SetString@WStringBuffer@Scaleform@@QEAAXPEB_W_K@Z 0x1425a81d0
// MS2-PIN: ?StripTrailingNewLines@WStringBuffer@Scaleform@@QEAAXXZ 0x1425a8230
