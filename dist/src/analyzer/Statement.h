#ifndef PAVE_STATEMENT
#define PAVE_STATEMENT

#include <analyzer/StatementData.h>

struct Token;
struct StatementData;

#line 75 "src/analyzer/Statement.pv"
struct Statement {
    struct Token* first_token;
    struct Token* last_token;
    struct StatementData data;
};

#line 82 "src/analyzer/Statement.pv"
struct Statement Statement__new(struct Token* first_token, struct Token* last_token, struct StatementData data);

#endif
