#include <stdint.h>
#include <stdbool.h>

#include <std/Hashed.h>

#include <std/Fnv1a.h>

#include <std/Fnv1a.h>

#line 5 "src/std/Hash.pv"
Hashed Fnv1a__hash(void const* value, uintptr_t size) {
    #line 6 "src/std/Hash.pv"
    uint64_t fnv_prime = 1099511628211ULL;
    #line 7 "src/std/Hash.pv"
    uint64_t fnv_offset_basis = 14695981039346656037ULL;

    #line 9 "src/std/Hash.pv"
    uint64_t result = fnv_offset_basis;

    #line 11 "src/std/Hash.pv"
    uint8_t const* bytes = value;

    #line 13 "src/std/Hash.pv"
    uintptr_t i = 0;
    #line 14 "src/std/Hash.pv"
    while (i < size) {
        #line 15 "src/std/Hash.pv"
        result = result ^ bytes[i];
        #line 16 "src/std/Hash.pv"
        result = result * fnv_prime;
        #line 17 "src/std/Hash.pv"
        i += 1;
    }

    #line 20 "src/std/Hash.pv"
    return result;
}

#line 23 "src/std/Hash.pv"
Hashed Fnv1a__continue_with(Hashed hash, void const* value, uintptr_t size) {
    #line 24 "src/std/Hash.pv"
    uint64_t fnv_prime = 1099511628211ULL;

    #line 26 "src/std/Hash.pv"
    uint64_t result = hash;

    #line 28 "src/std/Hash.pv"
    uint8_t const* bytes = value;

    #line 30 "src/std/Hash.pv"
    uintptr_t i = 0;
    #line 31 "src/std/Hash.pv"
    while (i < size) {
        #line 32 "src/std/Hash.pv"
        result = result ^ bytes[i];
        #line 33 "src/std/Hash.pv"
        result = result * fnv_prime;
        #line 34 "src/std/Hash.pv"
        i += 1;
    }

    #line 37 "src/std/Hash.pv"
    return result;
}
