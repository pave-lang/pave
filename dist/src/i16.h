#ifndef PAVE_I16
#define PAVE_I16

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash i16__Hash__hash(void* __self);

#line 70 "src/std/Hash.pv"
bool i16__Eq_i16__eq(int16_t self, int16_t other);

extern struct trait_HashVTable I16__VTABLE__HASH;

#endif
