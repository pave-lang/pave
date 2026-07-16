#include <stdint.h>

#include <std/Fnv1a.h>
#include <i16.h>

#include <i16.h>

#line 48 "src/std/Hash.pv"
Hash i16__Hash__hash(void* __self) {
    int16_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int16_t));
}

#line 70 "src/std/Hash.pv"
bool i16__Eq_i16__eq(int16_t self, int16_t other) {
    #line 70 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable I16__VTABLE__HASH = { .fn_hash = &i16__Hash__hash };
