#include <stdint.h>

#include <stdint.h>

#include <std/Fnv1a.h>
#include <std/ptr_void.h>

#line 48 "src/std/Hash.pv"
Hash ptr_void__Hash__hash(void* __self) {
    void** self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(void*));
}

#line 90 "src/std/Hash.pv"
bool ptr_void__Eq_ptr_void__eq(void* self, void* other) {
    #line 90 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}
