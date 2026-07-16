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
#include <std/ArenaState.h>
#include <std/ArenaBlock.h>
#include <std/ArenaOversize.h>
#include <std/test_ArenaAllocator__allocations_preserve_maximum_alignment.test.h>

#line 1 "src/std/ArenaAllocator.pv"
void test_ArenaAllocator__allocations_preserve_maximum_alignment() {
    #line 380 "src/std/ArenaAllocator.pv"
    struct ArenaAllocator allocator = ArenaAllocator__new((struct trait_Allocator) { .vtable = &GENERAL_PURPOSE_ALLOCATOR__VTABLE__ALLOCATOR, .instance = GeneralPurposeAllocator__default() }, 1024);
    #line 381 "src/std/ArenaAllocator.pv"
    struct ArenaState* state_ptr = allocator.state;
    #line 382 "src/std/ArenaAllocator.pv"
    if (state_ptr == 0) {
        #line 382 "src/std/ArenaAllocator.pv"
        abort();
    }
    #line 383 "src/std/ArenaAllocator.pv"
    struct ArenaState* state = state_ptr;

    #line 385 "src/std/ArenaAllocator.pv"
    if (!ArenaAllocator__guarded_backend()) {
        #line 386 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* block_ptr = state->last_block;
        #line 387 "src/std/ArenaAllocator.pv"
        if (block_ptr == 0) {
            #line 387 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 388 "src/std/ArenaAllocator.pv"
        struct ArenaBlock* block = block_ptr;

        #line 390 "src/std/ArenaAllocator.pv"
        void* first = ArenaAllocator__Allocator__alloc(&allocator, 1);
        #line 391 "src/std/ArenaAllocator.pv"
        if (first == 0) {
            #line 391 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 392 "src/std/ArenaAllocator.pv"
        uint8_t* first_bytes = first;
        #line 393 "src/std/ArenaAllocator.pv"
        uintptr_t first_offset = first_bytes - block->buffer;
        #line 394 "src/std/ArenaAllocator.pv"
        if (first_offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != first_offset) {
            #line 394 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 395 "src/std/ArenaAllocator.pv"
        if (block->offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != block->offset) {
            #line 395 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 397 "src/std/ArenaAllocator.pv"
        uintptr_t before_second = block->offset;
        #line 398 "src/std/ArenaAllocator.pv"
        void* second = ArenaAllocator__Allocator__alloc(&allocator, sizeof(uintptr_t));
        #line 399 "src/std/ArenaAllocator.pv"
        if (second == 0) {
            #line 399 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 400 "src/std/ArenaAllocator.pv"
        uint8_t* second_bytes = second;
        #line 401 "src/std/ArenaAllocator.pv"
        uintptr_t second_offset = second_bytes - block->buffer;
        #line 402 "src/std/ArenaAllocator.pv"
        if (second_offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != second_offset) {
            #line 402 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 403 "src/std/ArenaAllocator.pv"
        if (block->offset / ArenaAllocator__alignment() * ArenaAllocator__alignment() != block->offset) {
            #line 403 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 405 "src/std/ArenaAllocator.pv"
        if (ArenaAllocator__Allocator__realloc(&allocator, second, 1) == 0) {
            #line 405 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 406 "src/std/ArenaAllocator.pv"
        if (!ArenaAllocator__Allocator__free(&allocator, second)) {
            #line 406 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 407 "src/std/ArenaAllocator.pv"
        if (block->offset != before_second) {
            #line 407 "src/std/ArenaAllocator.pv"
            abort();
        }

        #line 409 "src/std/ArenaAllocator.pv"
        void* large = ArenaAllocator__Allocator__alloc(&allocator, 300);
        #line 410 "src/std/ArenaAllocator.pv"
        if (large == 0) {
            #line 410 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 411 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* oversize_ptr = state->last_oversize;
        #line 412 "src/std/ArenaAllocator.pv"
        if (oversize_ptr == 0) {
            #line 412 "src/std/ArenaAllocator.pv"
            abort();
        }
        #line 413 "src/std/ArenaAllocator.pv"
        struct ArenaOversize* oversize = oversize_ptr;
        #line 414 "src/std/ArenaAllocator.pv"
        void* oversize_void = oversize;
        #line 415 "src/std/ArenaAllocator.pv"
        if (oversize->data != large || oversize_void == large) {
            #line 415 "src/std/ArenaAllocator.pv"
            abort();
        }
    }

    #line 418 "src/std/ArenaAllocator.pv"
    ArenaAllocator__destroy(&allocator);
}
