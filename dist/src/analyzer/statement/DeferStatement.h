#ifndef PAVE_DEFER_STATEMENT
#define PAVE_DEFER_STATEMENT

struct Expression;
struct Block;
#line 5 "src/analyzer/statement/DeferStatement.pv"
struct DeferStatement {
    enum {
        DEFER_STATEMENT__EXPRESSION,
        DEFER_STATEMENT__BLOCK,
    } type;

    union {
        struct Expression* expression_value;
        struct Block* block_value;
    };
};

struct Context;
struct Generics;
struct DeferStatement;

#line 11 "src/analyzer/statement/DeferStatement.pv"
struct DeferStatement* DeferStatement__parse(struct Block* parent_block, struct Context* context, struct Generics* generics);

#endif
