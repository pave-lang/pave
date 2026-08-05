#ifndef PAVE_TOKEN
#define PAVE_TOKEN

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/TokenType.h>
#include <std/str.h>

#line 29 "src/analyzer/Token.pv"
struct Token {
    enum TokenType type;
    struct str value;
    uintptr_t start_line;
    uintptr_t start_column;
    uintptr_t end_line;
    uintptr_t end_column;
};

#include <analyzer/TokenType.h>

#line 60 "src/analyzer/Token.pv"
bool Token__eq(struct Token* self, enum TokenType type, char const* value);

#line 66 "src/analyzer/Token.pv"
void Token__print(struct Token* self, char const* path, char const* message);

#endif
