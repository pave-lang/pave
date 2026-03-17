#ifndef PAVE_GENERATOR_INCLUDE
#define PAVE_GENERATOR_INCLUDE

#include <std/str.h>

struct Type;

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#line 156 "src/compiler/Generator.pv"
struct GeneratorInclude {
    struct Type* type;
    struct str name;
};

#endif
