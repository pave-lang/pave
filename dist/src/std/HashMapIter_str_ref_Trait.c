#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashMapBucket_str_ref_Trait.h>
#include <std/HashMapIter_str_ref_Trait.h>
#include <tuple_str_ref_Trait.h>
#include <std/HashMapIter_str_ref_Trait.h>

#include <std/HashMapIter_str_ref_Trait.h>

#line 17 "src/std/HashMap.pv"
bool HashMapIter_str_ref_Trait__next(struct HashMapIter_str_ref_Trait* self) {
    #line 18 "src/std/HashMap.pv"
    self->iter += 1;
    #line 19 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 22 "src/std/HashMap.pv"
struct tuple_str_ref_Trait* HashMapIter_str_ref_Trait__value(struct HashMapIter_str_ref_Trait* self) {
    #line 23 "src/std/HashMap.pv"
    return (struct tuple_str_ref_Trait*)(self->iter);
}
