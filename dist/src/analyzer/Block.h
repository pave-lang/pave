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

#line 7 "src/analyzer/Block.pv"
struct Block {
    struct Context* context;
    struct Array_Statement statements;
    struct Array_DeferStatement defer_statements;
    bool is_top_level_and_has_defer_statements_inside;
    bool is_loop;
};

#line 16 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context);

#line 24 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context);

#line 28 "src/analyzer/Block.pv"
bool Block__parse_let_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 76 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 99 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 120 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 144 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 184 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 360 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 376 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables);

#line 388 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 516 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 547 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope);

#endif
