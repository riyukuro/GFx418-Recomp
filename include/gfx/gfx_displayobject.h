// Recovered Scaleform 4.1.18 GFx: data layout of the movie root base and the display object base, as far as
// the script VMs read them. Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder
// members. The virtual interfaces are not recovered yet (only reach these classes through data members).
#ifndef MS2_SF_GFX_DISPLAYOBJECT_H
#define MS2_SF_GFX_DISPLAYOBJECT_H

#include "../kernel/sf_refcount.h"
#include "gfx_log.h"

namespace Scaleform {

namespace Render { class TreeNode; }

namespace GFx {

class MovieImpl;
class ASSupport;
class InteractiveObject;

// AVM specific half of a movie (AS2::MovieRoot / AS3::MovieRoot). 0x28 bytes.
class ASMovieRootBase : public RefCountBase<ASMovieRootBase, 327>
{
public:
    MovieImpl*     pMovieImpl; // +0x10
    Ptr<ASSupport> pASSupport; // +0x18
    UByte          AVMVersion; // +0x20

    MovieImpl* GetMovieImpl() const { return pMovieImpl; }
};

// Base of every character on the display list. 0x70 bytes.
class DisplayObjectBase : public RefCountBaseWeakSupport<DisplayObjectBase, 322>,
                          public LogBase<DisplayObjectBase>
{
public:
    struct GeomDataType;
    struct PerspectiveDataType;
    struct IndirectTransformDataType;

    ASMovieRootBase* pASRoot;     // +0x20
    UInt32           Id;          // +0x28 ResourceId
    int              Depth;       // +0x2c
    unsigned         CreateFrame; // +0x30
    union
    {
        InteractiveObject* pParent;     // +0x38
        DisplayObjectBase* pParentChar;
    };
    float                      LastHitTestX;     // +0x40
    float                      LastHitTestY;     // +0x44
    Ptr<Render::TreeNode>      pRenNode;         // +0x48
    GeomDataType*              pGeomData;        // +0x50
    PerspectiveDataType*       pPerspectiveData; // +0x58
    IndirectTransformDataType* pIndXFormData;    // +0x60
    UInt16                     ClipDepth;        // +0x68
    UInt16                     Flags;            // +0x6a
    UByte                      BlendMode;        // +0x6c
    UByte                      AvmObjOffset;     // +0x6d

    ASMovieRootBase* GetASMovieRoot() const { return pASRoot; }
    MovieImpl*       GetMovieImpl() const   { return pASRoot->GetMovieImpl(); }
};

}} // namespace Scaleform::GFx

#endif
