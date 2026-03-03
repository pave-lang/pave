#include <stdio.h>
#include <string.h>

#include <stdbool.h>
#include <std/HashMapBucket_str_Array_InlayHint.h>
#include <std/str.h>
#include <std/Array_InlayHint.h>
#include <analyzer/InlayHint.h>
#include <tuple_str_Array_InlayHint.h>

#include <std/HashMapIter_str_Array_InlayHint.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_Array_InlayHint__next(struct HashMapIter_str_Array_InlayHint* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_str_Array_InlayHint* HashMapIter_str_Array_InlayHint__value(struct HashMapIter_str_Array_InlayHint* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_str_Array_InlayHint*)(self->iter);
}
