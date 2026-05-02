#include <stdint.h>

#include <std/HashMapBucket_usize_TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>
#include <tuple_usize_TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>

#include <std/HashMapIter_usize_TypeUsage_Struct.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Struct__next(struct HashMapIter_usize_TypeUsage_Struct* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Struct* HashMapIter_usize_TypeUsage_Struct__value(struct HashMapIter_usize_TypeUsage_Struct* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_usize_TypeUsage_Struct*)(self->iter);
}
