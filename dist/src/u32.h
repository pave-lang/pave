#ifndef PAVE_U32
#define PAVE_U32

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash u32__Hash__hash(void* __self);

#line 82 "src/std/Hash.pv"
bool u32__Eq_u32__eq(uint32_t self, uint32_t other);

extern struct trait_HashVTable U32__VTABLE__HASH;

#endif
