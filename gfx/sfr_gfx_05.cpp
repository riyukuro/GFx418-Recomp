// Recovered Scaleform 4.1.18 GFx_SpriteDef: the movie clip definition (DefineSprite), the timeline snapshot that a
// frame jump builds out of the place / remove tags, and the packed PlaceObject / RemoveObject / SetBackgroundColor
// tags themselves.
// Scaleform GFx 4.1.18, recovered from the exe; the SDK sources served only as a reference.
// MS2-UNIT: sfr_gfx_05
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425d51d0-0x1425d96d0 .text$mn
//
// The tail 0x1425d96d0-0x1425d9760 opens the GFx_Sprite unit (sfr_gfx_05b).
#include "../include/gfx/gfx_spritedef.h"
#include "../include/gfx/gfx_timelinesnapshot.h"
#include "../include/gfx/gfx_placeobject.h"
#include "../include/gfx/gfx_loadproc.h"
#include "../include/gfx/gfx_moviedef.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/gfx_sound.h"
#include "../include/gfx/gfx_log.h"
#include "../include/gfx/gfx_asstring.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/render/render_color.h"
#include "../include/render/render_filters.h"
#include "../include/kernel/sf_alg.h"

// MS2-PIN: ??_7SpriteDef@GFx@Scaleform@@6B@ 0x14318bb08
// MS2-PIN: ??_7PlaceObjectTag@GFx@Scaleform@@6B@ 0x14318bab0
// MS2-PIN: ??_7TimelineIODef@GFx@Scaleform@@6B@ 0x14318ba08
// MS2-PIN: ??_7ExecuteTag@GFx@Scaleform@@6B@ 0x14313ba68
// MS2-PIN: ??_7Resource@GFx@Scaleform@@6B@ 0x143149880

namespace Scaleform { namespace GFx {

// Filter list reader of the SWF 8 records (GFx_FilterDesc, sfr_gfx_08b).
template<class S>
unsigned LoadFilters(S* ps, Render::FilterSet* filters);

// The display list flag of objects placed by a tag.
enum { DisplayList_Flags_PlaceObject = 4 };

// MovieImpl: the background set by the SetBackgroundColor tag wins over later ones; its virtuals are not recovered
// (GetBackgroundAlpha is vftable slot 33, SetBackgroundColor slot 31).
enum { MovieImpl_Flag_BackgroundSetByTag = 0x20000 };
typedef float (*MovieImpl_GetBackgroundAlphaFn)(MovieImpl*);
typedef void (*MovieImpl_SetBackgroundColorFn)(MovieImpl*, const Render::Color);

static inline bool IsBackgroundSetByTag(const MovieImpl* pmroot)
{
    return ((pmroot->Flags >> 17) & 1) != 0;
}

static inline int IRound(float v)
{
    return (int)(v > 0 ? v + 0.5 : v - 0.5);
}

//
// ***** SpriteDef
//

// @0x1425d5300
PlaceObjectTag::PlaceObjectTag() : HasCxForm(false)
{
}

// @0x1425d5320
SpriteDef::SpriteDef(MovieDataDef* pmd)
    : pMovieDef(pmd), FrameCount(0), LoadingFrame(0), pScale9Grid(0), Flags(0)
{
}

// @0x1425d53d0
PlaceObject2Tag::~PlaceObject2Tag()
{
}

// @0x1425d53e0
PlaceObject3Tag::~PlaceObject3Tag()
{
}

// @0x1425d53f0
PlaceObjectTag::~PlaceObjectTag()
{
}

// @0x1425d5400
SpriteDef::~SpriteDef()
{
    // The tag memory belongs to the movie data; only the destructors run here.
    for (unsigned i = 0; i < Playlist.GetSize(); i++)
        Playlist[i].DestroyTags();
    delete pScale9Grid;
}

//
// ***** TimelineSnapshot
//

// @0x1425d5610
TimelineSnapshot::SnapshotElement* TimelineSnapshot::Add(int depth)
{
    SnapshotElement* pe = SnapshotHeap.Alloc();
    if (pe)
    {
        SnapshotList.PushBack(pe);
        pe->Depth = depth;

        UPInt i = Alg::UpperBound(SnapshotSortedArray, depth, DepthLess);
        SnapshotSortedArray.InsertAt(i, pe);
        return pe;
    }
    return 0;
}

// @0x1425d5790
void SpriteDef::AddFrameName(const String& name, LogState* plog)
{
    unsigned currentlyAssigned = 0;
    if (NamedFrames.GetAlt(name, &currentlyAssigned) == true)
    {
        if (plog)
            plog->LogError("AddFrameName(%d, '%s') -- frame name already assigned to frame %d; overriding",
                           LoadingFrame, name.ToCStr(), currentlyAssigned);
    }
    // The button state labels.
    if (name.GetLength() > 0 && name.ToCStr()[0] == '_')
    {
        if (name == "_up")
            Flags |= Flags_Has_Frame_up;
        else if (name == "_down")
            Flags |= Flags_Has_Frame_down;
        else if (name == "_over")
            Flags |= Flags_Has_Frame_over;
    }
    NamedFrames.Set(name, LoadingFrame);
}

// @0x1425d5a80
void GFxPlaceObjectUnpacked::AddToTimelineSnapshot(TimelineSnapshot* psnapshot, unsigned frame)
{
    Trace("\n");
    TimelineSnapshot::SnapshotElement* pse = psnapshot->FindDepth(Pos.Depth);
    // An element removed in this run already stays as it is; a new one follows it.
    if (pse && pse->Flags & TimelineSnapshot::Flags_DeadOnArrival)
        pse = 0;
    if (!pse)
    {
        pse = psnapshot->Add(Pos.Depth);
        pse->Tags.Assign(this);
        pse->PlaceType   = (UByte)TimelineSnapshot::Place_Add;
        pse->CreateFrame = frame;
    }
    else
    {
        pse->Tags.Assign(this);
        pse->CreateFrame = frame;
    }
    pse->Flags |= TimelineSnapshot::Flags_NoReplaceAllowed;
}

// @0x1425d5b90
void PlaceObject2Tag::AddToTimelineSnapshot(TimelineSnapshot* psnapshot, unsigned frame)
{
    Trace("\n");
    UInt16 depth     = GetDepth();
    UByte  placeType = (UByte)GetPlaceType();
    TimelineSnapshot::SnapshotElement* pse = psnapshot->FindDepth(depth);
    if (pse && pse->Flags & TimelineSnapshot::Flags_DeadOnArrival)
        pse = 0;

    if (!pse)
    {
        pse = psnapshot->Add(depth);
        pse->PlaceType   = placeType;
        pse->Tags.Assign(this);
        pse->CreateFrame = frame;
    }
    else
    {
        switch (placeType)
        {
        case Place_Move:
            pse->Tags.Union(this);
            break;
        case Place_Replace:
            if (pse->PlaceType != TimelineSnapshot::Place_Add)
                pse->PlaceType = Place_Replace;
            pse->Tags.Union(this);
            pse->CreateFrame = frame;
            break;
        default:
            pse->Tags.Assign(this);
            pse->CreateFrame = frame;
        }
    }
}

// @0x1425d5e40
void PlaceObject3Tag::AddToTimelineSnapshot(TimelineSnapshot* psnapshot, unsigned frame)
{
    Trace("\n");
    UInt16 depth     = GetDepth();
    UByte  placeType = (UByte)GetPlaceType();
    TimelineSnapshot::SnapshotElement* pse = psnapshot->FindDepth(depth);
    if (pse && pse->Flags & TimelineSnapshot::Flags_DeadOnArrival)
        pse = 0;
    if (!pse)
    {
        pse = psnapshot->Add(depth);
        pse->PlaceType   = placeType;
        pse->Tags.Assign(this);
        pse->CreateFrame = frame;
    }
    else
    {
        switch (placeType)
        {
        case Place_Move:
            pse->Tags.Union(this);
            break;
        case Place_Replace:
            if (pse->PlaceType != TimelineSnapshot::Place_Add)
                pse->PlaceType = Place_Replace;
            pse->Tags.Union(this);
            pse->CreateFrame = frame;
            break;
        default:
            pse->Tags.Assign(this);
            pse->CreateFrame = frame;
        }
    }
}

// @0x1425d60f0
void PlaceObjectTag::AddToTimelineSnapshot(TimelineSnapshot* psnapshot, unsigned frame)
{
    Trace("\n");
    UInt16 depth = GetDepth();
    TimelineSnapshot::SnapshotElement* pse = psnapshot->FindDepth(depth);
    if (pse && pse->Flags & TimelineSnapshot::Flags_DeadOnArrival)
        pse = 0;
    if (!pse)
    {
        pse = psnapshot->Add(depth);
        pse->PlaceType   = (UByte)TimelineSnapshot::Place_Add;
        pse->Tags.Assign(this);
        pse->CreateFrame = frame;
    }
    else
    {
        pse->Tags.Assign(this);
        pse->CreateFrame = frame;
    }
    pse->Flags |= TimelineSnapshot::Flags_NoReplaceAllowed;
}

// @0x1425d6220
void RemoveObject2Tag::AddToTimelineSnapshot(TimelineSnapshot* psnapshot, unsigned)
{
    Trace("\n");
    UPInt index;
    TimelineSnapshot::SnapshotElement* pse = psnapshot->FindDepth(Depth, &index);
    // A move / replace collected in this run is dropped; the remove below takes its place.
    if (pse && pse->PlaceType != TimelineSnapshot::Place_Add)
    {
        psnapshot->RemoveAtIndex(index);
        pse = 0;
    }
    if (pse)
    {
        if (pse->Tags.HasMainTag() && psnapshot->Dir == TimelineSnapshot::Direction_Forward)
        {
            // Going forward, a clip with an unload handler is still created (and its handlers run) before it
            // goes: the AVM tag keeps such an element and marks it dead on arrival.
            GFxPlaceObjectBase::EventArrayType* pEventHandlers = pse->Tags.pMainTag->UnpackEventHandlers();
            if (pEventHandlers)
                CheckEventHandlers((void**)&pse, pEventHandlers);
        }
        if (pse)
            psnapshot->RemoveAtIndex(index);
    }
    if (!pse)
    {
        if (psnapshot->Dir == TimelineSnapshot::Direction_Forward)
        {
            pse            = psnapshot->Add(Depth);
            pse->Depth     = Depth;
            pse->PlaceType = TimelineSnapshot::Place_Remove;
            pse->Flags    |= TimelineSnapshot::Flags_DeadOnArrival;
        }
    }
}

//
// ***** PlaceObjectTag
//

// @0x1425d63c0
void PlaceObjectTag::CheckForCxForm(UPInt dataSz)
{
    StreamContext sc(pData);
    Matrix2F      mat;
    sc.Skip(4);
    sc.ReadMatrix(&mat);
    HasCxForm = (sc.CurByteIndex < (dataSz - 1));
}

// @0x1425d6460
// MS2-FUNCTIONAL: verbose parse logging only; register allocation of the inlined ReadU16 differs
UPInt PlaceObject2Tag::ComputeDataSize(Stream* pin, unsigned movieVersion)
{
    int tagStart = pin->Tell();
    int tagEnd   = pin->GetTagEndPosition();
    int len      = tagEnd - tagStart;

    if (pin->IsVerboseParse())
    {
        UByte  po2Flags = pin->ReadU8();
        UInt32 allFlags = 0;
        char*  pname    = 0;

        CharPosInfo pos;
        pos.Depth = pin->ReadU16();
        if (po2Flags & PO2_HasChar)
        {
            pos.Flags.SetCharacterIdFlag();
            pos.CharacterId = ResourceId(pin->ReadU16());
        }
        if (po2Flags & PO2_HasMatrix)
        {
            pos.Flags.SetMatrixFlag();
            pin->ReadMatrix(&pos.Matrix_1);
        }
        if (po2Flags & PO2_HasCxform)
        {
            pos.Flags.SetCxFormFlag();
            pin->ReadCxformRgba(&pos.ColorTransform);
        }
        if (po2Flags & PO2_HasRatio)
        {
            pos.Flags.SetRatioFlag();
            pos.Ratio = (float)pin->ReadU16() / (float)65535;
        }
        if (po2Flags & PO2_HasName)
            pname = pin->ReadString(pin->GetHeap());
        if (po2Flags & PO2_HasClipBracket)
        {
            pos.Flags.SetClipDepthFlag();
            pos.ClipDepth = pin->ReadU16();
        }
        if (po2Flags & PO2_HasActions)
        {
            pin->ReadU16(); // reserved
            // The union of the handler event flags: 32 bits from SWF 6 on.
            if (movieVersion >= 6)
                allFlags = pin->ReadU32();
            else
                allFlags = pin->ReadU16();
        }

        pin->SetPosition(tagStart);

        bool hasChar  = (po2Flags & PO2_HasChar) != 0;
        bool flagMove = (po2Flags & PO2_FlagMove) != 0;
        pin->LogParse("  depth = %d\n", pos.Depth);
        if (po2Flags & PO2_HasChar)
            pin->LogParse("  char id = %d\n", pos.CharacterId.GetIdIndex());
        if (po2Flags & PO2_HasMatrix)
        {
            pin->LogParse("  mat:\n");
            pin->LogParseClass(pos.Matrix_1);
        }
        if (po2Flags & PO2_HasCxform)
        {
            pin->LogParse("  cxform:\n");
            pin->LogParseClass(pos.ColorTransform);
        }
        if (po2Flags & PO2_HasRatio)
            pin->LogParse("  ratio: %f\n", pos.Ratio);
        if (po2Flags & PO2_HasName)
            pin->LogParse("  name = %s\n", pname ? pname : "<null>");
        if (po2Flags & PO2_HasClipBracket)
            pin->LogParse("  ClipDepth = %d\n", pos.ClipDepth);
        if (po2Flags & PO2_HasActions)
            pin->LogParse("  actions: flags = 0x%X\n", (unsigned)allFlags);
        if (hasChar && flagMove)
            pin->LogParse("    * (replace)\n");
        else if (!hasChar && flagMove)
            pin->LogParse("    * (move)\n");

        if (pname)
            SF_FREE(pname);

        pin->SetPosition(tagStart);
    }
    return (UPInt)len;
}

// @0x1425d6960
// MS2-FUNCTIONAL: verbose parse logging only; register allocation of the inlined ReadU16 differs
UPInt PlaceObject3Tag::ComputeDataSize(Stream* pin)
{
    int tagStart = pin->Tell();
    int tagEnd   = pin->GetTagEndPosition();
    int len      = tagEnd - tagStart;

    if (pin->IsVerboseParse())
    {
        UByte  po2Flags  = pin->ReadU8();
        UByte  po3Flags  = pin->ReadU8();
        UInt32 allFlags  = 0;
        char*  pname     = 0;
        char*  classname = 0;

        CharPosInfo pos;
        pos.Depth = pin->ReadU16();
        if (po3Flags & PO3_HasClassName)
        {
            pos.Flags.SetClassNameFlag();
            pos.ClassName = classname = pin->ReadString(pin->GetHeap());
        }
        if (po2Flags & PlaceObject2Tag::PO2_HasChar)
        {
            pos.Flags.SetCharacterIdFlag();
            pos.CharacterId = ResourceId(pin->ReadU16());
        }
        if (po2Flags & PlaceObject2Tag::PO2_HasMatrix)
        {
            pos.Flags.SetMatrixFlag();
            pin->ReadMatrix(&pos.Matrix_1);
        }
        if (po2Flags & PlaceObject2Tag::PO2_HasCxform)
        {
            pos.Flags.SetCxFormFlag();
            pin->ReadCxformRgba(&pos.ColorTransform);
        }
        if (po2Flags & PlaceObject2Tag::PO2_HasRatio)
        {
            pos.Flags.SetRatioFlag();
            pos.Ratio = (float)pin->ReadU16() / (float)65535;
        }
        if (po2Flags & PlaceObject2Tag::PO2_HasName)
            pname = pin->ReadString(pin->GetHeap());
        if (po2Flags & PlaceObject2Tag::PO2_HasClipBracket)
        {
            pos.Flags.SetClipDepthFlag();
            pos.ClipDepth = pin->ReadU16();
        }
        if (po3Flags & PO3_HasFilters)
        {
            pos.Flags.SetFiltersFlag();
            LoadFilters(pin, (Render::FilterSet*)0);
        }
        if (po3Flags & PO3_HasBlendMode)
        {
            UByte blendMode = pin->ReadU8();
            if ((blendMode < 1) || (blendMode > 14))
                blendMode = 1;
            pos.Flags.SetBlendModeFlag();
            pos.BlendMode = (UByte)blendMode;
        }
        if (po3Flags & PO3_BitmapCaching)
            pin->ReadU8();
        if (po2Flags & PlaceObject2Tag::PO2_HasActions)
        {
            pin->ReadU16(); // reserved
            allFlags = pin->ReadU32();
        }

        pin->SetPosition(tagStart);

        bool hasChar  = (po2Flags & PlaceObject2Tag::PO2_HasChar) != 0;
        bool flagMove = (po2Flags & PlaceObject2Tag::PO2_FlagMove) != 0;
        pin->LogParse("  depth = %d\n", pos.Depth);
        if (po2Flags & PlaceObject2Tag::PO2_HasChar)
            pin->LogParse("  char id = %d\n", pos.CharacterId.GetIdIndex());
        if (po3Flags & PO3_HasClassName)
            pin->LogParse("  classname = %s\n", pos.ClassName);
        if (po2Flags & PlaceObject2Tag::PO2_HasMatrix)
        {
            pin->LogParse("  mat:\n");
            pin->LogParseClass(pos.Matrix_1);
        }
        if (po2Flags & PlaceObject2Tag::PO2_HasCxform)
        {
            pin->LogParse("  cxform:\n");
            pin->LogParseClass(pos.ColorTransform);
        }
        if (po2Flags & PlaceObject2Tag::PO2_HasRatio)
            pin->LogParse("  ratio: %f\n", pos.Ratio);
        if (po2Flags & PlaceObject2Tag::PO2_HasName)
            pin->LogParse("  name = %s\n", pname ? pname : "<null>");
        if (po2Flags & PlaceObject2Tag::PO2_HasClipBracket)
            pin->LogParse("  ClipDepth = %d\n", pos.ClipDepth);
        if (po3Flags & PO3_HasBlendMode)
            pin->LogParse("  blend mode = %d\n", pos.BlendMode);
        if (po2Flags & PlaceObject2Tag::PO2_HasActions)
            pin->LogParse("  actions: flags = 0x%X\n", (unsigned)allFlags);
        if (hasChar && flagMove)
            pin->LogParse("    * (replace)\n");
        else if (!hasChar && flagMove)
            pin->LogParse("    * (move)\n");

        if (pname)
            SF_FREE(pname);
        if (classname)
            SF_FREE(classname);

        pin->SetPosition(tagStart);
    }
    return (UPInt)len;
}

// @0x1425d6f60
// MS2-FUNCTIONAL: verbose parse logging only; register allocation of the inlined ReadU16 differs
UPInt PlaceObjectTag::ComputeDataSize(Stream* pin)
{
    int tagStart = pin->Tell();
    int tagEnd   = pin->GetTagEndPosition();
    int len      = tagEnd - tagStart;

    if (pin->IsVerboseParse())
    {
        CharPosInfo pos;
        pos.CharacterId = ResourceId(pin->ReadU16());
        pos.Depth       = pin->ReadU16();
        pin->ReadMatrix(&pos.Matrix_1);
        pin->LogParse("  CharId = %d\n"
                      "  depth = %d\n"
                      "  mat = \n",
                      pos.CharacterId.GetIdIndex(), pos.Depth);
        pin->LogParseClass(pos.Matrix_1);
        if (pin->Tell() < pin->GetTagEndPosition())
        {
            pin->ReadCxformRgb(&pos.ColorTransform);
            pin->LogParse("  cxform:\n");
            pin->LogParseClass(pos.ColorTransform);
        }
        pin->SetPosition(tagStart);
    }
    return (UPInt)len;
}

// @0x1425d7160
bool SpriteDef::DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase* pinst) const
{
    return false;
}

// @0x1425d7180
void GFxPlaceObjectUnpacked::Execute(DisplayObjContainer* m)
{
    ASStringManager* psm = m->GetStringManager();
    ASString         sname(psm->GetEmptyStringNode());
    m->AddDisplayObject(Pos, sname, 0, 0, ~0u, DisplayList_Flags_PlaceObject, 0, 0);
}

// @0x1425d7200
void PlaceObject3Tag::Execute(DisplayObjContainer* m)
{
    GFxPlaceObjectBase::UnpackedData data;
    Unpack(data);
    switch (data.PlaceType)
    {
    case Place_Add:
        {
            ASStringManager* psm = m->GetStringManager();
            ASString sname((data.Name == 0) ? ASString(psm->GetEmptyStringNode())
                                            : ASString(psm->CreateStringNode(data.Name)));
            m->AddDisplayObject(data.Pos, sname, data.pEventHandlers, 0, ~0u, DisplayList_Flags_PlaceObject, 0, 0);
        }
        break;

    case Place_Move:
        m->MoveDisplayObject(data.Pos);
        break;

    case Place_Replace:
        {
            ASStringManager* psm = m->GetStringManager();
            ASString sname((data.Name == 0) ? ASString(psm->GetEmptyStringNode())
                                            : ASString(psm->CreateStringNode(data.Name)));
            DisplayObjectBase* newChar;
            m->CreateAndReplaceDisplayObject(data.Pos, sname, &newChar);
        }
        break;
    }
}

// @0x1425d7450
void PlaceObjectTag::Execute(DisplayObjContainer* m)
{
    GFxPlaceObjectBase::UnpackedData data;
    Unpack(data);
    ASStringManager* psm = m->GetStringManager();
    m->AddDisplayObject(data.Pos, ASString(psm->GetEmptyStringNode()), 0, 0, ~0u, DisplayList_Flags_PlaceObject, 0,
                        0);
}

// @0x1425d7590
void RemoveObject2Tag::Execute(DisplayObjContainer* m)
{
    m->RemoveDisplayObject(Depth, ResourceId());
}

// @0x1425d75c0
void RemoveObjectTag::Execute(DisplayObjContainer* m)
{
    m->RemoveDisplayObject(Depth, ResourceId(Id));
}

// @0x1425d75f0
void SetBackgroundColorTag::Execute(DisplayObjContainer* m)
{
    // Only the first tag sets the background (the one of _level0).
    MovieImpl* pmroot = m->GetMovieImpl();
    if (!IsBackgroundSetByTag(pmroot))
    {
        float alpha = ((MovieImpl_GetBackgroundAlphaFn)(*(void***)pmroot)[33])(pmroot);
        Color.SetAlpha(UByte(IRound(alpha * 255.0f)));
        ((MovieImpl_SetBackgroundColorFn)(*(void***)pmroot)[31])(pmroot, Color);
        pmroot->Flags |= MovieImpl_Flag_BackgroundSetByTag;
    }
}

// @0x1425d7680
void PlaceObject2Tag::ExecuteBase(DisplayObjContainer* m, UByte version)
{
    GFxPlaceObjectBase::UnpackedData data;
    UnpackBase(data, version);
    switch (data.PlaceType)
    {
    case Place_Add:
        {
            ASStringManager* psm = m->GetStringManager();
            ASString sname((data.Name == 0) ? ASString(psm->GetEmptyStringNode())
                                            : ASString(psm->CreateStringNode(data.Name)));
            m->AddDisplayObject(data.Pos, sname, data.pEventHandlers, 0, ~0u, DisplayList_Flags_PlaceObject, 0, 0);
        }
        break;

    case Place_Move:
        m->MoveDisplayObject(data.Pos);
        break;

    case Place_Replace:
        {
            ASStringManager* psm = m->GetStringManager();
            ASString sname((data.Name == 0) ? ASString(psm->GetEmptyStringNode())
                                            : ASString(psm->CreateStringNode(data.Name)));
            DisplayObjectBase* newChar;
            m->CreateAndReplaceDisplayObject(data.Pos, sname, &newChar);
        }
        break;
    }
}

// @0x1425d78a0
void TimelineSnapshot::ExecuteSnapshot(DisplayObjContainer* pdispObj)
{
    if (!SnapshotList.IsEmpty())
    {
        const SnapshotElement* pe;
        for (pe = SnapshotList.GetFirst();; pe = SnapshotList.GetNext(pe))
        {
            const SnapshotElement& e = *pe;
            switch (e.PlaceType)
            {
            case Place_Add:
                {
                    GFxPlaceObjectBase::UnpackedData data;
                    e.Tags.Unpack(data);

                    ASStringManager* psm = pdispObj->GetStringManager();
                    ASString sname((data.Name == 0) ? ASString(psm->GetEmptyStringNode())
                                                    : ASString(psm->CreateStringNode(data.Name)));
                    // The display list's dead-on-arrival flag has the snapshot's value.
                    pdispObj->AddDisplayObject(data.Pos, sname, data.pEventHandlers, 0, e.CreateFrame,
                                               DisplayList_Flags_PlaceObject | (e.Flags & Flags_DeadOnArrival), 0,
                                               0);
                }
                break;
            case Place_Move:
                {
                    GFxPlaceObjectBase::UnpackedData data;
                    e.Tags.Unpack(data);
                    pdispObj->MoveDisplayObject(data.Pos);
                }
                break;
            case Place_Replace:
                {
                    GFxPlaceObjectBase::UnpackedData data;
                    e.Tags.Unpack(data);

                    ASStringManager* psm = pdispObj->GetStringManager();
                    ASString sname((data.Name == 0) ? ASString(psm->GetEmptyStringNode())
                                                    : ASString(psm->CreateStringNode(data.Name)));
                    DisplayObjectBase* newChar;
                    pdispObj->CreateAndReplaceDisplayObject(data.Pos, sname, &newChar);
                }
                break;
            case Place_Remove:
                // The remove tags keep no character id.
                pdispObj->RemoveDisplayObject(e.Depth, ResourceId());
                break;
            }

            if (SnapshotList.IsLast(pe))
                break;
        }
    }
}

// @0x1425d7bf0
UInt16 PlaceObject2Tag::GetDepth() const
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    if (po2Flags & PO2_HasActions)
        sc.Skip(sizeof(GFxPlaceObjectBase::EventArrayType*));
    return sc.ReadU16();
}

// @0x1425d7c20
UInt16 PlaceObject3Tag::GetDepth() const
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    if (po2Flags & PlaceObject2Tag::PO2_HasActions)
        sc.Skip(sizeof(GFxPlaceObjectBase::EventArrayType*));
    sc.Skip(1);
    return sc.ReadU16();
}

// @0x1425d7c50
UInt16 PlaceObjectTag::GetDepth() const
{
    StreamContext sc(pData);
    sc.Skip(2);
    return sc.ReadU16();
}

// Inlined everywhere; the linker drops the copies.
GFxPlaceObjectBase::PlaceActionType PlaceObject2Tag::GetPlaceType() const
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    bool          hasChar  = (po2Flags & PO2_HasChar) != 0;
    bool          flagMove = (po2Flags & PO2_FlagMove) != 0;
    if (hasChar && flagMove)
        return Place_Replace;
    else if (!hasChar && flagMove)
        return Place_Move;
    return Place_Add;
}

GFxPlaceObjectBase::PlaceActionType PlaceObject3Tag::GetPlaceType() const
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    bool          hasChar  = (po2Flags & PlaceObject2Tag::PO2_HasChar) != 0;
    bool          flagMove = (po2Flags & PlaceObject2Tag::PO2_FlagMove) != 0;
    if (hasChar && flagMove)
        return Place_Replace;
    else if (!hasChar && flagMove)
        return Place_Move;
    return Place_Add;
}

// @0x1425d7c60
GFxPlaceObjectBase::EventArrayType* PlaceObject2Tag::GetEventHandlersPtr(const UByte* pdata)
{
    return *((GFxPlaceObjectBase::EventArrayType**)(pdata + 1));
}

// @0x1425d7ca0
CharPosInfoFlags PlaceObject2Tag::GetFlags() const
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    return (UInt16)(po2Flags & 0x5F);
}

// @0x1425d7cb0
CharPosInfoFlags PlaceObject3Tag::GetFlags() const
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    if (po2Flags & PlaceObject2Tag::PO2_HasActions)
        sc.Skip(sizeof(GFxPlaceObjectBase::EventArrayType*));
    UByte po3Flags = sc.ReadU8();
    return (UByte)((po2Flags & 0x5f) | ((po3Flags & PO3_HasFilters) << 5) | ((po3Flags & PO3_HasBlendMode) << 6));
}

// @0x1425d7cf0
CharPosInfoFlags PlaceObjectTag::GetFlags() const
{
    return (UByte)(CharPosInfoFlags::Flags_HasCharacterId | CharPosInfoFlags::Flags_HasDepth |
                   CharPosInfoFlags::Flags_HasMatrix | ((HasCxForm) ? CharPosInfoFlags::Flags_HasCxform : 0x0));
}

// @0x1425d7d30
Array<String>* SpriteDef::GetFrameLabels(unsigned frameNumber, Array<String>* destArr) const
{
    StringHashLH<unsigned>::ConstIterator it = NamedFrames.Begin();
    int i = 0;
    for (; it != NamedFrames.End(); ++it)
    {
        if (frameNumber == it->Second)
        {
            destArr->PushBack(it->First);
            ++i;
        }
    }
    return i ? destArr : 0;
}

// @0x1425d8060
bool PlaceObject2Tag::HasEventHandlers(Stream* pin)
{
    UByte po2Flags = pin->ReadU8();
    pin->SetPosition(pin->Tell() - 1);
    return (po2Flags & PO2_HasActions) != 0;
}

// @0x1425d80c0
void SpriteDef::InitEmptyClipDef()
{
    FrameCount = 1;
    Playlist.Resize(FrameCount);
}

// @0x1425d80e0
void TimelineSnapshot::MakeSnapshot(TimelineDef* pdef, unsigned startFrame, unsigned endFrame)
{
    for (unsigned f = startFrame; f <= endFrame; ++f)
    {
        const TimelineDef::Frame& playlist = pdef->GetPlaylist(f);
        for (unsigned i = 0; i < playlist.GetTagCount(); i++)
        {
            ExecuteTag* e = playlist.GetTag(i);
            e->AddToTimelineSnapshot(this, f);
        }
    }
}

// @0x1425d8170
void RemoveObject2Tag::Read(LoadProcess* p)
{
    Depth = p->ReadU16();
}

// @0x1425d8190
void RemoveObjectTag::Read(LoadProcess* p)
{
    Id    = p->ReadU16();
    Depth = p->ReadU16();
}

// @0x1425d81d0
void SetBackgroundColorTag::Read(LoadProcess* p)
{
    p->GetStream()->ReadRgb(&Color);
    p->LogParse("  SetBackgroundColor: (%d %d %d)\n", (int)Color.GetRed(), (int)Color.GetGreen(),
                (int)Color.GetBlue());
}

// @0x1425d8230
void SpriteDef::Read(LoadProcess* p, ResourceId charId)
{
    Stream* pin    = p->GetStream();
    UInt32  tagEnd = pin->GetTagEndPosition();

    p->EnterSpriteDef(this);

    FrameCount = pin->ReadU16();
    // Some files have sprites of 0 frames; the player treats them as 1.
    if (FrameCount < 1)
        FrameCount = 1;
    Playlist.Resize(FrameCount);

    pin->LogParse("  frames = %d\n", FrameCount);

    LoadingFrame = 0;

    while ((UInt32)pin->Tell() < tagEnd)
    {
        TagInfo                    tagInfo;
        TagType                    tagType = pin->OpenTag(&tagInfo);
        LoaderImpl::LoaderFunction lf      = 0;

        p->ReportProgress(p->GetFileURL(), tagInfo, true);

        if (tagType == Tag_EndFrame)
        {
            // The frame count in the header may be short.
            if (LoadingFrame == (int)Playlist.GetSize())
            {
                Playlist.Resize(Playlist.GetSize() + 1);
                pin->LogError("An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
                              (int)charId.GetIdIndex(), (int)FrameCount, (int)LoadingFrame + 1);
            }

            p->CommitFrameTags();

            pin->LogParse("  ShowFrame (sprite, char id = %d)\n", charId.GetIdIndex());
            LoadingFrame++;
        }
        else if (LoaderImpl::GetTagLoader(tagType, &lf))
        {
            (*lf)(p, tagInfo);
        }
        else
        {
            pin->LogParse("*** no tag loader for type %d\n", tagType);
        }

        pin->CloseTag();
    }

    // Tags after the last ShowFrame make one more frame.
    if (p->FrameTagsAvailable())
    {
        if (LoadingFrame == (int)Playlist.GetSize())
        {
            Playlist.Resize(Playlist.GetSize() + 1);
            pin->LogError("An extra frame is found for sprite id = %d, framecnt = %d, actual frames = %d",
                          (int)charId.GetIdIndex(), (int)FrameCount, (int)LoadingFrame + 1);
        }
        p->CommitFrameTags();
    }

    p->LeaveSpriteDef();

    pin->LogParse("  -- sprite END, char id = %d --\n", charId.GetIdIndex());
}

// @0x1425d8610
void TimelineSnapshot::Remove(int depth)
{
    UPInt            idx;
    SnapshotElement* pe = FindDepth(depth, &idx);
    if (pe)
    {
        SnapshotList.Remove(pe);
        SnapshotSortedArray.RemoveAt(idx);
        SnapshotHeap.Free(pe);
    }
}

// @0x1425d8960
void PlaceObject2Tag::RestructureForEventHandlers(UByte* pdata)
{
    // The flags byte moves to the front, the pointer after it starts out null.
    pdata[0] = pdata[sizeof(GFxPlaceObjectBase::EventArrayType*)];
    *((GFxPlaceObjectBase::EventArrayType**)(pdata + 1)) = 0;
}

// @0x1425d8970
void PlaceObject2Tag::SetEventHandlersPtr(UByte* pdata, EventArrayType* peh)
{
    *((GFxPlaceObjectBase::EventArrayType**)(pdata + 1)) = peh;
}

// @0x1425d89a0
void SpriteDef::SetSoundStream(SoundStreamDef* psoundStream)
{
    pSoundStream = psoundStream;
}

// The timeline trace output is compiled out.

// @0x1425d89e0
void GFxPlaceObjectUnpacked::Trace(const char* str)
{
}

// @0x1425d89f0
void PlaceObject3Tag::Trace(const char* str)
{
}

// @0x1425d8a00
void PlaceObjectTag::Trace(const char* str)
{
}

// @0x1425d8a10
void RemoveObject2Tag::Trace(const char* str)
{
}

// @0x1425d8a20
void RemoveObjectTag::Trace(const char* str)
{
}

// @0x1425d8a30
void PlaceObject2Tag::TraceBase(const char* str, UByte version)
{
}

// @0x1425d8a40
void PlaceObject3Tag::Unpack(GFxPlaceObjectBase::UnpackedData& data)
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    if (po2Flags & PlaceObject2Tag::PO2_HasActions)
        sc.Skip(sizeof(GFxPlaceObjectBase::EventArrayType*));
    UByte po3Flags = sc.ReadU8();
    data.Pos.Depth = sc.ReadU16();
    if (po3Flags & PO3_HasClassName)
    {
        data.Pos.Flags.SetClassNameFlag();
        sc.Align();
        data.Pos.ClassName = (const char*)pData + sc.CurByteIndex;
        while (sc.ReadU8() != 0)
        {
        }
    }
    if (po2Flags & PlaceObject2Tag::PO2_HasChar)
    {
        data.Pos.Flags.SetCharacterIdFlag();
        data.Pos.CharacterId = ResourceId(sc.ReadU16());
    }
    if (po2Flags & PlaceObject2Tag::PO2_HasMatrix)
    {
        data.Pos.Flags.SetMatrixFlag();
        sc.ReadMatrix(&data.Pos.Matrix_1);
    }
    if (po2Flags & PlaceObject2Tag::PO2_HasCxform)
    {
        data.Pos.Flags.SetCxFormFlag();
        sc.ReadCxformRgba(&data.Pos.ColorTransform);
    }
    if (po2Flags & PlaceObject2Tag::PO2_HasRatio)
    {
        data.Pos.Flags.SetRatioFlag();
        data.Pos.Ratio = (float)sc.ReadU16() / (float)65535;
    }
    if (po2Flags & PlaceObject2Tag::PO2_HasName)
    {
        sc.Align();
        data.Name = (const char*)pData + sc.CurByteIndex;
        while (sc.ReadU8() != 0)
        {
        }
    }
    else
        data.Name = 0;
    if (po2Flags & PlaceObject2Tag::PO2_HasClipBracket)
    {
        data.Pos.ClipDepth = sc.ReadU16();
        data.Pos.Flags.SetClipDepthFlag();
    }
    if (po3Flags & PO3_HasFilters)
    {
        data.Pos.Flags.SetFiltersFlag();
        Ptr<Render::FilterSet> filters = *SF_HEAP_NEW(Memory::GetGlobalHeap()) Render::FilterSet;
        if (LoadFilters(&sc, filters.GetPtr()))
            data.Pos.pFilters = filters;
    }
    if (po3Flags & PO3_HasBlendMode)
    {
        data.Pos.Flags.SetBlendModeFlag();
        UByte blendMode = sc.ReadU8();
        if ((blendMode < 1) || (blendMode > 14))
            blendMode = 1;
        data.Pos.BlendMode = (UByte)blendMode;
    }
    if (po3Flags & PO3_BitmapCaching)
        sc.ReadU8();
    if (po2Flags & PlaceObject2Tag::PO2_HasActions)
        ProcessEventHandlers(data, sc, pData);
    else
        data.pEventHandlers = 0;

    bool hasChar   = (po2Flags & PlaceObject2Tag::PO2_HasChar) != 0;
    bool flagMove  = (po2Flags & PlaceObject2Tag::PO2_FlagMove) != 0;
    data.PlaceType = Place_Add;
    if (hasChar && flagMove)
        data.PlaceType = Place_Replace; // whatever is at the depth goes
    else if (!hasChar && flagMove)
        data.PlaceType = Place_Move;
}

// @0x1425d8d80
void PlaceObjectTag::Unpack(GFxPlaceObjectBase::UnpackedData& data)
{
    StreamContext sc(pData);
    data.Name           = 0;
    data.pEventHandlers = 0;
    data.PlaceType      = Place_Add;
    data.Pos.Flags.SetCharacterIdFlag();
    data.Pos.CharacterId = ResourceId(sc.ReadU16());
    data.Pos.Flags.SetDepthFlag();
    data.Pos.Depth = sc.ReadU16();
    data.Pos.Flags.SetMatrixFlag();
    sc.ReadMatrix(&data.Pos.Matrix_1);
    if (HasCxForm)
    {
        data.Pos.Flags.SetCxFormFlag();
        sc.ReadCxformRgb(&data.Pos.ColorTransform);
    }
}

// @0x1425d8e30
void TimelineSnapshot::SourceTags::Unpack(GFxPlaceObjectBase::UnpackedData& data) const
{
    pMainTag->Unpack(data);

    // The other tags' properties, each tag unpacked once: depth, character id, matrix, class name, cxform, blend
    // mode, clip depth, ratio, filters.
    GFxPlaceObjectBase::UnpackedData unpackedData[9];

    UPInt dataIdx;
    if (pDepthTag != pMainTag)
    {
        pDepthTag->Unpack(unpackedData[0]);
        data.Pos.Depth = unpackedData[0].Pos.Depth;
        data.Pos.Flags.SetDepthFlag();
    }
    if (pCharIdTag != pMainTag)
    {
        if (pDepthTag == pCharIdTag)
            dataIdx = 0;
        else
        {
            pCharIdTag->Unpack(unpackedData[1]);
            dataIdx = 1;
        }
        data.Pos.CharacterId = unpackedData[dataIdx].Pos.CharacterId;
        data.Pos.Flags.SetCharacterIdFlag();
    }
    if (pMatrixTag != pMainTag)
    {
        if (pDepthTag == pMatrixTag)
            dataIdx = 0;
        else if (pCharIdTag == pMatrixTag)
            dataIdx = 1;
        else
        {
            pMatrixTag->Unpack(unpackedData[2]);
            dataIdx = 2;
        }
        data.Pos.Matrix_1 = unpackedData[dataIdx].Pos.Matrix_1;
        data.Pos.Flags.SetMatrixFlag();
    }
    if (pClassNameTag != pMainTag)
    {
        if (pDepthTag == pClassNameTag)
            dataIdx = 0;
        else if (pCharIdTag == pClassNameTag)
            dataIdx = 1;
        else if (pMatrixTag == pClassNameTag)
            dataIdx = 2;
        else
        {
            pClassNameTag->Unpack(unpackedData[3]);
            dataIdx = 3;
        }
        data.Pos.ClassName = unpackedData[dataIdx].Pos.ClassName;
        data.Pos.Flags.SetClassNameFlag();
    }
    if (pCxFormTag != pMainTag)
    {
        if (pDepthTag == pCxFormTag)
            dataIdx = 0;
        else if (pCharIdTag == pCxFormTag)
            dataIdx = 1;
        else if (pMatrixTag == pCxFormTag)
            dataIdx = 2;
        else if (pClassNameTag == pCxFormTag)
            dataIdx = 3;
        else
        {
            pCxFormTag->Unpack(unpackedData[4]);
            dataIdx = 4;
        }
        data.Pos.ColorTransform = unpackedData[dataIdx].Pos.ColorTransform;
        data.Pos.Flags.SetCxFormFlag();
    }
    if (pBlendModeTag != pMainTag)
    {
        if (pDepthTag == pBlendModeTag)
            dataIdx = 0;
        else if (pCharIdTag == pBlendModeTag)
            dataIdx = 1;
        else if (pMatrixTag == pBlendModeTag)
            dataIdx = 2;
        else if (pClassNameTag == pBlendModeTag)
            dataIdx = 3;
        else if (pCxFormTag == pBlendModeTag)
            dataIdx = 4;
        else
        {
            pBlendModeTag->Unpack(unpackedData[5]);
            dataIdx = 5;
        }
        data.Pos.BlendMode = unpackedData[dataIdx].Pos.BlendMode;
        data.Pos.Flags.SetBlendModeFlag();
    }
    if (pClipDepthTag != pMainTag)
    {
        if (pDepthTag == pClipDepthTag)
            dataIdx = 0;
        else if (pCharIdTag == pClipDepthTag)
            dataIdx = 1;
        else if (pMatrixTag == pClipDepthTag)
            dataIdx = 2;
        else if (pClassNameTag == pClipDepthTag)
            dataIdx = 3;
        else if (pCxFormTag == pClipDepthTag)
            dataIdx = 4;
        else if (pBlendModeTag == pClipDepthTag)
            dataIdx = 5;
        else
        {
            pClipDepthTag->Unpack(unpackedData[6]);
            dataIdx = 6;
        }
        data.Pos.ClipDepth = unpackedData[dataIdx].Pos.ClipDepth;
        data.Pos.Flags.SetClipDepthFlag();
    }
    if (pRatioTag != pMainTag)
    {
        if (pDepthTag == pRatioTag)
            dataIdx = 0;
        else if (pCharIdTag == pRatioTag)
            dataIdx = 1;
        else if (pMatrixTag == pRatioTag)
            dataIdx = 2;
        else if (pClassNameTag == pRatioTag)
            dataIdx = 3;
        else if (pCxFormTag == pRatioTag)
            dataIdx = 4;
        else if (pBlendModeTag == pRatioTag)
            dataIdx = 5;
        else if (pClipDepthTag == pRatioTag)
            dataIdx = 6;
        else
        {
            pRatioTag->Unpack(unpackedData[7]);
            dataIdx = 7;
        }
        data.Pos.Ratio = unpackedData[dataIdx].Pos.Ratio;
        data.Pos.Flags.SetRatioFlag();
    }
    if (pFiltersTag != pMainTag)
    {
        if (pDepthTag == pFiltersTag)
            dataIdx = 0;
        else if (pCharIdTag == pFiltersTag)
            dataIdx = 1;
        else if (pMatrixTag == pFiltersTag)
            dataIdx = 2;
        else if (pClassNameTag == pFiltersTag)
            dataIdx = 3;
        else if (pCxFormTag == pFiltersTag)
            dataIdx = 4;
        else if (pBlendModeTag == pFiltersTag)
            dataIdx = 5;
        else if (pClipDepthTag == pFiltersTag)
            dataIdx = 6;
        else if (pRatioTag == pFiltersTag)
            dataIdx = 7;
        else
        {
            pFiltersTag->Unpack(unpackedData[8]);
            dataIdx = 8;
        }
        data.Pos.pFilters = unpackedData[dataIdx].Pos.pFilters;
        data.Pos.Flags.SetFiltersFlag();
    }
}

// @0x1425d92d0
void PlaceObject2Tag::UnpackBase(GFxPlaceObjectBase::UnpackedData& data, UByte version)
{
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    if (po2Flags & PO2_HasActions)
        sc.Skip(sizeof(GFxPlaceObjectBase::EventArrayType*));
    data.Pos.Depth = sc.ReadU16();
    if (po2Flags & PO2_HasChar)
    {
        data.Pos.Flags.SetCharacterIdFlag();
        data.Pos.CharacterId = ResourceId(sc.ReadU16());
    }
    if (po2Flags & PO2_HasMatrix)
    {
        data.Pos.Flags.SetMatrixFlag();
        sc.ReadMatrix(&data.Pos.Matrix_1);
    }
    if (po2Flags & PO2_HasCxform)
    {
        data.Pos.Flags.SetCxFormFlag();
        sc.ReadCxformRgba(&data.Pos.ColorTransform);
    }
    if (po2Flags & PO2_HasRatio)
    {
        data.Pos.Flags.SetRatioFlag();
        data.Pos.Ratio = (float)sc.ReadU16() / (float)65535;
    }
    if (po2Flags & PO2_HasName)
    {
        sc.Align();
        data.Name = (const char*)pData + sc.CurByteIndex;
        while (sc.ReadU8() != 0)
        {
        }
    }
    else
        data.Name = 0;
    if (po2Flags & PO2_HasClipBracket)
    {
        data.Pos.Flags.SetClipDepthFlag();
        data.Pos.ClipDepth = sc.ReadU16();
    }
    if (po2Flags & PO2_HasActions)
        ProcessEventHandlers(data, sc, pData, version);
    else
        data.pEventHandlers = 0;

    bool hasChar   = (po2Flags & PO2_HasChar) != 0;
    bool flagMove  = (po2Flags & PO2_FlagMove) != 0;
    data.PlaceType = Place_Add;
    if (hasChar && flagMove)
        data.PlaceType = Place_Replace;
    else if (!hasChar && flagMove)
        data.PlaceType = Place_Move;
}

// @0x1425d9510
GFxPlaceObjectBase::EventArrayType* PlaceObject2Tag::UnpackEventHandlers()
{
    GFxPlaceObjectBase::EventArrayType* peh = 0;
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    if (po2Flags & PO2_HasActions)
    {
        // The AVM builds the array on the first unpack.
        peh = GetEventHandlersPtr(pData);
        if (!peh)
        {
            GFxPlaceObjectBase::UnpackedData data;
            Unpack(data);
            peh = data.pEventHandlers;
        }
    }
    return peh;
}

// @0x1425d95f0
GFxPlaceObjectBase::EventArrayType* PlaceObject3Tag::UnpackEventHandlers()
{
    GFxPlaceObjectBase::EventArrayType* peh = 0;
    StreamContext sc(pData);
    UByte         po2Flags = sc.ReadU8();
    if (po2Flags & PlaceObject2Tag::PO2_HasActions)
    {
        peh = PlaceObject2Tag::GetEventHandlersPtr(pData);
        if (!peh)
        {
            GFxPlaceObjectBase::UnpackedData data;
            Unpack(data);
            peh = data.pEventHandlers;
        }
    }
    return peh;
}

}} // namespace Scaleform::GFx
