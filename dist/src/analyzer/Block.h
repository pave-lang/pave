#ifndef PAVE_BLOCK
#define PAVE_BLOCK

#include <std/Array_Statement.h>
#include <analyzer/statement/Statement.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <stdbool.h>

struct Context;
struct Generics;
struct Array_ForVariable;
struct ForVariable;

#include <stdio.h>

#line 6 "src/analyzer/Block.pv"
struct Block {
    struct Context* context;
    struct Array_Statement statements;
    struct Array_DeferStatement defer_statements;
    bool is_top_level_and_has_defer_statements_inside;
    bool is_loop;
};

#line 15 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context);

#line 23 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context);

#line 27 "src/analyzer/Block.pv"
bool Block__parse_let_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 75 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 98 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 119 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 143 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 183 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 359 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 375 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables);

#line 387 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 515 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 546 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope);

#endif
