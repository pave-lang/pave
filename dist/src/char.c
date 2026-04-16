#include <stdint.h>

#include <std/Fnv1a.h>
#include <char.h>

#include <char.h>

#line 48 "src/std/Hash.pv"
Hashed char__Hash__hash(void* __self) {
    char* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(char));
}

struct trait_HashVTable CHAR__VTABLE__HASH = { .hash = &char__Hash__hash };
