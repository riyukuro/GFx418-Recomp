// Recovered Scaleform GFx 4.1.18 AS3: the movie-side VM (ASVM) and the AS3 movie root, as the AS3 natives see them.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
//
// ASVM extends VM (as3_vm.h, which ends at +0x2d8) with the movie root and the class objects of the builtins the
// natives construct directly. MovieRoot is declared only as far as the natives reach (its movie, at +0x10 of the
// ASMovieRootBase part) and
// the external interface return value.
#ifndef MS2_SF_GFX_AS3_ASVM_H
#define MS2_SF_GFX_AS3_ASVM_H

#include "ms2/scaleform/include/gfx/gfx_displayobject.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimplstates.h"
#include "ms2/scaleform/include/gfx/gfx_value.h"
#include "ms2/scaleform/include/gfx/gfx_event.h"
#include "ms2/scaleform/include/gfx/gfx_keyboardstate.h"
#include "ms2/scaleform/include/gfx/as3/as3_vm.h"
#include "ms2/scaleform/include/gfx/gfx_playertasks.h"

// windows.h (through the kernel lock header) maps GetObject to GetObjectA; Value::GetObject keeps its name.
#ifdef GetObject
#undef GetObject
#endif

namespace Scaleform { namespace GFx { namespace AS3 {

class LoadQueueEntry;   // (appended, sfr19) as3_loadqueue.h
class ASVM;             // (appended, sfr19)
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

    // Converts v into a host value for the external interface.
    void ASValue2GFxValue(const Value& v, GFx::Value* pdestVal) const;     // 0x1424e42c0
    // (appended, sfr19) the reverse: a host value as an AS3 value. 0x1425048d0
    void GFxValue2ASValue(const GFx::Value& gfxVal, Value* pdestVal);

private:
    UByte               Unrecovered28[0x48 - sizeof(ASMovieRootBase)];
public:
    ASVM*               pAVM;                       // +0x48 AutoPtr<ASVM> (sfr19)
private:
    UByte               Unrecovered50[0x58 - 0x50];
public:
    Value               ExternalIntfRetVal;         // +0x58: what the host's ExternalInterface callback returned
private:
    UByte               Unrecovered78[0x158 - 0x78];
public:
    GFx::DisplayObject* pStage;                     // +0x158 Ptr<Stage>: the stage the root movies sit on (sfr19)
    StringManager       BuiltinsMgr;                // +0x160: the AS3 builtin strings

    // (appended for the Loader natives, sfr17) the load queue.
    void UnloadMovie(Instances::fl_display::Loader* ploader, bool stop = false, bool gc = false);   // 0x1425305f0
    void AddNewLoadQueueEntry(Instances::fl_net::URLRequest* urlRequest, Instances::fl_display::Loader* loader,
                              GFx::LoadQueueEntry::LoadMethod method = GFx::LoadQueueEntry::LM_None); // 0x1424e9090
    void AddNewLoadQueueEntry(Instances::fl_utils::ByteArray* bytes, Instances::fl_display::Loader* loader,
                              GFx::LoadQueueEntry::LoadMethod method = GFx::LoadQueueEntry::LM_None); // 0x1424e9010
    // (appended, sfr19) URLLoader.load. 0x1424e9210
    void AddNewLoadQueueEntry(Instances::fl_net::URLRequest* urlRequest, Instances::fl_net::URLLoader* loader,
                              GFx::LoadQueueEntry::LoadMethod method = GFx::LoadQueueEntry::LM_None);
    // (appended, sfr19) pentry handed to a loader-thread entry (variables, binary or movie). 0x1424e8c20
    void AddLoadQueueEntryMT(LoadQueueEntry* pentry);
    // (appended, sfr19) ASMovieRootBase::ProcessLoadQueueEntry: 4.1.18 vftable slot 26 (+0xd0).
    void ProcessLoadQueueEntry418(GFx::LoadQueueEntry* pentry, LoadStates* pls)
    {
        typedef void (*Fn)(MovieRoot*, GFx::LoadQueueEntry*, LoadStates*);
        (*reinterpret_cast<Fn const* const*>(this))[26](this, pentry, pls);
    }
    // (appended, sfr19) the directory of _level0's URL into ppath; false (ppath cleared) without one. 0x14250da50
    bool GetRootFilePath(String* ppath) const;
    // (appended, sfr19) ASMovieRootBase::GetStringManager: 4.1.18 vftable slot 50 (+0x190).
    ASStringManager* GetStringManager418() const
    {
        typedef ASStringManager* (*Fn)(const MovieRoot*);
        return (*reinterpret_cast<Fn const* const*>(this))[50](this);
    }
protected:
    // (appended, sfr19) the mouseCursorEvent name of a MouseCursorEvent cursor type. 0x14250bb10
    void GetMouseCursorTypeString(ASString& str, unsigned cursorType) const;
};

class ASVM : public VM
{
public:
    MovieImpl* GetMovieImpl() const { return pMovieRoot->GetMovieImpl(); }
    MovieRoot* GetMovieRoot() const { return pMovieRoot; }
    Log*       GetLog() const;     // 0x1424c90e0
    const ASString& GetBuiltin(BuiltinType btype) const { return pMovieRoot->BuiltinsMgr.GetBuiltin(btype); }

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
    // (appended, sfr_as3_09) the "Ex" event classes (scaleform.gfx.*EventEx: controller/mouse indices) are made in
    // place of the flash.events ones
    bool                ExtensionsEnabled;          // +0x3a0
};

}}} // namespace Scaleform::GFx::AS3

#endif
