// Recovered Scaleform GFx 4.1.18 AS3: what the namespace initializers of sfr_as3di_01/05 need. A native method table
// (ThunkInfo[]) is constant-initialized except for the NamespaceName of its AS3-, XML- or proxy-namespace methods,
// which the exe sets in a dynamic initializer from the extern namespace URI strings. Our build holds the tables as
// data-unit images (data_data_game), so the initializers set those fields through the table addresses below.
// Our own source, written from the exe.
#ifndef MS2_SFR_AS3DI_NS_H
#define MS2_SFR_AS3DI_NS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fntraits.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl {
extern const char* const NS_AS3;           // "http://adobe.com/AS3/2006/builtin"
extern const char* const NS_flash_proxy;   // "http://www.adobe.com/flash/proxy"
}

namespace Instances { namespace fl {
extern const char* DateMonthNames[];       // the image runs on into Object's method table (+0x60)
}}

// Sets the NamespaceName of `count` consecutive entries, the first `offset` bytes into `table`. Out of line: the
// tables are declared const, and an inlined copy lets the compiler fold the initializer to `true` without the stores.
static __declspec(noinline) bool SetThunkNamespaces(const void* table, UPInt offset, unsigned count, const char* ns)
{
    ThunkInfo* ti = (ThunkInfo*)((UByte*)table + offset);
    for (unsigned i = 0; i < count; ++i)
        ti[i].NamespaceName = ns;
    return true;
}

}}} // namespace Scaleform::GFx::AS3

extern const Scaleform::GFx::AS3::ThunkInfo DAT_143a2aab0[];   // Function prototype, then the fl class tables
extern const char* const DAT_143a2d158[];                       // ... Proxy's table at +0xc8
extern const Scaleform::GFx::AS3::ThunkInfo DAT_143a2d5c0[];   // the Object methods of a class object
extern "C" unsigned char DAT_143a2dd50[];                       // ... the fl_vec Vector tables

#endif
