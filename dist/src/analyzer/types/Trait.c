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
    };
}

#line 27 "src/analyzer/types/Trait.pv"
struct Trait Trait__parse(struct Module* module) {
    #line 28 "src/analyzer/types/Trait.pv"
    struct Context* context = &module->context;
    #line 29 "src/analyzer/types/Trait.pv"
    struct Trait node = Trait__new(module);
    #line 30 "src/analyzer/types/Trait.pv"
    struct Generics* generics = &node.generics;

    #line 32 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "trait")) {
        #line 32 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 34 "src/analyzer/types/Trait.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 35 "src/analyzer/types/Trait.pv"
    if (name == 0) {
        #line 35 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 37 "src/analyzer/types/Trait.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(generics, context)) {
        #line 37 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 39 "src/analyzer/types/Trait.pv"
    node.token_start = context->pos;
    #line 40 "src/analyzer/types/Trait.pv"
    Context__skip_brackets(context, "{", "}");
    #line 41 "src/analyzer/types/Trait.pv"
    node.token_end = context->pos;

    #line 43 "src/analyzer/types/Trait.pv"
    node.name = name;

    #line 45 "src/analyzer/types/Trait.pv"
    return node;
}

#line 48 "src/analyzer/types/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent) {
    #line 49 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 50 "src/analyzer/types/Trait.pv"
    context->pos = self->token_start;

    #line 52 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 52 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 54 "src/analyzer/types/Trait.pv"
    while (context->pos < self->token_end - 1) {
        #line 55 "src/analyzer/types/Trait.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "typedef")) {
            #line 56 "src/analyzer/types/Trait.pv"
            Context__next_token(context);
            #line 57 "src/analyzer/types/Trait.pv"
            struct Token* typedef_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 58 "src/analyzer/types/Trait.pv"
            if (typedef_name == 0) {
                #line 58 "src/analyzer/types/Trait.pv"
                return false;
            }
            #line 59 "src/analyzer/types/Trait.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 59 "src/analyzer/types/Trait.pv"
                return false;
            }

            #line 61 "src/analyzer/types/Trait.pv"
            struct Generic generic = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 62 "src/analyzer/types/Trait.pv"
            generic.name = typedef_name;
            #line 63 "src/analyzer/types/Trait.pv"
            uintptr_t index = Array_Generic__append(&self->generics.array, generic);
            #line 64 "src/analyzer/types/Trait.pv"
            HashMap_str_usize__insert(&self->generics.map, typedef_name->value, index);
            #line 65 "src/analyzer/types/Trait.pv"
            HashMap_str_usize__insert(&self->typedefs, typedef_name->value, index);
        } else {
            #line 67 "src/analyzer/types/Trait.pv"
            struct Function func_info = Function__parse_optional_body(context);
            #line 68 "src/analyzer/types/Trait.pv"
            if (func_info.name == 0) {
                #line 68 "src/analyzer/types/Trait.pv"
                return false;
            }

            #line 70 "src/analyzer/types/Trait.pv"
            func_info.parent = parent;

            #line 72 "src/analyzer/types/Trait.pv"
            HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);
        }
    }

    #line 76 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 76 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 78 "src/analyzer/types/Trait.pv"
    return true;
}

#line 81 "src/analyzer/types/Trait.pv"
bool Trait__has_dynamic_dispatch(struct Trait* self) {
    #line 82 "src/analyzer/types/Trait.pv"
    return self->typedefs.length == 0;
}

#line 85 "src/analyzer/types/Trait.pv"
bool Trait__parse_functions(struct Trait* self) {
    #line 86 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 87 "src/analyzer/types/Trait.pv"
    context->type_self = &self->type_self;

    #line 89 "src/analyzer/types/Trait.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 89 "src/analyzer/types/Trait.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 89 "src/analyzer/types/Trait.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 90 "src/analyzer/types/Trait.pv"
        bool has_impl = function->token_start < function->token_end;
        #line 91 "src/analyzer/types/Trait.pv"
        if (!has_impl) {
            #line 91 "src/analyzer/types/Trait.pv"
            continue;
        }

        #line 93 "src/analyzer/types/Trait.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 96 "src/analyzer/types/Trait.pv"
    context->type_self = &context->root->type_self;

    #line 98 "src/analyzer/types/Trait.pv"
    return true;
}
