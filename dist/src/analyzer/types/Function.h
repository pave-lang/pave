#ifndef PAVE_FUNCTION
#define PAVE_FUNCTION

#include <stdint.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/Generics.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/types/Type.h>
#include <std/Allocator.h>
#include <stdbool.h>

struct Token;
struct Context;
struct Block;
struct Function;
struct Generics;

#include <stdio.h>

#line 27 "src/analyzer/types/Function.pv"
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

#line 43 "src/analyzer/types/Function.pv"
struct Function Function__new(struct Context* context);

#line 51 "src/analyzer/types/Function.pv"
struct Function Function__new_allocator(struct Allocator allocator);

#line 58 "src/analyzer/types/Function.pv"
struct Function Function__parse(struct Context* context);

#line 62 "src/analyzer/types/Function.pv"
struct Function Function__parse_optional_body(struct Context* context);

#line 66 "src/analyzer/types/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional);

#line 102 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics);

#line 163 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics);

#line 174 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics);

#line 192 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics);

#endif
