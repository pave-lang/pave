#ifndef PAVE_FOR_STATEMENT
#define PAVE_FOR_STATEMENT

#include <std/Array_ForVariable.h>
#include <analyzer/ForVariable.h>
#include <analyzer/ForStatementType.h>

struct Expression;
struct Type;
struct Block;
struct ArenaAllocator;

#line 31 "src/analyzer/Statement.pv"
struct ForStatement {
    struct Array_ForVariable variables;
    struct Expression* expression;
    struct ForStatementType type;
    struct Type* iter_type;
    struct Type* value_type;
    struct Block* block;
};

#line 41 "src/analyzer/Statement.pv"
struct ForStatement ForStatement__new(struct ArenaAllocator* allocator);

#endif
