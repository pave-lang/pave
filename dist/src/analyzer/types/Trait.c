#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/types/Trait.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <analyzer/types/Generic.h>
#include <std/Array_Generic.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionParent.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <analyzer/Root.h>
#include <analyzer/types/Trait.h>

#include <analyzer/types/Trait.h>

#line 16 "src/analyzer/types/Trait.pv"
struct Trait Trait__new(struct Module* module) {
    #line 17 "src/analyzer/types/Trait.pv"
    struct Context context = module->context;

    #line 19 "src/analyzer/types/Trait.pv"
    return (struct Trait) {
        .module = module,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .typedefs = HashMap_str_usize__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .name = 0,
        .token_start = 0,
        .token_end = 0,
        .type_self = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
    };
}

#line 31 "src/analyzer/types/Trait.pv"
struct Trait Trait__parse(struct Module* module) {
    #line 32 "src/analyzer/types/Trait.pv"
    struct Context* context = &module->context;
    #line 33 "src/analyzer/types/Trait.pv"
    struct Trait node = Trait__new(module);
    #line 34 "src/analyzer/types/Trait.pv"
    struct Generics* generics = &node.generics;

    #line 36 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "trait")) {
        #line 36 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 38 "src/analyzer/types/Trait.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 39 "src/analyzer/types/Trait.pv"
    if (name == 0) {
        #line 39 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 41 "src/analyzer/types/Trait.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(generics, context)) {
        #line 41 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 43 "src/analyzer/types/Trait.pv"
    node.token_start = context->pos;
    #line 44 "src/analyzer/types/Trait.pv"
    Context__skip_brackets(context, "{", "}");
    #line 45 "src/analyzer/types/Trait.pv"
    node.token_end = context->pos;

    #line 47 "src/analyzer/types/Trait.pv"
    node.name = name;

    #line 49 "src/analyzer/types/Trait.pv"
    return node;
}

#line 52 "src/analyzer/types/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent) {
    #line 53 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 54 "src/analyzer/types/Trait.pv"
    context->pos = self->token_start;

    #line 56 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 56 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 58 "src/analyzer/types/Trait.pv"
    while (context->pos < self->token_end - 1) {
        #line 59 "src/analyzer/types/Trait.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "typedef")) {
            #line 60 "src/analyzer/types/Trait.pv"
            Context__next_token(context);
            #line 61 "src/analyzer/types/Trait.pv"
            struct Token* typedef_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 62 "src/analyzer/types/Trait.pv"
            if (typedef_name == 0) {
                #line 62 "src/analyzer/types/Trait.pv"
                return false;
            }
            #line 63 "src/analyzer/types/Trait.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 63 "src/analyzer/types/Trait.pv"
                return false;
            }

            #line 65 "src/analyzer/types/Trait.pv"
            struct Generic generic = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 66 "src/analyzer/types/Trait.pv"
            generic.name = typedef_name;
            #line 67 "src/analyzer/types/Trait.pv"
            uintptr_t index = Array_Generic__append(&self->generics.array, generic);
            #line 68 "src/analyzer/types/Trait.pv"
            HashMap_str_usize__insert(&self->generics.map, typedef_name->value, index);
            #line 69 "src/analyzer/types/Trait.pv"
            HashMap_str_usize__insert(&self->typedefs, typedef_name->value, index);
        } else {
            #line 71 "src/analyzer/types/Trait.pv"
            struct Function func_info = Function__parse_optional_body(context);
            #line 72 "src/analyzer/types/Trait.pv"
            if (func_info.name == 0) {
                #line 72 "src/analyzer/types/Trait.pv"
                return false;
            }

            #line 74 "src/analyzer/types/Trait.pv"
            func_info.parent = parent;

            #line 76 "src/analyzer/types/Trait.pv"
            HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);
        }
    }

    #line 80 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 80 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 82 "src/analyzer/types/Trait.pv"
    return true;
}

#line 85 "src/analyzer/types/Trait.pv"
bool Trait__has_dynamic_dispatch(struct Trait* self) {
    #line 86 "src/analyzer/types/Trait.pv"
    return self->typedefs.length == 0;
}

#line 89 "src/analyzer/types/Trait.pv"
bool Trait__parse_functions(struct Trait* self) {
    #line 90 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 91 "src/analyzer/types/Trait.pv"
    context->type_self = &self->type_self;

    #line 93 "src/analyzer/types/Trait.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 93 "src/analyzer/types/Trait.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 93 "src/analyzer/types/Trait.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 94 "src/analyzer/types/Trait.pv"
        bool has_impl = function->token_start < function->token_end;
        #line 95 "src/analyzer/types/Trait.pv"
        if (!has_impl) {
            #line 95 "src/analyzer/types/Trait.pv"
            continue;
        }

        #line 97 "src/analyzer/types/Trait.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 100 "src/analyzer/types/Trait.pv"
    context->type_self = &context->root->type_self;

    #line 102 "src/analyzer/types/Trait.pv"
    return true;
}
