#ifndef PAVE_TRAIT_ALLOCATOR
#define PAVE_TRAIT_ALLOCATOR

#include <stdint.h>
#include <stdbool.h>

#include <std/trait_Allocator.h>

#line 1 "src/std/Allocator.pv"
struct trait_AllocatorVTable {
        #line 2 "src/std/Allocator.pv"
void* (*alloc)(void* __self, uintptr_t size);
        #line 3 "src/std/Allocator.pv"
void* (*realloc)(void* __self, void* ptr, uintptr_t new_size);
        #line 4 "src/std/Allocator.pv"
bool (*free)(void* __self, void* ptr);
};

#line 1 "src/std/Allocator.pv"
struct trait_Allocator {
    const struct trait_AllocatorVTable* vtable;
    void* instance;
};

#endif
