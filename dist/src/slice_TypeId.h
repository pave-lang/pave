#ifndef PAVE_SLICE_TYPE_ID
#define PAVE_SLICE_TYPE_ID

#include <stdint.h>

typedef uint64_t TypeId;

struct slice_TypeId { TypeId* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_TypeId slice_TypeId__iter(struct slice_TypeId self);

#endif
