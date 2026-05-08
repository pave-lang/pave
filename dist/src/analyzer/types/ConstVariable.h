#ifndef PAVE_CONST_VARIABLE
#define PAVE_CONST_VARIABLE

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/Type.h>
struct Token;
struct Expression;
struct Module;

#line 5 "src/analyzer/types/ConstVariable.pv"
struct ConstVariable {
    struct Token* name;
    struct Type type;
    struct Expression* value;
    struct Module* module;
    uintptr_t token_start;
    uintptr_t token_end;
};

struct ConstVariable;

#line 15 "src/analyzer/types/ConstVariable.pv"
bool ConstVariable__parse_types(struct ConstVariable* self);

#endif
