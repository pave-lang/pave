#include <stdint.h>

#include <std/Fnv1a.h>
#include <char.h>

#include <char.h>

#line 48 "src/std/Hash.pv"
Hash char__Hash__hash(void* __self) {
    char* self = __self; (void)self;
    #line 48 "src/std/Hash.pv"
    return Fnv1a__hash(self, sizeof(char));
}

#line 62 "src/std/Hash.pv"
bool char__Eq_char__eq(char self, char other) {
    #line 62 "src/std/Hash.pv"
    return ((uint64_t)(self) ^ (uint64_t)(other)) <= (uint64_t)(0);
}

struct trait_HashVTable CHAR__VTABLE__HASH = { .fn_hash = &char__Hash__hash };
