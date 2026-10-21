// Recovered Scaleform 4.1.18 kernel: File, the abstract byte stream (vftable slots from the exe's callers).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Same include guard as the kernel tree's src/ms2/scaleform/kernel/sf_file.h on purpose: both describe the same
// class, so a unit only ever gets one of them.
#ifndef MS2_SF_KERNEL_FILE_H
#define MS2_SF_KERNEL_FILE_H

#include "sf_refcount.h"
#include "sf_string.h"

namespace Scaleform {

class File : public RefCountBase<File, Stat_Default_Mem>
{
public:
    enum SeekOrigin
    {
        Seek_Set = 0,
        Seek_Cur = 1,
        Seek_End = 2
    };

    virtual const char* GetFilePath()                                = 0; // +0x08
    virtual bool        IsValid()                                    = 0; // +0x10
    virtual bool        IsWritable()                                 = 0; // +0x18
    virtual int         Tell()                                       = 0; // +0x20
    virtual SInt64      LTell()                                      = 0; // +0x28
    virtual int         GetLength()                                  = 0; // +0x30
    virtual SInt64      LGetLength()                                 = 0; // +0x38
    virtual int         GetErrorCode()                               = 0; // +0x40
    virtual int         Write(const UByte* pbuffer, int numBytes)    = 0; // +0x48
    virtual int         Read(UByte* pbuffer, int numBytes)           = 0; // +0x50
    virtual int         SkipBytes(int numBytes)                      = 0; // +0x58
    virtual int         BytesAvailable()                             = 0; // +0x60
    virtual bool        Flush()                                      = 0; // +0x68
    virtual int         Seek(int offset, int origin = Seek_Set)      = 0; // +0x70
    virtual SInt64      LSeek(SInt64 offset, int origin = Seek_Set)  = 0; // +0x78
    virtual int         SeekToBegin() { return Seek(0); }                 // +0x80
    virtual bool        ChangeSize(int newSize)                      = 0; // +0x88
    virtual int         CopyFromStream(File* pstream, int byteSize)  = 0; // +0x90
    virtual bool        Close()                                      = 0; // +0x98

    // Little endian on the PC build: no byte swapping.
    UInt16 ReadUInt16() { UInt16 v = 0; Read((UByte*)&v, 2); return v; }
    UInt32 ReadUInt32() { UInt32 v = 0; Read((UByte*)&v, 4); return v; }
};

// A File over a caller owned buffer (0x30 bytes); read only. The virtuals bind to the exe's copy (vftable
// 0x142f465f8, RTTI: emitted by the game code).
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
