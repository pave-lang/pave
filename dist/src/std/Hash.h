#ifndef PAVE_HASH
#define PAVE_HASH

#include <stdint.h>
#include <stdbool.h>

#line 1 "src/std/Hash.pv"
typedef uint64_t Hash;

#include <std/trait_Hash.h>

#line 42 "src/std/Hash.pv"
Hash Hash__continue_with(Hash self, void const* value, uintptr_t size);

#line 52 "src/std/Hash.pv"
Hash Hash__Hash__hash(void* __self);

#line 56 "src/std/Hash.pv"
bool Hash__Eq_Hash__eq(Hash self, Hash other);

extern struct trait_HashVTable HASH__VTABLE__HASH;

#endif
