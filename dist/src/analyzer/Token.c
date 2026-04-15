#include <stdint.h>

#include <stdio.h>

#include <std/str.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>

#include <analyzer/Token.h>

#include <analyzer/Token.h>

#line 39 "src/analyzer/Token.pv"
bool Token__eq(struct Token* self, enum TokenType type, char const* value) {
    #line 40 "src/analyzer/Token.pv"
    struct str v = self->value;

    #line 42 "src/analyzer/Token.pv"
    return (self->type == type) && str__eq(v, (struct str){ .ptr = value, .length = strlen(value) });
}

#line 45 "src/analyzer/Token.pv"
void Token__print(struct Token* self, char const* path, char const* message) {
    #line 46 "src/analyzer/Token.pv"
    fprintf(stderr, "%s:%zu:%zu %s\n", path, self->start_line + 1, self->start_column + 1, message);
}
