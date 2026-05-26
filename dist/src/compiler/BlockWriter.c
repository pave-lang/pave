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
#include <std/Hash.h>
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
    struct Generator* generator = self->generator;
    #line 22 "src/compiler/BlockWriter.pv"
    struct ExpressionWriter expr = (struct ExpressionWriter) { .generator = generator };
    #line 23 "src/compiler/BlockWriter.pv"
    struct Type* expr_type = &expression->return_type;
    #line 24 "src/compiler/BlockWriter.pv"
    bool is_discriminated_union = Generator__type_is_discriminated_union(generator, expr_type, generics);

    #line 26 "src/compiler/BlockWriter.pv"
    fprintf(file, "if (");
    #line 27 "src/compiler/BlockWriter.pv"
    if (is_discriminated_union) {
        #line 28 "src/compiler/BlockWriter.pv"
        ExpressionWriter__write_expression(&expr, file, expression, generics);
        #line 29 "src/compiler/BlockWriter.pv"
        Generator__write_instance_member_accessor(generator, file, expr_type, generics);
        #line 30 "src/compiler/BlockWriter.pv"
        fprintf(file, "type == ");
        #line 31 "src/compiler/BlockWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, enum_variant);
    } else {
        #line 33 "src/compiler/BlockWriter.pv"
        Generator__write_deref_if_needed(generator, file, expr_type, generics);
        #line 34 "src/compiler/BlockWriter.pv"
        ExpressionWriter__write_expression(&expr, file, expression, generics);
        #line 35 "src/compiler/BlockWriter.pv"
        fprintf(file, " == ");
        #line 36 "src/compiler/BlockWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, enum_variant);
    }
    #line 38 "src/compiler/BlockWriter.pv"
    fprintf(file, ") {\n");
    #line 39 "src/compiler/BlockWriter.pv"
    generator->indent += 1;

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
        struct String accessor = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
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
                if (str__Eq_str__eq(&enum_variant->names.data[field_i], param_iter->field_name)) {
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
        variable_expression = Expression__make(generator->allocator, param_iter->variable, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = variable_expression, ._1 = String__as_str(&accessor)} }, param_type);

        #line 74 "src/compiler/BlockWriter.pv"
        struct Token* name = param_iter->variable;
        #line 75 "src/compiler/BlockWriter.pv"
        Generator__write_line_directive(generator, file, outer_block->context, name);
        #line 76 "src/compiler/BlockWriter.pv"
        Generator__write_indent(generator, file);
        #line 77 "src/compiler/BlockWriter.pv"
        Generator__write_type(generator, file, param_type, generics);
        #line 78 "src/compiler/BlockWriter.pv"
        if (param_iter->ref) {
            #line 78 "src/compiler/BlockWriter.pv"
            fprintf(file, "*");
        }
        #line 79 "src/compiler/BlockWriter.pv"
        fprintf(file, " ");
        #line 80 "src/compiler/BlockWriter.pv"
        Generator__write_token(generator, file, name);
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
    struct FunctionContext* function_context = generator->function_context;
    #line 90 "src/compiler/BlockWriter.pv"
    if (function_context == 0) {
        #line 91 "src/compiler/BlockWriter.pv"
        fprintf(stderr, "Missing function context in write_function_body\n");
        #line 92 "src/compiler/BlockWriter.pv"
        return false;
    }
    #line 94 "src/compiler/BlockWriter.pv"
    FunctionContext__push_scope(function_context, false, false);
    #line 95 "src/compiler/BlockWriter.pv"
    if (!BlockWriter__write_block(self, file, return_type, body, generics, true, true)) {
        #line 95 "src/compiler/BlockWriter.pv"
        return false;
    }
    #line 96 "src/compiler/BlockWriter.pv"
    FunctionContext__pop_scope(function_context);

    #line 98 "src/compiler/BlockWriter.pv"
    generator->indent -= 1;
    #line 99 "src/compiler/BlockWriter.pv"
    Generator__write_indent(generator, file);
    #line 100 "src/compiler/BlockWriter.pv"
    fprintf(file, "}");

    #line 102 "src/compiler/BlockWriter.pv"
    return true;
}

#line 105 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_defer_statements(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Array_DeferStatement* defer_statements, struct GenericMap* generics) {
    #line 106 "src/compiler/BlockWriter.pv"
    struct Generator* generator = self->generator;
    #line 107 "src/compiler/BlockWriter.pv"
    struct ExpressionWriter expr = (struct ExpressionWriter) { .generator = generator };
    #line 108 "src/compiler/BlockWriter.pv"
    { struct Iter_ref_DeferStatement __iter = Array_DeferStatement__iter(defer_statements);
    #line 108 "src/compiler/BlockWriter.pv"
    while (Iter_ref_DeferStatement__next(&__iter)) {
        #line 108 "src/compiler/BlockWriter.pv"
        struct DeferStatement* defer_info = Iter_ref_DeferStatement__value(&__iter);

        #line 109 "src/compiler/BlockWriter.pv"
        switch (defer_info->type) {
            #line 110 "src/compiler/BlockWriter.pv"
            case DEFER_STATEMENT__EXPRESSION: {
                #line 110 "src/compiler/BlockWriter.pv"
                struct Expression* expression = defer_info->expression_value;
                #line 111 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 112 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, expression, generics);
                #line 113 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 115 "src/compiler/BlockWriter.pv"
            case DEFER_STATEMENT__BLOCK: {
                #line 115 "src/compiler/BlockWriter.pv"
                struct Block* block = defer_info->block_value;
                #line 116 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 117 "src/compiler/BlockWriter.pv"
                struct FunctionContext* function_context = generator->function_context;
                #line 118 "src/compiler/BlockWriter.pv"
                if (function_context == 0) {
                    #line 119 "src/compiler/BlockWriter.pv"
                    fprintf(stderr, "Missing function context in write_defer_statements\n");
                    #line 120 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 122 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(function_context, false, false);
                #line 123 "src/compiler/BlockWriter.pv"
                BlockWriter__write_block(self, file, return_type, block, generics, false, false);
                #line 124 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(function_context);
            } break;
        }
    } }

    #line 129 "src/compiler/BlockWriter.pv"
    return true;
}

#line 132 "src/compiler/BlockWriter.pv"
bool BlockWriter__write_block(struct BlockWriter* self, FILE* file, struct Type* return_type, struct Block* block, struct GenericMap* generics, bool inline_, bool no_brackets) {
    #line 133 "src/compiler/BlockWriter.pv"
    struct Generator* generator = self->generator;
    #line 134 "src/compiler/BlockWriter.pv"
    struct ExpressionWriter expr = (struct ExpressionWriter) { .generator = generator };

    #line 136 "src/compiler/BlockWriter.pv"
    if (block == 0) {
        #line 137 "src/compiler/BlockWriter.pv"
        fprintf(file, "{}\n");
        #line 138 "src/compiler/BlockWriter.pv"
        return false;
    }

    #line 141 "src/compiler/BlockWriter.pv"
    if (!no_brackets) {
        #line 142 "src/compiler/BlockWriter.pv"
        fprintf(file, "{\n");
        #line 143 "src/compiler/BlockWriter.pv"
        generator->indent += 1;
    }

    #line 146 "src/compiler/BlockWriter.pv"
    if (block->is_top_level_and_has_defer_statements_inside && !Type__is_void(return_type)) {
        #line 147 "src/compiler/BlockWriter.pv"
        Generator__write_indent(generator, file);
        #line 148 "src/compiler/BlockWriter.pv"
        Generator__write_type(generator, file, return_type, generics);
        #line 149 "src/compiler/BlockWriter.pv"
        fprintf(file, " __result;\n\n");
    }

    #line 152 "src/compiler/BlockWriter.pv"
    bool last_statement_is_return = false;

    #line 154 "src/compiler/BlockWriter.pv"
    { struct Iter_ref_Statement __iter = Array_Statement__iter(&block->statements);
    #line 154 "src/compiler/BlockWriter.pv"
    while (Iter_ref_Statement__next(&__iter)) {
        #line 154 "src/compiler/BlockWriter.pv"
        struct Statement* statement = Iter_ref_Statement__value(&__iter);

        #line 155 "src/compiler/BlockWriter.pv"
        if (statement > block->statements.data) {
            #line 156 "src/compiler/BlockWriter.pv"
            struct Statement* prev_statement = statement - 1;

            #line 158 "src/compiler/BlockWriter.pv"
            if (prev_statement->last_token->end_line < statement->first_token->start_line - 1) {
                #line 159 "src/compiler/BlockWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 163 "src/compiler/BlockWriter.pv"
        Generator__write_line_directive(generator, file, block->context, statement->first_token);

        #line 165 "src/compiler/BlockWriter.pv"
        last_statement_is_return = false;

        #line 167 "src/compiler/BlockWriter.pv"
        switch (statement->data.type) {
            #line 168 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__BLOCK_STATEMENT: {
                #line 168 "src/compiler/BlockWriter.pv"
                struct Block* child_block = statement->data.blockstatement_value;
                #line 169 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 170 "src/compiler/BlockWriter.pv"
                struct FunctionContext* function_context = generator->function_context;
                #line 171 "src/compiler/BlockWriter.pv"
                if (function_context == 0) {
                    #line 172 "src/compiler/BlockWriter.pv"
                    fprintf(stderr, "Missing function context in write_block\n");
                    #line 173 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 175 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(function_context, false, false);
                #line 176 "src/compiler/BlockWriter.pv"
                if (!BlockWriter__write_block(self, file, return_type, child_block, generics, false, false)) {
                    #line 177 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 179 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(function_context);
            } break;
            #line 181 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__LET_STATEMENT: {
                #line 181 "src/compiler/BlockWriter.pv"
                struct LetStatement* let_statement = statement->data.letstatement_value;
                #line 182 "src/compiler/BlockWriter.pv"
                struct Token* name = let_statement->name;
                #line 183 "src/compiler/BlockWriter.pv"
                struct Type* type = let_statement->type;
                #line 184 "src/compiler/BlockWriter.pv"
                struct Expression* value = let_statement->value;

                #line 186 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);

                #line 188 "src/compiler/BlockWriter.pv"
                if (!let_statement->is_static) {
                    #line 189 "src/compiler/BlockWriter.pv"
                    struct FunctionContext* function_context = generator->function_context;
                    #line 190 "src/compiler/BlockWriter.pv"
                    if (function_context == 0) {
                        #line 191 "src/compiler/BlockWriter.pv"
                        fprintf(stderr, "Missing function context in let statement\n");
                        #line 192 "src/compiler/BlockWriter.pv"
                        return false;
                    }
                    #line 194 "src/compiler/BlockWriter.pv"
                    FunctionContext__add_variable(function_context, name->value, type);
                }

                #line 197 "src/compiler/BlockWriter.pv"
                if (let_statement->is_static) {
                    #line 198 "src/compiler/BlockWriter.pv"
                    fprintf(file, "static ");
                }

                #line 201 "src/compiler/BlockWriter.pv"
                if (Generator__is_coroutine(generator)) {
                    #line 202 "src/compiler/BlockWriter.pv"
                    Generator__write_variable(generator, file, name->value);
                } else {
                    #line 204 "src/compiler/BlockWriter.pv"
                    Generator__write_variable_decl(generator, file, name->value, type, generics);
                }

                #line 207 "src/compiler/BlockWriter.pv"
                if (value != 0) {
                    #line 208 "src/compiler/BlockWriter.pv"
                    switch (value->data.type) {
                        #line 209 "src/compiler/BlockWriter.pv"
                        case EXPRESSION_DATA__OPTIONAL_EXPRESSION: {
                            #line 210 "src/compiler/BlockWriter.pv"
                            if (ExpressionWriter__optional_needs_lowering(&expr, value)) {
                                #line 211 "src/compiler/BlockWriter.pv"
                                fprintf(file, "; {\n");
                                #line 212 "src/compiler/BlockWriter.pv"
                                generator->indent += 1;
                                #line 213 "src/compiler/BlockWriter.pv"
                                if (!ExpressionWriter__write_optional_assignment(&expr, file, name->value, type, value, generics)) {
                                    #line 213 "src/compiler/BlockWriter.pv"
                                    return false;
                                }
                                #line 214 "src/compiler/BlockWriter.pv"
                                generator->indent -= 1;
                                #line 215 "src/compiler/BlockWriter.pv"
                                Generator__write_indent(generator, file);
                                #line 216 "src/compiler/BlockWriter.pv"
                                fprintf(file, "}\n");
                                #line 217 "src/compiler/BlockWriter.pv"
                                continue;
                            }
                        } break;
                        #line 220 "src/compiler/BlockWriter.pv"
                        default: {
                        } break;
                    }

                    #line 223 "src/compiler/BlockWriter.pv"
                    fprintf(file, " = ");
                    #line 224 "src/compiler/BlockWriter.pv"
                    bool wrote_null_fat_let = false;
                    #line 225 "src/compiler/BlockWriter.pv"
                    switch (value->data.type) {
                        #line 226 "src/compiler/BlockWriter.pv"
                        case EXPRESSION_DATA__NULL_LITERAL: {
                            #line 227 "src/compiler/BlockWriter.pv"
                            if (Type__is_fat_pointer(type)) {
                                #line 228 "src/compiler/BlockWriter.pv"
                                fprintf(file, "(");
                                #line 229 "src/compiler/BlockWriter.pv"
                                Generator__write_type(generator, file, type, generics);
                                #line 230 "src/compiler/BlockWriter.pv"
                                fprintf(file, "){0}");
                                #line 231 "src/compiler/BlockWriter.pv"
                                wrote_null_fat_let = true;
                            }
                        } break;
                        #line 234 "src/compiler/BlockWriter.pv"
                        default: {
                        } break;
                    }
                    #line 236 "src/compiler/BlockWriter.pv"
                    if (!wrote_null_fat_let) {
                        #line 236 "src/compiler/BlockWriter.pv"
                        ExpressionWriter__write_expression(&expr, file, value, generics);
                    }
                }

                #line 239 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 241 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__YIELD_STATEMENT: {
                #line 241 "src/compiler/BlockWriter.pv"
                struct YieldStatement* yield_stmt = statement->data.yieldstatement_value;
                #line 242 "src/compiler/BlockWriter.pv"
                struct FunctionContext* function_context = generator->function_context;
                #line 243 "src/compiler/BlockWriter.pv"
                if (function_context == 0) {
                    #line 244 "src/compiler/BlockWriter.pv"
                    fprintf(stderr, "Missing function context in yield statement\n");
                    #line 245 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 247 "src/compiler/BlockWriter.pv"
                function_context->coroutine.yield_count += 1;

                #line 249 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 250 "src/compiler/BlockWriter.pv"
                uintptr_t yield_number = function_context->coroutine.yield_count;
                #line 251 "src/compiler/BlockWriter.pv"
                fprintf(file, "ctx->_value = ");
                #line 252 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, yield_stmt->expression, generics);
                #line 253 "src/compiler/BlockWriter.pv"
                fprintf(file, "; ctx->_state = %zu; return true; yield_%zu:;\n", yield_number, yield_number);
            } break;
            #line 255 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__RETURN_STATEMENT: {
                #line 255 "src/compiler/BlockWriter.pv"
                struct ReturnStatement* ret = statement->data.returnstatement_value;
                #line 256 "src/compiler/BlockWriter.pv"
                struct Expression* value = ret->expression;
                #line 257 "src/compiler/BlockWriter.pv"
                struct Array_DeferStatement* defer_statements = &ret->defer_statements;
                #line 258 "src/compiler/BlockWriter.pv"
                if (value == 0) {
                    #line 259 "src/compiler/BlockWriter.pv"
                    BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);
                    #line 260 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(generator, file);
                    #line 261 "src/compiler/BlockWriter.pv"
                    fprintf(file, "return;\n");
                } else if (defer_statements->length > 0) {
                    #line 263 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(generator, file);
                    #line 264 "src/compiler/BlockWriter.pv"
                    fprintf(file, "__result = ");
                    #line 265 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, value, generics);
                    #line 266 "src/compiler/BlockWriter.pv"
                    fprintf(file, ";\n");

                    #line 268 "src/compiler/BlockWriter.pv"
                    BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);

                    #line 270 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(generator, file);
                    #line 271 "src/compiler/BlockWriter.pv"
                    fprintf(file, "return __result;\n");
                } else {
                    #line 273 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(generator, file);
                    #line 274 "src/compiler/BlockWriter.pv"
                    fprintf(file, "return ");
                    #line 275 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, value, generics);
                    #line 276 "src/compiler/BlockWriter.pv"
                    fprintf(file, ";\n");
                }

                #line 279 "src/compiler/BlockWriter.pv"
                last_statement_is_return = true;
            } break;
            #line 281 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__IF_STATEMENT: {
                #line 281 "src/compiler/BlockWriter.pv"
                struct IfStatement* if_stmt = statement->data.ifstatement_value;
                #line 282 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);

                #line 284 "src/compiler/BlockWriter.pv"
                if (if_stmt->pattern != 0) {
                    #line 285 "src/compiler/BlockWriter.pv"
                    switch (if_stmt->pattern->type) {
                        #line 286 "src/compiler/BlockWriter.pv"
                        case MATCH_PATTERN__ENUM_VARIANT: {
                            #line 286 "src/compiler/BlockWriter.pv"
                            struct Type* type = if_stmt->pattern->enumvariant_value._0;
                            #line 286 "src/compiler/BlockWriter.pv"
                            struct EnumVariant* enum_variant = if_stmt->pattern->enumvariant_value._1;
                            #line 286 "src/compiler/BlockWriter.pv"
                            struct Array_EnumVariantParameter* parameters = &if_stmt->pattern->enumvariant_value._2;
                            #line 287 "src/compiler/BlockWriter.pv"
                            if (!BlockWriter__write_if_let_enum_variant(self, file, return_type, type, enum_variant, parameters, if_stmt->expression, if_stmt->block, block, generics)) {
                                #line 287 "src/compiler/BlockWriter.pv"
                                return false;
                            }
                        } break;
                        #line 289 "src/compiler/BlockWriter.pv"
                        default: {
                        } break;
                    }
                } else {
                    #line 292 "src/compiler/BlockWriter.pv"
                    fprintf(file, "if (");
                    #line 293 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, if_stmt->expression, generics);
                    #line 294 "src/compiler/BlockWriter.pv"
                    fprintf(file, ") ");
                    #line 295 "src/compiler/BlockWriter.pv"
                    struct FunctionContext* function_context = generator->function_context;
                    #line 296 "src/compiler/BlockWriter.pv"
                    if (function_context == 0) {
                        #line 297 "src/compiler/BlockWriter.pv"
                        fprintf(stderr, "Missing function context in if statement\n");
                        #line 298 "src/compiler/BlockWriter.pv"
                        return false;
                    }
                    #line 300 "src/compiler/BlockWriter.pv"
                    FunctionContext__push_scope(function_context, false, false);
                    #line 301 "src/compiler/BlockWriter.pv"
                    if (!BlockWriter__write_block(self, file, return_type, if_stmt->block, generics, true, false)) {
                        #line 301 "src/compiler/BlockWriter.pv"
                        return false;
                    }
                    #line 302 "src/compiler/BlockWriter.pv"
                    FunctionContext__pop_scope(function_context);
                }

                #line 305 "src/compiler/BlockWriter.pv"
                { struct Iter_ref_ElseStatement __iter = Array_ElseStatement__iter(&if_stmt->else_statements);
                #line 305 "src/compiler/BlockWriter.pv"
                while (Iter_ref_ElseStatement__next(&__iter)) {
                    #line 305 "src/compiler/BlockWriter.pv"
                    struct ElseStatement* else_statement = Iter_ref_ElseStatement__value(&__iter);

                    #line 306 "src/compiler/BlockWriter.pv"
                    fprintf(file, " else ");

                    #line 308 "src/compiler/BlockWriter.pv"
                    if (else_statement->pattern != 0) {
                        #line 309 "src/compiler/BlockWriter.pv"
                        switch (else_statement->pattern->type) {
                            #line 310 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 310 "src/compiler/BlockWriter.pv"
                                struct Type* type = else_statement->pattern->enumvariant_value._0;
                                #line 310 "src/compiler/BlockWriter.pv"
                                struct EnumVariant* enum_variant = else_statement->pattern->enumvariant_value._1;
                                #line 310 "src/compiler/BlockWriter.pv"
                                struct Array_EnumVariantParameter* parameters = &else_statement->pattern->enumvariant_value._2;
                                #line 311 "src/compiler/BlockWriter.pv"
                                if (!BlockWriter__write_if_let_enum_variant(self, file, return_type, type, enum_variant, parameters, else_statement->expression, else_statement->block, block, generics)) {
                                    #line 311 "src/compiler/BlockWriter.pv"
                                    return false;
                                }
                            } break;
                            #line 313 "src/compiler/BlockWriter.pv"
                            default: {
                            } break;
                        }
                    } else if (else_statement->expression != 0) {
                        #line 316 "src/compiler/BlockWriter.pv"
                        fprintf(file, "if (");
                        #line 317 "src/compiler/BlockWriter.pv"
                        ExpressionWriter__write_expression(&expr, file, else_statement->expression, generics);
                        #line 318 "src/compiler/BlockWriter.pv"
                        fprintf(file, ") ");
                        #line 319 "src/compiler/BlockWriter.pv"
                        struct FunctionContext* function_context = generator->function_context;
                        #line 320 "src/compiler/BlockWriter.pv"
                        if (function_context == 0) {
                            #line 321 "src/compiler/BlockWriter.pv"
                            fprintf(stderr, "Missing function context in else-if statement\n");
                            #line 322 "src/compiler/BlockWriter.pv"
                            return false;
                        }
                        #line 324 "src/compiler/BlockWriter.pv"
                        FunctionContext__push_scope(function_context, false, false);
                        #line 325 "src/compiler/BlockWriter.pv"
                        if (!BlockWriter__write_block(self, file, return_type, else_statement->block, generics, true, false)) {
                            #line 325 "src/compiler/BlockWriter.pv"
                            return false;
                        }
                        #line 326 "src/compiler/BlockWriter.pv"
                        FunctionContext__pop_scope(function_context);
                    } else {
                        #line 328 "src/compiler/BlockWriter.pv"
                        struct FunctionContext* function_context = generator->function_context;
                        #line 329 "src/compiler/BlockWriter.pv"
                        if (function_context == 0) {
                            #line 330 "src/compiler/BlockWriter.pv"
                            fprintf(stderr, "Missing function context in else statement\n");
                            #line 331 "src/compiler/BlockWriter.pv"
                            return false;
                        }
                        #line 333 "src/compiler/BlockWriter.pv"
                        FunctionContext__push_scope(function_context, false, false);
                        #line 334 "src/compiler/BlockWriter.pv"
                        if (!BlockWriter__write_block(self, file, return_type, else_statement->block, generics, true, false)) {
                            #line 334 "src/compiler/BlockWriter.pv"
                            return false;
                        }
                        #line 335 "src/compiler/BlockWriter.pv"
                        FunctionContext__pop_scope(function_context);
                    }
                } }

                #line 339 "src/compiler/BlockWriter.pv"
                fprintf(file, "\n");
            } break;
            #line 341 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__MATCH_STATEMENT: {
                #line 341 "src/compiler/BlockWriter.pv"
                struct MatchStatement* match_stmt = statement->data.matchstatement_value;
                #line 342 "src/compiler/BlockWriter.pv"
                struct Expression* expression = match_stmt->expression;
                #line 343 "src/compiler/BlockWriter.pv"
                struct Array_MatchCase* cases = &match_stmt->cases;
                #line 344 "src/compiler/BlockWriter.pv"
                struct Type* return_type = &expression->return_type;
                #line 345 "src/compiler/BlockWriter.pv"
                bool is_discriminated_union = Generator__type_is_discriminated_union(generator, return_type, generics);

                #line 347 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 348 "src/compiler/BlockWriter.pv"
                fprintf(file, "switch (");

                #line 350 "src/compiler/BlockWriter.pv"
                if (!is_discriminated_union) {
                    #line 351 "src/compiler/BlockWriter.pv"
                    Generator__write_deref_if_needed(generator, file, return_type, generics);
                }

                #line 354 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, expression, generics);

                #line 356 "src/compiler/BlockWriter.pv"
                if (is_discriminated_union) {
                    #line 357 "src/compiler/BlockWriter.pv"
                    Generator__write_instance_member_accessor(generator, file, return_type, generics);
                    #line 358 "src/compiler/BlockWriter.pv"
                    fprintf(file, "type");
                }

                #line 361 "src/compiler/BlockWriter.pv"
                fprintf(file, ") {\n");
                #line 362 "src/compiler/BlockWriter.pv"
                generator->indent += 1;

                #line 364 "src/compiler/BlockWriter.pv"
                { struct Iter_ref_MatchCase __iter = Array_MatchCase__iter(cases);
                #line 364 "src/compiler/BlockWriter.pv"
                while (Iter_ref_MatchCase__next(&__iter)) {
                    #line 364 "src/compiler/BlockWriter.pv"
                    struct MatchCase* case_info = Iter_ref_MatchCase__value(&__iter);

                    #line 365 "src/compiler/BlockWriter.pv"
                    Generator__write_line_directive(generator, file, block->context, case_info->first_token);
                    #line 366 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(generator, file);

                    #line 368 "src/compiler/BlockWriter.pv"
                    struct Array_MatchPattern* patterns = &case_info->patterns;
                    #line 369 "src/compiler/BlockWriter.pv"
                    { struct IterEnumerate_ref_MatchPattern __iter = Iter_ref_MatchPattern__enumerate(Array_MatchPattern__iter(patterns));
                    #line 369 "src/compiler/BlockWriter.pv"
                    while (IterEnumerate_ref_MatchPattern__next(&__iter)) {
                        #line 369 "src/compiler/BlockWriter.pv"
                        uintptr_t i = IterEnumerate_ref_MatchPattern__value(&__iter)._0;
                        #line 369 "src/compiler/BlockWriter.pv"
                        struct MatchPattern* pattern = IterEnumerate_ref_MatchPattern__value(&__iter)._1;

                        #line 370 "src/compiler/BlockWriter.pv"
                        if (i > 0) {
                            #line 370 "src/compiler/BlockWriter.pv"
                            fprintf(file, "\n");
                        }

                        #line 372 "src/compiler/BlockWriter.pv"
                        switch (pattern->type) {
                            #line 373 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__STATIC_VALUE: {
                                #line 373 "src/compiler/BlockWriter.pv"
                                struct Expression* expr_val = pattern->staticvalue_value;
                                #line 374 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 375 "src/compiler/BlockWriter.pv"
                                ExpressionWriter__write_expression(&expr, file, expr_val, generics);
                                #line 376 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 378 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 378 "src/compiler/BlockWriter.pv"
                                struct Type* type = pattern->enumvariant_value._0;
                                #line 378 "src/compiler/BlockWriter.pv"
                                struct EnumVariant* enum_variant = pattern->enumvariant_value._1;
                                #line 379 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 380 "src/compiler/BlockWriter.pv"
                                Generator__write_enum_variant_name(generator, file, type, enum_variant);
                                #line 381 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 383 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_CVALUE: {
                                #line 383 "src/compiler/BlockWriter.pv"
                                struct EnumCValue* enum_variant = pattern->enumcvalue_value;
                                #line 384 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");

                                #line 386 "src/compiler/BlockWriter.pv"
                                struct EnumC* enum_info = enum_variant->parent;
                                #line 387 "src/compiler/BlockWriter.pv"
                                if (!ParentCpp__is_none(&enum_info->parent)) {
                                    #line 388 "src/compiler/BlockWriter.pv"
                                    struct String type_name = Naming__get_type_name(generator->naming_decl, (struct Type[]){(struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info }}, generics->self_type, generics);
                                    #line 389 "src/compiler/BlockWriter.pv"
                                    Generator__write_str(generator, file, String__as_str(&type_name));
                                    #line 390 "src/compiler/BlockWriter.pv"
                                    String__release(&type_name);
                                    #line 391 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "::");
                                }

                                #line 394 "src/compiler/BlockWriter.pv"
                                Generator__write_str(generator, file, enum_variant->name);
                                #line 395 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 397 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__TYPE_ID: {
                                #line 397 "src/compiler/BlockWriter.pv"
                                struct Type* type = &pattern->typeid_value;
                                #line 398 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 399 "src/compiler/BlockWriter.pv"
                                Generator__write_typeid(generator, file, type, generics);
                                #line 400 "src/compiler/BlockWriter.pv"
                                fprintf(file, ":");
                            } break;
                            #line 402 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__HASH: {
                                #line 402 "src/compiler/BlockWriter.pv"
                                struct Token* token = pattern->hash_value;
                                #line 403 "src/compiler/BlockWriter.pv"
                                fprintf(file, "case ");
                                #line 404 "src/compiler/BlockWriter.pv"
                                Hash hash;

                                #line 406 "src/compiler/BlockWriter.pv"
                                switch (token->type) {
                                    #line 407 "src/compiler/BlockWriter.pv"
                                    case TOKEN_TYPE__STRING: {
                                        #line 408 "src/compiler/BlockWriter.pv"
                                        struct str value = str__slice(token->value, 1, token->value.length - 1);
                                        #line 409 "src/compiler/BlockWriter.pv"
                                        hash = str__Hash__hash(&value);
                                    } break;
                                    #line 411 "src/compiler/BlockWriter.pv"
                                    case TOKEN_TYPE__NUMBER: {
                                        #line 412 "src/compiler/BlockWriter.pv"
                                        struct str primitive = Expression__number_primitive(token->value);
                                        #line 413 "src/compiler/BlockWriter.pv"
                                        switch (str__Hash__hash(&primitive)) {
                                            #line 414 "src/compiler/BlockWriter.pv"
                                            case 15952682373371409732ULL: {
                                                #line 415 "src/compiler/BlockWriter.pv"
                                                float value = strtof(token->value.ptr, 0);
                                                #line 416 "src/compiler/BlockWriter.pv"
                                                hash = f32__Hash__hash(&value);
                                            } break;
                                            #line 418 "src/compiler/BlockWriter.pv"
                                            case 15957463049929925035ULL: {
                                                #line 419 "src/compiler/BlockWriter.pv"
                                                double value = strtod(token->value.ptr, 0);
                                                #line 420 "src/compiler/BlockWriter.pv"
                                                hash = f64__Hash__hash(&value);
                                            } break;
                                            #line 422 "src/compiler/BlockWriter.pv"
                                            case 5560783464435099345ULL: {
                                                #line 423 "src/compiler/BlockWriter.pv"
                                                uint32_t value = strtoul(token->value.ptr, 0, 10);
                                                #line 424 "src/compiler/BlockWriter.pv"
                                                hash = u32__Hash__hash(&value);
                                            } break;
                                            #line 426 "src/compiler/BlockWriter.pv"
                                            case 3094732814638223685ULL: {
                                                #line 427 "src/compiler/BlockWriter.pv"
                                                int32_t value = strtol(token->value.ptr, 0, 10);
                                                #line 428 "src/compiler/BlockWriter.pv"
                                                hash = i32__Hash__hash(&value);
                                            } break;
                                            #line 430 "src/compiler/BlockWriter.pv"
                                            default: {
                                                #line 431 "src/compiler/BlockWriter.pv"
                                                fprintf(stderr, "Hash match pattern on unsupported number literal type\n");
                                                #line 432 "src/compiler/BlockWriter.pv"
                                                hash = 0;
                                            } break;
                                        }
                                    } break;
                                    #line 436 "src/compiler/BlockWriter.pv"
                                    default: {
                                        #line 437 "src/compiler/BlockWriter.pv"
                                        fprintf(stderr, "Hash match pattern on unsupported token type\n");
                                        #line 438 "src/compiler/BlockWriter.pv"
                                        hash = 0;
                                    } break;
                                }

                                #line 442 "src/compiler/BlockWriter.pv"
                                fprintf(file, "%lluULL:", hash);
                            } break;
                            #line 444 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__DEFAULT: {
                                #line 445 "src/compiler/BlockWriter.pv"
                                fprintf(file, "default:");
                            } break;
                        }
                    } }

                    #line 450 "src/compiler/BlockWriter.pv"
                    fprintf(file, " {\n");
                    #line 451 "src/compiler/BlockWriter.pv"
                    generator->indent += 1;

                    #line 453 "src/compiler/BlockWriter.pv"
                    { struct Iter_ref_MatchPattern __iter = Array_MatchPattern__iter(patterns);
                    #line 453 "src/compiler/BlockWriter.pv"
                    while (Iter_ref_MatchPattern__next(&__iter)) {
                        #line 453 "src/compiler/BlockWriter.pv"
                        struct MatchPattern* pattern = Iter_ref_MatchPattern__value(&__iter);

                        #line 454 "src/compiler/BlockWriter.pv"
                        switch (pattern->type) {
                            #line 455 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__STATIC_VALUE: {
                            } break;
                            #line 456 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_VARIANT: {
                                #line 456 "src/compiler/BlockWriter.pv"
                                struct EnumVariant* enum_variant = pattern->enumvariant_value._1;
                                #line 456 "src/compiler/BlockWriter.pv"
                                struct Array_EnumVariantParameter* parameters = &pattern->enumvariant_value._2;
                                #line 457 "src/compiler/BlockWriter.pv"
                                struct Array_Type* types = &enum_variant->types;
                                #line 458 "src/compiler/BlockWriter.pv"
                                uintptr_t param_i = 0;
                                #line 459 "src/compiler/BlockWriter.pv"
                                { struct Iter_ref_EnumVariantParameter __iter = Array_EnumVariantParameter__iter(parameters);
                                #line 459 "src/compiler/BlockWriter.pv"
                                while (Iter_ref_EnumVariantParameter__next(&__iter)) {
                                    #line 459 "src/compiler/BlockWriter.pv"
                                    struct EnumVariantParameter* param_iter = Iter_ref_EnumVariantParameter__value(&__iter);

                                    #line 460 "src/compiler/BlockWriter.pv"
                                    if (Token__eq(param_iter->variable, TOKEN_TYPE__IDENTIFIER, "_")) {
                                        #line 461 "src/compiler/BlockWriter.pv"
                                        param_i += 1;
                                        #line 462 "src/compiler/BlockWriter.pv"
                                        continue;
                                    }

                                    #line 465 "src/compiler/BlockWriter.pv"
                                    struct Type* param_type;
                                    #line 466 "src/compiler/BlockWriter.pv"
                                    struct String accessor = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
                                    #line 467 "src/compiler/BlockWriter.pv"
                                    String__append_str_lowercase(&accessor, enum_variant->name->value);
                                    #line 468 "src/compiler/BlockWriter.pv"
                                    String__append(&accessor, (struct str){ .ptr = "_value", .length = strlen("_value") });

                                    #line 470 "src/compiler/BlockWriter.pv"
                                    if (enum_variant->names.length > 0) {
                                        #line 471 "src/compiler/BlockWriter.pv"
                                        uintptr_t field_i = 0;
                                        #line 472 "src/compiler/BlockWriter.pv"
                                        while (field_i < enum_variant->names.length) {
                                            #line 473 "src/compiler/BlockWriter.pv"
                                            if (str__Eq_str__eq(&enum_variant->names.data[field_i], param_iter->field_name)) {
                                                #line 473 "src/compiler/BlockWriter.pv"
                                                break;
                                            }
                                            #line 474 "src/compiler/BlockWriter.pv"
                                            field_i += 1;
                                        }
                                        #line 476 "src/compiler/BlockWriter.pv"
                                        param_type = types->data + field_i;
                                        #line 477 "src/compiler/BlockWriter.pv"
                                        String__append(&accessor, (struct str){ .ptr = ".", .length = strlen(".") });
                                        #line 478 "src/compiler/BlockWriter.pv"
                                        String__append(&accessor, param_iter->field_name);
                                    } else {
                                        #line 480 "src/compiler/BlockWriter.pv"
                                        param_type = types->data + param_i;
                                        #line 481 "src/compiler/BlockWriter.pv"
                                        if (types->length > 1) {
                                            #line 482 "src/compiler/BlockWriter.pv"
                                            String__append(&accessor, (struct str){ .ptr = "._", .length = strlen("._") });
                                            #line 483 "src/compiler/BlockWriter.pv"
                                            String__append_usize(&accessor, param_i);
                                        }
                                    }

                                    #line 487 "src/compiler/BlockWriter.pv"
                                    struct Expression* variable_expression = expression;
                                    #line 488 "src/compiler/BlockWriter.pv"
                                    variable_expression = Expression__make(generator->allocator, param_iter->variable, (struct ExpressionData) { .type = EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION, .memberinstanceexpression_value = { ._0 = variable_expression, ._1 = String__as_str(&accessor)} }, param_type);

                                    #line 490 "src/compiler/BlockWriter.pv"
                                    struct Token* name = param_iter->variable;
                                    #line 491 "src/compiler/BlockWriter.pv"
                                    Generator__write_line_directive(generator, file, block->context, name);
                                    #line 492 "src/compiler/BlockWriter.pv"
                                    Generator__write_indent(generator, file);
                                    #line 493 "src/compiler/BlockWriter.pv"
                                    Generator__write_type(generator, file, param_type, generics);
                                    #line 494 "src/compiler/BlockWriter.pv"
                                    if (param_iter->ref) {
                                        #line 494 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 495 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " ");
                                    #line 496 "src/compiler/BlockWriter.pv"
                                    Generator__write_token(generator, file, name);
                                    #line 497 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " = ");
                                    #line 498 "src/compiler/BlockWriter.pv"
                                    if (param_iter->ref) {
                                        #line 498 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 499 "src/compiler/BlockWriter.pv"
                                    ExpressionWriter__write_expression(&expr, file, variable_expression, generics);
                                    #line 500 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ";\n");

                                    #line 502 "src/compiler/BlockWriter.pv"
                                    param_i += 1;
                                } }
                            } break;
                            #line 505 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__ENUM_CVALUE: {
                            } break;
                            #line 506 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__TYPE_ID: {
                            } break;
                            #line 507 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__HASH: {
                            } break;
                            #line 508 "src/compiler/BlockWriter.pv"
                            case MATCH_PATTERN__DEFAULT: {
                            } break;
                        }
                    } }

                    #line 512 "src/compiler/BlockWriter.pv"
                    struct FunctionContext* function_context = generator->function_context;
                    #line 513 "src/compiler/BlockWriter.pv"
                    if (function_context == 0) {
                        #line 514 "src/compiler/BlockWriter.pv"
                        fprintf(stderr, "Missing function context in match case\n");
                        #line 515 "src/compiler/BlockWriter.pv"
                        return false;
                    }
                    #line 517 "src/compiler/BlockWriter.pv"
                    FunctionContext__push_scope(function_context, true, false);
                    #line 518 "src/compiler/BlockWriter.pv"
                    if (!BlockWriter__write_block(self, file, return_type, case_info->body, generics, true, true)) {
                        #line 518 "src/compiler/BlockWriter.pv"
                        return false;
                    }
                    #line 519 "src/compiler/BlockWriter.pv"
                    FunctionContext__pop_scope(function_context);

                    #line 521 "src/compiler/BlockWriter.pv"
                    generator->indent -= 1;
                    #line 522 "src/compiler/BlockWriter.pv"
                    Generator__write_indent(generator, file);
                    #line 523 "src/compiler/BlockWriter.pv"
                    fprintf(file, "} break;\n");
                } }

                #line 526 "src/compiler/BlockWriter.pv"
                generator->indent -= 1;
                #line 527 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 528 "src/compiler/BlockWriter.pv"
                fprintf(file, "}\n");
            } break;
            #line 530 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__WHILE_STATEMENT: {
                #line 530 "src/compiler/BlockWriter.pv"
                struct WhileStatement* while_stmt = statement->data.whilestatement_value;
                #line 531 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 532 "src/compiler/BlockWriter.pv"
                fprintf(file, "while (");
                #line 533 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, while_stmt->expression, generics);
                #line 534 "src/compiler/BlockWriter.pv"
                fprintf(file, ") ");
                #line 535 "src/compiler/BlockWriter.pv"
                struct FunctionContext* function_context = generator->function_context;
                #line 536 "src/compiler/BlockWriter.pv"
                if (function_context == 0) {
                    #line 537 "src/compiler/BlockWriter.pv"
                    fprintf(stderr, "Missing function context in while statement\n");
                    #line 538 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 540 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(function_context, true, true);
                #line 541 "src/compiler/BlockWriter.pv"
                if (!BlockWriter__write_block(self, file, return_type, while_stmt->block, generics, false, false)) {
                    #line 541 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 542 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(function_context);
            } break;
            #line 544 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__FOR_STATEMENT: {
                #line 544 "src/compiler/BlockWriter.pv"
                struct ForStatement* for_statement = statement->data.forstatement_value;
                #line 545 "src/compiler/BlockWriter.pv"
                bool is_iterator = false;

                #line 547 "src/compiler/BlockWriter.pv"
                switch (for_statement->type.type) {
                    #line 548 "src/compiler/BlockWriter.pv"
                    case FOR_STATEMENT_TYPE__ERROR: {
                        #line 549 "src/compiler/BlockWriter.pv"
                        fprintf(file, "/* ERROR: Invalid for loop type */\n");
                    } break;
                    #line 551 "src/compiler/BlockWriter.pv"
                    case FOR_STATEMENT_TYPE__RANGE: {
                        #line 551 "src/compiler/BlockWriter.pv"
                        struct Expression* start = for_statement->type.range_value._0;
                        #line 551 "src/compiler/BlockWriter.pv"
                        struct Expression* end = for_statement->type.range_value._1;
                        #line 552 "src/compiler/BlockWriter.pv"
                        is_iterator = true;
                        #line 553 "src/compiler/BlockWriter.pv"
                        struct ForVariable* variable = &for_statement->variables.data[0];
                        #line 554 "src/compiler/BlockWriter.pv"
                        struct str variable_name = variable->name->value;

                        #line 556 "src/compiler/BlockWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 557 "src/compiler/BlockWriter.pv"
                        fprintf(file, "for (");

                        #line 559 "src/compiler/BlockWriter.pv"
                        struct FunctionContext* function_context = generator->function_context;
                        #line 560 "src/compiler/BlockWriter.pv"
                        if (function_context == 0) {
                            #line 561 "src/compiler/BlockWriter.pv"
                            fprintf(stderr, "Missing function context in range for statement\n");
                            #line 562 "src/compiler/BlockWriter.pv"
                            return false;
                        }
                        #line 564 "src/compiler/BlockWriter.pv"
                        FunctionContext__add_variable(function_context, variable_name, variable->type);

                        #line 566 "src/compiler/BlockWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 567 "src/compiler/BlockWriter.pv"
                            Generator__write_variable(generator, file, variable_name);
                        } else {
                            #line 569 "src/compiler/BlockWriter.pv"
                            Generator__write_variable_decl(generator, file, variable_name, variable->type, generics);
                        }

                        #line 572 "src/compiler/BlockWriter.pv"
                        fprintf(file, " = ");
                        #line 573 "src/compiler/BlockWriter.pv"
                        ExpressionWriter__write_expression(&expr, file, start, generics);
                        #line 574 "src/compiler/BlockWriter.pv"
                        fprintf(file, "; ");
                        #line 575 "src/compiler/BlockWriter.pv"
                        Generator__write_variable(generator, file, variable_name);
                        #line 576 "src/compiler/BlockWriter.pv"
                        fprintf(file, " < ");
                        #line 577 "src/compiler/BlockWriter.pv"
                        ExpressionWriter__write_expression(&expr, file, end, generics);
                        #line 578 "src/compiler/BlockWriter.pv"
                        fprintf(file, "; ");
                        #line 579 "src/compiler/BlockWriter.pv"
                        Generator__write_variable(generator, file, variable_name);
                        #line 580 "src/compiler/BlockWriter.pv"
                        fprintf(file, "++) {");
                        #line 581 "src/compiler/BlockWriter.pv"
                        generator->indent += 1;
                    } break;
                    #line 583 "src/compiler/BlockWriter.pv"
                    case FOR_STATEMENT_TYPE__SEQUENCE: {
                        #line 583 "src/compiler/BlockWriter.pv"
                        struct Expression* iter_expression = for_statement->type.sequence_value;
                        #line 584 "src/compiler/BlockWriter.pv"
                        is_iterator = true;
                        #line 585 "src/compiler/BlockWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 586 "src/compiler/BlockWriter.pv"
                        struct Type iter_type = *for_statement->iter_type;
                        #line 587 "src/compiler/BlockWriter.pv"
                        switch (Type__deref(&iter_type)->type) {
                            #line 588 "src/compiler/BlockWriter.pv"
                            case TYPE__SEQUENCE: {
                                #line 588 "src/compiler/BlockWriter.pv"
                                struct Sequence* sequence = Type__deref(&iter_type)->sequence_value;
                                #line 589 "src/compiler/BlockWriter.pv"
                                switch (sequence->type.type) {
                                    #line 590 "src/compiler/BlockWriter.pv"
                                    case SEQUENCE_TYPE__FIXED_ARRAY: {
                                        #line 590 "src/compiler/BlockWriter.pv"
                                        struct Expression* size = sequence->type.fixedarray_value;
                                        #line 591 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "for (size_t __iter = 0; __iter < (");
                                        #line 592 "src/compiler/BlockWriter.pv"
                                        ExpressionWriter__write_expression(&expr, file, size, generics);
                                        #line 593 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "); __iter++) {\n");
                                    } break;
                                    #line 595 "src/compiler/BlockWriter.pv"
                                    case SEQUENCE_TYPE__SLICE: {
                                        #line 596 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "for (size_t __iter = 0; __iter < ");
                                        #line 597 "src/compiler/BlockWriter.pv"
                                        ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                        #line 598 "src/compiler/BlockWriter.pv"
                                        fprintf(file, ".length; __iter++) {\n");
                                    } break;
                                }
                            } break;
                            #line 602 "src/compiler/BlockWriter.pv"
                            default: {
                                #line 602 "src/compiler/BlockWriter.pv"
                                fprintf(file, "/* ERROR: Sequence for loop on non-sequence type */");
                            } break;
                        }

                        #line 605 "src/compiler/BlockWriter.pv"
                        generator->indent += 1;

                        #line 607 "src/compiler/BlockWriter.pv"
                        uintptr_t i = 0;
                        #line 608 "src/compiler/BlockWriter.pv"
                        { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                        #line 608 "src/compiler/BlockWriter.pv"
                        while (Iter_ref_ForVariable__next(&__iter)) {
                            #line 608 "src/compiler/BlockWriter.pv"
                            struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                            #line 609 "src/compiler/BlockWriter.pv"
                            if (!str__Eq_str__eq(&variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                #line 610 "src/compiler/BlockWriter.pv"
                                Generator__write_line_directive(generator, file, block->context, variable->name);
                                #line 611 "src/compiler/BlockWriter.pv"
                                Generator__write_indent(generator, file);
                                #line 612 "src/compiler/BlockWriter.pv"
                                Generator__write_type(generator, file, variable->type, generics);
                                #line 613 "src/compiler/BlockWriter.pv"
                                fprintf(file, " ");
                                #line 614 "src/compiler/BlockWriter.pv"
                                Generator__write_token(generator, file, variable->name);
                                #line 615 "src/compiler/BlockWriter.pv"
                                fprintf(file, " = ");
                                #line 616 "src/compiler/BlockWriter.pv"
                                if (variable->ref) {
                                    #line 616 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "&");
                                }
                                #line 617 "src/compiler/BlockWriter.pv"
                                if (variable->deref) {
                                    #line 617 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "*");
                                }
                                #line 618 "src/compiler/BlockWriter.pv"
                                struct Type iter_type = *for_statement->iter_type;
                                #line 619 "src/compiler/BlockWriter.pv"
                                switch (Type__deref(&iter_type)->type) {
                                    #line 620 "src/compiler/BlockWriter.pv"
                                    case TYPE__SEQUENCE: {
                                        #line 620 "src/compiler/BlockWriter.pv"
                                        struct Sequence* sequence = Type__deref(&iter_type)->sequence_value;
                                        #line 621 "src/compiler/BlockWriter.pv"
                                        switch (sequence->type.type) {
                                            #line 622 "src/compiler/BlockWriter.pv"
                                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                                #line 623 "src/compiler/BlockWriter.pv"
                                                ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                                #line 624 "src/compiler/BlockWriter.pv"
                                                fprintf(file, "[__iter]");
                                            } break;
                                            #line 626 "src/compiler/BlockWriter.pv"
                                            case SEQUENCE_TYPE__SLICE: {
                                                #line 627 "src/compiler/BlockWriter.pv"
                                                ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                                #line 628 "src/compiler/BlockWriter.pv"
                                                fprintf(file, ".data[__iter]");
                                            } break;
                                        }
                                    } break;
                                    #line 632 "src/compiler/BlockWriter.pv"
                                    default: {
                                        #line 632 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "/* ERROR */");
                                    } break;
                                }

                                #line 635 "src/compiler/BlockWriter.pv"
                                if (for_statement->variables.length > 1) {
                                    #line 636 "src/compiler/BlockWriter.pv"
                                    Generator__write_instance_member_accessor(generator, file, for_statement->value_type, generics);
                                    #line 637 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "_%zu", i);
                                }

                                #line 640 "src/compiler/BlockWriter.pv"
                                fprintf(file, ";\n");
                            }

                            #line 643 "src/compiler/BlockWriter.pv"
                            i += 1;
                        } }
                    } break;
                    #line 646 "src/compiler/BlockWriter.pv"
                    case FOR_STATEMENT_TYPE__ITER: {
                        #line 646 "src/compiler/BlockWriter.pv"
                        struct Expression* iter_expression = for_statement->type.iter_value;
                        #line 647 "src/compiler/BlockWriter.pv"
                        struct Type iter_type = *for_statement->iter_type;
                        #line 648 "src/compiler/BlockWriter.pv"
                        struct Type value_type = *for_statement->value_type;
                        #line 649 "src/compiler/BlockWriter.pv"
                        is_iterator = Type__is_iterator(Type__deref(&iter_type));
                        #line 650 "src/compiler/BlockWriter.pv"
                        if (is_iterator) {
                            #line 651 "src/compiler/BlockWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 652 "src/compiler/BlockWriter.pv"
                            fprintf(file, "while (");
                            #line 653 "src/compiler/BlockWriter.pv"
                            ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                            #line 654 "src/compiler/BlockWriter.pv"
                            fprintf(file, ".vtable->fn_next(");
                            #line 655 "src/compiler/BlockWriter.pv"
                            ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                            #line 656 "src/compiler/BlockWriter.pv"
                            fprintf(file, ".instance)) {");

                            #line 658 "src/compiler/BlockWriter.pv"
                            generator->indent += 1;

                            #line 660 "src/compiler/BlockWriter.pv"
                            uintptr_t i = 0;
                            #line 661 "src/compiler/BlockWriter.pv"
                            { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 661 "src/compiler/BlockWriter.pv"
                            while (Iter_ref_ForVariable__next(&__iter)) {
                                #line 661 "src/compiler/BlockWriter.pv"
                                struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                                #line 662 "src/compiler/BlockWriter.pv"
                                if (!str__Eq_str__eq(&variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 663 "src/compiler/BlockWriter.pv"
                                    Generator__write_line_directive(generator, file, block->context, variable->name);
                                    #line 664 "src/compiler/BlockWriter.pv"
                                    Generator__write_indent(generator, file);
                                    #line 665 "src/compiler/BlockWriter.pv"
                                    Generator__write_type(generator, file, variable->type, generics);
                                    #line 666 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " ");
                                    #line 667 "src/compiler/BlockWriter.pv"
                                    Generator__write_token(generator, file, variable->name);
                                    #line 668 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " = ");
                                    #line 669 "src/compiler/BlockWriter.pv"
                                    if (variable->ref) {
                                        #line 669 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 670 "src/compiler/BlockWriter.pv"
                                    if (variable->deref) {
                                        #line 670 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 671 "src/compiler/BlockWriter.pv"
                                    ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                    #line 672 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ".vtable->fn_value");
                                    #line 673 "src/compiler/BlockWriter.pv"
                                    if (for_statement->variables.length > 1) {
                                        #line 673 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 674 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "(");
                                    #line 675 "src/compiler/BlockWriter.pv"
                                    ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                                    #line 676 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ".instance);\n");
                                }

                                #line 679 "src/compiler/BlockWriter.pv"
                                i += 1;
                            } }
                        } else {
                            #line 682 "src/compiler/BlockWriter.pv"
                            struct String iter_type_name = Naming__get_type_name(&generator->naming_ident, for_statement->iter_type, generics->self_type, generics);

                            #line 684 "src/compiler/BlockWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 685 "src/compiler/BlockWriter.pv"
                            fprintf(file, "{ ");
                            #line 686 "src/compiler/BlockWriter.pv"
                            Generator__write_type(generator, file, for_statement->iter_type, generics);
                            #line 687 "src/compiler/BlockWriter.pv"
                            fprintf(file, " __iter = ");
                            #line 688 "src/compiler/BlockWriter.pv"
                            ExpressionWriter__write_expression(&expr, file, iter_expression, generics);
                            #line 689 "src/compiler/BlockWriter.pv"
                            fprintf(file, ";\n");

                            #line 691 "src/compiler/BlockWriter.pv"
                            Generator__write_line_directive(generator, file, block->context, iter_expression->token);

                            #line 693 "src/compiler/BlockWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 694 "src/compiler/BlockWriter.pv"
                            fprintf(file, "while (");
                            #line 695 "src/compiler/BlockWriter.pv"
                            Generator__write_string(generator, file, &iter_type_name);
                            #line 696 "src/compiler/BlockWriter.pv"
                            fprintf(file, "__next(&__iter)) {\n");

                            #line 698 "src/compiler/BlockWriter.pv"
                            generator->indent += 1;

                            #line 700 "src/compiler/BlockWriter.pv"
                            uintptr_t i = 0;
                            #line 701 "src/compiler/BlockWriter.pv"
                            { struct Iter_ref_ForVariable __iter = Array_ForVariable__iter(&for_statement->variables);
                            #line 701 "src/compiler/BlockWriter.pv"
                            while (Iter_ref_ForVariable__next(&__iter)) {
                                #line 701 "src/compiler/BlockWriter.pv"
                                struct ForVariable* variable = Iter_ref_ForVariable__value(&__iter);

                                #line 702 "src/compiler/BlockWriter.pv"
                                if (!str__Eq_str__eq(&variable->name->value, (struct str){ .ptr = "_", .length = strlen("_") })) {
                                    #line 703 "src/compiler/BlockWriter.pv"
                                    Generator__write_line_directive(generator, file, block->context, variable->name);
                                    #line 704 "src/compiler/BlockWriter.pv"
                                    Generator__write_indent(generator, file);
                                    #line 705 "src/compiler/BlockWriter.pv"
                                    Generator__write_type(generator, file, variable->type, generics);
                                    #line 706 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " ");
                                    #line 707 "src/compiler/BlockWriter.pv"
                                    Generator__write_token(generator, file, variable->name);
                                    #line 708 "src/compiler/BlockWriter.pv"
                                    fprintf(file, " = ");
                                    #line 709 "src/compiler/BlockWriter.pv"
                                    if (variable->ref) {
                                        #line 709 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "&");
                                    }
                                    #line 710 "src/compiler/BlockWriter.pv"
                                    if (variable->deref) {
                                        #line 710 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "*");
                                    }
                                    #line 711 "src/compiler/BlockWriter.pv"
                                    Generator__write_string(generator, file, &iter_type_name);
                                    #line 712 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "__value");
                                    #line 713 "src/compiler/BlockWriter.pv"
                                    if (!Type__is_tuple(Type__deref(&value_type)) && for_statement->variables.length > 1) {
                                        #line 714 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "_%zu", i);
                                    }
                                    #line 716 "src/compiler/BlockWriter.pv"
                                    fprintf(file, "(&__iter)");

                                    #line 718 "src/compiler/BlockWriter.pv"
                                    if (Type__is_tuple(Type__deref(&value_type)) && for_statement->variables.length > 1) {
                                        #line 719 "src/compiler/BlockWriter.pv"
                                        Generator__write_instance_member_accessor(generator, file, for_statement->value_type, generics);
                                        #line 720 "src/compiler/BlockWriter.pv"
                                        fprintf(file, "_%zu", i);
                                    }

                                    #line 723 "src/compiler/BlockWriter.pv"
                                    fprintf(file, ";\n");
                                }

                                #line 726 "src/compiler/BlockWriter.pv"
                                i += 1;
                            } }
                        }
                    } break;
                }

                #line 732 "src/compiler/BlockWriter.pv"
                fprintf(file, "\n");

                #line 734 "src/compiler/BlockWriter.pv"
                struct FunctionContext* function_context = generator->function_context;
                #line 735 "src/compiler/BlockWriter.pv"
                if (function_context == 0) {
                    #line 736 "src/compiler/BlockWriter.pv"
                    fprintf(stderr, "Missing function context in for statement\n");
                    #line 737 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 739 "src/compiler/BlockWriter.pv"
                FunctionContext__push_scope(function_context, true, true);
                #line 740 "src/compiler/BlockWriter.pv"
                if (!BlockWriter__write_block(self, file, return_type, for_statement->block, generics, false, true)) {
                    #line 740 "src/compiler/BlockWriter.pv"
                    return false;
                }
                #line 741 "src/compiler/BlockWriter.pv"
                FunctionContext__pop_scope(function_context);

                #line 743 "src/compiler/BlockWriter.pv"
                generator->indent -= 1;
                #line 744 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 745 "src/compiler/BlockWriter.pv"
                if (is_iterator) {
                    #line 746 "src/compiler/BlockWriter.pv"
                    fprintf(file, "}\n");
                } else {
                    #line 748 "src/compiler/BlockWriter.pv"
                    fprintf(file, "} }\n");
                }
            } break;
            #line 751 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__ASSIGNMENT_STATEMENT: {
                #line 751 "src/compiler/BlockWriter.pv"
                struct AssignmentStatement* assignment = statement->data.assignmentstatement_value;
                #line 752 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 753 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, assignment->left, generics);
                #line 754 "src/compiler/BlockWriter.pv"
                fprintf(file, " ");
                #line 755 "src/compiler/BlockWriter.pv"
                Generator__write_str(generator, file, assignment->operator->value);
                #line 756 "src/compiler/BlockWriter.pv"
                fprintf(file, " ");
                #line 757 "src/compiler/BlockWriter.pv"
                bool wrote_null_fat = false;
                #line 758 "src/compiler/BlockWriter.pv"
                switch (assignment->right->data.type) {
                    #line 759 "src/compiler/BlockWriter.pv"
                    case EXPRESSION_DATA__NULL_LITERAL: {
                        #line 760 "src/compiler/BlockWriter.pv"
                        if (Type__is_fat_pointer(&assignment->left->return_type)) {
                            #line 761 "src/compiler/BlockWriter.pv"
                            fprintf(file, "(");
                            #line 762 "src/compiler/BlockWriter.pv"
                            Generator__write_type(generator, file, &assignment->left->return_type, generics);
                            #line 763 "src/compiler/BlockWriter.pv"
                            fprintf(file, "){0}");
                            #line 764 "src/compiler/BlockWriter.pv"
                            wrote_null_fat = true;
                        }
                    } break;
                    #line 767 "src/compiler/BlockWriter.pv"
                    default: {
                    } break;
                }
                #line 769 "src/compiler/BlockWriter.pv"
                if (!wrote_null_fat) {
                    #line 769 "src/compiler/BlockWriter.pv"
                    ExpressionWriter__write_expression(&expr, file, assignment->right, generics);
                }
                #line 770 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 772 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__EXPRESSION_STATEMENT: {
                #line 772 "src/compiler/BlockWriter.pv"
                struct Expression* expression = statement->data.expressionstatement_value;
                #line 773 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 774 "src/compiler/BlockWriter.pv"
                ExpressionWriter__write_expression(&expr, file, expression, generics);
                #line 775 "src/compiler/BlockWriter.pv"
                fprintf(file, ";\n");
            } break;
            #line 777 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__CONTINUE_STATEMENT: {
                #line 777 "src/compiler/BlockWriter.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.continuestatement_value;
                #line 778 "src/compiler/BlockWriter.pv"
                BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 779 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 780 "src/compiler/BlockWriter.pv"
                fprintf(file, "continue;\n");
            } break;
            #line 782 "src/compiler/BlockWriter.pv"
            case STATEMENT_DATA__BREAK_STATEMENT: {
                #line 782 "src/compiler/BlockWriter.pv"
                struct Array_DeferStatement* defer_statements = &statement->data.breakstatement_value;
                #line 783 "src/compiler/BlockWriter.pv"
                BlockWriter__write_defer_statements(self, file, return_type, defer_statements, generics);
                #line 784 "src/compiler/BlockWriter.pv"
                Generator__write_indent(generator, file);
                #line 785 "src/compiler/BlockWriter.pv"
                fprintf(file, "break;\n");
            } break;
        }
    } }

    #line 790 "src/compiler/BlockWriter.pv"
    if (!last_statement_is_return) {
        #line 791 "src/compiler/BlockWriter.pv"
        BlockWriter__write_defer_statements(self, file, return_type, &block->defer_statements, generics);
    }

    #line 794 "src/compiler/BlockWriter.pv"
    if (!no_brackets) {
        #line 795 "src/compiler/BlockWriter.pv"
        generator->indent -= 1;
        #line 796 "src/compiler/BlockWriter.pv"
        Generator__write_indent(generator, file);

        #line 798 "src/compiler/BlockWriter.pv"
        if (inline_) {
            #line 799 "src/compiler/BlockWriter.pv"
            fprintf(file, "}");
        } else {
            #line 801 "src/compiler/BlockWriter.pv"
            fprintf(file, "}\n");
        }
    }

    #line 805 "src/compiler/BlockWriter.pv"
    return true;
}
