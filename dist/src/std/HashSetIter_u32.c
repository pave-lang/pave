#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashSetBucket_u32.h>
#include <std/HashSetIter_u32.h>

#include <std/HashSetIter_u32.h>

#line 16 "src/std/HashSet.pv"
bool HashSetIter_u32__next(struct HashSetIter_u32* self) {
    #line 17 "src/std/HashSet.pv"
    self->iter += 1;
    #line 18 "src/std/HashSet.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashSet.pv"
uint32_t* HashSetIter_u32__value(struct HashSetIter_u32* self) {
    #line 22 "src/std/HashSet.pv"
    return (uint32_t*)(self->iter);
}
