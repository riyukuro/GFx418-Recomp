// Recovered Scaleform GFx 4.1.18 AS3: the movie-side VM (ASVM) and the AS3 movie root, as the AS3 natives see them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// ASVM extends VM (as3_vm.h, which ends at +0x2d8) with the movie root and the class objects of the builtins the
// natives construct directly. MovieRoot is declared only as far as the natives reach (its movie, at +0x10 of the
// ASMovieRootBase part).
#ifndef MS2_SF_GFX_AS3_ASVM_H
#define MS2_SF_GFX_AS3_ASVM_H

#include "GFx/GFx_ASMovieRootBase.h"
#include "GFx/GFx_PlayerImpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"

namespace Scaleform { namespace GFx { namespace AS3 {

class MovieRoot : public ASMovieRootBase
{
public:
    // ASMovieRootBase::GetRootMovie. 4.1.18 has no GenerateTouchEvents/GenerateGestureEvents slots, so it is vftable
    // slot 14 (+0x70) in the exe, two slots before where the 4.1.19 SDK header puts it.
    DisplayObjContainer* GetRootMovie418(DisplayObject* dobj = NULL) const
    {
        typedef DisplayObjContainer* (*Fn)(const MovieRoot*, DisplayObject*);
        return (*reinterpret_cast<Fn const* const*>(this))[14](this, dobj);
    }
};

class ASVM : public VM
{
public:
    MovieImpl* GetMovieImpl() const { return pMovieRoot->GetMovieImpl(); }
    MovieRoot* GetMovieRoot() const { return pMovieRoot; }

    // Constructs an instance of the class object classObj; false when the construction threw.
    bool _constructInstance(SPtr<Object>& pobj, Object* classObj, unsigned argc, const Value* argv);   // 0x142531f40
    template <class T>
    bool ConstructInstance(SPtr<T>& pobj, Object* classObj, unsigned argc = 0, const Value* argv = 0)
    {
        return _constructInstance(reinterpret_cast<SPtr<Object>&>(pobj), classObj, argc, argv);
    }

protected:
    MovieRoot*          pMovieRoot;                 // +0x2d8
public:
    SPtr<Class>         GraphicsClass;              // +0x2e0
    SPtr<Class>         TransformClass;             // +0x2e8
    SPtr<Class>         MatrixClass;                // +0x2f0
    SPtr<Class>         Matrix3DClass;              // +0x2f8
    SPtr<Class>         PerspectiveProjectionClass; // +0x300
    SPtr<Class>         ColorTransformClass;        // +0x308
    SPtr<Class>         EventClass;                 // +0x310
    SPtr<Class>         MouseEventClass;            // +0x318
    SPtr<Class>         MouseEventExClass;          // +0x320
    SPtr<Class>         KeyboardEventClass;         // +0x328
    SPtr<Class>         KeyboardEventExClass;       // +0x330
    SPtr<Class>         FocusEventClass;            // +0x338
    SPtr<Class>         FocusEventExClass;          // +0x340
    SPtr<Class>         TextEventClass;             // +0x348
    SPtr<Class>         TextEventExClass;           // +0x350
    SPtr<Class>         TimerEventClass;            // +0x358
    SPtr<Class>         ProgressEventClass;         // +0x360
    SPtr<Class>         StageOrientationEventClass; // +0x368
    SPtr<Class>         AppLifecycleEventClass;     // +0x370
    SPtr<Class>         PointClass;                 // +0x378
    SPtr<Class>         RectangleClass;             // +0x380
    SPtr<Class>         TextFormatClass;            // +0x388
    SPtr<Class>         EventDispatcherClass;       // +0x390
    SPtr<Class>         Vector3DClass;              // +0x398
};

}}} // namespace Scaleform::GFx::AS3

#endif
