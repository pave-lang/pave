#include <stdint.h>

#include <std/Fnv1a.h>
#include <i32.h>

#include <i32.h>

#line 48 "src/std/Hash.pv"
Hashed i32__Hash__hash(void* __self) {
    int32_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int32_t));
}

struct trait_HashVTable I32__VTABLE__HASH = { .hash = &i32__Hash__hash };
