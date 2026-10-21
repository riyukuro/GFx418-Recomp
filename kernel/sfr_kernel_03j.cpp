// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, HeapMH_FreeBin (the MH page
// allocator's free lists: one ring per block count, the last ring takes everything longer). Our own source, written
// from the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03j
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426efb10-0x1426f0160 .text$mn
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/heapmh/sf_heapmh_freebin.h"

namespace Scaleform { namespace HeapMH {

ListBinMH::ListBinMH()
{
    Reset();
}

void ListBinMH::Reset()
{
    Mask = 0;
    memset(Roots, 0, sizeof(Roots));
}

// the links carry the size bits, so they are always rewritten through SetPrev/SetNext
SF_INLINE void ListBinMH::pushNode(UPInt idx, BinNodeMH* node)
{
    BinNodeMH* root = Roots[idx];
    if (root)
    {
        node->SetPrev(root);
        node->SetNext(root->GetNext());
        root->GetNext()->SetPrev(node);
        root->SetNext(node);
    }
    else
    {
        node->SetPrev(node);
        node->SetNext(node);
    }
    Roots[idx] = node;
    Mask |= UPInt(1) << idx;
}

SF_INLINE void ListBinMH::pullNode(UPInt idx, BinNodeMH* node)
{
    BinNodeMH* root = Roots[idx];
    if (node != root)
    {
        node->GetPrev()->SetNext(node->GetNext());
        node->GetNext()->SetPrev(node->GetPrev());
        return;
    }
    if (root != root->GetNext())
    {
        Roots[idx] = root->GetNext();
        node->GetPrev()->SetNext(node->GetNext());
        node->GetNext()->SetPrev(node->GetPrev());
        return;
    }
    Roots[idx] = 0;
    Mask &= ~(UPInt(1) << idx);
}

UByte* ListBinMH::GetAlignedPtr(UByte* start, UPInt alignMask)
{
    UPInt aligned = (UPInt(start) + alignMask) & ~alignMask;
    return (UByte*)aligned;
}

bool ListBinMH::AlignmentIsOK(const BinNodeMH* node, UPInt blocks, UPInt alignMask)
{
    UPInt bytes   = blocks << PageMH::UnitShift;
    UPInt aligned = UPInt(GetAlignedPtr((UByte*)node, alignMask));
    return aligned + bytes <= UPInt(node) + node->GetBytes();
}

BinNodeMH* ListBinMH::findAligned(BinNodeMH* root, UPInt blocks, UPInt alignMask)
{
    BinNodeMH* node = root;
    if (node) do
    {
        if (AlignmentIsOK(node, blocks, alignMask))
            return node;
        node = node->GetNext();
    } while (node != root);
    return 0;
}

// the root of the first non-empty ring that is big enough
BinNodeMH* ListBinMH::PullBest(UPInt blocks)
{
    UPInt      idx  = Alg::Min<UPInt>(blocks - 1, BinSize - 1);
    BinNodeMH* best = 0;
    UPInt      bits = Mask >> idx;
    if (bits)
    {
        UPInt i = idx + Alg::LowerBit(bits);
        best    = Roots[i];
        pullNode(i, best);
    }
    return best;
}

BinNodeMH* ListBinMH::PullBest(UPInt blocks, UPInt alignMask)
{
    UPInt      idx  = Alg::Min<UPInt>(blocks - 1, BinSize - 1);
    BinNodeMH* best = 0;
    UPInt      bits = Mask >> idx;
    if (bits)
    {
        UPInt i = idx + Alg::LowerBit(bits);
        do
        {
            best = findAligned(Roots[i], blocks, alignMask);
            if (best)
            {
                pullNode(i, best);
                break;
            }
        } while (++i < BinSize);
    }
    return best;
}

void ListBinMH::Push(UByte* node)
{
    BinNodeMH* tn     = (BinNodeMH*)node;
    UPInt      blocks = tn->GetBlocks();
    pushNode(Alg::Min<UPInt>(blocks - 1, BinSize - 1), tn);
}

void ListBinMH::Pull(UByte* node)
{
    BinNodeMH* tn     = (BinNodeMH*)node;
    UPInt      blocks = tn->GetBlocks();
    pullNode(Alg::Min<UPInt>(blocks - 1, BinSize - 1), tn);
}

SF_INLINE BinNodeMH* ListBinMH::getPrevAdjacent(UByte* node) const
{
    return (BinNodeMH*)(node - ((BinNodeMH*)node)->GetPrevBytes());
}

SF_INLINE BinNodeMH* ListBinMH::getNextAdjacent(UByte* node) const
{
    return (BinNodeMH*)(node + ((BinNodeMH*)node)->GetBytes());
}

// the freed block's size is written first so its neighbours can be found from it
void ListBinMH::Merge(UByte* node, UPInt bytes, bool left, bool right, PageMH* page)
{
    BinNodeMH* mergeNode = (BinNodeMH*)node;
    UPInt      mergeSize = bytes >> PageMH::UnitShift;
    mergeNode->SetBlocks(mergeSize);
    if (left)
    {
        mergeNode  = getPrevAdjacent(node);
        mergeSize += mergeNode->GetBlocks();
        Pull((UByte*)mergeNode);
    }
    if (right)
    {
        BinNodeMH* nextAdjacent = getNextAdjacent(node);
        mergeSize += nextAdjacent->GetBlocks();
        Pull((UByte*)nextAdjacent);
    }
    mergeNode->SetBlocks(mergeSize);
    mergeNode->SetPage(page);
    pushNode(Alg::Min<UPInt>(mergeSize - 1, BinSize - 1), mergeNode);
}

}}  // namespace Scaleform::HeapMH
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0ListBinMH@HeapMH@Scaleform@@QEAA@XZ 0x1426efb10
// MS2-PIN: ?GetAlignedPtr@ListBinMH@HeapMH@Scaleform@@SAPEAEPEAE_K@Z 0x1426efb80
// MS2-PIN: ?Merge@ListBinMH@HeapMH@Scaleform@@QEAAXPEAE_K_N2PEAUPageMH@23@@Z 0x1426efb90
// MS2-PIN: ?Pull@ListBinMH@HeapMH@Scaleform@@QEAAXPEAE@Z 0x1426efd50
// MS2-PIN: ?PullBest@ListBinMH@HeapMH@Scaleform@@QEAAPEAUBinNodeMH@23@_K0@Z 0x1426efe20
// MS2-PIN: ?PullBest@ListBinMH@HeapMH@Scaleform@@QEAAPEAUBinNodeMH@23@_K@Z 0x1426eff90
// MS2-PIN: ?Push@ListBinMH@HeapMH@Scaleform@@QEAAXPEAE@Z 0x1426f0050
// MS2-PIN: ?findAligned@ListBinMH@HeapMH@Scaleform@@AEAAPEAUBinNodeMH@23@PEAU423@_K1@Z 0x1426f0100
// MS2-PIN: ?AlignmentIsOK@ListBinMH@HeapMH@Scaleform@@SA_NPEBUBinNodeMH@23@_K1@Z 0x1426efb40
