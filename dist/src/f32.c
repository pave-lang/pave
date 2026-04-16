#include <stdint.h>

#include <std/Hashed.h>
#include <std/Fnv1a.h>
#include <f32.h>

#include <f32.h>

#line 48 "src/std/Hash.pv"
Hashed f32__Hash__hash(void* __self) {
    float* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(float));
}

struct trait_HashVTable F32__VTABLE__HASH = { .hash = &f32__Hash__hash };
