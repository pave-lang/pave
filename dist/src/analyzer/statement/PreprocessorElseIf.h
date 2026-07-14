#ifndef PAVE_PREPROCESSOR_ELSE_IF
#define PAVE_PREPROCESSOR_ELSE_IF

#include <std/Array_ref_Token.h>
struct Block;

#line 5 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorElseIf {
    struct Array_ref_Token condition;
    struct Block* block;
};

#endif
