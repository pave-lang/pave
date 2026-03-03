#ifndef PAVE_SLICE_CHAR
#define PAVE_SLICE_CHAR

#include <stdint.h>

struct slice_char { char* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct ArrayIter_ref_char slice_char__iter(struct slice_char self);

#endif
