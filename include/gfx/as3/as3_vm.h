// Recovered Scaleform GFx 4.1.18 AS3: the virtual machine object (VM). Shared header of the src/ms2/scaleform units
// (sfr lane): append, do not reorder members.
//
// Layout from VM(FlashUI&, FileLoader&, StringManager&, ASRefCountCollector&) 0x1424dae90 (0x2d8 bytes) and the VM
// accessors (GetClassBoolean 0x142507e30, GetInternedNamespace 0x14250aa50, AddVMAbcFileWeak 0x1424eaf00). The 4.1.18
// VM has no Proxy namespace and no generic-class / alias tables; the execution stacks between +0x48 and +0x180 are kept
// opaque until recovered code needs their members. The vftable has two slots: the deleting destructor and one that
// returns 0.
#ifndef MS2_SF_GFX_AS3_VM_H
#define MS2_SF_GFX_AS3_VM_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class FlashUI;
class FileLoader;
class XMLSupport;

namespace Instances { namespace fl { class GlobalObjectCPP; } }
namespace InstanceTraits { namespace fl { class GlobalObject; } }

class VM : public NewOverrideBase<StatMV_VM_VM_Mem>
{
public:
    VM(FlashUI& ui, FileLoader& loader, StringManager& string_manager, ASRefCountCollector& gc);
    virtual ~VM();                      // slot 0
    virtual void* Unk01() { return 0; } // slot 1 (returns 0)

    StringManager&          GetStringManager() const    { return StringManagerRef; }
    ASRefCountCollector&    GetGC() const               { return *GC; }
    RefCountCollector<StatMV_ActionScript_Mem>* GetGCPtr() const;
    MemoryHeap*             GetMemoryHeap() const       { return MHeap; }
    FlashUI&                GetUI() const               { return UI; }
    FileLoader&             GetFileLoader() const       { return Loader; }
    bool                    IsException() const         { return HandleException; }

    Instances::Namespace& GetPublicNamespace() const    { return *PublicNamespace; }
    Instances::Namespace& GetAS3Namespace() const       { return *AS3Namespace; }
    Instances::Namespace& GetVectorNamespace() const    { return *VectorNamespace; }

    ClassTraits::Traits& GetClassTraitsClassClass() const   { return *TraitsClassClass; }
    ClassTraits::Traits& GetClassTraitsObject() const       { return *TraitsObject; }
    ClassTraits::Traits& GetClassTraitsNamespace() const    { return *TraitsNamespace; }
    ClassTraits::Traits& GetClassTraitsFunction() const     { return *TraitsFunction; }
    ClassTraits::Traits& GetClassTraitsBoolean() const      { return *TraitsBoolean; }
    ClassTraits::Traits& GetClassTraitsNumber() const       { return *TraitsNumber; }
    ClassTraits::Traits& GetClassTraitsSInt() const         { return *TraitsInt; }
    ClassTraits::Traits& GetClassTraitsUInt() const         { return *TraitsUint; }
    ClassTraits::Traits& GetClassTraitsString() const       { return *TraitsString; }
    ClassTraits::Traits& GetClassTraitsArray() const        { return *TraitsArray; }
    ClassTraits::Traits& GetClassTraitsNull() const         { return *TraitsNull; }
    ClassTraits::Traits& GetClassTraitsVoid() const         { return *TraitsVoid; }

public:
    bool                                    Initialized;        // +0x008
    bool                                    InDestructor;       // +0x009
    StringManager&                          StringManagerRef;   // +0x010
    ASRefCountCollector*                    GC;                 // +0x018
    FlashUI&                                UI;                 // +0x020
    FileLoader&                             Loader;             // +0x028
    UPInt                                   InInitializer;      // +0x030
    MemoryHeap*                             MHeap;              // +0x038
    SPtr<XMLSupport>                        XMLSupport_;        // +0x040
    UPInt                                   OpStack[5];         // +0x048 value stack (current page at +0x060)
    UPInt                                   Unk070[5];          // +0x070 zeroed by the constructor
    UPInt                                   CallStack[0x15];    // +0x098 paged call frame array (ctor 0x1424d6900)
    UPInt                                   RegisterFile[4];    // +0x140 (current page at +0x150)
    ArrayDH<Value>                          ScopeStack;         // +0x160
    bool                                    HandleException;    // +0x180
    Value                                   ExceptionObj;       // +0x188
    ArrayLH<SPtr<Instances::fl::GlobalObject> > GlobalObjects;  // +0x1a8
    SPtr<VMAppDomain>                       SystemDomain;       // +0x1c0
    SPtr<VMAppDomain>                       CurrentDomain;      // +0x1c8
    SPtr<Instances::Namespace>          PublicNamespace;    // +0x1d0
    SPtr<Instances::Namespace>          AS3Namespace;       // +0x1d8
    SPtr<Instances::Namespace>          VectorNamespace;    // +0x1e0
    SPtr<Instances::Namespace>          XMLNamespace;       // +0x1e8
    SPtr<ClassTraits::Traits>               TraitsClassClass;   // +0x1f0
    SPtr<ClassTraits::Traits>               TraitsObject;       // +0x1f8
    SPtr<ClassTraits::Traits>               TraitsNamespace;    // +0x200
    SPtr<ClassTraits::Traits>               TraitsFunction;     // +0x208
    SPtr<ClassTraits::Traits>               TraitsBoolean;      // +0x210
    SPtr<ClassTraits::Traits>               TraitsNumber;       // +0x218
    SPtr<ClassTraits::Traits>               TraitsInt;          // +0x220
    SPtr<ClassTraits::Traits>               TraitsUint;         // +0x228
    SPtr<ClassTraits::Traits>               TraitsString;       // +0x230
    SPtr<ClassTraits::Traits>               TraitsArray;        // +0x238
    SPtr<ClassTraits::Traits>               Traits240;          // +0x240 QName or Catch (unverified)
    SPtr<ClassTraits::Traits>               TraitsVector;       // +0x248
    SPtr<ClassTraits::Traits>               TraitsVector_int;   // +0x250
    SPtr<ClassTraits::Traits>               TraitsVector_uint;  // +0x258
    SPtr<ClassTraits::Traits>               TraitsVector_double; // +0x260
    SPtr<ClassTraits::Traits>               TraitsVector_String; // +0x268
    SPtr<ClassTraits::Traits>               TraitsNull;         // +0x270
    SPtr<ClassTraits::Traits>               TraitsVoid;         // +0x278
    SPtr<InstanceTraits::Traits>            NoFunctionTraits;   // +0x280 (0x100-byte traits)
    SPtr<InstanceTraits::Traits>            ActivationTraits;   // +0x288 (0xd0-byte traits)
    SPtr<InstanceTraits::fl::GlobalObject>  TraitaGlobalObject; // +0x290
    SPtr<Instances::fl::GlobalObjectCPP>    GlobalObject;       // +0x298 (0xd8 bytes)
    Value                                   GlobalObjectValue;  // +0x2a0
    ArrayLH_POD<VMAbcFile*>                 VMAbcFilesWeak;     // +0x2c0
};

// The collector every object of this VM registers with.
inline RefCountCollector<StatMV_ActionScript_Mem>* VM::GetGCPtr() const
{
    return GC;
}

}}} // namespace Scaleform::GFx::AS3

#endif
