#ifndef PAVE_U64
#define PAVE_U64

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash u64__Hash__hash(void* __self);

#line 83 "src/std/Hash.pv"
bool u64__Eq_u64__eq(uint64_t self, uint64_t other);

extern struct trait_HashVTable U64__VTABLE__HASH;

#endif
