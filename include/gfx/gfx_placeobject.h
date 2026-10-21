// Recovered Scaleform 4.1.18 GFx: CharPosInfo (where and how a display object is placed on a timeline) and the
// PlaceObject tags that carry it. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_GFX_PLACEOBJECT_H
#define MS2_SF_GFX_PLACEOBJECT_H

#include "gfx_displayobjcontainer.h"
#include "gfx_loadproc.h"
#include "../render/render_constants.h"
#include "../render/render_cxform.h"
#include "../render/render_filters.h"
#include "../render/render_matrix2x4.h"

namespace Scaleform { namespace GFx {

using Render::Cxform;
using Render::Matrix2F;

// Which of the CharPosInfo fields a PlaceObject tag sets.
struct CharPosInfoFlags
{
    enum
    {
        Flags_HasDepth       = 0x001,
        Flags_HasCharacterId = 0x002,
        Flags_HasMatrix      = 0x004,
        Flags_HasCxform      = 0x008,
        Flags_HasRatio       = 0x010,
        Flags_HasFilters     = 0x020,
        Flags_HasClipDepth   = 0x040,
        Flags_HasBlendMode   = 0x080,
        Flags_HasClassName   = 0x100
    };

    UInt16 Flags;

    CharPosInfoFlags() : Flags(0) {}
    CharPosInfoFlags(UInt16 flags) : Flags(flags) {}

    void SetMatrixFlag()    { Flags |= Flags_HasMatrix; }
    void SetCxFormFlag()    { Flags |= Flags_HasCxform; }
    void SetBlendModeFlag() { Flags |= Flags_HasBlendMode; }
    // (appended for the place tags, sfr_gfx_05)
    void SetDepthFlag()       { Flags |= Flags_HasDepth; }
    void SetCharacterIdFlag() { Flags |= Flags_HasCharacterId; }
    void SetRatioFlag()       { Flags |= Flags_HasRatio; }
    void SetFiltersFlag()     { Flags |= Flags_HasFilters; }
    void SetClipDepthFlag()   { Flags |= Flags_HasClipDepth; }
    void SetClassNameFlag()   { Flags |= Flags_HasClassName; }

    bool HasMatrix() const      { return (Flags & Flags_HasMatrix) != 0; }
    bool HasCxform() const      { return (Flags & Flags_HasCxform) != 0; }
    bool HasBlendMode() const   { return (Flags & Flags_HasBlendMode) != 0; }
    bool HasFilters() const     { return (Flags & Flags_HasFilters) != 0; }
    bool HasDepth() const       { return (Flags & Flags_HasDepth) != 0; }
    bool HasClipDepth() const   { return (Flags & Flags_HasClipDepth) != 0; }
    bool HasRatio() const       { return (Flags & Flags_HasRatio) != 0; }
    bool HasCharacterId() const { return (Flags & Flags_HasCharacterId) != 0; }
    bool HasClassName() const   { return (Flags & Flags_HasClassName) != 0; }
};

// Placement of a display object (0x70 bytes; the assignment is exe 0x1425cc5d0).
class CharPosInfo
{
public:
    Cxform                 ColorTransform; // +0
    Matrix2F               Matrix_1;       // +0x20
    Ptr<Render::FilterSet> pFilters;       // +0x40
    float                  Ratio;          // +0x48
    int                    Depth;          // +0x4c
    ResourceId             CharacterId;    // +0x50
    const char*            ClassName;      // +0x58 PlaceObject3 class name
    UInt16                 ClipDepth;      // +0x60
    CharPosInfoFlags       Flags;          // +0x62
    UByte                  BlendMode;      // +0x64

    CharPosInfo()
    {
        Ratio     = 0.0f;
        Depth     = 0;
        ClipDepth = 0;
        BlendMode = Render::Blend_None;
        ClassName = 0;
    }
    CharPosInfo(ResourceId chId, int depth, bool hasCxform, const Cxform& cxform, bool hasMatrix,
                const Matrix2F& matrix, const char* className = 0, float ratio = 0.0f, UInt16 clipDepth = 0,
                bool hasBlendMode = false, Render::BlendMode blend = Render::Blend_None)
        : ColorTransform(cxform), Matrix_1(matrix), CharacterId(chId)
    {
        Ratio = ratio;
        if (hasMatrix)
            Flags.SetMatrixFlag();
        if (hasCxform)
            Flags.SetCxFormFlag();
        if (hasBlendMode)
            Flags.SetBlendModeFlag();
        Depth       = depth;
        CharacterId = chId;
        ClipDepth   = clipDepth;
        BlendMode   = (UByte)blend;
        ClassName   = className;
    }

    bool HasMatrix() const { return Flags.HasMatrix(); }
    bool HasCxform() const { return Flags.HasCxform(); }
};

class SwfEvent;

// A PlaceObject tag of any SWF version; Unpack gives the placement in one form.
// No vftable of its own in the exe (the derived constructors overwrite the pointer): novtable keeps it out of the
// objects.
class __declspec(novtable) GFxPlaceObjectBase : public ExecuteTag
{
public:
    typedef ArrayLH<SwfEvent*, StatMD_Tags_Mem> EventArrayType;

    enum PlaceActionType
    {
        Place_Add     = 0x00,
        Place_Move    = 0x01,
        Place_Replace = 0x02
    };

    struct UnpackedData
    {
        CharPosInfo      Pos;
        EventArrayType*  pEventHandlers;
        const char*      Name;
        PlaceActionType  PlaceType;
    };

    virtual void             Unpack(UnpackedData& data) = 0;
    virtual EventArrayType*  UnpackEventHandlers() { return 0; }
    virtual CharPosInfoFlags GetFlags() const = 0;
    virtual void             Trace(const char* str) = 0;
    virtual void             Execute(DisplayObjContainer* m) = 0;
};

// A placement kept unpacked; the image movies place their shape with it (0x80 bytes, vftable 0x14318b6b0).
class GFxPlaceObjectUnpacked : public GFxPlaceObjectBase
{
    GFxPlaceObjectUnpacked(const GFxPlaceObjectUnpacked&);
    GFxPlaceObjectUnpacked& operator=(const GFxPlaceObjectUnpacked&);

public:
    CharPosInfo Pos; // +0x10

    GFxPlaceObjectUnpacked(); // exe 0x1425ca910
    ~GFxPlaceObjectUnpacked() {}

    void Unpack(GFxPlaceObjectBase::UnpackedData& data)
    {
        data.Name           = 0;
        data.pEventHandlers = 0;
        data.PlaceType      = GFxPlaceObjectBase::Place_Add;
        data.Pos            = Pos;
    }
    CharPosInfoFlags GetFlags() const { return Pos.Flags; }

    virtual void Execute(DisplayObjContainer* m);                              // exe 0x1425d7180
    void         AddToTimelineSnapshot(TimelineSnapshot*, unsigned frame);     // exe 0x1425d5a80
    virtual void Trace(const char* str);                                       // exe 0x1425d89e0

    void InitializeToAdd(const CharPosInfo& posInfo) { Pos = posInfo; }
};

// (appended for the place tags, sfr_gfx_05) the packed PlaceObject tags: the tag data stays in the SWF layout and
// Unpack decodes it on use. Bodies: GFx_SpriteDef (sfr_gfx_05).

// SWF 1 PlaceObject (vftable 0x14318bab0).
class PlaceObjectTag : public GFxPlaceObjectBase
{
    PlaceObjectTag(const PlaceObjectTag&);
    PlaceObjectTag& operator=(const PlaceObjectTag&);

public:
    bool  HasCxForm; // +8 the color transform is optional
    UByte pData[1];  // +9 character id, depth, matrix, [cxform]

    PlaceObjectTag();
    ~PlaceObjectTag();

    static UPInt ComputeDataSize(Stream* pin);
    void         CheckForCxForm(UPInt dataSz);

    void             Unpack(GFxPlaceObjectBase::UnpackedData& data);
    CharPosInfoFlags GetFlags() const;

    virtual void Execute(DisplayObjContainer* m);
    void         AddToTimelineSnapshot(TimelineSnapshot*, unsigned frame);
    virtual void Trace(const char* str);

protected:
    UInt16 GetDepth() const;
};

// PlaceObject2 of SWF 3 and later; when the flags byte has PO2_HasActions, the event handler array pointer follows it.
class PlaceObject2Tag : public GFxPlaceObjectBase
{
    PlaceObject2Tag(const PlaceObject2Tag&);
    PlaceObject2Tag& operator=(const PlaceObject2Tag&);

public:
    enum PlaceObject2Flags
    {
        PO2_HasActions     = 0x80,
        PO2_HasClipBracket = 0x40,
        PO2_HasName        = 0x20,
        PO2_HasRatio       = 0x10,
        PO2_HasCxform      = 0x08,
        PO2_HasMatrix      = 0x04,
        PO2_HasChar        = 0x02,
        PO2_FlagMove       = 0x01
    };

    UByte pData[1]; // +8

    PlaceObject2Tag() {}
    ~PlaceObject2Tag();

    static bool            HasEventHandlers(Stream* pin);
    // Moves the flags byte to the front and clears the event handler pointer after it.
    static void            RestructureForEventHandlers(UByte* pdata);
    static EventArrayType* GetEventHandlersPtr(const UByte* pdata);
    static void            SetEventHandlersPtr(UByte* pdata, EventArrayType* peh);

    static UPInt ComputeDataSize(Stream* pin, unsigned movieVersion);

    virtual void     Unpack(GFxPlaceObjectBase::UnpackedData& data) { UnpackBase(data, 6); }
    EventArrayType*  UnpackEventHandlers();
    CharPosInfoFlags GetFlags() const;

    virtual void Execute(DisplayObjContainer* m) { ExecuteBase(m, 6); }
    void         AddToTimelineSnapshot(TimelineSnapshot* snapshot, unsigned frame);
    virtual void Trace(const char* str) { TraceBase(str, 6); }

protected:
    UInt16          GetDepth() const;
    PlaceActionType GetPlaceType() const;

    void ExecuteBase(DisplayObjContainer* m, UByte version);
    void TraceBase(const char* str, UByte version);
    void UnpackBase(GFxPlaceObjectBase::UnpackedData& data, UByte version);

    // The AVM tags build the event handler array.
    virtual void ProcessEventHandlers(UnpackedData& data, StreamContext& sc, const UByte* prawdata, UByte version) {}
};

// PlaceObject3 of SWF 8: a second flags byte, class name, filters, blend mode.
class PlaceObject3Tag : public GFxPlaceObjectBase
{
    PlaceObject3Tag(const PlaceObject3Tag&);
    PlaceObject3Tag& operator=(const PlaceObject3Tag&);

public:
    enum PlaceObject3Flags
    {
        PO3_HasImage      = 0x10,
        PO3_HasClassName  = 0x08,
        PO3_BitmapCaching = 0x04,
        PO3_HasBlendMode  = 0x02,
        PO3_HasFilters    = 0x01
    };

    UByte pData[1]; // +8

    PlaceObject3Tag() {}
    ~PlaceObject3Tag();

    static UPInt ComputeDataSize(Stream* pin);

    void             Unpack(GFxPlaceObjectBase::UnpackedData& data);
    EventArrayType*  UnpackEventHandlers();
    CharPosInfoFlags GetFlags() const;

    virtual void Execute(DisplayObjContainer* m);
    void         AddToTimelineSnapshot(TimelineSnapshot*, unsigned frame);
    virtual void Trace(const char* str);

protected:
    virtual void ProcessEventHandlers(UnpackedData& data, StreamContext& sc, const UByte* prawdata) {}

    UInt16          GetDepth() const;
    PlaceActionType GetPlaceType() const;
};

class RemoveObject2Tag : public ExecuteTag
{
public:
    UInt16 Depth; // +8

    virtual void Read(LoadProcess* p);
    virtual void Execute(DisplayObjContainer* m);
    virtual bool IsRemoveTag() const { return true; }
    virtual void AddToTimelineSnapshot(TimelineSnapshot*, unsigned frame);
    void         Trace(const char* str);

protected:
    // pse points at the snapshot element pointer; the AVM tags clear it to keep an element whose clip has an
    // unload handler.
    virtual void CheckEventHandlers(void** pse, GFxPlaceObjectBase::EventArrayType* pevts) {}
};

class RemoveObjectTag : public RemoveObject2Tag
{
public:
    UInt16 Id; // +0x10

    virtual void Read(LoadProcess* p);
    virtual void Execute(DisplayObjContainer* m);
    void         Trace(const char* str);
};

class SetBackgroundColorTag : public ExecuteTag
{
public:
    Render::Color Color; // +8

    void Execute(DisplayObjContainer* m);
    void Read(LoadProcess* p);
};

}} // namespace Scaleform::GFx

#endif
