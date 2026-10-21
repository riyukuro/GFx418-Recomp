// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 GFx_Stream (the SWF stream
// reader and the StreamContext bit reader; this build logs parsing, so the verbose-parse dumpers are in).
// Queue unit sfr_gfx_03 is split along its original sources: this file is GFx_Stream.
// MS2-UNIT: sfr_gfx_03
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x1425c1bf0-0x1425c1d30 .text$mn
// MS2-RANGE: 0x1425c1d40-0x1425c1d95 .text$mn
// MS2-RANGE: 0x1425c1da0-0x1425c2080 .text$mn
// MS2-RANGE: 0x1425c20a0-0x1425c34d0 .text$mn
// MS2-RANGE: 0x1425c34e0-0x1425c4320 .text$mn

#include "../include/kernel/sf_std.h"
#include "../include/gfx/gfx_stream.h"
#include "../include/gfx/gfx_loaderimpl.h"
#include "../include/kernel/sf_array.h"
#include "../include/render/render_color.h"
#include "../include/render/render_cxform.h"
#include "../include/render/render_matrix2x4.h"
#include "../include/render/render_twips.h"

namespace Scaleform { namespace GFx {

//
// Stream
//

// @0x1425c1bf0
Stream::Stream(File* pinput, MemoryHeap* pheap, Log* plog, ParseControl* pparseControl) : FileName(pheap)
{
    pBuffer    = BuiltinBuffer;
    BufferSize = sizeof(BuiltinBuffer);
    Initialize(pinput, plog, pparseControl);
}

// Reads from the memory block instead of a file.
// @0x1425c1c60
Stream::Stream(const UByte* pbuffer, unsigned bufSize, MemoryHeap* pheap, Log* plog, ParseControl* pparseControl)
    : FileName(pheap)
{
    pBuffer = (UByte*)pbuffer;
    if (!pbuffer)
        bufSize = 0;
    BufferSize = bufSize;
    Initialize(0, plog, pparseControl);
    DataSize = BufferSize;
    FilePos  = BufferSize;
}

// @0x1425c1d40
Stream::~Stream()
{
}

// @0x1425c1fc0
void Stream::Initialize(File* pinput, Log* plog, ParseControl* pparseControl)
{
    pInput        = pinput;
    pLog          = plog;
    pParseControl = pparseControl;
    ParseFlags    = pparseControl ? pparseControl->ParseFlags : 0;
    CurrentByte   = 0;
    UnusedBits    = 0;
    if (pinput)
        FileName = pinput->GetFilePath();
    else
        FileName.Clear();
    TagStackEntryCount = 0;
    TagStack[0]        = 0;
    TagStack[1]        = 0;
    Pos                = 0;
    DataSize           = 0;
    ResyncFile         = false;
    FilePos            = pinput ? pinput->Tell() : 0;
}

// @0x1425c42a0
void Stream::ShutDown()
{
    FileName.Clear();
    pInput        = 0;
    pLog          = 0;
    pParseControl = 0;
}

// @0x1425c1f00
Log* Stream::GetLog() const
{
    return pLog;
}

// @0x1425c2090
bool Stream::IsVerboseParse() const
{
    return (ParseFlags & 0x01) != 0;
}

// @0x1425c20a0
bool Stream::IsVerboseParseAction() const
{
    return (ParseFlags & 0x02) != 0;
}

// @0x1425c20c0
bool Stream::IsVerboseParseShape() const
{
    return (ParseFlags & 0x10) != 0;
}

// @0x1425c20b0
bool Stream::IsVerboseParseMorphShape() const
{
    return (ParseFlags & 0x20) != 0;
}

// Moves the unread bytes to the front and fills the rest of the buffer; returns whether size bytes are now
// available. With no file (memory block) the buffer is reset to zeroes.
// @0x1425c27a0
// MS2-FUNCTIONAL: the exe stores Pos = 0 before loading pInput; this build loads pInput first (same effect)
bool Stream::PopulateBuffer(int size)
{
    if (DataSize == 0 && pInput)
    {
        FilePos    = pInput->Tell();
        ResyncFile = false;
    }
    if (Pos < DataSize)
    {
        memmove(pBuffer, pBuffer + Pos, DataSize - Pos);
        DataSize -= Pos;
    }
    else
        DataSize = 0;
    Pos = 0;

    if (pInput)
    {
        int toRead    = BufferSize - DataSize;
        int readBytes = pInput->Read(pBuffer + DataSize, toRead);
        if (readBytes < toRead)
        {
            if (readBytes > 0)
            {
                DataSize += readBytes;
                FilePos += readBytes;
            }
            memset(pBuffer + DataSize, 0, BufferSize - DataSize);
            // Short read: pretend the zero fill is data so the caller can go on.
            bool result = size <= (int)(DataSize - Pos);
            if (!result)
                DataSize = Pos + size;
            return result;
        }
        DataSize += readBytes;
        FilePos += readBytes;
        return true;
    }

    pBuffer    = BuiltinBuffer;
    BufferSize = sizeof(BuiltinBuffer);
    memset(pBuffer, 0, BufferSize);
    FilePos += BufferSize;
    DataSize = BufferSize;
    Pos      = 0;
    return false;
}

// @0x1425c2790
bool Stream::PopulateBuffer1()
{
    return PopulateBuffer(1);
}

// @0x1425c3c50
int Stream::ReadToBuffer(UByte* pdest, unsigned size)
{
    int readBytes = 0;
    if (DataSize == 0)
    {
        FilePos    = pInput->Tell();
        ResyncFile = false;
    }
    if (Pos < DataSize)
    {
        unsigned n = Alg::Min(size, DataSize - Pos);
        memmove(pdest, pBuffer + Pos, n);
        Pos += n;
        pdest += n;
        size -= n;
        readBytes = n;
    }
    if (Pos >= DataSize)
    {
        Pos      = 0;
        DataSize = 0;
    }

    if (size)
    {
        int r = pInput->Read(pdest, size);
        FilePos += r;
        readBytes += r;
        if (r < (int)size)
            memset(pdest + r, 0, size - r);
    }
    return readBytes;
}

// @0x1425c3db0
unsigned Stream::ReadUInt(unsigned bitcount)
{
    unsigned value      = 0;
    int      bitsNeeded = bitcount;
    while (bitsNeeded > 0)
    {
        if (UnusedBits)
        {
            if (bitsNeeded >= UnusedBits)
            {
                bitsNeeded -= UnusedBits;
                value |= CurrentByte << bitsNeeded;
                UnusedBits = 0;
            }
            else
            {
                int shift = UnusedBits - bitsNeeded;
                bitsNeeded = 0;
                value |= CurrentByte >> shift;
                CurrentByte &= (1 << shift) - 1;
                UnusedBits = (UByte)shift;
            }
        }
        else
        {
            CurrentByte = ReadU8();
            UnusedBits  = 8;
        }
    }
    return value;
}

// @0x1425c3790
int Stream::ReadSInt(unsigned bitcount)
{
    int value = (int)ReadUInt(bitcount);
    if (value & (1 << (bitcount - 1)))
        value |= -1 << bitcount;
    return value;
}

// @0x1425c3d20
unsigned Stream::ReadUInt1()
{
    unsigned result;
    if (UnusedBits == 0)
    {
        UByte b     = ReadU8();
        result      = b >> 7;
        UnusedBits  = 7;
        CurrentByte = b & 0x7f;
    }
    else
    {
        UByte b     = CurrentByte;
        UnusedBits--;
        result      = b >> UnusedBits;
        CurrentByte = b & ((1 << UnusedBits) - 1);
    }
    return result;
}

// @0x1425c4100
unsigned long Stream::ReadVU32()
{
    unsigned long result = 0;
    unsigned shift  = 0;
    UByte    b;
    do
    {
        b = ReadU8();
        result |= (b & 0x7f) << shift;
        shift += 7;
    } while (shift < 32 && (b & 0x80));
    return result;
}

// @0x1425c4070
long Stream::ReadVS32()
{
    unsigned long result = 0;
    unsigned      shift  = 0;
    UByte         b;
    do
    {
        b = ReadU8();
        result |= (b & 0x7f) << shift;
        shift += 7;
    } while (shift < 32 && (b & 0x80));
    if (b & 0x40)
        return (long)result - (long)(1 << shift); // sign-extend
    return (long)result;
}

// @0x1425c3010
// MS2-FUNCTIONAL: same loads and shift/or chain; register allocation of the eight bytes differs
double Stream::ReadDouble()
{
    Align();
    if ((int)(DataSize - Pos) < 8)
        PopulateBuffer(8);
    UByte b0 = pBuffer[Pos++];
    UByte b1 = pBuffer[Pos++];
    UByte b2 = pBuffer[Pos++];
    UByte b3 = pBuffer[Pos++];
    UByte b4 = pBuffer[Pos++];
    UByte b5 = pBuffer[Pos++];
    UByte b6 = pBuffer[Pos++];
    UByte b7 = pBuffer[Pos++];
    union
    {
        UInt64 I;
        double D;
    } u;
    u.I = ((((((((UInt64)b7 << 8 | b6) << 8 | b5) << 8 | b4) << 8 | b3) << 8 | b2) << 8 | b1) << 8) | b0;
    return u.D;
}

// @0x1425c1f10
int Stream::GetTagEndPosition()
{
    unsigned idx = TagStackEntryCount - 1;
    if (idx < Stream_TagStackSize)
        return TagStack[idx];
    return 0;
}

// @0x1425c4220
void Stream::SetPosition(int pos)
{
    Align();
    if (pos >= (int)(FilePos - DataSize) && pos < (int)FilePos)
    {
        Pos = pos - (FilePos - DataSize);
        return;
    }
    if (!ResyncFile && Tell() == pos)
        return;
    if (pInput->Seek(pos) >= 0)
    {
        ResyncFile = false;
        Pos        = 0;
        DataSize   = 0;
        FilePos    = pos;
    }
}

// @0x1425c42e0
void Stream::SyncFileStream()
{
    int pos = pInput->Seek(Tell());
    if (pos != -1)
    {
        Pos      = 0;
        DataSize = 0;
        FilePos  = pos;
    }
}

// Reads a tag header and pushes the tag end on the tag stack.
// @0x1425c2680
TagType Stream::OpenTag()
{
    Align();
    unsigned tagHeader = ReadU16();
    int      tagType   = tagHeader >> 6;
    int      tagLength = tagHeader & 0x3f;
    if (tagLength == 0x3f)
        tagLength = ReadS32();
    if (IsVerboseParse())
        LogParse("---------------Tag type = %d, Tag length = %d\n", tagType, tagLength);
    TagStack[TagStackEntryCount] = Tell() + tagLength;
    TagStackEntryCount++;
    return (TagType)tagType;
}

// @0x1425c2540
TagType Stream::OpenTag(TagInfo* ptagInfo)
{
    Align();
    int      tagOffset = Tell();
    unsigned tagHeader = ReadU16();
    int      tagType   = tagHeader >> 6;
    int      tagLength = tagHeader & 0x3f;
    if (tagLength == 0x3f)
        tagLength = ReadS32();
    ptagInfo->TagOffset     = tagOffset;
    ptagInfo->TagType       = (TagType)tagType;
    ptagInfo->TagLength     = tagLength;
    ptagInfo->TagDataOffset = Tell();
    if (IsVerboseParse())
        LogParse("---------------Tag type = %d, Tag length = %d, offset = %d\n", tagType, tagLength, tagOffset);
    TagStack[TagStackEntryCount] = Tell() + tagLength;
    TagStackEntryCount++;
    return (TagType)tagType;
}

// Seeks to the end of the innermost open tag.
// @0x1425c1e80
void Stream::CloseTag()
{
    TagStackEntryCount--;
    SetPosition(TagStack[TagStackEntryCount]);
    UnusedBits = 0;
}

// @0x1425c37c0
char* Stream::ReadString(MemoryHeap* pheap)
{
    Array<char> buffer;
    char        c;
    while ((c = ReadU8()) != 0)
        buffer.PushBack(c);
    buffer.PushBack(0);

    char* retVal = 0;
    if (buffer.GetSize() > 0)
    {
        retVal = (char*)pheap->Alloc(buffer.GetSize());
        memcpy(retVal, &buffer[0], buffer.GetSize());
    }
    return retVal;
}

// @0x1425c3950
bool Stream::ReadString(String* pstr)
{
    Array<char> buffer;
    char        c;
    while ((c = ReadU8()) != 0)
        buffer.PushBack(c);
    buffer.PushBack(0);

    if (buffer.GetSize() == 0)
    {
        pstr->Clear();
        return false;
    }
    pstr->AssignString(&buffer[0], buffer.GetSize() - 1);
    return true;
}

// @0x1425c3ae0
char* Stream::ReadStringWithLength(MemoryHeap* pheap)
{
    int len = ReadU8();
    if (len == 0)
        return 0;
    char* buffer = (char*)pheap->Alloc(len + 1);
    int   i;
    for (i = 0; i < len; i++)
        buffer[i] = ReadU8();
    buffer[i] = 0;
    return buffer;
}

// @0x1425c3bc0
bool Stream::ReadStringWithLength(String* pstr)
{
    // Lets the string read its bytes straight from the stream into its own buffer.
    struct StringReader : public String::InitStruct
    {
        Stream* pStream;

        StringReader(Stream* pstream) : pStream(pstream) {}

        // @0x1425c1f30
        virtual void InitString(char* pbuffer, UPInt size) const
        {
            for (UPInt i = 0; i < size; i++)
                pbuffer[i] = pStream->ReadU8();
        }
    };

    int len = ReadU8();
    if (len == 0)
    {
        pstr->Clear();
        return false;
    }
    StringReader reader(this);
    pstr->AssignString(reader, len);
    return true;
}

// @0x1425c3100
void Stream::ReadMatrix(Render::Matrix2x4<float>* pm)
{
    Align();
    pm->SetIdentity();

    if (ReadUInt1())
    {
        int scaleBits = ReadUInt(5);
        pm->M[0][0]   = ReadSInt(scaleBits) / 65536.0f;
        pm->M[1][1]   = ReadSInt(scaleBits) / 65536.0f;
    }
    if (ReadUInt1())
    {
        int rotateBits = ReadUInt(5);
        pm->M[1][0]    = ReadSInt(rotateBits) / 65536.0f;
        pm->M[0][1]    = ReadSInt(rotateBits) / 65536.0f;
    }
    int translateBits = ReadUInt(5);
    if (translateBits > 0)
    {
        pm->M[0][3] = (float)ReadSInt(translateBits);
        pm->M[1][3] = (float)ReadSInt(translateBits);
    }
}

// @0x1425c28c0
// MS2-FUNCTIONAL: same reads and stores; this build keeps one more callee-saved register (r13)
void Stream::ReadCxformRgb(Render::Cxform* pcxform)
{
    Align();
    unsigned hasAdd  = ReadUInt1();
    unsigned hasMult = ReadUInt1();
    unsigned nbits   = ReadUInt(4);
    if (hasMult)
    {
        pcxform->M[0][0] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][1] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][2] = ReadSInt(nbits) / 256.0f;
    }
    else
    {
        pcxform->M[0][0] = 1.0f;
        pcxform->M[0][1] = 1.0f;
        pcxform->M[0][2] = 1.0f;
    }
    pcxform->M[0][3] = 1.0f;
    // The alpha offset ends up 1 (before Normalize) when the add terms are present.
    if (hasAdd)
    {
        pcxform->M[1][0] = (float)ReadSInt(nbits);
        pcxform->M[1][1] = (float)ReadSInt(nbits);
        pcxform->M[1][2] = (float)ReadSInt(nbits);
        pcxform->M[1][3] = 1.0f;
    }
    else
    {
        pcxform->M[1][0] = 0.0f;
        pcxform->M[1][1] = 0.0f;
        pcxform->M[1][2] = 0.0f;
        pcxform->M[1][3] = 0.0f;
    }
    pcxform->Normalize();
}

// @0x1425c2c20
void Stream::ReadCxformRgba(Render::Cxform* pcxform)
{
    Align();
    unsigned hasAdd  = ReadUInt1();
    unsigned hasMult = ReadUInt1();
    unsigned nbits   = ReadUInt(4);
    if (hasMult)
    {
        pcxform->M[0][0] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][1] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][2] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][3] = ReadSInt(nbits) / 256.0f;
    }
    else
    {
        pcxform->M[0][0] = 1.0f;
        pcxform->M[0][1] = 1.0f;
        pcxform->M[0][2] = 1.0f;
        pcxform->M[0][3] = 1.0f;
    }
    if (hasAdd)
    {
        pcxform->M[1][0] = (float)ReadSInt(nbits);
        pcxform->M[1][1] = (float)ReadSInt(nbits);
        pcxform->M[1][2] = (float)ReadSInt(nbits);
        pcxform->M[1][3] = (float)ReadSInt(nbits);
    }
    else
    {
        pcxform->M[1][0] = 0.0f;
        pcxform->M[1][1] = 0.0f;
        pcxform->M[1][2] = 0.0f;
        pcxform->M[1][3] = 0.0f;
    }
    pcxform->Normalize();
}

// @0x1425c34e0
void Stream::ReadRect(Render::Rect<float>* pr)
{
    Align();
    int nbits = ReadUInt(5);
    pr->x1    = (float)ReadSInt(nbits);
    pr->x2    = (float)ReadSInt(nbits);
    pr->y1    = (float)ReadSInt(nbits);
    pr->y2    = (float)ReadSInt(nbits);
}

// @0x1425c35c0
void Stream::ReadRgb(Render::Color* pc)
{
    pc->Channels.Red   = ReadU8();
    pc->Channels.Green = ReadU8();
    pc->Channels.Blue  = ReadU8();
    pc->Channels.Alpha = 0xff;
}

// @0x1425c3690
void Stream::ReadRgba(Render::Color* pc)
{
    ReadRgb(pc);
    pc->Channels.Alpha = ReadU8();
}

// Hex and character dump of the next numOfBytes bytes, 16 per line.
// @0x1425c20d0
void Stream::LogBytes(unsigned numOfBytes)
{
    char asciiBuf[16];
    int  count = 0;
    for (unsigned i = 0; i < numOfBytes; i++)
    {
        unsigned c = ReadU8();
        LogParse("%02X", c);
        if (c < 32)
            c = '.';
        else if (c > 127)
            c = '.';
        asciiBuf[count++] = (char)c;
        if (count >= 16)
        {
            LogParse("    ");
            for (int j = 0; j < 16; j++)
                LogParse("%c", asciiBuf[j]);
            count = 0;
            LogParse("\n");
        }
        else
            LogParse(" ");
    }
    if (count > 0)
        LogParse("\n");
}

// @0x1425c23e0
void Stream::LogTagBytes()
{
    LogBytes(GetTagEndPosition() - Tell());
}

// @0x1425c2380
void Stream::LogParseClass(const Render::Color& color)
{
    char buff[512];
    Format(buff, sizeof(buff), color);
    LogParse("%s", buff);
}

// @0x1425c2270
void Stream::LogParseClass(const Render::Rect<float>& rect)
{
    char buff[512];
    SFsprintf(buff, sizeof(buff), "xmin = %g, ymin = %g, xmax = %g, ymax = %g\n", Render::TwipsToPixels(rect.x1),
              Render::TwipsToPixels(rect.y1), Render::TwipsToPixels(rect.x2), Render::TwipsToPixels(rect.y2));
    LogParse("%s", buff);
}

// @0x1425c2320
void Stream::LogParseClass(const Render::Cxform& cxform)
{
    char buff[512];
    Format(buff, sizeof(buff), cxform);
    LogParse("%s", buff);
}

// @0x1425c2210
void Stream::LogParseClass(const Render::Matrix2x4<float>& matrix)
{
    char buff[512];
    Format(buff, sizeof(buff), matrix);
    LogParse("%s", buff);
}

//
// StreamContext
//

// Bit reads straight from the memory block: the bytes a read touches are gathered (big endian) and the excess
// low bits shifted out.
// @0x1425c3e70
// MS2-FUNCTIONAL: same switch and tail; the exe reuses the constant-1 register for the byte advances
unsigned StreamContext::ReadUInt(unsigned bitcount)
{
    // Bytes spanned by bitcount bits.
    static const UByte BytesForBits[33] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
                                            3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4 };

    unsigned totalBits = CurBitIndex + bitcount;
    unsigned mask      = (1 << (8 - CurBitIndex)) - 1;
    unsigned value;
    int      shift;
    switch (BytesForBits[bitcount])
    {
    case 0:
        return 0;
    case 1:
        value = pData[CurByteIndex] & mask;
        if (totalBits <= 8)
        {
            shift = 8 - totalBits;
            break;
        }
        value = (value << 8) | pData[CurByteIndex + 1];
        CurByteIndex += 1;
        shift = 16 - totalBits;
        break;
    case 2:
        value = ((pData[CurByteIndex] & mask) << 8) | pData[CurByteIndex + 1];
        if (totalBits <= 16)
        {
            CurByteIndex += 1;
            shift = 16 - totalBits;
            break;
        }
        value = (value << 8) | pData[CurByteIndex + 2];
        CurByteIndex += 2;
        shift = 24 - totalBits;
        break;
    case 3:
        value = ((((pData[CurByteIndex] & mask) << 8) | pData[CurByteIndex + 1]) << 8) | pData[CurByteIndex + 2];
        if (totalBits <= 24)
        {
            CurByteIndex += 2;
            shift = 24 - totalBits;
            break;
        }
        value = (value << 8) | pData[CurByteIndex + 3];
        CurByteIndex += 3;
        shift = 32 - totalBits;
        break;
    case 4:
        value = ((((((pData[CurByteIndex] & mask) << 8) | pData[CurByteIndex + 1]) << 8) | pData[CurByteIndex + 2])
                 << 8) |
                pData[CurByteIndex + 3];
        if (totalBits <= 32)
        {
            CurByteIndex += 3;
            shift = 32 - totalBits;
            break;
        }
        {
            // More than 32 bits spanned: the top bits of a fifth byte complete the value.
            unsigned extra = totalBits - 32;
            CurByteIndex += 4;
            CurBitIndex = extra;
            return (pData[CurByteIndex] >> (8 - extra)) | (value << extra);
        }
    default:
        value = 0;
        shift = 0;
        break;
    }

    if (shift)
    {
        CurBitIndex = 8 - shift;
        return value >> shift;
    }
    CurByteIndex++;
    CurBitIndex = 0;
    return value;
}

// @0x1425c32b0
// MS2-FUNCTIONAL: same code; prolog scheduling and constant materialization differ
void StreamContext::ReadMatrix(Render::Matrix2x4<float>* pm)
{
    Align();
    pm->SetIdentity();

    if (ReadUInt1())
    {
        int scaleBits = ReadUInt(5);
        pm->M[0][0]   = ReadSInt(scaleBits) / 65536.0f;
        pm->M[1][1]   = ReadSInt(scaleBits) / 65536.0f;
    }
    if (ReadUInt1())
    {
        int rotateBits = ReadUInt(5);
        pm->M[1][0]    = ReadSInt(rotateBits) / 65536.0f;
        pm->M[0][1]    = ReadSInt(rotateBits) / 65536.0f;
    }
    int translateBits = ReadUInt(5);
    if (translateBits > 0)
    {
        pm->M[0][3] = (float)ReadSInt(translateBits);
        pm->M[1][3] = (float)ReadSInt(translateBits);
    }
}

// @0x1425c2a60
// MS2-FUNCTIONAL: same reads and stores; this build keeps one more callee-saved register (r13)
void StreamContext::ReadCxformRgb(Render::Cxform* pcxform)
{
    Align();
    unsigned hasAdd  = ReadUInt1();
    unsigned hasMult = ReadUInt1();
    unsigned nbits   = ReadUInt(4);
    if (hasMult)
    {
        pcxform->M[0][0] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][1] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][2] = ReadSInt(nbits) / 256.0f;
    }
    else
    {
        pcxform->M[0][0] = 1.0f;
        pcxform->M[0][1] = 1.0f;
        pcxform->M[0][2] = 1.0f;
    }
    pcxform->M[0][3] = 1.0f;
    if (hasAdd)
    {
        pcxform->M[1][0] = (float)ReadSInt(nbits);
        pcxform->M[1][1] = (float)ReadSInt(nbits);
        pcxform->M[1][2] = (float)ReadSInt(nbits);
        pcxform->M[1][3] = 1.0f;
    }
    else
    {
        pcxform->M[1][0] = 0.0f;
        pcxform->M[1][1] = 0.0f;
        pcxform->M[1][2] = 0.0f;
        pcxform->M[1][3] = 0.0f;
    }
    pcxform->Normalize();
}

// @0x1425c2e00
// MS2-FUNCTIONAL: the exe materializes the ~0 sign mask as lea [r12 - 1] (r12 = 0) instead of mov -1
void StreamContext::ReadCxformRgba(Render::Cxform* pcxform)
{
    Align();
    unsigned hasAdd  = ReadUInt1();
    unsigned hasMult = ReadUInt1();
    unsigned nbits   = ReadUInt(4);
    if (hasMult)
    {
        pcxform->M[0][0] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][1] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][2] = ReadSInt(nbits) / 256.0f;
        pcxform->M[0][3] = ReadSInt(nbits) / 256.0f;
    }
    else
    {
        pcxform->M[0][0] = 1.0f;
        pcxform->M[0][1] = 1.0f;
        pcxform->M[0][2] = 1.0f;
        pcxform->M[0][3] = 1.0f;
    }
    if (hasAdd)
    {
        pcxform->M[1][0] = (float)ReadSInt(nbits);
        pcxform->M[1][1] = (float)ReadSInt(nbits);
        pcxform->M[1][2] = (float)ReadSInt(nbits);
        pcxform->M[1][3] = (float)ReadSInt(nbits);
    }
    else
    {
        pcxform->M[1][0] = 0.0f;
        pcxform->M[1][1] = 0.0f;
        pcxform->M[1][2] = 0.0f;
        pcxform->M[1][3] = 0.0f;
    }
    pcxform->Normalize();
}

}} // namespace Scaleform::GFx

// MS2-PIN: ??_7Stream@GFx@Scaleform@@6B@ 0x14318a178
// MS2-PIN: ??_7?$LogBase@VStream@GFx@Scaleform@@@GFx@Scaleform@@6B@ 0x14318a168
// MS2-PIN: ??_G?$LogBase@VStream@GFx@Scaleform@@@GFx@Scaleform@@UEAAPEAXI@Z 0x1425c1da0
// MS2-PIN: ??_7InitStruct@String@Scaleform@@6B@ 0x14313f358
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
