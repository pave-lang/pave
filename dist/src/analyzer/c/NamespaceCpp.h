#ifndef PAVE_NAMESPACE_CPP
#define PAVE_NAMESPACE_CPP

#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_Type.h>
struct Include;

#line 4 "src/analyzer/c/NamespaceCpp.pv"
struct NamespaceCpp {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};

#include <analyzer/c/ParentCpp.h>
struct Include;
struct NamespaceCpp;

#line 13 "src/analyzer/c/NamespaceCpp.pv"
struct NamespaceCpp* NamespaceCpp__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
