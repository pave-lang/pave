#include <stdint.h>

#include <std/Hash.h>
#include <std/Fnv1a.h>
#include <std/trait_Hash.h>
#include <std/Hash.h>

#include <std/Hash.h>

#line 42 "src/std/Hash.pv"
Hash Hash__continue_with(Hash self, void const* value, uintptr_t size) {
    #line 43 "src/std/Hash.pv"
    return Fnv1a__continue_with(self, value, size);
}

#line 52 "src/std/Hash.pv"
Hash Hash__Hash__hash(void* __self) {
    Hash* self = __self; (void)self;
    #line 52 "src/std/Hash.pv"
    return *self;
}

#line 56 "src/std/Hash.pv"
bool Hash__Eq_Hash__eq(Hash self, Hash other) {
    #line 57 "src/std/Hash.pv"
    return (self ^ other) <= (uint64_t)(0);
}

struct trait_HashVTable HASH__VTABLE__HASH = { .fn_hash = &Hash__Hash__hash };
