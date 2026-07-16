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
#include <std/ArenaOversize.h>
#include <std/test_ArenaAllocator__allocations_preserve_maximum_alignment.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__allocations_preserve_maximum_alignment() {
    #line 346 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 347 "src/std/ArenaAllocator.pv"
    struct ArenaBlock* block = allocator.last_block;
    #line 348 "src/std/ArenaAllocator.pv"
    if (block != 0) {
        #line 349 "src/std/ArenaAllocator.pv"
        void* first = ArenaAllocator__Allocator__alloc(&allocator, 1);
        #line 350 "src/std/ArenaAllocator.pv"
        if (first == 0) {
            #line 350 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 351 "src/std/ArenaAllocator.pv"
        uint8_t* first_bytes = first;
        #line 352 "src/std/ArenaAllocator.pv"
        uintptr_t first_offset = first_bytes - block->buffer;
        #line 353 "src/std/ArenaAllocator.pv"
        if (first_offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != first_offset) {
            #line 353 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 354 "src/std/ArenaAllocator.pv"
        if (block->offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != block->offset) {
            #line 354 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 356 "src/std/ArenaAllocator.pv"
        uintptr_t before_second = block->offset;
        #line 357 "src/std/ArenaAllocator.pv"
        void* second = ArenaAllocator__Allocator__alloc(&allocator, sizeof(uintptr_t));
        #line 358 "src/std/ArenaAllocator.pv"
        if (second == 0) {
            #line 358 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 359 "src/std/ArenaAllocator.pv"
        uint8_t* second_bytes = second;
        #line 360 "src/std/ArenaAllocator.pv"
        uintptr_t second_offset = second_bytes - block->buffer;
        #line 361 "src/std/ArenaAllocator.pv"
        if (second_offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != second_offset) {
            #line 361 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 362 "src/std/ArenaAllocator.pv"
        if (block->offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != block->offset) {
            #line 362 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 364 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__realloc(&allocator, second, 1) == 0) {
            #line 364 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 365 "src/std/ArenaAllocator.pv"
        if (!ArenaAllocator__Allocator__free(&allocator, second)) {
            #line 365 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 366 "src/std/ArenaAllocator.pv"
        if (block->offset != before_second) {
            #line 366 "src/std/ArenaAllocator.pv"
            abort();
        }
    } else {
        #line 367 "src/std/ArenaAllocator.pv"
        abort();
    }

    #line 369 "src/std/ArenaAllocator.pv"
    void* large = ArenaAllocator__Allocator__alloc(&allocator, 300);
    #line 370 "src/std/ArenaAllocator.pv"
    if (large == 0) {
        #line 370 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 371 "src/std/ArenaAllocator.pv"
    struct ArenaOversize* oversize = allocator.last_oversize;
    #line 372 "src/std/ArenaAllocator.pv"
    if (oversize != 0) {
        #line 373 "src/std/ArenaAllocator.pv"
        uint8_t* large_bytes = large;
        #line 374 "src/std/ArenaAllocator.pv"
        void* oversize_void = oversize;
        #line 375 "src/std/ArenaAllocator.pv"
        uint8_t* oversize_bytes = oversize_void;
        #line 376 "src/std/ArenaAllocator.pv"
        uintptr_t data_offset = large_bytes - oversize_bytes;
        #line 377 "src/std/ArenaAllocator.pv"
        if (data_offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != data_offset) {
            #line 377 "src/std/ArenaAllocator.pv"
            abort();
        }
    } else {
        #line 378 "src/std/ArenaAllocator.pv"
        abort();
    }

    #line 380 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(&allocator);
}
