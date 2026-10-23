// VMAbcFile: the VM side of a loaded ABC file (interned strings, namespaces and namespace sets of its constant pool).
// Only the members the recovered code reads are modeled; the VMFile base and the rest of the layout are not, so
// nothing here may allocate or copy one. Recovered from GetInternedString 0x14250b240, GetInternedNamespace
// 0x14250ae60, GetInternedNamespaceSet 0x14250aff0 and Multiname(VMAbcFile&, const Abc::Multiname&) 0x1424d8ec0.
#ifndef MS2_SCALEFORM_GFX_AS3_AS3_VMABCFILE_H
#define MS2_SCALEFORM_GFX_AS3_AS3_VMABCFILE_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// A set of namespaces a multiname is qualified with. 0x38 bytes, vftable 0x14317b058.
class NamespaceSet : public GASRefCountBase
{
private:
    NamespaceSet();
public:
    // (appended, sfr19)
    const ArrayLH<SPtr<Instances::Namespace> >& GetNamespaces() const { return Namespaces; }
private:
    ArrayLH<SPtr<Instances::Namespace> >    Namespaces;     // +0x20
};

// (appended, sfr19) a map keyed by an ABC constant pool index (and the index of the multiname that follows it, -1
// for none), hashed bytewise: a VMAbcFile interns its namespaces in one (+0x30, lookup 0x1425057f0, add 0x1424d4850).
template<class C, int SID = StatMV_VM_VMAbcFile_Mem>
class AbcMultinameHash
{
public:
    struct Key
    {
        UPInt NsInd;
        SPInt NextMnInd;

        Key(UPInt ind, SPInt next_ind = -1) : NsInd(ind), NextMnInd(next_ind) {}
        Key(const Key& other) : NsInd(other.NsInd), NextMnInd(other.NextMnInd) {}
        bool operator==(const Key& other) const { return NsInd == other.NsInd && NextMnInd == other.NextMnInd; }
    };

    typedef HashLH<Key, C, FixedSizeHash<Key>, SID> TContainer;
    TContainer Entries;
};

class VMAbcFile : public GASRefCountBase
{
public:
    VM&              GetVM() const      { return *pVM; }
    const Abc::File& GetAbcFile() const { return *pFile; }

    // The string at constant pool index ind, interned on first use (0x14250b240).
    ASString GetInternedString(UPInt ind);
    // The namespace at constant pool index ind, interned on first use (0x14250ae60).
    Instances::Namespace& GetInternedNamespace(UPInt ind);
    // (appended, sfr19) the namespace multiname mn is qualified with, interned on first use (0x14250abf0).
    Instances::Namespace& GetInternedNamespace(const Abc::Multiname& mn);
    // The namespace set at constant pool index ind, made on first use (0x14250aff0).
    NamespaceSet& GetInternedNamespaceSet(UPInt ind);
    // (appended, sfr19) keeps the class traits made for this file's classes (Vector.<T> of them) alive.
    void RegisterLoadedClass(const SPtr<ClassTraits::Traits>& tr) { LoadedClasses.PushBack(tr); }

private:
    VMAbcFile();

    // (appended, sfr19) makes the class traits of the file's classes, then its scripts (run when to_execute).
    // 0x142515b30
    CheckResult Load(bool to_execute);
    // (appended, sfr19) the two halves of Load. 0x142521780, 0x142521390
    bool RegisterUserDefinedClassTraits();
    bool RegisterScrips(bool to_execute);

    VM*              pVM;               // +0x20
    const Abc::File* pFile;             // +0x28 (counted)
    UPInt            Unk30[14];         // +0x30 (not modeled)
    ArrayLH<SPtr<ClassTraits::Traits> > LoadedClasses;  // +0xa0 (appended, sfr19)
};

// (appended, sfr19) the SlotInfo ctors need the complete VMAbcFile; declared in as3_obj.h.
inline SlotInfo::SlotInfo()
    : ReadOnly(0), DontEnum(0), DontDelete(0), Internal(0), CppBinding(0), BindType(BT_Unknown), ValueInd(-1),
      TI(NULL)
{
}

inline SlotInfo::SlotInfo(Pickable<const Instances::Namespace> ns, const ClassTraits::Traits* ctraits, int a,
                          const Ptr<ASStringNode>& name)
    : ReadOnly((a & aReadOnly) != 0), DontEnum((a & aDontEnum) != 0), DontDelete((a & aDontDelete) != 0),
      Internal((a & aInternal) != 0), CppBinding((a & aCppBinding) != 0), BindType(BT_Unknown), ValueInd(-1),
      pNs(ns), CTraits(ctraits), File(NULL), TI(NULL), Name(name)
{
}

inline SlotInfo::SlotInfo(Pickable<const Instances::Namespace> ns, VMAbcFile& file, const Abc::TraitInfo& ti, int a,
                          const Ptr<ASStringNode>& name)
    : ReadOnly((a & aReadOnly) != 0), DontEnum((a & aDontEnum) != 0), DontDelete((a & aDontDelete) != 0),
      Internal((a & aInternal) != 0), CppBinding((a & aCppBinding) != 0), BindType(BT_Unknown), ValueInd(-1),
      pNs(ns), CTraits(NULL), File(&file), TI(&ti), Name(name)
{
}

}}} // Scaleform::GFx::AS3

#endif
