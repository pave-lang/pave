#ifndef PAVE_TRAIT_HASH
#define PAVE_TRAIT_HASH

#include <stdint.h>

typedef uint64_t Hashed;

#line 47 "src/std/Hash.pv"
struct trait_HashVTable {
    #line 48 "src/std/Hash.pv"
Hashed (*hash)(void* __self);
};

#line 47 "src/std/Hash.pv"
struct trait_Hash {
    const struct trait_HashVTable* vtable;
    void* instance;
};

#endif
