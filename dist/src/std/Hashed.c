#include <stdint.h>
#include <std/Fnv1a.h>

#include <std/Hashed.h>

#line 42 "src/std/Hash.pv"
Hashed Hashed__continue_with(Hashed self, void const* value, uintptr_t size) {
    #line 43 "src/std/Hash.pv"
    return Fnv1a__continue_with(self, value, size);
}
