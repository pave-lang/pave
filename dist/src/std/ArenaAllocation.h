#ifndef PAVE_ARENA_ALLOCATION
#define PAVE_ARENA_ALLOCATION

#include <stdint.h>

#line 143 "src/std/ArenaAllocator.pv"
struct ArenaAllocation {
    uintptr_t size;
    uintptr_t start_offset;
    uintptr_t end_offset;
};

#endif
