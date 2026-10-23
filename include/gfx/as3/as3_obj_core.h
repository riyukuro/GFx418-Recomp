// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13): Scaleform GFx 4.1.18 AS3, the core top-level classes
// (Object, Array, Boolean, Number, int, uint, String, Math, Date, RegExp, QName, XML, XMLList, Catch and the Error
// family): their class traits, instance traits and class objects. Our own declarations, written from the exe.
// Type strings are the exe's (the 4.1.18 build is not consistent about the "fl::" part). Methods marked @ without a
// body here are defined in the AS3_Obj_All units.
#ifndef MS2_SCALEFORM_GFX_AS3_OBJ_CORE_H
#define MS2_SCALEFORM_GFX_AS3_OBJ_CORE_H

#include "ms2/scaleform/include/gfx/as3/as3_obj.h"
#include "ms2/scaleform/include/gfx/as3/obj/as3_obj_fwd.h"

// (appended, sfr19) PCRE's free hook (pcre_globals), which RegExp frees its compiled pattern through.
extern "C" void (*pcre_free)(void*);

namespace Scaleform { namespace GFx { namespace AS3 {

namespace fl
{
    extern const ClassInfo ObjectCI;
    extern const ClassInfo ArrayCI;
    extern const ClassInfo BooleanCI;
    extern const ClassInfo CatchCI;
    extern const ClassInfo DateCI;
    extern const ClassInfo ErrorCI;
    extern const ClassInfo MathCI;
    extern const ClassInfo NamespaceCI;
    extern const ClassInfo NumberCI;
    extern const ClassInfo QNameCI;
    extern const ClassInfo RegExpCI;
    extern const ClassInfo StringCI;
    extern const ClassInfo XMLCI;
    extern const ClassInfo XMLListCI;
    extern const ClassInfo int_CI;
    extern const ClassInfo uintCI;
    extern const ClassInfo ArgumentErrorCI;
    extern const ClassInfo DefinitionErrorCI;
    extern const ClassInfo EvalErrorCI;
    extern const ClassInfo RangeErrorCI;
    extern const ClassInfo ReferenceErrorCI;
    extern const ClassInfo SecurityErrorCI;
    extern const ClassInfo SyntaxErrorCI;
    extern const ClassInfo TypeErrorCI;
    extern const ClassInfo URIErrorCI;
    extern const ClassInfo UninitializedErrorCI;
    extern const ClassInfo VerifyErrorCI;
}

namespace InstanceTraits { namespace fl { class Namespace; } }

// (appended, sfr19) visitor of SparseArray::ForEach: slot 1 is called per element with its index.
class ArrayFunc
{
public:
    virtual ~ArrayFunc() {}
    virtual void operator()(UInt32 ind, const Value& v) = 0;
};

// Array storage: a dense part (ValueA) plus a hash for the indices past it. 0x68 bytes.
class SparseArray
{
public:
    explicit SparseArray(MemoryHeap* heap)
        : Length(0), ValueHLowInd(0), ValueHHighInd(0), ValueA(heap), ValueH(heap)
    {
    }

    // Resize 0x14241fe30, At 0x142405480, Set 0x1424213b0 (defined with the Array bodies).
    void Resize(UPInt newLength);
    const Value& At(UPInt ind) const;
    void Set(UPInt ind, const Value& v);
    UPInt GetSize() const { return Length; }

    // (appended, sfr14) bodies in sfr_as3_04.
    void PushBack(const Value& v);
    void Insert(UPInt pos, unsigned argc, const Value* argv);
    const Value& Top() const;
    AbsoluteIndex GetNextArrayIndex(AbsoluteIndex ind) const;

    // (appended, sfr19) bodies in sfr_as3_03.
    void Assign(const SparseArray& other);
    void Append(const ValueArrayDH& x);
    void Append(const ValueArray& x, UPInt ind, UPInt num);
    void Append(const SparseArray& other, UPInt ind, UPInt num);
    void Append(unsigned argc, const Value* argv);
    void ForEach(ArrayFunc& f) const;

    // (appended, sfr19) bodies in sfr_as3_04.
    void RemoveMultipleAt(UPInt pos, UPInt count);  // 0x14241ec80
    void Reverse();                                 // 0x142420800
    void Pop() { if (GetSize()) RemoveMultipleAt(GetSize() - 1, 1); }

    // (appended, sfr19) visits the dense and the hashed values for owner. 0x14240c050
    void ForEachChild_GC(RefCountCollector<StatMV_ActionScript_Mem>* prcc, ASRefCountBaseType::GcOp op,
                         const ASRefCountBaseType& owner) const;

    // (appended, sfr22) removes [pos, pos + count), pushing the removed values onto deleted when given. 0x142408230
    void CutMultipleAt(UPInt pos, UPInt count, SparseArray* deleted);

private:
    // (appended, sfr22) the hash part of CutMultipleAt: from first_ind, values below first_ind + cut_num go to
    // deleted, the rest move down by offset. 0x142407e30
    void CutHash(UPInt first_ind, UPInt cut_num, UPInt offset, SparseArray* deleted);
    // (appended, sfr22) moves the hashed values from first_ind up to the high bound down by offset. 0x14241ce70
    void MoveHashLeft(UPInt first_ind, UPInt offset);
    UPInt GetLeftEqualInd(UPInt start_from) const;
    UPInt GetRightEqualInd(UPInt start_from, UPInt end_ind) const;
    void MoveHashRight(UPInt first_ind, UPInt offset);
    void RemoveHash(UPInt first_ind, UPInt num);

public:
    UPInt                   Length;         // +0x00
    UPInt                   ValueHLowInd;   // +0x08
    UPInt                   ValueHHighInd;  // +0x10
    Value                   DefaultValue;   // +0x18
    ValueArrayDH            ValueA;         // +0x38
    HashDH<UPInt, Value>    ValueH;         // +0x58
};

// (appended, sfr15) string ordering used by Array sort; the flags are the sort options. 3 bytes.
class CompareAsString
{
public:
    CompareAsString(bool desc, bool ci, bool use_locale) : Desc(desc), CaseInsensitive(ci), UseLocale(use_locale) {}

    // exe 0x1424066d0 (body in sfr_as3_03).
    int Compare(const ASString& a, const ASString& b) const;

private:
    CompareAsString& operator=(const CompareAsString&);

    const bool Desc;            // +0x00
    const bool CaseInsensitive; // +0x01
    const bool UseLocale;       // +0x02
};

namespace Instances { namespace fl
{
    // 0xa0 bytes.
    class Array : public Instance
    {
    public:
        explicit Array(InstanceTraits::Traits& t);
        // @0x142414d00
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Array"; }
        // @0x14240bc90
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142421ff0
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);
        // @0x142416730
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);
        // @0x1424159a0
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);
        // @0x142409060
        virtual CheckResult DeleteProperty(const Multiname& prop_name);
        // @0x1423f5550
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // @0x142416200
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
        // @0x142416100
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
        // @0x142416520
        virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);

    public:
        void Resize(UPInt newLength) { SA.Resize(newLength); }
        const Value& At(UPInt ind) const { return SA.At(ind); }
        void Set(UPInt ind, const Value& v) { SA.Set(ind, v); }
        UPInt GetSize() const { return SA.GetSize(); }

    public:
        SparseArray SA;     // +0x38

    public:
        // native methods
        // @0x1423f7f50
        void AS3concat(Value& result, unsigned, const Value*);
        // @0x1423f8f60
        void AS3every(bool& result, const Value&, const Value&);
        // @0x1423f9880
        void AS3filter(SPtr<Instances::fl::Array>& result, const Value&, const Value&);
        // @0x1423f9d60
        void AS3forEach(const Value& result, const Value&, const Value&);
        // @0x1423fb1a0
        void AS3indexOf(SInt32& result, const Value&, SInt32);
        // @0x1423fb450
        void AS3join(Value& result, unsigned, const Value*);
        // @0x1423fb4e0
        void AS3lastIndexOf(SInt32& result, const Value&, SInt32);
        // @0x1423fbb20
        void AS3map(SPtr<Instances::fl::Array>& result, const Value&, const Value&);
        // @0x1423fcd60
        void AS3pop(Value& result);
        // @0x1423fd780
        void AS3push(Value& result, unsigned, const Value*);
        // @0x1423fdf30
        void AS3reverse(SPtr<Instances::fl::Array>& result);
        // @0x1423ff400
        void AS3shift(Value& result);
        // @0x1423ff4d0
        void AS3slice(SPtr<Instances::fl::Array>& result, SInt32, SInt32);
        // @0x1423ff800
        void AS3some(bool& result, const Value&, const Value&);
        // @0x1423ffba0
        void AS3sort(Value& result, unsigned, const Value*);
        // @0x142400500
        void AS3sortOn(SPtr<Instances::fl::Array>& result, const Value&, const Value&);
        // @0x142400d30
        void AS3splice(Value& result, unsigned, const Value*);
        // @0x1424036f0
        void AS3unshift(Value& result, unsigned, const Value*);

    public:
        // 0x142425540 (appended, sfr15)
        ASString ToLocaleStringInternal() const;
        // 0x142425b50 (appended, sfr15)
        ASString ToStringInternal(const ASString& sep) const;
        // @0x1423e0260 (appended, sfr15)
        static void toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e02a0 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142429290
        void lengthGet(UInt32& result);
        // @0x142429480
        void lengthSet(const Value& result, UInt32);
    };
    // Instance of the Catch scope of an exception handler. 0x38 bytes.
    class Catch : public Instance
    {
    public:
        explicit Catch(InstanceTraits::Traits& t);
        // @0x142414d80
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Catch"; }
    };

    // 0x48 bytes.
    class Date : public Instance
    {
    public:
        explicit Date(InstanceTraits::Traits& t);
        // @0x142414dd0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Date"; }
        // @0x1423f5650
        virtual void AS3Constructor(unsigned argc, const Value* argv);

    public:
        Value::Number   TimeValue;  // +0x38 ms since 1970-01-01 UTC
        SInt32          LocalTZA;   // +0x40

    public:
        // (appended, sfr14) ECMA-262 15.9.1 time arithmetic (bodies in sfr_as3_04). Times are ms since the epoch.
        static void   GetCurrentTimeValue(Value::Number* pTime, SInt32* pLocalTZA);
        static Value::Number HourFromTime(Value::Number t);
        static Value::Number MinFromTime(Value::Number t);
        static Value::Number SecFromTime(Value::Number t);
        static Value::Number MsFromTime(Value::Number t);
        static SInt32 WeekDay(Value::Number t);
        static Value::Number YearFromTime(Value::Number t);
        static SInt32 MonthFromTime(Value::Number t);
        static SInt32 MonthFromYearDay(SInt32 year, SInt32 day);
        static SInt32 DateFromTime(Value::Number t);
        static Value::Number MakeDay(Value::Number year, Value::Number month, Value::Number date);
        static Value::Number MakeTime(Value::Number hour, Value::Number min, Value::Number sec, Value::Number ms);
        static Value::Number TimeClip(Value::Number t);
        // (appended, sfr15) day number of the first day of a year (exe 0x142408710, body in sfr_as3_03).
        static Value::Number DayFromYear(Value::Number year);
        // (appended, sfr15) days before the end of each month: common years, then leap years (exe 0x14313e2f0).
        static const SInt32 Months[2][12];

        // (appended, sfr14) per-component date/time editing used by the set* natives.
        enum TimeEntry { Time_Hour, Time_Minute, Time_Second, Time_Ms, Time_Entry_Count };
        enum DateEntry { Date_Year, Date_Month, Date_Day, Date_Entry_Count };

        // Broken-down local time of a time value; MakeDate rebuilds it.
        struct TimeHolder
        {
            Value::Number Entries[Time_Entry_Count];    // +0x00

            TimeHolder(Value::Number time, Value::Number tza);
            Value::Number MakeDate() const;
        private:
            Value::Number Day;                          // +0x20
            Value::Number TZA;                          // +0x28
        };

        // Broken-down local date of a time value; MakeDate rebuilds it.
        struct DateHolder
        {
            Value::Number Entries[Date_Entry_Count];    // +0x00

            DateHolder(Value::Number time, Value::Number tza);
            Value::Number MakeDate() const;
        private:
            Value::Number TimeInDay;                    // +0x18
            Value::Number TZA;                          // +0x20
        };

        // Result of parsing a date string.
        struct Parser
        {
            bool    Valid;                              // +0x00
            bool    HasYear, HasMonth, HasDay, HasTime, HasTZA;
            int  Month;                              // +0x08
            int  Day;                                // +0x0C
            int  Year;                               // +0x10
            int  DayOfWeek;                          // +0x14
            int  TZA;                                // +0x18
            int  Hour, Minute, Sec;                  // +0x1C

            Parser(const char* str);                 // 0x1423ee1f0
            Value::Number MakeDate(int localTZA) const;

        private:
            enum StringType { String_Invalid, String_Month, String_WeekDay, String_GMT, String_UTC, String_AM, String_PM };
            static StringType interpretDateString(const char* pstr, SPInt length, int* index);
        };

        void applyTimeArgs(Value& result, unsigned argc, const Value* const argv, TimeEntry firstArg, Value::Number tza);
        void applyDateArgs(Value& result, unsigned argc, const Value* const argv, DateEntry firstArg, Value::Number tza);
        void applyTimeArg(TimeEntry arg, Value::Number value, Value::Number tza);
        void applyDateArg(DateEntry arg, Value::Number value, Value::Number tza);
        static Value::Number decodeUTCArgs(unsigned argc, const Value* const argv, Value::Number tza);
        static UPInt formatDateTimeString(char* buffer, UPInt bufferSize, Value::Number t, int tza,
                                          bool needDate, bool needTime, bool utc = false);

    public:
        // native methods
        // @0x1423fa190
        void AS3getDate(Value::Number& result);
        // @0x1423fa200
        void AS3getDay(Value::Number& result);
        // @0x1423fa2a0
        void AS3getFullYear(Value::Number& result);
        // @0x1423fa310
        void AS3getHours(Value::Number& result);
        // @0x1423fa3a0
        void AS3getMilliseconds(Value::Number& result);
        // @0x1423fa420
        void AS3getMinutes(Value::Number& result);
        // @0x1423fa4b0
        void AS3getMonth(Value::Number& result);
        // @0x1423fa520
        void AS3getSeconds(Value::Number& result);
        // @0x1423fa5b0
        void AS3getTime(Value::Number& result);
        // @0x1423fa5c0
        void AS3getTimezoneOffset(Value::Number& result);
        // @0x1423fa620
        void AS3getUTCDate(Value::Number& result);
        // @0x1423fa680
        void AS3getUTCDay(Value::Number& result);
        // @0x1423fa700
        void AS3getUTCFullYear(Value::Number& result);
        // @0x1423fa750
        void AS3getUTCHours(Value::Number& result);
        // @0x1423fa7d0
        void AS3getUTCMilliseconds(Value::Number& result);
        // @0x1423fa840
        void AS3getUTCMinutes(Value::Number& result);
        // @0x1423fa8c0
        void AS3getUTCMonth(Value::Number& result);
        // @0x1423fa920
        void AS3getUTCSeconds(Value::Number& result);
        // @0x1423fe350
        void AS3setDate(Value& result, unsigned, const Value*);
        // @0x1423fe380
        void AS3setFullYear(Value& result, unsigned, const Value*);
        // @0x1423fe3b0
        void AS3setHours(Value& result, unsigned, const Value*);
        // @0x1423fe590
        void AS3setMilliseconds(Value& result, unsigned, const Value*);
        // @0x1423fe5c0
        void AS3setMinutes(Value& result, unsigned, const Value*);
        // @0x1423fe5f0
        void AS3setMonth(Value& result, unsigned, const Value*);
        // @0x1423fea90
        void AS3setSeconds(Value& result, unsigned, const Value*);
        // @0x1423fefc0
        void AS3setTime(Value::Number& result, Value::Number);
        // @0x1423ff040
        void AS3setUTCDate(Value& result, unsigned, const Value*);
        // @0x1423ff060
        void AS3setUTCFullYear(Value& result, unsigned, const Value*);
        // @0x1423ff080
        void AS3setUTCHours(Value& result, unsigned, const Value*);
        // @0x1423ff0a0
        void AS3setUTCMilliseconds(Value& result, unsigned, const Value*);
        // @0x1423ff0c0
        void AS3setUTCMinutes(Value& result, unsigned, const Value*);
        // @0x1423ff0e0
        void AS3setUTCMonth(Value& result, unsigned, const Value*);
        // @0x1423ff100
        void AS3setUTCSeconds(Value& result, unsigned, const Value*);
        // @0x142401ae0
        void AS3toDateString(ASString& result);
        // @0x142401fc0
        void AS3toLocaleDateString(ASString& result);
        // @0x142402050
        void AS3toLocaleString(ASString& result);
        // @0x142402070
        void AS3toLocaleTimeString(ASString& result);
        // @0x1424025b0
        void AS3toString(ASString& result);
        // @0x142403050
        void AS3toTimeString(ASString& result);
        // @0x142403110
        void AS3toUTCString(ASString& result);
        // @0x1424037b0
        void AS3valueOf(Value::Number& result);
        // @0x142427c30
        void dateGet(Value::Number& result);
        // @0x142427c40
        void dateSet(const Value& result, Value::Number);
        // @0x142427c60
        void dateUTCGet(Value::Number& result);
        // @0x142427cc0
        void dateUTCSet(const Value& result, Value::Number);
        // @0x142427cd0
        void dayGet(Value::Number& result);
        // @0x142427ce0
        void dayUTCGet(Value::Number& result);
        // @0x1424289a0
        void fullYearGet(Value::Number& result);
        // @0x142428a10
        void fullYearSet(const Value& result, Value::Number);
        // @0x142428a20
        void fullYearUTCGet(Value::Number& result);
        // @0x142428a70
        void fullYearUTCSet(const Value& result, Value::Number);
        // @0x142428dc0
        void hoursGet(Value::Number& result);
        // @0x142428dd0
        void hoursSet(const Value& result, Value::Number);
        // @0x142428de0
        void hoursUTCGet(Value::Number& result);
        // @0x142428df0
        void hoursUTCSet(const Value& result, Value::Number);
        // @0x142429630
        void millisecondsGet(Value::Number& result);
        // @0x142429640
        void millisecondsSet(const Value& result, Value::Number);
        // @0x142429660
        void millisecondsUTCGet(Value::Number& result);
        // @0x1424296d0
        void millisecondsUTCSet(const Value& result, Value::Number);
        // @0x142429820
        void minutesGet(Value::Number& result);
        // @0x142429830
        void minutesSet(const Value& result, Value::Number);
        // @0x142429850
        void minutesUTCGet(Value::Number& result);
        // @0x142429860
        void minutesUTCSet(const Value& result, Value::Number);
        // @0x142429870
        void monthGet(Value::Number& result);
        // @0x142429880
        void monthSet(const Value& result, Value::Number);
        // @0x1424298a0
        void monthUTCGet(Value::Number& result);
        // @0x142429900
        void monthUTCSet(const Value& result, Value::Number);
        // @0x14242a070
        void secondsGet(Value::Number& result);
        // @0x14242a080
        void secondsSet(const Value& result, Value::Number);
        // @0x14242a0a0
        void secondsUTCGet(Value::Number& result);
        // @0x14242a0b0
        void secondsUTCSet(const Value& result, Value::Number);
        // @0x14242b120
        void timeGet(Value::Number& result);
        // @0x14242b130
        void timeSet(const Value& result, Value::Number);
        // @0x14242b180
        void timezoneOffsetGet(Value::Number& result);
    };

    // 0x58 bytes.
    class Error : public Instance
    {
    public:
        explicit Error(InstanceTraits::Traits& t);
        Error(InstanceTraits::Traits& t, int id, const ASString& msg);
        // @0x142414e20
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::Error"; }
        // @0x1423f5770
        virtual void AS3Constructor(unsigned argc, const Value* argv);

    public:
        ASString    message;        // +0x38
        ASString    name;           // +0x40
        SInt32      ID;             // +0x48
        ASString    StackTrace;     // +0x50

    public:
        // native methods
        // @0x1424282e0
        void errorIDGet(SInt32& result);
        // @0x142428c80
        void getStackTrace(ASString& result);
        // @0x14242b1e0
        void toStringProto(ASString& result);
    };

    // 0x48 bytes.
    class QName : public Instance
    {
    public:
        explicit QName(InstanceTraits::Traits& t);
        QName(InstanceTraits::Traits& t, const ASString& local, Instances::Namespace* ns);
        // @0x142414fa0
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::QName"; }
        // @0x14240c010
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x1423f5ae0
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // @0x142416330
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
        // @0x142416180
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
        // @0x142416630
        virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);

    public:
        ASString                    LocalName;  // +0x38
        SPtr<Instances::Namespace>  Ns;         // +0x40

    public:
        // native methods
        // @0x142402910
        void AS3toString(ASString& result);
        // @0x142403820
        void AS3valueOf(SPtr<Instances::fl::QName>& result);
        // @0x142429490
        void localNameGet(ASString& result);
        // @0x14242b710
        void uriGet(Value& result);
    };

    // 0x60 bytes.
    class RegExp : public Instance
    {
    public:
        explicit RegExp(InstanceTraits::Traits& t);
        // @0x142415010
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::RegExp"; }
        // @0x1423f5d90
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // (appended, sfr19) frees the compiled pattern.
        virtual ~RegExp()
        {
            pcre_free(CompRegExp);
            CompRegExp = NULL;
        }

    public:
        void*       CompRegExp;     // +0x38 compiled pattern (pcre)
        SInt32      MatchOffset;    // +0x40
        SInt32      MatchLength;    // +0x44
        String      Pattern;        // +0x48
        bool        IsGlobal;       // +0x50
        SInt32      LastIndex;      // +0x54
        int         OptionFlags;    // +0x58
        bool        HasNamedGroups; // +0x5c

    public:
        // native methods
        // @0x1423f9300
        void AS3exec(SPtr<Instances::fl::Object>& result, const ASString&);
        // @0x142401860
        void AS3test(bool& result, const ASString&);
        // "/pattern/flags" (exe 0x142425890, sfr_as3_04)
        ASString ToString();
        // @0x142428130
        void dotallGet(bool& result);
        // @0x142428490
        void extendedGet(bool& result);
        // @0x142428da0
        void globalGet(bool& result);
        // @0x142428e00
        void ignoreCaseGet(bool& result);
        // @0x1424291b0
        void lastIndexGet(SInt32& result);
        // @0x1424291c0
        void lastIndexSet(const Value& result, SInt32);
        // @0x142429910
        void multilineGet(bool& result);
        // @0x14242b010
        void sourceGet(ASString& result);
        // (appended, sfr19) the flag letters ("g", "i", "m", "s", "x") as a string. 0x142429920
        ASString GetFlags();
    };

    // 0x68 bytes.
    class XMLList : public Instance
    {
    public:
        explicit XMLList(InstanceTraits::Traits& t);
        // ??_G 0x1423f5070
        virtual ~XMLList();
        // @0x142415160
        virtual const char* GetAS3ObjectType() const { return "Instances::fl::XMLList"; }
        // @0x14240c440
        virtual void ForEachChild_GC(Collector* prcc, GcOp op) const;
        // @0x142422a20
        virtual CheckResult SetProperty(const Multiname& prop_name, const Value& value);
        // @0x142416b90
        virtual CheckResult GetProperty(const Multiname& prop_name, Value& value);
        // @0x142415a40
        virtual void GetDynamicProperty(AbsoluteIndex ind, Value& value);
        // @0x142409340
        virtual CheckResult DeleteProperty(const Multiname& prop_name);
        // @0x1423f63b0
        virtual void AS3Constructor(unsigned argc, const Value* argv);
        // @0x142416430
        virtual void GetNextPropertyName(Value& name, GlobalSlotIndex ind) const;
        // @0x1424161c0
        virtual GlobalSlotIndex GetNextDynPropIndex(GlobalSlotIndex ind) const;
        // @0x1424166c0
        virtual void GetNextPropertyValue(Value& value, GlobalSlotIndex ind);

        // (appended, sfr19) E4X list == v: item by item against another list, else the single item against v. 0x142409890
        CheckResult Equals(bool& result, const Value& v);

    public:
        SPtr<AS3::Object>                       TargetObject;       // +0x38
        ASStringNode*                           TargetProperty;     // +0x40
        SPtr<Instances::Namespace>              TargetNamespace;    // +0x48
        ArrayLH<SPtr<Instances::fl::XML> >      List;               // +0x50 the XML items

    public:
        // (appended, sfr19) a list of deep copies of the items, parented to parent. 0x142408c70
        Pickable<XMLList> DeepCopy(Instances::fl::XML* parent);
        // (appended, sfr19) the single item r stands for: List[0], or for an empty list a new element named by the
        // target, appended to the (resolved) target object; NULL when there is no target. More than one item throws.
        // 0x142420570
        CheckResult ResolveValue(Instances::fl::XML*& r);
        // (appended, sfr19) appends every item of l. 0x142404e90
        void Append(const XMLList& l);
        // (appended, sfr19) appends x. 0x142404f20
        void Append(Instances::fl::XML* x);

    public:
        // native methods
        // @0x1423f6ca0
        void AS3addNamespace(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423f6d50
        void AS3appendChild(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423f6f70
        void AS3attribute(SPtr<Instances::fl::XMLList>& result, const Value&);
        // @0x1423f71f0
        void AS3attributes(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f7710
        void AS3child(SPtr<Instances::fl::XMLList>& result, const Value&);
        // @0x1423f7960
        void AS3childIndex(SInt32& result);
        // @0x1423f7ae0
        void AS3children(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f7db0
        void AS3comments(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f81d0
        void AS3contains(bool& result, const Value&);
        // @0x1423f82d0
        void AS3copy(SPtr<Instances::fl::XMLList>& result);
        // @0x1423f8840
        void AS3descendants(Value& result, unsigned, const Value*);
        // @0x1423f8ce0
        void AS3elements(Value& result, unsigned, const Value*);
        // @0x1423fa9c0
        void AS3hasComplexContent(bool& result);
        // @0x1423fac80
        void AS3hasSimpleContent(bool& result);
        // @0x1423fb130
        void AS3inScopeNamespaces(SPtr<Instances::fl::Array>& result);
        // @0x1423fb2f0
        void AS3insertChildAfter(Value& result, const Value&, const Value&);
        // @0x1423fb3e0
        void AS3insertChildBefore(Value& result, const Value&, const Value&);
        // @0x1423fb880
        void AS3length(SInt32& result);
        // @0x1423fb8d0
        void AS3localName(ASString& result);
        // @0x1423fc420
        void AS3name(SPtr<Instances::fl::QName>& result);
        // @0x1423fc8f0
        void AS3namespaceDeclarations(SPtr<Instances::fl::Array>& result);
        // @0x1423fca10
        void AS3namespace_(Value& result, unsigned, const Value*);
        // @0x1423fcb00
        void AS3nodeKind(ASString& result);
        // @0x1423fcbe0
        void AS3normalize(SPtr<Instances::fl::XMLList>& result);
        // @0x1423fccd0
        void AS3parent(Value& result);
        // @0x1423fce50
        void AS3prependChild(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fcfc0
        void AS3processingInstructions(Value& result, unsigned, const Value*);
        // @0x1423fd650
        void AS3propertyIsEnumerable(Value& result, unsigned, const Value*);
        // @0x1423fd880
        void AS3removeNamespace(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fdec0
        void AS3replace(SPtr<Instances::fl::XML>& result, const Value&, const Value&);
        // @0x1423fe2e0
        void AS3setChildren(SPtr<Instances::fl::XML>& result, const Value&);
        // @0x1423fe520
        void AS3setLocalName(const Value& result, const Value&);
        // @0x1423fe8c0
        void AS3setName(const Value& result, const Value&);
        // @0x1423fea20
        void AS3setNamespace(const Value& result, const Value&);
        // @0x1424019b0
        void AS3text(SPtr<Instances::fl::XMLList>& result);
        // @0x142402c20
        void AS3toString(ASString& result);
        // @0x142403310
        void AS3toXMLString(ASString& result);
        // @0x1424039c0
        void AS3valueOf(SPtr<Instances::fl::XMLList>& result);
        // @0x142429ea0
        void prototypeGet(SPtr<Instances::fl::XMLList>& result);
        // @0x142429fa0
        void prototypeSet(const Value& result, const Value&);

    public:
        // (appended, sfr19) adds x (AddRef) to List. 0x142404f20 (the SDK spells it Apppend)
        void Apppend(Instances::fl::XML* x);
        // (appended, sfr19) 0x142423b50
        void SetTargetProperty(ASStringNode* prop);

        // (appended, sfr19) a visitor of the element children ForEachChild selects (no RTTI; ListGet is the one
        // derived class).
        class CallBack
        {
        public:
            CallBack(XMLList& list) : List(list) {}
            virtual ~CallBack() {}
            // the ind2-th child of the ind1-th item of List
            virtual void Call(UPInt ind1, UPInt ind2) = 0;

        protected:
            XMLList&    List;       // +0x08

        private:
            CallBack& operator=(const CallBack&);
        };

        // (appended, sfr19) cb for each child of an element item that prop_name matches; the number visited.
        // 0x14240b9a0
        UInt32 ForEachChild(const Multiname& prop_name, CallBack& cb);
        // (appended, sfr19) the matching children of the items (their attributes for an attribute name) appended
        // to list. 0x142416ad0
        CheckResult GetProperty(const Multiname& prop_name, XMLList& list);
        // (appended, sfr19) a new empty list with this list's target. 0x14241b350
        Pickable<XMLList> MakeXMLListInstance();
        // (appended, sfr19) a new list targeting prop_name of this list. 0x14241b190
        Pickable<XMLList> MakeXMLListInstance(const Multiname& mn);
        // (appended, sfr19) a new list (same target) holding the same items. 0x142423e50
        Pickable<XMLList> ShallowCopy();
        // (appended, sfr19) an in-scope namespace of an item with this URI. 0x14240b490
        Instances::Namespace* FindNamespaceByURI(const ASString& uri) const;
    };
}}

// Makes the Namespace instances of one VM and keeps the set of the namespaces it made (one per kind/uri/prefix).
// 0x20 bytes. vftable 0x143140af8.
class NamespaceInstanceFactory : public RefCountBase<NamespaceInstanceFactory, StatMV_VM_ITraits_Mem>
{
public:
    explicit NamespaceInstanceFactory(InstanceTraits::fl::Namespace* itr)
        : pNamespaceInstanceTraits(itr)
    {
    }
    // (appended, sfr19) user-declared: the exe's dtor re-stores the vftable before clearing the set.
    virtual ~NamespaceInstanceFactory() {}

    // The interned namespace of {kind, uri}: the one already made, or a new one with this prefix.
    // @0x14241baa0
    Pickable<Instances::Namespace> MakeNamespace(Abc::NamespaceKind kind, const ASString& uri, const Value& prefix);

public:
    // A namespace is hashed by its kind and uri; Key looks one up without making it.
    struct Key
    {
        Key(Abc::NamespaceKind kind, const ASString& uri) : Kind(kind), Uri(uri) {}

        friend bool operator==(const Instances::Namespace* ns, const Key& key)
        { return ns->GetKind() == key.Kind && ns->GetUri().GetNode() == key.Uri.GetNode(); }

        Abc::NamespaceKind  Kind;
        ASString            Uri;
    };

    struct NamespaceHashFunc
    {
        UPInt operator()(const Instances::Namespace* ns) const
        { return (ns->GetUri().GetHash() << 2) ^ (unsigned)ns->GetKind(); }
        UPInt operator()(const Key& key) const
        { return (key.Uri.GetHash() << 2) ^ (unsigned)key.Kind; }
    };

    typedef HashSetLH<Instances::Namespace*, NamespaceHashFunc, NamespaceHashFunc, Stat_Default_Mem,
                      HashsetEntry<Instances::Namespace*, NamespaceHashFunc> >
        NamespaceSetType;

    NamespaceSetType                NamespaceSet;               // +0x10
    InstanceTraits::fl::Namespace*  pNamespaceInstanceTraits;   // +0x18
};

// (appended, sfr22)
inline Instances::Namespace& Instances::Namespace::operator=(const Namespace& other)
{
    if (this != &other)
    {
        Prefix.Assign(other.Prefix);
        Uri = other.Uri;
        Kind = other.Kind;
        pFactory = other.pFactory;
    }
    return *this;
}

namespace InstanceTraits { namespace fl
{
    class Array : public CTraits
    {
    public:
        Array(VM& vm, const ClassInfo& ci);
        // @0x142414cf0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Array"; }
        // @0x14241bd80
        virtual void MakeObject(Value& result, Traits& t);

        // (appended, sfr19) a new instance of t.
        // @0x14241a500
        Pickable<Instances::fl::Array> MakeInstance(Array& t);
    };

    class Boolean : public CTraits
    {
    public:
        Boolean(VM& vm, const ClassInfo& ci);
        // @0x142414d30
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Boolean"; }
        // @0x14241be20
        virtual void MakeObject(Value& result, Traits& t);

    public:
        // @0x142403750
        static void AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e6fe0 (appended, sfr15)
        static void AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e7050 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e7120 (appended, sfr15)
        static void valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

    class Catch : public CTraits
    {
    public:
        Catch(VM& vm, const ClassInfo& ci);
        // @0x142414d70
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::Catch"; }
        // @0x14241be30
        virtual void MakeObject(Value& result, Traits& t);

        // (appended, sfr19) a new instance of t.
        // @0x14241a5b0
        Pickable<Instances::fl::Catch> MakeInstance(Catch& t);
    };

    class Date : public CTraits
    {
    public:
        Date(VM& vm, const ClassInfo& ci);
        // @0x142414dc0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Date"; }
        // @0x14241beb0
        virtual void MakeObject(Value& result, Traits& t);

        // (appended, sfr19) a new instance of t.
        // @0x14241a620
        Pickable<Instances::fl::Date> MakeInstance(Date& t);
    };

    class Error : public CTraits
    {
    public:
        Error(VM& vm, const ClassInfo& ci);
        // @0x142414e10
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Error"; }
        // @0x14241bf20
        virtual void MakeObject(Value& result, Traits& t);

        // (appended, sfr19) a new instance of t.
        // @0x14241a6a0
        Pickable<Instances::fl::Error> MakeInstance(Error& t);
    };

    class Namespace : public CTraits
    {
    public:
        Namespace(VM& vm, const ClassInfo& ci);
        // @0x142414ef0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::Namespace"; }
        // @0x14241c040
        virtual void MakeObject(Value& result, Traits& t);

        // @0x14241ab60
        Pickable<Instances::Namespace> MakeInstance(Abc::NamespaceKind kind, const ASString& uri, const Value& prefix);
        // @0x14241ba70
        Pickable<Instances::Namespace> MakeInternedInstance(Abc::NamespaceKind kind, const ASString& uri,
                                                            const Value& prefix);

        static void prefixGet(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);     // 0x1423e6090
        static void uriGet(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);        // 0x1423e6100
        static void AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);    // 0x1423e6170
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv); // 0x1423e61e0
        static void valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);  // 0x1423e62b0
        // (appended, sfr19)
        static void AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);   // 0x1424026a0

        // (appended, sfr19) the factory may outlive these traits: it forgets them.
        virtual ~Namespace() { InstanceFactory->pNamespaceInstanceTraits = NULL; }

    public:
        Ptr<NamespaceInstanceFactory> InstanceFactory;    // +0xe8
    };

    class Number : public CTraits
    {
    public:
        Number(VM& vm, const ClassInfo& ci);
        // @0x142414f20
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::Number"; }
        // @0x14241c050
        virtual void MakeObject(Value& result, Traits& t);

    public:
        // @0x1423e2850 (appended, sfr15)
        static void AS3toExponential(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142401ba0
        static void AS3toFixed(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402180
        static void AS3toPrecision(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1424037c0
        static void AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402710 (appended, sfr15)
        static void AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e29b0 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e2a50 (appended, sfr15)
        static void toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e2af0 (appended, sfr15)
        static void valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e2ff0 (appended, sfr15)
        static void toFixedProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e3180 (appended, sfr15)
        static void toPrecisionProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e2d40 (appended, sfr15)
        static void toExponentialProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

    class QName : public CTraits
    {
    public:
        QName(VM& vm, const ClassInfo& ci);
        // @0x142414f90
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::QName"; }
        // @0x14241c0c0
        virtual void MakeObject(Value& result, Traits& t);

    public:
        // @0x1423e1be0 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

    class RegExp : public CTraits
    {
    public:
        RegExp(VM& vm, const ClassInfo& ci);
        // @0x142415000
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::RegExp"; }
        // @0x14241c160
        virtual void MakeObject(Value& result, Traits& t);

        // (appended, sfr19) a new instance of t.
        // @0x14241ad90
        Pickable<Instances::fl::RegExp> MakeInstance(RegExp& t);
    };

    class String : public CTraits
    {
    public:
        String(VM& vm, const ClassInfo& ci);
        // @0x142415050
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::String"; }
        // @0x14241c1f0
        virtual void MakeObject(Value& result, Traits& t);

    public:
        // @0x1423ff660
        static void AS3slice(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142400e50 (appended, sfr22)
        static void AS3split(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1424013f0
        static void AS3substr(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1424015b0
        static void AS3substring(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142407090 (appended, sfr15) code point order used by localeCompare.
        static SInt32 Compare(ASString& l, ASString& r);
        // @0x1423e7410 (appended, sfr15)
        static void lengthGet(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e7490 (appended, sfr15)
        static void AS3indexOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402a90 (appended, sfr15)
        static void AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142403880 (appended, sfr15)
        static void AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e77a0 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e7990 (appended, sfr15)
        static void valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423f7310 (appended, sfr19)
        static void AS3charAt(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423f7440 (appended, sfr19)
        static void AS3charCodeAt(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423f8070 (appended, sfr19)
        static void AS3concat(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423fb5b0 (appended, sfr19)
        static void AS3lastIndexOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423fb960 (appended, sfr19)
        static void AS3localeCompare(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423fbf90 (appended, sfr19)
        static void AS3match(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423fd8f0 (appended, sfr19)
        static void AS3replace(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423fdfa0 (appended, sfr19)
        static void AS3search(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142401fd0 (appended, sfr19)
        static void AS3toLocaleLowerCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402080 (appended, sfr19)
        static void AS3toLocaleUpperCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402100 (appended, sfr19)
        static void AS3toLowerCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1424031d0 (appended, sfr19)
        static void AS3toUpperCase(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

    class XML : public CTraits
    {
    public:
        XML(VM& vm, const ClassInfo& ci);
        // @0x142415110
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::XML"; }
        // @0x14241c230
        virtual void MakeObject(Value& result, Traits& t);

    public:
        // @0x1423e7a30 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e7b30 (appended, sfr15)
        static void PropertyIsEnumerableProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e7c30 (appended, sfr15)
        static void HasOwnPropertyProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);

    public:
        // (appended, sfr19) a new element named name in (a public copy of) ns. 0x14241b5b0
        Pickable<Instances::fl::XMLElement> MakeInstanceElement(XML& t, const Instances::Namespace& ns,
                                                                const ASString& name, Instances::fl::XML* parent);
        // (appended, sfr19) a new attribute name=value in (a public copy of) ns. 0x14241b3e0
        Pickable<Instances::fl::XMLAttr> MakeInstanceAttr(XML& t, const Instances::Namespace& ns, const ASString& name,
                                                          const ASString& value, Instances::fl::XML* parent);
        // (appended, sfr19) a new text node; the string is made with t's VM. 0x14241b850
        Pickable<Instances::fl::XMLText> MakeInstanceText(XML& t, const StringDataPtr& str, Instances::fl::XML* parent);
        // 0x14241b7a0
        Pickable<Instances::fl::XMLText> MakeInstanceText(XML& t, const ASString& str, Instances::fl::XML* parent);
    };

    class XMLList : public CTraits
    {
    public:
        XMLList(VM& vm, const ClassInfo& ci);
        // @0x142415150
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::fl::XMLList"; }
        // @0x14241c2b0
        virtual void MakeObject(Value& result, Traits& t);

        // (appended, sfr19) a new empty list. 0x14241af80
        Pickable<Instances::fl::XMLList> MakeInstance(XMLList& t);
        // (appended, sfr19) a new empty list whose target is target_prop of target_obj. 0x14241b010
        Pickable<Instances::fl::XMLList> MakeInstance(XMLList& t, AS3::Object& target_obj, const ASString& target_prop,
                                                      Instances::Namespace& target_ns);

    public:
        // @0x1423e1840 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

    class int_ : public CTraits
    {
    public:
        int_(VM& vm, const ClassInfo& ci);
        // @0x142415190
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::int_"; }
        // @0x14241c330
        virtual void MakeObject(Value& result, Traits& t);

    public:
        // @0x1423e55f0 (appended, sfr15)
        static void AS3toExponential(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142401d00
        static void AS3toFixed(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1424022e0
        static void AS3toPrecision(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142403a20
        static void AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402d50 (appended, sfr15)
        static void AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e5750 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e57f0 (appended, sfr15)
        static void toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e5890 (appended, sfr15)
        static void valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e5c10 (appended, sfr15)
        static void toFixedProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e5da0 (appended, sfr15)
        static void toPrecisionProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e5960 (appended, sfr15)
        static void toExponentialProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

    class uint : public CTraits
    {
    public:
        uint(VM& vm, const ClassInfo& ci);
        // @0x1424151c0
        virtual const char* GetAS3ObjectType() const { return "InstanceTraits::uint"; }
        // @0x14241c340
        virtual void MakeObject(Value& result, Traits& t);

    public:
        // @0x1423e6540 (appended, sfr15)
        static void AS3toExponential(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142401e60
        static void AS3toFixed(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402440
        static void AS3toPrecision(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142403ac0
        static void AS3valueOf(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x142402ed0 (appended, sfr15)
        static void AS3toString(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e66a0 (appended, sfr15)
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e6740 (appended, sfr15)
        static void toLocaleStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e67e0 (appended, sfr15)
        static void valueOfProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e6b60 (appended, sfr15)
        static void toFixedProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e6cf0 (appended, sfr15)
        static void toPrecisionProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
        // @0x1423e68b0 (appended, sfr15)
        static void toExponentialProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

}}

namespace Classes { namespace fl
{
    class Object : public Class
    {
    public:
        Object(ClassTraits::Traits& t);
        // @0x142414f40
        virtual const char* GetAS3ObjectType() const { return "Classes::Object"; }
        // @0x142405a40
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407560
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417f60
        virtual void InitPrototype(AS3::Object& obj) const;

        // (appended, sfr19) "[class <name>]".
        // 0x14242b300
        void toStringProto(ASString& result);
    };

    class Array : public Class
    {
    public:
        Array(ClassTraits::Traits& t);
        // @0x142414ce0
        virtual const char* GetAS3ObjectType() const { return "Classes::Array"; }
        // @0x1424054e0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142417800
        virtual void InitPrototype(AS3::Object& obj) const;
        // @0x14241c350
        virtual Pickable<AS3::Object> MakePrototype() const;

    public:
        UInt32  CASEINSENSITIVE;       // +0x50
        UInt32  DESCENDING;            // +0x54
        UInt32  UNIQUESORT;            // +0x58
        UInt32  RETURNINDEXEDARRAY;    // +0x5c
        UInt32  NUMERIC;               // +0x60
    };

    class Boolean : public Class
    {
    public:
        Boolean(ClassTraits::Traits& t);
        // @0x142414d20
        virtual const char* GetAS3ObjectType() const { return "Classes::Boolean"; }
        // @0x1424055c0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407120
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417a30
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class Catch : public Class
    {
    public:
        Catch(ClassTraits::Traits& t);
        // @0x142414d60
        virtual const char* GetAS3ObjectType() const { return "Classes::fl::Catch"; }
    };

    class Date : public Class
    {
    public:
        Date(ClassTraits::Traits& t);
        // @0x142414db0
        virtual const char* GetAS3ObjectType() const { return "Classes::Date"; }
        // @0x142405670
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x14241c400
        virtual Pickable<AS3::Object> MakePrototype() const;

        // native methods
        // @0x142427200
        void UTC(Value& result, unsigned, const Value*);
        // @0x142429a70
        void parse(Value::Number& result, const Value&);
    };

    class Error : public Class
    {
    public:
        Error(ClassTraits::Traits& t);
        // @0x142414e00
        virtual const char* GetAS3ObjectType() const { return "Classes::Error"; }
        // @0x142405780
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142417b40
        virtual void InitPrototype(AS3::Object& obj) const;
        // @0x14241c4d0
        virtual Pickable<AS3::Object> MakePrototype() const;

        // native methods
        // @0x142428b20
        void getErrorMessage(ASString& result, SInt32);
        // @0x14242b0d0
        void throwError(Value& result, unsigned, const Value*);
    };

    class Math : public Class
    {
    public:
        Math(ClassTraits::Traits& t);
        // @0x142414eb0
        virtual const char* GetAS3ObjectType() const { return "Classes::Math"; }
        // @0x1424059b0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x1424072f0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);

        // native methods
        // @0x1424274f0
        void abs(Value::Number& result, Value::Number);
        // @0x142427540
        void acos(Value::Number& result, Value::Number);
        // @0x142427a60
        void asin(Value::Number& result, Value::Number);
        // @0x142427b90
        void atan(Value::Number& result, Value::Number);
        // @0x142427a80
        void atan2(Value::Number& result, Value::Number, Value::Number);
        // @0x142427bb0
        void ceil(Value::Number& result, Value::Number);
        // @0x142427c10
        void cos(Value::Number& result, Value::Number);
        // @0x142428470
        void exp(Value::Number& result, Value::Number);
        // @0x1424284a0
        void floor(Value::Number& result, Value::Number);
        // @0x1424294d0
        void log(Value::Number& result, Value::Number);
        // @0x1424294f0
        void (max)(Value& result, unsigned, const Value*);
        // @0x1424296e0
        void (min)(Value& result, unsigned, const Value*);
        // @0x142429d40
        void pow(Value::Number& result, Value::Number, Value::Number);
        // @0x142429fb0
        void random(Value::Number& result);
        // @0x142429fe0
        void round(Value::Number& result, Value::Number);
        // @0x14242afc0
        void sin(Value::Number& result, Value::Number);
        // @0x14242b090
        void sqrt(Value::Number& result, Value::Number);
        // @0x14242b0b0
        void tan(Value::Number& result, Value::Number);

    public:
        Value::Number LN10;      // +0x50
        Value::Number E;
        Value::Number LN2;
        Value::Number LOG10E;
        Value::Number LOG2E;
        Value::Number PI;
        Value::Number SQRT1_2;
        Value::Number SQRT2;   // +0x88
    };

    class Namespace : public Class
    {
    public:
        Namespace(ClassTraits::Traits& t);
        // @0x142414ee0
        virtual const char* GetAS3ObjectType() const { return "Classes::Namespace"; }
        // @0x142405a00
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407340
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417d40
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class Number : public Class
    {
    public:
        Number(ClassTraits::Traits& t);
        // @0x142414f10
        virtual const char* GetAS3ObjectType() const { return "Classes::Number"; }
        // @0x142405a20
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407480
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142417e50
        virtual void InitPrototype(AS3::Object& obj) const;

    public:
        Value::Number NaN;                  // +0x50
        Value::Number NEGATIVE_INFINITY;
        Value::Number POSITIVE_INFINITY;
        Value::Number MIN_VALUE;
        Value::Number MAX_VALUE;            // +0x70
    };

    class QName : public Class
    {
    public:
        QName(ClassTraits::Traits& t);
        // @0x142414f80
        virtual const char* GetAS3ObjectType() const { return "Classes::QName"; }
        // @0x142405a60
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x1424076a0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142418070
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class RegExp : public Class
    {
    public:
        RegExp(ClassTraits::Traits& t);
        // @0x142414ff0
        virtual const char* GetAS3ObjectType() const { return "Classes::RegExp"; }
        // @0x142405a80
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142418160
        virtual void InitPrototype(AS3::Object& obj) const;
        // @0x14241c560
        virtual Pickable<AS3::Object> MakePrototype() const;

        // (appended, sfr19) the prototype's toString thunk.
        // 0x14242b3d0
        static void toStringProto(const ThunkInfo& ti, VM& vm, const Value& _this, Value& result, unsigned argc, const Value* argv);
    };

    class String : public Class
    {
    public:
        String(ClassTraits::Traits& t);
        // @0x142415040
        virtual const char* GetAS3ObjectType() const { return "Classes::String"; }
        // @0x142405ae0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407730
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142418250
        virtual void InitPrototype(AS3::Object& obj) const;

        // native methods
        // @0x1423fa0b0
        void AS3fromCharCode(Value& result, unsigned, const Value*);
        // @0x142428880
        void fromCharCode(Value& result, unsigned, const Value*);
    };

    class XML : public Class
    {
    public:
        XML(ClassTraits::Traits& t);
        // @0x142415100
        virtual const char* GetAS3ObjectType() const { return "Classes::fl::XML"; }
        // @0x142405b00
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x1424077a0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x142418390
        virtual void InitPrototype(AS3::Object& obj) const;

        // native methods
        // @0x1423f8330
        void AS3defaultSettings(SPtr<Instances::fl::Object>& result);
        // @0x1423feac0
        void AS3setSettings(const Value& result, const Value&);
        // @0x1423ff120
        void AS3settings(SPtr<Instances::fl::Object>& result);
        // @0x142428100
        void defaultSettings(SPtr<Instances::fl::Object>& result);
        // @0x14242ae20
        void setSettings(const Value& result, const Value&);
        // @0x14242afb0
        void settings(SPtr<Instances::fl::Object>& result);

    public:
        bool    ignoreComments;                 // +0x50
        bool    ignoreProcessingInstructions;
        bool    ignoreWhitespace;
        bool    prettyPrinting;
        SInt32  prettyIndent;                   // +0x54
    };

    class XMLList : public Class
    {
    public:
        XMLList(ClassTraits::Traits& t);
        // @0x142415140
        virtual const char* GetAS3ObjectType() const { return "Classes::XMLList"; }
        // @0x142405b90
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407bf0
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x1424184b0
        virtual void InitPrototype(AS3::Object& obj) const;
    };

    class int_ : public Class
    {
    public:
        int_(ClassTraits::Traits& t);
        // @0x142415180
        virtual const char* GetAS3ObjectType() const { return "Classes::int_"; }
        // @0x142405bb0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407c80
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x1424185d0
        virtual void InitPrototype(AS3::Object& obj) const;

    public:
        SInt32  MIN_VALUE;  // +0x50
        SInt32  MAX_VALUE;  // +0x54
    };

    class uint : public Class
    {
    public:
        uint(ClassTraits::Traits& t);
        // @0x1424151b0
        virtual const char* GetAS3ObjectType() const { return "Classes::uint"; }
        // @0x142405bd0
        virtual void Call(const Value& _this, Value& result, unsigned argc, const Value* const argv);
        // @0x142407d30
        virtual void Construct(Value& _this, unsigned argc, const Value* argv, bool extCall = false);
        // @0x1424186e0
        virtual void InitPrototype(AS3::Object& obj) const;

    public:
        UInt32  MIN_VALUE;  // +0x50
        UInt32  MAX_VALUE;  // +0x54
    };

}}

namespace ClassTraits { namespace fl
{
    class ArgumentError : public Traits
    {
    public:
        ArgumentError(VM& vm);
        // @0x142414cc0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ArgumentError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Array : public Traits
    {
    public:
        Array(VM& vm);
        // @0x142414cd0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::Array"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Boolean : public Traits
    {
    public:
        Boolean(VM& vm);
        // @0x142414d10
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Boolean"; }
        // @0x1424060c0
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Catch : public Traits
    {
    public:
        Catch(VM& vm);
        // @0x142414d50
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Catch"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Date : public Traits
    {
    public:
        Date(VM& vm);
        // @0x142414da0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Date"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class DefinitionError : public Traits
    {
    public:
        DefinitionError(VM& vm);
        // @0x142414de0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::DefinitionError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Error : public Traits
    {
    public:
        Error(VM& vm);
        // @0x142414df0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Error"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class EvalError : public Traits
    {
    public:
        EvalError(VM& vm);
        // @0x142414e30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::EvalError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class int_ : public Traits
    {
    public:
        int_(VM& vm);
        // @0x142415170
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::int_"; }
        // @0x1424062d0
        virtual bool Coerce(const Value& value, Value& result) const;
        // @0x1424063e0
        bool CoerceValue(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Math : public Traits
    {
    public:
        Math(VM& vm);
        // @0x142414ea0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Math"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Namespace : public Traits
    {
    public:
        Namespace(VM& vm);
        // @0x142414ed0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Namespace"; }
        // @0x1424061b0
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Number : public Traits
    {
    public:
        Number(VM& vm);
        // @0x142414f00
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Number"; }
        // @0x142406210
        virtual bool Coerce(const Value& value, Value& result) const;
        // @0x142406360
        bool CoerceValue(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class Object : public Traits
    {
    public:
        Object(VM& vm);
        // @0x142414f30
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::Object"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class QName : public Traits
    {
    public:
        QName(VM& vm);
        // @0x142414f70
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::QName"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class RangeError : public Traits
    {
    public:
        RangeError(VM& vm);
        // @0x142414fc0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::RangeError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class ReferenceError : public Traits
    {
    public:
        ReferenceError(VM& vm);
        // @0x142414fd0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::ReferenceError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class RegExp : public Traits
    {
    public:
        RegExp(VM& vm);
        // @0x142414fe0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::RegExp"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SecurityError : public Traits
    {
    public:
        SecurityError(VM& vm);
        // @0x142415020
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SecurityError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class String : public Traits
    {
    public:
        String(VM& vm);
        // @0x142415030
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::String"; }
        // @0x142406220
        virtual bool Coerce(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class SyntaxError : public Traits
    {
    public:
        SyntaxError(VM& vm);
        // @0x142415060
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::SyntaxError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class TypeError : public Traits
    {
    public:
        TypeError(VM& vm);
        // @0x142415080
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::TypeError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class uint : public Traits
    {
    public:
        uint(VM& vm);
        // @0x1424151a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::uint"; }
        // @0x1424062e0
        virtual bool Coerce(const Value& value, Value& result) const;
        // @0x142406460
        bool CoerceValue(const Value& value, Value& result) const;
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class UninitializedError : public Traits
    {
    public:
        UninitializedError(VM& vm);
        // @0x1424150a0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::UninitializedError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class URIError : public Traits
    {
    public:
        URIError(VM& vm);
        // @0x142415090
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::URIError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class VerifyError : public Traits
    {
    public:
        VerifyError(VM& vm);
        // @0x1424150e0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::VerifyError"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class XML : public Traits
    {
    public:
        XML(VM& vm);
        // @0x1424150f0
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::XML"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

    class XMLList : public Traits
    {
    public:
        XMLList(VM& vm);
        // @0x142415130
        virtual const char* GetAS3ObjectType() const { return "ClassTraits::fl::XMLList"; }
        static Pickable<Traits> MakeClassTraits(VM& vm);
    };

}}


}}} // namespace Scaleform::GFx::AS3

#endif
