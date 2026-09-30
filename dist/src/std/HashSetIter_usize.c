#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <std/HashSetBucket_usize.h>
#include <std/HashSetIter_usize.h>

#include <std/HashSetIter_usize.h>

#line 16 "src/std/HashSet.pv"
bool HashSetIter_usize__next(struct HashSetIter_usize* self) {
    #line 17 "src/std/HashSet.pv"
    self->iter += 1;
    #line 18 "src/std/HashSet.pv"
    return self->iter < self->end;
}

#line 21 "src/std/HashSet.pv"
uintptr_t* HashSetIter_usize__value(struct HashSetIter_usize* self) {
    #line 22 "src/std/HashSet.pv"
    return (uintptr_t*)(self->iter);
}
