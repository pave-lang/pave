#include <stdint.h>

#include <stdlib.h>

#include <stdlib.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>

#include <std/GeneralPurposeAllocator.h>

#line 6 "src/std/GeneralPurposeAllocator.pv"
struct GeneralPurposeAllocator* GeneralPurposeAllocator__default() {
    #line 7 "src/std/GeneralPurposeAllocator.pv"
    static struct GeneralPurposeAllocator self = (struct GeneralPurposeAllocator) {};
    #line 8 "src/std/GeneralPurposeAllocator.pv"
    return &self;
}

#line 13 "src/std/GeneralPurposeAllocator.pv"
void* GeneralPurposeAllocator__Allocator__alloc(void* __self, uintptr_t size) {
    struct GeneralPurposeAllocator* self = __self; (void)self;
    #line 14 "src/std/GeneralPurposeAllocator.pv"
    return calloc(size, sizeof(uint8_t));
}

#line 17 "src/std/GeneralPurposeAllocator.pv"
void* GeneralPurposeAllocator__Allocator__realloc(void* __self, void* ptr, uintptr_t new_size) {
    struct GeneralPurposeAllocator* self = __self; (void)self;
    #line 18 "src/std/GeneralPurposeAllocator.pv"
    return realloc(ptr, new_size * sizeof(uint8_t));
}

#line 21 "src/std/GeneralPurposeAllocator.pv"
bool GeneralPurposeAllocator__Allocator__free(void* __self, void* ptr) {
    struct GeneralPurposeAllocator* self = __self; (void)self;
    #line 22 "src/std/GeneralPurposeAllocator.pv"
    free(ptr);

    #line 24 "src/std/GeneralPurposeAllocator.pv"
    return true;
}

struct trait_AllocatorVTable GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR = { .alloc = &GeneralPurposeAllocator__Allocator__alloc, .realloc = &GeneralPurposeAllocator__Allocator__realloc, .free = &GeneralPurposeAllocator__Allocator__free };
