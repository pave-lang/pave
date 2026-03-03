#include <stdio.h>

#include <analyzer/Context.h>
#include <std/Array_Statement.h>
#include <analyzer/Statement.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/DeferStatement.h>
#include <std/Array_Scope.h>
#include <stdbool.h>
#include <analyzer/Generics.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <analyzer/Type.h>
#include <analyzer/Expression.h>
#include <std/String.h>
#include <analyzer/GenericMap.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/LetStatement.h>
#include <analyzer/StatementData.h>
#include <analyzer/Function.h>
#include <analyzer/ExpressionData.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/ElseStatement.h>
#include <std/Array_MatchCase.h>
#include <analyzer/MatchCase.h>
#include <analyzer/MatchPattern.h>
#include <analyzer/Module.h>
#include <analyzer/EnumVariant.h>
#include <std/Array_EnumVariantParameter.h>
#include <analyzer/EnumVariantParameter.h>
#include <std/Array_Type.h>
#include <analyzer/Indirect.h>
#include <analyzer/IndirectType.h>
#include <std/Array_ForVariable.h>
#include <analyzer/ForVariable.h>
#include <analyzer/ForStatement.h>
#include <analyzer/ForStatementType.h>
#include <analyzer/InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/Enum.h>
#include <std/ArrayIter_ref_ForVariable.h>
#include <analyzer/Scope.h>
#include <std/ArrayIter_ref_Scope.h>

#include <analyzer/Block.h>

#line 14 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context) {
    #line 15 "src/analyzer/Block.pv"
    return (struct Block) {
        .context = context,
        .statements = Array_Statement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .defer_statements = Array_DeferStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 22 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context) {
    #line 23 "src/analyzer/Block.pv"
    return ArenaAllocator__store_Block(context->allocator, Block__new(context));
}

#line 26 "src/analyzer/Block.pv"
bool Block__parse_let_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 27 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 28 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "let") == 0) {
        #line 28 "src/analyzer/Block.pv"
        return false;
    }

    #line 30 "src/analyzer/Block.pv"
    bool is_static = Context__check_next(context, TOKEN_TYPE__KEYWORD, "static");

    #line 32 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 33 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 33 "src/analyzer/Block.pv"
        return false;
    }

    #line 35 "src/analyzer/Block.pv"
    struct Type* type = 0;

    #line 37 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 38 "src/analyzer/Block.pv"
        type = Context__parse_type2(context, generics);
        #line 39 "src/analyzer/Block.pv"
        if (type == 0) {
            #line 39 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 42 "src/analyzer/Block.pv"
    struct Expression* expression = 0;

    #line 44 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 45 "src/analyzer/Block.pv"
        expression = Expression__parse(context, generics);
        #line 46 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 46 "src/analyzer/Block.pv"
            return false;
        }

        #line 48 "src/analyzer/Block.pv"
        if (type == 0) {
            #line 49 "src/analyzer/Block.pv"
            type = &expression->return_type;

            #line 51 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 52 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 53 "src/analyzer/Block.pv"
            Context__inlay_hint(context, name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
        } else {
            #line 55 "src/analyzer/Block.pv"
            Expression__validate_type(expression, context, type);
        }
    }

    #line 73 "src/analyzer/Block.pv"
    if (Context__set_value(context, name, type) == 0) {
        #line 73 "src/analyzer/Block.pv"
        Context__error(context, "set_value");
        #line 73 "src/analyzer/Block.pv"
        return false;
    }
    #line 74 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 74 "src/analyzer/Block.pv"
        return false;
    }

    #line 76 "src/analyzer/Block.pv"
    struct LetStatement* let_statement = ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement) {
        .is_static = is_static,
        .name = name,
        .type = type,
        .value = expression,
    });

    #line 83 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement }));

    #line 85 "src/analyzer/Block.pv"
    return true;
}

#line 88 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 89 "src/analyzer/Block.pv"
    struct Array_DeferStatement defer_statements = Context__get_defer_statements(context);

    #line 91 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 92 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "return") == 0) {
        #line 92 "src/analyzer/Block.pv"
        return false;
    }

    #line 94 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 95 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = 0, ._1 = defer_statements} };
        #line 96 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 97 "src/analyzer/Block.pv"
        return true;
    }

    #line 100 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 101 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 101 "src/analyzer/Block.pv"
        return false;
    }
    #line 102 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 102 "src/analyzer/Block.pv"
        return false;
    }

    #line 104 "src/analyzer/Block.pv"
    struct Type* type = &context->function->return_type;

    #line 106 "src/analyzer/Block.pv"
    if (Type__needs_implicit_cast(type, &expression->return_type)) {
        #line 107 "src/analyzer/Block.pv"
        expression = Expression__make(context->allocator, first_token, (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression }, type);
    } else if (Type__eq(type, &expression->return_type) == 0) {
        #line 109 "src/analyzer/Block.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 110 "src/analyzer/Block.pv"
        String__append(&message, (struct str){ .ptr = "Function return type ", .length = strlen("Function return type ") });
        #line 111 "src/analyzer/Block.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 112 "src/analyzer/Block.pv"
        String__append(&message, String__as_str(&type_name));
        #line 113 "src/analyzer/Block.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 114 "src/analyzer/Block.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, &expression->return_type, context->type_self, 0);
        #line 115 "src/analyzer/Block.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 116 "src/analyzer/Block.pv"
        Context__error_token(context, first_token, String__c_str(&message));
    }

    #line 119 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = expression, ._1 = defer_statements} }));

    #line 121 "src/analyzer/Block.pv"
    return true;
}

#line 124 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 125 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 126 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield") == 0) {
        #line 126 "src/analyzer/Block.pv"
        return false;
    }

    #line 128 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 129 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = 0 };
        #line 130 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 131 "src/analyzer/Block.pv"
        return true;
    }

    #line 134 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 135 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 135 "src/analyzer/Block.pv"
        return false;
    }
    #line 136 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 136 "src/analyzer/Block.pv"
        return false;
    }

    #line 138 "src/analyzer/Block.pv"
    struct Type* type = &context->function->return_type;

    #line 140 "src/analyzer/Block.pv"
    if (Type__needs_implicit_cast(type, &expression->return_type)) {
        #line 141 "src/analyzer/Block.pv"
        expression = Expression__make(context->allocator, first_token, (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = expression }, type);
    } else if (Type__eq(type, &expression->return_type) == 0) {
        #line 143 "src/analyzer/Block.pv"
        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 144 "src/analyzer/Block.pv"
        String__append(&message, (struct str){ .ptr = "Function return type ", .length = strlen("Function return type ") });
        #line 145 "src/analyzer/Block.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
        #line 146 "src/analyzer/Block.pv"
        String__append(&message, String__as_str(&type_name));
        #line 147 "src/analyzer/Block.pv"
        String__append(&message, (struct str){ .ptr = " does not match expression return type of ", .length = strlen(" does not match expression return type of ") });
        #line 148 "src/analyzer/Block.pv"
        struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, &expression->return_type, context->type_self, 0);
        #line 149 "src/analyzer/Block.pv"
        String__append(&message, String__as_str(&return_type_name));
        #line 150 "src/analyzer/Block.pv"
        Context__error_token(context, first_token, String__c_str(&message));
    }

    #line 153 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = expression }));

    #line 155 "src/analyzer/Block.pv"
    return true;
}

#line 158 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 159 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 160 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 161 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 161 "src/analyzer/Block.pv"
        return false;
    }

    #line 163 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 164 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 165 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 165 "src/analyzer/Block.pv"
            return false;
        }

        #line 167 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 168 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 168 "src/analyzer/Block.pv"
            return false;
        }

        #line 170 "src/analyzer/Block.pv"
        struct Type* type = &expression->return_type;

        #line 172 "src/analyzer/Block.pv"
        if (Type__needs_implicit_cast(type, &value->return_type)) {
            #line 173 "src/analyzer/Block.pv"
            value = Expression__make(context->allocator, first_token, (struct ExpressionData) { .type = EXPRESSION_DATA__IMPLICIT_CAST, .implicitcast_value = value }, type);
        } else if (Type__eq(type, &value->return_type) == 0) {
            #line 175 "src/analyzer/Block.pv"
            struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 176 "src/analyzer/Block.pv"
            String__append(&message, (struct str){ .ptr = "Type ", .length = strlen("Type ") });
            #line 177 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 178 "src/analyzer/Block.pv"
            String__append(&message, String__as_str(&type_name));
            #line 179 "src/analyzer/Block.pv"
            String__append(&message, (struct str){ .ptr = " does not match expression type of ", .length = strlen(" does not match expression type of ") });
            #line 180 "src/analyzer/Block.pv"
            struct String return_type_name = Naming__get_type_decl(&context->root->naming_decl, &value->return_type, context->type_self, 0);
            #line 181 "src/analyzer/Block.pv"
            String__append(&message, String__as_str(&return_type_name));
            #line 182 "src/analyzer/Block.pv"
            Context__error_token(context, first_token, String__c_str(&message));
        }

        #line 185 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = { ._0 = expression, ._1 = operator, ._2 = value} }));
    } else {
        #line 187 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression }));
    }

    #line 190 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 190 "src/analyzer/Block.pv"
        return false;
    }

    #line 192 "src/analyzer/Block.pv"
    return true;
}

#line 195 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 196 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 197 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if") == 0) {
        #line 197 "src/analyzer/Block.pv"
        return false;
    }

    #line 199 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 200 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 200 "src/analyzer/Block.pv"
        return false;
    }

    #line 202 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 203 "src/analyzer/Block.pv"
    if (Block__parse(block, context, generics, 1) == 0) {
        #line 203 "src/analyzer/Block.pv"
        return false;
    }

    #line 205 "src/analyzer/Block.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 206 "src/analyzer/Block.pv"
    struct Expression* else_expression = 0;
    #line 207 "src/analyzer/Block.pv"
    struct Block* else_block = 0;
    #line 208 "src/analyzer/Block.pv"
    bool else_end = false;

    #line 210 "src/analyzer/Block.pv"
    while (else_end == 0 && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 211 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 212 "src/analyzer/Block.pv"
            else_expression = Expression__parse(context, generics);
            #line 213 "src/analyzer/Block.pv"
            if (else_expression == 0) {
                #line 213 "src/analyzer/Block.pv"
                return false;
            }
        } else {
            #line 215 "src/analyzer/Block.pv"
            else_expression = 0;
            #line 216 "src/analyzer/Block.pv"
            else_end = 1;
        }

        #line 219 "src/analyzer/Block.pv"
        else_block = Block__new_ptr(context);
        #line 220 "src/analyzer/Block.pv"
        if (Block__parse(else_block, context, generics, 1) == 0) {
            #line 220 "src/analyzer/Block.pv"
            return false;
        }

        #line 222 "src/analyzer/Block.pv"
        struct ElseStatement else_statement = (struct ElseStatement) {
            .expression = else_expression,
            .block = else_block,
        };

        #line 227 "src/analyzer/Block.pv"
        Array_ElseStatement__append(&else_statements, else_statement);
    }

    #line 230 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = { ._0 = expression, ._1 = block, ._2 = else_statements} }));

    #line 232 "src/analyzer/Block.pv"
    return true;
}

#line 235 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 236 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 237 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "match") == 0) {
        #line 237 "src/analyzer/Block.pv"
        return false;
    }

    #line 239 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 240 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 240 "src/analyzer/Block.pv"
        return false;
    }

    #line 242 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{") == 0) {
        #line 242 "src/analyzer/Block.pv"
        return false;
    }

    #line 244 "src/analyzer/Block.pv"
    struct Array_MatchCase cases = Array_MatchCase__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 246 "src/analyzer/Block.pv"
    while (Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 247 "src/analyzer/Block.pv"
        struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 248 "src/analyzer/Block.pv"
        struct Token* first_match_token = Context__current(context);

        #line 250 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 251 "src/analyzer/Block.pv"
        Context__push_scope(context, block);

        #line 253 "src/analyzer/Block.pv"
        struct Type* type = 0;

        #line 255 "src/analyzer/Block.pv"
        if (!Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "_")) {
            #line 256 "src/analyzer/Block.pv"
            struct Token* token = Context__current(context);
            #line 257 "src/analyzer/Block.pv"
            if (token == 0) {
                #line 257 "src/analyzer/Block.pv"
                return false;
            }

            #line 259 "src/analyzer/Block.pv"
            type = Context__get_value(context, token->value);

            #line 261 "src/analyzer/Block.pv"
            if (type != 0) {
                #line 262 "src/analyzer/Block.pv"
                Context__next_token(context);
                #line 263 "src/analyzer/Block.pv"
                pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE, .enumcvalue_value = token };
            } else {
                #line 265 "src/analyzer/Block.pv"
                struct Type* type_find = Module__find_type(context->module, token->value);
                #line 266 "src/analyzer/Block.pv"
                if (str__eq(token->value, (struct str){ .ptr = "Self", .length = strlen("Self") }) || (type_find != 0 && Type__is_enum(type_find))) {
                    #line 267 "src/analyzer/Block.pv"
                    type = Context__parse_type2(context, generics);
                    #line 268 "src/analyzer/Block.pv"
                    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
                        #line 268 "src/analyzer/Block.pv"
                        return false;
                    }
                } else {
                    #line 270 "src/analyzer/Block.pv"
                    type = &expression->return_type;
                }

                #line 273 "src/analyzer/Block.pv"
                struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                #line 274 "src/analyzer/Block.pv"
                if (enum_variant_token == 0) {
                    #line 274 "src/analyzer/Block.pv"
                    return false;
                }

                #line 276 "src/analyzer/Block.pv"
                struct GenericMap* generic_map = 0;

                #line 278 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 279 "src/analyzer/Block.pv"
                    case TYPE__SELF: {
                        #line 280 "src/analyzer/Block.pv"
                        type = context->type_self;
                    } break;
                    #line 282 "src/analyzer/Block.pv"
                    default: {
                    } break;
                }

                #line 285 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 286 "src/analyzer/Block.pv"
                    case TYPE__ENUM: {
                        #line 286 "src/analyzer/Block.pv"
                        struct GenericMap* generics = type->enum_value._1;
                        #line 287 "src/analyzer/Block.pv"
                        generic_map = generics;
                    } break;
                    #line 289 "src/analyzer/Block.pv"
                    default: {
                        #line 289 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 289 "src/analyzer/Block.pv"
                        Context__error(context, "Not an enum type");
                        #line 289 "src/analyzer/Block.pv"
                        return false;
                    } break;
                }

                #line 292 "src/analyzer/Block.pv"
                struct EnumVariant* enum_variant = Expression__get_enum_variant(context, type, enum_variant_token);
                #line 293 "src/analyzer/Block.pv"
                if (enum_variant == 0) {
                    #line 293 "src/analyzer/Block.pv"
                    return false;
                }

                #line 295 "src/analyzer/Block.pv"
                struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                #line 297 "src/analyzer/Block.pv"
                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                    #line 298 "src/analyzer/Block.pv"
                    uintptr_t variable_i = 0;

                    #line 300 "src/analyzer/Block.pv"
                    while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                        #line 301 "src/analyzer/Block.pv"
                        bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                        #line 302 "src/analyzer/Block.pv"
                        struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                        #line 303 "src/analyzer/Block.pv"
                        if (variable == 0) {
                            #line 303 "src/analyzer/Block.pv"
                            Context__pop_scope(context);
                            #line 303 "src/analyzer/Block.pv"
                            return false;
                        }

                        #line 305 "src/analyzer/Block.pv"
                        Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                        #line 307 "src/analyzer/Block.pv"
                        struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                        #line 308 "src/analyzer/Block.pv"
                        if (variable_type == 0) {
                            #line 308 "src/analyzer/Block.pv"
                            return false;
                        }

                        #line 310 "src/analyzer/Block.pv"
                        if (ref) {
                            #line 311 "src/analyzer/Block.pv"
                            struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type });
                            #line 312 "src/analyzer/Block.pv"
                            variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
                        }

                        #line 315 "src/analyzer/Block.pv"
                        struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                        #line 316 "src/analyzer/Block.pv"
                        String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                        #line 317 "src/analyzer/Block.pv"
                        Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                        #line 319 "src/analyzer/Block.pv"
                        if (Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_") == 0) {
                            #line 320 "src/analyzer/Block.pv"
                            if (Context__set_value(context, variable, variable_type) == 0) {
                                #line 320 "src/analyzer/Block.pv"
                                Context__pop_scope(context);
                                #line 320 "src/analyzer/Block.pv"
                                return false;
                            }
                        }

                        #line 323 "src/analyzer/Block.pv"
                        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                            #line 324 "src/analyzer/Block.pv"
                            Context__pop_scope(context);
                            #line 325 "src/analyzer/Block.pv"
                            Context__pop_scope(context);
                            #line 326 "src/analyzer/Block.pv"
                            Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                            #line 327 "src/analyzer/Block.pv"
                            return false;
                        }

                        #line 330 "src/analyzer/Block.pv"
                        variable_i += 1;
                    }

                    #line 333 "src/analyzer/Block.pv"
                    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                        #line 333 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 333 "src/analyzer/Block.pv"
                        return false;
                    }

                    #line 335 "src/analyzer/Block.pv"
                    if (parameters.length != enum_variant->types.length) {
                        #line 336 "src/analyzer/Block.pv"
                        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 337 "src/analyzer/Block.pv"
                        String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                        #line 338 "src/analyzer/Block.pv"
                        String__append_usize(&message, enum_variant->types.length);
                        #line 339 "src/analyzer/Block.pv"
                        Context__error_token(context, enum_variant_token, String__c_str(&message));
                    }
                } else {
                    #line 342 "src/analyzer/Block.pv"
                    if (enum_variant->types.length > 0) {
                        #line 343 "src/analyzer/Block.pv"
                        struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                        #line 344 "src/analyzer/Block.pv"
                        String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                        #line 345 "src/analyzer/Block.pv"
                        String__append_usize(&message, enum_variant->types.length);
                        #line 346 "src/analyzer/Block.pv"
                        String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                        #line 347 "src/analyzer/Block.pv"
                        Context__error_token(context, enum_variant_token, String__c_str(&message));
                    }
                }

                #line 351 "src/analyzer/Block.pv"
                pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = enum_variant, ._1 = parameters} };
            }
        }

        #line 355 "src/analyzer/Block.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>") == 0) {
            #line 355 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 355 "src/analyzer/Block.pv"
            return false;
        }

        #line 357 "src/analyzer/Block.pv"
        if (Block__parse(block, context, generics, 0) == 0) {
            #line 357 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 357 "src/analyzer/Block.pv"
            return false;
        }

        #line 359 "src/analyzer/Block.pv"
        struct MatchCase match_case = (struct MatchCase) {
            .first_token = first_match_token,
            .type = type,
            .pattern = pattern,
            .body = block,
        };

        #line 366 "src/analyzer/Block.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 368 "src/analyzer/Block.pv"
        Context__pop_scope(context);

        #line 370 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
            #line 371 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 372 "src/analyzer/Block.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 373 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 377 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 377 "src/analyzer/Block.pv"
        return false;
    }

    #line 379 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = { ._0 = expression, ._1 = cases} }));

    #line 381 "src/analyzer/Block.pv"
    return true;
}

#line 384 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 385 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 386 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "while") == 0) {
        #line 386 "src/analyzer/Block.pv"
        return false;
    }

    #line 388 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 389 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 389 "src/analyzer/Block.pv"
        return false;
    }

    #line 391 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 392 "src/analyzer/Block.pv"
    block->is_loop = true;
    #line 393 "src/analyzer/Block.pv"
    if (Block__parse(block, context, generics, 1) == 0) {
        #line 393 "src/analyzer/Block.pv"
        return false;
    }

    #line 395 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = { ._0 = expression, ._1 = block} }));

    #line 397 "src/analyzer/Block.pv"
    return true;
}

#line 400 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables) {
    #line 401 "src/analyzer/Block.pv"
    bool deref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "*");
    #line 402 "src/analyzer/Block.pv"
    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
    #line 403 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

    #line 405 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 405 "src/analyzer/Block.pv"
        return false;
    }

    #line 407 "src/analyzer/Block.pv"
    Array_ForVariable__append(variables, (struct ForVariable) { .deref = deref, .ref = ref, .name = name });

    #line 409 "src/analyzer/Block.pv"
    return true;
}

#line 412 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 413 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);

    #line 415 "src/analyzer/Block.pv"
    struct ForStatement for_statement = ForStatement__new(context->allocator);

    #line 417 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for") == 0) {
        #line 417 "src/analyzer/Block.pv"
        return false;
    }

    #line 419 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 420 "src/analyzer/Block.pv"
        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 421 "src/analyzer/Block.pv"
            if (Block__parse_for_variable(self, context, &for_statement.variables) == 0) {
                #line 421 "src/analyzer/Block.pv"
                return false;
            }

            #line 423 "src/analyzer/Block.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 424 "src/analyzer/Block.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 425 "src/analyzer/Block.pv"
                return false;
            }
        }

        #line 429 "src/analyzer/Block.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 429 "src/analyzer/Block.pv"
            return false;
        }
    } else {
        #line 431 "src/analyzer/Block.pv"
        if (Block__parse_for_variable(self, context, &for_statement.variables) == 0) {
            #line 431 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 434 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "in") == 0) {
        #line 434 "src/analyzer/Block.pv"
        return false;
    }

    #line 436 "src/analyzer/Block.pv"
    struct Token* expression_first_token = Context__current(context);
    #line 437 "src/analyzer/Block.pv"
    for_statement.expression = Expression__parse(context, generics);
    #line 438 "src/analyzer/Block.pv"
    if (for_statement.expression == 0) {
        #line 438 "src/analyzer/Block.pv"
        return false;
    }

    #line 440 "src/analyzer/Block.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&for_statement.expression->return_type, context);

    #line 442 "src/analyzer/Block.pv"
    bool is_range = false;

    #line 444 "src/analyzer/Block.pv"
    switch (for_statement.expression->data.type) {
        #line 445 "src/analyzer/Block.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 445 "src/analyzer/Block.pv"
            struct Expression* target = for_statement.expression->data.invoke_value._0;
            #line 445 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = for_statement.expression->data.invoke_value._1;
            #line 446 "src/analyzer/Block.pv"
            switch (target->return_type.type) {
                #line 447 "src/analyzer/Block.pv"
                case TYPE__ENUM: {
                    #line 447 "src/analyzer/Block.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 447 "src/analyzer/Block.pv"
                    struct GenericMap* generic_map = target->return_type.enum_value._1;
                    #line 448 "src/analyzer/Block.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 449 "src/analyzer/Block.pv"
                        is_range = true;
                        #line 450 "src/analyzer/Block.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__RANGE, .range_value = { ._0 = args.data[0].value, ._1 = args.data[1].value} };
                        #line 451 "src/analyzer/Block.pv"
                        for_statement.iter_type = &generic_map->array.data[0];
                        #line 452 "src/analyzer/Block.pv"
                        for_statement.variables.data[0].type = &generic_map->array.data[0];
                    }
                } break;
                #line 455 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        } break;
        #line 458 "src/analyzer/Block.pv"
        default: {
        } break;
    }

    #line 461 "src/analyzer/Block.pv"
    if (!is_range) {
        #line 462 "src/analyzer/Block.pv"
        struct Token* iter_member = ArenaAllocator__store_Token(context->allocator, *expression_first_token);
        #line 463 "src/analyzer/Block.pv"
        iter_member->value = (struct str){ .ptr = "iter", .length = strlen("iter") };

        #line 465 "src/analyzer/Block.pv"
        struct Type* iter_member_type = Expression__get_member_type(context, &for_statement.expression->return_type, iter_member, false);
        #line 466 "src/analyzer/Block.pv"
        bool iter_member_is_function = false;

        #line 468 "src/analyzer/Block.pv"
        if (iter_member_type != 0) {
            #line 469 "src/analyzer/Block.pv"
            switch (iter_member_type->type) {
                #line 470 "src/analyzer/Block.pv"
                case TYPE__FUNCTION: {
                    #line 470 "src/analyzer/Block.pv"
                    iter_member_is_function = true;
                } break;
                #line 471 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        }

        #line 475 "src/analyzer/Block.pv"
        if (!iter_member_is_function) {
            #line 476 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = for_statement.expression };
            #line 477 "src/analyzer/Block.pv"
            for_statement.iter_type = &for_statement.expression->return_type;
        } else {
            #line 479 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
            #line 480 "src/analyzer/Block.pv"
            Array_InvokeArgument__append(&args, (struct InvokeArgument) { .value = for_statement.expression });

            #line 482 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = Expression__make_type_function_call(context, iter_member, iter_member_type, args, generic_map) };
            #line 483 "src/analyzer/Block.pv"
            for_statement.iter_type = Expression__get_return_type(context, iter_member_type, iter_member, generic_map);
        }

        #line 486 "src/analyzer/Block.pv"
        struct Token value_member = *iter_member;
        #line 487 "src/analyzer/Block.pv"
        value_member.value = (struct str){ .ptr = "value", .length = strlen("value") };

        #line 489 "src/analyzer/Block.pv"
        struct Type* value_member_type = Expression__get_member_type(context, for_statement.iter_type, &value_member, true);
        #line 490 "src/analyzer/Block.pv"
        if (value_member_type == 0) {
            #line 490 "src/analyzer/Block.pv"
            return 0;
        }
        #line 491 "src/analyzer/Block.pv"
        for_statement.value_type = Expression__get_return_type(context, value_member_type, &value_member, generic_map);

        #line 493 "src/analyzer/Block.pv"
        uintptr_t variable_i = 0;
        #line 494 "src/analyzer/Block.pv"
        { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
        #line 494 "src/analyzer/Block.pv"
        while (ArrayIter_ref_ForVariable__next(&__iter)) {
            #line 494 "src/analyzer/Block.pv"
            struct ForVariable* variable = ArrayIter_ref_ForVariable__value(&__iter);

            #line 495 "src/analyzer/Block.pv"
            if (for_statement.variables.length == 1) {
                #line 496 "src/analyzer/Block.pv"
                variable->type = for_statement.value_type;
            } else {
                #line 498 "src/analyzer/Block.pv"
                struct Token value_member = *variable->name;
                #line 499 "src/analyzer/Block.pv"
                struct String value_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 500 "src/analyzer/Block.pv"
                String__append_usize(&value_name, variable_i);
                #line 501 "src/analyzer/Block.pv"
                value_member.type = TOKEN_TYPE__NUMBER;
                #line 502 "src/analyzer/Block.pv"
                value_member.value = String__as_str(&value_name);

                #line 504 "src/analyzer/Block.pv"
                variable->type = Expression__get_member_type(context, Type__deref(for_statement.value_type), &value_member, true);
            }

            #line 507 "src/analyzer/Block.pv"
            if (variable->deref) {
                #line 508 "src/analyzer/Block.pv"
                variable->type = Type__deref(variable->type);
            }

            #line 511 "src/analyzer/Block.pv"
            if (variable->ref) {
                #line 512 "src/analyzer/Block.pv"
                variable->type = Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *variable->type) }, context->allocator);
            }

            #line 515 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable->type, context->type_self, 0);
            #line 516 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 517 "src/analyzer/Block.pv"
            Context__inlay_hint(context, variable->name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);

            #line 519 "src/analyzer/Block.pv"
            variable_i += 1;
        } }
    }

    #line 523 "src/analyzer/Block.pv"
    Context__push_scope(context, self);

    #line 525 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
    #line 525 "src/analyzer/Block.pv"
    while (ArrayIter_ref_ForVariable__next(&__iter)) {
        #line 525 "src/analyzer/Block.pv"
        struct ForVariable* variable2 = ArrayIter_ref_ForVariable__value(&__iter);

        #line 526 "src/analyzer/Block.pv"
        if (Context__set_value(context, variable2->name, variable2->type) == 0) {
            #line 526 "src/analyzer/Block.pv"
            Context__error(context, "set_value");
            #line 526 "src/analyzer/Block.pv"
            return false;
        }
    } }

    #line 529 "src/analyzer/Block.pv"
    for_statement.block = Block__new_ptr(context);
    #line 530 "src/analyzer/Block.pv"
    for_statement.block->is_loop = true;
    #line 531 "src/analyzer/Block.pv"
    if (Block__parse(for_statement.block, context, generics, 0) == 0) {
        #line 531 "src/analyzer/Block.pv"
        return false;
    }

    #line 533 "src/analyzer/Block.pv"
    Context__pop_scope(context);

    #line 535 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = ArenaAllocator__store_ForStatement(context->allocator, for_statement) }));

    #line 537 "src/analyzer/Block.pv"
    return true;
}

#line 540 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 541 "src/analyzer/Block.pv"
    bool top_block_found = false;
    #line 542 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_Scope __iter = Array_Scope__iter(&context->scopes);
    #line 542 "src/analyzer/Block.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 542 "src/analyzer/Block.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 543 "src/analyzer/Block.pv"
        if (top_block_found) {
        } else {
            #line 545 "src/analyzer/Block.pv"
            struct Block* top_block = scope->block;
            #line 546 "src/analyzer/Block.pv"
            if (top_block != 0) {
                #line 547 "src/analyzer/Block.pv"
                top_block->is_top_level_and_has_defer_statements_inside = true;
                #line 548 "src/analyzer/Block.pv"
                top_block_found = true;
            }
        }
    } }

    #line 553 "src/analyzer/Block.pv"
    if (!top_block_found) {
        #line 553 "src/analyzer/Block.pv"
        Context__error(context, "could not find top_block for defer statements");
    }

    #line 555 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "defer") == 0) {
        #line 555 "src/analyzer/Block.pv"
        return false;
    }

    #line 557 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 558 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 559 "src/analyzer/Block.pv"
        if (Block__parse(block, context, generics, 1) == 0) {
            #line 559 "src/analyzer/Block.pv"
            return false;
        }
        #line 560 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__BLOCK, .block_value = block });
    } else {
        #line 562 "src/analyzer/Block.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 563 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 563 "src/analyzer/Block.pv"
            return false;
        }
        #line 564 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__EXPRESSION, .expression_value = expression });
        #line 565 "src/analyzer/Block.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
            #line 565 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 568 "src/analyzer/Block.pv"
    return true;
}

#line 571 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 572 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{") == 0) {
        #line 572 "src/analyzer/Block.pv"
        return false;
    }
    #line 573 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 573 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 575 "src/analyzer/Block.pv"
    while (Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 576 "src/analyzer/Block.pv"
        struct Token* token = &context->tokens[context->pos];
        #line 577 "src/analyzer/Block.pv"
        bool result = true;

        #line 579 "src/analyzer/Block.pv"
        if (Token__eq(token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 580 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 581 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 582 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, 1);
            #line 583 "src/analyzer/Block.pv"
            if (result != 0) {
                #line 583 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 585 "src/analyzer/Block.pv"
            result = Block__parse_defer_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 587 "src/analyzer/Block.pv"
            result = Block__parse_let_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "return")) {
            #line 589 "src/analyzer/Block.pv"
            result = Block__parse_return_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "yield")) {
            #line 591 "src/analyzer/Block.pv"
            result = Block__parse_yield_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "if")) {
            #line 593 "src/analyzer/Block.pv"
            result = Block__parse_if_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "match")) {
            #line 595 "src/analyzer/Block.pv"
            result = Block__parse_match_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "while")) {
            #line 597 "src/analyzer/Block.pv"
            result = Block__parse_while_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "for")) {
            #line 599 "src/analyzer/Block.pv"
            result = Block__parse_for_statement(self, context, generics);
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "continue")) {
            #line 601 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) }));
            #line 602 "src/analyzer/Block.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
                #line 602 "src/analyzer/Block.pv"
                return false;
            }
            #line 603 "src/analyzer/Block.pv"
            result = true;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "break")) {
            #line 605 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) }));
            #line 606 "src/analyzer/Block.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
                #line 606 "src/analyzer/Block.pv"
                return false;
            }
            #line 607 "src/analyzer/Block.pv"
            result = true;
        } else {
            #line 609 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics);
        }

        #line 612 "src/analyzer/Block.pv"
        if (!result) {
            #line 613 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 613 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 614 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 618 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 619 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 622 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 622 "src/analyzer/Block.pv"
        return false;
    }

    #line 624 "src/analyzer/Block.pv"
    return true;
}
