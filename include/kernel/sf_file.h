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

// Open flags and modes of the system files.
class FileConstants
{
public:
    enum OpenFlags
    {
        Open_Read     = 1,
        Open_Write    = 2,
        Open_ReadWrite = 3,
        Open_Create   = 4,
        Open_Truncate = 8,
        Open_Buffered = 32
    };

    enum Modes
    {
        Mode_Read      = 0444,
        Mode_Write     = 0222,
        Mode_ReadWrite = 0666
    };
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

// Times and size of a file on disk.
struct FileStat
{
    SInt64 ModifyTime; // +0
    SInt64 AccessTime; // +8
    SInt64 FileSize;   // +0x10
};

// A File forwarding every call to another one (0x18 bytes).
class DelegatedFile : public File
{
protected:
    Ptr<File> pFile; // +0x10

public:
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
};

// A file of the operating system, buffered (0x18 bytes; members bind to the exe: SysFile 0x1425a5f60,
// GetFileStat 0x1425a5840).
class SysFile : public DelegatedFile
{
public:
    SysFile(const String& path, int flags = FileConstants::Open_Read | FileConstants::Open_Buffered,
            int mode = FileConstants::Mode_ReadWrite);

    static bool SF_CDECL GetFileStat(FileStat* pfileStats, const String& path);
};

// The file name part of a path (SF_File; exe 0x14264d890).
const char* GetShortFilename(const char* path);

} // namespace Scaleform

struct z_stream_s;

namespace Scaleform { namespace GFx {

// Inflates a zlib compressed file as it is read (0x18 bytes; bodies in sfr_gfx_08: ZLibFile 0x142645610,
// ZLib_InitStream 0x142646120).
class ZLibFile : public File
{
    class ZLibFileImpl* pImpl; // +0x10

public:
    ZLibFile(File* psourceFile = 0);
    ~ZLibFile();

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

    // Sets up pstream for inflating into pbuffer; the zlib allocations go to the heap of pheapAddr.
    static int SF_STDCALL ZLib_InitStream(z_stream_s* pstream, void* pheapAddr, void* pbuffer, unsigned bufSize);
};

}} // namespace Scaleform::GFx

// (sfr24) sizes proven by the exe allocation before each ctor (work/sfr24/tmp/szscan.py).
static_assert(sizeof(Scaleform::GFx::ZLibFile) == 0x18, "ZLibFile size");

#endif
