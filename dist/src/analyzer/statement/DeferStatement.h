#ifndef PAVE_DEFER_STATEMENT
#define PAVE_DEFER_STATEMENT

struct Expression;
struct Block;

#line 4 "src/analyzer/statement/DeferStatement.pv"
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

#endif
