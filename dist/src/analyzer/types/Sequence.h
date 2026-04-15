#ifndef PAVE_SEQUENCE
#define PAVE_SEQUENCE

#include <stdbool.h>

#include <stdio.h>

#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Type.h>

#line 50 "src/analyzer/types/Type.pv"
struct Sequence {
    struct SequenceType type;
    struct Type element;
    struct Type element_pointer;
};
struct Sequence;


#line 57 "src/analyzer/types/Type.pv"
bool Sequence__is_slice(struct Sequence* self);

#line 64 "src/analyzer/types/Type.pv"
bool Sequence__is_fixed_array(struct Sequence* self);

#endif
