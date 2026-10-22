// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the primitive TU
// (Render_Primitive): shared hardware fills and their manager, meshes and complex meshes, primitives (a fill plus
// the meshes drawn with it, split into batches), and the mask / filter / 3D matrix queue items.
// Queue unit sfr_render_04 is split along its original sources (04f Render_Primitive).
// MS2-UNIT: sfr_render_04f
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14266b500-0x14266fc60 .text$mn

#include "ms2/scaleform/include/render/render_primitive.h"
#include "ms2/scaleform/include/render/render_hal.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_renderer2d.h"
#include "ms2/scaleform/include/render/render_primitivequeue.h"
#include "ms2/scaleform/include/render/render_meshcache.h"
#include "ms2/scaleform/include/render/render_queue.h"
#include "ms2/scaleform/include/render/render_threadcommand.h"

namespace Scaleform { namespace Render {

// ***** PrimitiveFillData

// The vertex channels each fill type reads, one letter per channel: C colour, E edge alpha factor,
// W texture 0 weight, U texture coordinates.
const char* PrimitiveFill_FormatCheck[PrimFill_UVTextureDFAlpha_VColor + 1] =
{
    "", "", "", "C", "CE", "", "E", "CW", "CWE", "W", "EW", "U", "UC", "UC"
};

// @0x14266ced0
bool PrimitiveFillData::CheckVertexFormat(PrimitiveFillType fill, const VertexFormat* format)
{
    if (!format->HasUsage(VET_Pos))
        return false;

    for (const char* p = PrimitiveFill_FormatCheck[fill]; *p; p++)
    {
        const char* missing = 0;
        switch (*p)
        {
        case 'C':
            if (!format->HasUsage(VET_Color))
                missing = "VColor";
            break;
        case 'E':
            if (!format->GetElement(VET_FactorAlpha8, VET_Type_Mask))
                missing = "FactorAlpha8";
            break;
        case 'W':
            if (!format->GetElement(VET_T0Weight8, VET_Type_Mask))
                missing = "T0Weight8";
            break;
        case 'U':
            if (!format->HasUsage(VET_TexCoord))
                missing = "TexCoord";
            break;
        }
        if (missing)
            return false;
    }
    return true;
}

// ***** PrimitiveFill / PrimitiveFillManager

// @0x14266c280
PrimitiveFill::~PrimitiveFill()
{
    if (pManager)
        pManager->removeFill(this);
}

// @0x14266f260
void PrimitiveFillManager::removeFill(PrimitiveFill* fill)
{
    FillSet.Remove(fill);
}

// @0x14266f380
void PrimitiveFillManager::removeGradient(GradientImage* img)
{
    Gradients.Remove(img);
}

// @0x14266f110
Image* PrimitiveFillManager::createGradientImage(GradientData* data, float morphRatio)
{
    GradientImage* img = 0;
    if (Gradients.GetAlt(GradientKey(data, morphRatio), &img))
        img->AddRef();
    else
    {
        img = SF_HEAP_AUTO_NEW(this) GradientImage(this, data, morphRatio);
        Gradients.Add(img);
    }
    return img;
}

// MS2-FUNCTIONAL: the exe reloads the hash table pointer after the out-of-line operator== call; ours keeps it in a register
// @0x14266d040
PrimitiveFill* PrimitiveFillManager::CreateFill(const PrimitiveFillData& data)
{
    PrimitiveFill* fill = 0;
    if (FillSet.GetAlt(data, &fill))
        fill->AddRef();
    else
    {
        fill = pHAL->CreatePrimitiveFill(data);
        if (!fill)
            return 0;
        FillSet.Add(fill);
        fill->SetManager(this);
    }
    return fill;
}

// @0x14266d170
PrimitiveFill* PrimitiveFillManager::CreateFill(const FillData& fd, Ptr<Image>* gradientImage,
                                                TextureManager* textureManager, float morphRatio)
{
    switch (fd.Type)
    {
    case Fill_Mask:
        {
            PrimitiveFillData data(PrimFill_Mask, fd.pVFormat);
            return CreateFill(data);
        }
    case Fill_SolidColor:
        {
            PrimitiveFillData data(PrimFill_SolidColor, fd.pVFormat, fd.Color);
            return CreateFill(data);
        }
    case Fill_VColor:
    case Fill_VColor_TestKey:
        {
            PrimitiveFillData data((PrimitiveFillType)fd.PrimFill, fd.pVFormat);
            if (fd.Type == Fill_VColor_TestKey)
                data.SolidColor = fd.Color;   // a unique batching key for the sorting tests
            return CreateFill(data);
        }
    case Fill_Image:
        {
            if (fd.pImage)
            {
                Texture* texture = fd.pImage->GetTexture(textureManager);
                if (texture)
                {
                    PrimitiveFillData data((PrimitiveFillType)fd.PrimFill, fd.pVFormat, texture, fd.FillMode);
                    return CreateFill(data);
                }
            }
            // no image or no texture: a red placeholder fill
            PrimitiveFillData data(PrimFill_SolidColor, fd.pVFormat, Color(0xFFFF0000));
            return CreateFill(data);
        }
    case Fill_Gradient:
        {
            *gradientImage = *createGradientImage(fd.pGradient, morphRatio);
            if (!*gradientImage)
                break;
            PrimitiveFillData data((PrimitiveFillType)fd.PrimFill, fd.pVFormat,
                                   (*gradientImage)->GetTexture(textureManager), fd.FillMode);
            return CreateFill(data);
        }
    case Fill_None:
        break;
    }
    return 0;
}

// Which merged shader input a pair of fills becomes, given how the tessellator merged them. Only the
// {Image, VColor} order is produced, so the reverse pairs are not listed.
struct FillTypeMergeInfo
{
    UByte F0, F1;
    UByte MergeFlags;
    UByte Result;
};

static FillTypeMergeInfo FillTypeMergeTable[] =
{
    { Fill_VColor,     Fill_None,   FillMerge_None,          PrimFill_VColor },
    { Fill_VColor,     Fill_None,   FillMerge_EAlpha,        PrimFill_VColor_EAlpha },
    { Fill_Image,      Fill_None,   FillMerge_None,          PrimFill_Texture },
    { Fill_Image,      Fill_None,   FillMerge_EAlpha,        PrimFill_Texture_EAlpha },
    { Fill_Image,      Fill_VColor, FillMerge_Weight,        PrimFill_Texture_VColor },
    { Fill_Image,      Fill_VColor, FillMerge_EAlpha_Weight, PrimFill_Texture_VColor_EAlpha },
    { Fill_Image,      Fill_Image,  FillMerge_Weight,        PrimFill_2Texture },
    { Fill_Image,      Fill_Image,  FillMerge_EAlpha_Weight, PrimFill_2Texture_EAlpha },
    { Fill_SolidColor, Fill_None,   FillMerge_None,          PrimFill_SolidColor },
    { Fill_Mask,       Fill_None,   FillMerge_None,          PrimFill_Mask },
    { Fill_None,       Fill_None,   FillMerge_None,          PrimFill_None }
};

// Linear search; the second fill only matters for weighted merges. Falls through to PrimFill_None.
PrimitiveFillType GetMergedFillType(FillType ft0, FillType ft1, unsigned mergeFlags)
{
    FillTypeMergeInfo* info = FillTypeMergeTable;
    do
    {
        if (info->F0 == ft0 && mergeFlags == info->MergeFlags)
            if (info->F1 == ft1 || !(mergeFlags & FillMerge_Weight))
                break;
        info++;
    } while (info->F0 != Fill_None);
    return (PrimitiveFillType)info->Result;
}

// @0x14266d510
PrimitiveFill* PrimitiveFillManager::CreateMergedFill(unsigned mergeFlags, const VertexFormat* format,
                                                      const FillData* fd0, const FillData* fd1,
                                                      Ptr<Image>* gradientImage0, Ptr<Image>* gradientImage1,
                                                      TextureManager* textureManager, float morphRatio)
{
    FillType ft0  = fd0->Type;
    FillType ft1  = fd1->Type;
    Image*   img0 = fd0->pImage;   // only meaningful for image fills
    Image*   img1 = fd1->pImage;

    // gradients are drawn as their images
    if (ft0 == Fill_Gradient)
    {
        *gradientImage0 = *createGradientImage(fd0->pGradient, morphRatio);
        img0 = *gradientImage0;
        ft0  = Fill_Image;
    }
    if (ft1 == Fill_Gradient)
    {
        *gradientImage1 = *createGradientImage(fd1->pGradient, morphRatio);
        img1 = *gradientImage1;
        ft1  = Fill_Image;
    }
    if (ft0 == Fill_VColor_TestKey)
        ft0 = Fill_VColor;
    if (ft1 == Fill_VColor_TestKey)
        ft1 = Fill_VColor;

    PrimitiveFillType type = GetMergedFillType(ft0, ft1, mergeFlags);
    PrimitiveFillData data(type, format);

    switch (type)
    {
    case PrimFill_Mask:
        break;
    case PrimFill_SolidColor:
        data.SolidColor = fd0->Color;
        break;
    case PrimFill_VColor:
    case PrimFill_VColor_EAlpha:
        if (fd0->Type == Fill_VColor_TestKey)
            data.SolidColor = fd0->Color;
        break;
    case PrimFill_2Texture:
    case PrimFill_2Texture_EAlpha:
        data.Textures[1]  = img1->GetTexture(textureManager);
        data.FillModes[1] = fd1->FillMode;
        // then texture 0 as for the single texture fills
    case PrimFill_Texture:
    case PrimFill_Texture_VColor:
    case PrimFill_Texture_EAlpha:
    case PrimFill_Texture_VColor_EAlpha:
        data.Textures[0]  = img0->GetTexture(textureManager);
        data.FillModes[0] = fd0->FillMode;
        break;
    default:
        return 0;   // no merged type for this pair
    }
    return CreateFill(data);
}

// Kept out of line: the shipped build calls it from the fill set lookup, and inlining it there would pull
// CreateFill into CreateMergedFill.
// @0x14266c3f0
SF_NOINLINE bool PrimitiveFillData::operator==(const PrimitiveFillData& o) const
{
    return Type == o.Type && SolidColor == o.SolidColor &&
           FillModes[0] == o.FillModes[0] && FillModes[1] == o.FillModes[1] &&
           Textures[0] == o.Textures[0] && Textures[1] == o.Textures[1] &&
           (pFormat == o.pFormat || *pFormat == *o.pFormat);
}

// ***** Mesh

// @0x14266bcd0
MeshBase::MeshBase(Renderer2DImpl* renderer, MeshProvider* provider, const Matrix2F& viewMatrix, float morphRatio,
                   unsigned layer, unsigned meshGenFlags)
    : pRenderer2D(renderer), pProvider(provider), ViewMatrix(viewMatrix), MorphRatio(morphRatio),
      Layer(layer), MGFlags(meshGenFlags)
{
}

// @0x14266bc40
Mesh::Mesh(Renderer2DImpl* renderer, MeshProvider* provider, const Matrix2F& viewMatrix, float morphRatio,
           unsigned layer, unsigned meshGenFlags)
    : MeshBase(renderer, provider, viewMatrix, morphRatio, layer, meshGenFlags), LargeMesh(false)
{
}

// @0x14266c0b0
Mesh::~Mesh()
{
    // the cache items drop their copies of us
    UPInt           count = CacheItems.GetSize();
    MeshCacheItem** items = CacheItems.GetBuffer();
    while (count--)
    {
        if (*items)
            (*items)->NotifyMeshRelease(this);
        items++;
    }
    // and we leave the staging buffer
    if (StagingBufferSize)
        RemoveNode();
}

// The busiest status over our cache items.
// @0x14266dd50
MeshUseStatus Mesh::GetUseStatus() const
{
    MeshUseStatus         status = MUS_Uncached;
    UPInt                 count  = CacheItems.GetSize();
    MeshCacheItem* const* items  = CacheItems.GetBuffer();
    for (UPInt i = 0; i < count; i++)
    {
        MeshUseStatus s = items[i]->GetUseStatus();
        if (s > status)
            status = s;
    }
    return status;
}

// ***** ComplexMesh

// @0x14266ba80
ComplexMesh::ComplexMesh(Renderer2DImpl* renderer, MeshProvider* provider, PrimitiveFillManager* fillManager,
                         const Matrix2F& viewMatrix, float morphRatio, unsigned layer, unsigned meshGenFlags)
    : MeshBase(renderer, provider, viewMatrix, morphRatio, layer, meshGenFlags),
      pFillManager(fillManager), pCacheMeshItem(0), AllocTooBig(false)
{
}

// @0x14266bf10
ComplexMesh::~ComplexMesh()
{
    if (UpdateListNode.pPrev)
        UpdateListNode.RemoveNode();
    if (pCacheMeshItem)
        pCacheMeshItem->NotifyMeshRelease(this);
    // complex meshes never use the staging buffer
}

// @0x14266ddf0
bool ComplexMesh::InitFillRecords(const VertexOutput::Fill* fills, unsigned fillCount, const Matrix2F& vertexMatrix,
                                  HAL* hal, UPInt* vbSize, unsigned* vertexCount, unsigned* indexCount)
{
    FillRecords.Resize(fillCount);
    if (FillRecords.GetSize() != fillCount)
        return false;

    TextureManager* textureManager = hal->GetTextureManager();

    // rejoin the update list below only if an image fill still needs it
    if (UpdateListNode.pPrev)
    {
        UpdateListNode.RemoveNode();
        UpdateListNode.pPrev = UpdateListNode.pNext = 0;
    }

    *vbSize      = 0;
    *vertexCount = *indexCount = 0;

    for (unsigned i = 0; i < fillCount; i++)
    {
        const VertexOutput::Fill& src = fills[i];
        FillRecord&               fr  = FillRecords[i];

        // the fill, merged with the second one for EdgeAA weights
        FillData   fd[2];
        Ptr<Image> gi[2];
        GetProvider()->GetFillData(&fd[0], GetLayer(), src.FillIndex0, GetMeshGenFlags());
        if (src.MergeFlags & FillMerge_Weight)
            GetProvider()->GetFillData(&fd[1], GetLayer(), src.FillIndex1, GetMeshGenFlags());

        fr.pFill = *pFillManager->CreateMergedFill(src.MergeFlags, src.pFormat, &fd[0], &fd[1], &gi[0], &gi[1],
                                                   textureManager, GetMorphRatio());
        if (!fr.pFill)
            return false;

        if (!UpdateListNode.pPrev && (fd[0].Type == Fill_Image || fd[1].Type == Fill_Image))
            GetRenderer()->AddComplexMeshToUpdateList(UpdateListNode);

        fr.IndexOffset        = *indexCount;
        fr.IndexCount         = src.IndexCount;
        fr.VertexByteOffset   = *vbSize;
        fr.VertexCount        = src.VertexCount;
        fr.FillMatrixIndex[0] = src.FillIndex0;
        fr.FillMatrixIndex[1] = src.FillIndex1;
        fr.MergeFlags         = src.MergeFlags;

        // gradient images stay referenced so their textures can be generated again
        if (gi[0]) GradientImages.PushBack(gi[0]);
        if (gi[1]) GradientImages.PushBack(gi[1]);

        const VertexFormat* batchFormat;
        hal->MapVertexFormat(fr.pFill->GetType(), fr.pFill->GetVertexFormat(), &fr.pFormats[0], &batchFormat,
                             &fr.pFormats[1], MeshCacheItem::Mesh_Complex);

        *vbSize      += fr.pFormats[0]->Size * src.VertexCount;
        *vertexCount += src.VertexCount;
        *indexCount  += src.IndexCount;
    }

    VertexMatrix = vertexMatrix;
    updateFillMatrixCache(vertexMatrix);
    return true;
}

// @0x14266f770
void ComplexMesh::updateFillMatrixCache(const Matrix2F& vertexMatrix)
{
    unsigned fillCount = GetFillCount(GetLayer(), GetMeshGenFlags());
    FillMatrixCache.Resize(fillCount);
    if (FillMatrixCache.GetSize() != fillCount)
        return;
    for (unsigned i = 0; i < fillCount; i++)
    {
        GetProvider()->GetFillMatrix(this, &FillMatrixCache[i], GetLayer(), i, GetMeshGenFlags());
        FillMatrixCache[i].Prepend(vertexMatrix);
    }
}

// Recreates the fills after texture changes (the mesh is in the renderer's update list).
// @0x14266f9a0
bool ComplexMesh::updateFills()
{
    if (!GetProvider()->IsValid())
        return false;
    TextureManager* textureManager = GetRenderer()->GetHAL()->GetTextureManager();

    for (unsigned i = 0; i < FillRecords.GetSize(); i++)
    {
        FillRecord& fr = FillRecords[i];
        if (!fr.pFill)
            continue;

        FillData   fd[2];
        Ptr<Image> gi[2];
        GetProvider()->GetFillData(&fd[0], GetLayer(), fr.FillMatrixIndex[0], GetMeshGenFlags());
        GetProvider()->GetFillData(&fd[1], GetLayer(), fr.FillMatrixIndex[1], GetMeshGenFlags());

        Ptr<PrimitiveFill> mergedFill = *pFillManager->CreateMergedFill(fr.MergeFlags, fr.pFill->GetVertexFormat(),
                                                                        &fd[0], &fd[1], &gi[0], &gi[1],
                                                                        textureManager, GetMorphRatio());
        if (!mergedFill)
            continue;   // keep the old fill
        fr.pFill = mergedFill;
    }
    updateFillMatrixCache(VertexMatrix);
    return true;
}

// ***** FillData

// @0x14266bc00
FillData::FillData(FillType type)
    : Type(type), Color(0), PrimFill(PrimFill_VColor_EAlpha), FillMode(), pVFormat(&VertexXY16iCF32::Format)
{
    if (type != Fill_VColor)
    {
        if (type == Fill_Mask)
        {
            PrimFill = PrimFill_Mask;
            pVFormat = &VertexXY16i::Format;
        }
    }
}

// @0x14266bbd0
FillData::FillData(Image* image, ImageFillMode fillMode)
    : Type(Fill_Image), pImage(image), PrimFill(PrimFill_Texture_EAlpha), FillMode(fillMode),
      pVFormat(&VertexXY16iCF32::Format)
{
}

// @0x14266bba0
FillData::FillData(GradientData* gradient)
    : Type(Fill_Gradient), pGradient(gradient), PrimFill(PrimFill_Texture_EAlpha),
      FillMode(ImageFillMode(Wrap_Clamp, Sample_Linear)), pVFormat(&VertexXY16iCF32::Format)
{
}

//--------------------------------------------------------------------
// ***** Primitive

// creations, live primitives and mesh inserts (statistics only)
static unsigned Primitive_CreateCount = 0;
static unsigned Primitive_LiveCount   = 0;
static unsigned Primitive_InsertCount = 0;

// the textures a fill type samples, each with its own texture matrix
static inline UByte Primitive_FillTextureCount(PrimitiveFillType type)
{
    if (type >= PrimFill_Texture && type <= PrimFill_2Texture_EAlpha)
        return (UByte)((type >= PrimFill_2Texture) + 1);
    return 0;
}

// @0x14266bdc0
Primitive::Primitive(HAL* hal, PrimitiveFill* fill)
    : pHAL(hal), pFill(fill), MatricesPerMesh(Primitive_FillTextureCount(fill->GetType()) + 1), ModifyIndex(0)
{
    Primitive_CreateCount++;
    Primitive_LiveCount++;
}

// @0x14266c1a0
Primitive::~Primitive()
{
    Primitive_LiveCount--;
    while (!Batches.IsEmpty())
        Batches.GetFirst()->RemoveAndFree();
}

// @0x14266e300
bool Primitive::Insert(unsigned index, Mesh* mesh, const HMatrix& m)
{
    PrimitiveBatch* p    = Batches.GetFirst();
    PrimitiveBatch* prev = 0;
    unsigned        i    = 0;
    const MeshCacheParams& params = pHAL->GetMeshCache().GetParams();

    for (;;)
    {
        if (i == index)
        {
            // at a batch boundary: grow the virtual batch on either side, else start a new virtual one
            if (prev && prev->Type == PrimitiveBatch::DP_Virtual)
            {
                prev->MeshCount++;
                break;
            }
            if (Batches.IsNull(p) || p->Type != PrimitiveBatch::DP_Virtual)
            {
                PrimitiveBatch* b = PrimitiveBatch::Create(this, PrimitiveBatch::DP_Virtual, i, 1);
                p->InsertNodeBefore(b);
                break;
            }
        }
        if (Batches.IsNull(p))
            break;
        if (index - i < p->MeshCount)
        {
            // inside a batch: an instanced batch of the same mesh stays instanced while it has room
            p->MeshCount++;
            if (p->Type != PrimitiveBatch::DP_Instanced || Meshes[i].pMesh != mesh ||
                p->MeshCount > params.MaxBatchInstances)
            {
                p->Type = PrimitiveBatch::DP_Virtual;
                p->ClearCacheItem();
            }
            break;
        }
        prev = p;
        i   += p->MeshCount;
        p    = p->pNext;
    }

    MeshEntry e = { m, mesh };
    Meshes.InsertAt(index, e);
    if (index < ModifyIndex)
        ModifyIndex = index;
    Primitive_InsertCount++;
    return true;
}

// @0x14266e7b0
void Primitive::Remove(unsigned index, unsigned count)
{
    PrimitiveBatch* p    = Batches.GetFirst();
    unsigned        i    = 0;
    unsigned        left = count;

    do
    {
        if (index - i < p->MeshCount)
        {
            if (index == i)
            {
                if (left >= p->MeshCount)
                {
                    // the whole batch goes; i stays where it is
                    PrimitiveBatch* old = p;
                    left -= p->MeshCount;
                    p     = p->pNext;
                    old->RemoveAndFree();
                    continue;
                }
                // drop the batch's first meshes
                p->MeshCount -= left;
                if (!p->IsInstanced())
                {
                    p->Type = PrimitiveBatch::DP_Virtual;
                    p->ClearCacheItem();
                }
                left = 0;
                break;
            }
            // drop the batch's tail (or a run inside it)
            unsigned n = (left > p->MeshCount - (index - i)) ? p->MeshCount - (index - i) : left;
            p->MeshCount -= n;
            if (!p->IsInstanced())
            {
                p->Type = PrimitiveBatch::DP_Virtual;
                p->ClearCacheItem();
            }
            left -= n;
            i    += p->MeshCount;
        }
        else
        {
            i += p->MeshCount;
        }
        p = p->pNext;
    } while (left && !Batches.IsNull(p));

    Meshes.RemoveMultipleAt(index, count);
    if (index < ModifyIndex)
        ModifyIndex = index;
}

// @0x14266f050
void Primitive::SetMesh(unsigned index, Mesh* mesh)
{
    if (Meshes[index].pMesh == mesh)
        return;
    Meshes[index].pMesh = mesh;

    // the batch holding the mesh has to be rebuilt
    PrimitiveBatch* p = Batches.GetFirst();
    unsigned        i = 0;
    while (index >= i + p->MeshCount)
    {
        i += p->MeshCount;
        p  = p->pNext;
    }
    p->Type = PrimitiveBatch::DP_Virtual;
    p->ClearCacheItem();
}

// @0x14266fc20
void Primitive::UpdateMeshIndicies()
{
    if (ModifyIndex < GetMeshCount())
    {
        unsigned index = GetMeshCount();
        for (PrimitiveBatch* p = Batches.GetLast(); !Batches.IsNull(p); p = p->pPrev)
        {
            index       -= p->MeshCount;
            p->MeshIndex = index;
            if (index < ModifyIndex)
                break;
        }
        ModifyIndex = GetMeshCount();
    }
}

//--------------------------------------------------------------------
// ***** PrimitiveBatch

// @0x14266cfd0
PrimitiveBatch* PrimitiveBatch::Create(Primitive* p, BatchType type, unsigned meshIndex, unsigned meshCount)
{
    PrimitiveBatch* batch = (PrimitiveBatch*)SF_HEAP_AUTO_ALLOC(p, sizeof(PrimitiveBatch));
    batch->Init(p, type, meshIndex, meshCount);
    return batch;
}

// @0x14266e970
void PrimitiveBatch::RemoveAndFree()
{
    RemoveNode();
    ClearCacheItem();
    SF_FREE(this);
}

// @0x14266cd90
void PrimitiveBatch::CalcMeshSizes(unsigned* totalVertices, unsigned* totalIndices)
{
    pPrimitive->UpdateMeshIndicies();
    unsigned meshCount   = IsInstanced() ? 1 : MeshCount;
    unsigned vertexCount = 0, indexCount = 0;
    for (unsigned i = 0; i < meshCount; i++)
    {
        Mesh* mesh   = pPrimitive->Meshes[MeshIndex + i].pMesh;
        vertexCount += mesh->VertexCount;
        indexCount  += mesh->IndexCount;
    }
    *totalVertices = vertexCount;
    *totalIndices  = indexCount;
}

//--------------------------------------------------------------------
// ***** MaskPrimitive

// @0x14266e280
void MaskPrimitive::Insert(UPInt index, const HMatrix& m)
{
    MaskAreas.InsertAt(index, m);
}

// @0x14266e6f0
void MaskPrimitive::Remove(UPInt index, UPInt count)
{
    MaskAreas.RemoveMultipleAt(index, count);
}

//--------------------------------------------------------------------
// ***** FilterPrimitive

// @0x14266bfd0
FilterPrimitive::~FilterPrimitive()
{
    for (unsigned i = 0; i < MaximumCachedResults; i++)
        CacheResults[i] = 0;
}

// The area matrix is the only one a filter has; the index is ignored.
// @0x14266e270
void FilterPrimitive::Insert(UPInt, const HMatrix& m)
{
    FilterArea = m;
}

// @0x14266e6b0
void FilterPrimitive::Remove(UPInt, UPInt)
{
    FilterArea.Clear();
}

// @0x14266dc50
void FilterPrimitive::GetCacheResults(RenderTarget** results, unsigned count)
{
    for (unsigned i = 0; i < count; i++)
        results[i] = (i < count) ? CacheResults[i].GetPtr() : 0;
}

// @0x14266efb0
void FilterPrimitive::SetCacheResults(CacheState state, RenderTarget** results, unsigned count)
{
    Caching = state;
    for (unsigned i = 0; i < MaximumCachedResults; i++)
    {
        if (i < count && results)
            CacheResults[i] = results[i];
        else
            CacheResults[i] = 0;
    }
}

// @0x14266e5b0
RenderQueueItem::QIPrepareResult FilterPrimitive::Prepare(RenderQueueItem&, RenderQueueProcessor& qp, bool)
{
    qp.GetHAL()->PrepareFilters(this);
    return RenderQueueItem::QIP_Done;
}

//--------------------------------------------------------------------
// ***** 3D view and projection

// @0x14266daa0
void ViewMatrix3DPrimitive::EmitToHAL(RenderQueueItem&, RenderQueueProcessor& qp)
{
    if (bHasViewMatrix)
        qp.GetHAL()->PushView3D(ViewMatrix);
    else
        qp.GetHAL()->PopView3D();
}

// @0x14266d8b0
void ProjectionMatrix3DPrimitive::EmitToHAL(RenderQueueItem&, RenderQueueProcessor& qp)
{
    if (bHasProjectionMatrix)
        qp.GetHAL()->PushProj3D(ProjectionMatrix);
    else
        qp.GetHAL()->PopProj3D();
}

}} // namespace Scaleform::Render

// the thread command base's deleting dtor is emitted with this TU
template class Scaleform::RefCountBase<Scaleform::Render::ThreadCommand, Scaleform::Stat_Default_Mem>;

// MS2-PIN: ??_7PrimitiveFill@Render@Scaleform@@6B@ 0x143191988
// MS2-PIN: ??_7MeshStagingNode@Render@Scaleform@@6B@ 0x143191928
// MS2-PIN: ??_7MeshBase@Render@Scaleform@@6B?$RefCountBase@VMeshBase@Render@Scaleform@@$0EG@@2@@ 0x143191948
// MS2-PIN: ??_7MeshBase@Render@Scaleform@@6BMeshStagingNode@12@@ 0x143191958
// MS2-PIN: ??_7Mesh@Render@Scaleform@@6B?$RefCountBase@VMeshBase@Render@Scaleform@@$0EG@@2@@ 0x143191968
// MS2-PIN: ??_7Mesh@Render@Scaleform@@6BMeshStagingNode@12@@ 0x143191978
// MS2-PIN: ??_7ComplexMesh@Render@Scaleform@@6B?$RefCountBase@VMeshBase@Render@Scaleform@@$0EG@@2@@ 0x1431919d8
// MS2-PIN: ??_7ComplexMesh@Render@Scaleform@@6BMeshStagingNode@12@@ 0x1431919e8
// MS2-PIN: ??_7?$RefCountBase@VThreadCommand@Render@Scaleform@@$01@Scaleform@@6B@ 0x143191938
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EG@@Scaleform@@6B@ 0x143191940
// MS2-PIN: ??_7?$RefCountBase@VMeshBase@Render@Scaleform@@$0EG@@Scaleform@@6B@ 0x143191a38
// MS2-PIN: ??_7Interface@RenderQueueItem@Render@Scaleform@@6B@ 0x143191990
// MS2-PIN: ??_7?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431919b0
// MS2-PIN: ??_7?$RefCountBase@VPrimitive@Render@Scaleform@@$0EE@@Scaleform@@6B@ 0x1431919a8
// MS2-PIN: ??_7Primitive@Render@Scaleform@@6B?$RefCountBase@VPrimitive@Render@Scaleform@@$0EE@@2@@ 0x1431919b8
// MS2-PIN: ??_7Primitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x1431919c0
// MS2-PIN: ??_7FilterPrimitive@Render@Scaleform@@6B?$RefCountBase@VFilterPrimitive@Render@Scaleform@@$0EE@@2@@ 0x1431919f8
// MS2-PIN: ??_7FilterPrimitive@Render@Scaleform@@6BInterface@RenderQueueItem@12@@ 0x143191a00
// (the deleting dtors named by the base vftables 0x143191940 / 0x1431919b0 / 0x1431919a8 / 0x143191938)
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EG@@Scaleform@@UEAAPEAXI@Z 0x14266c530
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$0EE@@Scaleform@@UEAAPEAXI@Z 0x14266c590
// MS2-PIN: ??_G?$RefCountBase@VPrimitive@Render@Scaleform@@$0EE@@Scaleform@@UEAAPEAXI@Z 0x14266c5f0
// MS2-PIN: ??_G?$RefCountBase@VThreadCommand@Render@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x14266c650
