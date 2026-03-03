#ifndef PAVE_ARENA_BLOCK
#define PAVE_ARENA_BLOCK

#include <std/Allocator.h>
#include <stdint.h>
#include <stdbool.h>

struct ArenaBlock;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#line 12 "src/std/ArenaAllocator.pv"
struct ArenaBlock {
    struct Allocator allocator;
    uint8_t* buffer;
    uintptr_t capacity;
    uintptr_t offset;
    struct ArenaBlock* prev;
};

#line 26 "src/std/ArenaAllocator.pv"
struct ArenaBlock* ArenaBlock__new(struct Allocator allocator, uintptr_t capacity, struct ArenaBlock* prev);

#line 40 "src/std/ArenaAllocator.pv"
void* ArenaBlock__alloc(struct ArenaBlock* self, uintptr_t size);

#line 59 "src/std/ArenaAllocator.pv"
bool ArenaBlock__is_in_block(struct ArenaBlock* self, void* ptr);

#line 65 "src/std/ArenaAllocator.pv"
uintptr_t ArenaBlock__size(struct ArenaBlock* self, void* ptr);

#line 74 "src/std/ArenaAllocator.pv"
bool ArenaBlock__free(struct ArenaBlock* self, void* ptr);

#line 92 "src/std/ArenaAllocator.pv"
void ArenaBlock__destroy(struct ArenaBlock* self, struct Allocator allocator);

#line 96 "src/std/ArenaAllocator.pv"
void* ArenaBlock__realloc(struct ArenaBlock* self, void* ptr, uintptr_t size);

#endif
