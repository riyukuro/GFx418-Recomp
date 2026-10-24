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
    // (appended, sfr24) an empty set owned by the VM's collector; inlined into VMAbcFile::GetInternedNamespaceSet
    // 0x14250aff0. Constructing one emits the vftable: ForEachChild_GC needs a definition or MS2-PIN.
    explicit NamespaceSet(Collector* gc) : GASRefCountBase(gc) {}
    // (appended, sfr24)
    void Add(Instances::Namespace& ns) { Namespaces.PushBack(SPtr<Instances::Namespace>(&ns)); }

    // (appended, sfr24) the vftable over GASRefCountBase's: 1, 3 and 5 stay the base's.
    // 0 0x142503860 (ICF): visits the non-null entries. The exe also passes this as the owner in r8, which the 2-arg
    // GcOp has no slot for, so a body written against this header is MS2-FUNCTIONAL.
    virtual void        ForEachChild_GC(Collector* prcc, GcOp op) const;
    virtual const char* GetAS3ObjectType() const { return "NamespaceSet"; }    // 2 0x142505e00
    // 4 ??_G 0x1424e3450: the implicit destructor (Namespaces, then ~GASRefCountBase).
private:
    ArrayLH<SPtr<Instances::Namespace> >    Namespaces;     // +0x20
};
static_assert(sizeof(NamespaceSet) == 0x38, "NamespaceSet size");

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

    // (appended, sfr19) registers itself with the VM unless the VM is being destroyed. 0x1424dbb30
    VMAbcFile(VM& vm, const Ptr<Abc::File>& file);
    // (appended, sfr19) the vftable (0x14317b750) overrides
    virtual ~VMAbcFile();                                       // 0x1424e3eb0

protected:
    virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;   // 0x142503ff0
    virtual const char* GetAS3ObjectType() const;               // 0x142505e40
    virtual String GetAS3ObjectName() const;                    // 0x142505dd0
    virtual void Finalize_GC();                                 // 0x1425008d0

private:
    // (appended, sfr19) makes the class traits of the file's classes, then its scripts (run when to_execute).
    // 0x142515b30
    CheckResult Load(bool to_execute);
    // (appended, sfr19) the two halves of Load. 0x142521780, 0x142521390
    bool RegisterUserDefinedClassTraits();
    bool RegisterScrips(bool to_execute);

    VM*              pVM;               // +0x20
    Ptr<Abc::File>   pFile;             // +0x28
    // (appended, sfr19) the members from +0x30 on, from the dtor 0x1424e3eb0; the hash sets the recovered code
    // does not use are kept as their table pointer.
    AbcMultinameHash<SPtr<Instances::Namespace> > IntNamespaces;   // +0x30
    void*            AbsObjectsTable;   // +0x38 (HashSetLH, 0x18-byte entries)
    ArrayLH<SPtr<NamespaceSet> >        IntNamespaceSets;           // +0x40
    ArrayLH<SPtr<ASStringNode> >        IntStrings;                 // +0x58 ([0] is the empty string)
    void*            GlobalObjectsTable;    // +0x70 (HashSetLH, 0x18-byte entries)
    ArrayLH<SPtr<VMAbcFile> >           Children;                   // +0x78
    void*            ActivationTraitsCacheTable;    // +0x90 (by method body)
    void*            FunctionTraitsCacheTable;      // +0x98 (by method index)
    ArrayLH<SPtr<ClassTraits::Traits> > LoadedClasses;              // +0xa0
    ArrayLH<ArrayLH_POD<UPInt, StatMV_VM_AbcFile_Mem>, StatMV_VM_VMAbcFile_Mem> OpCodeArray;    // +0xb8 (per method body)
    ArrayLH<Abc::MethodBodyInfo::Exception, StatMV_VM_VMAbcFile_Mem>             Exceptions;     // +0xd0 (per method body)
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
