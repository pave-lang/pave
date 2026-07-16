#ifndef PAVE_ARENA_STATE
#define PAVE_ARENA_STATE

#include <stdint.h>

#include <std/trait_Allocator.h>
struct ArenaBlock;
struct ArenaOversize;

#line 10 "src/std/ArenaAllocator.pv"
struct ArenaState {
    struct trait_Allocator allocator;
    uintptr_t block_size;
    struct ArenaBlock* last_block;
    struct ArenaOversize* last_oversize;
};

#endif
