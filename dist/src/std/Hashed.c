#include <std/Hashed.h>
#include <std/Fnv1a.h>
#include <std/trait_Hash.h>
#include <std/trait_Eq_Hashed.h>
#include <std/Hashed.h>

#include <std/Hashed.h>

#line 42 "src/std/Hash.pv"
Hashed Hashed__continue_with(Hashed self, void const* value, uintptr_t size) {
    #line 43 "src/std/Hash.pv"
    return Fnv1a__continue_with(self, value, size);
}

#line 52 "src/std/Hash.pv"
Hashed Hashed__Hash__hash(void* __self) {
    Hashed* self = __self; (void)self;
    #line 52 "src/std/Hash.pv"
    return *self;
}

#line 56 "src/std/Hash.pv"
bool Hashed__Eq_Hashed__eq(void* __self, Hashed other) {
    Hashed* self = __self; (void)self;
    #line 57 "src/std/Hash.pv"
    return (*self) == other;
}

struct trait_HashVTable HASHED__VTABLE__HASH = { .fn_hash = &Hashed__Hash__hash };
struct trait_Eq_HashedVTable HASHED__VTABLE__EQ = { .fn_eq = &Hashed__Eq_Hashed__eq };
