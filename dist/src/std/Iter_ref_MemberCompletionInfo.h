#ifndef PAVE_ITER_REF_MEMBER_COMPLETION_INFO
#define PAVE_ITER_REF_MEMBER_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

struct MemberCompletionInfo;

#line 4 "src/std/Array.pv"
struct Iter_ref_MemberCompletionInfo {
    intptr_t step;
    struct MemberCompletionInfo* iter;
    struct MemberCompletionInfo* start;
    struct MemberCompletionInfo* end;
};

#include <std/Iter_ref_MemberCompletionInfo.h>
#include <std/IterEnumerate_ref_MemberCompletionInfo.h>
struct MemberCompletionInfo;
struct Iter_ref_MemberCompletionInfo;

#line 12 "src/std/Array.pv"
struct Iter_ref_MemberCompletionInfo Iter_ref_MemberCompletionInfo__new(struct MemberCompletionInfo* start, struct MemberCompletionInfo* end);

#line 21 "src/std/Array.pv"
struct Iter_ref_MemberCompletionInfo Iter_ref_MemberCompletionInfo__reverse(struct Iter_ref_MemberCompletionInfo self);

#line 33 "src/std/Array.pv"
struct Iter_ref_MemberCompletionInfo Iter_ref_MemberCompletionInfo__skip(struct Iter_ref_MemberCompletionInfo self, intptr_t steps);

#line 38 "src/std/Array.pv"
bool Iter_ref_MemberCompletionInfo__next(struct Iter_ref_MemberCompletionInfo* self);

#line 43 "src/std/Array.pv"
struct MemberCompletionInfo* Iter_ref_MemberCompletionInfo__value(struct Iter_ref_MemberCompletionInfo* self);

#line 47 "src/std/Array.pv"
struct IterEnumerate_ref_MemberCompletionInfo Iter_ref_MemberCompletionInfo__enumerate(struct Iter_ref_MemberCompletionInfo self);

#endif
