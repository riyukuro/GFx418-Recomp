// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_MemItem (the memory
// report tree). Our own source, written from the exe. Queue unit sfr_kernel_03 is split along its original sources.
// MS2-UNIT: sfr_kernel_03m
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1426de710-0x1426dffe0 .text$mn   (0x1426dffe0-0x1426e00c0: RenderQueue ctors/dtor, not this TU)
#include <string.h>
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include "ms2/scaleform/kernel/sf_msgformat.h"
#include "ms2/scaleform/kernel/sf_memitem.h"

namespace Scaleform {

void MemItem::SetValue(UInt32 memValue)
{
    Value    = memValue;
    HasValue = true;
}

// children live in the heap of their parent
MemItem* MemItem::AddChild(UInt32 id, const char* name)
{
    MemItem* child = SF_HEAP_AUTO_NEW(this) MemItem(id);
    child->Name    = name;
    Children.PushBack(*child);
    return child;
}

MemItem* MemItem::AddChild(UInt32 id, const char* name, UInt32 memValue)
{
    MemItem* child = SF_HEAP_AUTO_NEW(this) MemItem(id);
    child->Name    = name;
    child->SetValue(memValue);
    Children.PushBack(*child);
    return child;
}

// depth first, this item first
MemItem* MemItem::SearchForName(const char* name)
{
    if (Name == name)
        return this;
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        MemItem* childFound = Children[i]->SearchForName(name);
        if (childFound != NULL)
            return childFound;
    }
    return NULL;
}

// the value of a matching item, or the sum over the children
UInt32 MemItem::SumValues(const char* name) const
{
    if (Name == name)
        return Value;
    UInt32 sum = 0;
    for (UPInt i = 0; i < Children.GetSize(); ++i)
        sum += Children[i]->SumValues(name);
    return sum;
}

// the first nonzero value of a matching item
UInt32 MemItem::GetValue(const char* name) const
{
    if (Name == name)
        return Value;
    for (UPInt i = 0; i < Children.GetSize(); ++i)
    {
        UInt32 childValue = Children[i]->GetValue(name);
        if (childValue != 0)
            return childValue;
    }
    return 0;
}

UInt32 MemItem::GetMaxId() const
{
    UInt32 maxId = ID;
    for (UPInt i = 0; i < Children.GetSize(); ++i)
        maxId = Alg::Max(maxId, Children[i]->GetMaxId());
    return maxId;
}

MemItem& MemItem::operator=(const MemItem& rhs)
{
    Name          = rhs.Name;
    Value         = rhs.Value;
    HasValue      = rhs.HasValue;
    StartExpanded = rhs.StartExpanded;
    ID            = rhs.ID;
    if (rhs.ImageExtraData)
    {
        ImageExtraData  = *SF_HEAP_AUTO_NEW(this) MemItemExtra(0);
        *ImageExtraData = *rhs.ImageExtraData;
    }
    else
    {
        ImageExtraData = NULL;
    }
    Children.Clear();
    for (UPInt i = 0; i < rhs.Children.GetSize(); ++i)
    {
        MemItem* newChild = SF_HEAP_AUTO_NEW(this) MemItem(rhs.Children[i]->ID);
        *newChild         = *rhs.Children[i];
        Children.PushBack(*newChild);
    }
    return *this;
}

MemItem& MemItem::operator/=(unsigned numFrames)
{
    Value /= numFrames;
    for (UPInt i = 0; i < Children.GetSize(); ++i)
        *Children[i] /= numFrames;
    return *this;
}

MemItem& MemItem::operator*=(unsigned num)
{
    Value *= num;
    for (UPInt i = 0; i < Children.GetSize(); ++i)
        *Children[i] *= num;
    return *this;
}

// add other into this tree when the names match (an empty item just becomes a copy); unmatched children are copied
bool MemItem::Merge(const MemItem& other)
{
    if (!HasValue && Name.IsEmpty() && Children.GetSize() == 0)
    {
        *this = other;
        return true;
    }
    if (other.Name != Name)
        return false;

    Value += other.Value;
    HasValue = (HasValue || other.HasValue);
    for (UPInt i = 0; i < other.Children.GetSize(); ++i)
    {
        bool merged = false;
        for (UPInt j = 0; j < Children.GetSize(); ++j)
        {
            if (Children[j]->Merge(*other.Children[i]))
            {
                merged = true;
                break;
            }
        }
        if (!merged)
        {
            MemItem* newItem = SF_HEAP_AUTO_NEW(this) MemItem(other.Children[i]->ID);
            *newItem         = *other.Children[i];
            Children.PushBack(*newItem);
        }
    }
    return true;
}

// stream format: name length + chars, flags, value, id, then (version > 11) an optional extra record or (older) a
// bare image id, then the children
void MemItem::Read(File& str, UInt32 version)
{
    UInt32 stringLength = str.ReadUInt32();
    for (UInt32 i = 0; i < stringLength; ++i)
        Name.AppendChar(str.ReadSByte());
    HasValue      = (str.ReadUByte() != 0);
    StartExpanded = (str.ReadUByte() != 0);
    Value         = str.ReadUInt32();
    ID            = str.ReadUInt32();
    if (version > 11)
    {
        UByte hasData = str.ReadUByte();
        if (hasData != 0)
        {
            ImageExtraData = *SF_HEAP_AUTO_NEW(this) MemItemExtra(0);
            ImageExtraData->Read(str, version);
        }
    }
    else
    {
        UInt32 imageId = str.ReadUInt32();
        if (imageId != 0)
            ImageExtraData = *SF_HEAP_AUTO_NEW(this) MemItemExtra(imageId);
    }
    UInt32 numChildren = str.ReadUInt32();
    Children.Resize(numChildren);
    for (UInt32 i = 0; i < numChildren; ++i)
    {
        Children[i] = *SF_HEAP_AUTO_NEW(this) MemItem(0);
        Children[i]->Read(str, version);
    }
}

void MemItem::Write(File& str, UInt32 version) const
{
    str.WriteUInt32(static_cast<UInt32>(Name.GetLength()));
    for (UPInt i = 0; i < Name.GetLength(); ++i)
        str.WriteSByte(Name[i]);
    str.WriteUByte(HasValue ? 1 : 0);
    str.WriteUByte(StartExpanded ? 1 : 0);
    str.WriteUInt32(Value);
    str.WriteUInt32(ID);
    if (version > 11)
    {
        if (ImageExtraData)
        {
            str.WriteUByte(1);
            ImageExtraData->Write(str, version);
        }
        else
        {
            str.WriteUByte(0);
        }
    }
    else
    {
        if (ImageExtraData)
            str.WriteUInt32(ImageExtraData->ImageId);
        else
            str.WriteUInt32(0);
    }
    str.WriteUInt32(static_cast<UInt32>(Children.GetSize()));
    for (UPInt i = 0; i < Children.GetSize(); ++i)
        Children[i]->Write(str, version);
}

// indented name, the value right-aligned at column 50, then the children 4 deeper
void MemItem::ToString(StringBuffer* report, UByte indent) const
{
    Array<char> sft(indent + 1);
    memset(&sft[0], ' ', indent);
    sft[indent] = '\0';
    report->AppendString(&sft[0]);
    report->AppendString(Name.ToCStr());
    if (HasValue)
    {
        const unsigned tabSize   = 50;
        unsigned       numSpaces = tabSize - Alg::Min(static_cast<unsigned>(Name.GetLength()) + indent, tabSize);
        sft.Resize(numSpaces + 1);
        memset(&sft[0], ' ', numSpaces);
        sft[numSpaces] = '\0';
        report->AppendString(&sft[0]);
        Format(*report, " {0:sep:,}", Value);
    }
    report->AppendChar('\n');
    for (UPInt i = 0; i < Children.GetSize(); ++i)
        Children[i]->ToString(report, indent + 4);
}

void MemItem::ToXml(StringBuffer* report, UByte indent) const
{
    Array<char> sft(indent + 1);
    memset(&sft[0], ' ', indent);
    sft[indent]  = '\0';
    char* indStr = &sft[0];
    if (HasValue)
        Format(*report, "{0}<MemItem Name=\"{1}\" Value={2}>", indStr, Name, Value);
    else
        Format(*report, "{0}<MemItem Name=\"{1}\">", indStr, Name);
    if (Children.GetSize() > 0)
    {
        report->AppendChar('\n');
        for (UPInt i = 0; i < Children.GetSize(); ++i)
            Children[i]->ToXml(report, indent + 4);
        Format(*report, "{0}</MemItem>\n", indStr);
    }
    else
    {
        report->AppendString("</MemItem>\n");
    }
}

void MemItemExtra::Read(File& str, UInt32 version)
{
    ImageId = str.ReadUInt32();
    if (version > 11)
    {
        AtlasId         = str.ReadUInt32();
        AtlasRectLeft   = str.ReadSInt32();
        AtlasRectTop    = str.ReadSInt32();
        AtlasRectRight  = str.ReadSInt32();
        AtlasRectBottom = str.ReadSInt32();
    }
}

void MemItemExtra::Write(File& str, UInt32 version) const
{
    str.WriteUInt32(ImageId);
    if (version > 11)
    {
        str.WriteUInt32(AtlasId);
        str.WriteSInt32(AtlasRectLeft);
        str.WriteSInt32(AtlasRectTop);
        str.WriteSInt32(AtlasRectRight);
        str.WriteSInt32(AtlasRectBottom);
    }
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??$FormatD1@PEAD@MsgFormat@Scaleform@@QEAAXAEBQEAD@Z 0x1426de710
// MS2-PIN: ??$FormatD1@VStringLH@Scaleform@@@MsgFormat@Scaleform@@QEAAXAEBVStringLH@1@@Z 0x1426de800
// MS2-PIN: ??4MemItem@Scaleform@@QEAAAEAU01@AEBU01@@Z 0x1426de8f0
// MS2-PIN: ??XMemItem@Scaleform@@QEAAAEAU01@I@Z 0x1426deb00
// MS2-PIN: ??_0MemItem@Scaleform@@QEAAAEAU01@I@Z 0x1426deb60
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1426debc0
// MS2-PIN: ??_GMemItemExtra@Scaleform@@UEAAPEAXI@Z 0x1426dec20
// MS2-PIN: ?AddChild@MemItem@Scaleform@@QEAAPEAU12@KPEBD@Z 0x1426dec80
// MS2-PIN: ?AddChild@MemItem@Scaleform@@QEAAPEAU12@KPEBDK@Z 0x1426ded70
// MS2-PIN: ?GetMaxId@MemItem@Scaleform@@QEBAKXZ 0x1426dee60
// MS2-PIN: ?GetValue@MemItem@Scaleform@@QEBAKPEBD@Z 0x1426deec0
// MS2-PIN: ?Merge@MemItem@Scaleform@@QEAA_NAEBU12@@Z 0x1426def50
// MS2-PIN: ?Read@MemItem@Scaleform@@QEAAXAEAVFile@2@K@Z 0x1426df150
// MS2-PIN: ?Read@MemItemExtra@Scaleform@@QEAAXAEAVFile@2@K@Z 0x1426df520
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@UMemItem@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@UMemItem@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1426df610
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@V?$Ptr@UMemItem@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@UMemItem@Scaleform@@@Scaleform@@$01@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x1426df730
// MS2-PIN: ?SearchForName@MemItem@Scaleform@@QEAAPEAU12@PEBD@Z 0x1426df7d0
// MS2-PIN: ?SumValues@MemItem@Scaleform@@QEBAKPEBD@Z 0x1426df870
// MS2-PIN: ?ToString@MemItem@Scaleform@@QEBAXPEAVStringBuffer@2@E@Z 0x1426df910
// MS2-PIN: ?ToXml@MemItem@Scaleform@@QEBAXPEAVStringBuffer@2@E@Z 0x1426dfac0
// MS2-PIN: ?Write@MemItem@Scaleform@@QEBAXAEAVFile@2@K@Z 0x1426dfcc0
// MS2-PIN: ?Write@MemItemExtra@Scaleform@@QEBAXAEAVFile@2@K@Z 0x1426dff00
// MS2-PIN: ??_7MemItem@Scaleform@@6B@ 0x143192160
// MS2-PIN: ??_7MemItemExtra@Scaleform@@6B@ 0x143193df8
// MS2-PIN: ??_7?$RefCountBase@UMemItemExtra@Scaleform@@$01@Scaleform@@6B@ 0x143193df0
// MS2-PIN: ??_7?$RefCountBase@UMemItem@Scaleform@@$01@Scaleform@@6B@ 0x143193df0
