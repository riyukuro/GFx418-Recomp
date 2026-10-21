// Recovered Scaleform 4.1.18 GFx: DisplayList (the depth-sorted children of a container) and DisplayObjContainer.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members or virtuals.
//
// DisplayObjContainer is 0x110 bytes (ctor 0x1425fbbf0, vftable 0x14318e318, LogBase vftable 0x14318e6e0); its new
// virtuals are slots 115..120 of the Sprite vftable. DisplayList is 0x30 bytes (ctor 0x1425f8d80).
#ifndef MS2_SF_GFX_DISPLAYOBJCONTAINER_H
#define MS2_SF_GFX_DISPLAYOBJCONTAINER_H

#include "gfx_interactiveobject.h"
#include "../kernel/sf_array.h"

namespace Scaleform { namespace GFx {

class CharPosInfo;
class SwfEvent;
struct CharacterCreateInfo;
class MovieDef;
class MovieDefRootNode;
class Sprite;

// Tag memory of the movie data (the SwfEvent handler arrays are allocated with it).
enum { StatMD_Tags_Mem = 0x104 };

class DisplayList
{
public:
    // One child: the object and its index in the render container (mask objects keep their own index).
    class DisplayEntry
    {
    public:
        DisplayObjectBase* pCharacter;
        unsigned           TreeIndex;
        unsigned           MaskTreeIndex;
    };
    struct DepthToIndexContainer;

    DisplayList();   // 0x1425f8d80

    ArrayLH<DisplayEntry>          DisplayObjectArray; // +0x00
    mutable DepthToIndexContainer* DepthToIndexMap;    // +0x18
    mutable DisplayObject*         pCachedChar;        // +0x20 last name lookup hit
    mutable UByte                  Flags;              // +0x28

    UPInt GetCount() const { return DisplayObjectArray.GetSize(); }
    DisplayObjectBase* GetDisplayObject(UPInt index) const { return DisplayObjectArray[index].pCharacter; }

    // Removes every entry, unloading and releasing the objects (0x1425f9100).
    void Clear(DisplayObjectBase* powner);
};

class DisplayObjContainer : public InteractiveObject
{
public:
    DisplayObjContainer(MovieDefImpl* pbindingDefImpl, ASMovieRootBase* pasRoot, InteractiveObject* pparent,
                        ResourceId id);   // 0x1425fbbf0
    virtual ~DisplayObjContainer();

    virtual RectF           GetBounds(const Matrix& t) const;
    virtual CharacterDef*   GetCharacterDef() const;
    virtual RectF           GetRectBounds(const Matrix& t) const;
    virtual FontManager*    GetFontManager() const;
    virtual void            SetStateChangeFlags(UByte flags);
    virtual void            ForceShutdown();
    virtual TopMostResult   GetTopMostMouseEntity(const PointF& pt, TopMostDescr* pdescr);
    virtual bool            PointTestLocal(const PointF& pt, UByte hitTestMask = 0) const;
    virtual void            PropagateMouseEvent(const EventId& id);
    virtual void            PropagateKeyEvent(const EventId& id, int* pkeyMask);
    virtual void            PropagateFocusGroupMask(unsigned mask);
    virtual void            RemoveDisplayObject(DisplayObjectBase* ch);
    virtual bool            Has3D();
    virtual void            UpdateViewAndPerspective();

    // addFlags is an unsigned long in the exe's signature.
    virtual DisplayObjectBase* AddDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                const ArrayLH<SwfEvent*, StatMD_Tags_Mem>* peventHandlers,
                                                const void* pinitSource, unsigned initSourceLen,
                                                unsigned long addFlags, CharacterCreateInfo* pcharCreateOverride,
                                                InteractiveObject* origChar);
    virtual void            ExecuteImportedInitActions(MovieDef* psourceMovie);
    virtual Sprite*         GetHitArea() const;
    virtual Sprite*         GetHitAreaHolder() const;
    virtual void            OnInsertionAsLevel(int level);
    virtual void            CreateAndReplaceDisplayObject(const CharPosInfo& pos, const ASString& name,
                                                          DisplayObjectBase** newChar);

    MovieDefRootNode* FindRootNode() const;      // 0x1425fc4a0

protected:
    void              AssignRootNode(bool importFlag = false);   // 0x1425fbe90

public:

    DisplayList       mDisplayList;  // +0xd8
    MovieDefRootNode* pRootNode;     // +0x108 set on the root of a loaded movie
};

}} // namespace Scaleform::GFx

#endif
