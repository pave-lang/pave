#include <stdint.h>

#include <std/Fnv1a.h>
#include <std/ptr_void.h>

#line 48 "src/std/Hash.pv"
Hash ptr_void__Hash__hash(void* __self) {
    void** self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(void*));
}
