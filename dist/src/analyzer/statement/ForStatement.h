#ifndef PAVE_FOR_STATEMENT
#define PAVE_FOR_STATEMENT

#include <stdbool.h>

struct Expression;
struct Type;
struct Block;
#include <std/Array_ForVariable.h>
#include <analyzer/statement/ForStatementType.h>

#line 6 "src/analyzer/statement/ForStatement.pv"
struct ForStatement {
    struct Array_ForVariable variables;
    struct Expression* expression;
    struct ForStatementType type;
    struct Type* iter_type;
    struct Type* value_type;
    struct Block* block;
};

struct ArenaAllocator;
struct Context;
struct Array_ForVariable;
struct Block;
struct Generics;
struct ForStatement;
#include <analyzer/statement/ForStatement.h>

#line 16 "src/analyzer/statement/ForStatement.pv"
struct ForStatement ForStatement__new(struct ArenaAllocator* allocator);

#line 20 "src/analyzer/statement/ForStatement.pv"
bool ForStatement__parse_for_variable(struct Context* context, struct Array_ForVariable* variables);

#line 32 "src/analyzer/statement/ForStatement.pv"
struct ForStatement* ForStatement__parse(struct Block* parent_block, struct Context* context, struct Generics* generics);

#endif
