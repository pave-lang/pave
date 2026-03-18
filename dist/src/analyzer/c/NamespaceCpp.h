#ifndef PAVE_NAMESPACE_CPP
#define PAVE_NAMESPACE_CPP

#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/Type.h>

struct Include;
struct ParentCpp;

#line 4 "src/analyzer/c/NamespaceCpp.pv"
struct NamespaceCpp {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};

#line 13 "src/analyzer/c/NamespaceCpp.pv"
struct NamespaceCpp* NamespaceCpp__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
