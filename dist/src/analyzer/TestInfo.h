#ifndef PAVE_TEST_INFO
#define PAVE_TEST_INFO

#include <std/str.h>
struct Token;

#line 7 "src/analyzer/Module.pv"
struct TestInfo {
    struct Token* description;
    struct str func_name;
};

#endif
