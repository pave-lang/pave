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
#include <std/Array_MatchPattern.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/expression/ExpressionData.h>
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
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/Sequence.h>
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
    if (Type__is_unknown(type)) {
        #line 66 "src/analyzer/Block.pv"
        Context__error_token(context, first_token, "Let statement is unable to determine it's type, manually specify it");
    }

    #line 69 "src/analyzer/Block.pv"
    if (Type__is_void(type)) {
        #line 70 "src/analyzer/Block.pv"
        Context__error_token(context, first_token, "Let statement cannot have void type");
    }

    #line 73 "src/analyzer/Block.pv"
    struct LetStatement* let_statement = ArenaAllocator__store_LetStatement(context->allocator, (struct LetStatement) {
        .is_static = is_static,
        .name = name,
        .type = type,
        .value = expression,
    });

    #line 80 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__LET_STATEMENT, .letstatement_value = let_statement }));

    #line 82 "src/analyzer/Block.pv"
    return true;
}

#line 85 "src/analyzer/Block.pv"
bool Block__parse_return_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 86 "src/analyzer/Block.pv"
    struct Array_DeferStatement defer_statements = Context__get_defer_statements(context);

    #line 88 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 89 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "return")) {
        #line 89 "src/analyzer/Block.pv"
        return false;
    }

    #line 91 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 92 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = 0, ._1 = defer_statements} };
        #line 93 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));

        #line 95 "src/analyzer/Block.pv"
        if (!Type__is_void(&context->function->return_type)) {
            #line 96 "src/analyzer/Block.pv"
            Context__error_token(context, first_token, "Return statement is blank but function has a return type");
        }

        #line 99 "src/analyzer/Block.pv"
        return true;
    }

    #line 102 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 103 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 103 "src/analyzer/Block.pv"
        return false;
    }
    #line 104 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 104 "src/analyzer/Block.pv"
        return false;
    }

    #line 106 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 108 "src/analyzer/Block.pv"
    if (Type__is_void(&context->function->return_type)) {
        #line 109 "src/analyzer/Block.pv"
        Context__error_token(context, first_token, "Function does not have a return type");
    }

    #line 112 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__RETURN_STATEMENT, .returnstatement_value = { ._0 = expression, ._1 = defer_statements} }));

    #line 114 "src/analyzer/Block.pv"
    return true;
}

#line 117 "src/analyzer/Block.pv"
bool Block__parse_yield_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 118 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 119 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "yield")) {
        #line 119 "src/analyzer/Block.pv"
        return false;
    }

    #line 121 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 122 "src/analyzer/Block.pv"
        struct StatementData statement = (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = 0 };
        #line 123 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), statement));
        #line 124 "src/analyzer/Block.pv"
        return true;
    }

    #line 127 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 128 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 128 "src/analyzer/Block.pv"
        return false;
    }
    #line 129 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 129 "src/analyzer/Block.pv"
        return false;
    }

    #line 131 "src/analyzer/Block.pv"
    Expression__validate_type(expression, context, &context->function->return_type, true);

    #line 133 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__YIELD_STATEMENT, .yieldstatement_value = expression }));

    #line 135 "src/analyzer/Block.pv"
    return true;
}

#line 138 "src/analyzer/Block.pv"
bool Block__parse_expression_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 139 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 140 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 141 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 141 "src/analyzer/Block.pv"
        return false;
    }

    #line 143 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "+=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "-=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "*=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "/=") || Context__check_value(context, TOKEN_TYPE__SYMBOL, "|=")) {
        #line 144 "src/analyzer/Block.pv"
        struct Token* operator = Context__expect(context, TOKEN_TYPE__SYMBOL);
        #line 145 "src/analyzer/Block.pv"
        if (operator == 0) {
            #line 145 "src/analyzer/Block.pv"
            return false;
        }

        #line 147 "src/analyzer/Block.pv"
        struct Expression* value = Expression__parse(context, generics);
        #line 148 "src/analyzer/Block.pv"
        if (value == 0) {
            #line 148 "src/analyzer/Block.pv"
            return false;
        }

        #line 150 "src/analyzer/Block.pv"
        Expression__validate_type(value, context, &expression->return_type, true);

        #line 152 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__ASSIGNMENT_STATEMENT, .assignmentstatement_value = { ._0 = expression, ._1 = operator, ._2 = value} }));
    } else {
        #line 154 "src/analyzer/Block.pv"
        Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__EXPRESSION_STATEMENT, .expressionstatement_value = expression }));
    }

    #line 157 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
        #line 157 "src/analyzer/Block.pv"
        return false;
    }

    #line 159 "src/analyzer/Block.pv"
    return true;
}

#line 162 "src/analyzer/Block.pv"
bool Block__parse_if_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 163 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 164 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 164 "src/analyzer/Block.pv"
        return false;
    }

    #line 166 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 167 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 167 "src/analyzer/Block.pv"
        return false;
    }

    #line 169 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 170 "src/analyzer/Block.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 170 "src/analyzer/Block.pv"
        return false;
    }

    #line 172 "src/analyzer/Block.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 173 "src/analyzer/Block.pv"
    struct Expression* else_expression = 0;
    #line 174 "src/analyzer/Block.pv"
    struct Block* else_block = 0;
    #line 175 "src/analyzer/Block.pv"
    bool else_end = false;

    #line 177 "src/analyzer/Block.pv"
    while (!else_end && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 178 "src/analyzer/Block.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 179 "src/analyzer/Block.pv"
            else_expression = Expression__parse(context, generics);
            #line 180 "src/analyzer/Block.pv"
            if (else_expression == 0) {
                #line 180 "src/analyzer/Block.pv"
                return false;
            }
        } else {
            #line 182 "src/analyzer/Block.pv"
            else_expression = 0;
            #line 183 "src/analyzer/Block.pv"
            else_end = true;
        }

        #line 186 "src/analyzer/Block.pv"
        else_block = Block__new_ptr(context);
        #line 187 "src/analyzer/Block.pv"
        if (!Block__parse(else_block, context, generics, true)) {
            #line 187 "src/analyzer/Block.pv"
            return false;
        }

        #line 189 "src/analyzer/Block.pv"
        struct ElseStatement else_statement = (struct ElseStatement) {
            .expression = else_expression,
            .block = else_block,
        };

        #line 194 "src/analyzer/Block.pv"
        Array_ElseStatement__append(&else_statements, else_statement);
    }

    #line 197 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__IF_STATEMENT, .ifstatement_value = { ._0 = expression, ._1 = block, ._2 = else_statements} }));

    #line 199 "src/analyzer/Block.pv"
    return true;
}

#line 202 "src/analyzer/Block.pv"
bool Block__parse_match_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 203 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 204 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "match")) {
        #line 204 "src/analyzer/Block.pv"
        return false;
    }

    #line 206 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 207 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 207 "src/analyzer/Block.pv"
        return false;
    }

    #line 209 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 209 "src/analyzer/Block.pv"
        return false;
    }

    #line 211 "src/analyzer/Block.pv"
    struct Array_MatchCase cases = Array_MatchCase__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

    #line 213 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 214 "src/analyzer/Block.pv"
        struct Token* first_match_token = Context__current(context);

        #line 216 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 217 "src/analyzer/Block.pv"
        Context__push_scope(context, block);

        #line 219 "src/analyzer/Block.pv"
        struct Array_MatchPattern patterns = Array_MatchPattern__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

        #line 221 "src/analyzer/Block.pv"
        while (patterns.length == 0 || Context__check_next(context, TOKEN_TYPE__SYMBOL, "|")) {
            #line 222 "src/analyzer/Block.pv"
            struct MatchPattern pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
            #line 223 "src/analyzer/Block.pv"
            if (!Block__parse_match_pattern(self, context, generics, &pattern)) {
                #line 223 "src/analyzer/Block.pv"
                return false;
            }

            #line 225 "src/analyzer/Block.pv"
            Array_MatchPattern__append(&patterns, pattern);
        }

        #line 228 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=>")) {
            #line 228 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 228 "src/analyzer/Block.pv"
            return false;
        }

        #line 230 "src/analyzer/Block.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 230 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 230 "src/analyzer/Block.pv"
            return false;
        }

        #line 232 "src/analyzer/Block.pv"
        struct MatchCase match_case = (struct MatchCase) {
            .first_token = first_match_token,
            .patterns = patterns,
            .body = block,
        };

        #line 238 "src/analyzer/Block.pv"
        Array_MatchCase__append(&cases, match_case);

        #line 240 "src/analyzer/Block.pv"
        Context__pop_scope(context);

        #line 242 "src/analyzer/Block.pv"
        if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
            #line 243 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 244 "src/analyzer/Block.pv"
            Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}");
            #line 245 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 249 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 249 "src/analyzer/Block.pv"
        return false;
    }

    #line 251 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__MATCH_STATEMENT, .matchstatement_value = { ._0 = expression, ._1 = cases} }));

    #line 253 "src/analyzer/Block.pv"
    return true;
}

#line 256 "src/analyzer/Block.pv"
bool Block__parse_match_pattern(struct Block* self, struct Context* context, struct Generics* generics, struct MatchPattern* pattern) {
    #line 257 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "_")) {
        #line 258 "src/analyzer/Block.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 259 "src/analyzer/Block.pv"
        return true;
    }

    #line 262 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__IDENTIFIER, "typeid")) {
        #line 263 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "(")) {
            #line 263 "src/analyzer/Block.pv"
            return false;
        }

        #line 265 "src/analyzer/Block.pv"
        struct Type type;
        #line 266 "src/analyzer/Block.pv"
        if (!Context__parse_type(context, &type, generics)) {
            #line 266 "src/analyzer/Block.pv"
            return false;
        }

        #line 268 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 268 "src/analyzer/Block.pv"
            return false;
        }

        #line 270 "src/analyzer/Block.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__TYPE_ID, .typeid_value = type };
        #line 271 "src/analyzer/Block.pv"
        return true;
    }

    #line 274 "src/analyzer/Block.pv"
    struct Token* token = Context__current(context);
    #line 275 "src/analyzer/Block.pv"
    if (token == 0) {
        #line 275 "src/analyzer/Block.pv"
        return false;
    }

    #line 277 "src/analyzer/Block.pv"
    struct Type* type = Context__get_value(context, token->value);

    #line 279 "src/analyzer/Block.pv"
    if (type != 0) {
        #line 280 "src/analyzer/Block.pv"
        Context__next_token(context);
        #line 281 "src/analyzer/Block.pv"
        struct Expression* expression = Expression__make(context->allocator, token, (struct ExpressionData) { .type = EXPRESSION_DATA__VARIABLE, .variable_value = token->value }, type);
        #line 282 "src/analyzer/Block.pv"
        *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__STATIC_VALUE, .staticvalue_value = expression };
        #line 283 "src/analyzer/Block.pv"
        return true;
    }

    #line 286 "src/analyzer/Block.pv"
    type = Context__parse_type2(context, generics);
    #line 287 "src/analyzer/Block.pv"
    if (type == 0) {
        #line 288 "src/analyzer/Block.pv"
        return false;
    } else if (!Type__is_enum(type)) {
        #line 290 "src/analyzer/Block.pv"
        Context__error_token(context, token, "Type is not an enum");
        #line 291 "src/analyzer/Block.pv"
        return false;
    }

    #line 294 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "::")) {
        #line 294 "src/analyzer/Block.pv"
        return false;
    }

    #line 296 "src/analyzer/Block.pv"
    struct Token* enum_variant_token = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
    #line 297 "src/analyzer/Block.pv"
    if (enum_variant_token == 0) {
        #line 297 "src/analyzer/Block.pv"
        return false;
    }

    #line 299 "src/analyzer/Block.pv"
    struct GenericMap* generic_map = 0;

    #line 301 "src/analyzer/Block.pv"
    switch (type->type) {
        #line 302 "src/analyzer/Block.pv"
        case TYPE__SELF: {
            #line 303 "src/analyzer/Block.pv"
            type = context->type_self;
        } break;
        #line 305 "src/analyzer/Block.pv"
        default: {
        } break;
    }

    #line 308 "src/analyzer/Block.pv"
    switch (type->type) {
        #line 309 "src/analyzer/Block.pv"
        case TYPE__ENUM: {
            #line 309 "src/analyzer/Block.pv"
            struct GenericMap* generics = type->enum_value._1;
            #line 309 "src/analyzer/Block.pv"
            generic_map = generics;
        } break;
        #line 310 "src/analyzer/Block.pv"
        case TYPE__ENUM_C: {
        } break;
        #line 311 "src/analyzer/Block.pv"
        default: {
            #line 312 "src/analyzer/Block.pv"
            Context__pop_scope(context);
            #line 313 "src/analyzer/Block.pv"
            Context__error(context, "Not an enum type");
            #line 314 "src/analyzer/Block.pv"
            return false;
        } break;
    }

    #line 318 "src/analyzer/Block.pv"
    struct EnumVariantResult enum_variant_result = Expression__get_enum_variant(context, type, enum_variant_token);
    #line 319 "src/analyzer/Block.pv"
    switch (enum_variant_result.type) {
        #line 320 "src/analyzer/Block.pv"
        case ENUM_VARIANT_RESULT__NONE: {
            #line 321 "src/analyzer/Block.pv"
            Context__error(context, "Could not find enum variant");
            #line 322 "src/analyzer/Block.pv"
            return false;
        } break;
        #line 324 "src/analyzer/Block.pv"
        case ENUM_VARIANT_RESULT__ENUM_VARIANT: {
            #line 324 "src/analyzer/Block.pv"
            struct EnumVariant* enum_variant = enum_variant_result.enumvariant_value;
            #line 325 "src/analyzer/Block.pv"
            struct Array_EnumVariantParameter parameters = Array_EnumVariantParameter__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });

            #line 327 "src/analyzer/Block.pv"
            if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
                #line 328 "src/analyzer/Block.pv"
                uintptr_t variable_i = 0;

                #line 330 "src/analyzer/Block.pv"
                while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 331 "src/analyzer/Block.pv"
                    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
                    #line 332 "src/analyzer/Block.pv"
                    struct Token* variable = Context__expect(context, TOKEN_TYPE__IDENTIFIER);
                    #line 333 "src/analyzer/Block.pv"
                    if (variable == 0) {
                        #line 333 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 333 "src/analyzer/Block.pv"
                        return false;
                    }

                    #line 335 "src/analyzer/Block.pv"
                    Array_EnumVariantParameter__append(&parameters, (struct EnumVariantParameter) { .ref = ref, .variable = variable });

                    #line 337 "src/analyzer/Block.pv"
                    struct Type* variable_type = Context__resolve_type(context->allocator, enum_variant->types.data + variable_i, generic_map, 0);
                    #line 338 "src/analyzer/Block.pv"
                    if (variable_type == 0) {
                        #line 338 "src/analyzer/Block.pv"
                        return false;
                    }

                    #line 340 "src/analyzer/Block.pv"
                    if (ref) {
                        #line 341 "src/analyzer/Block.pv"
                        struct Indirect* indirect = ArenaAllocator__store_Indirect(context->allocator, (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *variable_type });
                        #line 342 "src/analyzer/Block.pv"
                        variable_type = ArenaAllocator__store_Type(context->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
                    }

                    #line 345 "src/analyzer/Block.pv"
                    struct String variable_type_name = Naming__get_type_decl(&context->root->naming_decl, variable_type, context->type_self, 0);
                    #line 346 "src/analyzer/Block.pv"
                    String__prepend(&variable_type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
                    #line 347 "src/analyzer/Block.pv"
                    Context__inlay_hint(context, variable, String__c_str(&variable_type_name), INLAY_HINT_KIND__TYPE, false, false);

                    #line 349 "src/analyzer/Block.pv"
                    if (!Token__eq(variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                        #line 350 "src/analyzer/Block.pv"
                        if (!Context__set_value(context, variable, variable_type)) {
                            #line 350 "src/analyzer/Block.pv"
                            Context__pop_scope(context);
                            #line 350 "src/analyzer/Block.pv"
                            return false;
                        }
                    }

                    #line 353 "src/analyzer/Block.pv"
                    if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                        #line 354 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 355 "src/analyzer/Block.pv"
                        Context__pop_scope(context);
                        #line 356 "src/analyzer/Block.pv"
                        Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                        #line 357 "src/analyzer/Block.pv"
                        return false;
                    }

                    #line 360 "src/analyzer/Block.pv"
                    variable_i += 1;
                }

                #line 363 "src/analyzer/Block.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                    #line 363 "src/analyzer/Block.pv"
                    Context__pop_scope(context);
                    #line 363 "src/analyzer/Block.pv"
                    return false;
                }

                #line 365 "src/analyzer/Block.pv"
                if (parameters.length != enum_variant->types.length) {
                    #line 366 "src/analyzer/Block.pv"
                    struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 367 "src/analyzer/Block.pv"
                    String__append(&message, (struct str){ .ptr = "Number of parameters does not match, expected ", .length = strlen("Number of parameters does not match, expected ") });
                    #line 368 "src/analyzer/Block.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 369 "src/analyzer/Block.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            } else {
                #line 372 "src/analyzer/Block.pv"
                if (enum_variant->types.length > 0) {
                    #line 373 "src/analyzer/Block.pv"
                    struct String message = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                    #line 374 "src/analyzer/Block.pv"
                    String__append(&message, (struct str){ .ptr = "Expected ", .length = strlen("Expected ") });
                    #line 375 "src/analyzer/Block.pv"
                    String__append_usize(&message, enum_variant->types.length);
                    #line 376 "src/analyzer/Block.pv"
                    String__append(&message, (struct str){ .ptr = " parameters", .length = strlen(" parameters") });
                    #line 377 "src/analyzer/Block.pv"
                    Context__error_token(context, enum_variant_token, String__c_str(&message));
                }
            }

            #line 381 "src/analyzer/Block.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_VARIANT, .enumvariant_value = { ._0 = type, ._1 = enum_variant, ._2 = parameters} };
            #line 382 "src/analyzer/Block.pv"
            return true;
        } break;
        #line 384 "src/analyzer/Block.pv"
        case ENUM_VARIANT_RESULT__ENUM_CVALUE: {
            #line 384 "src/analyzer/Block.pv"
            struct EnumCValue* enum_variant = enum_variant_result.enumcvalue_value;
            #line 385 "src/analyzer/Block.pv"
            *pattern = (struct MatchPattern) { .type = MATCH_PATTERN__ENUM_CVALUE, .enumcvalue_value = enum_variant };
            #line 386 "src/analyzer/Block.pv"
            return true;
        } break;
    }
}

#line 391 "src/analyzer/Block.pv"
bool Block__parse_while_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 392 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);
    #line 393 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "while")) {
        #line 393 "src/analyzer/Block.pv"
        return false;
    }

    #line 395 "src/analyzer/Block.pv"
    struct Expression* expression = Expression__parse(context, generics);
    #line 396 "src/analyzer/Block.pv"
    if (expression == 0) {
        #line 396 "src/analyzer/Block.pv"
        return false;
    }

    #line 398 "src/analyzer/Block.pv"
    struct Block* block = Block__new_ptr(context);
    #line 399 "src/analyzer/Block.pv"
    block->is_loop = true;
    #line 400 "src/analyzer/Block.pv"
    if (!Block__parse(block, context, generics, true)) {
        #line 400 "src/analyzer/Block.pv"
        return false;
    }

    #line 402 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__WHILE_STATEMENT, .whilestatement_value = { ._0 = expression, ._1 = block} }));

    #line 404 "src/analyzer/Block.pv"
    return true;
}

#line 407 "src/analyzer/Block.pv"
bool Block__parse_for_variable(struct Block* self, struct Context* context, struct Array_ForVariable* variables) {
    #line 408 "src/analyzer/Block.pv"
    bool deref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "*");
    #line 409 "src/analyzer/Block.pv"
    bool ref = Context__check_next(context, TOKEN_TYPE__SYMBOL, "&");
    #line 410 "src/analyzer/Block.pv"
    struct Token* name = Context__expect(context, TOKEN_TYPE__IDENTIFIER);

    #line 412 "src/analyzer/Block.pv"
    if (name == 0) {
        #line 412 "src/analyzer/Block.pv"
        return false;
    }

    #line 414 "src/analyzer/Block.pv"
    Array_ForVariable__append(variables, (struct ForVariable) { .deref = deref, .ref = ref, .name = name });

    #line 416 "src/analyzer/Block.pv"
    return true;
}

#line 419 "src/analyzer/Block.pv"
bool Block__parse_for_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 420 "src/analyzer/Block.pv"
    struct Token* first_token = Context__current(context);

    #line 422 "src/analyzer/Block.pv"
    struct ForStatement for_statement = ForStatement__new(context->allocator);

    #line 424 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "for")) {
        #line 424 "src/analyzer/Block.pv"
        return false;
    }

    #line 426 "src/analyzer/Block.pv"
    if (Context__check_next(context, TOKEN_TYPE__SYMBOL, "(")) {
        #line 427 "src/analyzer/Block.pv"
        while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 428 "src/analyzer/Block.pv"
            if (!Block__parse_for_variable(self, context, &for_statement.variables)) {
                #line 428 "src/analyzer/Block.pv"
                return false;
            }

            #line 430 "src/analyzer/Block.pv"
            if (!Context__check_next(context, TOKEN_TYPE__SYMBOL, ",") && !Context__check_value(context, TOKEN_TYPE__SYMBOL, ")")) {
                #line 431 "src/analyzer/Block.pv"
                Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")");
                #line 432 "src/analyzer/Block.pv"
                return false;
            }
        }

        #line 436 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ")")) {
            #line 436 "src/analyzer/Block.pv"
            return false;
        }
    } else {
        #line 438 "src/analyzer/Block.pv"
        if (!Block__parse_for_variable(self, context, &for_statement.variables)) {
            #line 438 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 441 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "in")) {
        #line 441 "src/analyzer/Block.pv"
        return false;
    }

    #line 443 "src/analyzer/Block.pv"
    struct Token* expression_first_token = Context__current(context);
    #line 444 "src/analyzer/Block.pv"
    for_statement.expression = Expression__parse(context, generics);
    #line 445 "src/analyzer/Block.pv"
    if (for_statement.expression == 0) {
        #line 445 "src/analyzer/Block.pv"
        return false;
    }

    #line 447 "src/analyzer/Block.pv"
    struct GenericMap* generic_map = Type__get_generic_map(&for_statement.expression->return_type, context);

    #line 449 "src/analyzer/Block.pv"
    bool is_range = false;

    #line 451 "src/analyzer/Block.pv"
    switch (for_statement.expression->data.type) {
        #line 452 "src/analyzer/Block.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 452 "src/analyzer/Block.pv"
            struct Expression* target = for_statement.expression->data.invoke_value._0;
            #line 452 "src/analyzer/Block.pv"
            struct Array_InvokeArgument args = for_statement.expression->data.invoke_value._1;
            #line 453 "src/analyzer/Block.pv"
            switch (target->return_type.type) {
                #line 454 "src/analyzer/Block.pv"
                case TYPE__ENUM: {
                    #line 454 "src/analyzer/Block.pv"
                    struct Enum* enum_info = target->return_type.enum_value._0;
                    #line 454 "src/analyzer/Block.pv"
                    struct GenericMap* generic_map = target->return_type.enum_value._1;
                    #line 455 "src/analyzer/Block.pv"
                    if (str__eq(enum_info->name->value, (struct str){ .ptr = "Range", .length = strlen("Range") })) {
                        #line 456 "src/analyzer/Block.pv"
                        is_range = true;
                        #line 457 "src/analyzer/Block.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__RANGE, .range_value = { ._0 = args.data[0].value, ._1 = args.data[1].value} };
                        #line 458 "src/analyzer/Block.pv"
                        for_statement.iter_type = &generic_map->array.data[0];
                        #line 459 "src/analyzer/Block.pv"
                        for_statement.variables.data[0].type = &generic_map->array.data[0];
                    }
                } break;
                #line 462 "src/analyzer/Block.pv"
                default: {
                } break;
            }
        } break;
        #line 465 "src/analyzer/Block.pv"
        default: {
        } break;
    }

    #line 468 "src/analyzer/Block.pv"
    if (is_range) {
        #line 469 "src/analyzer/Block.pv"
        struct ForVariable variable = for_statement.variables.data[0];
        #line 470 "src/analyzer/Block.pv"
        struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable.type, context->type_self, 0);
        #line 471 "src/analyzer/Block.pv"
        String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
        #line 472 "src/analyzer/Block.pv"
        Context__inlay_hint(context, variable.name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);
    } else {
        #line 474 "src/analyzer/Block.pv"
        bool is_sequence = false;
        #line 475 "src/analyzer/Block.pv"
        switch (for_statement.expression->return_type.type) {
            #line 476 "src/analyzer/Block.pv"
            case TYPE__SEQUENCE: {
                #line 476 "src/analyzer/Block.pv"
                struct Sequence* sequence = for_statement.expression->return_type.sequence_value;
                #line 477 "src/analyzer/Block.pv"
                is_sequence = true;
                #line 478 "src/analyzer/Block.pv"
                for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__SEQUENCE, .sequence_value = for_statement.expression };
                #line 479 "src/analyzer/Block.pv"
                for_statement.iter_type = &for_statement.expression->return_type;
                #line 480 "src/analyzer/Block.pv"
                for_statement.value_type = &sequence->element;
            } break;
            #line 482 "src/analyzer/Block.pv"
            case TYPE__INDIRECT: {
                #line 482 "src/analyzer/Block.pv"
                struct Indirect* indirect = for_statement.expression->return_type.indirect_value;
                #line 483 "src/analyzer/Block.pv"
                switch (indirect->to.type) {
                    #line 484 "src/analyzer/Block.pv"
                    case TYPE__SEQUENCE: {
                        #line 484 "src/analyzer/Block.pv"
                        struct Sequence* sequence = indirect->to.sequence_value;
                        #line 485 "src/analyzer/Block.pv"
                        is_sequence = true;
                        #line 486 "src/analyzer/Block.pv"
                        for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__SEQUENCE, .sequence_value = for_statement.expression };
                        #line 487 "src/analyzer/Block.pv"
                        for_statement.iter_type = &for_statement.expression->return_type;
                        #line 488 "src/analyzer/Block.pv"
                        for_statement.value_type = &sequence->element;
                    } break;
                    #line 490 "src/analyzer/Block.pv"
                    default: {
                    } break;
                }
            } break;
            #line 493 "src/analyzer/Block.pv"
            default: {
            } break;
        }

        #line 496 "src/analyzer/Block.pv"
        if (!is_sequence) {
            #line 497 "src/analyzer/Block.pv"
            struct Token* iter_member = ArenaAllocator__store_Token(context->allocator, *expression_first_token);
            #line 498 "src/analyzer/Block.pv"
            iter_member->value = (struct str){ .ptr = "iter", .length = strlen("iter") };

            #line 500 "src/analyzer/Block.pv"
            struct Type* iter_member_type = Expression__get_member_type(context, &for_statement.expression->return_type, iter_member, false);
            #line 501 "src/analyzer/Block.pv"
            bool iter_member_is_function = false;

            #line 503 "src/analyzer/Block.pv"
            if (iter_member_type != 0) {
                #line 504 "src/analyzer/Block.pv"
                switch (iter_member_type->type) {
                    #line 505 "src/analyzer/Block.pv"
                    case TYPE__FUNCTION: {
                        #line 505 "src/analyzer/Block.pv"
                        iter_member_is_function = true;
                    } break;
                    #line 506 "src/analyzer/Block.pv"
                    default: {
                    } break;
                }
            }

            #line 510 "src/analyzer/Block.pv"
            if (!iter_member_is_function) {
                #line 511 "src/analyzer/Block.pv"
                for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = for_statement.expression };
                #line 512 "src/analyzer/Block.pv"
                for_statement.iter_type = &for_statement.expression->return_type;
            } else {
                #line 514 "src/analyzer/Block.pv"
                struct Array_InvokeArgument args = Array_InvokeArgument__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->context->allocator });
                #line 515 "src/analyzer/Block.pv"
                Array_InvokeArgument__append(&args, (struct InvokeArgument) { .value = for_statement.expression });

                #line 517 "src/analyzer/Block.pv"
                for_statement.type = (struct ForStatementType) { .type = FOR_STATEMENT_TYPE__ITER, .iter_value = Expression__make_type_function_call(context, iter_member, iter_member_type, args, generic_map) };
                #line 518 "src/analyzer/Block.pv"
                for_statement.iter_type = Expression__get_return_type(context, iter_member_type, iter_member, generic_map);
            }

            #line 521 "src/analyzer/Block.pv"
            struct Token value_member = *iter_member;
            #line 522 "src/analyzer/Block.pv"
            value_member.value = (struct str){ .ptr = "value", .length = strlen("value") };

            #line 524 "src/analyzer/Block.pv"
            struct Type* value_member_type = Expression__get_member_type(context, for_statement.iter_type, &value_member, true);
            #line 525 "src/analyzer/Block.pv"
            if (value_member_type == 0) {
                #line 525 "src/analyzer/Block.pv"
                return false;
            }
            #line 526 "src/analyzer/Block.pv"
            for_statement.value_type = Expression__get_return_type(context, value_member_type, &value_member, generic_map);
        }

        #line 529 "src/analyzer/Block.pv"
        uintptr_t variable_i = 0;
        #line 530 "src/analyzer/Block.pv"
        { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
        #line 530 "src/analyzer/Block.pv"
        while (ArrayIter_ref_ForVariable__next(&__iter)) {
            #line 530 "src/analyzer/Block.pv"
            struct ForVariable* variable = ArrayIter_ref_ForVariable__value(&__iter);

            #line 531 "src/analyzer/Block.pv"
            if (for_statement.variables.length == 1) {
                #line 532 "src/analyzer/Block.pv"
                variable->type = for_statement.value_type;
            } else {
                #line 534 "src/analyzer/Block.pv"
                struct Token value_member = *variable->name;
                #line 535 "src/analyzer/Block.pv"
                struct String value_name = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 536 "src/analyzer/Block.pv"
                String__append_usize(&value_name, variable_i);
                #line 537 "src/analyzer/Block.pv"
                value_member.type = TOKEN_TYPE__NUMBER;
                #line 538 "src/analyzer/Block.pv"
                value_member.value = String__as_str(&value_name);

                #line 540 "src/analyzer/Block.pv"
                variable->type = Expression__get_member_type(context, Type__deref(for_statement.value_type), &value_member, true);
            }

            #line 543 "src/analyzer/Block.pv"
            if (variable->deref) {
                #line 544 "src/analyzer/Block.pv"
                variable->type = Type__deref(variable->type);
            }

            #line 547 "src/analyzer/Block.pv"
            if (variable->ref) {
                #line 548 "src/analyzer/Block.pv"
                variable->type = Type__to_ptr(&(struct Type) { .type = TYPE__INDIRECT, .indirect_value = Indirect__new_reference((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, *variable->type) }, context->allocator);
            }

            #line 551 "src/analyzer/Block.pv"
            struct String type_name = Naming__get_type_decl(&context->root->naming_decl, variable->type, context->type_self, 0);
            #line 552 "src/analyzer/Block.pv"
            String__prepend(&type_name, (struct str){ .ptr = ": ", .length = strlen(": ") });
            #line 553 "src/analyzer/Block.pv"
            Context__inlay_hint(context, variable->name, String__c_str(&type_name), INLAY_HINT_KIND__TYPE, false, false);

            #line 555 "src/analyzer/Block.pv"
            variable_i += 1;
        } }
    }

    #line 559 "src/analyzer/Block.pv"
    Context__push_scope(context, self);

    #line 561 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement.variables);
    #line 561 "src/analyzer/Block.pv"
    while (ArrayIter_ref_ForVariable__next(&__iter)) {
        #line 561 "src/analyzer/Block.pv"
        struct ForVariable* variable2 = ArrayIter_ref_ForVariable__value(&__iter);

        #line 562 "src/analyzer/Block.pv"
        if (!Context__set_value(context, variable2->name, variable2->type)) {
            #line 562 "src/analyzer/Block.pv"
            Context__error(context, "set_value");
            #line 562 "src/analyzer/Block.pv"
            return false;
        }
    } }

    #line 565 "src/analyzer/Block.pv"
    for_statement.block = Block__new_ptr(context);
    #line 566 "src/analyzer/Block.pv"
    for_statement.block->is_loop = true;
    #line 567 "src/analyzer/Block.pv"
    if (!Block__parse(for_statement.block, context, generics, false)) {
        #line 567 "src/analyzer/Block.pv"
        return false;
    }

    #line 569 "src/analyzer/Block.pv"
    Context__pop_scope(context);

    #line 571 "src/analyzer/Block.pv"
    Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__FOR_STATEMENT, .forstatement_value = ArenaAllocator__store_ForStatement(context->allocator, for_statement) }));

    #line 573 "src/analyzer/Block.pv"
    return true;
}

#line 576 "src/analyzer/Block.pv"
bool Block__parse_defer_statement(struct Block* self, struct Context* context, struct Generics* generics) {
    #line 577 "src/analyzer/Block.pv"
    bool top_block_found = false;
    #line 578 "src/analyzer/Block.pv"
    { struct ArrayIter_ref_Scope __iter = Array_Scope__iter(&context->scopes);
    #line 578 "src/analyzer/Block.pv"
    while (ArrayIter_ref_Scope__next(&__iter)) {
        #line 578 "src/analyzer/Block.pv"
        struct Scope* scope = ArrayIter_ref_Scope__value(&__iter);

        #line 579 "src/analyzer/Block.pv"
        if (top_block_found) {
        } else {
            #line 581 "src/analyzer/Block.pv"
            struct Block* top_block = scope->block;
            #line 582 "src/analyzer/Block.pv"
            if (top_block != 0) {
                #line 583 "src/analyzer/Block.pv"
                top_block->is_top_level_and_has_defer_statements_inside = true;
                #line 584 "src/analyzer/Block.pv"
                top_block_found = true;
            }
        }
    } }

    #line 589 "src/analyzer/Block.pv"
    if (!top_block_found) {
        #line 589 "src/analyzer/Block.pv"
        Context__error(context, "could not find top_block for defer statements");
    }

    #line 591 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "defer")) {
        #line 591 "src/analyzer/Block.pv"
        return false;
    }

    #line 593 "src/analyzer/Block.pv"
    if (Context__check_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 594 "src/analyzer/Block.pv"
        struct Block* block = Block__new_ptr(context);
        #line 595 "src/analyzer/Block.pv"
        if (!Block__parse(block, context, generics, true)) {
            #line 595 "src/analyzer/Block.pv"
            return false;
        }
        #line 596 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__BLOCK, .block_value = block });
    } else {
        #line 598 "src/analyzer/Block.pv"
        struct Expression* expression = Expression__parse(context, generics);
        #line 599 "src/analyzer/Block.pv"
        if (expression == 0) {
            #line 599 "src/analyzer/Block.pv"
            return false;
        }
        #line 600 "src/analyzer/Block.pv"
        Array_DeferStatement__append(&self->defer_statements, (struct DeferStatement) { .type = DEFER_STATEMENT__EXPRESSION, .expression_value = expression });
        #line 601 "src/analyzer/Block.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
            #line 601 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 604 "src/analyzer/Block.pv"
    return true;
}

#line 607 "src/analyzer/Block.pv"
bool Block__parse(struct Block* self, struct Context* context, struct Generics* generics, bool new_scope) {
    #line 608 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "{")) {
        #line 608 "src/analyzer/Block.pv"
        return false;
    }
    #line 609 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 609 "src/analyzer/Block.pv"
        Context__push_scope(context, self);
    }

    #line 611 "src/analyzer/Block.pv"
    while (!Context__check_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 612 "src/analyzer/Block.pv"
        struct Token* token = &context->tokens[context->pos];
        #line 613 "src/analyzer/Block.pv"
        bool result = true;

        #line 615 "src/analyzer/Block.pv"
        if (Token__eq(token, TOKEN_TYPE__SYMBOL, "{")) {
            #line 616 "src/analyzer/Block.pv"
            struct Token* first_token = Context__current(context);
            #line 617 "src/analyzer/Block.pv"
            struct Block* block = Block__new_ptr(context);
            #line 618 "src/analyzer/Block.pv"
            result = Block__parse(block, context, generics, true);
            #line 619 "src/analyzer/Block.pv"
            if (result) {
                #line 619 "src/analyzer/Block.pv"
                Array_Statement__append(&self->statements, Statement__new(first_token, Context__prev(context), (struct StatementData) { .type = STATEMENT_DATA__BLOCK_STATEMENT, .blockstatement_value = block }));
            }
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "defer")) {
            #line 621 "src/analyzer/Block.pv"
            result = Block__parse_defer_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "let")) {
            #line 623 "src/analyzer/Block.pv"
            result = Block__parse_let_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "return")) {
            #line 625 "src/analyzer/Block.pv"
            result = Block__parse_return_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "yield")) {
            #line 627 "src/analyzer/Block.pv"
            result = Block__parse_yield_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "if")) {
            #line 629 "src/analyzer/Block.pv"
            result = Block__parse_if_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "match")) {
            #line 631 "src/analyzer/Block.pv"
            result = Block__parse_match_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "while")) {
            #line 633 "src/analyzer/Block.pv"
            result = Block__parse_while_statement(self, context, generics);
        } else if (Token__eq(token, TOKEN_TYPE__KEYWORD, "for")) {
            #line 635 "src/analyzer/Block.pv"
            result = Block__parse_for_statement(self, context, generics);
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "continue")) {
            #line 637 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__CONTINUE_STATEMENT, .continuestatement_value = Context__get_loop_defer_statements(context) }));
            #line 638 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 638 "src/analyzer/Block.pv"
                return false;
            }
            #line 639 "src/analyzer/Block.pv"
            result = true;
        } else if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "break")) {
            #line 641 "src/analyzer/Block.pv"
            Array_Statement__append(&self->statements, Statement__new(token, token, (struct StatementData) { .type = STATEMENT_DATA__BREAK_STATEMENT, .breakstatement_value = Context__get_loop_defer_statements(context) }));
            #line 642 "src/analyzer/Block.pv"
            if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, ";")) {
                #line 642 "src/analyzer/Block.pv"
                return false;
            }
            #line 643 "src/analyzer/Block.pv"
            result = true;
        } else {
            #line 645 "src/analyzer/Block.pv"
            result = Block__parse_expression_statement(self, context, generics);
        }

        #line 648 "src/analyzer/Block.pv"
        if (!result) {
            #line 649 "src/analyzer/Block.pv"
            if (new_scope) {
                #line 649 "src/analyzer/Block.pv"
                Context__pop_scope(context);
            }
            #line 650 "src/analyzer/Block.pv"
            return false;
        }
    }

    #line 654 "src/analyzer/Block.pv"
    if (new_scope) {
        #line 655 "src/analyzer/Block.pv"
        Context__pop_scope(context);
    }

    #line 658 "src/analyzer/Block.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "}")) {
        #line 658 "src/analyzer/Block.pv"
        return false;
    }

    #line 660 "src/analyzer/Block.pv"
    return true;
}
