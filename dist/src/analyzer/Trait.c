#include <analyzer/Module.h>
#include <analyzer/Context.h>
#include <analyzer/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/Function.h>
#include <analyzer/Root.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <stdint.h>
#include <analyzer/FunctionParent.h>
#include <analyzer/Type.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>

#include <analyzer/Trait.h>

#line 14 "src/analyzer/Trait.pv"
struct Trait Trait__new(struct Module* module) {
    #line 15 "src/analyzer/Trait.pv"
    struct Context context = module->context;

    #line 17 "src/analyzer/Trait.pv"
    return (struct Trait) {
        .module = module,
        .generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .functions = HashMap_str_Function__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
    };
}

#line 24 "src/analyzer/Trait.pv"
struct Trait Trait__parse(struct Module* module) {
    #line 25 "src/analyzer/Trait.pv"
    struct Context* context = &module->context;
    #line 26 "src/analyzer/Trait.pv"
    struct Trait node = Trait__new(module);
    #line 27 "src/analyzer/Trait.pv"
    struct Generics* generics = &node.generics;

    #line 29 "src/analyzer/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "trait")) {
        #line 29 "src/analyzer/Trait.pv"
        return node;
    }

    #line 31 "src/analyzer/Trait.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 32 "src/analyzer/Trait.pv"
    if (name == 0) {
        #line 32 "src/analyzer/Trait.pv"
        return node;
    }

    #line 34 "src/analyzer/Trait.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(generics, context)) {
        #line 34 "src/analyzer/Trait.pv"
        return node;
    }

    #line 36 "src/analyzer/Trait.pv"
    node.token_start = context->pos;
    #line 37 "src/analyzer/Trait.pv"
    Context__skip_brackets(context, "{", "}");
    #line 38 "src/analyzer/Trait.pv"
    node.token_end = context->pos;

    #line 40 "src/analyzer/Trait.pv"
    node.name = name;

    #line 42 "src/analyzer/Trait.pv"
    return node;
}

#line 45 "src/analyzer/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent) {
    #line 46 "src/analyzer/Trait.pv"
    struct Context* context = &self->module->context;
    #line 47 "src/analyzer/Trait.pv"
    context->pos = self->token_start;

    #line 49 "src/analyzer/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 49 "src/analyzer/Trait.pv"
        return false;
    }

    #line 51 "src/analyzer/Trait.pv"
    while (context->pos < self->token_end - 1) {
        #line 52 "src/analyzer/Trait.pv"
        struct Function func_info = Function__parse_optional_body(context);
        #line 53 "src/analyzer/Trait.pv"
        if (func_info.name == 0) {
            #line 53 "src/analyzer/Trait.pv"
            return false;
        }

        #line 55 "src/analyzer/Trait.pv"
        func_info.parent = parent;

        #line 57 "src/analyzer/Trait.pv"
        HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);
    }

    #line 60 "src/analyzer/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 60 "src/analyzer/Trait.pv"
        return false;
    }

    #line 62 "src/analyzer/Trait.pv"
    return true;
}

#line 65 "src/analyzer/Trait.pv"
bool Trait__parse_functions(struct Trait* self) {
    #line 66 "src/analyzer/Trait.pv"
    struct Context* context = &self->module->context;
    #line 67 "src/analyzer/Trait.pv"
    context->type_self = &self->type_self;

    #line 69 "src/analyzer/Trait.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 69 "src/analyzer/Trait.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 69 "src/analyzer/Trait.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 70 "src/analyzer/Trait.pv"
        bool has_impl = function->token_start < function->token_end;
        #line 71 "src/analyzer/Trait.pv"
        if (!has_impl) {
            #line 71 "src/analyzer/Trait.pv"
            continue;
        }

        #line 73 "src/analyzer/Trait.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 76 "src/analyzer/Trait.pv"
    context->type_self = &context->root->type_self;

    #line 78 "src/analyzer/Trait.pv"
    return true;
}
