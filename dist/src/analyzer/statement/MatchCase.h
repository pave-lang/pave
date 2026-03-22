#ifndef PAVE_MATCH_CASE
#define PAVE_MATCH_CASE

#include <std/Array_MatchPattern.h>
#include <analyzer/statement/MatchPattern.h>

struct Token;
struct Block;

#line 5 "src/analyzer/statement/MatchCase.pv"
struct MatchCase {
    struct Token* first_token;
    struct Array_MatchPattern patterns;
    struct Block* body;
};

#endif
