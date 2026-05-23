#ifndef PAVE_TOKEN_BOUNDS
#define PAVE_TOKEN_BOUNDS

struct Token;

#line 38 "src/analyzer/Token.pv"
struct TokenBounds {
    struct Token* first;
    struct Token* last;
};

#include <analyzer/TokenBounds.h>
struct Token;
struct TokenBounds;

#line 44 "src/analyzer/Token.pv"
struct TokenBounds TokenBounds__new(struct Token* first, struct Token* last);

#line 48 "src/analyzer/Token.pv"
void TokenBounds__include(struct TokenBounds* self, struct TokenBounds bounds);

#endif
