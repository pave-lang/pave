#include <std/ArenaAllocator.h>
#include <std/Array_ForVariable.h>
#include <analyzer/ForVariable.h>
#include <std/Allocator.h>

#include <analyzer/ForStatement.h>

#line 42 "src/analyzer/Statement.pv"
struct ForStatement ForStatement__new(struct ArenaAllocator* allocator) {
    #line 43 "src/analyzer/Statement.pv"
    return (struct ForStatement) { .variables = Array_ForVariable__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator }) };
}
