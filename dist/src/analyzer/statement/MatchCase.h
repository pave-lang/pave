#ifndef PAVE_MATCH_CASE
#define PAVE_MATCH_CASE

#include <analyzer/statement/MatchPattern.h>

struct Token;
struct Type;
struct Block;

#line 4 "src/analyzer/statement/MatchCase.pv"
struct MatchCase {
    struct Token* first_token;
    struct MatchPattern pattern;
    struct Type* type;
    struct Block* body;
};

#endif
