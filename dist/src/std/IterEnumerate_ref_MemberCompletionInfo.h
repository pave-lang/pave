#ifndef PAVE_ITER_ENUMERATE_REF_MEMBER_COMPLETION_INFO
#define PAVE_ITER_ENUMERATE_REF_MEMBER_COMPLETION_INFO

#include <stdint.h>
#include <stdbool.h>

#include <std/Iter_ref_MemberCompletionInfo.h>

#line 52 "src/std/Array.pv"
struct IterEnumerate_ref_MemberCompletionInfo {
    uintptr_t index;
    struct Iter_ref_MemberCompletionInfo iter;
};

#include <tuple_usize_ref_MemberCompletionInfo.h>
struct IterEnumerate_ref_MemberCompletionInfo;

#line 58 "src/std/Array.pv"
bool IterEnumerate_ref_MemberCompletionInfo__next(struct IterEnumerate_ref_MemberCompletionInfo* self);

#line 64 "src/std/Array.pv"
struct tuple_usize_ref_MemberCompletionInfo IterEnumerate_ref_MemberCompletionInfo__value(struct IterEnumerate_ref_MemberCompletionInfo* self);

#endif
