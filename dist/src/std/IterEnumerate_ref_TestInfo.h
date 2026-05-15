#ifndef PAVE_ITER_ENUMERATE_REF_TEST_INFO
#define PAVE_ITER_ENUMERATE_REF_TEST_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_TestInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_TestInfo {
    uintptr_t index;
    struct Iter_ref_TestInfo iter;
};

#include <tuple_usize_ref_TestInfo.h>
struct IterEnumerate_ref_TestInfo;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_TestInfo__next(struct IterEnumerate_ref_TestInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_TestInfo IterEnumerate_ref_TestInfo__value(struct IterEnumerate_ref_TestInfo* self);

#endif
