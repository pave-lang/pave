#include <analyzer/statement/Statement.h>
#include <analyzer/Token.h>
#include <analyzer/TokenBounds.h>
#include <analyzer/statement/Statement.h>

#include <analyzer/statement/Statement.h>

#line 10 "src/analyzer/statement/Statement.pv"
struct Statement Statement__new(struct Token* first_token, struct Token* last_token, struct StatementData data) {
    #line 11 "src/analyzer/statement/Statement.pv"
    return (struct Statement) { .first_token = first_token, .last_token = last_token, .data = data };
}

#line 14 "src/analyzer/statement/Statement.pv"
struct TokenBounds Statement__get_token_bounds(struct Statement* self) {
    #line 15 "src/analyzer/statement/Statement.pv"
    return TokenBounds__new(self->first_token, self->last_token);
}
