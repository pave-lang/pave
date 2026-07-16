#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashMapBucket_usize_TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>
#include <tuple_usize_TypeUsage_Struct.h>
#include <std/HashMapIter_usize_TypeUsage_Struct.h>

#include <std/HashMapIter_usize_TypeUsage_Struct.h>

#line 17 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Struct__next(struct HashMapIter_usize_TypeUsage_Struct* self) {
    #line 18 "src/std/HashMap.pv"
    self->iter += 1;
    #line 19 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 22 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Struct* HashMapIter_usize_TypeUsage_Struct__value(struct HashMapIter_usize_TypeUsage_Struct* self) {
    #line 23 "src/std/HashMap.pv"
    return (struct tuple_usize_TypeUsage_Struct*)(self->iter);
}
