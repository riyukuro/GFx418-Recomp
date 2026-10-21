// Recovered Scaleform 4.1.18 GFx AS2: the String wrapper object and its prototype methods.
// Shared header of the src/ms2/scaleform units (sfr lane): append, do not reorder members.
#ifndef MS2_SF_GFX_AS2_STRINGOBJECT_H
#define MS2_SF_GFX_AS2_STRINGOBJECT_H

#include "as2_action.h"

namespace Scaleform { namespace GFx { namespace AS2 {

// String instance. 0x70 bytes.
class StringObject : public Object
{
public:
    ASString sValue; // +0x68
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
};

// The String constructor function's own methods.
class StringCtorFunction
{
private:
    static void StringFromCharCode(const FnCall& fn);
};

}}} // namespace Scaleform::GFx::AS2

#endif
