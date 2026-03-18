#ifndef PAVE_SEQUENCE
#define PAVE_SEQUENCE

#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Type.h>
#include <stdbool.h>

#include <stdio.h>

#line 49 "src/analyzer/types/Type.pv"
struct Sequence {
    struct SequenceType type;
    struct Type element;
    struct Type element_pointer;
};

#line 56 "src/analyzer/types/Type.pv"
bool Sequence__is_slice(struct Sequence* self);

#line 63 "src/analyzer/types/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self);

#endif
