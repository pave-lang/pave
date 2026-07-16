#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdlib.h>
#include <std/ArenaAllocator.h>
#include <std/trait_Allocator.h>
#include <std/GeneralPurposeAllocator.h>
#include <std/ArenaBlock.h>
#include <std/ArenaAlloc.h>
#include <std/test_ArenaAllocator__allocations_preserve_maximum_alignment.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__allocations_preserve_maximum_alignment() {
    #line 365 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator_ptr = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 366 "src/std/ArenaAllocator.pv"
    if (allocator_ptr == 0) {
        #line 366 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 367 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator* allocator = allocator_ptr;

    #line 369 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__guarded_backend()) {
        #line 370 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* block_ptr = allocator->last_block;
        #line 371 "src/std/ArenaAllocator.pv"
        if (block_ptr == 0) {
            #line 371 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 372 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* block = block_ptr;

        #line 374 "src/std/ArenaAllocator.pv"
        void* first = ArenaAllocator__Allocator__alloc(allocator, 1);
        #line 375 "src/std/ArenaAllocator.pv"
        if (first == 0) {
            #line 375 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 376 "src/std/ArenaAllocator.pv"
        uint8_t* first_bytes = first;
        #line 377 "src/std/ArenaAllocator.pv"
        uintptr_t first_offset = first_bytes - block->buffer;
        #line 378 "src/std/ArenaAllocator.pv"
        if (first_offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != first_offset) {
            #line 378 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 379 "src/std/ArenaAllocator.pv"
        if (block->offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != block->offset) {
            #line 379 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 381 "src/std/ArenaAllocator.pv"
        uintptr_t before_second = block->offset;
        #line 382 "src/std/ArenaAllocator.pv"
        void* second = ArenaAllocator__Allocator__alloc(allocator, sizeof(uintptr_t));
        #line 383 "src/std/ArenaAllocator.pv"
        if (second == 0) {
            #line 383 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 384 "src/std/ArenaAllocator.pv"
        uint8_t* second_bytes = second;
        #line 385 "src/std/ArenaAllocator.pv"
        uintptr_t second_offset = second_bytes - block->buffer;
        #line 386 "src/std/ArenaAllocator.pv"
        if (second_offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != second_offset) {
            #line 386 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 387 "src/std/ArenaAllocator.pv"
        if (block->offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != block->offset) {
            #line 387 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 389 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__realloc(allocator, second, 1) == 0) {
            #line 389 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 390 "src/std/ArenaAllocator.pv"
        if (!ArenaAllocator__Allocator__free(allocator, second)) {
            #line 390 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 391 "src/std/ArenaAllocator.pv"
        if (block->offset != before_second) {
            #line 391 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 393 "src/std/ArenaAllocator.pv"
        void* large = ArenaAllocator__Allocator__alloc(allocator, 300);
        #line 394 "src/std/ArenaAllocator.pv"
        if (large == 0) {
            #line 394 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 395 "src/std/ArenaAllocator.pv"
        struct ArenaAlloc* alloc_ptr = allocator->last_alloc;
        #line 396 "src/std/ArenaAllocator.pv"
        if (alloc_ptr == 0) {
            #line 396 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 397 "src/std/ArenaAllocator.pv"
        struct ArenaAlloc* alloc = alloc_ptr;
        #line 398 "src/std/ArenaAllocator.pv"
        void* alloc_void = alloc;
        #line 399 "src/std/ArenaAllocator.pv"
        if (alloc->data != large || alloc_void == large) {
            #line 399 "src/std/ArenaAllocator.pv"
            abort();
        }
    }

    #line 402 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(allocator);
}
