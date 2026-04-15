#ifndef PAVE_NAMESPACE_CPP
#define PAVE_NAMESPACE_CPP

struct Include;
#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_Type.h>

#line 4 "src/analyzer/c/NamespaceCpp.pv"
struct NamespaceCpp {
    struct Include* include;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_Type types;
    struct HashMap_str_Type values;
};
struct Include;
struct NamespaceCpp;
#include <analyzer/c/ParentCpp.h>


#line 13 "src/analyzer/c/NamespaceCpp.pv"
struct NamespaceCpp* NamespaceCpp__new(struct Include* include, char const* name, struct ParentCpp parent);

#endif
