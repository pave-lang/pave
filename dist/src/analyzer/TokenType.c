#include <stdio.h>

#include <analyzer/TokenType.h>
#include <analyzer/TokenType.h>

#include <analyzer/TokenType.h>

#line 15 "src/analyzer/Token.pv"
char const* TokenType__get_name(enum TokenType* self) {
    #line 16 "src/analyzer/Token.pv"
    switch (*self) {
        #line 17 "src/analyzer/Token.pv"
        case TOKEN_TYPE__SYMBOL: {
            #line 17 "src/analyzer/Token.pv"
            return "Symbol";
        } break;
        #line 18 "src/analyzer/Token.pv"
        case TOKEN_TYPE__IDENTIFIER: {
            #line 18 "src/analyzer/Token.pv"
            return "Identifier";
        } break;
        #line 19 "src/analyzer/Token.pv"
        case TOKEN_TYPE__STRING: {
            #line 19 "src/analyzer/Token.pv"
            return "String";
        } break;
        #line 20 "src/analyzer/Token.pv"
        case TOKEN_TYPE__NUMBER: {
            #line 20 "src/analyzer/Token.pv"
            return "Number";
        } break;
        #line 21 "src/analyzer/Token.pv"
        case TOKEN_TYPE__KEYWORD: {
            #line 21 "src/analyzer/Token.pv"
            return "Keyword";
        } break;
        #line 22 "src/analyzer/Token.pv"
        case TOKEN_TYPE__COMMENT: {
            #line 22 "src/analyzer/Token.pv"
            return "Comment";
        } break;
    }

    #line 25 "src/analyzer/Token.pv"
    return "Unknown";
}
