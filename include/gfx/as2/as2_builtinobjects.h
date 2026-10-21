// Recovered Scaleform 4.1.18 GFx AS2: instance classes of the built-in script classes whose methods are not
// recovered yet. Only the sizes are known (from the Prototype<> layouts in the exe); move a class into its own
// header and name its members when its methods are recovered.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_BUILTINOBJECTS_H
#define MS2_SF_GFX_AS2_BUILTINOBJECTS_H

#include "as2_object.h"
#include "../gfx_asutils.h"
#include "../gfx_textsnapshot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// 0x68 bytes: nothing besides the object.
class AmpMarker : public Object {};
class AsBroadcaster : public Object {};
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
};
class ButtonObject : public Object
{
public:
    void* Data68; // +0x68 not recovered
};
class ColorObject : public Object
{
public:
    void* Data68; // +0x68 not recovered
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

    void* Data68; // +0x68 not recovered
};

// 0x78 bytes.
class BitmapData : public Object
{
public:
    void* Data68[2]; // +0x68 not recovered
};
class LoadVarsObject : public Object
{
public:
    void* Data68[2]; // +0x68 not recovered
};
class MovieClipObject : public Object
{
public:
    void* Data68[2]; // +0x68 not recovered
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
};
class SharedObject : public Object
{
public:
    void* Data68[2]; // +0x68 not recovered
};
class TextFieldObject : public Object
{
public:
    void* Data68[2]; // +0x68 not recovered
};

// 0x90 bytes.
class TextSnapshotObject : public Object
{
public:
    void* Data68[5]; // +0x68 StaticTextSnapshotData (0x28 bytes, layout not recovered)

    StaticTextSnapshotData& GetData() { return *(StaticTextSnapshotData*)Data68; }
    void SetSelectColor(const Render::Color& color) { GetData().SetSelectColor(color); }
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
    void* Data68[6]; // +0x68 not recovered
};

// 0xd0 bytes.
class TextFormatObject : public Object
{
public:
    void* Data68[13]; // +0x68 not recovered
};

// flash.geom.Transform of a character. 0x90 bytes.
class TransformObject : public Object
{
public:
    void*       Data68[2];       // +0x68 not recovered
    Ptr<Object> Matrix;          // +0x78 MatrixObject
    Ptr<Object> pColorTransform; // +0x80 ColorTransformObject
    Ptr<Object> PixelBounds;     // +0x88 RectangleObject

protected:
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

protected:
    template<class Functor> void ForEachChild_GC(Collector* prcc) const; // defined in sfr_as2_02
};

// The AmpMarker class: one static method that puts a named marker into the profiler stats of the movie.
class AmpMarkerCtorFunction : public CFunctionObject
{
private:
    static void AddMarker(const FnCall& fn);
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
