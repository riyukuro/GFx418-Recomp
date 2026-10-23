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
#include "../gfx_sharedobject.h"

namespace Scaleform { namespace Render { namespace Text { class TextFormat; class ParagraphFormat; } } }
// The IME styles live in GFx::Text in 4.1.18 (exe mangling).
namespace Scaleform { namespace GFx { namespace Text { struct IMEStyle; } } }

namespace Scaleform { namespace GFx {

class ImageResource;
class MovieDef;

namespace AS2 {

// 0x68 bytes: nothing besides the object.
class AmpMarker : public Object
{
public:
    AmpMarker(Environment* penv); // exe 0x142917b80
    AmpMarker(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

protected:
    void commonInit(Environment* penv); // exe 0x142994e10
};
// The AmpMarker prototype object.
class AmpMarkerProto : public Prototype<AmpMarker>
{
public:
    AmpMarkerProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142917c90
};
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
    // Takes plistener out of the _listeners of pthis, false when it is not there (exe 0x14297d1e0).
    static bool RemoveListener(Environment* penv, ObjectInterface* pthis, ObjectInterface* plistener);

    // Makes pobj a broadcaster: the prototype methods and a fresh _listeners array (exe 0x142961d40).
    static bool Initialize(ASStringContext* psc, ObjectInterface* pobj);
    // Adds addListener / broadcastMessage / removeListener to pobj, false without one (exe 0x142961fe0).
    static bool InitializeProto(ASStringContext* psc, ObjectInterface* pobj);
    // Gives pobj its own empty _listeners array (exe 0x142961ef0).
    static bool InitializeInstance(ASStringContext* psc, ObjectInterface* pobj);

    AsBroadcaster(Environment* penv); // exe 0x142918470
    AsBroadcaster(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }
    virtual ObjectType GetObjectType() const; // exe 0x142954140: Object_AsBroadcaster

protected:
    void commonInit(Environment* penv); // exe 0x142994e50
};

// The AsBroadcaster prototype object.
class AsBroadcasterProto : public Prototype<AsBroadcaster>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213460

    AsBroadcasterProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142918580
    static void AddListener(const FnCall& fn);      // exe 0x1428fbd10
    static void BroadcastMessage(const FnCall& fn); // exe 0x1428fbdc0
    static void RemoveListener(const FnCall& fn);   // exe 0x1428fbea0
};
class ExternalInterface : public Object
{
public:
    ExternalInterface(Environment* penv); // exe 0x14291bbd0
    ExternalInterface(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

    virtual ObjectType GetObjectType() const; // exe 0x142954240: Object_ExternalInterface
};
// The ExternalInterface prototype object.
class ExternalInterfaceProto : public Prototype<ExternalInterface>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213e30

    ExternalInterfaceProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291bd50
};
class KeyObject : public Object
{
public:
    KeyObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

    virtual ObjectType GetObjectType() const; // exe 0x142954260: Object_Key
};
// The Key prototype object.
class KeyProto : public Prototype<KeyObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432143a0

    KeyProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291dbe0
};
class Math : public Object
{
public:
    Math(Environment* penv); // exe 0x14291e1a0
    Math(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }
};
// The Math prototype object.
class MathProto : public Prototype<Math>
{
public:
    MathProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291e6a0
};
class MouseObject : public Object
{
public:
    MouseObject(Environment* penv); // exe 0x14291eb20
    MouseObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

protected:
    void commonInit(Environment* penv); // exe 0x142995040
};
// The Mouse prototype object.
class MouseProto : public Prototype<MouseObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213410

    MouseProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291eb90
};
class Selection : public Object
{
public:
    Selection(Environment* penv); // exe 0x1429204d0
    Selection(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

protected:
    void commonInit(Environment* penv); // exe 0x142995100
};
// The Selection prototype object.
class SelectionProto : public Prototype<Selection>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213040

    SelectionProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142920600
};
class StageObject : public Object
{
public:
    StageObject(Environment* penv); // exe 0x142920be0
    StageObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
    }

    virtual ObjectType GetObjectType() const; // exe 0x142954310: Object_Stage
};
// The Stage prototype object.
class StageProto : public Prototype<StageObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213660

    StageProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142920c50
};

// 0x70 bytes.
class BooleanObject : public Object
{
public:
    bool BValue; // +0x68

    BooleanObject(Environment* penv);         // exe 0x142919a00: false
    BooleanObject(Environment* penv, bool v); // exe 0x142919a70
    BooleanObject(ASStringContext* psc, Object* pprototype) : Object(psc), BValue(false)
    {
        Set__proto__(psc, pprototype);
    }
    virtual const char* GetTextValue(Environment* penv = 0) const; // exe 0x1429566a0
    virtual ObjectType  GetObjectType() const;                     // exe 0x1429541d0: Object_Boolean
    virtual void SetValue(Environment* penv, const Value& v); // exe 0x14298cc30
    virtual Value GetValue() const;                           // exe 0x142956c80

protected:
    void CommonInit(Environment* penv); // exe 0x142934a00
};
// The Boolean prototype object.
class BooleanProto : public Prototype<BooleanObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213630

    BooleanProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142919af0
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

    virtual ObjectType GetObjectType() const; // exe 0x142954200: Object_Color

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

    MovieClipLoader(Environment* penv); // exe 0x14291eca0

    virtual ObjectType GetObjectType() const; // exe 0x142954290: Object_MovieClipLoader

    // Broadcast the onLoad* events to the listeners (exe 0x14296a300 / 0x142969bd0 / 0x142969f50 / 0x142969d90 /
    // 0x14296a0a0).
    virtual void NotifyOnLoadStart(Environment* penv, InteractiveObject* ptarget);
    virtual void NotifyOnLoadComplete(Environment* penv, InteractiveObject* ptarget, int status);
    virtual void NotifyOnLoadInit(Environment* penv, InteractiveObject* ptarget);
    virtual void NotifyOnLoadError(Environment* penv, InteractiveObject* ptarget, const char* errorCode, int status);
    virtual void NotifyOnLoadProgress(Environment* penv, InteractiveObject* ptarget, int loadedBytes, int totalBytes);

    // Byte counts of the movie loading into pch, 0 when it is not tracked (exe 0x14294b170 / 0x142956b40).
    int GetLoadedBytes(InteractiveObject* pch) const;
    int GetTotalBytes(InteractiveObject* pch) const;

protected:
    virtual void Finalize_GC(); // exe 0x142942dd0

private:
    // Prototype, the broadcaster members and an own _listeners array (exe 0x142995080).
    void commonInit(Environment* penv);
};

// 0x78 bytes.
class BitmapData : public Object
{
public:
    BitmapData(Environment* penv); // exe 0x142918ef0
    virtual ~BitmapData(); // inline, defined in sfr_as2_03 (needs the complete ImageResource)

    virtual ObjectType GetObjectType() const; // exe 0x1429541a0: Object_BitmapData
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x1429854f0
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294dbe0

    Ptr<ImageResource> pImageRes; // +0x68
    Ptr<MovieDef>      pMovieDef; // +0x70 keeps the image heap of the movie alive

    void SetImage(Environment* penv, ImageResource* pimg, MovieDef* pmovieDef);

protected:
    virtual void Finalize_GC(); // exe 0x142942ca0

private:
    // Prototype and the read-only width / height members, unset until an image is set (exe 0x142994e90).
    void commonInit(Environment* penv);
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

    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());      // exe 0x142986790
    virtual bool SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val,
                              const PropFlags& flags = PropFlags());   // exe 0x142988b60
    // A non-clip prototype with button handlers makes the clip take button events (exe 0x14298dd70).
    virtual void Set__proto__(ASStringContext* psc, Object* protoObj);

protected:
    virtual void Finalize_GC(); // exe 0x142942df0

    // Button handler tracking and the renderer hint members, run before a member is set (exe 0x142988690).
    void SetMemberCommon(ASStringContext* psc, const ASString& name, const Value& val);
    // Sets (or clears) the mask bit of an on* button handler the clip gains (or loses) (exe 0x142992540).
    void TrackMemberButtonHandler(ASStringContext* psc, const ASString& name, bool deleteFlag = false);
};
class NumberObject : public Object
{
public:
    Number   NumberValue; // +0x68
    StringLH StringValue; // +0x70 text of the last ToString

    NumberObject(Environment* penv);           // exe 0x14291f430: 0
    NumberObject(Environment* penv, Number v); // exe 0x14291f4b0

    virtual ObjectType GetObjectType() const; // exe 0x1429542b0: Object_Number
    virtual Value      GetValue() const;      // exe 0x142956c90: NumberValue

    // Text of the value in the radix (see NumberUtil::ToString), kept alive in StringValue.
    const char* ToString(int radix)
    {
        char        buf[0x40];
        const char* pstr = NumberUtil::ToString(NumberValue, buf, sizeof(buf), radix);
        StringValue      = pstr;
        return StringValue.ToCStr();
    }

    virtual const char* GetTextValue(Environment* penv = 0) const; // exe 0x1429566d0 decimal text
    virtual void        SetValue(Environment* penv, const Value& v); // exe 0x14298cc50
    const char*         ToString_Call(int radix);                    // exe 0x142991e10, the out-of-line copy of ToString

protected:
    void CommonInit(Environment* penv); // exe 0x142934a40

    virtual void Finalize_GC(); // exe 0x142942e30
};
class SharedObject : public Object
{
public:
    SharedObject(Environment* penv); // exe 0x142920710

    virtual ObjectType GetObjectType() const; // exe 0x142954300: Object_SharedObject

    String Name;      // +0x68
    String LocalPath; // +0x70

    virtual void Finalize_GC(); // exe 0x142942f10

    // The "data" member (exe 0x1429804c0).
    void SetDataObject(Environment* penv, Object* pobj);
    // False for names with spaces or any of ~%&\;:"',<>?# (exe 0x142989250).
    bool SetNameAndLocalPath(const String& name, const String& localPath);

    // "data" is read-only (exe 0x142987280).
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
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
    virtual ~TextFieldObject(); // exe 0x142925f10
    virtual ObjectType               GetObjectType() const;  // exe 0x142954340: Object_TextField

protected:
    TextFieldObject(ASStringContext* psc, Object* pprototype); // exe 0x142921520
    TextFieldObject(Environment* penv);                        // exe 0x142921580

    virtual void Finalize_GC(); // exe 0x1429430b0
};

// 0x90 bytes.
class TextSnapshotObject : public Object
{
public:
    void* Data68[5]; // +0x68 StaticTextSnapshotData (0x28 bytes, layout not recovered)

    // (appended for sfr_as2_02: MovieClip.getTextSnapshot) an empty snapshot with the TextSnapshot prototype
    // Out of line in the exe (0x1429231e0, sfr_as2_03); MovieClip.getTextSnapshot has it inlined, so its TU defines
    // MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE before the includes.
#ifdef MS2_AS2_TEXTSNAPSHOT_CTOR_INLINE
    TextSnapshotObject(Environment* penv) : Object(penv)
    {
        ::new (Data68) StaticTextSnapshotData();
        Set__proto__(penv->GetSC(), penv->GetPrototype(ASBuiltin_TextSnapshot));
    }
#else
    TextSnapshotObject(Environment* penv);
#endif

    virtual ObjectType GetObjectType() const; // exe 0x142954360: Object_TextSnapshot

    StaticTextSnapshotData& GetData() { return *(StaticTextSnapshotData*)Data68; }
    void SetSelectColor(const Render::Color& color) { GetData().SetSelectColor(color); }

protected:
    virtual ~TextSnapshotObject(); // exe 0x142925f70
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

    // The character the transform reads and writes, 0 for none (exe 0x14298ba60).
    void SetTarget(InteractiveObject* pcharacter);

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

    // Asks the user event handler for cursor shape cursorType on mouse mouseIndex; false without a handler
    // (exe 0x142980380).
    static bool SetCursorType(MovieImpl* proot, unsigned mouseIndex, unsigned cursorType);

protected:
    // Mouse.setCursorType(shape[, mouse]) (exe 0x142980240).
    static void SetCursorType(const FnCall& fn);

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

    SharedObjectCtorFunction(ASStringContext* psc); // exe 0x142920790

    static const NameFunction StaticFunctionTable[]; // exe 0x143213ed0: getLocal

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937240

    // SharedObject() called as a function: a new shared object (exe 0x14295c670).
    static void GlobalCtor(const FnCall& fn);

protected:
    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const; // exe 0x142941220
    virtual void Finalize_GC(); // exe 0x142942f80

    template<class Functor> void ForEachChild_GC(Collector* prcc) const; // defined in sfr_as2_02
};

// The LoadVars class.
class GASLoadVarsLoaderCtorFunction : public CFunctionObject
{
public:
    GASLoadVarsLoaderCtorFunction(ASStringContext* psc); // exe 0x14291c1c0

    // LoadVars() on a LoadVars instance returns it, null otherwise (exe 0x14295afb0).
    static void GlobalCtor(const FnCall& fn);

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936e10
};

// The TextField.StyleSheet class.
class StyleSheetCtorFunction : public CFunctionObject
{
public:
    StyleSheetCtorFunction(ASStringContext* psc); // exe 0x142921110

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937380

    static void GlobalCtor(const FnCall& fn); // exe 0x14295c930
};

// The TextField class: the static TextField.getFontList.
class TextFieldCtorFunction : public CFunctionObject
{
public:
    TextFieldCtorFunction(ASStringContext* psc); // exe 0x142921480

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429373c0

    static void GlobalCtor(const FnCall& fn); // exe 0x14295ca00

    static const NameFunction StaticFunctionTable[]; // exe 0x143212f60: getFontList
};

// The TextFormat class.
class TextFormatCtorFunction : public CFunctionObject
{
public:
    TextFormatCtorFunction(ASStringContext* psc); // exe 0x142922650

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937470

    static void GlobalCtor(const FnCall& fn); // exe 0x14295ca10
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
    AmpMarkerCtorFunction(ASStringContext* psc); // exe 0x142917bf0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936790

    // exe 0x142982af0 / 0x14294bd90
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);

    static const NameFunction StaticFunctionTable[]; // exe 0x143214230: addMarker

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

private:
    static void GetFocus(const FnCall& fn);      // exe 0x1428ffcd0
    static void SetFocus(const FnCall& fn);      // exe 0x1428ffe30
    static void SetSelection(const FnCall& fn);  // exe 0x1429000d0
    static void GetCaretIndex(const FnCall& fn); // exe 0x142900260
    static void GetBeginIndex(const FnCall& fn); // exe 0x1429003c0
    static void GetEndIndex(const FnCall& fn);   // exe 0x142900530
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
    BooleanCtorFunction(ASStringContext* psc); // exe 0x142919980

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429369b0

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
    BitmapDataCtorFunction(ASStringContext* psc); // exe 0x142919060

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936930

    static const NameFunction StaticFunctionTable[]; // exe 0x1432134d0: loadBitmap

    // BitmapData() called as a function: a new empty bitmap (exe 0x142959160).
    static void GlobalCtor(const FnCall& fn);
};

// The MovieClipLoader class.
class MovieClipLoaderCtorFunction : public CFunctionObject
{
public:
    MovieClipLoaderCtorFunction(ASStringContext* psc); // exe 0x14291ed40

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936ff0

    // MovieClipLoader() on a loader instance makes it its own listener and returns it, null otherwise
    // (exe 0x14295bca0).
    static void GlobalCtor(const FnCall& fn);
};

// The AsBroadcaster class.
class AsBroadcasterCtorFunction : public CFunctionObject
{
public:
    AsBroadcasterCtorFunction(ASStringContext* psc); // exe 0x1429184e0

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429367e0

    static const NameFunction StaticFunctionTable[]; // exe 0x143213a30: initialize

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
