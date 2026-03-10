#ifndef PAVE_NAMESPACE_CPP
#define PAVE_NAMESPACE_CPP

#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>

struct Include;
struct NamespaceCpp;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 870 "src/analyzer/Include.pv"
struct NamespaceCpp {
    struct Include* include;
    struct str name;
    struct NamespaceCpp* parent;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};

#line 879 "src/analyzer/Include.pv"
struct NamespaceCpp* NamespaceCpp__new(struct Include* include, char const* name, struct NamespaceCpp* parent);

#endif
