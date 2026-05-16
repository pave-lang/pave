#ifndef PAVE_BLOCK
#define PAVE_BLOCK

#include <stdbool.h>

#include <std/Array_Statement.h>
#include <std/Array_DeferStatement.h>
struct Context;

#line 8 "src/analyzer/Block.pv"
struct Block {
    struct Context* context;
    struct Array_Statement statements;
    struct Array_DeferStatement defer_statements;
    bool is_top_level_and_has_defer_statements_inside;
    bool is_loop;
};

#include <analyzer/Block.h>
struct Context;
struct Block;
struct Generics;
struct StatementData;
struct Token;

#line 17 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context);

#line 27 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context);

#line 32 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics, struct StatementData* data);

#line 56 "src/analyzer/Block.pv"
bool Block__parse_keyword(struct Block* self, struct Context* context, struct Generics* generics, struct Token* first_token, struct StatementData* data);

#line 110 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope);

#endif
