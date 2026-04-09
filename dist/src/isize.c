#include <stdint.h>
#include <std/Hashed.h>
#include <std/Fnv1a.h>

#include <isize.h>

#line 48 "src/std/Hash.pv"
Hashed isize__Hash__hash(void* __self) {
    intptr_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(intptr_t));
}

struct trait_HashVTable ISIZE__VTABLE__HASH = { .hash = &isize__Hash__hash };
