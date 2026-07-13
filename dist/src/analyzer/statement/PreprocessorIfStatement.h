#ifndef PAVE_PREPROCESSOR_IF_STATEMENT
#define PAVE_PREPROCESSOR_IF_STATEMENT

#include <std/Array_ref_Token.h>
struct Block;

#line 5 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorIfStatement {
    struct Array_ref_Token condition;
    struct Block* block;
    struct Block* else_block;
};

struct Context;
struct Generics;
struct PreprocessorIfStatement;

#line 12 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorIfStatement* PreprocessorIfStatement__parse(struct Context* context, struct Generics* generics);

#endif
