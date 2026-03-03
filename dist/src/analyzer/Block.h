#ifndef PAVE_BLOCK
#define PAVE_BLOCK

#include <std/Array_Statement.h>
#include <analyzer/Statement.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/DeferStatement.h>
#include <stdbool.h>

struct Context;
struct Generics;
struct Array_ForVariable;
struct ForVariable;

#include <stdio.h>

#line 5 "src/analyzer/Block.pv"
struct Block {
    struct Context* context;
    struct Array_Statement statements;
    struct Array_DeferStatement defer_statements;
    bool is_top_level_and_has_defer_statements_inside;
    bool is_loop;
};

#line 14 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context);

#line 22 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context);

#line 26 "src/analyzer/Block.pv"
bool Block__parse_let_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 88 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 124 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 158 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 195 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 235 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 384 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 400 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables);

#line 412 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 540 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics);

#line 571 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope);

#endif
