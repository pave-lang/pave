#ifndef PAVE_SCOPE
#define PAVE_SCOPE

#include <std/HashMap_str_Type.h>
struct Block;

#line 4 "src/analyzer/Scope.pv"
struct Scope {
    struct HashMap_str_Type values;
    struct Block* block;
};

#include <analyzer/Scope.h>
struct ArenaAllocator;
struct Block;

#line 10 "src/analyzer/Scope.pv"
struct Scope Scope__new(struct ArenaAllocator* allocator, struct Block* block);

#endif
