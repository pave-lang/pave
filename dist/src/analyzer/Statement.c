#include <analyzer/Token.h>
#include <analyzer/StatementData.h>

#include <analyzer/Statement.h>

#line 83 "src/analyzer/Statement.pv"
struct Statement Statement__new(struct Token* first_token, struct Token* last_token, struct StatementData data) {
    #line 84 "src/analyzer/Statement.pv"
    return (struct Statement) { .first_token = first_token, .last_token = last_token, .data = data };
}
