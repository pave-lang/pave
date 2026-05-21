#ifndef PAVE_SEQUENCE_TYPE
#define PAVE_SEQUENCE_TYPE

struct Expression;
#line 46 "src/analyzer/types/Type.pv"
struct SequenceType {
    enum {
        SEQUENCE_TYPE__FIXED_ARRAY,
        SEQUENCE_TYPE__SLICE,
    } type;

    struct Expression* fixedarray_value;
};


#endif
