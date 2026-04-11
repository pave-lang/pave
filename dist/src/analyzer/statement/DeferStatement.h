#ifndef PAVE_DEFER_STATEMENT
#define PAVE_DEFER_STATEMENT

struct Expression;
struct Block;
struct DeferStatement;
struct Context;
struct Generics;

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

#line 11 "src/analyzer/statement/DeferStatement.pv"
struct DeferStatement* DeferStatement__parse(struct Block* parent_block, struct Context* context, struct Generics* generics);

#endif
