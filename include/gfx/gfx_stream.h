// Recovered Scaleform 4.1.18 GFx: the SWF input stream and its tag codes
// (only the parts used by recovered units so far; layouts from the exe).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Stream itself is recovered with unit sfr_gfx_03 (0x1425b3380-0x1425c4330); until then its out-of-line members
// bind to the exe: Stream 0x1425c1bf0, ~Stream 0x1425c1d40, Initialize 0x1425c1fc0, ReadRect 0x1425c34e0,
// OpenTag 0x1425c2680 / 0x1425c2540, CloseTag 0x1425c1e80, SetPosition 0x1425c4220, PopulateBuffer 0x1425c27a0,
// ReadStringWithLength 0x1425c3bc0, LogBase<Stream>::LogParse 0x14258e410.
#ifndef MS2_SF_GFX_STREAM_H
#define MS2_SF_GFX_STREAM_H

#include "gfx_log.h"

namespace Scaleform {
class File;
class String;
class MemoryHeap;
namespace Render { template<class T> class Rect; }
namespace GFx {

class ParseControl;

// SWF tag codes (only the ones named by recovered code).
enum TagType
{
    Tag_FileAttributes       = 69,
    Tag_ExporterInfo         = 1000,
    Tag_GFX_TagTableBegin    = 1000
};

// Where OpenTag found a tag.
struct TagInfo
{
    TagType  TagType;       // +0
    unsigned TagOffset;     // +4
    int      TagLength;     // +8
    unsigned TagDataOffset; // +0xc
};

// Buffered reader over a SWF file (0x270 bytes). The inline readers work on the buffer directly and refill it
// through PopulateBuffer; multi-byte values are little endian.
class Stream : public LogBase<Stream>
{
public:
    Stream(File* pinput, MemoryHeap* pheap, Log* plog, ParseControl* pparseControl);
    ~Stream();

    void Initialize(File* pinput, Log* plog, ParseControl* pparseControl);

    void Align() { UnusedBits = 0; }

    SF_FORCEINLINE UInt16 ReadU16()
    {
        Align();
        if (DataSize - Pos < 2)
            PopulateBuffer(2);
        unsigned pos = Pos;
        UInt16   val = (UInt16)(pBuffer[pos] | (pBuffer[pos + 1] << 8));
        Pos = pos + 2;
        return val;
    }
    SF_FORCEINLINE UInt32 ReadU32()
    {
        Align();
        if (DataSize - Pos < 4)
            PopulateBuffer(4);
        unsigned pos = Pos;
        UInt32   val = pBuffer[pos] | (pBuffer[pos + 1] << 8) | (pBuffer[pos + 2] << 16) | (pBuffer[pos + 3] << 24);
        Pos = pos + 4;
        return val;
    }

    // Offset of the read position in the file.
    int  Tell() const { return FilePos - DataSize + Pos; }
    void SetPosition(int pos);

    void    ReadRect(Render::Rect<float>* pr);
    bool    ReadStringWithLength(String* pstr);
    TagType OpenTag();
    TagType OpenTag(TagInfo* ptagInfo);
    void    CloseTag();
    // Reads up to size bytes past the buffered data (exe 0x1425c3c50); returns the count read.
    int     ReadToBuffer(UByte* pdest, unsigned size);
    // The log of the load (exe 0x1425c1f00).
    Log*    GetLog() const;

private:
    bool PopulateBuffer(int size);

    UByte        Unrecovered8[0x29 - 8];
    UByte        UnusedBits;             // +0x29
    UByte        Unrecovered2a[0x4c - 0x2a];
    int          Pos;                    // +0x4c
    int          DataSize;               // +0x50
    int          FilePos;                // +0x54
    UByte        Unrecovered58[8];
    const UByte* pBuffer;                // +0x60
    UByte        Unrecovered68[0x270 - 0x68];
};

}} // namespace Scaleform::GFx

#endif
