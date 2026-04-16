#ifndef PAVE_ITER_ENUMERATE_REF_CXCURSOR
#define PAVE_ITER_ENUMERATE_REF_CXCURSOR

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_CXCursor.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_CXCursor {
    uintptr_t index;
    struct Iter_ref_CXCursor iter;
};

#include <tuple_usize_ref_CXCursor.h>
struct IterEnumerate_ref_CXCursor;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_CXCursor__next(struct IterEnumerate_ref_CXCursor* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_CXCursor IterEnumerate_ref_CXCursor__value(struct IterEnumerate_ref_CXCursor* self);

#endif
