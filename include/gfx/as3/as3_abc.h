// Recovered Scaleform GFx 4.1.18 AS3 ABC (ActionScript byte code) file readers: the variable-length integer,
// double and string decoders the ABC parser and the interpreter use, and the parts of the constant pool and
// method body tables read from the exe so far. Our own declarations; bodies in sfr_as3_20 (0x1425452c0-).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_AS3_ABC_H
#define MS2_SF_GFX_AS3_ABC_H

#include "ms2/scaleform/include/kernel/sf_string.h"
#include "ms2/scaleform/include/gfx/as3/as3_value.h"

namespace Scaleform { namespace GFx { namespace AS3 { namespace Abc {

// u30: 7 bits per byte, low group first, high bit set while more bytes follow (at most 5 bytes).
template <typename T> int    ReadU30(const T*& p);                          // 0x1425455b0 <UInt8>
template <typename T> int    ReadU30(const T* data, UPInt& pos);            // 0x142545600 <UInt8>
// s24: three bytes little endian, sign-extended from bit 23.
template <typename T> int    ReadS24(const T* data, UPInt& pos);            // 0x1425454b0 <UInt8>
template <typename T> double ReadDouble(const T*& p);                       // 0x142545390 <UInt8>
template <typename T> String ReadString(const T*& p, UPInt size);           // 0x1425454f0 <UInt8>
template <typename T> String ReadString(const T* data, UPInt& pos, UPInt size); // 0x142545530 <UInt8>

// Bodies in sfr_as3_20 (instantiated there for UInt8); the other ABC units call them out of line.

// A namespace set: points at its u30 count followed by the namespace indices.
class NamespaceSetInfo
{
public:
    UPInt GetSize() const;                      // 0x1425452f0

    const UInt8* Data;                          // +0x00
};

// ==== Abc::File model (readers in sfr_as3_21 0x142565a30-) ============================================================

typedef SInt32 SInd;

// ABC multiname kind bytes as they appear in the file.
enum AbcKind
{
    AbcKind_Qname             = 0x07,
    AbcKind_QnameA            = 0x0D,
    AbcKind_RTQname           = 0x0F,
    AbcKind_RTQnameA          = 0x10,
    AbcKind_RTQnameL          = 0x11,
    AbcKind_RTQnameLA         = 0x12,
    AbcKind_Multiname         = 0x09,
    AbcKind_MultinameA        = 0x0E,
    AbcKind_MultinameL        = 0x1B,
    AbcKind_MultinameLA       = 0x1C,
    AbcKind_TypeName          = 0x1D,
    // Namespace kind bytes.
    AbcKind_Namespace         = 0x08,
    AbcKind_PackageNamespace  = 0x16,
    AbcKind_PackageInternalNs = 0x17,
    AbcKind_ProtectedNamespace= 0x18,
    AbcKind_ExplicitNamespace = 0x19,
    AbcKind_StaticProtectedNs = 0x1A,
    AbcKind_PrivateNs         = 0x05
};

// Multiname kinds decoded into flags (namespace part in the low two bits). as3_obj.h's MultinameKind keeps the raw
// AbcKind values, so these carry an MNF_ prefix.
enum MultinameFlagKind
{
    MNF_NS_Qualified = 0x00,
    MNF_NS_Runtime   = 0x01,
    MNF_NS_Multi     = 0x02,
    MNF_NameLate     = 0x04,
    MNF_Attr         = 0x08,
    MNF_QName        = MNF_NS_Qualified,
    MNF_QNameA       = MNF_NS_Qualified | MNF_Attr,
    MNF_RTQName      = MNF_NS_Runtime,
    MNF_RTQNameA     = MNF_NS_Runtime | MNF_Attr,
    MNF_RTQNameL     = MNF_NS_Runtime | MNF_NameLate,
    MNF_RTQNameLA    = MNF_NS_Runtime | MNF_NameLate | MNF_Attr,
    MNF_Multiname    = MNF_NS_Multi,
    MNF_MultinameA   = MNF_NS_Multi | MNF_Attr,
    MNF_MultinameL   = MNF_NS_Multi | MNF_NameLate,
    MNF_MultinameLA  = MNF_NS_Multi | MNF_NameLate | MNF_Attr,
    MNF_Typename     = 0x10,
    MNF_Invalid      = 0x20
};

// Constant pool value kinds (default values of optional parameters and slots).
enum ValueKind
{
    CONSTANT_Undefined = 0x00
};
bool IsValidValueKind(UInt8 vk);                // 0x142546080

// A string in the constant pool: points at its u30 length followed by the bytes.
class StringView
{
public:
    StringView() : Data(&Empty) {}
    StringView(const UInt8* d) : Data(d) {}

    StringDataPtr ToStringDataPtr() const;      // 0x142545310
    operator StringDataPtr () const { return ToStringDataPtr(); }

    static const UInt8 Empty;                   // 0x14317fe92
    const UInt8*       Data;
};

// 0x18 bytes.
class NamespaceInfo
{
public:
    NamespaceInfo() : Kind(NS_Undefined) {}
    NamespaceInfo(NamespaceKind k, const StringDataPtr& uri) : Kind(k), NameURI(uri) {}
    // The URI built in place (ConstPool's any namespace).
    NamespaceInfo(NamespaceKind k, const char* uri, UPInt size) : Kind(k), NameURI(uri, size) {}

    NamespaceKind Kind;                         // +0x00
    StringDataPtr NameURI;                      // +0x08
};

// 0x10 bytes; an aggregate.
class Multiname
{
public:
    MultinameFlagKind Kind;                     // +0x00
    SInd              Ind;                      // +0x04 namespace or namespace set index
    SInd              NameIndex;                // +0x08
    SInd              NextIndex;                // +0x0c type parameter of a Typename
};

// The constant pool, 0xc8 bytes.
class ConstPool : public NewOverrideBase<StatMV_VM_AbcConstPool_Mem>
{
public:
    ConstPool(); // 0x142545230
    typedef ArrayLH_POD<SInt32, StatMV_VM_AbcConstPool_Mem>           IntType;
    typedef ArrayLH_POD<UInt32, StatMV_VM_AbcConstPool_Mem>           UIntType;
    typedef ArrayLH<StringView, StatMV_VM_AbcConstPool_Mem>           StringsType;
    typedef ArrayLH<NamespaceInfo, StatMV_VM_AbcConstPool_Mem>        NamespaceType;
    typedef ArrayLH_POD<NamespaceSetInfo, StatMV_VM_AbcConstPool_Mem> NamespaceSetType;
    typedef ArrayLH<Multiname, StatMV_VM_AbcConstPool_Mem>            MultinamesType;

    // The double at index ind (1-based; 0 is NaN in the spec, 0.0 here as in the exe). 0x1425452c0
    double GetDouble(UPInt ind) const;
    // Empties the pools (the storage is kept or released by the arrays' resize rules). 0x142545bc0
    void Clear();

    StringDataPtr GetString(UPInt ind) const { return ConstStr[ind]; }
    const Multiname& GetMultiname(SPInt ind) const { return ind == 0 ? AnyType : const_multiname[ind]; }

    UInt32           DoubleCount;               // +0x00
    const UInt8*     ConstDouble;               // +0x08 the doubles, 8 bytes each
    IntType          ConstInt;                  // +0x10
    UIntType         ConstUInt;                 // +0x28
    StringsType      ConstStr;                  // +0x40
    NamespaceType    ConstNamespace;            // +0x58
    NamespaceSetType const_ns_set;              // +0x70
    MultinamesType   const_multiname;           // +0x88
    NamespaceInfo    any_namespace;             // +0xa0
    Multiname        AnyType;                   // +0xb8
};


// 8 bytes: a constant pool index and the pool it indexes.
class ValueDetail
{
public:
    ValueDetail() : ValueIndex(-1), Kind(CONSTANT_Undefined) {}
    ValueDetail(SInd ind, ValueKind kind) : ValueIndex(ind), Kind(kind) {}

    SInd      ValueIndex;                       // +0x00
    ValueKind Kind;                             // +0x04
};

// A method signature, 0x58 bytes.
class MethodInfo : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    enum Flag
    {
        fNEED_ARGUMENTS  = 0x01,
        fNEED_ACTIVATION = 0x02,
        fNEED_REST       = 0x04,
        fHAS_OPTIONAL    = 0x08,
        fSET_DXNS        = 0x40,
        fHAS_PARAM_NAMES = 0x80
    };

    MethodInfo() : RetTypeInd(-1), MethodBodyInfoInd(-1) {}

    bool HasOptionalParams() const { return (Flags & fHAS_OPTIONAL) != 0; }
    bool HasParamNames() const     { return (Flags & fHAS_PARAM_NAMES) != 0; }

    UInt8                                        Flags;             // +0x00
    SInd                                         RetTypeInd;        // +0x04
    SInd                                         MethodBodyInfoInd; // +0x08
    ArrayLH_POD<unsigned, StatMV_VM_AbcFile_Mem> ParamTypes;        // +0x10
    ArrayLH<ValueDetail, StatMV_VM_AbcFile_Mem>  OptionalParams;    // +0x28
    ArrayLH_POD<SInd, StatMV_VM_AbcFile_Mem>     ParamNames;        // +0x40
};

class MethodTable : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    ~MethodTable()
    {
        for (UPInt i = 0; i < Info.GetSize(); ++i)
            delete Info[i];
    }

    ArrayLH_POD<MethodInfo*, StatMV_VM_AbcFile_Mem> Info;
};

// Metadata: the name is not kept. 0x18 bytes.
class MetadataInfo : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    struct Item
    {
        SInd KeyInd;                            // +0x00
        SInd ValueInd;                          // +0x04
    };
    typedef ArrayLH<Item, StatMV_VM_AbcFile_Mem> ItemsT;

    ItemsT Items;                               // +0x00
};

class MetadataTable : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    ~MetadataTable()
    {
        for (UPInt i = 0; i < Info.GetSize(); ++i)
            delete Info[i];
    }

    ArrayLH_POD<MetadataInfo*, StatMV_VM_AbcFile_Mem> Info;
};

// A trait, 0x30 bytes.
class TraitInfo : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    enum Type { tSlot, tMethod, tGetter, tSetter, tClass, tFunction, tConst };
    enum Attr { aFinal = 0x10, aOverride = 0x20, aMetadata = 0x40 };

    struct MetaInfo
    {
        ArrayLH_POD<SInd, StatMV_VM_AbcFile_Mem> info;
    };

    TraitInfo() : name_ind(-1), SlotId(-1), Ind(-1) {}

    // The trait's name in the pool (0 = any type). 0x142546050
    const Multiname& GetName(const ConstPool& cp) const;

    Type GetType() const                { return static_cast<Type>(kind & 0x0F); }
    static bool HasMetaData(UInt8 kind) { return (kind & aMetadata) != 0; }

    UInt8       kind;                           // +0x00
    SInd        name_ind;                       // +0x04
    SInd        SlotId;                         // +0x08
    SInd        Ind;                            // +0x0c
    ValueDetail default_value;                  // +0x10
    MetaInfo    meta_info;                      // +0x18
};

class TraitTable : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    ~TraitTable()
    {
        for (UPInt i = 0; i < TraitInfos.GetSize(); ++i)
            delete TraitInfos[i];
    }

    ArrayLH_POD<TraitInfo*, StatMV_VM_AbcFile_Mem> TraitInfos;
};

class HasTraits : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    typedef ArrayLH_POD<SInd, StatMV_VM_AbcFile_Mem> ObjectTraits;

    ObjectTraits obj_traits;                    // +0x00
};

class HasCode : public HasTraits
{
public:
    HasCode() : method_info_ind(-1) {}

    SInd method_info_ind;                       // +0x18
};

// 0x48 bytes.
class Instance : public HasCode
{
public:
    enum { fProtectedNs = 0x08 };
    struct Interfaces
    {
        ArrayLH_POD<int, StatMV_VM_AbcFile_Mem> info;
    };

    Instance() : flags(0), name_ind(-1), super_name_ind(-1), protected_namespace_ind(-1) {}

    bool HasProtectedNamespace() const { return (flags & fProtectedNs) != 0; }
    // (appended, sfr22) the class flags of the UserDefined traits constructors (0x1423ef790)
    bool IsSealed() const    { return (flags & 0x01) != 0; }
    bool IsFinal() const     { return (flags & 0x02) != 0; }
    bool IsInterface() const { return (flags & 0x04) != 0; }

    UInt8      flags;                           // +0x20
    SInd       name_ind;                        // +0x24
    SInd       super_name_ind;                  // +0x28
    SInd       protected_namespace_ind;         // +0x2c
    Interfaces implemented_interfaces;          // +0x30
};

class StaticInfo : public HasCode
{
};

// 0x68 bytes.
class ClassInfo : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    Instance   inst_info;                       // +0x00
    StaticInfo stat_info;                       // +0x48
};

class ClassTable : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    ~ClassTable()
    {
        for (UPInt i = 0; i < Info.GetSize(); ++i)
            delete Info[i];
    }

    ArrayLH_POD<ClassInfo*, StatMV_VM_AbcFile_Mem> Info;
};

class ScriptInfo : public HasCode
{
};

class ScriptTable : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    ~ScriptTable()
    {
        for (UPInt i = 0; i < Info.GetSize(); ++i)
            delete Info[i];
    }

    ArrayLH_POD<ScriptInfo*, StatMV_VM_AbcFile_Mem> Info;
};

// A method body's byte code, 0x10 bytes.
class Code : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    // vftable 0x143181a00 (the scalar deleting destructor only).
    virtual ~Code() {}

    StringView code;                            // +0x08 u30 length, then the byte code

    // (appended, sfr24) the AVM2 opcodes (the byte values in the code); the enumerators are not modeled.
#if defined(_MSC_VER) && _MSC_VER < 1600 && !defined(__clang__)  // cl 15: no enum base
    enum OpCode;
#else
    enum OpCode : int;
#endif
};

// 0x58 bytes.
class MethodBodyInfo : public HasTraits
{
public:
    // 0x14 bytes.
    class ExceptionInfo
    {
    public:
        ExceptionInfo();                        // 0x142545670
        ExceptionInfo(SInd from, SInd to, SInd target, SInd exc_type_ind, SInd var_name_ind); // 0x142545650

        SInd from;                              // +0x00
        SInd to;                                // +0x04
        SInd target;                            // +0x08
        SInd exc_type_ind;                      // +0x0c
        SInd var_name_ind;                      // +0x10
    };
    struct Exception
    {
        // Advances from to the first handler whose [from, to] covers offset. 0x142545ff0
        bool FindExceptionInfo(UPInt offset, UPInt& from) const;

        ArrayLH_POD<ExceptionInfo, StatMV_VM_AbcFile_Mem> info;
    };

    MethodBodyInfo();                           // 0x142545680
    ~MethodBodyInfo();                          // 0x142545a80

    SInd      method_info_ind;                  // +0x18
    SInd      max_stack;                        // +0x1c
    SInd      local_reg_count;                  // +0x20
    SInd      init_scope_depth;                 // +0x24
    SInd      max_scope_depth;                  // +0x28
    Code      code;                             // +0x30
    Exception exception;                        // +0x40
};

class MethodBodyTable : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    ~MethodBodyTable();                         // 0x142545ac0

    ArrayLH_POD<MethodBodyInfo*, StatMV_VM_AbcFile_Mem> Info;
};

// A parsed ABC file.
class File : public NewOverrideBase<StatMV_VM_AbcFile_Mem>, public RefCountImpl
{
public:
    // (sfr24) as AbcFileWithMovieDef's inline ctor in MovieRoot::ExecuteAbc 0x1424f9d60 builds it (the versions stay unset).
    File() : DataSize(0), FileHandle(0), SwfFileOffset(0) {}
    ~File();                                    // 0x1425456e0 (vftable 0x14317b050)
    void Clear();                               // 0x142545dd0

    UInt32          DataSize;                   // +0x10
    String          Source;                     // +0x18
    UInt32          FileHandle;                 // +0x20
    int             SwfFileOffset;              // +0x24
    UInt16          MinorVersion;               // +0x28
    UInt16          MajorVersion;               // +0x2a
    ConstPool       Const_Pool;                 // +0x30
    MethodTable     Methods;                    // +0xf8
    MetadataTable   Metadata;                   // +0x110
    TraitTable      Traits;                     // +0x128
    ClassTable      AS3_Classes;                // +0x140
    ScriptTable     Scripts;                    // +0x158
    MethodBodyTable MethodBodies;               // +0x170
};

template <typename T> int Read16(const T*& p);  // 0x142545350 <UInt8>, little endian

inline UInt8 ReadU8(const UInt8*& ptr) { return *ptr++; }
inline bool Read8(const UInt8*& ptr, UInt8& v) { v = ReadU8(ptr); return true; }
inline bool Read(const UInt8*& ptr, SInt32& v) { v = ReadU30(ptr); return true; }
inline bool Read(const UInt8*& ptr, UInt32& v) { v = ReadU30(ptr); return true; }

bool Read(const UInt8*& ptr, MethodInfo& obj);  // 0x142565a30
bool Read(const UInt8*& ptr, ValueDetail& obj); // 0x142565c50

// The memory-buffer input stream File is read from.
class Reader : public NewOverrideBase<StatMV_VM_AbcFile_Mem>
{
public:
    Reader(const UInt8* data, UPInt size) : Size(size), CP(data) {}

    bool Read8(UInt8& v)   { return Abc::Read8(CP, v); }
    bool Read16(UInt16& v) { v = static_cast<UInt16>(Abc::Read16(CP)); return true; }
    bool Read(UInt32& v)   { return Abc::Read(CP, v); }
    bool Read(SInt32& v)   { return Abc::Read(CP, v); }

    bool Read(const ConstPool& cp, StringDataPtr& obj, const StringDataPtr& zero_val);
    bool Read(const ConstPool& cp, NamespaceInfo& obj);
    bool Read(NamespaceSetInfo& obj);
    bool Read(const ConstPool& cp, Multiname& obj);
    bool Read(ConstPool& obj);
    bool Read(ValueDetail& obj) { return Abc::Read(CP, obj); }
    bool Read(MethodInfo& obj)  { return Abc::Read(CP, obj); }
    bool Read(MethodTable& obj);
    bool Read(MetadataInfo& obj);
    bool Read(MetadataInfo::Item& obj);
    bool Read(MetadataTable& obj);
    bool Read(TraitInfo& obj);
    bool Read(TraitInfo::MetaInfo& obj);
    bool ReadTraits(TraitTable& t, HasTraits::ObjectTraits& obj_traits);
    bool Read(TraitTable& t, HasTraits& obj) { return ReadTraits(t, obj.obj_traits); }
    bool Read(TraitTable& t, HasCode& obj);
    bool Read(TraitTable& t, Instance& obj);
    bool Read(Instance::Interfaces& obj);
    bool Read(TraitTable& t, StaticInfo& obj);
    bool Read(TraitTable& t, ClassTable& obj);
    bool Read(TraitTable& t, ScriptInfo& obj);
    bool Read(TraitTable& t, ScriptTable& obj);
    bool Read(Code& obj);
    bool Read(TraitTable& t, MethodBodyInfo& obj);
    bool Read(MethodBodyInfo::ExceptionInfo& obj);
    bool Read(MethodBodyInfo::Exception& obj);
    bool Read(TraitTable& t, MethodTable& mt, MethodBodyTable& obj);
    bool Read(File& obj);

    const UPInt  Size;                          // +0x00
    const UInt8* CP;                            // +0x08
};

}}}} // namespace Scaleform::GFx::AS3::Abc

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::Abc::MethodBodyInfo) == 0x58, "MethodBodyInfo size");

#endif
