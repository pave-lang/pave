#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/TypedefC.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <analyzer/c/TypedefC.h>

#include <analyzer/c/TypedefC.h>

#line 11 "src/analyzer/c/TypedefC.pv"
struct TypedefC* TypedefC__new(struct Include* include, char const* name, struct Type* type) {
    #line 12 "src/analyzer/c/TypedefC.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 14 "src/analyzer/c/TypedefC.pv"
    return ArenaAllocator__store_TypedefC(allocator, (struct TypedefC) {
        .include = include,
        .name = (struct str){ .ptr = name, .length = strlen(name) },
        .type = type,
    });
}
