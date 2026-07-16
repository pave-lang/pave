#include <stdint.h>

#include <std/Fnv1a.h>
#include <isize.h>

#include <isize.h>

#line 48 "src/std/Hash.pv"
Hash isize__Hash__hash(void* __self) {
    intptr_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(intptr_t));
}

#line 73 "src/std/Hash.pv"
bool isize__Eq_isize__eq(intptr_t self, intptr_t other) {
    #line 73 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable ISIZE__VTABLE__HASH = { .fn_hash = &isize__Hash__hash };
