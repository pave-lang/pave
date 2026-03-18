#include <analyzer/Root.h>
#include <analyzer/Context.h>
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
#include <analyzer/Token.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/FunctionParent.h>
#include <tuple_str_Function.h>
#include <std/HashMapIter_str_Function.h>

#include <analyzer/Impl.h>

#line 28 "src/analyzer/Impl.pv"
struct Impl Impl__parse(struct Context* context) {
    #line 29 "src/analyzer/Impl.pv"
    struct Impl node = (struct Impl) {
        .context = context,
        .impl_generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .struct_generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .nodes = Array_ImplNode__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .functions = HashMap_str_Function__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };

    #line 37 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "impl")) {
        #line 37 "src/analyzer/Impl.pv"
        return node;
    }

    #line 39 "src/analyzer/Impl.pv"
    node.token_start = context->pos;
    #line 40 "src/analyzer/Impl.pv"
    Context__skip_to_symbol(context, "{");
    #line 41 "src/analyzer/Impl.pv"
    Context__skip_brackets(context, "{", "}");
    #line 42 "src/analyzer/Impl.pv"
    node.token_end = context->pos;

    #line 44 "src/analyzer/Impl.pv"
    return node;
}

#line 47 "src/analyzer/Impl.pv"
bool Impl__prefill_types(struct Impl* self) {
    #line 48 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 49 "src/analyzer/Impl.pv"
    context->pos = self->token_start;

    #line 51 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->impl_generics, context)) {
        #line 51 "src/analyzer/Impl.pv"
        return false;
    }

    #line 53 "src/analyzer/Impl.pv"
    if (Context__check(context, TOKEN_TYPE__IDENTIFIER)) {
        #line 54 "src/analyzer/Impl.pv"
        self->name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
        #line 55 "src/analyzer/Impl.pv"
        if (self->name == 0) {
            #line 55 "src/analyzer/Impl.pv"
            return false;
        }
        #line 56 "src/analyzer/Impl.pv"
        if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->struct_generics, context)) {
            #line 56 "src/analyzer/Impl.pv"
            return false;
        }
    } else {
        #line 58 "src/analyzer/Impl.pv"
        self->type = ArenaAllocator__Allocator__alloc(context->allocator, sizeof(struct Type));
        #line 59 "src/analyzer/Impl.pv"
        if (!Context__parse_type(context, self->type, &self->impl_generics)) {
            #line 59 "src/analyzer/Impl.pv"
            return false;
        }
    }

    #line 62 "src/analyzer/Impl.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->struct_generics, context)) {
        #line 62 "src/analyzer/Impl.pv"
        return false;
    }

    #line 64 "src/analyzer/Impl.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "for")) {
        #line 65 "src/analyzer/Impl.pv"
        self->trait_name = self->name;
        #line 66 "src/analyzer/Impl.pv"
        self->trait_type = self->type;
        #line 67 "src/analyzer/Impl.pv"
        self->trait_generics = self->struct_generics;
        #line 68 "src/analyzer/Impl.pv"
        self->struct_generics = Generics__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 70 "src/analyzer/Impl.pv"
        if (Context__check(context, TOKEN_TYPE__IDENTIFIER)) {
            #line 71 "src/analyzer/Impl.pv"
            self->name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
            #line 72 "src/analyzer/Impl.pv"
            if (self->name == 0) {
                #line 72 "src/analyzer/Impl.pv"
                return false;
            }
            #line 73 "src/analyzer/Impl.pv"
            if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "<") && !Generics__parse(&self->struct_generics, context)) {
                #line 73 "src/analyzer/Impl.pv"
                return false;
            }
        } else {
            #line 75 "src/analyzer/Impl.pv"
            self->type = ArenaAllocator__Allocator__alloc(context->allocator, sizeof(struct Type));
            #line 76 "src/analyzer/Impl.pv"
            if (!Context__parse_type(context, self->type, &self->impl_generics)) {
                #line 76 "src/analyzer/Impl.pv"
                return false;
            }
        }
    }

    #line 80 "src/analyzer/Impl.pv"
    self->token_start = context->pos;

    #line 82 "src/analyzer/Impl.pv"
    return true;
}

#line 85 "src/analyzer/Impl.pv"
bool Impl__fill_types(struct Impl* self, struct FunctionParent parent) {
    #line 86 "src/analyzer/Impl.pv"
    struct Context* context = self->context;
    #line 87 "src/analyzer/Impl.pv"
    context->pos = self->token_start;
    #line 88 "src/analyzer/Impl.pv"
    struct Array_ImplNode* nodes = &self->nodes;

    #line 90 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 90 "src/analyzer/Impl.pv"
        return false;
    }

    #line 92 "src/analyzer/Impl.pv"
    Context__skip_comments(context);

    #line 94 "src/analyzer/Impl.pv"
    while (context->pos < self->token_end - 1) {
        #line 95 "src/analyzer/Impl.pv"
        struct Function func_info = Function__parse(context);
        #line 96 "src/analyzer/Impl.pv"
        func_info.parent = parent;
        #line 97 "src/analyzer/Impl.pv"
        if (func_info.name == 0) {
            #line 97 "src/analyzer/Impl.pv"
            return false;
        }

        #line 99 "src/analyzer/Impl.pv"
        HashMap_str_Function__insert(&self->functions, func_info.name->value, func_info);

        #line 101 "src/analyzer/Impl.pv"
        struct ImplNode impl_node = (struct ImplNode) { .type = IMPL_NODE__FUNCTION, .function_value = func_info.name->value };
        #line 102 "src/analyzer/Impl.pv"
        Array_ImplNode__append(nodes, impl_node);

        #line 104 "src/analyzer/Impl.pv"
        Context__skip_comments(context);
    }

    #line 107 "src/analyzer/Impl.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 107 "src/analyzer/Impl.pv"
        return false;
    }

    #line 109 "src/analyzer/Impl.pv"
    return true;
}

#line 112 "src/analyzer/Impl.pv"
bool Impl__parse_functions(struct Impl* self) {
    #line 113 "src/analyzer/Impl.pv"
    self->context->type_self = &self->type_self;

    #line 115 "src/analyzer/Impl.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&self->functions);
    #line 115 "src/analyzer/Impl.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 115 "src/analyzer/Impl.pv"
        struct Function* function = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 116 "src/analyzer/Impl.pv"
        Function__parse_function(function, &self->impl_generics);
    } }

    #line 119 "src/analyzer/Impl.pv"
    self->context->type_self = &self->context->root->type_self;

    #line 121 "src/analyzer/Impl.pv"
    return true;
}
