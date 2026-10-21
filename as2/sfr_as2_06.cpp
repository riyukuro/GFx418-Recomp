// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 array element storage and
// the script runtime entry points from Init to Reset.
// MS2-UNIT: sfr_as2_06
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14295d700-0x14295d840 .text$mn
// MS2-RANGE: 0x14295d970-0x14295da40 .text$mn
// MS2-RANGE: 0x142961720-0x142961830 .text$mn
// MS2-RANGE: 0x142962010-0x1429620d0 .text$mn
// MS2-RANGE: 0x142966270-0x142966370 .text$mn
// MS2-RANGE: 0x1429684d0-0x142968560 .text$mn
// MS2-RANGE: 0x142968560-0x142968610 .text$mn
// MS2-RANGE: 0x14296f1b0-0x14296f260 .text$mn
// MS2-RANGE: 0x142971ba0-0x142971c50 .text$mn
// MS2-RANGE: 0x142971c50-0x142971cc0 .text$mn
// MS2-RANGE: 0x14297ca70-0x14297cae0 .text$mn
// MS2-RANGE: 0x14297d0d0-0x14297d1e0 .text$mn
// MS2-RANGE: 0x14297d4b0-0x14297d550 .text$mn
// MS2-RANGE: 0x14297d5f0-0x14297d690 .text$mn
// MS2-RANGE: 0x14297d7d0-0x14297d870 .text$mn
// MS2-RANGE: 0x14297d870-0x14297d910 .text$mn
// MS2-RANGE: 0x14297d910-0x14297d9b0 .text$mn
// MS2-RANGE: 0x14297d9b0-0x14297da50 .text$mn
// MS2-RANGE: 0x14297da50-0x14297daf0 .text$mn
// MS2-RANGE: 0x14297daf0-0x14297db90 .text$mn
// MS2-RANGE: 0x14297db90-0x14297dc30 .text$mn
// MS2-RANGE: 0x14297dcd0-0x14297dd70 .text$mn
// MS2-RANGE: 0x14297e060-0x14297e0e0 .text$mn
// MS2-RANGE: 0x14297e230-0x14297e2b0 .text$mn
// MS2-RANGE: 0x14297e2b0-0x14297e330 .text$mn
// MS2-RANGE: 0x14297e330-0x14297e3f0 .text$mn
// MS2-RANGE: 0x14297e450-0x14297e500 .text$mn
// MS2-RANGE: 0x14297e500-0x14297e5a0 .text$mn
// MS2-RANGE: 0x14297e5a0-0x14297e640 .text$mn

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_avmsprite.h"
#include "../include/gfx/as2/as2_keyobject.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_movieroot.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// @0x142961720
void ArrayObject::InitArray(const FnCall& fn)
{
    Value index;
    for (int i = 0; i < fn.NArgs; i++)
    {
        index.SetInt(i);
        SetMember(fn.Env, index.ToString(fn.Env), fn.Arg(i));
    }
}

// MS2-FUNCTIONAL jump offsets of the inlined Object::HasMember
// @0x14295d700
bool ArrayObject::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    int idx;
    if ((idx = ParseIndex(name)) >= 0)
    {
        if (idx >= (int)Elements.GetSize() || Elements[idx] == 0 || Elements[idx]->IsUndefined() ||
            Elements[idx]->IsNull())
            return false;
        return true;
    }
    return Object::HasMember(psc, name, inclPrototypes);
}

// MS2-FUNCTIONAL the exe keeps the copied member's type in a register and skips its destructor on the not found path
// @0x14295d970
bool Object::HasMember(ASStringContext* psc, const ASString& name, bool inclPrototypes)
{
    Member member;
    if (MemberHash_Get(&Members, name, &member))
        return true;
    else if (inclPrototypes && pProto)
        return pProto->HasMember(psc, name, true);
    return false;
}

// @0x142962010
void ArrayObject::InsertEmpty(int start, int count)
{
    int i;
    int oldSize = (int)Elements.GetSize();
    Elements.Resize(oldSize + count);
    if (oldSize)
    {
        for (i = (int)Elements.GetSize() - 1; i >= start + count; --i)
            Elements[i] = Elements[i - count];
    }
    for (i = 0; i < count; i++)
        Elements[start + i] = 0;
}

// @0x142966270
void ArrayObject::JoinToString(Environment* penv, StringBuffer* pbuffer, const char* pdelimiter) const
{
    pbuffer->Clear();
    Value undefinedValue;
    for (unsigned i = 0; i < Elements.GetSize(); i++)
    {
        if (i)
            pbuffer->AppendString(pdelimiter);
        if (Elements[i])
        {
            ASString s(Elements[i]->ToString(penv));
            pbuffer->AppendString(s.ToCStr());
        }
        else
        {
            ASString s(undefinedValue.ToString(penv));
            pbuffer->AppendString(s.ToCStr());
        }
    }
}

// @0x142971ba0
void ArrayObject::PushBack(const Value& val)
{
    Elements.PushBack(SF_HEAP_AUTO_NEW(this) Value(val));
}

// @0x142971c50
void ArrayObject::PushBack()
{
    Elements.PushBack(0);
}

// @0x1429684d0
void ArrayObject::MakeDeepCopy(MemoryHeap* pheap)
{
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
    {
        if (Elements[i])
        {
            Value* pval = SF_HEAP_NEW(pheap) Value(*Elements[i]);
            Elements[i] = pval;
        }
    }
}

// @0x142968560
void ArrayObject::MakeDeepCopyFrom(MemoryHeap* pheap, const ArrayObject& ao)
{
    Elements.Resize(ao.Elements.GetSize());
    for (UPInt i = 0, n = Elements.GetSize(); i < n; i++)
    {
        if (ao.Elements[i])
        {
            Value* pval = SF_HEAP_NEW(pheap) Value(*ao.Elements[i]);
            Elements[i] = pval;
        }
    }
}

// @0x14297d0d0
void ArrayObject::RemoveElements(int start, int count)
{
    if (Elements.GetSize())
    {
        int i;
        for (i = 0; i < count; i++)
            delete Elements[start + i];
        for (i = start + count; i < (int)Elements.GetSize(); i++)
        {
            Elements[i - count] = Elements[i];
            Elements[i]         = 0;
        }
        Elements.Resize(Elements.GetSize() - count);
    }
}

// @0x14297e330
void ArrayObject::Resize(int size)
{
    if (size < 0)
        size = 0;
    UPInt i;
    UPInt newSize = (UPInt)size;
    UPInt oldSize = Elements.GetSize();
    for (i = newSize; i < oldSize; i++)
        delete Elements[i];
    Elements.Resize(newSize);
    for (i = oldSize; i < newSize; i++)
        Elements[i] = 0;
}

// @0x14296f1b0
void ArrayObject::PopFront_Call()
{
    PopFront();
}

}}} // namespace Scaleform::GFx::AS2

namespace Scaleform {

// The out-of-line array growth of the AS2 containers.
// @0x14297d4b0
template void ArrayDataBase<GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Page*,
                            AllocatorLH<GFx::AS2::PagedStack<GFx::AS2::Value, 32>::Page*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d5f0
template void ArrayDataBase<GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::Page*,
                            AllocatorLH<GFx::AS2::PagedStack<Ptr<GFx::AS2::FunctionObject>, 32>::Page*, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d7d0
template void ArrayDataBase<Ptr<GFx::AS2::Object>, AllocatorLH<Ptr<GFx::AS2::Object>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d870
template void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297d9b0
template void ArrayDataBase<GFx::AS2::ArraySortFunctor, AllocatorGH<GFx::AS2::ArraySortFunctor, 2>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297da50
template void ArrayDataBase<GFx::AS2::Value, AllocatorGH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                        UPInt);
// @0x14297daf0
template void ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, 2>, ArrayDefaultPolicy>::Reserve(const void*,
                                                                                                        UPInt);
// @0x14297db90
template void ArrayDataBase<GFx::AS2::Value, AllocatorLH<GFx::AS2::Value, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297dcd0
template void ArrayDataBase<bool, AllocatorLH<bool, 2>, ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// TryBlocks_Resize
// @0x14297e060
template void ArrayBase<ArrayData<GFx::AS2::Environment::TryDescr, AllocatorLH<GFx::AS2::Environment::TryDescr, 2>,
                                  ArrayDefaultPolicy> >::Resize(UPInt);
// ArrayObjectElements_Resize (pinned at the end)
template void ArrayData<GFx::AS2::Value*, AllocatorLH<GFx::AS2::Value*, GFx::AS2::StatMV_ActionScript_Mem>,
                        ArrayDefaultPolicy>::Resize(UPInt);
// (pinned at the end)
template void ArrayData<GFx::AS2::Object*, AllocatorGH<GFx::AS2::Object*, 2>, ArrayDefaultPolicy>::Resize(UPInt);
// @0x14297d910
template void ArrayDataBase<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                            ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// @0x14297e450
template void ArrayDataBase<Ptr<GFx::AS2::LocalFrame>, AllocatorLH<Ptr<GFx::AS2::LocalFrame>, 2>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// @0x14297e500
template void ArrayDataBase<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);
// RemoveAt functional (pinned at the end): cl inlines the ResizeNoConstruct of Clear, the exe tail-calls it
template void ArrayBase<ArrayData<Ptr<GFx::Sprite>, AllocatorLH<Ptr<GFx::Sprite>, GFx::StatMV_Other_Mem>,
                                  ArrayDefaultPolicy> >::RemoveAt(UPInt);
// @0x14297e5a0
template void ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS2::StatMV_ActionScript_Mem>,
                            ArrayDefaultPolicy>::ResizeNoConstruct(const void*, UPInt);

} // namespace Scaleform
// MS2-PIN: ?RemoveAt@?$ArrayBase@U?$ArrayData@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VSprite@GFx@Scaleform@@@Scaleform@@$0BEH@@2@UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@QEAAX_K@Z 0x14297ca70
// MS2-PIN: ?Resize@?$ArrayData@PEAVValue@AS2@GFx@Scaleform@@U?$AllocatorLH@PEAVValue@AS2@GFx@Scaleform@@$0BED@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e2b0
// MS2-PIN: ?Resize@?$ArrayData@PEAVObject@AS2@GFx@Scaleform@@U?$AllocatorGH@PEAVObject@AS2@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x14297e230
