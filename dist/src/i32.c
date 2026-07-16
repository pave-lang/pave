#include <stdint.h>

#include <std/Fnv1a.h>
#include <i32.h>

#include <i32.h>

#line 48 "src/std/Hash.pv"
Hash i32__Hash__hash(void* __self) {
    int32_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int32_t));
}

#line 71 "src/std/Hash.pv"
bool i32__Eq_i32__eq(int32_t self, int32_t other) {
    #line 71 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable I32__VTABLE__HASH = { .fn_hash = &i32__Hash__hash };
