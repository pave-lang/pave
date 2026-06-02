#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <std/HashMapBucket_str_Array_MemberCompletionInfo.h>
#include <std/HashMapIter_str_Array_MemberCompletionInfo.h>
#include <tuple_str_Array_MemberCompletionInfo.h>
#include <std/HashMapIter_str_Array_MemberCompletionInfo.h>

#include <std/HashMapIter_str_Array_MemberCompletionInfo.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Array_MemberCompletionInfo__next(struct HashMapIter_str_Array_MemberCompletionInfo* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_str_Array_MemberCompletionInfo* HashMapIter_str_Array_MemberCompletionInfo__value(struct HashMapIter_str_Array_MemberCompletionInfo* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_str_Array_MemberCompletionInfo*)(self->iter);
}
