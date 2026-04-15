#ifndef PAVE_SLICE_CHAR
#define PAVE_SLICE_CHAR

#include <std/Iter_ref_char.h>
struct slice_char { char* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_char slice_char__iter(struct slice_char self);

#endif
