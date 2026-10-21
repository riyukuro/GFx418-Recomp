// Recovered Scaleform GFx 4.1.18: the memory report tree (SF_MemItem). Each item has a name, an optional value and
// children; trees from several frames can be merged, scaled, serialised to a File and printed as text or XML.
#ifndef MS2_SF_KERNEL_MEMITEM_H
#define MS2_SF_KERNEL_MEMITEM_H

#include "ms2/scaleform/kernel/sf_refcount.h"
#include "ms2/scaleform/kernel/sf_string.h"
#include "ms2/scaleform/kernel/sf_array.h"
#include "ms2/scaleform/kernel/sf_file.h"

namespace Scaleform {

// image/atlas placement of an item that stands for a texture
struct MemItemExtra : public RefCountBase<MemItemExtra, Stat_Default_Mem>
{
    UInt32 ImageId;           // +0x10
    UInt32 AtlasId;
    SInt32 AtlasRectTop;
    SInt32 AtlasRectBottom;
    SInt32 AtlasRectLeft;
    SInt32 AtlasRectRight;

    MemItemExtra(UInt32 imageId)
        : ImageId(imageId), AtlasId(0), AtlasRectTop(0), AtlasRectBottom(0), AtlasRectLeft(0), AtlasRectRight(0)
    { }

    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
};

struct MemItem : public RefCountBase<MemItem, Stat_Default_Mem>
{
    StringLH              Name;             // +0x10
    UInt32                Value;            // +0x18
    bool                  HasValue;
    bool                  StartExpanded;
    UInt32                ID;               // +0x20
    Ptr<MemItemExtra>     ImageExtraData;   // +0x28
    ArrayLH<Ptr<MemItem>> Children;         // +0x30

    MemItem(UInt32 id) : Value(0), HasValue(false), StartExpanded(false), ID(id) { }

    void     SetValue(UInt32 memValue);
    MemItem* AddChild(UInt32 id, const char* name);
    MemItem* AddChild(UInt32 id, const char* name, UInt32 memValue);
    MemItem* SearchForName(const char* name);
    UInt32   SumValues(const char* name) const;
    UInt32   GetValue(const char* name) const;
    UInt32   GetMaxId() const;

    MemItem& operator=(const MemItem& rhs);   // deep copy
    MemItem& operator/=(unsigned numFrames);
    MemItem& operator*=(unsigned num);
    bool     Merge(const MemItem& other);

    void Read(File& str, UInt32 version);
    void Write(File& str, UInt32 version) const;
    void ToString(StringBuffer* report, UByte indent = 0) const;
    void ToXml(StringBuffer* report, UByte indent = 0) const;
};

}  // namespace Scaleform

#endif
