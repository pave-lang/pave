#include <stdio.h>
#include <string.h>

#include <stdbool.h>
#include <std/HashMapBucket_str_usize.h>
#include <std/str.h>
#include <stdint.h>
#include <tuple_str_usize.h>

#include <std/HashMapIter_str_usize.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_str_usize__next(struct HashMapIter_str_usize* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_str_usize* HashMapIter_str_usize__value(struct HashMapIter_str_usize* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_str_usize*)(self->iter);
}
