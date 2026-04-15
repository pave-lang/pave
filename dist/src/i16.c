#include <stdint.h>

#include <std/Hashed.h>
#include <std/Fnv1a.h>
#include <i16.h>

#include <i16.h>

#line 48 "src/std/Hash.pv"
Hashed i16__Hash__hash(void* __self) {
    int16_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int16_t));
}

struct trait_HashVTable I16__VTABLE__HASH = { .hash = &i16__Hash__hash };
