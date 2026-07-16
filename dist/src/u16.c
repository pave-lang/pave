#include <stdint.h>

#include <std/Fnv1a.h>
#include <u16.h>

#include <u16.h>

#line 48 "src/std/Hash.pv"
Hash u16__Hash__hash(void* __self) {
    uint16_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint16_t));
}

#line 81 "src/std/Hash.pv"
bool u16__Eq_u16__eq(uint16_t self, uint16_t other) {
    #line 81 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable U16__VTABLE__HASH = { .fn_hash = &u16__Hash__hash };
