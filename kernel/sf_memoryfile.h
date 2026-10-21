// Recovered Scaleform GFx 4.1.18: MemoryFile, a read-only File over a caller owned buffer (0x30 bytes), for the
// units built on this kernel tree's sf_file.h. The class is the one src/ms2/scaleform/include/kernel/sf_file.h
// declares: the virtuals and the dtor bind to the exe's copy (game code at 0x141628f60.., vftable 0x142f465f8).
#ifndef MS2_SF_KERNEL_MEMORYFILE_H
#define MS2_SF_KERNEL_MEMORYFILE_H

#include "ms2/scaleform/kernel/sf_file.h"
#include "ms2/scaleform/kernel/sf_string.h"

namespace Scaleform {

class MemoryFile : public File
{
public:
    MemoryFile(const char* pfileName, const UByte* pbuffer, int buffSize) : FilePath(pfileName)
    {
        FileData  = pbuffer;
        FileSize  = buffSize;
        FileIndex = 0;
        Valid     = (pfileName && pbuffer && buffSize > 0) ? true : false;
    }
    MemoryFile(const String& fileName, const UByte* pbuffer, int buffSize) : FilePath(fileName)
    {
        FileData  = pbuffer;
        FileSize  = buffSize;
        FileIndex = 0;
        Valid     = (!fileName.IsEmpty() && pbuffer && buffSize > 0) ? true : false;
    }
    ~MemoryFile();

    const char* GetFilePath();
    bool        IsValid();
    bool        IsWritable();
    int         Tell();
    SInt64      LTell();
    int         GetLength();
    SInt64      LGetLength();
    int         GetErrorCode();
    int         Write(const UByte* pbuffer, int numBytes);
    int         Read(UByte* pbuffer, int numBytes);
    int         SkipBytes(int numBytes);
    int         BytesAvailable();
    bool        Flush();
    int         Seek(int offset, int origin = Seek_Set);
    SInt64      LSeek(SInt64 offset, int origin = Seek_Set);
    bool        ChangeSize(int newSize);
    int         CopyFromStream(File* pstream, int byteSize);
    bool        Close();

private:
    String       FilePath;  // +0x10
    const UByte* FileData;  // +0x18
    int          FileSize;  // +0x20
    int          FileIndex; // +0x24
    bool         Valid;     // +0x28
};

} // namespace Scaleform

#endif
