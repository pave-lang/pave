#ifndef PAVE_MATCH_CASE
#define PAVE_MATCH_CASE

#include <analyzer/MatchPattern.h>

struct Token;
struct Type;
struct Block;

#line 10 "src/analyzer/Statement.pv"
struct MatchCase {
    struct Token* first_token;
    struct MatchPattern pattern;
    struct Type* type;
    struct Block* body;
};

#endif
