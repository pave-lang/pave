#ifndef PAVE_CLASS_CPP
#define PAVE_CLASS_CPP

#include <stdbool.h>
#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/Array_Type.h>

struct Include;
struct NamespaceCpp;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 811 "src/analyzer/Include.pv"
struct ClassCpp {
    struct Include* include;
    bool is_struct;
    struct str name;
    struct HashMap_str_Type fields;
    struct HashMap_str_Type values;
    struct NamespaceCpp* namespace;
    struct Array_Type bases;
};

#line 822 "src/analyzer/Include.pv"
struct ClassCpp* ClassCpp__new(struct Include* include, char const* name, struct NamespaceCpp* namespace, bool is_struct);

#endif
