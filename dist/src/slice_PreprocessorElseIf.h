#ifndef PAVE_SLICE_PREPROCESSOR_ELSE_IF
#define PAVE_SLICE_PREPROCESSOR_ELSE_IF

#include <analyzer/statement/PreprocessorElseIf.h>
#include <std/Iter_ref_PreprocessorElseIf.h>
struct slice_PreprocessorElseIf { struct PreprocessorElseIf* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_PreprocessorElseIf slice_PreprocessorElseIf__iter(struct slice_PreprocessorElseIf self);

#endif
