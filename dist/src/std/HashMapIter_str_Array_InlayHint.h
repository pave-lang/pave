#ifndef PAVE_HASH_MAP_ITER_STR_ARRAY_INLAY_HINT
#define PAVE_HASH_MAP_ITER_STR_ARRAY_INLAY_HINT

#include <stdbool.h>

struct HashMapBucket_str_Array_InlayHint;

#line 11 "src/std/HashMap.pv"
struct HashMapIter_str_Array_InlayHint {
    struct HashMapBucket_str_Array_InlayHint* iter;
    struct HashMapBucket_str_Array_InlayHint* end;
};


#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_Array_InlayHint__next(struct HashMapIter_str_Array_InlayHint* self);

#line 22 "src/std/HashMap.pv"
struct tuple_str_Array_InlayHint* HashMapIter_str_Array_InlayHint__value(struct HashMapIter_str_Array_InlayHint* self);

#endif
