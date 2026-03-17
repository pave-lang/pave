#include <analyzer/Token.h>
#include <analyzer/statement/StatementData.h>

#include <analyzer/statement/Statement.h>

#line 10 "src/analyzer/statement/Statement.pv"
struct Statement Statement__new(struct Token* first_token, struct Token* last_token, struct StatementData data) {
    #line 11 "src/analyzer/statement/Statement.pv"
    return (struct Statement) { .first_token = first_token, .last_token = last_token, .data = data };
}
