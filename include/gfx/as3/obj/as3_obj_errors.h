// Recovered Scaleform GFx 4.1.18 AS3 flash.errors class traits (EOFError, IOError, IllegalOperationError,
// InvalidSWFError, MemoryError, ScriptTimeoutError, StackOverflowError); our own declarations. Instances use
// InstanceTraits::fl::Error, the class objects are plain Class.
#ifndef MS2_SF_GFX_AS3_OBJ_ERRORS_H
#define MS2_SF_GFX_AS3_OBJ_ERRORS_H

#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"

namespace Scaleform { namespace GFx { namespace AS3 {

namespace ClassTraits { namespace fl_errors {
    class EOFError : public Traits
    {
    public:
        EOFError(VM& vm);
        // @0x142455e20
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::EOFError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IOError : public Traits
    {
    public:
        IOError(VM& vm);
        // @0x142455e30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IOError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class IllegalOperationError : public Traits
    {
    public:
        IllegalOperationError(VM& vm);
        // @0x142455e40
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::IllegalOperationError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class InvalidSWFError : public Traits
    {
    public:
        InvalidSWFError(VM& vm);
        // @0x142455e50
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::InvalidSWFError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class MemoryError : public Traits
    {
    public:
        MemoryError(VM& vm);
        // @0x142455e60
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::MemoryError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ScriptTimeoutError : public Traits
    {
    public:
        ScriptTimeoutError(VM& vm);
        // @0x142455e70
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ScriptTimeoutError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class StackOverflowError : public Traits
    {
    public:
        StackOverflowError(VM& vm);
        // @0x142455e80
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::StackOverflowError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };
}}

}}} // namespace Scaleform::GFx::AS3

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_errors::EOFError) == 0xc8, "EOFError size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_errors::IOError) == 0xc8, "IOError size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_errors::IllegalOperationError) == 0xc8, "IllegalOperationError size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_errors::InvalidSWFError) == 0xc8, "InvalidSWFError size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_errors::MemoryError) == 0xc8, "MemoryError size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_errors::ScriptTimeoutError) == 0xc8, "ScriptTimeoutError size");
static_assert(sizeof(Scaleform::GFx::AS3::ClassTraits::fl_errors::StackOverflowError) == 0xc8, "StackOverflowError size");

#endif
