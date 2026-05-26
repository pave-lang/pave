#ifndef PAVE_DESTRUCTURE_BINDING
#define PAVE_DESTRUCTURE_BINDING

struct Token;
struct Type;

#line 6 "src/analyzer/statement/LetStatement.pv"
struct DestructureBinding {
    struct Token* name;
    struct Type* type;
};

#endif
