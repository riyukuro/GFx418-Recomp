// Recovered Scaleform 4.1.18 GFx AS2: the String wrapper object and its prototype methods.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_STRINGOBJECT_H
#define MS2_SF_GFX_AS2_STRINGOBJECT_H

#include "as2_action.h"
#include "as2_arrayobject.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// String instance. 0x70 bytes.
class StringObject : public Object
{
public:
    ASString sValue; // +0x68

    // "length" defaults to the length of the string (exe 0x1429538a0).
    virtual bool GetMemberRaw(ASStringContext* psc, const ASString& name, Value* val);
    virtual void SetValue(Environment* penv, const Value& v); // exe 0x14298cc80

protected:
    virtual void Finalize_GC(); // exe 0x142942fc0
};

// String.prototype methods.
class StringProto
{
public:
    static void StringCharAt(const FnCall& fn);
    static void StringCharCodeAt(const FnCall& fn);
    static void StringConcat(const FnCall& fn);
    static void StringIndexOf(const FnCall& fn);
    static void StringLastIndexOf(const FnCall& fn);
    static void StringLocaleCompare(const FnCall& fn);
    static void StringSlice(const FnCall& fn);
    static void StringSplit(const FnCall& fn);
    static void StringSubstr(const FnCall& fn);
    static void StringSubstring(const FnCall& fn);
    static void StringToLowerCase(const FnCall& fn);
    static void StringToString(const FnCall& fn);
    static void StringToUpperCase(const FnCall& fn);
    static void StringValueOf(const FnCall& fn);

    // length characters of str from start (length < 0: to the end) (exe 0x142990960).
    static ASString StringSubstring(const ASString& str, int start, int length);
    // str cut at each delimiter (0: one element per character), at most limit elements (exe 0x1429902c0).
    MS2_AS2_SCU static Ptr<ArrayObject> StringSplit(Environment* penv, const ASString& str, const char* delimiters, int limit);
    // The string from start to end (0: to the terminator); empty for a negative length (exe 0x142937e20).
    static ASString CreateStringFromCStr(ASStringContext* psc, const char* start, const char* end = 0);
};

// The String constructor function's own methods.
class StringCtorFunction
{
private:
    static void StringFromCharCode(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
