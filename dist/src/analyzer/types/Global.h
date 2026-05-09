#ifndef PAVE_GLOBAL
#define PAVE_GLOBAL

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/Type.h>
struct Token;
struct Expression;
struct Module;

#line 5 "src/analyzer/types/Global.pv"
struct Global {
    struct Token* name;
    struct Type type;
    struct Expression* value;
    struct Module* module;
    uintptr_t token_start;
    uintptr_t token_end;
    bool is_const;
};

struct Global;

#line 16 "src/analyzer/types/Global.pv"
bool Global__parse_types(struct Global* self);

#endif
