#include <stdint.h>

#include <std/Fnv1a.h>
#include <u64.h>

#include <u64.h>

#line 48 "src/std/Hash.pv"
Hashed u64__Hash__hash(void* __self) {
    uint64_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint64_t));
}

struct trait_HashVTable U64__VTABLE__HASH = { .hash = &u64__Hash__hash };
