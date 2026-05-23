#ifndef PAVE_ASSIGNMENT_STATEMENT
#define PAVE_ASSIGNMENT_STATEMENT

#include <stdbool.h>

struct Expression;
struct Token;

#line 6 "src/analyzer/statement/AssignmentStatement.pv"
struct AssignmentStatement {
    struct Expression* left;
    struct Token* operator;
    struct Expression* right;
};

struct Context;
struct Type;
struct Expression;

#line 13 "src/analyzer/statement/AssignmentStatement.pv"
struct Type* AssignmentStatement__make_pointer_type_for_reference_assignment(struct Context* context, struct Type* left_type, struct Expression* right);

#line 44 "src/analyzer/statement/AssignmentStatement.pv"
bool AssignmentStatement__validate_and_update_scope(struct Context* context, struct Expression* left, struct Expression* right);

#endif
