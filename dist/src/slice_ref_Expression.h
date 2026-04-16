#ifndef PAVE_SLICE_REF_EXPRESSION
#define PAVE_SLICE_REF_EXPRESSION

#include <std/Iter_ref_ref_Expression.h>
struct Expression;
struct slice_ref_Expression { struct Expression** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Expression slice_ref_Expression__iter(struct slice_ref_Expression self);

#endif
