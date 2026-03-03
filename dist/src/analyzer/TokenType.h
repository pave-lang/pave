#ifndef PAVE_TOKEN_TYPE
#define PAVE_TOKEN_TYPE

#include <stdio.h>

#line 5 "src/analyzer/Token.pv"
enum TokenType {
    TOKEN_TYPE__SYMBOL,
    TOKEN_TYPE__IDENTIFIER,
    TOKEN_TYPE__STRING,
    TOKEN_TYPE__NUMBER,
    TOKEN_TYPE__KEYWORD,
    TOKEN_TYPE__COMMENT,
};

#line 15 "src/analyzer/Token.pv"
char const* TokenType__get_name(enum TokenType* self);

#endif
