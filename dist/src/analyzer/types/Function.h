#ifndef PAVE_FUNCTION
#define PAVE_FUNCTION

#include <stdint.h>
#include <stdbool.h>

#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/Generics.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Type.h>
struct Token;
struct Context;
struct Block;

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
    bool is_test;
};

#include <analyzer/types/Function.h>
#include <std/trait_Allocator.h>
struct Context;
struct Function;
struct Generics;

#line 44 "src/analyzer/types/Function.pv"
struct Function Function__new(struct Context* context);

#line 52 "src/analyzer/types/Function.pv"
struct Function Function__new_allocator(struct trait_Allocator allocator);

#line 59 "src/analyzer/types/Function.pv"
struct Function Function__parse(struct Context* context);

#line 63 "src/analyzer/types/Function.pv"
struct Function Function__parse_optional_body(struct Context* context);

#line 67 "src/analyzer/types/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional);

#line 103 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics);

#line 164 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics);

#line 175 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics);

#line 198 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics);

#endif
