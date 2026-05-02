#include <stdint.h>

#include <std/HashMapBucket_usize_TypeUsage_Tuple.h>
#include <std/HashMapIter_usize_TypeUsage_Tuple.h>
#include <tuple_usize_TypeUsage_Tuple.h>
#include <std/HashMapIter_usize_TypeUsage_Tuple.h>

#include <std/HashMapIter_usize_TypeUsage_Tuple.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Tuple__next(struct HashMapIter_usize_TypeUsage_Tuple* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Tuple* HashMapIter_usize_TypeUsage_Tuple__value(struct HashMapIter_usize_TypeUsage_Tuple* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_usize_TypeUsage_Tuple*)(self->iter);
}
