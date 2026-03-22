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
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <stdint.h>
#include <analyzer/types/Type.h>
#include <analyzer/expression/Expression.h>
#include <std/String.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/Naming.h>
#include <analyzer/Root.h>
#include <std/str.h>
#include <analyzer/InlayHintKind.h>
#include <analyzer/statement/LetStatement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/types/Function.h>
#include <std/Array_ElseStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <std/Array_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/expression/EnumVariantResult.h>
#include <std/Array_EnumVariantParameter.h>
#include <analyzer/types/EnumVariantParameter.h>
#include <std/Array_Type.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/c/EnumCValue.h>
#include <std/Array_ForVariable.h>
#include <analyzer/statement/ForVariable.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/types/Enum.h>
#include <std/ArrayIter_ref_ForVariable.h>
#include <analyzer/Scope.h>
#include <std/ArrayIter_ref_Scope.h>

#include <analyzer/Block.h>

#line 17 "src/analyzer/Block.pv"
struct Block Block__new(struct Context* context) {
    #line 18 "src/analyzer/Block.pv"
    return (struct Block) {
        .context = context,
        .statements = Array_Statement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
        .defer_statements = Array_DeferStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }),
    };
}

#line 25 "src/analyzer/Block.pv"
struct Block* Block__new_ptr(struct Context* context) {
    #line 26 "src/analyzer/Block.pv"
    return ArenaAllocator__store_Block(context->allocator, Block__new(context));
}

#line 29 "src/analyzer/Block.pv"
bool Block__parse_let_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 30 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 31 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 31 "src/analyzer/Block.pv"
        return false;
    }

    #line 33 "src/analyzer/Block.pv"
    bool is_static = Context__check_next(context, TOKEN_TYPE__KEYWORD, "static");

    #line 35 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 36 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 36 "src/analyzer/Block.pv"
        return false;
    }

    #line 38 "src/analyzer/Block.pv"
    struct Type* type = 0;

    #line 40 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ":")) {
        #line 41 "src/analyzer/Block.pv"
        type = Context__parse_type2(context, generics);
        #line 42 "src/analyzer/Block.pv"
        if (type == 0) {
            #line 42 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 45 "src/analyzer/Block.pv"
    struct Expression* expression = 0;

    #line 47 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "=")) {
        #line 48 "src/analyzer/Block.pv"
        expression = Expression__parse(context, generics);
        #line 49 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 49 "src/analyzer/Block.pv"
            return false;
        }

        #line 51 "src/analyzer/Block.pv"
        if (type == 0) {
            #line 52 "src/analyzer/Block.pv"
            type = &expression->return_type;

            #line 54 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, type, context->type_self, 0);
            #line 55 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 56 "src/analyzer/Block.pv"
            Context__inlay_hint(context, name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
        } else {
            #line 58 "src/analyzer/Block.pv"
            Expression__validate_type(expression, context, type, true);
        }
    }

    #line 62 "src/analyzer/Block.pv"
    if (!Context__set_value(context, name, type)) {
        #line 62 "src/analyzer/Block.pv"
        Context__error(context, "set_value");
        #line 62 "src/analyzer/Block.pv"
        return false;
    }
    #line 63 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 63 "src/analyzer/Block.pv"
        return false;
    }

    #line 65 "src/analyzer/Block.pv"
    if (Type__is_void(type)) {
        #line 66 "src/analyzer/Block.pv"
        Context__error_token(context, first_token, "Let statement is unable to determine it's type, manually specify it");
    }

    #line 69 "src/analyzer/Block.pv"
    struct LetStatement* let_statement = ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement) {
        .is_static = is_static,
        .name = name,
        .type = type,
        .value = expression,
    });

    #line 76 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement }));

    #line 78 "src/analyzer/Block.pv"
    return true;
}

#line 81 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 82 "src/analyzer/Block.pv"
    struct Array_DeferStatement defer_statements = Context__get_defer_statements(context);

    #line 84 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 85 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "return")) {
        #line 85 "src/analyzer/Block.pv"
        return false;
    }

    #line 87 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 88 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = 0, ._1 = defer_statements} };
        #line 89 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));

        #line 91 "src/analyzer/Block.pv"
        if (!Type__is_void(&context->function->return_type)) {
            #line 92 "src/analyzer/Block.pv"
            Context__error_token(context, first_token, "Return statement is blank but function has a return type");
        }

        #line 95 "src/analyzer/Block.pv"
        return true;
    }

    #line 98 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 99 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 99 "src/analyzer/Block.pv"
        return false;
    }
    #line 100 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 100 "src/analyzer/Block.pv"
        return false;
    }

    #line 102 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 104 "src/analyzer/Block.pv"
    if (Type__is_void(&context->function->return_type)) {
        #line 105 "src/analyzer/Block.pv"
        Context__error_token(context, first_token, "Function does not have a return type");
    }

    #line 108 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = expression, ._1 = defer_statements} }));

    #line 110 "src/analyzer/Block.pv"
    return true;
}

#line 113 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 114 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 115 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield")) {
        #line 115 "src/analyzer/Block.pv"
        return false;
    }

    #line 117 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 118 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = 0 };
        #line 119 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 120 "src/analyzer/Block.pv"
        return true;
    }

    #line 123 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 124 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 124 "src/analyzer/Block.pv"
        return false;
    }
    #line 125 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 125 "src/analyzer/Block.pv"
        return false;
    }

    #line 127 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 129 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = expression }));

    #line 131 "src/analyzer/Block.pv"
    return true;
}

#line 134 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 135 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 136 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 137 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 137 "src/analyzer/Block.pv"
        return false;
    }

    #line 139 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 140 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 141 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 141 "src/analyzer/Block.pv"
            return false;
        }

        #line 143 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 144 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 144 "src/analyzer/Block.pv"
            return false;
        }

        #line 146 "src/analyzer/Block.pv"
        Expression__validate_type(value, context, &expression->return_type, true);

        #line 148 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = { ._0 = expression, ._1 = operator, ._2 = value} }));
    } else {
        #line 150 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression }));
    }

    #line 153 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 153 "src/analyzer/Block.pv"
        return false;
    }

    #line 155 "src/analyzer/Block.pv"
    return true;
}

#line 158 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 159 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 160 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 160 "src/analyzer/Block.pv"
        return false;
    }

    #line 162 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 163 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 163 "src/analyzer/Block.pv"
        return false;
    }

    #line 165 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 166 "src/analyzer/Block.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 166 "src/analyzer/Block.pv"
        return false;
    }

    #line 168 "src/analyzer/Block.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 169 "src/analyzer/Block.pv"
    struct Expression* else_expression = 0;
    #line 170 "src/analyzer/Block.pv"
    struct Block* else_block = 0;
    #line 171 "src/analyzer/Block.pv"
    bool else_end = false;

    #line 173 "src/analyzer/Block.pv"
    while (!else_end && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 174 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 175 "src/analyzer/Block.pv"
            else_expression = Expression__parse(context, generics);
            #line 176 "src/analyzer/Block.pv"
            if (else_expression == 0) {
                #line 176 "src/analyzer/Block.pv"
                return false;
            }
        } else {
            #line 178 "src/analyzer/Block.pv"
            else_expression = 0;
            #line 179 "src/analyzer/Block.pv"
            else_end = true;
        }

        #line 182 "src/analyzer/Block.pv"
        else_block = Block__new_ptr(context);
        #line 183 "src/analyzer/Block.pv"
        if (!Block__parse(else_block, context, generics, true)) {
            #line 183 "src/analyzer/Block.pv"
            return false;
        }

        #line 185 "src/analyzer/Block.pv"
        struct ElseStatement else_statement = (struct ElseStatement) {
            .expression = else_expression,
            .block = else_block,
        };

        #line 190 "src/analyzer/Block.pv"
        Array_ElseStatement__append(&else_statements, else_statement);
    }

    #line 193 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = { ._0 = expression, ._1 = block, ._2 = else_statements} }));

    #line 195 "src/analyzer/Block.pv"
    return true;
}

#line 198 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 199 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 200 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "match")) {
        #line 200 "src/analyzer/Block.pv"
        return false;
    }

    #line 202 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 203 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 203 "src/analyzer/Block.pv"
        return false;
    }

    #line 205 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 205 "src/analyzer/Block.pv"
        return false;
    }

    #line 207 "src/analyzer/Block.pv"
    struct Array_MatchCase cases = Array_MatchCase__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 209 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 210 "src/analyzer/Block.pv"
        struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 211 "src/analyzer/Block.pv"
        struct Token* first_match_token = Context__current(context);

        #line 213 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 214 "src/analyzer/Block.pv"
        Context__push_scope(context, block);

        #line 216 "src/analyzer/Block.pv"
        struct Type* type = 0;

        #line 218 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "typeid")) {
            #line 219 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 219 "src/analyzer/Block.pv"
                return false;
            }

            #line 221 "src/analyzer/Block.pv"
            struct Type type;
            #line 222 "src/analyzer/Block.pv"
            if (!Context__parse_type(context, &type, generics)) {
                #line 222 "src/analyzer/Block.pv"
                return false;
            }

            #line 224 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 224 "src/analyzer/Block.pv"
                return false;
            }

            #line 226 "src/analyzer/Block.pv"
            pattern = (struct MatchPattern) { .type = MATCH_PATTERN__TYPE_ID, .typeid_value = type };
        } else if (!Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "_")) {
            #line 228 "src/analyzer/Block.pv"
            struct Token* token = Context__current(context);
            #line 229 "src/analyzer/Block.pv"
            if (token == 0) {
                #line 229 "src/analyzer/Block.pv"
                return false;
            }

            #line 231 "src/analyzer/Block.pv"
            type = Context__get_value(context, token->value);

            #line 233 "src/analyzer/Block.pv"
            if (type != 0) {
                #line 234 "src/analyzer/Block.pv"
                Context__next_token(context);
                #line 235 "src/analyzer/Block.pv"
                pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = token };
            } else {
                #line 237 "src/analyzer/Block.pv"
                type = Context__parse_type2(context, generics);
                #line 238 "src/analyzer/Block.pv"
                if (type == 0) {
                    #line 239 "src/analyzer/Block.pv"
                    return false;
                } else if (!Type__is_enum(type)) {
                    #line 241 "src/analyzer/Block.pv"
                    Context__error_token(context, token, "Type is not an enum");
                    #line 242 "src/analyzer/Block.pv"
                    return false;
                }

                #line 245 "src/analyzer/Block.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
                    #line 245 "src/analyzer/Block.pv"
                    return false;
                }

                #line 247 "src/analyzer/Block.pv"
                struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                #line 248 "src/analyzer/Block.pv"
                if (enum_variant_token == 0) {
                    #line 248 "src/analyzer/Block.pv"
                    return false;
                }

                #line 250 "src/analyzer/Block.pv"
                struct GenericMap* generic_map = 0;

                #line 252 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 253 "src/analyzer/Block.pv"
                    case TYPE__SELF: {
                        #line 254 "src/analyzer/Block.pv"
                        type = context->type_self;
                    } break;
                    #line 256 "src/analyzer/Block.pv"
                    default: {
                    } break;
                }

                #line 259 "src/analyzer/Block.pv"
                switch (type->type) {
                    #line 260 "src/analyzer/Block.pv"
                    case TYPE__ENUM: {
                        #line 260 "src/analyzer/Block.pv"
                        struct GenericMap* generics = type->enum_value._1;
                        #line 260 "src/analyzer/Block.pv"
                        generic_map = generics;
                    } break;
                    #line 261 "src/analyzer/Block.pv"
                    case TYPE__ENUM_C: {
                    } break;
                    #line 262 "src/analyzer/Block.pv"
                    default: {
                        #line 263 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 264 "src/analyzer/Block.pv"
                        Context__error(context, "Not an enum type");
                        #line 265 "src/analyzer/Block.pv"
                        return false;
                    } break;
                }

                #line 269 "src/analyzer/Block.pv"
                struct EnumVariantResult enum_variant_result = Expression__get_enum_variant(context, type, enum_variant_token);
                #line 270 "src/analyzer/Block.pv"
                switch (enum_variant_result.type) {
                    #line 271 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__NONE: {
                        #line 272 "src/analyzer/Block.pv"
                        Context__error(context, "Could not find enum variant");
                        #line 273 "src/analyzer/Block.pv"
                        return false;
                    } break;
                    #line 275 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
                        #line 275 "src/analyzer/Block.pv"
                        struct EnumVariant* enum_variant = enum_variant_result.enumvariant_value;
                        #line 276 "src/analyzer/Block.pv"
                        struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

                        #line 278 "src/analyzer/Block.pv"
                        if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                            #line 279 "src/analyzer/Block.pv"
                            uintptr_t variable_i = 0;

                            #line 281 "src/analyzer/Block.pv"
                            while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 282 "src/analyzer/Block.pv"
                                bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                                #line 283 "src/analyzer/Block.pv"
                                struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                                #line 284 "src/analyzer/Block.pv"
                                if (variable == 0) {
                                    #line 284 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 284 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 286 "src/analyzer/Block.pv"
                                Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                                #line 288 "src/analyzer/Block.pv"
                                struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                                #line 289 "src/analyzer/Block.pv"
                                if (variable_type == 0) {
                                    #line 289 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 291 "src/analyzer/Block.pv"
                                if (ref) {
                                    #line 292 "src/analyzer/Block.pv"
                                    struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type });
                                    #line 293 "src/analyzer/Block.pv"
                                    variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
                                }

                                #line 296 "src/analyzer/Block.pv"
                                struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                                #line 297 "src/analyzer/Block.pv"
                                String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                                #line 298 "src/analyzer/Block.pv"
                                Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                                #line 300 "src/analyzer/Block.pv"
                                if (!Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                                    #line 301 "src/analyzer/Block.pv"
                                    if (!Context__set_value(context, variable, variable_type)) {
                                        #line 301 "src/analyzer/Block.pv"
                                        Context__pop_scope(context);
                                        #line 301 "src/analyzer/Block.pv"
                                        return false;
                                    }
                                }

                                #line 304 "src/analyzer/Block.pv"
                                if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                    #line 305 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 306 "src/analyzer/Block.pv"
                                    Context__pop_scope(context);
                                    #line 307 "src/analyzer/Block.pv"
                                    Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                                    #line 308 "src/analyzer/Block.pv"
                                    return false;
                                }

                                #line 311 "src/analyzer/Block.pv"
                                variable_i += 1;
                            }

                            #line 314 "src/analyzer/Block.pv"
                            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                                #line 314 "src/analyzer/Block.pv"
                                Context__pop_scope(context);
                                #line 314 "src/analyzer/Block.pv"
                                return false;
                            }

                            #line 316 "src/analyzer/Block.pv"
                            if (parameters.length != enum_variant->types.length) {
                                #line 317 "src/analyzer/Block.pv"
                                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                                #line 318 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                                #line 319 "src/analyzer/Block.pv"
                                String__append_usize(&message, enum_variant->types.length);
                                #line 320 "src/analyzer/Block.pv"
                                Context__error_token(context, enum_variant_token, String__c_str(&message));
                            }
                        } else {
                            #line 323 "src/analyzer/Block.pv"
                            if (enum_variant->types.length > 0) {
                                #line 324 "src/analyzer/Block.pv"
                                struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                                #line 325 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                                #line 326 "src/analyzer/Block.pv"
                                String__append_usize(&message, enum_variant->types.length);
                                #line 327 "src/analyzer/Block.pv"
                                String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                                #line 328 "src/analyzer/Block.pv"
                                Context__error_token(context, enum_variant_token, String__c_str(&message));
                            }
                        }

                        #line 332 "src/analyzer/Block.pv"
                        pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = enum_variant, ._1 = parameters} };
                    } break;
                    #line 334 "src/analyzer/Block.pv"
                    case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
                        #line 334 "src/analyzer/Block.pv"
                        struct EnumCValue* enum_variant = enum_variant_result.enumcvalue_value;
                        #line 335 "src/analyzer/Block.pv"
                        pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE, .enumcvalue_value = enum_variant };
                    } break;
                }
            }
        }

        #line 341 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>")) {
            #line 341 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 341 "src/analyzer/Block.pv"
            return false;
        }

        #line 343 "src/analyzer/Block.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 343 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 343 "src/analyzer/Block.pv"
            return false;
        }

        #line 345 "src/analyzer/Block.pv"
        struct MatchCase match_case = (struct MatchCase) {
            .first_token = first_match_token,
            .type = type,
            .pattern = pattern,
            .body = block,
        };

        #line 352 "src/analyzer/Block.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 354 "src/analyzer/Block.pv"
        Context__pop_scope(context);

        #line 356 "src/analyzer/Block.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 357 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 358 "src/analyzer/Block.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 359 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 363 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 363 "src/analyzer/Block.pv"
        return false;
    }

    #line 365 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = { ._0 = expression, ._1 = cases} }));

    #line 367 "src/analyzer/Block.pv"
    return true;
}

#line 370 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 371 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 372 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "while")) {
        #line 372 "src/analyzer/Block.pv"
        return false;
    }

    #line 374 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 375 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 375 "src/analyzer/Block.pv"
        return false;
    }

    #line 377 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 378 "src/analyzer/Block.pv"
    block->is_loop = true;
    #line 379 "src/analyzer/Block.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 379 "src/analyzer/Block.pv"
        return false;
    }

    #line 381 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = { ._0 = expression, ._1 = block} }));

    #line 383 "src/analyzer/Block.pv"
    return true;
}

#line 386 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables) {
    #line 387 "src/analyzer/Block.pv"
    bool deref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "*");
    #line 388 "src/analyzer/Block.pv"
    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
    #line 389 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

    #line 391 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 391 "src/analyzer/Block.pv"
        return false;
    }

    #line 393 "src/analyzer/Block.pv"
    Array_ForVariable__append(variables, (struct ForVariable) { .deref = deref, .ref = ref, .name = name });

    #line 395 "src/analyzer/Block.pv"
    return true;
}

#line 398 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 399 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);

    #line 401 "src/analyzer/Block.pv"
    struct ForStatement for_statement = ForStatement__new(context->allocator);

    #line 403 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
        #line 403 "src/analyzer/Block.pv"
        return false;
    }

    #line 405 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 406 "src/analyzer/Block.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 407 "src/analyzer/Block.pv"
            if (!Block__parse_for_variable(self, context, &for_statement.variables)) {
                #line 407 "src/analyzer/Block.pv"
                return false;
            }

            #line 409 "src/analyzer/Block.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 410 "src/analyzer/Block.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 411 "src/analyzer/Block.pv"
                return false;
            }
        }

        #line 415 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 415 "src/analyzer/Block.pv"
            return false;
        }
    } else {
        #line 417 "src/analyzer/Block.pv"
        if (!Block__parse_for_variable(self, context, &for_statement.variables)) {
            #line 417 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 420 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "in")) {
        #line 420 "src/analyzer/Block.pv"
        return false;
    }

    #line 422 "src/analyzer/Block.pv"
    struct Token* expression_first_token = Context__current(context);
    #line 423 "src/analyzer/Block.pv"
    for_statement.expression = Expression__parse(context, generics);
    #line 424 "src/analyzer/Block.pv"
    if (for_statement.expression == 0) {
        #line 424 "src/analyzer/Block.pv"
        return false;
    }

    #line 426 "src/analyzer/Block.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&for_statement.expression->return_type, context);

    #line 428 "src/analyzer/Block.pv"
    bool is_range = false;

    #line 430 "src/analyzer/Block.pv"
    switch (for_statement.expression->data.type) {
        #line 431 "src/analyzer/Block.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 431 "src/analyzer/Block.pv"
            struct Expression* target = for_statement.expression->data.invoke_value._0;
            #line 431 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = for_statement.expression->data.invoke_value._1;
            #line 432 "src/analyzer/Block.pv"
            switch (target->return_type.type) {
                #line 433 "src/analyzer/Block.pv"
                case TYPE__ENUM: {
                    #line 433 "src/analyzer/Block.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 433 "src/analyzer/Block.pv"
                    struct GenericMap* generic_map = target->return_type.enum_value._1;
                    #line 434 "src/analyzer/Block.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 435 "src/analyzer/Block.pv"
                        is_range = true;
                        #line 436 "src/analyzer/Block.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__RANGE, .range_value = { ._0 = args.data[0].value, ._1 = args.data[1].value} };
                        #line 437 "src/analyzer/Block.pv"
                        for_statement.iter_type = &generic_map->array.data[0];
                        #line 438 "src/analyzer/Block.pv"
                        for_statement.variables.data[0].type = &generic_map->array.data[0];
                    }
                } break;
                #line 441 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        } break;
        #line 444 "src/analyzer/Block.pv"
        default: {
        } break;
    }

    #line 447 "src/analyzer/Block.pv"
    if (!is_range) {
        #line 448 "src/analyzer/Block.pv"
        struct Token* iter_member = ArenaAllocator__store_Token(context->allocator, *expression_first_token);
        #line 449 "src/analyzer/Block.pv"
        iter_member->value = (struct str){ .ptr = "iter", .length = strlen("iter") };

        #line 451 "src/analyzer/Block.pv"
        struct Type* iter_member_type = Expression__get_member_type(context, &for_statement.expression->return_type, iter_member, false);
        #line 452 "src/analyzer/Block.pv"
        bool iter_member_is_function = false;

        #line 454 "src/analyzer/Block.pv"
        if (iter_member_type != 0) {
            #line 455 "src/analyzer/Block.pv"
            switch (iter_member_type->type) {
                #line 456 "src/analyzer/Block.pv"
                case TYPE__FUNCTION: {
                    #line 456 "src/analyzer/Block.pv"
                    iter_member_is_function = true;
                } break;
                #line 457 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        }

        #line 461 "src/analyzer/Block.pv"
        if (!iter_member_is_function) {
            #line 462 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = for_statement.expression };
            #line 463 "src/analyzer/Block.pv"
            for_statement.iter_type = &for_statement.expression->return_type;
        } else {
            #line 465 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
            #line 466 "src/analyzer/Block.pv"
            Array_InvokeArgument__append(&args, (struct InvokeArgument) { .value = for_statement.expression });

            #line 468 "src/analyzer/Block.pv"
            for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = Expression__make_type_function_call(context, iter_member, iter_member_type, args, generic_map) };
            #line 469 "src/analyzer/Block.pv"
            for_statement.iter_type = Expression__get_return_type(context, iter_member_type, iter_member, generic_map);
        }

        #line 472 "src/analyzer/Block.pv"
        struct Token value_member = *iter_member;
        #line 473 "src/analyzer/Block.pv"
        value_member.value = (struct str){ .ptr = "value", .length = strlen("value") };

        #line 475 "src/analyzer/Block.pv"
        struct Type* value_member_type = Expression__get_member_type(context, for_statement.iter_type, &value_member, true);
        #line 476 "src/analyzer/Block.pv"
        if (value_member_type == 0) {
            #line 476 "src/analyzer/Block.pv"
            return false;
        }
        #line 477 "src/analyzer/Block.pv"
        for_statement.value_type = Expression__get_return_type(context, value_member_type, &value_member, generic_map);

        #line 479 "src/analyzer/Block.pv"
        uintptr_t variable_i = 0;
        #line 480 "src/analyzer/Block.pv"
        { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
        #line 480 "src/analyzer/Block.pv"
        while (ArrayIter_ref_ForVariable__next(&__iter)) {
            #line 480 "src/analyzer/Block.pv"
            struct ForVariable* variable = ArrayIter_ref_ForVariable__value(&__iter);

            #line 481 "src/analyzer/Block.pv"
            if (for_statement.variables.length == 1) {
                #line 482 "src/analyzer/Block.pv"
                variable->type = for_statement.value_type;
            } else {
                #line 484 "src/analyzer/Block.pv"
                struct Token value_member = *variable->name;
                #line 485 "src/analyzer/Block.pv"
                struct String value_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 486 "src/analyzer/Block.pv"
                String__append_usize(&value_name, variable_i);
                #line 487 "src/analyzer/Block.pv"
                value_member.type = TOKEN_TYPE__NUMBER;
                #line 488 "src/analyzer/Block.pv"
                value_member.value = String__as_str(&value_name);

                #line 490 "src/analyzer/Block.pv"
                variable->type = Expression__get_member_type(context, Type__deref(for_statement.value_type), &value_member, true);
            }

            #line 493 "src/analyzer/Block.pv"
            if (variable->deref) {
                #line 494 "src/analyzer/Block.pv"
                variable->type = Type__deref(variable->type);
            }

            #line 497 "src/analyzer/Block.pv"
            if (variable->ref) {
                #line 498 "src/analyzer/Block.pv"
                variable->type = Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *variable->type) }, context->allocator);
            }

            #line 501 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable->type, context->type_self, 0);
            #line 502 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 503 "src/analyzer/Block.pv"
            Context__inlay_hint(context, variable->name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);

            #line 505 "src/analyzer/Block.pv"
            variable_i += 1;
        } }
    }

    #line 509 "src/analyzer/Block.pv"
    Context__push_scope(context, self);

    #line 511 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
    #line 511 "src/analyzer/Block.pv"
    while (ArrayIter_ref_ForVariable__next(&__iter)) {
        #line 511 "src/analyzer/Block.pv"
        struct ForVariable* variable2 = ArrayIter_ref_ForVariable__value(&__iter);

        #line 512 "src/analyzer/Block.pv"
        if (!Context__set_value(context, variable2->name, variable2->type)) {
            #line 512 "src/analyzer/Block.pv"
            Context__error(context, "set_value");
            #line 512 "src/analyzer/Block.pv"
            return false;
        }
    } }

    #line 515 "src/analyzer/Block.pv"
    for_statement.block = Block__new_ptr(context);
    #line 516 "src/analyzer/Block.pv"
    for_statement.block->is_loop = true;
    #line 517 "src/analyzer/Block.pv"
    if (!Block__parse(for_statement.block, context, generics, false)) {
        #line 517 "src/analyzer/Block.pv"
        return false;
    }

    #line 519 "src/analyzer/Block.pv"
    Context__pop_scope(context);

    #line 521 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = ArenaAllocator__store_ForStatement(context->allocator, for_statement) }));

    #line 523 "src/analyzer/Block.pv"
    return true;
}

#line 526 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 527 "src/analyzer/Block.pv"
    bool top_block_found = false;
    #line 528 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_Scope __iter = Array_Scope__iter(&context->scopes);
    #line 528 "src/analyzer/Block.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 528 "src/analyzer/Block.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 529 "src/analyzer/Block.pv"
        if (top_block_found) {
        } else {
            #line 531 "src/analyzer/Block.pv"
            struct Block* top_block = scope->block;
            #line 532 "src/analyzer/Block.pv"
            if (top_block != 0) {
                #line 533 "src/analyzer/Block.pv"
                top_block->is_top_level_and_has_defer_statements_inside = true;
                #line 534 "src/analyzer/Block.pv"
                top_block_found = true;
            }
        }
    } }

    #line 539 "src/analyzer/Block.pv"
    if (!top_block_found) {
        #line 539 "src/analyzer/Block.pv"
        Context__error(context, "could not find top_block for defer statements");
    }

    #line 541 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "defer")) {
        #line 541 "src/analyzer/Block.pv"
        return false;
    }

    #line 543 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 544 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 545 "src/analyzer/Block.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 545 "src/analyzer/Block.pv"
            return false;
        }
        #line 546 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__BLOCK, .block_value = block });
    } else {
        #line 548 "src/analyzer/Block.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 549 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 549 "src/analyzer/Block.pv"
            return false;
        }
        #line 550 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__EXPRESSION, .expression_value = expression });
        #line 551 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 551 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 554 "src/analyzer/Block.pv"
    return true;
}

#line 557 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 558 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 558 "src/analyzer/Block.pv"
        return false;
    }
    #line 559 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 559 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 561 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 562 "src/analyzer/Block.pv"
        struct Token* token = &context->tokens[context->pos];
        #line 563 "src/analyzer/Block.pv"
        bool result = true;

        #line 565 "src/analyzer/Block.pv"
        if (Token__eq(token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 566 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 567 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 568 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, true);
            #line 569 "src/analyzer/Block.pv"
            if (result) {
                #line 569 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 571 "src/analyzer/Block.pv"
            result = Block__parse_defer_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 573 "src/analyzer/Block.pv"
            result = Block__parse_let_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "return")) {
            #line 575 "src/analyzer/Block.pv"
            result = Block__parse_return_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "yield")) {
            #line 577 "src/analyzer/Block.pv"
            result = Block__parse_yield_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "if")) {
            #line 579 "src/analyzer/Block.pv"
            result = Block__parse_if_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "match")) {
            #line 581 "src/analyzer/Block.pv"
            result = Block__parse_match_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "while")) {
            #line 583 "src/analyzer/Block.pv"
            result = Block__parse_while_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "for")) {
            #line 585 "src/analyzer/Block.pv"
            result = Block__parse_for_statement(self, context, generics);
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "continue")) {
            #line 587 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) }));
            #line 588 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 588 "src/analyzer/Block.pv"
                return false;
            }
            #line 589 "src/analyzer/Block.pv"
            result = true;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "break")) {
            #line 591 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) }));
            #line 592 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 592 "src/analyzer/Block.pv"
                return false;
            }
            #line 593 "src/analyzer/Block.pv"
            result = true;
        } else {
            #line 595 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics);
        }

        #line 598 "src/analyzer/Block.pv"
        if (!result) {
            #line 599 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 599 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 600 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 604 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 605 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 608 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 608 "src/analyzer/Block.pv"
        return false;
    }

    #line 610 "src/analyzer/Block.pv"
    return true;
}
