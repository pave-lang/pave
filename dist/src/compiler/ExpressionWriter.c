#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>
#include <compiler/ExpressionWriter.h>
#include <compiler/Generator.h>
#include <analyzer/expression/Expression.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionParent.h>
#include <std/str.h>
#include <analyzer/Token.h>
#include <analyzer/types/Struct.h>
#include <analyzer/Context.h>
#include <std/ArenaAllocator.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <std/Array_Type.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/expression/ExpressionData.h>
#include <std/Array_InvokeArgument.h>
#include <analyzer/expression/InvokeArgument.h>
#include <std/IterEnumerate_ref_InvokeArgument.h>
#include <std/Iter_ref_InvokeArgument.h>
#include <tuple_usize_ref_InvokeArgument.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/EnumVariant.h>
#include <std/Array_str.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/c/FunctionC.h>
#include <std/Array_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <analyzer/Impl.h>
#include <analyzer/expression/CppExpression.h>
#include <compiler/ExpressionWriter.h>

#include <compiler/ExpressionWriter.h>

#line 14 "src/compiler/ExpressionWriter.pv"
struct ExpressionWriter ExpressionWriter__new(struct Generator* generator) {
    #line 15 "src/compiler/ExpressionWriter.pv"
    return (struct ExpressionWriter) { .generator = generator };
}

#line 18 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_str_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct GenericMap* generics, bool reference) {
    #line 19 "src/compiler/ExpressionWriter.pv"
    if (reference) {
        #line 19 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "&");
    }
    #line 20 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(struct str){ .ptr = ");
    #line 21 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 22 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = strlen(");
    #line 23 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, inner_expr, generics);
    #line 24 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") }");
}

#line 27 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_trait_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Type* type, struct GenericMap* generics) {
    #line 28 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 29 "src/compiler/ExpressionWriter.pv"
    switch (Type__deref(&inner_expr->return_type)->type) {
        #line 30 "src/compiler/ExpressionWriter.pv"
        case TYPE__FUNCTION: {
            #line 30 "src/compiler/ExpressionWriter.pv"
            struct Function* func_info = Type__deref(&inner_expr->return_type)->function_value._0;
            #line 30 "src/compiler/ExpressionWriter.pv"
            struct GenericMap* func_generics = Type__deref(&inner_expr->return_type)->function_value._1;
            #line 31 "src/compiler/ExpressionWriter.pv"
            if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                #line 32 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Co_CoroutineStatus) { .vtable = &");

                #line 34 "src/compiler/ExpressionWriter.pv"
                switch (func_info->parent.type) {
                    #line 35 "src/compiler/ExpressionWriter.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 35 "src/compiler/ExpressionWriter.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 36 "src/compiler/ExpressionWriter.pv"
                        Generator__write_str_title(g, file, struct_info->name->value);
                        #line 37 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "__");
                    } break;
                    #line 39 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 42 "src/compiler/ExpressionWriter.pv"
                Generator__write_str_title(g, file, func_info->name->value);
                #line 43 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 44 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(g, file, func_info, func_generics);
                #line 45 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Co_CoroutineStatus__Instance) {}");
                #line 46 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 48 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(struct trait_Fn) { .vtable = &");

                #line 50 "src/compiler/ExpressionWriter.pv"
                switch (func_info->parent.type) {
                    #line 51 "src/compiler/ExpressionWriter.pv"
                    case FUNCTION_PARENT__STRUCT: {
                        #line 51 "src/compiler/ExpressionWriter.pv"
                        struct Struct* struct_info = func_info->parent.struct_value._0;
                        #line 52 "src/compiler/ExpressionWriter.pv"
                        Generator__write_str_title(g, file, struct_info->name->value);
                        #line 53 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "__");
                    } break;
                    #line 55 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 58 "src/compiler/ExpressionWriter.pv"
                Generator__write_str_title(g, file, func_info->name->value);
                #line 59 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 60 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(g, file, func_info, func_generics);
                #line 61 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__Fn__Instance) {}");
                #line 62 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            }

            #line 65 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
        #line 67 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 70 "src/compiler/ExpressionWriter.pv"
    switch (type->type) {
        #line 71 "src/compiler/ExpressionWriter.pv"
        case TYPE__TRAIT: {
            #line 71 "src/compiler/ExpressionWriter.pv"
            struct Trait* trait_info = type->trait_value._0;
            #line 72 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 73 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(g, file, type, generics);
            #line 74 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 76 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(g->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 77 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&g->naming_ident, inner_type, generics->array.data, generics);
            #line 78 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(g, file, String__as_str(&inner_type_name));

            #line 80 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 81 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(g, file, trait_info->name->value);
            #line 82 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", .instance = ");
            #line 83 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
            #line 84 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " }");
        } break;
        #line 86 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 86 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner_expr, generics);
        } break;
    }
}

#line 90 "src/compiler/ExpressionWriter.pv"
void ExpressionWriter__write_sequence_cast(struct ExpressionWriter* self, FILE* file, struct Expression* inner_expr, struct Sequence* sequence, struct GenericMap* generics) {
    #line 91 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 92 "src/compiler/ExpressionWriter.pv"
    struct Sequence* inner_sequence = 0;

    #line 94 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->return_type.type) {
        #line 95 "src/compiler/ExpressionWriter.pv"
        case TYPE__INDIRECT: {
            #line 95 "src/compiler/ExpressionWriter.pv"
            struct Indirect* indirect = inner_expr->return_type.indirect_value;
            #line 96 "src/compiler/ExpressionWriter.pv"
            switch (indirect->to.type) {
                #line 97 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 97 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* inner_sequence_2 = indirect->to.sequence_value;
                    #line 97 "src/compiler/ExpressionWriter.pv"
                    inner_sequence = inner_sequence_2;
                } break;
                #line 98 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 101 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 104 "src/compiler/ExpressionWriter.pv"
    if (inner_sequence == 0) {
        #line 105 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
        #line 106 "src/compiler/ExpressionWriter.pv"
        return;
    }

    #line 109 "src/compiler/ExpressionWriter.pv"
    uintptr_t length = 0;
    #line 110 "src/compiler/ExpressionWriter.pv"
    switch (inner_sequence->type.type) {
        #line 111 "src/compiler/ExpressionWriter.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 111 "src/compiler/ExpressionWriter.pv"
            uintptr_t seq_length = inner_sequence->type.fixedarray_value;
            #line 111 "src/compiler/ExpressionWriter.pv"
            length = seq_length;
        } break;
        #line 112 "src/compiler/ExpressionWriter.pv"
        default: {
            #line 113 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " !!ERROR INVALID SEQUENCE TYPE TO CONVERT INTO SLICE!! ");
            #line 114 "src/compiler/ExpressionWriter.pv"
            return;
        } break;
    }

    #line 118 "src/compiler/ExpressionWriter.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = sequence };
    #line 119 "src/compiler/ExpressionWriter.pv"
    struct String name = Naming__get_type_name(&g->naming_c99, &sequence_type, &sequence_type, generics);
    #line 120 "src/compiler/ExpressionWriter.pv"
    struct Expression* unary_inner = 0;

    #line 122 "src/compiler/ExpressionWriter.pv"
    switch (inner_expr->data.type) {
        #line 123 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 123 "src/compiler/ExpressionWriter.pv"
            struct str expr = inner_expr->data.unaryexpression_value._0;
            #line 123 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = inner_expr->data.unaryexpression_value._1;
            #line 124 "src/compiler/ExpressionWriter.pv"
            if (str__eq(expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 125 "src/compiler/ExpressionWriter.pv"
                unary_inner = inner;
            }
        } break;
        #line 128 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 131 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 132 "src/compiler/ExpressionWriter.pv"
    Generator__write_string(g, file, &name);
    #line 133 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .data = ");

    #line 135 "src/compiler/ExpressionWriter.pv"
    if (unary_inner != 0) {
        #line 136 "src/compiler/ExpressionWriter.pv"
        bool is_array_literal = false;
        #line 137 "src/compiler/ExpressionWriter.pv"
        switch (unary_inner->data.type) {
            #line 138 "src/compiler/ExpressionWriter.pv"
            case EXPRESSION_DATA__INVOKE: {
                #line 138 "src/compiler/ExpressionWriter.pv"
                struct Expression* target = unary_inner->data.invoke_value._0;
                #line 139 "src/compiler/ExpressionWriter.pv"
                switch (target->return_type.type) {
                    #line 140 "src/compiler/ExpressionWriter.pv"
                    case TYPE__SEQUENCE: {
                        #line 140 "src/compiler/ExpressionWriter.pv"
                        struct Sequence* seq = target->return_type.sequence_value;
                        #line 141 "src/compiler/ExpressionWriter.pv"
                        switch (seq->type.type) {
                            #line 142 "src/compiler/ExpressionWriter.pv"
                            case SEQUENCE_TYPE__FIXED_ARRAY: {
                                #line 142 "src/compiler/ExpressionWriter.pv"
                                is_array_literal = true;
                            } break;
                            #line 143 "src/compiler/ExpressionWriter.pv"
                            default: {
                            } break;
                        }
                    } break;
                    #line 146 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 149 "src/compiler/ExpressionWriter.pv"
            default: {
            } break;
        }

        #line 152 "src/compiler/ExpressionWriter.pv"
        if (is_array_literal) {
            #line 153 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 154 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(g, file, &sequence->element, generics);
            #line 155 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[])");
        }
        #line 157 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, unary_inner, generics);
    } else {
        #line 159 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "*");
        #line 160 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, inner_expr, generics);
    }

    #line 163 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ", .length = %zu }", length);
}

#line 166 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 167 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 168 "src/compiler/ExpressionWriter.pv"
    if (Generator__is_type_single_value_struct(g, type, generics)) {
        #line 169 "src/compiler/ExpressionWriter.pv"
        if (fields->length > 1) {
            #line 170 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (fields->length == 1) {
            #line 172 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = fields->data;
            #line 173 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
        } else {
            #line 175 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
        }
    } else {
        #line 178 "src/compiler/ExpressionWriter.pv"
        bool compact = (fields->length <= 1) || (fields->data[0].value->token->start_line == fields->data[fields->length - 1].value->token->start_line);

        #line 180 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 181 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(g, file, type, generics);

        #line 183 "src/compiler/ExpressionWriter.pv"
        if (fields->length == 0) {
            #line 184 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {}");
        } else {
            #line 186 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {");
            #line 187 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 187 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 190 "src/compiler/ExpressionWriter.pv"
        g->indent += 1;
        #line 191 "src/compiler/ExpressionWriter.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 191 "src/compiler/ExpressionWriter.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 191 "src/compiler/ExpressionWriter.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 191 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 192 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 193 "src/compiler/ExpressionWriter.pv"
                if (i > 0) {
                    #line 193 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", .");
                } else {
                    #line 194 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 196 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(g, file);
                #line 197 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".");
            }

            #line 200 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(g, file, field->name);
            #line 201 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 202 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
            #line 203 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 203 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 206 "src/compiler/ExpressionWriter.pv"
        g->indent -= 1;

        #line 208 "src/compiler/ExpressionWriter.pv"
        if (fields->length != 0) {
            #line 209 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 210 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 212 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(g, file);
                #line 213 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 218 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 221 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 222 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 223 "src/compiler/ExpressionWriter.pv"
    struct Enum* parent = variant->parent;

    #line 225 "src/compiler/ExpressionWriter.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 226 "src/compiler/ExpressionWriter.pv"
        Generator__write_enum_variant_name(g, file, type, variant);
        #line 227 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 230 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 231 "src/compiler/ExpressionWriter.pv"
    Generator__write_type(g, file, type, generics);
    #line 232 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .type = ");
    #line 233 "src/compiler/ExpressionWriter.pv"
    Generator__write_enum_variant_name(g, file, type, variant);

    #line 235 "src/compiler/ExpressionWriter.pv"
    if (arguments == 0) {
        #line 236 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
        #line 237 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 240 "src/compiler/ExpressionWriter.pv"
    if (arguments->length > 0) {
        #line 241 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", .");
        #line 242 "src/compiler/ExpressionWriter.pv"
        struct Token* name = variant->name;
        #line 243 "src/compiler/ExpressionWriter.pv"
        Generator__write_str_lowercase(g, file, name->value);
        #line 244 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "_value = ");
    }

    #line 247 "src/compiler/ExpressionWriter.pv"
    if (variant->names.length > 0) {
        #line 248 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");
        #line 249 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 250 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 250 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 250 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 251 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 251 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 251 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 252 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ".");
            #line 253 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(g, file, arg.name);
            #line 254 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 255 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
        } }
        #line 257 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
    } else if (arguments->length == 1) {
        #line 259 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 261 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");

        #line 263 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = 0;
        #line 264 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 264 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 264 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 265 "src/compiler/ExpressionWriter.pv"
            if (i > 0) {
                #line 265 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 266 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "._%zu = ", i);
            #line 267 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
            #line 268 "src/compiler/ExpressionWriter.pv"
            i += 1;
        } }

        #line 271 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 274 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
    #line 275 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 278 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 279 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 280 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 282 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 283 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 283 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 284 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 285 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 285 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 285 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 286 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, g->allocator, generics);

                    #line 288 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(struct ");
                    #line 289 "src/compiler/ExpressionWriter.pv"
                    Generator__write_function_name(g, file, func_info, &resolved_generics);
                    #line 290 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ") {");

                    #line 292 "src/compiler/ExpressionWriter.pv"
                    uintptr_t i = 0;
                    #line 293 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 293 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 293 "src/compiler/ExpressionWriter.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 294 "src/compiler/ExpressionWriter.pv"
                        if (i == 0) {
                            #line 294 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " .");
                        } else {
                            #line 295 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", .");
                        }

                        #line 297 "src/compiler/ExpressionWriter.pv"
                        Generator__write_token(g, file, param->name);
                        #line 298 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " = ");

                        #line 300 "src/compiler/ExpressionWriter.pv"
                        if (i < arguments->length) {
                            #line 301 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 303 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "0");
                        }

                        #line 306 "src/compiler/ExpressionWriter.pv"
                        i += 1;
                    } }

                    #line 309 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " }");
                    #line 310 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
                #line 312 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 315 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 318 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 319 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 322 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 323 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 324 "src/compiler/ExpressionWriter.pv"
    struct str name = func_info->name->value;

    #line 326 "src/compiler/ExpressionWriter.pv"
    if (str__eq(name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 327 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, g->allocator, generics);
        #line 328 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 329 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 329 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 330 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typeid(g, file, type, generics);
    }

    #line 333 "src/compiler/ExpressionWriter.pv"
    if (str__eq(name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 334 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, g->allocator, generics);
        #line 335 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 336 "src/compiler/ExpressionWriter.pv"
        if (arg == 0) {
            #line 336 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 337 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 338 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 338 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 339 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 340 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(g, file, type, generics);
        #line 341 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")(");
        #line 342 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
        #line 343 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
        #line 344 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 347 "src/compiler/ExpressionWriter.pv"
    Generator__write_token(g, file, func_info->name);
    #line 348 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 349 "src/compiler/ExpressionWriter.pv"
    bool first = true;
    #line 350 "src/compiler/ExpressionWriter.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 350 "src/compiler/ExpressionWriter.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 350 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 351 "src/compiler/ExpressionWriter.pv"
        if (first) {
            #line 351 "src/compiler/ExpressionWriter.pv"
            first = false;
        } else {
            #line 351 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", ");
        }
        #line 352 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
    } }
    #line 354 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ")");
    #line 355 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 358 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 359 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 360 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;
    #line 361 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 362 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 362 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 363 "src/compiler/ExpressionWriter.pv"
            bool success = Generator__write_str(g, file, name);
            #line 364 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 365 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 366 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 366 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 366 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 367 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 367 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 367 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 368 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 370 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 371 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 373 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 374 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 375 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 376 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 377 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 377 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 377 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 378 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 378 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 378 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 379 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 381 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 382 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 384 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 385 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 386 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 387 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 388 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 388 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 388 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 389 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 389 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 389 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 390 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 392 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 393 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 395 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 395 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 396 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 398 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 398 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 399 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 400 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 400 "src/compiler/ExpressionWriter.pv"
                    type = generics->self_type;
                } break;
                #line 401 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 404 "src/compiler/ExpressionWriter.pv"
            switch (Type__resolve_typedef(type)->type) {
                #line 405 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 406 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 408 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT_C: {
                    #line 409 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 411 "src/compiler/ExpressionWriter.pv"
                case TYPE__UNION_C: {
                    #line 412 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 414 "src/compiler/ExpressionWriter.pv"
                case TYPE__TUPLE: {
                    #line 415 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 417 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 417 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = Type__resolve_typedef(type)->function_value._0;
                    #line 417 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(type)->function_value._1;
                    #line 418 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->type) {
                        #line 419 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 420 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 422 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 423 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 425 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }

                    #line 428 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name->value;
                    #line 429 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, g->allocator, generics);
                    #line 430 "src/compiler/ExpressionWriter.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 431 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 432 "src/compiler/ExpressionWriter.pv"
                    bool first = true;

                    #line 434 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 435 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 435 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 436 "src/compiler/ExpressionWriter.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 437 "src/compiler/ExpressionWriter.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 438 "src/compiler/ExpressionWriter.pv"
                                return false;
                            }

                            #line 441 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 443 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 444 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 445 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".vtable->");
                                #line 446 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(g, file, name) && success;
                                #line 447 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 448 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 449 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".instance");
                                #line 450 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 452 "src/compiler/ExpressionWriter.pv"
                                struct String parent_name = Naming__get_type_name(&g->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                #line 453 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(g, file, String__as_str(&parent_name)) && success;
                                #line 454 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 455 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(g, file, trait_info->name->value) && success;
                                #line 456 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 457 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(g, file, func_info->name->value) && success;
                                #line 458 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 459 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 460 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            }
                        } break;
                        #line 463 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 464 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_function_name(g, file, func_info, &resolved_generics) && success;
                            #line 465 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 469 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 469 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 469 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 470 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 470 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 470 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 471 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }

                    #line 474 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 475 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 477 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION_C: {
                    #line 477 "src/compiler/ExpressionWriter.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(type)->functionc_value;
                    #line 478 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name;
                    #line 479 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_str(g, file, name);
                    #line 480 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 481 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 482 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 482 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 482 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 483 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 483 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 483 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 484 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }
                    #line 486 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 487 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 489 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 489 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = Type__resolve_typedef(type)->sequence_value;
                    #line 490 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 491 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 492 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 493 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "{");
                            #line 494 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 495 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 495 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 495 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 496 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 496 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 496 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 497 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 499 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "}");
                        } break;
                        #line 501 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 502 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 503 "src/compiler/ExpressionWriter.pv"
                            Generator__write_type(g, file, &expression->return_type, generics);
                            #line 504 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ") {");
                            #line 505 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 506 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 506 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 506 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 507 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 507 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                    #line 507 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 507 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", .");
                                }
                                #line 508 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(g, file, arg->name->value) && success;
                                #line 509 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " = ");
                                #line 510 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 512 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " }");
                        } break;
                    }
                    #line 515 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 517 "src/compiler/ExpressionWriter.pv"
                case TYPE__CLASS_CPP: {
                    #line 518 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_type(g, file, type, generics);
                    #line 519 "src/compiler/ExpressionWriter.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 521 "src/compiler/ExpressionWriter.pv"
                    if (function_mode) {
                        #line 522 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "(");
                        #line 523 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 524 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 524 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 524 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 525 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 525 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 525 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 526 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 528 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    } else {
                        #line 530 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " {");
                        #line 531 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 532 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 532 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 532 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 533 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 533 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 533 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " .");
                            } else {
                                #line 533 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", .");
                            }
                            #line 534 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_str(g, file, arg->name->value) && success;
                            #line 535 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " = ");
                            #line 536 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 538 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " }");
                    }
                    #line 540 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 542 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 543 "src/compiler/ExpressionWriter.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 544 "src/compiler/ExpressionWriter.pv"
                    return false;
                } break;
            }
        } break;
        #line 548 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 551 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 552 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 555 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 556 "src/compiler/ExpressionWriter.pv"
    struct Generator* g = self->generator;
    #line 557 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 559 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 560 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 560 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 561 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(g, file, name);
            #line 562 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 564 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 564 "src/compiler/ExpressionWriter.pv"
            struct str value = data->literal_value;
            #line 565 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(g, file, &expression->return_type, value);
            #line 566 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 568 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 569 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 570 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 572 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 572 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = data->invoke_value._0;
            #line 572 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 573 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 575 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 575 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 576 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 578 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 578 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 578 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 579 "src/compiler/ExpressionWriter.pv"
            bool skip_operator = str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 580 "src/compiler/ExpressionWriter.pv"
            if (skip_operator) {
                #line 581 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, inner, generics);
                #line 582 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 585 "src/compiler/ExpressionWriter.pv"
            if (str__eq(operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 586 "src/compiler/ExpressionWriter.pv"
                bool is_rvalue = false;
                #line 587 "src/compiler/ExpressionWriter.pv"
                switch (inner->data.type) {
                    #line 588 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__INVOKE: {
                        #line 588 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 589 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 589 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 590 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__BINARY_EXPRESSION: {
                        #line 590 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 591 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 594 "src/compiler/ExpressionWriter.pv"
                if (is_rvalue) {
                    #line 597 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 598 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(g, file, &inner->return_type, generics);
                    #line 599 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "[]){");
                    #line 600 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner, generics);
                    #line 601 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "}");
                    #line 602 "src/compiler/ExpressionWriter.pv"
                    return true;
                }
            }

            #line 606 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(g, file, operator);
            #line 607 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner, generics);
            #line 608 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 610 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 610 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 610 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 610 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 611 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, left, generics);
            #line 612 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ");
            #line 613 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(g, file, operator);
            #line 614 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ");
            #line 615 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, right, generics);
            #line 616 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 618 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 618 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 618 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 618 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 619 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, cond, generics);
            #line 620 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ? ");
            #line 621 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, a, generics);
            #line 622 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " : ");
            #line 623 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, b, generics);
            #line 624 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 626 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 626 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 626 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 627 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 628 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 629 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 629 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = parent_type->struct_value._0;
                    #line 630 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 630 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 630 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 631 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 632 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 633 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&g->naming_ident, parent_type, parent_type, generics);
                            #line 634 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(g, file, String__as_str(&parent_name));
                            #line 635 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 636 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(g, file, member);
                            #line 637 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 641 "src/compiler/ExpressionWriter.pv"
                case TYPE__ENUM: {
                    #line 641 "src/compiler/ExpressionWriter.pv"
                    struct Enum* enum_info = parent_type->enum_value._0;
                    #line 642 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 642 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 642 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 643 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 644 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 645 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&g->naming_ident, parent_type, parent_type, generics);
                            #line 646 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(g, file, String__as_str(&parent_name));
                            #line 647 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 648 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(g, file, member);
                            #line 649 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 653 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 655 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, parent, generics);
            #line 656 "src/compiler/ExpressionWriter.pv"
            Generator__write_static_member_accessor(g, file, generics);
            #line 657 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(g, file, member);
            #line 658 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 660 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 660 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 660 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 661 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;

            #line 663 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(g, parent_type, generics)) {
                #line 664 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 665 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 665 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 666 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, parent, generics);
                #line 667 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 667 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 668 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 671 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 672 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 672 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 673 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 674 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 674 "src/compiler/ExpressionWriter.pv"
                            uintptr_t length = sequence->type.fixedarray_value;
                            #line 675 "src/compiler/ExpressionWriter.pv"
                            if (str__eq(member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 676 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "%zu", length);
                            } else {
                                #line 678 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 679 "src/compiler/ExpressionWriter.pv"
                                Generator__write_str(g, file, member);
                                #line 680 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 683 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 684 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "!!ERROR TODO MEMBERS FOR DYNAMIC SEQUENCES!!");
                        } break;
                    }
                } break;
                #line 688 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 689 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, parent, generics);
                    #line 690 "src/compiler/ExpressionWriter.pv"
                    Generator__write_instance_member_accessor(g, file, &parent->return_type, generics);
                    #line 691 "src/compiler/ExpressionWriter.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 691 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "_");
                    }
                    #line 692 "src/compiler/ExpressionWriter.pv"
                    Generator__write_str(g, file, member);
                } break;
            }

            #line 696 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 698 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 698 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 699 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(g, file, type, generics);
            #line 700 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 702 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 702 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 702 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 703 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, array_expr, generics);
            #line 704 "src/compiler/ExpressionWriter.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 705 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".data");
            }
            #line 707 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[");
            #line 708 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, index_expr, generics);
            #line 709 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "]");
            #line 710 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 712 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 712 "src/compiler/ExpressionWriter.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 713 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 714 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expr, generics);
            #line 715 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 716 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 718 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 718 "src/compiler/ExpressionWriter.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 719 "src/compiler/ExpressionWriter.pv"
            switch (cpp_expression.type) {
                #line 720 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 720 "src/compiler/ExpressionWriter.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 720 "src/compiler/ExpressionWriter.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 721 "src/compiler/ExpressionWriter.pv"
                    if (placement != 0) {
                        #line 722 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new(");
                        #line 723 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_expression(self, file, placement, generics);
                        #line 724 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 726 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new ");
                    }
                    #line 728 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, new_expression, generics);
                } break;
                #line 730 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 730 "src/compiler/ExpressionWriter.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 731 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "delete ");
                    #line 732 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, delete_expression, generics);
                } break;
            }
            #line 735 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 737 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 737 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 738 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 739 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 739 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 740 "src/compiler/ExpressionWriter.pv"
                    if (str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 741 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 744 "src/compiler/ExpressionWriter.pv"
                case TYPE__INDIRECT: {
                    #line 744 "src/compiler/ExpressionWriter.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 745 "src/compiler/ExpressionWriter.pv"
                    switch (indirect->to.type) {
                        #line 746 "src/compiler/ExpressionWriter.pv"
                        case TYPE__STRUCT: {
                            #line 746 "src/compiler/ExpressionWriter.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 747 "src/compiler/ExpressionWriter.pv"
                            if (str__eq(struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 748 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 750 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 753 "src/compiler/ExpressionWriter.pv"
                        case TYPE__SEQUENCE: {
                            #line 753 "src/compiler/ExpressionWriter.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 753 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 754 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 754 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 757 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 757 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 762 "src/compiler/ExpressionWriter.pv"
    return false;
}
