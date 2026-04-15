#ifndef PAVE_GENERAL_PURPOSE_ALLOCATOR
#define PAVE_GENERAL_PURPOSE_ALLOCATOR

#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>

#line 3 "src/std/GeneralPurposeAllocator.pv"
struct GeneralPurposeAllocator {
};
struct GeneralPurposeAllocator;


#line 6 "src/std/GeneralPurposeAllocator.pv"
struct GeneralPurposeAllocator* GeneralPurposeAllocator__default();

#line 13 "src/std/GeneralPurposeAllocator.pv"
void* GeneralPurposeAllocator__Allocator__alloc(void* __self, uintptr_t size);

#line 17 "src/std/GeneralPurposeAllocator.pv"
void* GeneralPurposeAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size);

#line 21 "src/std/GeneralPurposeAllocator.pv"
bool GeneralPurposeAllocator__Allocator__free(void* __self, void* ptr);

extern struct trait_AllocatorVTable GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR;

#endif
