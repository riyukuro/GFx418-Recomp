// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// two out-of-line copies of the string hash lookup by case (ASStringHashBase::GetCaseCheck), for the standard
// member map and the watchpoint table.
// MS2-UNIT: sfr_as2_05x
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142949cf0-0x142949ead .text$mn
// MS2-RANGE: 0x142949eb0-0x142949f5c .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_object.h"
#include "../include/gfx/gfx_asstringhash.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// The watchpoint hash's findIndexAlt (exact / ignoring case), COMDATs the exe calls out of line.
SPInt WatchpointHash_FindIndex(const ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key); // exe 0x142917220
SPInt WatchpointHash_FindIndexNoCase(const ASStringHash_GC<Object::Watchpoint>* phash,
                                     const ASStringNoCaseKey& key); // exe 0x142916e60

// The standard member of a name (ASStringHash<char>::GetCaseCheck): by node when case sensitive, else by the
// lowercase twins; the member is copied out when found.
// MS2-FUNCTIONAL: a free function in place of the template member; the hash walks are inlined in the exe
// @0x142949cf0
bool StandardMemberHash_GetCaseCheck(const ASStringHash<char>* phash, const ASString& key, char* pvalue,
                                     bool caseSensitive)
{
    return phash->GetCaseCheck(key, pvalue, caseSensitive);
}

// The watchpoint of a property (ASStringHash_GC<Object::Watchpoint>::GetCaseCheck), null when there is none.
// MS2-FUNCTIONAL: a free function in place of the template member (the callers reach it under this name)
// @0x142949eb0
const Object::Watchpoint* WatchpointHash_GetCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                                      bool caseSensitive)
{
    SPInt index;
    if (caseSensitive)
        index = WatchpointHash_FindIndex(phash, key);
    else
    {
        ASStringNoCaseKey ikey(key);
        index = WatchpointHash_FindIndexNoCase(phash, ikey);
    }
    if (index < 0)
        return 0;
    return &phash->NodeAt(index).Second;
}

}}} // namespace Scaleform::GFx::AS2
