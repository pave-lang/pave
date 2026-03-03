#ifndef PAVE_FUNCTION
#define PAVE_FUNCTION

#include <stdint.h>
#include <analyzer/FunctionParent.h>
#include <analyzer/FunctionType.h>
#include <analyzer/Generics.h>
#include <std/Array_Parameter.h>
#include <analyzer/Parameter.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>
#include <stdbool.h>

struct Token;
struct Context;
struct Block;
struct Function;
struct Generics;

#include <stdio.h>

#line 26 "src/analyzer/Function.pv"
struct Function {
    struct Token* name;
    struct Context* context;
    uintptr_t declaration_start;
    uintptr_t declaration_end;
    uintptr_t token_start;
    uintptr_t token_end;
    struct FunctionParent parent;
    enum FunctionType type;
    struct Generics generics;
    struct Array_Parameter parameters;
    struct Type return_type;
    struct Block* body;
};

#line 42 "src/analyzer/Function.pv"
struct Function Function__new(struct Context* context);

#line 50 "src/analyzer/Function.pv"
struct Function Function__new_allocator(struct Allocator allocator);

#line 57 "src/analyzer/Function.pv"
struct Function Function__parse(struct Context* context);

#line 61 "src/analyzer/Function.pv"
struct Function Function__parse_optional_body(struct Context* context);

#line 65 "src/analyzer/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional);

#line 101 "src/analyzer/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics);

#line 162 "src/analyzer/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics);

#line 170 "src/analyzer/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics);

#line 188 "src/analyzer/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics);

#endif
