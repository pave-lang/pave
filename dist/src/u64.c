#include <stdint.h>

#include <std/Fnv1a.h>
#include <u64.h>

#include <u64.h>

#line 48 "src/std/Hash.pv"
Hash u64__Hash__hash(void* __self) {
    uint64_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint64_t));
}

#line 83 "src/std/Hash.pv"
bool u64__Eq_u64__eq(uint64_t self, uint64_t other) {
    #line 83 "src/std/Hash.pv"
    return (self ^ other) <= (uint64_t)(0);
}

struct trait_HashVTable U64__VTABLE__HASH = { .fn_hash = &u64__Hash__hash };
