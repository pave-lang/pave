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
#include <std/Array_ElseStatement.h>
#include <analyzer/ElseStatement.h>
#include <std/Array_MatchCase.h>
#include <analyzer/MatchCase.h>
#include <analyzer/MatchPattern.h>
#include <analyzer/EnumVariantResult.h>
#include <std/Array_EnumVariantParameter.h>
#include <analyzer/EnumVariantParameter.h>
#include <std/Array_Type.h>
#include <analyzer/EnumVariant.h>
#include <analyzer/Indirect.h>
#include <analyzer/IndirectType.h>
#include <analyzer/EnumCValue.h>
#include <std/Array_ForVariable.h>
#include <analyzer/ForVariable.h>
#include <analyzer/ForStatement.h>
#include <analyzer/ExpressionData.h>
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

    #line 59 "src/analyzer/Block.pv"
    if (Context__set_value(context, name, type) == 0) {
        #line 59 "src/analyzer/Block.pv"
        Context__error(context, "set_value");
        #line 59 "src/analyzer/Block.pv"
        return false;
    }
    #line 60 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 60 "src/analyzer/Block.pv"
        return false;
    }

    #line 62 "src/analyzer/Block.pv"
    struct LetStatement* let_statement = ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement) {
        .is_static = is_static,
        .name = name,
        .type = type,
        .value = expression,
    });

    #line 69 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement }));

    #line 71 "src/analyzer/Block.pv"
    return true;
}

#line 74 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 75 "src/analyzer/Block.pv"
    struct Array_DeferStatement defer_statements = Context__get_defer_statements(context);

    #line 77 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 78 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "return") == 0) {
        #line 78 "src/analyzer/Block.pv"
        return false;
    }

    #line 80 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 81 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = 0, ._1 = defer_statements} };
        #line 82 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 83 "src/analyzer/Block.pv"
        return true;
    }

    #line 86 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 87 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 87 "src/analyzer/Block.pv"
        return false;
    }
    #line 88 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 88 "src/analyzer/Block.pv"
        return false;
    }

    #line 90 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type);

    #line 92 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = expression, ._1 = defer_statements} }));

    #line 94 "src/analyzer/Block.pv"
    return true;
}

#line 97 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 98 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 99 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield") == 0) {
        #line 99 "src/analyzer/Block.pv"
        return false;
    }

    #line 101 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 102 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = 0 };
        #line 103 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 104 "src/analyzer/Block.pv"
        return true;
    }

    #line 107 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 108 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 108 "src/analyzer/Block.pv"
        return false;
    }
    #line 109 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 109 "src/analyzer/Block.pv"
        return false;
    }

    #line 111 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type);

    #line 113 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = expression }));

    #line 115 "src/analyzer/Block.pv"
    return true;
}

#line 118 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 119 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 120 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 121 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 121 "src/analyzer/Block.pv"
        return false;
    }

    #line 123 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 124 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 125 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 125 "src/analyzer/Block.pv"
            return false;
        }

        #line 127 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 128 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 128 "src/analyzer/Block.pv"
            return false;
        }

        #line 130 "src/analyzer/Block.pv"
        Expression__validate_type(value, context, &expression->return_type);

        #line 132 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = { ._0 = expression, ._1 = operator, ._2 = value} }));
    } else {
        #line 134 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression }));
    }

    #line 137 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
        #line 137 "src/analyzer/Block.pv"
        return false;
    }

    #line 139 "src/analyzer/Block.pv"
    return true;
}

#line 142 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 143 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 144 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if") == 0) {
        #line 144 "src/analyzer/Block.pv"
        return false;
    }

    #line 146 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 147 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 147 "src/analyzer/Block.pv"
        return false;
    }

    #line 149 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 150 "src/analyzer/Block.pv"
    if (Block__parse(block, context, generics, 1) == 0) {
        #line 150 "src/analyzer/Block.pv"
        return false;
    }

    #line 152 "src/analyzer/Block.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 153 "src/analyzer/Block.pv"
    struct Expression* else_expression = 0;
    #line 154 "src/analyzer/Block.pv"
    struct Block* else_block = 0;
    #line 155 "src/analyzer/Block.pv"
    bool else_end = false;

    #line 157 "src/analyzer/Block.pv"
    while (else_end == 0 && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 158 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 159 "src/analyzer/Block.pv"
            else_expression = Expression__parse(context, generics);
            #line 160 "src/analyzer/Block.pv"
            if (else_expression == 0) {
                #line 160 "src/analyzer/Block.pv"
                return false;
            }
        } else {
            #line 162 "src/analyzer/Block.pv"
            else_expression = 0;
            #line 163 "src/analyzer/Block.pv"
            else_end = 1;
        }

        #line 166 "src/analyzer/Block.pv"
        else_block = Block__new_ptr(context);
        #line 167 "src/analyzer/Block.pv"
        if (Block__parse(else_block, context, generics, 1) == 0) {
            #line 167 "src/analyzer/Block.pv"
            return false;
        }

        #line 169 "src/analyzer/Block.pv"
        struct ElseStatement else_statement = (struct ElseStatement) {
            .expression = else_expression,
            .block = else_block,
        };

        #line 174 "src/analyzer/Block.pv"
        Array_ElseStatement__append(&else_statements, else_statement);
    }

    #line 177 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = { ._0 = expression, ._1 = block, ._2 = else_statements} }));

    #line 179 "src/analyzer/Block.pv"
    return true;
}

#line 182 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 183 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 184 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "match") == 0) {
        #line 184 "src/analyzer/Block.pv"
        return false;
    }

    #line 186 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 187 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 187 "src/analyzer/Block.pv"
        return false;
    }

    #line 189 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{") == 0) {
        #line 189 "src/analyzer/Block.pv"
        return false;
    }

    #line 191 "src/analyzer/Block.pv"
    struct Array_MatchCase cases = Array_MatchCase__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 193 "src/analyzer/Block.pv"
    while (Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 194 "src/analyzer/Block.pv"
        struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 195 "src/analyzer/Block.pv"
        struct Token* first_match_token = Context__current(context);

        #line 197 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 198 "src/analyzer/Block.pv"
        Context__push_scope(context, block);

        #line 200 "src/analyzer/Block.pv"
        struct Type* type = 0;

        #line 202 "src/analyzer/Block.pv"
        if (!Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "_")) {
            #line 203 "src/analyzer/Block.pv"
            struct Token* token = Context__current(context);
            #line 204 "src/analyzer/Block.pv"
            if (token == 0) {
                #line 204 "src/analyzer/Block.pv"
                return false;
            }

            #line 206 "src/analyzer/Block.pv"
            type = Context__get_value(context, token->value);

            #line 208 "src/analyzer/Block.pv"
            if (type != 0) {
                #line 209 "src/analyzer/Block.pv"
                Context__next_token(context);
                #line 210 "src/analyzer/Block.pv"
                pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = token };
            } else {
                #line 212 "src/analyzer/Block.pv"
                type = Context__parse_type2(context, generics);
                #line 213 "src/analyzer/Block.pv"
                if (!Type__is_enum(type)) {
                    #line 214 "src/analyzer/Block.pv"
                    Context__error_token(context, token, "Type is not an enum");
                    #line 215 "src/analyzer/Block.pv"
                    return false;
                }

                #line 218 "src/analyzer/Block.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
                    #line 218 "src/analyzer/Block.pv"
                    return false;
                }

                #line 228 "src/analyzer/Block.pv"
                struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                #line 229 "src/analyzer/Block.pv"
                if (enum_variant_token == 0) {
                    #line 229 "src/analyzer/Block.pv"
                    return false;
                }

                #line 231 "src/analyzer/Block.pv"
                struct GenericMap* generic_map = 0;

                #line 233 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 234 "src/analyzer/Block.pv"
                    case TYPE__SELF: {
                        #line 235 "src/analyzer/Block.pv"
                        type = context->type_self;
                    } break;
                    #line 237 "src/analyzer/Block.pv"
                    default: {
                    } break;
                }

                #line 240 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 241 "src/analyzer/Block.pv"
                    case TYPE__ENUM: {
                        #line 241 "src/analyzer/Block.pv"
                        struct GenericMap* generics = type->enum_value._1;
                        #line 241 "src/analyzer/Block.pv"
                        generic_map = generics;
                    } break;
                    #line 242 "src/analyzer/Block.pv"
                    case TYPE__ENUM_C: {
                    } break;
                    #line 243 "src/analyzer/Block.pv"
                    default: {
                        #line 244 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 245 "src/analyzer/Block.pv"
                        Context__error(context, "Not an enum type");
                        #line 246 "src/analyzer/Block.pv"
                        return false;
                    } break;
                }

                #line 250 "src/analyzer/Block.pv"
                struct EnumVariantResult enum_variant_result = Expression__get_enum_variant(context, type, enum_variant_token);
                #line 251 "src/analyzer/Block.pv"
                switch (enum_variant_result.type) {
                    #line 252 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__NONE: {
                        #line 253 "src/analyzer/Block.pv"
                        Context__error(context, "Could not find enum variant");
                        #line 254 "src/analyzer/Block.pv"
                        return false;
                    } break;
                    #line 256 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                        #line 256 "src/analyzer/Block.pv"
                        struct EnumVariant* enum_variant = enum_variant_result.enumvariant_value;
                        #line 257 "src/analyzer/Block.pv"
                        struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 259 "src/analyzer/Block.pv"
                        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 260 "src/analyzer/Block.pv"
                            uintptr_t variable_i = 0;

                            #line 262 "src/analyzer/Block.pv"
                            while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                                #line 263 "src/analyzer/Block.pv"
                                bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                                #line 264 "src/analyzer/Block.pv"
                                struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                                #line 265 "src/analyzer/Block.pv"
                                if (variable == 0) {
                                    #line 265 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 265 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 267 "src/analyzer/Block.pv"
                                Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                                #line 269 "src/analyzer/Block.pv"
                                struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                                #line 270 "src/analyzer/Block.pv"
                                if (variable_type == 0) {
                                    #line 270 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 272 "src/analyzer/Block.pv"
                                if (ref) {
                                    #line 273 "src/analyzer/Block.pv"
                                    struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type });
                                    #line 274 "src/analyzer/Block.pv"
                                    variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
                                }

                                #line 277 "src/analyzer/Block.pv"
                                struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                                #line 278 "src/analyzer/Block.pv"
                                String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                                #line 279 "src/analyzer/Block.pv"
                                Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                                #line 281 "src/analyzer/Block.pv"
                                if (Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_") == 0) {
                                    #line 282 "src/analyzer/Block.pv"
                                    if (Context__set_value(context, variable, variable_type) == 0) {
                                        #line 282 "src/analyzer/Block.pv"
                                        Context__pop_scope(context);
                                        #line 282 "src/analyzer/Block.pv"
                                        return false;
                                    }
                                }

                                #line 285 "src/analyzer/Block.pv"
                                if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                                    #line 286 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 287 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 288 "src/analyzer/Block.pv"
                                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                    #line 289 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 292 "src/analyzer/Block.pv"
                                variable_i += 1;
                            }

                            #line 295 "src/analyzer/Block.pv"
                            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                                #line 295 "src/analyzer/Block.pv"
                                Context__pop_scope(context);
                                #line 295 "src/analyzer/Block.pv"
                                return false;
                            }

                            #line 297 "src/analyzer/Block.pv"
                            if (parameters.length != enum_variant->types.length) {
                                #line 298 "src/analyzer/Block.pv"
                                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                                #line 299 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                                #line 300 "src/analyzer/Block.pv"
                                String__append_usize(&message, enum_variant->types.length);
                                #line 301 "src/analyzer/Block.pv"
                                Context__error_token(context, enum_variant_token, String__c_str(&message));
                            }
                        } else {
                            #line 304 "src/analyzer/Block.pv"
                            if (enum_variant->types.length > 0) {
                                #line 305 "src/analyzer/Block.pv"
                                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                                #line 306 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                                #line 307 "src/analyzer/Block.pv"
                                String__append_usize(&message, enum_variant->types.length);
                                #line 308 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                                #line 309 "src/analyzer/Block.pv"
                                Context__error_token(context, enum_variant_token, String__c_str(&message));
                            }
                        }

                        #line 313 "src/analyzer/Block.pv"
                        pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = enum_variant, ._1 = parameters} };
                    } break;
                    #line 315 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                        #line 315 "src/analyzer/Block.pv"
                        struct EnumCValue* enum_variant = enum_variant_result.enumcvalue_value;
                        #line 318 "src/analyzer/Block.pv"
                        pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE2, .enumcvalue2_value = enum_variant };
                    } break;
                }
            }
        }

        #line 326 "src/analyzer/Block.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>") == 0) {
            #line 326 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 326 "src/analyzer/Block.pv"
            return false;
        }

        #line 328 "src/analyzer/Block.pv"
        if (Block__parse(block, context, generics, 0) == 0) {
            #line 328 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 328 "src/analyzer/Block.pv"
            return false;
        }

        #line 330 "src/analyzer/Block.pv"
        struct MatchCase match_case = (struct MatchCase) {
            .first_token = first_match_token,
            .type = type,
            .pattern = pattern,
            .body = block,
        };

        #line 337 "src/analyzer/Block.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 339 "src/analyzer/Block.pv"
        Context__pop_scope(context);

        #line 341 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
            #line 342 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 343 "src/analyzer/Block.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 344 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 348 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 348 "src/analyzer/Block.pv"
        return false;
    }

    #line 350 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = { ._0 = expression, ._1 = cases} }));

    #line 352 "src/analyzer/Block.pv"
    return true;
}

#line 355 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 356 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 357 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "while") == 0) {
        #line 357 "src/analyzer/Block.pv"
        return false;
    }

    #line 359 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 360 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 360 "src/analyzer/Block.pv"
        return false;
    }

    #line 362 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 363 "src/analyzer/Block.pv"
    block->is_loop = true;
    #line 364 "src/analyzer/Block.pv"
    if (Block__parse(block, context, generics, 1) == 0) {
        #line 364 "src/analyzer/Block.pv"
        return false;
    }

    #line 366 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = { ._0 = expression, ._1 = block} }));

    #line 368 "src/analyzer/Block.pv"
    return true;
}

#line 371 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables) {
    #line 372 "src/analyzer/Block.pv"
    bool deref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "*");
    #line 373 "src/analyzer/Block.pv"
    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
    #line 374 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

    #line 376 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 376 "src/analyzer/Block.pv"
        return false;
    }

    #line 378 "src/analyzer/Block.pv"
    Array_ForVariable__append(variables, (struct ForVariable) { .deref = deref, .ref = ref, .name = name });

    #line 380 "src/analyzer/Block.pv"
    return true;
}

#line 383 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 384 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);

    #line 386 "src/analyzer/Block.pv"
    struct ForStatement for_statement = ForStatement__new(context->allocator);

    #line 388 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for") == 0) {
        #line 388 "src/analyzer/Block.pv"
        return false;
    }

    #line 390 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 391 "src/analyzer/Block.pv"
        while (Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 392 "src/analyzer/Block.pv"
            if (Block__parse_for_variable(self, context, &for_statement.variables) == 0) {
                #line 392 "src/analyzer/Block.pv"
                return false;
            }

            #line 394 "src/analyzer/Block.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") == 0 && Context__check_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
                #line 395 "src/analyzer/Block.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 396 "src/analyzer/Block.pv"
                return false;
            }
        }

        #line 400 "src/analyzer/Block.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")") == 0) {
            #line 400 "src/analyzer/Block.pv"
            return false;
        }
    } else {
        #line 402 "src/analyzer/Block.pv"
        if (Block__parse_for_variable(self, context, &for_statement.variables) == 0) {
            #line 402 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 405 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "in") == 0) {
        #line 405 "src/analyzer/Block.pv"
        return false;
    }

    #line 407 "src/analyzer/Block.pv"
    struct Token* expression_first_token = Context__current(context);
    #line 408 "src/analyzer/Block.pv"
    for_statement.expression = Expression__parse(context, generics);
    #line 409 "src/analyzer/Block.pv"
    if (for_statement.expression == 0) {
        #line 409 "src/analyzer/Block.pv"
        return false;
    }

    #line 411 "src/analyzer/Block.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&for_statement.expression->return_type, context);

    #line 413 "src/analyzer/Block.pv"
    bool is_range = false;

    #line 415 "src/analyzer/Block.pv"
    switch (for_statement.expression->data.type) {
        #line 416 "src/analyzer/Block.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 416 "src/analyzer/Block.pv"
            struct Expression* target = for_statement.expression->data.invoke_value._0;
            #line 416 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = for_statement.expression->data.invoke_value._1;
            #line 417 "src/analyzer/Block.pv"
            switch (target->return_type.type) {
                #line 418 "src/analyzer/Block.pv"
                case TYPE__ENUM: {
                    #line 418 "src/analyzer/Block.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 418 "src/analyzer/Block.pv"
                    struct GenericMap* generic_map = target->return_type.enum_value._1;
                    #line 419 "src/analyzer/Block.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 420 "src/analyzer/Block.pv"
                        is_range = true;
                        #line 421 "src/analyzer/Block.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__RANGE, .range_value = { ._0 = args.data[0].value, ._1 = args.data[1].value} };
                        #line 422 "src/analyzer/Block.pv"
                        for_statement.iter_type = &generic_map->array.data[0];
                        #line 423 "src/analyzer/Block.pv"
                        for_statement.variables.data[0].type = &generic_map->array.data[0];
                    }
                } break;
                #line 426 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        } break;
        #line 429 "src/analyzer/Block.pv"
        default: {
        } break;
    }

    #line 432 "src/analyzer/Block.pv"
    if (!is_range) {
        #line 433 "src/analyzer/Block.pv"
        struct Token* iter_member = ArenaAllocator__store_Token(context->allocator, *expression_first_token);
        #line 434 "src/analyzer/Block.pv"
        iter_member->value = (struct str){ .ptr = "iter", .length = strlen("iter") };

        #line 436 "src/analyzer/Block.pv"
        struct Type* iter_member_type = Expression__get_member_type(context, &for_statement.expression->return_type, iter_member, false);
        #line 437 "src/analyzer/Block.pv"
        bool iter_member_is_function = false;

        #line 439 "src/analyzer/Block.pv"
        if (iter_member_type != 0) {
            #line 440 "src/analyzer/Block.pv"
            switch (iter_member_type->type) {
                #line 441 "src/analyzer/Block.pv"
                case TYPE__FUNCTION: {
                    #line 441 "src/analyzer/Block.pv"
                    iter_member_is_function = true;
                } break;
                #line 442 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        }

        #line 446 "src/analyzer/Block.pv"
        if (!iter_member_is_function) {
            #line 447 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = for_statement.expression };
            #line 448 "src/analyzer/Block.pv"
            for_statement.iter_type = &for_statement.expression->return_type;
        } else {
            #line 450 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
            #line 451 "src/analyzer/Block.pv"
            Array_InvokeArgument__append(&args, (struct InvokeArgument) { .value = for_statement.expression });

            #line 453 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = Expression__make_type_function_call(context, iter_member, iter_member_type, args, generic_map) };
            #line 454 "src/analyzer/Block.pv"
            for_statement.iter_type = Expression__get_return_type(context, iter_member_type, iter_member, generic_map);
        }

        #line 457 "src/analyzer/Block.pv"
        struct Token value_member = *iter_member;
        #line 458 "src/analyzer/Block.pv"
        value_member.value = (struct str){ .ptr = "value", .length = strlen("value") };

        #line 460 "src/analyzer/Block.pv"
        struct Type* value_member_type = Expression__get_member_type(context, for_statement.iter_type, &value_member, true);
        #line 461 "src/analyzer/Block.pv"
        if (value_member_type == 0) {
            #line 461 "src/analyzer/Block.pv"
            return 0;
        }
        #line 462 "src/analyzer/Block.pv"
        for_statement.value_type = Expression__get_return_type(context, value_member_type, &value_member, generic_map);

        #line 464 "src/analyzer/Block.pv"
        uintptr_t variable_i = 0;
        #line 465 "src/analyzer/Block.pv"
        { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
        #line 465 "src/analyzer/Block.pv"
        while (ArrayIter_ref_ForVariable__next(&__iter)) {
            #line 465 "src/analyzer/Block.pv"
            struct ForVariable* variable = ArrayIter_ref_ForVariable__value(&__iter);

            #line 466 "src/analyzer/Block.pv"
            if (for_statement.variables.length == 1) {
                #line 467 "src/analyzer/Block.pv"
                variable->type = for_statement.value_type;
            } else {
                #line 469 "src/analyzer/Block.pv"
                struct Token value_member = *variable->name;
                #line 470 "src/analyzer/Block.pv"
                struct String value_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 471 "src/analyzer/Block.pv"
                String__append_usize(&value_name, variable_i);
                #line 472 "src/analyzer/Block.pv"
                value_member.type = TOKEN_TYPE__NUMBER;
                #line 473 "src/analyzer/Block.pv"
                value_member.value = String__as_str(&value_name);

                #line 475 "src/analyzer/Block.pv"
                variable->type = Expression__get_member_type(context, Type__deref(for_statement.value_type), &value_member, true);
            }

            #line 478 "src/analyzer/Block.pv"
            if (variable->deref) {
                #line 479 "src/analyzer/Block.pv"
                variable->type = Type__deref(variable->type);
            }

            #line 482 "src/analyzer/Block.pv"
            if (variable->ref) {
                #line 483 "src/analyzer/Block.pv"
                variable->type = Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *variable->type) }, context->allocator);
            }

            #line 486 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable->type, context->type_self, 0);
            #line 487 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 488 "src/analyzer/Block.pv"
            Context__inlay_hint(context, variable->name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);

            #line 490 "src/analyzer/Block.pv"
            variable_i += 1;
        } }
    }

    #line 494 "src/analyzer/Block.pv"
    Context__push_scope(context, self);

    #line 496 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
    #line 496 "src/analyzer/Block.pv"
    while (ArrayIter_ref_ForVariable__next(&__iter)) {
        #line 496 "src/analyzer/Block.pv"
        struct ForVariable* variable2 = ArrayIter_ref_ForVariable__value(&__iter);

        #line 497 "src/analyzer/Block.pv"
        if (Context__set_value(context, variable2->name, variable2->type) == 0) {
            #line 497 "src/analyzer/Block.pv"
            Context__error(context, "set_value");
            #line 497 "src/analyzer/Block.pv"
            return false;
        }
    } }

    #line 500 "src/analyzer/Block.pv"
    for_statement.block = Block__new_ptr(context);
    #line 501 "src/analyzer/Block.pv"
    for_statement.block->is_loop = true;
    #line 502 "src/analyzer/Block.pv"
    if (Block__parse(for_statement.block, context, generics, 0) == 0) {
        #line 502 "src/analyzer/Block.pv"
        return false;
    }

    #line 504 "src/analyzer/Block.pv"
    Context__pop_scope(context);

    #line 506 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = ArenaAllocator__store_ForStatement(context->allocator, for_statement) }));

    #line 508 "src/analyzer/Block.pv"
    return true;
}

#line 511 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 512 "src/analyzer/Block.pv"
    bool top_block_found = false;
    #line 513 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_Scope __iter = Array_Scope__iter(&context->scopes);
    #line 513 "src/analyzer/Block.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 513 "src/analyzer/Block.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 514 "src/analyzer/Block.pv"
        if (top_block_found) {
        } else {
            #line 516 "src/analyzer/Block.pv"
            struct Block* top_block = scope->block;
            #line 517 "src/analyzer/Block.pv"
            if (top_block != 0) {
                #line 518 "src/analyzer/Block.pv"
                top_block->is_top_level_and_has_defer_statements_inside = true;
                #line 519 "src/analyzer/Block.pv"
                top_block_found = true;
            }
        }
    } }

    #line 524 "src/analyzer/Block.pv"
    if (!top_block_found) {
        #line 524 "src/analyzer/Block.pv"
        Context__error(context, "could not find top_block for defer statements");
    }

    #line 526 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__KEYWORD, "defer") == 0) {
        #line 526 "src/analyzer/Block.pv"
        return false;
    }

    #line 528 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 529 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 530 "src/analyzer/Block.pv"
        if (Block__parse(block, context, generics, 1) == 0) {
            #line 530 "src/analyzer/Block.pv"
            return false;
        }
        #line 531 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__BLOCK, .block_value = block });
    } else {
        #line 533 "src/analyzer/Block.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 534 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 534 "src/analyzer/Block.pv"
            return false;
        }
        #line 535 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__EXPRESSION, .expression_value = expression });
        #line 536 "src/analyzer/Block.pv"
        if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
            #line 536 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 539 "src/analyzer/Block.pv"
    return true;
}

#line 542 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 543 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{") == 0) {
        #line 543 "src/analyzer/Block.pv"
        return false;
    }
    #line 544 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 544 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 546 "src/analyzer/Block.pv"
    while (Context__check_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 547 "src/analyzer/Block.pv"
        struct Token* token = &context->tokens[context->pos];
        #line 548 "src/analyzer/Block.pv"
        bool result = true;

        #line 550 "src/analyzer/Block.pv"
        if (Token__eq(token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 551 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 552 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 553 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, 1);
            #line 554 "src/analyzer/Block.pv"
            if (result != 0) {
                #line 554 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 556 "src/analyzer/Block.pv"
            result = Block__parse_defer_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 558 "src/analyzer/Block.pv"
            result = Block__parse_let_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "return")) {
            #line 560 "src/analyzer/Block.pv"
            result = Block__parse_return_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "yield")) {
            #line 562 "src/analyzer/Block.pv"
            result = Block__parse_yield_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "if")) {
            #line 564 "src/analyzer/Block.pv"
            result = Block__parse_if_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "match")) {
            #line 566 "src/analyzer/Block.pv"
            result = Block__parse_match_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "while")) {
            #line 568 "src/analyzer/Block.pv"
            result = Block__parse_while_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "for")) {
            #line 570 "src/analyzer/Block.pv"
            result = Block__parse_for_statement(self, context, generics);
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "continue")) {
            #line 572 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) }));
            #line 573 "src/analyzer/Block.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
                #line 573 "src/analyzer/Block.pv"
                return false;
            }
            #line 574 "src/analyzer/Block.pv"
            result = true;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "break")) {
            #line 576 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) }));
            #line 577 "src/analyzer/Block.pv"
            if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";") == 0) {
                #line 577 "src/analyzer/Block.pv"
                return false;
            }
            #line 578 "src/analyzer/Block.pv"
            result = true;
        } else {
            #line 580 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics);
        }

        #line 583 "src/analyzer/Block.pv"
        if (!result) {
            #line 584 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 584 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 585 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 589 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 590 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 593 "src/analyzer/Block.pv"
    if (Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}") == 0) {
        #line 593 "src/analyzer/Block.pv"
        return false;
    }

    #line 595 "src/analyzer/Block.pv"
    return true;
}
