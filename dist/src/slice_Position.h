#ifndef PAVE_SLICE_POSITION
#define PAVE_SLICE_POSITION

#include <analyzer/Position.h>
#include <std/Iter_ref_Position.h>
struct slice_Position { struct Position* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_Position slice_Position__iter(struct slice_Position self);

#endif
