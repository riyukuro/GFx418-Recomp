// Recovered Scaleform GFx 4.1.18 AS3: Value and the native class descriptors (ClassInfo / MemberInfo).
//
// Value, SPtr, Pickable, CheckResult and ThunkInfo come from the 4.1.19 headers on the scaleform include path for now
// (same layouts as the exe: Value 0x20, ThunkInfo 0x28). The 4.1.19 ClassInfo is NOT the exe's: there it points to a
// separate TypeInfo, while the 4.1.18 descriptor carries the type fields itself (flags, name, package, parent) followed
// by the factory, the four counts and the four tables (0x50 bytes, e.g. DefinitionError at 0x14313dda0, Error at
// 0x14313dd50, whose Parent points to the parent's descriptor). The 4.1.19 struct is therefore renamed while its header
// is read and the exe's descriptor is declared here as ClassInfo. Include this header before anything that pulls in
// GFx/AS3/AS3_Value.h (e.g. GFx/AS3/IME/AS3_IMEManager.h).
#ifndef MS2_SF_GFX_AS3_VALUE_H
#define MS2_SF_GFX_AS3_VALUE_H

#ifdef INC_AS3_Value_H
#error "include ms2/scaleform/include/gfx/as3/as3_value.h before GFx/AS3/AS3_Value.h"
#endif

#define ClassInfo ClassInfo_v4119
#include "GFx/AS3/AS3_Value.h"
#undef ClassInfo

namespace Scaleform { namespace GFx { namespace AS3 {

// Native member variable of a C++ class: name, byte offset in the instance, binding kind. 0x10 bytes.
struct MemberInfo
{
    const char* Name;           // +0x00
    UInt16      Offset;         // +0x08
    UInt8       BindingType;    // +0x0a
    UInt8       Flags;          // +0x0b
};

// Descriptor of a native class: its type (the TypeInfo part, 0x20 bytes) followed by the traits factory and the
// method / member tables. 0x50 bytes.
struct ClassInfo : public TypeInfo
{
    TTraitsFactory      Factory;            // +0x20
    UInt8               ClassMethodNum;     // +0x28
    UInt8               ClassMemberNum;     // +0x29
    UInt8               InstanceMethodNum;  // +0x2a
    UInt8               InstanceMemberNum;  // +0x2b
    const ThunkInfo*    ClassMethod;        // +0x30
    const MemberInfo*   ClassMember;        // +0x38
    const ThunkInfo*    InstanceMethod;     // +0x40
    const MemberInfo*   InstanceMember;     // +0x48

    const ClassInfo* GetParentInfo() const { return static_cast<const ClassInfo*>(Parent); }
};

}}} // namespace Scaleform::GFx::AS3

#endif
