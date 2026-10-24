// Recovered Scaleform 4.1.18 GFx AS2: instance classes of the built-in script classes whose methods are not
// recovered yet. Only the sizes are known (from the Prototype<> layouts in the exe); move a class into its own
// header and name its members when its methods are recovered.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_BUILTINOBJECTS_H
#define MS2_SF_GFX_AS2_BUILTINOBJECTS_H

#include "as2_object.h"
#include "as2_objectproto.h"
#include "as2_action.h"         // (sfr24) ASBuiltinType
#include "../gfx_interactiveobject.h"   // (sfr24) FocusMovedType
#include "../gfx_asutils.h"
#include "../gfx_textsnapshot.h"
#include "../../kernel/sf_stringhash.h"
#include "../gfx_sharedobject.h"

namespace Scaleform { namespace Render { namespace Text { class TextFormat; class ParagraphFormat; } } }
namespace Scaleform { namespace Render { namespace Text { struct HighlightInfo; } } }   // (appended, sfr24)
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

    // Next value of the movie's random generator (exe 0x142953f50).
    static UInt32 GetNextRandom(MovieImpl* proot);
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

    // (appended for sfr_as2_06) queues the focus change for the action queue (exe 0x142972490).
    static void QueueSetFocus(Environment* penv, InteractiveObject* pnewFocus, unsigned controllerIdx,
                              FocusMovedType fmt);
    // Broadcasts onSetFocus to the Selection listeners (exe 0x1429326a0).
    static void BroadcastOnSetFocus(Environment* penv, InteractiveObject* pold, InteractiveObject* pnew,
                                    unsigned controllerIdx);

protected:
    void commonInit(Environment* penv); // exe 0x142995100
    // ASnative focus transfer: (character, FocusMovedType, controller) to MovieImpl::TransferFocus (exe 0x1429390a0).
    static void DoTransferFocus(const FnCall& fn);
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
    // (sfr24) Calls toString / valueOf on a primitive boolean through the prototype (exe 0x142964710).
    static bool InvokePrimitiveMethod(const FnCall& fnCall, const ASString& methodName);

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

    // The prototype instance has no button.
    ButtonObject(ASStringContext* psc, Object* pprototype) : Object(psc) { Set__proto__(psc, pprototype); }
    inline ButtonObject(Environment* penv); // defined in sfr_as2_04
    // The AS object of a button character (AvmButton::GetButtonASObject, defined in sfr_as2_05d).
    inline ButtonObject(GlobalContext* pgc, InteractiveObject* pbutton);

    virtual ObjectType GetObjectType() const; // exe 0x1429541e0: Object_ButtonASObject
    virtual InteractiveObject*       GetASCharacter();       // exe 0x1429490c0
    virtual const InteractiveObject* GetASCharacter() const; // exe 0x142949140

protected:
    virtual void Finalize_GC(); // exe 0x142942d20
};

// Button.prototype: the methods and useHandCursor = true.
class ButtonProto : public Prototype<ButtonObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432135f0

    ButtonProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142919c00
};
class ColorObject : public Object
{
public:
    WeakPtr<InteractiveObject> pCharacter; // +0x68

    ColorObject(Environment* penv, InteractiveObject* ptarget); // exe 0x14291ad30
    // The prototype instance has no target.
    ColorObject(ASStringContext* psc, Object* pprototype) : Object(psc) { Set__proto__(psc, pprototype); }

    virtual ObjectType GetObjectType() const; // exe 0x142954200: Object_Color

    void SetTarget(InteractiveObject* ptarget) { pCharacter = ptarget; }

protected:
    virtual void Finalize_GC(); // exe 0x142942d60
};

// Color.prototype.
class ColorProto : public Prototype<ColorObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432136c0

    ColorProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291adc0

    static void GetRGB(const FnCall& fn);       // exe 0x1428ed450
    static void SetRGB(const FnCall& fn);       // exe 0x1428ed2a0
    static void GetTransform(const FnCall& fn); // exe 0x1428eccf0
    static void SetTransform(const FnCall& fn); // exe 0x1428ec780
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
    // The prototype instance tracks nothing.
    MovieClipLoader(ASStringContext* psc, Object* pprototype) : Object(psc) { Set__proto__(psc, pprototype); }

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

// MovieClipLoader.prototype.
class MovieClipLoaderProto : public Prototype<MovieClipLoader>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432134f0

    MovieClipLoaderProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291edc0

    static void GetProgress(const FnCall& fn); // exe 0x1428eb050
    static void LoadClip(const FnCall& fn);    // exe 0x1428eb340
    static void UnloadClip(const FnCall& fn);  // exe 0x1428eb6d0
};

// 0x78 bytes.
class BitmapData : public Object
{
public:
    BitmapData(Environment* penv); // exe 0x142918ef0
    // The prototype instance has no image.
    inline BitmapData(ASStringContext* psc, Object* pprototype); // defined in sfr_as2_03 (needs the complete ImageResource)
    virtual ~BitmapData(); // inline, defined in sfr_as2_03 (needs the complete ImageResource)

    virtual ObjectType GetObjectType() const; // exe 0x1429541a0: Object_BitmapData
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x1429854f0
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x14294dbe0

    Ptr<ImageResource> pImageRes; // +0x68
    Ptr<MovieDef>      pMovieDef; // +0x70 keeps the image heap of the movie alive

    void SetImage(Environment* penv, ImageResource* pimg, MovieDef* pmovieDef);
    // (sfr24) A BitmapData of the image exported under linkageId (BitmapData.loadBitmap; the name is the
    // Windows LoadBitmap macro's) (exe 0x142966480).
    static BitmapData* LoadBitmapA(Environment* penv, const String& linkageId);

protected:
    virtual void Finalize_GC(); // exe 0x142942ca0

private:
    // Prototype and the read-only width / height members, unset until an image is set (exe 0x142994e90).
    void commonInit(Environment* penv);
};

// BitmapData.prototype.
class BitmapDataProto : public Prototype<BitmapData>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432134b0

    BitmapDataProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142919100
};
class LoadVarsObject : public Object
{
public:
    LoadVarsObject(Environment* penv); // exe 0x14291dda0

    virtual ObjectType GetObjectType() const; // exe 0x142954270: Object_LoadVars
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x142986440
    // The prototype instance: nothing loaded.
    LoadVarsObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        Set__proto__(psc, pprototype);
        BytesLoaded = -1;
        BytesTotal  = -1;
    }

    Number BytesLoaded; // +0x68 -1 before a load
    Number BytesTotal;  // +0x70
    // Load completion callbacks broadcast one argument to the object's listeners.
    void NotifyOnData(Environment* penv, ASString& data);
    void NotifyOnHTTPStatus(Environment* penv, double status);
    void NotifyOnLoad(Environment* penv, bool success);
};

// LoadVars.prototype: the methods and the default onData handler.
class LoadVarsProto : public Prototype<LoadVarsObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143212f80

    LoadVarsProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291df80

    // onData(src): decode src into the members and call onLoad (exe 0x1429381f0).
    static void DefaultOnData(const FnCall& fn);
    // Decodes the url-encoded name=value pairs of data into members of pobj (exe 0x1429670e0).
    static bool LoadVariables(Environment* penv, ObjectInterface* pobj, const String& data);

    static void AddRequestHeader(const FnCall& fn); // exe 0x1428ec0b0
    static void Decode(const FnCall& fn);           // exe 0x1428ec130
    static void GetBytesLoaded(const FnCall& fn);   // exe 0x1428ec290
    static void GetBytesTotal(const FnCall& fn);    // exe 0x1428ec330
    static void Load(const FnCall& fn);             // exe 0x1428ec3d0
    static void Send(const FnCall& fn);             // exe 0x1428ec510
    static void SendAndLoad(const FnCall& fn);      // exe 0x1428ec590
    static void ToString(const FnCall& fn);         // exe 0x1428ec610
};
class MovieClipObject : public Object
{
public:
    WeakPtr<Sprite> pSprite;           // +0x68
    UInt16          ButtonEventMask;   // +0x70 button events with a handler set on the clip
    bool            HasButtonHandlers; // +0x72

    // The prototype instance has no sprite.
    inline MovieClipObject(ASStringContext* psc, Object* pprototype); // defined in sfr_as2_03
    inline MovieClipObject(Environment* penv);                        // defined in sfr_as2_04
    // A clip's own object, with its prototype (defined in sfr_as2_05).
    inline MovieClipObject(GlobalContext* pgc, Sprite* psprite);

    virtual ObjectType GetObjectType() const; // exe 0x1429542a0: Object_MovieClipObject

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

// MovieClip.prototype: the methods and useHandCursor = true.
class MovieClipProto : public Prototype<MovieClipObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213ef0

    MovieClipProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291eee0

private:
    // MovieClipObject::SetMemberRaw, inlined (defined in sfr_as2_03).
    inline bool SetClipMemberRaw(ASStringContext* psc, const ASString& name, const Value& val, const PropFlags& flags);
};
class NumberObject : public Object
{
public:
    Number   NumberValue; // +0x68
    StringLH StringValue; // +0x70 text of the last ToString

    NumberObject(Environment* penv);           // exe 0x14291f430: 0
    NumberObject(Environment* penv, Number v); // exe 0x14291f4b0
    // The prototype instance holds 0.
    NumberObject(ASStringContext* psc, Object* pprototype) : Object(psc), NumberValue(0) { Set__proto__(psc, pprototype); }

    virtual ObjectType GetObjectType() const; // exe 0x1429542b0: Object_Number
    virtual Value      GetValue() const;      // exe 0x142956c90: NumberValue
    // (sfr24) Calls toString / valueOf on a primitive number through the prototype (exe 0x142964950).
    static bool InvokePrimitiveMethod(const FnCall& fnCall, const ASString& methodName);

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
    // The prototype instance, no name.
    SharedObject(ASStringContext* psc, Object* pprototype) : Object(psc) { Set__proto__(psc, pprototype); }

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
    // (appended for sfr_as2_04)
    // Bytes of the names and values under "data", 4 per number (exe 0x142935580).
    UPInt ComputeSizeInBytes(Environment* penv);
    // (appended for sfr_as2_02)
    // Visits the "data" object into the writer (exe 0x142945b20).
    void Flush(Environment* penv, SharedObjectVisitor* pwriter);
};

// SharedObject.prototype (no methods).
class SharedObjectProto : public Prototype<SharedObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213e40 (empty)

    SharedObjectProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142920830

    // (appended for sfr_as2_02)
    static void Flush(const FnCall& fn); // exe 0x142901150
    static void Clear(const FnCall& fn); // exe 0x142900fc0
    static void GetSize(const FnCall& fn); // exe 0x142901280
};

// The out-of-line Resize / PushBack of the loader's object stack (exe COMDATs the exe calls where cl inlines them).
void ObjectPtrArray_Resize(Array<Object*>* parray, UPInt newSize);            // exe 0x14297e230
void ObjectPtrArray_PushBack(Array<Object*>* parray, Object* const& pobj);     // exe 0x142971a50

// Rebuilds a shared object's data from the visits of the shared object manager. 0x40 bytes.
class GASSharedObjectLoader : public SharedObjectVisitor
{
public:
    // (appended for sfr_as2_02) built on the stack by getLocal; pdata is not referenced.
    GASSharedObjectLoader(Environment* penv, Object* pdata) : pEnv(penv), pData(pdata), bArrayIsTop(false) {}

    // Starts from the data object alone on the stack (exe 0x142932010).
    virtual void Begin();
    virtual void PushObject(const String& name);                                               // exe 0x142972190
    virtual void PushArray(const String& name);                                                // exe 0x1429718b0
    virtual void AddProperty(const String& name, const String& value, GFx::Value::ValueType type); // exe 0x142930480
    virtual void PopObject();                                                                  // exe 0x14296f260
    virtual void PopArray();                                                                   // exe 0x14296f0c0
    virtual void End() {}

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
    // (appended, sfr24) copies st into the field's own IME styles (allocated on first use). 0x142981750
    void SetIMECompositionStringStyles(const GFx::Text::IMEStyle& st);

    virtual InteractiveObject*       GetASCharacter();       // exe 0x1429492c0
    virtual const InteractiveObject* GetASCharacter() const; // exe 0x142949340
    virtual ~TextFieldObject(); // exe 0x142925f10
    virtual ObjectType               GetObjectType() const;  // exe 0x142954340: Object_TextField

protected:
    friend class TextFieldCtorFunction;
    friend class AvmTextField; // GetTextFieldASObject
    template<class BaseClass, class GASEnvironment> friend class Prototype;
    TextFieldObject(ASStringContext* psc, Object* pprototype); // exe 0x142921520
    TextFieldObject(Environment* penv);                        // exe 0x142921580
    TextFieldObject(GlobalContext* gCtxt, InteractiveObject* ptextField); // exe 0x1429215f0

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
    // The prototype instance: an empty snapshot.
    TextSnapshotObject(ASStringContext* psc, Object* pprototype) : Object(psc)
    {
        ::new (Data68) StaticTextSnapshotData();
        Set__proto__(psc, pprototype);
    }

    virtual ObjectType GetObjectType() const; // exe 0x142954360: Object_TextSnapshot

    StaticTextSnapshotData& GetData() { return *(StaticTextSnapshotData*)Data68; }
    void SetSelectColor(const Render::Color& color) { GetData().SetSelectColor(color); }

protected:
    virtual ~TextSnapshotObject(); // exe 0x142925f70
    virtual void Finalize_GC(); // exe 0x142943130
};

// TextSnapshot.prototype.
class TextSnapshotProto : public Prototype<TextSnapshotObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143214250

    TextSnapshotProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142923250

    static void FindTextA(const FnCall& fn);
    static void GetCount(const FnCall& fn);
    static void GetSelected(const FnCall& fn);
    static void GetSelectedText(const FnCall& fn);
    static void GetText(const FnCall& fn);
    static void SetSelectColor(const FnCall& fn);
    static void SetSelected(const FnCall& fn);
    // (appended for sfr_as2_02)
    static void GetTextRunInfo(const FnCall& fn);     // exe 0x142908840
    static void HitTestTextNearPos(const FnCall& fn); // exe 0x142908a70
};

// The TextSnapshot class: it has no global constructor (snapshots come from MovieClip.getTextSnapshot).
class TextSnapshotCtorFunction : public CFunctionObject
{
public:
    TextSnapshotCtorFunction(ASStringContext* psc); // exe 0x1429231b0

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "TextSnapshot" (exe 0x14297bf80).
    static FunctionRef Register(GlobalContext* pgc);
};

// (appended for sfr_as2_02) Appends an info object per visited glyph to an array (TextSnapshot.getTextRunInfo).
// 0x80 bytes.
class ArrayObject;
class GASTextSnapshotGlyphVisitor : public StaticTextSnapshotData::GlyphVisitor
{
public:
    GASTextSnapshotGlyphVisitor(Environment* penv, ArrayObject* parray) : pEnv(penv), pArray(parray) {}

    virtual void OnVisit(); // exe 0x14296d330

    Environment* pEnv;   // +0x68
    ArrayObject* pArray; // +0x70
};

// 0x98 bytes.
class StyleSheetObject : public Object
{
public:
    StyleSheetObject(Environment* penv); // exe 0x142921190
    // The prototype instance: an empty style manager (exe 0x142921270 builds it inline in StyleSheetProto's ctor).
    StyleSheetObject(ASStringContext* psc, Object* pprototype);
    // Completes a stylesheet load and notifies its listeners (exe 0x142969aa0).
    void NotifyOnLoad(Environment* penv, bool success);
    virtual ObjectType GetObjectType() const; // exe 0x142954330: Object_StyleSheet

    void* Data68[6]; // +0x68 not recovered (a Text::StyleManager)

protected:
    // (appended for sfr_as2_05) destroys the style manager (exe 0x142942ff0).
    virtual void Finalize_GC();
};

// TextField.prototype IME natives (the rest of the class is not modeled yet).
class TextFieldProto : public Prototype<TextFieldObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143214410: getDepth ...

    TextFieldProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142921710

    static void SetIMECompositionStringStyle(const FnCall& fn); // exe 0x1428eb900
    static void GetIMECompositionStringStyle(const FnCall& fn); // exe 0x1428ebbd0

private:
    // (appended, sfr24) a highlight style from argument index of fn (an AS object), over base. 0x14296e9f0
    static Render::Text::HighlightInfo ParseStyle(const FnCall& fn, unsigned index,
                                                  const Render::Text::HighlightInfo& base);
    // (appended, sfr24) fn's result: an AS object describing info. 0x142968610
    static void MakeStyle(const FnCall& fn, const Render::Text::HighlightInfo& info);
};

// StyleSheet.prototype: the CSS methods working on the style manager at +0x68.
class StyleSheetProto : public Prototype<StyleSheetObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213880

    StyleSheetProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142921270
    static void Clear(const FnCall& fn);         // exe 0x1428f86b0
    static void GetStyle(const FnCall& fn);      // exe 0x1428f8720
    static void GetStyleNames(const FnCall& fn); // exe 0x1428f9630
    static void Load(const FnCall& fn);          // exe 0x1428f99f0
    static void ParseCSS(const FnCall& fn);      // exe 0x1428f9ba0
    static void SetStyle(const FnCall& fn);      // exe 0x1428f9cf0
    static void Transform(const FnCall& fn);     // exe 0x1428fa620
};

// 0xd0 bytes.
class TextFormatObject : public Object
{
public:
    TextFormatObject(Environment* penv); // exe 0x1429226d0
    // The prototype instance: empty formats (exe 0x142923030 builds it inline in TextFormatProto's ctor).
    TextFormatObject(ASStringContext* psc, Object* pprototype);
    virtual ~TextFormatObject();
    virtual ObjectType GetObjectType() const; // exe 0x142954350: Object_TextFormat
    // The AS properties write through to the format (exe 0x142987710).
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());

    void* Data68[13]; // +0x68 Render::Text::TextFormat (0x48 bytes), +0xb0 Render::Text::ParagraphFormat (0x20 bytes)

    Render::Text::TextFormat&      GetTextFormat()      { return *(Render::Text::TextFormat*)Data68; }
    Render::Text::ParagraphFormat& GetParagraphFormat() { return *(Render::Text::ParagraphFormat*)(Data68 + 9); }

    // (appended for sfr_as2_02) the AS properties from a format.
    void SetTextFormat(ASStringContext* psc, const Render::Text::TextFormat& textFmt);           // exe 0x14298c090
    void SetParagraphFormat(ASStringContext* psc, const Render::Text::ParagraphFormat& paraFmt); // exe 0x142989480

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
    // The prototype instance has no target.
    TransformObject(ASStringContext* psc, Object* pprototype) : Object(psc), pMovieRoot(0)
    {
        Set__proto__(psc, pprototype);
    }

    virtual ObjectType GetObjectType() const; // exe 0x142954370: Object_Transform
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags()); // exe 0x142988380
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val); // exe 0x1429505d0

    // The character the transform reads and writes, 0 for none (exe 0x14298ba60).
    void SetTarget(InteractiveObject* pcharacter);

protected:
    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const; // exe 0x142941280
    virtual void Finalize_GC(); // exe 0x142943150

    template<class Functor> void ForEachChild_GC(Collector* prcc) const; // defined in sfr_as2_02
};

// Transform.prototype: no methods, the properties as undefined members.
class TransformProto : public Prototype<TransformObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432134a0 (empty)

    TransformProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x1429234f0
};

// Receiver of the mouse events of a movie (MovieRoot); vftable { dtor, OnMouseMove, OnMouseDown, OnMouseUp,
// OnMouseWheel, IsEmpty }.
class MouseListener
{
public:
    virtual ~MouseListener() {}
    // (appended for sfr_as2_06)
    virtual void OnMouseMove(Environment* penv, unsigned mouseIndex) const = 0;
    virtual void OnMouseDown(Environment* penv, unsigned mouseIndex, unsigned button, InteractiveObject* ptarget) const = 0;
    virtual void OnMouseUp(Environment* penv, unsigned mouseIndex, unsigned button, InteractiveObject* ptarget) const = 0;
    virtual void OnMouseWheel(Environment* penv, unsigned mouseIndex, int sdelta, InteractiveObject* ptarget) const = 0;
    virtual bool IsEmpty() const = 0;
};

class ArrayObject;

// The Mouse class (constructor function holding the listeners). 0xb0 bytes (Register 0x142978a90 allocates 0xb0).
class MouseCtorFunction : public CFunctionObject, public MouseListener
{
public:
    Ptr<ArrayObject> pListenersArray;   // +0x78
    mutable SInt32   LastMousePos[2];   // +0x80 (the double-click test of OnMouseDown)
    mutable UInt32   LastClickTime;     // +0x88
    FunctionRef      SetCursorTypeFunc; // +0x90
    // (appended, sfr24) +0xa8: the allocation's last 8 bytes; neither the ctor nor any method touches them.
    bool             MouseExtensions;   // +0xa8

    // Asks the user event handler for cursor shape cursorType on mouse mouseIndex; false without a handler
    // (exe 0x142980380).
    static bool SetCursorType(MovieImpl* proot, unsigned mouseIndex, unsigned cursorType);
    // Mouse.setCursorType was replaced by a script function (exe 0x14295da50).
    bool HasOverloadedCursorTypeFunction(ASStringContext* psc) const;

protected:
    // Mouse.setCursorType(shape[, mouse]) (exe 0x142980240).
    static void SetCursorType(const FnCall& fn);

    // Mouse() called as a function: null (exe 0x14295bc20).
    static void GlobalCtor(const FnCall& fn);

    template<class Functor> void ForEachChild_GC(Collector* prcc) const; // defined in sfr_as2_02

    // Mouse.show / Mouse.hide([mouse]): requests to the user event handler.
    static void Show(const FnCall& fn);
    static void Hide(const FnCall& fn);
    // Mouse.getButtonsState([mouse]) / Mouse.getPosition([mouse]) (pixels, as a Point) (exe 0x142949c00,
    // 0x142954380).
    static void GetButtonsState(const FnCall& fn);
    static void GetPosition(const FnCall& fn);    // Mouse.getTopMostEntity([testAll[, mouse]]) / ([mouse]) / (x, y[, testAll]): the topmost interactive object
    // under the mouse or a _level0 point (exe 0x142956760).
    static void GetTopMostEntity(const FnCall& fn);

public:
    // Extension members (setCursorType, the button and cursor constants, getTopMostEntity, getPosition,
    // getButtonsState) when extensions are on (exe 0x14294f4f0).
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);

    // (appended for sfr_as2_03/06) Makes the class a broadcaster and the movie's mouse listener; the static
    // functions and the original setCursorType (exe 0x14291e940).
    MouseCtorFunction(ASStringContext* psc, MovieRoot* proot);
    static const NameFunction StaticFunctionTable[]; // exe 0x143213d60: show, hide, ...
    // Creates the class and its prototype and publishes "Mouse" (exe 0x142978a90).
    static FunctionRef Register(GlobalContext* pgc);
protected:
    // pListenersArray from the _listeners member (exe 0x142992a20).
    void UpdateListenersArray(ASStringContext* psc, Environment* penv);
public:

    // (appended for sfr_as2_06) MouseListener: onMouseMove / onMouseDown / onMouseUp / onMouseWheel to the
    // listeners (exe 0x14296cb80, 0x14296c220, 0x14296cbf0, 0x14296cd30); IsEmpty: a listener array without
    // listeners (exe 0x1429654e0).
    virtual bool IsEmpty() const;
protected:
    virtual void OnMouseMove(Environment* penv, unsigned mouseIndex) const;
    virtual void OnMouseDown(Environment* penv, unsigned mouseIndex, unsigned button, InteractiveObject* ptarget) const;
    virtual void OnMouseUp(Environment* penv, unsigned mouseIndex, unsigned button, InteractiveObject* ptarget) const;
    virtual void OnMouseWheel(Environment* penv, unsigned mouseIndex, int sdelta, InteractiveObject* ptarget) const;

private:
    // Calls the event method of each listener with the arguments of PushListenersParams.
    class LocalInvokeCallback : public AsBroadcaster::InvokeCallback
    {
    public:
        unsigned        MouseIndex;  // +0x08
        ASBuiltinType   EventName;   // +0x0c
        const ASString* pTargetName; // +0x10
        unsigned        Button;      // +0x18
        int             Delta;       // +0x1c
        bool            DblClick;    // +0x20

        LocalInvokeCallback(unsigned mouseIndex, ASBuiltinType eventName, const ASString* ptargetName,
                            unsigned button, int delta, bool dblClick)
            : MouseIndex(mouseIndex), EventName(eventName), pTargetName(ptargetName), Button(button),
              Delta(delta), DblClick(dblClick) {}

        virtual void Invoke(Environment* penv, ObjectInterface* pthis, const FunctionRef& method); // exe 0x142963400
    };

    // Broadcasts eventName to the listeners (exe 0x142969450).
    void NotifyListeners(Environment* penv, unsigned mouseIndex, ASBuiltinType eventName,
                         const ASString* ptargetName = 0, unsigned button = 0, int delta = 0,
                         bool dblClick = false) const;
    // Pushes the arguments of the event for method (extensions: mouse index, position, double click, target and
    // button); the count, or -1 when the extended button event must not reach method (exe 0x142971d70).
    static int PushListenersParams(Environment* penv, unsigned mouseIndex, ASBuiltinType eventName,
                                   const Value& method, const ASString* ptargetName, unsigned button, int delta,
                                   bool dblClick);

public:
    // (appended for the vftable) Mouse cannot be instantiated (exe 0x142936f20). setCursorType records a script
    // replacement in the movie; _listeners refreshes pListenersArray (exe 0x1429864e0).
    virtual Object* CreateNewObject(Environment*) const { return 0; }
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
protected:
    virtual void ExecuteForEachChild_GC(Collector* prcc, OperationGC operation) const; // exe 0x1429411c0
    virtual void Finalize_GC(); // exe 0x142942dc0
};
static_assert(sizeof(MouseCtorFunction) == 0xb0, "MouseCtorFunction size");

// Value of the SharedObject lookup: a pointer that the collector visits. 0x10 bytes, vftable { dtor, Finalize_GC }.
class SharedObjectPtr : public Ptr<SharedObject>
{
public:
    // (appended for sfr_as2_02)
    SharedObjectPtr() {}
    SharedObjectPtr(SharedObject* pobj) : Ptr<SharedObject>(pobj) {}

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

private:
    // (appended for sfr_as2_02)
    // getLocal(name[, localPath]): the cached shared object, else a new one loaded by the manager (exe 0x142901410).
    static void GetLocal(const FnCall& fn);

public:
    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "SharedObject" (exe 0x14297a4a0).
    static FunctionRef Register(GlobalContext* pgc);
};

// The LoadVars class.
class GASLoadVarsLoaderCtorFunction : public CFunctionObject
{
public:
    GASLoadVarsLoaderCtorFunction(ASStringContext* psc); // exe 0x14291c1c0

    // LoadVars() on a LoadVars instance returns it, null otherwise (exe 0x14295afb0).
    static void GlobalCtor(const FnCall& fn);

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936e10

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "LoadVars" (exe 0x142977ad0).
    static FunctionRef Register(GlobalContext* pgc);
};

// The TextField.StyleSheet class.
class StyleSheetCtorFunction : public CFunctionObject
{
public:
    StyleSheetCtorFunction(ASStringContext* psc); // exe 0x142921110

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937380

    static void GlobalCtor(const FnCall& fn); // exe 0x14295c930
    // (appended, sfr24) Creates the class and publishes it as TextField.StyleSheet (exe 0x14297b190).
    static FunctionRef Register(GlobalContext* pgc);
};

// The TextField class: the static TextField.getFontList.
class TextFieldCtorFunction : public CFunctionObject
{
public:
    TextFieldCtorFunction(ASStringContext* psc); // exe 0x142921480

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429373c0

    static void GlobalCtor(const FnCall& fn); // exe 0x14295ca00

    static const NameFunction StaticFunctionTable[]; // exe 0x143212f60: getFontList

    // (appended, sfr24) Creates the class, publishes "TextField" and registers TextField.StyleSheet for first use
    // (exe 0x14297b6b0).
    static FunctionRef Register(GlobalContext* pgc);
};

// The TextFormat prototype natives (appended for sfr_as2_02b).
class TextFormatProto : public Prototype<TextFormatObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x143213ac0

    TextFormatProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x142923030

    static void GetTextExtent(const FnCall& fn); // exe 0x1429006a0
};

// The TextFormat class.
class TextFormatCtorFunction : public CFunctionObject
{
public:
    TextFormatCtorFunction(ASStringContext* psc); // exe 0x142922650

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142937470

    static void GlobalCtor(const FnCall& fn); // exe 0x14295ca10
    // (appended, sfr24) Creates the class and its prototype and publishes "TextFormat" (exe 0x14297ba70).
    static FunctionRef Register(GlobalContext* pgc);
};

// The flash.geom.Transform class.
class TransformCtorFunction : public CFunctionObject
{
public:
    // (appended for sfr_as2_06) Inlined into Register in the exe.
    TransformCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429374b0
    // (appended for sfr_as2_06) new Transform(target) / Transform(target) for the movie clip target; undefined
    // without one (exe 0x14295d1c0).
    static void GlobalCtor(const FnCall& fn);

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Transform" (exe 0x14297c400).
    static FunctionRef Register(GlobalContext* pgc);
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

public:
    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Amp" (exe 0x142973080).
    static FunctionRef Register(GlobalContext* pgc);
};

// Classes with nothing to construct: called as a function they return null (ExternalInterface undefined).
class ExternalInterfaceCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936cf0
    static void GlobalCtor(const FnCall& fn); // exe 0x14295ae20 undefined
    // "available": an ExternalInterface handler is installed (exe 0x14294f140).
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);
    // (appended for sfr_as2_02)
    static void Call(const FnCall& fn); // exe 0x1428ffa20
    static void AddCallback(const FnCall& fn); // exe 0x1428ff660
    // (appended for sfr_as2_06) "available" and the static functions (exe 0x14291bc40).
    ExternalInterfaceCtorFunction(ASStringContext* psc);
    static const NameFunction StaticFunctionTable[]; // exe 0x143213d90: addCallback, call

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "ExternalInterface" (exe 0x1429775b0).
    static FunctionRef Register(GlobalContext* pgc);
};
class MathCtorFunction : public CFunctionObject
{
public:
    static void GlobalCtor(const FnCall& fn); // exe 0x14295bc00

    // (appended for sfr_as2_06) The constants E, LN2, ..., SQRT2 and the static functions (exe 0x14291e210).
    MathCtorFunction(ASStringContext* psc);
    static const NameFunction StaticFunctionTable[]; // exe 0x143213900: abs, acos, ...
    // Creates the class and its prototype and publishes "Math" (exe 0x142978780).
    static FunctionRef Register(GlobalContext* pgc);

    // (appended for the vftable) Math cannot be instantiated (exe 0x142936f10).
    virtual Object* CreateNewObject(Environment*) const { return 0; }

private:
    // The Math functions (exe 0x1428fb110-0x1428fbb70).
    static void Abs(const FnCall& fn);
    static void Acos(const FnCall& fn);
    static void Asin(const FnCall& fn);
    static void Atan(const FnCall& fn);
    static void Ceil(const FnCall& fn);
    static void Cos(const FnCall& fn);
    static void Exp(const FnCall& fn);
    static void Floor(const FnCall& fn);
    static void Log(const FnCall& fn);
    static void Sin(const FnCall& fn);
    static void Sqrt(const FnCall& fn);
    static void Tan(const FnCall& fn);
    static void Atan2(const FnCall& fn);
    static void Max(const FnCall& fn);
    static void Min(const FnCall& fn);
    static void Pow(const FnCall& fn);
    static void Random(const FnCall& fn);
    static void Round(const FnCall& fn);
};
class SelectionCtorFunction : public CFunctionObject
{
public:
    // A broadcaster with the static methods (exe 0x142920540).
    SelectionCtorFunction(ASStringContext* psc);

    // Selection cannot be instantiated (exe 0x142937230).
    virtual Object* CreateNewObject(Environment*) const { return 0; }
    // The focus properties (disableFocusRectangle, alwaysEnableArrowKeys, modalClip, ...) go to the movie
    // (exe 0x142987090, 0x14294fc20).
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);

    static void GlobalCtor(const FnCall& fn); // exe 0x14295c650

    static const NameFunction StaticFunctionTable[]; // exe 0x143213dc0

private:
    static void GetFocus(const FnCall& fn);      // exe 0x1428ffcd0
    static void SetFocus(const FnCall& fn);      // exe 0x1428ffe30
    static void SetSelection(const FnCall& fn);  // exe 0x1429000d0
    static void GetCaretIndex(const FnCall& fn); // exe 0x142900260
    static void GetBeginIndex(const FnCall& fn); // exe 0x1429003c0
    static void GetEndIndex(const FnCall& fn);   // exe 0x142900530
    // (appended for sfr_as2_05)
    static void GetControllerFocusGroup(const FnCall& fn);       // exe 0x14294a1e0
    static void GetControllerMaskByFocusGroup(const FnCall& fn); // exe 0x14294a2b0
    static void GetFocusBitmask(const FnCall& fn);               // exe 0x14294adf0
    static void GetFocusArray(const FnCall& fn);                 // exe 0x14294ab70
    static void GetModalClip(const FnCall& fn);                  // exe 0x142953cc0
    static void CaptureFocus(const FnCall& fn);                  // exe 0x142932ab0
    static void MoveFocus(const FnCall& fn);                     // exe 0x1429689e0
    static void FindFocus(const FnCall& fn);                     // exe 0x142943ce0
    static void SetModalClip(const FnCall& fn);                  // exe 0x142989060
    static void SetControllerFocusGroup(const FnCall& fn);       // exe 0x142980120

public:
    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Selection" (exe 0x142979fe0).
    static FunctionRef Register(GlobalContext* pgc);
};
class StageCtorFunction : public CFunctionObject
{
public:
    StageCtorFunction(ASStringContext* psc, MovieImpl* pmovie); // exe 0x142920950
    static void GlobalCtor(const FnCall& fn); // exe 0x14295c6f0

    // Extension members visibleRect, safeRect (the visible rect when unset) and originalRect, as new Rectangle
    // objects (exe 0x142950300).
    virtual bool GetMember(Environment* penv, const ASString& name, Value* val);
    // width and height of the visible stage (pixels), scaleMode and align of the view (exe 0x142953520).
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);
    // width and height are read-only (exe 0x142988f30).
    virtual bool SetMemberRaw(ASStringContext* psc, const ASString& name, const Value& val,
                              const PropFlags& flags = PropFlags());
    // scaleMode and align set the view of the movie (exe 0x1429872b0).
    virtual bool SetMember(Environment* penv, const ASString& name, const Value& val,
                           const PropFlags& flags = PropFlags());

    // (appended for sfr_as2_06) broadcasts onResize, with the visible rect as a Rectangle when the extensions are
    // on (exe 0x14296a540).
    void NotifyOnResize(Environment* penv);
    // Stage.onResize notification of the movie fn runs in (exe 0x14296a7c0).
    static void NotifyOnResize(const FnCall& fn);

    MovieImpl* pMovieRoot; // +0x70 the movie of the stage

    // (appended, sfr24) Creates the class and its prototype and publishes "Stage" (exe 0x14297a960).
    static FunctionRef Register(GlobalContext* pgc);

private:
    // A Rectangle object for rect (pixels) (exe 0x142937bc0).
    static Value CreateRectangleObject(Environment* penv, const Render::RectF& rect);
};

// The Boolean class.
class BooleanCtorFunction : public CFunctionObject
{
public:
    BooleanCtorFunction(ASStringContext* psc); // exe 0x142919980

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429369b0

    // new Boolean(v) stores v in the instance, Boolean(v) converts v (exe 0x1429595a0).
    static void GlobalCtor(const FnCall& fn);

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Boolean" (exe 0x1429752b0).
    static FunctionRef Register(GlobalContext* pgc);
};

// Number.prototype.
class NumberProto : public Prototype<NumberObject>
{
public:
    static const NameFunction FunctionTable[]; // exe 0x1432141a0

    NumberProto(ASStringContext* psc, Object* pprototype, const FunctionRef& constructor); // exe 0x14291f540
};

// The Number class.
class NumberCtorFunction : public CFunctionObject
{
public:
    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x1429370c0
    // new Number(v) stores v in the instance, Number(v) converts v (exe 0x14295bd30).
    static void GlobalCtor(const FnCall& fn);
    // (appended for sfr_as2_06) The constants MAX_VALUE, MIN_VALUE, NaN, ... as members (exe 0x14291f2c0).
    NumberCtorFunction(ASStringContext* psc);
    // A constant member of Number and the function computing it.
    struct NameConstFunction
    {
        const char* Name;
        Double      (SF_CDECL *Function)();
    };
    static const NameConstFunction ConstTable[]; // exe 0x1432141d0

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Number" (exe 0x142979260).
    static FunctionRef Register(GlobalContext* pgc);
};

// The Color class.
class ColorCtorFunction : public CFunctionObject
{
public:
    // (appended for sfr_as2_06) Inlined into Register in the exe.
    ColorCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936b10
    // Color(target) as a constructor retargets the instance, as a function makes a new one (exe 0x142959740).
    static void GlobalCtor(const FnCall& fn);

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Color" (exe 0x142975f30).
    static FunctionRef Register(GlobalContext* pgc);
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
    // loadBitmap(linkageId) (exe 0x1428f1e70).
    static void LoadBitmapA(const FnCall& fn);

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "BitmapData" (exe 0x142974460).
    static FunctionRef Register(GlobalContext* pgc);
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

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "MovieClipLoader" (exe 0x142978dd0).
    static FunctionRef Register(GlobalContext* pgc);
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

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "AsBroadcaster" (exe 0x142973a80).
    static FunctionRef Register(GlobalContext* pgc);

private:
    // AsBroadcaster.initialize(obj) (exe 0x1428fc080).
    static void Initialize(const FnCall& fn);
};

// The Button class.
class ButtonCtorFunction : public CFunctionObject
{
public:
    // (appended for sfr_as2_06) Inlined into Register in the exe.
    ButtonCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936a50
    // (appended for sfr_as2_06) Button() does nothing (exe 0x142959730, folded with other empty functions).
    static void GlobalCtor(const FnCall&) {}

    // (appended for sfr_as2_06) Creates the class and its prototype and publishes "Button" (exe 0x142975740).
    static FunctionRef Register(GlobalContext* pgc);
};

// The MovieClip class.
class MovieClipCtorFunction : public CFunctionObject
{
public:
    // (appended, sfr24) Inlined into GlobalContext::Init in the exe.
    MovieClipCtorFunction(ASStringContext* psc) : CFunctionObject(psc, GlobalCtor) {}

    virtual Object* CreateNewObject(Environment* penv) const; // exe 0x142936f30
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

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::AS2::BitmapData) == 0x78, "BitmapData size");
static_assert(sizeof(Scaleform::GFx::AS2::ColorObject) == 0x70, "ColorObject size");
static_assert(sizeof(Scaleform::GFx::AS2::MathCtorFunction) == 0x70, "MathCtorFunction size");
static_assert(sizeof(Scaleform::GFx::AS2::MovieClipLoader) == 0x70, "MovieClipLoader size");
static_assert(sizeof(Scaleform::GFx::AS2::SharedObject) == 0x78, "SharedObject size");
static_assert(sizeof(Scaleform::GFx::AS2::StageCtorFunction) == 0x78, "StageCtorFunction size");
static_assert(sizeof(Scaleform::GFx::AS2::StyleSheetObject) == 0x98, "StyleSheetObject size");
static_assert(sizeof(Scaleform::GFx::AS2::TextFormatObject) == 0xd0, "TextFormatObject size");
static_assert(sizeof(Scaleform::GFx::AS2::TransformObject) == 0x90, "TransformObject size");

#endif
