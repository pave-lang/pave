#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <compiler/BlockWriter.h>
#include <compiler/Generator.h>
#include <compiler/ExpressionWriter.h>
#include <analyzer/types/Type.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/EnumVariant.h>
#include <std/Array_Type.h>
#include <std/Array_EnumVariantParameter.h>
#include <std/Iter_ref_EnumVariantParameter.h>
#include <analyzer/types/EnumVariantParameter.h>
#include <analyzer/Token.h>
#include <analyzer/TokenType.h>
#include <std/String.h>
#include <std/trait_Allocator.h>
#include <std/ArenaAllocator.h>
#include <std/str.h>
#include <std/Array_str.h>
#include <analyzer/expression/ExpressionData.h>
#include <analyzer/Context.h>
#include <analyzer/Block.h>
#include <compiler/FunctionContext.h>
#include <std/Array_DeferStatement.h>
#include <std/Iter_ref_DeferStatement.h>
#include <analyzer/statement/DeferStatement.h>
#include <std/Array_Statement.h>
#include <std/Iter_ref_Statement.h>
#include <analyzer/statement/Statement.h>
#include <analyzer/statement/StatementData.h>
#include <analyzer/statement/LetStatement.h>
#include <compiler/FunctionCoroutine.h>
#include <analyzer/statement/YieldStatement.h>
#include <analyzer/statement/ReturnStatement.h>
#include <analyzer/statement/MatchPattern.h>
#include <analyzer/statement/IfStatement.h>
#include <std/Array_ElseStatement.h>
#include <std/Iter_ref_ElseStatement.h>
#include <analyzer/statement/ElseStatement.h>
#include <analyzer/statement/MatchStatement.h>
#include <std/Array_MatchCase.h>
#include <std/Iter_ref_MatchCase.h>
#include <analyzer/statement/MatchCase.h>
#include <std/Array_MatchPattern.h>
#include <std/IterEnumerate_ref_MatchPattern.h>
#include <std/Iter_ref_MatchPattern.h>
#include <tuple_usize_ref_MatchPattern.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/EnumCValue.h>
#include <analyzer/c/ParentCpp.h>
#include <analyzer/Naming.h>
#include <std/Hashed.h>
#include <std/trait_Hash.h>
#include <f32.h>
#include <f64.h>
#include <u32.h>
#include <i32.h>
#include <analyzer/statement/WhileStatement.h>
#include <analyzer/statement/ForStatementType.h>
#include <analyzer/statement/ForStatement.h>
#include <analyzer/statement/ForVariable.h>
#include <std/Array_ForVariable.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Sequence.h>
#include <std/Iter_ref_ForVariable.h>
#include <analyzer/statement/AssignmentStatement.h>
#include <compiler/BlockWriter.h>

#include <compiler/BlockWriter.h>

#line 16 "src/compiler/BlockWriter.pv"
struct BlockWriter BlockWriter__new(struct Generator* generator) {
    #line 17 "src/compiler/BlockWriter.pv"
    return (struct BlockWriter) { .generator = generator };
}

#line 20 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_if_let_enum_variant(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Type* type, struct EnumVariant* enum_variant, struct Array_EnumVariantParameter* parameters, struct Expression* expression, struct Block* body, struct Block* outer_block, struct GenericMap* generics) {
    #line 21 "src/compiler/BlockWriter.pv"
    struct Generator* g = self->generator;
    #line 22 "src/compiler/BlockWriter.pv"
    struct ExpressionWriter expr = (struct ExpressionWriter) { .generator = g };
    #line 23 "src/compiler/BlockWriter.pv"
    struct Type* expr_type = &expression->return_type;
    #line 24 "src/compiler/BlockWriter.pv"
    bool is_discriminated_union = Generator__type_is_discriminated_union(g, expr_type, generics);

    #line 26 "src/compiler/BlockWriter.pv"
    fprintf(file, "if (");
    #line 27 "src/compiler/BlockWriter.pv"
    if (is_discriminated_union) {
        #line 28 "src/compiler/BlockWriter.pv"
        ExpressionWriter__write_expression(&expr, file, expression, generics);
        #line 29 "src/compiler/BlockWriter.pv"
        Generator__write_instance_member_accessor(g, file, expr_type, generics);
        #line 30 "src/compiler/BlockWriter.pv"
        fprintf(file, "type == ");
        #line 31 "src/compiler/BlockWriter.pv"
        Generator__write_enum_variant_name(g, file, type, enum_variant);
    } else {
        #line 33 "src/compiler/BlockWriter.pv"
        Generator__write_deref_if_needed(g, file, expr_type, generics);
        #line 34 "src/compiler/BlockWriter.pv"
        ExpressionWriter__write_expression(&expr, file, expression, generics);
        #line 35 "src/compiler/BlockWriter.pv"
        fprintf(file, " == ");
        #line 36 "src/compiler/BlockWriter.pv"
        Generator__write_enum_variant_name(g, file, type, enum_variant);
    }
    #line 38 "src/compiler/BlockWriter.pv"
    fprintf(file, ") {\n");
    #line 39 "src/compiler/BlockWriter.pv"
    g->indent += 1;

    #line 41 "src/compiler/BlockWriter.pv"
    struct Array_Type* types = &enum_variant->types;
    #line 42 "src/compiler/BlockWriter.pv"
    uintptr_t param_i = 0;
    #line 43 "src/compiler/BlockWriter.pv"
    { struct Iter_ref_EnumVariantParameter __iter = Array_EnumVariantParameter__iter(parameters);
    #line 43 "src/compiler/BlockWriter.pv"
    while (Iter_ref_EnumVariantParameter__next(&__iter)) {
        #line 43 "src/compiler/BlockWriter.pv"
        struct EnumVariantParameter* param_iter = Iter_ref_EnumVariantParameter__value(&__iter);

        #line 44 "src/compiler/BlockWriter.pv"
        if (Token__eq(param_iter->variable, TOKEN_TYPE__IDENTIFIER, "_")) {
            #line 45 "src/compiler/BlockWriter.pv"
            param_i += 1;
            #line 46 "src/compiler/BlockWriter.pv"
            continue;
        }

        #line 49 "src/compiler/BlockWriter.pv"
        struct Type* param_type;
        #line 50 "src/compiler/BlockWriter.pv"
        struct String accessor = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = g->allocator });
        #line 51 "src/compiler/BlockWriter.pv"
        String__append_str_lowercase(&accessor, enum_variant->name->value);
        #line 52 "src/compiler/BlockWriter.pv"
        String__append(&accessor, (struct str){ .ptr = "_value", .length = strlen("_value") });

        #line 54 "src/compiler/BlockWriter.pv"
        if (enum_variant->names.length > 0) {
            #line 55 "src/compiler/BlockWriter.pv"
            uintptr_t field_i = 0;
            #line 56 "src/compiler/BlockWriter.pv"
            while (field_i < enum_variant->names.length) {
                #line 57 "src/compiler/BlockWriter.pv"
                if (str__eq(enum_variant->names.data[field_i], param_iter->field_name)) {
                    #line 57 "src/compiler/BlockWriter.pv"
                    break;
                }
                #line 58 "src/compiler/BlockWriter.pv"
                field_i += 1;
            }
            #line 60 "src/compiler/BlockWriter.pv"
            param_type = types->data + field_i;
            #line 61 "src/compiler/BlockWriter.pv"
            String__append(&accessor, (struct str){ .ptr = ".", .length = strlen(".") });
            #line 62 "src/compiler/BlockWriter.pv"
            String__append(&accessor, param_iter->field_name);
        } else {
            #line 64 "src/compiler/BlockWriter.pv"
            param_type = types->data + param_i;
            #line 65 "src/compiler/BlockWriter.pv"
            if (types->length > 1) {
                #line 66 "src/compiler/BlockWriter.pv"
                String__append(&accessor, (struct str){ .ptr = "._", .length = strlen("._") });
                #line 67 "src/compiler/BlockWriter.pv"
                String__append_usize(&accessor, param_i);
            }
        }

        #line 71 "src/compiler/BlockWriter.pv"
        struct Expression* variable_expression = expression;
        #line 72 "src/compiler/BlockWriter.pv"
        variable_expression = Expression__make(g->allocator, param_iter->variable, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = variable_expression, ._1 = String__as_str(&accessor)} }, param_type);

        #line 74 "src/compiler/BlockWriter.pv"
        struct Token* name = param_iter->variable;
        #line 75 "src/compiler/BlockWriter.pv"
        Generator__write_line_directive(g, file, outer_block->context, name);
        #line 76 "src/compiler/BlockWriter.pv"
        Generator__write_indent(g, file);
        #line 77 "src/compiler/BlockWriter.pv"
        Generator__write_type(g, file, param_type, generics);
        #line 78 "src/compiler/BlockWriter.pv"
        if (param_iter->ref) {
            #line 78 "src/compiler/BlockWriter.pv"
            fprintf(file, "*");
        }
        #line 79 "src/compiler/BlockWriter.pv"
        fprintf(file, " ");
        #line 80 "src/compiler/BlockWriter.pv"
        Generator__write_token(g, file, name);
        #line 81 "src/compiler/BlockWriter.pv"
        fprintf(file, " = ");
        #line 82 "src/compiler/BlockWriter.pv"
        if (param_iter->ref) {
            #line 82 "src/compiler/BlockWriter.pv"
            fprintf(file, "&");
        }
        #line 83 "src/compiler/BlockWriter.pv"
        ExpressionWriter__write_expression(&expr, file, variable_expression, generics);
        #line 84 "src/compiler/BlockWriter.pv"
        fprintf(file, ";\n");

        #line 86 "src/compiler/BlockWriter.pv"
        param_i += 1;
    } }

    #line 89 "src/compiler/BlockWriter.pv"
    FunctionContext__push_scope(g->function_context, false, false);
    #line 90 "src/compiler/BlockWriter.pv"
    if (!BlockWriter__write_block(self, file, return_type, body, generics, true, true)) {
        #line 90 "src/compiler/BlockWriter.pv"
        return false;
    }
    #line 91 "src/compiler/BlockWriter.pv"
    FunctionContext__pop_scope(g->function_context);

    #line 93 "src/compiler/BlockWriter.pv"
    g->indent -= 1;
    #line 94 "src/compiler/BlockWriter.pv"
    Generator__write_indent(g, file);
    #line 95 "src/compiler/BlockWriter.pv"
    fprintf(file, "}");

    #line 97 "src/compiler/BlockWriter.pv"
    return true;
}

#line 100 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_defer_statements(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Array_DeferStatement* defer_statements, struct GenericMap* generics) {
    #line 101 "src/compiler/BlockWriter.pv"
    struct Generator* g = self->generator;
    #line 102 "src/compiler/BlockWriter.pv"
    struct ExpressionWriter expr = (struct ExpressionWriter) { .generator = g };
    #line 103 "src/compiler/BlockWriter.pv"
    { struct Iter_ref_DeferStatement __iter = Array_DeferStatement__iter(defer_statements);
    #line 103 "src/compiler/BlockWriter.pv"
    while (Iter_ref_DeferStatement__next(&__iter)) {
        #line 103 "src/compiler/BlockWriter.pv"
        struct DeferStatement* defer_info = Iter_ref_DeferStatement__value(&__iter);

        #line 104 "src/compiler/BlockWriter.pv"
        switch (defer_info->type) {
            #line 105 "src/compiler/BlockWriter.pv"
            case DEFER_STATEMENT__EXPRESSION: {
                #line 105 "src/compiler/BlockWriter.pv"
                struct Expression* expression = defer_info->expression_value;
                #line 106 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 107 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, expression, generics);
                #line 108 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 110 "src/compiler/BlockWriter.pv"
            case DEFER_STATEMENT__BLOCK: {
                #line 110 "src/compiler/BlockWriter.pv"
                struct Block* block = defer_info->block_value;
                #line 111 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 112 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(g->function_context, false, false);
                #line 113 "src/compiler/BlockWriter.pv"
                BlockWriter__write_block(self, file, return_type, block, generics, false, false);
                #line 114 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(g->function_context);
            } break;
        }
    } }

    #line 119 "src/compiler/BlockWriter.pv"
    return true;
}

#line 122 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_block(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Block* block, struct GenericMap* generics, bool inline_, bool no_brackets) {
    #line 123 "src/compiler/BlockWriter.pv"
    struct Generator* g = self->generator;
    #line 124 "src/compiler/BlockWriter.pv"
    struct ExpressionWriter expr = (struct ExpressionWriter) { .generator = g };

    #line 126 "src/compiler/BlockWriter.pv"
    if (block == 0) {
        #line 127 "src/compiler/BlockWriter.pv"
        fprintf(file, "{}\n");
        #line 128 "src/compiler/BlockWriter.pv"
        return false;
    }

    #line 131 "src/compiler/BlockWriter.pv"
    if (!no_brackets) {
        #line 132 "src/compiler/BlockWriter.pv"
        fprintf(file, "{\n");
        #line 133 "src/compiler/BlockWriter.pv"
        g->indent += 1;
    }

    #line 136 "src/compiler/BlockWriter.pv"
    if (block->is_top_level_and_has_defer_statements_inside && !Type__is_void(return_type)) {
        #line 137 "src/compiler/BlockWriter.pv"
        Generator__write_indent(g, file);
        #line 138 "src/compiler/BlockWriter.pv"
        Generator__write_type(g, file, return_type, generics);
        #line 139 "src/compiler/BlockWriter.pv"
        fprintf(file, " __result;\n\n");
    }

    #line 142 "src/compiler/BlockWriter.pv"
    bool last_statement_is_return = false;

    #line 144 "src/compiler/BlockWriter.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 144 "src/compiler/BlockWriter.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 144 "src/compiler/BlockWriter.pv"
        struct Statement* statement = Iter_ref_Statement__value(&__iter);

        #line 145 "src/compiler/BlockWriter.pv"
        if (statement > block->statements.data) {
            #line 146 "src/compiler/BlockWriter.pv"
            struct Statement* prev_statement = statement - 1;

            #line 148 "src/compiler/BlockWriter.pv"
            if (prev_statement->last_token->end_line < statement->first_token->start_line - 1) {
                #line 149 "src/compiler/BlockWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 153 "src/compiler/BlockWriter.pv"
        Generator__write_line_directive(g, file, block->context, statement->first_token);

        #line 155 "src/compiler/BlockWriter.pv"
        last_statement_is_return = false;

        #line 157 "src/compiler/BlockWriter.pv"
        switch (statement->data.type) {
            #line 158 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 158 "src/compiler/BlockWriter.pv"
                struct Block* child_block = statement->data.blockstatement_value;
                #line 159 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 160 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(g->function_context, false, false);
                #line 161 "src/compiler/BlockWriter.pv"
                if (!BlockWriter__write_block(self, file, return_type, child_block, generics, false, false)) {
                    #line 162 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 164 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(g->function_context);
            } break;
            #line 166 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 166 "src/compiler/BlockWriter.pv"
                struct LetStatement* let_statement = statement->data.letstatement_value;
                #line 167 "src/compiler/BlockWriter.pv"
                struct Token* name = let_statement->name;
                #line 168 "src/compiler/BlockWriter.pv"
                struct Type* type = let_statement->type;
                #line 169 "src/compiler/BlockWriter.pv"
                struct Expression* value = let_statement->value;

                #line 171 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);

                #line 173 "src/compiler/BlockWriter.pv"
                if (!let_statement->is_static) {
                    #line 174 "src/compiler/BlockWriter.pv"
                    FunctionContext__add_variable(g->function_context, name->value, type);
                }

                #line 177 "src/compiler/BlockWriter.pv"
                if (let_statement->is_static) {
                    #line 178 "src/compiler/BlockWriter.pv"
                    fprintf(file, "static ");
                }

                #line 181 "src/compiler/BlockWriter.pv"
                if (Generator__is_coroutine(g)) {
                    #line 182 "src/compiler/BlockWriter.pv"
                    Generator__write_variable(g, file, name->value);
                } else {
                    #line 184 "src/compiler/BlockWriter.pv"
                    Generator__write_variable_decl(g, file, name->value, type, generics);
                }

                #line 187 "src/compiler/BlockWriter.pv"
                if (value != 0) {
                    #line 188 "src/compiler/BlockWriter.pv"
                    fprintf(file, " = ");
                    #line 189 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, value, generics);
                }

                #line 192 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 194 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 194 "src/compiler/BlockWriter.pv"
                struct YieldStatement* yield_stmt = statement->data.yieldstatement_value;
                #line 195 "src/compiler/BlockWriter.pv"
                g->function_context->coroutine.yield_count += 1;

                #line 197 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 198 "src/compiler/BlockWriter.pv"
                uintptr_t yield_number = g->function_context->coroutine.yield_count;
                #line 199 "src/compiler/BlockWriter.pv"
                fprintf(file, "ctx->_value = ");
                #line 200 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, yield_stmt->expression, generics);
                #line 201 "src/compiler/BlockWriter.pv"
                fprintf(file, "; ctx->_state = %zu; return true; yield_%zu:;\n", yield_number, yield_number);
            } break;
            #line 203 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 203 "src/compiler/BlockWriter.pv"
                struct ReturnStatement* ret = statement->data.returnstatement_value;
                #line 204 "src/compiler/BlockWriter.pv"
                struct Expression* value = ret->expression;
                #line 205 "src/compiler/BlockWriter.pv"
                struct Array_DeferStatement* defer_statements = &ret->defer_statements;
                #line 206 "src/compiler/BlockWriter.pv"
                if (value == 0) {
                    #line 207 "src/compiler/BlockWriter.pv"
                    BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);
                    #line 208 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(g, file);
                    #line 209 "src/compiler/BlockWriter.pv"
                    fprintf(file, "return;\n");
                } else if (defer_statements->length > 0) {
                    #line 211 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(g, file);
                    #line 212 "src/compiler/BlockWriter.pv"
                    fprintf(file, "__result = ");
                    #line 213 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, value, generics);
                    #line 214 "src/compiler/BlockWriter.pv"
                    fprintf(file, ";\n");

                    #line 216 "src/compiler/BlockWriter.pv"
                    BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);

                    #line 218 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(g, file);
                    #line 219 "src/compiler/BlockWriter.pv"
                    fprintf(file, "return __result;\n");
                } else {
                    #line 221 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(g, file);
                    #line 222 "src/compiler/BlockWriter.pv"
                    fprintf(file, "return ");
                    #line 223 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, value, generics);
                    #line 224 "src/compiler/BlockWriter.pv"
                    fprintf(file, ";\n");
                }

                #line 227 "src/compiler/BlockWriter.pv"
                last_statement_is_return = true;
            } break;
            #line 229 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 229 "src/compiler/BlockWriter.pv"
                struct IfStatement* if_stmt = statement->data.ifstatement_value;
                #line 230 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);

                #line 232 "src/compiler/BlockWriter.pv"
                if (if_stmt->pattern != 0) {
                    #line 233 "src/compiler/BlockWriter.pv"
                    switch (if_stmt->pattern->type) {
                        #line 234 "src/compiler/BlockWriter.pv"
                        case MATCH_PATTERN__ENUM_VARIANT: {
                            #line 234 "src/compiler/BlockWriter.pv"
                            struct Type* type = if_stmt->pattern->enumvariant_value._0;
                            #line 234 "src/compiler/BlockWriter.pv"
                            struct EnumVariant* enum_variant = if_stmt->pattern->enumvariant_value._1;
                            #line 234 "src/compiler/BlockWriter.pv"
                            struct Array_EnumVariantParameter* parameters = &if_stmt->pattern->enumvariant_value._2;
                            #line 235 "src/compiler/BlockWriter.pv"
                            if (!BlockWriter__write_if_let_enum_variant(self, file, return_type, type, enum_variant, parameters, if_stmt->expression, if_stmt->block, block, generics)) {
                                #line 235 "src/compiler/BlockWriter.pv"
                                return false;
                            }
                        } break;
                        #line 237 "src/compiler/BlockWriter.pv"
                        default: {
                        } break;
                    }
                } else {
                    #line 240 "src/compiler/BlockWriter.pv"
                    fprintf(file, "if (");
                    #line 241 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, if_stmt->expression, generics);
                    #line 242 "src/compiler/BlockWriter.pv"
                    fprintf(file, ") ");
                    #line 243 "src/compiler/BlockWriter.pv"
                    FunctionContext__push_scope(g->function_context, false, false);
                    #line 244 "src/compiler/BlockWriter.pv"
                    if (!BlockWriter__write_block(self, file, return_type, if_stmt->block, generics, true, false)) {
                        #line 244 "src/compiler/BlockWriter.pv"
                        return false;
                    }
                    #line 245 "src/compiler/BlockWriter.pv"
                    FunctionContext__pop_scope(g->function_context);
                }

                #line 248 "src/compiler/BlockWriter.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&if_stmt->else_statements);
                #line 248 "src/compiler/BlockWriter.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 248 "src/compiler/BlockWriter.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 249 "src/compiler/BlockWriter.pv"
                    fprintf(file, " else ");

                    #line 251 "src/compiler/BlockWriter.pv"
                    if (else_statement->pattern != 0) {
                        #line 252 "src/compiler/BlockWriter.pv"
                        switch (else_statement->pattern->type) {
                            #line 253 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 253 "src/compiler/BlockWriter.pv"
                                struct Type* type = else_statement->pattern->enumvariant_value._0;
                                #line 253 "src/compiler/BlockWriter.pv"
                                struct EnumVariant* enum_variant = else_statement->pattern->enumvariant_value._1;
                                #line 253 "src/compiler/BlockWriter.pv"
                                struct Array_EnumVariantParameter* parameters = &else_statement->pattern->enumvariant_value._2;
                                #line 254 "src/compiler/BlockWriter.pv"
                                if (!BlockWriter__write_if_let_enum_variant(self, file, return_type, type, enum_variant, parameters, else_statement->expression, else_statement->block, block, generics)) {
                                    #line 254 "src/compiler/BlockWriter.pv"
                                    return false;
                                }
                            } break;
                            #line 256 "src/compiler/BlockWriter.pv"
                            default: {
                            } break;
                        }
                    } else if (else_statement->expression != 0) {
                        #line 259 "src/compiler/BlockWriter.pv"
                        fprintf(file, "if (");
                        #line 260 "src/compiler/BlockWriter.pv"
                        ExpressionWriter__write_expression(&expr, file, else_statement->expression, generics);
                        #line 261 "src/compiler/BlockWriter.pv"
                        fprintf(file, ") ");
                        #line 262 "src/compiler/BlockWriter.pv"
                        FunctionContext__push_scope(g->function_context, false, false);
                        #line 263 "src/compiler/BlockWriter.pv"
                        if (!BlockWriter__write_block(self, file, return_type, else_statement->block, generics, true, false)) {
                            #line 263 "src/compiler/BlockWriter.pv"
                            return false;
                        }
                        #line 264 "src/compiler/BlockWriter.pv"
                        FunctionContext__pop_scope(g->function_context);
                    } else {
                        #line 266 "src/compiler/BlockWriter.pv"
                        FunctionContext__push_scope(g->function_context, false, false);
                        #line 267 "src/compiler/BlockWriter.pv"
                        if (!BlockWriter__write_block(self, file, return_type, else_statement->block, generics, true, false)) {
                            #line 267 "src/compiler/BlockWriter.pv"
                            return false;
                        }
                        #line 268 "src/compiler/BlockWriter.pv"
                        FunctionContext__pop_scope(g->function_context);
                    }
                } }

                #line 272 "src/compiler/BlockWriter.pv"
                fprintf(file, "\n");
            } break;
            #line 274 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 274 "src/compiler/BlockWriter.pv"
                struct MatchStatement* match_stmt = statement->data.matchstatement_value;
                #line 275 "src/compiler/BlockWriter.pv"
                struct Expression* expression = match_stmt->expression;
                #line 276 "src/compiler/BlockWriter.pv"
                struct Array_MatchCase* cases = &match_stmt->cases;
                #line 277 "src/compiler/BlockWriter.pv"
                struct Type* return_type = &expression->return_type;
                #line 278 "src/compiler/BlockWriter.pv"
                bool is_discriminated_union = Generator__type_is_discriminated_union(g, return_type, generics);

                #line 280 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 281 "src/compiler/BlockWriter.pv"
                fprintf(file, "switch (");

                #line 283 "src/compiler/BlockWriter.pv"
                if (!is_discriminated_union) {
                    #line 284 "src/compiler/BlockWriter.pv"
                    Generator__write_deref_if_needed(g, file, return_type, generics);
                }

                #line 287 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, expression, generics);

                #line 289 "src/compiler/BlockWriter.pv"
                if (is_discriminated_union) {
                    #line 290 "src/compiler/BlockWriter.pv"
                    Generator__write_instance_member_accessor(g, file, return_type, generics);
                    #line 291 "src/compiler/BlockWriter.pv"
                    fprintf(file, "type");
                }

                #line 294 "src/compiler/BlockWriter.pv"
                fprintf(file, ") {\n");
                #line 295 "src/compiler/BlockWriter.pv"
                g->indent += 1;

                #line 297 "src/compiler/BlockWriter.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(cases);
                #line 297 "src/compiler/BlockWriter.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 297 "src/compiler/BlockWriter.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 298 "src/compiler/BlockWriter.pv"
                    Generator__write_line_directive(g, file, block->context, case_info->first_token);
                    #line 299 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(g, file);

                    #line 301 "src/compiler/BlockWriter.pv"
                    struct Array_MatchPattern* patterns = &case_info->patterns;
                    #line 302 "src/compiler/BlockWriter.pv"
                    { struct IterEnumerate_ref_MatchPattern __iter = Iter_ref_MatchPattern__enumerate(Array_MatchPattern__iter(patterns));
                    #line 302 "src/compiler/BlockWriter.pv"
                    while (IterEnumerate_ref_MatchPattern__next(&__iter)) {
                        #line 302 "src/compiler/BlockWriter.pv"
                        uintptr_t i = IterEnumerate_ref_MatchPattern__value(&__iter)._0;
                        #line 302 "src/compiler/BlockWriter.pv"
                        struct MatchPattern* pattern = IterEnumerate_ref_MatchPattern__value(&__iter)._1;

                        #line 303 "src/compiler/BlockWriter.pv"
                        if (i > 0) {
                            #line 303 "src/compiler/BlockWriter.pv"
                            fprintf(file, "\n");
                        }

                        #line 305 "src/compiler/BlockWriter.pv"
                        switch (pattern->type) {
                            #line 306 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__STATIC_VALUE: {
                                #line 306 "src/compiler/BlockWriter.pv"
                                struct Expression* expr_val = pattern->staticvalue_value;
                                #line 307 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 308 "src/compiler/BlockWriter.pv"
                                ExpressionWriter__write_expression(&expr, file, expr_val, generics);
                                #line 309 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 311 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 311 "src/compiler/BlockWriter.pv"
                                struct Type* type = pattern->enumvariant_value._0;
                                #line 311 "src/compiler/BlockWriter.pv"
                                struct EnumVariant* enum_variant = pattern->enumvariant_value._1;
                                #line 312 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 313 "src/compiler/BlockWriter.pv"
                                Generator__write_enum_variant_name(g, file, type, enum_variant);
                                #line 314 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 316 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_CVALUE: {
                                #line 316 "src/compiler/BlockWriter.pv"
                                struct EnumCValue* enum_variant = pattern->enumcvalue_value;
                                #line 317 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");

                                #line 319 "src/compiler/BlockWriter.pv"
                                struct EnumC* enum_info = enum_variant->parent;
                                #line 320 "src/compiler/BlockWriter.pv"
                                if (!ParentCpp__is_none(&enum_info->parent)) {
                                    #line 321 "src/compiler/BlockWriter.pv"
                                    struct String type_name = Naming__get_type_name(g->naming_decl, (struct Type[]){(struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info }}, generics->self_type, generics);
                                    #line 322 "src/compiler/BlockWriter.pv"
                                    Generator__write_str(g, file, String__as_str(&type_name));
                                    #line 323 "src/compiler/BlockWriter.pv"
                                    String__release(&type_name);
                                    #line 324 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "::");
                                }

                                #line 327 "src/compiler/BlockWriter.pv"
                                Generator__write_str(g, file, enum_variant->name);
                                #line 328 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 330 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__TYPE_ID: {
                                #line 330 "src/compiler/BlockWriter.pv"
                                struct Type* type = &pattern->typeid_value;
                                #line 331 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 332 "src/compiler/BlockWriter.pv"
                                Generator__write_typeid(g, file, type, generics);
                                #line 333 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 335 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__HASH: {
                                #line 335 "src/compiler/BlockWriter.pv"
                                struct Token* token = pattern->hash_value;
                                #line 336 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 337 "src/compiler/BlockWriter.pv"
                                Hashed hash;

                                #line 339 "src/compiler/BlockWriter.pv"
                                switch (token->type) {
                                    #line 340 "src/compiler/BlockWriter.pv"
                                    case TOKEN_TYPE__STRING: {
                                        #line 341 "src/compiler/BlockWriter.pv"
                                        struct str value = str__slice(token->value, 1, token->value.length - 1);
                                        #line 342 "src/compiler/BlockWriter.pv"
                                        hash = str__Hash__hash(&value);
                                    } break;
                                    #line 344 "src/compiler/BlockWriter.pv"
                                    case TOKEN_TYPE__NUMBER: {
                                        #line 345 "src/compiler/BlockWriter.pv"
                                        struct str primitive = Expression__number_primitive(token->value);
                                        #line 346 "src/compiler/BlockWriter.pv"
                                        switch (str__Hash__hash(&primitive)) {
                                            #line 347 "src/compiler/BlockWriter.pv"
                                            case 15952682373371409732ULL: {
                                                #line 348 "src/compiler/BlockWriter.pv"
                                                float value = strtof(token->value.ptr, 0);
                                                #line 349 "src/compiler/BlockWriter.pv"
                                                hash = f32__Hash__hash(&value);
                                            } break;
                                            #line 351 "src/compiler/BlockWriter.pv"
                                            case 15957463049929925035ULL: {
                                                #line 352 "src/compiler/BlockWriter.pv"
                                                double value = strtod(token->value.ptr, 0);
                                                #line 353 "src/compiler/BlockWriter.pv"
                                                hash = f64__Hash__hash(&value);
                                            } break;
                                            #line 355 "src/compiler/BlockWriter.pv"
                                            case 5560783464435099345ULL: {
                                                #line 356 "src/compiler/BlockWriter.pv"
                                                uint32_t value = strtoul(token->value.ptr, 0, 10);
                                                #line 357 "src/compiler/BlockWriter.pv"
                                                hash = u32__Hash__hash(&value);
                                            } break;
                                            #line 359 "src/compiler/BlockWriter.pv"
                                            case 3094732814638223685ULL: {
                                                #line 360 "src/compiler/BlockWriter.pv"
                                                int32_t value = strtol(token->value.ptr, 0, 10);
                                                #line 361 "src/compiler/BlockWriter.pv"
                                                hash = i32__Hash__hash(&value);
                                            } break;
                                            #line 363 "src/compiler/BlockWriter.pv"
                                            default: {
                                                #line 364 "src/compiler/BlockWriter.pv"
                                                fprintf(stderr, "Hash match pattern on unsupported number literal type\n");
                                                #line 365 "src/compiler/BlockWriter.pv"
                                                hash = 0;
                                            } break;
                                        }
                                    } break;
                                    #line 369 "src/compiler/BlockWriter.pv"
                                    default: {
                                        #line 370 "src/compiler/BlockWriter.pv"
                                        fprintf(stderr, "Hash match pattern on unsupported token type\n");
                                        #line 371 "src/compiler/BlockWriter.pv"
                                        hash = 0;
                                    } break;
                                }

                                #line 375 "src/compiler/BlockWriter.pv"
                                fprintf(file, "%lluULL:", hash);
                            } break;
                            #line 377 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__DEFAULT: {
                                #line 378 "src/compiler/BlockWriter.pv"
                                fprintf(file, "default:");
                            } break;
                        }
                    } }

                    #line 383 "src/compiler/BlockWriter.pv"
                    fprintf(file, " {\n");
                    #line 384 "src/compiler/BlockWriter.pv"
                    g->indent += 1;

                    #line 386 "src/compiler/BlockWriter.pv"
                    { struct Iter_ref_MatchPattern __iter = Array_MatchPattern__iter(patterns);
                    #line 386 "src/compiler/BlockWriter.pv"
                    while (Iter_ref_MatchPattern__next(&__iter)) {
                        #line 386 "src/compiler/BlockWriter.pv"
                        struct MatchPattern* pattern = Iter_ref_MatchPattern__value(&__iter);

                        #line 387 "src/compiler/BlockWriter.pv"
                        switch (pattern->type) {
                            #line 388 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__STATIC_VALUE: {
                            } break;
                            #line 389 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 389 "src/compiler/BlockWriter.pv"
                                struct EnumVariant* enum_variant = pattern->enumvariant_value._1;
                                #line 389 "src/compiler/BlockWriter.pv"
                                struct Array_EnumVariantParameter* parameters = &pattern->enumvariant_value._2;
                                #line 390 "src/compiler/BlockWriter.pv"
                                struct Array_Type* types = &enum_variant->types;
                                #line 391 "src/compiler/BlockWriter.pv"
                                uintptr_t param_i = 0;
                                #line 392 "src/compiler/BlockWriter.pv"
                                { struct Iter_ref_EnumVariantParameter __iter = Array_EnumVariantParameter__iter(parameters);
                                #line 392 "src/compiler/BlockWriter.pv"
                                while (Iter_ref_EnumVariantParameter__next(&__iter)) {
                                    #line 392 "src/compiler/BlockWriter.pv"
                                    struct EnumVariantParameter* param_iter = Iter_ref_EnumVariantParameter__value(&__iter);

                                    #line 393 "src/compiler/BlockWriter.pv"
                                    if (Token__eq(param_iter->variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                                        #line 394 "src/compiler/BlockWriter.pv"
                                        param_i += 1;
                                        #line 395 "src/compiler/BlockWriter.pv"
                                        continue;
                                    }

                                    #line 398 "src/compiler/BlockWriter.pv"
                                    struct Type* param_type;
                                    #line 399 "src/compiler/BlockWriter.pv"
                                    struct String accessor = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = g->allocator });
                                    #line 400 "src/compiler/BlockWriter.pv"
                                    String__append_str_lowercase(&accessor, enum_variant->name->value);
                                    #line 401 "src/compiler/BlockWriter.pv"
                                    String__append(&accessor, (struct str){ .ptr = "_value", .length = strlen("_value") });

                                    #line 403 "src/compiler/BlockWriter.pv"
                                    if (enum_variant->names.length > 0) {
                                        #line 404 "src/compiler/BlockWriter.pv"
                                        uintptr_t field_i = 0;
                                        #line 405 "src/compiler/BlockWriter.pv"
                                        while (field_i < enum_variant->names.length) {
                                            #line 406 "src/compiler/BlockWriter.pv"
                                            if (str__eq(enum_variant->names.data[field_i], param_iter->field_name)) {
                                                #line 406 "src/compiler/BlockWriter.pv"
                                                break;
                                            }
                                            #line 407 "src/compiler/BlockWriter.pv"
                                            field_i += 1;
                                        }
                                        #line 409 "src/compiler/BlockWriter.pv"
                                        param_type = types->data + field_i;
                                        #line 410 "src/compiler/BlockWriter.pv"
                                        String__append(&accessor, (struct str){ .ptr = ".", .length = strlen(".") });
                                        #line 411 "src/compiler/BlockWriter.pv"
                                        String__append(&accessor, param_iter->field_name);
                                    } else {
                                        #line 413 "src/compiler/BlockWriter.pv"
                                        param_type = types->data + param_i;
                                        #line 414 "src/compiler/BlockWriter.pv"
                                        if (types->length > 1) {
                                            #line 415 "src/compiler/BlockWriter.pv"
                                            String__append(&accessor, (struct str){ .ptr = "._", .length = strlen("._") });
                                            #line 416 "src/compiler/BlockWriter.pv"
                                            String__append_usize(&accessor, param_i);
                                        }
                                    }

                                    #line 420 "src/compiler/BlockWriter.pv"
                                    struct Expression* variable_expression = expression;
                                    #line 421 "src/compiler/BlockWriter.pv"
                                    variable_expression = Expression__make(g->allocator, param_iter->variable, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = variable_expression, ._1 = String__as_str(&accessor)} }, param_type);

                                    #line 423 "src/compiler/BlockWriter.pv"
                                    struct Token* name = param_iter->variable;
                                    #line 424 "src/compiler/BlockWriter.pv"
                                    Generator__write_line_directive(g, file, block->context, name);
                                    #line 425 "src/compiler/BlockWriter.pv"
                                    Generator__write_indent(g, file);
                                    #line 426 "src/compiler/BlockWriter.pv"
                                    Generator__write_type(g, file, param_type, generics);
                                    #line 427 "src/compiler/BlockWriter.pv"
                                    if (param_iter->ref) {
                                        #line 427 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 428 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " ");
                                    #line 429 "src/compiler/BlockWriter.pv"
                                    Generator__write_token(g, file, name);
                                    #line 430 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " = ");
                                    #line 431 "src/compiler/BlockWriter.pv"
                                    if (param_iter->ref) {
                                        #line 431 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 432 "src/compiler/BlockWriter.pv"
                                    ExpressionWriter__write_expression(&expr, file, variable_expression, generics);
                                    #line 433 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ";\n");

                                    #line 435 "src/compiler/BlockWriter.pv"
                                    param_i += 1;
                                } }
                            } break;
                            #line 438 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_CVALUE: {
                            } break;
                            #line 439 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__TYPE_ID: {
                            } break;
                            #line 440 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__HASH: {
                            } break;
                            #line 441 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__DEFAULT: {
                            } break;
                        }
                    } }

                    #line 445 "src/compiler/BlockWriter.pv"
                    FunctionContext__push_scope(g->function_context, true, false);
                    #line 446 "src/compiler/BlockWriter.pv"
                    if (!BlockWriter__write_block(self, file, return_type, case_info->body, generics, true, true)) {
                        #line 446 "src/compiler/BlockWriter.pv"
                        return false;
                    }
                    #line 447 "src/compiler/BlockWriter.pv"
                    FunctionContext__pop_scope(g->function_context);

                    #line 449 "src/compiler/BlockWriter.pv"
                    g->indent -= 1;
                    #line 450 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(g, file);
                    #line 451 "src/compiler/BlockWriter.pv"
                    fprintf(file, "} break;\n");
                } }

                #line 454 "src/compiler/BlockWriter.pv"
                g->indent -= 1;
                #line 455 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 456 "src/compiler/BlockWriter.pv"
                fprintf(file, "}\n");
            } break;
            #line 458 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 458 "src/compiler/BlockWriter.pv"
                struct WhileStatement* while_stmt = statement->data.whilestatement_value;
                #line 459 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 460 "src/compiler/BlockWriter.pv"
                fprintf(file, "while (");
                #line 461 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, while_stmt->expression, generics);
                #line 462 "src/compiler/BlockWriter.pv"
                fprintf(file, ") ");
                #line 463 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(g->function_context, true, true);
                #line 464 "src/compiler/BlockWriter.pv"
                if (!BlockWriter__write_block(self, file, return_type, while_stmt->block, generics, false, false)) {
                    #line 464 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 465 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(g->function_context);
            } break;
            #line 467 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 467 "src/compiler/BlockWriter.pv"
                struct ForStatement* for_statement = statement->data.forstatement_value;
                #line 468 "src/compiler/BlockWriter.pv"
                bool is_iterator = false;

                #line 470 "src/compiler/BlockWriter.pv"
                switch (for_statement->type.type) {
                    #line 471 "src/compiler/BlockWriter.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 471 "src/compiler/BlockWriter.pv"
                        struct Expression* start = for_statement->type.range_value._0;
                        #line 471 "src/compiler/BlockWriter.pv"
                        struct Expression* end = for_statement->type.range_value._1;
                        #line 472 "src/compiler/BlockWriter.pv"
                        is_iterator = true;
                        #line 473 "src/compiler/BlockWriter.pv"
                        struct ForVariable* variable = &for_statement->variables.data[0];
                        #line 474 "src/compiler/BlockWriter.pv"
                        struct str variable_name = variable->name->value;

                        #line 476 "src/compiler/BlockWriter.pv"
                        Generator__write_indent(g, file);
                        #line 477 "src/compiler/BlockWriter.pv"
                        fprintf(file, "for (");

                        #line 479 "src/compiler/BlockWriter.pv"
                        FunctionContext__add_variable(g->function_context, variable_name, variable->type);

                        #line 481 "src/compiler/BlockWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 482 "src/compiler/BlockWriter.pv"
                            Generator__write_variable(g, file, variable_name);
                        } else {
                            #line 484 "src/compiler/BlockWriter.pv"
                            Generator__write_variable_decl(g, file, variable_name, variable->type, generics);
                        }

                        #line 487 "src/compiler/BlockWriter.pv"
                        fprintf(file, " = ");
                        #line 488 "src/compiler/BlockWriter.pv"
                        ExpressionWriter__write_expression(&expr, file, start, generics);
                        #line 489 "src/compiler/BlockWriter.pv"
                        fprintf(file, "; ");
                        #line 490 "src/compiler/BlockWriter.pv"
                        Generator__write_variable(g, file, variable_name);
                        #line 491 "src/compiler/BlockWriter.pv"
                        fprintf(file, " < ");
                        #line 492 "src/compiler/BlockWriter.pv"
                        ExpressionWriter__write_expression(&expr, file, end, generics);
                        #line 493 "src/compiler/BlockWriter.pv"
                        fprintf(file, "; ");
                        #line 494 "src/compiler/BlockWriter.pv"
                        Generator__write_variable(g, file, variable_name);
                        #line 495 "src/compiler/BlockWriter.pv"
                        fprintf(file, "++) {");
                        #line 496 "src/compiler/BlockWriter.pv"
                        g->indent += 1;
                    } break;
                    #line 498 "src/compiler/BlockWriter.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 498 "src/compiler/BlockWriter.pv"
                        struct Expression* iter_expression = for_statement->type.sequence_value;
                        #line 499 "src/compiler/BlockWriter.pv"
                        is_iterator = true;
                        #line 500 "src/compiler/BlockWriter.pv"
                        Generator__write_indent(g, file);
                        #line 501 "src/compiler/BlockWriter.pv"
                        switch (Type__deref(for_statement->iter_type)->type) {
                            #line 502 "src/compiler/BlockWriter.pv"
                            case TYPE__SEQUENCE: {
                                #line 502 "src/compiler/BlockWriter.pv"
                                struct Sequence* sequence = Type__deref(for_statement->iter_type)->sequence_value;
                                #line 503 "src/compiler/BlockWriter.pv"
                                switch (sequence->type.type) {
                                    #line 504 "src/compiler/BlockWriter.pv"
                                    case SEQUENCE_TYPE__FIXED_ARRAY: {
                                        #line 504 "src/compiler/BlockWriter.pv"
                                        uintptr_t size = sequence->type.fixedarray_value;
                                        #line 505 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "for (size_t __iter = 0; __iter < %zu; __iter++) {\n", size);
                                    } break;
                                    #line 507 "src/compiler/BlockWriter.pv"
                                    case SEQUENCE_TYPE__SLICE: {
                                        #line 508 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "for (size_t __iter = 0; __iter < ");
                                        #line 509 "src/compiler/BlockWriter.pv"
                                        ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                        #line 510 "src/compiler/BlockWriter.pv"
                                        fprintf(file, ".length; __iter++) {\n");
                                    } break;
                                }
                            } break;
                            #line 514 "src/compiler/BlockWriter.pv"
                            default: {
                                #line 514 "src/compiler/BlockWriter.pv"
                                fprintf(file, "/* ERROR: Sequence for loop on non-sequence type */");
                            } break;
                        }

                        #line 517 "src/compiler/BlockWriter.pv"
                        g->indent += 1;

                        #line 519 "src/compiler/BlockWriter.pv"
                        uintptr_t i = 0;
                        #line 520 "src/compiler/BlockWriter.pv"
                        { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                        #line 520 "src/compiler/BlockWriter.pv"
                        while (Iter_ref_ForVariable__next(&__iter)) {
                            #line 520 "src/compiler/BlockWriter.pv"
                            struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                            #line 521 "src/compiler/BlockWriter.pv"
                            if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                #line 522 "src/compiler/BlockWriter.pv"
                                Generator__write_line_directive(g, file, block->context, variable->name);
                                #line 523 "src/compiler/BlockWriter.pv"
                                Generator__write_indent(g, file);
                                #line 524 "src/compiler/BlockWriter.pv"
                                Generator__write_type(g, file, variable->type, generics);
                                #line 525 "src/compiler/BlockWriter.pv"
                                fprintf(file, " ");
                                #line 526 "src/compiler/BlockWriter.pv"
                                Generator__write_token(g, file, variable->name);
                                #line 527 "src/compiler/BlockWriter.pv"
                                fprintf(file, " = ");
                                #line 528 "src/compiler/BlockWriter.pv"
                                if (variable->ref) {
                                    #line 528 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "&");
                                }
                                #line 529 "src/compiler/BlockWriter.pv"
                                if (variable->deref) {
                                    #line 529 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "*");
                                }
                                #line 530 "src/compiler/BlockWriter.pv"
                                switch (Type__deref(for_statement->iter_type)->type) {
                                    #line 531 "src/compiler/BlockWriter.pv"
                                    case TYPE__SEQUENCE: {
                                        #line 531 "src/compiler/BlockWriter.pv"
                                        struct Sequence* sequence = Type__deref(for_statement->iter_type)->sequence_value;
                                        #line 532 "src/compiler/BlockWriter.pv"
                                        switch (sequence->type.type) {
                                            #line 533 "src/compiler/BlockWriter.pv"
                                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                                #line 534 "src/compiler/BlockWriter.pv"
                                                ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                                #line 535 "src/compiler/BlockWriter.pv"
                                                fprintf(file, "[__iter]");
                                            } break;
                                            #line 537 "src/compiler/BlockWriter.pv"
                                            case SEQUENCE_TYPE__SLICE: {
                                                #line 538 "src/compiler/BlockWriter.pv"
                                                ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                                #line 539 "src/compiler/BlockWriter.pv"
                                                fprintf(file, ".data[__iter]");
                                            } break;
                                        }
                                    } break;
                                    #line 543 "src/compiler/BlockWriter.pv"
                                    default: {
                                        #line 543 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "/* ERROR */");
                                    } break;
                                }

                                #line 546 "src/compiler/BlockWriter.pv"
                                if (for_statement->variables.length > 1) {
                                    #line 547 "src/compiler/BlockWriter.pv"
                                    Generator__write_instance_member_accessor(g, file, for_statement->value_type, generics);
                                    #line 548 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "_%zu", i);
                                }

                                #line 551 "src/compiler/BlockWriter.pv"
                                fprintf(file, ";\n");
                            }

                            #line 554 "src/compiler/BlockWriter.pv"
                            i += 1;
                        } }
                    } break;
                    #line 557 "src/compiler/BlockWriter.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 557 "src/compiler/BlockWriter.pv"
                        struct Expression* iter_expression = for_statement->type.iter_value;
                        #line 558 "src/compiler/BlockWriter.pv"
                        is_iterator = Type__is_iterator(Type__deref(for_statement->iter_type));
                        #line 559 "src/compiler/BlockWriter.pv"
                        if (is_iterator) {
                            #line 560 "src/compiler/BlockWriter.pv"
                            Generator__write_indent(g, file);
                            #line 561 "src/compiler/BlockWriter.pv"
                            fprintf(file, "while (");
                            #line 562 "src/compiler/BlockWriter.pv"
                            ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                            #line 563 "src/compiler/BlockWriter.pv"
                            fprintf(file, ".vtable->next(");
                            #line 564 "src/compiler/BlockWriter.pv"
                            ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                            #line 565 "src/compiler/BlockWriter.pv"
                            fprintf(file, ".instance)) {");

                            #line 567 "src/compiler/BlockWriter.pv"
                            g->indent += 1;

                            #line 569 "src/compiler/BlockWriter.pv"
                            uintptr_t i = 0;
                            #line 570 "src/compiler/BlockWriter.pv"
                            { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 570 "src/compiler/BlockWriter.pv"
                            while (Iter_ref_ForVariable__next(&__iter)) {
                                #line 570 "src/compiler/BlockWriter.pv"
                                struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                                #line 571 "src/compiler/BlockWriter.pv"
                                if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 572 "src/compiler/BlockWriter.pv"
                                    Generator__write_line_directive(g, file, block->context, variable->name);
                                    #line 573 "src/compiler/BlockWriter.pv"
                                    Generator__write_indent(g, file);
                                    #line 574 "src/compiler/BlockWriter.pv"
                                    Generator__write_type(g, file, variable->type, generics);
                                    #line 575 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " ");
                                    #line 576 "src/compiler/BlockWriter.pv"
                                    Generator__write_token(g, file, variable->name);
                                    #line 577 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " = ");
                                    #line 578 "src/compiler/BlockWriter.pv"
                                    if (variable->ref) {
                                        #line 578 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 579 "src/compiler/BlockWriter.pv"
                                    if (variable->deref) {
                                        #line 579 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 580 "src/compiler/BlockWriter.pv"
                                    ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                    #line 581 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ".vtable->value");
                                    #line 582 "src/compiler/BlockWriter.pv"
                                    if (for_statement->variables.length > 1) {
                                        #line 582 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 583 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "(");
                                    #line 584 "src/compiler/BlockWriter.pv"
                                    ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                    #line 585 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ".instance);\n");
                                }

                                #line 588 "src/compiler/BlockWriter.pv"
                                i += 1;
                            } }
                        } else {
                            #line 591 "src/compiler/BlockWriter.pv"
                            struct String iter_type_name = Naming__get_type_name(&g->naming_ident, for_statement->iter_type, generics->self_type, generics);

                            #line 593 "src/compiler/BlockWriter.pv"
                            Generator__write_indent(g, file);
                            #line 594 "src/compiler/BlockWriter.pv"
                            fprintf(file, "{ ");
                            #line 595 "src/compiler/BlockWriter.pv"
                            Generator__write_type(g, file, for_statement->iter_type, generics);
                            #line 596 "src/compiler/BlockWriter.pv"
                            fprintf(file, " __iter = ");
                            #line 597 "src/compiler/BlockWriter.pv"
                            ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                            #line 598 "src/compiler/BlockWriter.pv"
                            fprintf(file, ";\n");

                            #line 600 "src/compiler/BlockWriter.pv"
                            Generator__write_line_directive(g, file, block->context, iter_expression->token);

                            #line 602 "src/compiler/BlockWriter.pv"
                            Generator__write_indent(g, file);
                            #line 603 "src/compiler/BlockWriter.pv"
                            fprintf(file, "while (");
                            #line 604 "src/compiler/BlockWriter.pv"
                            Generator__write_string(g, file, &iter_type_name);
                            #line 605 "src/compiler/BlockWriter.pv"
                            fprintf(file, "__next(&__iter)) {\n");

                            #line 607 "src/compiler/BlockWriter.pv"
                            g->indent += 1;

                            #line 609 "src/compiler/BlockWriter.pv"
                            uintptr_t i = 0;
                            #line 610 "src/compiler/BlockWriter.pv"
                            { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 610 "src/compiler/BlockWriter.pv"
                            while (Iter_ref_ForVariable__next(&__iter)) {
                                #line 610 "src/compiler/BlockWriter.pv"
                                struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                                #line 611 "src/compiler/BlockWriter.pv"
                                if (!str__eq(variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 612 "src/compiler/BlockWriter.pv"
                                    Generator__write_line_directive(g, file, block->context, variable->name);
                                    #line 613 "src/compiler/BlockWriter.pv"
                                    Generator__write_indent(g, file);
                                    #line 614 "src/compiler/BlockWriter.pv"
                                    Generator__write_type(g, file, variable->type, generics);
                                    #line 615 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " ");
                                    #line 616 "src/compiler/BlockWriter.pv"
                                    Generator__write_token(g, file, variable->name);
                                    #line 617 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " = ");
                                    #line 618 "src/compiler/BlockWriter.pv"
                                    if (variable->ref) {
                                        #line 618 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 619 "src/compiler/BlockWriter.pv"
                                    if (variable->deref) {
                                        #line 619 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 620 "src/compiler/BlockWriter.pv"
                                    Generator__write_string(g, file, &iter_type_name);
                                    #line 621 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "__value");
                                    #line 622 "src/compiler/BlockWriter.pv"
                                    if (!Type__is_tuple(Type__deref(for_statement->value_type)) && for_statement->variables.length > 1) {
                                        #line 623 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 625 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "(&__iter)");

                                    #line 627 "src/compiler/BlockWriter.pv"
                                    if (Type__is_tuple(Type__deref(for_statement->value_type)) && for_statement->variables.length > 1) {
                                        #line 628 "src/compiler/BlockWriter.pv"
                                        Generator__write_instance_member_accessor(g, file, for_statement->value_type, generics);
                                        #line 629 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "_%zu", i);
                                    }

                                    #line 632 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ";\n");
                                }

                                #line 635 "src/compiler/BlockWriter.pv"
                                i += 1;
                            } }
                        }
                    } break;
                }

                #line 641 "src/compiler/BlockWriter.pv"
                fprintf(file, "\n");

                #line 643 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(g->function_context, true, true);
                #line 644 "src/compiler/BlockWriter.pv"
                if (!BlockWriter__write_block(self, file, return_type, for_statement->block, generics, false, true)) {
                    #line 644 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 645 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(g->function_context);

                #line 647 "src/compiler/BlockWriter.pv"
                g->indent -= 1;
                #line 648 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 649 "src/compiler/BlockWriter.pv"
                if (is_iterator) {
                    #line 650 "src/compiler/BlockWriter.pv"
                    fprintf(file, "}\n");
                } else {
                    #line 652 "src/compiler/BlockWriter.pv"
                    fprintf(file, "} }\n");
                }
            } break;
            #line 655 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 655 "src/compiler/BlockWriter.pv"
                struct AssignmentStatement* assignment = statement->data.assignmentstatement_value;
                #line 656 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 657 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, assignment->left, generics);
                #line 658 "src/compiler/BlockWriter.pv"
                fprintf(file, " ");
                #line 659 "src/compiler/BlockWriter.pv"
                Generator__write_str(g, file, assignment->operator->value);
                #line 660 "src/compiler/BlockWriter.pv"
                fprintf(file, " ");
                #line 661 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, assignment->right, generics);
                #line 662 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 664 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 664 "src/compiler/BlockWriter.pv"
                struct Expression* expression = statement->data.expressionstatement_value;
                #line 665 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 666 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, expression, generics);
                #line 667 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 669 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
                #line 669 "src/compiler/BlockWriter.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.continuestatement_value;
                #line 670 "src/compiler/BlockWriter.pv"
                BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 671 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 672 "src/compiler/BlockWriter.pv"
                fprintf(file, "continue;\n");
            } break;
            #line 674 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
                #line 674 "src/compiler/BlockWriter.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.breakstatement_value;
                #line 675 "src/compiler/BlockWriter.pv"
                BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 676 "src/compiler/BlockWriter.pv"
                Generator__write_indent(g, file);
                #line 677 "src/compiler/BlockWriter.pv"
                fprintf(file, "break;\n");
            } break;
        }
    } }

    #line 682 "src/compiler/BlockWriter.pv"
    if (!last_statement_is_return) {
        #line 683 "src/compiler/BlockWriter.pv"
        BlockWriter__write_defer_statements(self, file, return_type, &block->defer_statements, generics);
    }

    #line 686 "src/compiler/BlockWriter.pv"
    if (!no_brackets) {
        #line 687 "src/compiler/BlockWriter.pv"
        g->indent -= 1;
        #line 688 "src/compiler/BlockWriter.pv"
        Generator__write_indent(g, file);

        #line 690 "src/compiler/BlockWriter.pv"
        if (inline_) {
            #line 691 "src/compiler/BlockWriter.pv"
            fprintf(file, "}");
        } else {
            #line 693 "src/compiler/BlockWriter.pv"
            fprintf(file, "}\n");
        }
    }

    #line 697 "src/compiler/BlockWriter.pv"
    return true;
}
