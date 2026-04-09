#ifndef PAVE_SLICE_STATEMENT
#define PAVE_SLICE_STATEMENT

#include <stdint.h>

struct Statement;

struct slice_Statement { struct Statement* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Statement slice_Statement__iter(struct slice_Statement self);

#endif
