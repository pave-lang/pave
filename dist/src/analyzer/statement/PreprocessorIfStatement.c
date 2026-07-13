#include <stdbool.h>
#include <stdint.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Token.h>
#include <analyzer/Block.h>
#include <analyzer/types/Generics.h>
#include <analyzer/statement/PreprocessorIfStatement.h>
#include <analyzer/statement/PreprocessorIfStatement.h>

#include <analyzer/statement/PreprocessorIfStatement.h>

#line 12 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorIfStatement* PreprocessorIfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 13 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#if")) {
        #line 13 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 15 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Array_ref_Token condition = Array_ref_Token__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 16 "src/analyzer/statement/PreprocessorIfStatement.pv"
    while (context->pos < context->length && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 17 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Token* token = Context__current(context);
        #line 18 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (token == 0) {
            #line 18 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }
        #line 19 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Array_ref_Token__append(&condition, token);
        #line 20 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__next_token(context);
    }
    #line 22 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (condition.length == 0) {
        #line 23 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__error(context, "Expected preprocessor expression in #if condition");
        #line 24 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 27 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Block* block = Block__new_ptr(context);
    #line 28 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 28 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 30 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Block* else_block = 0;
    #line 31 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "#else")) {
        #line 32 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Block* parsed_else_block = Block__new_ptr(context);
        #line 33 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (!Block__parse(parsed_else_block, context, generics, true)) {
            #line 33 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }
        #line 34 "src/analyzer/statement/PreprocessorIfStatement.pv"
        else_block = parsed_else_block;
    }

    #line 37 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct PreprocessorIfStatement result = (struct PreprocessorIfStatement) { .condition = condition, .block = block, .else_block = else_block };
    #line 38 "src/analyzer/statement/PreprocessorIfStatement.pv"
    return ArenaAllocator__store_PreprocessorIfStatement(context->allocator, &result);
}
