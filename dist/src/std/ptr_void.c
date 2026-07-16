#include <stdint.h>

#include <std/ptr_void.h>

#line 90 "src/std/Hash.pv"
bool ptr_void__Eq_ptr_void__eq(void* self, void* other) {
    #line 90 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}
