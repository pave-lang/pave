#ifndef PAVE_CLASS_CPP
#define PAVE_CLASS_CPP

#include <stdbool.h>
#include <std/str.h>
#include <analyzer/ParentCpp.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Type.h>
#include <std/Array_Type.h>

struct Include;
struct ParentCpp;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 944 "src/analyzer/Include.pv"
struct ClassCpp {
    struct Include* include;
    bool is_struct;
    struct str name;
    struct ParentCpp parent;
    struct HashMap_str_Type fields;
    struct HashMap_str_Type values;
    struct HashMap_str_Type types;
    struct Array_Type bases;
};

#line 956 "src/analyzer/Include.pv"
struct ClassCpp* ClassCpp__new(struct Include* include, char const* name, struct ParentCpp parent, bool is_struct);

#endif
