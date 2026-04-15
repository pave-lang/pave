#ifndef PAVE_SCOPE
#define PAVE_SCOPE

struct Block;
#include <std/HashMap_str_Type.h>

#line 4 "src/analyzer/Scope.pv"
struct Scope {
    struct HashMap_str_Type values;
    struct Block* block;
};

struct ArenaAllocator;
struct Block;
#include <analyzer/Scope.h>

#line 10 "src/analyzer/Scope.pv"
struct Scope Scope__new(struct ArenaAllocator* allocator, struct Block* block);

#endif
