#include <std/Hashed.h>
#include <std/TypeId.h>
#include <std/TypeId.h>

#include <std/TypeId.h>

#line 3 "src/std/TypeId.pv"
Hashed TypeId__Hash__hash(void* __self) {
    TypeId* self = __self; (void)self;
    #line 3 "src/std/TypeId.pv"
    return (*self);
}

struct trait_HashVTable TYPE_ID__VTABLE__HASH = { .hash = &TypeId__Hash__hash };
