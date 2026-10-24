// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 small gap functions of
// sfr_as2_05 (lane sfr31, taken over from sfr22).
// MS2-UNIT: sfr_as2_05c
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429487e0-0x1429488a2 .text$mn
// MS2-RANGE: 0x14294dbe0-0x14294dd03 .text$mn

#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_value.h"
#include "../include/gfx/gfx_imageresource.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The IMEStyle category named by a "compositionSegment"-style string (0..4, in the order of Text::IMEStyle::Category);
// 5 (SC_MaxNum) if unknown. Returned as an int: sfr_as2_01 declares it that way, the mangled name has no return type.
// MS2-FUNCTIONAL: strcmp chain order kept, compiler folds the literals differently
// @0x1429487e0
int GFx_StringToIMEStyleCategory(const ASString& name)
{
    const char* pstr = name.ToCStr();
    if (strcmp(pstr, "compositionSegment") == 0)
        return 0;
    if (strcmp(pstr, "clauseSegment") == 0)
        return 1;
    if (strcmp(pstr, "convertedSegment") == 0)
        return 2;
    if (strcmp(pstr, "phraseLengthAdj") == 0)
        return 3;
    if (strcmp(pstr, "lowConfSegment") == 0)
        return 4;
    return 5;
}

// width and height are read from the image; everything else is an ordinary member.
// MS2-FUNCTIONAL: string compares written as strcmp
// @0x14294dbe0
bool BitmapData::GetMember(Environment* penv, const ASString& name, Value* val)
{
    if (pImageRes)
    {
        const char* pname = name.ToCStr();
        if (strcmp(pname, "width") == 0)
        {
            UInt32 width = 0;
            if (Render::ImageBase* pimg = pImageRes->GetImage())
                width = pimg->GetSize().Width;
            val->SetNumber(Number(width));
            return true;
        }
        if (strcmp(pname, "height") == 0)
        {
            UInt32 height = 0;
            if (Render::ImageBase* pimg = pImageRes->GetImage())
                height = pimg->GetSize().Height;
            val->SetNumber(Number(height));
            return true;
        }
    }
    return GetMemberRaw(penv->GetSC(), name, val);
}

}}} // namespace Scaleform::GFx::AS2
