#ifndef PAVE_PARENT_CPP
#define PAVE_PARENT_CPP

#include <stdbool.h>

struct ClassCpp;
struct NamespaceCpp;
#line 1 "src/analyzer/c/ParentCpp.pv"
struct ParentCpp {
    enum {
        PARENT_CPP__NONE,
        PARENT_CPP__CLASS,
        PARENT_CPP__NAMESPACE,
    } type;

    union {
        struct ClassCpp* class_value;
        struct NamespaceCpp* namespace_value;
    };
};

struct ParentCpp;

#line 8 "src/analyzer/c/ParentCpp.pv"
bool ParentCpp__is_none(struct ParentCpp* self);

#endif
