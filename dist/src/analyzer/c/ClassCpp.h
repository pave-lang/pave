#ifndef PAVE_CLASS_CPP
#define PAVE_CLASS_CPP

#include <stdbool.h>

#include <std/str.h>
#include <analyzer/c/ParentCpp.h>
#include <std/HashMap_str_Type.h>
#include <std/Array_Type.h>
struct Include;

#line 4 "src/analyzer/c/ClassCpp.pv"
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

#include <analyzer/c/ParentCpp.h>
struct Include;
struct ClassCpp;

#line 16 "src/analyzer/c/ClassCpp.pv"
struct ClassCpp* ClassCpp__new(struct Include* include, char const* name, struct ParentCpp parent, bool is_struct);

#endif
