#ifndef PAVE_STATEMENT
#define PAVE_STATEMENT

struct Token;
#include <analyzer/statement/StatementData.h>

#line 3 "src/analyzer/statement/Statement.pv"
struct Statement {
    struct Token* first_token;
    struct Token* last_token;
    struct StatementData data;
};

struct Token;
#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/Statement.h>

#line 10 "src/analyzer/statement/Statement.pv"
struct Statement Statement__new(struct Token* first_token, struct Token* last_token, struct StatementData data);

#endif
