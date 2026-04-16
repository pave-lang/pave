#include <stdint.h>

#include <std/Fnv1a.h>
#include <i64.h>

#include <i64.h>

#line 48 "src/std/Hash.pv"
Hashed i64__Hash__hash(void* __self) {
    int64_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int64_t));
}

struct trait_HashVTable I64__VTABLE__HASH = { .hash = &i64__Hash__hash };
