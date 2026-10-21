// Recovered Scaleform 4.1.18 GFx AS2: instance classes of the built-in script classes whose methods are not
// recovered yet. Only the sizes are known (from the Prototype<> layouts in the exe); move a class into its own
// header and name its members when its methods are recovered.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_BUILTINOBJECTS_H
#define MS2_SF_GFX_AS2_BUILTINOBJECTS_H

#include "as2_object.h"
#include "as2_objectproto.h"
#include "../gfx_asutils.h"
#include "../gfx_textsnapshot.h"
#include "../../kernel/sf_stringhash.h"

namespace Scaleform { namespace Render { namespace Text { class TextFormat; class ParagraphFormat; } } }
// The IME styles live in GFx::Text in 4.1.18 (exe mangling).
namespace Scaleform { namespace GFx { namespace Text { struct IMEStyle; } } }

namespace Scaleform { namespace GFx {

// Receiver of the stored data of a shared object (SharedObjectManagerBase::LoadSharedObject). Only Begin, the first
// slot after the destructor, is declared so far.
class ImageResource;
class MovieDef;

class SharedObjectVisitor : public RefCountBaseNTS<SharedObjectVisitor, Stat_Default_Mem>
{
public:
    virtual void Begin() = 0;
};

namespace AS2 {

// 0x68 bytes: nothing besides the object.
class AmpMarker : public Object {};
// The listener list behind AsBroadcaster.initialize (the _listeners array of the broadcaster).
class AsBroadcaster : public Object
{
public:
    // Called for each listener that has the broadcast method.
    class InvokeCallback
    {
    public:
        virtual ~InvokeCallback() {}
        virtual void Invoke(Environment* penv, ObjectInterface* pthis, const FunctionRef& method) = 0;
    };

    // Calls eventName on every listener with the nArgs stack arguments below firstArgBottomIndex; false without a
    // broadcaster (exe 0x142932180).
    static bool BroadcastMessage(Environment* penv, ObjectInterface* pthis, const ASString& eventName, int nArgs,
                                 int firstArgBottomIndex);
    static bool BroadcastMessageWithCallback(Environment* penv, ObjectInterface* pthis, const ASString& eventName,
                                             InvokeCallback* pcallback); // exe 0x142932290
    // Adds plistener to the _listeners of pthis unless it is there already (exe 0x14292f5b0).
    static bool AddListener(Environment* penv, ObjectInterface* pthis, ObjectInterface* plistener);

    // Makes pobj a broadcaster: the prototype methods and a fresh _listeners array (exe 0x142961d40).
    static bool Initialize(ASStringContext* psc, ObjectInterface* pobj);
    // Adds addListener / broadcastMessage / removeListener to pobj, false without one (exe 0x142961fe0).
    static bool InitializeProto(ASStringContext* psc, ObjectInterface* pobj);
    // Gives pobj its own empty _listeners array (exe 0x142961ef0).
    static bool InitializeInstance(ASStringContext* psc, ObjectInterface* pobj);
};

// The AsBroadcaster prototype object.
class AsBroadcasterProto : public Prototype<AsBroadcaster>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213460

    static void AddListener(const FnCall& fn);      // exe 0x1428fbd10
    static void BroadcastMessage(const FnCall& fn); // exe 0x1428fbdc0
    static void RemoveListener(const FnCall& fn);   // exe 0x1428fbea0
};
class ExternalInterface : public Object {};
class KeyObject : public Object {};
class Math : public Object {};
class MouseObject : public Object {};
class Selection : public Object {};
class StageObject : public Object {};

// 0x70 bytes.
class BooleanObject : public Object
{
public:
    bool BValue; // +0x68

protected:
    void CommonInit(Environment* penv); // exe 0x142934a00
};
class ButtonObject : public Object
{
public:
    WeakPtr<InteractiveObject> pButton; // +0x68

    virtual InteractiveObject*       GetASCharacter();       // exe 0x1429490c0
    virtual const InteractiveObject* GetASCharacter() const; // exe 0x142949140

protected:
    virtual void Finalize_GC(); // exe 0x142942d20
};
class ColorObject : public Object
{
public:
    WeakPtr<InteractiveObject> pCharacter; // +0x68

    ColorObject(Environment* penv, InteractiveObject* ptarget); // exe 0x14291ad30

    void SetTarget(InteractiveObject* ptarget) { pCharacter = ptarget; }

protected:
    virtual void Finalize_GC(); // exe 0x142942d60
};
class MovieClipLoader : public Object
{
public:
    // Byte counts of one movie being loaded (kept per URL).
    struct ProgressDesc
    {
        int LoadedBytes;
        int TotalBytes;

        ProgressDesc() {}
        ProgressDesc(int loaded, int total) : LoadedBytes(loaded), TotalBytes(total) {}
    };

    StringHashLH<ProgressDesc> ProgressInfo; // +0x68 by URL

    // Byte counts of the movie loading into pch, 0 when it is not tracked (exe 0x14294b170 / 0x142956b40).
    int GetLoadedBytes(InteractiveObject* pch) const;
    int GetTotalBytes(InteractiveObject* pch) const;

protected:
    virtual void Finalize_GC(); // exe 0x142942dd0
};

// 0x78 bytes.
class BitmapData : public Object
{
public:
    BitmapData(Environment* penv); // exe 0x142918ef0

    Ptr<ImageResource> pImageRes; // +0x68
    Ptr<MovieDef>      pMovieDef; // +0x70 keeps the image heap of the movie alive

protected:
    virtual void Finalize_GC(); // exe 0x142942ca0
};
class LoadVarsObject : public Object
{
public:
    LoadVarsObject(Environment* penv); // exe 0x14291dda0

    void* Data68[2]; // +0x68 not recovered
};
class MovieClipObject : public Object
{
public:
    WeakPtr<Sprite> pSprite;           // +0x68
    UInt16          ButtonEventMask;   // +0x70 button events with a handler set on the clip
    bool            HasButtonHandlers; // +0x72

    // The clip or the first movie clip prototype handles button events (exe 0x14292e120).
    bool ActsAsButton() const;

    // ButtonEventMask bits, one per button handler name.
    enum ButtonEventNameMask
    {
        Mask_onPress             = 0x001,
        Mask_onRelease           = 0x002,
        Mask_onReleaseOutside    = 0x004,
        Mask_onRollOver          = 0x008,
        Mask_onRollOut           = 0x010,
        Mask_onDragOver          = 0x020,
        Mask_onDragOut           = 0x040,
        Mask_onPressAux          = 0x080,
        Mask_onReleaseAux        = 0x100,
        Mask_onReleaseOutsideAux = 0x200,
        Mask_onDragOverAux       = 0x400,
        Mask_onDragOutAux        = 0x800
    };
    // The mask bit of a button handler name, 0 for any other name (exe 0x142949b30).
    static UInt16 GetButtonEventNameMask(ASStringContext* psc, const ASString& name);

    virtual bool DeleteMember(ASStringContext* psc, const ASString& name); // exe 0x142938850

    virtual InteractiveObject*       GetASCharacter();       // exe 0x1429491c0
    virtual const InteractiveObject* GetASCharacter() const; // exe 0x142949240

protected:
    virtual void Finalize_GC(); // exe 0x142942df0
};
class NumberObject : public Object
{
public:
    Number NumberValue; // +0x68
    String StringValue; // +0x70 text of the last ToString

    // Text of the value in the radix (see NumberUtil::ToString), kept alive in StringValue.
    const char* ToString(int radix)
    {
        char        buf[0x40];
        const char* pstr = NumberUtil::ToString(NumberValue, buf, sizeof(buf), radix);
        StringValue      = pstr;
        return StringValue.ToCStr();
    }

    virtual const char* GetTextValue(Environment* penv = 0) const; // exe 0x1429566d0 decimal text

protected:
    void CommonInit(Environment* penv); // exe 0x142934a40

    virtual void Finalize_GC(); // exe 0x142942e30
};
class SharedObject : public Object
{
public:
    SharedObject(Environment* penv); // exe 0x142920710

    String Name;      // +0x68
    String LocalPath; // +0x70

    virtual void Finalize_GC(); // exe 0x142942f10
};

// The out-of-line Resize / PushBack of the loader's object stack (exe COMDATs the exe calls where cl inlines them).
void ObjectPtrArray_Resize(Array<Object*>* parray, UPInt newSize);            // exe 0x14297e230
void ObjectPtrArray_PushBack(Array<Object*>* parray, Object* const& pobj);     // exe 0x142971a50

// Rebuilds a shared object's data from the visits of the shared object manager. 0x40 bytes.
class GASSharedObjectLoader : public SharedObjectVisitor
{
public:
    // Starts from the data object alone on the stack (exe 0x142932010).
    virtual void Begin();

private:
    Environment*   pEnv;        // +0x10
    Object*        pData;       // +0x18
    Array<Object*> ObjectStack; // +0x20
    bool           bArrayIsTop; // +0x38
};
class TextFieldObject : public Object
{
public:
    WeakPtr<InteractiveObject> pTextField;                  // +0x68
    GFx::Text::IMEStyle*    pIMECompositionStringStyles; // +0x70 owned

    // The IME styles of the field or of the nearest text field prototype that has them (exe 0x14294b030).
    GFx::Text::IMEStyle* GetIMECompositionStringStyles();

    virtual InteractiveObject*       GetASCharacter();       // exe 0x1429492c0
    virtual const InteractiveObject* GetASCharacter() const; // exe 0x142949340

protected:
    virtual void Finalize_GC(); // exe 0x1429430b0
};

// 0x90 bytes.
class TextSnapshotObject : public Object
{
public:
    void* Data68[5]; // +0x68 StaticTextSnapshotData (0x28 bytes, layout not recovered)

    StaticTextSnapshotData& GetData() { return *(StaticTextSnapshotData*)Data68; }
    void SetSelectColor(const Render::Color& color) { GetData().SetSelectColor(color); }

protected:
    virtual void Finalize_GC(); // exe 0x142943130
};

// TextSnapshot methods.
class TextSnapshotProto
{
public:
    static void FindTextA(const FnCall& fn);
    static void GetCount(const FnCall& fn);
    static void GetSelected(const FnCall& fn);
    static void GetSelectedText(const FnCall& fn);
    static void GetText(const FnCall& fn);
    static void SetSelectColor(const FnCall& fn);
    static void SetSelected(const FnCall& fn);
};

// 0x98 bytes.
class StyleSheetObject : public Object
{
public:
    StyleSheetObject(Environment* penv); // exe 0x142921190

    void* Data68[6]; // +0x68 not recovered
};

// 0xd0 bytes.
class TextFormatObject : public Object
{
public:
    TextFormatObject(Environment* penv); // exe 0x1429226d0

    void* Data68[13]; // +0x68 Render::Text::TextFormat (0x48 bytes), +0xb0 Render::Text::ParagraphFormat (0x20 bytes)

    Render::Text::TextFormat&      GetTextFormat()      { return *(Render::Text::TextFormat*)Data68; }
    Render::Text::ParagraphFormat& GetParagraphFormat() { return *(Render::Text::ParagraphFormat*)(Data68 + 9); }

protected:
    virtual void Finalize_GC(); // exe 0x142943100
};

// flash.geom.Transform of a character. 0x90 bytes.
class TransformObject : public Object
{
public:
    MovieImpl*           pMovieRoot;      // +0x68
    Ptr<CharacterHandle> TargetHandle;    // +0x70
    Ptr<Object>          Matrix;          // +0x78 MatrixObject
    Ptr<Object>          pColorTransform; // +0x80 ColorTransformObject
    Ptr<Object>          PixelBounds;     // +0x88 RectangleObject

    TransformObject(Environment* penv, InteractiveObject* pcharacter = 0); // exe 0x142923350

protected:
    virtual void Finalize_GC(); // exe 0x142943150

    template<class Functor> void ForEachChild_GC(Collector* prcc) const; // defined in sfr_as2_02
};

// Receiver of the mouse events of a movie (MovieRoot); vftable { dtor, OnMouseMove, OnMouseDown, OnMouseUp,
// OnMouseWheel, IsEmpty }, only the dtor declared so far.
class MouseListener
{
public:
    virtual ~MouseListener() {}
};

class ArrayObject;

// The Mouse class (constructor function holding the listeners). 0xa8 bytes.
class MouseCtorFunction : public CFunctionObject, public MouseListener
{
public:
    Ptr<ArrayObject> pListenersArray;   // +0x78
    SInt32           LastMousePos[2];   // +0x80
    UInt32           LastClickTime;     // +0x88
    FunctionRef      SetCursorTypeFunc; // +0x90

protected:
    // Mouse() called as a function: null (exe 0x14295bc20).
    static void GlobalCtor(const FnCall& fn);

    template<class Functor> void ForEachChild_GC(Collector* prcc) const; // defined in sfr_as2_02

    // Mouse.show / Mouse.hide([mouse]): requests to the user event handler.
    static void Show(const FnCall& fn);
    static void Hide(const FnCall& fn);
};

// Value of the SharedObject lookup: a pointer that the collector visits. 0x10 bytes, vftable { dtor, Finalize_GC }.
class SharedObjectPtr : public Ptr<SharedObject>
{
public:
    virtual ~SharedObjectPtr() {}
    virtual void Finalize_GC() {}

    template<class Functor>
    void ForEachChild_GC(ASRefCountBaseType::Collector* prcc) const
    {
        Functor::Call(prcc, pObject);
    }
};

// The SharedObject class: the shared objects by name. 0x90 bytes.
class SharedObjectCtorFunction : public CFunctionObject
{
public:
    ASStringHash_GC<SharedObjectPtr> SharedObjects; // +0x70

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937240

    // SharedObject() called as a function: a new shared object (exe 0x14295c670).
    static void GlobalCtor(const FnCall& fn);

protected:
    virtual void Finalize_GC(); // exe 0x142942f80

    template<class Functor> void ForEachChild_GC(Collector* prcc) const; // defined in sfr_as2_02
};

// The LoadVars class.
class GASLoadVarsLoaderCtorFunction : public CFunctionObject
{
public:
    // LoadVars() on a LoadVars instance returns it, null otherwise (exe 0x14295afb0).
    static void GlobalCtor(const FnCall& fn);

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936e10
};

// The TextField.StyleSheet class.
class StyleSheetCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937380
};

// The TextFormat class.
class TextFormatCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937470
};

// The flash.geom.Transform class.
class TransformCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429374b0
};

// The AmpMarker class: one static method that puts a named marker into the profiler stats of the movie.
class AmpMarkerCtorFunction : public CFunctionObject
{
public:
    static void GlobalCtor(const FnCall& fn); // exe 0x142958490 null

private:
    static void AddMarker(const FnCall& fn);
};

// Classes with nothing to construct: called as a function they return null (ExternalInterface undefined).
class ExternalInterfaceCtorFunction : public CFunctionObject
{
public:
    static void GlobalCtor(const FnCall& fn); // exe 0x14295ae20 undefined
};
class MathCtorFunction : public CFunctionObject
{
public:
    static void GlobalCtor(const FnCall& fn); // exe 0x14295bc00
};
class SelectionCtorFunction : public CFunctionObject
{
public:
    static void GlobalCtor(const FnCall& fn); // exe 0x14295c650
};
class StageCtorFunction : public CFunctionObject
{
public:
    static void GlobalCtor(const FnCall& fn); // exe 0x14295c6f0
};

// The Boolean class.
class BooleanCtorFunction : public CFunctionObject
{
public:
    // new Boolean(v) stores v in the instance, Boolean(v) converts v (exe 0x1429595a0).
    static void GlobalCtor(const FnCall& fn);
};

// The Number class.
class NumberCtorFunction : public CFunctionObject
{
public:
    // new Number(v) stores v in the instance, Number(v) converts v (exe 0x14295bd30).
    static void GlobalCtor(const FnCall& fn);
};

// The Color class.
class ColorCtorFunction : public CFunctionObject
{
public:
    // Color(target) as a constructor retargets the instance, as a function makes a new one (exe 0x142959740).
    static void GlobalCtor(const FnCall& fn);
};

// The flash.display.BitmapData class.
class BitmapDataCtorFunction : public CFunctionObject
{
public:
    // BitmapData() called as a function: a new empty bitmap (exe 0x142959160).
    static void GlobalCtor(const FnCall& fn);
};

// The MovieClipLoader class.
class MovieClipLoaderCtorFunction : public CFunctionObject
{
public:
    // MovieClipLoader() on a loader instance makes it its own listener and returns it, null otherwise
    // (exe 0x14295bca0).
    static void GlobalCtor(const FnCall& fn);
};

// The AsBroadcaster class.
class AsBroadcasterCtorFunction : public CFunctionObject
{
public:
    // AsBroadcaster() on a broadcaster instance returns it, null otherwise (exe 0x142958670).
    static void GlobalCtor(const FnCall& fn);
};

// The MovieClip class.
class MovieClipCtorFunction : public CFunctionObject
{
public:
    // MovieClip() on a clip object returns it, undefined otherwise (exe 0x14295bc40).
    static void GlobalCtor(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform { namespace GFx { namespace AMP {

// Profiler statistics of one movie view (MovieImpl::AdvanceStats).
class ViewStats
{
public:
    void AddMarker(const char* name); // exe 0x1426204e0
};

}}} // namespace Scaleform::GFx::AMP

#endif
