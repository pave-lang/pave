#ifndef PAVE_CHAR
#define PAVE_CHAR

#include <stdbool.h>

#include <std/trait_Hash.h>
#include <std/Hash.h>


#line 48 "src/std/Hash.pv"
Hash char__Hash__hash(void* __self);

#line 62 "src/std/Hash.pv"
bool char__Eq_char__eq(char self, char other);

extern struct trait_HashVTable CHAR__VTABLE__HASH;

#endif
