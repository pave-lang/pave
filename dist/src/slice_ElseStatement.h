#ifndef PAVE_SLICE_ELSE_STATEMENT
#define PAVE_SLICE_ELSE_STATEMENT

#include <analyzer/statement/ElseStatement.h>
#include <std/Iter_ref_ElseStatement.h>
struct slice_ElseStatement { struct ElseStatement* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_ElseStatement slice_ElseStatement__iter(struct slice_ElseStatement self);

#endif
