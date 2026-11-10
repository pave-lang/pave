#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Primitive.h>
#include <std/str.h>
#include <analyzer/Block.h>
#include <std/Array_NullNarrowing.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Iter_ref_NullNarrowing.h>
#include <analyzer/expression/NullNarrowing.h>
#include <analyzer/statement/WhileStatement.h>

#include <analyzer/statement/WhileStatement.h>

#line 12 "src/analyzer/statement/WhileStatement.pv"
struct WhileStatement* WhileStatement__parse(struct Context* context, struct Generics* generics) {
    #line 13 "src/analyzer/statement/WhileStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "while")) {
        #line 13 "src/analyzer/statement/WhileStatement.pv"
        return 0;
    }

    #line 15 "src/analyzer/statement/WhileStatement.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 16 "src/analyzer/statement/WhileStatement.pv"
    if (expression == 0) {
        #line 16 "src/analyzer/statement/WhileStatement.pv"
        return 0;
    }

    #line 18 "src/analyzer/statement/WhileStatement.pv"
    bool is_bool = false;
    #line 19 "src/analyzer/statement/WhileStatement.pv"
    switch (expression->return_type.type) {
        #line 20 "src/analyzer/statement/WhileStatement.pv"
        case TYPE__PRIMITIVE: {
            #line 20 "src/analyzer/statement/WhileStatement.pv"
            struct Primitive* prim = expression->return_type.primitive_value;
            #line 20 "src/analyzer/statement/WhileStatement.pv"
            is_bool = prim != 0 && str__Eq_str__eq(prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") });
        } break;
        #line 21 "src/analyzer/statement/WhileStatement.pv"
        default: {
        } break;
    }
    #line 23 "src/analyzer/statement/WhileStatement.pv"
    if (!is_bool) {
        #line 24 "src/analyzer/statement/WhileStatement.pv"
        Context__error_expression(context, expression, "While condition must be a bool expression");
        #line 25 "src/analyzer/statement/WhileStatement.pv"
        return 0;
    }

    #line 28 "src/analyzer/statement/WhileStatement.pv"
    struct Block* block = Block__new_ptr(context);
    #line 29 "src/analyzer/statement/WhileStatement.pv"
    block->is_loop = true;
    #line 32 "src/analyzer/statement/WhileStatement.pv"
    struct Array_NullNarrowing narrowings_true = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 33 "src/analyzer/statement/WhileStatement.pv"
    Expression__collect_null_narrowings(context, expression, true, &narrowings_true);
    #line 34 "src/analyzer/statement/WhileStatement.pv"
    if (narrowings_true.length > 0) {
        #line 35 "src/analyzer/statement/WhileStatement.pv"
        Context__push_scope(context, block);
        #line 36 "src/analyzer/statement/WhileStatement.pv"
        { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings_true);
        #line 36 "src/analyzer/statement/WhileStatement.pv"
        while (Iter_ref_NullNarrowing__next(&__iter)) {
            #line 36 "src/analyzer/statement/WhileStatement.pv"
            struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

            #line 36 "src/analyzer/statement/WhileStatement.pv"
            Context__set_narrowed(context, narrow->path, narrow->type);
        } }
        #line 37 "src/analyzer/statement/WhileStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 37 "src/analyzer/statement/WhileStatement.pv"
            Context__pop_scope(context);
            #line 37 "src/analyzer/statement/WhileStatement.pv"
            return 0;
        }
        #line 38 "src/analyzer/statement/WhileStatement.pv"
        Context__pop_scope(context);
    } else {
        #line 40 "src/analyzer/statement/WhileStatement.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 40 "src/analyzer/statement/WhileStatement.pv"
            return 0;
        }
    }

    #line 43 "src/analyzer/statement/WhileStatement.pv"
    return ArenaAllocator__store_WhileStatement(context->allocator, (struct WhileStatement[]){(struct WhileStatement) {
        .expression = expression,
        .block = block,
    }});
}
