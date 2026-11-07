// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_04
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1424133c0-0x14242a640 .text$mn
// MS2-RANGE: 0x142409f00-0x142409fd0 .text$mn
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_thunkdefs.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_e4x.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_userdefined.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fntraits.h"
#define MS2_CALLFRAME_PUSHBACK_INLINE __forceinline
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/as3/as3_udbase.h"
#include "ms2/scaleform/include/kernel/sf_std.h"

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
// the registered class traits of a multiname (VM, 0x14250d760)
namespace Scaleform { namespace GFx { namespace AS3 { const ClassTraits::Traits* FUN_14250d760(VM& vm, const Multiname& mn); }}}
using Scaleform::GFx::AS3::FUN_14250d760;
// VM: the class traits registered for name/ns (loaded ones first, then the builtin table).
namespace Scaleform { namespace GFx { namespace AS3 {
ClassTraits::Traits* Sfr27GetClassTraitsByName(VM* vm, const ASString* name, const Instances::Namespace* ns);
}}}
// Traits::GetConstructor, out of line in the exe (the InstanceTraits copy).
Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t);

namespace Scaleform { namespace GFx { namespace AS3 {

// Instances::fl::Array::AS3slice argument 1 default
template <> struct ThunkMethodDefault<Instances::fl::Array, 8, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0xffffff; }
};
// thunk 0x1424133c0: Instances::fl::Array::AS3slice
template struct ThunkFunc2<Instances::fl::Array, 8, SPtr<Instances::fl::Array>, SInt32, SInt32>;
// thunk 0x142413510: Instances::fl::Array::AS3unshift
template struct ThunkFunc2<Instances::fl::Array, 9, Value, unsigned, const Value*>;
// thunk 0x142413530: Instances::fl::Array::AS3splice
template struct ThunkFunc2<Instances::fl::Array, 10, Value, unsigned, const Value*>;
// thunk 0x142413550: Instances::fl::Array::AS3filter
template struct ThunkFunc2<Instances::fl::Array, 16, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x1424136c0: Instances::fl::Array::AS3forEach
template struct ThunkFunc2<Instances::fl::Array, 17, const Value, const Value&, const Value&>;
// thunk 0x1424137a0: Instances::fl::Array::AS3map
template struct ThunkFunc2<Instances::fl::Array, 18, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x142413910: Instances::fl::Array::AS3some
template struct ThunkFunc2<Instances::fl::Array, 19, bool, const Value&, const Value&>;
// thunk 0x142413a30: Instances::fl::Array::AS3sort
template struct ThunkFunc2<Instances::fl::Array, 11, Value, unsigned, const Value*>;
// thunk 0x142413a50: Instances::fl::Array::AS3sortOn
template struct ThunkFunc2<Instances::fl::Array, 12, SPtr<Instances::fl::Array>, const Value&, const Value&>;
// thunk 0x142413bc0: Instances::fl::Array::AS3indexOf
template struct ThunkFunc2<Instances::fl::Array, 13, SInt32, const Value&, SInt32>;
// Instances::fl::Array::AS3lastIndexOf argument 1 default
template <> struct ThunkMethodDefault<Instances::fl::Array, 14, 1, SInt32>
{
    SF_INLINE static SInt32 Get(StringManager&) { return 0x7fffffff; }
};
// thunk 0x142413d70: Instances::fl::Array::AS3lastIndexOf
template struct ThunkFunc2<Instances::fl::Array, 14, SInt32, const Value&, SInt32>;
// thunk 0x142413f20: Instances::fl::Array::AS3every
template struct ThunkFunc2<Instances::fl::Array, 15, bool, const Value&, const Value&>;
// thunk 0x142414040: Instances::fl::Date::AS3setFullYear
template struct ThunkFunc2<Instances::fl::Date, 27, Value, unsigned, const Value*>;
// thunk 0x142414060: Instances::fl::Date::AS3setMonth
template struct ThunkFunc2<Instances::fl::Date, 28, Value, unsigned, const Value*>;
// thunk 0x142414080: Instances::fl::Date::AS3setDate
template struct ThunkFunc2<Instances::fl::Date, 29, Value, unsigned, const Value*>;
// thunk 0x1424140a0: Instances::fl::Date::AS3setHours
template struct ThunkFunc2<Instances::fl::Date, 30, Value, unsigned, const Value*>;
// thunk 0x1424140c0: Instances::fl::Date::AS3setMinutes
template struct ThunkFunc2<Instances::fl::Date, 31, Value, unsigned, const Value*>;
// thunk 0x1424140e0: Instances::fl::Date::AS3setSeconds
template struct ThunkFunc2<Instances::fl::Date, 32, Value, unsigned, const Value*>;
// thunk 0x142414100: Instances::fl::Date::AS3setMilliseconds
template struct ThunkFunc2<Instances::fl::Date, 33, Value, unsigned, const Value*>;
// thunk 0x142414120: Instances::fl::Date::AS3setUTCFullYear
template struct ThunkFunc2<Instances::fl::Date, 34, Value, unsigned, const Value*>;
// thunk 0x142414140: Instances::fl::Date::AS3setUTCMonth
template struct ThunkFunc2<Instances::fl::Date, 35, Value, unsigned, const Value*>;
// thunk 0x142414160: Instances::fl::Date::AS3setUTCDate
template struct ThunkFunc2<Instances::fl::Date, 36, Value, unsigned, const Value*>;
// thunk 0x142414180: Instances::fl::Date::AS3setUTCHours
template struct ThunkFunc2<Instances::fl::Date, 37, Value, unsigned, const Value*>;
// thunk 0x1424141a0: Instances::fl::Date::AS3setUTCMinutes
template struct ThunkFunc2<Instances::fl::Date, 38, Value, unsigned, const Value*>;
// thunk 0x1424141c0: Instances::fl::Date::AS3setUTCSeconds
template struct ThunkFunc2<Instances::fl::Date, 39, Value, unsigned, const Value*>;
// thunk 0x1424141e0: Instances::fl::Date::AS3setUTCMilliseconds
template struct ThunkFunc2<Instances::fl::Date, 40, Value, unsigned, const Value*>;
// thunk 0x142414200: Instances::fl::GlobalObjectCPP::parseInt
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 6, Value, unsigned, const Value*>;
// thunk 0x142414220: Instances::fl::GlobalObjectCPP::escape
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 8, Value, unsigned, const Value*>;
// thunk 0x142414240: Instances::fl::GlobalObjectCPP::unescape
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 9, Value, unsigned, const Value*>;
// thunk 0x142414260: Instances::fl::GlobalObjectCPP::trace
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 11, Value, unsigned, const Value*>;
// thunk 0x142414280: Instances::fl::GlobalObjectCPP::print
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 12, Value, unsigned, const Value*>;
// thunk 0x1424142a0: Instances::fl::GlobalObjectCPP::fscommand
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 30, Value, unsigned, const Value*>;
// thunk 0x1424142c0: Instances::fl::GlobalObjectCPP::setInterval
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 21, Value, unsigned, const Value*>;
// thunk 0x1424142e0: Instances::fl::GlobalObjectCPP::setTimeout
template struct ThunkFunc2<Instances::fl::GlobalObjectCPP, 22, Value, unsigned, const Value*>;
// thunk 0x142414300: Classes::fl::String::fromCharCode
template struct ThunkFunc2<Classes::fl::String, 1, Value, unsigned, const Value*>;
// thunk 0x142414320: Instances::fl::XML::AS3propertyIsEnumerable
template struct ThunkFunc2<Instances::fl::XML, 4, Value, unsigned, const Value*>;
// thunk 0x142414340: Instances::fl::XML::AS3elements
template struct ThunkFunc2<Instances::fl::XML, 16, Value, unsigned, const Value*>;
// thunk 0x142414360: Instances::fl::XML::AS3insertChildAfter
template struct ThunkFunc2<Instances::fl::XML, 20, Value, const Value&, const Value&>;
// thunk 0x142414440: Instances::fl::XML::AS3insertChildBefore
template struct ThunkFunc2<Instances::fl::XML, 21, Value, const Value&, const Value&>;
// thunk 0x142414520: Instances::fl::XML::AS3namespace_
template struct ThunkFunc2<Instances::fl::XML, 25, Value, unsigned, const Value*>;
// thunk 0x142414540: Instances::fl::XML::AS3processingInstructions
template struct ThunkFunc2<Instances::fl::XML, 30, Value, unsigned, const Value*>;
// thunk 0x142414560: Instances::fl::XML::AS3replace
template struct ThunkFunc2<Instances::fl::XML, 33, SPtr<Instances::fl::XML>, const Value&, const Value&>;
// thunk 0x1424146d0: Instances::fl::XML::AS3descendants
template struct ThunkFunc2<Instances::fl::XML, 15, Value, unsigned, const Value*>;
// thunk 0x1424146f0: Instances::fl::XMLList::AS3propertyIsEnumerable
template struct ThunkFunc2<Instances::fl::XMLList, 6, Value, unsigned, const Value*>;
// thunk 0x142414710: Instances::fl::XMLList::AS3processingInstructions
template struct ThunkFunc2<Instances::fl::XMLList, 21, Value, unsigned, const Value*>;
// thunk 0x142414730: Instances::fl::XMLList::AS3insertChildAfter
template struct ThunkFunc2<Instances::fl::XMLList, 28, Value, const Value&, const Value&>;
// thunk 0x142414810: Instances::fl::XMLList::AS3insertChildBefore
template struct ThunkFunc2<Instances::fl::XMLList, 29, Value, const Value&, const Value&>;
// thunk 0x1424148f0: Instances::fl::XMLList::AS3namespace_
template struct ThunkFunc2<Instances::fl::XMLList, 31, Value, unsigned, const Value*>;
// thunk 0x142414910: Instances::fl::XMLList::AS3replace
template struct ThunkFunc2<Instances::fl::XMLList, 36, SPtr<Instances::fl::XML>, const Value&, const Value&>;
// thunk 0x142414a80: Instances::fl::XMLList::AS3descendants
template struct ThunkFunc2<Instances::fl::XMLList, 14, Value, unsigned, const Value*>;
// thunk 0x142414aa0: Instances::fl::XMLList::AS3elements
template struct ThunkFunc2<Instances::fl::XMLList, 15, Value, unsigned, const Value*>;

}}} // namespace Scaleform::GFx::AS3
// THUNKS-END

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <sys/timeb.h>
#include <math.h>
#include "ms2/scaleform/kernel/sf_random.h"
#include "../include/kernel/sf_msgformat.h"
#include "../include/kernel/sf_utf8util.h"
#include "../include/gfx/gfx_asutils.h"
#include <string.h>
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/gfx_movieslots.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"

// MsgFormat::FormatD1 instances are out-of-line calls in the exe (exe 0x1423e8500 / 0x1423e85f0, defined in sfr_as3_01c).
template<> void Scaleform::MsgFormat::FormatD1<int>(const int& v);
template<> void Scaleform::MsgFormat::FormatD1<const char*>(const char* const& v);
// ConstructorMov<SPtr<ClassTraits::Traits> >::DestructArray is out of line in the exe (0x142409550, sfr_as3_03).
template<> void Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> >::
    DestructArray(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>* p, Scaleform::UPInt count);
// and the Value array's RemoveMultipleAt (0x14241ebb0, pinned below)
template<> SF_NOINLINE void Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveMultipleAt(Scaleform::UPInt index, Scaleform::UPInt num);
// the namespace array's RemoveAt is out of line in the exe (0x14241e8b0, pinned below)
template<> SF_NOINLINE void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>,
    Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveAt(Scaleform::UPInt index);

namespace Scaleform { namespace GFx { namespace AS3 {

// HashDH<UPInt, Value>'s node lookup through the exe's out-of-line GetAlt.
static SF_INLINE const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* saHashGetNode(const HashDH<UPInt, Value>& h,
                                                                                   const UPInt& key)
{
    typedef HashNode<UPInt, Value, FixedSizeHash<UPInt> > NodeT;
    typedef decltype(h.mHash) ContT;
    // The exe calls GetAlt out of line (0x1423e87e0); going through a member pointer keeps cl from inlining it.
    const NodeT* (ContT::*getAlt)(const UPInt&) const = &ContT::GetAlt<UPInt>;
    return (h.mHash.*getAlt)(key);
}

// HashDH<UPInt, Value>::Get over saHashGetNode.
static SF_INLINE const Value* saHashGet(const HashDH<UPInt, Value>& h, const UPInt& key)
{
    const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* p = saHashGetNode(h, key);
    return p ? &p->Second : 0;
}

// The exe inlines SparseArray::At into the Array string helpers.
static SF_INLINE const Value& saAt(const SparseArray& sa, UPInt ind)
{
    if (ind < sa.ValueA.GetSize())
        return sa.ValueA[ind];
    if (ind >= sa.ValueHLowInd && ind <= sa.ValueHHighInd)
    {
        const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* p = sa.ValueH.mHash.GetAlt(ind);
        const Value* v = p ? &p->Second : 0;
        if (v)
            return *v;
    }
    return sa.DefaultValue;
}

// The same with the out-of-range hole returned on its own path.
static SF_INLINE const Value& saAtRanged(const SparseArray& sa, UPInt ind)
{
    if (ind < sa.ValueA.GetSize())
        return sa.ValueA[ind];
    else if (ind < sa.ValueHLowInd || ind > sa.ValueHHighInd)
        return sa.DefaultValue;
    const Value* v = sa.ValueH.Get(ind);
    if (v)
        return *v;
    return sa.DefaultValue;
}

// Free helpers out of line in the exe (VM call/convert paths).
CheckResult ExecutePropertyUnsafe(VM& vm, const Multiname& prop_name, const Value& _this, Value& result, unsigned argc, const Value* argv); // 0x1424ff910
ASString AsString(const Value& v, StringManager& sm); // 0x1424eb7b0

// ---- Namespace / script global objects / user-defined classes ----

// @0x142414c30
String Instances::Namespace::GetAS3ObjectName() const
{
    return String(GetUri().ToCStr());
}

// @0x142414c00
String Instances::fl::GlobalObjectScript::GetAS3ObjectName() const
{
    return GetFile().GetAbcFile().Source;
}

// @0x142418d00
const SlotInfo* Instances::fl::GlobalObjectScript::InitializeOnDemand(const SlotInfo* si, const ASString& /*name*/,
                                                                      const Instances::Namespace& /*ns*/,
                                                                      UPInt& /*index*/)
{
    if (si)
        InitOnDemand();
    return si;
}

// @0x142414c60
String Classes::UserDefined::GetAS3ObjectName() const
{
    return String(GetTraits().GetQualifiedName().ToCStr());
}

// @0x142415a60
VMAbcFile& InstanceTraits::UserDefined::GetFile() const
{
    return GetScript().GetFile();
}

// @0x142423dc0
CheckResult InstanceTraits::UserDefined::SetupSlotValues(AS3::Object& for_obj) const
{
    if (GetParent() && !GetParent()->SetupSlotValues(for_obj))
        return false;
    return AS3::Traits::SetupSlotValues(GetFile(), class_info.inst_info, for_obj);
}

// @0x1424177b0
void InstanceTraits::UserDefined::InitOnDemand() const
{
    Script->InitOnDemand();
}

// @0x14241e140
CheckResult InstanceTraits::UserDefined::PreInit(const Value& _this) const
{
    return SetupSlotValues(*_this.GetObject());
}

// Abc::Instance::Interfaces::GetName (SDK): the multiname of interface i
static inline const Abc::Multiname& Sfr04InterfaceName(const Abc::Instance::Interfaces& ifs, const Abc::ConstPool& cp, UPInt i)
{
    return cp.GetMultiname(ifs.info[static_cast<UInt32>(i)]);
}

// @0x142425370
bool InstanceTraits::UserDefined::SupportsInterface(const Traits& t) const
{
    const Abc::Instance::Interfaces& ifs = class_info.inst_info.implemented_interfaces;
    VM& vm = GetVM();
    const UPInt n = ifs.info.GetSize();
    for (UPInt i = 0; i < n; i++)
    {
        const Multiname mn(GetFile(), Sfr04InterfaceName(ifs, GetFile().GetAbcFile().Const_Pool, i));

        const ClassTraits::Traits* ctr = FUN_14250d760(vm, mn);

        if (ctr)
        {
            InstanceTraits::Traits& itr = ctr->GetInstanceTraits();

            if (&itr == &t)
                return true;

            // Recursive handling of nested interfaces.
            if (itr.SupportsInterface(t))
                return true;
        }
    }
    return false;
}

// @0x142423d90
CheckResult ClassTraits::UserDefined::SetupSlotValues(AS3::Object& for_obj) const
{
    return AS3::Traits::SetupSlotValues(*File, class_info.stat_info, for_obj);
}

// MS2-FUNCTIONAL: the exe builds the class Value after the name call (argument evaluation order)
// @0x142418be0
const SlotInfo* Instances::fl::GlobalObjectCPP::InitializeOnDemand(const SlotInfo* si, const ASString& name,
                                                                   const Instances::Namespace& ns, UPInt& index)
{
    if (si == NULL && ns.GetKind() == Abc::NS_Public)
    {
        ClassTraits::Traits* ctr = ::Scaleform::GFx::AS3::Sfr27GetClassTraitsByName(&GetVM(), &name, &ns);
        if (ctr)
        {
            Class& cl = FUN_142508460(&ctr->GetInstanceTraits());
            si = &AddFixedSlotValuePair(cl.GetClassTraits().GetName(),
                Pickable<const Instances::Namespace>(&ns, PickValue), &cl.GetClassTraits(), Value(&cl), index);
        }
    }
    return si;
}

// @0x142421ac0
void Traits::SetConstructor(Class& c)
{
    pConstructor = &c;
}

static SF_INLINE ASString Sfr04SourceGet(Instances::fl::RegExp& re)
{
    ASString result(re.GetVM().GetStringManager().CreateEmptyString());
    result = re.GetVM().GetStringManager().CreateString(re.Pattern);
    return result;
}

// @0x142425890
ASString Instances::fl::RegExp::ToString()
{
    StringManager& sm = GetVM().GetStringManager();
    return sm.CreateConstString("/") + Sfr04SourceGet(*this) +
           sm.CreateConstString("/") + GetFlags();
}

// @0x142429920
__declspec(noinline) ASString Instances::fl::RegExp::GetFlags()
{
    ASString result = GetVM().GetStringManager().CreateEmptyString();
    const char* s = IsGlobal ? "g" : "";
    result.Append(s, strlen(s));
    s = (OptionFlags & 1) ? "i" : "";
    result.Append(s, strlen(s));
    s = ((UByte)((UInt32)OptionFlags >> 1) & 1) ? "m" : "";
    result.Append(s, strlen(s));
    s = ((UByte)((UInt32)OptionFlags >> 2) & 1) ? "s" : "";
    result.Append(s, strlen(s));
    s = ((UByte)((UInt32)OptionFlags >> 3) & 1) ? "x" : "";
    result.Append(s, strlen(s));
    return result;
}

// MS2-FUNCTIONAL: the exe keeps the inlined hash-node select as a cmove against a zero register; ours branches
// @0x142425540
ASString Instances::fl::Array::ToLocaleStringInternal() const
{
    StringBuffer buf(GetVM().GetMemoryHeap());
    for (UPInt i = 0; i < SA.GetSize(); ++i)
    {
        if (i > 0)
            buf.AppendString(",");
        const Value& v = saAt(SA, i);
        if (v.IsNullOrUndefined())
            continue;
        const Multiname prop_name(GetVM().GetPublicNamespace(), GetVM().GetStringManager().CreateConstString("toLocaleString"));
        Value r;
        if (!ExecutePropertyUnsafe(GetVM(), prop_name, v, r, 0, NULL))
            break;
        if (r.IsString())
            buf.AppendString(r.AsString().ToCStr());
        else
            buf.AppendString(AsString(r, GetVM().GetStringManager()).ToCStr());
    }
    return GetVM().GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
}

// MS2-FUNCTIONAL: the exe keeps the inlined hash-node select as a cmove against a zero register; ours branches
// @0x142425b50
ASString Instances::fl::Array::ToStringInternal(const ASString& sep) const
{
    StringBuffer buf(GetVM().GetMemoryHeap());
    for (UPInt i = 0; i < SA.GetSize(); ++i)
    {
        if (i > 0)
            buf.AppendString(sep.ToCStr());
        const Value& v = saAt(SA, i);
        if (!v.IsNullOrUndefined())
        {
            if (!v.Convert2String(buf))
                break;
        }
    }
    return GetVM().GetStringManager().CreateString(buf.ToCStr(), buf.GetSize());
}

// ---- Slots ----

// the parent test is the SDK's AbsoluteIndex < UPInt (a negative index counts as below), as a bool
// @0x142416fb0
const SlotInfo& Slots::GetSlotInfo(AbsoluteIndex ind) const
{
    if (ind < FirstOwnSlotNum)
        return Parent->GetSlotInfo(ind);
    return VArray[static_cast<UInt32>(ind.Get()) - FirstOwnSlotNum].Value;
}

// ---- Value: reference take-over of the function / namespace kinds ----

// @0x14241dc00
void Value::Pick(Instances::FunctionBase* v)
{
    Release();
    SetKind(kFunction);
    value = reinterpret_cast<Instances::Function*>(v);
}

// @0x14241dc60
void Value::Pick(Instances::Function* v)
{
    Release();
    SetKind(kFunction);
    value = v;
}

// @0x14241dcc0
void Value::Pick(Instances::Namespace* v)
{
    Release();
    SetKind(kNamespace);
    value = v;
}

// @0x14241dd20
void Value::Pick(Instances::ThunkFunction* v)
{
    Release();
    SetKind(kThunkFunction);
    value = v;
}

// @0x14241ddc0
void Value::PickUnsafe(Instances::Function* v)
{
    SetKind(kFunction);
    value = v;
}

// @0x14241dde0
void Value::PickUnsafe(Instances::FunctionBase* v)
{
    SetKind(kFunction);
    value = reinterpret_cast<Instances::Function*>(v);
}

// @0x14241de00
void Value::PickUnsafe(Instances::Namespace* v)
{
    SetKind(kNamespace);
    value = v;
}

// @0x14241de20
void Value::PickUnsafe(Instances::ThunkFunction* v)
{
    SetKind(kThunkFunction);
    value = v;
}


// ---- XML 1.0 (5th ed.) name productions ----

// @0x142419b10
CheckResult IsNameStartChar(int c)
{
    if (c == ':' || c == '_')
    {
        return true;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return true;
    }
    if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    if (c >= 0xC0 && c <= 0xD6)
    {
        return true;
    }
    if (c >= 0xD8 && c <= 0xF6)
    {
        return true;
    }
    if (c >= 0xF8 && c <= 0x2FF)
    {
        return true;
    }
    if (c >= 0x370 && c <= 0x37D)
    {
        return true;
    }
    if (c >= 0x37F && c <= 0x1FFF)
    {
        return true;
    }
    if (c >= 0x200C && c <= 0x200D)
    {
        return true;
    }
    if (c >= 0x2070 && c <= 0x218F)
    {
        return true;
    }
    if (c >= 0x2C00 && c <= 0x2FEF)
    {
        return true;
    }
    if (c >= 0x3001 && c <= 0xD7FF)
    {
        return true;
    }
    if (c >= 0xF900 && c <= 0xFDCF)
    {
        return true;
    }
    if (c >= 0xFDF0 && c <= 0xFFFD)
    {
        return true;
    }
    if (c >= 0x10000 && c <= 0xEFFFF)
    {
        return true;
    }
    return false;
}

// @0x142419aa0
CheckResult IsNameChar(int c)
{
    if (IsNameStartChar(c))
    {
        return true;
    }
    if (c == '-' || c == '.')
    {
        return true;
    }
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    if (c == 0xB7)
    {
        return true;
    }
    if (c >= 0x0300 && c <= 0x036F)
    {
        return true;
    }
    if (c >= 0x203F && c <= 0x2040)
    {
        return true;
    }
    return false;
}

// @0x142419a50
CheckResult IsNCNameStartChar(int c)
{
    return IsNameStartChar(c) && c != ':';
}

// @0x1424199d0
CheckResult IsNCNameChar(int c)
{
    return IsNameChar(c) && c != ':';
}

// @0x142419bf0
CheckResult IsValidName(const ASString& name)
{
    if (name.GetLength() == 0 || !IsNameStartChar(name[0]))
        return false;
    const unsigned len = name.GetLength();
    for (unsigned i = 1; i < len; ++i)
    {
        if (!IsNameChar(name[i]))
            return false;
    }
    return true;
}

// ---- SparseArray: dense ValueA, then sparse indices [ValueHLowInd, ValueHHighInd] in ValueH ----

// @0x142415de0
UPInt SparseArray::GetLeftEqualInd(UPInt start_from) const
{
    SPInt i = static_cast<SPInt>(start_from);
    for (; i >= 0; --i)
    {
        if (saHashGetNode(ValueH, i))
            break;
    }
    return static_cast<UPInt>(i);
}

// @0x142416eb0
UPInt SparseArray::GetRightEqualInd(UPInt start_from, UPInt end_ind) const
{
    UPInt i = start_from;
    for (; i <= end_ind; ++i)
    {
        if (saHashGetNode(ValueH, i))
            break;
    }
    return i;
}

// MS2-FUNCTIONAL: the hash key sits in the third home slot in the exe (first in ours); instructions are the same
// @0x142416000
SF_NOINLINE AbsoluteIndex SparseArray::GetNextArrayIndex(AbsoluteIndex ind) const
{
    const UPInt denseSize = ValueA.GetSize();
    if (!ind.IsValid())
    {
        if (denseSize != 0)
            return AbsoluteIndex(0);
        if (ValueH.GetSize() > 0)
            return AbsoluteIndex(ValueHLowInd);
    }
    else
    {
        if (static_cast<UPInt>(ind.Get()) < denseSize)
        {
            if (static_cast<UInt32>(ind.Get()) == denseSize - 1)
            {
                if (ValueH.GetSize() > 0)
                    return AbsoluteIndex(ValueHLowInd);
            }
            else
                return AbsoluteIndex(ind.Get() + 1);
        }
        if (static_cast<UInt32>(ind.Get()) >= ValueHLowInd && static_cast<UInt32>(ind.Get()) <= ValueHHighInd)
        {
            for (UPInt j = static_cast<UInt32>(ind.Get() + 1); j <= ValueHHighInd; ++j)
            {
                if (saHashGetNode(ValueH, j))
                    return AbsoluteIndex(j);
            }
        }
    }
    return AbsoluteIndex(-1);
}

#pragma inline_depth(2)
// @0x142427180
const Value& SparseArray::Top() const
{
    return saAtRanged(*this, Length - 1);
}
#pragma inline_depth()

// @0x14241e4b0
void SparseArray::PushBack(const Value& v)
{
    if (Length == ValueA.GetSize())
        ValueA.PushBack(v);
    else
    {
        ValueHHighInd = Length;
        ValueH.Set(ValueHHighInd, v);
    }
    ++Length;
}

// @0x14241d1b0
void SparseArray::MoveHashRight(UPInt first_ind, UPInt offset)
{
    Value v;
    for (UPInt i = ValueHHighInd + 1; i > first_ind; --i)
    {
        const UPInt ci = i - 1;
        if (ValueH.Get(ci, &v))
        {
            ValueH.Remove(ci);
            ValueH.Set(ci + offset, v);
        }
    }
}

// @0x14241e9d0
void SparseArray::RemoveHash(UPInt first_ind, UPInt num)
{
    for (UInt32 i = 0; i < num; ++i)
    {
        const UPInt ind = i + first_ind;
        if (saHashGetNode(ValueH, ind))
            ValueH.Remove(ind);
    }
}

// MS2-FUNCTIONAL: /O2 order only: pos+count lea operands and the inlined hash's two top key bytes are scheduled the other way round
// @0x14241ec80
void SparseArray::RemoveMultipleAt(UPInt pos, UPInt count)
{
    if (count == 0)
        return;

    if (pos < ValueA.GetSize())
    {
        const UPInt count_a = ValueA.GetSize() - pos;
        if (pos + count < ValueA.GetSize())
        {
            // the tail of ValueA moves into the hash
            const UPInt sizeA = ValueA.GetSize();
            for (UPInt i = pos + count; i < sizeA; ++i)
            {
                if (ValueHLowInd == 0)
                    ValueHLowInd = i;
                ValueH.Set(i, ValueA[i]);
                if (ValueHHighInd < i)
                    ValueHHighInd = i;
            }
        }
        ValueA.RemoveMultipleAt(pos, count_a);
    }

    if (!ValueH.IsEmpty() && ValueHLowInd < pos + count && ValueHHighInd >= pos)
    {
        if (ValueHLowInd >= pos && ValueHHighInd < pos + count)
        {
            ValueH.Clear();
            ValueHLowInd = 0;
            ValueHHighInd = 0;
        }
        else
        {
            RemoveHash(Alg::Max(pos, ValueHLowInd), count);
            if (ValueHHighInd < pos + count)
                ValueHHighInd = GetLeftEqualInd(pos);
            if (ValueHLowInd >= pos)
                ValueHLowInd = GetRightEqualInd(pos + count, ValueHHighInd);
        }
    }

    if (Length <= pos + count)
        Length = pos;
}

// MS2-FUNCTIONAL: same structure; register allocation and the inlined hash Get/Set/Remove layout differ
// @0x142420800
void SparseArray::Reverse()
{
    if (GetSize() == ValueA.GetSize())
    {
        // dense only
        SPInt lo = 0;
        SPInt hi = static_cast<SPInt>(ValueA.GetSize()) - 1;
        while (lo < hi)
        {
            Alg::Swap(ValueA[lo], ValueA[hi]);
            ++lo;
            --hi;
        }
    }
    else
    {
        // from and to are absolute indices
        UInt32 from = 0;
        UPInt to = GetSize() - 1;

        const UPInt sizeA = ValueA.GetSize();
        for (; from < sizeA; ++from, --to)
        {
            const Value tmp = ValueA[from];
            Set(from, saAt(*this, to));
            Set(to, tmp);
        }

        // hash only
        Value value_from;
        Value value_to;
        bool range_changed = false;
        while (from < to)
        {
            if (ValueH.Get(from, &value_from))
            {
                if (ValueH.Get(to, &value_to))
                {
                    ValueH.Set(to, value_from);
                    ValueH.Set(from, value_to);
                }
                else
                {
                    range_changed = true;
                    ValueH.Remove(from);
                    ValueH.Set(to, value_from);
                }
            }
            else if (ValueH.Get(to, &value_to))
            {
                range_changed = true;
                ValueH.Remove(to);
                ValueH.Set(from, value_to);
            }
            ++from;
            --to;
        }

        if (range_changed)
        {
            ValueHHighInd = GetLeftEqualInd(ValueHHighInd);
            ValueHLowInd = GetRightEqualInd(0, ValueHHighInd);
        }
    }
}

// SDK 4.3 branch structure. The CutHash branch reproduces an exe bug on purpose: when truncating below
// ValueHHighInd the shipped client reads the hash node key through a null node pointer and crashes. The SDK's
// fixed form is the Remove(ValueHHighInd--) loop.
// @0x14241fe30
void SparseArray::Resize(UPInt newLength)
{
    if (newLength == 0)
    {
        ValueA.Clear();
        ValueH.Clear();
        ValueHLowInd = 0;
        ValueHHighInd = 0;
    }
    else if (newLength <= ValueA.GetSize() && ValueA.GetSize() != 0)
    {
        ValueA.Resize(newLength);
        ValueH.Clear();
        ValueHLowInd = 0;
        ValueHHighInd = 0;
    }
    else if (newLength < ValueHLowInd)
    {
        ValueH.Clear();
        ValueHLowInd = 0;
        ValueHHighInd = 0;
    }
    else if (newLength < ValueHHighInd)
    {
        UPInt* volatile* node = NULL;
        do
        {
            ValueH.Remove(*(const UPInt*)((const char*)*node + 0x20));
        } while (newLength < ValueHHighInd);
        ValueHHighInd = *(const UPInt*)((const char*)*(UPInt**)NULL + 0x20);
    }
    Length = newLength;
}

// @0x1424213b0
void SparseArray::Set(UPInt ind, const Value& v)
{
    if (ind >= Length)
        Resize(ind + 1);

    if (ind < ValueA.GetSize())
        ValueA[ind].Assign(v);
    else if (ind == ValueA.GetSize())
    {
        ValueA.PushBack(v);

        // Pull the hash run that now continues the dense part into ValueA.
        Value hv;
        while (ValueA.GetSize() == ValueHLowInd)
        {
            const HashNode<UPInt, Value, FixedSizeHash<UPInt> >* p = saHashGetNode(ValueH, ValueHLowInd);
            if (!p)
                break;
            hv.Assign(p->Second);
            ValueH.Remove(ValueHLowInd);
            ValueA.PushBack(hv);
            if (ValueH.GetSize() > 0)
                ValueHLowInd = (*ValueH.Begin()).First;
            else
            {
                ValueH.Clear();
                ValueHHighInd = 0;
                ValueHLowInd = 0;
            }
        }
    }
    else
    {
        ValueH.Set(ind, v);
        if (ind < ValueHLowInd || ValueH.GetSize() == 1)
            ValueHLowInd = ind;
        if (ind > ValueHHighInd)
            ValueHHighInd = ind;
    }
}

// @0x142418d50
void SparseArray::Insert(UPInt pos, unsigned argc, const Value* argv)
{
    if (pos < ValueA.GetSize())
    {
        for (unsigned i = 0; i < argc; ++i)
            ValueA.InsertAt(pos + i, argv[i]);
        if (ValueHLowInd != 0)
        {
            MoveHashRight(ValueHLowInd, argc);
            ValueHLowInd += argc;
            ValueHHighInd += argc;
        }
    }
    else if (pos == ValueA.GetSize())
    {
        for (unsigned i = 0; i < argc; ++i)
            ValueA.PushBack(argv[i]);
        if (!ValueH.IsEmpty())
        {
            MoveHashRight(ValueHLowInd, argc);
            ValueHLowInd += argc;
            ValueHHighInd += argc;
        }
    }
    else
    {
        if (pos < ValueHLowInd)
        {
            MoveHashRight(ValueHLowInd, argc);
            ValueHHighInd += argc;
            ValueHLowInd = pos;
        }
        else if (pos <= ValueHHighInd)
        {
            MoveHashRight(pos, argc);
            ValueHHighInd += argc;
        }
        else
            ValueHHighInd = pos - 1 + argc;

        for (unsigned i = 0; i < argc; ++i)
            ValueH.Set(pos + i, argv[i]);
    }
    Length += argc;
}

namespace Instances { namespace fl
{
    // ---- Array: indices are the dense/sparse store, everything else goes to Object ----

    // Element ind of the store, DefaultValue for holes.
    static SF_INLINE const Value& ElementAt(const SparseArray& sa, UPInt ind)
    {
        if (ind < sa.ValueA.GetSize())
            return sa.ValueA[ind];
        if (ind >= sa.ValueHLowInd && ind <= sa.ValueHHighInd)
        {
            const Value* v = sa.ValueH.Get(ind);
            if (v)
                return *v;
        }
        return sa.DefaultValue;
    }

    // @0x142421ff0
    CheckResult Array::SetProperty(const Multiname& prop_name, const Value& value)
    {
        UInt32 ind;
        if (GetArrayInd(prop_name, ind))
        {
            SA.Set(ind, value);
            return true;
        }
        return Object::SetProperty(prop_name, value);
    }

#pragma inline_depth(2)
    // @0x142416730
    CheckResult Array::GetProperty(const Multiname& prop_name, Value& value)
    {
        UInt32 ind;
        if (GetArrayInd(prop_name, ind))
        {
            value.Assign(ElementAt(SA, ind));
            return true;
        }
        return Object::GetProperty(prop_name, value);
    }

    // @0x1424159a0
    void Array::GetDynamicProperty(AbsoluteIndex ind, Value& value)
    {
        value.Assign(saAtRanged(SA, static_cast<UInt32>(ind.Get())));
    }

#pragma inline_depth()
    // @0x142416200
    void Array::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
    {
        if (!ind.IsValid())
        {
            name.SetUndefined();
            return;
        }
        if (ind.Get() <= SA.GetSize())
            name.SetUInt32(static_cast<UInt32>(AbsoluteIndex(ind.Get() - 1).Get()));
        else
            Object::GetNextPropertyName(name, GlobalSlotIndex(ind.Get() - static_cast<UInt32>(SA.GetSize())));
    }

    // @0x142416100
    GlobalSlotIndex Array::GetNextDynPropIndex(GlobalSlotIndex ind) const
    {
        GlobalSlotIndex result(0);
        if (ind.Get() <= SA.GetSize())
        {
            const AbsoluteIndex next = SA.GetNextArrayIndex(AbsoluteIndex(static_cast<UPInt>(ind.Get()) - 1));
            if (next.IsValid())
            {
                result = GlobalSlotIndex(static_cast<UInt32>(next.Get()) + 1);
                return result;
            }
        }
        ind = ind.Get() < static_cast<UInt32>(SA.GetSize()) ? ind : GlobalSlotIndex(ind.Get() - static_cast<UInt32>(SA.GetSize()));
        result = Object::GetNextDynPropIndex(ind);
        if (result.IsValid())
            result = GlobalSlotIndex(result.Get() + static_cast<UInt32>(SA.GetSize()));
        return result;
    }

    // @0x142416520
    void Array::GetNextPropertyValue(Value& value, GlobalSlotIndex ind)
    {
        if (!ind.IsValid())
        {
            value.SetUndefined();
            return;
        }
        if (ind.Get() <= SA.GetSize())
            value.Assign(saAtRanged(SA, ind.Get() - 1));
        else
            Object::GetNextPropertyValue(value, GlobalSlotIndex(ind.Get() - static_cast<UInt32>(SA.GetSize())));
    }

    // @0x142429290
    void Array::lengthGet(UInt32& result)
    {
        result = static_cast<UInt32>(SA.GetSize());
    }
}} // namespace Instances::fl

namespace Instances { namespace fl
{
    // ---- Date: ECMA-262 15.9.1 time arithmetic ----

    static const Value::Number msPerSecond  = 1000.0;
    static const Value::Number msPerMinute  = 60000.0;
    static const Value::Number msPerHour    = 3600000.0;
    static const Value::Number msPerDay     = 86400000.0;

    // Days before the end of each month: common years, then leap years.
    static const SInt32 MonthEndDay[24] =
    {
        31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365,
        31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
    };

    static SF_INLINE bool IsLeapYear(SInt32 y)
    {
        return (y % 4) == 0 && ((y % 100) != 0 || (y % 400) == 0);
    }

    // Day number of the first day of year y.
    static SF_INLINE Value::Number DayFromYear(Value::Number y)
    {
        return ::floor((y - 1969.0) * 0.25) + (y - 1970.0) * 365.0 - ::floor((y - 1901.0) / 100.0) +
               ::floor((y - 1601.0) / 400.0);
    }

    static SF_INLINE Value::Number TimeFromYear(Value::Number y)
    {
        return msPerDay * DayFromYear(y);
    }

    // @0x142415730
    void Date::GetCurrentTimeValue(Value::Number* pTime, SInt32* pLocalTZA)
    {
        __timeb64 tb;
        TIME_ZONE_INFORMATION tzi;
        _ftime64(&tb);
        GetTimeZoneInformation(&tzi);
        *pLocalTZA = tzi.Bias * -60000;
        *pTime = static_cast<Value::Number>(tb.time) * 1000.0 + tb.millitm;
    }

    // @0x142417730
    Value::Number Date::HourFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerHour), 24.0);
        if (r < 0)
            r += 24.0;
        return r;
    }

    // @0x14241ccb0
    Value::Number Date::MinFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerMinute), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }

    // @0x142421230
    Value::Number Date::SecFromTime(Value::Number t)
    {
        Value::Number r = fmod(::floor(t / msPerSecond), 60.0);
        if (r < 0)
            r += 60.0;
        return r;
    }

    // @0x14241d500
    Value::Number Date::MsFromTime(Value::Number t)
    {
        Value::Number r = fmod(t, msPerSecond);
        if (r < 0)
            r += msPerSecond;
        return r;
    }

    // @0x142427260
    SInt32 Date::WeekDay(Value::Number t)
    {
        SInt32 r = static_cast<SInt32>(fmod(::floor(t / msPerDay) + 4.0, 7.0));
        return r < 0 ? r + 7 : r;
    }

    // MS2-FUNCTIONAL: binary-search register allocation differs
    // @0x1424272a0
    Value::Number Date::YearFromTime(Value::Number t)
    {
        // The year lies between the estimates for all-leap and all-common years.
        const SInt32 y1 = static_cast<SInt32>(::floor(t / 31536000000.0)) + 1970;
        const SInt32 y2 = static_cast<SInt32>(::floor(t / 31622400000.0)) + 1970;
        SInt32 lo = y2 <= y1 ? y2 : y1;
        SInt32 hi = y2 <= y1 ? y1 : y2;
        while (lo < hi)
        {
            const SInt32 mid = (lo + hi) / 2;
            if (TimeFromYear(mid) <= t)
            {
                if (t < TimeFromYear(mid + 1))
                    return mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return lo;
    }

    // The leap-year table is picked by an index offset into MonthEndDay (as in MakeDay).
    // @0x14241cdc0
    __declspec(noinline) SInt32 Date::MonthFromYearDay(SInt32 year, SInt32 day)
    {
        const SInt32 leap = ((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0)) ? 12 : 0;
        SInt32 m = 0;
        for (; m < 12; ++m)
        {
            if (MonthEndDay[leap + m] > day)
                break;
        }
        return m;
    }

    // @0x14241ccf0
    __declspec(noinline) SInt32 Date::MonthFromTime(Value::Number t)
    {
        const Value::Number y = YearFromTime(t);
        return MonthFromYearDay(static_cast<SInt32>(y), static_cast<SInt32>(::floor(t / msPerDay) - fl::DayFromYear(y)));
    }

    // @0x14241a230
    Value::Number Date::MakeDay(Value::Number year, Value::Number month, Value::Number date)
    {
        if (NumberUtil::IsNaNOrInfinity(year + month + date))
            return NumberUtil::NaN();

        const Value::Number m = static_cast<SInt32>(month);
        const Value::Number dt = static_cast<SInt32>(date);
        const Value::Number ym = static_cast<SInt32>(year) + ::floor(m / 12.0);
        Value::Number mn = fmod(m, 12.0);
        if (mn < 0)
            mn += 12.0;
        const Value::Number day = ::floor(fl::DayFromYear(ym));   // the file-local copy, inlined
        const SInt32 y = static_cast<SInt32>(ym);
        const SPInt leap = (y % 4) == 0 && ((y % 100) != 0 || (y % 400) == 0) ? 12 : 0;
        const SInt32 im = static_cast<SInt32>(mn);
        const SInt32 monthDay = im != 0 ? MonthEndDay[leap + im - 1] : 0;
        return monthDay + day + dt - 1.0;
    }

    static SF_INLINE Value::Number ToInteger(Value::Number v)
    {
        return v > 0 ? ::floor(v) : -::floor(-v);
    }

    // @0x14241c6a0
    Value::Number Date::MakeTime(Value::Number hour, Value::Number min, Value::Number sec, Value::Number ms)
    {
        if (NumberUtil::IsNaNOrInfinity(hour + min + sec + ms))
            return NumberUtil::NaN();
        const Value::Number h = ToInteger(hour);
        const Value::Number m = ToInteger(min);
        const Value::Number s = ToInteger(sec);
        const Value::Number milli = ToInteger(ms);
        return m * msPerMinute + h * msPerHour + s * msPerSecond + milli;
    }

    // @0x1424254f0
    Value::Number Date::TimeClip(Value::Number t)
    {
        if (NumberUtil::IsNaNOrInfinity(t) || fabs(t) > 8.64e15)
            return NumberUtil::NaN();
        return t > 0 ? ::floor(t) : ::ceil(t);
    }

    // ---- Date component editing and string helpers ----

    // Three-letter day and month names (exe data), shared with the Date string formatting.
    extern const char* DateWeekDayNames[7];
    extern const char* DateMonthNames[12];

    // @0x142419ff0
    Value::Number Date::DateHolder::MakeDate() const
    {
        const Value::Number day = Date::MakeDay(Entries[Date_Year], Entries[Date_Month], Entries[Date_Day]);
        return Date::TimeClip(day * msPerDay + TimeInDay - TZA);
    }

    // @0x14241a190
    __declspec(noinline) Value::Number Date::TimeHolder::MakeDate() const    // out of line in applyTimeArgs as in the exe
    {
        const Value::Number time = Date::MakeTime(Entries[Time_Hour], Entries[Time_Minute], Entries[Time_Second], Entries[Time_Ms]);
        return Date::TimeClip(Day * msPerDay + time - TZA);
    }

    // @0x14241a080
    SF_NOINLINE Value::Number Date::Parser::MakeDate(int localTZA) const
    {
        if (!Valid)
            return NumberUtil::NaN();
        if (HasTZA)
            localTZA = TZA;
        const Value::Number time = Date::MakeTime(Hour, Minute, Sec, 0);
        const Value::Number day = Date::MakeDay(Year, Month, Day);
        return Date::TimeClip(day * msPerDay + time - localTZA);
    }

    // @0x142427600
    void Date::applyDateArg(DateEntry arg, Value::Number value, Value::Number tza)
    {
        DateHolder h(TimeValue, tza);
        h.Entries[arg] = value;
        TimeValue = h.MakeDate();
    }

    // @0x1424276e0
    void Date::applyDateArgs(Value& result, unsigned argc, const Value* const argv, DateEntry firstArg, Value::Number tza)
    {
        if (argc > 0)
        {
            DateHolder h(TimeValue, tza);
            if (argc > (unsigned)(Date_Entry_Count - firstArg))
                argc = Date_Entry_Count - firstArg;
            if (!argv[0].Convert2Number(h.Entries[firstArg]))
                return;
            if (argc >= 2)
                if (!argv[1].Convert2Number(h.Entries[firstArg + 1]))
                    return;
            if (argc >= 3)
                if (!argv[2].Convert2Number(h.Entries[firstArg + 2]))
                    return;
            TimeValue = h.MakeDate();
        }
        result.SetNumber(TimeValue);
    }

    // @0x142427810
    void Date::applyTimeArg(TimeEntry arg, Value::Number value, Value::Number tza)
    {
        TimeHolder h(TimeValue, tza);
        h.Entries[arg] = value;
        // MakeDate's sum the other way round: the day is added to MakeTime's result
        TimeValue = TimeClip(MakeTime(h.Entries[Time_Hour], h.Entries[Time_Minute], h.Entries[Time_Second], h.Entries[Time_Ms])
                             + h.Day * msPerDay - h.TZA);
    }

    // @0x142427900
    void Date::applyTimeArgs(Value& result, unsigned argc, const Value* const argv, TimeEntry firstArg, Value::Number tza)
    {
        if (argc > 0)
        {
            TimeHolder h(TimeValue, tza);
            if (argc > (unsigned)(Time_Entry_Count - firstArg))
                argc = Time_Entry_Count - firstArg;
            if (!argv[0].Convert2Number(h.Entries[firstArg]))
                return;
            if (argc >= 2)
                if (!argv[1].Convert2Number(h.Entries[firstArg + 1]))
                    return;
            if (argc >= 3)
                if (!argv[2].Convert2Number(h.Entries[firstArg + 2]))
                    return;
            if (argc >= 4)
                if (!argv[3].Convert2Number(h.Entries[firstArg + 3]))
                    return;
            TimeValue = h.MakeDate();
        }
        result.SetNumber(TimeValue);
    }

    // @0x142427f10
    Value::Number Date::decodeUTCArgs(unsigned argc, const Value* const argv, Value::Number tza)
    {
        // (year, month[, date[, hours[, minutes[, seconds[, ms]]]]]); two-digit years are 19xx.
        Value::Number yearArg;
        if (!argv[0].Convert2Number(yearArg))
            return 0;
        Value::Number year = (int(yearArg) > 99 || (int)yearArg < 0) ? yearArg : Value::Number(1900.0) + yearArg;
        Value::Number month;
        if (!argv[1].Convert2Number(month))
            return 0;

        Value::Number date = 1, hours = 0, minutes = 0, seconds = 0, ms = 0;
        if (argc >= 3 && !argv[2].Convert2Number(date))
            return 0;
        if (argc >= 4)
        {
            if (!argv[3].Convert2Number(hours))
                return 0;
            hours = static_cast<SInt32>(hours);
        }
        if (argc >= 5)
        {
            if (!argv[4].Convert2Number(minutes))
                return 0;
            minutes = static_cast<SInt32>(minutes);
        }
        if (argc >= 6)
        {
            if (!argv[5].Convert2Number(seconds))
                return 0;
            seconds = static_cast<SInt32>(seconds);
        }
        if (argc >= 7)
        {
            if (!argv[6].Convert2Number(ms))
                return 0;
            ms = static_cast<SInt32>(ms);
        }

        const Value::Number time = MakeTime(hours, minutes, seconds, ms);
        return TimeClip(MakeDay(year, month, date) * msPerDay + time - tza);
    }

    // The kind of a date-string word: AM/PM, GMT/UTC, a week-day name or a month name (with its index).
    // @0x142428e10
    Date::Parser::StringType Date::Parser::interpretDateString(const char* pstr, SPInt length, int* index)
    {
        if (length == 2)
        {
            if (pstr[1] == 'M')
            {
                if (pstr[0] == 'A')
                    return String_AM;
                if (pstr[0] == 'P')
                    return String_PM;
            }
        }
        else if (length == 3)
        {
            if (memcmp(pstr, "GMT", 3) == 0)
                return String_GMT;
            if (memcmp(pstr, "UTC", 3) == 0)
                return String_UTC;
            for (int i = 0; i < 7; ++i)
            {
                if (memcmp(pstr, DateWeekDayNames[i], 3) == 0)
                {
                    *index = i;
                    return String_WeekDay;
                }
            }
            for (int i = 0; i < 12; ++i)
            {
                if (memcmp(pstr, DateMonthNames[i], 3) == 0)
                {
                    *index = i;
                    return String_Month;
                }
            }
        }
        return String_Invalid;
    }

    // MS2-FUNCTIONAL: register allocation only: the exe keeps needTime in r12 and bufferSize in r15, ours swaps them.
    // The TimeHolder sits in its own block so its slot is reused by the Sink temp, as in the exe.
    // @0x1424284c0
    UPInt Date::formatDateTimeString(char* buffer, UPInt bufferSize, Value::Number t, int tza,
                                     bool needDate, bool needTime, bool utc)
    {
        if (NumberUtil::IsNaN(t))
        {
            memcpy(buffer, "Invalid Date", 13);
            return 12;
        }

        if (!utc) t += tza;

        UPInt size = 0;
        DateHolder dh(t, 0.0);

        if (needDate)
        {
            int weekDay = WeekDay(t);
            const int day = static_cast<int>(dh.Entries[Date_Day]);
            MsgFormat f(MsgFormat::Sink(StringDataPtr(buffer, bufferSize)));
            f.Parse("{0} {1} {2} ");
            f.FormatD1(SF_EXE_DATA(DateWeekDayNames)[weekDay]);
            f.FormatD1(SF_EXE_DATA(DateMonthNames)[static_cast<int>(dh.Entries[Date_Month])]);
            f.FormatD1(day);
            f.FinishFormatD();
            size += f.GetStrSize();
        }

        if (needTime)
        {
            int         tzaDelta;
            const char* gmtString;
            const char* format;
            int         hour, minute, second;
            {
                TimeHolder  th(t, 0.0);
                int         tzaMinutes = (tza / 60000);
                tzaDelta   = (tzaMinutes / 60) * 100 + tzaMinutes % 60;
                gmtString  = "GMT+";
                format     = "{0:02}:{1:02}:{2:02}";

                if (!utc)
                {
                    format = "{0:02}:{1:02}:{2:02} {3}{4:04}";
                    if (tzaDelta < 0)
                    {
                        tzaDelta  = -tzaDelta;
                        gmtString = "GMT-";
                    }
                }
                second = (int)th.Entries[Time_Second];
                minute = (int)th.Entries[Time_Minute];
                hour = (int)th.Entries[Time_Hour];
            }

            size += Format(MsgFormat::Sink(StringDataPtr(buffer+size, bufferSize-size)), format,
                           hour, minute, second, gmtString, tzaDelta);
        }

        if (needDate)
        {
            size += Format(MsgFormat::Sink(StringDataPtr(buffer+size, bufferSize-size)),
                           needTime ? " {0}" : "{0}", (int)dh.Entries[Date_Year]);
        }

        if (needTime && utc)
        {
            memcpy(buffer + size, " UTC", 5);
            size += 4;
        }
        return size;
    }

    // ---- Date property getters (UTC forms read TimeValue, the local ones add LocalTZA) ----

    // @0x142427c60
    void Date::dateUTCGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : DateFromTime(t);
    }

    // @0x1424289a0
    void Date::fullYearGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        if (NumberUtil::IsNaN(t))
        {
            result = t;
            return;
        }
        result = YearFromTime(t + LocalTZA);
    }

    // @0x142428a20
    void Date::fullYearUTCGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : YearFromTime(t);
    }

    // @0x142429660
    void Date::millisecondsUTCGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : MsFromTime(t);
    }

    // @0x1424298a0
    void Date::monthUTCGet(Value::Number& result)
    {
        const Value::Number t = TimeValue;
        result = NumberUtil::IsNaN(t) ? t : MonthFromTime(t);
    }

    // @0x142429bd0
    void GlobalObjectCPP::parseInt(Value& result, unsigned argc, const Value* argv)
    {
        ASString str = GetVM().GetStringManager().GetBuiltin(AS3Builtin_NaN);
        if (argc >= 1 && !argv[0].Convert2String(str))
            return;
        SInt32 radix = 0;
        const UInt32 len = str.GetSize();
        UInt32 endIndex = 0;
        if (len == 0)
        {
            result = Value(NumberUtil::NaN());
            return;
        }
        if (argc >= 2 && !argv[1].Convert2Int32(radix))
            return;
        result = Value(NumberUtil::StringToInt(str.ToCStr(), len, radix, &endIndex));
    }

    // @0x142429af0
    void GlobalObjectCPP::parseFloat(Value::Number& result, const ASString& str)
    {
        UInt32 len = str.GetSize();
        UInt32 offset = 0;
        const char* cstr = str.ToCStr();
        offset = static_cast<UInt32>(UTF8Util::GetByteIndex(ASUtils::SkipWhiteSpace(cstr), cstr, len));
        const char* numstr = cstr + offset;
        if (!strncmp(numstr, "0x", 2) || !strncmp(numstr, "0X", 2))
            result = 0.0;
        else
            result = NumberUtil::StringToDouble(numstr, len - offset, &offset);
    }
}} // namespace Instances::fl

namespace Classes { namespace fl
{
    // @0x142427200
    void Date::UTC(Value& result, unsigned argc, const Value* argv)
    {
        result.SetNumber(Instances::fl::Date::decodeUTCArgs(argc, argv, 0));
    }

    // ---- Math ----

    // @0x1424274f0
    void Math::abs(Value::Number& result, Value::Number v)
    {
        if (NumberUtil::IsNEGATIVE_ZERO(v))
        {
            result = 0.0;
            return;
        }
        result = fabs(v);
    }

    // @0x142427540
    void Math::acos(Value::Number& result, Value::Number v)
    {
        result = ::acos(v);
    }

    // @0x142427a60
    void Math::asin(Value::Number& result, Value::Number v)
    {
        result = ::asin(v);
    }

    // @0x142427b90
    void Math::atan(Value::Number& result, Value::Number v)
    {
        result = ::atan(v);
    }

    // @0x142427a80
    void Math::atan2(Value::Number& result, Value::Number y, Value::Number x)
    {
        // atan2 of two infinities is the quadrant diagonal (PI scaled in a local, then stored).
        if (NumberUtil::IsPOSITIVE_INFINITY(y))
        {
            if (NumberUtil::IsPOSITIVE_INFINITY(x))
            {
                Value::Number r = PI;
                r *= 0.25;
                result = r;
            }
            else if (NumberUtil::IsNEGATIVE_INFINITY(x))
            {
                Value::Number r = PI;
                r *= 0.75;
                result = r;
            }
            else
            {
                Value::Number r = PI;
                r *= 0.5;
                result = r;
            }
            return;
        }
        if (NumberUtil::IsNEGATIVE_INFINITY(y))
        {
            if (NumberUtil::IsPOSITIVE_INFINITY(x))
            {
                Value::Number r = PI;
                r *= -0.25;
                result = r;
            }
            else if (NumberUtil::IsNEGATIVE_INFINITY(x))
            {
                Value::Number r = PI;
                r *= -0.75;
                result = r;
            }
            else
            {
                Value::Number r = PI;
                r *= -0.5;
                result = r;
            }
            return;
        }
        result = ::atan2(y, x);
    }

    // @0x142427bb0
    void Math::ceil(Value::Number& result, Value::Number v)
    {
        result = ::ceil(v);
    }

    // @0x142427c10
    void Math::cos(Value::Number& result, Value::Number v)
    {
        result = ::cos(v);
    }

    // @0x142428470
    void Math::exp(Value::Number& result, Value::Number v)
    {
        result = ::exp(v);
    }

    // @0x1424284a0
    void Math::floor(Value::Number& result, Value::Number v)
    {
        result = ::floor(v);
    }

    // @0x1424294d0
    void Math::log(Value::Number& result, Value::Number v)
    {
        result = ::log(v);
    }

    // @0x1424294f0
    void Math::max(Value& result, unsigned argc, const Value* argv)
    {
        if (argc)
        {
            result.Assign(argv[0]);
            for (unsigned i = 1; i < argc; ++i)
            {
                Boolean3 cmp;
                if (!AbstractLessThan(cmp, argv[i], result))
                    return;
                if (cmp == undefined3)
                {
                    result.SetNumber(NumberUtil::NaN());
                    return;
                }
                if (cmp == false3)
                    result.Assign(argv[i]);
            }
            result.ToNumberValueInline();
        }
        else
            result.SetNumber(NumberUtil::NEGATIVE_INFINITY());
    }

    // @0x1424296e0
    void Math::min(Value& result, unsigned argc, const Value* argv)
    {
        if (argc)
        {
            result.Assign(argv[0]);
            for (unsigned i = 1; i < argc; ++i)
            {
                Boolean3 cmp;
                if (!AbstractLessThan(cmp, result, argv[i]))
                    return;
                if (cmp == undefined3)
                {
                    result.SetNumber(NumberUtil::NaN());
                    return;
                }
                if (cmp == false3)
                    result.Assign(argv[i]);
            }
            result.ToNumberValueInline();
        }
        else
            result.SetNumber(NumberUtil::POSITIVE_INFINITY());
    }

    // @0x142429a70
    void Date::parse(Value::Number& result, const Value& v)
    {
        ASString s = GetVM().GetStringManager().CreateEmptyString();
        if (v.Convert2String(s))
        {
            Instances::fl::Date::Parser p(s.ToCStr());
            result = p.MakeDate(0);
        }
    }

    // @0x142429d40
    void Math::pow(Value::Number& result, Value::Number x, Value::Number y)
    {
        if (y == 0.0)
        {
            result = 1.0;
            return;
        }
        if ((x == 1.0 || x == -1.0) && NumberUtil::IsNaNOrInfinity(y))
        {
            result = NumberUtil::NaN();
            return;
        }
        result = ::pow(x, y);
    }

    // @0x142429fb0
    void Math::random(Value::Number& result)
    {
        result = Alg::Random::NextRandom() / 4294967295.0;
    }

    // @0x142429fe0
    void Math::round(Value::Number& result, Value::Number v)
    {
        if (NumberUtil::IsNaNOrInfinity(v))
        {
            result = v;
            return;
        }
        result = ::floor(v + 0.5);
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances { namespace fl
{
    // @0x142427cf0
    void GlobalObjectCPP::decodeURI(ASString& result, const ASString& uri)
    {
        String out;
        if (!ASUtils::AS3::Unescape(uri.ToCStr(), uri.GetSize(), out))
        {
            GetVM().ThrowURIError(VM::Error(VM::eInvalidURIError, GetVM(), "decodeURI"));
            return;
        }
        result = GetVM().GetStringManager().CreateString(out.ToCStr(), out.GetSize());
    }

    // @0x142427e00
    void GlobalObjectCPP::decodeURIComponent(ASString& result, const ASString& uri)
    {
        String out;
        if (!ASUtils::AS3::Unescape(uri.ToCStr(), uri.GetSize(), out))
        {
            GetVM().ThrowURIError(VM::Error(VM::eInvalidURIError, GetVM(), "decodeURI"));
            return;
        }
        result = GetVM().GetStringManager().CreateString(out.ToCStr(), out.GetSize());
    }

    // @0x142428140
    void GlobalObjectCPP::encodeURI(ASString& result, const ASString& uri)
    {
        String out;
        ASUtils::AS3::EncodeURI(uri.ToCStr(), uri.GetSize(), out);
        result = GetVM().GetStringManager().CreateString(out);
    }

    // @0x142428210
    void GlobalObjectCPP::encodeURIComponent(ASString& result, const ASString& uri)
    {
        String out;
        ASUtils::AS3::EncodeURIComponent(uri.ToCStr(), uri.GetSize(), out);
        result = GetVM().GetStringManager().CreateString(out);
    }

    // @0x1424282f0
    void GlobalObjectCPP::escape(Value& result, unsigned argc, const Value* argv)
    {
        if (argc > 0)
        {
            if (argv[0].IsNullOrUndefined())
            {
                result.Assign(GetVM().GetStringManager().GetBuiltin(AS3Builtin_null));
                return;
            }
            {
                ASString str = GetVM().GetStringManager().CreateEmptyString();
                if (argv[0].Convert2String(str))
                {
                    String out;
                    ASUtils::AS3::Escape(str.ToCStr(), str.GetSize(), out);
                    result.Assign(GetVM().GetStringManager().CreateString(out.ToCStr(), out.GetSize()));
                }
            }
        }
        else
            result.Assign(GetVM().GetStringManager().GetBuiltin(AS3Builtin_undefined));
    }

    // The movie's fscommand handler (MovieImpl+0x238): a State whose slot 1 is the callback.
    class FSCommandHandlerSlots : public RefCountBase<FSCommandHandlerSlots, Stat_Default_Mem>
    {
    public:
        virtual void Callback(MovieImpl* pmovie, const char* pcommand, const char* parg) = 0;
    };

    // @0x142428890
    void GlobalObjectCPP::fscommand(Value& result, unsigned argc, const Value* argv)
    {
        SF_UNUSED(result);
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        FSCommandHandlerSlots* phandler = static_cast<FSCommandHandlerSlots*>(proot->pFSCommandHandler);
        if (phandler && argc > 0)
        {
            ASString command = argv[0].AsString();
            ASString args = argc > 1 ? argv[1].AsString() : GetVM().GetStringManager().GetBuiltin(AS3Builtin_empty_);
            phandler->Callback(proot, command.ToCStr(), args.ToCStr());
        }
    }

    // @0x142428a80
    void GlobalObjectCPP::getDefinitionByName(Value& result, const ASString& name)
    {
        Class* c = GetVM().GetClass(StringDataPtr(name.ToCStr()));
        if (c)
            result.Assign(c);
        else
            result.SetUndefined();
    }

    // @0x142428b70
    void GlobalObjectCPP::getQualifiedClassName(ASString& result, const Value& v)
    {
        const InstanceTraits::Traits& itr = GetVM().GetInstanceTraits(v);
        result = itr.GetQualifiedName();
    }

    // @0x142428be0
    void GlobalObjectCPP::getQualifiedSuperclassName(Value& result, const Value& v)
    {
        const InstanceTraits::Traits& itr = GetVM().GetInstanceTraits(v);
        if (itr.GetParent())
            result.Assign(itr.GetParent()->GetQualifiedName());
        else
            result.SetNull();
    }
    // The Error's string form followed by its stack trace on a new line.
    // @0x142428c80
    void Error::getStackTrace(ASString& result)
    {
        toStringProto(result);
        const String trace = String("\n") + String(StackTrace.ToCStr(), StackTrace.GetSize());
        result += trace.ToCStr();
    }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Instances
{
    // @0x1424291d0
    void ThunkFunction::length(Value& result, unsigned, const Value*)
    {
        const Value f(Function);
        const ThunkInfo& ti = f.AsThunk();
        unsigned n = ti.GetMaxArgNum();
        if (n == 0x3ff)
            n = ti.GetMinArgNum();
        result.SetUInt32(n);
    }
} // namespace Instances

namespace Classes { namespace fl
{
    // @0x142428b20
    void Error::getErrorMessage(ASString& result, SInt32)
    {
        SF_UNUSED(result);
        VM& vm = GetVM();
        vm.ThrowError(VM::Error(VM::eNotImplementedError, vm, "class_::Error::getErrorMessage()"));
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

Scaleform::GFx::AS3::Class& FUN_142508460(const Scaleform::GFx::AS3::Traits* t);  // Traits::GetConstructor, out of line
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e3a0[7];   // Classes::fl::Object prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e7f0[2];   // Classes::fl::Boolean prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d6e8[1];   // Classes::fl::Error prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e690[2];   // Classes::fl::Namespace prototype methods
// The exe's table is at 0x14313d600 (0x14313d610 is &[0].Name, which the exe's lea addresses); the data unit split
// it at 0x14313d610 and dropped [0].Method/ResultType, so [i].Name read a zero field. Classes::fl::Array prototype
// methods (type-checked), kept local.
struct Sd_14313d9e0; extern Sd_14313d9e0 DAT_14313d9e0;
// The result type is the exe's String type info; its address cannot sit in static data (ADDR64 on an exe global),
// so the table is filled at run time.
__declspec(noinline) static const Scaleform::GFx::AS3::TypeInfo* ArrayProtoResultType()
{
    return (const Scaleform::GFx::AS3::TypeInfo*)&DAT_14313d9e0;
}
static Scaleform::GFx::AS3::ThunkInfo s_ArrayProtoThunks[2];
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e840[2];   // Classes::fl::String prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d850[6];   // Classes::fl::Number prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d6a0[1];   // Classes::fl::QName prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_143a2d128[1];   // Classes::fl::RegExp prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e8e0[3];   // Classes::fl::XML prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313d650[2];   // Classes::fl::XMLList prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e5a0[6];   // Classes::fl::int_ prototype methods
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e700[6];   // Classes::fl::uint prototype methods

namespace Scaleform { namespace GFx { namespace AS3 {

namespace Classes { namespace fl
{
    // The prototype methods: name -> thunk, not enumerable.
    template <unsigned N>
    static SF_INLINE void AddDynamicFuncs(AS3::Object& obj, const ThunkInfo (&f)[N])
    {
        for (unsigned i = 0; i < N; ++i)
        {
            const ThunkInfo& ti = f[i];
            obj.AddDynamicSlotValuePair(obj.GetVM().GetStringManager().CreateConstString(ti.Name), Value(ti),
                                        SlotInfo::aDontEnum);
        }
    }

    // @0x142417f60
    void Object::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e3a0);
        AddConstructor(obj);
    }

    // @0x142417a30
    void Boolean::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e7f0);
        AddConstructor(obj);
    }

    // @0x142417b40
    void Error::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313d6e8);
        AddConstructor(obj);
    }

    // @0x142417d40
    void Namespace::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e690);
        AddConstructor(obj);
    }

    // @0x142417e50
    void Number::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313d850);
        AddConstructor(obj);
    }

    // @0x142418070
    void QName::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313d6a0);
        AddConstructor(obj);
    }

    // @0x142418160
    void RegExp::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        InitPrototypeFromVTableCheckType(obj);
        AddDynamicFuncs(obj, DAT_143a2d128);
        // (no constructor slot: RegExp's prototype keeps its own)
    }

    // The prototype methods go through a closure that checks the type of 'this' (so toString.toString() is a
    // function).
    // MS2-FUNCTIONAL: the exe inlines the FunctionBase constructor here as well
    // @0x142417800
    void Array::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        InitPrototypeFromVTableCheckType(obj);

        const Classes::Function& cf =
            static_cast<const Classes::Function&>(FUN_142508460(&GetVM().GetClassTraitsFunction().GetInstanceTraits()));
        InstanceTraits::Traits& itr = GetClassTraits().GetInstanceTraits();
        // The check-type instances keep a pointer to their ThunkInfo, so the table must outlive this call.
        s_ArrayProtoThunks[0] = {&Instances::fl::Array::toLocaleStringProto, ArrayProtoResultType(), "toLocaleString", 0};
        s_ArrayProtoThunks[1] = {&Instances::fl::Array::toStringProto, ArrayProtoResultType(), "toString", 0};
        for (unsigned i = 0; i < 2; ++i)
        {
            Value f(cf.MakeCheckTypeInstance(*this, s_ArrayProtoThunks[i], itr));
            obj.AddDynamicSlotValuePair(GetVM().GetStringManager().CreateConstString(s_ArrayProtoThunks[i].Name), f,
                                        SlotInfo::aDontEnum);
        }
        AddConstructor(obj);
    }

    // @0x142418250
    void String::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        InitPrototypeFromVTable(obj, &Class::ConvertCopy);
        AddDynamicFuncs(obj, DAT_14313e840);
        AddConstructor(obj);
    }

    // @0x142418390
    void XML::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        InitPrototypeFromVTableCheckType(obj);
        AddDynamicFuncs(obj, DAT_14313e8e0);
        AddConstructor(obj);
    }

    // @0x1424184b0
    void XMLList::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        InitPrototypeFromVTableCheckType(obj);
        AddDynamicFuncs(obj, DAT_14313d650);
        AddConstructor(obj);
    }

    // @0x1424185d0
    void int_::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e5a0);
        AddConstructor(obj);
    }

    // @0x1424186e0
    void uint::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        AddDynamicFuncs(obj, DAT_14313e700);
        AddConstructor(obj);
    }
}} // namespace Classes::fl

}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// The out-of-line copies of the inline Value setters the exe keeps in this range.
extern void (Value::* const ValueSetBool)(bool);
void (Value::* const ValueSetBool)(bool) = &Value::SetBool;
extern void (Value::* const ValueSetNull)();
void (Value::* const ValueSetNull)() = &Value::SetNull;
extern void (Value::* const ValueSetSInt32)(SInt32);
void (Value::* const ValueSetSInt32)(SInt32) = &Value::SetSInt32;
extern bool (Value::* const ValueIsCallable)() const;
bool (Value::* const ValueIsCallable)() const = &Value::IsCallable;
extern bool (* const pIsXMLObject)(const Value&);
bool (* const pIsXMLObject)(const Value&) = &IsXMLObject;
extern bool (* const pIsXMLListObject)(const Value&);
bool (* const pIsXMLListObject)(const Value&) = &IsXMLListObject;
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// The class Class never makes objects through its traits.
// @0x14241be90
void ClassTraits::ClassClass::MakeObject(Value&, AS3::Traits*)
{
}

// The Object class has no slot values of its own.
// @0x142423d80
void Classes::fl::Object::SetupSlotValues(AS3::Object&) const
{
}
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 {
// Inline copies of the instance ctors (their out-of-line copies are in sfr_as3_01c). The exe inlines
// them into the MakeObject/MakeInstance functions below.
namespace Instances { namespace fl {
    __forceinline Array::Array(InstanceTraits::Traits& t)
        : Instance(t), SA(t.GetVM().GetMemoryHeap())
    {
    }

    __forceinline Catch::Catch(InstanceTraits::Traits& t)
        : Instance(t)
    {
    }

    __forceinline Date::Date(InstanceTraits::Traits& t)
        : Instance(t), TimeValue(0), LocalTZA(0)
    {
    }

    __forceinline Error::Error(InstanceTraits::Traits& t)
        : Instance(t)
        , message(GetVM().GetStringManager().CreateEmptyString())
        , name(GetVM().GetStringManager().CreateEmptyString())
        , ID(0)
        , StackTrace(GetVM().GetStringManager().CreateEmptyString())
    {
        name = t.GetName();
        GetVM().GetStackTraceASString(StackTrace);
    }

    __forceinline Object::Object(InstanceTraits::Traits& t)
        : Instance(t)
    {
    }

    __forceinline QName::QName(InstanceTraits::Traits& t)
        : Instance(t)
        , LocalName(GetVM().GetStringManager().CreateEmptyString())
        , Ns(&t.GetVM().GetPublicNamespace())
    {
    }

    __forceinline QName::QName(InstanceTraits::Traits& t, const ASString& local, Instances::Namespace* ns)
        : Instance(t), LocalName(local), Ns(ns)
    {
    }

    __forceinline RegExp::RegExp(InstanceTraits::Traits& t)
        : Instance(t)
        , CompRegExp(NULL)
        , MatchOffset(-1)
        , MatchLength(0)
        , IsGlobal(false)
        , LastIndex(0)
        , OptionFlags(0x800)
        , HasNamedGroups(false)
    {
    }

    __forceinline XMLList::XMLList(InstanceTraits::Traits& t)
        : Instance(t), TargetProperty(NULL)
    {
    }

    __forceinline XML::XML(InstanceTraits::Traits& t)
        : Object(t), Text(t.GetVM().GetStringManager().CreateEmptyString())
    {
    }

    __forceinline XML::XML(InstanceTraits::Traits& t, const ASString& text, XML* parent)
        : Object(t), Text(text), Parent(parent)
    {
    }

    __forceinline XMLAttr::XMLAttr(InstanceTraits::Traits& t, const Instances::Namespace& ns, const ASString& name,
                     const ASString& value, XML* parent)
        : XML(t, name, parent), Data(value)
    {
        Ns = GetVM().MakeNamespace(Abc::NS_Public, ns.GetUri(), ns.GetPrefix());
    }

    __forceinline XMLComment::XMLComment(InstanceTraits::Traits& t, const ASString& text, XML* parent)
        : XML(t, text, parent)
    {
    }

    __forceinline XMLElement::XMLElement(InstanceTraits::Traits& t, const Instances::Namespace& ns, const ASString& name,
                           XML* parent)
        : XML(t, name, parent)
    {
        Ns = GetVM().MakeNamespace(Abc::NS_Public, ns.GetUri(), ns.GetPrefix());
    }

    __forceinline XMLProcInstr::XMLProcInstr(InstanceTraits::Traits& t, const ASString& name, const ASString& data, XML* parent)
        : XML(t, name, parent), Data(data)
    {
    }

    __forceinline XMLText::XMLText(InstanceTraits::Traits& t, const ASString& text, XML* parent)
        : XML(t, text, parent)
    {
    }
}} // namespace Instances::fl

namespace InstanceTraits
{
    // @0x14241be30
    void fl::Catch::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Catch(t));
    }

    // @0x14241c060
    void fl::Object::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Object(t));
    }

    // An interface makes plain objects.
    // @0x14241bfd0
    void Interface::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Object(t));
    }

    // @0x14241aaf0
    Pickable<Instances::fl::Object> Interface::MakeInstance(Interface& t)
    {
        return Pickable<Instances::fl::Object>(new(t.Alloc()) Instances::fl::Object(t));
    }

    // @0x14241ac70
    Pickable<Instances::fl::Object> fl::Object::MakeInstance(Object& t)
    {
        return Pickable<Instances::fl::Object>(new(t.Alloc()) Instances::fl::Object(t));
    }

    // @0x14241a500
    Pickable<Instances::fl::Array> fl::Array::MakeInstance(Array& t)
    {
        return Pickable<Instances::fl::Array>(new(t.Alloc()) Instances::fl::Array(t));
    }

    // @0x14241bd80
    void fl::Array::MakeObject(Value& result, Traits& t)
    {
        result = MakeInstance(static_cast<fl::Array&>(t));
    }

    // @0x14241a620
    Pickable<Instances::fl::Date> fl::Date::MakeInstance(Date& t)
    {
        return Pickable<Instances::fl::Date>(new(t.Alloc()) Instances::fl::Date(t));
    }

    // @0x14241beb0
    void fl::Date::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::Date(t));
    }

    // @0x14241a6a0
    __declspec(noinline) Pickable<Instances::fl::Error> fl::Error::MakeInstance(Error& t)
    {
        return Pickable<Instances::fl::Error>(new(t.Alloc()) Instances::fl::Error(t));
    }

    // @0x14241bf20
    void fl::Error::MakeObject(Value& result, Traits& t)
    {
        result.Pick(MakeInstance(static_cast<Error&>(t)));
    }

    // @0x14241ad90
    Pickable<Instances::fl::RegExp> fl::RegExp::MakeInstance(RegExp& t)
    {
        return Pickable<Instances::fl::RegExp>(new(t.Alloc()) Instances::fl::RegExp(t));
    }

    // @0x14241c160
    void fl::RegExp::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::RegExp(t));
    }

    // @0x14241c230
    void fl::XML::MakeObject(Value& result, Traits& t)
    {
        result = Pickable<Instances::fl::XML>(new(t.Alloc()) Instances::fl::XML(t));
    }

    // @0x14241af80
    __declspec(noinline) Pickable<Instances::fl::XMLList> fl::XMLList::MakeInstance(XMLList& t)
    {
        return Pickable<Instances::fl::XMLList>(new(t.Alloc()) Instances::fl::XMLList(t));
    }

    // 0x14241b010 fl::XMLList::MakeInstance(t, target_obj, target_prop, target_ns) is defined in as3_obj_core.h, so
    // its callers in sfr_as3_02/03/04 see the body as the exe's did.

    // @0x14241b5b0
    Pickable<Instances::fl::XMLElement> fl::XML::MakeInstanceElement(XML& t, const Instances::Namespace& ns,
                                                                    const ASString& name, Instances::fl::XML* parent)
    {
        return Pickable<Instances::fl::XMLElement>(new(GetVM().GetMemoryHeap()) Instances::fl::XMLElement(t, ns, name, parent));
    }

    // @0x14241b3e0
    Pickable<Instances::fl::XMLAttr> fl::XML::MakeInstanceAttr(XML& t, const Instances::Namespace& ns, const ASString& name,
                                                              const ASString& value, Instances::fl::XML* parent)
    {
        return Pickable<Instances::fl::XMLAttr>(new(GetVM().GetMemoryHeap()) Instances::fl::XMLAttr(t, ns, name, value, parent));
    }

    // @0x14241b850
    Pickable<Instances::fl::XMLText> fl::XML::MakeInstanceText(XML& t, const StringDataPtr& str, Instances::fl::XML* parent)
    {
        VM& vm = t.GetVM();
        const ASString text = vm.GetStringManager().CreateString(str.ToCStr(), str.GetSize());
        return Pickable<Instances::fl::XMLText>(new(vm.GetMemoryHeap()) Instances::fl::XMLText(t, text, parent));
    }

    // @0x14241b500
    Pickable<Instances::fl::XMLComment> fl::XML::MakeInstanceComment(XML& t, const ASString& str, Instances::fl::XML* parent)
    {
        return Pickable<Instances::fl::XMLComment>(new(GetVM().GetMemoryHeap()) Instances::fl::XMLComment(t, str, parent));
    }

    // @0x14241b6e0
    Pickable<Instances::fl::XMLProcInstr> fl::XML::MakeInstanceProcInstr(XML& t, const ASString& name, const ASString& data,
                                                                        Instances::fl::XML* parent)
    {
        return Pickable<Instances::fl::XMLProcInstr>(new(GetVM().GetMemoryHeap()) Instances::fl::XMLProcInstr(t, name, data, parent));
    }

    // @0x14241c2b0
    void fl::XMLList::MakeObject(Value& result, Traits& t)
    {
        result.Pick(new(t.Alloc()) Instances::fl::XMLList(t));
    }
}

namespace Classes { namespace fl
{
    // @0x14241c350
    Pickable<AS3::Object> Array::MakePrototype() const
    {
        InstanceTraits::fl::Array& itr = static_cast<InstanceTraits::fl::Array&>(GetClassTraits().GetInstanceTraits());
        return itr.MakeInstance(itr);
    }

    // A Date prototype gets its own traits so its constructor is Date.
    // @0x14241c400
    Pickable<AS3::Object> Date::MakePrototype() const
    {
        SPtr<InstanceTraits::Prototype> prototype = MakePickable(new(GetVM().GetMemoryHeap()) InstanceTraits::Prototype(GetVM(), AS3::fl::DateCI, const_cast<Date&>(*this)));
        InstanceTraits::Traits& itr = GetClassTraits().GetInstanceTraits();
        return Pickable<AS3::Object>(new(itr.Alloc()) Instances::fl::Date(*prototype));
    }

    // @0x14241c4d0
    Pickable<AS3::Object> Error::MakePrototype() const
    {
        InstanceTraits::fl::Error& itr = static_cast<InstanceTraits::fl::Error&>(GetClassTraits().GetInstanceTraits());
        return itr.MakeInstance(itr);
    }

    // @0x14241c560
    Pickable<AS3::Object> RegExp::MakePrototype() const
    {
        InstanceTraits::Traits& itr = GetClassTraits().GetInstanceTraits();
        return Pickable<AS3::Object>(new(itr.Alloc()) Instances::fl::RegExp(itr));
    }
}}
}}} // namespace Scaleform::GFx::AS3

// The instance traits of the four function kinds. Each names an anonymous function "Function-<hex id>".
namespace Scaleform { namespace GFx { namespace AS3 {
namespace InstanceTraits
{
    // Function (the traits of ABC function closures) is in as3_obj_fl.h.

    // MethodInd, Thunk and ThunkFunction are in as3_obj_fntraits.h.

    // @0x142415b00
    ASString Function::GetFunctionName(const Value& _this) const
    {
        const Function& itr = static_cast<const Function&>(_this.GetObject()->GetTraits());
        LongFormatter f((unsigned long)itr.GetMethodInfoInd());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }

    // @0x142415ef0
    ASString MethodInd::GetMethodIndName(const Value& _this) const
    {
        LongFormatter f((unsigned long)_this.GetMethodInd());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }

    // @0x142417100
    ASString Thunk::GetThunkName(const Value& _this) const
    {
        LongFormatter f((unsigned long)(UPInt)&_this.AsThunk());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }

    // @0x1424171d0
    ASString ThunkFunction::GetThunkName(const Value& _this) const
    {
        LongFormatter f((unsigned long)(UPInt)&_this.AsThunkFunction().GetThunk());
        ASString s = GetVM().GetStringManager().CreateConstString("Function-");
        f.SetBase(16).Convert();
        s += f.ToCStr();
        return s;
    }
}

namespace Classes
{
    // MS2-FUNCTIONAL: the exe inlines the ThunkFunction constructor
    // @0x14241c600
    Pickable<Instances::ThunkFunction> Function::MakeThunkFunction(const ThunkInfo& thunk, const Traits& ot) const
    {
        InstanceTraits::Traits& itr = GetClassTraits().GetThunkFunctionTraits();
        return Pickable<Instances::ThunkFunction>(new(itr.Alloc()) Instances::ThunkFunction(itr, thunk, ot));
    }

    // @0x142419d90
    Pickable<Instances::CheckTypeTF> Function::MakeCheckTypeInstance(const Class& data_type, const ThunkInfo& thunk,
                                                                     const Traits& ot) const
    {
        InstanceTraits::Traits& itr = GetClassTraits().GetThunkFunctionTraits();
        return Pickable<Instances::CheckTypeTF>(new(GetVM().GetMemoryHeap()) Instances::CheckTypeTF(itr, thunk, data_type, ot));
    }
}
}}} // namespace Scaleform::GFx::AS3

// @0x14241a5b0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Catch>
Scaleform::GFx::AS3::InstanceTraits::fl::Catch::MakeInstance(Catch& t)
{
    return Pickable<Instances::fl::Catch>(new(t.Alloc()) Instances::fl::Catch(t));
}

namespace Scaleform { namespace GFx { namespace AS3 {
typedef HashSetBase<Instances::Namespace*, NamespaceInstanceFactory::NamespaceHashFunc,
                    NamespaceInstanceFactory::NamespaceHashFunc, AllocatorLH<Instances::Namespace*, Stat_Default_Mem>,
                    HashsetEntry<Instances::Namespace*, NamespaceInstanceFactory::NamespaceHashFunc> >
    NamespaceInstanceSetBase;
}}}
// The set's Add is the out-of-line one (sfr_as3_01c's copy, 0x1423e80a0).
namespace Scaleform {
template <> template <>
void GFx::AS3::NamespaceInstanceSetBase::Add<GFx::AS3::Instances::Namespace*>(void*, GFx::AS3::Instances::Namespace* const&);
}

// The exe inlines the namespace set's keyed lookup and chain walk into its callers (no out-of-line GetAlt exists).
namespace Scaleform {
template<> template<>
__forceinline SPInt GFx::AS3::NamespaceInstanceSetBase::findIndexAlt<GFx::AS3::NamespaceInstanceFactory::Key>(
    const GFx::AS3::NamespaceInstanceFactory::Key& key) const
{
    if (pTable == 0)
        return -1;
    UPInt h = GFx::AS3::NamespaceInstanceFactory::NamespaceHashFunc()(key) & pTable->SizeMask;
    UPInt idx = h;
    const auto* e = &E(idx);

    if (e->IsEmpty() || (e->GetCachedHash(pTable->SizeMask) != idx))
        return -1;

    while (1)
    {
        if (e->GetCachedHash(pTable->SizeMask) == h && e->Value == key)
            return idx;
        idx = e->NextInChain;
        if (idx == (UPInt)-1)
            break;
        e = &E(idx);
    }
    return -1;
}
template<> template<>
__forceinline bool GFx::AS3::NamespaceInstanceSetBase::GetAlt<GFx::AS3::NamespaceInstanceFactory::Key>(
    const GFx::AS3::NamespaceInstanceFactory::Key& key, GFx::AS3::Instances::Namespace** pout) const
{
    SPInt idx = findIndexAlt(key);
    if (idx >= 0)
    {
        if (pout)
            *pout = E(idx).Value;
        return true;
    }
    return false;
}
} // namespace Scaleform

namespace Scaleform { namespace GFx { namespace AS3 {
// the Namespace constructor as the exe inlines it here (its out-of-line copy is sfr_as3_01c's 0x1423edb60)
SF_FORCEINLINE Instances::Namespace::Namespace(VM& vm, NamespaceInstanceFactory* pfactory, Abc::NamespaceKind kind,
                                               const ASString& uri, const Value& prefix, InlineCtorTag)
    : GASRefCountBase(vm.GetGCPtr())
    , Kind(kind)
    , IsInterface(false)
    , VMRef(vm)
    , Uri(uri)
    , pFactory(pfactory)
    , Prefix(prefix)
{
}

// @0x14241ab60
__declspec(noinline) Pickable<Instances::Namespace> InstanceTraits::fl::Namespace::MakeInstance(Abc::NamespaceKind kind, const ASString& uri,
                                                                           const Value& prefix)
{
    // allocated under StatMV_VM (0x148), the SDK's SF_HEAP_AUTO_NEW_ID(this, StatMV_VM)
    return Pickable<Instances::Namespace>(new((MemAddressPtr)((void*)this), StatMV_VM, __FILE__, __LINE__)
                                          Instances::Namespace(GetVM(), InstanceFactory, kind, uri, prefix,
                                                               Instances::Namespace::InlineCtorTag()));
}

// @0x14241ba70
Pickable<Instances::Namespace> InstanceTraits::fl::Namespace::MakeInternedInstance(Abc::NamespaceKind kind,
                                                                                   const ASString& uri,
                                                                                   const Value& prefix)
{
    return InstanceFactory->MakeNamespace(kind, uri, prefix);
}

// @0x14241baa0
__declspec(noinline) Pickable<Instances::Namespace> NamespaceInstanceFactory::MakeNamespace(Abc::NamespaceKind kind, const ASString& uri,
                                                                       const Value& prefix)
{
    Key key(kind, uri);
    Instances::Namespace* ns = 0;

    if (!NamespaceSet.GetAlt(key, &ns))
    {
        Pickable<Instances::Namespace> result = pNamespaceInstanceTraits->MakeInstance(kind, uri, prefix);
        NamespaceSet.Add(result.GetPtr());
        return result;
    }

    return Pickable<Instances::Namespace>(ns, PickValue);
}
}}}
// The namespace set's out-of-line rehash.
template void Scaleform::GFx::AS3::NamespaceInstanceSetBase::setRawCapacity(void*, Scaleform::UPInt);
// Namespace enumerates two properties: 1 = uri, 2 = prefix.
// Namespace::GetNextPropIndex.
// @0x1424161e0
Scaleform::GFx::AS3::GlobalSlotIndex*
FUN_1424161e0(const Scaleform::GFx::AS3::Instances::Namespace*, Scaleform::GFx::AS3::GlobalSlotIndex* result,
              Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
    if (ind.Get() <= 1)
    {
        ind = Scaleform::GFx::AS3::GlobalSlotIndex(ind.Get() + 1);
        *result = ind;
        return result;
    }
    *result = Scaleform::GFx::AS3::GlobalSlotIndex(0);
    return result;
}
// Namespace::GetNextPropertyName.
// @0x1424162b0
void FUN_1424162b0(const Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& name,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
    Scaleform::GFx::AS3::VM& vm = self->GetVM();
    switch (ind.Get())
    {
    case 1: name.Assign(vm.GetStringManager().CreateConstString("uri")); break;
    case 2: name.Assign(vm.GetStringManager().CreateConstString("prefix")); break;
    }
}
// Namespace::GetNextPropertyValue.
// @0x142416600
void FUN_142416600(Scaleform::GFx::AS3::Instances::Namespace* self, Scaleform::GFx::AS3::Value& value,
                   Scaleform::GFx::AS3::GlobalSlotIndex ind)
{
    switch (ind.Get())
    {
    case 1: value.Assign(self->GetUri()); break;
    case 2: value.Assign(self->GetPrefix()); break;
    }
}
// Namespace::SetUri.
// @0x142423bd0
__declspec(noinline) void FUN_142423bd0(Scaleform::GFx::AS3::Instances::Namespace* self, const Scaleform::GFx::ASString& uri)
{ const_cast<Scaleform::GFx::ASString&>(self->GetUri()) = uri; }
// String::StringSplit: the parts of str split at each delim (at most limit of them), as a new Array: no delim gives
// str itself, an empty delim each character. A delim that ends str adds a trailing empty part.
// SparseArray::PushBack, inlined at each push of the split.
static SF_INLINE void splitPushBack(Scaleform::GFx::AS3::SparseArray& sa, const Scaleform::GFx::AS3::Value& v)
{
    if (sa.Length == sa.ValueA.GetSize())
        sa.ValueA.PushBack(v);
    else
    {
        sa.ValueHHighInd = sa.Length;
        sa.ValueH.Set(sa.ValueHHighInd, v);
    }
    ++sa.Length;
}
// The same with the dense part's ArrayDataDH::PushBack inlined too (only the empty-string push has it in the exe).
struct SplitValueArray : Scaleform::GFx::AS3::ValueArrayDH
{
    SF_INLINE void InlinePushBack(const Scaleform::GFx::AS3::Value& v)
    {
        Data.ResizeNoConstruct(Data.pHeap, Data.Size + 1);
        ::new (Data.Data + Data.Size - 1) Scaleform::GFx::AS3::Value(v);
    }
};
static SF_INLINE void splitPushBackInline(Scaleform::GFx::AS3::SparseArray& sa, const Scaleform::GFx::AS3::Value& v)
{
    if (sa.Length == sa.ValueA.GetSize())
        static_cast<SplitValueArray&>(sa.ValueA).InlinePushBack(v);
    else
    {
        sa.ValueHHighInd = sa.Length;
        sa.ValueH.Set(sa.ValueHHighInd, v);
    }
    ++sa.Length;
}
static SF_INLINE Scaleform::GFx::ASString splitCreateString(Scaleform::GFx::AS3::StringManager& sm, const char* start,
                                                             const char* end = NULL)
{
    int len = (end == 0) ? (int)strlen(start) : int(end - start);
    if (len < 0)
        len = 0;
    if (len > 0)
        return sm.CreateString(start, len);
    return sm.CreateEmptyString();
}
// @0x142424ca0
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> FUN_142424ca0(Scaleform::GFx::AS3::VM& vm,
                                                                               const Scaleform::GFx::ASString& str,
                                                                               const char* delimiters, Scaleform::UInt32 limit)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    Pickable<Instances::fl::Array> retVal = vm.MakeArray();

    const char* search = delimiters;
    const char* pstr = str.ToCStr();

    UInt32 c1, c2;

    if (search == 0)
    {
        splitPushBack(retVal->SA, Value(str));
    }
    else if (*search == 0)
    {
        if (str.GetSize() == 0)
        {
            Value v(str);
            splitPushBackInline(retVal->SA, v);
        }
        else
        {
            Scaleform::String tmpStr;

            while ((c1 = UTF8Util::DecodeNextChar(&pstr)) != 0)
            {
                tmpStr.Clear();
                tmpStr.AppendChar(c1);
                splitPushBack(retVal->SA, Value(vm.GetStringManager().CreateString(tmpStr.ToCStr(), tmpStr.GetSize())));
            }
        }
    }
    else
    {
        UInt32 count = 0;
        const char* start = pstr;

        for (;;)
        {
            const char* s2   = search;
            const char* end  = pstr;
            const char* prev = pstr;
            const char* pnext = NULL;

            for (;;)
            {
                prev = pstr;
                c1 = UTF8Util::DecodeNextChar(&pstr);
                c2 = UTF8Util::DecodeNextChar(&s2);
                if (!pnext)
                    pnext = pstr;
                if (c1 == 0 || c2 == 0)
                {
                    break;
                }
                if (c1 != c2)
                {
                    pstr = pnext;
                    break;
                }
            }
            if (c2 == 0)
            {
                if (count >= limit) break;
                splitPushBack(retVal->SA, Value(splitCreateString(vm.GetStringManager(), start, end)));
                pstr = start = prev;
                ++count;
            }
            if (c1 == 0)
            {
                if (count < limit)
                {
                    if (c2 == 0)
                        splitPushBack(retVal->SA, Value(splitCreateString(vm.GetStringManager(), start, end)));
                    else
                        splitPushBack(retVal->SA, Value(splitCreateString(vm.GetStringManager(), start)));
                }
                break;
            }
        }
    }

    return retVal;
}
// ArrayPagedBase<CallFrame, 6, 64, AllocatorPagedCC<CallFrame, 329>>::allocatePage, the VM call frame stack (pages of
// 64 frames of 0xa8 bytes; the page table grows by 64 entries).
// MS2-FUNCTIONAL: the call frame array is not modelled in VM; written on its layout
// @0x142427560
void FUN_142427560(void* self, Scaleform::UPInt nb)
{
    using namespace Scaleform;
    struct CallFramePages
    {
        UPInt   Size;       // +0x00 (+0x08 unused here)
        UPInt   Unk08;
        UPInt   NumPages;   // +0x10
        UPInt   MaxPages;   // +0x18
        void**  Pages;      // +0x20
    };
    typedef AllocatorBaseLH<329> Allocator;
    CallFramePages& a = *static_cast<CallFramePages*>(self);
    if (nb >= a.MaxPages)
    {
        if (a.Pages)
            a.Pages = (void**)Allocator::Realloc(a.Pages, (a.MaxPages + 64) * sizeof(void*), __FILE__, __LINE__);
        else
            a.Pages = (void**)Allocator::Alloc(self, 64 * sizeof(void*), __FILE__, __LINE__);
        a.MaxPages += 64;
    }
    a.Pages[nb] = Allocator::Alloc(self, 64 * 0xa8, __FILE__, __LINE__);
    a.NumPages++;
}
// LookupNamespace: a new public namespace with ns's uri and prefix; the prefix of the first namespace of nsa with
// the same uri wins.
// @0x142419d00
Scaleform::Pickable<Scaleform::GFx::AS3::Instances::Namespace> FUN_142419d00(
    const Scaleform::GFx::AS3::Instances::Namespace& ns, const Scaleform::GFx::AS3::NamespaceArray* nsa)
{
    using namespace Scaleform;
    using namespace Scaleform::GFx::AS3;
    Pickable<Instances::Namespace> result = ns.GetVM().MakeNamespace(Abc::NS_Public, ns.GetUri(), ns.GetPrefix());
    if (nsa)
    {
        const UPInt size = nsa->Namespaces.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            const Instances::Namespace& other = *nsa->Namespaces[i];
            if (other.GetUri().GetNode() == result->GetUri().GetNode())
            {
                result->SetPrefix(other.GetPrefix());
                break;
            }
        }
    }
    return result;
}
// Namespace::SetUri(Value): a QName gives its namespace's uri (or "*" without one), anything else its string.
// @0x142423c10
void FUN_142423c10(Scaleform::GFx::AS3::Instances::Namespace* self, const Scaleform::GFx::AS3::Value& v)
{
    using namespace Scaleform::GFx::AS3;
    VM& vm = self->GetVM();
    const Traits& tr = vm.GetValueTraits(v);
    if (tr.GetTraitsType() == Traits_QName && tr.IsInstanceTraits())
    {
        const Instances::fl::QName* qn = static_cast<const Instances::fl::QName*>(v.GetObject());
        if (qn == NULL)
            return;
        if (qn->Ns.GetPtr() == NULL)
        {
            Scaleform::GFx::ASString any(vm.GetStringManager().CreateConstString("*"));
            const_cast<Scaleform::GFx::ASString&>(self->GetUri()) = any;
            return;
        }
        FUN_142423bd0(self, qn->Ns->GetUri());
    }
    else
        v.Convert2String(const_cast<Scaleform::GFx::ASString&>(self->GetUri()));
}
// MultinameHash<ClassTraits::Traits*>::Get: the class traits cached under {name, ns}.
// MS2-FUNCTIONAL: the exe builds the temporary key in another home slot
// @0x142414ac0
Scaleform::GFx::AS3::ClassTraits::Traits**
FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self, const Scaleform::GFx::ASString& name,
              const Scaleform::GFx::AS3::Instances::Namespace& ns)
{ return self->Entries.Get(Scaleform::GFx::AS3::TClassTraitsCache::Key(name, &ns)); }
// Multiname::IsAnyNamespace: a qualified name with no namespace.
// @0x1424198b0
bool FUN_1424198b0(const Scaleform::GFx::AS3::Multiname& mn)
{
    return (mn.Kind & 3) <= 1 && mn.Obj.GetPtr() == NULL;
}

// ---- global functions ----
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl
{
    // A repeating interval timer registered with the movie; returns its id.
    // @0x14242a0c0
    void GlobalObjectCPP::setInterval(Value& result, unsigned argc, const Value* argv)
    {
        if (argc < 2)
        {
            GetVM().ThrowArgumentError(VM::Error(VM::eWrongArgumentCountError, GetVM(), "GlobalObjectCPP::setInterval", 2, 1023, argc));
            return;
        }
        UInt32 delay;
        if (!argv[1].Convert2UInt32(delay))
            return;
        void* pmem = GetVM().GetMemoryHeap()->Alloc(0x70);
        ASIntervalTimerIntf* ptimer = pmem ? ::new (pmem) IntervalTimer(argv[0], delay, false) : NULL;
        if (argc > 2)
            static_cast<IntervalTimer*>(ptimer)->SetArguments(argc - 2, argv + 2);
        MovieImpl* proot = static_cast<ASVM&>(GetVM()).GetMovieImpl();
        result.Assign(Value(UInt32(proot->AddIntervalTimer(ptimer))));
        ptimer->Start(proot);
        ptimer->Release();
    }

    // Milliseconds since the movie started.
    // @0x142428d70
    void GlobalObjectCPP::getTimer(SInt32& result)
    {
        result = (SInt32)AsMovieSlots(static_cast<ASVM&>(GetVM()).GetMovieImpl())->GetASTimerMs();
    }
}}}}} // namespace Scaleform::GFx::AS3::Instances::fl
namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances
{
    // The AS3 Function.length: the declared parameter count.
    // @0x1424292a0
    void FunctionBase::lengthGet(UInt32& result)
    {
        result = GetMaxParamNum();
    }
}}}} // namespace Scaleform::GFx::AS3::Instances

// ==== E4X nodes ======================================================================================================
namespace Scaleform { namespace GFx { namespace AS3
{
    // The E4X wildcard name: null, undefined or the empty string.
    // @0x1424198d0
    bool Multiname::IsAnyType() const
    {
        return Name.IsNullOrUndefined() || (Name.IsString() && Name.AsString().IsEmpty());
    }
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 { namespace Instances { namespace fl
{
    // E4X name matching: the local name (or the wildcard), then the namespace. An unqualified element name
    // means the default xml namespace (the public one when the call frame has none); a namespace set matches
    // through its public members, an empty URI again standing for the default namespace.
    // MS2-FUNCTIONAL: register allocation (exe keeps the result in dil and this in r14)
    // @0x14241ca70
    bool XML::Matches(const Multiname& prop_name) const
    {
        bool result = false;
        if (prop_name.Name.IsString())
        {
        const ASString name = prop_name.Name.AsString();
        if (GetName() == name || prop_name.IsAnyType())
        {
            if (prop_name.IsQName())
            {
                if (prop_name.IsAnyNamespace())
                    result = true;
                else
                {
                    const Instances::Namespace& ns = prop_name.GetNamespace();
                    VM& vm = GetVM();
                    Instances::Namespace* def_ns = vm.GetDefXMLNamespace();
                    if (def_ns == NULL)
                        def_ns = &vm.GetPublicNamespace();
                    const ASString& uri = ns.GetKind() == Abc::NS_Public &&
                                          (prop_name.IsAttr() || !ns.GetUri().IsEmpty()) ? ns.GetUri()
                                                                                          : def_ns->GetUri();
                    if (uri == GetNamespace().GetUri())
                        result = true;
                }
            }
            else if (prop_name.IsAnyType())
                result = true;
            else
            {
                VM& vm = GetVM();
                const Instances::Namespace& cur_ns = GetNamespace();
                Instances::Namespace* def_ns = NULL;
                if (!prop_name.IsAttr())
                    def_ns = vm.GetDefXMLNamespace();
                Instances::Namespace& pub_ns = vm.GetPublicNamespace();
                if (def_ns == NULL)
                    def_ns = &pub_ns;

                if (prop_name.ContainsNamespace(pub_ns))
                {
                    const ArrayLH<SPtr<Instances::Namespace> >& nss =
                        static_cast<const NamespaceSet*>(prop_name.Obj.GetPtr())->GetNamespaces();
                    for (UPInt i = 0; i < nss.GetSize(); ++i)
                    {
                        const Instances::Namespace& ns = *nss[i];
                        if (ns.GetKind() != Abc::NS_Public)
                            continue;
                        const ASString& uri = ns.GetUri().IsEmpty() ? def_ns->GetUri() : ns.GetUri();
                        if (uri == cur_ns.GetUri())
                        {
                            result = true;
                            break;
                        }
                    }
                }
                else if (def_ns->GetUri() == cur_ns.GetUri())
                    result = def_ns->GetKind() == cur_ns.GetKind();
            }
        }
        }
        return result;
    }

    // XML nodes take no indexed assignment.
    // @0x142422070
    CheckResult XML::SetProperty(const Multiname& prop_name, const Value& value)
    {
        SF_UNUSED(value);
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            GetVM().ThrowTypeError(VM::Error(VM::eXMLAssignmentToIndexedXMLNotAllowed, GetVM()));
            return false;
        }
        return false;
    }

    // E4X [[Put]] on an element. An attribute name sets (or adds) that attribute to value's string, a list
    // joining its items with spaces; any further attributes of that name are deleted. An element name
    // replaces the last matching child (the others are removed) or appends one; a primitive value becomes
    // the text of that child, a new element of the name when there was none.
    // MS2-FUNCTIONAL: the exe inlines the XMLAttr constructor and SPtr copies; register allocation differs
    // @0x1424220e0
    CheckResult XMLElement::SetProperty(const Multiname& prop_name, const Value& value)
    {
        VM& vm = GetVM();
        StringManager& sm = vm.GetStringManager();

        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            vm.ThrowTypeError(VM::Error(VM::eXMLAssignmentToIndexedXMLNotAllowed, vm));
            return false;
        }

        Value c;
        if (IsXMLObject(value))
            c = Value(static_cast<XML*>(value.GetObject())->DeepCopy(NULL));
        else if (IsXMLListObject(value))
            c = Value(static_cast<XMLList*>(value.GetObject())->DeepCopy(NULL));
        else
        {
            ASString str = sm.CreateEmptyString();
            if (!value.Convert2String(str))
                return false;
            c = str;
        }

        if (prop_name.IsAttr())
        {
            if (IsXMLListObject(c))
            {
                XMLList* list = static_cast<XMLList*>(c.GetObject());
                StringBuffer buf(vm.GetMemoryHeap());
                const UPInt size = list->List.GetSize();
                for (UPInt i = 0; i < size; ++i)
                {
                    if (i > 0)
                        buf.AppendChar(' ');
                    list->List[i]->ToString(buf, 0);
                }
                c = sm.CreateString(buf.ToCStr(), buf.GetSize());
            }
            else if (IsXMLObject(c))
            {
                ASString s = sm.CreateEmptyString();
                static_cast<XML*>(c.GetObject())->AS3toString(s);
                c = s;
            }
            else
                c = c.AsString();

            SPtr<XMLAttr> a;
            for (UPInt j = 0; j < Attrs.GetSize(); ++j)
            {
                if (Attrs[j]->Matches(prop_name))
                {
                    if (a.GetPtr() == NULL)
                        a = Attrs[j];
                    else if (!DeleteProperty(prop_name))
                        return false;
                }
            }

            if (a.GetPtr() == NULL)
            {
                Instances::Namespace* ns = prop_name.IsQName() ? &prop_name.GetNamespace() : vm.GetDefXMLNamespace();
                if (ns == NULL)
                    ns = &vm.GetPublicNamespace();

                a = Pickable<XMLAttr>(new(GetVM().GetMemoryHeap()) XMLAttr(GetInstanceTraits(), *ns,
                                      prop_name.Name.AsString(), c.AsString(), this));
                Attrs.PushBack(a);
                AddInScopeNamespace(*ns);
            }

            a->Data = c.AsString();
            return true;
        }

        bool result = true;
        Value i;

        ASString propName = sm.CreateEmptyString();
        if (!prop_name.Name.Convert2String(propName))
            return false;

        const bool primitiveAssign = !IsXMLObject(c) && !IsXMLListObject(c) && !prop_name.IsAnyType();

        // the children can shrink inside this loop
        for (UPInt j = Children.GetSize(); j > 0; --j)
        {
            const UPInt k = j - 1;
            if (Children[k]->Matches(prop_name))
            {
                if (!i.IsUndefined())
                    Children.RemoveAt(i.AsInt());
                i.SetSInt32(static_cast<SInt32>(k));
            }
        }

        if (i.IsUndefined())
        {
            i.SetSInt32(static_cast<SInt32>(Children.GetSize()));
            if (primitiveAssign)
            {
                InstanceTraits::fl::XML& itr = static_cast<InstanceTraits::fl::XML&>(GetInstanceTraits());
                Instances::Namespace* ns = prop_name.IsQName() && !prop_name.IsAnyNamespace() ?
                                           &prop_name.GetNamespace() : vm.GetDefXMLNamespace();
                if (ns == NULL)
                    ns = &vm.GetPublicNamespace();

                SPtr<XMLElement> y = itr.MakeInstanceElement(itr, *ns, prop_name.Name.AsString(), this);
                if (!Replace(static_cast<UPInt>(i.AsInt()), Value(y.GetPtr())))
                    return false;
                y->AddInScopeNamespace(*ns);
            }
        }

        if (primitiveAssign)
        {
            SPtr<XML> xml = Children[i.AsInt()];
            xml->DeleteChildren(NULL);
            if (!c.AsString().IsEmpty())
            {
                if (xml->GetKind() == kElement)
                    result = static_cast<XMLElement*>(xml.GetPtr())->Replace(0, c);
            }
        }
        else
            result = Replace(i.AsInt(), c);

        return result;
    }

    // The node a list assignment works on. A one-item list is its item; an empty list with a target gets a new
    // element of the target name appended to the (resolved) target node; an untargeted or "*" list has none.
    // MS2-FUNCTIONAL: the exe inlines the Error and the List push; register allocation differs
    // @0x142420570
    CheckResult XMLList::ResolveValue(XML*& r)
    {
        r = NULL;
        VM& vm = GetVM();
        const UPInt size = List.GetSize();
        if (size != 0)
        {
            if (size == 1)
            {
                r = List[0];
                return true;
            }
            vm.ThrowTypeError(VM::Error(VM::eXMLAssigmentOneItemLists, vm));
            return false;
        }
        else
        {
            if (!TargetObject || !TargetProperty || strcmp(TargetProperty->pData, "*") == 0)
                return true;

            XML* base = NULL;
            const Traits& tr = TargetObject->GetTraits();
            if (tr.GetTraitsType() == Traits_XML && tr.IsInstanceTraits())
                base = static_cast<XML*>(TargetObject.GetPtr());
            else if (tr.GetTraitsType() == Traits_XMLList && tr.IsInstanceTraits())
            {
                if (!static_cast<XMLList*>(TargetObject.GetPtr())->ResolveValue(base))
                    return false;
            }
            else
                return false;
            if (base == NULL)
                return true;

            InstanceTraits::fl::XML& itr = static_cast<InstanceTraits::fl::XML&>(*vm.GetXMLSupport().GetITraitsXML());
            SPtr<XML> target(Pickable<XML>(itr.MakeInstanceElement(itr, *TargetNamespace, ASString(TargetProperty), base)));
            base->AppendChild(target);
            List.PushBack(target);
            r = target;
        }
        return true;
    }

    // E4X [[Put]] on a list. An index at or past the end appends a new node to the target (an attribute, a text
    // or an element of the target name) after the last item; the indexed item then takes the value: an attribute
    // is set on its parent, a list is spliced in its place, a node or string replaces it in its parent, anything
    // else becomes its content. Any other name is put on the only item (an empty list resolves its target).
    // MS2-FUNCTIONAL: the exe inlines ShallowCopy, the XMLList and XMLText constructors and the attribute search
    // @0x142422a20
    CheckResult XMLList::SetProperty(const Multiname& prop_name, const Value& value)
    {
        VM& vm = GetVM();
        UInt32 i = 0;

        if (GetVectorInd(prop_name, i))
        {
            XML* r = NULL;
            XMLList* rList = NULL;

            if (TargetObject)
            {
                const Traits& tr = TargetObject->GetTraits();
                if (!tr.IsInstanceTraits())
                    return false;
                switch (tr.GetTraitsType())
                {
                case Traits_XML:
                    r = static_cast<XML*>(TargetObject.GetPtr());
                    break;
                case Traits_XMLList:
                    rList = static_cast<XMLList*>(TargetObject.GetPtr());
                    if (!rList->ResolveValue(r))
                        return false;
                    break;
                default:
                    return false;
                }
                if (r == NULL)
                    return false;
            }

            if (i >= List.GetSize())
            {
                if (rList != NULL)
                {
                    if (rList->List.GetSize() != 1)
                        return false;
                    r = rList->List[0];
                }
                if (r && r->GetKind() != XML::kElement)
                    return false;

                XMLElement* rElement = static_cast<XMLElement*>(r);
                SPtr<XML> y;
                InstanceTraits::fl::XML& itr_xml = static_cast<InstanceTraits::fl::XML&>(*vm.GetXMLSupport().GetITraitsXML());

                const bool isAttribute = TargetNamespace && TargetProperty &&
                                         Multiname(*TargetNamespace, Value(ASString(TargetProperty))).IsAttr();
                if (isAttribute)
                {
                    Multiname target_mn(*TargetNamespace, Value(ASString(TargetProperty)));
                    if (target_mn.Name.IsString())
                    {
                        const ASString name = target_mn.Name.AsString();
                        for (UPInt k = 0; k < rElement->Attrs.GetSize(); ++k)
                        {
                            if (rElement->Attrs[k]->Matches(target_mn))
                                return false;
                        }
                    }
                    y = itr_xml.MakeInstanceAttr(itr_xml, *TargetNamespace, ASString(TargetProperty),
                                                 vm.GetStringManager().CreateEmptyString(), r);
                }
                else if (TargetProperty == NULL || strcmp(TargetProperty->pData, "*") == 0)
                    y = itr_xml.MakeInstanceText(itr_xml, StringDataPtr("", 0), r);
                else
                    y = itr_xml.MakeInstanceElement(itr_xml, *TargetNamespace, ASString(TargetProperty), r);

                i = static_cast<UInt32>(List.GetSize());

                if (!isAttribute)
                {
                    if (r != NULL)
                    {
                        UInt32 j;
                        const UPInt size = rElement->Children.GetSize();
                        if (i > 0)
                        {
                            const XML* xml = List[i - 1];
                            j = 0;
                            while (j < size - 1 && rElement->Children[j] != xml)
                                ++j;
                        }
                        else
                            j = static_cast<UInt32>(size - 1);

                        if (!r->InsertChildAt(j + 1, Value(y)))
                            return false;
                    }

                    if (IsXMLObject(value))
                        y->AS3setName(Value::GetUndefined(), Value(static_cast<XML*>(value.GetObject())->GetName()));
                    else if (IsXMLListObject(value))
                        y->AS3setName(Value::GetUndefined(), Value(static_cast<XMLList*>(value.GetObject())->TargetProperty));
                }

                List.PushBack(y);
            }

            Value V(value);
            {
                bool isTextValue = true;
                if (IsXMLObject(value))
                {
                    const XML::Kind kind = static_cast<XML*>(value.GetObject())->GetKind();
                    isTextValue = kind == XML::kText || kind == XML::kAttr;
                }
                else if (IsXMLListObject(value))
                    isTextValue = false;

                if (isTextValue)
                {
                    ASString strValue = vm.GetStringManager().CreateEmptyString();
                    if (!value.Convert2String(strValue))
                        return false;
                    V.Assign(strValue);
                }
            }

            XML* xml = List[i];
            const XML::Kind xmlKind = xml->GetKind();

            if (xmlKind == XML::kAttr)
            {
                Multiname z(const_cast<Instances::Namespace&>(xml->GetNamespace()), Value(xml->GetName()));
                xml->Parent->SetProperty(z, V);
                SPtr<XMLList> attr = MakeXMLListInstance();
                xml->Parent->GetProperty(z, *attr);
                List[i] = attr->List[0];
            }
            else if (IsXMLListObject(V))
            {
                SPtr<XMLList> c = static_cast<XMLList*>(V.GetObject())->ShallowCopy();
                XML* parent = xml->Parent;
                const UPInt csize = c->List.GetSize();

                if (parent != NULL)
                {
                    UPInt q;
                    if (xml->GetChildIndex(q))
                    {
                        XMLElement* eparent = static_cast<XMLElement*>(parent);
                        if (!eparent->Replace(q, Value(c)))
                            return false;
                        for (UPInt j = 0; j < csize; ++j)
                            c->List[j] = eparent->Children[q + j];
                    }
                }

                const UPInt oldSize = List.GetSize();
                if (csize > 1)
                    List.Resize(oldSize + csize - 1);

                if (csize == 0)
                    List.RemoveAt(i);
                else
                {
                    if (csize > 1)
                    {
                        for (UPInt j = oldSize - 1; j > i; --j)
                        {
                            List[j + csize - 1] = List[j];
                            List[j] = NULL;
                        }
                    }

                    for (UPInt j = 0; j < csize; ++j)
                    {
                        XML* l_value = List[i + j];
                        XML* r_value = c->List[j];
                        if (l_value && r_value->GetKind() != XML::kElement)
                        {
                            const Multiname mn(l_value->GetCurrNamespace(), Value(vm.GetStringManager().CreateConstString("*")));
                            Pickable<XML> new_xml = l_value->DeepCopy(l_value->Parent);
                            List[i + j] = new_xml;
                            if (!new_xml->SetProperty(mn, Value(r_value)))
                                return false;
                        }
                        else
                            List[i + j] = r_value;
                    }
                }
            }
            else if (IsXMLObject(V) || xmlKind == XML::kText || xmlKind == XML::kComment || xmlKind == XML::kInstruction)
            {
                XML* parent = xml->Parent;
                if (parent != NULL)
                {
                    UPInt q;
                    if (xml->GetChildIndex(q))
                    {
                        XMLElement* eparent = static_cast<XMLElement*>(parent);
                        if (!eparent->Replace(q, V) || eparent->Children.GetSize() <= q)
                            return false;
                        V.Assign(eparent->Children[q]);
                    }
                }

                if (V.IsString())
                {
                    InstanceTraits::fl::XML& itr_xml = static_cast<InstanceTraits::fl::XML&>(*vm.GetXMLSupport().GetITraitsXML());
                    List[i] = Pickable<XML>(new(itr_xml.GetVM().GetMemoryHeap()) XMLText(itr_xml, V.AsString(), parent));
                }
                else
                    List[i] = static_cast<XML*>(V.GetObject());
            }
            else
            {
                const Multiname mn(vm);
                if (!List[i]->SetProperty(mn, V))
                    return false;
            }
        }
        else if (List.GetSize() <= 1)
        {
            if (List.GetSize() == 0)
            {
                XML* r;
                if (!ResolveValue(r) || r == NULL)
                    return false;
                List.PushBack(r);
            }
            if (!List[0]->SetProperty(prop_name, value))
                return false;
        }
        else
        {
            vm.ThrowTypeError(VM::Error(VM::eXMLAssigmentOneItemLists, vm));
            return false;
        }

        return true;
    }

    // An XML node enumerates as a one-item list: its only name is "0".
    // Past the end the name is the "null" builtin (Builtins[2], as in the SDK).
    // @0x1424163b0
    void XML::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
    {
        StringManager& sm = GetVM().GetStringManager();
        if (ind.IsValid())
            name.Assign(sm.CreateConstString("0"));
        else
            name.Assign(sm.GetBuiltin(AS3Builtin_null));
    }

    // @0x142416670
    void XML::GetNextPropertyValue(Value& value, GlobalSlotIndex ind)
    {
        if (ind.IsValid())
            value.Assign(this);
        else
            value.SetUndefined();
    }

    // @0x142416800
    CheckResult XML::GetProperty(const Multiname& prop_name, Value& value)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            if (ind == 0)
            {
                value.Assign(this);
                return true;
            }
            value.SetUndefined();
        }
        return false;
    }

    // @0x1424168a0
    CheckResult XML::GetProperty(const Multiname& prop_name, XMLList& list)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind) && ind == 0)
        {
            list.Append(this);
            return true;
        }
        return false;
    }

    // The exe inlines the XMLList constructor (out of line at 0x1423f00f0, sfr_as3_01c) here; the tag keeps this
    // copy's COMDAT apart from 01c's definition (same copy as sfr_as3_02).
    __forceinline XMLList::XMLList(InstanceTraits::Traits& t, InlineCtor)
        : Instance(t), TargetProperty(NULL)
    {
    }

    // InstanceTraits::fl::XMLList::MakeInstance(itr), expanded in place as the exe does.
    static SF_INLINE Pickable<XMLList> Sfr04NewXMLList(InstanceTraits::fl::XMLList& itr)
    {
        return Pickable<XMLList>(new(itr.Alloc()) XMLList(itr, InlineCtor()));
    }

    // InstanceTraits::fl::XMLList::MakeInstance(itr, obj, name, ns), its result read back from the temporary
    static __forceinline Pickable<XMLList> Sfr04NewTargetListOf(InstanceTraits::fl::XMLList& itr, Object& obj,
        const ASString& name, Instances::Namespace& ns)
    {
        return itr.MakeInstance(itr, obj, name, ns);
    }

    // @0x14241c880
    Pickable<XMLList> XML::MakeXMLListInstance(const Multiname& mn)
    {
        Pickable<XMLList> result;
        if (mn.Name.IsString())
        {
            Instances::Namespace* ns;
            if (mn.IsQName() && !mn.IsAnyNamespace())
            {
                ns = &mn.GetNamespace();
                if (ns->GetPrefix().IsUndefined())
                {
                    // an in-scope namespace may carry a prefix for this URI
                    Instances::Namespace* local_ns = FindNamespaceByURI(ns->GetUri(), NULL);
                    if (local_ns)
                        ns = local_ns;
                }
            }
            else
            {
                VM& vm = GetVM();
                ns = vm.GetDefXMLNamespace();
                if (ns == NULL)
                    ns = &vm.GetPublicNamespace();
                else if (ns->GetPrefix().IsUndefined())
                {
                    Instances::Namespace* local_ns = FindNamespaceByURI(ns->GetUri(), NULL);
                    if (local_ns)
                        ns = local_ns;
                }
            }
            const ASString name = mn.Name.AsString();
            InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(
                GetVM().GetXMLSupport().GetClassTraitsXMLList()->GetInstanceTraits());
            result = Sfr04NewTargetListOf(itr, *this, name, *ns);
        }
        else
        {
            InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(
                GetVM().GetXMLSupport().GetClassTraitsXMLList()->GetInstanceTraits());
            result = Sfr04NewXMLList(itr);
        }
        return result;
    }

    // @0x142429df0
    __declspec(noinline) void XML::prototypeGet(SPtr<XMLList>& result)
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(
            GetVM().GetXMLSupport().GetClassTraitsXMLList()->GetInstanceTraits());
        result = Pickable<XMLList>(new(itr.Alloc()) XMLList(itr));
    }

    // @0x142415320
    void XMLElement::GetChildren(XMLList& list, const Multiname& prop_name)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            if (ind <= Children.GetSize())
                list.Append(Children[ind]);
        }
        else
        {
            ChildGet cb(*this, list);
            ForEachChild(prop_name, cb);
        }
    }

    // A node kind (and, for processing instructions, a name other than "" or "*") selects children; kNone takes
    // them all.
    // MS2-FUNCTIONAL: the exe calls the ArrayLH copy-assignment out of line
    // @0x1424153c0
    void XMLElement::GetChildren(XMLList& list, Kind k, const ASString* name)
    {
        if (k == kNone)
        {
            list.List = Children;
            return;
        }
        const bool any_name = name == NULL || name->IsEmpty() || *name == "*";
        const UPInt n = Children.GetSize();
        for (UPInt i = 0; i < n; ++i)
        {
            XML* child = Children[i];
            const Kind ck = child->GetKind();
            if (ck == k && (ck != kInstruction || name == NULL || any_name || child->GetName() == *name))
                list.List.PushBack(SPtr<XML>(child));
        }
    }

    // @0x142416910
    CheckResult XMLElement::GetProperty(const Multiname& prop_name, Value& value)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            if (ind == 0)
            {
                value.Assign(this);
                return true;
            }
            value.SetUndefined();
            return false;
        }
        XMLList* list = MakeXMLListInstance(prop_name).GetPtr();
        value.Pick(list);
        return GetProperty(prop_name, *list);
    }

    // @0x1424169f0
    CheckResult XMLElement::GetProperty(const Multiname& prop_name, XMLList& list)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            if (ind < Children.GetSize())
                list.Append(Children[ind]);
            return true;
        }
        if (prop_name.IsAttr())
        {
            AttrGet cb(*this, list);
            ForEachAttr(prop_name, cb);
            return true;
        }
        ChildGet cb(*this, list);
        return ForEachChild(prop_name, cb) != 0;
    }

    // XMLElement::ForEachAttr (sfr_as3_03), expanded in place as the exe does
    static __forceinline UInt32 Sfr04ForEachAttr(ArrayLH<SPtr<XMLAttr> >& attrs, const Multiname& prop_name, XMLElement::CallBack& cb)
    {
        UInt32 num = 0;
        if (prop_name.Name.IsString())
        {
            const UPInt size = attrs.GetSize();
            for (UPInt i = 0; i < size; ++i)
            {
                if (attrs[i]->Matches(prop_name))
                {
                    ++num;
                    if (!cb.Call(i))
                        break;
                }
            }
        }
        return num;
    }

    // The attributes (for an attribute name) or elements prop_name matches, at any depth, in document order.
    // @0x1424157d0
    void XMLElement::GetDescendants(XMLList& list, const Multiname& prop_name)
    {
        if (prop_name.IsAttr())
        {
            AttrGet cb(*this, list);
            Sfr04ForEachAttr(Attrs, prop_name, cb);
        }

        const UPInt size = Children.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            XML* child = Children[i];

            if (!prop_name.IsAttr())
            {
                if (child->Matches(prop_name))
                    list.List.PushBack(SPtr<XML>(child));   // XMLList::Append, inlined
            }

            child->GetDescendants(list, prop_name);
        }
    }

    // p names an attribute ("@x") or a child of this element.
    // @0x142417330
    bool XMLElement::HasOwnProperty(const ASString& p)
    {
        bool result = false;

        if (p.IsEmpty())
            return result;

        EmptyCallBack cb(*this);
        Multiname mn(GetVM().GetPublicNamespace(), p);

        if (mn.IsAttr())
        {
            result = Sfr04ForEachAttr(Attrs, mn, cb) != 0;
        }
        else
            result = ForEachChild(mn, cb) != 0;

        return result;
    }

    // MS2-FUNCTIONAL: frame layout: the exe keeps ind and the CheckResult in the argument home slots
    // @0x1424174c0
    bool XMLElement::HasProperty(const Multiname& prop_name, bool /*check_prototype*/)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
            return ind == 0;
        EmptyCallBack cb(*this);
        if (prop_name.IsAttr())
            return ForEachAttr(prop_name, cb) != 0;
        if (ForEachChild(prop_name, cb) != 0)
            return true;
        return false;
    }

    // @0x142416c50
    SPtr<QName> XMLAttr::GetQName()
    {
        InstanceTraits::Traits& itr = GetVM().GetXMLSupport().GetClassTraitsQName()->GetInstanceTraits();
        Instances::Namespace* ns = Ns.GetPtr();
        return Pickable<QName>(new(itr.Alloc()) QName(itr, Text, ns));
    }

    // @0x142416d00
    SPtr<QName> XMLElement::GetQName()
    {
        InstanceTraits::Traits& itr = GetVM().GetXMLSupport().GetClassTraitsQName()->GetInstanceTraits();
        Instances::Namespace* ns = Ns.GetPtr();
        return Pickable<QName>(new(itr.Alloc()) QName(itr, Text, ns));
    }

    // A processing instruction's target is in the public namespace.
    // @0x142416db0
    SPtr<QName> XMLProcInstr::GetQName()
    {
        InstanceTraits::Traits& itr = GetVM().GetXMLSupport().GetClassTraitsQName()->GetInstanceTraits();
        Instances::Namespace* ns = &GetVM().GetPublicNamespace();
        return Pickable<QName>(new(itr.Alloc()) QName(itr, Text, ns));
    }

    // @0x142421c40
    void XMLAttr::SetNamespace(Namespace& ns)
    {
        Ns = &ns;
    }

    // @0x142421b50
    void XMLAttr::SetNamespace2(Namespace& ns)
    {
        Ns = &ns;
    }

    // The children become value: a node, a list's items, or a text node of value's string.
    // @0x142421780
    void XMLElement::SetChildren(const Value& value)
    {
        VM& vm = GetVM();
        Children.Clear();

        if (IsXMLObject(value))
        {
            XML* xml = static_cast<XML*>(value.GetObject());

            for (XML* node = this; node; node = node->Parent)
            {
                if (node == xml)
                    return vm.ThrowTypeError(VM::Error(VM::eXMLIllegalCyclicalLoop, vm));
            }

            xml->SetParent(this);
            Children.PushBack(xml);
        }
        else if (IsXMLListObject(value))
        {
            XMLList* list = static_cast<XMLList*>(value.GetObject());
            const UPInt size = list->List.GetSize();

            for (UPInt i = 0; i < size; ++i)
            {
                XML* xml = list->List[i];

                for (XML* node = this; node; node = node->Parent)
                {
                    if (node == xml)
                        return vm.ThrowTypeError(VM::Error(VM::eXMLIllegalCyclicalLoop, vm));
                }

                xml->Parent = this;
            }

            Children = list->List;
        }
        else
        {
            ASString txt = vm.GetStringManager().CreateEmptyString();
            if (value.Convert2String(txt))
            {
                InstanceTraits::Traits& itr = GetInstanceTraits();
                Children.PushBack(Pickable<XML>(new(itr.GetVM().GetMemoryHeap()) XMLText(itr, txt, this)));
            }
        }
    }

    // @0x142421f80
    __declspec(noinline) void XML::SetParent(XML* p)
    {
        Parent = p;
    }

    // The attributes follow the element into ns.
    // @0x142421cb0
    void XMLElement::SetNamespace(Namespace& ns)
    {
        Ns = &ns;
        const UPInt n = Attrs.GetSize();
        for (UPInt i = 0; i < n; ++i)
            Attrs[i]->SetNamespace(ns);
    }

    // @0x142421bc0
    void XMLElement::SetNamespace2(Namespace& ns)
    {
        Ns = &ns;
    }

    // Collect the prefix of Ns into nr unless lp already declares it.
    // @0x142420270
    void XMLAttr::ResolveNamespaces(HashSetDH<ASString>& nr, XML* lp) const
    {
        if (Ns->GetPrefix().IsString())
        {
            const ASString prefix = ASString(ASString(Ns->GetPrefix()));
            if (!FindNamespaceByPrefix(prefix, lp) && !nr.Get(prefix))
                nr.Add(prefix);
        }
    }

    // MS2-FUNCTIONAL: hash byte terms scheduled in a different order
    // @0x1424203b0
    void XMLElement::ResolveNamespaces(HashSetDH<ASString>& nr, XML* lp) const
    {
        if (Ns->GetPrefix().IsString())
        {
            const ASString prefix = ASString(ASString(Ns->GetPrefix()));
            if (!FindNamespaceByPrefix(prefix, lp) && !nr.Get(prefix))
                nr.Add(prefix);
        }

        UPInt n = Attrs.GetSize();
        for (UPInt i = 0; i < n; ++i)
            Attrs[i]->ResolveNamespaces(nr, lp);

        n = Children.GetSize();
        for (UPInt i = 0; i < n; ++i)
            Children[i]->ResolveNamespaces(nr, lp);
    }

    // An attribute prints as its escaped value.
    // @0x142425d20
    void XMLAttr::ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                              const NamespaceArray* usedNotDeclared)
    {
        SF_UNUSED3(ident, ancestorNamespaces, usedNotDeclared);
        const char* p = Data.ToCStr();
        const char* end = p + Data.GetSize();
        while (p < end)
        {
            const UInt32 ch = UTF8Util::DecodeNextChar_Advance0(&p);
            switch (ch)
            {
            case '\t':
                buf.AppendString("&#x9;", 5);
                break;
            case '\n':
                buf.AppendString("&#xA;", 5);
                break;
            case '\r':
                buf.AppendString("&#xD;", 5);
                break;
            case '<':
                buf.AppendString("&lt;", 4);
                break;
            case '"':
                buf.AppendString("&quot;", 6);
                break;
            case '\'':
                buf.AppendString("&apos;", 6);
                break;
            case '&':
                buf.AppendString("&amp;", 5);
                break;
            default:
                buf.AppendChar(ch);
                break;
            }
        }
    }

    // @0x142425a60
    void XMLComment::ToString(StringBuffer& buf, SInt32 ident)
    {
        ToXMLString(buf, ident, NULL, NULL);
    }

    // @0x142425ea0
    void XMLComment::ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared)
    {
        SF_UNUSED2(ancestorNamespaces, usedNotDeclared);
        const Classes::fl::XML& cl = static_cast<const Classes::fl::XML&>(FUN_142508460(&GetTraits()));
        bool pretty = cl.prettyPrinting;
        if (cl.prettyIndent < 0)
            pretty = false;
        if (pretty && ident > 0)
            AddIndent(buf, ident);
        buf.AppendString("<!--", 4);
        buf.AppendString(Text.ToCStr(), Text.GetSize());
        buf.AppendString("-->", 3);
    }

    // @0x142427020
    void XMLProcInstr::ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                   const NamespaceArray* usedNotDeclared)
    {
        SF_UNUSED2(ancestorNamespaces, usedNotDeclared);
        const Classes::fl::XML& cl = static_cast<const Classes::fl::XML&>(FUN_142508460(&GetTraits()));
        bool pretty = cl.prettyPrinting;
        if (cl.prettyIndent < 0)
            pretty = false;
        if (pretty && ident > 0)
            AddIndent(buf, ident);
        buf.AppendString("<?", 2);
        buf.AppendString(Text.ToCStr(), Text.GetSize());
        buf.AppendChar(' ');
        buf.AppendString(Data.ToCStr(), Data.GetSize());
        buf.AppendString("?>", 2);
    }

    // Pretty printing trims the text.
    // @0x1424270d0
    void XMLText::ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                              const NamespaceArray* usedNotDeclared)
    {
        SF_UNUSED2(ancestorNamespaces, usedNotDeclared);
        const Classes::fl::XML& cl = static_cast<const Classes::fl::XML&>(FUN_142508460(&GetTraits()));
        bool pretty = cl.prettyPrinting;
        if (cl.prettyIndent < 0)
            pretty = false;
        if (pretty && ident > 0)
            AddIndent(buf, ident);
        const Classes::fl::XML& cl2 = static_cast<const Classes::fl::XML&>(FUN_142508460(&GetTraits()));
        const ASString& text = Text;
        if (cl2.prettyPrinting)
        {
            EscapeElementValue(buf, ASString(text.TruncateWhitespaceNode()));
            return;
        }
        EscapeElementValue(buf, text);
    }

    // Simple content prints as the text of its text children, anything else as XML.
    // @0x142425a80
    void XMLElement::ToString(StringBuffer& buf, SInt32 ident)
    {
        const UPInt n = Children.GetSize();
        for (UPInt i = 0; i < n; ++i)
        {
            if (Children[i]->GetKind() == kElement)
            {
                ToXMLString(buf, ident, NULL, NULL);
                return;
            }
        }
        const UPInt size = Children.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            XML* child = Children[i];
            if (child->GetKind() == kText)
                child->ToString(buf, ident);
        }
    }

    // @0x1424151e0
    void XMLElement::GetAttributes(XMLList& list)
    {
        const UPInt n = Attrs.GetSize();
        for (UPInt i = 0; i < n; ++i)
            list.List.PushBack(SPtr<XML>(Attrs[i]));
    }

    // @0x1424176b0
    bool XMLElement::HasSimpleContent() const
    {
        const UPInt n = Children.GetSize();
        for (UPInt i = 0; i < n; ++i)
        {
            if (Children[i]->GetKind() == kElement)
                return false;
        }
        return true;
    }

    // Insert value (a node, a list's items, or a node built from value) as child pos; a text node goes in as a
    // copy. Nothing is inserted past the end, nor an ancestor of this element.
    // MS2-FUNCTIONAL: register allocation and list-loop induction differ
    // @0x142419270
    CheckResult XMLElement::InsertChildAt(UPInt pos, const Value& value)
    {
        VM& vm = GetVM();
        bool result = false;

        if (IsXMLListObject(value))
        {
            XMLList* list = static_cast<XMLList*>(value.GetObject());
            const UPInt size = list->List.GetSize();

            for (UPInt i = 0; i < size; ++i)
            {
                XML* v = list->List[i];

                for (XML* node = this; node; node = node->Parent)
                {
                    if (node == v)
                    {
                        vm.ThrowTypeError(VM::Error(VM::eXMLIllegalCyclicalLoop, vm));
                        return result;
                    }
                }

                const UPInt size = Children.GetSize();
                if (pos + i < size)
                {
                    if (v->GetKind() == kText)
                        Children.InsertAt(pos + i, v->DeepCopy(this));
                    else
                    {
                        Children.InsertAt(pos + i, v);
                        v->SetParent(this);
                    }

                    result = true;
                }
                else if (pos + i == size)
                {
                    if (v->GetKind() == kText)
                        Children.PushBack(v->DeepCopy(this));
                    else
                    {
                        Children.PushBack(v);
                        v->SetParent(this);
                    }

                    result = true;
                }
            }
        }
        else
        {
            SPtr<XML> v;
            if (IsXMLObject(value))
                v = static_cast<XML*>(value.GetObject());
            else
            {
                Value _this;
                FUN_142508460(&GetInstanceTraits()).Construct(_this, 1, &value, true);
                if (GetVM().IsException())
                    return result;

                if (_this.IsNull())
                    return result;

                v = static_cast<XML*>(_this.GetObject());
            }

            for (XML* node = this; node; node = node->Parent)
            {
                if (node == v)
                {
                    vm.ThrowTypeError(VM::Error(VM::eXMLIllegalCyclicalLoop, vm));
                    return result;
                }
            }

            const UPInt size = Children.GetSize();
            if (pos < size)
            {
                if (v->GetKind() == kText)
                    Children.InsertAt(pos, v->DeepCopy(this));
                else
                {
                    Children.InsertAt(pos, v);
                    v->SetParent(this);
                }

                result = true;
            }
            else if (pos == size)
            {
                if (v->GetKind() == kText)
                    Children.PushBack(v->DeepCopy(this));
                else
                {
                    Children.PushBack(v);
                    v->SetParent(this);
                }

                result = true;
            }
        }

        return result;
    }

    // @0x1424191a0
    CheckResult XMLElement::InsertChildAfter(const Value& child1, const Value& child2)
    {
        bool result = false;

        if (child1.IsNullOrUndefined())
            result = InsertChildAt(0, child2);
        else
        {
            XML* x = ToXML(child1);
            if (x)
            {
                const UPInt n = Children.GetSize();
                for (UPInt i = 0; i < n; ++i)
                {
                    if (Children[i] == x)
                    {
                        result = InsertChildAt(static_cast<UInt32>(i + 1), child2);
                        break;
                    }
                }
            }
        }

        return result;
    }

    // @0x1424197f0
    CheckResult XMLElement::InsertChildBefore(const Value& child1, const Value& child2)
    {
        bool result = false;

        if (child1.IsNullOrUndefined())
            result = InsertChildAt(static_cast<UInt32>(Children.GetSize()), child2);
        else
        {
            XML* x = ToXML(child1);
            if (x)
            {
                const UPInt n = Children.GetSize();
                for (UPInt i = 0; i < n; ++i)
                {
                    if (Children[i] == x)
                    {
                        result = InsertChildAt(static_cast<UInt32>(i), child2);
                        break;
                    }
                }
            }
        }

        return result;
    }

    // @0x142425c90
    XML* XMLElement::ToXML(const Value& v) const
    {
        if (IsXMLObject(v))
            return static_cast<XML*>(v.GetObject());
        if (IsXMLListObject(v))
        {
            XMLList* list = static_cast<XMLList*>(v.GetObject());
            if (list->List.GetSize() == 1)
                return list->List[0];
        }
        return NULL;
    }

    // @0x14241f4b0
    CheckResult XMLElement::Replace(const Multiname& prop_name, const Value& value)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
            return Replace(ind, value);

        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eXMLAssignmentToIndexedXMLNotAllowed, vm));
        return false;
    }

    // Drop ns from the in-scope declarations of this element and its children, unless the element or one of
    // its attributes is in ns.
    // s has only white space.
    static inline bool IsWhiteSpaceString(const ASString& s)
    {
        for (UInt32 i = 0; i < s.GetSize(); ++i)
        {
            if (!ASUtils::IsWhiteSpace(s[i]))
                return false;
        }
        return true;
    }

    // Merge each run of adjacent text children into its first non-blank node; blank leading text goes.
    // @0x14241d580
    void XMLElement::Normalize()
    {
        XMLText* txt = NULL;
        UPInt size = Children.GetSize();

        for (UPInt i = 0; i < size; ++i)
        {
            XML* child = Children[i];

            if (child->GetKind() == kText)
            {
                XMLText* txt_child = static_cast<XMLText*>(child);

                if (txt)
                {
                    if (!txt_child->Text.IsEmpty())
                        txt->Text.Append(txt_child->Text);

                    Children.RemoveAt(i);
                    --i;
                    --size;
                }
                else if (!txt_child->Text.IsEmpty() && !IsWhiteSpaceString(txt_child->Text))
                    txt = txt_child;
                else
                {
                    Children.RemoveAt(i);
                    --i;
                    --size;
                }
            }
            else
                txt = NULL;
        }
    }

    // @0x14241efd0
    XML* XMLElement::RemoveNamespace(const Value& ns)
    {
        SPtr<const Namespace> removeNs;

        if (ns.IsNamespace())
            removeNs = &ns.AsNamespace();
        else
            removeNs = GetVM().MakeNamespace(Abc::NS_Private, ns.AsString(), Value::GetUndefined());

        if (GetNamespace() == *removeNs)
            return this;

        for (UPInt i = 0; i < Attrs.GetSize(); ++i)
        {
            if (Attrs[i]->GetNamespace() == *removeNs)
                return this;
        }

        for (UPInt i = 0; i < Namespaces.Namespaces.GetSize(); ++i)
        {
            const Namespace& inScopeNs = *Namespaces.Namespaces[i];
            if (inScopeNs.GetUri() == removeNs->GetUri() &&
                (removeNs->GetPrefix().IsUndefined() || StrictEqual(removeNs->GetPrefix(), inScopeNs.GetPrefix())))
            {
                Namespaces.Namespaces.RemoveAt(i);
                break;
            }
        }

        for (UPInt i = 0; i < Children.GetSize(); ++i)
            Children[i]->RemoveNamespace(ns);

        return this;
    }

    // MS2-FUNCTIONAL: the exe calls SetParent and the SPtr<XML> assignment out of line
    // @0x14241f1a0
    CheckResult XMLElement::Replace(UPInt ind, const Value& value)
    {
        bool result = true;

        if (ind >= Children.GetSize())
        {
            Children.Resize(Children.GetSize() + 1);
            ind = Children.GetSize() - 1;
            Children[ind] = NULL;
        }

        if (value.IsObject() && IsXMLObject(value.GetObject()) &&
            static_cast<XML*>(value.GetObject())->GetKind() != kAttr)
        {
            XML* x = static_cast<XML*>(value.GetObject());
            if (x->GetKind() == kElement)
            {
                for (XML* p = this; p; p = p->Parent)
                {
                    if (p == x)
                    {
                        VM& vm = GetVM();
                        vm.ThrowTypeError(VM::Error(VM::eXMLIllegalCyclicalLoop, vm));
                        return false;
                    }
                }
            }

            x->SetParent(this);
            if (Children[ind])
                Children[ind]->Parent = NULL;
            Children[ind] = x;
        }
        else if (value.IsObject() && IsXMLListObject(value.GetObject()))
        {
            DeleteByIndex(ind);
            result = InsertChildAt(ind, value);
        }
        else
        {
            if (Children[ind])
                Children[ind]->Parent = NULL;
            ASString str = value.AsString();
            Children[ind] = Pickable<XML>(new(GetVM().GetMemoryHeap()) XMLText(GetInstanceTraits(), str, this));
        }

        return result;
    }

    // @0x1424166c0
    void XMLList::GetNextPropertyValue(Value& value, GlobalSlotIndex ind)
    {
        if (ind.Get() <= static_cast<UInt32>(List.GetSize()))
            value.Assign(List[ind.Get() - 1]);
        else
            value.SetUndefined();
    }

    // @0x142416ad0
    __declspec(noinline) CheckResult XMLList::GetProperty(const Multiname& prop_name, XMLList& list)
    {
        if (prop_name.IsAttr())
        {
            const UPInt n = List.GetSize();
            for (UPInt i = 0; i < n; ++i)
                List[i]->GetProperty(prop_name, list);
            return list.List.GetSize() != 0;
        }
        ListGet cb(*this, list);
        return ForEachChild(prop_name, cb) != 0;
    }

    // @0x142416b90
    CheckResult XMLList::GetProperty(const Multiname& prop_name, Value& value)
    {
        UInt32 ind;
        if (GetVectorInd(prop_name, ind))
        {
            if (ind < List.GetSize())
            {
                value.Assign(List[ind]);
                return true;
            }
            return false;
        }
        Pickable<XMLList> list = MakeXMLListInstance(prop_name);
        value.Pick(list);
        return GetProperty(prop_name, *list);
    }

    // The names of a list are its indices, "0" up.
    // Past the end the name is the builtin "null" string (0x1424164ee lea rdx,[rsi+0x10]: Builtins[2]).
    // @0x142416430
    void XMLList::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
    {
        StringManager& sm = GetVM().GetStringManager();
        if (ind.Get() <= static_cast<UInt32>(List.GetSize()))
        {
            LongFormatter f(ind.Get() - 1);
            f.Convert();
            name.Assign(sm.CreateString(f.ToCStr(), f.GetSize()));
        }
        else
            name.Assign(sm.GetBuiltin(AS3Builtin_null));
    }

    // XMLList::MakeXMLListInstance(), expanded in place as the exe does.
    static __forceinline Pickable<XMLList> Sfr04NewXMLListLike(XMLList& self)
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(self.GetInstanceTraits());
        if (self.TargetNamespace && self.TargetObject && self.TargetProperty)
            return itr.MakeInstance(itr, *self.TargetObject, ASString(self.TargetProperty), *self.TargetNamespace);
        return Sfr04NewXMLList(itr);
    }

    // InstanceTraits::fl::XMLList::MakeInstance(itr, obj, name, ns) on this list's traits.
    static __forceinline Pickable<XMLList> Sfr04NewTargetList(XMLList& self, const ASString& name, Instances::Namespace& ns)
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(self.GetInstanceTraits());
        return itr.MakeInstance(itr, self, name, ns);
    }

    // register allocation of the target fields differs
    // @0x14241b350
    Pickable<XMLList> XMLList::MakeXMLListInstance()
    {
        InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(GetInstanceTraits());
        if (TargetNamespace && TargetObject && TargetProperty)
            return itr.MakeInstance(itr, *TargetObject, ASString(TargetProperty), *TargetNamespace);
        return itr.MakeInstance(itr);
    }

    // @0x14241b190
    Pickable<XMLList> XMLList::MakeXMLListInstance(const Multiname& mn)
    {
        Pickable<XMLList> result;
        if (mn.Name.IsString())
        {
            Instances::Namespace* ns;
            if (mn.IsQName() && !mn.IsAnyNamespace())
            {
                ns = &mn.GetNamespace();
                if (ns->GetPrefix().IsUndefined())
                {
                    Instances::Namespace* local_ns = FindNamespaceByURI(ns->GetUri());
                    if (local_ns)
                        ns = local_ns;
                }
            }
            else
            {
                VM& vm = GetVM();
                ns = vm.GetDefXMLNamespace();
                if (ns == NULL)
                    ns = &vm.GetPublicNamespace();
                else if (ns->GetPrefix().IsUndefined())
                {
                    Instances::Namespace* local_ns = FindNamespaceByURI(ns->GetUri());
                    if (local_ns)
                        ns = local_ns;
                }
            }
            const ASString name = mn.Name.AsString();
            result = Sfr04NewTargetList(*this, name, *ns);
        }
        else
            result = Sfr04NewXMLListLike(*this);
        return result;
    }

    // @0x142429ea0
    void XMLList::prototypeGet(SPtr<XMLList>& result)
    {
        result = Sfr04NewXMLListLike(*this);
    }

    // @0x142423e50
    Pickable<XMLList> XMLList::ShallowCopy()
    {
        Pickable<XMLList> result = MakeXMLListInstance();
        const UPInt n = List.GetSize();
        for (UPInt i = 0; i < n; ++i)
            result->List.PushBack(List[i]);
        return result;
    }

    // @0x142423b50
    void XMLList::SetTargetProperty(ASStringNode* prop)
    {
        if (TargetProperty)
            TargetProperty->Release();
        TargetProperty = prop;
        if (prop)
            prop->AddRef();
    }
}}}}} // namespace Scaleform::GFx::AS3::Instances::fl

namespace Scaleform { namespace GFx { namespace AS3
{
    // @0x142416f20
    void XMLParser::GetRootNodes(ArrayLH<SPtr<Instances::fl::XML> >& nodes) const
    {
        for (UPInt i = 0; i < RootElements.GetSize(); ++i)
            nodes.PushBack(RootElements[i]);
    }
}}} // namespace Scaleform::GFx::AS3

// The array element types of the Array sort helpers and of the XML parser's node-kind stack.
// ==== sfr21: the remaining members of this range =====================================================================
// the Unicode character class tables (Scaleform Kernel)
extern const Scaleform::UInt16 DAT_143186050[];   // alpha
extern const Scaleform::UInt16 DAT_1431866f0[];   // digit

namespace Scaleform { namespace GFx { namespace AS3
{
// (as sfr_as3_01c) the builtin ClassInfo registration hash of GlobalObjectCPP: chained entries of name -> ClassInfo
struct CIRegistrationEntry
{
    SPInt            NextInChain;   // -2 empty, -1 end of chain
    UPInt            HashValue;     // the home index
    const char*      Key;
    const ClassInfo* Value;
};
struct CIRegistrationTable
{
    UPInt               EntryCount;
    UPInt               SizeMask;
    CIRegistrationEntry E[1];
};
}}} // namespace Scaleform::GFx::AS3

using Scaleform::UPInt;
using Scaleform::SPInt;
using Scaleform::String;
using Scaleform::Pickable;
using Scaleform::UnicodeCharIs;
using Scaleform::GFx::ASString;
using Scaleform::GFx::AS3::VM;
using Scaleform::GFx::AS3::SPtr;
using Scaleform::GFx::AS3::Class;
using Scaleform::GFx::AS3::ClassInfo;
using Scaleform::GFx::AS3::CheckResult;
using Scaleform::GFx::AS3::Multiname;
using Scaleform::GFx::AS3::VMAbcFile;
using Scaleform::GFx::AS3::ScopeStackType;
using Scaleform::GFx::AS3::CIRegistrationEntry;
using Scaleform::GFx::AS3::CIRegistrationTable;
namespace Instances = Scaleform::GFx::AS3::Instances;
namespace InstanceTraits = Scaleform::GFx::AS3::InstanceTraits;
namespace ClassTraits = Scaleform::GFx::AS3::ClassTraits;
namespace AS3 = Scaleform::GFx::AS3;

// VMAbcFile::GetFunctionInstanceTraits: the traits of method method_ind of a script
namespace Scaleform { namespace GFx { namespace AS3 {
InstanceTraits::Traits& FUN_14250a250(VMAbcFile* file, Instances::fl::GlobalObjectScript& gos, UInt32 method_ind);
}}}
using Scaleform::GFx::AS3::FUN_14250a250;

static __forceinline const CIRegistrationTable* Sfr04CITable(Instances::fl::GlobalObjectCPP* self)
{
    return *reinterpret_cast<const CIRegistrationTable* const*>(&self->CIRegistrationHash);
}

// Hash::findIndexCore over the registration table: the entry index of key, or -1
static __forceinline SPInt Sfr04CIFindIndex(const CIRegistrationTable* table, const char* key, UPInt hashValue)
{
    SPInt index = hashValue;
    const CIRegistrationEntry* e = &table->E[index];
    if (e->NextInChain == -2 || e->HashValue != (UPInt)index)
        return -1;
    for (;;)
    {
        if (e->HashValue == hashValue && strcmp(e->Key, key) == 0)
            return index;
        index = e->NextInChain;
        if (index == -1)
            break;
        e = &table->E[index];
    }
    return -1;
}

// GlobalObjectCPP: the class traits of a builtin class by name, made through its ClassInfo factory and kept in CTraits
// @0x142415520
ClassTraits::Traits* FUN_142415520(Instances::fl::GlobalObjectCPP* self, const ASString& name,
                                   const Instances::Namespace& ns)
{
    if (!Sfr04CITable(self))
        return NULL;
    const Instances::fl::ConstStringKey k = { name.ToCStr() };
    const char* key = k.pChar;
    const UPInt hashValue = Instances::fl::ConstStringHashFn()(k);
    // the table is read again after the hash, as Hash::findIndexAlt does
    const CIRegistrationTable* table = Sfr04CITable(self);
    const SPInt index = Sfr04CIFindIndex(table, key, hashValue & table->SizeMask);
    // Hash::GetAlt: the entry's node (Key, Value), then its value
    const char* const* pnode = index >= 0 ? &table->E[index].Key : NULL;
    if (!pnode)
        return NULL;
    const ClassInfo* ci = *reinterpret_cast<const ClassInfo* const*>(pnode + 1);
    if (!ci || strcmp(ns.GetUri().ToCStr(), ci->PkgName) != 0)
        return NULL;
    SPtr<ClassTraits::Traits> ctr(ci->Factory(self->GetVM()));
    self->CTraits.PushBack(ctr);
    return ctr.GetPtr();
}

// XMLList: the descendants of every item
// @0x142415930
void FUN_142415930(Instances::fl::XMLList* self, Instances::fl::XMLList& list, const Multiname& prop_name)
{
    const UPInt size = self->List.GetSize();
    for (UPInt i = 0; i < size; ++i)
        self->List[i]->GetDescendants(list, prop_name);
}

// InstanceTraits::Function: the VM of the script it belongs to
// MS2-FUNCTIONAL: written from the exe on raw offsets
// @0x142416720
void* FUN_142416720(const void* self)
{
    return *(void**)(*(const char* const*)((const char*)self + 0xf8) + 0x20);
}

// XMLList: the operation needs a one item list. A member in the exe (this in rcx, the result in rdx), so it is
// declared on a view of XMLList.
struct Sfr04XMLListView : public Instances::fl::XMLList
{
    CheckResult FUN_1424172b0(const char* method_name) const;
};
// written from the exe
// @0x1424172b0
CheckResult Sfr04XMLListView::FUN_1424172b0(const char* method_name) const
{
    if (List.GetSize() != 1)
    {
        VM& vm = GetVM();
        vm.ThrowTypeError(VM::Error(VM::eXMLOnlyWorksWithOneItemLists, vm, method_name));
        return false;
    }
    return true;
}

// a Function sharing f's traits, scope and name, bound to stored_this
// written from the exe
// @0x14241a490
Pickable<Instances::Function> InstanceTraits::Function::FUN_14241a490(Instances::Function& f, const AS3::Value& stored_this)
{
    InstanceTraits::Traits& t = f.GetInstanceTraits();
    const ScopeStackType& ss = *(const ScopeStackType*)((const char*)&f + 0x40);   // StoredScopeStack
    const ASString& name = *(const ASString*)((const char*)&f + 0x80);             // Name
    return Pickable<Instances::Function>(new(t.Alloc()) Instances::Function(t, ss, stored_this, name));
}

// a Function of method method_ind of file
// written from the exe
// @0x14241a410
Pickable<Instances::Function> InstanceTraits::Function::FUN_14241a410(VMAbcFile& file, Scaleform::UInt32 method_ind,
                                             const AS3::Value& stored_this, const ScopeStackType& ss,
                                             Instances::fl::GlobalObjectScript& gos, const ASString& name)
{
    InstanceTraits::Traits& t = FUN_14250a250(&file, gos, method_ind);
    return Pickable<Instances::Function>(new(t.Alloc()) Instances::Function(t, ss, stored_this, name));
}

// InstanceTraits::fl::QName: a new QName (empty local name, public namespace)
// @0x14241ace0
Pickable<Instances::fl::QName> InstanceTraits::fl::QName::FUN_14241ace0(InstanceTraits::Traits& t)
{
    return Pickable<Instances::fl::QName>(new(t.Alloc()) Instances::fl::QName(t));
}

// InstanceTraits::fl::XML: a new node of kind none with empty text
// @0x14241ae30
__declspec(noinline) Pickable<Instances::fl::XML> InstanceTraits::fl::XML::FUN_14241ae30(InstanceTraits::Traits& t)
{
    return Pickable<Instances::fl::XML>(new(t.Alloc()) Instances::fl::XML(t));
}

// InstanceTraits::fl::XML: a new node of kind none holding text
// @0x14241aec0
Pickable<Instances::fl::XML> InstanceTraits::fl::XML::FUN_14241aec0(InstanceTraits::Traits& t, const ASString& text,
                                                                    Instances::fl::XML* parent)
{
    InstanceTraits::Traits* self = this;
    return Pickable<Instances::fl::XML>(new(self->GetVM().GetMemoryHeap()) Instances::fl::XML(t, text, parent));
}

// Instances::fl::XML: a new empty node of this node's traits
// written from the exe
// @0x14241af60
Pickable<Instances::fl::XML> Instances::fl::XML::FUN_14241af60()
{
    InstanceTraits::Traits& itr = GetInstanceTraits();
    return static_cast<InstanceTraits::fl::XML&>(itr).FUN_14241ae30(itr);
}

// Instances::fl::XMLList: a new list of this list's traits targeting target_prop of target_obj
// written from the exe
// @0x14241b160
Pickable<Instances::fl::XMLList> Instances::fl::XMLList::FUN_14241b160(AS3::Object& target_obj, const ASString& target_prop,
                                                                       Instances::Namespace& target_ns)
{
    InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(GetInstanceTraits());
    return itr.MakeInstance(itr, target_obj, target_prop, target_ns);
}

// a new empty XMLList of the VM's XMLList class
// written from the exe
// @0x14241ca30
Pickable<Instances::fl::XMLList> Instances::fl::XML::FUN_14241ca30()
{
    InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(
        GetVM().GetXMLSupport().GetClassTraitsXMLList()->GetInstanceTraits());
    return itr.MakeInstance(itr);
}

namespace Scaleform { namespace GFx { namespace AS3
{
namespace Instances { namespace fl
{
    // for-in over a QName: "uri", then "localName"
    // @0x142416330
    void QName::GetNextPropertyName(Value& name, GlobalSlotIndex ind) const
    {
        StringManager& sm = GetVM().GetStringManager();
        switch (ind.Get())
        {
        case 1:
            name.Assign(sm.CreateConstString("uri"));
            break;
        case 2:
            name.Assign(sm.CreateConstString("localName"));
            break;
        }
    }

    // @0x142429490
    void QName::localNameGet(ASString& result)
    {
        result = LocalName;
    }

    // @0x142428fa0
    void GlobalObjectCPP::isXMLName(bool& result, const Value& str)
    {
        if (str.IsNullOrUndefined())
        {
            result = false;
            return;
        }
        ASString name = GetVM().GetStringManager().CreateEmptyString();
        if (!str.Convert2String(name))
            GetVM().ThrowArgumentError(VM::Error(VM::ErrorID(1050), GetVM()));   // eConvertToPrimitiveError

        if (name.GetSize() == 0)
        {
            result = false;
            return;
        }

        wchar_t ch = (wchar_t)name.GetCharAt(0);
        if (!UnicodeCharIs(DAT_143186050, ch) && ch != '_')     // SFiswalpha
        {
            result = false;
            return;
        }

        for (unsigned i = 1; i < name.GetLength(); i++)
        {
            wchar_t ch = (wchar_t)name.GetCharAt(i);
            if (UnicodeCharIs(DAT_1431866f0, ch) || UnicodeCharIs(DAT_143186050, ch) || (ch == '.') || (ch == '-') || (ch == '_'))
                continue;
            else
            {
                result = false;
                return;
            }
        }

        result = true;
    }
}} // namespace Instances::fl

namespace InstanceTraits { namespace fl
{
    // @0x14241c0c0
    void QName::MakeObject(Value& result, Traits& t)
    {
        result = FUN_14241ace0(t);
    }

    // @0x14241b7a0
    SF_NOINLINE Pickable<Instances::fl::XMLText> XML::MakeInstanceText(XML& t, const ASString& str, Instances::fl::XML* parent)
    {
        return Pickable<Instances::fl::XMLText>(new(GetVM().GetMemoryHeap()) Instances::fl::XMLText(t, str, parent));
    }
}} // namespace InstanceTraits::fl
}}} // namespace Scaleform::GFx::AS3

// ---- the namespace, script and class-traits helpers
extern const Scaleform::GFx::AS3::ThunkInfo DAT_14313e4e0[4];   // Classes::Function prototype methods
// VM: the class traits a multiname of file names (NULL when unresolved)
namespace Scaleform { namespace GFx { namespace AS3 { UPInt Sfr31ResolveClassTraits(UPInt vm, UPInt file, UPInt mn); }}}
// IsScaleformGFx: whether ns is the "scaleform.gfx" namespace
bool FUN_142514cd0(const Instances::Namespace& ns);
// Traits: the interface slots of an interface class (class_info: its Abc::ClassInfo)
namespace Scaleform { namespace GFx { namespace AS3 { void Sfr21AddInterfaceSlots(Traits* self, VMAbcFile& file, const Abc::ClassInfo& info); }}}

// InstanceTraits::fl::Namespace: the interned namespace of {kind, uri}, else the public one (NULL once the traits are
// gone)
// NamespaceInstanceFactory::GetNamespace (SDK body), inlined into its caller.
static __forceinline Instances::Namespace& As3_04GetNamespace(Scaleform::GFx::AS3::NamespaceInstanceFactory* f,
                                                             Scaleform::GFx::AS3::Abc::NamespaceKind kind,
                                                             const ASString& uri)
{
    Scaleform::GFx::AS3::NamespaceInstanceFactory::Key key(kind, uri);
    Instances::Namespace* ns = 0;
    if (!f->NamespaceSet.GetAlt(key, &ns))
    {
        if (f->pNamespaceInstanceTraits)
            return f->pNamespaceInstanceTraits->GetVM().GetPublicNamespace();
    }
    return *ns;
}

// @0x142415c20
Instances::Namespace* FUN_142415c20(InstanceTraits::fl::Namespace* self, Scaleform::GFx::AS3::Abc::NamespaceKind kind,
                                    const ASString& uri, const Scaleform::GFx::AS3::Value& /*prefix*/)
{
    return &As3_04GetNamespace(self->InstanceFactory, kind, uri);
}

// the name of the trait a method's body belongs to
// Written from the exe on raw offsets (VMAbcFile +0x28, Abc::File tables)
// @0x142416e70
const void* FUN_142416e70(const char* self)
{
    const char* abc = *(const char* const*)(*(const char* const*)(self + 0xf0) + 0x28);
    const char* const* methods = *(const char* const* const*)(abc + 0xf8);
    const char* const* bodies = *(const char* const* const*)(abc + 0x170);
    const char* mi = methods[*(const int*)(self + 0xe8)];
    const char* body = bodies[*(const int*)(mi + 8)];
    const AS3::Abc::TraitInfo* ti = reinterpret_cast<const AS3::Abc::TraitInfo*>(methods[*(const int*)(body + 0x18)]);
    return &ti->GetName(*reinterpret_cast<const AS3::Abc::ConstPool*>(abc + 0x30));
}

// ClassTraits::UserDefined::GetSuperClassTraits: the class traits of a class's super class; an unresolved name
// throws VerifyError 1001 (eNotImplementedError, as the SDK does).
// MS2-FUNCTIONAL: written from the exe on raw offsets. Same length as the exe; only the entry differs: the exe
// moves the file to rsi before it loads the super-name index into rcx, ours loads the index into rax first.
// @0x142417000
ClassTraits::Traits* FUN_142417000(VMAbcFile* self, const char* class_info)
{
    ClassTraits::Traits* result = NULL;
    const int ind = *(const int*)(class_info + 0x28);
    if (ind != 0)
    {
        // the abc file (+0x28) and the VM (+0x20) are read at each use
        const char* mn = *(const char* const*)(*(const char* const*)((const char*)self + 0x28) + 0xb8) + (SPInt)ind * 0x10;
        result = reinterpret_cast<ClassTraits::Traits*>(AS3::Sfr31ResolveClassTraits(*(const UPInt*)((const char*)self + 0x20), reinterpret_cast<UPInt>(self), reinterpret_cast<UPInt>(mn)));
        if (!result)
        {
            const Scaleform::StringDataPtr s =
                (*(const Scaleform::GFx::AS3::Abc::StringView* const*)(*(const char* const*)((const char*)self + 0x28) + 0x70))[*(const unsigned*)(mn + 8)].ToStringDataPtr();
            String name(s.ToCStr(), s.GetSize());
            VM* vm = *(VM* const*)((const char*)self + 0x20);
            vm->ThrowVerifyError(VM::Error(VM::ErrorID(0x3e9), *vm, name.ToCStr()));
        }
    }
    return result;
}

// XMLElement::HasProperty, inlined into the list's
static SF_INLINE bool Sfr04XmlElementHasProperty(Instances::fl::XMLElement* el, const Multiname& prop_name)
{
    Scaleform::UInt32 ind;
    if (Scaleform::GFx::AS3::GetVectorInd(prop_name, ind))
        return ind == 0;
    Instances::fl::EmptyCallBack cb(*el);
    if ((prop_name.IsAttr() ? el->ForEachAttr(prop_name, cb) : el->ForEachChild(prop_name, cb)) != 0)
        return true;
    return false;
}

// XMLList::HasProperty: an index within the list, or a matching child / attribute of an element item
// MS2-FUNCTIONAL: exe tests the empty list before saving rdi/r12/r15 and duplicates the return-true epilogue
// @0x142417560
bool FUN_142417560(Instances::fl::XMLList* self, const Multiname& prop_name)
{
    Scaleform::UInt32 ind;
    if (Scaleform::GFx::AS3::GetVectorInd(prop_name, ind))
        return ind < self->List.GetSize();
    const UPInt size = self->List.GetSize();
    for (UPInt i = 0; i < size; ++i)
    {
        Instances::fl::XML* x = self->List[i];
        if (x->GetKind() == Instances::fl::XML::kElement)
        {
            if (Sfr04XmlElementHasProperty(static_cast<Instances::fl::XMLElement*>(x), prop_name))
                return true;
        }
    }
    return false;
}

// The name of a trait's type: its own for a slot or const, its class's for the others (inlined in the exe).
static inline const AS3::Abc::Multiname& Sfr04TraitTypeName(const AS3::Abc::File& abc, const AS3::Abc::TraitInfo& ti)
{
    const AS3::Abc::TraitInfo::Type t = ti.GetType();
    const AS3::Abc::SInd ind = (t == AS3::Abc::TraitInfo::tSlot || t == AS3::Abc::TraitInfo::tConst)
        ? ti.Ind : abc.AS3_Classes.Info[ti.Ind]->inst_info.name_ind;
    return abc.Const_Pool.GetMultiname(ind);
}

// GlobalObjectScript: the instance traits of the script's classes run in this script
// MS2-FUNCTIONAL: a free function in place of the exe's member (self stands for a non-null this); the instance
// traits' script is read on its offset (protected)
// @0x1424187f0
void FUN_1424187f0(Instances::fl::GlobalObjectScript* self)
{
    __assume(self != NULL);
    const InstanceTraits::fl::GlobalObjectScript& tr = self->GetTraits();
    const AS3::Abc::ScriptInfo& script = tr.GetScript();
    VMAbcFile& file = tr.GetFile();
    const AS3::Abc::File& abc = file.GetAbcFile();
    for (UPInt i = 0; i < script.obj_traits.GetSize(); ++i)
    {
        const AS3::Abc::TraitInfo& ti = *abc.Traits.TraitInfos[script.obj_traits[(unsigned)i]];
        if (ti.GetType() != AS3::Abc::TraitInfo::tClass)
            continue;
        const AS3::Abc::Multiname& mn = Sfr04TraitTypeName(file.GetAbcFile(), ti);
        Instances::Namespace& ns = file.GetInternedNamespace(mn.Ind);
        ASString name = file.GetInternedString(mn.NameIndex);
        if (FUN_142514cd0(ns))
            continue;
        ClassTraits::Traits** pctr = FUN_142414ac0(&self->GetTraits().GetVM().ClassTraitsSet, name, ns);
        if (!pctr || !*pctr)
            continue;
        ClassTraits::UserDefined& ctr = static_cast<ClassTraits::UserDefined&>(**pctr);
        if (&ctr.GetFile() != &file)
            continue;
        InstanceTraits::Traits& itr = ctr.GetInstanceTraits();
        Instances::fl::GlobalObjectScript*& owner =
            *reinterpret_cast<Instances::fl::GlobalObjectScript**>((char*)&itr + 0xd0);
        if (owner == NULL)
        {
            self->AddRef();
            owner = self;
        }
    }
}

// ClassTraits::UserDefined: resolves the super class (initializing it first), makes the instance traits, then the
// class's static slots
// MS2-FUNCTIONAL: written from the exe on raw offsets; the exe inlines FUN_142417000
// @0x142418970
CheckResult ClassTraits::Traits::FUN_142418970()
{
    ClassTraits::Traits* self = this;
    ClassTraits::Traits* parent = FUN_142417000(*(VMAbcFile**)((char*)self + 0xc8), *(const char**)((char*)self + 0xd0));
    VMAbcFile* file = *(VMAbcFile**)((char*)self + 0xc8);
    const char* ci = *(const char**)((char*)self + 0xd0);
    VM& vm = self->GetVM();
    if (vm.IsException())
        return false;
    SPtr<const Scaleform::GFx::AS3::Traits>& pparent = *(SPtr<const Scaleform::GFx::AS3::Traits>*)((char*)self + 0x88);
    if (!pparent && parent)
        pparent = parent;
    if (*(void**)((char*)self + 0xc0))
        return true;
    InstanceTraits::Traits* parent_itr = NULL;
    if (parent)
    {
        if (!*(void**)((char*)parent + 0xc0))
        {
            parent->FUN_142418970();
            if (vm.IsException())
                return false;
        }
        parent_itr = *(InstanceTraits::Traits**)((char*)parent + 0xc0);
    }
    void* mem = vm.GetMemoryHeap()->Alloc(0xe0);
    InstanceTraits::Traits* itr = mem ? (static_cast<InstanceTraits::UserDefined*>(mem)->UserDefined::UserDefined(*file, parent_itr, *reinterpret_cast<const AS3::Abc::ClassInfo*>(ci)), static_cast<InstanceTraits::Traits*>(mem)) : NULL;
    self->SetInstanceTraits(Pickable<InstanceTraits::Traits>(itr));
    if (vm.IsException())
        return false;
    if (!self->AddSlots(*(const Scaleform::GFx::AS3::Abc::HasTraits*)(ci + 0x48), *file, self->GetFixedMemSize()))
        return false;
    if (*(const Scaleform::UInt8*)(ci + 0x20) & 4)
        AS3::Sfr21AddInterfaceSlots(self, *file, *reinterpret_cast<const AS3::Abc::ClassInfo*>(ci));
    return true;
}
// ClassTraits::UserDefined::RegisterSlots: the class's static slots (after the Classes::UserDefined object), then the
// interface slots of an interface class
// @0x14241e6b0
CheckResult ClassTraits::UserDefined::FUN_14241e6b0()
{
    ClassTraits::UserDefined* self = this;
    VMAbcFile& file = self->GetFile();
    const Scaleform::GFx::AS3::Abc::ClassInfo& ci = *reinterpret_cast<const Scaleform::GFx::AS3::Abc::ClassInfo*>(&self->GetClassInfo());
    const Scaleform::GFx::AS3::Abc::HasTraits& st = ci.stat_info;
    if (!self->AddSlots(st, file, self->GetFixedMemSize()))
        return false;
    const char* ci2 = (const char*)&self->GetClassInfo();
    if (*(const Scaleform::UInt8*)(ci2 + 0x20) & 4)
        AS3::Sfr21AddInterfaceSlots(self, self->GetFile(), *reinterpret_cast<const AS3::Abc::ClassInfo*>(ci2));
    return true;
}

// InstanceTraits::UserDefined::SetScript: the script object (+0xd0) that defines the class
// MS2-FUNCTIONAL: free function on the layout (the member is protected)
// @0x142423ae0
void FUN_142423ae0(InstanceTraits::UserDefined* self, Instances::fl::GlobalObjectScript* script)
{
    *reinterpret_cast<SPtr<Instances::fl::GlobalObjectScript>*>(reinterpret_cast<char*>(self) + 0xd0) = script;
}

// pops the top of the VM operand stack into v
// MS2-FUNCTIONAL: free function
// @0x142420770
void FUN_142420770(AS3::Object* self, Scaleform::GFx::AS3::Value& v)
{
    v.Pick(*reinterpret_cast<Scaleform::GFx::AS3::ValueStack*>(reinterpret_cast<char*>(&self->GetVM()) + 0x48));
}

// ---- objects made by traits: script classes, functions, global objects, catch scopes
// MS2-PIN: ??_7UserDefined@Classes@AS3@GFx@Scaleform@@6B@ 0x143144040   (C3: the vptr store of the InlineCtorTag ctor in FUN_142419e50; owner sfr_as3_01c)
extern const ClassInfo DAT_14313dd00;       // the "Catch" ClassInfo
// Traits::StoreScopeStack: the scope the traits' methods run in, from the VM scope stack above base
namespace Scaleform { namespace GFx { namespace AS3 { void Sfr31StoreScopeStack(UPInt self, UPInt start, UPInt* src); }}}

// the VM's current call frame (0xa8 bytes, 64 to a page)
static const char* FUN_CurrCallFrame(const VM* vm)
{
    const UPInt n = *(const UPInt*)((const char*)vm + 0x78) - 1;
    return (*(const char* const* const*)((const char*)vm + 0x90))[n >> 6] + (n & 0x3f) * 0xa8;
}
static UPInt FUN_CurrScopeBase(const VM* vm)
{
    if (*(const UPInt*)((const char*)vm + 0x78) == 0)
        return 0;
    return *(const UPInt*)(FUN_CurrCallFrame(vm) + 8);
}

// ClassTraits::UserDefined::MakeClass: the class object, its static slots and the scope its methods run in, then the
// static initializer
// The exe inlines the Classes::UserDefined constructor. The SDK's placement new is null-checked, so the class
// pointer comes from a ?: on Alloc(); the ctor's StoreScopeStack goes through the new class's own traits.
// @0x142419e50
SPtr<Class> ClassTraits::Traits::FUN_142419e50()
{
    ClassTraits::Traits* self = this;
    void* mem = self->Alloc();
    Class* cls = mem
        ? (static_cast<AS3::Classes::UserDefined*>(mem)->UserDefined::UserDefined(*self, AS3::Classes::UserDefined::InlineCtorTag()),
           (self->SetupSlotValues(*(Class*)mem)
                ? AS3::Sfr31StoreScopeStack(reinterpret_cast<UPInt>(&((Class*)mem)->GetTraits()), FUN_CurrScopeBase(&((Class*)mem)->GetTraits().GetVM()), reinterpret_cast<UPInt*>(&((Class*)mem)->GetTraits().GetVM().ScopeStack))
                : (void)0),
           (Class*)mem)
        : NULL;
    InstanceTraits::Traits& itr = self->GetInstanceTraits();
    SPtr<Class> result(cls);
    itr.SetConstructor(Pickable<Class>(cls));
    AS3::Sfr31StoreScopeStack(reinterpret_cast<UPInt>(static_cast<AS3::Traits*>(&itr)), FUN_CurrScopeBase(self->pVM), reinterpret_cast<UPInt*>(&self->pVM->ScopeStack));
    itr.Add2StoredScopeStack(AS3::Value(result.GetPtr()));
    static_cast<Scaleform::GFx::AS3::Classes::UserDefined*>(result.GetPtr())->CallStaticConstructor();
    return result;
}

// a Function of method method_ind of file named "method id: <ind>"
// @0x14241a7d0
Pickable<Instances::Function> Scaleform::GFx::AS3::Classes::Function::FUN_14241a7d0(VMAbcFile& file, Scaleform::UInt32 method_ind,
                                                               const ScopeStackType& ss, Instances::fl::GlobalObjectScript& gos) const
{
    InstanceTraits::Traits& t = FUN_14250a250(&file, gos, method_ind);
    return Pickable<Instances::Function>(new(t.Alloc()) Instances::Function(t, ss, AS3::Value::GetUndefined(),
        GetVM().GetStringManager().CreateConstString("method id: ") + Scaleform::AsString(method_ind).ToCStr()));
}

// The GlobalObjectScript constructor (0x1423ed7b0 in sfr_as3_01c), inlined into FUN_14241aa60.
__forceinline Instances::fl::GlobalObjectScript::GlobalObjectScript(InstanceTraits::fl::GlobalObjectScript& t,
                                                                    InlineCtorTag)
    : GlobalObject(t, GlobalObject::InlineCtorTag())
    , Initialized(false)
{
    t.SetupSlotValues(GetTraits().GetFile(), GetTraits().GetScript(), *this);
}

// InstanceTraits::fl::GlobalObjectScript: a new global object of the script
// @0x14241aa60
Pickable<Instances::fl::GlobalObjectScript> InstanceTraits::fl::GlobalObjectScript::FUN_14241aa60()
{
    return Pickable<Instances::fl::GlobalObjectScript>(
        new(Alloc()) Instances::fl::GlobalObjectScript(*this, Instances::fl::GlobalObjectScript::InlineCtorTag()));
}

namespace Scaleform { namespace GFx { namespace AS3 { namespace InstanceTraits { namespace fl {
    // Inline copy of the catch scope traits ctor (its out-of-line copy is in sfr_as3_01c); the exe inlines it below.
    __forceinline Catch::Catch(VMAbcFile& file, VM& vm, const Abc::MethodBodyInfo::ExceptionInfo& e)
        : CTraits(vm, AS3::fl::CatchCI)
    {
        TraitsType = Traits_Catch;
        UInt32 var_ind = e.var_name_ind;
        if (var_ind != 0)
            var_ind = UInt32(file.GetAbcFile().Const_Pool.ConstStr.GetSize()) - var_ind;
        ASString name = file.GetInternedString(var_ind);
        SlotInfo::BindingType bt = (SlotInfo::BindingType)2;
        if (e.exc_type_ind != 0)
            bt = GetBindingType(file, file.GetAbcFile().Const_Pool.GetMultiname(e.exc_type_ind));
        AddSlot(name, Pickable<const Instances::Namespace>(GetVM().PublicNamespace.GetPtr(), PickValue), bt,
                AbsoluteIndex(0));
        CalculateMemSize(0x38);
    }
}}}}}

// the traits of a catch scope: one slot named by the exception variable, typed by the exception type
namespace Scaleform { namespace GFx { namespace AS3 { namespace Classes { namespace fl {
    // @0x14241b920
    SPtr<InstanceTraits::fl::Catch> Catch::MakeInstanceTraits(VMAbcFile& file, const Abc::MethodBodyInfo::ExceptionInfo& e)
    {
        // the SDK's SF_HEAP_AUTO_NEW_ID(this, StatMV_VM)
        SPtr<InstanceTraits::fl::Catch> tr = MakePickable(
            new((Scaleform::MemAddressPtr)((void*)this), StatMV_VM, __FILE__, __LINE__) InstanceTraits::fl::Catch(file, GetVM(), e));
        return tr;
    }
}}}}}

// E4X: the "prefix:" of a namespace in an XML string, unless it is the default xml namespace
// @0x14241bc30 (out of line, as the exe calls it from ToXMLString)
__declspec(noinline) void FUN_14241bc30(AS3::Object* self, Scaleform::StringBuffer& buf, const Instances::Namespace& ns, bool skip_default)
{
    if (skip_default)
    {
        const Instances::Namespace* def = *(const Instances::Namespace* const*)(FUN_CurrCallFrame(&self->GetVM()) + 0x58);
        if (def && def->GetUri().GetNode() == ns.GetUri().GetNode() &&
            Scaleform::GFx::AS3::StrictEqual(def->GetPrefix(), ns.GetPrefix()))
            return;
    }
    if (ns.GetPrefix().IsString())
    {
        const Scaleform::GFx::ASStringNode* prefix = ns.GetPrefix().GetStringNode();
        const unsigned size = prefix->Size;
        if (size != 0)
        {
            buf.AppendString(prefix->pData, size);
            buf.AppendChar(':');
        }
    }
}

// E4X: the ":prefix" of a namespace in an XML string (attribute form), unless it is the default xml namespace
// @0x14241bcd0
void FUN_14241bcd0(AS3::Object* self, Scaleform::StringBuffer& buf, const Instances::Namespace& ns, bool skip_default)
{
    if (skip_default)
    {
        const Instances::Namespace* def = *(const Instances::Namespace* const*)(FUN_CurrCallFrame(&self->GetVM()) + 0x58);
        if (def && def->GetUri().GetNode() == ns.GetUri().GetNode() &&
            Scaleform::GFx::AS3::StrictEqual(def->GetPrefix(), ns.GetPrefix()))
            return;
    }
    if (ns.GetPrefix().IsString())
    {
        const Scaleform::GFx::ASStringNode* prefix = ns.GetPrefix().GetStringNode();
        if (prefix->Size != 0)
        {
            buf.AppendChar(':');
            buf.AppendString(prefix->pData, prefix->Size);
        }
    }
}

namespace Scaleform { namespace GFx { namespace AS3
{
namespace Instances { namespace fl
{
    // The exe inlines these NamespaceArray members (sfr_as3_03), LookupNamespace (0x142419d00) and the prefix
    // printers into ToXMLString; these are their bodies.
    static SF_INLINE bool NsaFind(const NamespaceArray& nsa, const Instances::Namespace& ns)
    {
        const UPInt size = nsa.Namespaces.GetSize();
        for (UPInt i = 0; i < size; ++i)
        {
            const Instances::Namespace& cur = *nsa.Namespaces[i];
            if (cur.GetUri() == ns.GetUri() && StrictEqual(cur.GetPrefix(), ns.GetPrefix()))
                return true;
        }
        return false;
    }

    static SF_INLINE bool NsaFindByPrefix(const NamespaceArray& nsa, const ASString& prefix)
    {
        bool found = false;
        const UPInt n = nsa.Namespaces.GetSize();
        for (UPInt i = 0; !found; ++i)
        {
            if (i >= n)
                return found;
            const Value& p = nsa.Namespaces[i]->GetPrefix();
            if (!p.IsNullOrUndefined())
                found = p.AsString() == prefix;
        }
        return found;
    }

    static SF_INLINE void NsaAdd(NamespaceArray& nsa, Instances::Namespace& ns, bool checkUnique = true)
    {
        if (checkUnique)
        {
            for (UPInt i = 0; i < nsa.Namespaces.GetSize(); ++i)
                if (*nsa.Namespaces[i] == ns)
                    return;
        }
        // Namespaces.PushBack(&ns), with the exe's out-of-line ResizeNoConstruct
        typedef SPtr<Instances::Namespace> NsPtr;
        typedef Scaleform::ArrayDataDH<NsPtr, Scaleform::AllocatorDH<NsPtr>, Scaleform::ArrayDefaultPolicy> NsPtrData;
        const NsPtr v(&ns);
        NsPtrData* d = reinterpret_cast<NsPtrData*>(&nsa.Namespaces);
        d->ResizeNoConstruct(d->pHeap, d->Size + 1);
        NsPtrData::AllocatorType::Construct(d->Data + d->Size - 1, v);
    }

    static SF_INLINE Pickable<Instances::Namespace> LookupNs(const Instances::Namespace& qName, const NamespaceArray* nsa)
    {
        Pickable<Instances::Namespace> result = qName.GetVM().MakeNamespace(Abc::NS_Public, qName.GetUri(), qName.GetPrefix());
        if (nsa)
        {
            const UPInt size = nsa->Namespaces.GetSize();
            for (UPInt i = 0; i < size; ++i)
            {
                const Instances::Namespace& other = *nsa->Namespaces[i];
                if (other.GetUri().GetNode() == result->GetUri().GetNode())
                {
                    result->SetPrefix(other.GetPrefix());
                    break;
                }
            }
        }
        return result;
    }

    static SF_INLINE void NsPrefix(AS3::Object* self, StringBuffer& buf, const Instances::Namespace& ns, bool checkDefaultNs)
    {
        if (checkDefaultNs)
        {
            const Instances::Namespace* def = *(const Instances::Namespace* const*)(FUN_CurrCallFrame(&self->GetVM()) + 0x58);
            if (def && def->GetUri().GetNode() == ns.GetUri().GetNode() && StrictEqual(def->GetPrefix(), ns.GetPrefix()))
                return;
        }
        if (ns.GetPrefix().IsString())
        {
            const ASStringNode* prefix = ns.GetPrefix().GetStringNode();
            if (prefix->Size != 0)
            {
                buf.AppendString(prefix->pData, prefix->Size);
                buf.AppendChar(':');
            }
        }
    }

    static SF_INLINE void NsSuffix(AS3::Object* self, StringBuffer& buf, const Instances::Namespace& ns, bool checkDefaultNs)
    {
        if (checkDefaultNs)
        {
            const Instances::Namespace* def = *(const Instances::Namespace* const*)(FUN_CurrCallFrame(&self->GetVM()) + 0x58);
            if (def && def->GetUri().GetNode() == ns.GetUri().GetNode() && StrictEqual(def->GetPrefix(), ns.GetPrefix()))
                return;
        }
        if (ns.GetPrefix().IsString())
        {
            const ASStringNode* prefix = ns.GetPrefix().GetStringNode();
            if (prefix->Size != 0)
            {
                buf.AppendChar(':');
                buf.AppendString(prefix->pData, prefix->Size);
            }
        }
    }

    // E4X 10.2.1: the start tag with this element's name, its attributes and the namespaces it has to declare (the
    // in-scope ones its ancestors did not declare and the ones its name and attributes use), then the children one
    // level deeper and the end tag; no children close the start tag.
    // the SDK body; the end tag's prefix stays a call to 0x14241bc30, as in the exe
    // @0x142425f30
    void XMLElement::ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                                 const NamespaceArray* usedNotDeclared)
    {
        VM& vm = GetVM();
        const Classes::fl::XML& cl = static_cast<const Classes::fl::XML&>(FUN_142508460(&GetTraits()));
        SInt32 prettyIndent = cl.prettyIndent;
        bool prettyPrinting = cl.prettyPrinting;

        if (prettyIndent < 0)
        {
            prettyPrinting = false;
            prettyIndent = 0;
        }

        if (prettyPrinting && ident > 0)
            AddIndent(buf, ident);

        NamespaceArray ancestorsAndDeclarations(vm.GetMemoryHeap());
        if (ancestorNamespaces != NULL)
        {
            const UPInt size = ancestorNamespaces->Namespaces.GetSize();
            for (UPInt i = 0; i < size; ++i)
                NsaAdd(ancestorsAndDeclarations, *ancestorNamespaces->Namespaces[i], true);
        }

        NamespaceArray namespaceDeclarations(vm.GetMemoryHeap());

        const UPInt sizei = Namespaces.Namespaces.GetSize();
        for (UPInt i = 0; i < sizei; ++i)
        {
            Instances::Namespace& cns = *Namespaces.Namespaces[i];
            const bool found = NsaFind(ancestorsAndDeclarations, cns);
            if (!found)
            {
                NsaAdd(namespaceDeclarations, cns, true);
                NsaAdd(ancestorsAndDeclarations, cns, false);
            }
        }

        if (usedNotDeclared)
        {
            const UPInt size = usedNotDeclared->Namespaces.GetSize();
            for (UPInt i = 0; i < size; ++i)
            {
                Instances::Namespace& cns = *usedNotDeclared->Namespaces[i];
                const bool found = NsaFind(ancestorsAndDeclarations, cns);
                if (!found)
                {
                    NsaAdd(namespaceDeclarations, cns, true);
                    NsaAdd(ancestorsAndDeclarations, cns, false);
                }
            }
        }

        NamespaceArray attrNamespaces(vm.GetMemoryHeap());
        SPtr<Instances::Namespace> nsCopy = LookupNs(*Ns, &ancestorsAndDeclarations);
        NsaAdd(attrNamespaces, *nsCopy);

        const UPInt sizeAttrs = Attrs.GetSize();
        for (UPInt i = 0; i < sizeAttrs; ++i)
        {
            const Instances::Namespace& nsAttr = Attrs[i]->GetNamespace();
            SPtr<Instances::Namespace> nsCopy = LookupNs(nsAttr, &ancestorsAndDeclarations);
            NsaAdd(attrNamespaces, *nsCopy);
        }

        const UPInt sizeAN = attrNamespaces.Namespaces.GetSize();
        for (UPInt i = 0; i < sizeAN; ++i)
        {
            Instances::Namespace& nsAttr = *attrNamespaces.Namespaces[i];
            const bool found = NsaFind(ancestorsAndDeclarations, nsAttr);

            if (!found && !nsAttr.GetUri().IsEmpty())
            {
                if (nsAttr.GetPrefix().IsUndefined())
                {
                    ASString newPrefix = vm.GetStringManager().CreateEmptyString();
                    bool matchFound = true;
                    while (matchFound)
                    {
                        matchFound = NsaFindByPrefix(ancestorsAndDeclarations, newPrefix);
                        if (matchFound)
                            newPrefix.Append("aaa", 3);
                    }
                    nsAttr.SetPrefix(Value(newPrefix));
                }

                NsaAdd(namespaceDeclarations, nsAttr);
                NsaAdd(ancestorsAndDeclarations, nsAttr);
            }
        }

        buf.AppendChar('<');
        NsPrefix(this, buf, *attrNamespaces.Namespaces[0], true);
        buf.AppendString(Text.ToCStr(), Text.GetSize());

        for (UPInt i = 0; i < Attrs.GetSize(); ++i)
        {
            buf.AppendChar(' ');

            XMLAttr* an = Attrs[i];
            SPtr<Instances::Namespace> ans = LookupNs(an->GetNamespace(), &ancestorsAndDeclarations);

            if (!ans->GetUri().IsEmpty() && ans->GetPrefix().IsUndefined())
            {
                ASString newPrefix = vm.GetStringManager().CreateEmptyString();
                bool prefixFound = true;
                const UPInt sizeAD = ancestorsAndDeclarations.Namespaces.GetSize();

                while (prefixFound)
                {
                    prefixFound = NsaFindByPrefix(ancestorsAndDeclarations, newPrefix);
                    if (prefixFound)
                        newPrefix.Append("aaa", 3);
                }

                ans->SetPrefix(Value(newPrefix));

                bool nsFound = false;
                for (UPInt j = 0; j < sizeAD; ++j)
                {
                    const Instances::Namespace& d = *ancestorsAndDeclarations.Namespaces[j];
                    if (d.GetPrefix().IsNullOrUndefined())
                        nsFound = (newPrefix.IsEmpty() || d.GetUri().GetNode() == ans->GetUri().GetNode());

                    if (d == *ans)
                    {
                        nsFound = true;
                        break;
                    }
                }

                if (!nsFound)
                    NsaAdd(namespaceDeclarations, *ans);
            }

            NsPrefix(this, buf, *ans, false);
            buf.AppendString(an->Text.ToCStr(), an->Text.GetSize());

            buf.AppendString("=\"");
            an->ToXMLString(buf, ident, &ancestorsAndDeclarations, NULL);
            buf.AppendChar('"');
        }

        for (UPInt i = 0; i < namespaceDeclarations.Namespaces.GetSize(); ++i)
        {
            const Instances::Namespace& cns = *namespaceDeclarations.Namespaces[i];

            buf.AppendString(" xmlns");

            SPtr<Instances::Namespace> ans = vm.MakeNamespace(Abc::NS_Public, cns.GetUri(), cns.GetPrefix());

            if (!ans->GetUri().IsEmpty() && ans->GetPrefix().IsUndefined())
            {
                ASString newPrefix = vm.GetStringManager().CreateEmptyString();
                bool prefixFound = true;

                while (prefixFound)
                {
                    prefixFound = NsaFindByPrefix(ancestorsAndDeclarations, newPrefix);
                    if (prefixFound)
                        newPrefix.Append("aaa", 3);
                }

                ans->SetPrefix(Value(newPrefix));
            }

            NsSuffix(this, buf, *ans, true);

            buf.AppendString("=\"");
            const ASString& uri = ans->GetUri();
            buf.AppendString(uri.ToCStr(), uri.GetSize());
            buf.AppendChar('"');
        }

        const UPInt xLength = Children.GetSize();
        if (xLength == 0)
        {
            buf.AppendString("/>");
            return;
        }

        buf.AppendChar('>');

        bool indentChildren = (xLength > 1 || (xLength == 1 && Children[0]->GetKind() != kText));
        SInt32 nextIndentLevel = (prettyPrinting && indentChildren) ? ident + prettyIndent : 0;

        for (UPInt i = 0; i < xLength; ++i)
        {
            if (prettyPrinting && indentChildren)
                buf.AppendChar('\n');
            Children[i]->ToXMLString(buf, nextIndentLevel, &ancestorsAndDeclarations, NULL);
        }

        if (prettyPrinting && indentChildren)
        {
            buf.AppendChar('\n');
            AddIndent(buf, ident);
        }

        buf.AppendString("</");
        FUN_14241bc30(this, buf, *attrNamespaces.Namespaces[0], true);
        buf.AppendString(Text.ToCStr(), Text.GetSize());
        buf.AppendChar('>');
    }
}} // namespace Instances::fl
}}} // namespace Scaleform::GFx::AS3

// XML::MakeXMLListInstance(target_obj, target_prop, target_ns): a new empty list whose target is target_prop of
// target_obj (an XML method in the SDK; not declared on the shared XML class).
// an XML member (the exe passes the result slot in rdx)
// @0x14241c810
Pickable<Instances::fl::XMLList> Instances::fl::XML::FUN_14241c810(AS3::Object& target_obj,
                                                                    const ASString& target_prop, Instances::Namespace& target_ns)
{
    Instances::fl::XML* self = this;
    InstanceTraits::fl::XMLList& itr = static_cast<InstanceTraits::fl::XMLList&>(
        self->GetVM().GetXMLSupport().GetClassTraitsXMLList()->GetInstanceTraits());
    return itr.MakeInstance(itr, target_obj, target_prop, target_ns);
}

// Instances::Function::StoreScopeStack (private): the closure's stored scope stack (+0x40) becomes the entries of ss
// from base on.
// A free function on the Function layout (the member is private in the shared header).
// @0x142424bd0
void FUN_142424bd0(Instances::Function* self, UPInt base, const Scaleform::ArrayDH<AS3::Value>& ss)
{
    Scaleform::ArrayDH<AS3::Value>& stored =
        *reinterpret_cast<Scaleform::ArrayDH<AS3::Value>*>(reinterpret_cast<char*>(self) + 0x40);
    stored.Resize(0);
    const UPInt size = ss.GetSize();
    for (UPInt i = base; i < size; ++i)
        stored.PushBack(ss[i]);
}

// InstanceTraits::fl::String::StringSubstring: the [start, start + length) part of str, clamped to the string; a
// negative length means "to the end".
// @0x1424252c0
ASString FUN_1424252c0(Scaleform::GFx::AS3::StringManager& sm, const ASString& str, Scaleform::SInt32 start, Scaleform::SInt32 length)
{
    if (length == 0)
        return sm.CreateEmptyString();
    if (start < 0)
        start = 0;
    const Scaleform::SInt32 len = (Scaleform::SInt32)str.GetLength();
    if (start >= len)
        return sm.CreateEmptyString();
    if (length < 0 || start + length > len)
        length = len - start;
    return ASString(str.SubstringNode(start, start + length));
}

// expat (sfr_gfx_12)
extern "C" int XML_Parse(void* parser, const char* s, int len, int isFinal);
extern "C" int XML_GetCurrentByteIndex(void* parser);
extern "C" int XML_GetErrorCode(void* parser);
extern "C" int XML_StopParser(void* parser, unsigned char resumable);   // XML_Bool

// ArrayDH<SPtr<XML> >::PushBack, out of line. The exe expands the PushBack and ResizeNoConstruct bodies here; cl
// leaves either one as a call when it is inline, so both are written out on the array's data.
// @0x14241e390
SF_NOINLINE void FUN_14241e390(Scaleform::ArrayDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> >* arr,
                   const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>* v)
{
    typedef Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> XMLPtr;
    typedef Scaleform::ArrayDataDH<XMLPtr, Scaleform::AllocatorDH<XMLPtr>, Scaleform::ArrayDefaultPolicy> XMLPtrData;
    XMLPtrData* d = reinterpret_cast<XMLPtrData*>(arr);
    const Scaleform::MemoryHeap* heap = d->pHeap;
    Scaleform::UPInt oldSize = d->Size;
    Scaleform::UPInt newSize = oldSize + 1;
    if (newSize < oldSize)
    {
        XMLPtrData::AllocatorType::DestructArray(d->Data + newSize, oldSize - newSize);
        if (newSize < (d->Policy.GetCapacity() >> 1))
            d->XMLPtrData::BaseType::Reserve(heap, newSize);
    }
    else if (newSize >= d->Policy.GetCapacity())
    {
        d->XMLPtrData::BaseType::Reserve(heap, newSize + (newSize >> 2));
    }
    d->Size = newSize;
    XMLPtrData::AllocatorType::Construct(d->Data + d->Size - 1, *v);
}

// ValueStack::PopBack: pops (and releases) the top n values
// @0x14241de40
void FUN_14241de40(Scaleform::GFx::AS3::ValueStack* stack, unsigned n)
{
    while (n)
    {
        --n;
        stack->GetTopPtr()->~Value();
        stack->Release(1);
    }
}

// SparseArray: appends the top n values of the operand stack, moving them off it
// @0x14241d980
void FUN_14241d980(Scaleform::GFx::AS3::SparseArray* sa, Scaleform::GFx::AS3::ValueStack* stack, Scaleform::UPInt n)
{
    using namespace Scaleform::GFx::AS3;
    if (n == 0)
        return;
    const Scaleform::UPInt len = sa->Length;
    const Scaleform::UPInt old = sa->ValueA.GetSize();
    if (len == old)
    {
        sa->ValueA.Resize(old + n);
        memcpy(&sa->ValueA[old], stack->GetTopPtr() - static_cast<Scaleform::UInt16>(n - 1), n * sizeof(Value));
        stack->Release(n);
        sa->Length = sa->ValueA.GetSize();
        return;
    }
    else
    {
        Scaleform::UPInt ind = sa->ValueHHighInd + n;
        for (Scaleform::UPInt i = 0; i < n; ++i, --ind)
        {
            sa->ValueH.Set(ind, *stack->GetTopPtr());
            stack->GetTopPtr()->~Value();
            stack->Release(1);
        }
        sa->ValueHHighInd += n;
    }
    sa->Length += n;
}

namespace Scaleform { namespace GFx { namespace AS3
{
    // @0x14241ce70
    void SparseArray::MoveHashLeft(UPInt first_ind, UPInt offset)
    {
        if (first_ind < offset)
            return;
        Value v;
        for (UPInt i = first_ind; i <= ValueHHighInd; ++i)
        {
            if (ValueH.Get(i, &v))
            {
                ValueH.Remove(i);
                ValueH.Set(i - offset, v);
            }
        }
    }

    // MS2-FUNCTIONAL: the exe inlines the trim and the AppendChild/PushBack choice differently
    // @0x142421d60
    void XMLParser::SetNodeKind(Kind k)
    {
        if (CurrKind == k)
            return;
        if (CurrKind == kText)
        {
            if (static_cast<const Classes::fl::XML&>(FUN_142508460(&ITr)).ignoreWhitespace)
                Text = ASString(Text.TruncateWhitespaceNode());
            if (Text.GetSize() != 0)
            {
                SPtr<Instances::fl::XML> t(Pickable<Instances::fl::XML>(ITr.MakeInstanceText(ITr, Text, CurrElement)));
                if (CurrElement && CurrElement->GetKind() == Instances::fl::XML::kElement)
                    CurrElement->AppendChild(t);
                else
                {
                    FUN_14241e390(&RootElements, &t);
                    CurrElement = t;
                }
                Text.Clear();
            }
        }
        CurrKind = k;
    }

    // @0x14241d6f0
    CheckResult XMLParser::Parse(const StringDataPtr& str, UPInt& pos, bool isList)
    {
        UPInt startPos = pos;

        bool rc = XML_Parse(Parser, str.ToCStr() + startPos, (int)(str.GetSize() - startPos), 1) == 1;
        bool shouldAdvancePos = true;

        if (!rc)
        {
            const int ecode = XML_GetErrorCode(Parser);
            VM& vm = ITr.GetVM();
            VM::ErrorID errorID = VM::ErrorID(0x442);
            Kind k = kNone;

            if (KindStack.GetSize())
                k = KindStack.Back();

            bool shouldThrow = true;
            switch (ecode)
            {
            case 0:
                // a processing instruction left open at the start: skip past its "?>"
                if (pos == startPos && CurrElement)
                {
                    if (CurrElement->GetKind() == Instances::fl::XML::kInstruction)
                    {
                        UPInt offset = 0;
                        UPInt len = str.GetSize() - startPos;
                        while (offset < len)
                        {
                            if (str.ToCStr()[offset] == '?' && ((offset + 1) < len))
                            {
                                if (str.ToCStr()[offset + 1] == '>')
                                {
                                    pos += offset + 2;
                                    return true;
                                }
                            }
                            offset++;
                        }
                    }
                }
                break;
            case 9:
                if (isList)
                {
                    shouldThrow = false;
                    rc = true;
                }
                else if (CurrElement.GetPtr() && k == kElement)
                {
                    errorID = VM::ErrorID(0x43d);
                }
                else
                {
                    errorID = VM::ErrorID(0x440);
                }
                break;
            case 1:
                errorID = VM::ErrorID(1000);
                break;
            case 7:
                if (k == kElement)
                    errorID = VM::ErrorID(0x43d);
                break;
            case 3:
                if (isList)
                {
                    shouldAdvancePos = false;
                    shouldThrow = false;
                }
                if (CurrElement && k == kElement)
                {
                    errorID = VM::ErrorID(0x43d);
                }
                else
                {
                    shouldThrow = false;
                }
                break;
            case 8:
                errorID = VM::ErrorID(0x450);
                break;
            case 5:
                errorID = VM::ErrorID(0x449);
                break;
            case 0x14:
                errorID = VM::ErrorID(0x443);
                break;
            case 0x23:
                shouldThrow = false;
                shouldAdvancePos = false;
                break;
            case 2:
                break;
            case 4:
                if (!CurrElement)
                {
                    shouldThrow = false;
                }
                break;
            default:
                break;
            }

            if (shouldThrow)
            {
                vm.ThrowTypeError(VM::Error(errorID, vm));
            }
        }

        if (shouldAdvancePos)
        {
            pos += XML_GetCurrentByteIndex(Parser);
        }

        SetNodeKind(kNone);
        return rc;
    }

    // InstanceTraits::fl::XML::MakeInstanceProcInstr (0x14241b6e0), inlined here
    static __forceinline Pickable<Instances::fl::XMLProcInstr> Sfr04MakeProcInstr(InstanceTraits::fl::XML& t, const ASString& name,
                                                                                  const ASString& data, Instances::fl::XML* parent)
    {
        return Pickable<Instances::fl::XMLProcInstr>(new(t.GetVM().GetMemoryHeap()) Instances::fl::XMLProcInstr(t, name, data, parent));
    }

    // @0x14241e160
    void XMLParser::ProcessingInstructionExpatCallback(void* userData, const char* target, const char* data)
    {
        XMLParser* p = static_cast<XMLParser*>(userData);
        p->SetNodeKind(kProcInstr);
        InstanceTraits::fl::XML& itr = p->ITr;
        StringManager& sm = itr.GetVM().GetStringManager();
        Pickable<Instances::fl::XMLProcInstr> pi = Sfr04MakeProcInstr(itr, sm.CreateString(target), sm.CreateString(data), p->CurrElement);
        SPtr<Instances::fl::XML> el(pi);
        if (p->CurrElement && p->CurrElement->GetKind() == Instances::fl::XML::kElement)
            p->CurrElement->AppendChild(el);
        else
        {
            // a top-level processing instruction ends the parse
            p->CurrElement = el;
            p->RootElements.PushBack(el);
            XML_StopParser(p->Parser, 1);
        }
    }

    // XMLParser::StartCDataSectionExpatCallback (not declared on the shared class)
    // MS2-FUNCTIONAL: free function
    // @0x142424020
    void FUN_142424020(void* userData)
    {
        static_cast<XMLParser*>(userData)->KindStack.PushBack(XMLParser::kCData);
    }

    // @0x142424090
    void XMLParser::StartDoctypeDeclExpatCallback(void* userData, const char* doctypeName, const char* sysid,
                                                  const char* pubid, int has_internal_subset)
    {
        static_cast<XMLParser*>(userData)->KindStack.PushBack(kDocType);
    }

    // eXMLPrefixNotBound / eXMLBadQName
    static const VM::ErrorID kXMLPrefixNotBound = (VM::ErrorID)1083;
    static const VM::ErrorID kXMLBadQName       = (VM::ErrorID)1084;

    // an "xmlns" or "xmlns:prefix" attribute
    static inline bool IsNsDeclAttr(UPInt len, const char* an)
    {
        return len >= 5 && an[0] == 'x' && an[1] == 'm' && an[2] == 'l' && an[3] == 'n' && an[4] == 's';
    }

    // MS2-FUNCTIONAL: the exe inlines MakeInstance (the Namespace / XMLAttr constructors) and the XML/XMLAttr
    // array growth
    // @0x142424100
    void XMLParser::StartElementExpatCallback(void* userData, const char* name, const char** atts)
    {
        XMLParser* p = static_cast<XMLParser*>(userData);
        p->SetNodeKind(kElement);
        p->KindStack.PushBack(kElement);
        InstanceTraits::fl::XML& itr = p->ITr;
        VM& vm = itr.GetVM();
        StringManager& sm = vm.GetStringManager();

        // the namespaces declared on this element
        ArrayDH<SPtr<Instances::Namespace> > namespaces(vm.GetMemoryHeap());
        InstanceTraits::fl::Namespace& itr_ns =
            static_cast<InstanceTraits::fl::Namespace&>(vm.GetClassTraitsNamespace().GetInstanceTraits());
        for (UPInt i = 0; atts[i]; i += 2)
        {
            const char* an = atts[i];
            const UPInt len = SFstrlen(an);
            if (len != 0 && an[0] == p->NsSeparator)
            {
                vm.ThrowTypeError(VM::Error(kXMLBadQName, vm, an));
                XML_StopParser(p->Parser, 0);
                return;
            }
            if (IsNsDeclAttr(len, an))
            {
                ASString ns_prefix = sm.CreateEmptyString();
                if (len > 5 && an[5] == p->NsSeparator)
                    ns_prefix = sm.CreateString(an + 6);
                const ASString ns_uri = sm.CreateString(atts[i + 1]);
                SPtr<Instances::Namespace> ns(itr_ns.MakeInstance(Abc::NS_Public, ns_uri, Value(ns_prefix)));
                // namespaces.PushBack(ns), with the exe's out-of-line ResizeNoConstruct
                typedef SPtr<Instances::Namespace> NsPtr;
                typedef Scaleform::ArrayDataDH<NsPtr, Scaleform::AllocatorDH<NsPtr>, Scaleform::ArrayDefaultPolicy>
                    NsPtrData;
                NsPtrData* d = reinterpret_cast<NsPtrData*>(&namespaces);
                d->ResizeNoConstruct(d->pHeap, d->Size + 1);
                NsPtrData::AllocatorType::Construct(d->Data + d->Size - 1, ns);
            }
        }

        const char* delim = SFstrchr(name, p->NsSeparator);
        if (delim == name)
        {
            vm.ThrowTypeError(VM::Error(kXMLBadQName, vm, name));
            XML_StopParser(p->Parser, 0);
            return;
        }
        ASString ns_prefix = sm.CreateEmptyString();
        ASString el_name = sm.CreateEmptyString();
        if (delim == NULL)
            el_name = sm.CreateString(name);
        else
        {
            ns_prefix = sm.CreateString(name, delim - name);
            el_name = sm.CreateString(delim + 1);
        }

        // the element's namespace: by prefix here, then in the parent; an unprefixed name takes the default xml
        // namespace (a local declaration of its uri first), else the public one
        Instances::Namespace* ns = NULL;
        for (UPInt i = 0; i < namespaces.GetSize(); ++i)
        {
            const Value& pr = namespaces[i]->GetPrefix();
            if (pr.IsString() && pr.AsString() == ns_prefix)
            {
                ns = namespaces[i];
                break;
            }
        }
        if (ns == NULL && p->CurrElement)
            ns = p->CurrElement->FindNamespaceByPrefix(ns_prefix, NULL);
        if (ns == NULL)
        {
            if (ns_prefix.GetSize() != 0)
            {
                vm.ThrowTypeError(VM::Error(kXMLPrefixNotBound, vm, Value(ns_prefix), name));
                XML_StopParser(p->Parser, 0);
                return;
            }
            ns = vm.GetDefXMLNamespace();
            if (ns == NULL)
                ns = &vm.GetPublicNamespace();
            else
            {
                bool found_local = false;
                for (UPInt i = 0; i < namespaces.GetSize(); ++i)
                {
                    if (namespaces[i]->GetUri() == ns->GetUri())
                    {
                        ns = namespaces[i];
                        found_local = true;
                        break;
                    }
                }
                if (!found_local && p->CurrElement)
                {
                    Instances::Namespace* local_ns = p->CurrElement->FindNamespaceByURI(ns->GetUri(), NULL);
                    if (local_ns)
                        ns = local_ns;
                }
            }
        }

        SPtr<Instances::fl::XMLElement> el = itr.MakeInstanceElement(itr, *ns, el_name, p->CurrElement.GetPtr());
        SPtr<Instances::fl::XML> ptr_el(el.GetPtr());
        if (p->CurrElement && p->CurrElement->GetKind() == Instances::fl::XML::kElement)
            p->CurrElement->AppendChild(ptr_el);
        else
            p->RootElements.PushBack(ptr_el);

        for (UPInt i = 0; i < namespaces.GetSize(); ++i)
        {
            if (namespaces[i]->GetPrefix().IsString())
                el->Namespaces.Namespaces.PushBack(namespaces[i]);
        }

        // the attributes (unprefixed ones are in the public namespace)
        for (UPInt i = 0; atts[i]; i += 2)
        {
            const char* an = atts[i];
            if (IsNsDeclAttr(SFstrlen(an), an))
                continue;
            const char* adelim = SFstrchr(an, p->NsSeparator);
            const ASString value = sm.CreateString(atts[i + 1]);
            ASString aname = sm.CreateEmptyString();
            const Instances::Namespace* ans;
            if (adelim == NULL)
            {
                aname = sm.CreateString(an);
                ans = &vm.GetPublicNamespace();
            }
            else
            {
                const ASString apre = sm.CreateString(an, adelim - an);
                aname = sm.CreateString(adelim + 1);
                ans = el->FindNamespaceByPrefix(apre, NULL);
                if (ans == NULL)
                    ans = &vm.GetPublicNamespace();
            }
            SPtr<Instances::fl::XMLAttr> attr = itr.MakeInstanceAttr(itr, *ans, aname, value, el.GetPtr());
            el->Attrs.PushBack(attr);
        }

        p->CurrElement = ptr_el;
    }
}}} // namespace Scaleform::GFx::AS3

// The builtin ClassInfo registry of GlobalObjectCPP (+0x38): a GH hash keyed by the borrowed class name, as declared
// in sfr_as3_01c.
typedef Scaleform::Hash<Instances::fl::ConstStringKey, const ClassInfo*, Instances::fl::ConstStringHashFn,
                        Scaleform::AllocatorGH<Instances::fl::ConstStringKey, 328> > CIRegistrationHashType;

// GlobalObjectCPP::RegisterClassInfoTable: registers a null-terminated table of builtin classes by name
// @0x14241e540
void FUN_14241e540(Instances::fl::GlobalObjectCPP* self, const ClassInfo* table[])
{
    for (unsigned i = 0; table[i]; ++i)
    {
        Instances::fl::ConstStringKey key = { table[i]->GetName() };
        self->CIRegistrationHash.Add(key, table[i]);
    }
}

// pushes a copy of v onto the VM's operand stack (pCurrent at +8 of the stack)
// MS2-FUNCTIONAL: ValueStack::PushBack is not modeled in the shared header; the stack top is reached by offset
// @0x14241e4f0
void FUN_14241e4f0(AS3::Object* self, const AS3::Value& v)
{
    VM& vm = self->GetVM();
    AS3::Value*& top = *reinterpret_cast<AS3::Value**>(&vm.OpStack[1]);
    ++top;
    new (top) AS3::Value(v);
}

namespace Scaleform { namespace GFx { namespace AS3
{
namespace Classes
{
    // the prototype is an empty function
    // @0x14241c500
    Pickable<AS3::Object> Function::MakePrototype() const
    {
        InstanceTraits::Traits& itr = GetClassTraits().GetInstanceTraits();
        void* mem = itr.Alloc();
        return Pickable<AS3::Object>(mem ? new (mem) Instances::FunctionBase(itr) : NULL);
    }

    // Runs the instance initializer of the class on _this.
    // @0x14241dea0
    void UserDefined::PostInit(const Value& _this, unsigned argc, const Value* argv) const
    {
        const InstanceTraits::Traits& itr = GetClassTraits().GetInstanceTraits();
        const SInt32 mbi_ind =
            GetFile().GetAbcFile().Methods.Info[GetClassInfo().inst_info.method_info_ind]->MethodBodyInfoInd;
        const ASString name = GetTraits().GetName();
        GetVM().AddFrame(_this, GetFile(), mbi_ind, _this, argc, argv, true, itr.InitScope, itr,
                         name + " instance constructor");
    }
} // namespace Classes
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3
{
namespace InstanceTraits
{
    // a closure object made by these traits (its body comes from them, its memory from t)
    // @0x14241bf50
    void Function::MakeObject(Value& result, Traits& t)
    {
        void* mem = t.Alloc();
        result.Pick(mem ? new (mem) Instances::FunctionBase(*this) : NULL);
    }
} // namespace InstanceTraits

    // "length" of the function kinds: the parameter count of the method (a native thunk: its maximum argument count,
    // its minimum one when unbounded).
    // MS2-FUNCTIONAL: the kind's payload is read by offset (the value union is not public)
    // @0x142429360
    void FUN_142429360(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc,
                       const Value* argv)
    {
        SF_UNUSED4(ti, vm, argc, argv);
        const ThunkInfo& thunk = **reinterpret_cast<const ThunkInfo* const*>(reinterpret_cast<const char*>(&_this) + 0x10);
        unsigned n = thunk.GetMaxArgNum();
        if (n == 0x3ff)
            n = thunk.GetMinArgNum();
        result.SetUInt32(n);
    }

    // MethodInd::lengthGet: the parameter count of the ABC method (a closure: through its object's traits)
    // @0x1424292c0
    void FUN_1424292c0(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc,
                       const Value* argv)
    {
        SF_UNUSED4(ti, vm, argc, argv);
        const SInt32 ind = _this.GetMethodInd();
        const Traits& tr = _this.GetKind() == Value::kMethodInd ? _this.GetTraits() : _this.GetClosure()->GetTraits();

        if (tr.GetFilePtr() == NULL)
            return;

        const VMAbcFile& file = *tr.GetFilePtr();
        const UPInt count = file.GetAbcFile().Methods.Info[ind]->ParamTypes.GetSize();

        result.SetUInt32(static_cast<UInt32>(count));
    }

    // VTableInd::lengthGet: the parameter count of the ABC method in the vtable slot
    // @0x1424293d0
    void FUN_1424293d0(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc,
                       const Value* argv)
    {
        SF_UNUSED4(ti, vm, argc, argv);
        const SInt32 vt_ind = _this.GetVTableInd();
        const Traits& tr = _this.GetKind() == Value::kVTableInd ? _this.GetTraits() : _this.GetClosure()->GetTraits();
        const Value& real_value = tr.GetVT().VTMethods[(UPInt)(UInt32)vt_ind];
        const SInt32 ind = real_value.GetMethodInd();

        if (tr.GetFilePtr() == NULL)
            return;

        const VMAbcFile& file = *tr.GetFilePtr();
        const UPInt count = file.GetAbcFile().Methods.Info[ind]->ParamTypes.GetSize();

        result.SetUInt32(static_cast<UInt32>(count));
    }

namespace Instances { namespace fl
{
    // prototypeGet returning the list
    // @0x142429dd0
    SPtr<XMLList> XML::FUN_142429dd0()
    {
        XML* self = this;
        SPtr<XMLList> result;
        self->prototypeGet(result);
        return result;
    }
}} // namespace Instances::fl
}}} // namespace Scaleform::GFx::AS3

extern const Scaleform::GFx::AS3::ThunkInfo DAT_143a2aab0[3];   // the Function prototype methods added to its traits

namespace Scaleform { namespace GFx { namespace AS3
{
    // the "prototype" slot (the C++ member at +0x38) and the three Function methods of a function kind's traits
    // @0x14241e5d0
    void FUN_14241e5d0(Traits* tr)
    {
        tr->AddSlotCPP(tr->GetVM().GetStringManager().CreateConstString("prototype"),
                       Pickable<const Instances::Namespace>(tr->GetVM().PublicNamespace.GetPtr(), PickValue),
                       tr->GetVM().TraitsObject.GetPtr(), SlotInfo::BT_ObjectCpp, AbsoluteIndex(0x38), false);
        for (unsigned i = 0; i < 3; ++i)
            tr->Add2VT(AS3::fl::FunctionCI, DAT_143a2aab0[i]);
    }

    // a class's prototype as a plain new object, then filled by the class
    // @0x142423d00
    void FUN_142423d00(Class* cl)
    {
        SPtr<AS3::Object>& proto = *reinterpret_cast<SPtr<AS3::Object>*>(reinterpret_cast<char*>(cl) + 0x48);
        proto = Pickable<AS3::Object>(cl->GetVM().MakeObject());
        cl->InitPrototype(cl->GetPrototype());
    }

    // removes the first element; the rest move down by one
    // @0x142423ef0
    void SparseArray::ShiftLeft()
    {
        SparseArray* sa = this;
        if (sa->Length == 0)
            return;
        if (sa->ValueA.GetSize() > 0)
        {
            // The exe (0x142423ef0) inlines RemoveAt: release data[0], memmove the rest down, --Size. Resizing after
            // the memmove would destruct the duplicated tail Value and over-release the last element.
            sa->ValueA.RemoveAt(0);
        }
        else if (sa->ValueHLowInd == 0)
        {
            sa->ValueH.Remove(sa->ValueHLowInd);
            if (sa->ValueH.GetSize() > 0)
                sa->ValueHLowInd = sa->ValueH.Begin()->First;
        }
        if (sa->ValueH.GetSize() > 0)
        {
            sa->MoveHashLeft(sa->ValueHLowInd, 1);
            --sa->ValueHLowInd;
            --sa->ValueHHighInd;
            --sa->Length;
            return;
        }
        --sa->Length;
        sa->ValueHHighInd = 0;
        sa->ValueHLowInd  = 0;
    }
}}}

namespace Scaleform { namespace GFx { namespace AS3
{
namespace Classes
{
    // @0x142417c30
    void Function::InitPrototype(AS3::Object& obj) const
    {
        if (GetParentClass())
            GetParentClass()->InitPrototype(obj);
        fl::AddDynamicFuncs(obj, DAT_14313e4e0);
        AddConstructor(obj);
    }
}
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform {
template <class F, class S> struct Pair { F First; S Second; };
namespace GFx { namespace AS3 {
namespace Impl { template <class A, class B, class C> struct Triple { A First; B Second; C Third; }; }
}}} // namespace Scaleform::GFx::AS3

// The out-of-line ArrayDataBase::Reserve instances of this range.
template void Scaleform::ArrayDataBase<Scaleform::UInt32, Scaleform::AllocatorDH<Scaleform::UInt32, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Pair<const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, Scaleform::AllocatorDH<Scaleform::Pair<const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<double, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<double, const Scaleform::GFx::AS3::Value*, Scaleform::UInt32>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLAttr>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value, Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::XMLParser::Kind, Scaleform::AllocatorDH_POD<Scaleform::GFx::AS3::XMLParser::Kind, 2>, Scaleform::ArrayDefaultPolicy>::Reserve(const void*, Scaleform::UPInt);


// The out-of-line array resize and insert/remove instances of this range.
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>, 2>, Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(const void*, Scaleform::UPInt);
template void Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::UPInt);
// declared noinline at the top of the file, so this is the SDK body as a specialization
template<> SF_NOINLINE void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::Namespace>, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveAt(Scaleform::UPInt index)
{
    if (Data.Size == 1)
    {
        Clear();
    }
    else
    {
        AllocatorType::Destruct(Data.Data + index);
        AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + 1, Data.Size - 1 - index);
        --Data.Size;
    }
}
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveAt(Scaleform::UPInt);
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>, 2>, Scaleform::ArrayDefaultPolicy> >::InsertAt(Scaleform::UPInt, const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>&);
// declared noinline at the top of the file, so this is the SDK body as a specialization
template<> SF_NOINLINE void Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value, Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value, 2>, Scaleform::ArrayDefaultPolicy> >::RemoveMultipleAt(Scaleform::UPInt index, Scaleform::UPInt num)
{
    if (Data.Size == num)
    {
        Clear();
    }
    else
    {
        AllocatorType::DestructArray(Data.Data + index, num);
        AllocatorType::CopyArrayForward(Data.Data + index, Data.Data + index + num, Data.Size - num - index);
        Data.Size -= num;
    }
}

// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$07V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@JJ@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424133c0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413510
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$09VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413530
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BA@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413550
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BB@$$CBVValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424136c0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BC@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424137a0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0BD@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413910
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0L@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413a30
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0M@V?$SPtr@VArray@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413a50
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0N@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413bc0
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0O@JAEBVValue@456@J@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413d70
// MS2-PIN: ?Func@?$ThunkFunc2@VArray@fl@Instances@AS3@GFx@Scaleform@@$0P@_NAEBVValue@456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142413f20
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BL@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414040
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BM@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414060
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BN@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414080
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140a0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0BP@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140c0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CA@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424140e0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CB@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414100
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CC@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414120
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CD@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414140
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CE@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414160
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414180
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CG@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141a0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CH@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141c0
// MS2-PIN: ?Func@?$ThunkFunc2@VDate@fl@Instances@AS3@GFx@Scaleform@@$0CI@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424141e0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$05VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414200
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$07VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414220
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$08VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414240
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0L@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414260
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0M@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414280
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142a0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142c0
// MS2-PIN: ?Func@?$ThunkFunc2@VGlobalObjectCPP@fl@Instances@AS3@GFx@Scaleform@@$0BG@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424142e0
// MS2-PIN: ?Func@?$ThunkFunc2@VString@fl@Classes@AS3@GFx@Scaleform@@$00VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414300
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$03VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414320
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BA@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414340
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BE@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414360
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414440
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BJ@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414520
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0BO@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414540
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0CB@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414560
// MS2-PIN: ?Func@?$ThunkFunc2@VXML@fl@Instances@AS3@GFx@Scaleform@@$0P@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424146d0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$05VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424146f0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BF@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414710
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BM@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414730
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BN@VValue@456@AEBV7456@AEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414810
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0BP@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x1424148f0
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0CE@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@456@AEBVValue@456@AEBV8456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414910
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0O@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414a80
// MS2-PIN: ?Func@?$ThunkFunc2@VXMLList@fl@Instances@AS3@GFx@Scaleform@@$0P@VValue@456@IPEBV7456@@AS3@GFx@Scaleform@@SAXAEBUThunkInfo@234@AEAVVM@234@AEBVValue@234@AEAV7234@IPEBV7234@@Z 0x142414aa0
// MS2-PIN: ?SetBool@Value@AS3@GFx@Scaleform@@QEAAX_N@Z 0x142421710
// MS2-PIN: ?SetNull@Value@AS3@GFx@Scaleform@@QEAAXXZ 0x142421ed0
// MS2-PIN: ?SetSInt32@Value@AS3@GFx@Scaleform@@QEAAXJ@Z 0x142423a90
// MS2-PIN: ?Reserve@?$ArrayDataBase@KU?$AllocatorDH@K$01@Scaleform@@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14241f560
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@U?$AllocatorDH@U?$Pair@PEBVValue@AS3@GFx@Scaleform@@K@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x14241f600
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@K@Impl@AS3@GFx@Scaleform@@U?$AllocatorDH@U?$Triple@VASString@GFx@Scaleform@@PEBVValue@AS3@23@K@Impl@AS3@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14241f6a0
// MS2-PIN: ?Reserve@?$ArrayDataBase@U?$Triple@NPEBVValue@AS3@GFx@Scaleform@@K@Impl@AS3@GFx@Scaleform@@U?$AllocatorDH@U?$Triple@NPEBVValue@AS3@GFx@Scaleform@@K@Impl@AS3@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14241f740
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorDH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f7e0
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f880
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VXMLAttr@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXMLAttr@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f920
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorDH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241f9c0
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241fa60
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241fb00
// MS2-PIN: ?Reserve@?$ArrayDataBase@VValue@AS3@GFx@Scaleform@@U?$AllocatorLH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241fc40
// MS2-PIN: ?Reserve@?$ArrayDataBase@W4Kind@XMLParser@AS3@GFx@Scaleform@@U?$AllocatorDH_POD@W4Kind@XMLParser@AS3@GFx@Scaleform@@$01@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x14241fce0
// MS2-PIN: ?IsCallable@Value@AS3@GFx@Scaleform@@QEBA_NXZ 0x142419940
// MS2-PIN: ?IsXMLObject@AS3@GFx@Scaleform@@YA_NAEBVValue@123@@Z 0x142419cd0
// MS2-PIN: ?IsXMLListObject@AS3@GFx@Scaleform@@YA_NAEBVValue@123@@Z 0x142419ca0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorDH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241ff20
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x14241ffc0
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142420100
// MS2-FUNCTIONAL ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z: the exe calls DestructArray out of line; ours inlines it
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142420060
// MS2-FUNCTIONAL ?Resize@?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z: the exe calls ResizeNoConstruct out of line; ours inlines it
// MS2-PIN: ?Resize@?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14241fd80
// MS2-FUNCTIONAL ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z: the exe calls ResizeNoConstruct out of line for Clear; ours inlines it
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespace@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14241e8b0
// MS2-FUNCTIONAL ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z: the exe calls ResizeNoConstruct out of line for Clear; ours inlines it
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14241e940
// MS2-FUNCTIONAL ?InsertAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_KAEBV?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@2@@Z: the exe calls ResizeNoConstruct out of line; ours inlines it
// MS2-PIN: ?InsertAt@?$ArrayBase@U?$ArrayData@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_KAEBV?$SPtr@VXML@fl@Instances@AS3@GFx@Scaleform@@@AS3@GFx@2@@Z 0x1424190e0
// MS2-PIN: ?RemoveMultipleAt@?$ArrayBase@U?$ArrayDataDH@VValue@AS3@GFx@Scaleform@@U?$AllocatorDH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@@Scaleform@@QEAAX_K0@Z 0x14241ebb0
// MS2-PIN: ?setRawCapacity@?$HashSetBase@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@U67345@U?$AllocatorLH@PEAVNamespace@Instances@AS3@GFx@Scaleform@@$01@5@V?$HashsetEntry@PEAVNamespace@Instances@AS3@GFx@Scaleform@@UNamespaceHashFunc@NamespaceInstanceFactory@345@@5@@Scaleform@@AEAAXPEAX_K@Z 0x14242a240
// MS2-PIN: ??_7?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@6B@ 0x14313f368
// MS2-PIN: ??_7GASRefCountBase@AS3@GFx@Scaleform@@6B@ 0x14313f398
// MS2-PIN: ??_7Namespace@Instances@AS3@GFx@Scaleform@@6B@ 0x143140070
// MS2-PIN: ??_7CallBack@XMLElement@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142f90
// MS2-PIN: ??_7CallBack@XMLList@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431436c0
// MS2-PIN: ??_7EmptyCallBack@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439b8
// MS2-PIN: ??_7ChildGet@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439e8
// MS2-PIN: ??_7AttrGet@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431439f8
// MS2-PIN: ??_7ListGet@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143ae0
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PIN: ??_7Catch@fl@InstanceTraits@AS3@GFx@Scaleform@@6B@ 0x1431405f0
// MS2-PIN: ??_7ThunkFunction@Instances@AS3@GFx@Scaleform@@6B@ 0x14313fa78
// MS2-PIN: ??_7CheckTypeTF@Instances@AS3@GFx@Scaleform@@6B@ 0x14313fb38
// MS2-PIN: ??_7FunctionBase@Instances@AS3@GFx@Scaleform@@6B@ 0x14313f8f8
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@UConstStringKey@fl@Instances@AS3@GFx@Scaleform@@PEBUClassInfo@456@VConstStringHashFn@23456@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@UConstStringKey@fl@Instances@AS3@GFx@Scaleform@@$0BEI@@2@V?$HashsetCachedNodeEntry@U?$HashNode@UConstStringKey@fl@Instances@AS3@GFx@Scaleform@@PEBUClassInfo@456@VConstStringHashFn@23456@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x14242a3a0

// ---- The full-exe out-of-line members of this range: property accessors, empty MakeObject/prototypeSet bodies and
// the small E4X/QName virtuals. ----

namespace Scaleform { namespace GFx { namespace AS3 {

// The global escapeMultiByte() helper (sfr_as3_12).
void escapeMultiByteInternal(VM& vm, ASString& result, const ASString& value);

// The GC-object type name of a non-AS3 object.
// @0x142414cb0
template <>
const char* RefCountBaseGC<StatMV_ActionScript_Mem>::GetAS3ObjectType() const
{
    return "<unknown>";
}

namespace Instances
{
    // @0x142415eb0
    UInt32 FunctionBase::GetMaxParamNum() const
    {
        return 0;
    }
}

namespace InstanceTraits
{
    // @0x142415ad0
    unsigned Function::GetFixedMemSize() const
    {
        return sizeof(Instances::Function);
    }

    // @0x14241c030
    void MethodInd::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c200
    void Thunk::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c210
    void ThunkFunction::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c220
    void VTableInd::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

namespace fl
{
    // The primitive types have no object form: Value carries them.
    // @0x14241be20
    void Boolean::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c040
    void Namespace::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c050
    void Number::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c1f0
    void String::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c330
    void int_::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }

    // @0x14241c340
    void uint::MakeObject(Value& result, Traits& t)
    {
        SF_UNUSED2(result, t);
    }
}
} // namespace InstanceTraits

namespace Classes { namespace fl
{
    // @0x142428100
    void XML::defaultSettings(SPtr<Instances::fl::Object>& result)
    {
        AS3defaultSettings(result);
    }

    // @0x142428880
    void String::fromCharCode(Value& result, unsigned argc, const Value* argv)
    {
        AS3fromCharCode(result, argc, argv);
    }
}} // namespace Classes::fl

namespace Instances { namespace fl
{
    // The index of this element in its parent's children.
    // MS2-FUNCTIONAL 0x1424152b0: same loop and results as the exe; the exe reuses the zero index register for the empty-parent false return where the compiler emits a separate store, and the exe has no .pdata size for this leaf
    // @0x1424152b0
    CheckResult XMLElement::GetChildIndex(UPInt& ind) const
    {
        const XMLElement* parent = static_cast<const XMLElement*>(Parent.GetPtr());
        if (parent == NULL)
            return false;
        const UPInt size = parent->Children.GetSize();
        for (ind = 0; ind < size; ++ind)
        {
            if (parent->Children[ind].GetPtr() == this)
                return true;
        }
        return false;
    }

    // @0x142415700
    Instances::Namespace& XML::GetCurrNamespace() const
    {
        return GetVM().GetPublicNamespace();
    }

    // @0x142415fd0
    const Instances::Namespace& XML::GetNamespace() const
    {
        return GetVM().GetPublicNamespace();
    }

    // @0x142415a40
    void XMLList::GetDynamicProperty(AbsoluteIndex ind, Value& value)
    {
        value.Assign(List[(UInt32)ind.Get()]);
    }

    // A QName enumerates two properties: uri and localName.
    // @0x142416180
    GlobalSlotIndex QName::GetNextDynPropIndex(GlobalSlotIndex ind) const
    {
        if (ind.Get() <= 1)
            return GlobalSlotIndex(ind.Get() + 1);
        return GlobalSlotIndex(0);
    }

    // @0x142416630
    void QName::GetNextPropertyValue(Value& value, GlobalSlotIndex ind)
    {
        switch (ind.Get())
        {
        case 1:
            if (Ns)
                value.Assign(Ns->GetUri());
            else
                value.SetNull();
            break;
        case 2:
            value.Assign(LocalName);
            break;
        }
    }

    // A plain XML node enumerates one property: itself.
    // @0x1424161a0
    GlobalSlotIndex XML::GetNextDynPropIndex(GlobalSlotIndex ind) const
    {
        if (ind.Get() != 0)
            return GlobalSlotIndex(0);
        return GlobalSlotIndex(1);
    }

    // @0x1424161c0
    GlobalSlotIndex XMLList::GetNextDynPropIndex(GlobalSlotIndex ind) const
    {
        if (ind.Get() < (UInt32)List.GetSize())
            return GlobalSlotIndex(ind.Get() + 1);
        return GlobalSlotIndex(0);
    }

    // @0x142425a20
    void XML::ToString(StringBuffer& buf, SInt32 ident)
    {
        SF_UNUSED(ident);
        buf.AppendString(Text.ToCStr(), Text.GetSize());
    }

    // @0x142425a40
    void XMLAttr::ToString(StringBuffer& buf, SInt32 ident)
    {
        SF_UNUSED(ident);
        buf.AppendString(Data.ToCStr(), Data.GetSize());
    }

    // @0x142425d00
    void XML::ToXMLString(StringBuffer& buf, SInt32 ident, const NamespaceArray* ancestorNamespaces,
                          const NamespaceArray* usedNotDeclared)
    {
        SF_UNUSED3(ident, ancestorNamespaces, usedNotDeclared);
        buf.AppendString(Text.ToCStr(), Text.GetSize());
    }

    // @0x142429f90
    void XML::prototypeSet(const Value& result, const Value& v)
    {
        SF_UNUSED2(result, v);
    }

    // @0x142429fa0
    void XMLList::prototypeSet(const Value& result, const Value& v)
    {
        SF_UNUSED2(result, v);
    }

    // ---- GlobalObjectCPP ----

    // @0x142427bd0
    void GlobalObjectCPP::clearInterval(const Value& result, UInt32 id)
    {
        SF_UNUSED(result);
        static_cast<ASVM&>(GetVM()).GetMovieImpl()->ClearIntervalTimer(id);
    }

    // @0x142427bf0
    void GlobalObjectCPP::clearTimeout(const Value& result, UInt32 id)
    {
        SF_UNUSED(result);
        static_cast<ASVM&>(GetVM()).GetMovieImpl()->ClearIntervalTimer(id);
    }

    // @0x142428110
    void GlobalObjectCPP::describeType(SPtr<Instances::fl::XML>& result, const Value& v)
    {
        GetVM().GetXMLSupport().DescribeType(GetVM(), result, v);
    }

    // @0x142428460
    void GlobalObjectCPP::escapeMultiByte(ASString& result, const ASString& v)
    {
        escapeMultiByteInternal(GetVM(), result, v);
    }

    // @0x142428f30
    void GlobalObjectCPP::isFinite(bool& result, Value::Number v)
    {
        result = !NumberUtil::IsNaNOrInfinity(v);
    }

    // @0x142428f60
    void GlobalObjectCPP::isNaN(bool& result, Value::Number v)
    {
        result = NumberUtil::IsNaN(v);
    }

    // @0x142429dc0
    void GlobalObjectCPP::print(Value& result, unsigned argc, const Value* argv)
    {
        trace(result, argc, argv);
    }

    // ---- RegExp, Error, Array ----

    // The OptionFlags bits are the pcre options: caseless 1, multiline 2, dotall 4, extended 8.
    // @0x142428130
    void RegExp::dotallGet(bool& result)
    {
        result = ((static_cast<UInt32>(OptionFlags) >> 2) & 1) != 0;
    }

    // @0x142428490
    void RegExp::extendedGet(bool& result)
    {
        result = ((static_cast<UInt32>(OptionFlags) >> 3) & 1) != 0;
    }

    // @0x142428da0
    void RegExp::globalGet(bool& result)
    {
        result = IsGlobal;
    }

    // @0x142428e00
    void RegExp::ignoreCaseGet(bool& result)
    {
        result = (OptionFlags & 1) != 0;
    }

    // @0x1424291b0
    void RegExp::lastIndexGet(SInt32& result)
    {
        result = LastIndex;
    }

    // @0x1424291c0
    void RegExp::lastIndexSet(const Value& result, SInt32 v)
    {
        SF_UNUSED(result);
        LastIndex = v;
    }

    // @0x142429910
    void RegExp::multilineGet(bool& result)
    {
        result = ((static_cast<UInt32>(OptionFlags) >> 1) & 1) != 0;
    }

    // @0x1424282e0
    void Error::errorIDGet(SInt32& result)
    {
        result = ID;
    }

    // @0x142429480
    void Array::lengthSet(const Value& result, UInt32 v)
    {
        SF_UNUSED(result);
        SA.Resize(v);
    }

    // ---- Date properties: the local getters are the AS3get* methods; the setters change one field, the UTC ones
    // with no time zone adjustment. ----

    // @0x142427c30
    void Date::dateGet(Value::Number& result) { AS3getDate(result); }
    // @0x142427cd0
    void Date::dayGet(Value::Number& result) { AS3getDay(result); }
    // @0x142427ce0
    void Date::dayUTCGet(Value::Number& result) { AS3getUTCDay(result); }
    // @0x142428dc0
    void Date::hoursGet(Value::Number& result) { AS3getHours(result); }
    // @0x142428de0
    void Date::hoursUTCGet(Value::Number& result) { AS3getUTCHours(result); }
    // @0x142429630
    void Date::millisecondsGet(Value::Number& result) { AS3getMilliseconds(result); }
    // @0x142429820
    void Date::minutesGet(Value::Number& result) { AS3getMinutes(result); }
    // @0x142429850
    void Date::minutesUTCGet(Value::Number& result) { AS3getUTCMinutes(result); }
    // @0x142429870
    void Date::monthGet(Value::Number& result) { AS3getMonth(result); }
    // @0x14242a070
    void Date::secondsGet(Value::Number& result) { AS3getSeconds(result); }
    // @0x14242a0a0
    void Date::secondsUTCGet(Value::Number& result) { AS3getUTCSeconds(result); }

    // @0x142427c40
    void Date::dateSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyDateArg(Date_Day, v, LocalTZA); }
    // @0x142427cc0
    void Date::dateUTCSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyDateArg(Date_Day, v, 0); }
    // @0x142428a10
    void Date::fullYearSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyDateArg(Date_Year, v, LocalTZA); }
    // @0x142428a70
    void Date::fullYearUTCSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyDateArg(Date_Year, v, 0); }
    // @0x142429880
    void Date::monthSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyDateArg(Date_Month, v, LocalTZA); }
    // @0x142429900
    void Date::monthUTCSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyDateArg(Date_Month, v, 0); }
    // @0x142428dd0
    void Date::hoursSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Hour, v, LocalTZA); }
    // @0x142428df0
    void Date::hoursUTCSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Hour, v, 0); }
    // @0x142429830
    void Date::minutesSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Minute, v, LocalTZA); }
    // @0x142429860
    void Date::minutesUTCSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Minute, v, 0); }
    // @0x14242a080
    void Date::secondsSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Second, v, LocalTZA); }
    // @0x14242a0b0
    void Date::secondsUTCSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Second, v, 0); }
    // @0x142429640
    void Date::millisecondsSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Ms, v, LocalTZA); }
    // @0x1424296d0
    void Date::millisecondsUTCSet(const Value& result, Value::Number v) { SF_UNUSED(result); applyTimeArg(Time_Ms, v, 0); }
}} // namespace Instances::fl

}}} // namespace Scaleform::GFx::AS3
// MS2-PIN: ??_7Array@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431415b0
// MS2-PIN: ??_7Catch@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143140530
// MS2-PIN: ??_7Date@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142508
// MS2-PIN: ??_7Error@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143141b80
// MS2-PIN: ??_7GlobalObject@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143b20
// MS2-PIN: ??_7GlobalObjectScript@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143bf0
// MS2-PIN: ??_7Object@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x14313f590
// MS2-PIN: ??_7QName@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143140810
// MS2-PIN: ??_7RegExp@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143141880
// MS2-PIN: ??_7XML@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431429d0
// MS2-PIN: ??_7XMLAttr@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142dc8
// MS2-PIN: ??_7XMLComment@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431434f8
// MS2-PIN: ??_7XMLElement@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143142fa0
// MS2-PIN: ??_7XMLList@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x1431436d0
// MS2-PIN: ??_7XMLProcInstr@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143330
// MS2-PIN: ??_7XMLText@fl@Instances@AS3@GFx@Scaleform@@6B@ 0x143143168
