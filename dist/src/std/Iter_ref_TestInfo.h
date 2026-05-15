#ifndef PAVE_ITER_REF_TEST_INFO
#define PAVE_ITER_REF_TEST_INFO

#include <stdint.h>
#include <stdbool.h>

struct TestInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_TestInfo {
    intptr_t step;
    struct TestInfo* iter;
    struct TestInfo* start;
    struct TestInfo* end;
};

#include <std/Iter_ref_TestInfo.h>
#include <std/IterEnumerate_ref_TestInfo.h>
struct TestInfo;
struct Iter_ref_TestInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_TestInfo Iter_ref_TestInfo__new(struct TestInfo* start, struct TestInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_TestInfo Iter_ref_TestInfo__reverse(struct Iter_ref_TestInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_TestInfo Iter_ref_TestInfo__skip(struct Iter_ref_TestInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_TestInfo__next(struct Iter_ref_TestInfo* self);

#line 43 "src/std/Array.pv"
struct TestInfo* Iter_ref_TestInfo__value(struct Iter_ref_TestInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_TestInfo Iter_ref_TestInfo__enumerate(struct Iter_ref_TestInfo self);

#endif
