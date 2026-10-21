// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 function reference assignment
// and the out-of-line hash table helpers (grow, clear) of the AS2 member, watchpoint and prototype tables.
// MS2-UNIT: sfr_as2_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142931790-0x142931870 .text$mn
// MS2-RANGE: 0x1429339a0-0x142933bd0 .text$mn
// MS2-RANGE: 0x142934060-0x142934390 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/gfx_asstringhash.h"
#include "../include/kernel/sf_stringhash.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x142931790
void FunctionRefBase::Assign(const FunctionRefBase& orig)
{
    if (this == &orig)
        return;

    FunctionObject* pprev = Function;
    if (!(Flags & FuncRef_Internal) && pprev && pprev != orig.Function)
        pprev->Release();
    Function = orig.Function;
    if (!(Flags & FuncRef_Internal) && orig.Function && pprev != orig.Function)
        orig.Function->AddRef();

    if (orig.pLocalFrame)
        SetLocalFrame(orig.pLocalFrame, (orig.Flags & FuncRef_Weak) != 0);
    else
    {
        // SetLocalFrame(0), inlined.
        if (pLocalFrame && !(Flags & FuncRef_Weak))
            pLocalFrame->Release();
        Flags &= ~FuncRef_Weak;
        pLocalFrame = 0;
    }
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// Growth of the AS2 hash tables (one more entry).
typedef HashNode<GFx::AS2::ASBuiltinType, Ptr<GFx::AS2::Object>, FixedSizeHash<GFx::AS2::ASBuiltinType> >
    MS2_AS2PrototypeNode;
template void HashSetBase<MS2_AS2PrototypeNode, MS2_AS2PrototypeNode::NodeHashF, MS2_AS2PrototypeNode::NodeAltHashF,
                          AllocatorLH<GFx::AS2::ASBuiltinType, 2>,
                          HashsetNodeEntry<MS2_AS2PrototypeNode, MS2_AS2PrototypeNode::NodeHashF> >::CheckExpand(void*);

// The string keyed sets: ASStringHash<U> (plain entries) and ASStringHash_GC<U> (collector entries).
#define MS2_AS2_STRING_SET(U, E)                                                                                     \
    HashSetBase<HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,                                                \
                HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeHashF,                                     \
                HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeAltHashF,                                  \
                AllocatorLH<GFx::ASString, GFx::StatMV_ASString_Mem>,                                                \
                E<HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>,                                              \
                  HashNode<GFx::ASString, U, GFx::ASStringHashFunctor>::NodeHashF> >

template void MS2_AS2_STRING_SET(GFx::AS2::MovieRoot::InvokeAliasInfo, HashsetNodeEntry)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::Object::Watchpoint, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::Member, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::SharedObjectPtr, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void MS2_AS2_STRING_SET(GFx::AS2::Value, GFx::HashsetNodeEntry_GC)::CheckExpand(void*);
template void decltype(StringHashLH<GFx::AS2::MovieClipLoader::ProgressDesc>::mHash)::BaseType::CheckExpand(void*);

// Clearing (destroys every entry and frees the table).
template void MS2_AS2_STRING_SET(char, HashsetNodeEntry)::Clear();
// @0x1429340f0
// MS2-FUNCTIONAL cl inlines the node destructor that the exe calls out of line (~HashNode<ASString, FunctionRef>, 0x142924490)
template void MS2_AS2_STRING_SET(GFx::AS2::FunctionRef, HashsetNodeEntry)::Clear();
template void MS2_AS2_STRING_SET(GFx::AS2::Member, GFx::HashsetNodeEntry_GC)::Clear();
// @0x142934220
// MS2-FUNCTIONAL cl inlines the ArrayDataBase<Value, LH 323> destructor that the exe calls out of line (0x142924420)
template void decltype(HashLH<GFx::EventId, ArrayLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>, GFx::EventIdHashFunctor,
                              GFx::AS2::StatMV_ActionScript_Mem>::mHash)::BaseType::Clear();
// @0x1429342b0
// MS2-FUNCTIONAL register allocation differs (key / value String release order kept)
template void HashsetCachedNodeEntry<HashNode<String, String, String::NoCaseHashFunctor>,
                                     HashNode<String, String, String::NoCaseHashFunctor>::NodeHashF>::Clear();
template void GFx::HashsetNodeEntry_GC<HashNode<GFx::ASString, GFx::AS2::Object::Watchpoint, GFx::ASStringHashFunctor>,
                                       HashNode<GFx::ASString, GFx::AS2::Object::Watchpoint,
                                                GFx::ASStringHashFunctor>::NodeHashF>::Clear();
template void GFx::HashsetNodeEntry_GC<HashNode<GFx::ASString, GFx::AS2::Member, GFx::ASStringHashFunctor>,
                                       HashNode<GFx::ASString, GFx::AS2::Member, GFx::ASStringHashFunctor>::NodeHashF>::Clear();

} // namespace Scaleform

// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@W4ASBuiltinType@AS2@GFx@Scaleform@@V?$Ptr@VObject@AS2@GFx@Scaleform@@@4@V?$FixedSizeHash@W4ASBuiltinType@AS2@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@W4ASBuiltinType@AS2@GFx@Scaleform@@$01@2@V?$HashsetNodeEntry@U?$HashNode@W4ASBuiltinType@AS2@GFx@Scaleform@@V?$Ptr@VObject@AS2@GFx@Scaleform@@@4@V?$FixedSizeHash@W4ASBuiltinType@AS2@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1429339a0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@UInvokeAliasInfo@MovieRoot@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x1429339f0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@UWatchpoint@Object@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@UWatchpoint@Object@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933a40
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933a90
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VSharedObjectPtr@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VSharedObjectPtr@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933ae0
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXPEAX@Z 0x142933b30
// MS2-PIN: ?CheckExpand@?$HashSetBase@U?$StringLH_HashNode@UProgressDesc@MovieClipLoader@AS2@GFx@Scaleform@@UNoCaseHashFunctor@String@5@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UProgressDesc@MovieClipLoader@AS2@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$StringLH_HashNode@UProgressDesc@MovieClipLoader@AS2@GFx@Scaleform@@UNoCaseHashFunctor@String@5@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXPEAX@Z 0x142933b80
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@DUASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@DUASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x142934060
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VFunctionRef@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x1429340f0
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@2@@Scaleform@@QEAAXXZ 0x142934180
// MS2-PIN: ?Clear@?$HashSetBase@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VEventId@GFx@Scaleform@@$0BED@@2@V?$HashsetCachedNodeEntry@U?$HashNode@VEventId@GFx@Scaleform@@V?$ArrayLH@VValue@AS2@GFx@Scaleform@@$0BED@UArrayDefaultPolicy@4@@3@UEventIdHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@QEAAXXZ 0x142934220
// MS2-PIN: ?Clear@?$HashsetCachedNodeEntry@U?$HashNode@VString@Scaleform@@V12@UNoCaseHashFunctor@12@@Scaleform@@UNodeHashF@12@@Scaleform@@QEAAXXZ 0x1429342b0
// MS2-PIN: ?Clear@?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@UWatchpoint@Object@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@Scaleform@@QEAAXXZ 0x142934320
// MS2-PIN: ?Clear@?$HashsetNodeEntry_GC@U?$HashNode@VASString@GFx@Scaleform@@VMember@AS2@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@GFx@Scaleform@@QEAAXXZ 0x142934350
// MS2-PIN: ??_7SharedObjectPtr@AS2@GFx@Scaleform@@6B@ 0x14321dd78
