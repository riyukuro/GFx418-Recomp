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

namespace Scaleform { namespace GFx {

class StateBagImpl;
class LoaderImpl;
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
};

// Loaded movie as seen by the user: Resource at +0, StateBag at +0x18.
class MovieDef : public Resource, public StateBag
{
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
    // Load-time data (frames, fonts, exports); filled by the LoadProcess.
    class LoadTaskData : public RefCountBase<LoadTaskData, Stat_Default_Mem>
    {
    public:
        void             WaitForLoadFinish();
        FontDataUseNode* GetFirstFont() const { return pFonts; }

    private:
        UByte                     Unknown10[0x110]; // +0x10
        FontDataUseNode* volatile pFonts;           // +0x120
    };

    void             WaitForLoadFinish() const { pData->WaitForLoadFinish(); }
    FontDataUseNode* GetFirstFont() const      { return pData->GetFirstFont(); }

private:
    UByte             Unknown18[0x28]; // +0x18
public:
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
        MovieDataDef* GetDataDef() const { return pDataDef; }
    };

    Ptr<StateBagImpl>       pStateBag;    // +0x20
    Ptr<LoaderImpl>         pLoaderImpl;  // +0x28
    Ptr<MovieDefBindStates> pBindStates;  // +0x30
    Ptr<BindTaskData>       pBindData;    // +0x38

    ~MovieDefImpl();

    MovieDataDef*    GetDataDef() const         { return pBindData->GetDataDef(); }
    unsigned         GetLoadFlags() const       { return pBindData->LoadFlags; }
    ResourceBinding& GetResourceBinding() const { return pBindData->ResourceBinding; }
};

}} // namespace Scaleform::GFx

#endif
