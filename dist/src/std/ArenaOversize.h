#ifndef PAVE_ARENA_OVERSIZE
#define PAVE_ARENA_OVERSIZE

#include <stdint.h>

struct ArenaOversize;

#line 19 "src/std/ArenaAllocator.pv"
struct ArenaOversize {
    uintptr_t size;
    struct ArenaOversize* prev;
};

#endif
