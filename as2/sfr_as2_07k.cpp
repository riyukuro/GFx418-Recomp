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

// ArrayObject::PushBack (0x142971ba0) and StringProto::CreateStringFromCStr (0x142937e20), which the exe inlines here.
static SF_FORCEINLINE void PushElem(ArrayObject* parr, const Value& val)
{
    parr->Elements.PushBack(SF_HEAP_AUTO_NEW(parr) Value(val));
}

static SF_FORCEINLINE ASString PieceString(ASStringContext* psc, const char* start, const char* end = 0)
{
    int len = (end == 0) ? (int)strlen(start) : int(end - start);
    if (len < 0)
        len = 0;
    if (len > 0)
        return psc->CreateString(start, len);
    return psc->GetBuiltin(ASBuiltin_empty_);
}

// No delimiter keeps the string whole; an empty one gives each character (the limit is not looked at then). Else the
// pieces between the delimiters, at most limit of them (a negative limit is 0).
// MS2-FUNCTIONAL: the SDK body; PushBack and CreateStringFromCStr are inlined as in the exe. The exe's inlined
// PushBack keeps the new Value* in a stack slot (0 on a failed alloc) and re-reads the type byte after the Value copy,
// and splits the second string AddRef into load/inc/store; ours keeps these in registers (exe 83 bytes longer).
// @0x1429902c0
Ptr<ArrayObject> StringProto::StringSplit(Environment* penv, const ASString& str, const char* delimiters, int limit)
{
    Ptr<ArrayObject> retVal = *static_cast<ArrayObject*>(penv->OperatorNew(penv->GetBuiltin(ASBuiltin_Array)));

    const char*      search = delimiters;
    ASStringContext* psc    = penv->GetSC();
    const char*      pstr   = str.ToCStr();

    if (limit < 0)
        limit = 0;

    UInt32 c1, c2;

    if (search == 0)
    {
        retVal->PushBack(Value(str));
    }
    else if (*search == 0)
    {
        String tmpStr;

        while ((c1 = UTF8Util::DecodeNextChar(&pstr)) != 0)
        {
            tmpStr.Clear();
            tmpStr.AppendChar(c1);
            PushElem(retVal, Value(psc->CreateString(tmpStr)));
        }
    }
    else
    {
        int         count = 0;
        const char* start = pstr;

        for (;;)
        {
            const char* s2    = search;
            const char* end   = pstr;
            const char* prev  = pstr;
            const char* pnext = NULL;

            for (;;)
            {
                prev = pstr;
                c1   = UTF8Util::DecodeNextChar(&pstr);
                c2   = UTF8Util::DecodeNextChar(&s2);
                if (!pnext)
                    pnext = pstr;
                if (c1 == 0 || c2 == 0)
                    break;
                if (c1 != c2)
                {
                    pstr = pnext;
                    break;
                }
            }
            if (c2 == 0)
            {
                if (count >= limit)
                    break;
                PushElem(retVal, Value(PieceString(psc, start, end)));
                pstr = start = prev;
                ++count;
            }
            if (c1 == 0)
            {
                if (count < limit)
                {
                    if (c2 == 0)
                        PushElem(retVal, Value(PieceString(psc, start, end)));
                    else
                        PushElem(retVal, Value(PieceString(psc, start)));
                }
                break;
            }
        }
    }
    return retVal;
}

}}} // namespace Scaleform::GFx::AS2
