#ifndef PAVE_SEQUENCE
#define PAVE_SEQUENCE

#include <analyzer/SequenceType.h>
#include <analyzer/Type.h>
#include <stdbool.h>

#include <stdio.h>

#line 41 "src/analyzer/Type.pv"
struct Sequence {
    struct SequenceType type;
    struct Type element;
    struct Type element_pointer;
};

#line 48 "src/analyzer/Type.pv"
bool Sequence__is_slice(struct Sequence* self);

#line 55 "src/analyzer/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self);

#endif
