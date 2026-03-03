#include <stdio.h>
#include <string.h>

#include <stdbool.h>
#include <std/HashMapBucket_usize_TypeFunctionUsage.h>
#include <stdint.h>
#include <compiler/TypeFunctionUsage.h>
#include <tuple_usize_TypeFunctionUsage.h>

#include <std/HashMapIter_usize_TypeFunctionUsage.h>

#line 16 "src/std/HashMap.pv"
bool HashMapIter_usize_TypeFunctionUsage__next(struct HashMapIter_usize_TypeFunctionUsage* self) {
    #line 17 "src/std/HashMap.pv"
    self->iter += 1;
    #line 18 "src/std/HashMap.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashMap.pv"
struct tuple_usize_TypeFunctionUsage* HashMapIter_usize_TypeFunctionUsage__value(struct HashMapIter_usize_TypeFunctionUsage* self) {
    #line 22 "src/std/HashMap.pv"
    return (struct tuple_usize_TypeFunctionUsage*)(self->iter);
}
