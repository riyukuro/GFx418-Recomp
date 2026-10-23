// VMAbcFile: the VM side of a loaded ABC file (interned strings, namespaces and namespace sets of its constant pool).
// Only the members the recovered code reads are modeled; the VMFile base and the rest of the layout are not, so
// nothing here may allocate or copy one. Recovered from GetInternedString 0x14250b240, GetInternedNamespace
// 0x14250ae60, GetInternedNamespaceSet 0x14250aff0 and Multiname(VMAbcFile&, const Abc::Multiname&) 0x1424d8ec0.
#ifndef MS2_SCALEFORM_GFX_AS3_AS3_VMABCFILE_H
#define MS2_SCALEFORM_GFX_AS3_AS3_VMABCFILE_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"
#include "ms2/scaleform/include/gfx/as3/as3_abc.h"

namespace Scaleform { namespace GFx { namespace AS3 {

// A set of namespaces a multiname is qualified with. 0x38 bytes, vftable 0x14317b058; members not modeled.
class NamespaceSet : public GASRefCountBase
{
private:
    NamespaceSet();
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
    // The namespace set at constant pool index ind, made on first use (0x14250aff0).
    NamespaceSet& GetInternedNamespaceSet(UPInt ind);
    // (appended, sfr19) keeps the class traits made for this file's classes (Vector.<T> of them) alive.
    void RegisterLoadedClass(const SPtr<ClassTraits::Traits>& tr) { LoadedClasses.PushBack(tr); }

private:
    VMAbcFile();

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
