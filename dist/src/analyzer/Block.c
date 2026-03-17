#include <stdio.h>

#include <analyzer/Context.h>
#include <std/Array_Statement.h>
#include <analyzer/statement/Statement.h>
#include <std/Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/Array_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <std/Array_Scope.h>
#include <stdbool.h>
#include <analyzer/Generics.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <analyzer/Type.h>
#include <analyzer/expression/Expression.h>
#include <std/String.h>
#include <analyzer/GenericMap.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/Function.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <std/Array_EnumVariantParameter.h>
#include <analyzer/EnumVariantParameter.h>
#include <std/Array_Type.h>
#include <analyzer/EnumVariant.h>
#include <analyzer/Indirect.h>
#include <analyzer/IndirectType.h>
#include <analyzer/EnumCValue.h>
#include <std/Array_ForVariable.h>
#include <analyzer/statement/ForVariable.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/Enum.h>
#include <std/ArrayIter_ref_ForVariable.h>
#include <analyzer/Scope.h>
#include <std/ArrayIter_ref_Scope.h>

#include <analyzer/Block.h>

#line 16 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context) {
    #line 17 "src/analyzer/Block.pv"
    return (struct Block) {
        .context = context,
        .statements = Array_Statement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .defer_statements = Array_DeferStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 24 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context) {
    #line 25 "src/analyzer/Block.pv"
    return ArenaAllocator__store_Block(context->allocator, Block__new(context));
}

#line 28 "src/analyzer/Block.pv"
bool Block__parse_let_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 29 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 30 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 30 "src/analyzer/Block.pv"
        return false;
    }

    #line 32 "src/analyzer/Block.pv"
    bool is_static = Context__check_next(context, TOKEN_TYPE__KEYWORD, "static");

    #line 34 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 35 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 35 "src/analyzer/Block.pv"
        return false;
    }

    #line 37 "src/analyzer/Block.pv"
    struct Type* type = 0;

    #line 39 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 40 "src/analyzer/Block.pv"
        type = Context__parse_type2(context, generics);
        #line 41 "src/analyzer/Block.pv"
        if (type == 0) {
            #line 41 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 44 "src/analyzer/Block.pv"
    struct Expression* expression = 0;

    #line 46 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 47 "src/analyzer/Block.pv"
        expression = Expression__parse(context, generics);
        #line 48 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 48 "src/analyzer/Block.pv"
            return false;
        }

        #line 50 "src/analyzer/Block.pv"
        if (type == 0) {
            #line 51 "src/analyzer/Block.pv"
            type = &expression->return_type;

            #line 53 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 54 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 55 "src/analyzer/Block.pv"
            Context__inlay_hint(context, name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
        } else {
            #line 57 "src/analyzer/Block.pv"
            Expression__validate_type(expression, context, type, true);
        }
    }

    #line 61 "src/analyzer/Block.pv"
    if (!Context__set_value(context, name, type)) {
        #line 61 "src/analyzer/Block.pv"
        Context__error(context, "set_value");
        #line 61 "src/analyzer/Block.pv"
        return false;
    }
    #line 62 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 62 "src/analyzer/Block.pv"
        return false;
    }

    #line 64 "src/analyzer/Block.pv"
    struct LetStatement* let_statement = ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement) {
        .is_static = is_static,
        .name = name,
        .type = type,
        .value = expression,
    });

    #line 71 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement }));

    #line 73 "src/analyzer/Block.pv"
    return true;
}

#line 76 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 77 "src/analyzer/Block.pv"
    struct Array_DeferStatement defer_statements = Context__get_defer_statements(context);

    #line 79 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 80 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "return")) {
        #line 80 "src/analyzer/Block.pv"
        return false;
    }

    #line 82 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 83 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = 0, ._1 = defer_statements} };
        #line 84 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 85 "src/analyzer/Block.pv"
        return true;
    }

    #line 88 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 89 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 89 "src/analyzer/Block.pv"
        return false;
    }
    #line 90 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 90 "src/analyzer/Block.pv"
        return false;
    }

    #line 92 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 94 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = expression, ._1 = defer_statements} }));

    #line 96 "src/analyzer/Block.pv"
    return true;
}

#line 99 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 100 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 101 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield")) {
        #line 101 "src/analyzer/Block.pv"
        return false;
    }

    #line 103 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 104 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = 0 };
        #line 105 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 106 "src/analyzer/Block.pv"
        return true;
    }

    #line 109 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 110 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 110 "src/analyzer/Block.pv"
        return false;
    }
    #line 111 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 111 "src/analyzer/Block.pv"
        return false;
    }

    #line 113 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 115 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = expression }));

    #line 117 "src/analyzer/Block.pv"
    return true;
}

#line 120 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 121 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 122 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 123 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 123 "src/analyzer/Block.pv"
        return false;
    }

    #line 125 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 126 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 127 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 127 "src/analyzer/Block.pv"
            return false;
        }

        #line 129 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 130 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 130 "src/analyzer/Block.pv"
            return false;
        }

        #line 132 "src/analyzer/Block.pv"
        Expression__validate_type(value, context, &expression->return_type, true);

        #line 134 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = { ._0 = expression, ._1 = operator, ._2 = value} }));
    } else {
        #line 136 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression }));
    }

    #line 139 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 139 "src/analyzer/Block.pv"
        return false;
    }

    #line 141 "src/analyzer/Block.pv"
    return true;
}

#line 144 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 145 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 146 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 146 "src/analyzer/Block.pv"
        return false;
    }

    #line 148 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 149 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 149 "src/analyzer/Block.pv"
        return false;
    }

    #line 151 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 152 "src/analyzer/Block.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 152 "src/analyzer/Block.pv"
        return false;
    }

    #line 154 "src/analyzer/Block.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 155 "src/analyzer/Block.pv"
    struct Expression* else_expression = 0;
    #line 156 "src/analyzer/Block.pv"
    struct Block* else_block = 0;
    #line 157 "src/analyzer/Block.pv"
    bool else_end = false;

    #line 159 "src/analyzer/Block.pv"
    while (else_end == 0 && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 160 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 161 "src/analyzer/Block.pv"
            else_expression = Expression__parse(context, generics);
            #line 162 "src/analyzer/Block.pv"
            if (else_expression == 0) {
                #line 162 "src/analyzer/Block.pv"
                return false;
            }
        } else {
            #line 164 "src/analyzer/Block.pv"
            else_expression = 0;
            #line 165 "src/analyzer/Block.pv"
            else_end = true;
        }

        #line 168 "src/analyzer/Block.pv"
        else_block = Block__new_ptr(context);
        #line 169 "src/analyzer/Block.pv"
        if (!Block__parse(else_block, context, generics, true)) {
            #line 169 "src/analyzer/Block.pv"
            return false;
        }

        #line 171 "src/analyzer/Block.pv"
        struct ElseStatement else_statement = (struct ElseStatement) {
            .expression = else_expression,
            .block = else_block,
        };

        #line 176 "src/analyzer/Block.pv"
        Array_ElseStatement__append(&else_statements, else_statement);
    }

    #line 179 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = { ._0 = expression, ._1 = block, ._2 = else_statements} }));

    #line 181 "src/analyzer/Block.pv"
    return true;
}

#line 184 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 185 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 186 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "match")) {
        #line 186 "src/analyzer/Block.pv"
        return false;
    }

    #line 188 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 189 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 189 "src/analyzer/Block.pv"
        return false;
    }

    #line 191 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 191 "src/analyzer/Block.pv"
        return false;
    }

    #line 193 "src/analyzer/Block.pv"
    struct Array_MatchCase cases = Array_MatchCase__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 195 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 196 "src/analyzer/Block.pv"
        struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 197 "src/analyzer/Block.pv"
        struct Token* first_match_token = Context__current(context);

        #line 199 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 200 "src/analyzer/Block.pv"
        Context__push_scope(context, block);

        #line 202 "src/analyzer/Block.pv"
        struct Type* type = 0;

        #line 204 "src/analyzer/Block.pv"
        if (Context__check_value(context, TOKEN_TYPE__IDENTIFIER, "typeid")) {
            #line 205 "src/analyzer/Block.pv"
            struct Expression* expression = Expression__parse(context, generics);
            #line 206 "src/analyzer/Block.pv"
            if (!expression) {
                #line 206 "src/analyzer/Block.pv"
                return false;
            }

            #line 208 "src/analyzer/Block.pv"
            pattern = (struct MatchPattern) { .type = MATCH_PATTERN__EXPRESSION, .expression_value = expression };
        } else if (!Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "_")) {
            #line 210 "src/analyzer/Block.pv"
            struct Token* token = Context__current(context);
            #line 211 "src/analyzer/Block.pv"
            if (token == 0) {
                #line 211 "src/analyzer/Block.pv"
                return false;
            }

            #line 213 "src/analyzer/Block.pv"
            type = Context__get_value(context, token->value);

            #line 215 "src/analyzer/Block.pv"
            if (type != 0) {
                #line 216 "src/analyzer/Block.pv"
                Context__next_token(context);
                #line 217 "src/analyzer/Block.pv"
                pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = token };
            } else {
                #line 219 "src/analyzer/Block.pv"
                type = Context__parse_type2(context, generics);
                #line 220 "src/analyzer/Block.pv"
                if (type == 0) {
                    #line 221 "src/analyzer/Block.pv"
                    return false;
                } else if (!Type__is_enum(type)) {
                    #line 223 "src/analyzer/Block.pv"
                    Context__error_token(context, token, "Type is not an enum");
                    #line 224 "src/analyzer/Block.pv"
                    return false;
                }

                #line 227 "src/analyzer/Block.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
                    #line 227 "src/analyzer/Block.pv"
                    return false;
                }

                #line 237 "src/analyzer/Block.pv"
                struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                #line 238 "src/analyzer/Block.pv"
                if (enum_variant_token == 0) {
                    #line 238 "src/analyzer/Block.pv"
                    return false;
                }

                #line 240 "src/analyzer/Block.pv"
                struct GenericMap* generic_map = 0;

                #line 242 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 243 "src/analyzer/Block.pv"
                    case TYPE__SELF: {
                        #line 244 "src/analyzer/Block.pv"
                        type = context->type_self;
                    } break;
                    #line 246 "src/analyzer/Block.pv"
                    default: {
                    } break;
                }

                #line 249 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 250 "src/analyzer/Block.pv"
                    case TYPE__ENUM: {
                        #line 250 "src/analyzer/Block.pv"
                        struct GenericMap* generics = type->enum_value._1;
                        #line 250 "src/analyzer/Block.pv"
                        generic_map = generics;
                    } break;
                    #line 251 "src/analyzer/Block.pv"
                    case TYPE__ENUM_C: {
                    } break;
                    #line 252 "src/analyzer/Block.pv"
                    default: {
                        #line 253 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 254 "src/analyzer/Block.pv"
                        Context__error(context, "Not an enum type");
                        #line 255 "src/analyzer/Block.pv"
                        return false;
                    } break;
                }

                #line 259 "src/analyzer/Block.pv"
                struct EnumVariantResult enum_variant_result = Expression__get_enum_variant(context, type, enum_variant_token);
                #line 260 "src/analyzer/Block.pv"
                switch (enum_variant_result.type) {
                    #line 261 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__NONE: {
                        #line 262 "src/analyzer/Block.pv"
                        Context__error(context, "Could not find enum variant");
                        #line 263 "src/analyzer/Block.pv"
                        return false;
                    } break;
                    #line 265 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                        #line 265 "src/analyzer/Block.pv"
                        struct EnumVariant* enum_variant = enum_variant_result.enumvariant_value;
                        #line 266 "src/analyzer/Block.pv"
                        struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 268 "src/analyzer/Block.pv"
                        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 269 "src/analyzer/Block.pv"
                            uintptr_t variable_i = 0;

                            #line 271 "src/analyzer/Block.pv"
                            while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 272 "src/analyzer/Block.pv"
                                bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                                #line 273 "src/analyzer/Block.pv"
                                struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                                #line 274 "src/analyzer/Block.pv"
                                if (variable == 0) {
                                    #line 274 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 274 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 276 "src/analyzer/Block.pv"
                                Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                                #line 278 "src/analyzer/Block.pv"
                                struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                                #line 279 "src/analyzer/Block.pv"
                                if (variable_type == 0) {
                                    #line 279 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 281 "src/analyzer/Block.pv"
                                if (ref) {
                                    #line 282 "src/analyzer/Block.pv"
                                    struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type });
                                    #line 283 "src/analyzer/Block.pv"
                                    variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
                                }

                                #line 286 "src/analyzer/Block.pv"
                                struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                                #line 287 "src/analyzer/Block.pv"
                                String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                                #line 288 "src/analyzer/Block.pv"
                                Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                                #line 290 "src/analyzer/Block.pv"
                                if (!Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                                    #line 291 "src/analyzer/Block.pv"
                                    if (!Context__set_value(context, variable, variable_type)) {
                                        #line 291 "src/analyzer/Block.pv"
                                        Context__pop_scope(context);
                                        #line 291 "src/analyzer/Block.pv"
                                        return false;
                                    }
                                }

                                #line 294 "src/analyzer/Block.pv"
                                if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                    #line 295 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 296 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 297 "src/analyzer/Block.pv"
                                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                    #line 298 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 301 "src/analyzer/Block.pv"
                                variable_i += 1;
                            }

                            #line 304 "src/analyzer/Block.pv"
                            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 304 "src/analyzer/Block.pv"
                                Context__pop_scope(context);
                                #line 304 "src/analyzer/Block.pv"
                                return false;
                            }

                            #line 306 "src/analyzer/Block.pv"
                            if (parameters.length != enum_variant->types.length) {
                                #line 307 "src/analyzer/Block.pv"
                                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                                #line 308 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                                #line 309 "src/analyzer/Block.pv"
                                String__append_usize(&message, enum_variant->types.length);
                                #line 310 "src/analyzer/Block.pv"
                                Context__error_token(context, enum_variant_token, String__c_str(&message));
                            }
                        } else {
                            #line 313 "src/analyzer/Block.pv"
                            if (enum_variant->types.length > 0) {
                                #line 314 "src/analyzer/Block.pv"
                                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                                #line 315 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                                #line 316 "src/analyzer/Block.pv"
                                String__append_usize(&message, enum_variant->types.length);
                                #line 317 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                                #line 318 "src/analyzer/Block.pv"
                                Context__error_token(context, enum_variant_token, String__c_str(&message));
                            }
                        }

                        #line 322 "src/analyzer/Block.pv"
                        pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = enum_variant, ._1 = parameters} };
                    } break;
                    #line 324 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                        #line 324 "src/analyzer/Block.pv"
                        struct EnumCValue* enum_variant = enum_variant_result.enumcvalue_value;
                        #line 325 "src/analyzer/Block.pv"
                        pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE, .enumcvalue_value = enum_variant };
                    } break;
                }
            }
        }

        #line 331 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>")) {
            #line 331 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 331 "src/analyzer/Block.pv"
            return false;
        }

        #line 333 "src/analyzer/Block.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 333 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 333 "src/analyzer/Block.pv"
            return false;
        }

        #line 335 "src/analyzer/Block.pv"
        struct MatchCase match_case = (struct MatchCase) {
            .first_token = first_match_token,
            .type = type,
            .pattern = pattern,
            .body = block,
        };

        #line 342 "src/analyzer/Block.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 344 "src/analyzer/Block.pv"
        Context__pop_scope(context);

        #line 346 "src/analyzer/Block.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 347 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 348 "src/analyzer/Block.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 349 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 353 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 353 "src/analyzer/Block.pv"
        return false;
    }

    #line 355 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = { ._0 = expression, ._1 = cases} }));

    #line 357 "src/analyzer/Block.pv"
    return true;
}

#line 360 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 361 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 362 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "while")) {
        #line 362 "src/analyzer/Block.pv"
        return false;
    }

    #line 364 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 365 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 365 "src/analyzer/Block.pv"
        return false;
    }

    #line 367 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 368 "src/analyzer/Block.pv"
    block->is_loop = true;
    #line 369 "src/analyzer/Block.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 369 "src/analyzer/Block.pv"
        return false;
    }

    #line 371 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = { ._0 = expression, ._1 = block} }));

    #line 373 "src/analyzer/Block.pv"
    return true;
}

#line 376 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables) {
    #line 377 "src/analyzer/Block.pv"
    bool deref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "*");
    #line 378 "src/analyzer/Block.pv"
    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
    #line 379 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

    #line 381 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 381 "src/analyzer/Block.pv"
        return false;
    }

    #line 383 "src/analyzer/Block.pv"
    Array_ForVariable__append(variables, (struct ForVariable) { .deref = deref, .ref = ref, .name = name });

    #line 385 "src/analyzer/Block.pv"
    return true;
}

#line 388 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 389 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);

    #line 391 "src/analyzer/Block.pv"
    struct ForStatement for_statement = ForStatement__new(context->allocator);

    #line 393 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
        #line 393 "src/analyzer/Block.pv"
        return false;
    }

    #line 395 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 396 "src/analyzer/Block.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 397 "src/analyzer/Block.pv"
            if (!Block__parse_for_variable(self, context, &for_statement.variables)) {
                #line 397 "src/analyzer/Block.pv"
                return false;
            }

            #line 399 "src/analyzer/Block.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 400 "src/analyzer/Block.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 401 "src/analyzer/Block.pv"
                return false;
            }
        }

        #line 405 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 405 "src/analyzer/Block.pv"
            return false;
        }
    } else {
        #line 407 "src/analyzer/Block.pv"
        if (!Block__parse_for_variable(self, context, &for_statement.variables)) {
            #line 407 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 410 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "in")) {
        #line 410 "src/analyzer/Block.pv"
        return false;
    }

    #line 412 "src/analyzer/Block.pv"
    struct Token* expression_first_token = Context__current(context);
    #line 413 "src/analyzer/Block.pv"
    for_statement.expression = Expression__parse(context, generics);
    #line 414 "src/analyzer/Block.pv"
    if (for_statement.expression == 0) {
        #line 414 "src/analyzer/Block.pv"
        return false;
    }

    #line 416 "src/analyzer/Block.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&for_statement.expression->return_type, context);

    #line 418 "src/analyzer/Block.pv"
    bool is_range = false;

    #line 420 "src/analyzer/Block.pv"
    switch (for_statement.expression->data.type) {
        #line 421 "src/analyzer/Block.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 421 "src/analyzer/Block.pv"
            struct Expression* target = for_statement.expression->data.invoke_value._0;
            #line 421 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = for_statement.expression->data.invoke_value._1;
            #line 422 "src/analyzer/Block.pv"
            switch (target->return_type.type) {
                #line 423 "src/analyzer/Block.pv"
                case TYPE__ENUM: {
                    #line 423 "src/analyzer/Block.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 423 "src/analyzer/Block.pv"
                    struct GenericMap* generic_map = target->return_type.enum_value._1;
                    #line 424 "src/analyzer/Block.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 425 "src/analyzer/Block.pv"
                        is_range = true;
                        #line 426 "src/analyzer/Block.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__RANGE, .range_value = { ._0 = args.data[0].value, ._1 = args.data[1].value} };
                        #line 427 "src/analyzer/Block.pv"
                        for_statement.iter_type = &generic_map->array.data[0];
                        #line 428 "src/analyzer/Block.pv"
                        for_statement.variables.data[0].type = &generic_map->array.data[0];
                    }
                } break;
                #line 431 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        } break;
        #line 434 "src/analyzer/Block.pv"
        default: {
        } break;
    }

    #line 437 "src/analyzer/Block.pv"
    if (!is_range) {
        #line 438 "src/analyzer/Block.pv"
        struct Token* iter_member = ArenaAllocator__store_Token(context->allocator, *expression_first_token);
        #line 439 "src/analyzer/Block.pv"
        iter_member->value = (struct str){ .ptr = "iter", .length = strlen("iter") };

        #line 441 "src/analyzer/Block.pv"
        struct Type* iter_member_type = Expression__get_member_type(context, &for_statement.expression->return_type, iter_member, false);
        #line 442 "src/analyzer/Block.pv"
        bool iter_member_is_function = false;

        #line 444 "src/analyzer/Block.pv"
        if (iter_member_type != 0) {
            #line 445 "src/analyzer/Block.pv"
            switch (iter_member_type->type) {
                #line 446 "src/analyzer/Block.pv"
                case TYPE__FUNCTION: {
                    #line 446 "src/analyzer/Block.pv"
                    iter_member_is_function = true;
                } break;
                #line 447 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        }

        #line 451 "src/analyzer/Block.pv"
        if (!iter_member_is_function) {
            #line 452 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = for_statement.expression };
            #line 453 "src/analyzer/Block.pv"
            for_statement.iter_type = &for_statement.expression->return_type;
        } else {
            #line 455 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
            #line 456 "src/analyzer/Block.pv"
            Array_InvokeArgument__append(&args, (struct InvokeArgument) { .value = for_statement.expression });

            #line 458 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = Expression__make_type_function_call(context, iter_member, iter_member_type, args, generic_map) };
            #line 459 "src/analyzer/Block.pv"
            for_statement.iter_type = Expression__get_return_type(context, iter_member_type, iter_member, generic_map);
        }

        #line 462 "src/analyzer/Block.pv"
        struct Token value_member = *iter_member;
        #line 463 "src/analyzer/Block.pv"
        value_member.value = (struct str){ .ptr = "value", .length = strlen("value") };

        #line 465 "src/analyzer/Block.pv"
        struct Type* value_member_type = Expression__get_member_type(context, for_statement.iter_type, &value_member, true);
        #line 466 "src/analyzer/Block.pv"
        if (value_member_type == 0) {
            #line 466 "src/analyzer/Block.pv"
            return false;
        }
        #line 467 "src/analyzer/Block.pv"
        for_statement.value_type = Expression__get_return_type(context, value_member_type, &value_member, generic_map);

        #line 469 "src/analyzer/Block.pv"
        uintptr_t variable_i = 0;
        #line 470 "src/analyzer/Block.pv"
        { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
        #line 470 "src/analyzer/Block.pv"
        while (ArrayIter_ref_ForVariable__next(&__iter)) {
            #line 470 "src/analyzer/Block.pv"
            struct ForVariable* variable = ArrayIter_ref_ForVariable__value(&__iter);

            #line 471 "src/analyzer/Block.pv"
            if (for_statement.variables.length == 1) {
                #line 472 "src/analyzer/Block.pv"
                variable->type = for_statement.value_type;
            } else {
                #line 474 "src/analyzer/Block.pv"
                struct Token value_member = *variable->name;
                #line 475 "src/analyzer/Block.pv"
                struct String value_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 476 "src/analyzer/Block.pv"
                String__append_usize(&value_name, variable_i);
                #line 477 "src/analyzer/Block.pv"
                value_member.type = TOKEN_TYPE__NUMBER;
                #line 478 "src/analyzer/Block.pv"
                value_member.value = String__as_str(&value_name);

                #line 480 "src/analyzer/Block.pv"
                variable->type = Expression__get_member_type(context, Type__deref(for_statement.value_type), &value_member, true);
            }

            #line 483 "src/analyzer/Block.pv"
            if (variable->deref) {
                #line 484 "src/analyzer/Block.pv"
                variable->type = Type__deref(variable->type);
            }

            #line 487 "src/analyzer/Block.pv"
            if (variable->ref) {
                #line 488 "src/analyzer/Block.pv"
                variable->type = Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *variable->type) }, context->allocator);
            }

            #line 491 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable->type, context->type_self, 0);
            #line 492 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 493 "src/analyzer/Block.pv"
            Context__inlay_hint(context, variable->name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);

            #line 495 "src/analyzer/Block.pv"
            variable_i += 1;
        } }
    }

    #line 499 "src/analyzer/Block.pv"
    Context__push_scope(context, self);

    #line 501 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
    #line 501 "src/analyzer/Block.pv"
    while (ArrayIter_ref_ForVariable__next(&__iter)) {
        #line 501 "src/analyzer/Block.pv"
        struct ForVariable* variable2 = ArrayIter_ref_ForVariable__value(&__iter);

        #line 502 "src/analyzer/Block.pv"
        if (!Context__set_value(context, variable2->name, variable2->type)) {
            #line 502 "src/analyzer/Block.pv"
            Context__error(context, "set_value");
            #line 502 "src/analyzer/Block.pv"
            return false;
        }
    } }

    #line 505 "src/analyzer/Block.pv"
    for_statement.block = Block__new_ptr(context);
    #line 506 "src/analyzer/Block.pv"
    for_statement.block->is_loop = true;
    #line 507 "src/analyzer/Block.pv"
    if (!Block__parse(for_statement.block, context, generics, false)) {
        #line 507 "src/analyzer/Block.pv"
        return false;
    }

    #line 509 "src/analyzer/Block.pv"
    Context__pop_scope(context);

    #line 511 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = ArenaAllocator__store_ForStatement(context->allocator, for_statement) }));

    #line 513 "src/analyzer/Block.pv"
    return true;
}

#line 516 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 517 "src/analyzer/Block.pv"
    bool top_block_found = false;
    #line 518 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_Scope __iter = Array_Scope__iter(&context->scopes);
    #line 518 "src/analyzer/Block.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 518 "src/analyzer/Block.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 519 "src/analyzer/Block.pv"
        if (top_block_found) {
        } else {
            #line 521 "src/analyzer/Block.pv"
            struct Block* top_block = scope->block;
            #line 522 "src/analyzer/Block.pv"
            if (top_block != 0) {
                #line 523 "src/analyzer/Block.pv"
                top_block->is_top_level_and_has_defer_statements_inside = true;
                #line 524 "src/analyzer/Block.pv"
                top_block_found = true;
            }
        }
    } }

    #line 529 "src/analyzer/Block.pv"
    if (!top_block_found) {
        #line 529 "src/analyzer/Block.pv"
        Context__error(context, "could not find top_block for defer statements");
    }

    #line 531 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "defer")) {
        #line 531 "src/analyzer/Block.pv"
        return false;
    }

    #line 533 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 534 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 535 "src/analyzer/Block.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 535 "src/analyzer/Block.pv"
            return false;
        }
        #line 536 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__BLOCK, .block_value = block });
    } else {
        #line 538 "src/analyzer/Block.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 539 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 539 "src/analyzer/Block.pv"
            return false;
        }
        #line 540 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__EXPRESSION, .expression_value = expression });
        #line 541 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 541 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 544 "src/analyzer/Block.pv"
    return true;
}

#line 547 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 548 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 548 "src/analyzer/Block.pv"
        return false;
    }
    #line 549 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 549 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 551 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 552 "src/analyzer/Block.pv"
        struct Token* token = &context->tokens[context->pos];
        #line 553 "src/analyzer/Block.pv"
        bool result = true;

        #line 555 "src/analyzer/Block.pv"
        if (Token__eq(token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 556 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 557 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 558 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, true);
            #line 559 "src/analyzer/Block.pv"
            if (result) {
                #line 559 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 561 "src/analyzer/Block.pv"
            result = Block__parse_defer_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 563 "src/analyzer/Block.pv"
            result = Block__parse_let_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "return")) {
            #line 565 "src/analyzer/Block.pv"
            result = Block__parse_return_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "yield")) {
            #line 567 "src/analyzer/Block.pv"
            result = Block__parse_yield_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "if")) {
            #line 569 "src/analyzer/Block.pv"
            result = Block__parse_if_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "match")) {
            #line 571 "src/analyzer/Block.pv"
            result = Block__parse_match_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "while")) {
            #line 573 "src/analyzer/Block.pv"
            result = Block__parse_while_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "for")) {
            #line 575 "src/analyzer/Block.pv"
            result = Block__parse_for_statement(self, context, generics);
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "continue")) {
            #line 577 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) }));
            #line 578 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 578 "src/analyzer/Block.pv"
                return false;
            }
            #line 579 "src/analyzer/Block.pv"
            result = true;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "break")) {
            #line 581 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) }));
            #line 582 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 582 "src/analyzer/Block.pv"
                return false;
            }
            #line 583 "src/analyzer/Block.pv"
            result = true;
        } else {
            #line 585 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics);
        }

        #line 588 "src/analyzer/Block.pv"
        if (!result) {
            #line 589 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 589 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 590 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 594 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 595 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 598 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 598 "src/analyzer/Block.pv"
        return false;
    }

    #line 600 "src/analyzer/Block.pv"
    return true;
}
