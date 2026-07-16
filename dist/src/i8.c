#include <stdint.h>

#include <std/Fnv1a.h>
#include <i8.h>

#include <i8.h>

#line 48 "src/std/Hash.pv"
Hash i8__Hash__hash(void* __self) {
    int8_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int8_t));
}

#line 69 "src/std/Hash.pv"
bool i8__Eq_i8__eq(int8_t self, int8_t other) {
    #line 69 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable I8__VTABLE__HASH = { .fn_hash = &i8__Hash__hash };
