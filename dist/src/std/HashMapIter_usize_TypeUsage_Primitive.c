#include <std/HashMapBucket_usize_TypeUsage_Primitive.h>
#include <std/HashMapIter_usize_TypeUsage_Primitive.h>
#include <tuple_usize_TypeUsage_Primitive.h>
#include <std/HashMapIter_usize_TypeUsage_Primitive.h>

#include <std/HashMapIter_usize_TypeUsage_Primitive.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeUsage_Primitive__next(struct HashMapIter_usize_TypeUsage_Primitive* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeUsage_Primitive* HashMapIter_usize_TypeUsage_Primitive__value(struct HashMapIter_usize_TypeUsage_Primitive* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_usize_TypeUsage_Primitive*)(self->iter);
}
