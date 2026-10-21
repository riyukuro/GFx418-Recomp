// Recovered Scaleform 4.1.18 GFx: state bags, movie definitions and their resource bindings
// (only the parts used by recovered units so far; layouts from the exe).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// Out-of-line members not recovered yet bind to the exe:
//   MovieDataDef::LoadTaskData::WaitForLoadFinish 0x1425d3c40, ResourceBinding::GetResourceData_Locked 0x142636720.
#ifndef MS2_SF_GFX_MOVIEDEF_H
#define MS2_SF_GFX_MOVIEDEF_H

#include "gfx_resource.h"
#include "gfx_state.h"
#include "../kernel/sf_lock.h"
#include "../render/render_fontprovider.h"

namespace Scaleform {
class Log;
namespace Render { template<class T> class Rect; }
namespace GFx {

class StateBagImpl;
class LoaderImpl;
class ImageCreator;
class FileOpener;
class TextClipboard;
class TextKeyMap;
class MovieDefImpl;
class ResourceBinding;

// Something that hands out states by type; MovieDef, Loader and the movie instances are state bags.
class StateBag : public FileTypeConstants
{
public:
    virtual StateBag* GetStateBagImpl() const;
    virtual ~StateBag() {}
    virtual void      SetState(State::StateType state, State* pstate);
    virtual State*    GetStateAddRef(State::StateType state) const;
    // Fills pstates[i] with an AddRef'ed state of type pstateTypes[i] (or null) under one lock.
    virtual void      GetStatesAddRef(State** pstates, const State::StateType* pstateTypes, unsigned count) const;

    // Typed setters (exe: SetLog 0x1425b39d0). The inline ones need the state class complete: they are defined
    // after it (ImageCreator, TextClipboard, TextKeyMap: in the unit that defines the loader constructors).
    void        SetLog(Log* plog);
    inline void SetImageCreator(ImageCreator* ptr);
    inline void SetTextClipboard(TextClipboard* ptr);
    inline void SetTextKeyMap(TextKeyMap* ptr);
};

// Loaded movie as seen by the user: Resource at +0, StateBag at +0x18.
class MovieDef : public Resource, public StateBag
{
public:
    // Primary vftable after the Resource slots (MovieDefImpl: 0x14318b588).
    virtual unsigned            GetVersion() const      = 0; // +0x20
    virtual unsigned            GetLoadingFrame() const = 0; // +0x28
    virtual float               GetWidth() const        = 0; // +0x30
    virtual float               GetHeight() const       = 0; // +0x38
    virtual unsigned            GetFrameCount() const   = 0; // +0x40
    virtual float               GetFrameRate() const    = 0; // +0x48
    virtual Render::Rect<float> GetFrameRect() const    = 0; // +0x50
    virtual unsigned            GetSWFFlags() const     = 0; // +0x58
    virtual const char*         GetFileURL() const      = 0; // +0x60
};

// One font a movie defines, chained in load order.
struct FontDataUseNode
{
    ResourceId                 Id;         // +0
    Ptr<Render::Font>          pFontData;  // +8
    unsigned                   BindIndex;  // +0x10
    FontDataUseNode* volatile  pNext;      // +0x18
};

// Parsed SWF data shared by every binding of the same file.
class MovieDataDef : public Resource
{
public:
    enum MovieDataType
    {
        MT_Empty,
        MT_Flash,
        MT_Image
    };

    MovieDataDef(const ResourceKey& creationKey, MovieDataType mtype, const char* purl, MemoryHeap* pargHeap = 0,
                 bool debugHeap = false, UPInt memoryArena = 0);

    // Library key of the data of file purl (exe 0x1425ceaa0); 4.1.18 keys on one more binding state than later SDKs.
    static ResourceKey SF_STDCALL CreateMovieFileKey(const char* purl, SInt64 modifyTime, FileOpener* pfileOpener,
                                                     ImageCreator* pimageCreator, State* pbindState23);

    // Load-time data (frames, fonts, exports); filled by the LoadProcess.
    class LoadTaskData : public RefCountBase<LoadTaskData, Stat_Default_Mem>
    {
    public:
        void             WaitForLoadFinish();
        FontDataUseNode* GetFirstFont() const { return pFonts; }
        const char*      GetFileURL() const   { return FileURL.ToCStr(); }

        UInt32           GetTagCount() const  { return TagCount; }
        // The MovieHeaderData of the file (only defined by the units that read it).
        const void*      GetHeaderData() const { return HeaderData; }

    private:
        UByte                     Unknown10[0x38];  // +0x10
        String                    FileURL;          // +0x48
        UByte                     HeaderData[0x78]; // +0x50 MovieHeaderData
        UByte                     UnknownC8[0x28];  // +0xc8
        UInt32                    TagCount;         // +0xf0
        UByte                     UnknownF4[0x2c];  // +0xf4
        FontDataUseNode* volatile pFonts;           // +0x120
    };

    void             WaitForLoadFinish() const { pData->WaitForLoadFinish(); }
    FontDataUseNode* GetFirstFont() const      { return pData->GetFirstFont(); }
    const char*      GetFileURL() const        { return pData->GetFileURL(); }

private:
    UByte             Unknown18[0x20]; // +0x18
public:
    MovieDataType     MovieType;       // +0x38
    Ptr<LoadTaskData> pData;           // +0x40
};

// Resource bound at one index of a movie binding.
struct ResourceBindData
{
    Ptr<Resource>    pResource;
    ResourceBinding* pBinding;

    ResourceBindData() : pBinding(0) {}
    ResourceBindData& operator=(const ResourceBindData& src)
    {
        pResource = src.pResource;
        pBinding  = src.pBinding;
        return *this;
    }
};

// Index -> resource table of a MovieDefImpl. Once Frozen it is read without the lock.
class ResourceBinding
{
    MemoryHeap*                pHeap;          // +0
    volatile unsigned          ResourceCount;  // +8
    ResourceBindData* volatile pResources;     // +0x10
    mutable Lock               ResourceLock;   // +0x18
    volatile bool              Frozen;         // +0x40

public:
    void GetResourceData_Locked(ResourceBindData* pdata, unsigned index) const;

    void GetResourceData(ResourceBindData* pdata, unsigned index) const
    {
        if (Frozen && (index < ResourceCount))
            *pdata = pResources[index];
        else
            GetResourceData_Locked(pdata, index);
    }
};

// The states a binding depends on: a movie bound under different values of these is a different MovieDefImpl.
class MovieDefBindStates : public RefCountBase<MovieDefBindStates, Stat_Default_Mem>
{
public:
    Ptr<State> pFileOpener;               // +0x10
    Ptr<State> pURLBuilder;               // +0x18
    Ptr<State> pImageCreator;             // +0x20
    Ptr<State> pImageFileHandlerRegistry; // +0x28 (not taken from the bag)
    Ptr<State> pImportVisitor;            // +0x30
    Ptr<State> pFontPackParams;           // +0x38
    Ptr<State> pBindState23;              // +0x40
    Ptr<State> pFontCompactorParams;      // +0x48
    Ptr<State> pImagePackParams;          // +0x50

    MovieDefBindStates(StateBag* psharedState)
    {
        static const State::StateType queried[8] = {
            State::State_FileOpener,     State::State_URLBuilder,     State::State_ImageCreator,
            State::State_ImportVisitor,  State::State_FontPackParams, State::State_BindState23,
            State::State_FontCompactorParams, State::State_ImagePackerParams};
        State* pstates[8] = {0, 0, 0, 0, 0, 0, 0, 0};

        psharedState->GetStatesAddRef(pstates, queried, 8);
        pFileOpener          = *pstates[0];
        pURLBuilder          = *pstates[1];
        pImageCreator        = *pstates[2];
        pImportVisitor       = *pstates[3];
        pFontPackParams      = *pstates[4];
        pBindState23         = *pstates[5];
        pFontCompactorParams = *pstates[6];
        pImagePackParams     = *pstates[7];
    }
};

// A MovieDataDef bound under one set of binding states.
class MovieDefImpl : public MovieDef
{
public:
    enum BindStateFlags
    {
        BSF_Frame1Loaded    = 0x100,
        BSF_LastFrameLoaded = 0x200
    };

    // Binding produced by the bind process.
    class BindTaskData : public RefCountBase<BindTaskData, Stat_Default_Mem>
    {
        friend class MovieDefImpl;

        MemoryHeap*       pHeap;            // +0x10
        Ptr<MovieDataDef> pDataDef;         // +0x18
        MovieDefImpl*     pDefImpl_Unsafe;  // +0x20
        unsigned          LoadFlags;        // +0x28
        ResourceBinding   ResourceBinding;  // +0x30

    public:
        ~BindTaskData();

        // Blocks until all BindStateFlags bits in flags are set; false if binding failed.
        bool WaitForBindStateFlags(unsigned flags);
        MovieDataDef* GetDataDef() const { return pDataDef; }
    };

    Ptr<StateBagImpl>       pStateBag;    // +0x20
    Ptr<LoaderImpl>         pLoaderImpl;  // +0x28
    Ptr<MovieDefBindStates> pBindStates;  // +0x30
    Ptr<BindTaskData>       pBindData;    // +0x38

    MovieDefImpl(MovieDataDef* pdataDef, MovieDefBindStates* pstates, LoaderImpl* ploaderImpl, unsigned loadConstants,
                 StateBagImpl* pdelegateState = 0, MemoryHeap* pargHeap = 0, bool debugHeap = false,
                 UPInt memoryArena = 0);
    ~MovieDefImpl();

    // MovieDef overrides (exe: GetFileURL 0x1425cfb50, ...); declared so the class is concrete.
    virtual unsigned            GetVersion() const;
    virtual unsigned            GetLoadingFrame() const;
    virtual float               GetWidth() const;
    virtual float               GetHeight() const;
    virtual unsigned            GetFrameCount() const;
    virtual float               GetFrameRate() const;
    virtual Render::Rect<float> GetFrameRect() const;
    virtual unsigned            GetSWFFlags() const;
    virtual const char*         GetFileURL() const;

    // Library key of the binding of pdataDef under pstates.
    static ResourceKey SF_STDCALL CreateMovieKey(MovieDataDef* pdataDef, MovieDefBindStates* pstates);

    MovieDataDef*    GetDataDef() const         { return pBindData->GetDataDef(); }
    unsigned         GetLoadFlags() const       { return pBindData->LoadFlags; }
    ResourceBinding& GetResourceBinding() const { return pBindData->ResourceBinding; }
};

}} // namespace Scaleform::GFx

#endif
