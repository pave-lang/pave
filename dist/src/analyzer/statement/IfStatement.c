#include <stdint.h>
#include <string.h>

#include <usize.h>
#include <std/Array_Statement.h>
#include <analyzer/Block.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/Context.h>
#include <analyzer/TokenType.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/Generics.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Primitive.h>
#include <std/str.h>
#include <std/Array_NullNarrowing.h>
#include <std/trait_Allocator.h>
#include <std/Iter_ref_NullNarrowing.h>
#include <analyzer/expression/NullNarrowing.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/IfStatement.h>
#include <analyzer/statement/IfStatement.h>

#include <analyzer/statement/IfStatement.h>

#line 14 "src/analyzer/statement/IfStatement.pv"
bool IfStatement__block_always_diverges(struct Block* block) {
    #line 15 "src/analyzer/statement/IfStatement.pv"
    if (usize__Eq_usize__eq(block->statements.length, 0)) {
        #line 15 "src/analyzer/statement/IfStatement.pv"
        return false;
    }
    #line 16 "src/analyzer/statement/IfStatement.pv"
    struct Statement* last = &block->statements.data[block->statements.length - 1];
    #line 17 "src/analyzer/statement/IfStatement.pv"
    switch (last->data.type) {
        #line 18 "src/analyzer/statement/IfStatement.pv"
        case STATEMENT_DATA__RETURN_STATEMENT: {
            #line 18 "src/analyzer/statement/IfStatement.pv"
            return true;
        } break;
        #line 19 "src/analyzer/statement/IfStatement.pv"
        case STATEMENT_DATA__BREAK_STATEMENT: {
            #line 19 "src/analyzer/statement/IfStatement.pv"
            return true;
        } break;
        #line 20 "src/analyzer/statement/IfStatement.pv"
        case STATEMENT_DATA__CONTINUE_STATEMENT: {
            #line 20 "src/analyzer/statement/IfStatement.pv"
            return true;
        } break;
        #line 21 "src/analyzer/statement/IfStatement.pv"
        default: {
            #line 21 "src/analyzer/statement/IfStatement.pv"
            return false;
        } break;
    }
}

#line 25 "src/analyzer/statement/IfStatement.pv"
struct IfStatement* IfStatement__parse(struct Context* context, struct Generics* generics) {
    #line 26 "src/analyzer/statement/IfStatement.pv"
    if (!Context__expect_value(context, TOKEN_TYPE__KEYWORD, "if")) {
        #line 26 "src/analyzer/statement/IfStatement.pv"
        return 0;
    }

    #line 28 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* pattern = 0;
    #line 29 "src/analyzer/statement/IfStatement.pv"
    struct Expression* expression = 0;
    #line 30 "src/analyzer/statement/IfStatement.pv"
    struct Block* block = Block__new_ptr(context);

    #line 32 "src/analyzer/statement/IfStatement.pv"
    if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
        #line 33 "src/analyzer/statement/IfStatement.pv"
        Context__push_scope(context, block);
        #line 34 "src/analyzer/statement/IfStatement.pv"
        struct MatchPattern p = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
        #line 35 "src/analyzer/statement/IfStatement.pv"
        if (!MatchPattern__parse(context, generics, &p)) {
            #line 35 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 35 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 36 "src/analyzer/statement/IfStatement.pv"
        if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
            #line 36 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 36 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 37 "src/analyzer/statement/IfStatement.pv"
        pattern = ArenaAllocator__store_MatchPattern(context->allocator, &p);
        #line 38 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 39 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 39 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 39 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 40 "src/analyzer/statement/IfStatement.pv"
        switch (p.type) {
            #line 41 "src/analyzer/statement/IfStatement.pv"
            case MATCH_PATTERN__ENUM_VARIANT: {
                #line 41 "src/analyzer/statement/IfStatement.pv"
                struct Type* enum_type = p.enumvariant_value._0;
                #line 42 "src/analyzer/statement/IfStatement.pv"
                if (!Type__eq(Type__deref(&expression->return_type), enum_type)) {
                    #line 43 "src/analyzer/statement/IfStatement.pv"
                    Context__error_expression(context, expression, "If let expression type does not match pattern enum type");
                    #line 44 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 45 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
            #line 48 "src/analyzer/statement/IfStatement.pv"
            default: {
                #line 49 "src/analyzer/statement/IfStatement.pv"
                if (!Type__is_discriminated_union(Type__deref(&expression->return_type))) {
                    #line 50 "src/analyzer/statement/IfStatement.pv"
                    Context__error_expression(context, expression, "If let expression must be an enum (discriminated union)");
                    #line 51 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 52 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
        }
        #line 56 "src/analyzer/statement/IfStatement.pv"
        if (!Block__parse(block, context, generics, false)) {
            #line 56 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
            #line 56 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 57 "src/analyzer/statement/IfStatement.pv"
        Context__pop_scope(context);
    } else {
        #line 59 "src/analyzer/statement/IfStatement.pv"
        expression = Expression__parse(context, generics);
        #line 60 "src/analyzer/statement/IfStatement.pv"
        if (expression == 0) {
            #line 60 "src/analyzer/statement/IfStatement.pv"
            return 0;
        }
        #line 61 "src/analyzer/statement/IfStatement.pv"
        switch (expression->return_type.type) {
            #line 62 "src/analyzer/statement/IfStatement.pv"
            case TYPE__PRIMITIVE: {
                #line 62 "src/analyzer/statement/IfStatement.pv"
                struct Primitive* prim = expression->return_type.primitive_value;
                #line 63 "src/analyzer/statement/IfStatement.pv"
                if (prim == 0) {
                    #line 63 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 64 "src/analyzer/statement/IfStatement.pv"
                if (!str__Eq_str__eq(prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                    #line 65 "src/analyzer/statement/IfStatement.pv"
                    Context__error_expression(context, expression, "If condition must be a bool expression");
                    #line 66 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            } break;
            #line 69 "src/analyzer/statement/IfStatement.pv"
            default: {
                #line 70 "src/analyzer/statement/IfStatement.pv"
                Context__error_expression(context, expression, "If condition must be a bool expression");
                #line 71 "src/analyzer/statement/IfStatement.pv"
                return 0;
            } break;
        }

        #line 75 "src/analyzer/statement/IfStatement.pv"
        struct Array_NullNarrowing narrowings_true = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
        #line 76 "src/analyzer/statement/IfStatement.pv"
        Expression__collect_null_narrowings(context, expression, true, &narrowings_true);
        #line 77 "src/analyzer/statement/IfStatement.pv"
        if (narrowings_true.length > 0) {
            #line 78 "src/analyzer/statement/IfStatement.pv"
            Context__push_scope(context, block);
            #line 79 "src/analyzer/statement/IfStatement.pv"
            { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings_true);
            #line 79 "src/analyzer/statement/IfStatement.pv"
            while (Iter_ref_NullNarrowing__next(&__iter)) {
                #line 79 "src/analyzer/statement/IfStatement.pv"
                struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

                #line 79 "src/analyzer/statement/IfStatement.pv"
                Context__set_narrowed(context, narrow->path, narrow->type);
            } }
            #line 80 "src/analyzer/statement/IfStatement.pv"
            if (!Block__parse(block, context, generics, false)) {
                #line 80 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
                #line 80 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }
            #line 81 "src/analyzer/statement/IfStatement.pv"
            Context__pop_scope(context);
        } else {
            #line 83 "src/analyzer/statement/IfStatement.pv"
            if (!Block__parse(block, context, generics, true)) {
                #line 83 "src/analyzer/statement/IfStatement.pv"
                return 0;
            }
        }
    }

    #line 87 "src/analyzer/statement/IfStatement.pv"
    struct Array_ElseStatement else_statements = Array_ElseStatement__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
    #line 88 "src/analyzer/statement/IfStatement.pv"
    struct Expression* else_expression = 0;
    #line 89 "src/analyzer/statement/IfStatement.pv"
    struct MatchPattern* else_pattern = 0;
    #line 90 "src/analyzer/statement/IfStatement.pv"
    struct Block* else_block = 0;
    #line 91 "src/analyzer/statement/IfStatement.pv"
    bool else_end = false;

    #line 93 "src/analyzer/statement/IfStatement.pv"
    while (!else_end && Context__check_next(context, TOKEN_TYPE__KEYWORD, "else")) {
        #line 94 "src/analyzer/statement/IfStatement.pv"
        else_expression = 0;
        #line 95 "src/analyzer/statement/IfStatement.pv"
        else_pattern = 0;

        #line 97 "src/analyzer/statement/IfStatement.pv"
        if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "if")) {
            #line 98 "src/analyzer/statement/IfStatement.pv"
            if (Context__check_next(context, TOKEN_TYPE__KEYWORD, "let")) {
                #line 99 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 100 "src/analyzer/statement/IfStatement.pv"
                Context__push_scope(context, else_block);
                #line 101 "src/analyzer/statement/IfStatement.pv"
                struct MatchPattern ep = (struct MatchPattern) { .type = MATCH_PATTERN__DEFAULT };
                #line 102 "src/analyzer/statement/IfStatement.pv"
                if (!MatchPattern__parse(context, generics, &ep)) {
                    #line 102 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 102 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 103 "src/analyzer/statement/IfStatement.pv"
                if (!Context__expect_value(context, TOKEN_TYPE__SYMBOL, "=")) {
                    #line 103 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 103 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 104 "src/analyzer/statement/IfStatement.pv"
                else_pattern = ArenaAllocator__store_MatchPattern(context->allocator, &ep);
                #line 105 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 106 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 106 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 106 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 107 "src/analyzer/statement/IfStatement.pv"
                switch (ep.type) {
                    #line 108 "src/analyzer/statement/IfStatement.pv"
                    case MATCH_PATTERN__ENUM_VARIANT: {
                        #line 108 "src/analyzer/statement/IfStatement.pv"
                        struct Type* enum_type = ep.enumvariant_value._0;
                        #line 109 "src/analyzer/statement/IfStatement.pv"
                        if (!Type__eq(&else_expression->return_type, enum_type)) {
                            #line 110 "src/analyzer/statement/IfStatement.pv"
                            Context__error_expression(context, else_expression, "If let expression type does not match pattern enum type");
                            #line 111 "src/analyzer/statement/IfStatement.pv"
                            Context__pop_scope(context);
                            #line 112 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                    #line 115 "src/analyzer/statement/IfStatement.pv"
                    default: {
                        #line 116 "src/analyzer/statement/IfStatement.pv"
                        if (!Type__is_enum(&else_expression->return_type)) {
                            #line 117 "src/analyzer/statement/IfStatement.pv"
                            Context__error_expression(context, else_expression, "If let expression must be an enum (discriminated union)");
                            #line 118 "src/analyzer/statement/IfStatement.pv"
                            Context__pop_scope(context);
                            #line 119 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                }
                #line 123 "src/analyzer/statement/IfStatement.pv"
                if (else_block == 0) {
                    #line 123 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 123 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 124 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, false)) {
                    #line 124 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 124 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 125 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
            } else {
                #line 127 "src/analyzer/statement/IfStatement.pv"
                else_expression = Expression__parse(context, generics);
                #line 128 "src/analyzer/statement/IfStatement.pv"
                if (else_expression == 0) {
                    #line 128 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 129 "src/analyzer/statement/IfStatement.pv"
                switch (else_expression->return_type.type) {
                    #line 130 "src/analyzer/statement/IfStatement.pv"
                    case TYPE__PRIMITIVE: {
                        #line 130 "src/analyzer/statement/IfStatement.pv"
                        struct Primitive* prim = else_expression->return_type.primitive_value;
                        #line 131 "src/analyzer/statement/IfStatement.pv"
                        if (prim == 0) {
                            #line 131 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                        #line 132 "src/analyzer/statement/IfStatement.pv"
                        if (!str__Eq_str__eq(prim->name, (struct str){ .ptr = "bool", .length = strlen("bool") })) {
                            #line 133 "src/analyzer/statement/IfStatement.pv"
                            Context__error_expression(context, else_expression, "If condition must be a bool expression");
                            #line 134 "src/analyzer/statement/IfStatement.pv"
                            return 0;
                        }
                    } break;
                    #line 137 "src/analyzer/statement/IfStatement.pv"
                    default: {
                        #line 138 "src/analyzer/statement/IfStatement.pv"
                        Context__error_expression(context, else_expression, "If condition must be a bool expression");
                        #line 139 "src/analyzer/statement/IfStatement.pv"
                        return 0;
                    } break;
                }
                #line 142 "src/analyzer/statement/IfStatement.pv"
                else_block = Block__new_ptr(context);
                #line 143 "src/analyzer/statement/IfStatement.pv"
                if (else_block == 0) {
                    #line 143 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }

                #line 145 "src/analyzer/statement/IfStatement.pv"
                struct Array_NullNarrowing narrowings_true = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
                #line 146 "src/analyzer/statement/IfStatement.pv"
                Expression__collect_null_narrowings(context, else_expression, true, &narrowings_true);
                #line 147 "src/analyzer/statement/IfStatement.pv"
                if (narrowings_true.length > 0) {
                    #line 148 "src/analyzer/statement/IfStatement.pv"
                    Context__push_scope(context, else_block);
                    #line 149 "src/analyzer/statement/IfStatement.pv"
                    { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings_true);
                    #line 149 "src/analyzer/statement/IfStatement.pv"
                    while (Iter_ref_NullNarrowing__next(&__iter)) {
                        #line 149 "src/analyzer/statement/IfStatement.pv"
                        struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

                        #line 149 "src/analyzer/statement/IfStatement.pv"
                        Context__set_narrowed(context, narrow->path, narrow->type);
                    } }
                    #line 150 "src/analyzer/statement/IfStatement.pv"
                    if (!Block__parse(else_block, context, generics, false)) {
                        #line 150 "src/analyzer/statement/IfStatement.pv"
                        Context__pop_scope(context);
                        #line 150 "src/analyzer/statement/IfStatement.pv"
                        return 0;
                    }
                    #line 151 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                } else {
                    #line 153 "src/analyzer/statement/IfStatement.pv"
                    if (!Block__parse(else_block, context, generics, true)) {
                        #line 153 "src/analyzer/statement/IfStatement.pv"
                        return 0;
                    }
                }
            }
        } else {
            #line 157 "src/analyzer/statement/IfStatement.pv"
            else_end = true;
            #line 158 "src/analyzer/statement/IfStatement.pv"
            else_block = Block__new_ptr(context);

            #line 160 "src/analyzer/statement/IfStatement.pv"
            struct Array_NullNarrowing narrowings_false = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 161 "src/analyzer/statement/IfStatement.pv"
            if (pattern == 0 && expression != 0) {
                #line 162 "src/analyzer/statement/IfStatement.pv"
                Expression__collect_null_narrowings(context, expression, false, &narrowings_false);
            }

            #line 165 "src/analyzer/statement/IfStatement.pv"
            if (narrowings_false.length > 0) {
                #line 166 "src/analyzer/statement/IfStatement.pv"
                Context__push_scope(context, else_block);
                #line 167 "src/analyzer/statement/IfStatement.pv"
                { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings_false);
                #line 167 "src/analyzer/statement/IfStatement.pv"
                while (Iter_ref_NullNarrowing__next(&__iter)) {
                    #line 167 "src/analyzer/statement/IfStatement.pv"
                    struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

                    #line 167 "src/analyzer/statement/IfStatement.pv"
                    Context__set_narrowed(context, narrow->path, narrow->type);
                } }
                #line 168 "src/analyzer/statement/IfStatement.pv"
                if (else_block == 0) {
                    #line 168 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 168 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 169 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, false)) {
                    #line 169 "src/analyzer/statement/IfStatement.pv"
                    Context__pop_scope(context);
                    #line 169 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 170 "src/analyzer/statement/IfStatement.pv"
                Context__pop_scope(context);
            } else {
                #line 172 "src/analyzer/statement/IfStatement.pv"
                if (else_block == 0) {
                    #line 172 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
                #line 173 "src/analyzer/statement/IfStatement.pv"
                if (!Block__parse(else_block, context, generics, true)) {
                    #line 173 "src/analyzer/statement/IfStatement.pv"
                    return 0;
                }
            }
        }

        #line 177 "src/analyzer/statement/IfStatement.pv"
        Array_ElseStatement__append(&else_statements, (struct ElseStatement) {
            .pattern = else_pattern,
            .expression = else_expression,
            .block = else_block,
        });
    }

    #line 184 "src/analyzer/statement/IfStatement.pv"
    if (pattern == 0 && expression != 0 && usize__Eq_usize__eq(else_statements.length, 0)) {
        #line 185 "src/analyzer/statement/IfStatement.pv"
        if (IfStatement__block_always_diverges(block)) {
            #line 186 "src/analyzer/statement/IfStatement.pv"
            struct Array_NullNarrowing narrowings_after = Array_NullNarrowing__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = context->allocator });
            #line 187 "src/analyzer/statement/IfStatement.pv"
            Expression__collect_null_narrowings(context, expression, false, &narrowings_after);
            #line 188 "src/analyzer/statement/IfStatement.pv"
            { struct Iter_ref_NullNarrowing __iter = Array_NullNarrowing__iter(&narrowings_after);
            #line 188 "src/analyzer/statement/IfStatement.pv"
            while (Iter_ref_NullNarrowing__next(&__iter)) {
                #line 188 "src/analyzer/statement/IfStatement.pv"
                struct NullNarrowing* narrow = Iter_ref_NullNarrowing__value(&__iter);

                #line 188 "src/analyzer/statement/IfStatement.pv"
                Context__set_narrowed(context, narrow->path, narrow->type);
            } }
        }
    }

    #line 192 "src/analyzer/statement/IfStatement.pv"
    return ArenaAllocator__store_IfStatement(context->allocator, (struct IfStatement[]){(struct IfStatement) {
        .pattern = pattern,
        .expression = expression,
        .block = block,
        .else_statements = else_statements,
    }});
}
