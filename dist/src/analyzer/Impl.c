#include <analyzer/Root.h>
#include <analyzer/Context.h>
#include <analyzer/Token.h>
#include <analyzer/types/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_ImplNode.h>
#include <analyzer/ImplNode.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/types/Function.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/FunctionParent.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>

#include <analyzer/Impl.h>

#line 24 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context) {
    #line 25 "src/analyzer/Impl.pv"
    struct Impl node = (struct Impl) {
        .context = context,
        .token = Context__current(context),
        .generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .nodes = Array_ImplNode__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .functions = HashMap_str_Function__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };

    #line 33 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "impl")) {
        #line 33 "src/analyzer/Impl.pv"
        return node;
    }

    #line 35 "src/analyzer/Impl.pv"
    node.token_start = context->pos;
    #line 36 "src/analyzer/Impl.pv"
    Impl__skip_to_open_brace(&node);
    #line 37 "src/analyzer/Impl.pv"
    Context__skip_brackets(context, "{", "}");
    #line 38 "src/analyzer/Impl.pv"
    node.token_end = context->pos;

    #line 40 "src/analyzer/Impl.pv"
    return node;
}

#line 43 "src/analyzer/Impl.pv"
bool Impl__skip_to_open_brace(struct Impl* self) {
    #line 44 "src/analyzer/Impl.pv"
    struct Context* context = self->context;

    #line 46 "src/analyzer/Impl.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 47 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 48 "src/analyzer/Impl.pv"
            self->has_trait = true;
        }

        #line 51 "src/analyzer/Impl.pv"
        Context__next_token(context);
    }

    #line 54 "src/analyzer/Impl.pv"
    return Context__check_value(context, TOKEN_TYPE__SYMBOL, "{");
}

#line 57 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self) {
    #line 58 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 59 "src/analyzer/Impl.pv"
    context->pos = self->token_start;

    #line 61 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->generics, context)) {
        #line 61 "src/analyzer/Impl.pv"
        return false;
    }

    #line 63 "src/analyzer/Impl.pv"
    if (self->has_trait) {
        #line 64 "src/analyzer/Impl.pv"
        if (!Context__parse_type_trait(context, &self->trait_type, &self->generics)) {
            #line 64 "src/analyzer/Impl.pv"
            return false;
        }

        #line 66 "src/analyzer/Impl.pv"
        switch (self->trait_type.type) {
            #line 67 "src/analyzer/Impl.pv"
            case TYPE__TRAIT: {
                #line 67 "src/analyzer/Impl.pv"
                struct Trait* trait_info = self->trait_type.trait_value._0;
                #line 68 "src/analyzer/Impl.pv"
                self->trait_ = trait_info;
                #line 69 "src/analyzer/Impl.pv"
                self->trait_name = trait_info->name;
            } break;
            #line 71 "src/analyzer/Impl.pv"
            default: {
                #line 72 "src/analyzer/Impl.pv"
                Context__error(context, "Expected trait type in impl declaration");
                #line 73 "src/analyzer/Impl.pv"
                return false;
            } break;
        }

        #line 77 "src/analyzer/Impl.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
            #line 77 "src/analyzer/Impl.pv"
            return false;
        }
    }

    #line 80 "src/analyzer/Impl.pv"
    if (!Context__parse_type(context, &self->type, &self->generics)) {
        #line 80 "src/analyzer/Impl.pv"
        return false;
    }

    #line 82 "src/analyzer/Impl.pv"
    self->token_start = context->pos;

    #line 84 "src/analyzer/Impl.pv"
    return true;
}

#line 87 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent) {
    #line 88 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 89 "src/analyzer/Impl.pv"
    context->pos = self->token_start;
    #line 90 "src/analyzer/Impl.pv"
    struct Array_ImplNode* nodes = &self->nodes;

    #line 92 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 92 "src/analyzer/Impl.pv"
        return false;
    }

    #line 94 "src/analyzer/Impl.pv"
    Context__skip_comments(context);

    #line 96 "src/analyzer/Impl.pv"
    while (context->pos < self->token_end - 1) {
        #line 97 "src/analyzer/Impl.pv"
        struct Function func_info = Function__parse(context);
        #line 98 "src/analyzer/Impl.pv"
        func_info.parent = parent;
        #line 99 "src/analyzer/Impl.pv"
        if (func_info.name == 0) {
            #line 99 "src/analyzer/Impl.pv"
            return false;
        }

        #line 101 "src/analyzer/Impl.pv"
        HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);

        #line 103 "src/analyzer/Impl.pv"
        struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__FUNCTION, .function_value = func_info.name->value };
        #line 104 "src/analyzer/Impl.pv"
        Array_ImplNode__append(nodes, impl_node);

        #line 106 "src/analyzer/Impl.pv"
        Context__skip_comments(context);
    }

    #line 109 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 109 "src/analyzer/Impl.pv"
        return false;
    }

    #line 111 "src/analyzer/Impl.pv"
    return true;
}

#line 114 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self) {
    #line 115 "src/analyzer/Impl.pv"
    self->context->type_self = &self->type;

    #line 117 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 117 "src/analyzer/Impl.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 117 "src/analyzer/Impl.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 118 "src/analyzer/Impl.pv"
        Function__parse_function(function, &self->generics);
    } }

    #line 121 "src/analyzer/Impl.pv"
    self->context->type_self = &self->context->root->type_self;

    #line 123 "src/analyzer/Impl.pv"
    return true;
}
