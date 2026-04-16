#include <stdint.h>

#include <std/Fnv1a.h>
#include <u16.h>

#include <u16.h>

#line 48 "src/std/Hash.pv"
Hashed u16__Hash__hash(void* __self) {
    uint16_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint16_t));
}

struct trait_HashVTable U16__VTABLE__HASH = { .hash = &u16__Hash__hash };
