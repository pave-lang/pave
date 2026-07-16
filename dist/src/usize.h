#ifndef PAVE_USIZE
#define PAVE_USIZE

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash usize__Hash__hash(void* __self);

#line 84 "src/std/Hash.pv"
bool usize__Eq_usize__eq(uintptr_t self, uintptr_t other);

extern struct trait_HashVTable USIZE__VTABLE__HASH;

#endif
