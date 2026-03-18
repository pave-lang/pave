#ifndef PAVE_PARENT_CPP
#define PAVE_PARENT_CPP

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <stdbool.h>

struct ClassCpp;
struct NamespaceCpp;

#line 859 "src/analyzer/Include.pv"
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

#line 866 "src/analyzer/Include.pv"
bool ParentCpp__is_none(struct ParentCpp* self);

#endif
