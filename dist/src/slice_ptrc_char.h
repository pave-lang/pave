#ifndef PAVE_SLICE_PTRC_CHAR
#define PAVE_SLICE_PTRC_CHAR

#include <std/Iter_ref_ptrc_char.h>
struct slice_ptrc_char { char const** data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ptrc_char slice_ptrc_char__iter(struct slice_ptrc_char self);

#endif
