#include <stdint.h>

#include <std/Fnv1a.h>
#include <usize.h>

#include <usize.h>

#line 48 "src/std/Hash.pv"
Hash usize__Hash__hash(void* __self) {
    uintptr_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(uintptr_t));
}

#line 84 "src/std/Hash.pv"
bool usize__Eq_usize__eq(uintptr_t self, uintptr_t other) {
    #line 84 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable USIZE__VTABLE__HASH = { .fn_hash = &usize__Hash__hash };
