#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_Scope.h>
#include <analyzer/Scope.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_ref_Token.h>
#include <analyzer/Block.h>
#include <analyzer/types/Generics.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <analyzer/types/Type.h>
#include <std/str.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/statement/PreprocessorIfStatement.h>
#include <analyzer/statement/PreprocessorIfStatement.h>

#include <analyzer/statement/PreprocessorIfStatement.h>

#line 12 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorIfStatement* PreprocessorIfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 13 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Token* if_token = Context__current(context);
    #line 14 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#if")) {
        #line 14 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }
    #line 15 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (if_token == 0) {
        #line 15 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 17 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Array_ref_Token condition = Array_ref_Token__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 18 "src/analyzer/statement/PreprocessorIfStatement.pv"
    while (context->pos < context->length) {
        #line 19 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Token* token = Context__current(context);
        #line 20 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (token == 0) {
            #line 20 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }
        #line 21 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (token->start_line != if_token->start_line) {
            #line 21 "src/analyzer/statement/PreprocessorIfStatement.pv"
            break;
        }
        #line 22 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Array_ref_Token__append(&condition, token);
        #line 23 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__next_token(context);
    }
    #line 25 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (condition.length == 0) {
        #line 26 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__error(context, "Expected preprocessor expression in #if condition");
        #line 27 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 30 "src/analyzer/statement/PreprocessorIfStatement.pv"
    uintptr_t parent_index = context->scopes.length - 1;
    #line 31 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Scope* parent_scope = &context->scopes.data[parent_index];
    #line 32 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct HashMap_str_Type original_values = HashMap_str_Type__clone(&parent_scope->values, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 33 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct HashMap_str_Type original_narrow_originals = HashMap_str_Type__clone(&parent_scope->narrow_originals, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 34 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct HashMap_str_ref_Token original_definition_tokens = HashMap_str_ref_Token__clone(&parent_scope->definition_tokens, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 36 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Block* block = Block__new_ptr(context);
    #line 37 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Scope* block_scope = Block__parse_preprocessor_branch(block, context, generics);
    #line 38 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (block_scope == 0) {
        #line 38 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }
    #line 42 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope = &context->scopes.data[parent_index];
    #line 43 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->values = HashMap_str_Type__clone(&original_values, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 44 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->narrow_originals = HashMap_str_Type__clone(&original_narrow_originals, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 45 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->definition_tokens = HashMap_str_ref_Token__clone(&original_definition_tokens, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 47 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Block* else_block = 0;
    #line 48 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Scope* else_scope = 0;
    #line 49 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "#else")) {
        #line 50 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Block* parsed_else_block = Block__new_ptr(context);
        #line 51 "src/analyzer/statement/PreprocessorIfStatement.pv"
        else_scope = Block__parse_preprocessor_branch(parsed_else_block, context, generics);
        #line 52 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (else_scope == 0) {
            #line 52 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }
        #line 53 "src/analyzer/statement/PreprocessorIfStatement.pv"
        else_block = parsed_else_block;
    }

    #line 56 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#endif")) {
        #line 56 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 58 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope = &context->scopes.data[parent_index];
    #line 59 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->values = HashMap_str_Type__clone(&original_values, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 60 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->narrow_originals = HashMap_str_Type__clone(&original_narrow_originals, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 61 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->definition_tokens = HashMap_str_ref_Token__clone(&original_definition_tokens, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 65 "src/analyzer/statement/PreprocessorIfStatement.pv"
    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&block_scope->values);
    #line 65 "src/analyzer/statement/PreprocessorIfStatement.pv"
    while (HashMapIter_str_Type__next(&__iter)) {
        #line 65 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct str name = HashMapIter_str_Type__value(&__iter)->_0;

        #line 66 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (HashMap_str_Type__find(&original_values, &name) != 0) {
            #line 67 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct Token** token = HashMap_str_ref_Token__find(&block_scope->definition_tokens, &name);
            #line 68 "src/analyzer/statement/PreprocessorIfStatement.pv"
            if (token != 0) {
                #line 68 "src/analyzer/statement/PreprocessorIfStatement.pv"
                Context__error_token(context, *token, "Conditional declaration cannot shadow an existing variable");
            }
        }
    } }
    #line 71 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (else_scope != 0) {
        #line 72 "src/analyzer/statement/PreprocessorIfStatement.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&else_scope->values);
        #line 72 "src/analyzer/statement/PreprocessorIfStatement.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 72 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 73 "src/analyzer/statement/PreprocessorIfStatement.pv"
            if (HashMap_str_Type__find(&original_values, &name) != 0) {
                #line 74 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct Token** token = HashMap_str_ref_Token__find(&else_scope->definition_tokens, &name);
                #line 75 "src/analyzer/statement/PreprocessorIfStatement.pv"
                if (token != 0) {
                    #line 75 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    Context__error_token(context, *token, "Conditional declaration cannot shadow an existing variable");
                }
            }
        } }
    }
    #line 82 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (else_scope != 0) {
        #line 83 "src/analyzer/statement/PreprocessorIfStatement.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&block_scope->values);
        #line 83 "src/analyzer/statement/PreprocessorIfStatement.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 83 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 83 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct Type block_type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 84 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct Type* other_type = HashMap_str_Type__find(&else_scope->values, &name);
            #line 85 "src/analyzer/statement/PreprocessorIfStatement.pv"
            if (other_type == 0) {
                #line 85 "src/analyzer/statement/PreprocessorIfStatement.pv"
                continue;
            }
            #line 89 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct String block_type_name = Naming__get_type_decl(&context->root->naming_decl, &block_type, context->type_self, 0);
            #line 90 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct String else_type_name = Naming__get_type_decl(&context->root->naming_decl, other_type, context->type_self, 0);
            #line 91 "src/analyzer/statement/PreprocessorIfStatement.pv"
            if (!str__Eq_str__eq((struct str[]){String__as_str(&block_type_name)}, String__as_str(&else_type_name))) {
                #line 92 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 93 "src/analyzer/statement/PreprocessorIfStatement.pv"
                String__append(&message, (struct str){ .ptr = "Conditional declarations disagree for '", .length = strlen("Conditional declarations disagree for '") });
                #line 94 "src/analyzer/statement/PreprocessorIfStatement.pv"
                String__append(&message, name);
                #line 95 "src/analyzer/statement/PreprocessorIfStatement.pv"
                String__append(&message, (struct str){ .ptr = "': ", .length = strlen("': ") });
                #line 96 "src/analyzer/statement/PreprocessorIfStatement.pv"
                String__append(&message, String__as_str(&block_type_name));
                #line 97 "src/analyzer/statement/PreprocessorIfStatement.pv"
                String__append(&message, (struct str){ .ptr = " versus ", .length = strlen(" versus ") });
                #line 98 "src/analyzer/statement/PreprocessorIfStatement.pv"
                String__append(&message, String__as_str(&else_type_name));
                #line 99 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct Token** token = HashMap_str_ref_Token__find(&else_scope->definition_tokens, &name);
                #line 100 "src/analyzer/statement/PreprocessorIfStatement.pv"
                if (token != 0) {
                    #line 100 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    Context__error_token(context, *token, String__c_str(&message));
                } else {
                    #line 101 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    Context__error(context, String__c_str(&message));
                }
                #line 102 "src/analyzer/statement/PreprocessorIfStatement.pv"
                continue;
            }
            #line 106 "src/analyzer/statement/PreprocessorIfStatement.pv"
            if (HashMap_str_Type__find(&parent_scope->values, &name) == 0) {
                #line 107 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct Token** token = HashMap_str_ref_Token__find(&block_scope->definition_tokens, &name);
                #line 108 "src/analyzer/statement/PreprocessorIfStatement.pv"
                if (token != 0) {
                    #line 108 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    Context__set_value(context, *token, &block_type);
                }
            }
        } }
    }

    #line 113 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct PreprocessorIfStatement result = (struct PreprocessorIfStatement) { .condition = condition, .block = block, .else_block = else_block };
    #line 114 "src/analyzer/statement/PreprocessorIfStatement.pv"
    return ArenaAllocator__store_PreprocessorIfStatement(context->allocator, &result);
}
