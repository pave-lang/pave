#include <stdint.h>

#include <std/Fnv1a.h>
#include <f64.h>

#include <f64.h>

#line 48 "src/std/Hash.pv"
Hashed f64__Hash__hash(void* __self) {
    double* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(double));
}

struct trait_HashVTable F64__VTABLE__HASH = { .hash = &f64__Hash__hash };
