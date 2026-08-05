#ifndef PAVE_ITER_REF_COMPLETION_INFO
#define PAVE_ITER_REF_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

struct CompletionInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_CompletionInfo {
    intptr_t step;
    struct CompletionInfo* iter;
    struct CompletionInfo* start;
    struct CompletionInfo* end;
};

#include <std/IterEnumerate_ref_CompletionInfo.h>
struct CompletionInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_CompletionInfo Iter_ref_CompletionInfo__new(struct CompletionInfo* start, struct CompletionInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_CompletionInfo Iter_ref_CompletionInfo__reverse(struct Iter_ref_CompletionInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_CompletionInfo Iter_ref_CompletionInfo__skip(struct Iter_ref_CompletionInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_CompletionInfo__next(struct Iter_ref_CompletionInfo* self);

#line 43 "src/std/Array.pv"
struct CompletionInfo* Iter_ref_CompletionInfo__value(struct Iter_ref_CompletionInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_CompletionInfo Iter_ref_CompletionInfo__enumerate(struct Iter_ref_CompletionInfo self);

#endif
