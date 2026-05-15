#ifndef PAVE_SLICE_TEST_INFO
#define PAVE_SLICE_TEST_INFO

#include <analyzer/TestInfo.h>
#include <std/Iter_ref_TestInfo.h>
struct slice_TestInfo { struct TestInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_TestInfo slice_TestInfo__iter(struct slice_TestInfo self);

#endif
