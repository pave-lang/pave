#ifndef PAVE_FOR_VARIABLE
#define PAVE_FOR_VARIABLE

#include <stdbool.h>

struct Token;
struct Type;

#line 3 "src/analyzer/statement/ForVariable.pv"
struct ForVariable {
    bool deref;
    bool ref;
    struct Token* name;
    struct Type* type;
};

#endif
