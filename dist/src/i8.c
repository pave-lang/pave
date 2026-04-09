#include <stdint.h>
#include <std/Hashed.h>
#include <std/Fnv1a.h>

#include <i8.h>

#line 48 "src/std/Hash.pv"
Hashed i8__Hash__hash(void* __self) {
    int8_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int8_t));
}

struct trait_HashVTable I8__VTABLE__HASH = { .hash = &i8__Hash__hash };
