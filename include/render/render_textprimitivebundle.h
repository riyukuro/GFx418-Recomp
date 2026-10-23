// Recovered Scaleform 4.1.18 Render: TextPrimitiveBundle, the bundle that batches the layers of text meshes
// (Render_TextPrimitiveBundle, 0x1426f2460-0x1426f3f20, unit sfr_render_07q). All text fields drawn in one run of the
// sorted entries share the bundle; their meshes are sorted into one primitive per layer type and fill, so e.g. all
// glyph backgrounds are drawn before all glyphs. Mask layers go through a MaskPrimitive of the fields' clear bounds.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_TEXTPRIMITIVEBUNDLE_H
#define MS2_SF_RENDER_TEXTPRIMITIVEBUNDLE_H

#include "ms2/scaleform/include/render/render_bundle.h"
// (appended for sfr_render_07q)
#include "ms2/scaleform/include/render/render_primitivequeue.h"
#include "ms2/scaleform/include/render/render_containers.h"
#include "ms2/scaleform/include/render/render_textlayertype.h"

namespace Scaleform { namespace Render {

class TextMeshProvider;
// (appended for sfr_render_07q)
class TreeCacheText;
class TextPrepareBuffer;
class TextEmitBuffer;

// (appended for sfr_render_07q) the meshes of one layer type and fill over all the bundle's text fields, with the
// entry each mesh belongs to (0x80 bytes)
struct TextLayerPrimitive : public Primitive
{
    TextLayerType         Type;      // +0x60
    ArrayLH<BundleEntry*> Entries;   // +0x68, parallel to the meshes

    TextLayerPrimitive(HAL* hal, TextLayerType type, PrimitiveFill* fill) : Primitive(hal, fill), Type(type) {}

    bool AddEntry(BundleEntry* e, Mesh* mesh, const HMatrix& m);   // 0x1426f28e0
    // drops every mesh of e; the result is unused
    bool RemoveEntry(BundleEntry* e);                               // 0x1426f32f0

    // the providers stay pinned while their meshes are prepared
    void PinEntryBatches();     // 0x1426f2c80
    void UnpinEntryBatches();   // 0x1426f3440
};

class TextPrimitiveBundle : public Bundle, public RenderQueueItem::Interface
{
    friend class TextMeshProvider;
    // (appended for sfr_render_07q)
    friend class TextPrepareBuffer;
    friend class TextEmitBuffer;

    // takes the entry's meshes out of every text layer of the bundle
    void removeEntryFromLayers(BundleEntry* e);   // 0x1426f3bf0

public:
    // (appended for sfr_render_07q)
    TextPrimitiveBundle();    // 0x1426f2650
    ~TextPrimitiveBundle();   // 0x1426f2740

    void Draw(HAL* hal) { hal->Draw(RenderQueueItem(this, 0)); }

    virtual void InsertEntry(UPInt index, BundleEntry* entry);
    virtual void RemoveEntries(UPInt index, UPInt count);
    virtual void UpdateMesh(BundleEntry* entry);

    virtual QIPrepareResult Prepare(RenderQueueItem& item, RenderQueueProcessor& qp, bool waitForCache);
    virtual void            EmitToHAL(RenderQueueItem& item, RenderQueueProcessor& qp);

private:
    ArrayReserveLH_Mov<Ptr<TextLayerPrimitive>, 2> Layers;           // +0x40, sorted by type, then fill
    Ptr<MaskPrimitive>                             pMaskPrimitive;   // +0x58

    void startPrimitive(RenderQueueItem& item, TextPrepareBuffer* prepareBuffer, RenderQueueProcessor& qp);
    // sorts the provider's layers into the bundle's primitives; false when a primitive could not be created
    bool addAndPinBatchLayers(TreeCacheText* textCache, TextMeshProvider* tm);   // 0x1426f3500
    void clearBatchLayers();

    void pinLayerBatches()
    {
        for (UPInt i = 0; i < Layers.GetSize(); i++)
            Layers[i]->PinEntryBatches();
    }
    void unpinLayerBatches()
    {
        for (UPInt i = 0; i < Layers.GetSize(); i++)
            Layers[i]->UnpinEntryBatches();
    }
};

}} // namespace Scaleform::Render

#endif
