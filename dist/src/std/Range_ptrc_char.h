#ifndef PAVE_RANGE_PTRC_CHAR
#define PAVE_RANGE_PTRC_CHAR

struct Iter_ptrc_char;

#line 1 "src/std/Range.pv"
#ifndef PAVE_RANGE__TYPE
#define PAVE_RANGE__TYPE
enum Range__Type {
    RANGE__ALL,
    RANGE__START,
    RANGE__END,
    RANGE__START_END,
};
#endif

struct Range_ptrc_char {
    enum Range__Type type;
    union {
        char const* start_value;
        char const* end_value;
        struct { char const* _0; char const* _1; } startend_value;
    };
};

#line 25 "src/std/Range.pv"
struct Iter_ptrc_char Range_ptrc_char__iter(struct Range_ptrc_char self);

#endif
