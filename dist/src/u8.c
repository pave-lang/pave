#include <stdint.h>

#include <std/Hashed.h>
#include <std/Fnv1a.h>
#include <u8.h>

#include <u8.h>

#line 48 "src/std/Hash.pv"
Hashed u8__Hash__hash(void* __self) {
    uint8_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uint8_t));
}

struct trait_HashVTable U8__VTABLE__HASH = { .hash = &u8__Hash__hash };
