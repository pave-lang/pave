#ifndef PAVE_SEQUENCE_TYPE
#define PAVE_SEQUENCE_TYPE

#include <stdio.h>

#include <stdint.h>

#line 45 "src/analyzer/types/Type.pv"
struct SequenceType {
    enum {
        SEQUENCE_TYPE__FIXED_ARRAY,
        SEQUENCE_TYPE__SLICE,
    } type;

    uintptr_t fixedarray_value;
};

#endif
