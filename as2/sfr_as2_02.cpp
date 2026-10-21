// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS2 collector traversals
// (ForEachChild_GC of the collectable classes and of every built-in prototype, for the release, mark-in-cycle and
// scan-in-use passes) and the Stage function stub.
// MS2-UNIT: sfr_as2_02
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x14290bed0-0x142914500 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin

#include "../include/gfx/as2/as2_action.h"
#include "../include/gfx/as2/as2_arrayobject.h"
#include "../include/gfx/as2/as2_bitmapfilter.h"
#include "../include/gfx/as2/as2_builtinobjects.h"
#include "../include/gfx/as2/as2_colortransform.h"
#include "../include/gfx/as2/as2_date.h"
#include "../include/gfx/as2/as2_matrixobject.h"
#include "../include/gfx/as2/as2_objectproto.h"
#include "../include/gfx/as2/as2_pointobject.h"
#include "../include/gfx/as2/as2_rectangleobject.h"
#include "../include/gfx/as2/as2_refcountcollector.h"
#include "../include/gfx/as2/as2_stringobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

typedef ASRefCountBaseType::Collector Collector;

// The Stage methods that do nothing in GFx.
void GFx_StageFuncStub(const FnCall& fn)
{
    fn.Result->SetUndefined();
}

// Instantiates ForEachChild_GC of a class for the three collector passes.
#define MS2_AS2_GC_FOR_EACH_CHILD(Class)                                                                        \
    template void Class::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector * prcc) const;           \
    template void Class::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector * prcc) const;       \
    template void Class::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector * prcc) const;

template<class Functor>
void FunctionRefBase::ForEachChild_GC(Collector* prcc) const
{
    if (Function)
        Functor::Call(prcc, Function);
    if (pLocalFrame)
        Functor::Call(prcc, pLocalFrame);
}
MS2_AS2_GC_FOR_EACH_CHILD(FunctionRefBase)

template<class Functor>
void Value::ForEachChild_GC(Collector* prcc) const
{
    if (IsFunction())
        V.FunctionValue.template ForEachChild_GC<Functor>(prcc);
    else if (IsObject() && V.pObjectValue)
        Functor::Call(prcc, V.pObjectValue);
    else if (IsProperty())
        Functor::Call(prcc, V.pProperty);
}
MS2_AS2_GC_FOR_EACH_CHILD(Value)

template<class Functor>
void Object::ForEachChild_GC(Collector* prcc) const
{
    ASStringHash_GC<Member>::ConstIterator it = Members.Begin();
    while (it != Members.End())
    {
        const Value& value = it->Second.GetMemberValue();
        value.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
    ResolveHandler.template ForEachChild_GC<Functor>(prcc);
    if (pWatchpoints)
    {
        ASStringHash_GC<Watchpoint>::ConstIterator wit = pWatchpoints->Begin();
        while (wit != pWatchpoints->End())
        {
            const Watchpoint& wp = wit->Second;
            wp.template ForEachChild_GC<Functor>(prcc);
            ++wit;
        }
    }
    if (pProto)
        Functor::Call(prcc, pProto);
}
MS2_AS2_GC_FOR_EACH_CHILD(Object)

template<class Functor>
void LocalFrame::ForEachChild_GC(Collector* prcc) const
{
    ASStringHash_GC<Value>::ConstIterator it = Variables.Begin();
    while (it != Variables.End())
    {
        const Value& value = it->Second;
        value.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
    if (PrevFrame)
        Functor::Call(prcc, PrevFrame);
    Callee.template ForEachChild_GC<Functor>(prcc);
    Caller.template ForEachChild_GC<Functor>(prcc);
}
MS2_AS2_GC_FOR_EACH_CHILD(LocalFrame)

template<class Functor>
void ArrayObject::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    UPInt i, n;
    for (i = 0, n = Elements.GetSize(); i < n; i++)
    {
        Value* pval = Elements[i];
        if (pval)
            pval->template ForEachChild_GC<Functor>(prcc);
    }
}
template void ArrayObject::ForEachChild_GC<ASRefCountBaseType::ReleaseFunctor>(Collector* prcc) const;
template void ArrayObject::ForEachChild_GC<ASRefCountBaseType::ScanInUseFunctor>(Collector* prcc) const;

// The mark pass copy, which the exe does not inline into the prototype (the other two it does).
template<>
__declspec(noinline) void ArrayObject::ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(Collector* prcc) const
{
    Object::template ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
    UPInt i, n;
    for (i = 0, n = Elements.GetSize(); i < n; i++)
    {
        Value* pval = Elements[i];
        if (pval)
            pval->template ForEachChild_GC<ASRefCountBaseType::MarkInCycleFunctor>(prcc);
    }
}

MS2_AS2_GC_FOR_EACH_CHILD(SuperObject)

// Never inlined into the prototype in the exe.
template<class Functor>
__declspec(noinline) void TransformObject::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    if (Matrix)
        Functor::Call(prcc, Matrix);
    if (pColorTransform)
        Functor::Call(prcc, pColorTransform);
    if (PixelBounds)
        Functor::Call(prcc, PixelBounds);
}
MS2_AS2_GC_FOR_EACH_CHILD(TransformObject)

template<class Functor>
void MouseCtorFunction::ForEachChild_GC(Collector* prcc) const
{
    SetCursorTypeFunc.template ForEachChild_GC<Functor>(prcc);
    if (pListenersArray)
        Functor::Call(prcc, pListenersArray);
    CFunctionObject::template ForEachChild_GC<Functor>(prcc);
}
MS2_AS2_GC_FOR_EACH_CHILD(MouseCtorFunction)

template<class Functor>
void SharedObjectCtorFunction::ForEachChild_GC(Collector* prcc) const
{
    Object::template ForEachChild_GC<Functor>(prcc);
    ASStringHash_GC<SharedObjectPtr>::ConstIterator it = SharedObjects.Begin();
    while (it != SharedObjects.End())
    {
        const SharedObjectPtr& pobj = it->Second;
        pobj.template ForEachChild_GC<Functor>(prcc);
        ++it;
    }
}
MS2_AS2_GC_FOR_EACH_CHILD(SharedObjectCtorFunction)

// The built-in prototypes.
#define MS2_AS2_GC_PROTOTYPE(Class) MS2_AS2_GC_FOR_EACH_CHILD(Prototype<Class>)

MS2_AS2_GC_PROTOTYPE(AmpMarker)
MS2_AS2_GC_PROTOTYPE(ArrayObject)
MS2_AS2_GC_PROTOTYPE(Selection)
MS2_AS2_GC_PROTOTYPE(ColorMatrixFilterObject)
MS2_AS2_GC_PROTOTYPE(SharedObject)
MS2_AS2_GC_PROTOTYPE(BevelFilterObject)
MS2_AS2_GC_PROTOTYPE(BlurFilterObject)
MS2_AS2_GC_PROTOTYPE(GlowFilterObject)
MS2_AS2_GC_PROTOTYPE(DropShadowFilterObject)
MS2_AS2_GC_PROTOTYPE(BitmapFilterObject)
MS2_AS2_GC_PROTOTYPE(BooleanObject)
MS2_AS2_GC_PROTOTYPE(TextSnapshotObject)
MS2_AS2_GC_PROTOTYPE(DateObject)
MS2_AS2_GC_PROTOTYPE(StringObject)
MS2_AS2_GC_PROTOTYPE(ExternalInterface)
MS2_AS2_GC_PROTOTYPE(ColorObject)
MS2_AS2_GC_PROTOTYPE(MouseObject)
MS2_AS2_GC_PROTOTYPE(NumberObject)
MS2_AS2_GC_PROTOTYPE(KeyObject)
MS2_AS2_GC_PROTOTYPE(AsBroadcaster)
MS2_AS2_GC_PROTOTYPE(Math)
MS2_AS2_GC_PROTOTYPE(ButtonObject)
MS2_AS2_GC_PROTOTYPE(BitmapData)
MS2_AS2_GC_PROTOTYPE(TextFieldObject)
MS2_AS2_GC_PROTOTYPE(StageObject)
MS2_AS2_GC_PROTOTYPE(PointObject)
MS2_AS2_GC_PROTOTYPE(RectangleObject)
MS2_AS2_GC_PROTOTYPE(MatrixObject)
MS2_AS2_GC_PROTOTYPE(LoadVarsObject)
MS2_AS2_GC_PROTOTYPE(Object)
MS2_AS2_GC_PROTOTYPE(MovieClipLoader)
MS2_AS2_GC_PROTOTYPE(StyleSheetObject)
MS2_AS2_GC_PROTOTYPE(MovieClipObject)
MS2_AS2_GC_PROTOTYPE(TextFormatObject)
MS2_AS2_GC_PROTOTYPE(ColorTransformObject)
MS2_AS2_GC_PROTOTYPE(TransformObject)

}}} // namespace Scaleform::GFx::AS2
