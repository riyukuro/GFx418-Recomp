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
#include "../include/gfx/as2/as2_hashaccess.h"

// The watchpoint hash's findIndexAlt (exact / ignoring case), COMDATs the exe calls out of line.
typedef Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint>::SetType Sfr05xWatchpointSet;
template<> template<> Scaleform::SPInt Sfr05xWatchpointSet::findIndexAlt<Scaleform::GFx::ASString>(const Scaleform::GFx::ASString& key) const; // exe 0x142917220
template<> template<> Scaleform::SPInt Sfr05xWatchpointSet::findIndexAlt<Scaleform::GFx::ASStringNoCaseKey>(
    const Scaleform::GFx::ASStringNoCaseKey& key) const; // exe 0x142916e60

namespace Scaleform { namespace GFx { namespace AS2 {

MS2_AS2_HASH_FINDINDEX(Object::Watchpoint)

// The standard member of a name (ASStringHash<char>::GetCaseCheck): by node when case sensitive, else by the
// lowercase twins; the member is copied out when found.
// MS2-PIN: ?GetCaseCheck@?$ASStringHashBase@DV?$HashUncachedLH@VASString@GFx@Scaleform@@DUASStringHashFunctor@23@$0BEE@@Scaleform@@@GFx@Scaleform@@QEBA_NAEBVASString@23@PEAD_N@Z 0x142949cf0 ; unique: the exe body is the template member
// @0x142949cf0
// (was the free forwarder StandardMemberHash_GetCaseCheck; the exe function is the template member itself)
}}} // namespace Scaleform::GFx::AS2
template bool Scaleform::GFx::ASStringHashBase<char, Scaleform::HashUncachedLH<Scaleform::GFx::ASString, char,
    Scaleform::GFx::ASStringHashFunctor, Scaleform::GFx::StatMV_ASString_Mem> >::GetCaseCheck(const Scaleform::GFx::ASString&, char*, bool) const;
namespace Scaleform { namespace GFx { namespace AS2 {

// The watchpoint of a property (ASStringHash_GC<Object::Watchpoint>::GetCaseCheck), null when there is none.
// A free function in place of the template member (the callers reach it under this name). It is the inlined
// Hash::GetAlt: the node of the found index, then its value when the node is not null.
// @0x142949eb0
const Object::Watchpoint* WatchpointHash_GetCaseCheck(ASStringHash_GC<Object::Watchpoint>* phash, const ASString& key,
                                                      bool caseSensitive)
{
    typedef ASStringHash_GC<Object::Watchpoint>::NodeType NodeType;
    if (caseSensitive)
    {
        SPInt           index = HashFindIndex(phash, key);
        const NodeType* p     = index >= 0 ? &phash->NodeAt(index) : 0;
        return p ? &p->Second : 0;
    }
    ASStringNoCaseKey ikey(key);
    SPInt             index = HashFindIndex(phash, ikey);
    const NodeType*   p     = index >= 0 ? &phash->NodeAt(index) : 0;
    return p ? &p->Second : 0;
}

}}} // namespace Scaleform::GFx::AS2
