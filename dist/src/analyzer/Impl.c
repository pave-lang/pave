#include <analyzer/Root.h>
#include <analyzer/Context.h>
#include <analyzer/Generics.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_ImplNode.h>
#include <analyzer/ImplNode.h>
#include <std/HashMap_str_Function.h>
#include <std/str.h>
#include <analyzer/Function.h>
#include <stdbool.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <analyzer/Token.h>
#include <analyzer/Type.h>
#include <analyzer/FunctionParent.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>

#include <analyzer/Impl.h>

#line 27 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context) {
    #line 28 "src/analyzer/Impl.pv"
    struct Impl node = (struct Impl) {
        .context = context,
        .impl_generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .struct_generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .nodes = Array_ImplNode__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .functions = HashMap_str_Function__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };

    #line 36 "src/analyzer/Impl.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "impl") == 0) {
        #line 36 "src/analyzer/Impl.pv"
        return node;
    }

    #line 38 "src/analyzer/Impl.pv"
    node.token_start = context->pos;
    #line 39 "src/analyzer/Impl.pv"
    Context__skip_to_symbol(context, "{");
    #line 40 "src/analyzer/Impl.pv"
    Context__skip_brackets(context, "{", "}");
    #line 41 "src/analyzer/Impl.pv"
    node.token_end = context->pos;

    #line 43 "src/analyzer/Impl.pv"
    return node;
}

#line 46 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self) {
    #line 47 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 48 "src/analyzer/Impl.pv"
    context->pos = self->token_start;

    #line 50 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->impl_generics, context)) {
        #line 50 "src/analyzer/Impl.pv"
        return false;
    }

    #line 52 "src/analyzer/Impl.pv"
    if (Context__check(context, TOKEN_TYPE__IDENTIFIER)) {
        #line 53 "src/analyzer/Impl.pv"
        self->name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 54 "src/analyzer/Impl.pv"
        if (self->name == 0) {
            #line 54 "src/analyzer/Impl.pv"
            return false;
        }
        #line 55 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->struct_generics, context)) {
            #line 55 "src/analyzer/Impl.pv"
            return false;
        }
    } else {
        #line 57 "src/analyzer/Impl.pv"
        self->type = ArenaAllocator__Allocator__alloc(context->allocator, sizeof(struct Type));
        #line 58 "src/analyzer/Impl.pv"
        if (!Context__parse_type(context, self->type, &self->impl_generics)) {
            #line 58 "src/analyzer/Impl.pv"
            return false;
        }
    }

    #line 61 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->struct_generics, context)) {
        #line 61 "src/analyzer/Impl.pv"
        return false;
    }

    #line 63 "src/analyzer/Impl.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "for")) {
        #line 64 "src/analyzer/Impl.pv"
        self->trait_name = self->name;
        #line 65 "src/analyzer/Impl.pv"
        self->trait_type = self->type;
        #line 66 "src/analyzer/Impl.pv"
        self->trait_generics = self->struct_generics;
        #line 67 "src/analyzer/Impl.pv"
        self->struct_generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 69 "src/analyzer/Impl.pv"
        if (Context__check(context, TOKEN_TYPE__IDENTIFIER)) {
            #line 70 "src/analyzer/Impl.pv"
            self->name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 71 "src/analyzer/Impl.pv"
            if (self->name == 0) {
                #line 71 "src/analyzer/Impl.pv"
                return false;
            }
            #line 72 "src/analyzer/Impl.pv"
            if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->struct_generics, context)) {
                #line 72 "src/analyzer/Impl.pv"
                return false;
            }
        } else {
            #line 74 "src/analyzer/Impl.pv"
            self->type = ArenaAllocator__Allocator__alloc(context->allocator, sizeof(struct Type));
            #line 75 "src/analyzer/Impl.pv"
            if (!Context__parse_type(context, self->type, &self->impl_generics)) {
                #line 75 "src/analyzer/Impl.pv"
                return false;
            }
        }
    }

    #line 79 "src/analyzer/Impl.pv"
    self->token_start = context->pos;

    #line 81 "src/analyzer/Impl.pv"
    return true;
}

#line 84 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent) {
    #line 85 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 86 "src/analyzer/Impl.pv"
    context->pos = self->token_start;
    #line 87 "src/analyzer/Impl.pv"
    struct Array_ImplNode* nodes = &self->nodes;

    #line 89 "src/analyzer/Impl.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{") == 0) {
        #line 89 "src/analyzer/Impl.pv"
        return false;
    }

    #line 91 "src/analyzer/Impl.pv"
    Context__skip_comments(context);

    #line 93 "src/analyzer/Impl.pv"
    while (context->pos < self->token_end - 1) {
        #line 94 "src/analyzer/Impl.pv"
        struct Function func_info = Function__parse(context);
        #line 95 "src/analyzer/Impl.pv"
        func_info.parent = parent;
        #line 96 "src/analyzer/Impl.pv"
        if (func_info.name == 0) {
            #line 96 "src/analyzer/Impl.pv"
            return false;
        }

        #line 98 "src/analyzer/Impl.pv"
        HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);

        #line 100 "src/analyzer/Impl.pv"
        struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__FUNCTION, .function_value = func_info.name->value };
        #line 101 "src/analyzer/Impl.pv"
        Array_ImplNode__append(nodes, impl_node);

        #line 103 "src/analyzer/Impl.pv"
        Context__skip_comments(context);
    }

    #line 106 "src/analyzer/Impl.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 106 "src/analyzer/Impl.pv"
        return false;
    }

    #line 108 "src/analyzer/Impl.pv"
    return true;
}

#line 111 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self) {
    #line 112 "src/analyzer/Impl.pv"
    self->context->type_self = &self->type_self;

    #line 114 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 114 "src/analyzer/Impl.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 114 "src/analyzer/Impl.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 115 "src/analyzer/Impl.pv"
        Function__parse_function(function, &self->impl_generics);
    } }

    #line 118 "src/analyzer/Impl.pv"
    self->context->type_self = &self->context->root->type_self;

    #line 120 "src/analyzer/Impl.pv"
    return true;
}
