// Recovered Scaleform GFx 4.1.18: WStringBuffer, a growable wide string with an optional caller-provided reserve buffer
// (0x20 bytes; bodies in sfr_kernel_02f). Lengths are in characters and exclude the terminating zero.
#ifndef MS2_SF_KERNEL_WSTRING_H
#define MS2_SF_KERNEL_WSTRING_H

#include "ms2/scaleform/kernel/sf_types.h"

namespace Scaleform {

class String;

class WStringBuffer
{
public:
    // storage the buffer starts in and never frees (a Reserve<N> member of the owner)
    struct ReserveHeader
    {
        wchar_t* pBuffer;
        UPInt    Size;

        ReserveHeader() : pBuffer(0), Size(0) { }
        ReserveHeader(wchar_t* p, UPInt sz) : pBuffer(p), Size(sz) { }
        ReserveHeader(const ReserveHeader& other) : pBuffer(other.pBuffer), Size(other.Size) { }
    };

    template<unsigned N>
    struct Reserve : public ReserveHeader
    {
        wchar_t Buffer[N];
        Reserve() : ReserveHeader(Buffer, N) { }
    };

private:
    wchar_t*      pText;        // +0x00
    UPInt         Length;       // +0x08
    ReserveHeader Reserved;     // +0x10

public:
    WStringBuffer() : pText(0), Length(0) { }
    WStringBuffer(const ReserveHeader& reserve) : pText(reserve.pBuffer), Length(0), Reserved(reserve)
    {
        if (pText)
            pText[0] = 0;
    }
    WStringBuffer(const WStringBuffer& other);
    ~WStringBuffer();

    const wchar_t* ToWStr() const    { return pText ? pText : L""; }
    UPInt          GetLength() const { return Length; }
    wchar_t*       GetBuffer() const { return pText; }

    WStringBuffer& operator=(const WStringBuffer& other);
    WStringBuffer& operator=(const String& str);
    WStringBuffer& operator=(const char* utf8);
    WStringBuffer& operator=(const wchar_t* str);

    // sets the length (keeps the old characters, terminates); false when the allocation failed
    bool Resize(UPInt length);
    void SetString(const char* utf8, UPInt bytes = SF_MAX_UPINT);
    void SetString(const wchar_t* str, UPInt length = SF_MAX_UPINT);
    void StripTrailingNewLines();
};

}  // namespace Scaleform

#endif
