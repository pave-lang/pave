#ifndef PAVE_SLICE_MEMBER_COMPLETION_INFO
#define PAVE_SLICE_MEMBER_COMPLETION_INFO

#include <analyzer/MemberCompletionInfo.h>
#include <std/Iter_ref_MemberCompletionInfo.h>
struct slice_MemberCompletionInfo { struct MemberCompletionInfo* data; uintptr_t length; };

#line 2 "src/std/Slice.pv"
struct Iter_ref_MemberCompletionInfo slice_MemberCompletionInfo__iter(struct slice_MemberCompletionInfo self);

#endif
