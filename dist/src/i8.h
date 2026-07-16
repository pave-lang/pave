#ifndef PAVE_I8
#define PAVE_I8

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash i8__Hash__hash(void* __self);

#line 69 "src/std/Hash.pv"
bool i8__Eq_i8__eq(int8_t self, int8_t other);

extern struct trait_HashVTable I8__VTABLE__HASH;

#endif
