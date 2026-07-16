#include <stdint.h>
#include <string.h>

#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Context.h>
#include <analyzer/Token.h>
#include <usize.h>
#include <std/str.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/PreprocessorIfStatement.h>
#include <std/Array_Scope.h>
#include <analyzer/Scope.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_ref_Token.h>
#include <analyzer/Block.h>
#include <analyzer/types/Generics.h>
#include <std/Array_ref_Scope.h>
#include <analyzer/statement/PreprocessorElseIf.h>
#include <std/Iter_ref_ref_Scope.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <analyzer/types/Type.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <analyzer/statement/PreprocessorIfStatement.h>

#include <analyzer/statement/PreprocessorIfStatement.h>

#line 19 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct Array_ref_Token PreprocessorIfStatement__parse_condition(struct Context* context, struct Token* directive) {
    #line 20 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Array_ref_Token condition = Array_ref_Token__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 21 "src/analyzer/statement/PreprocessorIfStatement.pv"
    while (context->pos < context->length) {
        #line 22 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Token* token = Context__current(context);
        #line 23 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (token == 0) {
            #line 23 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return condition;
        }
        #line 24 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (token->start_line != directive->start_line) {
            #line 24 "src/analyzer/statement/PreprocessorIfStatement.pv"
            break;
        }
        #line 25 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Array_ref_Token__append(&condition, token);
        #line 26 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__next_token(context);
    }
    #line 28 "src/analyzer/statement/PreprocessorIfStatement.pv"
    return condition;
}

#line 31 "src/analyzer/statement/PreprocessorIfStatement.pv"
bool PreprocessorIfStatement__validate_condition(struct Context* context, struct Token* directive, struct Array_ref_Token* condition) {
    #line 32 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (usize__Eq_usize__eq(condition->length, 0)) {
        #line 33 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__error_token(context, directive, "Expected preprocessor condition");
        #line 34 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return false;
    }
    #line 36 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if ((str__Eq_str__eq(directive->value, (struct str){ .ptr = "#ifdef", .length = strlen("#ifdef") }) || str__Eq_str__eq(directive->value, (struct str){ .ptr = "#ifndef", .length = strlen("#ifndef") })) && (condition->length != 1 || condition->data[0]->type != TOKEN_TYPE__IDENTIFIER)) {
        #line 37 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__error_token(context, directive, "Expected one macro identifier");
        #line 38 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return false;
    }
    #line 40 "src/analyzer/statement/PreprocessorIfStatement.pv"
    return true;
}

#line 43 "src/analyzer/statement/PreprocessorIfStatement.pv"
struct PreprocessorIfStatement* PreprocessorIfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 44 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Token* directive = Context__current(context);
    #line 45 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (directive == 0) {
        #line 45 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }
    #line 46 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (!Token__eq(directive, TOKEN_TYPE__KEYWORD, "#if") && !Token__eq(directive, TOKEN_TYPE__KEYWORD, "#ifdef") && !Token__eq(directive, TOKEN_TYPE__KEYWORD, "#ifndef")) {
        #line 47 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__error_token(context, directive, "Expected #if, #ifdef, or #ifndef");
        #line 48 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }
    #line 50 "src/analyzer/statement/PreprocessorIfStatement.pv"
    Context__next_token(context);

    #line 52 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Array_ref_Token condition = PreprocessorIfStatement__parse_condition(context, directive);
    #line 53 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (!PreprocessorIfStatement__validate_condition(context, directive, &condition)) {
        #line 53 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 55 "src/analyzer/statement/PreprocessorIfStatement.pv"
    uintptr_t parent_index = context->scopes.length - 1;
    #line 56 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Scope* parent_scope = &context->scopes.data[parent_index];
    #line 57 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct HashMap_str_Type original_values = HashMap_str_Type__clone(&parent_scope->values, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 58 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct HashMap_str_Type original_narrow_originals = HashMap_str_Type__clone(&parent_scope->narrow_originals, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 59 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct HashMap_str_ref_Token original_definition_tokens = HashMap_str_ref_Token__clone(&parent_scope->definition_tokens, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 61 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Block* block = Block__new_ptr(context);
    #line 62 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Scope* block_scope = Block__parse_preprocessor_branch(block, context, generics);
    #line 63 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (block_scope == 0) {
        #line 63 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }
    #line 64 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Array_ref_Scope branch_scopes = Array_ref_Scope__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 65 "src/analyzer/statement/PreprocessorIfStatement.pv"
    Array_ref_Scope__append(&branch_scopes, block_scope);
    #line 69 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope = &context->scopes.data[parent_index];
    #line 70 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->values = HashMap_str_Type__clone(&original_values, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 71 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->narrow_originals = HashMap_str_Type__clone(&original_narrow_originals, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 72 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->definition_tokens = HashMap_str_ref_Token__clone(&original_definition_tokens, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 74 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Array_PreprocessorElseIf else_ifs = Array_PreprocessorElseIf__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 75 "src/analyzer/statement/PreprocessorIfStatement.pv"
    while (Context__check_value(context, TOKEN_TYPE__KEYWORD, "#elif")) {
        #line 76 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Token* elif_token = Context__current(context);
        #line 77 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (elif_token == 0) {
            #line 77 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }
        #line 78 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Context__next_token(context);
        #line 79 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Array_ref_Token elif_condition = PreprocessorIfStatement__parse_condition(context, elif_token);
        #line 80 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (!PreprocessorIfStatement__validate_condition(context, elif_token, &elif_condition)) {
            #line 80 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }

        #line 82 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Block* elif_block = Block__new_ptr(context);
        #line 83 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Scope* elif_scope = Block__parse_preprocessor_branch(elif_block, context, generics);
        #line 84 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (elif_scope == 0) {
            #line 84 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }
        #line 85 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Array_ref_Scope__append(&branch_scopes, elif_scope);
        #line 86 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Array_PreprocessorElseIf__append(&else_ifs, (struct PreprocessorElseIf) { .condition = elif_condition, .block = elif_block });

        #line 88 "src/analyzer/statement/PreprocessorIfStatement.pv"
        parent_scope = &context->scopes.data[parent_index];
        #line 89 "src/analyzer/statement/PreprocessorIfStatement.pv"
        parent_scope->values = HashMap_str_Type__clone(&original_values, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 90 "src/analyzer/statement/PreprocessorIfStatement.pv"
        parent_scope->narrow_originals = HashMap_str_Type__clone(&original_narrow_originals, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 91 "src/analyzer/statement/PreprocessorIfStatement.pv"
        parent_scope->definition_tokens = HashMap_str_ref_Token__clone(&original_definition_tokens, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    }

    #line 94 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Block* else_block = 0;
    #line 95 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct Scope* else_scope = 0;
    #line 96 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "#else")) {
        #line 97 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Block* parsed_else_block = Block__new_ptr(context);
        #line 98 "src/analyzer/statement/PreprocessorIfStatement.pv"
        else_scope = Block__parse_preprocessor_branch(parsed_else_block, context, generics);
        #line 99 "src/analyzer/statement/PreprocessorIfStatement.pv"
        if (else_scope == 0) {
            #line 99 "src/analyzer/statement/PreprocessorIfStatement.pv"
            return 0;
        }
        #line 100 "src/analyzer/statement/PreprocessorIfStatement.pv"
        Array_ref_Scope__append(&branch_scopes, else_scope);
        #line 101 "src/analyzer/statement/PreprocessorIfStatement.pv"
        else_block = parsed_else_block;
    }

    #line 104 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "#endif")) {
        #line 104 "src/analyzer/statement/PreprocessorIfStatement.pv"
        return 0;
    }

    #line 106 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope = &context->scopes.data[parent_index];
    #line 107 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->values = HashMap_str_Type__clone(&original_values, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 108 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->narrow_originals = HashMap_str_Type__clone(&original_narrow_originals, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 109 "src/analyzer/statement/PreprocessorIfStatement.pv"
    parent_scope->definition_tokens = HashMap_str_ref_Token__clone(&original_definition_tokens, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 113 "src/analyzer/statement/PreprocessorIfStatement.pv"
    { struct Iter_ref_ref_Scope __iter = Array_ref_Scope__iter(&branch_scopes);
    #line 113 "src/analyzer/statement/PreprocessorIfStatement.pv"
    while (Iter_ref_ref_Scope__next(&__iter)) {
        #line 113 "src/analyzer/statement/PreprocessorIfStatement.pv"
        struct Scope* branch_scope = *Iter_ref_ref_Scope__value(&__iter);

        #line 114 "src/analyzer/statement/PreprocessorIfStatement.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&branch_scope->values);
        #line 114 "src/analyzer/statement/PreprocessorIfStatement.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 114 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 115 "src/analyzer/statement/PreprocessorIfStatement.pv"
            if (HashMap_str_Type__find(&original_values, &name) != 0) {
                #line 116 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct Token** token = HashMap_str_ref_Token__find(&branch_scope->definition_tokens, &name);
                #line 117 "src/analyzer/statement/PreprocessorIfStatement.pv"
                if (token != 0) {
                    #line 117 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    Context__error_token(context, *token, "Conditional declaration cannot shadow an existing variable");
                }
            }
        } }
    } }
    #line 124 "src/analyzer/statement/PreprocessorIfStatement.pv"
    if (else_scope != 0) {
        #line 125 "src/analyzer/statement/PreprocessorIfStatement.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&block_scope->values);
        #line 125 "src/analyzer/statement/PreprocessorIfStatement.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 125 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 125 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct Type block_type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 126 "src/analyzer/statement/PreprocessorIfStatement.pv"
            struct String block_type_name = Naming__get_type_decl(&context->root->naming_decl, &block_type, context->type_self, 0);
            #line 127 "src/analyzer/statement/PreprocessorIfStatement.pv"
            bool compatible = true;

            #line 129 "src/analyzer/statement/PreprocessorIfStatement.pv"
            { struct Iter_ref_ref_Scope __iter = Array_ref_Scope__iter(&branch_scopes);
            #line 129 "src/analyzer/statement/PreprocessorIfStatement.pv"
            while (Iter_ref_ref_Scope__next(&__iter)) {
                #line 129 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct Scope* branch_scope = *Iter_ref_ref_Scope__value(&__iter);

                #line 130 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct Type* other_type = HashMap_str_Type__find(&branch_scope->values, &name);
                #line 131 "src/analyzer/statement/PreprocessorIfStatement.pv"
                if (other_type == 0) {
                    #line 132 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    compatible = false;
                    #line 133 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    continue;
                }
                #line 138 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct String other_type_name = Naming__get_type_decl(&context->root->naming_decl, other_type, context->type_self, 0);
                #line 139 "src/analyzer/statement/PreprocessorIfStatement.pv"
                if (!str__Eq_str__eq(String__as_str(&block_type_name), String__as_str(&other_type_name))) {
                    #line 140 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    struct String message = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 141 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    String__append(&message, (struct str){ .ptr = "Conditional declarations disagree for '", .length = strlen("Conditional declarations disagree for '") });
                    #line 142 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    String__append(&message, name);
                    #line 143 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    String__append(&message, (struct str){ .ptr = "': ", .length = strlen("': ") });
                    #line 144 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    String__append(&message, String__as_str(&block_type_name));
                    #line 145 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    String__append(&message, (struct str){ .ptr = " versus ", .length = strlen(" versus ") });
                    #line 146 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    String__append(&message, String__as_str(&other_type_name));
                    #line 147 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    struct Token** token = HashMap_str_ref_Token__find(&branch_scope->definition_tokens, &name);
                    #line 148 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    if (token != 0) {
                        #line 148 "src/analyzer/statement/PreprocessorIfStatement.pv"
                        Context__error_token(context, *token, String__c_str(&message));
                    } else {
                        #line 149 "src/analyzer/statement/PreprocessorIfStatement.pv"
                        Context__error(context, String__c_str(&message));
                    }
                    #line 150 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    compatible = false;
                }
            } }
            #line 155 "src/analyzer/statement/PreprocessorIfStatement.pv"
            if (compatible && HashMap_str_Type__find(&parent_scope->values, &name) == 0) {
                #line 156 "src/analyzer/statement/PreprocessorIfStatement.pv"
                struct Token** token = HashMap_str_ref_Token__find(&block_scope->definition_tokens, &name);
                #line 157 "src/analyzer/statement/PreprocessorIfStatement.pv"
                if (token != 0) {
                    #line 157 "src/analyzer/statement/PreprocessorIfStatement.pv"
                    Context__set_value(context, *token, &block_type);
                }
            }
        } }
    }

    #line 162 "src/analyzer/statement/PreprocessorIfStatement.pv"
    struct PreprocessorIfStatement result = (struct PreprocessorIfStatement) { .directive = directive, .condition = condition, .block = block, .else_ifs = else_ifs, .else_block = else_block };
    #line 163 "src/analyzer/statement/PreprocessorIfStatement.pv"
    return ArenaAllocator__store_PreprocessorIfStatement(context->allocator, &result);
}
