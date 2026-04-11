#ifndef PAVE_ASSIGNMENT_STATEMENT
#define PAVE_ASSIGNMENT_STATEMENT

struct Expression;
struct Token;

#line 4 "src/analyzer/statement/AssignmentStatement.pv"
struct AssignmentStatement {
    struct Expression* left;
    struct Token* operator;
    struct Expression* right;
};

#endif
