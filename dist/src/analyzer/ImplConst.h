#ifndef PAVE_IMPL_CONST
#define PAVE_IMPL_CONST

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/Type.h>
struct Token;
struct Expression;
struct Context;

#line 5 "src/analyzer/Impl.pv"
struct ImplConst {
    struct Token* name;
    struct Type type;
    struct Expression* value;
    struct Context* context;
    uintptr_t token_start;
    uintptr_t token_end;
};

struct ImplConst;

#line 15 "src/analyzer/Impl.pv"
bool ImplConst__parse_types(struct ImplConst* self);

#endif
