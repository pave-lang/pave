#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <analyzer/types/Trait.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/TokenType.h>
#include <analyzer/Token.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generic.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionParent.h>
#include <std/String.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/Root.h>
#include <analyzer/types/Trait.h>

#include <analyzer/types/Trait.h>

#line 17 "src/analyzer/types/Trait.pv"
struct Trait Trait__new(struct Module* module) {
    #line 18 "src/analyzer/types/Trait.pv"
    struct Context context = module->context;

    #line 20 "src/analyzer/types/Trait.pv"
    return (struct Trait) {
        .module = module,
        .generics = Generics__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .functions = HashMap_str_Function__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .typedefs = HashMap_str_usize__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context.allocator }),
        .name = 0,
        .token_start = 0,
        .token_end = 0,
        .generic_arity = 0,
        .type_self = (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = 0 },
    };
}

#line 33 "src/analyzer/types/Trait.pv"
struct Trait Trait__parse(struct Module* module) {
    #line 34 "src/analyzer/types/Trait.pv"
    struct Context* context = &module->context;
    #line 35 "src/analyzer/types/Trait.pv"
    struct Trait node = Trait__new(module);
    #line 36 "src/analyzer/types/Trait.pv"
    struct Generics* generics = &node.generics;

    #line 38 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "trait")) {
        #line 38 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 40 "src/analyzer/types/Trait.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 41 "src/analyzer/types/Trait.pv"
    if (name == 0) {
        #line 41 "src/analyzer/types/Trait.pv"
        return node;
    }

    #line 43 "src/analyzer/types/Trait.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(generics, context)) {
        #line 43 "src/analyzer/types/Trait.pv"
        return node;
    }
    #line 44 "src/analyzer/types/Trait.pv"
    node.generic_arity = generics->array.length;

    #line 46 "src/analyzer/types/Trait.pv"
    node.token_start = context->pos;
    #line 47 "src/analyzer/types/Trait.pv"
    Context__skip_brackets(context, "{", "}");
    #line 48 "src/analyzer/types/Trait.pv"
    node.token_end = context->pos;

    #line 50 "src/analyzer/types/Trait.pv"
    node.name = name;

    #line 52 "src/analyzer/types/Trait.pv"
    return node;
}

#line 55 "src/analyzer/types/Trait.pv"
bool Trait__fill_types(struct Trait* self, struct FunctionParent parent) {
    #line 56 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 57 "src/analyzer/types/Trait.pv"
    context->pos = self->token_start;

    #line 59 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 59 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 61 "src/analyzer/types/Trait.pv"
    while (context->pos < self->token_end - 1) {
        #line 62 "src/analyzer/types/Trait.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "typedef")) {
            #line 63 "src/analyzer/types/Trait.pv"
            Context__next_token(context);
            #line 64 "src/analyzer/types/Trait.pv"
            struct Token* typedef_name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 65 "src/analyzer/types/Trait.pv"
            if (typedef_name == 0) {
                #line 65 "src/analyzer/types/Trait.pv"
                return false;
            }
            #line 66 "src/analyzer/types/Trait.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 66 "src/analyzer/types/Trait.pv"
                return false;
            }

            #line 68 "src/analyzer/types/Trait.pv"
            struct Generic generic = Generic__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 69 "src/analyzer/types/Trait.pv"
            generic.name = typedef_name;
            #line 70 "src/analyzer/types/Trait.pv"
            uintptr_t index = Array_Generic__append(&self->generics.array, generic);
            #line 71 "src/analyzer/types/Trait.pv"
            HashMap_str_usize__insert(&self->generics.map, typedef_name->value, index);
            #line 72 "src/analyzer/types/Trait.pv"
            HashMap_str_usize__insert(&self->typedefs, typedef_name->value, index);
        } else {
            #line 74 "src/analyzer/types/Trait.pv"
            struct Function func_info = Function__parse_optional_body(context);
            #line 75 "src/analyzer/types/Trait.pv"
            if (func_info.name == 0) {
                #line 75 "src/analyzer/types/Trait.pv"
                return false;
            }

            #line 77 "src/analyzer/types/Trait.pv"
            func_info.parent = parent;

            #line 79 "src/analyzer/types/Trait.pv"
            HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);
        }
    }

    #line 83 "src/analyzer/types/Trait.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 83 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 85 "src/analyzer/types/Trait.pv"
    return true;
}

#line 88 "src/analyzer/types/Trait.pv"
struct str Trait__get_key(struct Trait* self, struct trait_Allocator allocator) {
    #line 89 "src/analyzer/types/Trait.pv"
    struct Token* name = self->name;
    #line 90 "src/analyzer/types/Trait.pv"
    if (name == 0) {
        #line 90 "src/analyzer/types/Trait.pv"
        return (struct str){ .ptr = "", .length = strlen("") };
    }

    #line 92 "src/analyzer/types/Trait.pv"
    struct String key = String__new(allocator);
    #line 93 "src/analyzer/types/Trait.pv"
    String__append(&key, name->value);
    #line 94 "src/analyzer/types/Trait.pv"
    String__append(&key, (struct str){ .ptr = "#", .length = strlen("#") });
    #line 95 "src/analyzer/types/Trait.pv"
    String__append_usize(&key, self->generic_arity);
    #line 96 "src/analyzer/types/Trait.pv"
    return String__as_str(&key);
}

#line 99 "src/analyzer/types/Trait.pv"
bool Trait__has_dynamic_dispatch(struct Trait* self) {
    #line 100 "src/analyzer/types/Trait.pv"
    if (self->typedefs.length != 0) {
        #line 100 "src/analyzer/types/Trait.pv"
        return false;
    }

    #line 102 "src/analyzer/types/Trait.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 102 "src/analyzer/types/Trait.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 102 "src/analyzer/types/Trait.pv"
        struct Function* func = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 103 "src/analyzer/types/Trait.pv"
        if (func->parameters.length == 0) {
            #line 103 "src/analyzer/types/Trait.pv"
            continue;
        }
        #line 104 "src/analyzer/types/Trait.pv"
        struct Parameter* first_param = Array_Parameter__get(&func->parameters, 0);
        #line 105 "src/analyzer/types/Trait.pv"
        if (first_param == 0) {
            #line 105 "src/analyzer/types/Trait.pv"
            continue;
        }
        #line 106 "src/analyzer/types/Trait.pv"
        if (Type__is_self(&first_param->type)) {
            #line 106 "src/analyzer/types/Trait.pv"
            return false;
        }
    } }

    #line 109 "src/analyzer/types/Trait.pv"
    return true;
}

#line 112 "src/analyzer/types/Trait.pv"
bool Trait__parse_functions(struct Trait* self) {
    #line 113 "src/analyzer/types/Trait.pv"
    struct Context* context = &self->module->context;
    #line 114 "src/analyzer/types/Trait.pv"
    context->type_self = &self->type_self;

    #line 116 "src/analyzer/types/Trait.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 116 "src/analyzer/types/Trait.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 116 "src/analyzer/types/Trait.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 117 "src/analyzer/types/Trait.pv"
        bool has_impl = function->token_start < function->token_end;
        #line 118 "src/analyzer/types/Trait.pv"
        if (!has_impl) {
            #line 118 "src/analyzer/types/Trait.pv"
            continue;
        }

        #line 120 "src/analyzer/types/Trait.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 123 "src/analyzer/types/Trait.pv"
    context->type_self = &context->root->type_self;

    #line 125 "src/analyzer/types/Trait.pv"
    return true;
}
