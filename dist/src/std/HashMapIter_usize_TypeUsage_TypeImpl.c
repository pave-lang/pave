#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashMapBucket_usize_TypeUsage_TypeImpl.h>
#include <tuple_usize_TypeUsage_TypeImpl.h>
#include <std/HashMapIter_usize_TypeUsage_TypeImpl.h>

#include <std/HashMapIter_usize_TypeUsage_TypeImpl.h>

#line 17 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_TypeImpl__next(struct HashMapIter_usize_TypeUsage_TypeImpl* self) {
    #line 18 "src/std/HashMap.pv"
    self->iter += 1;
    #line 19 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 22 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_TypeImpl* HashMapIter_usize_TypeUsage_TypeImpl__value(struct HashMapIter_usize_TypeUsage_TypeImpl* self) {
    #line 23 "src/std/HashMap.pv"
    return (struct tuple_usize_TypeUsage_TypeImpl*)(self->iter);
}
