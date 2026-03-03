#ifndef PAVE_ARENA_OVERSIZE
#define PAVE_ARENA_OVERSIZE

#include <stdint.h>

struct ArenaOversize;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#line 20 "src/std/ArenaAllocator.pv"
struct ArenaOversize {
    uintptr_t size;
    struct ArenaOversize* prev;
};

#endif
