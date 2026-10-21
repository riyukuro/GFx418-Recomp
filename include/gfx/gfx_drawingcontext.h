// Recovered Scaleform 4.1.18 GFx: DrawingContext, the shape a script draws into (the AS drawing API of clips, and
// the mask shape of a scrollRect). Bodies: GFx_DrawingContext (queue unit sfr_gfx_06, file 06e).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
// Only the bases and the members the clips call are declared so far (moved here from gfx_sprite.h).
#ifndef MS2_SF_GFX_DRAWINGCONTEXT_H
#define MS2_SF_GFX_DRAWINGCONTEXT_H

#include "../kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_list.h"
#include "gfx_characterdef.h"

namespace Scaleform { namespace Render { class TreeContainer; } }

namespace Scaleform { namespace GFx {

class DisplayObjectBase;

class DrawingContext : public RefCountBaseNTS<DrawingContext, 322>, public ListNode<DrawingContext>
{
public:
    // Bounds of everything drawn so far, in the clip's space (0x1425fec60).
    void ComputeBound(RectF* pRect) const;
    // Hit test of the drawn shapes, testShape asking for the exact outline instead of the bounds (0x1425ff270).
    bool DefPointTestLocal(const PointF& pt, bool testShape, const DisplayObjectBase* pinst) const;

    // (appended for the scrollRect of the display objects, sfr_gfx_06) the container node of the drawn shapes
    Render::TreeContainer* GetTreeNode() const { return pTreeContainer; }

    void BeginSolidFill(unsigned rgba);   // 0x1425fe8f0
    void MoveTo(float x, float y);        // 0x1425ff680
    void LineTo(float x, float y);        // 0x1425ff590
    void EndFill();                       // 0x1425ff3e0
    void UpdateRenderNode() const;        // 0x1426006a0

    void*                  Unrecovered_20;
    Render::TreeContainer* pTreeContainer;   // +0x28 (a Ptr in the exe)
};

}} // namespace Scaleform::GFx

#endif
