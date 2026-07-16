#ifndef PAVE_ISIZE
#define PAVE_ISIZE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash isize__Hash__hash(void* __self);

#line 73 "src/std/Hash.pv"
bool isize__Eq_isize__eq(intptr_t self, intptr_t other);

extern struct trait_HashVTable ISIZE__VTABLE__HASH;

#endif
