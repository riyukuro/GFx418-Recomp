// Recovered Scaleform 4.1.18 GFx: character definitions as the loader builds them (the CharacterDef base) and the
// timelines among them (TimelineDef: sprites and the movie data).
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder.
//
// CharacterDef::Display binds to the exe (0x142645600) until GFx_CharacterDef is recovered.
#ifndef MS2_SF_GFX_CHARACTERDEF_H
#define MS2_SF_GFX_CHARACTERDEF_H

#include "gfx_resource.h"
#include "../kernel/sf_array.h"
#include "../kernel/sf_string.h"
#include "../render/render_types2d.h"

namespace Scaleform { namespace GFx {

// Allocation stat of the character definitions.
enum { StatMD_CharDefs_Mem = 0x102 };

class DisplayContext;
class DisplayObjectBase;
class ExecuteTag;
class SoundStreamDef;

using Render::PointF;
using Render::RectF;

// The template of a timeline element, shared by its instances (vftable slots 4..9 after the Resource ones). Its vptr
// stores are dead in every constructor / destructor of the exe, hence novtable; the vftable itself (0x1431846c8, no
// RTTI locator) and its deleting destructor sit in the TextFieldDef source, which defines
// SF_GFX_CHARACTERDEF_VFTABLE to emit them.
#ifdef SF_GFX_CHARACTERDEF_VFTABLE
#define SF_GFX_CHARACTERDEF_NOVTABLE
#else
#define SF_GFX_CHARACTERDEF_NOVTABLE __declspec(novtable)
#endif
class SF_GFX_CHARACTERDEF_NOVTABLE CharacterDef : public Resource
{
    ResourceId Id; // +0x18

public:
    enum CharacterDefType
    {
        Unknown,
        Shape,
        MovieData,
        Sprite,
        TextField,
        StaticText,
        Button,
        Video,
        Bitmap,
        EmptySprite
    };

    // Id starts as ResourceId::InvalidId.
    virtual ~CharacterDef() {}

    virtual CharacterDefType GetType() const = 0;
    virtual void             Display(DisplayContext& context, DisplayObjectBase* pinstanceInfo);
    virtual bool             DefPointTestLocal(const PointF&, bool = 0, const DisplayObjectBase* = 0) const
    {
        return false;
    }
    virtual RectF    GetBoundsLocal(float = 0) const     { return RectF(); }
    virtual RectF    GetRectBoundsLocal(float = 0) const { return RectF(); }
    virtual unsigned GetVersion() const                  { return 0; }

    ResourceId GetId() const          { return Id; }
    void       SetId(ResourceId rid)  { Id = rid; }
};
// The deleting destructor frees 0x20 bytes.
static_assert(sizeof(CharacterDef) == 0x20, "CharacterDef size");

// A character with frames (vftable slots 10..18): the frame tags, the frame labels and the streaming sound.
class __declspec(novtable) TimelineDef : public CharacterDef
{
public:
    // The tags of one frame; they live in the tag memory of the movie data.
    struct Frame
    {
        ExecuteTag** pTagPtrList;
        unsigned     TagCount;

        Frame() : pTagPtrList(0), TagCount(0) {}
        Frame(const Frame& src) : pTagPtrList(src.pTagPtrList), TagCount(src.TagCount) {}
        Frame& operator=(const Frame& src)
        {
            pTagPtrList = src.pTagPtrList;
            TagCount    = src.TagCount;
            return *this;
        }

        // Runs the destructors of the tags (their memory belongs to the movie data).
        void DestroyTags();

        unsigned    GetTagCount() const          { return TagCount; }
        ExecuteTag* GetTag(unsigned index) const { return pTagPtrList[index]; }
    };

    virtual unsigned       GetFrameCount() const                                                       = 0;
    // Frames are returned by value: the playlist may grow on the loading thread.
    virtual const Frame    GetPlaylist(int frameNumber) const                                          = 0;
    virtual bool           GetInitActions(Frame* pframe, int frameNumber) const                        = 0;
    virtual bool           GetLabeledFrame(const char* label, unsigned* frameNumber,
                                           bool translateNumbers = 1) const                            = 0;
    virtual const String*  GetFrameLabel(unsigned frameNumber, unsigned* exactFrameNumberForLabel = 0) const = 0;
    // Appends the labels of a frame (there may be several) to destArr.
    virtual Array<String>* GetFrameLabels(unsigned frameNumber, Array<String>* destArr) const          = 0;
    virtual SoundStreamDef* GetSoundStream() const                                                     = 0;
    virtual void           SetSoundStream(SoundStreamDef* pdef)                                        = 0;
    virtual unsigned       GetLoadingFrame() const                                                     = 0;
};

}} // namespace Scaleform::GFx

#endif
