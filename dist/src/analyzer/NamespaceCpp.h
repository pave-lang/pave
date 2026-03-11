#ifndef PAVE_NAMESPACE_CPP
#define PAVE_NAMESPACE_CPP

#include <std/str.h>
#include <analyzer/ParentCpp.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>

struct Include;
struct ParentCpp;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 990 "src/analyzer/Include.pv"
struct NamespaceCpp {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};

#line 999 "src/analyzer/Include.pv"
struct NamespaceCpp* NamespaceCpp__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
