#ifndef PAVE_ITER_REF_PREPROCESSOR_ELSE_IF
#define PAVE_ITER_REF_PREPROCESSOR_ELSE_IF

#include <stdint.h>
#include <stdbool.h>

struct PreprocessorElseIf;

#line 4 "src/std/Array.pv"
struct Iter_ref_PreprocessorElseIf {
    intptr_t step;
    struct PreprocessorElseIf* iter;
    struct PreprocessorElseIf* start;
    struct PreprocessorElseIf* end;
};

#include <std/IterEnumerate_ref_PreprocessorElseIf.h>
struct PreprocessorElseIf;

#line 12 "src/std/Array.pv"
struct Iter_ref_PreprocessorElseIf Iter_ref_PreprocessorElseIf__new(struct PreprocessorElseIf* start, struct PreprocessorElseIf* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_PreprocessorElseIf Iter_ref_PreprocessorElseIf__reverse(struct Iter_ref_PreprocessorElseIf self);

#line 33 "src/std/Array.pv"
struct Iter_ref_PreprocessorElseIf Iter_ref_PreprocessorElseIf__skip(struct Iter_ref_PreprocessorElseIf self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_PreprocessorElseIf__next(struct Iter_ref_PreprocessorElseIf* self);

#line 43 "src/std/Array.pv"
struct PreprocessorElseIf* Iter_ref_PreprocessorElseIf__value(struct Iter_ref_PreprocessorElseIf* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_PreprocessorElseIf Iter_ref_PreprocessorElseIf__enumerate(struct Iter_ref_PreprocessorElseIf self);

#endif
