// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 Kernel, SF_File (BufferedFile: one
// read-or-write buffer in front of another file; transfers larger than the tolerance go straight to the file).
// Our own source, written from the exe. Queue unit sfr_kernel_02 is split along its original sources.
// MS2-UNIT: sfr_kernel_02i
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14264d420-0x14264dec0 .text$mn
#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_file.h"
#include "ms2/scaleform/kernel/sf_std.h"
#include "ms2/scaleform/kernel/sf_alg.h"
#include "ms2/scaleform/kernel/sf_memory.h"
#include <string.h>

namespace Scaleform {

enum
{
    FileBuffer_Size      = 0x1FF8,      // 8 KB less the allocation header
    FileBuffer_Tolerance = 0x1000       // larger reads/writes bypass the buffer
};

BufferedFile::BufferedFile() : DelegatedFile(0)
{
    pBuffer    = (UByte*)SF_MEMALIGN(FileBuffer_Size, 1, Stat_Default_Mem);
    BufferMode = NoBuffer;
    FilePos    = 0;
    Pos        = 0;
    DataSize   = 0;
}

BufferedFile::BufferedFile(File* file) : DelegatedFile(file)
{
    pBuffer    = (UByte*)SF_MEMALIGN(FileBuffer_Size, 1, Stat_Default_Mem);
    BufferMode = NoBuffer;
    FilePos    = file->LTell();
    Pos        = 0;
    DataSize   = 0;
}

BufferedFile::~BufferedFile()
{
    if (pFile)
        FlushBuffer();
    if (pBuffer)
        SF_FREE(pBuffer);
}

int BufferedFile::BytesAvailable()
{
    int avail = pFile->BytesAvailable();
    switch (BufferMode)
    {
    case ReadBuffer:
        avail += DataSize - Pos;
        break;
    case WriteBuffer:
        avail -= Pos;
        if (avail < 0)
            avail = 0;
        break;
    default:
        break;
    }
    return avail;
}

bool BufferedFile::ChangeSize(int newSize)
{
    FlushBuffer();
    return pFile->ChangeSize(newSize);
}

bool BufferedFile::Close()
{
    switch (BufferMode)
    {
    case WriteBuffer:
        FlushBuffer();
        break;
    case ReadBuffer:
        BufferMode = NoBuffer;
        break;
    default:
        break;
    }
    return pFile->Close();
}

int BufferedFile::CopyFromStream(File* stream, int byteSize)
{
    UByte buff[0x4000];
    int   count = 0;
    while (byteSize)
    {
        int toRead = byteSize > 0x4000 ? 0x4000 : byteSize;
        int got = stream->Read(buff, toRead);
        int written = 0;
        if (got > 0)
            written = Write(buff, got);
        count    += written;
        byteSize -= written;
        if (written < toRead)
            break;
    }
    return count;
}

bool BufferedFile::Flush()
{
    FlushBuffer();
    return pFile->Flush();
}

void BufferedFile::FlushBuffer()
{
    switch (BufferMode)
    {
    case ReadBuffer:
        // give the unread part back to the file
        if (DataSize != Pos)
            FilePos = pFile->LSeek((int)(Pos - DataSize), Seek_Cur);
        Pos = 0;
        DataSize = 0;
        break;
    case WriteBuffer:
    {
        FilePos += pFile->Write(pBuffer, Pos);
        Pos = 0;
        break;
    }
    default:
        break;
    }
}

int BufferedFile::GetLength()
{
    int length = pFile->GetLength();
    if (length != -1 && BufferMode == WriteBuffer)
    {
        int end = pFile->Tell() + Pos;
        if (end > length)
            length = end;
    }
    return length;
}

const char* GetShortFilename(const char* path)
{
    for (UPInt i = SFstrlen(path); i > 0; i--)
    {
        if (path[i] == '\\' || path[i] == '/')
            return path + i + 1;
    }
    return path;
}

SInt64 BufferedFile::LGetLength()
{
    SInt64 length = pFile->LGetLength();
    if (length != -1 && BufferMode == WriteBuffer)
    {
        SInt64 end = pFile->LTell() + Pos;
        if (end > length)
            length = end;
    }
    return length;
}

SInt64 BufferedFile::LSeek(SInt64 offset, int origin)
{
    if (BufferMode == ReadBuffer)
    {
        if (origin == Seek_Cur)
        {
            if ((unsigned)offset + Pos <= DataSize)
            {
                Pos += (unsigned)offset;
                return (SInt64)(FilePos - DataSize + Pos);
            }
            // outside the buffer: seek the file to the absolute position, without seeking back first
            origin = Seek_Set;
            offset = (SInt64)(FilePos - DataSize + Pos) + offset;
            Pos = DataSize = 0;
        }
        else if (origin == Seek_Set)
        {
            if ((UInt64)offset - (FilePos - DataSize) <= DataSize)
            {
                Pos = (unsigned)((UInt64)offset - (FilePos - DataSize));
                return offset;
            }
            Pos = DataSize = 0;
        }
        else
            FlushBuffer();
    }
    else
        FlushBuffer();
    FilePos = pFile->LSeek(offset, origin);
    return FilePos;
}

SInt64 BufferedFile::LTell()
{
    if (BufferMode == ReadBuffer)
        return Pos - (UInt64)DataSize + FilePos;
    SInt64 pos = pFile->LTell();
    if (pos != -1 && BufferMode == WriteBuffer)
        pos += Pos;
    return pos;
}

void BufferedFile::LoadBuffer()
{
    if (BufferMode == ReadBuffer)
    {
        int got = pFile->Read(pBuffer, FileBuffer_Size);
        Pos = 0;
        DataSize = got < 0 ? 0 : got;
        FilePos += DataSize;
    }
}

int BufferedFile::Read(UByte* buffer, int numBytes)
{
    if (BufferMode != ReadBuffer && !SetBufferMode(ReadBuffer))
    {
        int got = pFile->Read(buffer, numBytes);
        if (got > 0)
            FilePos += got;
        return got;
    }
    int    avail = DataSize - Pos;
    UByte* src = pBuffer + Pos;
    if (avail >= numBytes)
    {
        memcpy(buffer, src, numBytes);
        Pos += numBytes;
        return numBytes;
    }
    memcpy(buffer, src, avail);
    buffer   += avail;
    numBytes -= avail;
    Pos = DataSize;
    if (numBytes > FileBuffer_Tolerance)
    {
        int got = pFile->Read(buffer, numBytes);
        if (got > 0)
        {
            FilePos += got;
            Pos = 0;
            DataSize = 0;
        }
        return avail + (got == -1 ? 0 : got);
    }
    LoadBuffer();
    if ((int)(DataSize - Pos) < numBytes)
        numBytes = DataSize - Pos;
    memcpy(buffer, pBuffer + Pos, numBytes);
    Pos += numBytes;
    return numBytes + avail;
}

int BufferedFile::Seek(int offset, int origin)
{
    if (BufferMode == ReadBuffer)
    {
        if (origin == Seek_Cur)
        {
            if ((unsigned)offset + Pos <= DataSize)
            {
                Pos += offset;
                return (int)(FilePos - DataSize + Pos);
            }
            origin = Seek_Set;
            offset = (int)(FilePos - DataSize + Pos) + offset;
            Pos = DataSize = 0;
        }
        else if (origin == Seek_Set)
        {
            if ((unsigned)offset - (FilePos - DataSize) <= DataSize)
            {
                Pos = (unsigned)offset - (unsigned)(FilePos - DataSize);
                return offset;
            }
            Pos = DataSize = 0;
        }
        else
            FlushBuffer();
    }
    else
        FlushBuffer();
    FilePos = pFile->Seek(offset, origin);
    return (int)FilePos;
}

bool BufferedFile::SetBufferMode(BufferModeType mode)
{
    if (!pBuffer)
        return false;
    if (mode == BufferMode)
        return true;
    FlushBuffer();
    if (mode == WriteBuffer && !(pFile && pFile->IsWritable()))
        return false;
    BufferMode = mode;
    Pos = 0;
    DataSize = 0;
    return true;
}

int BufferedFile::SkipBytes(int numBytes)
{
    int skipped = 0;
    if (BufferMode == ReadBuffer)
    {
        skipped = ((int)DataSize - (int)Pos >= numBytes) ? numBytes : (int)(DataSize - Pos);
        Pos      += skipped;
        numBytes -= skipped;
    }
    if (numBytes)
    {
        numBytes = pFile->SkipBytes(numBytes);
        if (numBytes != -1)
        {
            skipped += numBytes;
            FilePos += numBytes;
            Pos = DataSize = 0;
        }
        else if (skipped <= 0)
            skipped = -1;
    }
    return skipped;
}

int BufferedFile::Tell()
{
    if (BufferMode == ReadBuffer)
        return (int)(FilePos - DataSize) + Pos;
    int pos = pFile->Tell();
    if (pos != -1 && BufferMode == WriteBuffer)
        pos += Pos;
    return pos;
}

int BufferedFile::Write(const UByte* buffer, int numBytes)
{
    if (BufferMode == WriteBuffer || SetBufferMode(WriteBuffer))
    {
        if ((int)(FileBuffer_Size - Pos) < numBytes)
        {
            FlushBuffer();
            if (numBytes > FileBuffer_Tolerance)
                goto direct;
        }
        memcpy(pBuffer + Pos, buffer, numBytes);
        Pos += numBytes;
        return numBytes;
    }
direct:
    numBytes = pFile->Write(buffer, numBytes);
    if (numBytes > 0)
        FilePos += numBytes;
    return numBytes;
}

}  // namespace Scaleform
// ---- pins (work/sfr/repin.sh) ----
// MS2-PIN: ??0BufferedFile@Scaleform@@QEAA@PEAVFile@1@@Z 0x14264d490
// MS2-PIN: ??1BufferedFile@Scaleform@@UEAA@XZ 0x14264d520
// MS2-PIN: ??_GBufferedFile@Scaleform@@UEAAPEAXI@Z 0x14264d570
// MS2-PIN: ?BytesAvailable@BufferedFile@Scaleform@@UEAAHXZ 0x14264d610
// MS2-PIN: ?ChangeSize@BufferedFile@Scaleform@@UEAA_NH@Z 0x14264d660
// MS2-PIN: ?Close@BufferedFile@Scaleform@@UEAA_NXZ 0x14264d690
// MS2-PIN: ?CopyFromStream@BufferedFile@Scaleform@@UEAAHPEAVFile@2@H@Z 0x14264d6e0
// MS2-PIN: ?Flush@BufferedFile@Scaleform@@UEAA_NXZ 0x14264d7b0
// MS2-PIN: ?FlushBuffer@BufferedFile@Scaleform@@IEAAXXZ 0x14264d7d0
// MS2-PIN: ?GetLength@BufferedFile@Scaleform@@UEAAHXZ 0x14264d840
// MS2-PIN: ?GetShortFilename@Scaleform@@YAPEBDPEBD@Z 0x14264d890
// MS2-PIN: ?LGetLength@BufferedFile@Scaleform@@UEAA_JXZ 0x14264d8d0
// MS2-PIN: ?LSeek@BufferedFile@Scaleform@@UEAA_J_JH@Z 0x14264d920
// MS2-PIN: ?LTell@BufferedFile@Scaleform@@UEAA_JXZ 0x14264d9f0
// MS2-PIN: ?LoadBuffer@BufferedFile@Scaleform@@IEAAXXZ 0x14264da40
// MS2-PIN: ?Read@BufferedFile@Scaleform@@UEAAHPEAEH@Z 0x14264da80
// MS2-PIN: ?Seek@BufferedFile@Scaleform@@UEAAHHH@Z 0x14264dbd0
// MS2-PIN: ?SetBufferMode@BufferedFile@Scaleform@@IEAA_NW4BufferModeType@12@@Z 0x14264dca0
// MS2-PIN: ?SkipBytes@BufferedFile@Scaleform@@UEAAHH@Z 0x14264dd00
// MS2-PIN: ?Tell@BufferedFile@Scaleform@@UEAAHXZ 0x14264dd70
// MS2-PIN: ?Write@BufferedFile@Scaleform@@UEAAHPEBEH@Z 0x14264ddb0
// MS2-PIN: ??_7DelegatedFile@Scaleform@@6B@ 0x143188ba8
// MS2-PIN: ??_7BufferedFile@Scaleform@@6B@ 0x143190530
