#ifndef PAVE_MATCH_CASE
#define PAVE_MATCH_CASE

#include <std/Array_MatchPattern.h>
#include <analyzer/statement/MatchPattern.h>
#include <stdbool.h>

struct Token;
struct Block;
struct Context;
struct Generics;

#line 7 "src/analyzer/statement/MatchCase.pv"
struct MatchCase {
    struct Token* first_token;
    struct Array_MatchPattern patterns;
    struct Block* body;
};

#line 14 "src/analyzer/statement/MatchCase.pv"
bool MatchCase__parse(struct MatchCase* self, struct Context* context, struct Generics* generics);

#endif
