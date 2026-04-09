#ifndef PAVE_SLICE_REF_TRAIT
#define PAVE_SLICE_REF_TRAIT

#include <stdint.h>

struct Trait;

struct slice_ref_Trait { struct Trait** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ref_Trait slice_ref_Trait__iter(struct slice_ref_Trait self);

#endif
