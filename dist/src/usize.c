#include <stdint.h>
#include <std/Hashed.h>
#include <std/Fnv1a.h>

#include <usize.h>

#line 48 "src/std/Hash.pv"
Hashed usize__Hash__hash(void* __self) {
    uintptr_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uintptr_t));
}

struct HashVTable USIZE__VTABLE__HASH = { .hash = &usize__Hash__hash };
