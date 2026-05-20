#ifndef PAVE_HASHED
#define PAVE_HASHED

#include <stdint.h>
#include <stdbool.h>

#line 1 "src/std/Hash.pv"
typedef uint64_t Hashed;

#include <std/Hashed.h>
typedef uint64_t Hashed;

#line 42 "src/std/Hash.pv"
Hashed Hashed__continue_with(Hashed self, void const* value, uintptr_t size);

#line 52 "src/std/Hash.pv"
Hashed Hashed__Hash__hash(void* __self);

#line 56 "src/std/Hash.pv"
bool Hashed__Eq_Hashed__eq(void* __self, Hashed other);

extern struct trait_HashVTable HASHED__VTABLE__HASH;
extern struct trait_Eq_HashedVTable HASHED__VTABLE__EQ;

#endif
