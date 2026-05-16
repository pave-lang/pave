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

#line 28 "src/analyzer/types/Function.pv"
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

#include <analyzer/types/Function.h>
#include <std/trait_Allocator.h>
struct Context;
struct Function;
struct Generics;

#line 44 "src/analyzer/types/Function.pv"
struct Function Function__new(struct Context* context);

#line 61 "src/analyzer/types/Function.pv"
struct Function Function__new_allocator(struct trait_Allocator allocator);

#line 78 "src/analyzer/types/Function.pv"
struct Function Function__parse(struct Context* context);

#line 82 "src/analyzer/types/Function.pv"
struct Function Function__parse_optional_body(struct Context* context);

#line 86 "src/analyzer/types/Function.pv"
struct Function Function__parse_inner(struct Context* context, bool body_optional);

#line 122 "src/analyzer/types/Function.pv"
bool Function__parse_parameters(struct Function* self, struct Generics* generics);

#line 184 "src/analyzer/types/Function.pv"
bool Function__parse_return_type(struct Function* self, struct Generics* generics);

#line 195 "src/analyzer/types/Function.pv"
bool Function__fill_types(struct Function* self, struct Generics* generics);

#line 218 "src/analyzer/types/Function.pv"
bool Function__parse_function(struct Function* self, struct Generics* generics);

#endif
