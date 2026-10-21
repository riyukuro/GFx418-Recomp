// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Render, the mesh key TU
// (Render_MeshKey). A shape layer's mesh is cached under a key made from the scale of its view matrix (or the scale9
// setup); a new view reuses a cached mesh while its key stays within the configured scale tolerances. The keys of
// a provider live in its MeshKeySet, the sets in the MeshKeyManager.
// Queue unit sfr_render_05 is split along its original sources (05d Render_MeshKey).
// MS2-UNIT: sfr_render_05d
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142695030-0x142696790 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "ms2/scaleform/include/kernel/sf_simd.h"
#include "ms2/scaleform/include/render/render_meshkey.h"
#include "ms2/scaleform/include/render/render_toleranceparams.h"

#include <math.h>
#include <string.h>

// the exe calls the CRT atan2f import thunk (0x14280f28e) here; the "atan2f" of the symbol table is the cmath
// float overload wrapper of another TU (0x140a4e660), so the thunk goes by its own name
extern "C" float __cdecl sfr_atan2f_thunk(float y, float x);

namespace Scaleform { namespace Render {

// ----------------------------------------------------------------------------------------------------------------
// MeshKey

// three scale floats (or the scale9 key), then the morph ratio
// @0x142695eb0
unsigned MeshKey::GetKeySize(unsigned flags)
{
    unsigned size = 3;
    if (flags & KF_Scale9Grid)
        size = Scale9GridData::MeshKeySize;
    return size + 1;
}

// whether the cached mesh of this key can stand in for keyData
// @0x142695f00
bool MeshKey::Match(unsigned layer, unsigned flags, const float* keyData, const ToleranceParams& cfg) const
{
    if (flags != Flags || layer != pMesh->GetLayer())
        return false;
    if (flags & KF_Degenerate)
        return true;

    unsigned i;
    if (flags & KF_Scale9Grid)
    {
        // the grid must be the same, the scales within the scale9 range
        for (i = 0; i < 8; ++i)
        {
            if (keyData[i] != Data[i])
                return false;
        }
        for (i = 0; i < 3; ++i)
        {
            if (keyData[i + 8] < Data[i + 8] * cfg.Scale9LowerScale ||
                keyData[i + 8] > Data[i + 8] * cfg.Scale9UpperScale)
                return false;
        }
        for (i = 0; i < 2; ++i)
        {
            if (keyData[i + 11] != Data[i + 11])
                return false;
        }
    }
    else
    {
        unsigned n     = 3;
        float    lower = cfg.FillLowerScale;
        float    upper = cfg.FillUpperScale;
        if ((flags & KF_EdgeAA) == 0 || (flags & KF_Mask) != 0)
        {
            lower = cfg.FillAliasedLowerScale;
            upper = cfg.FillAliasedUpperScale;
        }
        switch (flags & KF_KeyTypeMask)
        {
        case KF_Fill:
            for (i = 0; i < n; ++i)
            {
                if (keyData[i] < Data[i] * lower || keyData[i] > Data[i] * upper)
                    return false;
            }
            break;

        case KF_Stroke:
            lower = cfg.StrokeLowerScale;
            upper = cfg.StrokeUpperScale;
            if (flags & KF_NormalStroke)
            {
                // a uniform rescale (same skew, x / y ratio kept) of a normal stroke may use the fill range
                float sx = keyData[0] * Data[1];
                float sy = keyData[1] * Data[0];
                if (keyData[2] >= Data[2] * 0.999f && keyData[2] <= Data[2] * 1.001f && sx >= sy * 0.999f &&
                    sx <= sy * 1.001f)
                {
                    lower = cfg.FillLowerScale;
                    upper = cfg.FillUpperScale;
                }
            }
            for (i = 0; i < n; ++i)
            {
                if (keyData[i] < Data[i] * lower || keyData[i] > Data[i] * upper)
                    return false;
            }
            break;

        case KF_StrokeHinted:
            for (i = 0; i < n; ++i)
            {
                if (keyData[i] < Data[i] * cfg.HintedStrokeLowerScale ||
                    keyData[i] > Data[i] * cfg.HintedStrokeUpperScale)
                    return false;
            }
            break;
        }
    }

    // the morph ratio comes last
    if (keyData[Size - 1] < Data[Size - 1] * (1 - cfg.MorphTolerance) ||
        keyData[Size - 1] > Data[Size - 1] * (1 + cfg.MorphTolerance))
        return false;
    return true;
}

// The SSE version (no m2 only). With x2 y2 / x3 y3 the images of the x / y axis: sx = |x2 y2|, sy = |x3 y3|, the
// parallelogram height h = |cross| / sx and the shift w = dot / sx; the skew key is 1 + w / h for w >= 0, else
// h / (h - w). Writes four floats.
// MS2-FUNCTIONAL: instruction scheduling of the SSE key (same operations, xmm6/xmm7 save order)
// @0x142695140
bool MeshKey::CalcMatrixKey(const Matrix2F& m, float* key, Matrix2F* m2)
{
    using namespace SIMD;
    if (m2)
        return CalcMatrixKey_NonOpt(m, key, m2);

    static const __declspec(align(16)) float unitY[4] = { 0, 1.0f, 0, 0 };

    Vector4f row0   = _mm_loadu_ps(m.M[0]);
    Vector4f sq0    = _mm_mul_ps(row0, row0);
    Vector4f row1   = _mm_loadu_ps(m.M[1]);
    Vector4f a2     = _mm_shuffle_ps(row0, row1, _MM_SHUFFLE(0, 0, 0, 0));   // x2 x2 y2 y2
    Vector4f a3     = _mm_shuffle_ps(row0, row1, _MM_SHUFFLE(1, 1, 1, 1));   // x3 x3 y3 y3
    Vector4f b2     = _mm_shuffle_ps(row1, row0, _MM_SHUFFLE(0, 0, 0, 0));   // y2 y2 x2 x2
    Vector4f diff   = _mm_sub_ps(a3, a2);
    Vector4f prod   = _mm_mul_ps(a3, a2);
    Vector4f lenSq  = _mm_add_ps(_mm_mul_ps(row1, row1), sq0);              // d2 d3 . .
    Vector4f prodSw = _mm_shuffle_ps(prod, prod, _MM_SHUFFLE(0, 0, 2, 2));
    Vector4f cross  = _mm_mul_ps(diff, b2);
    Vector4f rlen   = _mm_rsqrt_ps(lenSq);
    Vector4f crossS = _mm_shuffle_ps(cross, cross, _MM_SHUFFLE(0, 0, 2, 2));
    Vector4f height = _mm_and_ps(_mm_sub_ps(crossS, cross), Constant<0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF>());
    Vector4f dot    = _mm_add_ps(prod, prodSw);
    Vector4f hw     = _mm_mul_ps(_mm_unpacklo_ps(height, dot), _mm_shuffle_ps(rlen, rlen, _MM_SHUFFLE(0, 0, 0, 0)));
    bool degenerate = (_mm_movemask_ps(_mm_cmpneq_ps(_mm_shuffle_ps(lenSq, hw, _MM_SHUFFLE(0, 0, 1, 0)),
                                                     Constant<0, 0, 0, 0>())) & 0xF) != 0xF;
    Vector4f wwhw   = _mm_shuffle_ps(hw, hw, _MM_SHUFFLE(3, 0, 3, 3));
    Vector4f dhw    = _mm_sub_ps(hw, _mm_and_ps(wwhw, Constant<0xFFFFFFFF, 0, 0, 0>()));
    Vector4f wPos   = _mm_cmpge_ps(wwhw, Constant<0, 0, 0, 0>());
    Vector4f denom  = _mm_shuffle_ps(dhw, rlen, _MM_SHUFFLE(1, 0, 2, 0));    // h-w h 1/sy 1/sx
    Vector4f rcp    = _mm_rcp_ps(denom);
    Vector4f skew   = _mm_add_ps(_mm_mul_ps(hw, rcp), _mm_load_ps(unitY));
    Vector4f skewSw = _mm_shuffle_ps(skew, skew, _MM_SHUFFLE(3, 2, 0, 1));
    Vector4f sel    = _mm_xor_ps(skew, _mm_and_ps(wPos, _mm_xor_ps(skewSw, skew)));
    _mm_storeu_ps(key, _mm_shuffle_ps(rcp, sel, _MM_SHUFFLE(0, 0, 3, 2)));
    return !degenerate;
}

// the scalar version; m2 gets the matrix mapping the unit square onto the key's parallelogram, turned so that its
// longest direction is vertical (the tessellator does better on it)
// MS2-FUNCTIONAL: lb5 oracle compiles it functional only (register allocation in the rotation search)
// @0x142695230
bool MeshKey::CalcMatrixKey_NonOpt(const Matrix2F& m, float* key, Matrix2F* m2)
{
    float x2 = m.Sx();
    float y2 = m.Shy();
    float x3 = m.Shx();
    float y3 = m.Sy();

    float d2 = x2 * x2 + y2 * y2;
    float d3 = x3 * x3 + y3 * y3;
    if (d2 == 0 || d3 == 0)
        return false;

    float sx = sqrtf(d2);
    float h  = fabsf((y3 - y2) * x2 - (x3 - x2) * y2) / sx;
    if (h < 1e-8f)
        return false;

    float w = sx * (x3 * x2 + y3 * y2) / d2;
    key[0]  = sx;
    key[1]  = sqrtf(d3);
    key[2]  = (w >= 0) ? 1 + w / h : h / (h - w);
    if (m2)
    {
        float p[8] = { 0, 0, sx, 0, sx + w, h };
        m2->SetRectToParl(0, 0, 1, 1, p);

        // four candidate directions (0, 45, 90 a bit favoured, 135 degrees)
        p[0] = 1;
        p[1] = 0;
        p[2] = 0.707106781f;
        p[3] = 0.707106781f;
        p[4] = 0;
        p[5] = 1.05f;
        p[6] = -0.707106781f;
        p[7] = 0.707106781f;

        float    longest = 0;
        unsigned best    = 4;
        for (unsigned i = 0; i < 8; i += 2)
        {
            m2->Transform2x2(&p[i + 0], &p[i + 1]);
            d2 = p[i + 0] * p[i + 0] + p[i + 1] * p[i + 1];
            if (d2 > longest)
            {
                longest = d2;
                best    = i;
            }
        }
        m2->AppendRotation(3.141592653589793f / 2 - sfr_atan2f_thunk(p[best + 1], p[best + 0]));
    }
    return true;
}

// the last user gone: drop the key unless its mesh is still cached (scale9 and gradient morph meshes always go)
// @0x1426962c0
void MeshKey::Release()
{
    if (--UseCount == 0)
    {
        if (!pMesh || pMesh->IsEvicted() || (Flags & (KF_Scale9Grid | KF_GradientMorph)))
            pKeySet->DestroyKey(this);
    }
}

// ----------------------------------------------------------------------------------------------------------------
// MeshKeySetHandle

// @0x142696690
void MeshKeySetHandle::releaseCache()
{
    MeshKeyManager* manager = AtomicOps<MeshKeyManager*>::Exchange_NoSync(&pManager, 0);
    if (manager)
    {
        manager->providerLost(*this);
        manager->Release();
    }
}

void MeshKeySetHandle::releaseCache_NoNotify()
{
    MeshKeyManager* manager = AtomicOps<MeshKeyManager*>::Exchange_NoSync(&pManager, 0);
    if (manager)
        manager->Release();
}

// ----------------------------------------------------------------------------------------------------------------
// MeshKeySet

// a new key (variable size: the key floats follow) at the end of the list
// @0x142695590
MeshKey* MeshKeySet::CreateKey(const float* keyData, unsigned flags)
{
    unsigned size = MeshKey::GetKeySize(flags);
    void*    mem  = SF_HEAP_ALLOC(pManager->pRenderHeap, sizeof(MeshKey) + sizeof(float) * (size - 1), StatRender_Mem);
    if (!mem)
        return 0;

    MeshKey* key = Construct<MeshKey>(mem);
    key->pKeySet = this;
    key->Size    = (UInt16)size;
    key->Flags   = (UInt16)flags;
    memcpy(key->Data, keyData, sizeof(float) * size);
    Meshes.PushBack(key);
    return key;
}

// unlinks and frees a key no one uses; an emptied set goes too
// @0x142695c40
void MeshKeySet::DestroyKey(MeshKey* key)
{
    key->RemoveNode();
    if (key->pMesh)
    {
        key->pMesh->ClearProvider();
        key->pMesh.Clear();
    }
    SF_FREE(key);
    if (Meshes.IsEmpty())
        pManager->destroyKeySet(this);
}

// the meshes lose their provider first, so freeing them does not come back into this set
// @0x142695b90
void MeshKeySet::DestroyAllKeys()
{
    MeshKey* key = Meshes.GetFirst();
    MeshKey* next;
    while (!Meshes.IsNull(key))
    {
        if (key->pMesh)
            key->pMesh->ClearProvider();
        key = key->pNext;
    }

    key = Meshes.GetFirst();
    while (!Meshes.IsNull(key))
    {
        next = key->pNext;
        if (key->pMesh)
            key->pMesh.Clear();
        SF_FREE(key);
        key = next;
    }
    Meshes.Clear();
}

// a cached mesh was swapped out: its key goes when unused
void MeshKeySet::OnEvict(MeshBase* mesh)
{
    MeshKey* key = Meshes.GetFirst();
    while (!Meshes.IsNull(key))
    {
        if (mesh == key->pMesh.GetPtr())
        {
            if (key->NotInUse())
                DestroyKey(key);
            break;
        }
        key = key->pNext;
    }
}

// @0x142696560
MeshKey* MeshKeySet::findMatchingKey(unsigned layer, unsigned flags, const float* keyData, const ToleranceParams& cfg)
{
    MeshKey* key = Meshes.GetFirst();
    while (!Meshes.IsNull(key))
    {
        SIMD::PrefetchObj(key->pMesh.GetPtr());
        SIMD::PrefetchObj(key->pNext);
        if (key->Match(layer, flags, keyData, cfg))
            return key;
        key = key->pNext;
    }
    return 0;
}

// render thread, under the manager's lock: detaches the provider (whose handle still points here)
// @0x142696750
void MeshKeySet::releaseDelegate_RenderThread()
{
    if (pDelegate)
    {
        MeshKeySetHandle& handle = pDelegate->hKeySet;
        handle.pKeySet           = 0;
        handle.releaseCache_NoNotify();
        pDelegate = 0;
    }
}

// ----------------------------------------------------------------------------------------------------------------
// MeshKeyManager

// @0x1426959c0
void MeshKeyManager::DestroyAllKeys()
{
    Lock::Locker lock(getLock());
    destroyKeySetList_NTS(KeySet_KillList);
    destroyKeySetList_NTS(KeySet_LiveList);
}

// @0x1426961e0
void MeshKeyManager::ProcessKillList()
{
    Lock::Locker lock(getLock());
    destroyKeySetList_NTS(KeySet_KillList);
}

// the provider's key set is made on first use (and the manager referenced from its handle)
// @0x1426957b0
MeshKey* MeshKeyManager::CreateMatchingKey(MeshProvider_KeySupport* provider, unsigned layer, unsigned flags,
                                           const float* keyData, const ToleranceParams& cfg)
{
    MeshKeySetHandle& handle = provider->hKeySet;
    if (!handle.pManager)
    {
        AddRef();
        handle.pManager = this;
    }
    if (!handle.pKeySet)
    {
        Lock::Locker lock(getLock());
        handle.pKeySet = SF_HEAP_NEW(pRenderHeap) MeshKeySet(this, provider);
        if (!handle.pKeySet)
            return 0;
        KeySets[KeySet_LiveList].PushBack(handle.pKeySet);
    }
    return CreateMatchingKey(handle.pKeySet, layer, flags, keyData, cfg);
}

// a key of the set that matches, referenced, or else a new one
// @0x142695660
MeshKey* MeshKeyManager::CreateMatchingKey(MeshKeySet* keySet, unsigned layer, unsigned flags, const float* keyData,
                                           const ToleranceParams& cfg)
{
    MeshKey* key = keySet->findMatchingKey(layer, flags, keyData, cfg);
    if (key)
    {
        key->AddRef();
        return key;
    }
    return keySet->CreateKey(keyData, flags);
}

// the provider is going away (any thread): its key set, if still there, moves to the kill list
// @0x142696610
void MeshKeyManager::providerLost(MeshKeySetHandle& handle)
{
    Lock::Locker lock(getLock());
    MeshKeySet*  keySet = handle.pKeySet;
    if (!keySet)
        return;
    keySet->RemoveNode();
    KeySets[KeySet_KillList].PushBack(keySet);
    keySet->pDelegate = 0;
    handle.pKeySet    = 0;
}

// @0x142696310
void MeshKeyManager::destroyKeySet(MeshKeySet* keySet)
{
    Lock::Locker lock(getLock());
    keySet->releaseDelegate_RenderThread();
    keySet->RemoveNode();
    delete keySet;
    if (!KeySets[KeySet_KillList].IsEmpty())
        destroyKeySetList_NTS(KeySet_KillList);
}

// frees one list; the sets are taken over into a local list first, as freeing their meshes can come back here
// @0x142696450
void MeshKeyManager::destroyKeySetList_NTS(KeySetListType type)
{
    if (KeySets[type].IsEmpty())
        return;

    List<MeshKeySet> list;
    list.PushListToFront(KeySets[type]);
    do
    {
        MeshKeySet* keySet = list.GetFirst();
        if (type != KeySet_KillList)
            keySet->releaseDelegate_RenderThread();
        keySet->RemoveNode();
        delete keySet;
    } while (!list.IsEmpty());
}

}} // namespace Scaleform::Render
// MS2-PIN: ??_7MeshProvider@Render@Scaleform@@6B@ 0x14318f0c0
// MS2-PIN: ??_7MeshKeySet@Render@Scaleform@@6B@ 0x1431922d0
