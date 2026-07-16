#ifndef PAVE_I32
#define PAVE_I32

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash i32__Hash__hash(void* __self);

#line 71 "src/std/Hash.pv"
bool i32__Eq_i32__eq(int32_t self, int32_t other);

extern struct trait_HashVTable I32__VTABLE__HASH;

#endif
