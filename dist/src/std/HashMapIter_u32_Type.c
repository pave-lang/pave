#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include <std/HashMapBucket_u32_Type.h>
#include <std/HashMapIter_u32_Type.h>
#include <tuple_u32_Type.h>
#include <std/HashMapIter_u32_Type.h>

#include <std/HashMapIter_u32_Type.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_u32_Type__next(struct HashMapIter_u32_Type* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_u32_Type* HashMapIter_u32_Type__value(struct HashMapIter_u32_Type* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_u32_Type*)(self->iter);
}
