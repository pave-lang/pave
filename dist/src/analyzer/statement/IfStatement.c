#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/Block.h>
#include <analyzer/types/Generics.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Type.h>
#include <analyzer/Token.h>
#include <std/str.h>
#include <analyzer/types/Primitive.h>
#include <std/trait_Allocator.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/statement/IfStatement.h>

#include <analyzer/statement/IfStatement.h>

#line 14 "src/analyzer/statement/IfStatement.pv"
struct IfStatement* IfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 15 "src/analyzer/statement/IfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 15 "src/analyzer/statement/IfStatement.pv"
        return 0;
    }

    #line 17 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* pattern = 0;
    #line 18 "src/analyzer/statement/IfStatement.pv"
    struct Expression* expression = 0;
    #line 19 "src/analyzer/statement/IfStatement.pv"
    struct Block* block = Block__new_ptr(context);

    #line 21 "src/analyzer/statement/IfStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 22 "src/analyzer/statement/IfStatement.pv"
        Context__push_scope(context, block);
        #line 23 "src/analyzer/statement/IfStatement.pv"
        struct MatchPattern p = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 24 "src/analyzer/statement/IfStatement.pv"
        if (!MatchPattern__parse(context, generics, &p)) {
            #line 24 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 24 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 25 "src/analyzer/statement/IfStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 25 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 25 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 26 "src/analyzer/statement/IfStatement.pv"
        pattern = ArenaAllocator__store_MatchPattern(context->allocator, &p);
        #line 27 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 28 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 28 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 28 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 29 "src/analyzer/statement/IfStatement.pv"
        switch (p.type) {
            #line 30 "src/analyzer/statement/IfStatement.pv"
            case MATCH_PATTERN__ENUM_VARIANT: {
                #line 30 "src/analyzer/statement/IfStatement.pv"
                struct Type* enum_type = p.enumvariant_value._0;
                #line 31 "src/analyzer/statement/IfStatement.pv"
                if (!Type__eq(Type__deref(&expression->return_type), enum_type)) {
                    #line 32 "src/analyzer/statement/IfStatement.pv"
                    Context__error_token(context, expression->token, "If let expression type does not match pattern enum type");
                    #line 33 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 34 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
            #line 37 "src/analyzer/statement/IfStatement.pv"
            default: {
                #line 38 "src/analyzer/statement/IfStatement.pv"
                if (!Type__is_discriminated_union(Type__deref(&expression->return_type))) {
                    #line 39 "src/analyzer/statement/IfStatement.pv"
                    Context__error_token(context, expression->token, "If let expression must be an enum (discriminated union)");
                    #line 40 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 41 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
        }
        #line 45 "src/analyzer/statement/IfStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 45 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 45 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 46 "src/analyzer/statement/IfStatement.pv"
        Context__pop_scope(context);
    } else {
        #line 48 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 49 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 49 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 50 "src/analyzer/statement/IfStatement.pv"
        switch (expression->return_type.type) {
            #line 51 "src/analyzer/statement/IfStatement.pv"
            case TYPE__PRIMITIVE: {
                #line 51 "src/analyzer/statement/IfStatement.pv"
                struct Primitive* prim = expression->return_type.primitive_value;
                #line 52 "src/analyzer/statement/IfStatement.pv"
                if (!str__eq(prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                    #line 53 "src/analyzer/statement/IfStatement.pv"
                    Context__error_token(context, expression->token, "If condition must be a bool expression");
                    #line 54 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
            #line 57 "src/analyzer/statement/IfStatement.pv"
            default: {
                #line 58 "src/analyzer/statement/IfStatement.pv"
                Context__error_token(context, expression->token, "If condition must be a bool expression");
                #line 59 "src/analyzer/statement/IfStatement.pv"
                return 0;
            } break;
        }
        #line 62 "src/analyzer/statement/IfStatement.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 62 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
    }

    #line 65 "src/analyzer/statement/IfStatement.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 66 "src/analyzer/statement/IfStatement.pv"
    struct Expression* else_expression = 0;
    #line 67 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* else_pattern = 0;
    #line 68 "src/analyzer/statement/IfStatement.pv"
    struct Block* else_block = 0;
    #line 69 "src/analyzer/statement/IfStatement.pv"
    bool else_end = false;

    #line 71 "src/analyzer/statement/IfStatement.pv"
    while (!else_end && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 72 "src/analyzer/statement/IfStatement.pv"
        else_expression = 0;
        #line 73 "src/analyzer/statement/IfStatement.pv"
        else_pattern = 0;

        #line 75 "src/analyzer/statement/IfStatement.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 76 "src/analyzer/statement/IfStatement.pv"
            if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
                #line 77 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 78 "src/analyzer/statement/IfStatement.pv"
                Context__push_scope(context, else_block);
                #line 79 "src/analyzer/statement/IfStatement.pv"
                struct MatchPattern ep = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
                #line 80 "src/analyzer/statement/IfStatement.pv"
                if (!MatchPattern__parse(context, generics, &ep)) {
                    #line 80 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 80 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 81 "src/analyzer/statement/IfStatement.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
                    #line 81 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 81 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 82 "src/analyzer/statement/IfStatement.pv"
                else_pattern = ArenaAllocator__store_MatchPattern(context->allocator, &ep);
                #line 83 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 84 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 84 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 84 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 85 "src/analyzer/statement/IfStatement.pv"
                switch (ep.type) {
                    #line 86 "src/analyzer/statement/IfStatement.pv"
                    case MATCH_PATTERN__ENUM_VARIANT: {
                        #line 86 "src/analyzer/statement/IfStatement.pv"
                        struct Type* enum_type = ep.enumvariant_value._0;
                        #line 87 "src/analyzer/statement/IfStatement.pv"
                        if (!Type__eq(&else_expression->return_type, enum_type)) {
                            #line 88 "src/analyzer/statement/IfStatement.pv"
                            Context__error_token(context, else_expression->token, "If let expression type does not match pattern enum type");
                            #line 89 "src/analyzer/statement/IfStatement.pv"
                            Context__pop_scope(context);
                            #line 90 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                    #line 93 "src/analyzer/statement/IfStatement.pv"
                    default: {
                        #line 94 "src/analyzer/statement/IfStatement.pv"
                        if (!Type__is_enum(&else_expression->return_type)) {
                            #line 95 "src/analyzer/statement/IfStatement.pv"
                            Context__error_token(context, else_expression->token, "If let expression must be an enum (discriminated union)");
                            #line 96 "src/analyzer/statement/IfStatement.pv"
                            Context__pop_scope(context);
                            #line 97 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                }
                #line 101 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, false)) {
                    #line 101 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 101 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 102 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
            } else {
                #line 104 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 105 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 105 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 106 "src/analyzer/statement/IfStatement.pv"
                switch (else_expression->return_type.type) {
                    #line 107 "src/analyzer/statement/IfStatement.pv"
                    case TYPE__PRIMITIVE: {
                        #line 107 "src/analyzer/statement/IfStatement.pv"
                        struct Primitive* prim = else_expression->return_type.primitive_value;
                        #line 108 "src/analyzer/statement/IfStatement.pv"
                        if (!str__eq(prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                            #line 109 "src/analyzer/statement/IfStatement.pv"
                            Context__error_token(context, else_expression->token, "If condition must be a bool expression");
                            #line 110 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                    #line 113 "src/analyzer/statement/IfStatement.pv"
                    default: {
                        #line 114 "src/analyzer/statement/IfStatement.pv"
                        Context__error_token(context, else_expression->token, "If condition must be a bool expression");
                        #line 115 "src/analyzer/statement/IfStatement.pv"
                        return 0;
                    } break;
                }
                #line 118 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 119 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, true)) {
                    #line 119 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            }
        } else {
            #line 122 "src/analyzer/statement/IfStatement.pv"
            else_end = true;
            #line 123 "src/analyzer/statement/IfStatement.pv"
            else_block = Block__new_ptr(context);
            #line 124 "src/analyzer/statement/IfStatement.pv"
            if (!Block__parse(else_block, context, generics, true)) {
                #line 124 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }
        }

        #line 127 "src/analyzer/statement/IfStatement.pv"
        Array_ElseStatement__append(&else_statements, (struct ElseStatement) {
            .pattern = else_pattern,
            .expression = else_expression,
            .block = else_block,
        });
    }

    #line 134 "src/analyzer/statement/IfStatement.pv"
    return ArenaAllocator__store_IfStatement(context->allocator, (struct IfStatement[]){(struct IfStatement) {
        .pattern = pattern,
        .expression = expression,
        .block = block,
        .else_statements = else_statements,
    }});
}
