#ifndef PAVE_PARSED_ARGUMENTS
#define PAVE_PARSED_ARGUMENTS

#include <std/Array_InvokeArgument.h>
#include <std/Array_Position.h>
struct Token;

#line 5 "src/analyzer/expression/ParseCallArguments.pv"
struct ParsedArguments {
    struct Array_InvokeArgument arguments;
    struct Token* open_paren;
    struct Token* close_paren;
    struct Array_Position comma_positions;
};

#endif
