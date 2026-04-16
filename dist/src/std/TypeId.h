#ifndef PAVE_TYPE_ID
#define PAVE_TYPE_ID

#include <stdint.h>

#line 1 "src/std/TypeId.pv"
typedef uint64_t TypeId;

#include <std/trait_Hash.h>
#include <std/Hashed.h>
typedef uint64_t TypeId;

#line 3 "src/std/TypeId.pv"
Hashed TypeId__Hash__hash(void* __self);

extern struct trait_HashVTable TYPE_ID__VTABLE__HASH;

#endif
