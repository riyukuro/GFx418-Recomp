// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3 native classes. Our own
// source, written from the exe. The native method thunks are instances of the ThunkFuncN templates of
// as3_marshalling.h; they call through ThunkFuncN<...>::Method, defined in the sfr_as3di_* units.
// MS2-UNIT: sfr_as3_19
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x142523170-0x14252b580 .text$mn
// MS2-RANGE: 0x14252c7e0-0x142542820 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Reserve@?$ArrayDataBase@UPair@Slots@AS3@GFx@Scaleform@@U?$AllocatorLH@UPair@Slots@AS3@GFx@Scaleform@@$0BEM@@5@UArrayDefaultPolicy@5@@Scaleform@@QEAAXPEBX_K@Z 0x142523170 ; probe
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@U?$AllocatorLH@V?$Ptr@VInteractiveObject@GFx@Scaleform@@@Scaleform@@$0BED@@2@UArrayDefaultPolicy@2@@Scaleform@@QEAAXPEBX_K@Z 0x142523530 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@UASStringNode@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@UASStringNode@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425235d0 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142523670 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VTraits@ClassTraits@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142523710 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VVMAbcFile@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$0BFE@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x1425238f0 ; order
// MS2-PIN: ?Reserve@?$ArrayDataBase@VASString@GFx@Scaleform@@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BED@@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAXPEBX_K@Z 0x142523a30 ; order
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@PEAV?$ArrayLH@UListener@EventDispatcher@fl_events@Instances@AS3@GFx@Scaleform@@$01UArrayDefaultPolicy@7@@3@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425422c0 ; unique
// MS2-PINS-END tplpin
#define MS2_AS3_SCU   // AS3_All.cpp SCU: AS3_Object.cpp weak-ref bodies inline (as3_value.h)
#include "ms2/scaleform/include/kernel/sf_std.h"
#include "ms2/scaleform/include/gfx/gfx_input.h"
#include "ms2/scaleform/include/gfx/as3/as3_vmabcfile.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_natives.h"
#include "ms2/scaleform/include/gfx/as3/as3_readargs.h"
#include "ms2/scaleform/include/gfx/as3/as3_callframe.h"
#include "ms2/scaleform/include/gfx/as3/as3_intervaltimer.h"
#include "ms2/scaleform/include/gfx/gfx_loaderimpl.h"
#include "ms2/scaleform/include/gfx/gfx_movieimpl.h"
#include "ms2/scaleform/include/gfx/as3/as3_asvm.h"
#include "ms2/scaleform/include/gfx/as3/as3_avm.h"
#include "ms2/scaleform/include/gfx/gfx_textfield.h"
#include "ms2/scaleform/include/gfx/as3/as3_valueobjectinterface.h"
#include "ms2/scaleform/include/gfx/gfx_button.h"
#include "ms2/scaleform/include/gfx/as3/as3_mnhash.h"
#include "ms2/scaleform/include/gfx/as3/as3_obj_core.h"
#include <cmath>

namespace Scaleform { namespace GFx { namespace AS3 { namespace TR { class State; } }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_1425245c0(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524470(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_1425247f0(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524870(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_1425248e0(UPInt* a, const void* addr, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524c30(UPInt* a, const void* addr, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524af0(UPInt* a, const void* addr, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524680(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524710(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_1425244e0(UPInt* a, UPInt n); }}}
namespace Scaleform { namespace GFx { namespace AS3 { extern "C" void FUN_142524a30(UPInt* a, const void* addr, UPInt n); }}}
void FUN_14251cd30(Scaleform::GFx::AS3::TR::State* state, Scaleform::GFx::AS3::Value* popped);   // State::PopOpValue
void FUN_1424e6aa0(Scaleform::UPInt tracer, void* state, Scaleform::UInt64 pos, int a, bool b);
void FUN_1424d6cf0(void* err, int id, void* vm, const void* a1, const void* a2);   // VM::Error::Error(id, vm, Value, Value)
void FUN_1424d6f40(void* err, int id, void* vm, const void* a1);   // VM::Error::Error(id, vm, Value)
void FUN_1424d79f0(void* err, int id, void* vm, const char* a1, const void* a2);   // VM::Error::Error(id, vm, char*, Value)
void FUN_142529f70(void* button, int state, void* obj);   // AvmButton::SetStateObject
void FUN_1424ffc10(Scaleform::UPInt a, Scaleform::UPInt b, Scaleform::UPInt c, int d, const Scaleform::GFx::AS3::Value* e);
void FUN_1424f03f0(unsigned char* self, void* heap);                                // HeapLimit::Collect
void FUN_14241a500(Scaleform::UPInt traits, Scaleform::UPInt* ret, Scaleform::UPInt t);   // InstanceTraits::Array::MakeInstance
void FUN_14241d980(Scaleform::UPInt arr, Scaleform::UPInt stack, Scaleform::UInt32 n);   // Array: fill from the operand stack
void FUN_14241b920(Scaleform::UPInt tbl, void* ret, Scaleform::UPInt a, Scaleform::UPInt b);   // class table: find interface traits
const Scaleform::GFx::AS3::Traits& FUN_14250ffc0(Scaleform::GFx::AS3::VM& vm, const Scaleform::GFx::AS3::Value& obj);   // Value traits
void* FUN_14250fa80(const Scaleform::GFx::AS3::Traits* tr);   // Traits::GetVT
void FUN_1424e6aa0(Scaleform::UPInt tracer, Scaleform::UPInt a, Scaleform::SPInt idx, int b, int c);   // Tracer: trace a block from idx
void FUN_14241fe30(void* arr, Scaleform::UInt32 size);   // Array::SetLength
bool FUN_142514000(Scaleform::UPInt tracer, const void* v);   // Tracer::IsBooleanType
bool FUN_142514470(Scaleform::UPInt tracer, const void* v);   // Tracer::IsNumberType
bool FUN_142514c30(Scaleform::UPInt tracer, const void* v);   // Tracer::IsIntType
bool FUN_142514e10(Scaleform::UPInt tracer, const void* v);   // Tracer::IsStringType
bool FUN_1425150c0(Scaleform::UPInt tracer, const void* v);   // Tracer::IsUIntType
bool FUN_142514510(Scaleform::UPInt tracer, void* traits);   // Tracer::IsNumericType
bool FUN_142514a80(Scaleform::UPInt tracer, void* traits);   // Tracer::IsPrimitiveType
void* FUN_14250fe80(void* state, const void* v);             // TR::State::GetValueTraits
void FUN_14252ecb0(void* vm, const void* error, const void* classInfo);   // VM: raise the error as an instance of the class
char* FUN_1424f1a30(void* v, void* ok, unsigned long* out);         // Value::Convert2UInt32
char* FUN_1424f0d30(void* v, void* ok, long* out);                  // Value::Convert2SInt32 (CheckResult returned in *ok)
void FUN_1424d9640(void* ra, Scaleform::GFx::AS3::VM* vm, void* state, Scaleform::UInt32 argc);   // TR::ReadArgs::ReadArgs
void FUN_1424dea90(void* ra);                                                                         // TR::ReadArgs::~ReadArgs
void FUN_1424d9530(void* ra, Scaleform::GFx::AS3::VM* vm, Scaleform::UInt32 argc);                     // ReadArgs::ReadArgs
void FUN_1424de9e0(void* ra);                                          // ReadArgs::~ReadArgs
bool FUN_1425146d0(Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* v, const void* traits);
Scaleform::UPInt FUN_14250fa80(Scaleform::UPInt traits);                           // Traits::GetVT
void FUN_142500260(Scaleform::GFx::AS3::VM* vm, Scaleform::UInt32 index, Scaleform::UPInt traits, Scaleform::GFx::AS3::Value* obj);
void FUN_142501b00(Scaleform::GFx::AS3::PropRef* prop, Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Value* obj, const Scaleform::GFx::AS3::Multiname* mn, int mode);   // FindObjProperty
Scaleform::UPInt FUN_142508330(void* frame);
int FUN_142519a00(Scaleform::GFx::AS3::VM* vm, Scaleform::UPInt index, void* frame);
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_1425085b0(const Scaleform::GFx::AS3::SlotInfo* si, Scaleform::GFx::AS3::VM* vm);   // the slot's declared type
void FUN_142508720(const Scaleform::GFx::AS3::SlotInfo* si, Scaleform::GFx::ASString* name, Scaleform::GFx::AS3::VM* vm);       // its name
void FUN_14250e770(const void* si, void* ok, Scaleform::GFx::AS3::Value* result, Scaleform::GFx::AS3::Object* obj);             // SlotInfo: load into result
void FUN_14251f710(Scaleform::UPInt arr, const Scaleform::UPInt* pos);   // Tracer: OrigOpcodePos.PushBack(*pos)
void FUN_1424e0b80(void* dst, const void* src);   // SlotInfo::operator=
void FUN_1426150b0(Scaleform::UPInt doc);   // DocView::SetAutoSizeX
void FUN_1426150d0(Scaleform::UPInt doc);   // DocView::SetAutoSizeY
void FUN_1425bc060(Scaleform::UPInt tf);   // TextField::SetDirtyFlag
void FUN_142511b00(Scaleform::UPInt tracer, Scaleform::UPInt* now, Scaleform::UPInt* old);   // Tracer: merge block states
char* FUN_142516c40(Scaleform::UPInt tracer, void* buf, Scaleform::UPInt* now, Scaleform::UPInt* old);   // Tracer: merge, result flag
void FUN_1425303b0(Scaleform::UPInt entry);   // shutdown of a registered entry
void FUN_1424ef2a0(Scaleform::UPInt array);   // ArrayDH::Clear
Scaleform::UPInt FUN_14250fa80(Scaleform::UPInt traits);   // Traits::GetVT
int FUN_1425de200(int mouseState);   // MouseState -> ButtonState
void FUN_1425048d0(Scaleform::UPInt movieRoot, const void* gfxValue, Scaleform::GFx::AS3::Value* out);   // MovieRoot::GFxValue2ASValue
void FUN_1424213b0(Scaleform::UPInt sparseArray, Scaleform::UInt32 ind, const Scaleform::GFx::AS3::Value* v);   // SparseArray::Set
void FUN_1423dfa20(void* obj);                                                                                                  // GC release of an object whose count reached its floor
Scaleform::GFx::AS3::ClassTraits::Traits** FUN_142414ac0(Scaleform::GFx::AS3::TClassTraitsCache* self, const Scaleform::GFx::ASString& name, const Scaleform::GFx::AS3::Instances::Namespace& ns);   // MultinameHash::Get
Scaleform::GFx::AS3::ClassTraits::Traits* FUN_142415520(void* globalObject, const Scaleform::GFx::ASString* name, const Scaleform::GFx::AS3::Instances::Namespace* ns);   // the global object's class of that name
void FUN_14251ccc0(Scaleform::GFx::AS3::TR::State* state, Scaleform::UPInt n);   // State::PopOp
void FUN_14251fcd0(Scaleform::UPInt tracer, Scaleform::UPInt regIndex);                    // Tracer: note register write
bool* FUN_1424f1390(Scaleform::GFx::AS3::Value* v, void* tmpNode, void* strOut);   // Value::ToStringValue style conversion
void FUN_1424e0860(void* out, unsigned long long value);                                                    // assign from the scratch value
void FUN_1424201a0(void* arr, void* heap, Scaleform::UPInt n);                      // ArrayDH<Value>::Resize growth
void FUN_142521f00(void* value);                                                    // Value::ReleaseInternal
Scaleform::SPInt FUN_1425f9200(void* list, void* obj);                          // DisplayList::FindDisplayIndex(const DisplayObjectBase*)
bool FUN_1425fb480(void* list, void* owner, Scaleform::UPInt i1, Scaleform::UPInt i2);   // DisplayList::SwapEntriesAtIndexes
void FUN_142517ed0(void* avmInteractiveObj);                                     // AvmInteractiveObj::MoveBranchInPlayList
int FUN_142520380(void* ctx, void* multiname);                                    // Tracer: number of run-time operands a multiname takes off the stack
void FUN_1425201f0(void* ctx, void* multiname);                                      // exec: resolve runtime multiname operands from the stack
unsigned char* FUN_14250ef80(unsigned char* ret, Scaleform::UPInt vm, Scaleform::UPInt traits, void* result, const void* obj, const void* multiname, int target); // GetSuperProperty
void FUN_142502570(Scaleform::UPInt vm, void* propRef, void* multiname);              // VM: resolve a multiname to a property reference
void FUN_14252c640(Scaleform::UPInt tracer, Scaleform::UPInt* pos);                      // Tracer: advance over padding/labels at pos
void FUN_1425212f0(Scaleform::UPInt tracer, Scaleform::UPInt pos);                                              // Tracer: per-opcode bookkeeping
void FUN_1424d7690(void* err, int id, void* vm, const char* a, const char* b);       // VM::Error::Error(id, vm, char*, char*)
Scaleform::UPInt FUN_142507f60(Scaleform::UPInt vm, const void* value);               // class traits of a value
void FUN_142500260(Scaleform::UPInt vm, unsigned int a, Scaleform::UPInt traits, void* value, unsigned int n, void* args);   // VM: call helper on a value with n arguments
Scaleform::UPInt FUN_1425081f0(Scaleform::UPInt vm);                                     // VM: class-traits factory
Scaleform::UPInt FUN_142563380(Scaleform::UPInt factory, Scaleform::UPInt traits);       // class traits for traits
void FUN_1423f1840(void* slot, Scaleform::UPInt obj);                                                                            // assign a refcounted object into a slot
void* FUN_1423edb60(void* mem, Scaleform::UPInt vm, Scaleform::UPInt factory, int kind, void* uri, const void* prefix);           // Instances::Namespace ctor
void FUN_142522350(void* hash, void* key);                                         // MultinameHash::Remove
bool FUN_142506000(Scaleform::UPInt root, void* valueOut, Scaleform::UPInt path);   // MovieRoot::GetVariable as AS3 Value
void FUN_14241e430(void* arr, const Scaleform::GFx::AS3::Value* v);   // ValueArray::PushBack
Scaleform::UPInt FUN_14250f9a0(Scaleform::UPInt vm, Scaleform::UPInt link, Scaleform::UPInt entry);   // class table entry -> traits
void FUN_1423eb030(void* hash, void* hash2, void* nodeRef, Scaleform::UPInt hashValue);   // MultinameHash::add
Scaleform::UPInt FUN_14250a060(Scaleform::UPInt vm, void* value);   // value -> traits
Scaleform::UPInt FUN_14250a550(Scaleform::UPInt vm);   // the VM's fallback object (global)
void FUN_1424d7130(void* err, int id, void* vm, const void* value, const char* s);   // VM::Error::Error(id, vm, Value, char*)
void FUN_142508bd0(Scaleform::UPInt obj, void* out, int hint);   // Object::GetDefaultValue-style conversion to a primitive
Scaleform::UInt8* FUN_14250d2f0(void* ret, Scaleform::UPInt vm, void* obj, void* mn, void* result);   // VM::GetProperty (result written to the last slot)
void FUN_1424d2890(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (8-byte key)
void FUN_1424d2be0(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (int to AutoPtr map)
void FUN_1424d2d50(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (4-byte key)
void FUN_1424d2eb0(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (4-byte key to SPtr)
void FUN_1424d3030(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (pointer key to Resource)
void FUN_1424d3200(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (8-byte key to SPtr)
void FUN_1424d3380(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (multiname key to SPtr)
void FUN_1424d3530(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (ASStringNode pointer)
void FUN_1424d3870(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (ASString to Value)
void FUN_1424d5020(void* tbl, Scaleform::UPInt heap, void* key, Scaleform::UInt64 hash);   // HashSet add (SPtr key)
Scaleform::UInt64 FUN_1424e0f00(void* self, void* key);   // multiname key hash functor
void FUN_1424dc730(void* arr);   // ~ArrayDataBase<WeakPtr<DisplayObject>>
void FUN_1424dcb40(void* node);   // ~HashNode<ASString,Value>
void FUN_1425a4030(void* res);   // Resource::Release
void FUN_1424eef00(void* tbl, Scaleform::UPInt heap);   // HashSetBase::CheckExpand
void FUN_1424eeff0(void* tbl, Scaleform::UPInt heap);   // HashSetBase::CheckExpand (dynamic attributes)
void FUN_1424d5390(void* dst, void* src);   // HashNode<DynAttrsKey,Value> copy constructor
void FUN_1424dcac0(void* node);   // ~HashNode<DynAttrsKey,Value>
bool FUN_1425149a0(Scaleform::UPInt traits, Scaleform::UPInt src);   // traits setup from a class-traits owner
bool FUN_142514560(Scaleform::UPInt src, Scaleform::UPInt dst);   // traits setup from instance traits

void FUN_14250b240(Scaleform::UPInt link, Scaleform::UPInt* out, Scaleform::SPInt idx);   // VMAbcFile::GetInternedString (hidden return)
Scaleform::UPInt FUN_142507b80(Scaleform::UPInt traitsOwner);   // factory for a class traits' owner
void* FUN_14250f330(void* out, void* nameSlot, Scaleform::UPInt a, int b);   // type name for a class-kind value (releases the name)
void* FUN_14250fc60(void* out, void* nameSlot, Scaleform::UPInt vt, Scaleform::UInt32 idx, int b);   // type name for a slot-kind value (releases the name)
void* FUN_142416720(const void* self);   // InstanceTraits::Function: its VM-side owner
void FUN_1424fef00(void* vm, void* callee, const void* thisVal, void* result, unsigned argc, const void* args, unsigned flag);
Scaleform::UPInt* FUN_1425ddd50(Scaleform::UPInt button, Scaleform::UPInt* out, int state);   // Button::CreateStateRenderContainer
Scaleform::UPInt FUN_14250dbc0(Scaleform::UPInt container);   // TreeContainer::GetSize
void FUN_14261cf50(Scaleform::UPInt container, Scaleform::UPInt pos, Scaleform::UPInt count);   // TreeContainer::Remove
unsigned char FUN_14261c690(Scaleform::UPInt container, Scaleform::UPInt pos, Scaleform::UPInt node);   // TreeContainer::Insert
Scaleform::UPInt FUN_1425f26c0(Scaleform::UPInt displayObject);   // DisplayObjectBase::GetRenderNode
void FUN_142581700(Scaleform::UPInt entry);   // ContextImpl::Entry::destroyHelper
char FUN_142522a60(Scaleform::UPInt owner, Scaleform::UPInt traits);   // owner-side check before the class traits are torn down
void FUN_1424ef7b0(Scaleform::UPInt hash);   // hash Clear (stride 0x18, refcounted member at +0x20)
void FUN_1424ef860(Scaleform::UPInt hash);   // hash Clear (stride 0x18, refcounted member at +0x20)
void FUN_1424ef5b0(Scaleform::UPInt hash);   // hash Clear
void FUN_1424ef500(Scaleform::UPInt hash);   // hash Clear (stride 0x20, refcounted member at +0x28)
void FUN_1424ef450(Scaleform::UPInt hash);   // hash Clear (stride 0x20, refcounted member at +0x28)
char* FUN_1424ff910(char* ret, Scaleform::GFx::AS3::VM* vm, const Scaleform::GFx::AS3::Multiname* mn, const Scaleform::GFx::AS3::Value* obj, Scaleform::GFx::AS3::Value* result, unsigned argc, const void* args);   // ExecutePropertyUnsafe
void FUN_142403310(Scaleform::UPInt obj, Scaleform::GFx::ASString* inout);   // XMLList-style toString
void FUN_14251fb90(void* tr, int op, Scaleform::UPInt arg);   // Tracer: record a rewritten opcode for a register
unsigned char* FUN_14250e2d0(Scaleform::UPInt slotRef, void* ret, void* vm, Scaleform::GFx::AS3::Value* out, const Scaleform::GFx::AS3::Value* thisObj, const void* vt, unsigned b);   // read the value behind a slot reference (vt: VTable*, tested as 64 bits)
void FUN_1424161e0(Scaleform::UPInt obj, void* out, Scaleform::UInt32 idx);   // next enumeration index of a string-like object
Scaleform::UPInt FUN_1425fc530(Scaleform::UPInt container, unsigned idx);   // DisplayObjContainer::GetChildAt
void FUN_1424d4c10(void* self, void* table, const void* nodeRef, Scaleform::UPInt hash);   // StickyVarNode hash: add an entry
Scaleform::UPInt FUN_142443d90(Scaleform::UPInt loader);   // Loader::GetLoaderInfo
void FUN_1425a3850(void* resource);   // Resource::AddRef
void* FUN_1425059f0(void* map, const Scaleform::UPInt* key);   // identity hash: value slot of key
void FUN_1424d54f0(void* dst, void* src);   // hash entry copy (key, value ref, count)
void FUN_1425224f0(void* arr, Scaleform::UPInt idx);   // ArrayBase::RemoveAt
void FUN_14261d270(void* node, int mode);   // TreeNode::SetEdgeAAMode
const void* FUN_1425f1d00(void* dispObj);   // DisplayObjectBase::GetCxform
void FUN_1425f4060(void* dispObj, const void* cx);   // DisplayObjectBase::SetCxform
void FUN_1425bc060(void* textField);   // TextField::SetDirtyFlag
void FUN_1425be970(void* textField, void* ret, const void* displayInfo);   // TextField::TransformToTextRectSpace
namespace Scaleform { namespace GFx { void ASCharacter_MatrixScaleAndRotate2x2(Render::Matrix2F& m, float sx, float sy, float radians); } }   // sfr_gfx_06, 0x1425f0dd0
double FUN_1425e3ee0();   // the "no value" double (NaN)
void FUN_1424f1e50(Scaleform::UPInt state, Scaleform::UPInt traits, int nullType);   // TR::State::ConvertOpTo
int FUN_1424eea80(Scaleform::UPInt tracer, Scaleform::UPInt traits);   // Tracer::CanBeNull
bool FUN_1424f8b00(void* tr, int op, void* state, const Scaleform::GFx::AS3::Traits* t, const Scaleform::GFx::AS3::Multiname* pmn, int ind);   // trace a get on a name
bool FUN_1424f92f0(void* tr, int op, const Scaleform::GFx::AS3::Traits* t, void* unused, const Scaleform::GFx::AS3::Multiname* pmn, int ind);   // trace a set on a name
bool FUN_1424f7540(void* tr, int op, void* state, void* pinfo, int ind);   // trace a call on a name
bool FUN_1424f7cc0(Scaleform::UPInt tracer, void* state, int idx, bool a, int b, bool c);   // trace find/getlex
void FUN_1424f9180(void* tr);   // Tracer: drop the code of the last pushed value
const char* FUN_14250cf20(void* state, char* ret, const void* t, const void* si, Scaleform::GFx::AS3::Value& result);
int FUN_14250c990(Scaleform::UPInt tracer, Scaleform::UPInt pos);   // Tracer: note the lookahead at pos
void FUN_14251f930(void* tr, int op);   // Tracer: emit opcode op
void FUN_14251fa10(void* tr, int op, Scaleform::UPInt arg1, Scaleform::UPInt arg2);   // Tracer: emit opcode op with two arguments
void FUN_1424d8ec0(void* mn, Scaleform::UPInt link, Scaleform::UPInt entry);   // Multiname::Multiname(VMAbcFile&, Abc::Multiname&)
void FUN_1424dee30(void* r);   // TR::ReadValueMnObject::~ReadValueMnObject (0x90 record)
void FUN_1424ded40(void* r);   // TR::ReadMnObject::~ReadMnObject (0x70 record)
void FUN_1424debc0(void* r);   // ReadArgsMnObject::~ReadArgsMnObject
void FUN_14251cc80(Scaleform::UPInt tracer);   // Tracer: close the block at a label
void FUN_142520e60(Scaleform::UPInt state, Scaleform::UPInt traits, int op);   // TR::State: unary typed op
void FUN_142520f30(Scaleform::UPInt state, Scaleform::UPInt traits, int op);   // TR::State: binary typed op
void FUN_142520d80(Scaleform::UPInt state, Scaleform::UPInt traits, int op, unsigned int idx);   // TR::State: typed op on a register
void FUN_1424f1ed0(Scaleform::UPInt state, unsigned int ind, Scaleform::UPInt traits, int nullType);   // TR::State::ConvertRegisterTo
void FUN_14251bdc0(Scaleform::UPInt vm, void* value);   // VM: flush a pending value
void* FUN_142581a40(void* entry, unsigned changeBits);   // ContextImpl::Entry::getWritableData
void FUN_142581430(void* entry);                         // ContextImpl::Entry::addToPropagateImpl
Scaleform::UPInt FUN_1425f26c0(void* displayObjectBase); // DisplayObjectBase::GetRenderNode
void FUN_1424d7850(void* err, int id, void* vm, const char* s);   // VM::Error::Error(id, vm, char*)
void FUN_1424e42c0(Scaleform::UPInt root, const Scaleform::GFx::AS3::Value* v, void* gfxValue);   // MovieRoot::ASValue2GFxValue
void FUN_142545310(Scaleform::UPInt entry, void* out);    // constant-pool string entry -> (chars, length)

namespace Scaleform { namespace GFx { namespace AS3 {
void FUN_142501e80(void* state, void* propRef, void* multiname, void* a, void* b);   // Tracer: resolve a multiname to a property reference
// Defined below under their recovered names (the callers used to spell them FUN_<va>, which never linked).
char* Sfr27SlotSetValueThis(const SlotInfo* si, char* ret, VM* vm, const Value* v, const Value* thisV, VTable* vt);
char* Sfr27SlotSetValueObj(const SlotInfo* si, char* ret, VM* vm, const Value* v, Object* obj);
char* Sfr27SetPropertyOfValue(char* ret, VM* vm, const Value* obj, const Multiname* mn, const Value* v);
void  Sfr31TraceNoteJump(UPInt tr, SPInt base, UPInt blk, SInt32 off, SInt32 arg);
void  Sfr31ValueToBool(Value* v);
void  Sfr31StoreSlotValue(UPInt vt, UPInt idx, const Value* v, int kind, const UPInt* name);
void  Sfr31ButtonSwitchStateIntl(UPInt self, int state);
char  Sfr31TracerCommonOp(UPInt tracer, unsigned char op, UPInt* pos, UPInt state);
void  Sfr31StateTraceOp(UPInt state, unsigned char op, UPInt* pos);
UPInt Sfr31ResolveClassTraits(UPInt vmAddr, UPInt link, UPInt entry);
void  FUN_142524af0(UPInt* a, const void* addr, UPInt n);
UPInt Sfr31FindClassTraitsByMn(UPInt vm, UPInt mn);
void  FUN_1425245c0(UPInt* a, UPInt n);
}}} // namespace Scaleform::GFx::AS3

namespace Scaleform { namespace GFx { namespace AS3 { namespace ClassTraits {

// @0x1425274f0
void Traits::SetInstanceTraits(Pickable<InstanceTraits::Traits> itr)
{
    // SDK SetIsInterface(itr->IsInterface()); our shared header only has the argument-less setter.
    Flags = (Flags & ~static_cast<SPInt>(AS3::Traits::IsInterfaceMask))
        | (-static_cast<SPInt>(itr->IsInterface()) & AS3::Traits::IsInterfaceMask);
    ITraits = itr;
}

}}}} // namespace Scaleform::GFx::AS3::ClassTraits

namespace Scaleform { namespace GFx { namespace AS3 {

// An Error built by the exe's constructors (VM::Error::Error is functional in sfr_as3_15, so it is not linkable from here).
struct Sfr31Err
{
    alignas(8) char Buf[sizeof(VM::Error)];
    Sfr31Err(VM::ErrorID id, VM& vm, const Value& a)               { FUN_1424d6f40(Buf, id, &vm, &a); }
    Sfr31Err(VM::ErrorID id, VM& vm, const Value& a, const Value& b) { FUN_1424d6cf0(Buf, id, &vm, &a, &b); }
    Sfr31Err(VM::ErrorID id, VM& vm, const char* a, const Value& b) { FUN_1424d79f0(Buf, id, &vm, a, &b); }
    ~Sfr31Err()                         { Get().~Error(); }
    VM::Error& Get()                    { return *reinterpret_cast<VM::Error*>(Buf); }
    operator const VM::Error&()         { return Get(); }
};


// MS2-FUNCTIONAL 0x14252a460: header inline Value::SetUInt32; the exe inlines Release (weak-ref free) where ours calls the out-of-line ReleaseWeakRef.
// Out-of-line copies of header inlines that the exe emits as COMDATs; taking the address forces ours (pinned below).
void (Value::* volatile sfr27KeepSetUInt32)(UInt32) = &Value::SetUInt32;

// @0x14252e560
void Value::Swap(Value& other)
{
    const UInt32 flags = other.Flags;
    const Extra bonus = other.Bonus;
    const VU val = other.value;
    other.Flags = Flags;
    other.Bonus = Bonus;
    other.value = value;
    Flags = flags;
    Bonus = bonus;
    value = val;
}

// @0x142532280
void Object::constructor(Value& result)
{
    result.Assign(&GetTraits().GetConstructor());
}

// @0x142540bb0
void Class::prototypeGet(Value& result)
{
    result.Assign(&GetPrototype());
}

// MS2-FUNCTIONAL 0x14252f6d0: delegates conversion to the recovered primitive/complex helper; the exe has an explicit tag switch.
// @0x14252f6d0
CheckResult Value::ToNumberValueInline()
{
    Number result;
    if (!Convert2NumberInline(result))
        return CheckResult(false);
    SetNumber(result);
    return CheckResult(true);
}

// MS2-FUNCTIONAL 0x14252f670: register allocation and branch layout differ (/O2 codegen); same calls as the exe.
// ToInt32 in place: Convert2Int32 (objects through their hintNone primitive) then SetSInt32, as in the exe.
// @0x14252f670
CheckResult Value::ToInt32Value()
{
    SInt32 result;
    if (!Convert2Int32(result))
        return false;
    SetSInt32(result);
    return true;
}

// MS2-FUNCTIONAL 0x14252fe80: register allocation and branch layout differ (/O2 codegen); same calls as the exe.
// ToUInt32 in place: Convert2UInt32 then SetUInt32, as in the exe.
// @0x14252fe80
CheckResult Value::ToUInt32Value()
{
    UInt32 result;
    if (!Convert2UInt32(result))
        return false;
    SetUInt32(result);
    return true;
}

// MS2-FUNCTIONAL 0x14252fe10: converts into an ASString and assigns it back; the exe routes allocation through the supplied StringManager.
// @0x14252fe10
CheckResult Value::ToStringValue(StringManager& stringManager)
{
    ASString string = stringManager.CreateString("", 0);
    CheckResult converted = Convert2String(string);
    if (converted)
        Assign(string);
    return converted;
}

// MS2-FUNCTIONAL 0x142527560: updates the pair and key-to-latest-slot chain; inlined refcount/hash paths differ.
// @0x142527560
void SlotContainerType::SetKey(AbsoluteIndex ind, const ASString& key)
{
    Pair& pair = VArray[static_cast<UPInt>(ind.Get())];
    ASStringNode* node = key.GetNode();
    if (pair.Key.GetPtr() == node)
        return;

    pair.Key = node;
    SetType::Iterator it = KVHashSet.Find(node);
    if (it.IsEnd())
    {
        pair.Prev = -1;
        KVHashSet.Add(node, static_cast<SPInt>(ind.Get()));
    }
    else
    {
        pair.Prev = it->Second;
        it->Second = static_cast<SPInt>(ind.Get());
    }
}

// MS2-FUNCTIONAL 0x1425276d0: updates the pair name, prior-name chain and name-to-slot map; Ptr/Hash helpers produce different temporary refcount code.
// @0x1425276d0
__declspec(noinline) void Slots::SetKey(AbsoluteIndex ind, const ASString& key)
{
    const UInt32 ownIndex = static_cast<UInt32>(ind.Get()) - static_cast<UInt32>(FirstOwnSlotNum);
    Pair& pair = VArray[ownIndex];
    if (pair.Key.GetPtr() == key.GetNode())
        return;

    pair.Key = key.GetNode();
    const UInt32* previous = Set.Get(pair.Key);
    if (previous)
    {
        pair.Prev = static_cast<SPInt>(*previous);
        Set.Set(pair.Key, static_cast<UInt32>(ind.Get()));
    }
    else
    {
        pair.Prev = -1;
        Set.Set(pair.Key, static_cast<UInt32>(ind.Get()));
    }
}

namespace TR {

// The Tracer reaches the VM and the abc file through a short pointer chain.
static inline UPInt TrRd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
static inline UPInt TrAbcLink(UPInt tracer) { return TrRd(TrRd(tracer, 0x20), 0x28); }
static inline UPInt TrVM(UPInt tracer) { return TrRd(TrAbcLink(tracer), 0x20); }
static inline UPInt TrFile(UPInt tracer) { return TrRd(TrAbcLink(tracer), 0x28); }
static inline InstanceTraits::Traits& TrITraits(UPInt tracer, UPInt vmOff)
{
    return *reinterpret_cast<InstanceTraits::Traits*>(TrRd(TrRd(TrVM(tracer), vmOff), 0xc0));
}

// The exe pushes tracer values without releasing the temporary (the tag is known to need no release).
struct TrScratch
{
    template <class A> explicit TrScratch(const A& a) { new (&buf0) Value(a); }
    template <class A, class B> TrScratch(A& a, const B& b) { new (&buf0) Value(a, b); }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&buf0); }
    UPInt buf0, buf1, buf2, buf3;
};

// Tracer number value: tag first, then the payload (the exe fills the tag before reading the pool).
struct TrNumScratch
{
    explicit TrNumScratch(Value::KindType k) { w0 = static_cast<UInt32>(k); w1 = 0; }
    void SetInt(SInt32 v) { i = v; }
    void SetUInt(UInt32 v) { i = static_cast<SInt32>(v); }
    void SetNumber(double v) { d = v; }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1;
    union { SInt32 i; double d; };
    UPInt w3;
};

// Tracer value with a traits pointer: the exe zeroes the second word before storing the tag.
struct TrTraitsScratch
{
    TrTraitsScratch()
    {
        w1 = 0;
        w0 = static_cast<UInt32>(Value::kInstanceTraits);
    }
    void SetTraits(InstanceTraits::Traits& tr) { w2 = reinterpret_cast<UPInt>(&tr); }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// @0x142528e20
void State::SetRegister(AbsoluteIndex ind, const Value& v)
{
    const UInt32 i = static_cast<UInt32>(ind.Get());
    Registers[i].Assign(v);
    RegChanged[i >> 3] |= static_cast<UInt8>(1 << (i & 7));
}

// @0x14253fde0
void State::SetLocal0()
{
    SetRegister(AbsoluteIndex(0), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253fe30
void State::SetLocal1()
{
    SetRegister(AbsoluteIndex(1), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253fe80
void State::SetLocal2()
{
    SetRegister(AbsoluteIndex(2), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253fed0
void State::SetLocal3()
{
    SetRegister(AbsoluteIndex(3), OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253ff20
void State::SetLocalN(UInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    Registers[ind].Assign(OpStack[OpStack.GetSize() - 1]);
    RegChanged[ind >> 3] |= static_cast<UInt8>(1 << (ind & 7));
    FUN_14251ccc0(this, 1);
}

// @0x14253f4a0
void State::PushScope()
{
    ScopeStack.PushBack(OpStack[OpStack.GetSize() - 1]);
    FUN_14251ccc0(this, 1);
}

// @0x14253f2f0
void State::PushByte(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(static_cast<char>(arg))); OpStack.PushBack(t.Get()); }
}

// @0x14253f640
void State::PushShort(SInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrScratch t(static_cast<SInt32>(arg)); OpStack.PushBack(t.Get()); }
}

// @0x14253f3b0
void State::PushInt(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kInt); t.SetInt(pool->ConstInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f770
void State::PushUInt(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kUInt); t.SetUInt(pool->ConstUInt[ind]); OpStack.PushBack(t.Get()); }
}

// @0x14253f340
void State::PushDouble(SInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Abc::ConstPool* pool = reinterpret_cast<const Abc::ConstPool*>(TrFile(reinterpret_cast<UPInt>(pTracer)) + 0x30);
    { TrNumScratch t(Value::kNumber); t.SetNumber(pool->GetDouble(ind)); OpStack.PushBack(t.Get()); }
}

// @0x1425395f0
void State::PushObject(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c1a0
void State::PushObject2(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x1f8)); OpStack.PushBack(t.Get()); }
}

// @0x14253c8b0
void State::PushFunction(UInt32 arg)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(arg));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x208)); OpStack.PushBack(t.Get()); }
}

// @0x14253a630
void State::PushBoolean2(UInt32 a, UInt32 b)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(a));
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(b));
    { TrTraitsScratch t; t.SetTraits(TrITraits(reinterpret_cast<UPInt>(pTracer), 0x210)); OpStack.PushBack(t.Get()); }
}

// @0x142538f20
void State::PushITraits(InstanceTraits::Traits* tr)
{
    { TrTraitsScratch t; t.SetTraits(*tr); OpStack.PushBack(t.Get()); }
}

// @0x14253bdf0
void State::KillRegister(UInt32 ind)
{
    FUN_14251fcd0(reinterpret_cast<UPInt>(pTracer), static_cast<UInt32>(ind));
    const Value& undef = Value::GetUndefined();
    Registers[ind].Assign(undef);
    const UInt32 sh = ind & 7;
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] | (1u << sh));
    RegChanged[ind >> 3] = static_cast<UInt8>(RegChanged[ind >> 3] & ~(1u << sh));
}


// ---- Tracer opcode handlers (free functions: `this` is the TR::State, ABI identical to the exe's member form) ----
struct StV
{
    explicit StV(void* st) : s(reinterpret_cast<UPInt>(st)) { }
    UPInt Tracer() const { return TrRd(s, 0); }
    Value* Ops() const { return reinterpret_cast<Value*>(TrRd(s, 0x38)); }
    UPInt NumOps() const { return TrRd(s, 0x40); }
    Value& Top() const { return Ops()[NumOps() - 1]; }
    Value& Below() const { return Ops()[NumOps() - 2]; }
    ArrayDH<Value>& OpStack() const { return *reinterpret_cast<ArrayDH<Value>*>(s + 0x38); }
    // The tracer's opcode array; its last entry is the opcode being specialized.
    UInt64& LastOp() const
    {
        UPInt* arr = reinterpret_cast<UPInt*>(TrRd(Tracer(), 0x28));
        return reinterpret_cast<UInt64*>(arr[0])[arr[1] - 1];
    }
    const UInt8* Code() const { return reinterpret_cast<const UInt8*>(TrRd(Tracer(), 0x50)); }
    UPInt s;
};

// The popped operand lives in raw storage: PopOpValue fills it in and the exe releases it at the end.
// Storage of a popped Value (filled by PopOpValue). The empty ctor keeps cl from treating it as a /GS buffer.
struct TrPopped
{
    TrPopped() {}
    Value& Get() { return *reinterpret_cast<Value*>(&w0); }
    UPInt w0, w1, w2, w3;
};

// Raw storage of a TR::ReadArgs (0x140 bytes), built and destroyed by the exe's own functions.
struct TrReadArgsRaw
{
    TrReadArgsRaw(VM* vm, void* st, UInt32 argc) { FUN_1424d9640(buf, vm, st, argc); }
    ~TrReadArgsRaw() { FUN_1424dea90(buf); }
    UInt8 buf[0x140];
};

// @0x14253af70
void Sfr27TraceIfTrueFalse(State* st, UInt64* pos, int op)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    if (FUN_142514000(tracer, &s.Top()))
        s.LastOp() = static_cast<UInt64>(op != 0x11) + 0x33;
    const int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    FUN_14251ccc0(st, 1);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), off, -1);
}

// @0x14253ad00
void Sfr27TraceIfCompare(State* st, UInt64* pos, UInt32 op)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    UInt64 newOp = op;
    if (FUN_142514c30(tracer, &s.Top()) && FUN_142514c30(tracer, &s.Below()))
    {
        switch (op)
        {
        case 0xc: newOp = 0x8a; break;
        case 0xd: newOp = 0x8b; break;
        case 0xe: newOp = 0x8c; break;
        case 0xf: newOp = 0x8d; break;
        case 0x13: case 0x19: newOp = 0x8e; break;
        case 0x14: case 0x1a: newOp = 0x9f; break;
        case 0x15: newOp = 0x9e; break;
        case 0x16: newOp = 0x9d; break;
        case 0x17: newOp = 0x9c; break;
        case 0x18: newOp = 0x8f; break;
        }
        s.LastOp() = newOp;
    }
    else if (FUN_142514470(tracer, &s.Top()) && FUN_142514470(tracer, &s.Below()))
    {
        switch (op)
        {
        case 0xc: newOp = 200; break;
        case 0xd: newOp = 0xc9; break;
        case 0xe: newOp = 0xca; break;
        case 0xf: newOp = 0xcb; break;
        case 0x13: case 0x19: newOp = 0xcc; break;
        case 0x14: case 0x1a: newOp = 0xbf; break;
        case 0x15: newOp = 0xbe; break;
        case 0x16: newOp = 0xbd; break;
        case 0x17: newOp = 0xbc; break;
        case 0x18: newOp = 0xcd; break;
        }
        s.LastOp() = newOp;
    }
    const int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), off, -1);
}

// @0x14253bd80
void Sfr27TraceJump(State* st, UInt64* pos)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    const int off = Abc::ReadS24<UInt8>(s.Code(), *pos);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), off, -1);
    FUN_1424e6aa0(tracer, st, *pos, 1, 1);
}

// @0x142540750
void Sfr27TraceLookupSwitch(State* st, UInt64* pos)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    FUN_14251ccc0(st, 1);
    const UPInt base = TrRd(tracer, 0x38);
    int off = Abc::ReadS24<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
    Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), static_cast<int>(base - *pos) + off, 1);
    const int caseCount = Abc::ReadU30<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
    FUN_14251fcd0(tracer, static_cast<SPInt>(caseCount));
    for (int i = 0; i <= caseCount; ++i)
    {
        off = Abc::ReadS24<UInt8>(reinterpret_cast<const UInt8*>(TrRd(tracer, 0x50)), *pos);
        Sfr31TraceNoteJump(tracer, *pos, reinterpret_cast<UPInt>(st), static_cast<int>(base - *pos) + off, i + 3);
    }
    FUN_1424e6aa0(tracer, st, *pos, 1, 1);
}

// @0x14253bb30
void Sfr27TraceTopBoolean(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), static_cast<UInt32>(arg));
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x210));
    s.Top().Assign(t.Get());
}

// @0x14253f260
void Sfr27TraceCheckNumericOp(State* st)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    void* tr = FUN_14250fe80(st, &s.Top());
    const UPInt vm = TrVM(tracer);
    if (tr != reinterpret_cast<void*>(TrRd(TrRd(vm, 0x210), 0xc0)) &&
        tr != reinterpret_cast<void*>(TrRd(vm, 0x278)) && tr != reinterpret_cast<void*>(TrRd(vm, 0x270)))
    {
        if (!FUN_142514510(tracer, tr))
        {
            FUN_14251ccc0(st, 1);
            return;
        }
    }
    s.LastOp() = 0x6b;
    FUN_14251ccc0(st, 1);
}

// @0x142538280
void Sfr27TraceDup2Check(State* st)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    void* tr = FUN_14250fe80(st, &s.Top());
    const UPInt vm = TrVM(tracer);
    if (tr == reinterpret_cast<void*>(TrRd(TrRd(vm, 0x210), 0xc0)) ||
        tr == reinterpret_cast<void*>(TrRd(vm, 0x278)) || tr == reinterpret_cast<void*>(TrRd(vm, 0x270)) ||
        FUN_142514510(tracer, tr))
        s.LastOp() = 0x69;
    s.OpStack().PushBack(Value::GetUndefined());
    s.Top().Assign(s.Below());
}

// Two operands popped, one value of a builtin type pushed.
// @0x14253ab60
void Sfr27TracePop2PushInt(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x220));
    s.OpStack().PushBack(t.Get());
}

// @0x14253d3d0
void Sfr27TracePop2PushObject(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    FUN_14251ccc0(st, 1);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

// @0x14253c030
void Sfr27TraceNewArray(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, argc);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x238));
    s.OpStack().PushBack(t.Get());
}

// @0x14253cd00
void Sfr27TraceNewObject(State* st, UInt32 propCount)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), propCount);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, propCount * 2);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
}

// The first operand popped and dropped after noting a register/operand read.
// @0x142532f20
void Sfr27TracePopNote(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), arg);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    popped.Get().~Value();
}

// @0x1425379f0
void Sfr27TraceConvertTopBoolean(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        Sfr31ValueToBool(&top);
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x210));
    top.Assign(t.Get());
}

// @0x142537ab0
void Sfr27TraceConvertTopNumber(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        top.ToNumberValueInline();
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x218));
    top.Assign(t.Get());
}

// @0x142537b70
void Sfr27TraceConvertTopInt(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        SInt32 result;
        CheckResult ok(false);
        if (*FUN_1424f0d30(&top, &ok, &result))
            top.SetSInt32(result);
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x220));
    top.Assign(t.Get());
}

// @0x142537e00
void Sfr27TraceConvertTopUInt(State* st)
{
    StV s(st);
    Value& top = s.Top();
    const UInt32 k = static_cast<UInt32>(top.GetKind());
    if (k < 5 || k == 10)
    {
        UInt32 result;
        CheckResult ok(false);
        if (*FUN_1424f1a30(&top, &ok, &result))
            top.SetUInt32(result);
        return;
    }
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x228));
    top.Assign(t.Get());
}


#define SFR27_TOP_OP(Name, Off) \
    void State::Name() \
    { \
        Value tv(TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
        OpStack[OpStack.GetSize() - 1].Assign(tv); \
    }
#define SFR27_POP2_OP(Name, Off) \
    void State::Name() \
    { \
        TrPopped popped; \
        FUN_14251cd30(this, &popped.Get()); \
        Value tv(TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
        OpStack[OpStack.GetSize() - 1].Assign(tv); \
        popped.Get().~Value(); \
    }
#define SFR27_REG_OP(Name, Off) \
    void State::Name(UInt32 ind) \
    { \
        Value tv(TrITraits(reinterpret_cast<UPInt>(pTracer), Off), Value::NotNull); \
        Registers[ind].Assign(tv); \
    }

// dxns / dxnslate: the method must set the SETS_DXNS flag (and XML support must be enabled).
static inline void TraceCheckSetsDxns(State* st, const char* disabledName, UInt32 arg, bool pop)
{
    const UPInt tracer = TrRd(reinterpret_cast<UPInt>(st), 0);
    UPInt link = TrAbcLink(tracer);
    const char* what;
    if (*reinterpret_cast<const char*>(TrRd(TrRd(link, 0x20), 0x40) + 0x20) == 0)
        what = disabledName;
    else
    {
        if (pop)
            FUN_14251ccc0(st, 1);
        else
            FUN_14251fcd0(tracer, arg);
        link = TrAbcLink(tracer);
        const UPInt file = TrRd(link, 0x28);
        const int methodIndex = *reinterpret_cast<const int*>(TrRd(tracer, 0x20) + 0x30);
        const UPInt method = TrRd(TrRd(file, 0x170), static_cast<SPInt>(methodIndex) * 8);
        const int bodyIndex = *reinterpret_cast<const int*>(method + 0x18);
        const UPInt body = TrRd(TrRd(file, 0xf8), static_cast<SPInt>(bodyIndex) * 8);
        if (*reinterpret_cast<const UInt8*>(body) & 0x40)
            return;
        what = "does not have the SETS_DXNS flag set";
    }
    VM& vm = *reinterpret_cast<VM*>(TrRd(link, 0x20));
    vm.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), vm, what));
}

// @0x142532670
SFR27_TOP_OP(TopNumber, 0x218)
// @0x142532710
SFR27_TOP_OP(TopInt, 0x220)
// @0x1425327b0
SFR27_TOP_OP(TopString, 0x230)
// @0x142532850
SFR27_POP2_OP(Pop2Boolean, 0x210)
// @0x142532930
SFR27_POP2_OP(Pop2Number, 0x218)
// @0x142532a10
SFR27_POP2_OP(Pop2Int, 0x220)
// @0x142532af0
SFR27_POP2_OP(Pop2UInt, 0x228)
// @0x142537c50
SFR27_REG_OP(RegNumber, 0x218)
// @0x142537ce0
SFR27_REG_OP(RegInt, 0x220)
// @0x142537d70
SFR27_REG_OP(RegUInt, 0x228)

// @0x1425383d0
void Sfr27TraceDxns(State* st, UInt32 arg) { TraceCheckSetsDxns(st, "dxns", arg, false); }
// @0x142538490
void Sfr27TraceDxnsLate(State* st) { TraceCheckSetsDxns(st, "dxnslate", 0, true); }

} // namespace TR

}}} // namespace Scaleform::GFx::AS3


namespace Scaleform { namespace GFx { namespace AS3 {

// @0x14252ec90
void VM::ThrowArgumentError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ArgumentErrorCI); }
// @0x14252eca0
void VM::ThrowError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ErrorCI); }
// @0x14252efc0
void VM::ThrowEvalError(const Error& e) { FUN_14252ecb0(this, &e, &fl::EvalErrorCI); }
// @0x14252f1a0
void VM::ThrowRangeError(const Error& e) { FUN_14252ecb0(this, &e, &fl::RangeErrorCI); }
// @0x14252f1b0
void VM::ThrowReferenceError(const Error& e) { FUN_14252ecb0(this, &e, &fl::ReferenceErrorCI); }
// @0x14252f1e0
void VM::ThrowTypeError(const Error& e) { FUN_14252ecb0(this, &e, &fl::TypeErrorCI); }
// @0x14252f1f0
void VM::ThrowURIError(const Error& e) { FUN_14252ecb0(this, &e, &fl::URIErrorCI); }
// @0x14252f210
void VM::ThrowVerifyError(const Error& e) { FUN_14252ecb0(this, &e, &fl::VerifyErrorCI); }

// ---- Small vftable-slot functions of the exe's .rdata (data_rdata_sf_b references them by FUN_<va>) ----

// Sets the "dirty" flag of the movie behind the object's owner.
// @0x1425262d0
void FUN_1425262d0(char* self) { *(*reinterpret_cast<char**>(*reinterpret_cast<char**>(self + 0x40) + 0x20) + 0xb0) = 1; }
// Hands a GFx::Value to MovieRoot::GFxValue2ASValue with the object's own Value slot as the output.
// @0x142527390
void FUN_142527390(char* self, const void* gfxValue) { FUN_1425048d0(reinterpret_cast<UPInt>(self), gfxValue, reinterpret_cast<Value*>(self + 0x58)); }
// @0x1425282c0
void FUN_1425282c0(void*) {}
// Raises or lowers a nesting counter of the movie behind the object's owner.
// @0x14252e530
void FUN_14252e530(char* self, bool enter)
{
    UInt8& n = *reinterpret_cast<UInt8*>(*reinterpret_cast<char**>(*reinterpret_cast<char**>(self + 0x40) + 0x20) + 0xb1);
    n = enter ? UInt8(n + 1) : UInt8(n - 1);
}

// Interface casts of a multiply-inherited class (null stays null) with their 0x30 / 0x40 adjustor thunks.
// @0x14252f220
void* FUN_14252f220(char* p) { return p ? p + 0x40 : nullptr; }
// @0x14252f230
void* FUN_14252f230(char* p) { return FUN_14252f220(p - 0x30); }
// @0x14252f23c
void* FUN_14252f23c(char* p) { return FUN_14252f220(p - 0x40); }
// @0x14252f290
UPInt FUN_14252f290(void*) { return 0; }
// @0x14252f294
UPInt FUN_14252f294(char* p) { return FUN_14252f290(p - 0x30); }
// @0x14252f2a0
UPInt FUN_14252f2a0(char* p) { return FUN_14252f290(p - 0x40); }
// @0x14252f2b0
UPInt FUN_14252f2b0(void*) { return 0; }
// @0x14252f2b4
UPInt FUN_14252f2b4(char* p) { return FUN_14252f2b0(p - 0x30); }
// @0x14252f2c0
UPInt FUN_14252f2c0(char* p) { return FUN_14252f2b0(p - 0x40); }
// @0x14252f300
UPInt FUN_14252f300(void*) { return 0; }
// @0x14252f304
UPInt FUN_14252f304(char* p) { return FUN_14252f300(p - 0x30); }
// @0x14252f310
UPInt FUN_14252f310(char* p) { return FUN_14252f300(p - 0x40); }
// @0x14252f320
void* FUN_14252f320(char* p) { return p ? p + 0x30 : nullptr; }
// @0x14252f330
void* FUN_14252f330(char* p) { return FUN_14252f320(p - 0x30); }
// @0x14252f33c
void* FUN_14252f33c(char* p) { return FUN_14252f320(p - 0x40); }
// @0x14252f3b0
void* FUN_14252f3b0(char* p) { return p ? p + 0x30 : nullptr; }
// @0x14252f3c0
void* FUN_14252f3c0(char* p) { return FUN_14252f3b0(p - 0x30); }
// @0x14252f3cc
void* FUN_14252f3cc(char* p) { return FUN_14252f3b0(p - 0x40); }
// @0x14252f3e0
UPInt FUN_14252f3e0(void*) { return 0; }
// @0x14252f3e4
UPInt FUN_14252f3e4(char* p) { return FUN_14252f3e0(p - 0x30); }
// @0x14252f3f0
UPInt FUN_14252f3f0(char* p) { return FUN_14252f3e0(p - 0x40); }
// @0x14252f440
UPInt FUN_14252f440(void*) { return 0; }
// @0x14252f444
UPInt FUN_14252f444(char* p) { return FUN_14252f440(p - 0x30); }
// @0x14252f450
UPInt FUN_14252f450(char* p) { return FUN_14252f440(p - 0x40); }
// @0x14252f460
UPInt FUN_14252f460(void*) { return 0; }
// @0x14252f464
UPInt FUN_14252f464(char* p) { return FUN_14252f460(p - 0x30); }
// @0x14252f470
UPInt FUN_14252f470(char* p) { return FUN_14252f460(p - 0x40); }
// @0x14252f4c0
void* FUN_14252f4c0(char* p) { return p ? p + 0x40 : nullptr; }
// @0x14252f4d0
void* FUN_14252f4d0(char* p) { return FUN_14252f4c0(p - 0x30); }
// @0x14252f4dc
void* FUN_14252f4dc(char* p) { return FUN_14252f4c0(p - 0x40); }

// @0x142530fb0
void FUN_142530fb0(void*) {}
// @0x1425310d0
bool FUN_1425310d0(void*) { return false; }
// @0x142531250
void FUN_142531250(void*) {}

// ---- Interpreter opcode handlers (free functions; the VM is the first argument as in the exe) ----

// Raw storage of a (TR::)ReadArgs: constructed and destroyed by the exe's own out-of-line functions.
struct RA
{
    RA(VM* vm, UInt32 argc) { FUN_1424d9530(buf, vm, argc); }
    ~RA() { FUN_1424de9e0(buf); }
    ValueStack& Stk() { return **reinterpret_cast<ValueStack**>(buf + 8); }
    UInt32 ArgNum() const { return *reinterpret_cast<const UInt32*>(buf + 0x10); }
    const Value* Argv() { return ArgNum() > 8 ? *reinterpret_cast<const Value**>(buf + 0x118) : reinterpret_cast<const Value*>(buf + 0x18); }
    UInt8 buf[0x140];
};

// null or undefined where an object is needed: TypeError 1009 / 1010
static inline void ExecRequireObject(VM& vm, const Value& v)
{
    const UInt32 k = static_cast<UInt32>(v.GetKind());
    if (k == 0 || (k - 0xc < 4 && v.GetGASRefCountBase() == NULL))
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(k - 0xc < 4 ? 0x3f1 : 0x3f2), vm));
}

// VM::Convert check used by astype/coerce handlers (returns whether value can be converted to the traits).

// The class operand popped: a value not convertible to its type becomes null.
// MS2-FUNCTIONAL 0x142533300: same class test and error paths; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x142533300
void Sfr27ExecAsType(VM* vm)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value* below = stk.GetTopPtr() - 1;
    Value y;
    y.Pick(stk);
    if (y.GetKind() == Value::kClass)
    {
        if (!FUN_1425146d0(vm, below, &y.AsClass().GetTraits()))
            below->SetNull();
    }
    else
    {
        const UInt32 k = static_cast<UInt32>(y.GetKind());
        if (k != 0 && (k - 0xc >= 4 || y.GetGASRefCountBase() != NULL))
            vm->ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x411), *vm));
        else
            ExecRequireObject(*vm, y);
    }
}

// call: function, receiver and argc arguments popped; the result is dropped.
// MS2-FUNCTIONAL 0x142533680: same receiver/function pops and ExecuteInternalUnsafe call; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x142533680
void Sfr27ExecCallVoid(VM* vm, UInt32 argc)
{
    RA args(vm, argc);
    Value receiver;
    receiver.Pick(args.Stk());
    ExecRequireObject(*vm, receiver);
    Value func;
    func.Pick(args.Stk());
    if (vm->IsException())
        return;
    Value result(Value::GetUndefined());
    vm->ExecuteInternalUnsafe(func, receiver, result, argc, args.Argv(), true);
}

// callmethod: receiver and argc arguments popped; the method comes from the receiver's method table.
// MS2-FUNCTIONAL 0x142533980: same method-table lookup and two ExecuteInternalUnsafe calls; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x142533980
void Sfr27ExecCallMethod(VM* vm, UInt32 methodIndex, UInt32 argc)
{
    RA args(vm, argc);
    Value receiver;
    receiver.Pick(args.Stk());
    ExecRequireObject(*vm, receiver);
    if (vm->IsException())
        return;
    const UPInt traits = reinterpret_cast<UPInt>(&FUN_14250ffc0(*vm, receiver));
    const UPInt vt = FUN_14250fa80(traits);
    Value func;
    vm->ExecuteInternalUnsafe(*reinterpret_cast<Value*>(*reinterpret_cast<UPInt*>(vt + 8) + methodIndex * 0x20ULL),
                              receiver, func, 0, NULL, false);
    if (!vm->IsException())
    {
        Value result(Value::GetUndefined());
        vm->ExecuteInternalUnsafe(func, receiver, result, argc, args.Argv(), true);
    }
}


static inline UPInt VmRd(VM* vm, UPInt off) { return *reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(vm) + off); }

// Push a copy of v on the VM's operand stack (VM +0x50 is the top-of-stack pointer).
static inline Value* ExecPushCopy(VM* vm, const Value& v)
{
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    ++cur;
    return new (cur) Value(v);
}

// getscopeobject: the scope entry of the frame at index.
// @0x142539af0
void Sfr27ExecGetScopeObject(VM* vm, void* frame, UInt32 index)
{
    UPInt* scopes = *reinterpret_cast<UPInt**>(reinterpret_cast<UPInt>(frame) + 0x38);
    if (scopes == NULL || scopes[1] <= index)
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x7d6), *vm));
        return;
    }
    ExecPushCopy(vm, reinterpret_cast<Value*>(scopes[0])[index]);
}

// getouterscope-style read of the VM scope stack at the frame's scope base plus index.
// @0x142539e20
void Sfr27ExecGetScopeStack(VM* vm, void* frame, UInt32 index)
{
    const UPInt pos = static_cast<UPInt>(index) + *reinterpret_cast<const UPInt*>(reinterpret_cast<UPInt>(frame) + 8);
    if (VmRd(vm, 0x168) <= pos)
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x7d6), *vm));
        return;
    }
    Value* pushed = ExecPushCopy(vm, reinterpret_cast<Value*>(VmRd(vm, 0x160))[pos]);
    *reinterpret_cast<UInt32*>(pushed) &= 0xfffffeff;
}


// The innermost call frame of the VM (the paged call stack: VM +0x78 frames, 64 per page of 0xa8-byte frames), or 0.
static inline UPInt ExecTopFrame(VM* vm)
{
    const UPInt count = VmRd(vm, 0x78);
    if (count == 0)
        return 0;
    const UPInt i = count - 1;
    return (i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8);
}

// The object the frame runs in: the first scope object, else the frame's this when that is an object.
static inline Object* ExecFrameObject(VM* vm)
{
    const UPInt frame = ExecTopFrame(vm);
    if (frame == 0)
        return NULL;
    const UPInt* scopes = *reinterpret_cast<const UPInt* const*>(frame + 0x38);
    if (scopes != NULL && scopes[1] != 0)
        return *reinterpret_cast<Object* const*>(scopes[0] + 0x10);
    const Value* self = *reinterpret_cast<Value* const*>(*reinterpret_cast<const UPInt*>(frame + 0x18) + 8);
    if (static_cast<UInt32>(self->GetKind()) - 0xc < 4)
        return reinterpret_cast<Object*>(self->GetGASRefCountBase());
    return NULL;
}

static inline const SlotInfo& ExecSlotOf(Object* obj, SPInt slot, bool relativeToOwn)
{
    Traits& tr = obj->GetTraits();
    SPInt ind = slot - 1;
    if (relativeToOwn)
        ind += tr.FirstOwnSlotInd.Get();
    return tr.GetSlotInfo(AbsoluteIndex(ind));
}

// getglobalslot: pushes undefined, then loads the global object's slot into it.
// MS2-FUNCTIONAL 0x142539490: same push of undefined and slot read; the exe inlines the Value copy (AddRef) and the global-object lookup where ours calls out-of-line helpers (callee count 5 vs 3).
// @0x142539490
void Sfr27ExecGetGlobalSlot(VM* vm, UInt32 slot)
{
    Value* top = ExecPushCopy(vm, Value::GetUndefined());
    Object* obj = ExecFrameObject(vm);
    CheckResult ok(false);
    FUN_14250e770(&ExecSlotOf(obj, slot, true), &ok, top, obj);
}

// getslot: the object on top of the stack is replaced by the value of its slot.
// MS2-FUNCTIONAL 0x142538f50: same slot read through the shared getter; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x142538f50
void Sfr27ExecGetSlot(VM* vm, SPInt slot)
{
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    ExecRequireObject(*vm, *top);
    if (vm->IsException())
        return;
    Value saved(*top, PickValue);
    Object* obj = reinterpret_cast<Object*>(saved.GetGASRefCountBase());
    CheckResult ok(false);
    FUN_14250e770(&ExecSlotOf(obj, slot, false), &ok, top, obj);
}

// setglobalslot: the value on top of the stack is stored into the global object's slot and popped.
// MS2-FUNCTIONAL 0x14253fc90: same slot write into the global object; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x14253fc90
void Sfr27ExecSetGlobalSlot(VM* vm, UInt32 slot)
{
    Object* obj = ExecFrameObject(vm);
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    CheckResult ok(false);
    Sfr27SlotSetValueObj(&ExecSlotOf(obj, slot, true), reinterpret_cast<char*>(&ok), vm, top, obj);
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    cur->~Value();
    --cur;
}

// getslot for objects whose slots follow the traits' first own slot.
// MS2-FUNCTIONAL 0x14253a2d0: same slot read through the shared getter; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x14253a2d0
void Sfr27ExecGetOwnSlot(VM* vm, UInt32 slot)
{
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    ExecRequireObject(*vm, *top);
    if (vm->IsException())
        return;
    Value saved(*top, PickValue);
    Object* obj = reinterpret_cast<Object*>(saved.GetGASRefCountBase());
    CheckResult ok(false);
    FUN_14250e770(&ExecSlotOf(obj, slot, true), &ok, top, obj);
}

// setslot: value and object popped, the object's slot receives the value.
// MS2-FUNCTIONAL 0x14253faa0: same slot write through the shared setter; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x14253faa0
void Sfr27ExecSetSlot(VM* vm, SPInt slot)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value value;
    value.Pick(stk);
    Value self;
    self.Pick(stk);
    ExecRequireObject(*vm, self);
    if (vm->IsException())
        return;
    Object* obj = reinterpret_cast<Object*>(self.GetGASRefCountBase());
    CheckResult ok(false);
    Sfr27SlotSetValueObj(&ExecSlotOf(obj, slot, false), reinterpret_cast<char*>(&ok), &obj->GetVM(), &value, obj);
}


// ---- SlotInfo::SetSlotValue (two entry points: with the receiver's Value and VTable, or with the Object) ----

// The out-of-line helpers write an ASString into raw storage they initialize themselves.
struct RawASString
{
    ASString& Get() { return *reinterpret_cast<ASString*>(&node); }
    ~RawASString() { Get().~ASString(); }
    UPInt node;
};

// The value stored through a bound slot: one case per binding kind (the data lives at obj + ValueInd, or in the
// global object's value array for BT_ValueArray). Returns false for unbound or read-only kinds.
static bool SlotStoreBound(const SlotInfo& si, Object* obj, const Value& v)
{
    const UPInt base = reinterpret_cast<UPInt>(obj);
    const SInt32 ind = si.ValueInd;
    // the payload words of the (already coerced) value
    const UPInt* raw = reinterpret_cast<const UPInt*>(&v);
    switch (si.BindType)
    {
    case SlotInfo::BT_ValueArray:
        reinterpret_cast<Value*>(*reinterpret_cast<UPInt*>(base + 0xa8))[ind].Assign(v);
        return true;
    case SlotInfo::BT_Value:
        reinterpret_cast<Value*>(base + ind)->Assign(v);
        return true;
    case SlotInfo::BT_ObjectAS:
        reinterpret_cast<STPtr*>(base + ind)->SetValue(v);
        return true;
    case SlotInfo::BT_ObjectCpp:
    {
        UPInt* slot = reinterpret_cast<UPInt*>(base + ind);
        const UPInt np = raw[2];
        if (np != *slot)
        {
            const UPInt old = *slot;
            if (old != 0)
            {
                if ((old & 1) == 0)
                {
                    UInt32* rc = reinterpret_cast<UInt32*>(old + 0x10);
                    if ((*rc & 0x3fffff) != 0)
                    {
                        --*rc;
                        FUN_1423dfa20(reinterpret_cast<void*>(old));
                    }
                }
                else
                    *slot = old - 1;
            }
            if (np != 0)
            {
                UInt32* rc = reinterpret_cast<UInt32*>(np + 0x10);
                *rc = (*rc + 1) & 0x8fbfffff;
            }
            *slot = np;
        }
        return true;
    }
    case SlotInfo::BT_Boolean:
        *reinterpret_cast<UInt8*>(base + ind) = static_cast<UInt8>(raw[2]);
        return true;
    case SlotInfo::BT_Int:
    case SlotInfo::BT_UInt:
        *reinterpret_cast<UInt32*>(base + ind) = static_cast<UInt32>(raw[2]);
        return true;
    case SlotInfo::BT_Number:
        *reinterpret_cast<UPInt*>(base + ind) = raw[2];
        return true;
    case SlotInfo::BT_String:
    {
        ASStringNode** slot = reinterpret_cast<ASStringNode**>(base + ind);
        ASStringNode* old = *slot;
        ASStringNode* ns = reinterpret_cast<ASStringNode*>(raw[2]);
        if (old != NULL)
            old->Release();
        *slot = ns;
        if (ns != NULL)
            ns->AddRef();
        return true;
    }
    }
    return false;
}

// The bound class's traits, coerce the value to the slot's declared type (unless it is a class).
// Returns false (after throwing) when the type is unknown or the value does not fit.
static bool SlotCoerceForStore(const SlotInfo* si, VM* vm, const Value& v, Value& coerced)
{
    if (v.GetKind() != Value::kClass && si->BindType <= 10)
    {
        ClassTraits::Traits* ct = FUN_1425085b0(si, vm);
        if (ct == NULL)
        {
            RawASString typeName;
            FUN_142508720(si, &typeName.Get(), vm);
            Value tv(typeName.Get());
            vm->ThrowVerifyError(Sfr31Err(static_cast<VM::ErrorID>(0x3f6), *vm, tv));
            return false;
        }
        if (!ct->Coerce(v, coerced))
        {
            RawASString typeName;
            FUN_142508720(si, &typeName.Get(), vm);
            Value tv(typeName.Get());
            vm->ThrowTypeError(Sfr31Err(static_cast<VM::ErrorID>(0x40a), *vm, v, tv));
            return false;
        }
        return true;
    }
    coerced.Assign(v);
    return true;
}

// Store v into slot si of the object held by thisV (setters run with thisV as receiver).
// @0x142529030
char* Sfr27SlotSetValueThis(const SlotInfo* si, char* ret, VM* vm, const Value* v, const Value* thisV, VTable* vt)
{
    if (si->ReadOnly && static_cast<int>(VmRd(vm, 0x30)) < 1)
    {
        vm->ThrowReferenceError(Sfr31Err(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, *thisV));
        *ret = 0;
        return ret;
    }
    Value coerced;
    if (!SlotCoerceForStore(si, vm, *v, coerced))
    {
        *ret = 0;
        return ret;
    }
    Object* obj = reinterpret_cast<Object*>(thisV->GetGASRefCountBase());
    switch (si->BindType)
    {
    case SlotInfo::BT_ValueArray: case SlotInfo::BT_Value: case SlotInfo::BT_ObjectAS: case SlotInfo::BT_ObjectCpp:
    case SlotInfo::BT_Boolean: case SlotInfo::BT_Int: case SlotInfo::BT_UInt: case SlotInfo::BT_Number:
    case SlotInfo::BT_String:
        *ret = SlotStoreBound(*si, obj, coerced);
        break;
    case 10: case SlotInfo::BT_Get:
        vm->ThrowReferenceError(Sfr31Err(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData, *thisV));
        *ret = 0;
        break;
    case SlotInfo::BT_Code:
    {
        const UInt32 k = static_cast<UInt32>(thisV->GetKind());
        const bool primitive = k < 5 || k == 10;
        vm->ThrowReferenceError(Sfr31Err(static_cast<VM::ErrorID>(primitive ? 0x420 : 0x40d), *vm, si->Name->pData, *thisV));
        *ret = 0;
        break;
    }
    case SlotInfo::BT_Set: case SlotInfo::BT_GetSet:
    {
        if (vt == NULL)
            vt = reinterpret_cast<VTable*>(FUN_14250fa80(reinterpret_cast<UPInt>(&FUN_14250ffc0(*vm, *thisV))));
        Value setter = vt->GetValue(AbsoluteIndex(si->ValueInd + 1));
        const UInt32 sk = static_cast<UInt32>(setter.GetKind());
        if (sk < 0xc && sk - 5 > 2)
        {
            vm->ThrowTypeError(Sfr31Err(static_cast<VM::ErrorID>(0x3ee), *vm, setter));
            *ret = 0;
        }
        else
        {
            Value result(Value::GetUndefined());
            vm->ExecuteInternalUnsafe(setter, *thisV, result, 1, &coerced, false);
            *ret = vm->IsException() ? 0 : 1;
        }
        break;
    }
    default:
        *ret = 0;
        break;
    }
    return ret;
}

// The same for an Object receiver; the error texts name the object's traits.
// @0x142529720
char* Sfr27SlotSetValueObj(const SlotInfo* si, char* ret, VM* vm, const Value* v, Object* obj)
{
    if (si->ReadOnly && static_cast<int>(VmRd(vm, 0x30)) < 1)
    {
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData,
                                          obj->GetTraits().GetName().ToCStr()));
        *ret = 0;
        return ret;
    }
    Value coerced;
    if (!SlotCoerceForStore(si, vm, *v, coerced))
    {
        *ret = 0;
        return ret;
    }
    switch (si->BindType)
    {
    case SlotInfo::BT_ValueArray: case SlotInfo::BT_Value: case SlotInfo::BT_ObjectAS: case SlotInfo::BT_ObjectCpp:
    case SlotInfo::BT_Boolean: case SlotInfo::BT_Int: case SlotInfo::BT_UInt: case SlotInfo::BT_Number:
    case SlotInfo::BT_String:
        *ret = SlotStoreBound(*si, obj, coerced);
        break;
    case 10: case SlotInfo::BT_Get:
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x432), *vm, si->Name->pData,
                                          obj->GetTraits().GetName().ToCStr()));
        *ret = 1;
        break;
    case SlotInfo::BT_Code:
        vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x40d), *vm, si->Name->pData,
                                          obj->GetTraits().GetName().ToCStr()));
        *ret = 0;
        break;
    case SlotInfo::BT_Set: case SlotInfo::BT_GetSet:
    {
        VTable* vt = reinterpret_cast<VTable*>(FUN_14250fa80(reinterpret_cast<UPInt>(&obj->GetTraits())));
        Value setter = vt->GetValue(AbsoluteIndex(si->ValueInd + 1));
        const UInt32 sk = static_cast<UInt32>(setter.GetKind());
        if (sk < 0xc && sk - 5 > 2)
        {
            vm->ThrowTypeError(Sfr31Err(static_cast<VM::ErrorID>(0x3ee), *vm, setter));
            *ret = 0;
        }
        else
        {
            Value result(Value::GetUndefined());
            Value self(obj);
            vm->ExecuteInternalUnsafe(setter, self, result, 1, &coerced, false);
            *ret = vm->IsException() ? 0 : 1;
        }
        break;
    }
    default:
        *ret = 0;
        break;
    }
    return ret;
}


// throw: the exception object is taken off the stack, then the frame's handler table is searched.
// @0x142540850
int Sfr27ExecThrow(VM* vm, UInt64* pc, CallFrame* frame)
{
    vm->ExceptionObj.Pick(*reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48));
    const UPInt* code = reinterpret_cast<const UPInt*>(FUN_142508330(frame));
    return FUN_142519a00(vm, (reinterpret_cast<UPInt>(pc) - *code) >> 3, frame);
}

// typeof: the value on top of the stack is replaced by the name of its type.
// MS2-FUNCTIONAL 0x142540910: same kind switch and string-manager index; register allocation and Value temporaries differ from the exe (frame differs, same helper calls).
// @0x142540910
void Sfr27ExecTypeOf(VM* vm)
{
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    SPInt idx;
    switch (static_cast<UInt32>(top->GetKind()))
    {
    case 0: idx = 1; break;
    case 1: idx = 6; break;
    case 2: case 3: case 4: idx = 7; break;
    case 5: case 7: case 0xe: case 0xf: case 0x10: case 0x11: idx = 9; break;
    case 10:
        idx = top->GetGASRefCountBase() == NULL ? 10 : 8;
        break;
    case 0xb: case 0xc:
    {
        const UPInt traits = reinterpret_cast<UPInt>(&FUN_14250ffc0(*vm, *top));
        idx = static_cast<UInt32>(*reinterpret_cast<const int*>(traits + 0x70) - 0xd) < 2 ? 11 : 10;
        break;
    }
    default: idx = 0xc; break;
    }
    top->Assign(reinterpret_cast<ASStringNode**>(&vm->GetStringManager())[idx]);
}


// A PropRef that found nothing: no this value, or an empty dynamic/closure tag.
static inline bool PropRefNotFound(const PropRef& p)
{
    const UPInt w = reinterpret_cast<UPInt>(p.pValue);
    return p.This.GetKind() == Value::kUndefined || w == 1 || w == 2;
}

// Object.SetProperty: a fixed slot, an existing dynamic value, or a new dynamic property.
// MS2-FUNCTIONAL 0x142528a50: same lookup and branches; the exe inlines the Value temporaries differently (frame differs).
// @0x142528a50
CheckResult Object::SetProperty(const Multiname& prop_name, const Value& value)
{
    VM& vm = GetVM();
    PropRef prop;
    {
        Value self(this);
        FUN_142501b00(&prop, &vm, &self, &prop_name, 1);
    }
    if (PropRefNotFound(prop))
    {
        if (!pTraits->IsDynamic() || !prop_name.ContainsNamespace(vm.GetPublicNamespace()))
        {
            vm.ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x420), vm, prop_name.Name,
                                             GetTraits().GetName().ToCStr()));
            return CheckResult(false);
        }
        AddDynamicSlotValuePair(prop_name.Name, value);
        return CheckResult(true);
    }
    switch (reinterpret_cast<UPInt>(prop.pValue) & 3)
    {
    case 0:
    {
        CheckResult ok(false);
        Sfr27SlotSetValueThis(prop.pSI, reinterpret_cast<char*>(&ok), &vm, &value, &prop.This, NULL);
        return ok;
    }
    case 1:
        reinterpret_cast<Value*>(reinterpret_cast<UPInt>(prop.pValue) & ~static_cast<UPInt>(1))->Assign(value);
        return CheckResult(true);
    case 2:
        return CheckResult(false);
    }
    return CheckResult(true);
}

// setproperty on any value: objects with special property handling take it themselves, the rest go through
// the property lookup.
// @0x142528810
char* Sfr27SetPropertyOfValue(char* ret, VM* vm, const Value* obj, const Multiname* mn, const Value* v)
{
    if (static_cast<UInt32>(obj->GetKind()) - 0xc < 4)
    {
        Object* o = reinterpret_cast<Object*>(obj->GetGASRefCountBase());
        Traits& tr = o->GetTraits();
        const UPInt flags = static_cast<UPInt>(tr.Flags);
        const int type = static_cast<int>(tr.TraitsType);
        if ((flags & 1) != 0 || (static_cast<UInt32>(type - 0xd) < 2 && ((~(flags >> 5)) & 1) != 0))
        {
            *ret = o->SetProperty(*mn, *v) ? 1 : 0;
            return ret;
        }
    }
    PropRef prop;
    FUN_142501b00(&prop, vm, obj, mn, 1);
    if (PropRefNotFound(prop))
    {
        if (static_cast<UInt32>(obj->GetKind()) - 0xc < 4 &&
            (reinterpret_cast<Object*>(obj->GetGASRefCountBase())->GetTraits().Flags >> 1 & 1) != 0 &&
            mn->ContainsNamespace(vm->GetPublicNamespace()))
        {
            reinterpret_cast<Object*>(obj->GetGASRefCountBase())->AddDynamicSlotValuePair(mn->Name, *v);
            *ret = 1;
        }
        else
        {
            Traits* tr = const_cast<Traits*>(&FUN_14250ffc0(*vm, *obj));
            vm->ThrowReferenceError(VM::Error(static_cast<VM::ErrorID>(0x420), *vm, mn->Name, tr->GetName().ToCStr()));
            *ret = 0;
        }
        return ret;
    }
    char r = 1;
    switch (reinterpret_cast<UPInt>(prop.pValue) & 3)
    {
    case 0:
        Sfr27SlotSetValueThis(prop.pSI, &r, vm, v, &prop.This, NULL);
        break;
    case 1:
        reinterpret_cast<Value*>(reinterpret_cast<UPInt>(prop.pValue) & ~static_cast<UPInt>(1))->Assign(*v);
        break;
    case 2:
        r = 0;
        break;
    }
    *ret = r;
    return ret;
}

// A run-time multiname taken from a QName object: its name and namespace.
// @0x1425273b0
__declspec(noinline) void Sfr27MultinameFromQName(Multiname* mn, const Value* v)
{
    const UPInt q = reinterpret_cast<UPInt>(v->GetGASRefCountBase());
    mn->Name.Assign(*reinterpret_cast<const ASString*>(q + 0x38));
    if (mn->Name.GetKind() == Value::kString)
    {
        ASStringNode* node = reinterpret_cast<ASStringNode*>(mn->Name.GetGASRefCountBase());
        node->AddRef();
        if (node->Size != 0 && node->pData[0] == '*')
            mn->Name.Assign(reinterpret_cast<ASStringNode*>(reinterpret_cast<UPInt>(node->pManager) + 0x40));
        node->Release();
    }
    mn->Obj = reinterpret_cast<GASRefCountBase*>(*reinterpret_cast<UPInt*>(q + 0x40));
    *reinterpret_cast<UInt32*>(mn) &= 0xfffffff9;
}

// @0x142528cc0
void Multiname::SetRTNameUnsafe(const Value& v)
{
    const UInt32 k = static_cast<UInt32>(v.GetKind());
    if (k - 0xc <= 3 && v.GetGASRefCountBase() != NULL)
    {
        const Traits& tr = reinterpret_cast<Object*>(v.GetGASRefCountBase())->GetTraits();
        if (static_cast<int>(tr.TraitsType) == 0xc && (static_cast<UInt8>(~static_cast<UInt8>(static_cast<UInt8>(tr.Flags) >> 5)) & 1) != 0)
        {
            Sfr27MultinameFromQName(this, &v);
            return;
        }
    }
    Name.AssignUnsafe(v);
    PostProcessName(false);
}


// setslot for objects whose slots follow the traits' first own slot.
// MS2-FUNCTIONAL 0x1425402a0: same slot write through the shared setter; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x1425402a0
void Sfr27ExecSetOwnSlot(VM* vm, UInt32 slot)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value value;
    value.Pick(stk);
    Value self;
    self.Pick(stk);
    ExecRequireObject(*vm, self);
    if (vm->IsException())
        return;
    Object* obj = reinterpret_cast<Object*>(self.GetGASRefCountBase());
    CheckResult ok(false);
    Sfr27SlotSetValueObj(&ExecSlotOf(obj, slot, true), reinterpret_cast<char*>(&ok), &obj->GetVM(), &value, obj);
}

// initslot: setslot with read-only checks off (the VM is counted as inside an initializer).
// MS2-FUNCTIONAL 0x14253b420: same slot write with the initializer counter bumped; the exe inlines the Value Release/AddRef paths where ours calls the out-of-line ReleaseInternal/ReleaseWeakRef (frame and size differ; same helper calls).
// @0x14253b420
void Sfr27ExecInitSlot(VM* vm, SPInt slot)
{
    ValueStack& stk = *reinterpret_cast<ValueStack*>(reinterpret_cast<UPInt>(vm) + 0x48);
    Value value;
    value.Pick(stk);
    Value self;
    self.Pick(stk);
    ExecRequireObject(*vm, self);
    if (vm->IsException())
        return;
    int& inInitializer = *reinterpret_cast<int*>(reinterpret_cast<UPInt>(vm) + 0x30);
    ++inInitializer;
    Object* obj = reinterpret_cast<Object*>(self.GetGASRefCountBase());
    CheckResult ok(false);
    Sfr27SlotSetValueObj(&ExecSlotOf(obj, slot, false), reinterpret_cast<char*>(&ok), &obj->GetVM(), &value, obj);
    --inInitializer;
}


// Makes room for n more values, moving to a new page when the current one is full.
// @0x1425241f0
void ValueStack::Reserve(UInt16 n)
{
    if (pCurrent + n < pCurrentPage->Values + pCurrentPage->PageSize)
    {
        pStack = pCurrent + 1;
    }
    else
    {
        Page* p = NewPage(n);

        p->pNext = NULL;
        p->pPrev = pCurrentPage;
        pCurrentPage->pNext = p;

        pCurrentPage->pCurrent = pCurrent;
        pCurrentPage->pFirst = pStack;

        pCurrentPage = p;

        pStack = pCurrentPage->Values;
        pCurrent = pCurrentPage->Values;
        --pCurrent;
    }
    ReservedNum = n;
    ++pCurrentPage->ReservationNum;
}

// Reserves the num registers of a new call frame.
// @0x1425240e0
void ValueRegisterFile::Reserve(UInt16 num)
{
    UInt16 currSize = 0;

    if (Unk00 + num <= pCurrentPage->PageSize)
    {
        currSize = static_cast<UInt16>(Unk00 - (pRF - pCurrentPage->Values));
        pRF = pCurrentPage->Values + Unk00;
        Unk00 = Unk00 + num;
    }
    else
    {
        Page* p = NewPage(num);

        p->pNext = NULL;
        p->pPrev = pCurrentPage;
        pCurrentPage->pNext = p;
        pCurrentPage->ReservedNum = Unk00;
        pCurrentPage->pCurrent = pRF;
        pCurrentPage = p;

        pRF = pCurrentPage->Values;
        Unk00 = num;
    }

    Page* page = pCurrentPage;
    GetReservations(page)[page->CurrPos++] = currSize;

    for (UInt32 i = 0; i < num; ++i)
        Construct<Value>(pRF + i);
}


// The class traits registered under name and namespace; looked up in the global object's classes on a miss
// (and then cached).
// MS2-FUNCTIONAL 0x1425251e0: the registry lookup and Add are inlined here, so the frame and size differ from the exe
// @0x1425251e0
ClassTraits::Traits* Sfr27GetClassTraitsByName(VM* vm, const ASString* name, const Instances::Namespace* ns)
{
    ClassTraits::Traits** found = FUN_142414ac0(&vm->ClassTraitsSet, *name, *ns);
    ClassTraits::Traits* ct = found != NULL ? *found : NULL;
    if (ct == NULL)
    {
        ct = FUN_142415520(reinterpret_cast<void*>(VmRd(vm, 0x298)), name, ns);
        if (ct != NULL)
            vm->ClassTraitsSet.Add(*name, *ns, ct);
    }
    return ct;
}


// The traits' slot ind receives v for obj.
// @0x142529eb0
char* Sfr27TraitsSetSlotValue(Traits* tr, char* ret, SPInt ind, Value* v, Object* obj)
{
    Sfr27SlotSetValueObj(&tr->GetSlotInfo(AbsoluteIndex(ind)), ret, &tr->GetVM(), v, obj);
    return ret;
}

// Object slot number slot (1-based, counted from the traits' first own slot) receives v.
// @0x142528f80
char* Sfr27ObjectSetSlotValue(Object* obj, char* ret, UInt32 slot, Value* v)
{
    Traits& tr = obj->GetTraits();
    return Sfr27TraitsSetSlotValue(&tr, ret, static_cast<SPInt>(slot) - 1 + tr.FirstOwnSlotInd.Get(), v, obj);
}

// AS3 Array object: sets its length (GFx::Value::ObjectInterface::SetArraySize).
// @0x1425265d0
bool Sfr27ObjectInterfaceSetArraySize(void* self, UPInt obj, UInt32 size)
{
    reinterpret_cast<Instances::fl::Array*>(obj)->Resize(size);
    return true;
}

// The tag bits an object address carries for this value (no exe address of its own: inlined everywhere).
Value::ObjectTag Value::GetObjectTag() const
{
    switch (GetKind())
    {
    case kFunction:  return otFunction;
    case kObject:    return otObject;
    case kClass:     return otClass;
    case kNamespace: return otNamespace;
    default:         break;
    }
    return otInvalid;
}

void STPtr::AddRef() const
{
    if (pObject)
        GetRawAddr()->AddRef();
}

// A pointer the collector killed (bit 0 set; the object is already freed) is only untagged, not released
// (exe STPtr::SetValue 0x14252a640: and ~6; test cl,1; jne skip).
void STPtr::Release() const
{
    if (pObject)
    {
        ObjType* addr = GetAddrNoTag();
        if ((UPInt)addr & 1)
            pObject = (ObjType*)((UPInt)addr - 1 + GetObjectTag((UPInt)pObject));
        else
            addr->Release();
    }
}


// The button's up state receives obj.
// @0x14252a4e0
void Sfr31ButtonSetUpState(void* button, void* obj) { FUN_142529f70(button, 0, obj); }

// The same for the over state.
// @0x1425287b0
void Sfr31ButtonSetOverState(void* button, void* obj) { FUN_142529f70(button, 1, obj); }

// The same for the down state.
// @0x1425272f0
void Sfr31ButtonSetDownState(void* button, void* obj) { FUN_142529f70(button, 2, obj); }

// The same for the hit-test state.
// @0x142527490
void Sfr31ButtonSetHitTestState(void* button, void* obj) { FUN_142529f70(button, 3, obj); }

// Two bounds with -1 meaning the default (0 and 1000); the second is stored twice.
// @0x1425287c0
void Sfr31SetDefaultedBounds(char* self, int lo, int hi)
{
    if (lo == -1)
        lo = 0;
    *reinterpret_cast<int*>(self + 0xac) = lo;
    if (hi == -1)
        hi = 1000;
    *reinterpret_cast<int*>(self + 0x8c) = hi;
    *reinterpret_cast<int*>(self + 0xa8) = hi;
}

// Hands arg to the helper with the table 200 bytes into the file's constant block.
// @0x142531510
void Sfr31HandOffToFileBlock(UPInt self, UPInt arg)
{
    FUN_1424ffc10(self, *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x20) + 0x78) + 0x10) + 200,
                  arg, 0, 0);
}

// Calls the helper object's virtual 0x58 with the owner and its +0x50 field (result discarded).
// @0x142538810
void Sfr31CallHelperVirtual(UPInt self)
{
    typedef void (*Fn)(UPInt helper, void* ret, UPInt owner, UPInt arg);
    UPInt helper = *reinterpret_cast<UPInt*>(self + 0x40);
    char ret[32];
    (*reinterpret_cast<Fn*>(*reinterpret_cast<UPInt*>(helper) + 0x58))(helper, ret, self, *reinterpret_cast<UPInt*>(self + 0x50));
}

// Flags the object (virtual 0x30 with 0x20000) after the global init helper, and caches its field 0x60.
// @0x142524350
void Sfr31FlagAndCacheField(UPInt self, UPInt* obj)
{
    typedef void (*Fn)(UPInt* obj, int flags);
    FUN_1424f03f0(reinterpret_cast<unsigned char*>(self), obj);
    (*reinterpret_cast<Fn*>(*obj + 0x30))(obj, 0x20000);
    *reinterpret_cast<UPInt*>(self + 0x28) = obj[0xc];
}


// Stage::SetOrientation: the orientation string (+0x120) is replaced.
// @0x142528770
void Sfr31StageSetOrientation(char* self, const ASString& orientation)
{
    *reinterpret_cast<ASString*>(self + 0x120) = orientation;
}

// ShapeDataInterface::SkipPathData: reads (virtual 0x48) until it reports the end.
// @0x14252c850
void Sfr31SkipPathData(UPInt self, void* pos)
{
    typedef int (*Fn)(UPInt self, void* pos, void* out);
    char out[24];
    while ((*reinterpret_cast<Fn*>(*reinterpret_cast<UPInt*>(self) + 0x48))(self, pos, out) != 0)
    {
    }
}


// Stores np into a tagged GC reference slot (odd values are weak marks); the old target is released.
static void Sfr31AssignGcRef(UPInt* slot, UPInt np)
{
    if (np != *slot)
    {
        const UPInt old = *slot;
        if (old != 0)
        {
            if ((old & 1) != 0)
                *slot = old - 1;
            else
            {
                UInt32* rc = reinterpret_cast<UInt32*>(old + 0x10);
                if ((*rc & 0x3fffff) != 0)
                {
                    --*rc;
                    FUN_1423dfa20(reinterpret_cast<void*>(old));
                }
            }
        }
        if (np != 0)
        {
            UInt32* rc = reinterpret_cast<UInt32*>(np + 0x10);
            *rc = (*rc + 1) & 0x8fbfffff;
        }
        *slot = np;
    }
}

// Stores the new GC reference at +8 and clears the word after it.
// @0x142526340
void Sfr31SetGcRefClearNext(UPInt self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 8), np);
    *reinterpret_cast<UPInt*>(self + 0x10) = 0;
}

// Stores the new GC reference at +8 and clears the two low flag bits of the first word.
// @0x142528d20
void Sfr31SetGcRefClearFlags(UInt32* self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 2), np);
    *self &= 0xfffffffc;
}

// Stores the new GC reference at +8.
// @0x142540bd0
void Sfr31SetGcRef(UPInt self, UPInt np)
{
    Sfr31AssignGcRef(reinterpret_cast<UPInt*>(self + 8), np);
}

// Replaces the resource at +0xc0 (the new one is referenced first).
// @0x1425274b0
void Sfr31SetResource(UPInt self, Resource* res)
{
    if (res)
        res->AddRef();
    Resource*& cur = *reinterpret_cast<Resource**>(self + 0xc0);
    if (cur)
        cur->Release();
    cur = res;
}

// AvmBitmap::SetResourceMovieDef: the movie def (a resource) at +0xc8 is replaced.
// @0x142528e70
void Sfr31BitmapSetMovieDef(UPInt self, Resource* def)
{
    if (def)
        def->AddRef();
    Resource*& cur = *reinterpret_cast<Resource**>(self + 0xc8);
    if (cur)
        cur->Release();
    cur = def;
}

// MS2-FUNCTIONAL 0x142528f20: the copy/rename helpers are shared out-of-line code.
// @0x142528f20
void Slots::SetSlotInfo(AbsoluteIndex ind, const ASString& k, const SlotInfo& v)
{
    FUN_1424e0b80(&VArray[static_cast<UInt32>(ind.Get()) - FirstOwnSlotNum].Value, &v);
    SetKey(ind, k);
}

// Tracer::SkipOrigOpCode: a position inside the code gets its register state noted before moving on.
// @0x14252c7e0
void Sfr31TracerSkipOrigOpCode(UPInt tracer, UPInt* pos, UPInt next)
{
    if (*pos < *reinterpret_cast<UPInt*>(tracer + 0x58))
    {
        FUN_14251f710(tracer + 0x70, pos);
        *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(tracer + 0xd0) + *pos * 8) =
            *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(tracer + 0x28) + 8);
    }
    *pos = next;
}


// Re-reads the autosize flags of the text field (+0x18) into its document view and marks it dirty.
// MS2-FUNCTIONAL 0x142530fc0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142530fc0
void Sfr31UpdateAutosizeSettings(UPInt self)
{
    const UPInt tf = *reinterpret_cast<UPInt*>(self + 0x18);
    const UInt8 flags = *reinterpret_cast<UInt8*>(tf + 0xfc);
    UPInt doc = *reinterpret_cast<UPInt*>(tf + 0xe0);
    if ((flags & 1) && !(*reinterpret_cast<UInt8*>(doc + 0x149) & 8))
        FUN_1426150b0(doc);
    else
        *reinterpret_cast<UInt8*>(doc + 0x149) &= 0xfe;
    if (!(flags & 1))
        *reinterpret_cast<UInt8*>(*reinterpret_cast<UPInt*>(tf + 0xe0) + 0x149) &= 0xfd;
    else
        FUN_1426150d0(*reinterpret_cast<UPInt*>(tf + 0xe0));
    *reinterpret_cast<UInt32*>(tf + 0xfc) |= 0x2000;
    FUN_1425bc060(tf);
}

// Tracer::UpdateBlock: moves to the block that starts at pos; false when the merge of the old state fails.
// MS2-FUNCTIONAL 0x142531040: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142531040
void Sfr31TracerUpdateBlock(UPInt tracer, char* ok, UPInt pos)
{
    UPInt* old = *reinterpret_cast<UPInt**>(tracer + 0x68);
    UPInt* blk = *reinterpret_cast<UPInt**>(tracer + 0x110);
    if (blk != NULL)
    {
        while (pos < blk[4])
        {
            blk = reinterpret_cast<UPInt*>(*blk);
            if (blk == NULL)
            {
                *ok = 1;
                return;
            }
        }
        if (blk[4] == pos)
        {
            *reinterpret_cast<UPInt**>(tracer + 0x68) = blk;
            if ((*reinterpret_cast<UInt8*>(blk + 2) & 1) == 0)
                FUN_142511b00(tracer, blk, old);
            else if (blk != old)
            {
                char buf[32];
                if (*FUN_142516c40(tracer, buf, blk, old) == 0)
                {
                    *ok = 0;
                    return;
                }
            }
        }
    }
    *ok = 1;
}

// Runs the shutdown of every registered entry (+0x2c0 array of +0x2c8 items), then empties the array.
// @0x142530d50
void Sfr31ShutdownRegistered(UPInt self)
{
    const UPInt n = *reinterpret_cast<UPInt*>(self + 0x2c8);
    const UInt8 saved = *reinterpret_cast<UInt8*>(self + 9);
    *reinterpret_cast<UInt8*>(self + 9) = 1;
    for (UPInt i = 0; i < n; ++i)
        FUN_1425303b0(reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x2c0))[i]);
    FUN_1424ef2a0(self + 0x2c0);
    *reinterpret_cast<UInt8*>(self + 9) = saved;
}

// Runs the slot (kind bits 5..9 are not a getter unless the caller asked for one) through the invoke helper.
// MS2-FUNCTIONAL 0x1425311c0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x1425311c0
void Sfr31InvokeSlot(UPInt self, const SlotInfo* si, UPInt arg, int argc)
{
    const UPInt traits = FUN_14250fa80(self);
    const SInt32 bt = si->BindType;
    const SPInt index = si->ValueInd;
    if (bt != SlotInfo::BT_Code || argc == bt)
    {
        ASString name(si->Name.GetPtr());
        Sfr31StoreSlotValue(traits, index, reinterpret_cast<const Value*>(arg), argc, reinterpret_cast<const UPInt*>(&name));
    }
}

// Looks the name up in the own slots and invokes the newest one whose namespace has the flag (bit 4).
// MS2-FUNCTIONAL 0x1425310e0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x1425310e0
void Sfr31InvokeNamedSlot(UPInt self, const ASString& name, UPInt target, UPInt arg, int argc)
{
    if (target != *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 0x78) + 0x1d0))
        return;
    const Slots& slots = *reinterpret_cast<const Slots*>(self + 0x20);
    SPInt i = *slots.FindSlotValues(name);
    do
    {
        const SlotInfo* si;
        if (static_cast<UPInt>(i) < slots.FirstOwnSlotNum)
            si = &slots.Parent->GetSlotInfo(AbsoluteIndex(i));
        else
            si = &slots.VArray[static_cast<UInt32>(i) - static_cast<UInt32>(slots.FirstOwnSlotNum)].Value;
        if ((*reinterpret_cast<const UInt8*>(*reinterpret_cast<const UPInt*>(reinterpret_cast<const char*>(si) + 8) + 0x20) >> 4) & 1)
        {
            Sfr31InvokeSlot(self, si, arg, argc);
            return;
        }
        if (static_cast<UPInt>(i) < slots.FirstOwnSlotNum)
            i = slots.Parent->GetPrevSlotIndex(i);
        else
            i = slots.VArray[static_cast<UInt32>(i) - static_cast<UInt32>(slots.FirstOwnSlotNum)].Prev;
    } while (i >= 0);
}


// TR::State::SwapOp: the two topmost operand stack values trade places.
// MS2-FUNCTIONAL 0x14252e800: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252e800
void Sfr31StateSwapOp(UPInt state)
{
    Value* data = *reinterpret_cast<Value**>(state + 0x38);
    const UPInt n = *reinterpret_cast<UPInt*>(state + 0x40);
    Value top(data[n - 1]);
    data[n - 1] = data[n - 2];
    data[n - 2] = top;
}

// AvmDisplayObj::SwitchAS3ObjPtrType: type 1 makes the object reference strong, anything else weak.
// MS2-FUNCTIONAL 0x14252e900: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252e900
void Sfr31SwitchAS3ObjPtrType(UPInt self, int type)
{
    UPInt* strong = reinterpret_cast<UPInt*>(self + 8);
    UPInt* weak = reinterpret_cast<UPInt*>(self + 0x10);
    UPInt v = *weak;
    if (type == 1)
    {
        if (v == 0)
            v = *strong;
        if (v & 1)
            --v;
        Sfr31SetGcRefClearNext(self, v);
        return;
    }
    if (v == 0)
        v = *strong;
    if (v & 1)
        --v;
    *weak = v;
    const UPInt s = *strong;
    if (s != 0)
    {
        if (((s & 1) == 0) && (*reinterpret_cast<UInt32*>(s + 0x10) & 0x3fffff) != 0)
        {
            --*reinterpret_cast<UInt32*>(s + 0x10);
            FUN_1423dfa20(reinterpret_cast<void*>(s));
        }
        *strong = 0;
    }
}

// AvmButton::SwitchState: unless the owner is being destroyed or already removed, the mouse state is
// translated and handed to SwitchStateIntl.
// MS2-FUNCTIONAL 0x14252e980: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252e980
void Sfr31ButtonSwitchState(UPInt self, int mouseState)
{
    const UPInt owner = *reinterpret_cast<UPInt*>(self - 0x28);
    const UInt16 flags = *reinterpret_cast<UInt16*>(owner + 0x6a);
    if (!((flags >> 4) & 1) && !(flags & 0x1000) && *reinterpret_cast<int*>(owner + 0x2c) > -2)
        Sfr31ButtonSwitchStateIntl(self - 0x40, FUN_1425de200(mouseState));
}

// AS3ValueObjectInterface::SetElement: stores the converted value at the array index.
// MS2-FUNCTIONAL 0x142527300: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142527300
bool Sfr31SetElement(UPInt self, UPInt array, UInt32 ind, const void* gfxValue)
{
    Value v;
    FUN_1425048d0(*reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 8) + 0x18), gfxValue, &v);
    FUN_1424213b0(array + 0x38, ind, &v);
    return true;
}

// AS3ValueObjectInterface::ToString: the value's string form is copied into out.
// MS2-FUNCTIONAL 0x14252fd40: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252fd40
void Sfr31ToString(UPInt self, String* out, const void* gfxValue)
{
    const UPInt root = *reinterpret_cast<UPInt*>(*reinterpret_cast<UPInt*>(self + 8) + 0x18);
    Value v;
    FUN_1425048d0(root, gfxValue, &v);
    ASString s(reinterpret_cast<ASStringNode*>(*reinterpret_cast<UPInt*>(root + 0x348) + 0x40));
    v.Convert2String(s);
    out->AssignString(s.ToCStr(), s.GetSize());
}

}}} // namespace Scaleform::GFx::AS3

// ---- display-object setters and small helpers (sfr31) ----
void FUN_1425f4090(void* obj);
Scaleform::UInt64 FUN_1425e3560(void);
Scaleform::SInt32 FUN_142622510(Scaleform::UPInt obj);
Scaleform::SInt64 FUN_1426224d0(Scaleform::UPInt obj);
void FUN_142623560(Scaleform::UPInt obj, Scaleform::UInt64 delta);
void FUN_1426244e0(Scaleform::UPInt obj, Scaleform::SInt32 v);
void FUN_142624450(Scaleform::UPInt obj, Scaleform::SInt64 v);
Scaleform::GFx::AS3::Value* FUN_14250a490(Scaleform::UPInt tracer, Scaleform::GFx::AS3::Value* out, Scaleform::UPInt state);

namespace Scaleform { namespace GFx {

// @0x1425265f0
void InteractiveObject::SetBlendMode(Render::BlendMode mode)
{
    DisplayObjectBase::SetBlendMode(mode);
    FUN_1425f4090(this);
}

namespace AS3 {

static inline UPInt Sfr31Rd(UPInt base, UPInt off) { return *reinterpret_cast<const UPInt*>(base + off); }
static inline void Sfr31Wr(UPInt base, UPInt off, UPInt v) { *reinterpret_cast<UPInt*>(base + off) = v; }

// @0x1425262e0
void Sfr31AvmDisplayObjSetAS3Obj(UPInt self, UPInt obj)
{
    if (Sfr31Rd(Sfr31Rd(self, 0x18), 0x38) != 0) { Sfr31SetGcRefClearNext(self, obj); return; }
    *reinterpret_cast<UPInt*>(self + 0x10) = obj;
    UPInt old = Sfr31Rd(self, 8);
    if (old != 0)
    {
        if (((old & 1) == 0) && ((*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0))
        {
            *reinterpret_cast<UInt32*>(old + 0x10) -= 1;
            FUN_1423dfa20(reinterpret_cast<void*>(old));
        }
        *reinterpret_cast<UPInt*>(self + 8) = 0;
    }
}

// @0x1425266c0
bool Sfr31SetCxform(UPInt self, UPInt obj, const Render::Cxform* cx)
{
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) != 0))
    {
        DisplayObjectBase* d = *reinterpret_cast<DisplayObjectBase**>(obj + 0x58);
        d->SetCxform(*cx);
        typedef void (*Fn)(void*, SInt32);
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(d), 0), 0x188))(d, 0);
        return true;
    }
    return false;
}

// MS2-FUNCTIONAL 0x142539420: same logic; Value init/release and register allocation differ
// @0x142539420
void Sfr31StatePushTyped(UPInt st)
{
    Value v;
    const Value* r = FUN_14250a490(Sfr31Rd(st, 0), &v, st);
    reinterpret_cast<TR::State*>(st)->GetOpStack().PushBack(*r);
}

// The syncing object: vtable slot 1 returns the render-side object it mirrors to (or null).
struct Sfr31SyncView
{
    virtual void Slot0();
    virtual UPInt GetTarget();
};

// @0x142526430
void Sfr31SyncSetInt(UPInt* self, SInt32 val)
{
    UPInt o = reinterpret_cast<Sfr31SyncView*>(self)->GetTarget();
    if (o != 0 && val != FUN_142622510(o))
    {
        UInt64 t = FUN_1425e3560();
        FUN_142623560(o, t - self[0x38]);
        self[0x38] = t;
        FUN_1426244e0(o, val);
    }
}

// @0x1425263b0
void Sfr31SyncSetInt64(UPInt* self, SInt64 val)
{
    UPInt o = reinterpret_cast<Sfr31SyncView*>(self)->GetTarget();
    if (o != 0 && val != FUN_1426224d0(o))
    {
        UInt64 t = FUN_1425e3560();
        FUN_142623560(o, t - self[0x38]);
        self[0x38] = t;
        FUN_142624450(o, val);
    }
}

// MS2-FUNCTIONAL 0x142528fb0: the exe places the kind-2 (false) result block before the kind-3 (true) one
// @0x142528fb0
char* Sfr31PropRefSetSlotValue(UPInt self, char* ret, UPInt vm, const Value* v)
{
    // PropRef: the low two bits of the first word tag a SlotInfo (0), a Value (1) or a missing property (2).
    const UPInt w = Sfr31Rd(self, 0);
    switch (w & 3)
    {
    case 0:
    {
        char tmp;   // CheckResult
        *ret = *Sfr27SlotSetValueThis(reinterpret_cast<const SlotInfo*>(w), &tmp, reinterpret_cast<VM*>(vm), v, reinterpret_cast<const Value*>(self + 0x10), 0);
        return ret;
    }
    case 1:
        reinterpret_cast<Value*>(w & ~UPInt(1))->Assign(*v);
        *ret = 1;
        return ret;
    case 2:
        *ret = 0;
        return ret;
    }
    *ret = 1;
    return ret;
}

}}} // namespace Scaleform::GFx::AS3

// ---- tracer pushes, display-list index, VM pop/pushundefined (sfr31) ----
Scaleform::UPInt FUN_142506f00(Scaleform::UPInt link, Scaleform::UPInt traits, Scaleform::GFx::ASString* name);
Scaleform::UPInt FUN_14250ae60(Scaleform::UPInt link, Scaleform::UPInt ind);
Scaleform::GFx::AS3::Value* FUN_1423ef9b0(Scaleform::GFx::AS3::Value* out, Scaleform::UPInt x);
Scaleform::UPInt FUN_14250d760(Scaleform::UPInt root, Scaleform::UPInt pos);
void FUN_14257dcd0(void* obj);
void FUN_1424efe30(Scaleform::GFx::AS3::VM* vm, Scaleform::GFx::AS3::Value* a, Scaleform::GFx::AS3::Value* b);

namespace Scaleform { namespace GFx { namespace AS3 {

// A tracer value holding a pointer at +0x10 (the exe stores the kind and clears the second word).
struct TrPtrScratch
{
    TrPtrScratch(UInt32 kind) { w1 = 0; w0 = kind; }
    const Value& Get() const { return *reinterpret_cast<const Value*>(&w0); }
    UInt32 w0;
    UPInt w1, w2, w3;
};

// MS2-FUNCTIONAL 0x14253be60: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253be60
void Sfr31StatePushNs(UPInt st)
{
    const UPInt own = Sfr31Rd(Sfr31Rd(st, 0), 0x20);
    ASString name(reinterpret_cast<ASStringNode*>(Sfr31Rd(own, 0x70)));
    const UPInt link = Sfr31Rd(own, 0x28);
    TrPtrScratch t(8);
    t.w2 = FUN_142506f00(link, *reinterpret_cast<const UPInt*>(Sfr31Rd(Sfr31Rd(link, 0x28), 0x170) + static_cast<SPInt>(*reinterpret_cast<const SInt32*>(own + 0x30)) * 8), &name);
    reinterpret_cast<TR::State*>(st)->GetOpStack().PushBack(t.Get());
}

// MS2-FUNCTIONAL 0x14253f410: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253f410
void Sfr31StatePushPool(UPInt st, UInt32 ind)
{
    const UPInt tr = Sfr31Rd(st, 0);
    FUN_14251fcd0(tr, ind);
    Value v;
    const Value* r = FUN_1423ef9b0(&v, FUN_14250ae60(Sfr31Rd(Sfr31Rd(tr, 0x20), 0x28), ind));
    reinterpret_cast<TR::State*>(st)->GetOpStack().PushBack(*r);
}

// Instance traits seen through their vtable: slot 16 (+0x80) is the subtype test.
#define SFR31_VPAD4(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3();
struct Sfr31TraitsVtView
{
    SFR31_VPAD4(a) SFR31_VPAD4(b) SFR31_VPAD4(c) SFR31_VPAD4(d)
    virtual char IsSubtypeOf(UPInt tr);
};

// A recorded state's traits equal to, or derived from, tr (state array at +0xd0, 0x30 bytes each).
// @0x14252e480
bool Sfr31TracerHasTraits(UPInt self, UPInt tr)
{
    const UPInt root = Sfr31Rd(self, 0x78);
    for (UPInt i = 0; i < Sfr31Rd(self, 0xd8); ++i)
    {
        UPInt t = FUN_14250d760(root, Sfr31Rd(self, 0xd0) + i * 0x30);
        if (t != 0)
        {
            UPInt p = Sfr31Rd(t, 0xc0);
            if (p == tr || reinterpret_cast<Sfr31TraitsVtView*>(p)->IsSubtypeOf(tr) != 0)
                return true;
        }
    }
    return false;
}

// ASUserData view: SetLastObjectValue is a member call (exe 0x142575f10).
struct Sfr31UserDataView { void FUN_142575f10(UPInt movie, UPInt owner, bool isdobj); };

// Instances::fl::Object view: pUserDataHolder at +0x30.
struct Sfr31ObjectUserDataView
{
    UInt8 Pad[0x30];
    UPInt* pUserDataHolder;
    void SetUserData(UPInt pmovieView, UPInt puserData, bool isdobj);
};

// Object::SetUserData: replace the 16-byte holder {movie, userdata}; the user data records this object.
// @0x14252a5a0
void Sfr31ObjectUserDataView::SetUserData(UPInt pmovieView, UPInt puserData, bool isdobj)
{
    if (pUserDataHolder != 0)
        Memory::pGlobalHeap->Free(pUserDataHolder);
    AllocInfo ai(0x151, 0, 0);   // StatMV_VM_Instance_Mem, as in AS3ValueObjectInterface::SetUserData
    UPInt* h = static_cast<UPInt*>(Memory::pGlobalHeap->AllocAutoHeap(this, 0x10, &ai));
    if (h != 0) { h[0] = pmovieView; h[1] = puserData; }
    pUserDataHolder = h;
    if (puserData != 0)
        reinterpret_cast<Sfr31UserDataView*>(puserData)->FUN_142575f10(Sfr31Rd(pmovieView, 0x38), reinterpret_cast<UPInt>(this), isdobj);
}

} // namespace AS3

// AS3ValueObjectInterface::SetUserData (vftable slot 36): the AS3 object pdata gets a new {movie, user data} holder.
// @0x14252a4f0
void AS3ValueObjectInterface::SetUserData(void* pdata, ASUserData* puserdata, bool isdobj)
{
    using namespace AS3;
    const UPInt self = reinterpret_cast<UPInt>(pdata);
    const UPInt b = reinterpret_cast<UPInt>(puserdata);
    if (self != 0)
    {
        const UPInt a = reinterpret_cast<UPInt>(pMovieRoot);
        if (Sfr31Rd(self, 0x30) != 0)
            Memory::pGlobalHeap->Free(reinterpret_cast<void*>(Sfr31Rd(self, 0x30)));
        AllocInfo ai(0x151, 0, 0);
        UPInt* h = static_cast<UPInt*>(Memory::pGlobalHeap->AllocAutoHeap(reinterpret_cast<void*>(self), 0x10, &ai));
        if (h != 0) { h[0] = a; h[1] = b; }
        *reinterpret_cast<UPInt**>(self + 0x30) = h;
        if (b != 0)
            reinterpret_cast<Sfr31UserDataView*>(b)->FUN_142575f10(Sfr31Rd(a, 0x38), self, isdobj);
    }
}

namespace AS3 {

// MS2-FUNCTIONAL 0x142526610: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142526610
bool Sfr31ContainerSetChildIndex(UPInt self, DisplayObjectBase* ch, UInt32 index)
{
    const UPInt holder = Sfr31Rd(self, 0x18);
    if (index < *reinterpret_cast<const UInt32*>(holder + 0xe0))
    {
        DisplayList* dl = reinterpret_cast<DisplayList*>(holder + 0xd8);
        SPInt at = dl->FindDisplayIndex(ch);
        if (at >= 0)
        {
            if (ch != 0)
                ++*reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(ch) + 8);
            dl->RemoveEntryAtIndex(reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(self, 0x18)), static_cast<UPInt>(at));
            dl->AddEntryAtIndex(reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(self, 0x18)), index, ch);
            typedef void (*Fn)(void*, SInt32);
            reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(ch), 0), 0x188))(ch, 0);
            *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(ch) + 0x30) = 0;
            *reinterpret_cast<SInt32*>(reinterpret_cast<UPInt>(ch) + 0x2c) = -1;
            *reinterpret_cast<UInt8*>(holder + 0x100) |= 3;
            FUN_14257dcd0(ch);
            return true;
        }
    }
    return false;
}

// pop: with a running frame flag clear the exe's slow helper pops, otherwise the top is released inline.
// MS2-FUNCTIONAL 0x14253f920: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253f920
void Sfr31ExecPop(VM* vm)
{
    const UPInt i = VmRd(vm, 0x78) - 1;
    Value* top = reinterpret_cast<Value*>(VmRd(vm, 0x50));
    if (*reinterpret_cast<const char*>((i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8)) == 0)
    {
        FUN_1424efe30(vm, top, top);
        return;
    }
    Value*& cur = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    cur->~Value();
    --cur;
}

// MS2-FUNCTIONAL 0x14253f9e0: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14253f9e0
void Sfr31ExecPushUndefined(VM* vm)
{
    const UPInt i = VmRd(vm, 0x78) - 1;
    if (*reinterpret_cast<const char*>((i & 0x3f) * 0xa8 + *reinterpret_cast<const UPInt*>(VmRd(vm, 0x90) + (i >> 6) * 8)) == 0)
        ExecPushCopy(vm, Value::GetUndefined());
}

// MS2-FUNCTIONAL 0x14252a640: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x14252a640
STPtr* Sfr31STPtrSetValue(STPtr* self, const Value& v)
{
    return &self->SetValue(v);
}

}}} // namespace Scaleform::GFx::AS3

// ---- tracer pops with ReadArgs, TextField text, invoke alias, cursor type, action queue (sfr31) ----
namespace Scaleform { namespace GFx { namespace AS3 {
using namespace TR;

// MS2-FUNCTIONAL 0x142537710: behavior-equivalent recovery; codegen differs from exe
// @0x142537710
void Sfr31TraceCallPop(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, argc);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    popped.Get().~Value();
}

// MS2-FUNCTIONAL 0x1425401a0: behavior-equivalent recovery; codegen differs from exe
// @0x1425401a0
void Sfr31TracePop2Note(State* st, UInt32 arg)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), arg);
    TrPopped a, b;
    FUN_14251cd30(st, &a.Get());
    FUN_14251cd30(st, &b.Get());
    b.Get().~Value();
    a.Get().~Value();
}

// setInterval/setTimeout: appends the extra call arguments to the IntervalTimer's Params (ArrayLH<Value> at +0x38).
// The callers (0x14242a1a4, 0x14242af14) pass the new IntervalTimer, not a tracer State.
// MS2-FUNCTIONAL 0x1425264b0: behavior-equivalent recovery; codegen differs from exe
// @0x1425264b0
void Sfr31StatePushValues(State* st, UInt32 n, const Value* vals)
{
    ArrayLH<Value>& params = *reinterpret_cast<ArrayLH<Value>*>(reinterpret_cast<UPInt>(st) + 0x38);
    for (UInt32 i = 0; i < n; ++i)
        params.PushBack(vals[i]);
}

// MS2-FUNCTIONAL 0x142540a90: behavior-equivalent recovery; codegen differs from exe
// @0x142540a90
const MovieRoot::ActionEntry* MovieRoot::ActionQueueIterator::getNext()
{
    ActionQueueType* q = pActionQueue;
    ActionEntry* pe;
    if (q->ModId != ModId)
    {
        ModId = q->ModId;
        ActionEntry** src = pRootEntry ? &pRootEntry->pNextEntry : &q->Entries[Level].pActionRoot;
        pe = *src;
        pCurEntry = pe;
    }
    else
        pe = pCurEntry;
    if (pe != 0)
    {
        if (pe == q->Entries[Level].pInsertEntry)
        {
            ActionEntry* nx = pe->pNextEntry;
            if (nx == 0)
                nx = pRootEntry;
            q->Entries[Level].pInsertEntry = nx;
        }
        ActionEntry** root = &pActionQueue->Entries[Level].pActionRoot;
        ActionEntry* cur = pCurEntry;
        if (cur == *root)
            *root = cur->pNextEntry;
        else if (pRootEntry != 0)
            pRootEntry->pNextEntry = cur->pNextEntry;
        q = pActionQueue;
        pCurEntry = pCurEntry->pNextEntry;
    }
    if (q->Entries[Level].pActionRoot == 0)
    {
        q->Entries[Level].pInsertEntry = 0;
        pActionQueue->Entries[Level].pLastEntry = 0;
    }
    if (pLastEntry != 0)
    {
        pLastEntry->pNextEntry = 0;
        pActionQueue->AddToFreeList(pLastEntry);
        ++pActionQueue->ModId;
        ModId = pActionQueue->ModId;
    }
    pLastEntry = pe;
    return pe;
}

// A text assignment through the host interface: TextFields take it directly, anything else gets text/htmlText.
// MS2-FUNCTIONAL 0x14252a360: behavior-equivalent recovery; codegen differs from exe
// @0x14252a360
bool Sfr31SetTextOnObject(UPInt* self, UPInt obj, const wchar_t* text, bool html)
{
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U < 0xc) && ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) != 0))
    {
        TextField* tf = *reinterpret_cast<TextField**>(obj + 0x58);
        typedef SInt32 (*Kind)(void*);
        if (reinterpret_cast<Kind>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(tf), 0), 0x258))(tf) == 4)
        {
            tf->SetText(text, html);
            return true;
        }
        struct RawGfxValue { UPInt iface; UInt32 type; const wchar_t* str; } v = { 0, 7, text };
        typedef char (*Set)(void*, UPInt, const char*, void*, SInt32);
        char r = reinterpret_cast<Set>(Sfr31Rd(self[0], 0x28))(self, obj, html ? "htmlText" : "text", &v, 1);
        if ((v.type >> 6 & 1) != 0)
        {
            typedef void (*Rel)(void*, void*, const wchar_t*);
            reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(v.iface, 0), 0x10))(reinterpret_cast<void*>(v.iface), &v, v.str);
        }
        return r != 0;
    }
    return false;
}

// MS2-FUNCTIONAL 0x142525400: behavior-equivalent recovery; codegen differs from exe
// @0x142525400
Value* Sfr31ResolveInvokeAlias(UPInt root, const char* name)
{
    if (Sfr31Rd(root, 0x80) != 0)
    {
        ASStringNode* node = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateStringNode(name);
        Value* res = 0;
        const SInt32 rc = node->RefCount;
        node->RefCount = rc + 1;
        UPInt tbl = *reinterpret_cast<UPInt*>(Sfr31Rd(root, 0x80));
        UPInt ent = 0;
        if (tbl != 0)
        {
            const UPInt mask = Sfr31Rd(tbl, 8);
            UPInt idx = node->HashFlags & mask;
            UPInt* e = reinterpret_cast<UPInt*>(tbl + 0x10 + idx * 0x30);
            if (e[0] != ~UPInt(1) && (reinterpret_cast<ASStringNode*>(e[1])->HashFlags & mask) == idx)
            {
                UPInt at = idx;
                while ((reinterpret_cast<ASStringNode*>(e[1])->HashFlags & mask) != idx || reinterpret_cast<ASStringNode*>(e[1]) != node)
                {
                    at = e[0];
                    if (at == ~UPInt(0)) { ent = 0; goto done; }
                    e = reinterpret_cast<UPInt*>(tbl + 0x10 + at * 0x30);
                }
                if (static_cast<SPInt>(at) >= 0)
                    ent = tbl + 0x18 + at * 0x30;
            }
        }
    done:
        node->RefCount = rc;
        res = ent != 0 ? reinterpret_cast<Value*>(ent + 8) : 0;
        if (rc == 0)
            node->ReleaseNode();
        return res;
    }
    return 0;
}

// MS2-FUNCTIONAL 0x142528620: behavior-equivalent recovery; codegen differs from exe
// @0x142528620
void Sfr31SetMouseCursorType(UPInt self, const ASString* name, UInt32 mouse)
{
    const char* s = name->ToCStr();
    SInt32 v = -1;
    if (strcmp(s, "arrow") == 0) v = 0;
    else if (strcmp(s, "button") == 0) v = 3;
    else if (strcmp(s, "hand") == 0) v = 1;
    else if (strcmp(s, "ibeam") == 0) v = 2;
    SInt32* p0;
    SInt32* p1;
    if (mouse >= 4)
    {
        p0 = reinterpret_cast<SInt32*>(0x40);
        p1 = reinterpret_cast<SInt32*>(0x44);
    }
    else
    {
        p0 = reinterpret_cast<SInt32*>(Sfr31Rd(self, 0x10) + 0x12a0 + static_cast<UPInt>(mouse) * 0x50);
        p1 = reinterpret_cast<SInt32*>(Sfr31Rd(self, 0x10) + 0x12a4 + static_cast<UPInt>(mouse) * 0x50);
    }
    typedef void (*Fn)(UPInt, UInt32, SInt32);
    reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(self, 0), 0x18))(self, mouse, v);
    *p1 = v;
    *p0 = v;
}

// Tracer::Recalculate: a position to retrace and the argument it needs (0x10 bytes).
class Tracer { public: struct Recalculate { UPInt Pos; UInt32 Arg; UInt32 Pad; }; };

const SlotInfo* FindFixedSlot(VM& vm, const Traits& tr, const Multiname& mn, UPInt& ind, Object* obj);   // 0x142500f90

// batch 18
// LinearHeap::allocFromLastPage: bump-allocates from the last page, or (when that page is untouched) replaces it with one
// big enough for the request.
// MS2-FUNCTIONAL 0x142532060: functional recovery; codegen differs from exe
// @0x142532060
void* Sfr31LinearHeapAllocFromLastPage(UPInt self, UPInt n)
{
    UPInt page = Sfr31Rd(self, 0x18);
    UPInt used = Sfr31Rd(page, 0x10);
    if (static_cast<SPInt>(n) <= static_cast<SPInt>(Sfr31Rd(page, 8) - used))
    {
        Sfr31Wr(page, 0x10, used + n);
        return reinterpret_cast<void*>(Sfr31Rd(Sfr31Rd(self, 0x18), 0x10) - n);
    }
    if (used == Sfr31Rd(page, 0))
    {
        MemoryHeap* heap = reinterpret_cast<MemoryHeap*>(Sfr31Rd(self, 0));
        if (Sfr31Rd(page, 0) != 0)
            heap->Free(reinterpret_cast<void*>(Sfr31Rd(page, 0)));
        UPInt pageSize = Sfr31Rd(self, 8);
        UPInt total = n - 1 + pageSize;
        total -= total % pageSize;
        UPInt p = reinterpret_cast<UPInt>(heap->Alloc(total, static_cast<const AllocInfo*>(0)));
        UPInt cur = Sfr31Rd(self, 0x18);
        Sfr31Wr(cur, 0x10, p);
        Sfr31Wr(Sfr31Rd(self, 0x18), 0, p);
        Sfr31Wr(Sfr31Rd(self, 0x18), 8, Sfr31Rd(Sfr31Rd(self, 0x18), 0) + total);
        Sfr31Wr(Sfr31Rd(self, 0x18), 0x10, Sfr31Rd(Sfr31Rd(self, 0x18), 0x10) + n);
        return reinterpret_cast<void*>(Sfr31Rd(Sfr31Rd(self, 0x18), 0));
    }
    return 0;
}

// SetSuperProperty: stores v through the parent traits' fixed slot for the multiname; false when there is no such slot.
// MS2-FUNCTIONAL 0x14252a150: functional recovery; codegen differs from exe
// @0x14252a150
CheckResult SetSuperProperty(VM& vm, const Traits* tr, const Value& obj, const Multiname& mn, const Value& v)
{
    if (tr == 0)
        tr = &FUN_14250ffc0(vm, obj);
    const Traits* parent = tr->GetParent();
    if (parent != 0)
    {
        UPInt ind = 0;
        const SlotInfo* si = FindFixedSlot(vm, *parent, mn, ind, 0);
        if (si != 0)
        {
            UByte res[16];
            void* vt = FUN_14250fa80(parent);
            if (*Sfr27SlotSetValueThis(si, reinterpret_cast<char*>(res), &vm, &v, &obj, static_cast<VTable*>(vt)) != 0)
                return true;
        }
    }
    return false;
}

// Tracer: records a position to retrace after the target of a jump (backward jumps only note the target's position).
// MS2-FUNCTIONAL 0x14252c9f0: functional recovery; codegen differs from exe
// @0x14252c9f0
void Sfr31TraceNoteJump(UPInt tr, SPInt base, UPInt blk, SInt32 off, SInt32 arg)
{
    SPInt idx = off + base;
    if (off < 0)
    {
        FUN_14251fcd0(tr, Sfr31Rd(Sfr31Rd(tr, 0xd0) + idx * 8, 0) - Sfr31Rd(Sfr31Rd(tr, 0x28), 8) + static_cast<SPInt>(arg));
        return;
    }
    FUN_1424e6aa0(tr, blk, idx, 0, 1);
    FUN_14251fcd0(tr, idx);
    UPInt pos = Sfr31Rd(Sfr31Rd(tr, 0x28), 8);
    ArrayDataBase<Tracer::Recalculate, AllocatorDH_POD<Tracer::Recalculate, 328>, ArrayDefaultPolicy>* arr =
        reinterpret_cast<ArrayDataBase<Tracer::Recalculate, AllocatorDH_POD<Tracer::Recalculate, 328>, ArrayDefaultPolicy>*>(tr + 0xb0);
    UPInt n = arr->Size + 1;
    arr->ResizeNoConstruct(reinterpret_cast<const void*>(Sfr31Rd(tr, 0xc8)), n);
    Tracer::Recalculate& r = arr->Data[n - 1];
    r.Pos = pos - 1;
    r.Arg = static_cast<UInt32>(arg);
}

// batch 19
// nextname/nextvalue share the shape: the index on top is consumed, the object below becomes the name/value.
static __forceinline void Sfr31ExecNextCommon(VM* vm, bool wantValue)
{
    Value*& top = *reinterpret_cast<Value**>(reinterpret_cast<UPInt>(vm) + 0x50);
    UInt64 tmp;
    long idx;
    const bool ok = *FUN_1424f0d30(top, &tmp, &idx) != 0;
    if (ok)
        top->SetSInt32(idx);
    top->~Value();
    --top;
    if (ok)
    {
        Object* obj = *reinterpret_cast<Object**>(reinterpret_cast<UPInt>(top) + 0x10);
        if (wantValue)
            obj->GetNextPropertyValue(*top, GlobalSlotIndex(static_cast<UInt32>(idx)));
        else
            obj->GetNextPropertyName(*top, GlobalSlotIndex(static_cast<UInt32>(idx)));
    }
}

// MS2-FUNCTIONAL 0x14253d2f0: object released through Value::~Value and the namespace case dispatched virtually
// @0x14253d2f0
void Sfr27ExecNextName(VM* vm) { Sfr31ExecNextCommon(vm, false); }

// MS2-FUNCTIONAL 0x14253d440: functional recovery; codegen differs from exe
// @0x14253d440
void Sfr27ExecNextValue(VM* vm) { Sfr31ExecNextCommon(vm, true); }

// As Sfr31SetTextOnObject, for a UTF-8 string; a TextField also has its html flag (+0xfc bit 1) synced to the request.
// MS2-FUNCTIONAL 0x14252a230: behavior-equivalent recovery; codegen differs from exe
// @0x14252a230
bool Sfr31SetTextOnObjectUtf8(UPInt* self, UPInt obj, const char* text, bool html)
{
    UPInt a = Sfr31Rd(obj, 0x20);
    if ((*reinterpret_cast<SInt32*>(a + 0x70) - 0x11U >= 0xc) || ((static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<UInt8*>(a + 0x68) >> 5)) & 1) == 0))
        return false;
    TextField* tf = *reinterpret_cast<TextField**>(obj + 0x58);
    typedef SInt32 (*Kind)(void*);
    if (reinterpret_cast<Kind>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(tf), 0), 0x258))(tf) != 4)
    {
        struct RawGfxValue { UPInt iface; UInt32 type; const char* str; } v = { 0, 6, text };
        typedef char (*Set)(void*, UPInt, const char*, void*, SInt32);
        char r = reinterpret_cast<Set>(Sfr31Rd(self[0], 0x28))(self, obj, html ? "htmlText" : "text", &v, 1);
        if ((v.type >> 6 & 1) != 0)
        {
            typedef void (*Rel)(void*, void*, const char*);
            reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(v.iface, 0), 0x10))(reinterpret_cast<void*>(v.iface), &v, v.str);
        }
        return r != 0;
    }
    UInt32& flags = *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(tf) + 0xfc);
    if (!html)
        flags &= 0xfffffffd;
    else
        flags |= 2;
    tf->SetTextValue(text, html, true);
    return true;
}

// newarray: a new Array filled from the n values on the operand stack, pushed.
// MS2-FUNCTIONAL 0x14253c0f0: behavior-equivalent recovery; codegen differs from exe
// @0x14253c0f0
void Sfr31ExecNewArray(UPInt vm, UInt32 n)
{
    UPInt traits = Sfr31Rd(Sfr31Rd(vm, 0x238), 0xc0);
    UPInt arr;
    FUN_14241a500(traits, &arr, traits);
    FUN_14241d980(arr + 0x38, vm + 0x48, n);
    Value v(Pickable<Object>(reinterpret_cast<Object*>(arr)));
    ExecPushCopy(reinterpret_cast<VM*>(vm), v);
}

// newcatch: a new Catch scope object for the exception handler (file a, exception info b), pushed on the operand stack.
// MS2-FUNCTIONAL 0x14253c200: behavior-equivalent recovery; codegen differs from exe
// @0x14253c200
void Sfr31ExecPushInterfaceInstance(UPInt vm, UPInt a, UPInt b)
{
    UPInt owner = Sfr31Rd(Sfr31Rd(vm, 0x240), 0xc0);
    UPInt tbl = Sfr31Rd(owner, 0x80);
    if (tbl == 0)
    {
        typedef void (*Init)(UPInt);
        reinterpret_cast<Init>(Sfr31Rd(Sfr31Rd(owner, 0), 0x68))(owner);
        tbl = Sfr31Rd(owner, 0x80);
    }
    // FUN_14241b920 builds the catch scope's traits; the exe makes a Catch instance of them (0x14241a5b0)
    SPtr<InstanceTraits::fl::Catch> tr;
    FUN_14241b920(tbl, &tr, a, b);
    Value v(tr->MakeInstance(*tr));
    ExecPushCopy(reinterpret_cast<VM*>(vm), v);
}


// ---- batch 20: raw models of the ArrayDataBase Reserve / ResizeNoConstruct / Resize instances (Data +0, Size +8, Capacity +0x10)
// Kinds of element teardown run by the shrinking path.
enum { Sfr31ElNone, Sfr31ElStrNode, Sfr31ElStrNodeTag, Sfr31ElRcFree, Sfr31ElObj, Sfr31ElValue, Sfr31ElFree, Sfr31ElSPtr };

static void Sfr31ArrReserve(UPInt* a, const void* addr, UPInt n, UPInt esz, UInt32 id, MemoryHeap* dh)
{
    UPInt cap = 0;
    if (n != 0)
    {
        cap = (n + 3) & ~static_cast<UPInt>(3);
        if (a[0] != 0)
        {
            a[0] = reinterpret_cast<UPInt>(Memory::Realloc(reinterpret_cast<void*>(a[0]), cap * esz));
            a[2] = cap;
            return;
        }
        if (dh != 0)
            a[0] = reinterpret_cast<UPInt>(Memory::AllocInHeap(dh, cap * esz, AllocInfo(id, 0, 0)));
        else
            a[0] = reinterpret_cast<UPInt>(Memory::AllocAutoHeap(addr, cap * esz, AllocInfo(id, 0, 0)));
    }
    else if (a[0] != 0)
    {
        Memory::Free(reinterpret_cast<void*>(a[0]));
        a[0] = 0;
    }
    a[2] = cap;
}

static void Sfr31ArrTearDown(UPInt slot, int kind)
{
    const UPInt el = Sfr31Rd(slot, 0);
    switch (kind)
    {
    case Sfr31ElStrNode:
    {
        int* rc = reinterpret_cast<int*>(el + 0x18);
        if (--*rc == 0)
            reinterpret_cast<ASStringNode*>(el)->ReleaseNode();
        break;
    }
    case Sfr31ElStrNodeTag:
        if (el != 0)
        {
            if ((el & 1) == 0)
            {
                int* rc = reinterpret_cast<int*>(el + 0x18);
                if (--*rc == 0)
                    reinterpret_cast<ASStringNode*>(el)->ReleaseNode();
            }
            else
                Sfr31Wr(slot, 0, el - 1);
        }
        break;
    case Sfr31ElRcFree:
        if (el != 0 && --*reinterpret_cast<int*>(el) == 0)
            Memory::Free(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElObj:
        if (el != 0)
            FUN_14257dcd0(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElFree:
        Memory::Free(reinterpret_cast<void*>(el));
        break;
    case Sfr31ElSPtr:   // ConstructorMov<SPtr<T>>::DestructArray: a killed (tagged) pointer is untagged, not released
        reinterpret_cast<SPtr<GASRefCountBase>*>(slot)->~SPtr();
        break;
    default:
        break;
    }
}

// Shrink (destroy the tail, release spare capacity) or grow (reserve n + n/4); Size is set to n.
static void Sfr31ArrResizeNC(UPInt* a, const void* addr, UPInt n, UPInt esz, UInt32 id, MemoryHeap* dh, int kind)
{
    const UPInt old = a[1];
    UPInt want = n;
    bool doReserve;
    if (n < old)
    {
        if (kind == Sfr31ElValue)
        {
            AS3::Value* v = reinterpret_cast<AS3::Value*>(a[0]);
            for (UPInt i = old; i > n; --i)
                v[i - 1].~Value();
        }
        else
        {
            for (UPInt i = old; i > n; --i)
                Sfr31ArrTearDown(a[0] + (i - 1) * esz, kind);
        }
        doReserve = n < (a[2] >> 1);
    }
    else
    {
        doReserve = n >= a[2];
        want = n + (n >> 2);
    }
    if (doReserve)
        Sfr31ArrReserve(a, addr, want, esz, id, dh);
    a[1] = n;
}

// ---- batch 21
static inline void Sfr31ReleaseStr(UPInt node)
{
    int* rc = reinterpret_cast<int*>(node + 0x18);
    if (--*rc == 0)
        reinterpret_cast<ASStringNode*>(node)->ReleaseNode();
}

typedef void (*Sfr31VFn1)(UPInt);
typedef void (*Sfr31VFn3)(UPInt, UPInt, UPInt);

namespace {
// Ptr<ShapeMeshProvider> (RefCountBase at +0x10 of the provider): operator= AddRefs the new one, Releases the old one.
struct Sfr31ShapePtr
{
    UPInt pObject;
    void operator=(UPInt p)
    {
        if (p != 0)
            reinterpret_cast<Sfr31VFn1>(Sfr31Rd(Sfr31Rd(p + 0x10, 0), 8))(p + 0x10);
        if (pObject != 0)
            reinterpret_cast<Sfr31VFn1>(Sfr31Rd(Sfr31Rd(pObject + 0x10, 0), 0x10))(pObject + 0x10);
        pObject = p;
    }
};
struct Sfr31TreeShapeNodeData { UInt8 Pad[0x90]; Sfr31ShapePtr pShape; };

struct Sfr31TreeShapeEntry
{
    UInt8 Pad[0x28];
    void* pPropagateNext;
    bool hasPropagate() const { return pPropagateNext != 0; }
    void SetShape(UPInt pshape);
};
}

// ShapeMeshProvider holder of a TreeShape (render tree entry): swap the provider, queue the entry for propagation.
// @0x142528eb0
void Sfr31TreeShapeEntry::SetShape(UPInt pshape)
{
    Sfr31TreeShapeNodeData* pdata = static_cast<Sfr31TreeShapeNodeData*>(FUN_142581a40(this, 0x400));
    pdata->pShape = pshape;
    if (!hasPropagate())
        FUN_142581430(this);
}

// ShapeObject::SetRatio: only when its render node is a shape node.
// MS2-FUNCTIONAL 0x142528da0: raw-offset model; codegen differs from the exe
// @0x142528da0
void Sfr31ShapeObjectSetRatio(UPInt self, float ratio)
{
    const UPInt node = FUN_1425f26c0(reinterpret_cast<void*>(self));
    if (node == 0)
        return;
    const UPInt page = node & ~static_cast<UPInt>(0xfff);
    const UInt32 idx = static_cast<UInt32>(static_cast<SPInt>(node - page - 0x38) / 0x38);
    const UPInt info = Sfr31Rd(Sfr31Rd(page, 0x20), 0x28 + static_cast<UPInt>(idx) * 8);
    if (*reinterpret_cast<const SInt16*>(info + 8) == 3)
    {
        UPInt data = reinterpret_cast<UPInt>(FUN_142581a40(reinterpret_cast<void*>(Sfr31Rd(self, 0x48)), 0x10));
        *reinterpret_cast<float*>(data + 0x98) = ratio;
    }
}

// An object value whose traits are of builtin type ty and not a user subclass (flag bit 5 clear).
static inline bool Sfr31IsObjectOfTraitsType(UPInt v, int ty)
{
    if ((*reinterpret_cast<const UInt32*>(v) & 0x1f) - 0xc <= 3)
    {
        const UPInt o = Sfr31Rd(v, 0x10);
        if (o != 0)
        {
            const UPInt tr = Sfr31Rd(o, 0x20);
            if (*reinterpret_cast<const int*>(tr + 0x70) == ty
                && (static_cast<UInt8>(~static_cast<UInt8>(*reinterpret_cast<const UInt8*>(tr + 0x68) >> 5)) & 1) != 0)
                return true;
        }
    }
    return false;
}

// checkfilter: the top of the operand stack must be an XML or XMLList instance, else TypeError 1123.
// MS2-FUNCTIONAL 0x142536ab0: behavior-equivalent recovery; codegen differs from exe
// @0x142536ab0
void Sfr31ExecCheckFilter(UPInt vm)
{
    const UPInt top = Sfr31Rd(vm, 0x50);
    if (Sfr31IsObjectOfTraitsType(top, 0xd) || Sfr31IsObjectOfTraitsType(top, 0xe))   // IsXMLObject || IsXMLListObject
        return;
    const UPInt tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(*reinterpret_cast<VM*>(vm), *reinterpret_cast<const Value*>(top)));
    UPInt name = 0;
    typedef UPInt* (*GetName)(UPInt, UPInt*);
    UPInt* p = reinterpret_cast<GetName>(Sfr31Rd(Sfr31Rd(tr, 0), 0x38))(tr, &name);
    UPInt err[2];
    FUN_1424d7850(err, 0x463, reinterpret_cast<void*>(vm), *reinterpret_cast<const char* const*>(*p));
    FUN_14252ecb0(reinterpret_cast<void*>(vm), err, &fl::TypeErrorCI);
    Sfr31ReleaseStr(err[1]);
    Sfr31ReleaseStr(name);
}

// Push the elements [start, start + count) of the array storage (clamped to its length) into an interface object.
// MS2-FUNCTIONAL 0x142531550: behavior-equivalent recovery; codegen differs from exe
// @0x142531550
void Sfr31ArrayToGfxValues(UPInt self, UPInt arr, UPInt out, UInt32 start, int count)
{
    SparseArray* sa = reinterpret_cast<SparseArray*>(arr + 0x38);
    const UInt32 len = static_cast<UInt32>(sa->GetSize());
    const UPInt root = Sfr31Rd(Sfr31Rd(self, 8), 0x18);
    if (start >= len)
        return;
    if (count < 0)
        count = static_cast<int>(len - start);
    UPInt gv[3] = { 0, 0, 0 };
    UInt32 end = start + static_cast<UInt32>(count);
    if (len < end)
        end = len;
    for (UInt32 i = start; i < end; ++i)
    {
        const Value& v = sa->At(i);
        FUN_1424e42c0(root, &v, gv);
        reinterpret_cast<Sfr31VFn3>(Sfr31Rd(Sfr31Rd(out, 0), 8))(out, i, reinterpret_cast<UPInt>(gv));
    }
    if ((reinterpret_cast<UInt32*>(gv)[2] >> 6) & 1)
    {
        typedef void (*Rel)(UPInt, UPInt*, UPInt);
        reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(gv[0], 0), 0x10))(gv[0], gv, gv[2]);
    }
}

// Tracer: push the constant-pool string index as a String value (the empty string becomes a null object).
// MS2-FUNCTIONAL 0x14253f690: behavior-equivalent recovery; codegen differs from exe
// @0x14253f690
void Sfr31TracePushString(State* st, UInt32 index)
{
    const UPInt tracer = Sfr31Rd(reinterpret_cast<UPInt>(st), 0);
    FUN_14251fcd0(tracer, index);
    UPInt lit[2];
    FUN_142545310(Sfr31Rd(TrFile(tracer), 0x70) + static_cast<UPInt>(index) * 8, lit);
    ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(Sfr31Rd(TrVM(tracer), 0x10), 0x1e8));
    ASStringNode* node = mgr->CreateStringNode(reinterpret_cast<const char*>(lit[0]), lit[1]);
    UPInt raw[4] = { 10, 0, 0, 0 };
    UInt32* kind = reinterpret_cast<UInt32*>(raw);
    int* rc = reinterpret_cast<int*>(reinterpret_cast<UPInt>(node) + 0x18);
    const int base = *rc;
    *rc = base + 1;
    if (reinterpret_cast<UPInt>(node) == Sfr31Rd(reinterpret_cast<UPInt>(node), 8) + 0x68)
    {
        *kind = 0xc;
        raw[2] = 0;
        raw[3] = lit[1];
    }
    else
    {
        *rc = base + 2;
        raw[2] = reinterpret_cast<UPInt>(node);
    }
    StV(st).OpStack().PushBack(*reinterpret_cast<const Value*>(raw));
    reinterpret_cast<Value*>(raw)->~Value();
    Sfr31ReleaseStr(reinterpret_cast<UPInt>(node));
}

// Set the owned object of a holder {obj, ownsFlag}: destroy the previous owned object (a value array plus its names).
// MS2-FUNCTIONAL 0x142524290: behavior-equivalent recovery; codegen differs from exe
// @0x142524290
void Sfr31SetOwnedObject(UPInt* holder, UPInt np, char own)
{
    const UPInt old = holder[0];
    if (old != np)
    {
        if (old != 0 && static_cast<char>(holder[1]) != 0)
        {
            *reinterpret_cast<char*>(&holder[1]) = 0;
            Sfr31ReleaseStr(Sfr31Rd(old, 0x38));
            UPInt* names = reinterpret_cast<UPInt*>(old + 0x20);
            for (UPInt i = names[1]; i > 0; --i)
                Sfr31ReleaseStr(Sfr31Rd(names[0], (i - 1) * 8));
            if (names[0] != 0)
                Memory::Free(reinterpret_cast<void*>(names[0]));
            Value* vals = reinterpret_cast<Value*>(Sfr31Rd(old, 8));
            for (UPInt i = Sfr31Rd(old, 0x10); i > 0; --i)
                vals[i - 1].~Value();
            Memory::Free(reinterpret_cast<void*>(Sfr31Rd(old, 8)));
            Memory::Free(reinterpret_cast<void*>(old));
        }
        holder[0] = np;
    }
    *reinterpret_cast<char*>(&holder[1]) = (np != 0 && own != 0) ? 1 : 0;
}
// ---- batch 22
static void Sfr31PushByte(UPInt* a, UInt8 b)
{
    const UPInt n = a[1] + 1;
    if (n < a[1])
    {
        if (n >= (a[2] >> 1))
            goto store;
    }
    else if (n < a[2])
        goto store;
    // ArrayDataBase<UByte, AllocatorGH>::Reserve (0x142522c70): the global heap, not the array's own
    Sfr31ArrReserve(a, a, n < a[1] ? n : n + (n >> 2), 1, 2, Memory::pGlobalHeap);
store:
    a[1] = n;
    *reinterpret_cast<UInt8*>(a[0] + n - 1) = b;
}

// Variable-length integer writer: the low two bits of the first byte give the byte count - 1.
// MS2-FUNCTIONAL 0x142531bf0: raw-offset model; codegen differs from the exe
// @0x142531bf0
UPInt Sfr31WriteVarint(UPInt** arr, UInt32 v)
{
    UPInt* a = *arr;
    const UInt8 b0 = static_cast<UInt8>(v << 2);
    if (v < 0x40)
    {
        Sfr31PushByte(a, b0);
        return 1;
    }
    if (v < 0x4000)
    {
        Sfr31PushByte(a, b0 | 1);
        Sfr31PushByte(*arr, static_cast<UInt8>(v >> 6));
        return 2;
    }
    if (v < 0x400000)
    {
        Sfr31PushByte(a, b0 | 2);
        Sfr31PushByte(*arr, static_cast<UInt8>(v >> 6));
        Sfr31PushByte(*arr, static_cast<UInt8>(v >> 14));
        return 3;
    }
    Sfr31PushByte(a, b0 | 3);
    Sfr31PushByte(*arr, static_cast<UInt8>(v >> 6));
    Sfr31PushByte(*arr, static_cast<UInt8>(v >> 14));
    Sfr31PushByte(*arr, static_cast<UInt8>(v >> 22));
    return 4;
}

// Record writer: emits a leading 0 byte on the first record, then a 1 tag and three varints.
// MS2-FUNCTIONAL 0x14252c8b0: raw-offset model; codegen differs from the exe
// @0x14252c8b0
void Sfr31WriteRecord3(UPInt self, UInt32 a, UInt32 b, UInt32 c)
{
    UPInt* arr = reinterpret_cast<UPInt*>(Sfr31Rd(self, 0x48));
    UPInt* cur = arr;
    if (*reinterpret_cast<int*>(self + 0x10) == 0)
    {
        Sfr31PushByte(arr, 0);
        *reinterpret_cast<int*>(self + 0x10) = 1;
    }
    Sfr31PushByte(arr, 1);
    Sfr31WriteVarint(&cur, a);
    Sfr31WriteVarint(&cur, b);
    Sfr31WriteVarint(&cur, c);
    *reinterpret_cast<int*>(self + 0x10) = 2;
}

// Evaluates a virtual getter into a scratch Value; a non-null result is handed to FUN_1424e0860, else the out slot is cleared.
// MS2-FUNCTIONAL 0x142531f40: raw-offset model; codegen differs from the exe
// @0x142531f40
UPInt Sfr31FetchOrClear(UPInt self, UPInt* out, UPInt src, UInt32 arg, UPInt arg2)
{
    // the AS3 Value is 0x20 bytes (its value union holds two pointers): Construct writes all of it, so a 0x18-byte
    // buffer let the second value word overwrite the /GS cookie the array got (the exe's frame has no cookie)
    struct { UInt32 flags, pad; UPInt bonus, v0, v1; } val = {};
    UInt32* tmp = &val.flags;
    typedef void (*Fn)(UPInt, void*, UInt32, UPInt, int);
    reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(src, 0), 0x60))(src, &val, arg, arg2, 1);
    UPInt result;
    const UInt32 kind = tmp[0] & 0x1f;
    if (*reinterpret_cast<UInt8*>(self + 0x180) == 0 && kind != 0 && (kind - 0xc > 3 || *reinterpret_cast<UPInt*>(&tmp[4]) != 0))
    {
        FUN_1424e0860(out, *reinterpret_cast<UPInt*>(&tmp[4]));
        result = 1;
    }
    else
    {
        UPInt old = *out;
        if (old != 0)
        {
            if ((old & 1) == 0 && (*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0)
            {
                *reinterpret_cast<UInt32*>(old + 0x10) -= 1;
                FUN_1423dfa20(reinterpret_cast<void*>(old));
            }
            *out = 0;
        }
        *reinterpret_cast<UInt8*>(self + 0x180) = 0;
        result = 0;
    }
    if (kind > 9)
    {
        if (((tmp[0] >> 9) & 1) == 0)
            FUN_142521f00(tmp);
        else
        {
            int* rc = *reinterpret_cast<int**>(&tmp[4]);
            if (--*rc == 0)
                Memory::pGlobalHeap->Free(rc);
        }
    }
    return result;
}

// Traits::StoreScopeStack: appends copies of scope entries [start, n) onto the stored scope array.
// MS2-FUNCTIONAL 0x14252cad0: raw-offset model; codegen differs from the exe
// @0x14252cad0
void Sfr31StoreScopeStack(UPInt self, UPInt start, UPInt* src)
{
    const UPInt n = src[1];
    UPInt* dst = reinterpret_cast<UPInt*>(self + 0xa0);
    if (dst[2] < dst[1] + n)
        Sfr31ArrReserve(dst, reinterpret_cast<void*>(dst[3]), dst[1] + n, 0x20, 2, reinterpret_cast<MemoryHeap*>(dst[3]));
    for (UPInt i = start; i < n; ++i)
    {
        const AS3::Value* s = reinterpret_cast<const AS3::Value*>(src[0]) + i;
        FUN_1424201a0(dst, reinterpret_cast<void*>(dst[3]), dst[1] + 1);
        new (reinterpret_cast<AS3::Value*>(dst[0]) + dst[1] - 1) AS3::Value(*s);
    }
}

// exec_esc_xattr: converts the top of stack to a string and replaces it with its XML-escaped form.
// MS2-FUNCTIONAL 0x142538700: behavior-equivalent recovery; codegen differs from exe
// @0x142538700
void Sfr31ExecEscXAttr(UPInt vm)
{
    const UPInt mgr = Sfr31Rd(Sfr31Rd(vm, 0x10), 0x1e8);
    AS3::Value* top = reinterpret_cast<AS3::Value*>(Sfr31Rd(vm, 0x50));
    UPInt tmpNode = 0;
    ASString str(reinterpret_cast<ASStringNode*>(mgr + 0x40));
    const bool ok = *FUN_1424f1390(top, &tmpNode, &str);
    if (ok)
        *top = str;
    if (ok)
    {
        StringBuffer buf(Memory::pGlobalHeap);
        ASString cur(reinterpret_cast<ASStringNode*>(Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10)));
        Instances::fl::XML::EscapeElementValue(buf, cur);
        const char* c = buf.ToCStr();
        ASString res(reinterpret_cast<ASStringManager*>(mgr)->CreateStringNode(c ? c : "", buf.GetSize()));
        *top = res;
    }
}
// ---- batch 23
// Native call whose first argument must be a non-null object: reports TypeError 1009/1010 otherwise, then dispatches through the object.
// MS2-FUNCTIONAL 0x142533fd0: raw-offset model; codegen differs from the exe
// @0x142533fd0
void Sfr31CallOnObjectArg(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, argc);
    const UInt32* a0 = reinterpret_cast<const UInt32*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8), 8));
    const UInt32 k = (a0[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(a0), 0x10);
    if ((a0[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        const UInt32 id = (k < 4 ? (obj != 0) : 1u) + 0x3f1;
        VM::Error e(static_cast<VM::ErrorID>(id), vm);
        vm.ThrowTypeError(e);
    }
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt o = Sfr31Rd(reinterpret_cast<UPInt>(a0), 0x10);
        typedef void (*Fn)(UPInt, const Value*, const void*, UInt32, void*);
        const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
        void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(o, 0), 0x50))(o, &Value::GetUndefined(), a0, argc, args);
    }
    FUN_1424de9e0(raBuf);
}

// The top of the operand stack is converted to an int index and popped; the new top's object is queried at that index and
// the top replaced by the resulting uint.
// MS2-FUNCTIONAL 0x14253abd0: behavior-equivalent recovery; codegen differs from exe
// @0x14253abd0
void Sfr31ExecIndexedQuery(UPInt vm)
{
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(vm, 0x50));
    UInt8 okBuf[8];
    long out;
    const bool ok = *FUN_1424f0d30(top, okBuf, &out) != 0;
    UInt32 idx = 0;
    if (ok)
    {
        top->SetSInt32(static_cast<SInt32>(out));
        idx = *reinterpret_cast<const UInt32*>(reinterpret_cast<UPInt>(top) + 0x10);
    }
    top->~Value();
    Sfr31Wr(vm, 0x50, Sfr31Rd(vm, 0x50) - 0x20);
    if (ok)
    {
        const UPInt cur = reinterpret_cast<UPInt>(top) - 0x20;
        const UPInt o = Sfr31Rd(cur, 0x10);
        typedef const UInt32* (*Fn)(UPInt, void*, UInt32);
        const UInt32* r = reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(o, 0), 0x88))(o, okBuf, idx);
        Value res(static_cast<UInt32>(*r));
        reinterpret_cast<Value*>(cur)->Assign(res);
    }
}
// ---- batch 24
// Value -> Boolean conversion used by the tracer, in place.
// MS2-FUNCTIONAL 0x14252f4f0: behavior-equivalent recovery; codegen differs from exe
// @0x14252f4f0
void Sfr31ValueToBool(Value* v)
{
    const UInt32 kind = *reinterpret_cast<const UInt32*>(v) & 0x1f;
    const UPInt p = reinterpret_cast<UPInt>(v);
    bool r = false;
    switch (kind)
    {
    case 1:
        r = *reinterpret_cast<const UInt8*>(p + 0x10) != 0;
        break;
    case 2:
    case 3:
        r = *reinterpret_cast<const int*>(p + 0x10) != 0;
        break;
    case 4:
    {
        const UInt64 bits = *reinterpret_cast<const UInt64*>(p + 0x10);
        const bool nan = (bits & 0x7ff0000000000000ull) == 0x7ff0000000000000ull && (bits & 0xfffffffffffffull) != 0;
        r = !nan && (bits & 0x7fffffffffffffffull) != 0;
        break;
    }
    case 5:
    case 7:
    case 0x10:
    case 0x11:
        r = true;
        break;
    case 10:
    {
        const UPInt node = Sfr31Rd(p, 0x10);
        r = node != 0 && *reinterpret_cast<const int*>(node + 0x20) != 0;
        break;
    }
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
        r = Sfr31Rd(p, 0x10) != 0;
        break;
    default:
        break;
    }
    v->SetBool(r);
}

static bool Sfr31SwapChildrenTail(UPInt owner, UPInt i1, UPInt i2)
{
    if (i1 >= Sfr31Rd(owner, 0xe0) || i2 >= Sfr31Rd(owner, 0xe0))
        return false;
    if (!FUN_1425fb480(reinterpret_cast<void*>(owner + 0xd8), reinterpret_cast<void*>(owner), i1, i2))
        return false;
    const UPInt list = Sfr31Rd(owner, 0xd8);
    const UPInt c1 = Sfr31Rd(list, i1 * 0x10);
    const UPInt c2 = Sfr31Rd(list, i2 * 0x10);
    typedef void (*Fn)(UPInt, UInt32);
    if (c1 != 0)
    {
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(c1, 0), 0x188))(c1, 0);
        *reinterpret_cast<UInt32*>(c1 + 0x30) = 0;
        *reinterpret_cast<UInt32*>(c1 + 0x2c) = 0xffffffffu;
    }
    if (c2 != 0)
    {
        reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(c2, 0), 0x188))(c2, 0);
        *reinterpret_cast<UInt32*>(c2 + 0x30) = 0;
        *reinterpret_cast<UInt32*>(c2 + 0x2c) = 0xffffffffu;
    }
    *reinterpret_cast<UInt8*>(owner + 0x100) |= 3;
    typedef UPInt (*Fn2)(UPInt);
    UPInt avm = 0;
    if (*reinterpret_cast<const SInt8*>(c1 + 0x6a) < 0)
    {
        const UPInt sub = c1 + static_cast<UPInt>(*reinterpret_cast<const UInt8*>(c1 + 0x6d)) * 4;
        const UPInt r = reinterpret_cast<Fn2>(Sfr31Rd(Sfr31Rd(sub, 0), 8))(sub);
        avm = r != 0 ? r - 0x30 : 0;
        FUN_142517ed0(reinterpret_cast<void*>(avm));
    }
    if (*reinterpret_cast<const SInt8*>(c2 + 0x6a) < 0)
    {
        const UPInt sub = c2 + static_cast<UPInt>(*reinterpret_cast<const UInt8*>(c2 + 0x6d)) * 4;
        const UPInt r = reinterpret_cast<Fn2>(Sfr31Rd(Sfr31Rd(sub, 0), 8))(sub);
        FUN_142517ed0(reinterpret_cast<void*>(r != 0 ? r - 0x30 : 0));
    }
    return true;
}

// AvmDisplayObjContainer::SwapChildren: swaps two children of the display list.
// MS2-FUNCTIONAL 0x14252e590: raw-offset model; codegen differs from the exe
// @0x14252e590
bool Sfr31SwapChildren(UPInt self, UPInt ch1, UPInt ch2)
{
    const UPInt owner = Sfr31Rd(self, 0x18);
    const UPInt list = owner + 0xd8;
    const UInt32 i1 = static_cast<UInt32>(FUN_1425f9200(reinterpret_cast<void*>(Sfr31Rd(self, 0x18) + 0xd8), reinterpret_cast<void*>(ch1)));
    const UInt32 i2 = static_cast<UInt32>(FUN_1425f9200(reinterpret_cast<void*>(list), reinterpret_cast<void*>(ch2)));
    return Sfr31SwapChildrenTail(owner, i1, i2);
}

// AvmDisplayObjContainer::SwapChildrenAt
// MS2-FUNCTIONAL 0x14252e6d0: raw-offset model; codegen differs from the exe
// @0x14252e6d0
bool Sfr31SwapChildrenAt(UPInt self, UInt32 i1, UInt32 i2)
{
    return Sfr31SwapChildrenTail(Sfr31Rd(self, 0x18), i1, i2);
}
// ---- batch 25
// Strict equality of two values (same kind: payload compare; mixed Int/UInt/Number: numeric compare).
// MS2-FUNCTIONAL 0x14252cbf0: behavior-equivalent recovery; codegen differs from exe
// @0x14252cbf0
bool Sfr31StrictEquals(const UInt32* a, const UInt32* b)
{
    const UInt32 ka = a[0] & 0x1f;
    const UInt32 kb = b[0] & 0x1f;
    const UPInt pa = reinterpret_cast<UPInt>(a);
    const UPInt pb = reinterpret_cast<UPInt>(b);
    if (ka != kb)
    {
        if (ka - 2 > 2 || kb - 2 > 2)
            return false;
        if (ka - 2 < 2)
        {
            if (kb == 2)
                return static_cast<int>(b[4]) >= 0 && a[4] == b[4];
            if (kb == 4)
            {
                const double d = static_cast<double>(static_cast<UInt64>(a[4]));
                const double e = *reinterpret_cast<const double*>(pb + 0x10);
                return d == e;
            }
        }
        else
        {
            const double d = kb == 2 ? static_cast<double>(static_cast<int>(b[4])) : static_cast<double>(static_cast<UInt64>(b[4]));
            return *reinterpret_cast<const double*>(pa + 0x10) == d;
        }
    }
    switch (ka)
    {
    case 0:
        return true;
    case 1:
        return static_cast<char>(a[4]) == static_cast<char>(b[4]);
    case 2:
    case 3:
        return a[4] == b[4];
    case 4:
        return *reinterpret_cast<const double*>(pa + 0x10) == *reinterpret_cast<const double*>(pb + 0x10);
    case 5:
    case 10:
    case 11:
        return Sfr31Rd(pa, 0x10) == Sfr31Rd(pb, 0x10);
    case 7:
        return a[4] == b[4] && Sfr31Rd(pa, 0x18) == Sfr31Rd(pb, 0x18);
    case 0x10:
        return Sfr31Rd(pa, 0x18) == Sfr31Rd(pb, 0x18) && Sfr31Rd(pa, 0x10) == Sfr31Rd(pb, 0x10);
    case 0x11:
        return Sfr31Rd(pa, 0x18) == Sfr31Rd(pb, 0x18) && a[4] == b[4];
    case 6:
    case 8:
    case 9:
        return false;
    default:
        return ka <= 0x11 && Sfr31Rd(pa, 0x10) == Sfr31Rd(pb, 0x10);
    }
}

// Tracer ops taking the two counts of a call and pushing an object value.
// MS2-FUNCTIONAL 0x142533cb0: behavior-equivalent recovery; codegen differs from exe
// @0x142533cb0
void Sfr31TraceCallPushObject(State* st, UInt32 a, UInt32 b)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), a);
    FUN_14251fcd0(s.Tracer(), b);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, b);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
    popped.Get().~Value();
}

// MS2-FUNCTIONAL 0x142535540: behavior-equivalent recovery; codegen differs from exe
// @0x142535540
void Sfr31TraceCallPushObjectB(State* st, UInt32 a, UInt32 b)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), a);
    FUN_14251fcd0(s.Tracer(), b);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, b);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x1f8));
    s.OpStack().PushBack(t.Get());
    popped.Get().~Value();
}

struct Sfr31MnCtx
{
    UPInt vm;
    State* st;
    int pops;
};

static inline const Abc::Multiname& Sfr31MnEntry(UPInt abcLink, UInt32 idx)
{
    const UPInt file = TrRd(abcLink, 0x28);
    return *reinterpret_cast<const Abc::Multiname*>(idx == 0 ? file + 0xe8 : static_cast<UPInt>(idx) * 0x10 + TrRd(file, 0xb8));
}

// Tracer op with a multiname: notes the name operand(s), pops the object and pushes an object value.
// MS2-FUNCTIONAL 0x142537f00: behavior-equivalent recovery; codegen differs from exe
// @0x142537f00
void Sfr31TraceMnPopPush(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++ctx.pops;
    TrTraitsScratch t;
    t.SetTraits(TrITraits(s.Tracer(), 0x210));
    s.OpStack().PushBack(t.Get());
    popped.Get().~Value();
}

// Tracer op with a multiname that pops the object and the value without pushing.
// MS2-FUNCTIONAL 0x14253b640: behavior-equivalent recovery; codegen differs from exe
// @0x14253b640
void Sfr31TraceMnPop2(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    TrPopped first;
    FUN_14251cd30(st, &first.Get());
    ++ctx.pops;
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    TrPopped second;
    FUN_14251cd30(st, &second.Get());
    ++ctx.pops;
    second.Get().~Value();
    first.Get().~Value();
}
// ---- batch 26
static void Sfr31ThrowIfNotObject(VM& vm, const UInt32* v)
{
    const UInt32 k = (v[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    if ((v[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>((k < 4 ? (obj != 0) : 1u) + 0x3f1), vm);
        vm.ThrowTypeError(e);
    }
}

// Constructs the named class into a scratch value; a non-null object result is moved into *out, else *out is cleared.
// MS2-FUNCTIONAL 0x142532130: raw-offset model; codegen differs from the exe
// @0x142532130
UInt8* Sfr31ConstructOrClear(UPInt self, UInt8* ret, UPInt* out, const char* gname, UInt32 argc, const Value* argv)
{
    Value tmp;
    reinterpret_cast<VM*>(self)->Construct(gname, tmp, argc, argv, true);
    const UInt32 kind = *reinterpret_cast<const UInt32*>(&tmp) & 0x1f;
    if (*reinterpret_cast<UInt8*>(self + 0x180) == 0 && kind != 0 &&
        (kind - 0xc > 3 || Sfr31Rd(reinterpret_cast<UPInt>(&tmp), 0x10) != 0))
    {
        FUN_1424e0860(out, Sfr31Rd(reinterpret_cast<UPInt>(&tmp), 0x10));
        *ret = 1;
    }
    else
    {
        UPInt old = *out;
        if (old != 0)
        {
            if ((old & 1) == 0 && (*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0)
            {
                *reinterpret_cast<UInt32*>(old + 0x10) -= 1;
                FUN_1423dfa20(reinterpret_cast<void*>(old));
            }
            *out = 0;
        }
        *reinterpret_cast<UInt8*>(self + 0x180) = 0;
        *ret = 0;
    }
    return ret;
}

// pushscope: the (non-null) object on top of the operand stack moves onto the scope stack. An undefined or null
// object throws and stays on the operand stack.
// MS2-FUNCTIONAL 0x14253f4e0: behavior-equivalent recovery; codegen differs from exe
// @0x14253f4e0
void Sfr31ExecPushWith(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(vmAddr, 0x50));
    const UInt32 kind = *reinterpret_cast<const UInt32*>(top) & 0x1f;
    if (kind == 0 || (kind - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10) == 0))
    {
        Sfr31ThrowIfNotObject(vm, reinterpret_cast<const UInt32*>(top));
        return;
    }
    vm.ScopeStack.PushBack(Value::GetUndefined());
    UInt32* dst = reinterpret_cast<UInt32*>(vm.ScopeStack.GetDataPtr() + vm.ScopeStack.GetSize() - 1);
    UInt32* src = reinterpret_cast<UInt32*>(top);
    for (int i = 0; i < 8; ++i)
        dst[i] = src[i];
    src[0] = 0;
    top->~Value();
    Sfr31Wr(vmAddr, 0x50, Sfr31Rd(vmAddr, 0x50) - 0x20);
}

// applytype: the first argument must be a Class value; replaces it with the Class returned by its ApplyTypeArgs.
// MS2-FUNCTIONAL 0x142532dc0: raw-offset model; codegen differs from the exe
// @0x142532dc0
void Sfr31CallClassArg(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, argc);
    Value* a0 = reinterpret_cast<Value*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8), 8));
    Sfr31ThrowIfNotObject(vm, reinterpret_cast<const UInt32*>(a0));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        if ((*reinterpret_cast<const UInt32*>(a0) & 0x1f) == 0xd)
        {
            const UPInt o = Sfr31Rd(reinterpret_cast<UPInt>(a0), 0x10);
            const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
            void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
            // Class::ApplyTypeArgs (slot 0xb8) returns a Class&; the exe stores it through Value::Assign(Class*)
            typedef Class& (*Fn)(UPInt, UInt32, void*);
            a0->Assign(&reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(o, 0), 0xb8))(o, cnt, args));
        }
        else
        {
            VM::Error e(static_cast<VM::ErrorID>(0x467), vm);
            vm.ThrowTypeError(e);
        }
    }
    FUN_1424de9e0(raBuf);
}

// Tracer op: replaces the popped value with the instance traits it denotes (primitives collapse to the Object traits).
// MS2-FUNCTIONAL 0x1425331a0: behavior-equivalent recovery; codegen differs from exe
// @0x1425331a0
void Sfr31TraceTopInstanceTraits(State* st)
{
    StV s(st);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    const UPInt p = reinterpret_cast<UPInt>(&popped.Get());
    const UInt32 k = *reinterpret_cast<const UInt32*>(p) & 0x1f;
    UPInt tr = Sfr31Rd(p, 0x10);
    if (k == 9)
        tr = Sfr31Rd(tr, 0xc0);
    else if (k == 0xd)
        tr = Sfr31Rd(Sfr31Rd(tr, 0x20), 0xc0);
    else if (k != 8)
    {
        popped.Get().~Value();
        return;
    }
    if (tr != 0)
    {
        if (FUN_142514a80(s.Tracer(), reinterpret_cast<void*>(tr)))
            tr = Sfr31Rd(Sfr31Rd(TrVM(s.Tracer()), 0x1f8), 0xc0);
        TrTraitsScratch t;
        t.SetTraits(*reinterpret_cast<InstanceTraits::Traits*>(tr));
        s.Top().Assign(t.Get());
    }
    popped.Get().~Value();
}
// ---- batch 27
struct Sfr31RawTraitsVal
{
    UInt32 w0;
    UPInt w1, w2, w3;
};

// Tracer find-property core: resolves the multiname and pushes the property value, or the Object traits when unresolved.
static void Sfr31TraceFindProp(State* st, UInt32 idx, UInt32 fallbackTag)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    UPInt pr[6] = {0, 0, 0, 0, 0, 0};
    UInt8 t1[8], t2[8];
    FUN_142501e80(st, pr, &mn, t1, t2);
    Value& res = *reinterpret_cast<Value*>(&pr[2]);
    const UPInt f = pr[0];
    Sfr31RawTraitsVal fb;
    const Value* push = &res;
    if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
    {
        fb.w0 = fallbackTag;
        fb.w1 = 0;
        fb.w2 = Sfr31Rd(Sfr31Rd(TrVM(s.Tracer()), 0x1f8), 0xc0);
        fb.w3 = 0;
        push = reinterpret_cast<const Value*>(&fb);
    }
    s.OpStack().PushBack(*push);
    res.~Value();
}

// MS2-FUNCTIONAL 0x142538840: behavior-equivalent recovery; codegen differs from exe
// @0x142538840
void Sfr31TraceFindPropA(State* st, UInt32 idx) { Sfr31TraceFindProp(st, idx, 0x48); }

// MS2-FUNCTIONAL 0x142538bc0: behavior-equivalent recovery; codegen differs from exe
// @0x142538bc0
void Sfr31TraceFindPropB(State* st, UInt32 idx) { Sfr31TraceFindProp(st, idx, 8); }

// Tracer op: an operand of a type-describing kind becomes its instance traits, anything else is pushed back as it was.
// MS2-FUNCTIONAL 0x142536dd0: behavior-equivalent recovery; codegen differs from exe
// @0x142536dd0
void Sfr31TraceTypeOperand(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    TrReadArgsRaw args(reinterpret_cast<VM*>(TrVM(s.Tracer())), st, argc);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    const UPInt p = reinterpret_cast<UPInt>(&popped.Get());
    const UInt32 k = *reinterpret_cast<const UInt32*>(p) & 0x1f;
    UPInt tr = Sfr31Rd(p, 0x10);
    bool conv = true;
    if (k == 9)
        tr = Sfr31Rd(tr, 0xc0);
    else if (k == 0xd)
        tr = Sfr31Rd(Sfr31Rd(tr, 0x20), 0xc0);
    else if (k != 8)
        conv = false;
    if (conv)
    {
        Sfr31RawTraitsVal v = {8, 0, tr, 0};
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
    }
    else
        s.OpStack().PushBack(popped.Get());
    popped.Get().~Value();
}
// ---- batch 28
struct Sfr31ExecMnCtx
{
    UPInt vm;
    UPInt stack;
    UPInt file;
};

static inline void Sfr31ThrowIfNullOperand(UPInt vmAddr, const UInt32* v)
{
    const UInt32 k = (v[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    if ((v[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>((k < 4 ? (obj != 0) : 1u) + 0x3f1), *reinterpret_cast<VM*>(vmAddr));
        reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(e);
    }
}

// Takes the Value on top of the operand stack bitwise, without touching refcounts.
static inline void Sfr31TakeTop(UPInt vmAddr, Sfr31RawTraitsVal& out)
{
    const UPInt top = Sfr31Rd(vmAddr, 0x50);
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&out)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(vmAddr, 0x50, top - 0x20);
}

// setproperty: pops the value and the object, resolves the multiname and stores the value.
// MS2-FUNCTIONAL 0x14253b790: raw-offset model; codegen differs from the exe
// @0x14253b790
void Sfr31ExecSetProperty(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Sfr31RawTraitsVal val;
    Sfr31TakeTop(cvm, val);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt st = Sfr31Rd(ctx.stack, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(st)[i];
    Sfr31Wr(ctx.stack, 8, st - 0x20);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UInt8 ret[16];
        *reinterpret_cast<UInt32*>(vmAddr + 0x30) += 1;
        Sfr27SetPropertyOfValue(reinterpret_cast<char*>(ret), reinterpret_cast<VM*>(vmAddr), reinterpret_cast<const Value*>(&obj), &mn, reinterpret_cast<const Value*>(&val));
        *reinterpret_cast<UInt32*>(vmAddr + 0x30) -= 1;
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    reinterpret_cast<Value*>(&val)->~Value();
}

// getsuper: reads the named property of the object on top of the stack through the current frame's super traits.
// MS2-FUNCTIONAL 0x14253a430: raw-offset model; codegen differs from the exe
// @0x14253a430
void Sfr31ExecGetSuper(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    UPInt top = Sfr31Rd(ctx.stack, 8);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(top));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        Sfr31RawTraitsVal obj;
        for (int i = 0; i < 8; ++i)
            reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(top)[i];
        *reinterpret_cast<UInt32*>(top) = 0;
        const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
        const UPInt frame = Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8;
        UInt8 ret[16];
        UInt8* r = FUN_14250ef80(ret, vmAddr, Sfr31Rd(frame, 0), reinterpret_cast<void*>(top), &obj, &mn, 0);
        if (*r == 0)
        {
            VM::Error e(static_cast<VM::ErrorID>(0x40b), *reinterpret_cast<VM*>(vmAddr));
            reinterpret_cast<VM*>(vmAddr)->ThrowReferenceError(e);
        }
        reinterpret_cast<Value*>(&obj)->~Value();
    }
}
// ---- batch 29
// getlex-style resolve: pushes the value the multiname resolves to, or raises a ReferenceError.
// MS2-FUNCTIONAL 0x142538d30: raw-offset model; codegen differs from the exe
// @0x142538d30
void Sfr31ExecGetLex(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) != 0)
        return;
    UPInt pr[6] = {0, 0, 0, 0, 0, 0};
    FUN_142502570(vmAddr, pr, &mn);
    Value& res = *reinterpret_cast<Value*>(&pr[2]);
    const UPInt f = pr[0];
    if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
    {
        VM::Error e(static_cast<VM::ErrorID>(0x429), *reinterpret_cast<VM*>(vmAddr));
        reinterpret_cast<VM*>(vmAddr)->ThrowReferenceError(e);
    }
    else
        ExecPushCopy(reinterpret_cast<VM*>(vmAddr), res);
    res.~Value();
}

typedef UInt8* (*Sfr31VFnDel)(UPInt self, UInt8* ret, const void* obj, const void* mn);
typedef UPInt* (*Sfr31VFnName)(UPInt self, UPInt* out);

// deleteproperty-style op: asks the VM helper object to handle the name; when it declines, pops the operand and raises a TypeError naming the traits.
// MS2-FUNCTIONAL 0x142539230: raw-offset model; codegen differs from the exe
// @0x142539230
void Sfr31ExecDeleteProp(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt obj = Sfr31Rd(ctx.stack, 8);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt helper = Sfr31Rd(vmAddr, 0x40);
        UInt8 ret[16];
        Sfr31VFnDel fn = *reinterpret_cast<Sfr31VFnDel*>(Sfr31Rd(helper, 0) + 0x68);
        if (*fn(helper, ret, reinterpret_cast<const void*>(obj), &mn) == 0)
        {
            Value* top = reinterpret_cast<Value*>(Sfr31Rd(vmAddr, 0x50));
            top->~Value();
            Sfr31Wr(vmAddr, 0x50, Sfr31Rd(vmAddr, 0x50) - 0x20);
            const UPInt tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(*reinterpret_cast<VM*>(vmAddr), *reinterpret_cast<const Value*>(obj)));
            UPInt nameNode = 0;
            Sfr31VFnName nf = *reinterpret_cast<Sfr31VFnName*>(Sfr31Rd(tr, 0) + 0x38);
            UPInt* p = nf(tr, &nameNode);
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d7850(eb, 0x3f8, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(Sfr31Rd(*p, 0)));
            reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
            Sfr31ReleaseStr(nameNode);
        }
    }
}

// initproperty: pops the value and the object, resolves the multiname and initializes the property.
// MS2-FUNCTIONAL 0x14253ffa0: raw-offset model; codegen differs from the exe
// @0x14253ffa0
void Sfr31ExecInitProperty(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Sfr31RawTraitsVal val;
    Sfr31TakeTop(cvm, val);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt st = Sfr31Rd(ctx.stack, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(st)[i];
    Sfr31Wr(ctx.stack, 8, st - 0x20);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UInt8 ret[16];
        Sfr27SetPropertyOfValue(reinterpret_cast<char*>(ret), reinterpret_cast<VM*>(vmAddr), reinterpret_cast<const Value*>(&obj), &mn, reinterpret_cast<const Value*>(&val));
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    reinterpret_cast<Value*>(&val)->~Value();
}
// ---- batch 30
// Tracer op: the popped operand becomes the traits describing its class: the Object traits for a null value, otherwise the
// traits of its dynamic class (or its instance traits when it is a class/function traits holder).
// MS2-FUNCTIONAL 0x14253d160: raw-offset model; codegen differs from the exe
// @0x14253d160
void Sfr31TraceOperandClassTraits(State* st)
{
    StV s(st);
    FUN_14251ccc0(st, 1);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    const UPInt vm = TrVM(s.Tracer());
    const UPInt pv = reinterpret_cast<UPInt>(&popped.Get());
    const UInt32 kind = *reinterpret_cast<const UInt32*>(pv) & 0x1f;
    UPInt tr = 0;
    if (kind == 0)
        tr = Sfr31Rd(vm, 0x278);
    else if (kind == 8 || kind == 9)
        tr = Sfr31Rd(pv, 0x10);
    else
        tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(*reinterpret_cast<VM*>(vm), popped.Get()));
    if (tr != 0 && tr == Sfr31Rd(vm, 0x1f0))
        tr = Sfr31Rd(vm, 0x1f8);
    Sfr31RawTraitsVal v = {0x48, 0, 0, 0};
    if (*reinterpret_cast<const UInt32*>(tr + 0x70) == 10 && ((*reinterpret_cast<const UInt8*>(tr + 0x68) >> 5) & 1) == 0)
        v.w2 = Sfr31Rd(Sfr31Rd(vm, 0x1f8), 0xc0);
    else if ((*reinterpret_cast<const UInt8*>(tr + 0x68) & 1) != 0)
    {
        v.w0 = 8;
        v.w2 = Sfr31Rd(Sfr31Rd(vm, 0x228), 0xc0);
    }
    else
        v.w2 = Sfr31Rd(Sfr31Rd(vm, 0x230), 0xc0);
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
    popped.Get().~Value();
}

// Traces the code of the block containing pos, merging block states, and keeps tracing opcodes until the code ends or a halt is raised.
// MS2-FUNCTIONAL 0x142530220: raw-offset model; codegen differs from the exe
// @0x142530220
void Sfr31TraceBlock(UPInt tr, UPInt pos, UPInt block)
{
    UPInt b = Sfr31Rd(tr, 0x110);
    while (b != 0 && pos < Sfr31Rd(b, 0x20))
        b = Sfr31Rd(b, 0);
    Sfr31Wr(tr, 0x68, b);
    UInt8 buf[8];
    if ((*reinterpret_cast<const UInt8*>(b + 0x10) & 1) == 0)
        FUN_142511b00(tr, reinterpret_cast<UPInt*>(b), reinterpret_cast<UPInt*>(block));
    else if (b != block && *FUN_142516c40(tr, buf, reinterpret_cast<UPInt*>(b), reinterpret_cast<UPInt*>(block)) == 0)
        return;
    if (pos >= Sfr31Rd(tr, 0x58))
        return;
    while (*reinterpret_cast<const UInt8*>(TrVM(tr) + 0x180) == 0)
    {
        const UPInt prev = Sfr31Rd(tr, 0x68);
        for (UPInt p = Sfr31Rd(tr, 0x110); p != 0; p = Sfr31Rd(p, 0))
        {
            if (Sfr31Rd(p, 0x20) <= pos)
            {
                if (Sfr31Rd(p, 0x20) == pos)
                {
                    Sfr31Wr(tr, 0x68, p);
                    if ((*reinterpret_cast<const UInt8*>(p + 0x10) & 1) == 0)
                        FUN_142511b00(tr, reinterpret_cast<UPInt*>(p), reinterpret_cast<UPInt*>(prev));
                    else if (p != prev && *FUN_142516c40(tr, buf, reinterpret_cast<UPInt*>(p), reinterpret_cast<UPInt*>(prev)) == 0)
                        return;
                }
                break;
            }
        }
        FUN_14252c640(tr, &pos);
        if (Sfr31Rd(tr, 0x58) <= pos)
            return;
        FUN_1425212f0(tr, pos);
        const UInt8 op = *reinterpret_cast<const UInt8*>(pos + Sfr31Rd(tr, 0x50));
        ++pos;
        const UPInt state = Sfr31Rd(Sfr31Rd(tr, 0x68), 0x18);
        if (Sfr31TracerCommonOp(tr, op, &pos, state) == 0)
        {
            if (*reinterpret_cast<const UInt8*>(TrVM(tr) + 0x180) != 0)
                return;
            Sfr31StateTraceOp(state, op, &pos);
        }
        if (Sfr31Rd(tr, 0x58) <= pos)
            return;
    }
}
// ---- batch 31
typedef UPInt (*Sfr31VFnGet)(UPInt self);

// Tracer getdescendants: raises a verify error when XML support is absent, else the object operand becomes an XMLList-typed value.
// MS2-FUNCTIONAL 0x1425390a0: raw-offset model; codegen differs from the exe
// @0x1425390a0
void Sfr31TraceGetDescendants(State* st, UInt32 idx)
{
    StV s(st);
    const UPInt vm = TrVM(s.Tracer());
    const UPInt helper = Sfr31Rd(vm, 0x40);
    if (*reinterpret_cast<const UInt8*>(helper + 0x20) == 0)
    {
        VM& v = *reinterpret_cast<VM*>(vm);
        v.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), v, "getdescendants"));
        return;
    }
    FUN_14251fcd0(s.Tracer(), idx);
    const UPInt link = TrAbcLink(s.Tracer());
    Sfr31MnCtx ctx = {TrRd(link, 0x20), st, 0};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(link), Sfr31MnEntry(link, idx));
    ctx.pops += FUN_142520380(&ctx, &mn);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++ctx.pops;
    Sfr31VFnGet fn = *reinterpret_cast<Sfr31VFnGet*>(Sfr31Rd(helper, 0) + 0x98);
    Sfr31RawTraitsVal v = {8, 0, fn(helper), 0};
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
    popped.Get().~Value();
}
// ---- batch 32
// istype-style op: replaces the top value with whether it is an instance of the named class; names resolved at compile time are rejected.
// MS2-FUNCTIONAL 0x14253bbe0: raw-offset model; codegen differs from the exe
// @0x14253bbe0
void Sfr31ExecIsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    const UPInt cfile = Sfr31Rd(file, 0x28);
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    const UPInt nameSlot = Sfr31Rd(cfile, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8;
    if ((flags & 3) == 1 || ((flags >> 2) & 1) != 0)
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        String name(reinterpret_cast<const char*>(sv[0]), sv[1]);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x436, reinterpret_cast<void*>(cvm), name.ToCStr(), "compile time");
        reinterpret_cast<VM*>(cvm)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(cvm, 0x50));
    const UPInt tr = Sfr31ResolveClassTraits(vmAddr, file, entry);
    if (tr == 0)
    {
        UPInt sv[2];
        FUN_142545310(Sfr31Rd(Sfr31Rd(file, 0x28), 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8, sv);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7850(eb, 0x3f6, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(sv[0]));
        reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    else
        top->SetBool(FUN_1425146d0(reinterpret_cast<VM*>(vmAddr), top, reinterpret_cast<const void*>(tr)));
}
// ---- batch 33
// instanceof: pops the class operand and replaces the top value with whether the class (or its prototype) is on the value's traits chain.
// MS2-FUNCTIONAL 0x14253b990: raw-offset model; codegen differs from the exe
// @0x14253b990
void Sfr31ExecInstanceOf(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Value* below;
    Sfr31RawTraitsVal cls;
    {
        const UPInt top = Sfr31Rd(vmAddr, 0x50);
        for (int i = 0; i < 8; ++i)
            reinterpret_cast<UInt32*>(&cls)[i] = reinterpret_cast<const UInt32*>(top)[i];
        below = reinterpret_cast<Value*>(top - 0x20);
        Sfr31Wr(vmAddr, 0x50, top - 0x20);
    }
    const UInt32 ck = cls.w0 & 0x1f;
    if (ck - 0xd > 1)
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x410), vm));
    else
    {
        const UInt32 bk = *reinterpret_cast<const UInt32*>(below) & 0x1f;
        bool r = false;
        if (bk != 0 && (bk - 0xc > 3 || Sfr31Rd(reinterpret_cast<UPInt>(below), 0x10) != 0))
        {
            UPInt chain = FUN_142507f60(vmAddr, below);
            const UPInt target = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(&cls)));
            if (ck == 0xd)
            {
                for (; chain != 0; chain = Sfr31Rd(chain, 0x88))
                    if (chain == target)
                    {
                        r = true;
                        break;
                    }
            }
            else
            {
                typedef void (*Fn)(UPInt);
                UPInt proto = Sfr31Rd(target, 0x80);
                if (proto == 0)
                {
                    (*reinterpret_cast<Fn*>(Sfr31Rd(target, 0) + 0x68))(target);
                    proto = Sfr31Rd(target, 0x80);
                }
                for (; chain != 0; chain = Sfr31Rd(chain, 0x88))
                {
                    UPInt c = Sfr31Rd(chain, 0x80);
                    if (c == 0)
                    {
                        (*reinterpret_cast<Fn*>(Sfr31Rd(chain, 0) + 0x68))(chain);
                        c = Sfr31Rd(chain, 0x80);
                    }
                    if (reinterpret_cast<UPInt>(&reinterpret_cast<Class*>(c)->GetPrototype()) == proto)
                    {
                        r = true;
                        break;
                    }
                }
            }
        }
        below->SetBool(r);
    }
    reinterpret_cast<Value*>(&cls)->~Value();
}
// ---- batch 34
// astype-style op: replaces the top value with null when it is an instance of the named class; names resolved at compile time are rejected.
// MS2-FUNCTIONAL 0x142532ff0: raw-offset model; codegen differs from the exe
// @0x142532ff0
void Sfr31ExecAsTypeNamed(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    const UPInt cfile = Sfr31Rd(file, 0x28);
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    const UPInt nameSlot = Sfr31Rd(cfile, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8;
    if ((flags & 3) == 1 || ((flags >> 2) & 1) != 0)
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        String name(reinterpret_cast<const char*>(sv[0]), sv[1]);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x436, reinterpret_cast<void*>(cvm), name.ToCStr(), "compile time");
        reinterpret_cast<VM*>(cvm)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(cvm, 0x50));
    if (*reinterpret_cast<const UInt8*>(vmAddr + 0x180) != 0)
        return;
    const UPInt tr = Sfr31ResolveClassTraits(vmAddr, file, entry);
    if (tr == 0 || tr == FUN_142507f60(vmAddr, top))
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7850(eb, 0x3f6, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(sv[0]));
        reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    else
        top->SetNull();
}

// Raises verify error 0x42c naming two conflicting objects; an object whose name is the empty string is reported as null.
// MS2-FUNCTIONAL 0x14252efe0: raw-offset model; codegen differs from the exe
// @0x14252efe0
void Sfr31RaiseNameConflict(UPInt tr, UPInt a, UPInt b)
{
    const UPInt vm = TrVM(tr);
    UPInt nodeB = 0, nodeA = 0;
    Sfr31VFnName fb = *reinterpret_cast<Sfr31VFnName*>(Sfr31Rd(b, 0) + 0x38);
    UPInt* pb = fb(b, &nodeB);
    Sfr31RawTraitsVal vb = {10, 0, *pb, 0};
    if (*pb == Sfr31Rd(*pb, 8) + 0x68)
    {
        vb.w0 = 0xc;
        vb.w2 = 0;
    }
    else
        ++*reinterpret_cast<int*>(vb.w2 + 0x18);
    Sfr31VFnName fa = *reinterpret_cast<Sfr31VFnName*>(Sfr31Rd(a, 0) + 0x38);
    UPInt* pa = fa(a, &nodeA);
    Sfr31RawTraitsVal va = {10, 0, *pa, 0};
    if (*pa == Sfr31Rd(*pa, 8) + 0x68)
    {
        va.w0 = 0xc;
        va.w2 = 0;
    }
    else
        ++*reinterpret_cast<int*>(va.w2 + 0x18);
    {
        VM& v = *reinterpret_cast<VM*>(vm);
        Sfr31Err e(static_cast<VM::ErrorID>(0x42c), v, *reinterpret_cast<const Value*>(&va), *reinterpret_cast<const Value*>(&vb));
        v.ThrowVerifyError(e);
    }
    reinterpret_cast<Value*>(&va)->~Value();
    Sfr31ReleaseStr(nodeA);
    reinterpret_cast<Value*>(&vb)->~Value();
    Sfr31ReleaseStr(nodeB);
}
// ---- batch 35
// Native with a required object argument: the popped value is handed to the owner's helper through its virtual call along with the remaining arguments.
// MS2-FUNCTIONAL 0x142537810: raw-offset model; codegen differs from the exe
// @0x142537810
void Sfr31ExecOwnerCall(UPInt vmAddr, UPInt owner, UInt32 n)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, n);
    const UPInt frame = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    const UPInt top = Sfr31Rd(frame, 8);
    Sfr31RawTraitsVal val;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&val)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(frame, 8, top - 0x20);
    Sfr31ThrowIfNotObject(vm, reinterpret_cast<const UInt32*>(&val));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt helper = Sfr31Rd(Sfr31Rd(owner, 0x40), 0x88);
        if (helper != 0)
        {
            const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
            void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
            typedef void (*Fn)(UPInt, UPInt, void*, UInt32, void*);
            (*reinterpret_cast<Fn*>(Sfr31Rd(helper, 0) + 0x78))(helper, Sfr31Rd(owner, 0x40), &val, n, args);
        }
    }
    reinterpret_cast<Value*>(&val)->~Value();
    FUN_1424de9e0(raBuf);
}
// ---- batch 36
// Native with a required object argument: the helper is invoked with the argument's traits and the remaining arguments.
// MS2-FUNCTIONAL 0x142533df0: raw-offset model; codegen differs from the exe
// @0x142533df0
void Sfr31ExecCallWithTraits(UPInt vmAddr, UInt32 a, UInt32 n)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, n);
    const UPInt frame = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    const UPInt top = Sfr31Rd(frame, 8);
    Sfr31RawTraitsVal val;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&val)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(frame, 8, top - 0x20);
    Sfr31ThrowIfNotObject(vm, reinterpret_cast<const UInt32*>(&val));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
        void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
        const UPInt tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(&val)));
        FUN_142500260(vmAddr, a, tr, &val, n, args);
    }
    reinterpret_cast<Value*>(&val)->~Value();
    FUN_1424de9e0(raBuf);
}

// Tracer op: the first argument's type picks the class traits (null/undefined -> Object) that are pushed.
// MS2-FUNCTIONAL 0x142532bd0: raw-offset model; codegen differs from the exe
// @0x142532bd0
void Sfr31TraceArgClassTraits(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    const UPInt vm = TrVM(s.Tracer());
    TrReadArgsRaw args(reinterpret_cast<VM*>(vm), st, argc);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    const UPInt bp = reinterpret_cast<UPInt>(args.buf);
    const UPInt p = *reinterpret_cast<const UInt32*>(bp + 0x18) <= Sfr31Rd(bp, 0x128) ? Sfr31Rd(bp, 0x120) : bp + 0x20;
    UPInt tr = 0;
    const UInt32 k = *reinterpret_cast<const UInt32*>(p) & 0x1f;
    if (k == 0 || (k == 0xc && Sfr31Rd(p, 0x10) == 0))
        tr = Sfr31Rd(vm, 0x1f8);
    else if (k == 9)
        tr = Sfr31Rd(p, 0x10);
    else if (k == 0xd)
        tr = Sfr31Rd(Sfr31Rd(p, 0x10), 0x20);
    UPInt out = Sfr31Rd(vm, 0x1f8);
    if (tr != 0)
    {
        if (tr == Sfr31Rd(vm, 0x220))
            out = Sfr31Rd(vm, 0x250);
        else if (tr == Sfr31Rd(vm, 0x228))
            out = Sfr31Rd(vm, 0x258);
        else if (tr == Sfr31Rd(vm, 0x218))
            out = Sfr31Rd(vm, 0x260);
        else if (tr == Sfr31Rd(vm, 0x230))
            out = Sfr31Rd(vm, 0x268);
        else
            out = FUN_142563380(FUN_1425081f0(vm), tr);
    }
    Sfr31RawTraitsVal v = {9, 0, out, 0};
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(&v));
    popped.Get().~Value();
}
// ---- batch 37
// Pops the operand stack top: a Namespace value becomes the target's namespace slot; anything else is converted to a string and a
// non-empty result creates a new Namespace for the slot.
// MS2-FUNCTIONAL 0x142538560: raw-offset model; codegen differs from the exe
// @0x142538560
void Sfr31ExecPushNamespace(UPInt vm, UPInt target)
{
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(vm, 0x50));
    const UInt32* tw = reinterpret_cast<const UInt32*>(top);
    if ((tw[0] & 0x1f) == 0xb)
        FUN_1423f1840(reinterpret_cast<void*>(target + 0x58), Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10));
    else
    {
        const UPInt mgr = Sfr31Rd(Sfr31Rd(vm, 0x10), 0x1e8);
        ASString str(reinterpret_cast<ASStringNode*>(mgr + 0x40));
        const bool ok = top->Convert2String(str);
        if (ok && *reinterpret_cast<const UInt32*>(Sfr31Rd(reinterpret_cast<UPInt>(&str), 0) + 0x20) != 0)
        {
            // SF_HEAP_AUTO_NEW(tr) Instances::fl::Namespace(...): the ctor's prefix argument is evaluated before the allocation.
            const Value& prefix = Value::GetUndefined();
            const UPInt tr = Sfr31Rd(Sfr31Rd(vm, 0x200), 0xc0);
            AllocInfo ai(0x148, 0, 0);   // StatMV_VM_Instance_Mem-family id the exe passes
            void* mem = Memory::pGlobalHeap->AllocAutoHeap(reinterpret_cast<void*>(tr), 0x60, &ai);
            UPInt ns = 0;
            if (mem != 0)
                ns = reinterpret_cast<UPInt>(FUN_1423edb60(mem, Sfr31Rd(tr, 0x78), Sfr31Rd(tr, 0xe8), 0, &str, &prefix));
            const UPInt old = Sfr31Rd(target, 0x58);
            if (ns != old)
            {
                if (old != 0 && (old & 1) == 0 && (*reinterpret_cast<UInt32*>(old + 0x10) & 0x3fffff) != 0)
                {
                    --*reinterpret_cast<UInt32*>(old + 0x10);
                    FUN_1423dfa20(reinterpret_cast<void*>(old));
                }
                Sfr31Wr(target, 0x58, ns);
            }
        }
    }
    top->~Value();
    Sfr31Wr(vm, 0x50, Sfr31Rd(vm, 0x50) - 0x20);
}

// ---- batch 38
// Removes every class traits held in the array at +0xa0 from the owner's multiname hash, then clears the array.
// MS2-FUNCTIONAL 0x142530de0: raw-offset model; codegen differs from the exe
// @0x142530de0
void Sfr31UnregisterClassTraits(UPInt self)
{
    const UPInt count = Sfr31Rd(self, 0xa8);
    for (UPInt i = 0; i < count; ++i)
    {
        const UPInt tr = Sfr31Rd(Sfr31Rd(self, 0xa0), i * 8);
        const UPInt nsObj = Sfr31Rd(tr, 0xc0);
        const UPInt owner = Sfr31Rd(self, 0x20);
        if (nsObj == 0)
        {
            // value-keyed removal: scan the hash for the entry holding this traits
            const UPInt tbl = Sfr31Rd(owner, 0x1c8);
            for (UPInt e = 0; tbl != 0 && static_cast<long>(Sfr31Rd(tbl, 8)) >= static_cast<long>(e); ++e)
            {
                if (Sfr31Rd(tbl, e * 0x28 + 0x10) == static_cast<UPInt>(-2))
                    continue;
                if (Sfr31Rd(tbl, e * 0x28 + 0x30) == tr)
                {
                    FUN_142522350(reinterpret_cast<void*>(owner + 0x1c8), reinterpret_cast<void*>(tbl + e * 0x28 + 0x20));
                    break;
                }
            }
            continue;
        }
        UPInt node = 0;
        reinterpret_cast<Sfr31VFnName>(Sfr31Rd(Sfr31Rd(nsObj, 0), 0x38))(nsObj, &node);
        const UPInt ns = Sfr31Rd(nsObj, 0xc0);
        UPInt key[2];
        key[0] = node;
        ++*reinterpret_cast<int*>(node + 0x18);
        if (ns != 0)
            *reinterpret_cast<UInt32*>(ns + 0x10) = (*reinterpret_cast<UInt32*>(ns + 0x10) + 1u) & 0x8fbfffffu;
        key[1] = ns;
        FUN_142522350(reinterpret_cast<void*>(Sfr31Rd(self, 0x20) + 0x1c8), key);
        if (ns != 0)
        {
            if ((ns & 1) == 0)
            {
                if ((*reinterpret_cast<UInt32*>(ns + 0x10) & 0x3fffff) != 0)
                {
                    --*reinterpret_cast<UInt32*>(ns + 0x10);
                    FUN_1423dfa20(reinterpret_cast<void*>(ns));
                }
            }
        }
        Sfr31ReleaseStr(key[0]);
        Sfr31ReleaseStr(node);
    }
    FUN_142524af0(reinterpret_cast<UPInt*>(self + 0xa0), reinterpret_cast<const void*>(self + 0xa0), 0);
}

// ---- batch 39
static inline void Sfr31ReleaseRawVal(UPInt* v)
{
    UInt32* w = reinterpret_cast<UInt32*>(v);
    if ((w[0] & 0x1f) <= 9)
        return;
    if (((w[0] >> 9) & 1) == 0)
    {
        FUN_142521f00(v);
        return;
    }
    int* rc = reinterpret_cast<int*>(v[1]);
    if (--*rc == 0)
        Memory::pGlobalHeap->Free(rc);
}

// Resizes the array stored at a variable path, creating a new array of that length when the variable is not an Array.
// MS2-FUNCTIONAL 0x14252b3a0: raw-offset model; codegen differs from the exe
// @0x14252b3a0
bool Sfr31SetArraySize(UPInt root, UPInt path, int size, UInt32 flags)
{
    UPInt cur[4] = { 0, 0, 0, 0 };
    const bool got = FUN_142506000(root, cur, path);
    const UInt32 kind = reinterpret_cast<UInt32*>(cur)[0] & 0x1f;
    bool ok;
    if (got && kind - 0xc < 4 && cur[2] != 0 && Sfr31Rd(Sfr31Rd(cur[2], 0x20), 0x70) == 7 &&
        ((*reinterpret_cast<UInt8*>(Sfr31Rd(cur[2], 0x20) + 0x68) >> 5) & 1) == 0)
    {
        if (size != *reinterpret_cast<int*>(cur[2] + 0x38))
            FUN_14241fe30(reinterpret_cast<void*>(cur[2] + 0x38), size);
        ok = true;
    }
    else
    {
        const UPInt tr = Sfr31Rd(Sfr31Rd(Sfr31Rd(root, 0x48), 0x238), 0xc0);
        UPInt arr = 0;
        FUN_14241a500(tr, &arr, tr);
        FUN_14241fe30(reinterpret_cast<void*>(arr + 0x38), size);
        UPInt nv[4] = { 0xc, 0, arr, 0 };
        UPInt gv[3] = { 0, 0, 0 };
        FUN_1424e42c0(root, reinterpret_cast<const Value*>(nv), gv);
        typedef bool (*SetVar)(UPInt, UPInt, void*, UInt32);
        ok = reinterpret_cast<SetVar>(Sfr31Rd(Sfr31Rd(root, 0), 0x138))(root, path, gv, flags);
        if ((reinterpret_cast<UInt32*>(gv)[2] >> 6) & 1)
        {
            typedef void (*Rel)(UPInt, UPInt*, UPInt);
            reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(gv[0], 0), 0x10))(gv[0], gv, gv[2]);
        }
        Sfr31ReleaseRawVal(nv);
    }
    Sfr31ReleaseRawVal(cur);
    return ok;
}

// ---- batch 40
// pushwith: the (non-null) top of the operand stack moves onto the scope stack and is marked as a with-scope.
// MS2-FUNCTIONAL 0x14253f7d0: raw-offset model; codegen differs from the exe
// @0x14253f7d0
void Sfr31ExecPushWithScope(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt32* top = reinterpret_cast<UInt32*>(Sfr31Rd(vmAddr, 0x50));
    const UInt32 k = (top[0] & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10);
    if ((top[0] & 0x1f) == 0 || (k < 4 && obj == 0))
    {
        const UInt32 id = (k < 4 ? (obj != 0) : 1u) + 0x3f1;
        VM::Error e(static_cast<VM::ErrorID>(id), vm);
        vm.ThrowTypeError(e);
        return;
    }
    FUN_14241e430(reinterpret_cast<void*>(vmAddr + 0x160), &Value::GetUndefined());
    UInt32* dst = reinterpret_cast<UInt32*>(Sfr31Rd(vmAddr, 0x160) + Sfr31Rd(vmAddr, 0x168) * 0x20 - 0x20);
    for (int i = 0; i < 8; ++i)
        dst[i] = top[i];
    top[0] = 0;
    reinterpret_cast<Value*>(top)->~Value();
    Sfr31Wr(vmAddr, 0x50, Sfr31Rd(vmAddr, 0x50) - 0x20);
    dst[0] |= 0x100;
}

// Tracer op: pops one operand and pushes the class traits named by the class entry (builtin classes get the plain traits kind).
// MS2-FUNCTIONAL 0x14253c2f0: raw-offset model; codegen differs from the exe
// @0x14253c2f0
void Sfr31TraceClassTraitsFromIndex(State* st, UInt32 idx)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), idx);
    FUN_14251ccc0(st, 1);
    const UPInt link = Sfr31Rd(Sfr31Rd(s.Tracer(), 0x20), 0x28);
    const UPInt file = Sfr31Rd(link, 0x28);
    const UPInt cls = Sfr31Rd(Sfr31Rd(file, 0x140), static_cast<UPInt>(idx) * 8);
    const SPInt mnIdx = *reinterpret_cast<const int*>(cls + 0x24);
    const UPInt mn = mnIdx == 0 ? file + 0xe8 : mnIdx * 0x10 + Sfr31Rd(file, 0xb8);
    const UPInt ns = FUN_14250ae60(link, *reinterpret_cast<const int*>(mn + 4));
    const UPInt uri = Sfr31Rd(ns, 0x30);
    const bool gfx = *reinterpret_cast<const UInt32*>(uri + 0x20) >= 13 && strncmp(reinterpret_cast<const char*>(Sfr31Rd(uri, 0)), "scaleform.gfx", 13) == 0;
    const UPInt vm = Sfr31Rd(link, 0x20);
    UPInt tr = gfx ? Sfr31ResolveClassTraits(vm, link, mn) : FUN_14250f9a0(vm, link, cls);
    if (tr == 0)
        tr = Sfr31Rd(vm, 0x1f8);
    const UPInt c = Sfr31Rd(tr, 0xc0);
    UPInt raw[4] = { 0x49, 0, tr, 0 };
    if (c == Sfr31Rd(Sfr31Rd(vm, 0x220), 0xc0) || c == Sfr31Rd(Sfr31Rd(vm, 0x228), 0xc0) ||
        c == Sfr31Rd(Sfr31Rd(vm, 0x218), 0xc0) || c == Sfr31Rd(Sfr31Rd(vm, 0x210), 0xc0))
        raw[0] = 9;
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(raw));
}

// Finds the class traits for a multiname; unregistered ones are looked up on the global object by name and cached in the hash.
// MS2-FUNCTIONAL 0x142525270: raw-offset model; codegen differs from the exe
// @0x142525270
UPInt Sfr31FindClassTraitsByMn(UPInt vm, UPInt mn)
{
    UPInt found = FUN_14250d760(vm, mn);
    if (found != 0)
        return found;
    const UPInt mgr = Sfr31Rd(Sfr31Rd(vm, 0x10), 0x1e8);
    ASString str(reinterpret_cast<ASStringNode*>(mgr + 0x40));
    UInt8 tmp[8];
    if (*FUN_1424f1390(reinterpret_cast<Value*>(mn + 0x10), tmp, &str) == 0)
        return 0;
    const UPInt node = Sfr31Rd(reinterpret_cast<UPInt>(&str), 0);
    const UPInt ns = Sfr31Rd(mn, 8);
    found = reinterpret_cast<UPInt>(FUN_142415520(reinterpret_cast<void*>(Sfr31Rd(vm, 0x298)), &str, reinterpret_cast<const Instances::Namespace*>(ns)));
    if (found != 0)
    {
        UPInt key[2];
        key[0] = node;
        ++*reinterpret_cast<int*>(node + 0x18);
        if (ns != 0)
            *reinterpret_cast<UInt32*>(ns + 0x10) = (*reinterpret_cast<UInt32*>(ns + 0x10) + 1u) & 0x8fbfffffu;
        key[1] = ns;
        UPInt* nodeRef[2] = { key, &found };
        const UInt32 h = static_cast<UInt32>(static_cast<SPInt>(Sfr31Rd(ns, 0x20) << 60) >> 60) ^
                         ((*reinterpret_cast<const UInt32*>(Sfr31Rd(ns, 0x30) + 0x1c) & 0xffffffu) << 2) ^
                         (*reinterpret_cast<const UInt32*>(node + 0x1c) & 0xffffffu);
        FUN_1423eb030(reinterpret_cast<void*>(vm + 0x1c8), reinterpret_cast<void*>(vm + 0x1c8), nodeRef, h);
        if (ns != 0 && (ns & 1) == 0 && (*reinterpret_cast<UInt32*>(ns + 0x10) & 0x3fffff) != 0)
        {
            --*reinterpret_cast<UInt32*>(ns + 0x10);
            FUN_1423dfa20(reinterpret_cast<void*>(ns));
        }
        Sfr31ReleaseStr(key[0]);
    }
    return found;
}

// Tracer op: pops two operands and pushes the traits of the lower one as a kind-8 value (builtin classes drop the extra flag).
// MS2-FUNCTIONAL 0x142533470: raw-offset model; codegen differs from the exe
// @0x142533470
void Sfr31TraceTraitsOfSecond(State* st, UInt32 argc)
{
    StV s(st);
    FUN_14251fcd0(s.Tracer(), argc);
    const UPInt vm = TrVM(s.Tracer());
    TrReadArgsRaw args(reinterpret_cast<VM*>(vm), st, argc);
    TrPopped p1, p2;
    FUN_14251cd30(st, &p1.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    FUN_14251cd30(st, &p2.Get());
    ++*reinterpret_cast<UInt32*>(args.buf + 0x10);
    const UPInt tr = FUN_14250a060(vm, &p2.Get());
    UPInt raw[4] = { 0x48, 0, tr, 0 };
    if (tr == Sfr31Rd(Sfr31Rd(vm, 0x220), 0xc0) || tr == Sfr31Rd(Sfr31Rd(vm, 0x228), 0xc0) ||
        tr == Sfr31Rd(Sfr31Rd(vm, 0x218), 0xc0) || tr == Sfr31Rd(Sfr31Rd(vm, 0x210), 0xc0))
        raw[0] = 8;
    s.OpStack().PushBack(*reinterpret_cast<const Value*>(raw));
    p2.Get().~Value();
    p1.Get().~Value();
}

// findproperty-style resolve: pushes the property's value, or the VM's fallback object when it does not resolve.
// MS2-FUNCTIONAL 0x1425389b0: raw-offset model; codegen differs from the exe
// @0x1425389b0
void Sfr31ExecFindPropOrGlobal(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UPInt pr[6] = {0, 0, 0, 0, 0, 0};
        FUN_142502570(vmAddr, pr, &mn);
        Value& res = *reinterpret_cast<Value*>(&pr[2]);
        const UPInt f = pr[0];
        if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
        {
            const UPInt g = FUN_14250a550(vmAddr);
            UPInt raw[4] = { 0xc, 0, g, 0 };
            if (g != 0)
                *reinterpret_cast<UInt32*>(g + 0x10) = (*reinterpret_cast<UInt32*>(g + 0x10) + 1u) & 0x8fbfffffu;
            ExecPushCopy(reinterpret_cast<VM*>(vmAddr), *reinterpret_cast<Value*>(raw));
            FUN_142521f00(raw);
        }
        else
            ExecPushCopy(reinterpret_cast<VM*>(vmAddr), res);
        res.~Value();
    }
}

// Verifies that the top of the operand stack is usable as the scope object named by the multiname (name check, class lookup, type check).
// MS2-FUNCTIONAL 0x142536b90: raw-offset model; codegen differs from the exe
// @0x142536b90
void Sfr31ExecCheckScopeObject(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    const UPInt cfile = Sfr31Rd(file, 0x28);
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    if ((flags & 3) == 1 || ((flags >> 2) & 1) != 0)
    {
        UPInt sv[2];
        FUN_142545310(Sfr31Rd(cfile, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8, sv);
        String name(reinterpret_cast<const char*>(sv[0]), sv[1]);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x436, reinterpret_cast<void*>(cvm), name.ToCStr(), "compile time");
        reinterpret_cast<VM*>(cvm)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    const UPInt top = Sfr31Rd(cvm, 0x50);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) != 0)
        return;
    const UPInt tr = Sfr31ResolveClassTraits(vmAddr, file, entry);
    if (tr == 0)
    {
        UPInt sv[2];
        FUN_142545310(Sfr31Rd(cfile, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8, sv);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x42d, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(sv[0]), "any object on the scope stack");
        reinterpret_cast<VM*>(vmAddr)->ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
        return;
    }
    typedef char (*VCheck)(UPInt, UPInt, UPInt);
    if (reinterpret_cast<VCheck>(Sfr31Rd(Sfr31Rd(tr, 0), 0x70))(tr, top, top) != 0)
        return;
    UPInt node = 0;
    UPInt* nm = reinterpret_cast<Sfr31VFnName>(Sfr31Rd(Sfr31Rd(tr, 0), 0x38))(tr, &node);
    alignas(8) char eb[sizeof(VM::Error)];
    FUN_1424d7130(eb, 0x40a, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const void*>(top), reinterpret_cast<const char*>(Sfr31Rd(*nm, 0)));
    reinterpret_cast<VM*>(vmAddr)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
    reinterpret_cast<VM::Error*>(eb)->~Error();
    Sfr31ReleaseStr(node);
}

// Converts a value in place to its primitive form (objects through their conversion hook); *ok tells whether it succeeded.
// MS2-FUNCTIONAL 0x14252f790: raw-offset model; codegen differs from the exe
// @0x14252f790
UInt8* Sfr31ValueToPrimitive(Value* v, UInt8* ok)
{
    Value local;
    UPInt* lw = reinterpret_cast<UPInt*>(&local);
    const UPInt vp = reinterpret_cast<UPInt>(v);
    const UInt32 k = *reinterpret_cast<const UInt32*>(vp) & 0x1f;
    bool good = true;
    if (k < 5 || k == 10 || (k - 0xc < 4 && Sfr31Rd(vp, 0x10) == 0))
        local.Assign(*v);
    else if (((k - 5) & 0xfffffffdu) == 0 || k - 0x10 < 2)
    {
        *reinterpret_cast<UInt32*>(lw) = 4;
        lw[2] = 0;
        lw[3] = 0;
    }
    else if (k == 0xb)
        local = *reinterpret_cast<const ASString*>(Sfr31Rd(vp, 0x10) + 0x30);
    else
    {
        FUN_142508bd0(Sfr31Rd(vp, 0x10), &local, 0);
        if (*reinterpret_cast<UInt8*>(Sfr31Rd(Sfr31Rd(Sfr31Rd(vp, 0x10), 0x20), 0x78) + 0x180) != 0)
            good = false;
    }
    if (good)
    {
        UPInt* vw = reinterpret_cast<UPInt*>(v);
        for (int i = 0; i < 4; ++i)
        {
            const UPInt t = vw[i];
            vw[i] = lw[i];
            lw[i] = t;
        }
    }
    *ok = good ? 1 : 0;
    return ok;
}

// 'in' operator: replaces the top value (the object) with whether it has the property named by the multiname.
// MS2-FUNCTIONAL 0x142538040: raw-offset model; codegen differs from the exe
// @0x142538040
void Sfr31ExecIn(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(ctx.stack, 8));
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(top));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt mnp = reinterpret_cast<UPInt>(&mn);
        const Value& nameV = *reinterpret_cast<const Value*>(mnp + 0x10);
        const UInt32 nk = *reinterpret_cast<const UInt32*>(mnp + 0x10) & 0x1f;
        const UPInt nobj = Sfr31Rd(mnp, 0x20);
        const UPInt vmHelper = Sfr31Rd(vmAddr, 0x40);
        if (*reinterpret_cast<UInt8*>(vmHelper + 0x20) == 0 || nk - 0xc > 3 || nobj == 0 ||
            Sfr31Rd(Sfr31Rd(nobj, 0x20), 0x70) != 0xe || ((*reinterpret_cast<UInt8*>(Sfr31Rd(nobj, 0x20) + 0x68) >> 5) & 1) != 0)
        {
            const UInt32 tk = *reinterpret_cast<const UInt32*>(top) & 0x1f;
            if (tk > 4 && tk != 10)
            {
                bool res = false;
                bool halted = false;
                if (tk - 0xc < 4)
                {
                    const UPInt o = Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10);
                    if ((*reinterpret_cast<UInt8*>(Sfr31Rd(o, 0x20) + 0x68) >> 1) & 1)
                    {
                        typedef UInt8* (*VHas)(UPInt, UInt8*, void*);
                        UInt8 tmp[8];
                        res = *reinterpret_cast<VHas>(Sfr31Rd(Sfr31Rd(o, 0), 0x48))(o, tmp, &mn) != 0;
                    }
                    halted = *reinterpret_cast<UInt8*>(vmAddr + 0x180) != 0;
                }
                if (!halted)
                    top->SetBool(res);
            }
            else
            {
                Sfr31Err e(static_cast<VM::ErrorID>(0x460), vm, nameV, *top);
                vm.ThrowReferenceError(e);
            }
        }
        else
        {
            const UPInt tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, nameV));
            UPInt node = 0;
            UPInt* nm = reinterpret_cast<Sfr31VFnName>(Sfr31Rd(Sfr31Rd(tr, 0), 0x38))(tr, &node);
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d7850(eb, 0x45f, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(Sfr31Rd(*nm, 0)));
            vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
            Sfr31ReleaseStr(node);
        }
    }
}

// getproperty-style op: moves the object off the stack top, reads the named property into the slot and raises a ReferenceError
// when a primitive has no such property.
// MS2-FUNCTIONAL 0x142539be0: raw-offset model; codegen differs from the exe
// @0x142539be0
void Sfr31ExecGetProp(UPInt vmAddr, UPInt file, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    Value* top = reinterpret_cast<Value*>(Sfr31Rd(ctx.stack, 8));
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(top));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        Sfr31RawTraitsVal obj;
        for (int i = 0; i < 8; ++i)
            reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(top)[i];
        *reinterpret_cast<UInt32*>(top) = 0;
        UInt8 ret[16];
        const UInt8* r = FUN_14250d2f0(ret, vmAddr, &obj, &mn, top);
        const UInt32 ok = obj.w0 & 0x1f;
        if (*r == 0 && *reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0 && (ok < 5 || ok == 10))
        {
            Sfr31Err e(static_cast<VM::ErrorID>(0x42d), vm, *reinterpret_cast<const Value*>(reinterpret_cast<UPInt>(&mn) + 0x10),
                       *reinterpret_cast<const Value*>(&obj));
            vm.ThrowReferenceError(e);
        }
        reinterpret_cast<Value*>(&obj)->~Value();
    }
}

// ---- batch 41
static inline UPInt Sfr31HashCap(UPInt n)
{
    UPInt c = 8;
    while (c < n)
        c <<= 1;
    return c;
}

static inline UInt64 Sfr31Sdbm(const void* p, int len)
{
    const UInt8* b = static_cast<const UInt8*>(p);
    UInt64 h = 5381;
    for (int i = len - 1; i >= 0; --i)
        h = h * 65599 + b[i];
    return h;
}

static inline void Sfr31DropSPtr(UPInt slot)
{
    const UPInt v = Sfr31Rd(slot, 0);
    if (v == 0)
        return;
    if ((v & 1) == 0)
    {
        UInt32* rc = reinterpret_cast<UInt32*>(v + 0x10);
        if ((*rc & 0x3fffff) != 0)
        {
            --*rc;
            FUN_1423dfa20(reinterpret_cast<void*>(v));
        }
    }
    else
        Sfr31Wr(slot, 0, v - 1);
}

static inline void Sfr31DropStrNode(UPInt slot)
{
    const UPInt n = Sfr31Rd(slot, 0);
    if (n != 0)
        Sfr31ReleaseStr(n);
}

static inline void Sfr31DropResource(UPInt slot)
{
    const UPInt r = Sfr31Rd(slot, 0);
    if (r != 0)
        FUN_1425a4030(reinterpret_cast<void*>(r));
}

// AutoPtr<ArrayLH<...>> entry: pointer at +0x10, owned flag at +0x18.
static inline void Sfr31DropAutoPtr(UPInt e)
{
    const UPInt a = Sfr31Rd(e, 0x10);
    if (a != 0)
    {
        if (*reinterpret_cast<UInt8*>(e + 0x18) != 0)
        {
            *reinterpret_cast<UInt8*>(e + 0x18) = 0;
            FUN_1424dc730(reinterpret_cast<void*>(a));
            Memory::pGlobalHeap->Free(reinterpret_cast<void*>(a));
        }
        Sfr31Wr(e, 0x10, 0);
    }
    *reinterpret_cast<UInt8*>(e + 0x18) = 0;
}

typedef void* (*Sfr31VAlloc)(UPInt self, UPInt size, void* info);

// Allocates and empties a hash table body of cap entries (header: count at +0, mask at +8, entries from +0x10).
static inline UPInt Sfr31HashNew(UPInt heap, UPInt cap, UPInt stride, UInt32 id, int mode)
{
    UPInt t;
    if (mode == 2)
        t = reinterpret_cast<UPInt>(Memory::AllocAutoHeap(reinterpret_cast<const void*>(heap), cap * stride + 0x10, AllocInfo(id, 0, 0)));
    else
    {
        UInt32 info[2] = { id, 0 };
        const UPInt self = (mode == 1) ? reinterpret_cast<UPInt>(Memory::pGlobalHeap) : heap;
        t = reinterpret_cast<UPInt>(reinterpret_cast<Sfr31VAlloc>(Sfr31Rd(Sfr31Rd(self, 0), 0x50))(self, cap * stride + 0x10, info));
    }
    Sfr31Wr(t, 0, 0);
    Sfr31Wr(t, 8, cap - 1);
    for (UPInt i = 0; i < cap; ++i)
        Sfr31Wr(t + 0x10, i * stride, UPInt(-2));
    return t;
}

// Chained insert into a hash table whose entries cache the slot index (next at +0, slot at +8, key and value at +0x10).
static inline void Sfr31HashAddCached(UPInt* nt, UPInt heap, UInt64 hash, UPInt k0, UPInt k1)
{
    FUN_1424eef00(nt, heap);
    ++*reinterpret_cast<SPInt*>(*nt);
    const UPInt mask = Sfr31Rd(*nt, 8);
    const UPInt idx = hash & mask;
    const UPInt base = *nt + 0x10;
    const UPInt nat = base + idx * 0x20;
    const UPInt oldNext = Sfr31Rd(nat, 0);
    if (oldNext == UPInt(-2))
    {
        Sfr31Wr(nat, 0, UPInt(-1));
        Sfr31Wr(nat, 0x10, k0);
        Sfr31Wr(nat, 0x18, k1);
    }
    else
    {
        UPInt fr = idx;
        do
            fr = (fr + 1) & mask;
        while (Sfr31Rd(base + fr * 0x20, 0) != UPInt(-2));
        const UPInt free = base + fr * 0x20;
        const UPInt slot = Sfr31Rd(nat, 8);
        Sfr31Wr(free, 0, oldNext);
        Sfr31Wr(free, 8, slot);
        Sfr31Wr(free, 0x10, Sfr31Rd(nat, 0x10));
        Sfr31Wr(free, 0x18, Sfr31Rd(nat, 0x18));
        if (slot == idx)
            Sfr31Wr(nat, 0, fr);
        else
        {
            UPInt p = base + slot * 0x20;
            UPInt nx = Sfr31Rd(p, 0);
            while (nx != idx)
            {
                p = base + nx * 0x20;
                nx = Sfr31Rd(p, 0);
            }
            Sfr31Wr(p, 0, fr);
            Sfr31Wr(nat, 0, UPInt(-1));
        }
        Sfr31Wr(nat, 0x10, k0);
        Sfr31Wr(nat, 0x18, k1);
    }
    Sfr31Wr(nat, 8, idx);
}

// Dynamic-attribute node (key {id, name string}, Value) assignment over an existing node.
static inline void Sfr31DynNodeAssign(UPInt dst, UPInt src)
{
    *reinterpret_cast<UInt32*>(dst) = *reinterpret_cast<const UInt32*>(src);
    const UPInt nn = Sfr31Rd(src, 8);
    ++*reinterpret_cast<int*>(nn + 0x18);
    Sfr31ReleaseStr(Sfr31Rd(dst, 8));
    Sfr31Wr(dst, 8, nn);
    reinterpret_cast<Value*>(dst + 0x10)->Assign(*reinterpret_cast<const Value*>(src + 0x10));
}

// ---- batch 42
// Resolves the class traits matching a value's kind and hands them to the instance-traits setup of the given traits.
// MS2-FUNCTIONAL 0x142531260: raw-offset model; codegen differs from the exe
// @0x142531260
bool Sfr31SetTraitsForValue(UPInt st, const UInt32* v, UPInt traits)
{
    const UInt32 k = v[0] & 0x1f;
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    const UPInt dst = Sfr31Rd(traits, 0xc0);
    if (k == 9)
    {
        return FUN_1425149a0(traits, obj);
    }
    if (k == 0xd)
    {
        return FUN_1425149a0(traits, Sfr31Rd(obj, 0x20));
    }
    const UPInt vm = Sfr31Rd(Sfr31Rd(Sfr31Rd(st, 0x20), 0x28), 0x20);
    if (k - 0xc < 4 && obj == 0)
    {
        return FUN_142514560(Sfr31Rd(vm, 0x270), dst);
    }
    if (k == 0)
    {
        return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x1f0), 0xc0), dst);
    }
    if (k == 8)
    {
        return FUN_142514560(obj, dst);
    }
    switch (k)
    {
    case 1: return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x210), 0xc0), dst);
    case 2: return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x220), 0xc0), dst);
    case 3: return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x228), 0xc0), dst);
    case 4: return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x218), 0xc0), dst);
    case 5:
    case 0x10: return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x208), 0xc8), dst);
    case 7:
    case 0x11: return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x208), 0xe0), dst);
    case 10:
        if (obj != 0)
        {
            return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x230), 0xc0), dst);
        }
        break;
    case 0xb: return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x200), 0xc0), dst);
    case 0xc:
    case 0xe:
    case 0xf:
        if (obj != 0)
        {
            return FUN_142514560(Sfr31Rd(obj, 0x20), dst);
        }
        break;
    default: return FUN_142514560(Sfr31Rd(vm, 0x278), dst);
    }
    return FUN_142514560(Sfr31Rd(Sfr31Rd(vm, 0x1f8), 0xc0), dst);
}

// The class traits of a class description: its package namespace plus its name, resolved through the VM's class traits cache.
// MS2-FUNCTIONAL 0x142525ca0: SDK-API model; the exe inlines the string and namespace construction
// @0x142525ca0
ClassTraits::Traits* Sfr31GetClassTraitsByInfo(VM* vm, UPInt info)
{
    const UPInt ti = Sfr31Rd(info, 0x18);
    if (ti == 0)
        return NULL;
    const char* pkg = reinterpret_cast<const char*>(Sfr31Rd(ti, 0x10));
    ASString uri = vm->GetStringManager().CreateString(pkg ? pkg : "");
    SPtr<Instances::Namespace> ns;
    if (uri.IsEmpty())
        ns = vm->PublicNamespace.GetPtr();
    else
        ns = SPtr<Instances::Namespace>(static_cast<InstanceTraits::fl::Namespace&>(vm->GetClassTraitsNamespace().GetInstanceTraits())
                                            .MakeInternedInstance(Abc::NS_Public, uri, Value::GetUndefined()));
    const char* nm = reinterpret_cast<const char*>(Sfr31Rd(ti, 8));
    UPInt len = 0;
    while (nm[len] != '\0')
        ++len;
    ASString name(reinterpret_cast<ASStringManager*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(vm), 0x10), 0x1e8))->CreateConstStringNode(nm, len, 0));
    return Sfr27GetClassTraitsByName(vm, &name, ns.GetPtr());
}

// ---- batch 43
// Resolves the class traits named by a multiname entry; the Vector.<T> cases map to the specialised builtin traits.
// MS2-FUNCTIONAL 0x142524f60: raw-offset model; codegen differs from the exe
// @0x142524f60
UPInt Sfr31ResolveClassTraits(UPInt vmAddr, UPInt link, UPInt entry)
{
    const UPInt file = Sfr31Rd(link, 0x28);
    if (entry == file + 0xe8)
        return Sfr31Rd(vmAddr, 0x1f0);
    UPInt nameNode = 0;
    FUN_14250b240(link, &nameNode, *reinterpret_cast<const int*>(entry + 8));
    UPInt r;
    if (nameNode == Sfr31Rd(Sfr31Rd(vmAddr, 0x10), 0x18))
        r = Sfr31Rd(vmAddr, 0x1f8);
    else
    {
        const UPInt ns = FUN_14250ae60(link, *reinterpret_cast<const int*>(entry + 4));
        ASString name(reinterpret_cast<ASStringNode*>(nameNode));
        r = reinterpret_cast<UPInt>(Sfr27GetClassTraitsByName(reinterpret_cast<VM*>(vmAddr), &name, reinterpret_cast<const Instances::Namespace*>(ns)));
        if (r == Sfr31Rd(vmAddr, 0x248))
        {
            const int idx = *reinterpret_cast<const int*>(entry + 0xc);
            UPInt r2;
            if (idx == 0)
                r2 = Sfr31Rd(vmAddr, 0x1f8);
            else
                r2 = Sfr31ResolveClassTraits(vmAddr, link, static_cast<SPInt>(idx) * 0x10 + Sfr31Rd(file, 0xb8));
            if (r2 != 0)
            {
                if (r2 == Sfr31Rd(vmAddr, 0x220))
                    r = Sfr31Rd(vmAddr, 0x250);
                else if (r2 == Sfr31Rd(vmAddr, 0x228))
                    r = Sfr31Rd(vmAddr, 0x258);
                else if (r2 == Sfr31Rd(vmAddr, 0x218))
                    r = Sfr31Rd(vmAddr, 0x260);
                else if (r2 == Sfr31Rd(vmAddr, 0x230))
                    r = Sfr31Rd(vmAddr, 0x268);
                else if (Sfr31Rd(r2, 0xc0) != 0)
                    r = FUN_142563380(FUN_142507b80(Sfr31Rd(r, 0xc0)), r2);
            }
        }
    }
    Sfr31ReleaseStr(nameNode);
    return r;
}
// ---- batch 44
// setsuper: pops the value and the object, then stores through the parent traits' fixed slot or raises a ReferenceError.
// MS2-FUNCTIONAL 0x142540490: raw-offset model; codegen differs from the exe
// @0x142540490
void Sfr31ExecSetSuper(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    Sfr31ExecMnCtx ctx = {cvm, cvm + 0x48, file};
    Sfr31RawTraitsVal val;
    Sfr31TakeTop(cvm, val);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt st = Sfr31Rd(ctx.stack, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(st)[i];
    Sfr31Wr(ctx.stack, 8, st - 0x20);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
        const UPInt frame = Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8;
        UPInt tr = Sfr31Rd(frame, 0);
        VM& vm = *reinterpret_cast<VM*>(vmAddr);
        if (!SetSuperProperty(vm, reinterpret_cast<const Traits*>(tr), *reinterpret_cast<const Value*>(&obj), mn, *reinterpret_cast<const Value*>(&val)))
        {
            VM::Error e(static_cast<VM::ErrorID>(0x40b), vm);
            vm.ThrowReferenceError(e);
        }
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    reinterpret_cast<Value*>(&val)->~Value();
}
// ---- batch 45
// Native with a required object argument: the current frame's parent-traits helper is invoked with the remaining arguments.
// MS2-FUNCTIONAL 0x1425363e0: raw-offset model; codegen differs from the exe
// @0x1425363e0
void Sfr31ExecCallSuper(UPInt vmAddr, UInt32 a, UInt32 n)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, n);
    const UPInt frame = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    const UPInt top = Sfr31Rd(frame, 8);
    Sfr31RawTraitsVal val;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&val)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(frame, 8, top - 0x20);
    Sfr31ThrowIfNullOperand(vmAddr, reinterpret_cast<const UInt32*>(&val));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt cnt = Sfr31Rd(vmAddr, 0x78) - 1;
        UPInt tr = Sfr31Rd(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (cnt >> 6) * 8) + 0x40 + (cnt & 0x3f) * 0xa8, 0);
        if (tr == 0)
            tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(&val)));
        const UPInt parent = Sfr31Rd(tr, 0x88);
        if (parent != 0)
        {
            const UInt32 argc = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
            void* args = argc > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
            FUN_142500260(vmAddr, a, parent, &val, n, args);
        }
        else
        {
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d7850(eb, 0x40b, reinterpret_cast<void*>(vmAddr), "Couldn't find parent property");
            vm.ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
        }
    }
    reinterpret_cast<Value*>(&val)->~Value();
    FUN_1424de9e0(raBuf);
}
// ---- batch 46
ASString FUN_14250bc60(const Traits& tr);
const char* FUN_1424ed700(Abc::NamespaceKind kind);

// The name a value's type shows under in messages: the builtin names, qualified class names or the kind-specific forms.
// MS2-FUNCTIONAL 0x1425322c0: raw-offset model; codegen differs from the exe
// @0x1425322c0
ASString* Sfr31ValueTypeName(UPInt vmAddr, ASString* out, const UInt32* v)
{
    const UPInt helper = Sfr31Rd(vmAddr, 0x10);
    ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(helper, 0x1e8));
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    const UPInt aux = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x18);
    UPInt node;
    switch (v[0] & 0x1f)
    {
    case 0: node = Sfr31Rd(helper, 8); break;
    case 1: node = Sfr31Rd(helper, 0x30); break;
    case 2: node = reinterpret_cast<UPInt>(mgr->CreateConstStringNode("int", 3, 0)); break;
    case 3: node = reinterpret_cast<UPInt>(mgr->CreateConstStringNode("uint", 4, 0)); break;
    case 4: node = Sfr31Rd(helper, 0x38); break;
    case 5:
    {
        UPInt slot = Sfr31Rd(helper, 0);
        *reinterpret_cast<SInt32*>(slot + 0x18) += 1;
        FUN_14250f330(out, &slot, obj, 0);
        return out;
    }
    case 7:
    {
        UPInt slot = Sfr31Rd(helper, 0);
        *reinterpret_cast<SInt32*>(slot + 0x18) += 1;
        FUN_14250fc60(out, &slot, FUN_14250fa80(aux), v[4], 0);
        return out;
    }
    case 10: node = Sfr31Rd(helper, obj != 0 ? 0x40 : 0x10); break;
    case 0xb:
    {
        const char* c = FUN_1424ed700(static_cast<Abc::NamespaceKind>(Sfr31Rd(obj, 0x20) & 0xf));
        UPInt len = 0;
        while (c[len] != '\0')
            ++len;
        ASString s(mgr->CreateConstStringNode(c, len, 0));
        if (*reinterpret_cast<const SInt32*>(Sfr31Rd(obj, 0x30) + 0x20) != 0)
        {
            s.Append(" ", 1);
            s.Append(*reinterpret_cast<const ASString*>(obj + 0x30));
        }
        new (out) ASString(s);
        return out;
    }
    case 0xc:
        if (obj != 0)
            new (out) ASString(FUN_14250bc60(*reinterpret_cast<const Traits*>(Sfr31Rd(obj, 0x20))));
        else
            new (out) ASString(reinterpret_cast<ASStringNode*>(Sfr31Rd(helper, 0x10)));
        return out;
    case 0xd:
        if (obj != 0)
        {
            ASString s = FUN_14250bc60(*reinterpret_cast<const Traits*>(Sfr31Rd(obj, 0x20)));
            s.Append("$", 1);
            new (out) ASString(s);
        }
        else
            new (out) ASString(reinterpret_cast<ASStringNode*>(Sfr31Rd(helper, 0x10)));
        return out;
    case 0xe:
    {
        const UPInt inner = Sfr31Rd(obj, 0x20);
        const UPInt cls = reinterpret_cast<UPInt>(FUN_142416720(reinterpret_cast<const void*>(inner)));
        ASString nm(reinterpret_cast<ASStringNode*>(Sfr31Rd(helper, 0)));
        typedef void (*GetName)(UPInt, ASString*);
        (*reinterpret_cast<GetName*>(Sfr31Rd(inner, 0) + 0x38))(inner, &nm);
        ASString head = FUN_14250bc60(*reinterpret_cast<const Traits*>(cls));
        new (out) ASString(head + "::" + nm);
        return out;
    }
    case 0xf:
    {
        ASString n = FUN_14250bc60(*reinterpret_cast<const Traits*>(Sfr31Rd(obj, 0x48)));
        UPInt slot = reinterpret_cast<UPInt>(n.GetNode());
        *reinterpret_cast<SInt32*>(slot + 0x18) += 1;
        FUN_14250f330(out, &slot, Sfr31Rd(obj, 0x40), 0);
        return out;
    }
    case 0x10:
    {
        ASString n = FUN_14250bc60(*reinterpret_cast<const Traits*>(Sfr31Rd(aux, 0x20)));
        UPInt slot = reinterpret_cast<UPInt>(n.GetNode());
        *reinterpret_cast<SInt32*>(slot + 0x18) += 1;
        FUN_14250f330(out, &slot, obj, 1);
        return out;
    }
    case 0x11:
    {
        ASString n = FUN_14250bc60(*reinterpret_cast<const Traits*>(Sfr31Rd(aux, 0x20)));
        UPInt slot = reinterpret_cast<UPInt>(n.GetNode());
        *reinterpret_cast<SInt32*>(slot + 0x18) += 1;
        FUN_14250fc60(out, &slot, FUN_14250fa80(Sfr31Rd(aux, 0x20)), v[4], 1);
        return out;
    }
    default: node = Sfr31Rd(helper, 0); break;
    }
    new (out) ASString(reinterpret_cast<ASStringNode*>(node));
    return out;
}
// ---- batch 47
// newobject: builds a plain Object from n name/value pairs popped off the operand stack and pushes it.
// MS2-FUNCTIONAL 0x14253cdc0: raw-offset model; codegen differs from the exe
// @0x14253cdc0
void Sfr31ExecNewObject(UPInt vmAddr, UInt32 n)
{
    InstanceTraits::Interface* tr = reinterpret_cast<InstanceTraits::Interface*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x1f8), 0xc0));
    Value result(tr->MakeInstance(*tr));
    Instances::fl::Object* o = static_cast<Instances::fl::Object*>(result.GetObject());
    for (UInt32 i = 0; i < n; ++i)
    {
        Sfr31RawTraitsVal val;
        Sfr31TakeTop(vmAddr, val);
        Sfr31RawTraitsVal name;
        Sfr31TakeTop(vmAddr, name);
        o->AddDynamicSlotValuePair(*reinterpret_cast<const Value*>(&name), *reinterpret_cast<const Value*>(&val));
        reinterpret_cast<Value*>(&name)->~Value();
        reinterpret_cast<Value*>(&val)->~Value();
    }
    ExecPushCopy(reinterpret_cast<VM*>(vmAddr), result);
}
// ---- batch 48
// callsuper body shared by the two instantiations: pops the receiver, reads the named property through the frame's super traits
// and calls it with the popped arguments.
static void Sfr31CallSuperBody(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, reinterpret_cast<VM*>(cvm), argc);
    const UPInt frame0 = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    Sfr31ExecMnCtx ctx = {cvm, frame0, file};
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(&ctx, &mn);
    const UPInt top = Sfr31Rd(frame0, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(frame0, 8, top - 0x20);
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        Value callee;
        const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
        const UPInt frame = Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8;
        UInt8 ret[16];
        UInt8* r = FUN_14250ef80(ret, vmAddr, Sfr31Rd(frame, 0), &callee, &obj, &mn, 0);
        if (*r != 0)
        {
            Value result(Value::GetUndefined());
            const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
            const void* args = cnt > 8 ? reinterpret_cast<const void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<const void*>(raBuf + 0x18);
            FUN_1424fef00(reinterpret_cast<void*>(vmAddr), &callee, &obj, &result, argc, args, 1);
        }
        else
        {
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d6f40(eb, 0x42e, reinterpret_cast<void*>(vmAddr), reinterpret_cast<UInt8*>(&mn) + 0x10);
            reinterpret_cast<VM*>(vmAddr)->ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
        }
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    FUN_1424de9e0(raBuf);
}

// callsuper opcode: calls a method of the super class on the popped receiver.
// MS2-FUNCTIONAL 0x142535af0: raw-offset model; codegen differs from the exe
// @0x142535af0
void Sfr31ExecCallSuperArgsA(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc) { Sfr31CallSuperBody(vmAddr, file, idx, argc); }

// callsuper opcode, second instantiation (same body).
// MS2-FUNCTIONAL 0x142536660: raw-offset model; codegen differs from the exe
// @0x142536660
void Sfr31ExecCallSuperArgsB(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc) { Sfr31CallSuperBody(vmAddr, file, idx, argc); }
// ---- batch 49
// Stores the accessor-prefixed name for a slot: kind 0xb keeps the name, 0xc stores "get " + name at idx, 0xd stores "set " + name at idx + 1.
// MS2-FUNCTIONAL 0x1425283c0: raw-offset model; the string concatenation goes through the string manager directly
// @0x1425283c0
void Sfr31StoreSlotName(UPInt vt, UInt32 idx, int kind, const UPInt* name)
{
    UPInt* names = reinterpret_cast<UPInt*>(vt + 0x20);
    if (names[1] <= idx)
        FUN_142524470(names, idx + 1);
    UPInt slotIdx = idx;
    const char* prefix = 0;
    if (kind == 0xc)
        prefix = "get ";
    else if (kind == 0xd)
    {
        slotIdx = idx + 1;
        if (names[1] <= slotIdx)
            FUN_142524470(names, idx + 2);
        prefix = "set ";
    }
    else if (kind != 0xb)
        return;
    UPInt* slot = reinterpret_cast<UPInt*>(names[0]) + slotIdx;
    UPInt node = *name;
    if (prefix == 0)
    {
        ++*reinterpret_cast<int*>(node + 0x18);
    }
    else
    {
        ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(*slot, 8));
        ASStringNode* n = mgr->CreateStringNode(prefix, 4, reinterpret_cast<const char*>(Sfr31Rd(node, 0)),
                                                *reinterpret_cast<const UInt32*>(node + 0x20));
        node = reinterpret_cast<UPInt>(n);
        ++*reinterpret_cast<int*>(node + 0x18);
    }
    Sfr31ReleaseStr(*slot);
    *slot = node;
}

// Records a value in the slot table: the name goes in through the accessor-name store, then the value cell at the slot (or slot + 1 for setters) is assigned.
// MS2-FUNCTIONAL 0x1425282d0: raw-offset model; codegen differs from the exe
// @0x1425282d0
void Sfr31StoreSlotValue(UPInt vt, UPInt idx, const Value* v, int kind, const UPInt* name)
{
    Value* cell = 0;
    if (kind > 10)
    {
        if (kind < 0xd)
            cell = reinterpret_cast<Value*>(Sfr31Rd(vt, 8) + (idx & 0xffffffffu) * 0x20);
        else if (kind == 0xd)
            cell = reinterpret_cast<Value*>(Sfr31Rd(vt, 8) + static_cast<UPInt>(static_cast<UInt32>(idx) + 1) * 0x20);
    }
    Sfr31StoreSlotName(vt, static_cast<UInt32>(idx), kind, name);
    if ((*reinterpret_cast<const UInt32*>(v) & 0x1f) == 2)
    {
        UPInt raw[4] = {6, 0, 0, Sfr31Rd(vt, 0)};
        *reinterpret_cast<UInt32*>(&raw[2]) = *reinterpret_cast<const UInt32*>(reinterpret_cast<const char*>(v) + 0x10);
        cell->Assign(*reinterpret_cast<const Value*>(raw));
    }
    else
        cell->Assign(*v);
}
// ---- batch 50
// Puts the display object into the button's render container for the state (rebuilding the container first), records it in the state's
// mask-stack slot and, when that state is the current one, switches to it.
// MS2-FUNCTIONAL 0x142529f70: raw-offset model; codegen differs from the exe
// @0x142529f70
void Sfr31ButtonSetStateObject(UPInt self, int state, UPInt obj)
{
    const UPInt btn = Sfr31Rd(self, 0x18);
    if (state != 3)
    {
        UPInt cont = Sfr31Rd(btn, (static_cast<UPInt>(state) + 7) * 0x20);
        if (cont != 0)
        {
            ++*reinterpret_cast<UPInt*>(cont + 8);
            FUN_14261cf50(cont, 0, FUN_14250dbc0(cont));
        }
        else
        {
            UPInt out = 0;
            UPInt* p = FUN_1425ddd50(btn, &out, state);
            cont = *p;
            if (cont != 0)
                ++*reinterpret_cast<UPInt*>(cont + 8);
            cont = *p;
            if (out != 0 && --*reinterpret_cast<UPInt*>(out + 8) == 0)
                FUN_142581700(out);
        }
        const UPInt owner = Sfr31Rd(obj, 0x38);
        if (owner != 0 && (owner != btn || Sfr31Rd(FUN_1425f26c0(obj), 0x20) != cont))
        {
            const UPInt sub = owner + *reinterpret_cast<const UInt8*>(owner + 0x6d) * 4;
            typedef unsigned char (*Fn)(UPInt, UPInt);
            if (reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(sub, 0), 0xa8))(sub, obj) != 0)
                Sfr31Wr(obj, 0x38, btn);
        }
        if (Sfr31Rd(FUN_1425f26c0(obj), 0x20) == 0)
            FUN_14261c690(cont, FUN_14250dbc0(cont), FUN_1425f26c0(obj));
        if (cont != 0 && --*reinterpret_cast<UPInt*>(cont + 8) == 0)
            FUN_142581700(cont);
    }
    UPInt* arr = reinterpret_cast<UPInt*>(btn + static_cast<UPInt>(state) * 0x20 + 0xe8);
    if (obj == 0)
        FUN_1425248e0(arr, arr, 0);
    else
    {
        const UPInt old = arr[1];
        FUN_1425248e0(arr, arr, 1);
        if (old == 0)
            *reinterpret_cast<UPInt*>(arr[0]) = 0;
        UPInt* slot = reinterpret_cast<UPInt*>(arr[0]);
        ++*reinterpret_cast<int*>(obj + 8);
        if (*slot != 0)
            FUN_14257dcd0(reinterpret_cast<void*>(*slot));
        *slot = obj;
    }
    if (FUN_1425de200(*reinterpret_cast<const int*>(btn + 0x168)) == state)
        Sfr31ButtonSwitchStateIntl(self, state);
}
// ---- batch 51
// Applies a 2x4 matrix to the display object behind a value (movie-clip-like kinds only): the matrix goes to the object with its
// translation in twips, and the position, scale and rotation properties are re-derived from it.
// MS2-FUNCTIONAL 0x1425270e0: raw-offset model; codegen differs from the exe
// @0x1425270e0
bool Sfr31SetDisplayMatrix(UPInt self, UPInt valueObj, const float* m)
{
    const UPInt info = Sfr31Rd(valueObj, 0x20);
    if (*reinterpret_cast<const SInt32*>(info + 0x70) - 0x11u >= 0xc || (~(*reinterpret_cast<const UInt8*>(info + 0x68) >> 5) & 1) == 0)
        return false;
    DisplayObjectBase* obj = reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(valueObj, 0x58));
    if (!reinterpret_cast<const Render::Matrix2x4<float>*>(m)->IsValid())
        return false;
    float tm[8] = {m[0], m[1], m[2], m[3] * 20.0f, m[4], m[5], m[6], m[7] * 20.0f};
    typedef void (*Fn)(DisplayObjectBase*, const float*);
    reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(obj), 0), 0x18))(obj, tm);
    DisplayObjectBase::GeomDataType gd;
    obj->GetGeomData(gd);
    const double y = m[4];
    const double x = m[0];
    gd.X = static_cast<int>(m[3]);
    gd.Y = static_cast<int>(m[7]);
    gd.XScale = sqrt(x * x + y * y) * 100.0;
    gd.YScale = sqrt(static_cast<double>(m[1]) * m[1] + static_cast<double>(m[5]) * m[5]) * 100.0;
    gd.Rotation = (atan2(y, x) * 180.0) / 3.141592653589793;
    obj->SetGeomData(gd);
    return true;
}
// ---- batch 52
// call-style opcode on the popped value: a null operand is a TypeError; an object kind is dispatched through its own call slot with the
// remaining arguments; class kinds and everything else raise TypeErrors naming the offender.
// MS2-FUNCTIONAL 0x142536f40: raw-offset model; codegen differs from the exe
// @0x142536f40
void Sfr31ExecCallValue(UPInt vmAddr, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, argc);
    const UInt32* v = reinterpret_cast<const UInt32*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8), 8));
    Sfr31ThrowIfNullOperand(vmAddr, v);
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UInt32 kind = v[0] & 0x1f;
        const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
        if (kind == 0 || (kind - 0xc < 4 && obj == 0))
        {
            VM::Error e(static_cast<VM::ErrorID>(0x3f1), vm);
            vm.ThrowTypeError(e);
        }
        else if (kind == 7 || kind == 0x11)
        {
            const UPInt tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(v)));
            UPInt nameNode = 0;
            Sfr31VFnName nf = *reinterpret_cast<Sfr31VFnName*>(Sfr31Rd(tr, 0) + 0x38);
            UPInt* p = nf(tr, &nameNode);
            UPInt raw[4] = {10, 0, *p, 0};
            if (*p == Sfr31Rd(*p, 8) + 0x68)
                raw[0] = 0xc, raw[2] = 0;
            else
                ++*reinterpret_cast<int*>(*p + 0x18);
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d6f40(eb, 0x428, &vm, raw);
            vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
            reinterpret_cast<Value*>(raw)->~Value();
            Sfr31ReleaseStr(nameNode);
        }
        else if (kind - 0xc < 4)
        {
            const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
            void* args = cnt > 8 ? reinterpret_cast<void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<void*>(raBuf + 0x18);
            typedef void (*Fn)(UPInt, const UInt32*, UInt32, void*, bool);
            reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(obj, 0), 0x60))(obj, v, argc, args, false);
        }
        else
        {
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d6f40(eb, 0x45b, &vm, v);
            vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
        }
    }
    FUN_1424de9e0(raBuf);
}
// ---- batch 53
// Tears down a class traits' member tables: unregisters it, empties its arrays and hashes, and takes every traits recorded in the
// slot-name hash out of the owner's registration list.
// MS2-FUNCTIONAL 0x1425303b0: raw-offset model; codegen differs from the exe
// @0x1425303b0
void Sfr31ClassTraitsCleanup(UPInt self)
{
    const UPInt owner = Sfr31Rd(self, 0x20);
    if (FUN_142522a60(owner, self) == 0)
        return;
    Sfr31UnregisterClassTraits(self);
    for (UPInt i = Sfr31Rd(self, 0xc0); i != 0; --i)
        FUN_1425247f0(reinterpret_cast<UPInt*>(Sfr31Rd(self, 0xb8)) + (Sfr31Rd(self, 0xc0) - i) * 3, 0);
    FUN_1425244e0(reinterpret_cast<UPInt*>(self + 0xb8), 0);
    FUN_1424ef7b0(self + 0x38);
    const UPInt table = Sfr31Rd(self, 0x70);
    if (table != 0)
    {
        const SPInt mask = static_cast<SPInt>(Sfr31Rd(table, 8));
        for (SPInt i = 0; i <= mask; ++i)
        {
            const UPInt t = Sfr31Rd(self, 0x70);
            if (t == 0 || static_cast<SPInt>(Sfr31Rd(t, 8)) < i)
                break;
            const UPInt e = t + 0x10 + static_cast<UPInt>(i) * 0x18;
            if (static_cast<SPInt>(Sfr31Rd(e, 0)) == -2)
                continue;
            const UPInt val = Sfr31Rd(e, 0x10);
            UPInt n = Sfr31Rd(owner, 0x1b0);
            UPInt* data = reinterpret_cast<UPInt*>(Sfr31Rd(owner, 0x1a8));
            for (UPInt j = 0; j < n; ++j)
            {
                if (data[j] != val)
                    continue;
                if (n == 1)
                {
                    if ((Sfr31Rd(owner, 0x1b8) & ~static_cast<UPInt>(1)) != 0)
                    {
                        if (data != 0)
                        {
                            Memory::Free(data);
                            Sfr31Wr(owner, 0x1a8, 0);
                        }
                        Sfr31Wr(owner, 0x1b8, 0);
                    }
                    Sfr31Wr(owner, 0x1b0, 0);
                }
                else
                {
                    memmove(data + j, data + j + 1, (n - j) * 8 - 8);
                    Sfr31Wr(owner, 0x1b0, n - 1);
                }
                break;
            }
        }
    }
    FUN_1424ef860(self + 0x70);
    FUN_142524c30(reinterpret_cast<UPInt*>(self + 0x78), reinterpret_cast<const void*>(self + 0x78), 0);
    FUN_1424ef5b0(self + 0x30);
    FUN_142524680(reinterpret_cast<UPInt*>(self + 0x40), 0);
    FUN_142524a30(reinterpret_cast<UPInt*>(self + 0x58), reinterpret_cast<const void*>(self + 0x58), 0);
    FUN_1424ef500(self + 0x90);
    FUN_1424ef450(self + 0x98);
    FUN_142524710(reinterpret_cast<UPInt*>(self + 0xd0), 0);
}
// ---- batch 54
static inline UPInt Sfr31SubObj(UPInt o) { return o + *reinterpret_cast<const UInt8*>(o + 0x6d) * 4; }
static inline UPInt Sfr31VCall0(UPInt self, UPInt off)
{
    typedef UPInt (*Fn)(UPInt);
    return reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(self, 0), off))(self);
}

// Moves the button's state objects: every other state's object is detached from the button, then the object of the requested state is
// attached to its render container (once) and the container is appended to the button's own.
// MS2-FUNCTIONAL 0x14252e9d0: raw-offset model; codegen differs from the exe
// @0x14252e9d0
void Sfr31ButtonSwitchStateIntl(UPInt self, int state)
{
    const UPInt btn = Sfr31Rd(self, 0x18);
    const UInt16 f = *reinterpret_cast<const UInt16*>(btn + 0x6a);
    if ((f & 0x10) != 0 || (f & 0x1000) != 0 || *reinterpret_cast<const SInt32*>(btn + 0x2c) < -1)
        return;
    UPInt c = Sfr31VCall0(btn, 0x1f8);
    if (FUN_14250dbc0(c) != 0)
    {
        c = Sfr31VCall0(btn, 0x1f8);
        FUN_14261cf50(c, 0, 1);
    }
    typedef UPInt (*Fn2)(UPInt, UPInt);
    for (int s = 0; s < 3; ++s)
    {
        if (Sfr31Rd(btn, static_cast<UPInt>(s) * 0x20 + 0xf0) == 0)
            continue;
        const UPInt first = Sfr31Rd(Sfr31Rd(btn, static_cast<UPInt>(s) * 0x20 + 0xe8), 0);
        const UPInt io = (*reinterpret_cast<const UInt8*>(first + 0x6b) & 1) != 0 ? first : 0;
        const UPInt br = (*reinterpret_cast<const UInt16*>(io + 0x6a) >> 9 & 1) != 0 ? io : 0;
        const UPInt owner = Sfr31Rd(io, 0x38);
        if (s != state && owner != 0)
        {
            const UPInt sub = Sfr31SubObj(owner);
            reinterpret_cast<Fn2>(Sfr31Rd(Sfr31Rd(sub, 0), 0xa8))(sub, io);
            Sfr31Wr(io, 0x38, 0);
            if (br != 0)
            {
                const UPInt l = Sfr31VCall0(Sfr31SubObj(br), 8);
                FUN_142517ed0(reinterpret_cast<void*>(l != 0 ? l - 0x30 : 0));
            }
        }
    }
    if (Sfr31Rd(btn, static_cast<UPInt>(state) * 0x20 + 0xf0) == 0)
        return;
    const UPInt first = Sfr31Rd(Sfr31Rd(btn, static_cast<UPInt>(state) * 0x20 + 0xe8), 0);
    const UPInt io = (*reinterpret_cast<const UInt8*>(first + 0x6b) & 1) != 0 ? first : 0;
    const UPInt br = (*reinterpret_cast<const UInt16*>(io + 0x6a) >> 9 & 1) != 0 ? io : 0;
    const UPInt cont = Sfr31Rd(btn, (static_cast<UPInt>(state) + 7) * 0x20);
    if (cont != 0)
        ++*reinterpret_cast<UPInt*>(cont + 8);
    UPInt owner = Sfr31Rd(io, 0x38);
    bool detach = owner != 0;
    if (owner == btn && Sfr31Rd(FUN_1425f26c0(io), 0x20) == cont)
        detach = false;
    if (detach)
    {
        owner = Sfr31Rd(io, 0x38);
        const UPInt sub = owner != 0 ? Sfr31SubObj(owner) : 0;
        reinterpret_cast<Fn2>(Sfr31Rd(Sfr31Rd(sub, 0), 0xa8))(sub, io);
    }
    if (Sfr31Rd(FUN_1425f26c0(io), 0x20) == 0)
        FUN_14261c690(cont, FUN_14250dbc0(cont), FUN_1425f26c0(io));
    if (Sfr31Rd(io, 0x38) == 0)
    {
        Sfr31Wr(io, 0x38, btn);
        if (br != 0)
        {
            const UPInt l = Sfr31VCall0(Sfr31SubObj(br), 8);
            FUN_142517ed0(reinterpret_cast<void*>(l != 0 ? l - 0x30 : 0));
            typedef void (*Fn3)(UPInt, UPInt);
            for (UPInt i = 0; i < Sfr31Rd(br, 0xe0); ++i)
            {
                const UPInt child = Sfr31Rd(Sfr31Rd(br, 0xd8) + i * 0x10, 0);
                if ((*reinterpret_cast<const UInt16*>(child + 0x6a) >> 10 & 1) != 0)
                {
                    // Sprite::GotoFrame(0), then SetPlayState(State_Playing)
                    reinterpret_cast<Fn3>(Sfr31Rd(Sfr31Rd(child, 0), 0x340))(child, 0);
                    reinterpret_cast<Fn3>(Sfr31Rd(Sfr31Rd(child, 0), 0x360))(child, 0);
                }
            }
        }
    }
    const UPInt own = Sfr31VCall0(btn, 0x1f8);
    FUN_14261c690(own, FUN_14250dbc0(own), cont);
    if (cont != 0 && --*reinterpret_cast<UPInt*>(cont + 8) == 0)
        FUN_142581700(cont);
}
// ---- batch 55
// Raises an error: instantiates the error class named by the ClassInfo (resolved through the class traits cache), constructs it
// with the message and error id, stores it as the pending exception and sets the halt flag.
// MS2-FUNCTIONAL 0x14252ecb0: raw-offset model; the class lookup is shared with the class-description resolver
// @0x14252ecb0
void Sfr31VMRaiseError(UPInt vmAddr, const UInt32* err, UPInt classInfo)
{
    UPInt fake[4] = {0, 0, 0, classInfo };
    // the resolver reads the type description through +0x18; point it at the ClassInfo itself
    ClassTraits::Traits* ct = Sfr31GetClassTraitsByInfo(reinterpret_cast<VM*>(vmAddr), reinterpret_cast<UPInt>(fake));
    Value inst;
    const UPInt it = Sfr31Rd(reinterpret_cast<UPInt>(ct), 0xc0);
    typedef void (*MakeFn)(UPInt, Value*, UPInt);
    reinterpret_cast<MakeFn>(Sfr31Rd(Sfr31Rd(it, 0), 0x70))(it, &inst, it);
    const UPInt msg = Sfr31Rd(reinterpret_cast<UPInt>(err), 8);
    UPInt args[8] = {10, 0, msg, 0, 2, 0, 0, 0};
    if (msg == Sfr31Rd(msg, 8) + 0x68)
        args[0] = 0xc, args[2] = 0;
    else
        ++*reinterpret_cast<int*>(msg + 0x18);
    *reinterpret_cast<UInt32*>(reinterpret_cast<char*>(&args[6])) = err[0];
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(&inst), 0x10);
    typedef void (*CtorFn)(UPInt, int, void*);
    reinterpret_cast<CtorFn>(Sfr31Rd(Sfr31Rd(obj, 0), 0x58))(obj, 2, args);
    *reinterpret_cast<UInt8*>(vmAddr + 0x180) = 1;
    reinterpret_cast<Value*>(vmAddr + 0x188)->Assign(inst);
    reinterpret_cast<Value*>(&args[4])->~Value();
    reinterpret_cast<Value*>(&args[0])->~Value();
}
// ---- batch 56
// Checks that a value converts to a string: null-ish operands convert directly; otherwise the object's public toString is invoked
// and its result converted. Writes the success flag through ret.
// MS2-FUNCTIONAL 0x14252f9b0: models the inlined "toString" multiname construction with the Multiname ctor
// @0x14252f9b0
char* Sfr31ValueToStringCheck(char* ret, VM* vm, Value* v, void* strOut)
{
    UPInt tmpNode;
    const UInt32 k = v->GetKind() & 0x1f;
    if (k == 0 || (k - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10) == 0))
    {
        *ret = *FUN_1424f1390(v, &tmpNode, strOut) ? 1 : 0;
        return ret;
    }
    ASString nm(reinterpret_cast<ASStringManager*>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(vm), 0x10), 0x1e8))->CreateConstStringNode("toString", 8, 0));
    Multiname mn(vm->GetPublicNamespace(), Value(nm));
    Value res;
    bool ok = *FUN_1424ff910(reinterpret_cast<char*>(&tmpNode), vm, &mn, v, &res, 0, 0) != 0;
    if (ok && (res.GetKind() & 0x1f) != 10)
        ok = *FUN_1424f1390(&res, &tmpNode, strOut) != 0;
    *ret = ok ? 1 : 0;
    return ret;
}

// Converts a value in place to an XML-escaped string for element content. Null/undefined operands raise TypeError
// 1009/1010.
// MS2-FUNCTIONAL 0x14252fef0: raw-offset model; codegen differs from the exe
// @0x14252fef0
CheckResult XMLSupportImpl::ToXMLString(VM& vm, Value& val) const
{
    Value* v = &val;
    const UPInt vp = reinterpret_cast<UPInt>(v);
    const UPInt vmAddr = reinterpret_cast<UPInt>(&vm);
    const UInt32 k = *reinterpret_cast<const UInt32*>(vp) & 0x1f;
    ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x10), 0x1e8));
    if (k == 0 || (k - 0xc < 4 && Sfr31Rd(vp, 0x10) == 0))
    {
        // null (an object kind with no object) is 1009, undefined 1010
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(k - 0xc < 4 ? 0x3f1 : 0x3f2), vm));
        return false;
    }
    if (k < 5)
    {
        return v->ToStringValue(vm.GetStringManager());
    }
    if (k == 10)
    {
        // escaped into its own buffer, then falls through to be escaped again as a primitive (as the SDK does)
        StringBuffer sbuf(Memory::pGlobalHeap);
        ASString cur(reinterpret_cast<ASStringNode*>(Sfr31Rd(vp, 0x10)));
        Instances::fl::XML::EscapeElementValue(sbuf, cur);
        const char* c = sbuf.ToCStr();
        ASString res(mgr->CreateStringNode(c ? c : "", sbuf.GetSize()));
        *v = res;
    }
    StringBuffer buf(Memory::pGlobalHeap);
    const UInt32 k2 = (*reinterpret_cast<const UInt32*>(vp) & 0x1f) - 0xc;
    const UPInt obj = Sfr31Rd(vp, 0x10);
    if (k2 < 4 && obj != 0 && *reinterpret_cast<const int*>(Sfr31Rd(obj, 0x20) + 0x70) == 0xd && !(*reinterpret_cast<const UInt8*>(Sfr31Rd(obj, 0x20) + 0x68) & 0x20))
    {
        typedef void (*ToStrFn)(UPInt, StringBuffer*, int, int, int);
        reinterpret_cast<ToStrFn>(Sfr31Rd(Sfr31Rd(obj, 0), 0xd0))(obj, &buf, 0, 0, 0);
    }
    else if (k2 < 4 && obj != 0 && *reinterpret_cast<const int*>(Sfr31Rd(obj, 0x20) + 0x70) == 0xe && !(*reinterpret_cast<const UInt8*>(Sfr31Rd(obj, 0x20) + 0x68) & 0x20))
    {
        const UPInt m2 = Sfr31Rd(Sfr31Rd(Sfr31Rd(Sfr31Rd(obj, 0x20), 0x78), 0x10), 0x1e8);
        ASString s(reinterpret_cast<ASStringNode*>(m2 + 0x40));
        FUN_142403310(obj, &s);
        *v = s;
        return true;
    }
    else
    {
        UInt8 ok;
        Sfr31ValueToPrimitive(v, &ok);
        const UInt32 k3 = *reinterpret_cast<const UInt32*>(vp) & 0x1f;
        if (!ok || (k3 > 4 && k3 != 10))
        {
            return false;
        }
        ASString e(reinterpret_cast<ASStringNode*>(Sfr31Rd(Sfr31Rd(vmAddr, 0x10), 0x1e8) + 0x40));
        UPInt tn = 0;
        if (*FUN_1424f1390(v, &tn, &e))
            *v = e;
        ASString cur(reinterpret_cast<ASStringNode*>(Sfr31Rd(vp, 0x10)));
        Instances::fl::XML::EscapeElementValue(buf, cur);
    }
    const char* c = buf.ToCStr();
    ASString res(mgr->CreateStringNode(c ? c : "", buf.GetSize()));
    *v = res;
    return true;
}

// ---- batch 57
// Number to decimal string (ECMAScript style): integers print plainly, NaN/Infinity by name, other values with %.16g
// (integer digit count up to 21 for 1e16..1e21); exponents lose leading zeros and small negative exponents expand to 0.000ddd form. Returns the length.
// MS2-FUNCTIONAL 0x142525f20: precision selection follows the exe (%.16g, %.17g-%.21g for 1e16..1e21); codegen and the exponent rewrite differ
// @0x142525f20
SPInt Sfr31NumberToChars(char* out, int size, double d)
{
    if (d == static_cast<double>(static_cast<int>(d)))
    {
        const int n = static_cast<int>(SFsprintf(out, static_cast<UPInt>(size), "%d", static_cast<int>(d)));
        return n;
    }
    if (d != d)
    {
        SFsprintf(out, static_cast<UPInt>(size), "NaN");
        return 3;
    }
    if (d == HUGE_VAL)
    {
        SFsprintf(out, static_cast<UPInt>(size), "Infinity");
        return 8;
    }
    if (d == -HUGE_VAL)
    {
        SFsprintf(out, static_cast<UPInt>(size), "-Infinity");
        return 9;
    }
    char tmp[40] = {};
    // The exe prints with %.16g, widened to the integer digit count (17..21) for 1e16 <= |d| < 1e21.
    char fmt[6] = {'%', '.', '1', '6', 'g', '\0'};
    const double a = fabs(d);
    if (a >= 1e16 && a < 1e21)
    {
        if (a < 1e17)
            fmt[3] = '7';
        else if (a < 1e18)
            fmt[3] = '8';
        else if (a < 1e19)
            fmt[3] = '9';
        else
        {
            fmt[2] = '2';
            fmt[3] = a >= 1e20 ? '1' : '0';
        }
    }
    SFsprintf(tmp, sizeof(tmp), fmt, d);
    char* e = tmp;
    while (*e && *e != 'e')
        ++e;
    char mant[40];
    int ml = static_cast<int>(e - tmp);
    for (int i = 0; i < ml; ++i)
        mant[i] = tmp[i] == ',' ? '.' : tmp[i];
    mant[ml] = '\0';
    char* o = out;
    if (*e == 'e')
    {
        const char* x = e + 1;
        const bool neg = *x == '-';
        if (*x == '-' || *x == '+')
            ++x;
        while (*x == '0')
            ++x;
        int ex = 0;
        for (const char* y = x; *y >= '0' && *y <= '9'; ++y)
            ex = ex * 10 + (*y - '0');
        // The exe expands only a d.ddd mantissa (0x142526250: first digit 1-9, '.' after it); "1e-05" stays "1e-5".
        const char* lead = mant[0] == '-' ? mant + 1 : mant;
        if (neg && ex >= 1 && ex <= 6 && *lead >= '1' && *lead <= '9' && lead[1] == '.')
        {
            const char* m = mant;
            if (*m == '-')
                *o++ = *m++;
            *o++ = '0';
            *o++ = '.';
            for (int i = 1; i < ex; ++i)
                *o++ = '0';
            for (; *m; ++m)
                if (*m >= '0' && *m <= '9')
                    *o++ = *m;
            *o = '\0';
            return o - out;
        }
        for (int i = 0; i < ml; ++i)
            *o++ = mant[i];
        *o++ = 'e';
        if (*e && (e[1] == '-' || e[1] == '+'))
            *o++ = e[1];
        for (const char* y = x; *y; ++y)
            *o++ = *y;
        *o = '\0';
        return o - out;
    }
    for (int i = 0; i < ml; ++i)
        *o++ = mant[i];
    *o = '\0';
    return o - out;
}

// ---- batch 58
// Tracer getslot: pops the object, resolves its traits and pushes the declared type of the slot (nullability from the declared
// instance traits); an unresolvable slot type is a verify error, an unknown object type pushes undefined.
// MS2-FUNCTIONAL 0x142539f30: raw-offset model; codegen differs from the exe
// @0x142539f30
void Sfr31TraceGetSlot(State* st, UInt32 slot)
{
    StV s(st);
    const UPInt tracer = s.Tracer();
    FUN_14251fcd0(tracer, slot);
    VM* vm = reinterpret_cast<VM*>(TrRd(TrRd(TrRd(tracer, 0x20), 0x28), 0x20));
    const UPInt vmA = reinterpret_cast<UPInt>(vm);
    TrPopped popped;
    FUN_14251cd30(st, &popped.Get());
    const UInt32 k = popped.w0 & 0x1f;
    UPInt tr;
    if (k == 0)
        tr = TrRd(vmA, 0x278);
    else if (k == 8 || k == 9)
        tr = popped.w2;
    else
        tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(*vm, popped.Get()));
    bool pushed = false;
    if (tr != 0)
    {
        if (tr == TrRd(vmA, 0x1f0))
            tr = TrRd(vmA, 0x1f8);
        if (tr != 0)
        {
            pushed = true;
            if (TrRd(tr, 0x38) + TrRd(tr, 0x20) < slot)
            {
                TrTraitsScratch t;
                t.w0 = 0x48;
                t.SetTraits(*reinterpret_cast<InstanceTraits::Traits*>(TrRd(TrRd(vmA, 0x1f8), 0xc0)));
                s.OpStack().PushBack(t.Get());
            }
            else
            {
                const SPInt idx = static_cast<SPInt>(slot) - 1 + static_cast<UInt32>(TrRd(tr, 0x50));  // 64-bit (lea/add at 0x14253a021)
                const SlotInfo* si = &reinterpret_cast<Traits*>(tr)->GetSlotInfo(AbsoluteIndex(idx));
                ClassTraits::Traits* ct = FUN_1425085b0(si, reinterpret_cast<VM*>(TrRd(tr, 0x78)));
                if (ct == NULL)
                {
                    RawASString typeName;
                    FUN_142508720(si, &typeName.Get(), vm);
                    Value tv(typeName.Get());
                    vm->ThrowVerifyError(Sfr31Err(static_cast<VM::ErrorID>(0x3f6), *vm, tv));
                }
                else
                {
                    InstanceTraits::Traits* it = reinterpret_cast<InstanceTraits::Traits*>(TrRd(reinterpret_cast<UPInt>(ct), 0xc0));
                    const UPInt aux = TrRd(reinterpret_cast<UPInt>(si), 0x20);
                    const bool isClass = (*reinterpret_cast<const UInt32*>(si) & 0x3e0) == 0x20 ||
                                         (aux != 0 && (*reinterpret_cast<const UInt8*>(aux) & 0xf) == 4);
                    TrTraitsScratch t;
                    t.w0 = (static_cast<UInt32>(reinterpret_cast<const TR::State*>(st)->CanBeNull(*it)) & 0x7fffff7u) << 5;
                    if (isClass)
                    {
                        t.w0 |= 9;
                        t.w2 = reinterpret_cast<UPInt>(ct);
                    }
                    else
                    {
                        t.w0 |= 8;
                        t.SetTraits(*it);
                    }
                    s.OpStack().PushBack(t.Get());
                }
            }
        }
    }
    if (!pushed)
        s.OpStack().PushBack(Value::GetUndefined());
    popped.Get().~Value();
}

// ---- batch 59
// Peephole for "increment/decrement; convert; setlocal N" on register N: when the register's known type matches, the sequence
// is replaced by one specialized opcode and the register is converted. Returns whether the sequence was consumed.
// MS2-FUNCTIONAL 0x14252cd80: raw-offset model; codegen differs from the exe
// @0x14252cd80
bool Sfr31TracerOptRegIncDec(UPInt tracer, UPInt* pos, UPInt code0, UPInt state, UInt32 reg)
{
    const UInt8* code = reinterpret_cast<const UInt8*>(Sfr31Rd(tracer, 0x50));
    UPInt* posArr = reinterpret_cast<UPInt*>(tracer + 0x70);
    const UInt32* regv = reinterpret_cast<const UInt32*>(Sfr31Rd(state, 0x18) + static_cast<UPInt>(reg) * 0x20);
    const UInt8 op = code[code0];
    UPInt p = code0 + 1;
    if (op != 0x91 && op != 0x93 && op - 0xc0u > 1)
        return false;
    FUN_142524870(posArr, posArr[1] + 1);
    reinterpret_cast<UPInt*>(posArr[0])[posArr[1] - 1] = p;
    int curTy = 4;
    int want;
    UInt8 next = code[p++];
    UPInt pushed;
    if (next == 0x73 || next == 0x74 || next == 0x75)
    {
        want = next == 0x73 ? 2 : (next == 0x74 ? 3 : 4);
        FUN_142524870(posArr, posArr[1] + 1);
        pushed = 2;
        reinterpret_cast<UPInt*>(posArr[0])[posArr[1] - 1] = p;
        next = code[p++];
    }
    else
    {
        pushed = 1;
        want = op - 0xc0u > 1 ? 4 : 2;
    }
    UInt32 r;
    if (next == 0x63)
        r = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, p));
    else if (next >= 0xd4 && next <= 0xd7)
        r = next - 0xd4u;
    else
        r = 0xffffffffu - 1;
    if ((next != 0x63 && !(next >= 0xd4 && next <= 0xd7)) || r != reg)
    {
        FUN_142524870(posArr, posArr[1] - pushed);
        return false;
    }
    const UInt32 k = regv[0] & 0x1f;
    const UPInt vmA = TrVM(tracer);
    UPInt tr;
    if (k == 0)
        tr = Sfr31Rd(vmA, 0x278);
    else if (k == 8 || k == 9)
        tr = Sfr31Rd(reinterpret_cast<UPInt>(regv), 0x10);
    else
        tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(*reinterpret_cast<VM*>(vmA), *reinterpret_cast<const Value*>(regv)));
    if (tr != 0)
    {
        if (tr == Sfr31Rd(vmA, 0x1f0))
            tr = Sfr31Rd(vmA, 0x1f8);
        if (tr != 0 && !((*reinterpret_cast<const UInt8*>(tr + 0x68) >> 5) & 1))
            curTy = *reinterpret_cast<const int*>(tr + 0x70);
    }
    int newOp;
    if (op == 0x91 || op == 0xc0)
    {
        if (curTy == want)
            newOp = curTy == 2 ? 10 : (curTy == 3 ? 0x37 : (curTy == 4 ? 0x92 : 0));
        else
            newOp = want != 2 ? 0x92 : 0xc2;
    }
    else
    {
        if (curTy == want)
            newOp = curTy == 2 ? 0xb : (curTy == 3 ? 0x38 : (curTy == 4 ? 0x94 : 0));
        else
            newOp = want == 2 ? 0xc3 : 0x94;
    }
    if (newOp != 0)
    {
        FUN_14251fb90(reinterpret_cast<void*>(tracer), newOp, static_cast<SPInt>(static_cast<SInt32>(reg)));
        // the register takes the new opcode's type: Number (0x92/0x94), uint (0x37/0x38), else int
        if (newOp == 0x92 || newOp == 0x94)
            reinterpret_cast<State*>(state)->RegNumber(reg);
        else if (newOp == 0x37 || newOp == 0x38)
            reinterpret_cast<State*>(state)->RegUInt(reg);
        else
            reinterpret_cast<State*>(state)->RegInt(reg);
    }
    Sfr31TracerSkipOrigOpCode(tracer, pos, p);
    return true;
}

// ---- batch 60
// exec_in: pops the object; the name below it is replaced by whether the object has that property. A null object is a TypeError.
// MS2-FUNCTIONAL 0x14253b020: raw-offset model; codegen differs from the exe
// @0x14253b020
void Sfr31ExecIn(UPInt vmAddr)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    Sfr31RawTraitsVal obj;
    Sfr31TakeTop(vmAddr, obj);
    const UInt32 ok = obj.w0 & 0x1f;
    Value* name = reinterpret_cast<Value*>(Sfr31Rd(vmAddr, 0x50));
    if (ok == 0 || (ok - 0xc < 4 && obj.w2 == 0))
    {
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f1), vm));
        reinterpret_cast<Value*>(&obj)->~Value();
        return;
    }
    Multiname mn(vm.GetPublicNamespace());
    mn.SetRTNameUnsafe(*name);
    bool found;
    const UPInt tr = ok - 0xc < 4 ? Sfr31Rd(obj.w2, 0x20) : 0;
    if (ok - 0xc < 4 && ((*reinterpret_cast<const UInt8*>(tr + 0x68) & 1) ||
                        (*reinterpret_cast<const int*>(tr + 0x70) == 0xd && !((*reinterpret_cast<const UInt8*>(tr + 0x68) >> 5) & 1))))
    {
        Value undef(Value::GetUndefined());
        typedef bool* (*HasFn)(UPInt, void*, void*, void*);
        UInt8 tmp[8];
        found = *reinterpret_cast<HasFn>(Sfr31Rd(Sfr31Rd(obj.w2, 0), 0x38))(obj.w2, tmp, &mn, &undef);
    }
    else
    {
        PropRef prop;
        FUN_142501b00(&prop, &vm, reinterpret_cast<const Value*>(&obj), &mn, 0);
        found = prop;
    }
    name->SetBool(found);
    reinterpret_cast<Value*>(&obj)->~Value();
}

// ---- batch 61
// exec_getclass-style op: the operand must be a class object (or null when the entry has no base); the class entry resolves to its
// class object, except classes in the "scaleform.gfx" package, which must exist as a property of the global object.
// MS2-FUNCTIONAL 0x14253c470: raw-offset model; codegen differs from the exe
// @0x14253c470
void Sfr31ExecClassEntry(UPInt vmAddr, UPInt link, UInt32 idx)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    const UPInt file = Sfr31Rd(link, 0x28);
    const UPInt cls = Sfr31Rd(Sfr31Rd(file, 0x140), static_cast<UPInt>(idx) * 8);
    UInt32* top = reinterpret_cast<UInt32*>(Sfr31Rd(vmAddr, 0x50));
    const UInt32 k = top[0] & 0x1f;
    bool ok;
    if (k == 0 || (k - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10) == 0))
        ok = *reinterpret_cast<const int*>(cls + 0x28) == 0;
    else
        ok = k == 0xd;
    if (!ok)
    {
        vm.ThrowTypeError(VM::Error(static_cast<VM::ErrorID>(0x3f1), vm));
        return;
    }
    const SPInt mnIdx = *reinterpret_cast<const int*>(cls + 0x24);
    const UPInt mnE = mnIdx == 0 ? file + 0xe8 : mnIdx * 0x10 + Sfr31Rd(file, 0xb8);
    const UPInt ns = FUN_14250ae60(link, *reinterpret_cast<const int*>(mnE + 4));
    const UPInt uri = Sfr31Rd(ns, 0x30);
    if (*reinterpret_cast<const UInt32*>(uri + 0x20) < 13 || strncmp(reinterpret_cast<const char*>(Sfr31Rd(uri, 0)), "scaleform.gfx", 13) != 0)
    {
        const UPInt tr = FUN_14250f9a0(vmAddr, link, cls);
        const UPInt inst = Sfr31Rd(tr, 0xc0);
        if (Sfr31Rd(inst, 0x80) != 0)
        {
            reinterpret_cast<Value*>(top)->Assign(reinterpret_cast<Class*>(Sfr31Rd(inst, 0x80)));   // the class object itself (exe: Assign(Class*))
            return;
        }
        SPtr<Class> made = reinterpret_cast<ClassTraits::Traits*>(tr)->FUN_142419e50();
        const UPInt obj = reinterpret_cast<UPInt>(made.GetPtr());
        made.GetRawRef() = NULL;   // the reference moves into the stack Value
        reinterpret_cast<Value*>(top)->~Value();
        top[0] = (top[0] & 0xffffffedu) | 0xd;
        *reinterpret_cast<UPInt*>(top + 4) = obj;
        *reinterpret_cast<UPInt*>(top + 6) = 0;
        return;
    }
    UPInt nameNode;
    FUN_14250b240(link, &nameNode, *reinterpret_cast<const int*>(mnE + 8));
    ASString name(reinterpret_cast<ASStringNode*>(nameNode));
    Multiname mn(*reinterpret_cast<Instances::Namespace*>(ns));
    Value nv(name);
    mn.SetRTNameUnsafe(nv);
    const UPInt glob = Sfr31Rd(vmAddr, 0x298);
    typedef bool* (*HasFn)(UPInt, void*, void*, void*);
    UInt8 tmp[8];
    const bool found = *reinterpret_cast<HasFn>(Sfr31Rd(Sfr31Rd(glob, 0), 0x38))(glob, tmp, &mn, top);
    if (!found)
    {
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x42d, &vm, name.ToCStr(), "scaleform.gfx");
        vm.ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
}

// ---- batch 62
// 3x4 matrix variant of SetDisplayMatrix (movie-clip-like kinds only): the matrix goes to the object with its translation in twips and
// the 3D position, z scale and the two rotations are re-derived from it.
// MS2-FUNCTIONAL 0x1425278d0: raw-offset model; codegen differs from the exe
// @0x1425278d0
bool Sfr31SetDisplayMatrix3D(UPInt self, UPInt valueObj, const float* m)
{
    (void)self;
    const UPInt info = Sfr31Rd(valueObj, 0x20);
    if (*reinterpret_cast<const SInt32*>(info + 0x70) - 0x11u >= 0xc || (~(*reinterpret_cast<const UInt8*>(info + 0x68) >> 5) & 1) == 0)
        return false;
    DisplayObjectBase* obj = reinterpret_cast<DisplayObjectBase*>(Sfr31Rd(valueObj, 0x58));
    for (int i = 0; i < 12; ++i)
        if (!(m[i] >= -3.40282346e38f && m[i] <= 3.40282346e38f))
            return false;
    float tm[12] = {m[0], m[1], m[2], m[3] * 20.0f, m[4], m[5], m[6], m[7] * 20.0f, m[8], m[9], m[10], m[11] * 20.0f};
    typedef void (*Fn)(DisplayObjectBase*, const float*);
    reinterpret_cast<Fn>(Sfr31Rd(Sfr31Rd(reinterpret_cast<UPInt>(obj), 0), 0x28))(obj, tm);
    DisplayObjectBase::GeomDataType gd;
    obj->GetGeomData(gd);
    gd.Z = m[11];
    gd.ZScale = static_cast<double>(sqrtf(m[2] * m[2] + m[6] * m[6] + m[10] * m[10])) * 100.0;
    const float inv0 = 1.0f / sqrtf(m[0] * m[0] + m[4] * m[4] + m[8] * m[8]);
    const float inv2 = 1.0f / sqrtf(m[2] * m[2] + m[6] * m[6] + m[10] * m[10]);
    float xr, yr;
    const float s = m[4] * inv0;
    if (s > 0.998f || s < -0.998f)
    {
        xr = 0.0f;
        yr = atan2f(m[2] * inv2, m[10] * inv2);
    }
    else
    {
        xr = atan2f(-(m[6] * inv2), m[5] * (1.0f / sqrtf(m[1] * m[1] + m[5] * m[5] + m[9] * m[9])));
        yr = atan2f(-(m[8] * inv0), m[0] * inv0);
    }
    gd.XRotation = (static_cast<double>(xr) * 180.0) / 3.141592653589793;
    gd.YRotation = (static_cast<double>(yr) * 180.0) / 3.141592653589793;
    obj->SetGeomData(gd);
    return true;
}
// ---- batch 63
// Super-property getter-and-call opcode: pops the receiver, resolves the frame's parent-slot accessor, runs it to get a function and
// calls that with the popped arguments.
// MS2-FUNCTIONAL 0x142535f40: raw-offset model; codegen differs from the exe
// @0x142535f40
void Sfr31ExecCallParentSlot(UPInt vmAddr, UInt32 slotIdx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, argc);
    const UPInt frame0 = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    const UPInt top = Sfr31Rd(frame0, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(frame0, 8, top - 0x20);
    Sfr31ThrowIfNullOperand(vmAddr, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt n = Sfr31Rd(vmAddr, 0x78) - 1;
        UPInt traits = Sfr31Rd(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), (n >> 6) * 8) + 0x40 + (n & 0x3f) * 0xa8, 0);
        if (traits == 0)
            traits = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(&obj)));
        if (Sfr31Rd(traits, 0x88) == 0)
        {
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d7850(eb, 0x40b, &vm, "Couldn't find parent property");
            vm.ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
        }
        else
        {
            Sfr31RawTraitsVal callee = {7, 0, slotIdx, Sfr31Rd(traits, 0x88)};
            Value fn;
            FUN_1424fef00(&vm, &callee, &obj, &fn, 0, 0, 0);
            if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
            {
                const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
                const void* args = cnt > 8 ? reinterpret_cast<const void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<const void*>(raBuf + 0x18);
                Value result(Value::GetUndefined());
                FUN_1424fef00(&vm, &fn, &obj, &result, argc, args, 1);
            }
        }
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    FUN_1424de9e0(raBuf);
}
// ---- batch 64
// callstatic opcode: pops the receiver, then runs the method body of the file's method idx on it with the popped arguments in a new
// call frame (the frame is named after the receiver's traits plus " callstatic").
// MS2-FUNCTIONAL 0x142535680: raw-offset model; codegen differs from the exe
// @0x142535680
void Sfr31ExecCallStatic(UPInt vmAddr, UPInt file, SInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, &vm, argc);
    const UPInt frame0 = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    const UPInt top = Sfr31Rd(frame0, 8);
    Sfr31RawTraitsVal obj;
    for (int i = 0; i < 8; ++i)
        reinterpret_cast<UInt32*>(&obj)[i] = reinterpret_cast<const UInt32*>(top)[i];
    Sfr31Wr(frame0, 8, top - 0x20);
    Sfr31ThrowIfNullOperand(vmAddr, reinterpret_cast<const UInt32*>(&obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UPInt abc = Sfr31Rd(file, 0x28);
        const UPInt traits = Sfr31Rd(obj.w2, 0x20);
        const SInt32 mbiInd = *reinterpret_cast<const SInt32*>(Sfr31Rd(Sfr31Rd(abc, 0xf8), idx * 8) + 8);
        alignas(8) UInt8 nm[sizeof(ASString)];
        typedef void (*GetNameFn)(UPInt, void*);
        reinterpret_cast<GetNameFn>(Sfr31Rd(Sfr31Rd(traits, 0), 0x38))(traits, nm);
        ASString& n = *reinterpret_cast<ASString*>(nm);
        ASString full = n + " callstatic";
        const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
        const Value* args = cnt > 8 ? reinterpret_cast<const Value*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : reinterpret_cast<const Value*>(raBuf + 0x18);
        vm.AddFrame(Value::GetUndefined(), *reinterpret_cast<VMAbcFile*>(file), mbiInd, *reinterpret_cast<const Value*>(&obj), argc, args, false,
                    *reinterpret_cast<const ScopeStackType*>(traits + 0xa0), *reinterpret_cast<const Traits*>(traits), full);
        n.~ASString();
    }
    reinterpret_cast<Value*>(&obj)->~Value();
    FUN_1424de9e0(raBuf);
}
// ---- batch 65
// getlex-style opcode on a compile-time name: resolves the multiname (no runtime parts) against the scope stack and pushes the property's
// value; a non-compile-time name is a TypeError and an unresolved one a ReferenceError.
// MS2-FUNCTIONAL 0x142539650: raw-offset model; codegen differs from the exe
// @0x142539650
void Sfr31ExecGetLexStatic(UPInt vmAddr, UPInt file, UInt32 idx)
{
    const UPInt cvm = Sfr31Rd(file, 0x20);
    const UPInt cfile = Sfr31Rd(file, 0x28);
    const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(file, idx));
    const UInt32 flags = *reinterpret_cast<const UInt32*>(entry);
    const UPInt nameSlot = Sfr31Rd(cfile, 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8;
    if ((flags & 3) == 1 || ((flags >> 2) & 1) != 0)
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        String name(reinterpret_cast<const char*>(sv[0]), sv[1]);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x436, reinterpret_cast<void*>(cvm), name.ToCStr(), "compile time");
        reinterpret_cast<VM*>(cvm)->ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) != 0)
        return;
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    UPInt pr[6] = {0, 0, 0, 0, 0, 0};
    FUN_142502570(vmAddr, pr, &mn);
    Value& res = *reinterpret_cast<Value*>(&pr[2]);
    const UPInt f = pr[0];
    if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
    {
        UPInt sv[2];
        FUN_142545310(nameSlot, sv);
        alignas(8) char eb[sizeof(VM::Error)];
        FUN_1424d7690(eb, 0x42d, reinterpret_cast<void*>(vmAddr), reinterpret_cast<const char*>(sv[0]), "any object on the scope stack");
        reinterpret_cast<VM*>(vmAddr)->ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
        reinterpret_cast<VM::Error*>(eb)->~Error();
    }
    else
    {
        Value e;
        const UPInt kind = f & 3;
        if (kind == 0)
        {
            UInt8 ret[16];
            const unsigned char* ok = FUN_14250e2d0(f, ret, reinterpret_cast<void*>(vmAddr), &e, &res, 0, 0);
            if (*ok != 0)
                ExecPushCopy(reinterpret_cast<VM*>(vmAddr), e);
        }
        else
        {
            if (kind == 1)
                e.Assign(*reinterpret_cast<const Value*>(f & ~static_cast<UPInt>(1)));
            else if (kind == 2)
            {
                const UPInt g = f & ~static_cast<UPInt>(2);
                UPInt raw[4] = { 0xc, 0, g, 0 };
                if (g != 0)
                    *reinterpret_cast<UInt32*>(g + 0x10) = (*reinterpret_cast<UInt32*>(g + 0x10) + 1u) & 0x8fbfffffu;
                e.Assign(*reinterpret_cast<const Value*>(raw));
                FUN_142521f00(raw);
            }
            ExecPushCopy(reinterpret_cast<VM*>(vmAddr), e);
        }
    }
    res.~Value();
}
// ---- batch 66
// hasnext2 opcode: registers objReg/idxReg hold the object and the enumeration index; advances the index (walking the prototype chain
// when the own properties are exhausted), stores both back and pushes whether another property exists.
// MS2-FUNCTIONAL 0x14253a6a0: raw-offset model; codegen differs from the exe
// @0x14253a6a0
void Sfr31ExecHasNext2(UPInt vmAddr, UInt32 objReg, UInt32 idxReg)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    const UPInt regs = Sfr31Rd(vmAddr, 0x148);
    Value* ov = reinterpret_cast<Value*>(regs + static_cast<UPInt>(objReg) * 0x20);
    Value* iv = reinterpret_cast<Value*>(regs + static_cast<UPInt>(idxReg) * 0x20);
    const UPInt ovp = reinterpret_cast<UPInt>(ov);
    if (idxReg == objReg)
    {
        VM::Error e(static_cast<VM::ErrorID>(0x464), vm);
        vm.ThrowTypeError(e);
        return;
    }
    const UInt32 kind = *reinterpret_cast<const UInt32*>(ov) & 0x1f;
    bool result = false;
    if (kind == 0 || (kind - 0xc < 4 && Sfr31Rd(ovp, 0x10) == 0))
    {
        UPInt top = Sfr31Rd(vmAddr, 0x50) + 0x20;
        Sfr31Wr(vmAddr, 0x50, top);
        Sfr31Wr(top, 0, 1);
        Sfr31Wr(top, 8, 0);
        Sfr31Wr(top, 0x10, 0);
        Sfr31Wr(top, 0x18, 0);
        return;
    }
    UInt32 next = 0;
    unsigned long idx = 0;
    UInt8 okTmp[16];
    if (*FUN_1424f1a30(iv, okTmp, &idx) == 0)
        return;
    typedef int* (*NextFn)(UPInt, void*, UInt32);
    typedef void (*MakeFn)(UPInt);
    if (kind - 0xc < 4)
    {
        const UPInt obj = Sfr31Rd(ovp, 0x10);
        reinterpret_cast<NextFn>(Sfr31Rd(Sfr31Rd(obj, 0), 0x88))(obj, &next, static_cast<UInt32>(idx));
        UPInt found = obj;
        UPInt t = Sfr31Rd(obj, 0x20);
        bool hit = false;
        for (; t != 0; t = Sfr31Rd(t, 0x88))
        {
            if (next != 0)
            {
                hit = true;
                break;
            }
            UPInt cls = Sfr31Rd(t, 0x80);
            if (cls == 0)
            {
                reinterpret_cast<MakeFn>(Sfr31Rd(Sfr31Rd(t, 0), 0x68))(t);
                cls = Sfr31Rd(t, 0x80);
            }
            found = reinterpret_cast<UPInt>(&reinterpret_cast<Class*>(cls)->GetPrototype());
            UInt8 tmp[16];
            next = *reinterpret_cast<UInt32*>(reinterpret_cast<NextFn>(Sfr31Rd(Sfr31Rd(found, 0), 0x88))(found, tmp, 0));
        }
        if (t == 0 && next == 0)
            ov->Assign(Value::GetNull());
        else if (found != obj)
        {
            UPInt raw[4] = { 0xc, 0, found, 0 };
            *reinterpret_cast<UInt32*>(found + 0x10) = (*reinterpret_cast<UInt32*>(found + 0x10) + 1u) & 0x8fbfffffu;
            ov->Assign(*reinterpret_cast<const Value*>(raw));
            FUN_142521f00(raw);
        }
        (void)hit;
    }
    else if (kind == 0xb)
        FUN_1424161e0(Sfr31Rd(ovp, 0x10), &next, static_cast<UInt32>(idx));
    else
    {
        const UPInt tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *ov));
        if (*reinterpret_cast<const SInt32*>(tr + 0x70) == 6 && (~(*reinterpret_cast<const UInt8*>(tr + 0x68) >> 5) & 1) != 0 && idx < 2)
        {
            iv->Assign(Value(static_cast<UInt32>(idx + 1)));
            result = true;
        }
        else
        {
            UPInt t = tr;
            UPInt proto = 0;
            UInt32 iVar = 0;
            bool nullIt = false;
            do
            {
                UPInt cls = Sfr31Rd(t, 0x80);
                if (cls == 0)
                {
                    reinterpret_cast<MakeFn>(Sfr31Rd(Sfr31Rd(t, 0), 0x68))(t);
                    cls = Sfr31Rd(t, 0x80);
                }
                proto = reinterpret_cast<UPInt>(&reinterpret_cast<Class*>(cls)->GetPrototype());
                UInt8 tmp[16];
                iVar = *reinterpret_cast<UInt32*>(reinterpret_cast<NextFn>(Sfr31Rd(Sfr31Rd(proto, 0), 0x88))(proto, tmp, 0));
                t = Sfr31Rd(t, 0x88);
                if (t == 0)
                {
                    nullIt = iVar == 0;
                    break;
                }
            } while (iVar == 0);
            if (nullIt)
                ov->Assign(Value::GetNull());
            else
            {
                UPInt raw[4] = { 0xc, 0, proto, 0 };
                *reinterpret_cast<UInt32*>(proto + 0x10) = (*reinterpret_cast<UInt32*>(proto + 0x10) + 1u) & 0x8fbfffffu;
                ov->Assign(*reinterpret_cast<const Value*>(raw));
                FUN_142521f00(raw);
            }
            iv->Assign(Value(static_cast<UInt32>(iVar)));
            result = iVar != 0;
        }
        UPInt top = Sfr31Rd(vmAddr, 0x50) + 0x20;
        Sfr31Wr(vmAddr, 0x50, top);
        Sfr31Wr(top, 0, 1);
        Sfr31Wr(top, 8, 0);
        Sfr31Wr(top, 0x10, result ? 1 : 0);
        Sfr31Wr(top, 0x18, 0);
        return;
    }
    iv->Assign(Value(next));
    result = next != 0;
    UPInt top = Sfr31Rd(vmAddr, 0x50) + 0x20;
    Sfr31Wr(vmAddr, 0x50, top);
    Sfr31Wr(top, 0, 1);
    Sfr31Wr(top, 8, 0);
    Sfr31Wr(top, 0x10, result ? 1 : 0);
    Sfr31Wr(top, 0x18, 0);
}
// ---- batch 67
// constructprop opcode: the receiver stays on the operand stack; a class named by a static multiname is constructed directly, otherwise
// the property is looked up on the receiver and the value found is constructed with the popped arguments.
// MS2-FUNCTIONAL 0x1425371f0: raw-offset model; codegen differs from the exe
// @0x1425371f0
void Sfr31ExecConstructProp(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    const UPInt cvm = Sfr31Rd(file, 0x20);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, reinterpret_cast<VM*>(cvm), argc);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(raBuf, &mn);
    const UPInt frame0 = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8);
    Value* recv = reinterpret_cast<Value*>(Sfr31Rd(frame0, 8));
    Sfr31ThrowIfNullOperand(cvm, reinterpret_cast<const UInt32*>(recv));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
        const void* args = cnt > 8 ? reinterpret_cast<const void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<const void*>(raBuf + 0x18);
        typedef void (*CtorFn)(UPInt, Value*, UInt32, const void*, bool);
        UPInt tr = 0;
        if ((*reinterpret_cast<const UInt32*>(&mn) & 3) < 2)
            tr = Sfr31FindClassTraitsByMn(reinterpret_cast<UPInt>(&vm), reinterpret_cast<UPInt>(&mn));
        if (tr != 0)
        {
            const UPInt itr = Sfr31Rd(tr, 0xc0);
            UPInt cls = Sfr31Rd(itr, 0x80);
            if (cls == 0)
            {
                typedef void (*MakeFn)(UPInt);
                reinterpret_cast<MakeFn>(Sfr31Rd(Sfr31Rd(itr, 0), 0x68))(itr);
                cls = Sfr31Rd(itr, 0x80);
            }
            reinterpret_cast<CtorFn>(Sfr31Rd(Sfr31Rd(cls, 0), 0x60))(cls, recv, argc, args, false);
        }
        else
        {
            UPInt pr[6] = {0, 0, 0, 0, 0, 0};
            FUN_142501b00(reinterpret_cast<PropRef*>(pr), &vm, recv, &mn, 0);
            Value& res = *reinterpret_cast<Value*>(&pr[2]);
            const UPInt f = pr[0];
            if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
            {
                alignas(8) char eb[sizeof(VM::Error)];
                FUN_1424d6cf0(eb, 0x42d, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10, recv);
                vm.ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
                reinterpret_cast<VM::Error*>(eb)->~Error();
            }
            else
            {
                Value e;
                const UPInt kind = f & 3;
                bool have = true;
                if (kind == 0)
                {
                    UInt8 ret[16];
                    have = *FUN_14250e2d0(f, ret, &vm, &e, &res, 0, 0) != 0;
                }
                else if (kind == 1)
                    e.Assign(*reinterpret_cast<const Value*>(f & ~static_cast<UPInt>(1)));
                else if (kind == 2)
                {
                    const UPInt g = f & ~static_cast<UPInt>(2);
                    UPInt raw[4] = { 0xc, 0, g, 0 };
                    if (g != 0)
                        *reinterpret_cast<UInt32*>(g + 0x10) = (*reinterpret_cast<UInt32*>(g + 0x10) + 1u) & 0x8fbfffffu;
                    e.Assign(*reinterpret_cast<const Value*>(raw));
                    FUN_142521f00(raw);
                }
                if (have)
                {
                    const UInt32 ek = *reinterpret_cast<const UInt32*>(&e) & 0x1f;
                    const UPInt eo = Sfr31Rd(reinterpret_cast<UPInt>(&e), 0x10);
                    if (ek == 0 || (ek - 0xc < 4 && eo == 0))
                    {
                        VM::Error er(static_cast<VM::ErrorID>(0x3f1), vm);
                        vm.ThrowTypeError(er);
                    }
                    else if (ek == 7 || ek == 0x11)
                    {
                        alignas(8) char eb[sizeof(VM::Error)];
                        FUN_1424d6f40(eb, 0x428, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10);
                        vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
                        reinterpret_cast<VM::Error*>(eb)->~Error();
                    }
                    else
                        reinterpret_cast<CtorFn>(Sfr31Rd(Sfr31Rd(eo, 0), 0x60))(eo, recv, argc, args, false);
                }
            }
            res.~Value();
        }
    }
    FUN_1424de9e0(raBuf);
}
// ---- batch 68
// newfunction opcode: builds the closure scope (the running frame's saved scope followed by what the innermost frame pushed on the scope
// stack), creates the Function of method methodInd on the Function class and pushes it.
// MS2-FUNCTIONAL 0x14253c910: raw-offset model; codegen differs from the exe
// @0x14253c910
void Sfr31ExecNewFunction(UPInt vmAddr, UPInt frame, UInt32 methodInd)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    ArrayDH<Value> ss(reinterpret_cast<MemoryHeap*>(Sfr31Rd(vmAddr, 0x38)));
    const ArrayDH<Value>* saved = reinterpret_cast<const ArrayDH<Value>*>(Sfr31Rd(frame, 0x38));
    if (saved != 0 && saved->GetSize() != 0)
        for (UPInt i = 0; i < saved->GetSize(); ++i)
            ss.PushBack((*saved)[i]);
    const UPInt nFrames = Sfr31Rd(vmAddr, 0x78);
    UPInt base = 0;
    if (nFrames != 0)
        base = Sfr31Rd(Sfr31Rd(Sfr31Rd(vmAddr, 0x90), ((nFrames - 1) >> 6) * 8) + ((nFrames - 1) & 0x3f) * 0xa8, 8);
    const UPInt scopeEnd = Sfr31Rd(vmAddr, 0x168);
    for (UPInt i = base; i < scopeEnd; ++i)
        ss.PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(vmAddr, 0x160) + i * 0x20));
    UPInt gos = 0;
    if (nFrames != 0)
    {
        const UPInt top = Sfr31Rd(Sfr31Rd(vmAddr, 0x90), ((nFrames - 1) >> 6) * 8) + ((nFrames - 1) & 0x3f) * 0xa8;
        const ArrayDH<Value>* sv = reinterpret_cast<const ArrayDH<Value>*>(Sfr31Rd(top, 0x38));
        if (sv == 0 || sv->GetSize() == 0)
        {
            const UPInt p = Sfr31Rd(Sfr31Rd(top, 0x18), 8);
            if (*reinterpret_cast<const UInt32*>(p) - 0xc & 0x1f)
                gos = 0;
            if (((*reinterpret_cast<const UInt32*>(p) & 0x1f) - 0xc) < 4)
                gos = Sfr31Rd(p, 0x10);
        }
        else
            gos = Sfr31Rd(reinterpret_cast<UPInt>(&(*sv)[0]), 0x10);
    }
    const UPInt ftr = Sfr31Rd(Sfr31Rd(vmAddr, 0x208), 0xc0);
    UPInt cls = Sfr31Rd(ftr, 0x80);
    if (cls == 0)
    {
        typedef void (*MakeFn)(UPInt);
        reinterpret_cast<MakeFn>(Sfr31Rd(Sfr31Rd(ftr, 0), 0x68))(ftr);
        cls = Sfr31Rd(ftr, 0x80);
    }
    Value v;
    v.PickUnsafe(reinterpret_cast<const Classes::Function*>(cls)->FUN_14241a7d0(
        *reinterpret_cast<VMAbcFile*>(Sfr31Rd(frame, 0x28)), methodInd, ss, *reinterpret_cast<Instances::fl::GlobalObjectScript*>(gos)));
    ExecPushCopy(&vm, v);
}
// ---- batch 69
// AS3ValueObjectInterface::SetMember: sets the named member of an object from a GFx value. "*" is the any-name and a leading "@" makes
// the name an attribute. A name that is already a child of a display object is refused with a log message.
// MS2-FUNCTIONAL 0x142527d60: raw-offset model; the abort message is composed with String instead of MsgFormat
// @0x142527d60
bool Sfr31ValueSetMember(UPInt self, Object* obj, const char* name, const void* gfxValue)
{
    const UPInt root = Sfr31Rd(Sfr31Rd(self, 8), 0x18);
    VM& vm = *reinterpret_cast<VM*>(Sfr31Rd(root, 0x48));
    ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348));
    ASString nameStr(mgr->CreateStringNode(name));
    Value nm;
    if (nameStr.GetNode() == reinterpret_cast<ASStringNode*>(reinterpret_cast<UPInt>(mgr) + 0x68))
        nm.SetNull();
    else
        nm.Assign(nameStr);
    Multiname mn(*reinterpret_cast<Instances::Namespace*>(Sfr31Rd(reinterpret_cast<UPInt>(&vm), 0x1d0)), nm);
    if (mn.Name.GetKind() == Value::kString)
    {
        ASStringNode* node = reinterpret_cast<ASStringNode*>(mn.Name.GetGASRefCountBase());
        node->AddRef();
        if (node->Size != 0)
        {
            ASStringNode* any = reinterpret_cast<ASStringNode*>(reinterpret_cast<UPInt>(node->pManager) + 0x40);
            if (node->pData[0] == '*')
                mn.Name.Assign(any);
            else if (node->pData[0] == '@')
            {
                *reinterpret_cast<UInt32*>(&mn) = 8;
                if (node->Size == 2 && node->pData[1] == '*')
                    mn.Name.Assign(any);
                else
                {
                    ASStringNode* sub = node->pManager->CreateStringNode(node->pData + 1, node->Size - 1);
                    mn.Name.Assign(sub);
                }
            }
        }
        node->Release();
    }
    const UPInt otraits = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x20);
    if (*reinterpret_cast<const int*>(otraits + 0x70) - 0x17U < 6 && ((~(*reinterpret_cast<const UByte*>(otraits + 0x68) >> 5)) & 1) != 0)
    {
        UPInt dobj = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x58);
        if (dobj != 0 && !((*reinterpret_cast<const UInt16*>(dobj + 0x6a) >> 9) & 1))
            dobj = 0;
        UPInt owner = 0x18;
        if (dobj != 0)
        {
            const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
            typedef UPInt (*GetAvmFn)(UPInt);
            const UPInt avm = reinterpret_cast<GetAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x28))(sub);
            owner = avm != 0 ? avm - 0x28 : 0x18;
        }
        ASString key(mgr->CreateStringNode(name));
        DisplayList* dl = reinterpret_cast<DisplayList*>(Sfr31Rd(owner, 0) + 0xd8);
        DisplayObject* ch = dl->GetDisplayObjectByName(key, true);
        if (ch != NULL)
        {
            const UPInt sub = reinterpret_cast<UPInt>(ch) + *reinterpret_cast<const UByte*>(reinterpret_cast<UPInt>(ch) + 0x6d) * 4;
            typedef void (*MakeAvmFn)(UPInt, int);
            reinterpret_cast<MakeAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x78))(sub, 1);
            UPInt avmObj = Sfr31Rd(sub, 0x10);
            if (avmObj == 0)
                avmObj = Sfr31Rd(sub, 8);
            if (avmObj & 1)
                avmObj -= 1;
            if (avmObj != 0)
            {
                String msg("Property '");
                msg += name;
                msg += "' already exists as a DisplayObject. SetMember aborted.";
                typedef void (*LogFn)(UPInt, int, const char*);
                reinterpret_cast<LogFn>(Sfr31Rd(Sfr31Rd(root + 0x28, 0), 8))(root + 0x28, 1, msg.ToCStr());
                return false;
            }
        }
    }
    Value val;
    FUN_1425048d0(root, gfxValue, &val);
    if (!obj->SetProperty(mn, val))
    {
        const UPInt vmAddr = reinterpret_cast<UPInt>(&vm);
        if (*reinterpret_cast<UByte*>(vmAddr + 0x180) != 0)
        {
            *reinterpret_cast<UByte*>(vmAddr + 0x180) = 0;
            vm.OutputError(*reinterpret_cast<Value*>(vmAddr + 0x188));
            reinterpret_cast<Value*>(vmAddr + 0x188)->SetUndefined();
        }
        return false;
    }
    return true;
}
// ---- batch 70
// The AS3 object the display object part of an interface object (at dobj) carries; created on first use.
static UPInt Sfr31AvmObjOfDisplay(UPInt dobj)
{
    const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
    typedef void (*MakeAvmFn)(UPInt, int);
    reinterpret_cast<MakeAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x78))(sub, 1);
    UPInt avmObj = Sfr31Rd(sub, 0x10);
    if (avmObj == 0)
        avmObj = Sfr31Rd(sub, 8);
    if (avmObj & 1)
        avmObj -= 1;
    return avmObj;
}

// AS3ValueObjectInterface::VisitMembers: the visitor receives the dynamic members, the public non-method slots (when it asks for them)
// and, for a display object container, its children by name.
// MS2-FUNCTIONAL 0x142531630: raw-offset model; codegen (register use, reference-count helpers) differs from the exe
// @0x142531630
void Sfr31ValueVisitMembers(UPInt self, Object* obj, UPInt visitor)
{
    typedef void (*VisitFn)(UPInt, const char*, const void*);
    typedef bool (*WantFn)(UPInt);
    const UPInt root = Sfr31Rd(Sfr31Rd(self, 8), 0x18);
    const VisitFn visit = reinterpret_cast<VisitFn>(Sfr31Rd(Sfr31Rd(visitor, 0), 0x10));
    const Object::DynAttrsType& attrs = *obj->GetDynamicAttrs();
    for (Object::DynAttrsType::ConstIterator it = attrs.Begin(); !it.IsEnd(); ++it)
    {
        GFx::Value gv;
        FUN_1424e42c0(root, &it->Second, &gv);
        visit(visitor, it->First.Name.ToCStr(), &gv);
    }
    if (reinterpret_cast<WantFn>(Sfr31Rd(Sfr31Rd(visitor, 0), 8))(visitor))
    {
        const Traits& tr = obj->GetTraits();
        const UPInt n = tr.GetSlotInfoNum();
        for (UPInt i = 0; i < n; ++i)
        {
            ASString name(tr.GetSlotNameNode(AbsoluteIndex(i)));
            const SlotInfo& si = tr.GetSlotInfo(AbsoluteIndex(i));
            const int bt = static_cast<int>(si.BindType);
            if (bt == 0xb || bt > 0xc || static_cast<int>(si.pNs->GetKind()) != 0)
                continue;
            Value v;
            char ok;
            FUN_14250e770(&si, &ok, &v, obj);
            GFx::Value gv;
            FUN_1424e42c0(root, &v, &gv);
            visit(visitor, name.ToCStr(), &gv);
        }
    }
    const UPInt otraits = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x20);
    if (*reinterpret_cast<const int*>(otraits + 0x70) - 0x17U > 5 || ((~(*reinterpret_cast<const UByte*>(otraits + 0x68) >> 5)) & 1) == 0)
        return;
    UPInt dobj = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x58);
    if (dobj != 0 && !((*reinterpret_cast<const UInt16*>(dobj + 0x6a) >> 9) & 1))
        dobj = 0;
    UPInt owner = 0x18;
    if (dobj != 0)
    {
        const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
        typedef UPInt (*GetAvmFn)(UPInt);
        const UPInt avm = reinterpret_cast<GetAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x28))(sub);
        owner = avm != 0 ? avm - 0x28 : 0x18;
    }
    const UPInt container = Sfr31Rd(owner, 0);
    for (UInt32 i = 0; i < *reinterpret_cast<const UInt32*>(container + 0xe0); ++i)
    {
        const UPInt child = FUN_1425fc530(container, i);
        if (child == 0)
            continue;
        const UPInt avmObj = Sfr31AvmObjOfDisplay(child);
        if (avmObj == 0)
            continue;
        ASString name = reinterpret_cast<DisplayObject*>(Sfr31Rd(avmObj, 0x58))->GetName();
        Value v(reinterpret_cast<Object*>(avmObj));
        GFx::Value gv;
        FUN_1424e42c0(root, &v, &gv);
        visit(visitor, name.ToCStr(), &gv);
    }
}
// ---- batch 71
// callpropvoid opcode: the receiver is popped, the property looked up on it (a missing one is an error unless the object is dynamic) and
// the value found called with the popped arguments, the result dropped.
// MS2-FUNCTIONAL 0x142534eb0: raw-offset model; codegen differs from the exe
// @0x142534eb0
void Sfr31ExecCallPropVoid(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, reinterpret_cast<VM*>(Sfr31Rd(file, 0x20)), argc);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(raBuf, &mn);
    const UPInt topSlot = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8) + 8;
    UPInt obj[4];
    for (int i = 0; i < 4; ++i)
        obj[i] = Sfr31Rd(Sfr31Rd(topSlot, 0), i * 8);
    Sfr31Wr(topSlot, 0, Sfr31Rd(topSlot, 0) - 0x20);
    Sfr31ThrowIfNullOperand(vmAddr, reinterpret_cast<const UInt32*>(obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UPInt pr[6] = {0, 0, 0, 0, 0, 0};
        FUN_142501b00(reinterpret_cast<PropRef*>(pr), &vm, reinterpret_cast<const Value*>(obj), &mn, 2);
        Value& res = *reinterpret_cast<Value*>(&pr[2]);
        const UPInt f = pr[0];
        if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
        {
            const UPInt traits = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(obj)));
            alignas(8) char eb[sizeof(VM::Error)];
            if (((*reinterpret_cast<const UInt8*>(traits + 0x68) >> 1) & 1) == 0)
            {
                FUN_1424d6cf0(eb, 0x42d, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10, obj);
                vm.ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
            }
            else
            {
                FUN_1424d6f40(eb, 0x3ee, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10);
                vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            }
            reinterpret_cast<VM::Error*>(eb)->~Error();
        }
        else
        {
            Value e;
            const UPInt kind = f & 3;
            bool have = true;
            if (kind == 0)
            {
                UInt8 ret[16];
                have = *FUN_14250e2d0(f, ret, &vm, &e, &res, 0, 0) != 0;
            }
            else if (kind == 1)
                e.Assign(*reinterpret_cast<const Value*>(f & ~static_cast<UPInt>(1)));
            else if (kind == 2)
            {
                const UPInt g = f & ~static_cast<UPInt>(2);
                UPInt raw[4] = { 0xc, 0, g, 0 };
                if (g != 0)
                    *reinterpret_cast<UInt32*>(g + 0x10) = (*reinterpret_cast<UInt32*>(g + 0x10) + 1u) & 0x8fbfffffu;
                e.Assign(*reinterpret_cast<const Value*>(raw));
                FUN_142521f00(raw);
            }
            if (have)
            {
                const UInt32 ek = *reinterpret_cast<const UInt32*>(&e) & 0x1f;
                const UPInt eo = Sfr31Rd(reinterpret_cast<UPInt>(&e), 0x10);
                if (ek != 0 && (ek - 0xc >= 4 || eo != 0))
                {
                    const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
                    const void* args = cnt > 8 ? reinterpret_cast<const void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<const void*>(raBuf + 0x18);
                    Value result(Value::GetUndefined());
                    FUN_1424fef00(&vm, &e, obj, &result, argc, args, 0);
                }
                else
                {
                    alignas(8) char eb[sizeof(VM::Error)];
                    FUN_1424d6f40(eb, 0x3ee, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10);
                    vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
                    reinterpret_cast<VM::Error*>(eb)->~Error();
                }
            }
        }
        res.~Value();
    }
    reinterpret_cast<Value*>(obj)->~Value();
    FUN_1424de9e0(raBuf);
}
// ---- batch 72
// callproplex opcode: the receiver is popped, the property looked up on it (a missing one is an error unless the object is dynamic) and
// the value found called with undefined as this and the popped arguments; the result is pushed.
// MS2-FUNCTIONAL 0x142534820: raw-offset model; codegen differs from the exe
// @0x142534820
void Sfr31ExecCallPropLex(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, reinterpret_cast<VM*>(Sfr31Rd(file, 0x20)), argc);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(raBuf, &mn);
    const UPInt topSlot = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8) + 8;
    UPInt obj[4];
    for (int i = 0; i < 4; ++i)
        obj[i] = Sfr31Rd(Sfr31Rd(topSlot, 0), i * 8);
    Sfr31Wr(topSlot, 0, Sfr31Rd(topSlot, 0) - 0x20);
    Sfr31ThrowIfNullOperand(vmAddr, reinterpret_cast<const UInt32*>(obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UPInt pr[6] = {0, 0, 0, 0, 0, 0};
        FUN_142501b00(reinterpret_cast<PropRef*>(pr), &vm, reinterpret_cast<const Value*>(obj), &mn, 2);
        Value& res = *reinterpret_cast<Value*>(&pr[2]);
        const UPInt f = pr[0];
        if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
        {
            const UPInt traits = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(obj)));
            alignas(8) char eb[sizeof(VM::Error)];
            if (((*reinterpret_cast<const UInt8*>(traits + 0x68) >> 1) & 1) == 0)
            {
                FUN_1424d6cf0(eb, 0x42d, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10, obj);
                vm.ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
            }
            else
            {
                FUN_1424d6f40(eb, 0x3ee, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10);
                vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            }
            reinterpret_cast<VM::Error*>(eb)->~Error();
        }
        else
        {
            Value e;
            const UPInt kind = f & 3;
            bool have = true;
            if (kind == 0)
            {
                UInt8 ret[16];
                have = *FUN_14250e2d0(f, ret, &vm, &e, &res, 0, 0) != 0;
            }
            else if (kind == 1)
                e.Assign(*reinterpret_cast<const Value*>(f & ~static_cast<UPInt>(1)));
            else if (kind == 2)
            {
                const UPInt g = f & ~static_cast<UPInt>(2);
                UPInt raw[4] = { 0xc, 0, g, 0 };
                if (g != 0)
                    *reinterpret_cast<UInt32*>(g + 0x10) = (*reinterpret_cast<UInt32*>(g + 0x10) + 1u) & 0x8fbfffffu;
                e.Assign(*reinterpret_cast<const Value*>(raw));
                FUN_142521f00(raw);
            }
            if (have)
            {
                const UInt32 ek = *reinterpret_cast<const UInt32*>(&e) & 0x1f;
                const UPInt eo = Sfr31Rd(reinterpret_cast<UPInt>(&e), 0x10);
                if (ek != 0 && (ek - 0xc >= 4 || eo != 0))
                {
                    const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
                    const void* args = cnt > 8 ? reinterpret_cast<const void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<const void*>(raBuf + 0x18);
                    Value result(Value::GetUndefined());
                    FUN_1424fef00(&vm, &e, &Value::GetUndefined(), &result, argc, args, 1);
                }
                else
                {
                    alignas(8) char eb[sizeof(VM::Error)];
                    FUN_1424d6f40(eb, 0x3ee, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10);
                    vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
                    reinterpret_cast<VM::Error*>(eb)->~Error();
                }
            }
        }
        res.~Value();
    }
    reinterpret_cast<Value*>(obj)->~Value();
    FUN_1424de9e0(raBuf);
}
// ---- batch 73
// MovieRoot::SetArray: copies count elements of the given kind (0 int, 1 double, 2 float as number, 3 char* string, 4 wchar_t* string,
// 5 GFx::Value) into the Array found at the variable path (a new one is created and stored when the variable is no Array).
// MS2-FUNCTIONAL 0x14252acc0: raw-offset model; codegen differs from the exe
// @0x14252acc0
bool Sfr31SetArray(UPInt root, int type, UPInt path, UInt32 start, const void* data, UInt32 count, UInt32 setVarType)
{
    UPInt cur[4] = { 0, 0, 0, 0 };
    const bool got = FUN_142506000(root, cur, path);
    UPInt arr = 0;
    if (got && ((reinterpret_cast<UInt32*>(cur)[0] & 0x1f) - 0xc) < 4 && cur[2] != 0 && Sfr31Rd(Sfr31Rd(cur[2], 0x20), 0x70) == 7 &&
        ((*reinterpret_cast<UInt8*>(Sfr31Rd(cur[2], 0x20) + 0x68) >> 5) & 1) == 0)
    {
        arr = cur[2];
        UInt32* rc = reinterpret_cast<UInt32*>(arr + 0x10);
        *rc = (*rc + 1) & 0x8fbfffff;
    }
    const bool existed = arr != 0;
    if (!existed)
    {
        const UPInt tr = Sfr31Rd(Sfr31Rd(Sfr31Rd(root, 0x48), 0x238), 0xc0);
        FUN_14241a500(tr, &arr, tr);
    }
    const UPInt sa = arr + 0x38;
    if (*reinterpret_cast<UInt32*>(sa) < start + count)
        FUN_14241fe30(reinterpret_cast<void*>(sa), start + count);
    for (UInt32 i = 0; i < count; ++i)
    {
        UPInt raw[4] = { 0, 0, 0, 0 };
        UInt32* kind = reinterpret_cast<UInt32*>(raw);
        UPInt strNode = 0;
        switch (type)
        {
        case 0:
            kind[0] = 2;
            kind[4] = static_cast<const UInt32*>(data)[i];
            break;
        case 1:
            kind[0] = 4;
            *reinterpret_cast<double*>(&raw[2]) = static_cast<const double*>(data)[i];
            break;
        case 2:
            kind[0] = 4;
            *reinterpret_cast<double*>(&raw[2]) = static_cast<double>(static_cast<const float*>(data)[i]);
            break;
        case 3:
        case 4:
        {
            ASStringManager* mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348));
            ASStringNode* n = (type == 3) ? mgr->CreateStringNode(static_cast<const char* const*>(data)[i])
                                          : mgr->CreateStringNode(static_cast<const wchar_t* const*>(data)[i], -1);
            strNode = reinterpret_cast<UPInt>(n);
            ++*reinterpret_cast<int*>(strNode + 0x18);
            kind[0] = 10;
            if (strNode == Sfr31Rd(strNode, 8) + 0x68)
                kind[0] = 0xc;
            else
            {
                ++*reinterpret_cast<int*>(strNode + 0x18);
                raw[2] = strNode;
            }
            break;
        }
        case 5:
            FUN_1425048d0(root, static_cast<const UPInt*>(data) + i * 4, reinterpret_cast<Value*>(raw));
            break;
        }
        FUN_1424213b0(sa, start + i, reinterpret_cast<const Value*>(raw));
        Sfr31ReleaseRawVal(raw);
        if (strNode != 0)
            Sfr31ReleaseStr(strNode);
    }
    bool ok = true;
    if (!existed)
    {
        UPInt nv[4] = { 0xc, 0, arr, 0 };
        UPInt gv[3] = { 0, 0, 0 };
        FUN_1424e42c0(root, reinterpret_cast<const Value*>(nv), gv);
        typedef bool (*SetVar)(UPInt, UPInt, void*, UInt32);
        ok = reinterpret_cast<SetVar>(Sfr31Rd(Sfr31Rd(root, 0), 0x138))(root, path, gv, setVarType);
        if ((reinterpret_cast<UInt32*>(gv)[2] >> 6) & 1)
        {
            typedef void (*Rel)(UPInt, UPInt*, UPInt);
            reinterpret_cast<Rel>(Sfr31Rd(Sfr31Rd(gv[0], 0), 0x10))(gv[0], gv, gv[2]);
        }
        Sfr31ReleaseRawVal(nv);
    }
    Sfr31ReleaseRawVal(cur);
    if (arr != 0 && (arr & 1) == 0 && (*reinterpret_cast<UInt32*>(arr + 0x10) & 0x3fffff) != 0)
    {
        --*reinterpret_cast<UInt32*>(arr + 0x10);
        FUN_1423dfa20(reinterpret_cast<void*>(arr));
    }
    return ok;
}
// ---- batch 74
// callproperty opcode: the receiver is popped, the property looked up on it (a missing one is an error unless the object is dynamic) and
// the value found called with the popped arguments, the result pushed.
// MS2-FUNCTIONAL 0x142534100: raw-offset model; codegen differs from the exe
// @0x142534100
void Sfr31ExecCallProperty(UPInt vmAddr, UPInt file, UInt32 idx, UInt32 argc)
{
    VM& vm = *reinterpret_cast<VM*>(vmAddr);
    UInt8 raBuf[0x140];
    FUN_1424d9530(raBuf, reinterpret_cast<VM*>(Sfr31Rd(file, 0x20)), argc);
    Multiname mn(*reinterpret_cast<VMAbcFile*>(file), Sfr31MnEntry(file, idx));
    FUN_1425201f0(raBuf, &mn);
    const UPInt topSlot = Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 8) + 8;
    UPInt obj[4];
    for (int i = 0; i < 4; ++i)
        obj[i] = Sfr31Rd(Sfr31Rd(topSlot, 0), i * 8);
    Sfr31Wr(topSlot, 0, Sfr31Rd(topSlot, 0) - 0x20);
    Sfr31ThrowIfNullOperand(vmAddr, reinterpret_cast<const UInt32*>(obj));
    if (*reinterpret_cast<UInt8*>(vmAddr + 0x180) == 0)
    {
        UPInt pr[6] = {0, 0, 0, 0, 0, 0};
        FUN_142501b00(reinterpret_cast<PropRef*>(pr), &vm, reinterpret_cast<const Value*>(obj), &mn, 2);
        Value& res = *reinterpret_cast<Value*>(&pr[2]);
        const UPInt f = pr[0];
        if ((*reinterpret_cast<const UInt32*>(&res) & 0x1f) == 0 || f == 1 || ((f & 2) != 0 && (f & ~static_cast<UPInt>(2)) == 0))
        {
            const UPInt traits = reinterpret_cast<UPInt>(&FUN_14250ffc0(vm, *reinterpret_cast<const Value*>(obj)));
            alignas(8) char eb[sizeof(VM::Error)];
            if (((*reinterpret_cast<const UInt8*>(traits + 0x68) >> 1) & 1) == 0)
            {
                FUN_1424d6cf0(eb, 0x42d, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10, obj);
                vm.ThrowReferenceError(*reinterpret_cast<VM::Error*>(eb));
            }
            else
            {
                FUN_1424d6f40(eb, 0x3ee, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10);
                vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
            }
            reinterpret_cast<VM::Error*>(eb)->~Error();
        }
        else
        {
            Value e;
            const UPInt kind = f & 3;
            bool have = true;
            if (kind == 0)
            {
                UInt8 ret[16];
                have = *FUN_14250e2d0(f, ret, &vm, &e, &res, 0, 0) != 0;
            }
            else if (kind == 1)
                e.Assign(*reinterpret_cast<const Value*>(f & ~static_cast<UPInt>(1)));
            else if (kind == 2)
            {
                const UPInt g = f & ~static_cast<UPInt>(2);
                UPInt raw[4] = { 0xc, 0, g, 0 };
                if (g != 0)
                    *reinterpret_cast<UInt32*>(g + 0x10) = (*reinterpret_cast<UInt32*>(g + 0x10) + 1u) & 0x8fbfffffu;
                e.Assign(*reinterpret_cast<const Value*>(raw));
                FUN_142521f00(raw);
            }
            if (have)
            {
                const UInt32 ek = *reinterpret_cast<const UInt32*>(&e) & 0x1f;
                const UPInt eo = Sfr31Rd(reinterpret_cast<UPInt>(&e), 0x10);
                if (ek != 0 && (ek - 0xc >= 4 || eo != 0))
                {
                    const UInt32 cnt = *reinterpret_cast<const UInt32*>(raBuf + 0x10);
                    const void* args = cnt > 8 ? reinterpret_cast<const void*>(Sfr31Rd(reinterpret_cast<UPInt>(raBuf), 0x118)) : static_cast<const void*>(raBuf + 0x18);
                    Value result(Value::GetUndefined());
                    FUN_1424fef00(&vm, &e, obj, &result, argc, args, 1);
                }
                else
                {
                    alignas(8) char eb[sizeof(VM::Error)];
                    FUN_1424d6f40(eb, 0x3ee, &vm, reinterpret_cast<UInt8*>(&mn) + 0x10);
                    vm.ThrowTypeError(*reinterpret_cast<VM::Error*>(eb));
                    reinterpret_cast<VM::Error*>(eb)->~Error();
                }
            }
        }
        res.~Value();
    }
    reinterpret_cast<Value*>(obj)->~Value();
    FUN_1424de9e0(raBuf);
}
// ---- batch 75
// Finds the entry of the sticky variable table (entries of 0x18 bytes from +0x10: next index, key string node, value) holding key.
// Returns its index (-1 when absent); prevIdx receives the index of the entry whose chain link leads to it (-1 for the chain head).
static SInt64 Sfr31StickyFind(UPInt tbl, UPInt key, SInt64& prevIdx)
{
    const UPInt mask = Sfr31Rd(tbl, 8);
    const UPInt natural = *reinterpret_cast<const UInt32*>(key + 0x1c) & mask;
    UPInt e = tbl + 0x10 + natural * 0x18;
    prevIdx = -1;
    if (static_cast<SInt64>(Sfr31Rd(e, 0)) == -2)
        return -1;
    if ((*reinterpret_cast<const UInt32*>(Sfr31Rd(e, 8) + 0x1c) & mask) != natural)
        return -1;
    SInt64 idx = static_cast<SInt64>(natural);
    for (;;)
    {
        const UPInt k = Sfr31Rd(e, 8);
        if ((*reinterpret_cast<const UInt32*>(k + 0x1c) & mask) == natural && k == key)
            return idx;
        const SInt64 nx = static_cast<SInt64>(Sfr31Rd(e, 0));
        if (nx == -1)
            return -1;
        prevIdx = idx;
        idx = nx;
        e = tbl + 0x10 + static_cast<UPInt>(nx) * 0x18;
    }
}

// MovieRoot: applies the sticky variables kept for a display object (SetVariable calls made before the object existed) to its AS3 object.
// The ones not marked permanent are dropped from the object's chain (and the chain from the table when none is left).
// MS2-FUNCTIONAL 0x142525500: raw-offset model; codegen differs from the exe
// @0x142525500
void Sfr31ResolveStickyVariables(UPInt root, UPInt dobj)
{
    UPInt handle = Sfr31Rd(dobj, 0x70);
    if (handle == 0)
        handle = reinterpret_cast<UPInt>(reinterpret_cast<DisplayObject*>(dobj)->GetCharacterHandle());
    const UPInt key = Sfr31Rd(handle, 0x18);
    const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
    typedef UPInt (*GetAvmFn)(UPInt);
    const UPInt avm = reinterpret_cast<GetAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 8))(sub);
    if (avm == 0)
        return;
    UPInt avmObj = Sfr31Rd(avm - 0x20, 0);
    if (avmObj == 0)
        avmObj = Sfr31Rd(avm - 0x28, 0);
    if (avmObj & 1)
        avmObj -= 1;
    const UPInt impl = Sfr31Rd(root, 0x10);
    UPInt tbl = Sfr31Rd(impl, 0x2e08);
    if (tbl == 0)
        return;
    SInt64 prev;
    SInt64 idx = Sfr31StickyFind(tbl, key, prev);
    if (idx < 0)
        return;
    const UPInt head = Sfr31Rd(tbl + 0x10 + static_cast<UPInt>(idx) * 0x18, 0x10);
    UPInt keptHead = 0;
    UPInt keptTail = 0;
    VM& vm = *reinterpret_cast<VM*>(Sfr31Rd(root, 0x48));
    UPInt node = head;
    while (node != 0)
    {
        const UPInt nameNode = Sfr31Rd(node, 8);
        ASString nameStr(reinterpret_cast<ASStringNode*>(nameNode));
        Value nm;
        if (nameNode == Sfr31Rd(nameNode, 8) + 0x68)
            nm.SetNull();
        else
            nm.Assign(nameStr);
        Multiname mn(*reinterpret_cast<Instances::Namespace*>(Sfr31Rd(reinterpret_cast<UPInt>(&vm), 0x1d0)), nm);
        reinterpret_cast<Object*>(avmObj)->SetProperty(mn, *reinterpret_cast<const Value*>(node + 0x20));
        const UPInt next = Sfr31Rd(node, 0x10);
        if (*reinterpret_cast<const UByte*>(node + 0x18) == 0)
        {
            typedef void (*DelFn)(UPInt, int);
            reinterpret_cast<DelFn>(Sfr31Rd(Sfr31Rd(node, 0), 0))(node, 1);
        }
        else if (keptHead == 0)
        {
            keptHead = keptTail = node;
            Sfr31Wr(node, 0x10, 0);
        }
        else
        {
            Sfr31Wr(keptTail, 0x10, node);
            keptTail = node;
            Sfr31Wr(node, 0x10, 0);
        }
        node = next;
    }
    if (keptHead != 0)
    {
        if (keptHead == head)
            return;
        tbl = Sfr31Rd(impl, 0x2e08);
        if (tbl != 0)
        {
            idx = Sfr31StickyFind(tbl, key, prev);
            if (idx >= 0)
            {
                const UPInt e = tbl + 0x10 + static_cast<UPInt>(idx) * 0x18;
                ++*reinterpret_cast<int*>(key + 0x18);
                Sfr31ReleaseStr(Sfr31Rd(e, 8));
                Sfr31Wr(e, 8, key);
                Sfr31Wr(e, 0x10, keptHead);
                return;
            }
        }
        UPInt nodeRef[2] = { key, keptHead };
        FUN_1424d4c10(reinterpret_cast<void*>(impl + 0x2e08), reinterpret_cast<void*>(impl + 0x2e08), nodeRef,
                      *reinterpret_cast<const UInt32*>(key + 0x1c));
        return;
    }
    tbl = Sfr31Rd(impl, 0x2e08);
    if (tbl == 0)
        return;
    idx = Sfr31StickyFind(tbl, key, prev);
    if (idx < 0)
        return;
    UPInt e = tbl + 0x10 + static_cast<UPInt>(idx) * 0x18;
    const UPInt natural = *reinterpret_cast<const UInt32*>(key + 0x1c) & Sfr31Rd(tbl, 8);
    if (static_cast<UPInt>(idx) == natural)
    {
        const SInt64 nx = static_cast<SInt64>(Sfr31Rd(e, 0));
        if (nx != -1)
        {
            const UPInt ne = tbl + 0x10 + static_cast<UPInt>(nx) * 0x18;
            Sfr31ReleaseStr(Sfr31Rd(e, 8));
            Sfr31Wr(e, 0, Sfr31Rd(ne, 0));
            Sfr31Wr(e, 8, Sfr31Rd(ne, 8));
            ++*reinterpret_cast<int*>(Sfr31Rd(ne, 8) + 0x18);
            Sfr31Wr(e, 0x10, Sfr31Rd(ne, 0x10));
            e = ne;
        }
    }
    else
        Sfr31Wr(tbl + 0x10 + static_cast<UPInt>(prev) * 0x18, 0, Sfr31Rd(e, 0));
    Sfr31ReleaseStr(Sfr31Rd(e, 8));
    Sfr31Wr(e, 0, static_cast<UPInt>(-2));
    --*reinterpret_cast<SInt64*>(tbl);
}
// ---- batch 76
// The display object part's AS3 object (without creating it): the pointer at +0x10, else the one at +0x8, minus the tag bit.
static inline UPInt Sfr31DispAvmPeek(UPInt dobj)
{
    const UPInt sub = dobj + *reinterpret_cast<const UByte*>(dobj + 0x6d) * 4;
    UPInt p = Sfr31Rd(sub, 0x10);
    if (p == 0)
        p = Sfr31Rd(sub, 8);
    return (p & 1) ? p - 1 : p;
}

// True when the AS3 object of dobj belongs to the movie definition def.
static inline bool Sfr31DispBelongsTo(UPInt dobj, UPInt def)
{
    const UPInt avmObj = Sfr31DispAvmPeek(dobj);
    if (avmObj == 0)
        return false;
    const UPInt traits = Sfr31Rd(avmObj, 0x20);
    typedef UPInt (*FileFn)(UPInt);
    const UPInt file = reinterpret_cast<FileFn>(Sfr31Rd(Sfr31Rd(traits, 0), 0x50))(traits);
    return file != 0 && Sfr31Rd(Sfr31Rd(file, 0x28), 0x188) == def;
}

// Drops the display objects of the movie definition def from an array of display object pointers (data, size, capacity).
static void Sfr31DropDispOfDef(UPInt* arr, UPInt def)
{
    UPInt i = 0;
    while (i < arr[1])
    {
        UPInt* data = reinterpret_cast<UPInt*>(arr[0]);
        const UPInt elem = data[i];
        if (elem == 0)
        {
            ++i;
            continue;
        }
        ++*reinterpret_cast<int*>(elem + 8);
        if (!Sfr31DispBelongsTo(elem, def))
            ++i;
        else if (arr[1] == 1)
            FUN_1425245c0(arr, 0);
        else
        {
            FUN_14257dcd0(reinterpret_cast<void*>(elem));
            data = reinterpret_cast<UPInt*>(arr[0]);
            memmove(data + i, data + i + 1, (arr[1] - i) * 8 - 8);
            --arr[1];
        }
        FUN_14257dcd0(reinterpret_cast<void*>(elem));
    }
}

// MovieRoot: a Loader's content goes away (unload): the content gets its unload event, the loaded movie definition is unregistered when
// its last user left (the objects, listeners, timers, fonts and root display objects of it are dropped too when asked to) and the
// text format caches are flushed.
// MS2-FUNCTIONAL 0x1425305f0: raw-offset model; codegen differs from the exe
// @0x1425305f0
void Sfr31UnloadLoaderContent(UPInt root, UPInt loader, bool dropAll, bool flagRoot)
{
    typedef Instances::fl_display::LoaderInfo LoaderInfo;
    LoaderInfo* li = reinterpret_cast<LoaderInfo*>(FUN_142443d90(loader));
    if (li)
        *reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(li) + 0x10) = (*reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(li) + 0x10) + 1) & 0x8fbfffff;
    UPInt keep = 0;
    if (li)
    {
        DisplayObject* content = li->GetContentDispObj();
        if (content)
        {
            ++*reinterpret_cast<int*>(reinterpret_cast<UPInt>(content) + 8);
            keep = reinterpret_cast<UPInt>(content);
        }
        ASString evType(reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348))->CreateConstStringNode("unload", 6, 0));
        SPtr<Instances::fl_events::Event> ev = li->CreateEventObject(evType, false, false);
        li->DispatchEventObject(ev.GetPtr(), li->GetContentDispObj());
    }
    reinterpret_cast<Instances::fl_display::Loader*>(loader)->ResetContent();
    const UPInt impl = Sfr31Rd(root, 0x10);
    for (UPInt n = Sfr31Rd(impl, 0x34a0); n != 0; n = Sfr31Rd(n, 8))
        if (Sfr31Rd(Sfr31Rd(n, 0x20), 0x28) == loader)
            *reinterpret_cast<UByte*>(Sfr31Rd(n, 0x20) + 0x25) = 1;
    for (UPInt n = Sfr31Rd(impl, 0x20); n != 0; n = Sfr31Rd(n, 8))
        if (Sfr31Rd(n, 0x28) == loader)
            *reinterpret_cast<UByte*>(n + 0x25) = 1;
    const UPInt owner = Sfr31Rd(loader, 0x58);
    UPInt cur = keep;
    bool have = true;
    if (cur == 0)
    {
        if (owner == 0 || *reinterpret_cast<const int*>(owner + 0xe0) == 0 || (cur = FUN_1425fc530(owner, 0)) == 0)
            have = false;
        else
            ++*reinterpret_cast<int*>(cur + 8);
    }
    if (have)
    {
        typedef void (*VFn)(UPInt);
        typedef UPInt (*VFnR)(UPInt);
        reinterpret_cast<VFn>(Sfr31Rd(Sfr31Rd(cur, 0), 0x228))(cur);
        reinterpret_cast<VFn>(Sfr31Rd(Sfr31Rd(cur, 0), 0x1b0))(cur);
        const UPInt def = reinterpret_cast<VFnR>(Sfr31Rd(Sfr31Rd(cur, 0), 0x1e0))(cur);
        if (def != 0)
        {
            FUN_1425a3850(reinterpret_cast<void*>(def));
            UPInt keyBuf = def;
            bool last = false;
            UPInt slot = reinterpret_cast<UPInt>(FUN_1425059f0(reinterpret_cast<void*>(root + 0x6e8), &keyBuf));
            if (slot != 0 && --*reinterpret_cast<int*>(slot + 8) == 0)
            {
                UPInt tbl = Sfr31Rd(root, 0x6e8);
                if (tbl != 0)
                {
                    const UPInt mask = Sfr31Rd(tbl, 8);
                    const UPInt home = def & mask;
                    UPInt e = tbl + 0x10 + home * 0x20;
                    if (static_cast<SInt64>(Sfr31Rd(e, 0)) != -2 && (Sfr31Rd(e, 8) & mask) == home)
                    {
                        UPInt idx = home;
                        UPInt prev = static_cast<UPInt>(-1);
                        bool found = true;
                        while ((Sfr31Rd(e, 8) & mask) != home || Sfr31Rd(e, 8) != def)
                        {
                            const UPInt nx = Sfr31Rd(e, 0);
                            if (nx == static_cast<UPInt>(-1))
                            {
                                found = false;
                                break;
                            }
                            prev = idx;
                            idx = nx;
                            e = tbl + 0x10 + nx * 0x20;
                        }
                        if (found)
                        {
                            const UPInt nx = Sfr31Rd(e, 0);
                            if (home == idx)
                            {
                                if (nx != static_cast<UPInt>(-1))
                                {
                                    if (Sfr31Rd(e, 0x10) != 0)
                                        reinterpret_cast<Resource*>(Sfr31Rd(e, 0x10))->Release();
                                    Sfr31Wr(e, 0, static_cast<UPInt>(-2));
                                    const UPInt ne = tbl + 0x10 + nx * 0x20;
                                    FUN_1424d54f0(reinterpret_cast<void*>(e), reinterpret_cast<void*>(ne));
                                    e = ne;
                                }
                            }
                            else
                                Sfr31Wr(tbl + 0x10 + prev * 0x20, 0, nx);
                            if (Sfr31Rd(e, 0x10) != 0)
                                reinterpret_cast<Resource*>(Sfr31Rd(e, 0x10))->Release();
                            Sfr31Wr(e, 0, static_cast<UPInt>(-2));
                            --*reinterpret_cast<SInt64*>(Sfr31Rd(root, 0x6e8));
                        }
                    }
                }
                last = true;
            }
            if (dropAll && last)
            {
                // objects registered per movie definition: drop the ones that belong to def
                const UPInt tbl150 = Sfr31Rd(root, 0x150);
                if (tbl150 != 0)
                {
                    for (UPInt hi = 0; hi <= Sfr31Rd(tbl150, 8); ++hi)
                    {
                        const UPInt he = tbl150 + 0x10 + hi * 0x20;
                        if (static_cast<SInt64>(Sfr31Rd(he, 0)) == -2)
                            continue;
                        UPInt* list = reinterpret_cast<UPInt*>(Sfr31Rd(he, 0x10));
                        if (list == 0)
                            continue;
                        UPInt k = 0;
                        while (k < list[1])
                        {
                            UPInt* data = reinterpret_cast<UPInt*>(list[0]);
                            int* proxy = reinterpret_cast<int*>(data[k]);
                            UPInt target = 0;
                            if (proxy == 0)
                            {
                                ++k;
                                continue;
                            }
                            target = Sfr31Rd(reinterpret_cast<UPInt>(proxy), 8);
                            if (target == 0)
                            {
                                if (--*proxy == 0)
                                    Memory::pGlobalHeap->Free(proxy);
                                data[k] = 0;
                                ++k;
                                continue;
                            }
                            if (*reinterpret_cast<int*>(target + 8) == 0)
                            {
                                ++k;
                                continue;
                            }
                            *reinterpret_cast<int*>(target + 8) += 2;
                            FUN_14257dcd0(reinterpret_cast<void*>(target));
                            typedef UPInt (*ResFn)(UPInt);
                            if (reinterpret_cast<ResFn>(Sfr31Rd(Sfr31Rd(target, 0), 0x1e0))(target) != def)
                                ++k;
                            else
                                FUN_1425224f0(list, k);
                            FUN_14257dcd0(reinterpret_cast<void*>(target));
                        }
                    }
                }
                const UPInt stage = Sfr31Rd(root, 0x158);
                UPInt disp = 0;
                if (stage != 0)
                {
                    const UPInt sub = stage + *reinterpret_cast<const UByte*>(stage + 0x6d) * 4;
                    typedef UPInt (*GetAvmFn)(UPInt);
                    const UPInt avm = reinterpret_cast<GetAvmFn>(Sfr31Rd(Sfr31Rd(sub, 0), 0x28))(sub);
                    if (avm != 0)
                    {
                        disp = Sfr31Rd(avm - 0x30, 0);
                        if (disp == 0)
                            disp = Sfr31Rd(avm - 0x38, 0);
                        if (disp & 1)
                            disp -= 1;
                    }
                }
                if (disp != 0)
                    reinterpret_cast<Instances::fl_events::EventDispatcher*>(disp)->RemoveListenersForMovieDef(reinterpret_cast<MovieDefImpl*>(def));
                reinterpret_cast<MovieImpl*>(impl)->ShutdownTimersForMovieDef(reinterpret_cast<MovieDefImpl*>(def));
                reinterpret_cast<MovieImpl*>(impl)->UnregisterFonts(reinterpret_cast<MovieDefImpl*>(def));
                for (int g = 0; g < 4; ++g)
                {
                    const UPInt base = root + 0x360 + g * 0xe0;
                    Sfr31DropDispOfDef(reinterpret_cast<UPInt*>(base), def);
                    const UPInt single = Sfr31Rd(base, 0x18);
                    if (single != 0 && Sfr31DispBelongsTo(single, def))
                    {
                        FUN_14257dcd0(reinterpret_cast<void*>(single));
                        Sfr31Wr(base, 0x18, 0);
                    }
                }
            }
        }
        // the display object part of cur gives up its AS3 object
        const UPInt sub = cur + *reinterpret_cast<const UByte*>(cur + 0x6d) * 4;
        Sfr31Wr(sub, 0x10, Sfr31DispAvmPeek(cur));
        const UPInt held = Sfr31Rd(sub, 8);
        if (held != 0)
        {
            if ((held & 1) == 0 && (*reinterpret_cast<UInt32*>(held + 0x10) & 0x3fffff) != 0)
            {
                --*reinterpret_cast<UInt32*>(held + 0x10);
                FUN_1423dfa20(reinterpret_cast<void*>(held));
            }
            Sfr31Wr(sub, 8, 0);
        }
        if (owner != 0)
        {
            reinterpret_cast<DisplayList*>(owner + 0xd8)->Clear(reinterpret_cast<DisplayObjectBase*>(owner));
            FUN_1425f4090(reinterpret_cast<void*>(owner));
        }
        keep = cur;
        if (def != 0)
            reinterpret_cast<Resource*>(def)->Release();
    }
    if (flagRoot)
        *reinterpret_cast<UByte*>(Sfr31Rd(Sfr31Rd(root, 0x48), 0x18) + 0xb0) = 1;
    Render::Text::Allocator* ta = reinterpret_cast<Render::Text::Allocator*>(Sfr31Rd(Sfr31Rd(root, 0x40), 0x28));
    if (ta)
    {
        ta->FlushTextFormatCache(false);
        ta->FlushParagraphFormatCache(false);
    }
    if (keep != 0 && (keep & 1) == 0)
        FUN_14257dcd0(reinterpret_cast<void*>(keep));
    if (li && (reinterpret_cast<UPInt>(li) & 1) == 0 && (*reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(li) + 0x10) & 0x3fffff) != 0)
    {
        --*reinterpret_cast<UInt32*>(reinterpret_cast<UPInt>(li) + 0x10);
        FUN_1423dfa20(reinterpret_cast<void*>(li));
    }
}
// ---- batch 77
static inline double Sfr31DblAt(const unsigned char* base, UPInt off) { return *reinterpret_cast<const double*>(base + off); }
static inline bool Sfr31NotNaN(double v) { return v == v; }

// Wraps an angle in degrees into (-180, 180].
static inline double Sfr31WrapDeg(double v)
{
    const double m = fmod(v, 360.0);
    if (m <= 180.0)
        return m < -180.0 ? m + 360.0 : m;
    return m - 360.0;
}

}}} // namespace Scaleform::GFx::AS3
namespace Scaleform { namespace GFx {

// AS3ValueObjectInterface::SetDisplayInfo (vftable slot 20): applies the fields of a DisplayInfo to the display object of
// an AS3 DisplayObject node (pdata). The exe calls it through the vftable (this=rcx, pdata=rdx, info=r8).
// MS2-FUNCTIONAL 0x142526730: same field order and twips rounding; the text rect space DisplayInfo scratch and the stale-value paths use NaN
// @0x142526730
bool AS3ValueObjectInterface::SetDisplayInfo(void* pdata, const Value::DisplayInfo& info)
{
    using namespace AS3;
    const UPInt node = reinterpret_cast<UPInt>(pdata);
    const unsigned char* d = reinterpret_cast<const unsigned char*>(&info);
    const UPInt traits = Sfr31Rd(node, 0x20);
    if (*reinterpret_cast<const UInt32*>(traits + 0x70) - 0x11u > 0xb || ((*reinterpret_cast<const UByte*>(traits + 0x68) >> 5) & 1) != 0)
        return false;
    const UPInt self = Sfr31Rd(node, 0x58);
    void* const dob = reinterpret_cast<void*>(self);
    const UPInt vt = Sfr31Rd(self, 0);
    typedef UPInt (*VfPtr)(void*);
    typedef void (*VfVoid)(void*);
    typedef void (*VfPtrArg)(void*, const void*);
    typedef void (*VfInt)(void*, int);
    typedef double (*VfDbl)(void*);
    typedef void (*VfDblArg)(void*, double);
    const bool notText = static_cast<int>(reinterpret_cast<VfPtr>(Sfr31Rd(vt, 0x258))(dob)) != 4;
    bool changed = false;
    UInt16 f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    const double nan = FUN_1425e3ee0();
    if ((f >> 14) & 1)
        FUN_14261d270(reinterpret_cast<void*>(FUN_1425f26c0(dob)), *reinterpret_cast<const int*>(d + 0xd0));
    const double alpha = Sfr31DblAt(d, 0x28);
    if (((f >> 5) & 1) && Sfr31NotNaN(alpha))
    {
        alignas(16) UInt32 cx[8];   // a Cxform: SetCxform copies it with movaps
        memcpy(cx, FUN_1425f1d00(dob), sizeof(cx));
        *reinterpret_cast<float*>(cx + 3) = static_cast<float>(alpha / 100.0);
        FUN_1425f4060(dob, cx);
        reinterpret_cast<VfInt>(Sfr31Rd(vt, 0x188))(dob, 0);
    }
    f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    if ((f >> 6) & 1)
        reinterpret_cast<VfInt>(Sfr31Rd(vt, 0x1a0))(dob, d[0x30]);
    const UPInt data = Sfr31Rd(self, 0x50);
    f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    if ((f >> 7) & 1)
    {
        double z = Sfr31DblAt(d, 0x38) * 20.0;
        if (!Sfr31NotNaN(z) || z == HUGE_VAL || z == -HUGE_VAL)
            z = 0.0;
        double* slot = reinterpret_cast<double*>(data + 0x40);
        if (z != *slot)
        {
            *slot = z;
            changed = true;
        }
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if ((f >> 10) & 1)
    {
        double s = Sfr31DblAt(d, 0x50);
        if (!Sfr31NotNaN(s) || s == HUGE_VAL || s == -HUGE_VAL)
            s = 100.0;
        double* slot = reinterpret_cast<double*>(data + 0x48);
        if (*slot != s)
        {
            *slot = s;
            changed = true;
        }
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if (((f >> 8) & 1) && Sfr31DblAt(d, 0x40) != *reinterpret_cast<double*>(data + 0x50))
    {
        *reinterpret_cast<double*>(data + 0x50) = Sfr31WrapDeg(Sfr31DblAt(d, 0x40));
        changed = true;
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if (((f >> 9) & 1) && Sfr31DblAt(d, 0x48) != *reinterpret_cast<double*>(data + 0x58))
    {
        *reinterpret_cast<double*>(data + 0x58) = Sfr31WrapDeg(Sfr31DblAt(d, 0x48));
        changed = true;
    }
    if (changed)
        reinterpret_cast<VfVoid>(Sfr31Rd(vt, 0x58))(dob);
    if ((*reinterpret_cast<const UInt16*>(d + 0xd4) >> 11) & 1)
    {
        const double fov = Sfr31DblAt(d, 0x58);
        if (fov != reinterpret_cast<VfDbl>(Sfr31Rd(vt, 0x120))(dob))
            reinterpret_cast<VfDblArg>(Sfr31Rd(vt, 0x118))(dob, fmod(fov, 180.0));
    }
    f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    if ((f >> 12) & 1)
    {
        reinterpret_cast<VfPtrArg>(Sfr31Rd(vt, 0x38))(dob, d + 0x90);
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if ((f >> 13) & 1)
    {
        reinterpret_cast<VfPtrArg>(Sfr31Rd(vt, 0x48))(dob, d + 0x60);
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
    }
    if ((f & 0x1f) == 0)
        return true;
    if (!notText)
    {
        *reinterpret_cast<UInt32*>(self + 0xfc) |= 0x2000;
        FUN_1425bc060(dob);
    }
    reinterpret_cast<VfInt>(Sfr31Rd(vt, 0x188))(dob, 0);
    const UPInt geom = Sfr31Rd(self, 0x50);   // reread: the calls above can allocate the geometry data (exe 0x142526b46)
    typedef const float* (*MatFn)(void*);
    alignas(16) float m[8];   // a Matrix2F (aligned like the exe frame slot)
    memcpy(m, reinterpret_cast<MatFn>(Sfr31Rd(vt, 0x10))(dob), sizeof(m));
    double x, y;
    if (notText || (f & 3) == 0)
    {
        x = (f & 1) ? Sfr31DblAt(d, 0) : nan;
        y = ((f >> 1) & 1) ? Sfr31DblAt(d, 8) : nan;
    }
    else
    {
        alignas(16) float tr[56] = {};
        FUN_1425be970(dob, tr, d);
        f = *reinterpret_cast<const UInt16*>(d + 0xd4);
        x = tr[0];
        y = tr[1];
    }
    int* const pd = reinterpret_cast<int*>(geom);
    if (f & 0x1c)
    {
        const double a = static_cast<float>(pd[0xc]);
        const double b = static_cast<float>(pd[8]);
        const double c = static_cast<float>(pd[0xd]);
        const double e = static_cast<float>(pd[9]);
        const double rot0 = atan2(a, b);
        const double sx0 = sqrt(b * b + a * a);
        const double sy0 = sqrt(e * e + c * c);
        double rad = *reinterpret_cast<double*>(pd + 6) * 3.141592653589793;
        double xs = *reinterpret_cast<double*>(pd + 2) / 100.0;
        double ys = *reinterpret_cast<double*>(pd + 4) / 100.0;
        const double rotIn = (f & 4) ? Sfr31DblAt(d, 0x10) : nan;
        if (Sfr31NotNaN(rotIn))
        {
            const double w = Sfr31WrapDeg(rotIn);
            *reinterpret_cast<double*>(pd + 6) = w;
            rad = w * 3.141592653589793;
        }
        double xdiv = sx0, ydiv = sy0;
        const double nx = ((*reinterpret_cast<const UInt16*>(d + 0xd4) >> 3) & 1) ? Sfr31DblAt(d, 0x18) / 100.0 : nan;
        if (nx != xs && Sfr31NotNaN(nx) && nx - nx == 0.0)
        {
            *reinterpret_cast<double*>(pd + 2) = Sfr31DblAt(d, 0x18);
            if (sx0 == 0.0 || nx > 1e16)
            {
                xs = 0.0;
                xdiv = 1.0;
            }
            else
                xs = nx;
        }
        const double ny = ((*reinterpret_cast<const UInt16*>(d + 0xd4) >> 4) & 1) ? Sfr31DblAt(d, 0x20) / 100.0 : nan;
        if (ny != ys && Sfr31NotNaN(ny) && ny - ny == 0.0)
        {
            *reinterpret_cast<double*>(pd + 4) = Sfr31DblAt(d, 0x20);
            if (sy0 == 0.0 || ny > 1e16)
            {
                ys = 0.0;
                ydiv = 1.0;
            }
            else
                ys = ny;
        }
        GFx::ASCharacter_MatrixScaleAndRotate2x2(*reinterpret_cast<Render::Matrix2F*>(m), static_cast<float>(xs / xdiv), static_cast<float>(ys / ydiv), static_cast<float>(rad / 180.0 - rot0));
    }
    // x/y hold the text rect space position on the text path (exe xmm11/xmm10, 0x142526edb).
    if (Sfr31NotNaN((f & 1) ? x : nan))
    {
        double v = (f & 1) ? x : nan;
        if (v == HUGE_VAL || v == -HUGE_VAL)
            v = 0.0;
        v = floor(v * 20.0);
        pd[0] = static_cast<int>(v);
        m[3] = static_cast<float>(static_cast<int>(v));
    }
    if (Sfr31NotNaN(((f >> 1) & 1) ? y : nan))
    {
        double v = ((f >> 1) & 1) ? y : nan;
        if (v == HUGE_VAL || v == -HUGE_VAL)
            v = 0.0;
        v = floor(v * 20.0);
        pd[1] = static_cast<int>(v);
        m[7] = static_cast<float>(static_cast<int>(v));
    }
    if (reinterpret_cast<const Render::Matrix2x4<float>*>(m)->IsValid())
    {
        if (reinterpret_cast<DisplayObjectBase*>(self)->Is3D())
            reinterpret_cast<VfVoid>(Sfr31Rd(vt, 0x58))(dob);
        else
            reinterpret_cast<VfPtrArg>(Sfr31Rd(vt, 0x18))(dob, m);
    }
    if (!notText)
    {
        if (f & 1)
        {
            double v = x * 20.0;
            v = v <= 0.0 ? v - 0.5 : v + 0.5;
            pd[0] = static_cast<int>(v);
        }
        if ((f >> 1) & 1)
        {
            double v = y * 20.0;
            v = v <= 0.0 ? v - 0.5 : v + 0.5;
            pd[1] = static_cast<int>(v);
        }
    }
    return true;
}

}} // namespace Scaleform::GFx
// Tracer::GetValueTraits (sfr_as3_18)
Scaleform::UPInt FUN_14250ff00(Scaleform::UPInt tracer, const Scaleform::GFx::AS3::Value& v, bool super_tr);
namespace Scaleform { namespace GFx { namespace AS3 {
// ---- batch 78

// The traits of a tracer value: kinds 8/9 carry them, undefined has the VM's Object-less default, and the builtin Class
// traits stand for Object.
static UPInt Sfr31TrTraitsOfVal(UPInt vmA, UInt32* v)
{
    const UInt32 k = v[0] & 0x1f;
    UPInt tr;
    if (k == 0)
        tr = Sfr31Rd(vmA, 0x278);
    else if (k == 8 || k == 9)
        tr = Sfr31Rd(reinterpret_cast<UPInt>(v), 0x10);
    else
        tr = reinterpret_cast<UPInt>(&FUN_14250ffc0(*reinterpret_cast<VM*>(vmA), *reinterpret_cast<const Value*>(v)));
    if (tr != 0 && tr == Sfr31Rd(vmA, 0x1f0))
        tr = Sfr31Rd(vmA, 0x1f8);
    return tr;
}

static void Sfr31TrPushTraits(UPInt state, UInt32 flags, UPInt traits)
{
    TrTraitsScratch t;
    t.w0 = flags;
    t.SetTraits(*reinterpret_cast<InstanceTraits::Traits*>(traits));
    reinterpret_cast<ArrayDH<Value>*>(state + 0x38)->PushBack(t.Get());
}

// Tracer::TraceCommonOp: per-opcode specialization of the ops that need no block structure: property get/set/call ops on
// names with a known fixed slot become slot or vtable accesses, the convert ops vanish for operands of the target type,
// getlocal/kill update the register model. Returns whether the original opcode was consumed.
// MS2-FUNCTIONAL 0x14252d100: raw-offset model; codegen differs from the exe
// @0x14252d100
char Sfr31TracerCommonOp(UPInt tracer, unsigned char op, UPInt* pos, UPInt state)
{
    const UInt8* code = reinterpret_cast<const UInt8*>(Sfr31Rd(tracer, 0x50));
    const UPInt link = TrAbcLink(tracer);
    const UPInt vmA = TrRd(link, 0x20);
    UInt8* const stk = reinterpret_cast<UInt8*>(Sfr31Rd(state, 0x38));
    UInt32* const top = reinterpret_cast<UInt32*>(stk + Sfr31Rd(state, 0x40) * 0x20 - 0x20);
    UPInt p;
    switch (op)
    {
    case 4:
    case 0x66:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x70];
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0, vmA);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 8, state);
        *reinterpret_cast<int*>(R + 0x10) = 0;
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x18, link);
        FUN_1424d8ec0(R + 0x20, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x20);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x50));
        ++*reinterpret_cast<int*>(R + 0x10);
        const UPInt tr = FUN_14250ff00(tracer, *reinterpret_cast<const Value*>(R + 0x50), op == 4);
        const bool ok = FUN_1424f8b00(reinterpret_cast<void*>(tracer), op, reinterpret_cast<void*>(state),
                                      reinterpret_cast<const Traits*>(tr), reinterpret_cast<const Multiname*>(R + 0x20),
                                      static_cast<int>(idx));
        if (ok)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424ded40(R);
        return ok;
    }
    case 5:
    case 0x61:
    case 0x68:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x90];
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0, vmA);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 8, state);
        *reinterpret_cast<int*>(R + 0x10) = 0;
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x18));
        ++*reinterpret_cast<int*>(R + 0x10);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x38, link);
        FUN_1424d8ec0(R + 0x40, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x40);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x70));
        ++*reinterpret_cast<int*>(R + 0x10);
        const UPInt tr = FUN_14250ff00(tracer, *reinterpret_cast<const Value*>(R + 0x70), op == 5);
        UInt32* val = reinterpret_cast<UInt32*>(R + 0x18);
        const UPInt vt = Sfr31TrTraitsOfVal(vmA, val);
        const bool ok = FUN_1424f92f0(reinterpret_cast<void*>(tracer), op, reinterpret_cast<const Traits*>(tr),
                                      reinterpret_cast<void*>(vt), reinterpret_cast<const Multiname*>(R + 0x40),
                                      static_cast<int>(idx));
        if (ok)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424dee30(R);
        return ok;
    }
    case 8:
    {
        const UInt32 reg = Abc::ReadU30<UInt8>(code, *pos);
        reinterpret_cast<State*>(state)->SetRegister(AbsoluteIndex(reg), Value::GetUndefined());
        *reinterpret_cast<UInt8*>(Sfr31Rd(state, 0x78) + (reg >> 3)) &= static_cast<UInt8>(~(1 << (reg & 7)));
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    }
    case 0x45:
    case 0x46:
    case 0x4c:
    case 0x4e:
    case 0x4f:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        const UInt32 argc = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x198];
        FUN_1424d9640(R, reinterpret_cast<VM*>(vmA), reinterpret_cast<void*>(state), argc);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x140, link);
        FUN_1424d8ec0(R + 0x148, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x148);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x178));
        ++*reinterpret_cast<int*>(R + 0x10);
        const bool ok = FUN_1424f7540(reinterpret_cast<void*>(tracer), op, reinterpret_cast<void*>(state), R,
                                      static_cast<int>(idx));
        if (ok)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424debc0(R);
        return ok;
    }
    case 0x4a:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        const UInt32 argc = Abc::ReadU30<UInt8>(code, p);
        alignas(8) UInt8 R[0x198];
        FUN_1424d9640(R, reinterpret_cast<VM*>(vmA), reinterpret_cast<void*>(state), argc);
        Sfr31Wr(reinterpret_cast<UPInt>(R), 0x140, link);
        FUN_1424d8ec0(R + 0x148, link, reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx)));
        *reinterpret_cast<int*>(R + 0x10) += FUN_142520380(R, R + 0x148);
        FUN_14251cd30(reinterpret_cast<State*>(state), reinterpret_cast<Value*>(R + 0x178));
        ++*reinterpret_cast<int*>(R + 0x10);
        const UInt32 mnw = *reinterpret_cast<UInt32*>(R + 0x148);
        UInt32* obj = reinterpret_cast<UInt32*>(R + 0x178);
        const UPInt objPtr = Sfr31Rd(reinterpret_cast<UPInt>(obj), 0x10);
        bool generic = (mnw & 3) == 1 || ((mnw >> 2) & 1) != 0;
        bool done = false;
        if (!generic)
        {
            if (((obj[0] >> 10) & 1) == 0)
            {
                if (argc != 0)
                    generic = true;
                else
                {
                    const UPInt tr = Sfr31TrTraitsOfVal(vmA, obj);
                    UPInt slotInd = 0;
                    const SlotInfo* si = FindFixedSlot(*reinterpret_cast<VM*>(vmA), *reinterpret_cast<const Traits*>(tr),
                                                       *reinterpret_cast<const Multiname*>(R + 0x148), slotInd, 0);
                    if (!si)
                        generic = true;
                    else
                    {
                        FUN_14251fb90(reinterpret_cast<void*>(tracer), 0xb6, static_cast<SPInt>(static_cast<UInt32>(slotInd) + 1));
                        FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x42, 0);
                        TrPopped res;
                        res.w0 = 0;
                        res.w1 = 0;
                        res.w2 = 0;
                        res.w3 = 0;
                        char okb[8];
                        const char* r = FUN_14250cf20(reinterpret_cast<void*>(state), okb, reinterpret_cast<const void*>(tr),
                                                      si, res.Get());
                        if (*r == 0)
                        {
                            res.Get().~Value();
                            FUN_1424debc0(R);
                            return 0;
                        }
                        reinterpret_cast<ArrayDH<Value>*>(state + 0x38)->PushBack(res.Get());
                        res.Get().~Value();
                        done = true;
                    }
                }
            }
            else
            {
                const UInt32 k = obj[0] & 0x1f;
                UPInt it;
                if (k == 9)
                {
                    FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x42, static_cast<SPInt>(argc));
                    it = Sfr31Rd(objPtr, 0xc0);
                    Sfr31TrPushTraits(state, 8, it);
                    done = true;
                }
                else if (k == 0xd)
                {
                    FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x42, static_cast<SPInt>(argc));
                    it = Sfr31Rd(Sfr31Rd(objPtr, 0x20), 0xc0);
                    Sfr31TrPushTraits(state, 8, it);
                    done = true;
                }
                else
                    generic = true;
            }
        }
        if (generic)
        {
            FUN_14251fa10(reinterpret_cast<void*>(tracer), 0x4a, idx, argc);
            Sfr31TrPushTraits(state, 8, Sfr31Rd(Sfr31Rd(vmA, 0x1f8), 0xc0));
            done = true;
        }
        if (done)
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        FUN_1424debc0(R);
        return done;
    }
    case 0x5d:
    {
        p = *pos;
        const int idx = static_cast<int>(Abc::ReadU30<UInt8>(code, p));
        const UInt8 c = code[p];
        UPInt q = p + 1;
        const int r = FUN_14250c990(tracer, p);
        if (c == 'f')
        {
            Abc::ReadU30<UInt8>(code, q);
            if (FUN_1424f7cc0(tracer, reinterpret_cast<void*>(state), idx, true, r, true))
            {
                Sfr31TracerSkipOrigOpCode(tracer, pos, q);
                return 1;
            }
        }
        else if (FUN_1424f7cc0(tracer, reinterpret_cast<void*>(state), idx, false, r, true))
        {
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
    }
    // fall through: the plain find-property trace
    case 0x5e:
    case 0x60:
    {
        p = *pos;
        const int idx = static_cast<int>(Abc::ReadU30<UInt8>(code, p));
        if (FUN_1424f7cc0(tracer, reinterpret_cast<void*>(state), idx, op == 0x60, 2, false))
        {
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
        return 0;
    }
    case 0x62:
    {
        p = *pos;
        const UInt32 reg = Abc::ReadU30<UInt8>(code, p);
        return Sfr31TracerOptRegIncDec(tracer, pos, p, state, reg);
    }
    case 0xd0:
    case 0xd1:
    case 0xd2:
    case 0xd3:
        return Sfr31TracerOptRegIncDec(tracer, pos, *pos, state, op - 0xd0u);
    case 100:
    {
        const UInt8 c = code[*pos];
        p = *pos + 1;
        if (c == 'l')
        {
            Sfr31StatePushTyped(state);
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0x6e);
            const UInt32 slot = Abc::ReadU30<UInt8>(code, p);
            Sfr31TraceGetSlot(reinterpret_cast<State*>(state), slot);
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
        if (c != '+')
            return 0;
        UPInt* posArr = reinterpret_cast<UPInt*>(tracer + 0x70);
        FUN_142524870(posArr, posArr[1] + 1);
        reinterpret_cast<UPInt*>(posArr[0])[posArr[1] - 1] = p;
        const UInt8 d = code[p++];
        if (d == 'm')
        {
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0x6f);
            Sfr31StatePushTyped(state);
            Sfr31StateSwapOp(state);
            const UInt32 slot = Abc::ReadU30<UInt8>(code, p);
            Sfr31TracePop2Note(reinterpret_cast<State*>(state), slot);
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            return 1;
        }
        FUN_142524870(posArr, posArr[1] - 1);
        return 0;
    }
    case 0x70:
    case 0x85:
    {
        const UInt32 k = top[0] & 0x1f;
        if (op == 0x85 && k == 10)
            return 1;
        const UInt32 kk = k - 0xc;
        if ((kk > 3 || Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10) != 0) && !FUN_142514e10(tracer, top))
            return 0;
        int nn = 2;
        if (op == 0x85)
            nn = (kk < 4 ? (Sfr31Rd(reinterpret_cast<UPInt>(top), 0x10) != 0 ? 1 : 0) : 1) + 1;
        FUN_1424f1e50(state, Sfr31Rd(Sfr31Rd(vmA, 0x230), 0xc0), nn);
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    }
    case 0x73:
        if (!FUN_142514c30(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x74:
        if (!FUN_1425150c0(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x75:
        if (!FUN_142514470(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x76:
        if (!FUN_142514000(tracer, top))
            return 0;
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x80:
    {
        p = *pos;
        const UInt32 idx = Abc::ReadU30<UInt8>(code, p);
        const UPInt entry = reinterpret_cast<UPInt>(&Sfr31MnEntry(link, idx));
        UInt8* const endp = stk + Sfr31Rd(state, 0x40) * 0x20;
        UInt32* const tv = reinterpret_cast<UInt32*>(endp - 0x20);
        const UPInt tr = Sfr31ResolveClassTraits(vmA, link, entry);
        if (tr == 0)
        {
            UPInt sv[2];
            FUN_142545310(Sfr31Rd(TrFile(tracer), 0x70) + static_cast<UPInt>(*reinterpret_cast<const UInt32*>(entry + 8)) * 8, sv);
            alignas(8) char eb[sizeof(VM::Error)];
            FUN_1424d7850(eb, 0x3f6, reinterpret_cast<void*>(vmA), reinterpret_cast<const char*>(sv[0]));
            reinterpret_cast<VM*>(vmA)->ThrowVerifyError(*reinterpret_cast<VM::Error*>(eb));
            reinterpret_cast<VM::Error*>(eb)->~Error();
            return 1;
        }
        const UPInt it = Sfr31Rd(tr, 0xc0);
        const UInt32 k = tv[0] & 0x1f;
        bool nullable = false;
        if (k == 0)
        {
            if (it != Sfr31Rd(Sfr31Rd(vmA, 0x1f0), 0xc0) && it != Sfr31Rd(Sfr31Rd(vmA, 0x220), 0xc0) &&
                it != Sfr31Rd(Sfr31Rd(vmA, 0x228), 0xc0) && it != Sfr31Rd(Sfr31Rd(vmA, 0x218), 0xc0) &&
                it != Sfr31Rd(Sfr31Rd(vmA, 0x210), 0xc0) && it != Sfr31Rd(vmA, 0x278) &&
                it != Sfr31Rd(Sfr31Rd(vmA, 0x230), 0xc0))
            {
                UPInt* posArr = reinterpret_cast<UPInt*>(tracer + 0x90);
                if (posArr[1] != 0)
                {
                    UPInt* ops = reinterpret_cast<UPInt*>(Sfr31Rd(tracer, 0x28));
                    UInt64* arr = reinterpret_cast<UInt64*>(ops[0]);
                    if (*reinterpret_cast<int*>(&arr[reinterpret_cast<UPInt*>(posArr[0])[posArr[1] - 1]]) == 0x21)
                    {
                        arr[ops[1] - 1] = 0x20;
                        FUN_1424f1e50(state, it, 1);
                        Sfr31TracerSkipOrigOpCode(tracer, pos, p);
                        return 1;
                    }
                }
            }
        }
        else if (k - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(tv), 0x10) == 0)
            nullable = true;
        if (!nullable && !Sfr31SetTraitsForValue(tracer, tv, tr))
        {
            Sfr31TracerSkipOrigOpCode(tracer, pos, p);
            FUN_14251fb90(reinterpret_cast<void*>(tracer), 0x80, static_cast<SPInt>(idx));
            FUN_1424f1e50(state, it, 2);
            return 1;
        }
        int nt = FUN_1424eea80(tracer, it);
        if ((tv[0] & 0x1f) - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(tv), 0x10) == 0)
            nt = 1;
        FUN_1424f1e50(state, it, nt);
        Sfr31TracerSkipOrigOpCode(tracer, pos, p);
        return 1;
    }
    case 0x82:
        if (FUN_142514c30(tracer, top) || FUN_1425150c0(tracer, top))
        {
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0x75);
            if ((top[0] & 0x1f) - 2 > 1)
                FUN_1424f1e50(state, Sfr31Rd(Sfr31Rd(vmA, 0x218), 0xc0), 0);
            else
                reinterpret_cast<Value*>(top)->ToNumberValueInline();
            return 1;
        }
        Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
        return 1;
    case 0x87:
    {
        TrPopped pv;
        FUN_14251cd30(reinterpret_cast<State*>(state), &pv.Get());
        const UInt32 k = pv.w0 & 0x1f;
        UPInt ct = pv.w2;
        if (k == 0xd)
            ct = Sfr31Rd(ct, 0x20);
        if ((k == 9 || k == 0xd) && ct != 0)
        {
            UInt32* t2 = reinterpret_cast<UInt32*>(stk + Sfr31Rd(state, 0x40) * 0x20 - 0x20);
            if (((t2[0] & 0x1f) - 0xc < 4 && Sfr31Rd(reinterpret_cast<UPInt>(t2), 0x10) == 0) ||
                Sfr31SetTraitsForValue(tracer, t2, ct))
            {
                FUN_1424f9180(reinterpret_cast<void*>(tracer));
                Sfr31TracerSkipOrigOpCode(tracer, pos, *pos);
                FUN_1424f1e50(state, Sfr31Rd(ct, 0xc0), 2);
                pv.Get().~Value();
                return 1;
            }
        }
        reinterpret_cast<ArrayDH<Value>*>(state + 0x38)->PushBack(pv.Get());
        pv.Get().~Value();
        return 0;
    }
    case 0xa0:
    {
        TrPopped b;
        TrPopped a;
        FUN_14251cd30(reinterpret_cast<State*>(state), &b.Get());
        FUN_14251cd30(reinterpret_cast<State*>(state), &a.Get());
        const UPInt ta = Sfr31TrTraitsOfVal(vmA, reinterpret_cast<UInt32*>(&a));
        const UPInt tb = Sfr31TrTraitsOfVal(vmA, reinterpret_cast<UInt32*>(&b));
        const UPInt strT = Sfr31Rd(Sfr31Rd(vmA, 0x230), 0xc0);
        UInt32 flags = 8;
        UPInt owner;
        if (ta == strT || tb == strT)
        {
            FUN_14251f930(reinterpret_cast<void*>(tracer), 0xa0);
            owner = Sfr31Rd(vmA, 0x230);
            flags = 0x48;
        }
        else
        {
            bool number = false;
            if (FUN_142514470(tracer, &a) && FUN_142514470(tracer, &b))
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0x7c);
                number = true;
            }
            else if (code[*pos] == 0x75)
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0x9b);
                Sfr31TracerSkipOrigOpCode(tracer, pos, *pos + 1);
                number = true;
            }
            else if (FUN_142514c30(tracer, &a) && FUN_142514c30(tracer, &b))
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0x79);
                owner = Sfr31Rd(vmA, 0x220);
            }
            else
            {
                FUN_14251f930(reinterpret_cast<void*>(tracer), 0xa0);
                if (FUN_142514a80(tracer, reinterpret_cast<void*>(ta)) && FUN_142514a80(tracer, reinterpret_cast<void*>(tb)))
                    number = true;
                else
                {
                    owner = Sfr31Rd(vmA, 0x1f8);
                    flags = 0x48;
                }
            }
            if (number)
                owner = Sfr31Rd(vmA, 0x218);
        }
        Sfr31TrPushTraits(state, flags, Sfr31Rd(owner, 0xc0));
        a.Get().~Value();
        b.Get().~Value();
        return 1;
    }
    }
    return 0;
}
// ---- batch 79
static inline UPInt Sfr31VmTr(UPInt vmA, UPInt off) { return Sfr31Rd(Sfr31Rd(vmA, off), 0xc0); }

// The opcode table's operand class for the opcodes TR::State handles by default: 0 none, 1 one U30, 2 two U30, -1 unusable.
static int Sfr31StateOpClass(unsigned char op)
{
    switch (op)
    {
    case 0x02: case 0x22: case 0x3f: case 0x54: case 0x69: case 0x6b:
    case 0x79: case 0x7a: case 0x7b: case 0x7c: case 0x7d: case 0x7e: case 0x7f:
    case 0x98: case 0x99:
        return 0;
    case 0x0a: case 0x0b: case 0x33: case 0x34: case 0x67:
    case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f:
    case 0x9c: case 0x9d: case 0x9e: case 0x9f:
    case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb:
    case 0xbc: case 0xbd: case 0xbe: case 0xbf:
    case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce:
        return 1;
    default:
        return -1;
    }
}

static void Sfr31StateBadOp(UPInt vmA, const char* name)
{
    VM& vm = *reinterpret_cast<VM*>(vmA);
    vm.ThrowVerifyError(VM::Error(static_cast<VM::ErrorID>(0x3e9), vm, name));
}

// TR::State::TraceOp: the opcodes of the tracer that are not common to every state. The stack and register effects are
// modeled by the per-opcode handlers; unusable opcodes raise a verify error naming them.
// MS2-FUNCTIONAL 0x14253d520: raw-offset model; dispatches to the recovered per-opcode handlers; codegen differs from the exe
// @0x14253d520
void Sfr31StateTraceOp(UPInt state, unsigned char op, UPInt* pos)
{
    State* const st = reinterpret_cast<State*>(state);
    const UPInt tracer = Sfr31Rd(state, 0);
    const UInt8* const code = reinterpret_cast<const UInt8*>(Sfr31Rd(tracer, 0x50));
    const UPInt vmA = TrVM(tracer);
    StV s(st);
    Sfr31Wr(state, 0x10, *pos - 1);
    FUN_14251f930(reinterpret_cast<void*>(tracer), op);
    switch (op)
    {
    case 3:
        FUN_14251ccc0(st, 1);
        return;
    case 4: case 5: case 0x45: case 0x46: case 0x4a: case 0x4c: case 0x4e: case 0x4f: case 0x61: case 0x66:
    case 0x77: case 0x78: case 0x80: case 0x82: case 0xa0:
        return;
    case 6:
        Sfr27TraceDxns(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 7:
        Sfr27TraceDxnsLate(st);
        return;
    case 8:
        st->KillRegister(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 9:
        FUN_1424e6aa0(tracer, st, *pos - 1, 0, 1);
        FUN_14251cc80(tracer);
        return;
    case 0xc: case 0xd: case 0xe: case 0xf: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
    case 0x19: case 0x1a:
        Sfr27TraceIfCompare(st, reinterpret_cast<UInt64*>(pos), op);
        return;
    case 0x10:
        Sfr27TraceJump(st, reinterpret_cast<UInt64*>(pos));
        return;
    case 0x47:
        FUN_1424e6aa0(tracer, st, *pos, 1, 1);
        return;
    case 0x11: case 0x12:
        Sfr27TraceIfTrueFalse(st, reinterpret_cast<UInt64*>(pos), op);
        return;
    case 0x1b:
        Sfr27TraceLookupSwitch(st, reinterpret_cast<UInt64*>(pos));
        return;
    case 0x1c:
    {
        TrPopped p;
        FUN_14251cd30(st, &p.Get());
        reinterpret_cast<ArrayDH<Value>*>(state + 0x58)->PushBack(p.Get());
        p.Get().~Value();
        *reinterpret_cast<UInt32*>(Sfr31Rd(state, 0x58) + Sfr31Rd(state, 0x60) * 0x20 - 0x20) |= 0x100;
        return;
    }
    case 0x1d:
        FUN_1424201a0(reinterpret_cast<void*>(state + 0x58), reinterpret_cast<void*>(Sfr31Rd(state, 0x70)),
                      Sfr31Rd(state, 0x60) - 1);
        return;
    case 0x1e:
        Sfr31TraceOperandClassTraits(st);
        return;
    case 0x1f:
        Sfr27TracePop2PushInt(st);
        return;
    case 0x20:
        s.OpStack().PushBack(Value::GetNull());
        return;
    case 0x21:
        s.OpStack().PushBack(Value::GetUndefined());
        return;
    case 0x23:
        Sfr27TracePop2PushObject(st);
        return;
    case 0x24:
    {
        const UInt32 b = code[*pos];
        ++*pos;
        st->PushByte(b);
        return;
    }
    case 0x25:
        st->PushShort(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x26:
    case 0x27:
    {
        const bool b = op == 0x26;
        TrScratch t(b);
        s.OpStack().PushBack(t.Get());
        return;
    }
    case 0x28:
    {
        TrNumScratch t(Value::kNumber);
        t.SetNumber(FUN_1425e3ee0());
        s.OpStack().PushBack(t.Get());
        return;
    }
    case 0x29:
        Sfr27TraceCheckNumericOp(st);
        return;
    case 0x2a:
        Sfr27TraceDup2Check(st);
        return;
    case 0x2b:
        Sfr31StateSwapOp(state);
        return;
    case 0x2c:
        Sfr31TracePushString(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x2d:
        st->PushInt(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x2e:
        st->PushUInt(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x2f:
        st->PushDouble(Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x30:
        st->PushScope();
        return;
    case 0x31:
        Sfr31StatePushPool(state, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x32:
    {
        const UInt32 a = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        const UInt32 b = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        FUN_14251fcd0(tracer, a);
        FUN_14251fcd0(tracer, b);
        TrTraitsScratch t;
        t.SetTraits(TrITraits(tracer, 0x210));
        s.OpStack().PushBack(t.Get());
        return;
    }
    case 0x35: Sfr31StateBadOp(vmA, "exec_li8"); return;
    case 0x36: Sfr31StateBadOp(vmA, "exec_li16"); return;
    case 0x37: Sfr31StateBadOp(vmA, "exec_li32"); return;
    case 0x38: Sfr31StateBadOp(vmA, "exec_lf32"); return;
    case 0x39: Sfr31StateBadOp(vmA, "exec_lf64"); return;
    case 0x3a: Sfr31StateBadOp(vmA, "exec_si8"); return;
    case 0x3b: Sfr31StateBadOp(vmA, "exec_si16"); return;
    case 0x3c: Sfr31StateBadOp(vmA, "exec_si32"); return;
    case 0x3d: Sfr31StateBadOp(vmA, "exec_sf32"); return;
    case 0x3e: Sfr31StateBadOp(vmA, "exec_sf64"); return;
    case 0x50: Sfr31StateBadOp(vmA, "exec_sxi1"); return;
    case 0x51: Sfr31StateBadOp(vmA, "exec_sxi8"); return;
    case 0x52: Sfr31StateBadOp(vmA, "exec_sxi16"); return;
    case 0x40:
        st->PushFunction(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x41:
        Sfr31TraceTraitsOfSecond(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x42:
        Sfr31TraceTypeOperand(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x43:
    case 0x44:
    {
        const UInt32 a = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        const UInt32 b = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        if (op == 0x43)
            Sfr31TraceCallPushObject(st, a, b);
        else
            Sfr31TraceCallPushObjectB(st, a, b);
        return;
    }
    case 0x48:
        FUN_14251ccc0(st, 1);
        FUN_1424e6aa0(tracer, st, *pos, 1, 1);
        return;
    case 0x49:
        Sfr31TraceCallPop(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x53:
        Sfr31TraceArgClassTraits(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x55:
        Sfr27TraceNewObject(st, Abc::ReadU30<UInt8>(code, *pos));
        return;
    case 0x56:
        Sfr27TraceNewArray(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x57:
        Sfr31StatePushNs(state);
        return;
    case 0x58:
        Sfr31TraceClassTraitsFromIndex(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x59:
        Sfr31TraceGetDescendants(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x5a:
    case 0x60:
        st->PushObject(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x5d:
        Sfr31TraceFindPropB(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x5e:
        Sfr31TraceFindPropA(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x62:
    {
        const UInt32 idx = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        FUN_14251fcd0(tracer, idx);
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(state, 0x18) + static_cast<UPInt>(idx) * 0x20));
        return;
    }
    case 0x63:
        st->SetLocalN(static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x64:
        Sfr31StatePushTyped(state);
        return;
    case 0x65:
    {
        const UInt32 idx = static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos));
        FUN_14251fcd0(tracer, idx);
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(state, 0x58) + static_cast<UPInt>(idx) * 0x20));
        *reinterpret_cast<UInt32*>(&s.Top()) &= 0xfffffeffu;
        return;
    }
    case 0x68:
        Sfr31TraceMnPop2(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6a:
        Sfr31TraceMnPopPush(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6c:
        Sfr31TraceGetSlot(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6d:
        Sfr31TracePop2Note(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x6e:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        s.OpStack().PushBack(Value::GetUndefined());
        return;
    case 0x6f:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        FUN_14251ccc0(st, 1);
        return;
    case 0x70:
    case 0x95:
        st->TopString();
        return;
    case 0x85:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) != 10)
            st->TopString();
        return;
    case 0x71:
    case 0x72:
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x230), 0);
        return;
    case 0x73:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopInt(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x220), 0);
        return;
    case 0x97:
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x220), 0);
        return;
    case 0x74:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopUInt(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x228), 0);
        return;
    case 0x75:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopNumber(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x218), 0);
        return;
    case 0x76:
        if ((*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) < 5 || (*reinterpret_cast<const UInt32*>(&s.Top()) & 0x1f) == 10)
        {
            Sfr27TraceConvertTopBoolean(st);
            return;
        }
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x210), 0);
        return;
    case 0xb2:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        FUN_1424f1e50(state, Sfr31VmTr(vmA, 0x210), 0);
        return;
    case 0x86:
        Sfr27TracePopNote(st, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0x87:
    {
        TrPopped p;
        FUN_14251cd30(st, &p.Get());
        const UPInt pv = reinterpret_cast<UPInt>(&p.Get());
        const UInt32 k = *reinterpret_cast<const UInt32*>(pv) & 0x1f;
        UPInt tr = Sfr31Rd(pv, 0x10);
        if (k == 9)
            tr = Sfr31Rd(tr, 0xc0);
        else if (k == 0xd)
            tr = Sfr31Rd(Sfr31Rd(tr, 0x20), 0xc0);
        else if (k != 8)
            tr = 0;
        if (tr != 0)
        {
            if (FUN_142514a80(tracer, reinterpret_cast<void*>(tr)))
                tr = Sfr31VmTr(vmA, 0x1f8);
            FUN_1424f1e50(state, tr, 2);
        }
        p.Get().~Value();
        return;
    }
    case 0x90: FUN_142520e60(state, Sfr31VmTr(vmA, 0x218), 0x54); return;
    case 0x91:
    case 0x93:
        st->TopNumber();
        return;
    case 0x92:
    case 0x94:
        FUN_1424f1ed0(state, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)), Sfr31VmTr(vmA, 0x218), 0);
        return;
    case 0x96: FUN_142520e60(state, Sfr31VmTr(vmA, 0x210), 0x22); return;
    case 0x9b: FUN_142520f30(state, Sfr31VmTr(vmA, 0x218), 0x7c); return;
    case 0xa1: FUN_142520f30(state, Sfr31VmTr(vmA, 0x218), 0x7d); return;
    case 0xa2: FUN_142520f30(state, Sfr31VmTr(vmA, 0x218), 0x7e); return;
    case 0xa3: FUN_142520f30(state, Sfr31VmTr(vmA, 0x218), 0x7f); return;
    case 0xa4:
    case 0xa7:
    {
        TrPopped p;
        FUN_14251cd30(st, &p.Get());
        FUN_1424f1e50(state, Sfr31VmTr(vmA, op == 0xa4 ? 0x218 : 0x228), 0);
        p.Get().~Value();
        return;
    }
    case 0xa5: case 0xa6: case 0xa8: case 0xa9: case 0xaa:
        st->Pop2Int();
        return;
    case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: case 0xb0: case 0xb1: case 0xb3: case 0xb4:
        st->Pop2Boolean();
        return;
    case 0xc0: FUN_142520e60(state, Sfr31VmTr(vmA, 0x220), 0x98); return;
    case 0xc1: FUN_142520e60(state, Sfr31VmTr(vmA, 0x220), 0x99); return;
    case 0xc2:
        FUN_142520d80(state, Sfr31VmTr(vmA, 0x220), 10, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0xc3:
        FUN_142520d80(state, Sfr31VmTr(vmA, 0x220), 0xb, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0xc4: FUN_142520e60(state, Sfr31VmTr(vmA, 0x220), 0x3f); return;
    case 0xc5: FUN_142520f30(state, Sfr31VmTr(vmA, 0x220), 0x79); return;
    case 0xc6: FUN_142520f30(state, Sfr31VmTr(vmA, 0x220), 0x7a); return;
    case 0xc7: FUN_142520f30(state, Sfr31VmTr(vmA, 0x220), 0x7b); return;
    case 0xd0: case 0xd1: case 0xd2: case 0xd3:
        s.OpStack().PushBack(*reinterpret_cast<const Value*>(Sfr31Rd(state, 0x18) + static_cast<UPInt>(op - 0xd0) * 0x20));
        return;
    case 0xd4: st->SetLocal0(); return;
    case 0xd5: st->SetLocal1(); return;
    case 0xd6: st->SetLocal2(); return;
    case 0xd7: st->SetLocal3(); return;
    case 0xef:
    {
        FUN_14251fcd0(tracer, code[*pos]);
        ++*pos;
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        FUN_14251fcd0(tracer, code[*pos]);
        ++*pos;
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    }
    case 0xf0:
    case 0xf1:
        FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
        return;
    case 0xf2:
        Abc::ReadU30<UInt8>(code, *pos);
        return;
    default:
    {
        const int cls = Sfr31StateOpClass(op);
        if (cls == 0)
            return;
        if (cls == 1)
        {
            FUN_14251fcd0(tracer, static_cast<UInt32>(Abc::ReadU30<UInt8>(code, *pos)));
            return;
        }
        static const char hex[] = "0123456789ABCDEF";
        char name[8] = { 'O', 'P', '_', '0', 'x', hex[op >> 4], hex[op & 15], 0 };
        Sfr31StateBadOp(vmA, name);
        return;
    }
    }
}
// ---- batch 80
// Pushes a new Instance of the traits found through the owner's name onto the VM's value stack (vm + 0x50 points at the top).
// MS2-FUNCTIONAL 0x14253bef0: the new instance is constructed through the Instance model; the local value copy and its reference counts are folded away
// @0x14253bef0
void Sfr31PushNewInstanceOfOwner(UPInt vm, UPInt own)
{
    ASString name(reinterpret_cast<ASStringNode*>(Sfr31Rd(own, 0x70)));
    const UPInt link = Sfr31Rd(own, 0x28);
    const UPInt tr = FUN_142506f00(link, *reinterpret_cast<const UPInt*>(Sfr31Rd(Sfr31Rd(link, 0x28), 0x170) + static_cast<SPInt>(*reinterpret_cast<const SInt32*>(own + 0x30)) * 8), &name);
    InstanceTraits::Traits& traits = *reinterpret_cast<InstanceTraits::Traits*>(tr);
    void* mem = traits.Alloc();
    Instance* obj = mem != NULL ? new (mem) Instance(traits) : NULL;
    if (obj != NULL)
        traits.ConstructTail(*obj);
    const UPInt top = Sfr31Rd(vm, 0x50) + 0x20;
    Sfr31Wr(vm, 0x50, top);
    *reinterpret_cast<UInt32*>(top) = 0xc;
    Sfr31Wr(top, 8, 0);
    Sfr31Wr(top, 0x10, reinterpret_cast<UPInt>(obj));
}
// ---- batch 81
// The AVM flavor of a SetVariable value waiting for its target (0x40 bytes; the base lives in the player unit).
struct Sfr31AvmStickyVarNode
{
    const void* const* VTbl;    // +0x00 two slots: scalar deleting destructor, Assign (a function table kept here, not a C++ vftable)
    ASString Name;              // +0x08
    void*    pNext;             // +0x10
    bool     Permanent;         // +0x18
    Value    Val;               // +0x20
};

static void* Sfr31AvmStickyDelete(Sfr31AvmStickyVarNode* n, unsigned flags)
{
    n->Val.~Value();
    n->Name.~ASString();
    if (flags & 1)
        SF_FREE(n);
    return n;
}

static void Sfr31AvmStickyAssign(Sfr31AvmStickyVarNode* n, const Sfr31AvmStickyVarNode* o)
{
    n->Name = o->Name;
    n->Permanent = o->Permanent;
    n->Val = o->Val;
}

static const void* const Sfr31AvmStickyTable[2] = { reinterpret_cast<const void*>(&Sfr31AvmStickyDelete),
                                                    reinterpret_cast<const void*>(&Sfr31AvmStickyAssign) };

// MovieRoot::SetVariable: sets the member after the last '.' of the path on the object the rest of the path resolves to
// ("root" when there is no dot). setType 1 keeps the value for a target that does not exist yet, 2 keeps it permanently.
// MS2-FUNCTIONAL 0x14252a700: the multiname is built in a local structure and the string reference counts are folded into ASString; the sticky node is a local class standing in for the exe one
// @0x14252a700
char Sfr31MovieRootSetVariable(UPInt root, const char* path, const void* gfxValue, int setType)
{
    ASStringManager* const mgr = reinterpret_cast<ASStringManager*>(Sfr31Rd(root, 0x348));
    const UPInt len = strlen(path);
    const char* dot = NULL;
    for (UPInt i = len; i != 0; --i)
        if (path[i] == '.')
        {
            dot = path + i;
            break;
        }
    ASString member(mgr->CreateStringNode(dot != NULL ? dot + 1 : path));
    ASString target(dot != NULL ? mgr->CreateStringNode(path, static_cast<UPInt>(dot - path)) : mgr->CreateStringNode("root"));

    Value targetVal;
    if (!FUN_142506000(root, &targetVal, *reinterpret_cast<const UPInt*>(Sfr31Rd(reinterpret_cast<UPInt>(&target), 0))))
        return 0;

    const UPInt memberNode = Sfr31Rd(reinterpret_cast<UPInt>(&member), 0);
    struct Mn
    {
        UInt32 Flags;
        UPInt  Ns;
        Value  Name;
    } mn;
    mn.Flags = 0;
    mn.Ns = Sfr31Rd(Sfr31Rd(root, 0x48), 0x1d0);
    if (mn.Ns != 0)
        *reinterpret_cast<UInt32*>(mn.Ns + 0x10) = (*reinterpret_cast<UInt32*>(mn.Ns + 0x10) + 1u) & 0x8fbfffffu;
    if (memberNode == Sfr31Rd(memberNode, 8) + 0x68)
        mn.Name = Value::GetNull();
    else
    {
        mn.Name = member;
        const UInt32 n = *reinterpret_cast<const UInt32*>(memberNode + 0x20);
        if (n != 0)
        {
            const char* s = *reinterpret_cast<const char* const*>(memberNode);
            if (s[0] == '*' || s[0] == '@')
            {
                bool any = s[0] == '*';
                if (s[0] == '@')
                {
                    mn.Flags = 8;
                    any = n == 2 && s[1] == '*';
                }
                if (any)
                    mn.Name = ASString(reinterpret_cast<ASStringNode*>(Sfr31Rd(memberNode, 8) + 0x40));
                else if (s[0] == '@')
                    mn.Name = ASString(member.SubstringNode(1, static_cast<int>(n)));
            }
        }
    }

    Value converted;
    FUN_1425048d0(root, gfxValue, &converted);
    typedef char* (*SetPropFn)(void*, void*, void*, void*);
    const UPInt obj = Sfr31Rd(reinterpret_cast<UPInt>(&targetVal), 0x10);
    UPInt resSlot = 0;
    char result = *reinterpret_cast<SetPropFn>(Sfr31Rd(Sfr31Rd(obj, 0), 0x30))(reinterpret_cast<void*>(obj), &resSlot, &mn, &converted);
    if (((result == 0 && setType != 0) || setType == 2) && *reinterpret_cast<const UInt32*>(memberNode + 0x20) != 0)
    {
        Sfr31AvmStickyVarNode* node = static_cast<Sfr31AvmStickyVarNode*>(
            SF_HEAP_ALLOC(reinterpret_cast<MovieImpl*>(Sfr31Rd(root, 0x10))->GetMovieHeap(), sizeof(Sfr31AvmStickyVarNode), 0x147));   // movie heap, as the exe ([[root+0x10]+0x40])
        node->VTbl = Sfr31AvmStickyTable;
        new (&node->Name) ASString(member);
        node->pNext = NULL;
        node->Permanent = setType == 2;
        new (&node->Val) Value(converted);
        reinterpret_cast<MovieImpl*>(Sfr31Rd(root, 0x10))->AddStickyVariableNode(target, reinterpret_cast<MovieImpl::StickyVarNode*>(node));
    }
    const UPInt vm = Sfr31Rd(root, 0x48);
    if (*reinterpret_cast<const UByte*>(vm + 0x180) != 0)
    {
        *reinterpret_cast<UByte*>(vm + 0x180) = 0;
        FUN_14251bdc0(vm, reinterpret_cast<void*>(vm + 0x188));
        reinterpret_cast<Value*>(vm + 0x188)->SetUndefined();
    }
    return result;
}
}}} // namespace Scaleform::GFx::AS3

// INST-Reserve-BEGIN
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SlotContainerType::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SlotContainerType::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Slots::Pair,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Slots::Pair,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Multiname,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long const*,Scaleform::AllocatorDH<long const*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<double const*,Scaleform::AllocatorDH<double const*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object*,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<unsigned int,Scaleform::AllocatorLH_POD<unsigned int,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::TR::State*,Scaleform::AllocatorDH<Scaleform::GFx::AS3::TR::State*,328>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::ClassInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::ClassInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MetadataInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
struct Sfr31Rec24 { Scaleform::UInt64 a, b, c; };
struct Sfr31Rec64 { Scaleform::UInt64 a[8]; };
template void Scaleform::ArrayDataBase<const Scaleform::UInt8*,Scaleform::AllocatorDH<const Scaleform::UInt8*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::ASStringNode*,Scaleform::AllocatorGH<Scaleform::GFx::ASStringNode*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::DisplayObject*,Scaleform::AllocatorGH<Scaleform::GFx::DisplayObject*,2>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value*,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value*,331>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Sfr31Rec24,Scaleform::AllocatorLH<Sfr31Rec24,340>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo*,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::NamespaceInfo*,338>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Sfr31Rec64,Scaleform::AllocatorLH<Sfr31Rec64,332>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
template void Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>,328>,Scaleform::ArrayDefaultPolicy>::Reserve(const void*, UPInt);
// INST-Reserve-END

// INST-HashRaw-BEGIN
template void Scaleform::HashSetBase<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeAltHashF,Scaleform::AllocatorLH<int,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >,Scaleform::HashNode<int,Scaleform::AutoPtr<Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>,2,Scaleform::ArrayDefaultPolicy> >,Scaleform::IdentityHash<int> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::UInt32,340>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >,Scaleform::HashNode<Scaleform::UInt32,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::Function>,Scaleform::FixedSizeHash<Scaleform::UInt32> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode*,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>,Scaleform::HashNode<Scaleform::GFx::ASStringNode*,long long,Scaleform::GFx::AS3::ASStringNodeHashFunc>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::GFx::AS3::GASRefCountBase*,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >,Scaleform::HashNode<Scaleform::GFx::AS3::GASRefCountBase*,Scaleform::GFx::AS3::WeakProxy*,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::GASRefCountBase*> >::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::UInt32,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy>*,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::setRawCapacity(void*, Scaleform::UPInt);
template void Scaleform::HashSetBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> >,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase>,Scaleform::FixedSizeHash<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::GASRefCountBase> > > >::setRawCapacity(void*, Scaleform::UPInt);
// INST-HashRaw-END

// INST-Resize-BEGIN
template void Scaleform::ArrayBase<Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> >::Resize(Scaleform::UPInt);
template void Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::UInt8,Scaleform::AllocatorLH<Scaleform::UInt8,2>,Scaleform::ArrayDefaultPolicy> >::Resize(Scaleform::UPInt);
// INST-Resize-END

// THUNKS-BEGIN (work/sfr5/gen_thunks.py)
namespace Scaleform { namespace GFx { namespace AS3 {


}}} // namespace Scaleform::GFx::AS3
// THUNKS-END
// Vtable-only virtuals present at the executable addresses below.
// @0x142525c90
void Scaleform::GFx::DisplayObjectBase::Restart() {}
// @0x142526720
void Scaleform::GFx::InteractiveObject::SetDisplayCallback(void (SF_CDECL* callback)(void*), void* userPtr)
{
    pDisplayCallback = callback;
    DisplayCallbackUserPtr = userPtr;
}
// @0x1425274a0
void Scaleform::GFx::AS3::IntervalTimer::SetId(int id) { Id = id; }
// @0x1425287f0
void Scaleform::GFx::InteractiveObject::SetPause(bool) {}
// @0x142528800
void Scaleform::GFx::InteractiveObject::SetPlayState(Scaleform::GFx::PlayState) {}
// @0x142528d90
void Scaleform::GFx::DisplayObjectBase::SetRatio(float) {}
// @0x142529f40
void Scaleform::GFx::DisplayObjectBase::SetStateChangeFlags(Scaleform::UByte) {}
// @0x142529f50
void Scaleform::GFx::InteractiveObject::SetStateChangeFlags(Scaleform::UByte flags)
{
    Flags = (Flags & 0xfff0ffffu) | ((static_cast<Scaleform::UInt32>(flags) & 0x0fu) << 16);
}
// @0x14252c8a0
void Scaleform::GFx::AS3::IntervalTimer::Start(Scaleform::GFx::MovieImpl* proot)
{
    const auto* movieBytes = reinterpret_cast<const unsigned char*>(proot);
    InvokeTime = *reinterpret_cast<const Scaleform::UInt64*>(movieBytes + 0x268) + Interval;
}
// @0x14252c9c0
void Scaleform::GFx::InteractiveObject::StopActiveSounds(Scaleform::GFx::ASSoundIntf*) {}
// @0x14252c9d0
void Scaleform::GFx::InteractiveObject::StopActiveSounds(Scaleform::GFx::SoundResource*) {}
// @0x14252c9e0
void Scaleform::GFx::InteractiveObject::StopActiveSounds() {}
// @0x14252e520
bool Scaleform::GFx::AS3::InstanceTraits::Traits::SupportsInterface(const Scaleform::GFx::AS3::InstanceTraits::Traits&) const { return false; }
// @0x14252fee0
Scaleform::GFx::AS3::CheckResult Scaleform::GFx::AS3::XMLSupport::ToXMLString(Scaleform::GFx::AS3::VM&, Scaleform::GFx::AS3::Value&) const
{
    return Scaleform::GFx::AS3::CheckResult(false);
}
// @0x142540ba0
void Scaleform::GFx::AS3::Class::lengthGet(Scaleform::SInt32& result)
{
    result = *reinterpret_cast<const Scaleform::SInt32*>(reinterpret_cast<const unsigned char*>(this) + 0x40);
}

// MS2-PIN: ?SetUInt32@Value@AS3@GFx@Scaleform@@QEAAXK@Z 0x14252a460

// The out-of-line array COMDATs of this range, on the real element types (header templates, so attributed by
// byte match or MS2-PIN rather than by tag).
namespace Scaleform {
// The exe calls the Value range destructor out of line from the ResizeNoConstruct bodies (0x1424f6d50, sfr_as3_17).
extern template void ConstructorMov<GFx::AS3::Value>::DestructArray(GFx::AS3::Value*, UPInt);
template void ArrayDataBase<GFx::AS3::Value, AllocatorGH<GFx::AS3::Value, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524e20
template void ArrayDataBase<GFx::AS3::Value, AllocatorLH<GFx::AS3::Value, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524ec0
template void ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524cd0
template void ArrayDataBase<WeakPtr<GFx::DisplayObject>, AllocatorLH<WeakPtr<GFx::DisplayObject>, Stat_Default_Mem>, ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity);   // 0x142523990
template void ArrayDataBase<Ptr<GFx::InteractiveObject>, AllocatorDH<Ptr<GFx::InteractiveObject>, GFx::StatMV_Other_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524990
template void ArrayDataBase<GFx::AS3::SPtr<GFx::ASStringNode>, AllocatorLH<GFx::AS3::SPtr<GFx::ASStringNode>, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524a30
template void ArrayData<ArrayLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>, AllocatorLH<ArrayLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x1425244e0
template void ArrayData<GFx::AS3::Abc::MethodBodyInfo::Exception, AllocatorLH<GFx::AS3::Abc::MethodBodyInfo::Exception, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524710
template void ArrayDataBase<GFx::AS3::Abc::MethodBodyInfo::Exception, AllocatorLH<GFx::AS3::Abc::MethodBodyInfo::Exception, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity);   // 0x142523b70
template void ArrayData<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::NamespaceSet>, Stat_Default_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524680
}
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@VValue@AS3@GFx@Scaleform@@U?$AllocatorGH@VValue@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142524e20
// MS2-PIN: ?ResizeNoConstruct@?$ArrayDataBase@VValue@AS3@GFx@Scaleform@@U?$AllocatorLH@VValue@AS3@GFx@Scaleform@@$0BEL@@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAXPEBX_K@Z 0x142524ec0
// MS2-PIN: ?Resize@?$ArrayData@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@U?$AllocatorLH@V?$SPtr@VNamespaceSet@AS3@GFx@Scaleform@@@AS3@GFx@Scaleform@@$01@4@UArrayDefaultPolicy@4@@Scaleform@@QEAAX_K@Z 0x142524680
// MS2-PIN: ?Reserve@?$ArrayDataBase@UException@MethodBodyInfo@Abc@AS3@GFx@Scaleform@@U?$AllocatorLH@UException@MethodBodyInfo@Abc@AS3@GFx@Scaleform@@$0BFE@@6@UArrayDefaultPolicy@6@@Scaleform@@QEAAXPEBX_K@Z 0x142523b70
namespace Scaleform {
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, Stat_Default_Mem>, ArrayDefaultPolicy>::Reserve(const void* pheapAddr, UPInt newCapacity);   // 0x142523850
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524b90 (MovieRoot::AbcFiles)
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::VMAbcFile>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524c30 (VMAbcFile::Children)
template void ArrayDataBase<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, AllocatorLH<GFx::AS3::SPtr<GFx::AS3::ClassTraits::Traits>, GFx::AS3::StatMV_VM_VMAbcFile_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524af0 (VMAbcFile::LoadedClasses)
template void ArrayDataBase<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x142524d80
template void ArrayDataCC<GFx::ASString, AllocatorLH<GFx::ASString, GFx::AS3::StatMV_VM_VTable_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524470 (VTable::NamesT)
template void ArrayData<Ptr<GFx::InteractiveObject>, AllocatorLH<Ptr<GFx::InteractiveObject>, GFx::AS3::StatMV_ActionScript_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x1425245c0 (RolloverStack)
template void ArrayData<UPInt, AllocatorLH_POD<UPInt, GFx::AS3::StatMV_VM_AbcFile_Mem>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x1425247f0
template void ArrayDataDH<UPInt, AllocatorDH_POD<UPInt, GFx::AS3::StatMV_VM>, ArrayDefaultPolicy>::Resize(UPInt newSize);   // 0x142524870 (Tracer TCodeOffset arrays)
template void ArrayDataBase<GFx::Button::CharToRec, AllocatorLH<GFx::Button::CharToRec, Stat_Default_Mem>, ArrayDefaultPolicy>::ResizeNoConstruct(const void* pheapAddr, UPInt newSize);   // 0x1425248e0 (Button::StateCharArray)
}
// MS2-PIN: ?Resize@?$ArrayDataCC@VASString@GFx@Scaleform@@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEL@@3@UArrayDefaultPolicy@3@@Scaleform@@QEAAX_K@Z 0x142524470

// The out-of-line HashSetBase::setRawCapacity COMDATs of this range, on the node/allocator/entry types of the add
// instances in sfr_as3_15 (the same typedefs, repeated here).
namespace Scaleform {
template<class N, class A, class E>
struct MS2_HashSetOf
{
    typedef HashSetBase<N, typename N::NodeHashF, typename N::NodeAltHashF, A, E> Type;
};
typedef HashSetBase<const void*, FixedSizeHash<const void*>, FixedSizeHash<const void*>, AllocatorGH<const void*, 2>,
                    HashsetCachedEntry<const void*, FixedSizeHash<const void*> > > MS2_ObjPtrSet;
typedef HashNode<int, AutoPtr<ArrayLH<WeakPtr<GFx::DisplayObject>, 2> >, IdentityHash<int> > MS2_DepthToObjsNode;
typedef MS2_HashSetOf<MS2_DepthToObjsNode, AllocatorLH<int, 2>,
                      HashsetNodeEntry<MS2_DepthToObjsNode, MS2_DepthToObjsNode::NodeHashF> >::Type MS2_DepthToObjsSet;
struct MS2_SlotPos
{
    SPInt       Ind;
    const void* pSlots;

    MS2_SlotPos(const MS2_SlotPos& other) : Ind(other.Ind), pSlots(other.pSlots) {}
    MS2_SlotPos& operator=(const MS2_SlotPos& other)
    {
        Ind    = other.Ind;
        pSlots = other.pSlots;
        return *this;
    }
};
typedef HashNode<UInt32, MS2_SlotPos, FixedSizeHash<UInt32> > MS2_SlotPosNode;
typedef MS2_HashSetOf<MS2_SlotPosNode, AllocatorDH<UInt32, 2>,
                      HashsetCachedNodeEntry<MS2_SlotPosNode, MS2_SlotPosNode::NodeHashF> >::Type MS2_SlotPosSet;
typedef HashNode<UInt32, GFx::AS3::SPtr<GFx::AS3::InstanceTraits::Function>, FixedSizeHash<UInt32> > MS2_FunctionTraitsNode;
typedef MS2_HashSetOf<MS2_FunctionTraitsNode, AllocatorLH<UInt32, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_FunctionTraitsNode, MS2_FunctionTraitsNode::NodeHashF> >::Type
    MS2_FunctionTraitsSet;
typedef HashNode<GFx::AS3::GASRefCountBase*, GFx::AS3::WeakProxy*, FixedSizeHash<GFx::AS3::GASRefCountBase*> > MS2_WeakProxyNode;
typedef MS2_HashSetOf<MS2_WeakProxyNode, AllocatorGH<GFx::AS3::GASRefCountBase*, 2>,
                      HashsetCachedNodeEntry<MS2_WeakProxyNode, MS2_WeakProxyNode::NodeHashF> >::Type MS2_WeakProxySet;
struct MS2_LoadedMovieDefInfo
{
    Ptr<GFx::MovieDefImpl> pMovieDef;
    unsigned               UseCnt;

    MS2_LoadedMovieDefInfo(GFx::MovieDefImpl* def) : pMovieDef(def), UseCnt(1) {}
};
typedef HashNode<GFx::MovieDefImpl*, MS2_LoadedMovieDefInfo, IdentityHash<GFx::MovieDefImpl*> > MS2_LoadedMovieDefNode;
typedef MS2_HashSetOf<MS2_LoadedMovieDefNode, AllocatorLH<GFx::MovieDefImpl*, 2>,
                      HashsetNodeEntry<MS2_LoadedMovieDefNode, MS2_LoadedMovieDefNode::NodeHashF> >::Type
    MS2_LoadedMovieDefSet;
typedef HashNode<const GFx::AS3::Abc::MethodBodyInfo*, GFx::AS3::SPtr<GFx::AS3::InstanceTraits::Traits>,
                 FixedSizeHash<const GFx::AS3::Abc::MethodBodyInfo*> > MS2_ActivationTraitsNode;
typedef MS2_HashSetOf<MS2_ActivationTraitsNode, AllocatorLH<const GFx::AS3::Abc::MethodBodyInfo*, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_ActivationTraitsNode, MS2_ActivationTraitsNode::NodeHashF> >::Type
    MS2_ActivationTraitsSet;
typedef GFx::AS3::AbcMultinameHash<GFx::AS3::SPtr<GFx::AS3::Instances::Namespace> >::Key MS2_AbcNsKey;
typedef HashNode<MS2_AbcNsKey, GFx::AS3::SPtr<GFx::AS3::Instances::Namespace>, FixedSizeHash<MS2_AbcNsKey> > MS2_AbcNsNode;
typedef MS2_HashSetOf<MS2_AbcNsNode, AllocatorLH<MS2_AbcNsKey, GFx::AS3::StatMV_VM_VMAbcFile_Mem>,
                      HashsetCachedNodeEntry<MS2_AbcNsNode, MS2_AbcNsNode::NodeHashF> >::Type MS2_AbcNsSet;
typedef HashNode<GFx::ASString, GFx::AS3::Value, GFx::ASStringHashFunctor> MS2_StringValueNode;
typedef MS2_HashSetOf<MS2_StringValueNode, AllocatorLH<GFx::ASString, GFx::StatMV_ASString_Mem>,
                      HashsetNodeEntry<MS2_StringValueNode, MS2_StringValueNode::NodeHashF> >::Type MS2_StringValueSet;
typedef GFx::AS3::SPtr<GFx::AS3::GASRefCountBase> MS2_GCRootPtr;
typedef HashSetBase<MS2_GCRootPtr, FixedSizeHash<MS2_GCRootPtr>, FixedSizeHash<MS2_GCRootPtr>, AllocatorLH<MS2_GCRootPtr, 2>,
                    HashsetCachedEntry<MS2_GCRootPtr, FixedSizeHash<MS2_GCRootPtr> > > MS2_GCRootSet;

extern template void MS2_ObjPtrSet::add<const void*>(void*, const void* const&, UPInt);
extern template void MS2_ObjPtrSet::Clear();
template<class T> struct MS2_SetValueOf;
template<class C, class H, class AH, class A, class E>
struct MS2_SetValueOf<HashSetBase<C, H, AH, A, E> >
{
    typedef C Type;
};
typedef decltype(GFx::AS3::Object::DynAttrsType::mHash)::BaseType MS2_DynAttrsSet;
typedef decltype(GFx::AS3::Slots::SetType::mHash)::BaseType MS2_SlotNameSet;
extern template void MS2_DepthToObjsSet::add<MS2_DepthToObjsNode>(void*, const MS2_DepthToObjsNode&, UPInt);
extern template void MS2_DepthToObjsSet::Clear();
extern template void MS2_SlotPosSet::add<MS2_SlotPosNode>(void*, const MS2_SlotPosNode&, UPInt);
extern template void MS2_FunctionTraitsSet::add<MS2_FunctionTraitsNode>(void*, const MS2_FunctionTraitsNode&, UPInt);
extern template void MS2_FunctionTraitsSet::Clear();
extern template void MS2_WeakProxySet::CheckExpand(void*);
extern template void MS2_LoadedMovieDefSet::add<MS2_LoadedMovieDefNode>(void*, const MS2_LoadedMovieDefNode&, UPInt);
extern template void MS2_ActivationTraitsSet::add<MS2_ActivationTraitsNode>(void*, const MS2_ActivationTraitsNode&, UPInt);
extern template void MS2_ActivationTraitsSet::Clear();
extern template void MS2_DynAttrsSet::CheckExpand(void*);
extern template void MS2_AbcNsSet::add<MS2_AbcNsNode>(void*, const MS2_AbcNsNode&, UPInt);
extern template void MS2_AbcNsSet::Clear();
extern template void MS2_SlotNameSet::add<MS2_SetValueOf<MS2_SlotNameSet>::Type>(void*, const MS2_SetValueOf<MS2_SlotNameSet>::Type&, UPInt);
extern template void MS2_SlotNameSet::Clear();
extern template void MS2_StringValueSet::add<MS2_StringValueNode>(void*, const MS2_StringValueNode&, UPInt);
extern template void MS2_GCRootSet::add<MS2_GCRootPtr>(void*, const MS2_GCRootPtr&, UPInt);
extern template void MS2_GCRootSet::Clear();
extern template MS2_FunctionTraitsSet::~HashSetBase();
extern template MS2_ActivationTraitsSet::~HashSetBase();
extern template MS2_DynAttrsSet::~HashSetBase();
extern template MS2_StringValueSet::~HashSetBase();
extern template MS2_AbcNsSet::~HashSetBase();
extern template MS2_GCRootSet::~HashSetBase();
extern template UPInt FixedSizeHash<MS2_AbcNsKey>::operator()(const MS2_AbcNsKey&) const;
template void MS2_ObjPtrSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142540c40
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@H$01@2@V?$HashsetNodeEntry@U?$HashNode@HV?$AutoPtr@V?$ArrayLH@V?$WeakPtr@VDisplayObject@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@Scaleform@@@Scaleform@@V?$IdentityHash@H@2@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142540e40
template void MS2_DepthToObjsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142540e40
template void MS2_SlotPosSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142540fc0
template void MS2_FunctionTraitsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541170
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorGH@PEAVGASRefCountBase@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@PEAVGASRefCountBase@AS3@GFx@Scaleform@@PEAVWeakProxy@234@V?$FixedSizeHash@PEAVGASRefCountBase@AS3@GFx@Scaleform@@@4@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x1425415a0
template void MS2_WeakProxySet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x1425415a0
template void MS2_LoadedMovieDefSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x1425418d0
template void MS2_ActivationTraitsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541a60
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@UDynAttrsKey@Object@AS3@GFx@Scaleform@@$01@2@V?$HashsetCachedNodeEntry@U?$HashNode@UDynAttrsKey@Object@AS3@GFx@Scaleform@@VValue@345@UDynAttrsKeyHashFunctor@2345@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142541ca0
template void decltype(GFx::AS3::Object::DynAttrsType::mHash)::BaseType::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541ca0
template void MS2_AbcNsSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142541fe0
template void decltype(GFx::AS3::Slots::SetType::mHash)::BaseType::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142542170
// MS2-PIN: ?setRawCapacity@?$HashSetBase@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@UNodeAltHashF@12@U?$AllocatorLH@VASString@GFx@Scaleform@@$0BEE@@2@V?$HashsetNodeEntry@U?$HashNode@VASString@GFx@Scaleform@@VValue@AS3@23@UASStringHashFunctor@23@@Scaleform@@UNodeHashF@12@@2@@Scaleform@@AEAAXPEAX_K@Z 0x142542450
template void MS2_StringValueSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x142542450
template void MS2_GCRootSet::setRawCapacity(void* pheapAddr, UPInt newSize);   // 0x1425425e0
}
