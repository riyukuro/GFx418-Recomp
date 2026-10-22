// Recovered Scaleform 4.1.18 Render: RectPacker, packs glyph rectangles into fixed size pages (the glyph cache's
// and the font packer's): the rects are sorted tallest first, then every page is filled by a recursive guillotine
// split of its free space (the placed rect, the strip to its right, the space below).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
#ifndef MS2_SF_RENDER_RECTPACKER_H
#define MS2_SF_RENDER_RECTPACKER_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_allocator.h"
#include "ms2/scaleform/include/kernel/sf_arraypaged.h"

namespace Scaleform { namespace Render {

class RectPacker
{
    enum { SID = Stat_Default_Mem };
    enum { Packed = 0x80000000U };   // RectType::Id flag of a placed source rect

public:
    // a source rect: x / y are its width and height; a packed one: x / y are its position
    struct RectType
    {
        unsigned x, y, Id;
    };
    // the packed rects of one page
    struct PackType
    {
        unsigned StartRect;
        unsigned NumRects;
    };

    RectPacker();                                         // 0x1426d7460

    void     SetWidth(unsigned w)  { Width = w; }
    void     SetHeight(unsigned h) { Height = h; }
    unsigned GetWidth() const      { return Width; }
    unsigned GetHeight() const     { return Height; }

    void Clear()
    {
        SrcRects.Clear();
        PackedRects.Clear();
        Packs.Clear();
        PackTree.Clear();
        Failed.Clear();
    }
    void ClearAndRelease()
    {
        SrcRects.ClearAndRelease();
        PackedRects.ClearAndRelease();
        Packs.ClearAndRelease();
        PackTree.ClearAndRelease();
        Failed.ClearAndRelease();
    }

    // a rect that can never fit (empty or bigger than a page) goes straight to the failed list
    void AddRect(unsigned w, unsigned h, unsigned id)
    {
        if (w && h && w <= Width && h <= Height)
        {
            RectType r;
            r.x  = w;
            r.y  = h;
            r.Id = id;
            SrcRects.PushBack(r);
        }
        else
            Failed.PushBack(id);
    }

    void Pack();                                          // 0x1426d7540

    UPInt           GetNumPacks() const              { return Packs.GetSize(); }
    const PackType& GetPack(UPInt packIdx) const     { return Packs[packIdx]; }
    const RectType& GetRect(const PackType& pack, unsigned rectIdx) const
    {
        return PackedRects[pack.StartRect + rectIdx];
    }
    UPInt           GetNumFailed() const             { return Failed.GetSize(); }
    unsigned        GetFailed(UPInt idx) const       { return Failed[idx]; }

    // a free (Id ~0) or used area of the page; Node1 / Node2 are the right strip and the space below
    struct NodeType
    {
        unsigned x, y, Width, Height, Id, Node1, Node2;
    };

private:
    // taller first, then wider first
    static bool cmpRects(const RectType& a, const RectType& b)
    {
        if (b.y != a.y)
            return b.y < a.y;
        return b.x < a.x;
    }

    void packRects(unsigned nodeIdx, unsigned start);           // 0x1426d79c0
    void splitSpace(unsigned nodeIdx, const RectType& rect);    // 0x1426d7c30
    void emitPacked();                                          // 0x1426d78f0

    unsigned                               Width;         // +0x00
    unsigned                               Height;
    unsigned                               NumPacked;
    unsigned                               MinWidth;
    unsigned                               MinHeight;
    ArrayPagedLH_POD<RectType, 8, 64, SID> SrcRects;      // +0x18
    ArrayPagedLH_POD<RectType, 8, 64, SID> PackedRects;
    ArrayPagedLH_POD<PackType, 4, 16, SID> Packs;
    ArrayPagedLH_POD<NodeType, 8, 64, SID> PackTree;
    ArrayPagedLH_POD<unsigned, 6, 64, SID> Failed;
};

}} // namespace Scaleform::Render

#endif
