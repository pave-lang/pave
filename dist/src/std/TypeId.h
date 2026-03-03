#ifndef PAVE_TYPE_ID
#define PAVE_TYPE_ID

#include <stdint.h>
#include <std/Hash.h>

typedef uint64_t Hashed;

#line 1 "src/std/TypeId.pv"
typedef uint64_t TypeId;

#line 3 "src/std/TypeId.pv"
Hashed TypeId__Hash__hash(void* __self);

extern struct HashVTable TYPE_ID__VTABLE__HASH;

#endif
