#ifndef PAVE_ARENA_OVERSIZE
#define PAVE_ARENA_OVERSIZE

#include <stdint.h>

struct ArenaOversize;

#line 24 "src/std/ArenaAllocator.pv"
struct ArenaOversize {
    uintptr_t size;
    void* data;
    struct ArenaOversize* prev;
};

#endif
