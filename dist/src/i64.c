#include <stdint.h>

#include <std/Fnv1a.h>
#include <i64.h>

#include <i64.h>

#line 48 "src/std/Hash.pv"
Hash i64__Hash__hash(void* __self) {
    int64_t* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(int64_t));
}

#line 72 "src/std/Hash.pv"
bool i64__Eq_i64__eq(int64_t self, int64_t other) {
    #line 72 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable I64__VTABLE__HASH = { .fn_hash = &i64__Hash__hash };
