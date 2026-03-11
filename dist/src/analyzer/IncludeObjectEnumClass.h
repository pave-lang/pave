#ifndef PAVE_INCLUDE_OBJECT_ENUM_CLASS
#define PAVE_INCLUDE_OBJECT_ENUM_CLASS

struct EnumC;
struct ClassCpp;

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#line 872 "src/analyzer/Include.pv"
struct IncludeObjectEnumClass {
    struct EnumC* enum_info;
    struct ClassCpp* class_info;
};

#endif
