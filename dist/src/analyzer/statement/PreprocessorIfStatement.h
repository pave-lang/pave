#ifndef PAVE_PREPROCESSOR_IF_STATEMENT
#define PAVE_PREPROCESSOR_IF_STATEMENT

#include <stdbool.h>

#include <std/Array_ref_Token.h>
#include <std/Array_PreprocessorElseIf.h>
struct Token;
struct Block;

#line 10 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorIfStatement {
    struct Token* directive;
    struct Array_ref_Token condition;
    struct Block* block;
    struct Array_PreprocessorElseIf else_ifs;
    struct Block* else_block;
};

#include <std/Array_ref_Token.h>
struct Context;
struct Token;
struct Array_ref_Token;
struct Generics;
struct PreprocessorIfStatement;

#line 19 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct Array_ref_Token PreprocessorIfStatement__parse_condition(struct Context* context, struct Token* directive);

#line 31 "src/analyzer/statement/PreprocessorIfStatement.pv"
bool PreprocessorIfStatement__validate_condition(struct Context* context, struct Token* directive, struct Array_ref_Token* condition);

#line 43 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorIfStatement* PreprocessorIfStatement__parse(struct Context* context, struct Generics* generics);

#endif
