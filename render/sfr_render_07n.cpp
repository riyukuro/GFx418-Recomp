// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the text node cache TU
// (Render_TreeCacheText): TreeCacheText, the render-side cache of a TreeText. It owns the node's TextMeshProvider,
// rebuilds it when the layout or the transform changes, re-meshes vector glyph layers per matrix and hands the
// distance field shadow to the shader.
// MS2-UNIT: sfr_render_07n
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426d5e40-0x1426d6f50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/render/render_treenode.h"
#include "ms2/scaleform/include/render/render_treecachenode.h"
#include "ms2/scaleform/include/render/render_treetext.h"
#include "ms2/scaleform/include/render/render_treecachetext.h"
#include "ms2/scaleform/include/render/render_textmeshprovider.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_bundle.h"
#include "ms2/scaleform/include/render/render_matrixpool.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_twips.h"
#include "ms2/scaleform/include/render/text_docview.h"
#include "ms2/scaleform/include/render/text_filterdesc.h"
#include <math.h>

namespace Scaleform { namespace Render {

// MS2-PIN: ??_7TreeCacheText@Render@Scaleform@@6B@ 0x143193a90

// @0x1426d5e40
TreeCacheText::TreeCacheText(TreeText* node, Renderer2DImpl* renderer2D, unsigned flags)
    : TreeCacheMeshBase(node, SortKey(SortKeyText, (flags & NF_3D) != 0), renderer2D, flags),
      pNextNoBatch(0), TMProvider(pRenderer2D->GetGlyphCache())
{
}

// @0x1426d5ef0
TreeCacheText::~TreeCacheText()
{
}

// @0x1426d5fa0
TextMeshProvider* TreeCacheText::CreateMeshProvider()
{
    const TextLayout* layout = GetNodeData()->pLayout;
    if (layout && pRoot)
    {
        Matrix4F m4;
        Viewport vp;
        if (M.Has3D())
        {
            Matrix4F viewProj = GetViewProj();
            getMatrix4F(&m4, viewProj);
            vp = pRoot->GetNodeData()->VP;
        }
        TMProvider.CreateMeshData(layout, pRenderer2D, M, m4, vp, calcMeshGenFlags());
    }
    if (TMProvider.IsCreated())
        UpdateDistanceFieldUniforms();
    return TMProvider.IsCreated() ? &TMProvider : 0;
}

// @0x1426d6230
MeshBase* TreeCacheText::GetMesh()
{
    return 0;
}

// @0x1426d6240
TextMeshProvider* TreeCacheText::GetMeshProvider()
{
    return TMProvider.IsCreated() ? &TMProvider : 0;
}

// @0x1426d6260
void TreeCacheText::HandleChanges(unsigned changeBits)
{
    if (changeBits & TreeText::Change_TextLayout)
    {
        if (Bundle* bundle = GetBundle())
            bundle->UpdateMesh(&SorterShapeNode);
        TMProvider.Clear();
    }
    if (changeBits & Change_EdgeAAMode)
        propagateEdgeAA(CalcEdgeAAMode(GetNodeData(), GetParent()));
}

// @0x1426d6320
void TreeCacheText::RemoveMesh()
{
}

// @0x1426d6330
void TreeCacheText::UpdateCache(TreeCacheContainer* parent, UInt16 depth)
{
    Depth = depth;
    pRoot = parent->pRoot;
}

// @0x1426d6340
void TreeCacheText::UpdateChildSubtree(const TreeNode::NodeData* data, UInt16 depth)
{
    unsigned newFlags = (GetFlags() & ~NF_PartOfMask) |
                        (GetParent()->GetFlags() & (NF_PartOfMask | NF_PartOfScale9)) |
                        ((GetFlags() & NF_MaskNode) << 1);
    if (data && data->Is3D())
        newFlags |= NF_3D;
    if (newFlags != GetFlags())
        SetFlags(newFlags);
    if (data)
        updateMaskCache(data, depth, true);
}

// The shader parameters of a distance field text with a drop shadow (the matrix user data, 0x40 bytes).
struct DistFieldUniforms
{
    float ShadowColor[4];    // +0x00
    float ShadowEnable;      // +0x10
    float Pad0[3];
    float ShadowOffset[4];   // +0x20
    float ShadowWidth;       // +0x30
    float Pad1[2];
    float Width;             // +0x3c

    DistFieldUniforms()
    {
        Width        = 9.0f;
        ShadowWidth  = 0;
        ShadowOffset[0] = ShadowOffset[1] = ShadowOffset[2] = ShadowOffset[3] = 0;
        ShadowEnable = 0;
    }
};

static inline float channelToFloat(UByte c) { return c == 0 ? 0 : c / 255.f; }

// @0x1426d63a0
void TreeCacheText::UpdateDistanceFieldUniforms()
{
    if (!TMProvider.HasDistanceField())
        return;

    DistFieldUniforms       df;
    const Text::TextFilter& tf = GetNodeData()->pDocView->GetFilters();
    if (tf.ShadowParams.BlurX > 0)
    {
        df.ShadowEnable = 1;
        df.ShadowWidth  = df.Width * 2 * Alg::Min(3.f, TwipsToPixels(tf.ShadowParams.BlurX));
        df.ShadowOffset[0] = -TwipsToPixels(tf.ShadowParams.Offset.x);
        df.ShadowOffset[1] = -TwipsToPixels(tf.ShadowParams.Offset.y);
        // the shadow reaches at most 2 pixels out
        float len2 = df.ShadowOffset[0] * df.ShadowOffset[0] + df.ShadowOffset[1] * df.ShadowOffset[1];
        if (len2 > 4.f)
        {
            float s = 2.f / sqrtf(len2);
            df.ShadowOffset[0] *= s;
            df.ShadowOffset[1] *= s;
        }

        const UByte* c    = (const UByte*)&tf.ShadowParams.Colors[0];
        df.ShadowColor[0] = channelToFloat(c[2]);
        df.ShadowColor[1] = channelToFloat(c[1]);
        df.ShadowColor[2] = channelToFloat(c[0]);
        df.ShadowColor[3] = channelToFloat(c[3]);
    }
    M.SetUserData(&df, sizeof(df));
}

// the image of the unit x axis without translation has both coordinates off zero
static inline bool isFreeRotation(const Matrix2F& m)
{
    Matrix2F mat2(m);
    mat2.M[0][3] = 0;
    mat2.M[1][3] = 0;
    PointF p10(mat2.M[0][0] * 1 + mat2.M[0][1] * 0 + mat2.M[0][3], mat2.M[1][0] * 1 + mat2.M[1][1] * 0 + mat2.M[1][3]);
    return float(fabs(p10.x)) > 1e-6f && float(fabs(p10.y)) > 1e-6f;
}

// MS2-FUNCTIONAL: register allocation in the pixel-snap block (exe holds the translation x in xmm1, the y axis term in xmm2)
// @0x1426d6600
void TreeCacheText::UpdateTransform(const TreeNode::NodeData* nodeData, const TransformArgs& t, TransformFlags flags)
{
    RectF cullRect(t.CullRect);
    updateCulling(nodeData, t, &cullRect, (TransformFlags)(flags | TF_CullCxform));

    SortParentBounds = nodeData->AproxParentBounds;
    SetFlags(GetFlags() & ~NF_ExpandedBounds);
    ComputeFinalMatrix(t, flags);

    const TextLayout* layout = GetNodeData()->pLayout;
    if (flags & TF_Matrix)
    {
        if ((layout->GetParam().TextParam.Flags & GlyphParam::OptRead) &&
            !(M.Has3D() || isFreeRotation(M.GetMatrix2D())))
        {
            Matrix2F m2(M.GetMatrix2D());
            // rounds half away from zero
            m2.Tx() = floorf(m2.Tx() + (m2.Tx() < 0 ? -0.5f : 0.5f));
            m2.Ty() = floorf(m2.Ty() + (m2.Ty() < 0 ? -0.5f : 0.5f));
            M.SetMatrix2D(m2);
        }

        Bundle* bundle = GetBundle();
        if (!bundle || !TMProvider.IsCreated())
            return;

        Matrix4F m4;
        Viewport vp;
        if (M.Has3D() && pRoot)
        {
            getMatrix4F(&m4, t.GetViewProj());
            vp = pRoot->GetNodeData()->VP;
        }
        if (TMProvider.NeedsUpdate(M, m4, vp, layout->GetParam()))
        {
            bundle->UpdateMesh(&SorterShapeNode);
            TMProvider.Clear();
            return;
        }
    }

    if (TMProvider.HasVectorGlyphs())
    {
        unsigned meshGenFlags = calcMeshGenFlags();
        for (unsigned i = 0; i < TMProvider.GetLayerCount(); i++)
        {
            TextMeshLayer& layer = TMProvider.GetLayer(i);
            if (layer.Type != TextLayer_Shapes && layer.Type != TextLayer_Shapes_Masked)
                continue;

            const TextMeshEntry& ent = TMProvider.GetEntry(layer, 0);
            Matrix2F scaling         = Matrix2F::Scaling(TMProvider.GetHeightRatio() * layer.SizeScale);
            float    keyData[MeshKey::MaxKeySize];
            unsigned keyFlags = TextMeshProvider::CalcVectorParams(layer, ent, scaling, layer.SizeScale, M,
                                                                   pRenderer2D, meshGenFlags, keyData);
            MeshKeyManager*        keyManager = pRenderer2D->GetMeshKeyManager();
            const ToleranceParams& cfg        = pRenderer2D->GetToleranceParams();
            if (layer.pMeshKey && layer.pMeshKey->Match(0, flags, keyData, cfg))
                continue;

            layer.pMeshKey = *keyManager->CreateMatchingKey(layer.pShape, 0, keyFlags, keyData, cfg);
            if (!layer.pMeshKey->pMesh)
                layer.pMeshKey->pMesh = *SF_HEAP_AUTO_NEW(this)
                    Mesh(pRenderer2D, layer.pMeshKey->GetKeySet(), scaling, 0, 0, meshGenFlags);
            layer.pMesh = (Mesh*)layer.pMeshKey->pMesh.GetPtr();
        }
    }

    if ((flags & TF_Matrix) && TMProvider.HasMask())
        TMProvider.UpdateMaskClearBounds(M);
}

// @0x1426d6df0
unsigned TreeCacheText::calcMeshGenFlags() const
{
    unsigned meshGenFlags = 0;
    if (GetFlags() & NF_PartOfMask)
        meshGenFlags |= Mesh_Mask;
    else if ((GetFlags() & NF_EdgeAA_Mask) == EdgeAA_On)
        meshGenFlags |= Mesh_EdgeAA;
    if (GetFlags() & NF_PartOfScale9)
        meshGenFlags |= Mesh_Scale9;
    return meshGenFlags;
}

// @0x1426d6e30
void TreeCacheText::forceUpdateImages()
{
    HandleChanges(TreeText::Change_TextLayout);
}

// @0x1426d6e40
void TreeCacheText::getMatrix4F(Matrix4F* m4, const Matrix4F& viewProj) const
{
    m4->MultiplyMatrix(viewProj, M.GetMatrix3D());
}

// @0x1426d6ea0
void TreeCacheText::propagateEdgeAA(EdgeAAMode parentEdgeAA)
{
    EdgeAAMode edgeAA = parentEdgeAA;
    if (GetNode())
        edgeAA = CalcEdgeAAMode(GetNodeData(), parentEdgeAA);
    if ((GetFlags() & NF_EdgeAA_Mask) != (unsigned)edgeAA)
    {
        SetFlags((GetFlags() & ~NF_EdgeAA_Mask) | edgeAA);
        TMProvider.Clear();
    }
}

// @0x1426d6f30
void TreeCacheText::propagateMaskFlag(unsigned partOfMask)
{
    unsigned newFlags = (GetFlags() & ~NF_PartOfMask) | partOfMask;
    if (newFlags != GetFlags())
        SetFlags(newFlags);
}

}} // namespace Scaleform::Render
