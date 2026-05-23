#include <string.h>
#include <stdint.h>

#include <analyzer/expression/Expression.h>
#include <analyzer/expression/ExpressionData.h>
#include <std/str.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/Indirect.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Context.h>
#include <std/Array_Statement.h>
#include <analyzer/Block.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Token.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/IfStatement.h>

#include <analyzer/statement/IfStatement.h>

#line 17 "src/analyzer/statement/IfStatement.pv"
struct Type* IfStatement__detect_null_narrowing(struct Context* context, struct Expression* expr, bool narrow_on_true) {
    #line 18 "src/analyzer/statement/IfStatement.pv"
    struct Expression* inner = expr;
    #line 19 "src/analyzer/statement/IfStatement.pv"
    switch (inner->data.type) {
        #line 20 "src/analyzer/statement/IfStatement.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 20 "src/analyzer/statement/IfStatement.pv"
            struct Expression* child = inner->data.parenthesizedexpression_value;
            #line 20 "src/analyzer/statement/IfStatement.pv"
            inner = child;
        } break;
        #line 21 "src/analyzer/statement/IfStatement.pv"
        default: {
        } break;
    }

    #line 24 "src/analyzer/statement/IfStatement.pv"
    switch (inner->data.type) {
        #line 25 "src/analyzer/statement/IfStatement.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 25 "src/analyzer/statement/IfStatement.pv"
            struct Expression* lhs = inner->data.binaryexpression_value._0;
            #line 25 "src/analyzer/statement/IfStatement.pv"
            struct str op = inner->data.binaryexpression_value._1;
            #line 25 "src/analyzer/statement/IfStatement.pv"
            struct Expression* rhs = inner->data.binaryexpression_value._2;
            #line 26 "src/analyzer/statement/IfStatement.pv"
            struct str want_op = (struct str){ .ptr = narrow_on_true ? "!=" : "==", .length = strlen(narrow_on_true ? "!=" : "==") };
            #line 27 "src/analyzer/statement/IfStatement.pv"
            if (!str__Eq_str__eq(&op, want_op)) {
                #line 27 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }

            #line 29 "src/analyzer/statement/IfStatement.pv"
            struct Expression* var_expr = 0;
            #line 30 "src/analyzer/statement/IfStatement.pv"
            struct Expression* other = 0;

            #line 32 "src/analyzer/statement/IfStatement.pv"
            switch (lhs->data.type) {
                #line 33 "src/analyzer/statement/IfStatement.pv"
                case EXPRESSION_DATA__VARIABLE: {
                    #line 33 "src/analyzer/statement/IfStatement.pv"
                    var_expr = lhs;
                    #line 33 "src/analyzer/statement/IfStatement.pv"
                    other = rhs;
                } break;
                #line 34 "src/analyzer/statement/IfStatement.pv"
                default: {
                } break;
            }

            #line 37 "src/analyzer/statement/IfStatement.pv"
            if (var_expr == 0) {
                #line 38 "src/analyzer/statement/IfStatement.pv"
                switch (rhs->data.type) {
                    #line 39 "src/analyzer/statement/IfStatement.pv"
                    case EXPRESSION_DATA__VARIABLE: {
                        #line 39 "src/analyzer/statement/IfStatement.pv"
                        var_expr = rhs;
                        #line 39 "src/analyzer/statement/IfStatement.pv"
                        other = lhs;
                    } break;
                    #line 40 "src/analyzer/statement/IfStatement.pv"
                    default: {
                        #line 40 "src/analyzer/statement/IfStatement.pv"
                        return 0;
                    } break;
                }
            }

            #line 44 "src/analyzer/statement/IfStatement.pv"
            struct Expression* other_inner = other;
            #line 45 "src/analyzer/statement/IfStatement.pv"
            switch (other_inner->data.type) {
                #line 46 "src/analyzer/statement/IfStatement.pv"
                case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
                    #line 46 "src/analyzer/statement/IfStatement.pv"
                    struct Expression* c = other_inner->data.parenthesizedexpression_value;
                    #line 46 "src/analyzer/statement/IfStatement.pv"
                    other_inner = c;
                } break;
                #line 47 "src/analyzer/statement/IfStatement.pv"
                default: {
                } break;
            }

            #line 50 "src/analyzer/statement/IfStatement.pv"
            switch (other_inner->data.type) {
                #line 51 "src/analyzer/statement/IfStatement.pv"
                case EXPRESSION_DATA__NULL_LITERAL: {
                } break;
                #line 52 "src/analyzer/statement/IfStatement.pv"
                default: {
                    #line 52 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                } break;
            }

            #line 55 "src/analyzer/statement/IfStatement.pv"
            switch (var_expr->return_type.type) {
                #line 56 "src/analyzer/statement/IfStatement.pv"
                case TYPE__INDIRECT: {
                    #line 56 "src/analyzer/statement/IfStatement.pv"
                    struct Indirect* indirect = var_expr->return_type.indirect_value;
                    #line 57 "src/analyzer/statement/IfStatement.pv"
                    if (indirect->type != INDIRECT_TYPE__POINTER && indirect->type != INDIRECT_TYPE__CONST_POINTER) {
                        #line 58 "src/analyzer/statement/IfStatement.pv"
                        return 0;
                    }
                    #line 60 "src/analyzer/statement/IfStatement.pv"
                    struct Indirect* ref_indirect = Indirect__new_reference((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator }, indirect->to);
                    #line 61 "src/analyzer/statement/IfStatement.pv"
                    return ArenaAllocator__store_Type(context->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = ref_indirect }});
                } break;
                #line 63 "src/analyzer/statement/IfStatement.pv"
                default: {
                    #line 63 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                } break;
            }
        } break;
        #line 66 "src/analyzer/statement/IfStatement.pv"
        default: {
            #line 66 "src/analyzer/statement/IfStatement.pv"
            return 0;
        } break;
    }

    #line 69 "src/analyzer/statement/IfStatement.pv"
    return 0;
}

#line 72 "src/analyzer/statement/IfStatement.pv"
bool IfStatement__block_always_diverges(struct Block* block) {
    #line 73 "src/analyzer/statement/IfStatement.pv"
    if (block->statements.length == 0) {
        #line 73 "src/analyzer/statement/IfStatement.pv"
        return false;
    }
    #line 74 "src/analyzer/statement/IfStatement.pv"
    struct Statement* last = &block->statements.data[block->statements.length - 1];
    #line 75 "src/analyzer/statement/IfStatement.pv"
    switch (last->data.type) {
        #line 76 "src/analyzer/statement/IfStatement.pv"
        case STATEMENT_DATA__RETURN_STATEMENT: {
            #line 76 "src/analyzer/statement/IfStatement.pv"
            return true;
        } break;
        #line 77 "src/analyzer/statement/IfStatement.pv"
        case STATEMENT_DATA__BREAK_STATEMENT: {
            #line 77 "src/analyzer/statement/IfStatement.pv"
            return true;
        } break;
        #line 78 "src/analyzer/statement/IfStatement.pv"
        case STATEMENT_DATA__CONTINUE_STATEMENT: {
            #line 78 "src/analyzer/statement/IfStatement.pv"
            return true;
        } break;
        #line 79 "src/analyzer/statement/IfStatement.pv"
        default: {
            #line 79 "src/analyzer/statement/IfStatement.pv"
            return false;
        } break;
    }
}

#line 83 "src/analyzer/statement/IfStatement.pv"
struct str IfStatement__narrowed_var_name(struct Expression* expr) {
    #line 84 "src/analyzer/statement/IfStatement.pv"
    struct Expression* inner = expr;
    #line 85 "src/analyzer/statement/IfStatement.pv"
    switch (inner->data.type) {
        #line 86 "src/analyzer/statement/IfStatement.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 86 "src/analyzer/statement/IfStatement.pv"
            struct Expression* child = inner->data.parenthesizedexpression_value;
            #line 86 "src/analyzer/statement/IfStatement.pv"
            inner = child;
        } break;
        #line 87 "src/analyzer/statement/IfStatement.pv"
        default: {
        } break;
    }
    #line 89 "src/analyzer/statement/IfStatement.pv"
    switch (inner->data.type) {
        #line 90 "src/analyzer/statement/IfStatement.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 90 "src/analyzer/statement/IfStatement.pv"
            struct Expression* lhs = inner->data.binaryexpression_value._0;
            #line 90 "src/analyzer/statement/IfStatement.pv"
            struct Expression* rhs = inner->data.binaryexpression_value._2;
            #line 91 "src/analyzer/statement/IfStatement.pv"
            switch (lhs->data.type) {
                #line 92 "src/analyzer/statement/IfStatement.pv"
                case EXPRESSION_DATA__VARIABLE: {
                    #line 92 "src/analyzer/statement/IfStatement.pv"
                    struct str name = lhs->data.variable_value;
                    #line 92 "src/analyzer/statement/IfStatement.pv"
                    return name;
                } break;
                #line 93 "src/analyzer/statement/IfStatement.pv"
                default: {
                } break;
            }
            #line 95 "src/analyzer/statement/IfStatement.pv"
            switch (rhs->data.type) {
                #line 96 "src/analyzer/statement/IfStatement.pv"
                case EXPRESSION_DATA__VARIABLE: {
                    #line 96 "src/analyzer/statement/IfStatement.pv"
                    struct str name = rhs->data.variable_value;
                    #line 96 "src/analyzer/statement/IfStatement.pv"
                    return name;
                } break;
                #line 97 "src/analyzer/statement/IfStatement.pv"
                default: {
                } break;
            }
        } break;
        #line 100 "src/analyzer/statement/IfStatement.pv"
        default: {
        } break;
    }
    #line 102 "src/analyzer/statement/IfStatement.pv"
    return (struct str) { .ptr = 0, .length = 0 };
}

#line 105 "src/analyzer/statement/IfStatement.pv"
struct IfStatement* IfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 106 "src/analyzer/statement/IfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 106 "src/analyzer/statement/IfStatement.pv"
        return 0;
    }

    #line 108 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* pattern = 0;
    #line 109 "src/analyzer/statement/IfStatement.pv"
    struct Expression* expression = 0;
    #line 110 "src/analyzer/statement/IfStatement.pv"
    struct Block* block = Block__new_ptr(context);

    #line 112 "src/analyzer/statement/IfStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 113 "src/analyzer/statement/IfStatement.pv"
        Context__push_scope(context, block);
        #line 114 "src/analyzer/statement/IfStatement.pv"
        struct MatchPattern p = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 115 "src/analyzer/statement/IfStatement.pv"
        if (!MatchPattern__parse(context, generics, &p)) {
            #line 115 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 115 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 116 "src/analyzer/statement/IfStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 116 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 116 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 117 "src/analyzer/statement/IfStatement.pv"
        pattern = ArenaAllocator__store_MatchPattern(context->allocator, &p);
        #line 118 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 119 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 119 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 119 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 120 "src/analyzer/statement/IfStatement.pv"
        switch (p.type) {
            #line 121 "src/analyzer/statement/IfStatement.pv"
            case MATCH_PATTERN__ENUM_VARIANT: {
                #line 121 "src/analyzer/statement/IfStatement.pv"
                struct Type* enum_type = p.enumvariant_value._0;
                #line 122 "src/analyzer/statement/IfStatement.pv"
                if (!Type__eq(Type__deref(&expression->return_type), enum_type)) {
                    #line 123 "src/analyzer/statement/IfStatement.pv"
                    Context__error_token(context, expression->token, "If let expression type does not match pattern enum type");
                    #line 124 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 125 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
            #line 128 "src/analyzer/statement/IfStatement.pv"
            default: {
                #line 129 "src/analyzer/statement/IfStatement.pv"
                if (!Type__is_discriminated_union(Type__deref(&expression->return_type))) {
                    #line 130 "src/analyzer/statement/IfStatement.pv"
                    Context__error_token(context, expression->token, "If let expression must be an enum (discriminated union)");
                    #line 131 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 132 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
        }
        #line 136 "src/analyzer/statement/IfStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 136 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 136 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 137 "src/analyzer/statement/IfStatement.pv"
        Context__pop_scope(context);
    } else {
        #line 139 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 140 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 140 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 141 "src/analyzer/statement/IfStatement.pv"
        switch (expression->return_type.type) {
            #line 142 "src/analyzer/statement/IfStatement.pv"
            case TYPE__PRIMITIVE: {
                #line 142 "src/analyzer/statement/IfStatement.pv"
                struct Primitive* prim = expression->return_type.primitive_value;
                #line 143 "src/analyzer/statement/IfStatement.pv"
                if (!str__Eq_str__eq(&prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                    #line 144 "src/analyzer/statement/IfStatement.pv"
                    Context__error_token(context, expression->token, "If condition must be a bool expression");
                    #line 145 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
            #line 148 "src/analyzer/statement/IfStatement.pv"
            default: {
                #line 149 "src/analyzer/statement/IfStatement.pv"
                Context__error_token(context, expression->token, "If condition must be a bool expression");
                #line 150 "src/analyzer/statement/IfStatement.pv"
                return 0;
            } break;
        }

        #line 154 "src/analyzer/statement/IfStatement.pv"
        struct Type* narrow_true = IfStatement__detect_null_narrowing(context, expression, true);
        #line 155 "src/analyzer/statement/IfStatement.pv"
        if (narrow_true != 0) {
            #line 156 "src/analyzer/statement/IfStatement.pv"
            struct str var_name = IfStatement__narrowed_var_name(expression);
            #line 157 "src/analyzer/statement/IfStatement.pv"
            Context__push_scope(context, block);
            #line 158 "src/analyzer/statement/IfStatement.pv"
            Context__set_narrowed(context, var_name, narrow_true);
            #line 159 "src/analyzer/statement/IfStatement.pv"
            if (!Block__parse(block, context, generics, false)) {
                #line 159 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
                #line 159 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }
            #line 160 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
        } else {
            #line 162 "src/analyzer/statement/IfStatement.pv"
            if (!Block__parse(block, context, generics, true)) {
                #line 162 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }
        }
    }

    #line 166 "src/analyzer/statement/IfStatement.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 167 "src/analyzer/statement/IfStatement.pv"
    struct Expression* else_expression = 0;
    #line 168 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* else_pattern = 0;
    #line 169 "src/analyzer/statement/IfStatement.pv"
    struct Block* else_block = 0;
    #line 170 "src/analyzer/statement/IfStatement.pv"
    bool else_end = false;

    #line 172 "src/analyzer/statement/IfStatement.pv"
    while (!else_end && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 173 "src/analyzer/statement/IfStatement.pv"
        else_expression = 0;
        #line 174 "src/analyzer/statement/IfStatement.pv"
        else_pattern = 0;

        #line 176 "src/analyzer/statement/IfStatement.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 177 "src/analyzer/statement/IfStatement.pv"
            if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
                #line 178 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 179 "src/analyzer/statement/IfStatement.pv"
                Context__push_scope(context, else_block);
                #line 180 "src/analyzer/statement/IfStatement.pv"
                struct MatchPattern ep = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
                #line 181 "src/analyzer/statement/IfStatement.pv"
                if (!MatchPattern__parse(context, generics, &ep)) {
                    #line 181 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 181 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 182 "src/analyzer/statement/IfStatement.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
                    #line 182 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 182 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 183 "src/analyzer/statement/IfStatement.pv"
                else_pattern = ArenaAllocator__store_MatchPattern(context->allocator, &ep);
                #line 184 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 185 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 185 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 185 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 186 "src/analyzer/statement/IfStatement.pv"
                switch (ep.type) {
                    #line 187 "src/analyzer/statement/IfStatement.pv"
                    case MATCH_PATTERN__ENUM_VARIANT: {
                        #line 187 "src/analyzer/statement/IfStatement.pv"
                        struct Type* enum_type = ep.enumvariant_value._0;
                        #line 188 "src/analyzer/statement/IfStatement.pv"
                        if (!Type__eq(&else_expression->return_type, enum_type)) {
                            #line 189 "src/analyzer/statement/IfStatement.pv"
                            Context__error_token(context, else_expression->token, "If let expression type does not match pattern enum type");
                            #line 190 "src/analyzer/statement/IfStatement.pv"
                            Context__pop_scope(context);
                            #line 191 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                    #line 194 "src/analyzer/statement/IfStatement.pv"
                    default: {
                        #line 195 "src/analyzer/statement/IfStatement.pv"
                        if (!Type__is_enum(&else_expression->return_type)) {
                            #line 196 "src/analyzer/statement/IfStatement.pv"
                            Context__error_token(context, else_expression->token, "If let expression must be an enum (discriminated union)");
                            #line 197 "src/analyzer/statement/IfStatement.pv"
                            Context__pop_scope(context);
                            #line 198 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                }
                #line 202 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, false)) {
                    #line 202 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 202 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 203 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
            } else {
                #line 205 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 206 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 206 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 207 "src/analyzer/statement/IfStatement.pv"
                switch (else_expression->return_type.type) {
                    #line 208 "src/analyzer/statement/IfStatement.pv"
                    case TYPE__PRIMITIVE: {
                        #line 208 "src/analyzer/statement/IfStatement.pv"
                        struct Primitive* prim = else_expression->return_type.primitive_value;
                        #line 209 "src/analyzer/statement/IfStatement.pv"
                        if (!str__Eq_str__eq(&prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                            #line 210 "src/analyzer/statement/IfStatement.pv"
                            Context__error_token(context, else_expression->token, "If condition must be a bool expression");
                            #line 211 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                    #line 214 "src/analyzer/statement/IfStatement.pv"
                    default: {
                        #line 215 "src/analyzer/statement/IfStatement.pv"
                        Context__error_token(context, else_expression->token, "If condition must be a bool expression");
                        #line 216 "src/analyzer/statement/IfStatement.pv"
                        return 0;
                    } break;
                }
                #line 219 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 220 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, true)) {
                    #line 220 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            }
        } else {
            #line 223 "src/analyzer/statement/IfStatement.pv"
            else_end = true;
            #line 224 "src/analyzer/statement/IfStatement.pv"
            else_block = Block__new_ptr(context);

            #line 226 "src/analyzer/statement/IfStatement.pv"
            struct Type* narrow_false = 0;
            #line 227 "src/analyzer/statement/IfStatement.pv"
            if (pattern == 0 && expression != 0) {
                #line 228 "src/analyzer/statement/IfStatement.pv"
                narrow_false = IfStatement__detect_null_narrowing(context, expression, false);
            }

            #line 231 "src/analyzer/statement/IfStatement.pv"
            if (narrow_false != 0) {
                #line 232 "src/analyzer/statement/IfStatement.pv"
                struct str var_name = IfStatement__narrowed_var_name(expression);
                #line 233 "src/analyzer/statement/IfStatement.pv"
                Context__push_scope(context, else_block);
                #line 234 "src/analyzer/statement/IfStatement.pv"
                Context__set_narrowed(context, var_name, narrow_false);
                #line 235 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, false)) {
                    #line 235 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 235 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 236 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
            } else {
                #line 238 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, true)) {
                    #line 238 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            }
        }

        #line 242 "src/analyzer/statement/IfStatement.pv"
        Array_ElseStatement__append(&else_statements, (struct ElseStatement) {
            .pattern = else_pattern,
            .expression = else_expression,
            .block = else_block,
        });
    }

    #line 249 "src/analyzer/statement/IfStatement.pv"
    if (pattern == 0 && expression != 0 && else_statements.length == 0) {
        #line 250 "src/analyzer/statement/IfStatement.pv"
        if (IfStatement__block_always_diverges(block)) {
            #line 251 "src/analyzer/statement/IfStatement.pv"
            struct Type* narrow_after = IfStatement__detect_null_narrowing(context, expression, false);
            #line 252 "src/analyzer/statement/IfStatement.pv"
            if (narrow_after != 0) {
                #line 253 "src/analyzer/statement/IfStatement.pv"
                struct str var_name = IfStatement__narrowed_var_name(expression);
                #line 254 "src/analyzer/statement/IfStatement.pv"
                Context__set_narrowed(context, var_name, narrow_after);
            }
        }
    }

    #line 259 "src/analyzer/statement/IfStatement.pv"
    return ArenaAllocator__store_IfStatement(context->allocator, (struct IfStatement[]){(struct IfStatement) {
        .pattern = pattern,
        .expression = expression,
        .block = block,
        .else_statements = else_statements,
    }});
}
