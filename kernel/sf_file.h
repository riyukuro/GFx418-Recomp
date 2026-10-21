// Recovered Scaleform GFx 4.1.18: File, the abstract byte stream (vftable order from the exe's callers:
// Write at slot 9, Read at slot 10).
#ifndef MS2_SF_KERNEL_FILE_H
#define MS2_SF_KERNEL_FILE_H

#include "ms2/scaleform/kernel/sf_types.h"
#include "ms2/scaleform/kernel/sf_refcount.h"

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
    enum OpenFlags
    {
        Open_Read       = 1,
        Open_Write      = 2,
        Open_ReadWrite  = 3,
        Open_Truncate   = 4,
        Open_Create     = 8,
        Open_CreateOnly = 24,
        Open_Buffered   = 32
    };
    enum Modes   // unix style permission bits
    {
        Mode_Read      = 0444,
        Mode_Write     = 0222,
        Mode_Execute   = 0111,
        Mode_ReadWrite = 0666
    };
    enum Errors
    {
        Error_FileNotFound = 0x1001,
        Error_Access       = 0x1002,
        Error_IOError      = 0x1003,
        Error_DiskFull     = 0x1004
    };

    File() {}
    // no user-declared destructor: the exe never re-stores the File vftable when destroying

    virtual const char* GetFilePath() = 0;                                  // 1
    virtual bool        IsValid() = 0;                                      // 2
    virtual bool        IsWritable() = 0;                                   // 3
    virtual int         Tell() = 0;                                         // 4
    virtual SInt64      LTell() = 0;                                        // 5
    virtual int         GetLength() = 0;                                    // 6
    virtual SInt64      LGetLength() = 0;                                   // 7
    virtual int         GetErrorCode() = 0;                                 // 8
    virtual int         Write(const UByte* buffer, int numBytes) = 0;       // 9
    virtual int         Read(UByte* buffer, int numBytes) = 0;              // 10
    virtual int         SkipBytes(int numBytes) = 0;                        // 11
    virtual int         BytesAvailable() = 0;                               // 12
    virtual bool        Flush() = 0;                                        // 13
    virtual int         Seek(int offset, int origin = Seek_Set) = 0;        // 14
    virtual SInt64      LSeek(SInt64 offset, int origin = Seek_Set) = 0;    // 15
    virtual int         SeekToBegin() { return Seek(0); }                   // 16
    virtual bool        ChangeSize(int newSize) = 0;                        // 17
    virtual int         CopyFromStream(File* stream, int byteSize) = 0;     // 18
    virtual bool        Close() = 0;                                        // 19

    // little-endian helpers (the PC build needs no byte swapping)
    UByte  ReadUByte()  { UByte v = 0;  Read(&v, 1); return v; }
    SByte  ReadSByte()  { SByte v = 0;  Read((UByte*)&v, 1); return v; }
    UInt8  ReadUInt8()  { UInt8 v = 0;  Read(&v, 1); return v; }
    UInt16 ReadUInt16() { UInt16 v = 0; Read((UByte*)&v, 2); return v; }
    UInt32 ReadUInt32() { UInt32 v = 0; Read((UByte*)&v, 4); return v; }
    UInt64 ReadUInt64() { UInt64 v = 0; Read((UByte*)&v, 8); return v; }
    SInt32 ReadSInt32() { UInt32 v = 0; Read((UByte*)&v, 4); return (SInt32)v; }

    // each write passes the value on once more by value, the copy whose address goes to Write
    void WriteUByte(UByte v)   { PutBytes8(v); }
    void WriteSByte(SByte v)   { PutBytes8((UInt8)v); }
    void WriteUInt8(UInt8 v)   { PutBytes8(v); }
    void WriteUInt16(UInt16 v) { PutBytes16(v); }
    void WriteUInt32(UInt32 v) { PutBytes32(v); }
    void WriteUInt64(UInt64 v) { PutBytes64(v); }
    void WriteSInt32(SInt32 v) { PutBytes32((UInt32)v); }

protected:
    void PutBytes8(UInt8 v)   { Write(&v, 1); }
    void PutBytes16(UInt16 v) { Write((UByte*)&v, 2); }
    void PutBytes32(UInt32 v) { Write((UByte*)&v, 4); }
    void PutBytes64(UInt64 v) { Write((UByte*)&v, 8); }
};

typedef File FileConstants;   // the open/mode/error constants live in File here

class String;

// Forwards every call to the wrapped file (SF_File / SF_SysFile).
class DelegatedFile : public File
{
protected:
    Ptr<File> pFile;
    DelegatedFile() : pFile(0) { }
public:
    DelegatedFile(File* file) : pFile(file) { }

    virtual const char* GetFilePath()                         { return pFile->GetFilePath(); }
    virtual bool        IsValid()                             { return pFile && pFile->IsValid(); }
    virtual bool        IsWritable()                          { return pFile->IsWritable(); }
    virtual int         Tell()                                { return pFile->Tell(); }
    virtual SInt64      LTell()                               { return pFile->LTell(); }
    virtual int         GetLength()                           { return pFile->GetLength(); }
    virtual SInt64      LGetLength()                          { return pFile->LGetLength(); }
    virtual int         GetErrorCode()                        { return pFile->GetErrorCode(); }
    virtual int         Write(const UByte* buffer, int n)     { return pFile->Write(buffer, n); }
    virtual int         Read(UByte* buffer, int n)            { return pFile->Read(buffer, n); }
    virtual int         SkipBytes(int n)                      { return pFile->SkipBytes(n); }
    virtual int         BytesAvailable()                      { return pFile->BytesAvailable(); }
    virtual bool        Flush()                               { return pFile->Flush(); }
    virtual int         Seek(int offset, int origin = Seek_Set)       { return pFile->Seek(offset, origin); }
    virtual SInt64      LSeek(SInt64 offset, int origin = Seek_Set)   { return pFile->LSeek(offset, origin); }
    virtual bool        ChangeSize(int newSize)               { return pFile->ChangeSize(newSize); }
    virtual int         CopyFromStream(File* stream, int n)   { return pFile->CopyFromStream(stream, n); }
    virtual bool        Close()                               { return pFile->Close(); }
};

// Read/write buffering over another file (SF_File, bodies in sfr_kernel_02i); 0x38 bytes.
class BufferedFile : public DelegatedFile
{
protected:
    enum BufferModeType { NoBuffer, ReadBuffer, WriteBuffer };
    UByte*         pBuffer;
    BufferModeType BufferMode;
    unsigned       Pos;
    unsigned       DataSize;
    UInt64         FilePos;
public:
    BufferedFile();
    BufferedFile(File* file);
    ~BufferedFile();

    virtual int    Tell();
    virtual SInt64 LTell();
    virtual int    GetLength();
    virtual SInt64 LGetLength();
    virtual int    Write(const UByte* buffer, int n);
    virtual int    Read(UByte* buffer, int n);
    virtual int    SkipBytes(int n);
    virtual int    BytesAvailable();
    virtual bool   Flush();
    virtual int    Seek(int offset, int origin = Seek_Set);
    virtual SInt64 LSeek(SInt64 offset, int origin = Seek_Set);
    virtual bool   ChangeSize(int newSize);
    virtual int    CopyFromStream(File* stream, int n);
    virtual bool   Close();
protected:
    bool SetBufferMode(BufferModeType mode);
    void FlushBuffer();
    void LoadBuffer();
};

// the file name part of a path (after the last '/' or '\\')
const char* GetShortFilename(const char* path);

struct FileStat
{
    SInt64 ModifyTime;
    SInt64 AccessTime;
    SInt64 FileSize;
    bool operator==(const FileStat& o) const
    {
        return ModifyTime == o.ModifyTime && AccessTime == o.AccessTime && FileSize == o.FileSize;
    }
};

// A file of the operating system (stdio underneath, buffered on request).
class SysFile : public DelegatedFile
{
public:
    SysFile();
    SysFile(const String& path, int flags = Open_Read | Open_Buffered, int mode = Mode_ReadWrite);

    bool Open(const String& path, int flags = Open_Read | Open_Buffered, int mode = Mode_ReadWrite);
    bool Create(const String& path, int mode = Mode_ReadWrite) { return Open(path, Open_ReadWrite | Open_Create, mode); }

    static bool SF_CDECL GetFileStat(FileStat* fileStat, const String& path);

    virtual int  GetErrorCode();
    virtual bool IsValid();
    virtual bool Close();
};

File* FileFILEOpen(const String& path, int flags, int mode);

} // namespace Scaleform

#endif
