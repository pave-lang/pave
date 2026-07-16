#ifndef PAVE_I64
#define PAVE_I64

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash i64__Hash__hash(void* __self);

#line 72 "src/std/Hash.pv"
bool i64__Eq_i64__eq(int64_t self, int64_t other);

extern struct trait_HashVTable I64__VTABLE__HASH;

#endif
