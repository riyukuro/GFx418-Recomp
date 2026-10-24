// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_07):
// a string cut into an array at a delimiter.
// MS2-UNIT: sfr_as2_07k
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1429902c0-0x14299094b .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_stringobject.h"
#include "../include/kernel/sf_utf8util.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// No delimiter keeps the string whole; an empty one gives each character (the limit is not looked at then). Else the
// pieces between the delimiters, at most limit of them (a negative limit is 0).
// MS2-FUNCTIONAL: the exe inlines ArrayObject::PushBack and CreateStringFromCStr; same behavior
// @0x1429902c0
Ptr<ArrayObject> StringProto::StringSplit(Environment* penv, const ASString& str, const char* delimiters, int limit)
{
    Ptr<ArrayObject> parr = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Array)));
    if (limit < 0)
        limit = 0;

    const char* p = str.ToCStr();
    if (!delimiters)
    {
        parr->PushBack(Value(str));
        return parr;
    }

    if (*delimiters == 0)
    {
        String  charStr;
        UInt32  c;
        while ((c = UTF8Util::DecodeNextChar(&p)) != 0)
        {
            charStr.Clear();
            charStr.AppendChar(c);
            parr->PushBack(Value(penv->CreateString(charStr)));
        }
        return parr;
    }

    // pstart: the start of the current piece; pmatch: where the delimiter is being matched.
    const char* pstart = p;
    const char* pmatch = 0;
    UInt32      c1, c2;
    int         count = 0;
    do
    {
        pmatch                = p;
        const char* pd        = delimiters;
        const char* pnextChar = 0;
        const char* pprev;
        for (;;)
        {
            pprev = p;
            c1    = UTF8Util::DecodeNextChar(&p);
            c2    = UTF8Util::DecodeNextChar(&pd);
            if (!pnextChar)
                pnextChar = p;
            if (c1 == 0 || c2 == 0)
                break;
            if (c1 != c2)
            {
                // No match here: go on from the character after the match start.
                p = pnextChar;
                break;
            }
        }
        if (c2 == 0)
        {
            if (count >= limit)
                return parr;
            parr->PushBack(Value(CreateStringFromCStr(&penv->StringContext, pstart, pmatch)));
            ++count;
            p      = pprev;
            pstart = pprev;
        }
    } while (c1 != 0);

    if (count >= limit)
        return parr;
    if (c2 == 0)
        parr->PushBack(Value(CreateStringFromCStr(&penv->StringContext, pstart, pmatch)));
    else
        parr->PushBack(Value(CreateStringFromCStr(&penv->StringContext, pstart)));
    return parr;
}

}}} // namespace Scaleform::GFx::AS2
