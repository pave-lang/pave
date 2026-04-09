#include <stdint.h>
#include <std/Hashed.h>
#include <std/Fnv1a.h>

#include <u32.h>

#line 48 "src/std/Hash.pv"
Hashed u32__Hash__hash(void* __self) {
    uint32_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint32_t));
}

struct trait_HashVTable U32__VTABLE__HASH = { .hash = &u32__Hash__hash };
