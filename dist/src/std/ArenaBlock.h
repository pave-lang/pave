#ifndef PAVE_ARENA_BLOCK
#define PAVE_ARENA_BLOCK

#include <stdint.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArenaBlock;

#line 12 "src/std/ArenaAllocator.pv"
struct ArenaBlock {
    uint8_t* buffer;
    uintptr_t capacity;
    uintptr_t offset;
    struct ArenaBlock* prev;
};
struct ArenaBlock;
#include <std/trait_Allocator.h>


#line 25 "src/std/ArenaAllocator.pv"
struct ArenaBlock* ArenaBlock__new(struct trait_Allocator allocator, uintptr_t capacity, struct ArenaBlock* prev);

#line 39 "src/std/ArenaAllocator.pv"
void* ArenaBlock__alloc(struct ArenaBlock* self, uintptr_t size);

#line 58 "src/std/ArenaAllocator.pv"
bool ArenaBlock__is_in_block(struct ArenaBlock* self, void* ptr);

#line 64 "src/std/ArenaAllocator.pv"
uintptr_t ArenaBlock__size(struct ArenaBlock* self, void* ptr);

#line 73 "src/std/ArenaAllocator.pv"
bool ArenaBlock__free(struct ArenaBlock* self, void* ptr);

#line 91 "src/std/ArenaAllocator.pv"
void ArenaBlock__destroy(struct ArenaBlock* self, struct trait_Allocator allocator);

#line 95 "src/std/ArenaAllocator.pv"
void* ArenaBlock__realloc(struct ArenaBlock* self, void* ptr, uintptr_t size);

#endif
