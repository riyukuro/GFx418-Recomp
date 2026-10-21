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
#include "../kernel/sf_file.h"

namespace Scaleform {
class File;
class String;
class MemoryHeap;
namespace Render { template<class T> class Rect; template<class T> class Matrix2x4; class Cxform; class Color; }
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

// Buffered reader over a SWF file or a memory block (0x270 bytes, vftable 0x14318a178). The inline readers work on
// the buffer directly and refill it through PopulateBuffer; multi-byte values are little endian. Bodies in sfr_gfx_03.
class Stream : public LogBase<Stream>
{
public:
    Stream(File* pinput, MemoryHeap* pheap, Log* plog, ParseControl* pparseControl);
    Stream(const UByte* pbuffer, unsigned bufSize, MemoryHeap* pheap, Log* plog, ParseControl* pparseControl);
    ~Stream();

    void Initialize(File* pinput, Log* plog, ParseControl* pparseControl);
    void ShutDown();

    void Align() { UnusedBits = 0; }

    unsigned ReadUInt(unsigned bitcount);
    int      ReadSInt(unsigned bitcount);
    unsigned ReadUInt1();

    SF_FORCEINLINE UByte ReadU8()
    {
        Align();
        if ((int)(DataSize - Pos) < 1)
            PopulateBuffer(1);
        return pBuffer[Pos++];
    }
    SF_FORCEINLINE UInt16 ReadU16()
    {
        Align();
        if ((int)(DataSize - Pos) < 2)
            PopulateBuffer(2);
        unsigned pos = Pos;
        UInt16   val = (UInt16)(pBuffer[pos] | (pBuffer[pos + 1] << 8));
        Pos = pos + 2;
        return val;
    }
    SF_FORCEINLINE UInt32 ReadU32()
    {
        Align();
        if ((int)(DataSize - Pos) < 4)
            PopulateBuffer(4);
        unsigned pos = Pos;
        UInt32   val = pBuffer[pos] | (pBuffer[pos + 1] << 8) | (pBuffer[pos + 2] << 16) | (pBuffer[pos + 3] << 24);
        Pos = pos + 4;
        return val;
    }
    SF_FORCEINLINE SInt32 ReadS32() { return (SInt32)ReadU32(); }

    // Variable-length (7 bits per byte) integers of the AS3 byte code. Spelled long: the exe's UInt32/SInt32 are
    // the Win64 long types (mangled K/J), which the include tree's typedefs are not.
    unsigned long ReadVU32();
    long          ReadVS32();
    double ReadDouble();

    // Offset of the read position in the file.
    int  Tell() const { return FilePos - DataSize + Pos; }
    int  GetTagEndPosition();
    void SetPosition(int pos);

    TagType OpenTag();
    TagType OpenTag(TagInfo* ptagInfo);
    void    CloseTag();

    bool  ReadString(String* pstr);
    bool  ReadStringWithLength(String* pstr);
    // Strings allocated from pheap (0 for an empty length-prefixed one).
    char* ReadString(MemoryHeap* pheap);
    char* ReadStringWithLength(MemoryHeap* pheap);

    // Seeks the file back to the read position after it was used directly.
    void SyncFileStream();

    void ReadMatrix(Render::Matrix2x4<float>* pm);
    void ReadCxformRgb(Render::Cxform* pcxform);
    void ReadCxformRgba(Render::Cxform* pcxform);
    void ReadRect(Render::Rect<float>* pr);
    void ReadRgb(Render::Color* pc);
    void ReadRgba(Render::Color* pc);

    // Reads up to size bytes, buffered data first; the part the file cannot supply is zero filled. Returns the
    // count read.
    int  ReadToBuffer(UByte* pdest, unsigned size);
    // The log of the load (exe 0x1425c1f00).
    Log* GetLog() const;

    bool IsVerboseParse() const;
    bool IsVerboseParseShape() const;
    bool IsVerboseParseMorphShape() const;
    bool IsVerboseParseAction() const;

    // Parse log output (verbose parse builds): hex dump of the rest of the tag / of the next bytes, and values.
    void LogTagBytes();
    void LogBytes(unsigned numOfBytes);
    void LogParseClass(const Render::Color& color);
    void LogParseClass(const Render::Rect<float>& rect);
    void LogParseClass(const Render::Cxform& cxform);
    void LogParseClass(const Render::Matrix2x4<float>& matrix);

    ParseControl* GetParseControl() const { return pParseControl; }

private:
    bool PopulateBuffer(int size);
    bool PopulateBuffer1();

    enum
    {
        Stream_TagStackSize = 2,
        Stream_BufferSize   = 512
    };

    Log*          pLog;                               // +8
    ParseControl* pParseControl;                      // +0x10
    unsigned      ParseFlags;                         // +0x18 ParseControl flags at construction
    Ptr<File>     pInput;                             // +0x20
    UByte         CurrentByte;                        // +0x28 bits not consumed yet by ReadUInt
    UByte         UnusedBits;                         // +0x29
    StringDH      FileName;                           // +0x30
    int           TagStack[Stream_TagStackSize];      // +0x40 end positions of the open tags
    unsigned      TagStackEntryCount;                 // +0x48
    unsigned      Pos;                                // +0x4c read position in the buffer
    unsigned      DataSize;                           // +0x50 bytes in the buffer
    unsigned      FilePos;                            // +0x54 file position of the buffer end
    bool          ResyncFile;                         // +0x58
    UByte*        pBuffer;                            // +0x60 BuiltinBuffer or the memory block
    unsigned      BufferSize;                         // +0x68
    UByte         BuiltinBuffer[Stream_BufferSize];   // +0x6c
};

// Bit reader over a memory block, used by the shape and morph parsers (0x20 bytes).
class StreamContext
{
public:
    const UByte* pData;        // +0
    UPInt        DataSize;     // +8
    UPInt        CurByteIndex; // +0x10
    unsigned     CurBitIndex;  // +0x18

    StreamContext(const UByte* pdata) : pData(pdata), DataSize(~0u), CurByteIndex(0), CurBitIndex(0) {}

    void Align()
    {
        if (CurBitIndex)
            ++CurByteIndex;
        CurBitIndex = 0;
    }
    // The bit, unshifted (non-zero when set).
    unsigned ReadUInt1()
    {
        unsigned v = pData[CurByteIndex] & (1 << (7 - CurBitIndex));
        if (++CurBitIndex >= 8)
        {
            ++CurByteIndex;
            CurBitIndex = 0;
        }
        return v;
    }
    unsigned ReadUInt(unsigned bitcount);
    int      ReadSInt(unsigned bitcount)
    {
        unsigned v = ReadUInt(bitcount);
        if (v & (1 << (bitcount - 1)))
            v |= ~0u << bitcount;
        return (int)v;
    }

    void ReadMatrix(Render::Matrix2x4<float>* pm);
    void ReadCxformRgb(Render::Cxform* pcxform);
    void ReadCxformRgba(Render::Cxform* pcxform);
};

}} // namespace Scaleform::GFx

#endif
