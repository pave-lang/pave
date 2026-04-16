#ifndef PAVE_GENERATOR_INCLUDE
#define PAVE_GENERATOR_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <std/str.h>
struct Type;

#line 158 "src/compiler/Generator.pv"
struct GeneratorInclude {
    struct Type* type;
    struct str name;
};

#endif
