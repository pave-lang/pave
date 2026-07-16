#ifndef PAVE_ARENA_ALLOC
#define PAVE_ARENA_ALLOC

#include <stdint.h>

struct ArenaAlloc;

#line 20 "src/std/ArenaAllocator.pv"
struct ArenaAlloc {
    uintptr_t size;
    void* data;
    struct ArenaAlloc* prev;
};

#endif
