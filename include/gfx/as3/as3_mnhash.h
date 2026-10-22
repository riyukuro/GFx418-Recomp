// MultinameHash: {Name, Namespace} -> C map kept by the VM (class traits cache). Recovered from the
// setRawCapacity instantiation at 0x14242a640 (entry 0x28: NextInChain, HashValue, Key{Name, pNs}, C).
#ifndef MS2_SCALEFORM_GFX_AS3_AS3_MNHASH_H
#define MS2_SCALEFORM_GFX_AS3_AS3_MNHASH_H

#include "ms2/scaleform/include/kernel/sf_hash.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace ClassTraits { class Traits; }

template<class C, int SID = Stat_Default_Mem>
class MultinameHash
{
public:
    struct Key
    {
        ASString                              Name;     // +0x00
        SPtr<const Instances::Namespace>  pNs;      // +0x08

        Key(const ASString& name, const Instances::Namespace* ns) : Name(name), pNs(ns) {}
        Key(const Key& other) : Name(other.Name), pNs(other.pNs) {}

        bool operator==(const Key& other) const
        { return (Name == other.Name) && (pNs->GetKind() == other.pNs->GetKind()) && (pNs->GetUri() == other.pNs->GetUri()); }

        struct HashFunctor
        {
            static unsigned NsHash(const Instances::Namespace& ns)
            { return (ns.GetUri().GetHash() << 2) ^ ns.GetKind(); }

            UPInt operator()(const Key& key) const
            { return key.Name.GetHash() ^ NsHash(*key.pNs); }
        };
    };

    typedef HashDH<Key, C, typename Key::HashFunctor, SID> TContainer;
    TContainer Entries;

    explicit MultinameHash(void* pheap) : Entries(pheap) {}
};

typedef MultinameHash<ClassTraits::Traits*, StatMV_VM_VM_Mem> TClassTraitsCache;

}}} // namespace Scaleform::GFx::AS3

#endif
