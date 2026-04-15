#ifndef PAVE_FNV1A
#define PAVE_FNV1A

#include <stdint.h>

#line 3 "src/std/Hash.pv"
struct Fnv1a;

#include <std/Hashed.h>

#line 5 "src/std/Hash.pv"
Hashed Fnv1a__hash(void const* value, uintptr_t size);

#line 23 "src/std/Hash.pv"
Hashed Fnv1a__continue_with(Hashed hash, void const* value, uintptr_t size);

#endif
