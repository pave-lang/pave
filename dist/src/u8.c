#include <stdint.h>

#include <std/Fnv1a.h>
#include <u8.h>

#include <u8.h>

#line 48 "src/std/Hash.pv"
Hash u8__Hash__hash(void* __self) {
    uint8_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint8_t));
}

#line 80 "src/std/Hash.pv"
bool u8__Eq_u8__eq(uint8_t self, uint8_t other) {
    #line 80 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable U8__VTABLE__HASH = { .fn_hash = &u8__Hash__hash };
