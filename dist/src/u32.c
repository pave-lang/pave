#include <stdint.h>

#include <std/Fnv1a.h>
#include <u32.h>

#include <u32.h>

#line 48 "src/std/Hash.pv"
Hash u32__Hash__hash(void* __self) {
    uint32_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint32_t));
}

#line 82 "src/std/Hash.pv"
bool u32__Eq_u32__eq(uint32_t self, uint32_t other) {
    #line 82 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable U32__VTABLE__HASH = { .fn_hash = &u32__Hash__hash };
