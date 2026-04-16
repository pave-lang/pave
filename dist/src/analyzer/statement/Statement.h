#ifndef PAVE_STATEMENT
#define PAVE_STATEMENT

#include <analyzer/statement/StatementData.h>
struct Token;

#line 3 "src/analyzer/statement/Statement.pv"
struct Statement {
    struct Token* first_token;
    struct Token* last_token;
    struct StatementData data;
};

#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/Statement.h>
struct Token;

#line 10 "src/analyzer/statement/Statement.pv"
struct Statement Statement__new(struct Token* first_token, struct Token* last_token, struct StatementData data);

#endif
