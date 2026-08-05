#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashMapBucket_usize_TypeUsage_Trait.h>
#include <tuple_usize_TypeUsage_Trait.h>
#include <std/HashMapIter_usize_TypeUsage_Trait.h>

#include <std/HashMapIter_usize_TypeUsage_Trait.h>

#line 17 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Trait__next(struct HashMapIter_usize_TypeUsage_Trait* self) {
    #line 18 "src/std/HashMap.pv"
    self->iter += 1;
    #line 19 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 22 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Trait* HashMapIter_usize_TypeUsage_Trait__value(struct HashMapIter_usize_TypeUsage_Trait* self) {
    #line 23 "src/std/HashMap.pv"
    return (struct tuple_usize_TypeUsage_Trait*)(self->iter);
}
