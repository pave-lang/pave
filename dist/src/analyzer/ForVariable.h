#ifndef PAVE_FOR_VARIABLE
#define PAVE_FOR_VARIABLE

#include <stdbool.h>

struct Token;
struct Type;

#line 55 "src/analyzer/Statement.pv"
struct ForVariable {
    bool deref;
    bool ref;
    struct Token* name;
    struct Type* type;
};

#endif
