#include <analyzer/Module.h>
#include <analyzer/Context.h>
#include <analyzer/types/Generics.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <analyzer/Root.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Type.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>

#include <analyzer/types/Trait.h>

#line 15 "src/analyzer/types/Trait.pv"
struct Trait Trait__new(struct Module* module) {
    #line 16 "src/analyzer/types/Trait.pv"
    struct Context context = module->context;

    #line 18 "src/analyzer/types/Trait.pv"
    return (struct Trait) {
        .module = module,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
    };
}

#line 25 "src/analyzer/types/Trait.pv"
struct Trait Trait__parse(struct Module* module) {
    #line 26 "src/analyzer/types/Trait.pv"
    struct Context* context = &module->context;
    #line 27 "src/analyzer/types/Trait.pv"
    struct Trait node = Trait__new(module);
    #line 28 "src/analyzer/types/Trait.pv"
    struct Generics* generics = &node.generics;

    #line 30 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "trait")) {
        #line 30 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 32 "src/analyzer/types/Trait.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 33 "src/analyzer/types/Trait.pv"
    if (name == 0) {
        #line 33 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 35 "src/analyzer/types/Trait.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(generics, context)) {
        #line 35 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 37 "src/analyzer/types/Trait.pv"
    node.token_start = context->pos;
    #line 38 "src/analyzer/types/Trait.pv"
    Context__skip_brackets(context, "{", "}");
    #line 39 "src/analyzer/types/Trait.pv"
    node.token_end = context->pos;

    #line 41 "src/analyzer/types/Trait.pv"
    node.name = name;

    #line 43 "src/analyzer/types/Trait.pv"
    return node;
}

#line 46 "src/analyzer/types/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent) {
    #line 47 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 48 "src/analyzer/types/Trait.pv"
    context->pos = self->token_start;

    #line 50 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 50 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 52 "src/analyzer/types/Trait.pv"
    while (context->pos < self->token_end - 1) {
        #line 53 "src/analyzer/types/Trait.pv"
        struct Function func_info = Function__parse_optional_body(context);
        #line 54 "src/analyzer/types/Trait.pv"
        if (func_info.name == 0) {
            #line 54 "src/analyzer/types/Trait.pv"
            return false;
        }

        #line 56 "src/analyzer/types/Trait.pv"
        func_info.parent = parent;

        #line 58 "src/analyzer/types/Trait.pv"
        HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);
    }

    #line 61 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 61 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 63 "src/analyzer/types/Trait.pv"
    return true;
}

#line 66 "src/analyzer/types/Trait.pv"
bool Trait__parse_functions(struct Trait* self) {
    #line 67 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 68 "src/analyzer/types/Trait.pv"
    context->type_self = &self->type_self;

    #line 70 "src/analyzer/types/Trait.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 70 "src/analyzer/types/Trait.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 70 "src/analyzer/types/Trait.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 71 "src/analyzer/types/Trait.pv"
        bool has_impl = function->token_start < function->token_end;
        #line 72 "src/analyzer/types/Trait.pv"
        if (!has_impl) {
            #line 72 "src/analyzer/types/Trait.pv"
            continue;
        }

        #line 74 "src/analyzer/types/Trait.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 77 "src/analyzer/types/Trait.pv"
    context->type_self = &context->root->type_self;

    #line 79 "src/analyzer/types/Trait.pv"
    return true;
}
