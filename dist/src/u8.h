#ifndef PAVE_U8
#define PAVE_U8

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash u8__Hash__hash(void* __self);

#line 80 "src/std/Hash.pv"
bool u8__Eq_u8__eq(uint8_t self, uint8_t other);

extern struct trait_HashVTable U8__VTABLE__HASH;

#endif
