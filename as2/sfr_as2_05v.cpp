// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 (gap recovery of sfr_as2_05):
// the display info of a clip for the host (GFx::Value::GetDisplayInfo).
// MS2-UNIT: sfr_as2_05v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14294a5b0-0x14294a8f0 .text$mn
// (sfr36) the AvmCharacter / MovieRoot small virtuals below (no-VA trap stubs of the full-exe link)
// MS2-RANGE: 0x142933420-0x142933423 .text$mn
// MS2-RANGE: 0x142945d70-0x142945d7d .text$mn
// MS2-RANGE: 0x1429493c0-0x1429493fb .text$mn
// MS2-RANGE: 0x142949400-0x14294940a .text$mn
// MS2-RANGE: 0x142949430-0x142949435 .text$mn
// MS2-RANGE: 0x142949440-0x142949445 .text$mn
// MS2-RANGE: 0x142949450-0x142949453 .text$mn
// MS2-RANGE: 0x142949460-0x142949463 .text$mn
// MS2-RANGE: 0x142949490-0x142949495 .text$mn
// MS2-RANGE: 0x1429494a0-0x1429494a5 .text$mn
// MS2-RANGE: 0x14294afb0-0x14294afbd .text$mn
// MS2-RANGE: 0x142953cb0-0x142953cb5 .text$mn
// MS2-RANGE: 0x142954ec0-0x142954ec9 .text$mn
// MS2-RANGE: 0x1429561d0-0x1429561d9 .text$mn
// MS2-RANGE: 0x142956b10-0x142956b35 .text$mn
// MS2-RANGE: 0x14296ce70-0x14296ce73 .text$mn
// MS2-RANGE: 0x14296ce80-0x14296ce83 .text$mn
// MS2-RANGE: 0x142981600-0x142981609 .text$mn
// MS2-RANGE: 0x142989030-0x14298905f .text$mn

#include "../include/gfx/gfx_rendertree.h"
#include "../include/gfx/as2/as2_valueobjectinterface.h"
#include "../include/gfx/gfx_characterdef.h"
#include "../include/gfx/gfx_displayobject.h"
#include "../include/gfx/gfx_interactiveobject.h"
#include "../include/gfx/gfx_displayobjcontainer.h"
#include "../include/gfx/gfx_movieimpl.h"
#include "../include/gfx/as2/as2_movieroot.h"
#include "../include/gfx/as2/as2_avmcharacter.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_avmtextfield.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/gfx_button.h"

void FUN_1425b8e60(void* ptf, void* pinfo); // TextField: the display info of a text field (its text rect space)

namespace Scaleform { namespace GFx {

namespace {

// Value::DisplayInfo as the getter fills it.
struct DiDisplayInfo
{
    Double   X, Y;               // +0x00 pixels
    Double   Rotation;           // +0x10
    Double   XScale, YScale;     // +0x18
    Double   Alpha;              // +0x28 percent
    bool     Visible;            // +0x30
    Double   Z;                  // +0x38
    Double   XRotation;          // +0x40
    Double   YRotation;          // +0x48
    Double   ZScale;             // +0x50
    Double   FOV;                // +0x58
    Matrix3F ViewMatrix3D;       // +0x60
    Matrix4F ProjectionMatrix3D; // +0x90
    UInt32   EdgeAAMode;         // +0xd0
    UInt16   VarsSet;            // +0xd4 V_* bits of the fields set
};
static_assert(offsetof(DiDisplayInfo, ViewMatrix3D) == 0x60, "DisplayInfo::ViewMatrix3D");
static_assert(offsetof(DiDisplayInfo, ProjectionMatrix3D) == 0x90, "DisplayInfo::ProjectionMatrix3D");
static_assert(offsetof(DiDisplayInfo, VarsSet) == 0xd4, "DisplayInfo::VarsSet");

} // namespace

// Position, scales, rotations (pixels / percent / degrees), alpha, visibility, the field of view, the 3D matrices
// and the edge AA mode of the character pdata; a text field gives its own position fields.
// MS2-FUNCTIONAL: DisplayInfo is written through a layout view (DisplayInfo::Set inlined in the exe); Z stays in twips
// as in the exe
// @0x14294a5b0
bool AS2ValueObjectInterface::GetDisplayInfo(void* pdata, Value::DisplayInfo* pinfo) const
{
    DisplayObject* pd = static_cast<CharacterHandle*>(pdata)->ResolveCharacter(pMovieRoot);
    if (!pd)
        return false;
    DiDisplayInfo* info = reinterpret_cast<DiDisplayInfo*>(pinfo);

    DisplayObjectBase::GeomDataType geomData;
    pd->GetGeomData(geomData);
    if (pd->GetType() == CharacterDef::TextField)
        FUN_1425b8e60(pd, pinfo);
    else
    {
        const Double x     = Double(geomData.X) * 0.05;
        const Double y     = Double(geomData.Y) * 0.05;
        const float  alpha = reinterpret_cast<const float*>(&pd->GetCxform())[3] * 100.0f;
        info->Visible   = pd->GetVisible();
        info->VarsSet  |= 0x7ff;
        info->X         = x;
        info->Y         = y;
        info->Rotation  = geomData.Rotation;
        info->Alpha     = Double(alpha);
        info->XScale    = geomData.XScale;
        info->YScale    = geomData.YScale;
        info->XRotation = geomData.XRotation;
        info->YRotation = geomData.YRotation;
        info->ZScale    = geomData.ZScale;
        info->Z         = geomData.Z;
    }

    const Double fov = pd->GetFOV();
    info->VarsSet |= 0x800;
    info->FOV = fov;
    Matrix4F matProj;
    if (pd->GetProjectionMatrix3D(&matProj, false))
    {
        info->VarsSet |= 0x1000;
        info->ProjectionMatrix3D = matProj;
    }
    Matrix3F matView;
    if (pd->GetViewMatrix3D(&matView, false))
    {
        info->VarsSet |= 0x2000;
        info->ViewMatrix3D = matView;
    }
    const unsigned edgeAA = pd->GetRenderNode()->GetEdgeAAMode();
    info->VarsSet |= 0x4000;
    info->EdgeAAMode = edgeAA;
    return true;
}

}} // namespace Scaleform::GFx

// ---- (sfr36) AS2 small virtuals of AvmCharacter (vftable 0x143215b00) and MovieRoot (vftable 0x1432177d8)
// that the headers declared but no unit defined, so the full-exe link left them as trap stubs. ----

namespace Scaleform { namespace GFx { namespace AS2 {

// ---- AvmCharacter ----

// The five below are the shared one-instruction stubs of the exe (0x14000e380 store, 0x14000e3e0 null,
// 0x14000e3f0 / 0x14000e400 / 0x14000e4d0 false), folded with other classes' stubs inside sfr_video_01 / 02's ranges,
// so they carry no address tag here.
// MS2-FUNCTIONAL: ICF-shared stub bodies owned by the sfr_video ranges; defined untagged for the link.
void AvmCharacter::Bind(DisplayObject* po)
{
    pDispObj = static_cast<InteractiveObject*>(po);
}

// MS2-FUNCTIONAL: ICF-shared stub (0x14000e3e0), untagged.
InteractiveObject* AvmCharacter::GetRelativeTarget(const ASString& name, bool firstCall)
{
    SF_UNUSED2(name, firstCall);
    return 0;
}

// MS2-FUNCTIONAL: ICF-shared stub (0x14000e3f0), untagged.
bool AvmCharacter::ReplaceChildCharacterOnLoad(InteractiveObject* poldChar, InteractiveObject* pnewChar)
{
    SF_UNUSED2(poldChar, pnewChar);
    return false;
}

// MS2-FUNCTIONAL: ICF-shared stub (0x14000e400), untagged.
bool AvmCharacter::ReplaceChildCharacter(InteractiveObject* poldChar, InteractiveObject* pnewChar)
{
    SF_UNUSED2(poldChar, pnewChar);
    return false;
}

// MS2-FUNCTIONAL: ICF-shared stub (0x14000e4d0), untagged; only sprites run action buffers.
bool AvmCharacter::ExecuteBuffer(ActionBuffer* pactionbuffer)
{
    SF_UNUSED(pactionbuffer);
    return false;
}

// A plain character has no environment of its own: the nearest sprite ancestor's.
// @0x1429493c0
Environment* AvmCharacter::GetASEnvironment()
{
    for (InteractiveObject* p = pDispObj->GetParent(); p; p = p->GetParent())
    {
        if (p->IsSprite())
            return static_cast<AvmCharacter*>(static_cast<AvmInteractiveObjBase*>(p->GetAvmObjImpl()))
                ->GetASEnvironment();
    }
    return 0;
}

// @0x142949400
const Environment* AvmCharacter::GetASEnvironment() const
{
    return const_cast<AvmCharacter*>(this)->GetASEnvironment();
}

// No AS object for a plain character (buttons and text fields have their own, sprites the clip object).
// @0x142949450
Object* AvmCharacter::GetASObject()
{
    return 0;
}

// @0x142949460
Object* AvmCharacter::GetASObject() const
{
    return 0;
}

// @0x14294afb0
GlobalContext* AvmCharacter::GetGC() const
{
    return GetAS2Root()->pGlobalContext;
}

// The parent's top parent while the parent is an AS2 character, else this character.
// @0x142956b10
InteractiveObject* AvmCharacter::GetTopParent(bool ignoreLockRoot) const
{
    InteractiveObject* pparent = pDispObj->GetParent();
    if (pparent && pparent->GetASMovieRoot()->AVMVersion == 1)
        return pparent->GetTopParent(ignoreLockRoot);
    return pDispObj;
}

// ---- MovieRoot ----

// @0x142933420
bool MovieRoot::CheckAvm()
{
    return true;
}

// @0x142945d70
void MovieRoot::ForceEmergencyCollect()
{
    GetASGC()->ForceEmergencyCollect();
}

// @0x142953cb0
MemoryContext* MovieRoot::GetMemoryContext() const
{
    return MemContext;
}

// _level0.
// @0x142954ec0
DisplayObjContainer* MovieRoot::GetRootMovie(DisplayObject* dobj) const
{
    SF_UNUSED(dobj);
    return static_cast<DisplayObjContainer*>(pMovieImpl->pMainMovie);
}

// The string manager pointer the memory context keeps at +0x18.
// @0x1429561d0
ASStringManager* MovieRoot::GetStringManager() const
{
    return *reinterpret_cast<ASStringManager* const*>(MemContext->Unrecovered_18);
}

// @0x14296ce70
void MovieRoot::OnMovieFocus(bool set)
{
    SF_UNUSED(set);
}

// @0x14296ce80
void MovieRoot::OnNextFrame()
{
}

// The host's answer to ExternalInterface.call, kept as an AS value until the call returns.
// @0x142981600
void MovieRoot::SetExternalInterfaceRetVal(const GFx::Value& retVal)
{
    Value2ASValue(retVal, &ExternalIntfRetVal);
}

// ~0u keeps the default: no frame limit, 1000 roots.
// MS2-FUNCTIONAL: same stores and defaults; the exe interleaves the cmov/compare differently (47 vs 48 bytes).
// @0x142989030
void MovieRoot::SetMemoryParams(unsigned frameBetweenCollections, unsigned maxRootCount)
{
    ASRefCountCollector* pgc = MemContext->ASGC;
    if (frameBetweenCollections == ~0u)
        frameBetweenCollections = 0;
    if (maxRootCount == ~0u)
        maxRootCount = 1000;
    pgc->PresetFramesBetween = frameBetweenCollections;
    pgc->MaxRootCount        = maxRootCount;
    pgc->PresetMaxRootCount  = maxRootCount;
}

// The script side of a button (partial local copy: the AS object slots; the vftable is sfr_as2_03z's).
class AvmButton : public AvmCharacter, public AvmButtonBase
{
public:
    virtual Object* GetASObject();
    virtual Object* GetASObject() const;

private:
    ButtonObject* GetButtonASObject(); // sfr_as2_05d
};

// AvmCharacter's AS object slots of a button and a text field: the character's own AS object, made on first use.
// @0x142949430
Object* AvmButton::GetASObject()
{
    return GetButtonASObject();
}

// @0x142949440
Object* AvmButton::GetASObject() const
{
    return const_cast<AvmButton*>(this)->GetButtonASObject();
}

// @0x142949490
Object* AvmTextField::GetASObject()
{
    return GetTextFieldASObject();
}

// @0x1429494a0
Object* AvmTextField::GetASObject() const
{
    return const_cast<AvmTextField*>(this)->GetTextFieldASObject();
}

}}} // namespace Scaleform::GFx::AS2
