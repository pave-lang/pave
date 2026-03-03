#ifndef PAVE_HASH
#define PAVE_HASH

#include <stdint.h>

typedef uint64_t Hashed;

#line 47 "src/std/Hash.pv"
struct HashVTable {
    #line 48 "src/std/Hash.pv"
Hashed (*hash)(void* __self);
};

#line 47 "src/std/Hash.pv"
struct Hash {
    const struct HashVTable* vtable;
    void* instance;
};

#endif
