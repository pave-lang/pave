#ifndef PAVE_U16
#define PAVE_U16

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash u16__Hash__hash(void* __self);

#line 81 "src/std/Hash.pv"
bool u16__Eq_u16__eq(uint16_t self, uint16_t other);

extern struct trait_HashVTable U16__VTABLE__HASH;

#endif
