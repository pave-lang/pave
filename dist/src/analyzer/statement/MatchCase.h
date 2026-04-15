#ifndef PAVE_MATCH_CASE
#define PAVE_MATCH_CASE

#include <stdbool.h>

struct Token;
struct Block;
#include <std/Array_MatchPattern.h>

#line 7 "src/analyzer/statement/MatchCase.pv"
struct MatchCase {
    struct Token* first_token;
    struct Array_MatchPattern patterns;
    struct Block* body;
};
struct MatchCase;
struct Context;
struct Generics;


#line 14 "src/analyzer/statement/MatchCase.pv"
bool MatchCase__parse(struct MatchCase* self, struct Context* context, struct Generics* generics);

#endif
