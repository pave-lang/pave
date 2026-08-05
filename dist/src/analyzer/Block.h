#ifndef PAVE_BLOCK
#define PAVE_BLOCK

#include <stdbool.h>

#include <std/Array_Statement.h>
struct Context;

#line 8 "src/analyzer/Block.pv"
struct Block {
    struct Context* context;
    struct Array_Statement statements;
    bool is_top_level_and_has_defer_statements_inside;
    bool is_loop;
};

struct Context;
struct Generics;
struct StatementData;
struct Token;
struct Scope;

#line 16 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context);

#line 25 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context);

#line 30 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics, struct StatementData* data);

#line 62 "src/analyzer/Block.pv"
bool Block__parse_keyword(struct Block* self, struct Context* context, struct Generics* generics, struct Token* first_token, struct StatementData* data);

#line 131 "src/analyzer/Block.pv"
bool Block__parse_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 159 "src/analyzer/Block.pv"
struct Scope* Block__parse_preprocessor_branch(struct Block* self, struct Context* context, struct Generics* generics);

#line 184 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope);

#endif
