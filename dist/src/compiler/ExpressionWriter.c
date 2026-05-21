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
    struct Generator* generator = self->generator;
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
                        Generator__write_str_title(generator, file, struct_info->name->value);
                        #line 37 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "__");
                    } break;
                    #line 39 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 42 "src/compiler/ExpressionWriter.pv"
                Generator__write_str_title(generator, file, func_info->name->value);
                #line 43 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__CO, .instance = &(struct ");
                #line 44 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
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
                        Generator__write_str_title(generator, file, struct_info->name->value);
                        #line 53 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "__");
                    } break;
                    #line 55 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 58 "src/compiler/ExpressionWriter.pv"
                Generator__write_str_title(generator, file, func_info->name->value);
                #line 59 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "__VTABLE__DYN_FN, .instance = &(struct ");
                #line 60 "src/compiler/ExpressionWriter.pv"
                Generator__write_function_name(generator, file, func_info, func_generics);
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
            Generator__write_type(generator, file, type, generics);
            #line 74 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") { .vtable = &");

            #line 76 "src/compiler/ExpressionWriter.pv"
            struct Type* inner_type = Context__resolve_type(generator->allocator, Type__deref(&inner_expr->return_type), generics, 0);
            #line 77 "src/compiler/ExpressionWriter.pv"
            struct String inner_type_name = Naming__get_type_name(&generator->naming_ident, inner_type, generics->array.data, generics);
            #line 78 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&inner_type_name));

            #line 80 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "__VTABLE__");
            #line 81 "src/compiler/ExpressionWriter.pv"
            Generator__write_str_title(generator, file, trait_info->name->value);
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
    struct Generator* generator = self->generator;
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
    struct Expression* length_expr = 0;
    #line 110 "src/compiler/ExpressionWriter.pv"
    switch (inner_sequence->type.type) {
        #line 111 "src/compiler/ExpressionWriter.pv"
        case SEQUENCE_TYPE__FIXED_ARRAY: {
            #line 111 "src/compiler/ExpressionWriter.pv"
            struct Expression* seq_length = inner_sequence->type.fixedarray_value;
            #line 111 "src/compiler/ExpressionWriter.pv"
            length_expr = seq_length;
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
    struct String name = Naming__get_type_name(&generator->naming_c99, &sequence_type, &sequence_type, generics);
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
            if (str__Eq_str__eq(&expr, (struct str){ .ptr = "&", .length = strlen("&") })) {
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
    Generator__write_string(generator, file, &name);
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
            Generator__write_type(generator, file, &sequence->element, generics);
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
    fprintf(file, ", .length = ");
    #line 164 "src/compiler/ExpressionWriter.pv"
    ExpressionWriter__write_expression(self, file, length_expr, generics);
    #line 165 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
}

#line 168 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_struct_construction(struct ExpressionWriter* self, FILE* file, struct Type* type, struct Array_InvokeArgument* fields, struct GenericMap* generics) {
    #line 169 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 170 "src/compiler/ExpressionWriter.pv"
    if (Generator__is_type_single_value_struct(generator, type, generics)) {
        #line 171 "src/compiler/ExpressionWriter.pv"
        if (fields->length > 1) {
            #line 172 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "expected a single field as a value into this struct");
        } else if (fields->length == 1) {
            #line 174 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = fields->data;
            #line 175 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
        } else {
            #line 177 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
        }
    } else {
        #line 180 "src/compiler/ExpressionWriter.pv"
        bool compact = (fields->length <= 1) || (fields->data[0].value->token->start_line == fields->data[fields->length - 1].value->token->start_line);

        #line 182 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 183 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);

        #line 185 "src/compiler/ExpressionWriter.pv"
        if (fields->length == 0) {
            #line 186 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {}");
        } else {
            #line 188 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ") {");
            #line 189 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 189 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "\n");
            }
        }

        #line 192 "src/compiler/ExpressionWriter.pv"
        generator->indent += 1;
        #line 193 "src/compiler/ExpressionWriter.pv"
        { struct IterEnumerate_ref_InvokeArgument __iter = Iter_ref_InvokeArgument__enumerate(Array_InvokeArgument__iter(fields));
        #line 193 "src/compiler/ExpressionWriter.pv"
        while (IterEnumerate_ref_InvokeArgument__next(&__iter)) {
            #line 193 "src/compiler/ExpressionWriter.pv"
            uintptr_t i = IterEnumerate_ref_InvokeArgument__value(&__iter)._0;
            #line 193 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument* field = IterEnumerate_ref_InvokeArgument__value(&__iter)._1;

            #line 194 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 195 "src/compiler/ExpressionWriter.pv"
                if (i > 0) {
                    #line 195 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", .");
                } else {
                    #line 196 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " .");
                }
            } else {
                #line 198 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 199 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".");
            }

            #line 202 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, field->name);
            #line 203 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 204 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, field->value, generics);
            #line 205 "src/compiler/ExpressionWriter.pv"
            if (!compact) {
                #line 205 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ",\n");
            }
        } }

        #line 208 "src/compiler/ExpressionWriter.pv"
        generator->indent -= 1;

        #line 210 "src/compiler/ExpressionWriter.pv"
        if (fields->length != 0) {
            #line 211 "src/compiler/ExpressionWriter.pv"
            if (compact) {
                #line 212 "src/compiler/ExpressionWriter.pv"
                fprintf(file, " }");
            } else {
                #line 214 "src/compiler/ExpressionWriter.pv"
                Generator__write_indent(generator, file);
                #line 215 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "}");
            }
        }
    }

    #line 220 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 223 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_enum_variant(struct ExpressionWriter* self, FILE* file, struct EnumVariant* variant, struct Type* type, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 224 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 225 "src/compiler/ExpressionWriter.pv"
    struct Enum* parent = variant->parent;

    #line 227 "src/compiler/ExpressionWriter.pv"
    if (!Enum__is_discriminated_union(parent)) {
        #line 228 "src/compiler/ExpressionWriter.pv"
        Generator__write_enum_variant_name(generator, file, type, variant);
        #line 229 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 232 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 233 "src/compiler/ExpressionWriter.pv"
    Generator__write_type(generator, file, type, generics);
    #line 234 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ") { .type = ");
    #line 235 "src/compiler/ExpressionWriter.pv"
    Generator__write_enum_variant_name(generator, file, type, variant);

    #line 237 "src/compiler/ExpressionWriter.pv"
    if (arguments == 0) {
        #line 238 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
        #line 239 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 242 "src/compiler/ExpressionWriter.pv"
    if (arguments->length > 0) {
        #line 243 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ", .");
        #line 244 "src/compiler/ExpressionWriter.pv"
        struct Token* name = variant->name;
        #line 245 "src/compiler/ExpressionWriter.pv"
        Generator__write_str_lowercase(generator, file, name->value);
        #line 246 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "_value = ");
    }

    #line 249 "src/compiler/ExpressionWriter.pv"
    if (variant->names.length > 0) {
        #line 250 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");
        #line 251 "src/compiler/ExpressionWriter.pv"
        bool first = true;
        #line 252 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 252 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 252 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 253 "src/compiler/ExpressionWriter.pv"
            if (first) {
                #line 253 "src/compiler/ExpressionWriter.pv"
                first = false;
            } else {
                #line 253 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 254 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ".");
            #line 255 "src/compiler/ExpressionWriter.pv"
            Generator__write_token(generator, file, arg.name);
            #line 256 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " = ");
            #line 257 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
        } }
        #line 259 "src/compiler/ExpressionWriter.pv"
        fprintf(file, " }");
    } else if (arguments->length == 1) {
        #line 261 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arguments->data[0].value, generics);
    } else if (arguments->length > 1) {
        #line 263 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "{ ");

        #line 265 "src/compiler/ExpressionWriter.pv"
        uintptr_t i = 0;
        #line 266 "src/compiler/ExpressionWriter.pv"
        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
        #line 266 "src/compiler/ExpressionWriter.pv"
        while (Iter_ref_InvokeArgument__next(&__iter)) {
            #line 266 "src/compiler/ExpressionWriter.pv"
            struct InvokeArgument arg = *Iter_ref_InvokeArgument__value(&__iter);

            #line 267 "src/compiler/ExpressionWriter.pv"
            if (i > 0) {
                #line 267 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ", ");
            }
            #line 268 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "._%zu = ", i);
            #line 269 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, arg.value, generics);
            #line 270 "src/compiler/ExpressionWriter.pv"
            i += 1;
        } }

        #line 273 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "}");
    }

    #line 276 "src/compiler/ExpressionWriter.pv"
    fprintf(file, " }");
    #line 277 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 280 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_coroutine_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 281 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 282 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 284 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 285 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 285 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 286 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 287 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 287 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = type->function_value._0;
                    #line 287 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = type->function_value._1;
                    #line 288 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, generator->allocator, generics);

                    #line 290 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(struct ");
                    #line 291 "src/compiler/ExpressionWriter.pv"
                    Generator__write_function_name(generator, file, func_info, &resolved_generics);
                    #line 292 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ") {");

                    #line 294 "src/compiler/ExpressionWriter.pv"
                    uintptr_t i = 0;
                    #line 295 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                    #line 295 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_Parameter__next(&__iter)) {
                        #line 295 "src/compiler/ExpressionWriter.pv"
                        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                        #line 296 "src/compiler/ExpressionWriter.pv"
                        if (i == 0) {
                            #line 296 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " .");
                        } else {
                            #line 297 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", .");
                        }

                        #line 299 "src/compiler/ExpressionWriter.pv"
                        Generator__write_token(generator, file, param->name);
                        #line 300 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " = ");

                        #line 302 "src/compiler/ExpressionWriter.pv"
                        if (i < arguments->length) {
                            #line 303 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_expression(self, file, arguments->data[i].value, generics);
                        } else {
                            #line 305 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "0");
                        }

                        #line 308 "src/compiler/ExpressionWriter.pv"
                        i += 1;
                    } }

                    #line 311 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, " }");
                    #line 312 "src/compiler/ExpressionWriter.pv"
                    return true;
                } break;
                #line 314 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
        } break;
        #line 317 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 320 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "coroutine invoke unsupported expression\n");
    #line 321 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 324 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_builtin_function_invoke(struct ExpressionWriter* self, FILE* file, struct Function* func_info, struct Array_InvokeArgument* arguments, struct GenericMap* func_generics, struct GenericMap* generics) {
    #line 325 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 326 "src/compiler/ExpressionWriter.pv"
    struct str name = func_info->name->value;

    #line 328 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "typeid", .length = strlen("typeid") })) {
        #line 329 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 330 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 331 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 331 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 332 "src/compiler/ExpressionWriter.pv"
        return Generator__write_typeid(generator, file, type, generics);
    }

    #line 335 "src/compiler/ExpressionWriter.pv"
    if (str__Eq_str__eq(&name, (struct str){ .ptr = "cast", .length = strlen("cast") })) {
        #line 336 "src/compiler/ExpressionWriter.pv"
        struct GenericMap resolved_generics = GenericMap__resolve_types(func_generics, generator->allocator, generics);
        #line 337 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Array_InvokeArgument__get(arguments, 0);
        #line 338 "src/compiler/ExpressionWriter.pv"
        if (arg == 0) {
            #line 338 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 339 "src/compiler/ExpressionWriter.pv"
        struct Type* type = GenericMap__get(&resolved_generics, (struct str){ .ptr = "T", .length = strlen("T") });
        #line 340 "src/compiler/ExpressionWriter.pv"
        if (type == 0) {
            #line 340 "src/compiler/ExpressionWriter.pv"
            return false;
        }
        #line 341 "src/compiler/ExpressionWriter.pv"
        fprintf(file, "(");
        #line 342 "src/compiler/ExpressionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 343 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")(");
        #line 344 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
        #line 345 "src/compiler/ExpressionWriter.pv"
        fprintf(file, ")");
        #line 346 "src/compiler/ExpressionWriter.pv"
        return true;
    }

    #line 349 "src/compiler/ExpressionWriter.pv"
    Generator__write_token(generator, file, func_info->name);
    #line 350 "src/compiler/ExpressionWriter.pv"
    fprintf(file, "(");
    #line 351 "src/compiler/ExpressionWriter.pv"
    bool first = true;
    #line 352 "src/compiler/ExpressionWriter.pv"
    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
    #line 352 "src/compiler/ExpressionWriter.pv"
    while (Iter_ref_InvokeArgument__next(&__iter)) {
        #line 352 "src/compiler/ExpressionWriter.pv"
        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

        #line 353 "src/compiler/ExpressionWriter.pv"
        if (first) {
            #line 353 "src/compiler/ExpressionWriter.pv"
            first = false;
        } else {
            #line 353 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ", ");
        }
        #line 354 "src/compiler/ExpressionWriter.pv"
        ExpressionWriter__write_expression(self, file, arg->value, generics);
    } }
    #line 356 "src/compiler/ExpressionWriter.pv"
    fprintf(file, ")");
    #line 357 "src/compiler/ExpressionWriter.pv"
    return true;
}

#line 360 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_invoke(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct Array_InvokeArgument* arguments, struct GenericMap* generics) {
    #line 361 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 362 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;
    #line 363 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 364 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 364 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 365 "src/compiler/ExpressionWriter.pv"
            bool success = Generator__write_str(generator, file, name);
            #line 366 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 367 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 368 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 368 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 368 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 369 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 369 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 369 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 370 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 372 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 373 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 375 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 376 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 377 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 378 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 379 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 379 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 379 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 380 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 380 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 380 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 381 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 383 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 384 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 386 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 387 "src/compiler/ExpressionWriter.pv"
            bool success = ExpressionWriter__write_expression(self, file, expression, generics);
            #line 388 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 389 "src/compiler/ExpressionWriter.pv"
            bool first = true;
            #line 390 "src/compiler/ExpressionWriter.pv"
            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
            #line 390 "src/compiler/ExpressionWriter.pv"
            while (Iter_ref_InvokeArgument__next(&__iter)) {
                #line 390 "src/compiler/ExpressionWriter.pv"
                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                #line 391 "src/compiler/ExpressionWriter.pv"
                if (first) {
                    #line 391 "src/compiler/ExpressionWriter.pv"
                    first = false;
                } else {
                    #line 391 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ", ");
                }
                #line 392 "src/compiler/ExpressionWriter.pv"
                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
            } }
            #line 394 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 395 "src/compiler/ExpressionWriter.pv"
            return success;
        } break;
        #line 397 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 397 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 398 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, arguments, generics);
        } break;
        #line 400 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 400 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 401 "src/compiler/ExpressionWriter.pv"
            switch (type->type) {
                #line 402 "src/compiler/ExpressionWriter.pv"
                case TYPE__SELF: {
                    #line 402 "src/compiler/ExpressionWriter.pv"
                    type = generics->self_type;
                } break;
                #line 403 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }

            #line 406 "src/compiler/ExpressionWriter.pv"
            switch (Type__resolve_typedef(type)->type) {
                #line 407 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 408 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 410 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT_C: {
                    #line 411 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 413 "src/compiler/ExpressionWriter.pv"
                case TYPE__UNION_C: {
                    #line 414 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 416 "src/compiler/ExpressionWriter.pv"
                case TYPE__TUPLE: {
                    #line 417 "src/compiler/ExpressionWriter.pv"
                    return ExpressionWriter__write_struct_construction(self, file, type, arguments, generics);
                } break;
                #line 419 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION: {
                    #line 419 "src/compiler/ExpressionWriter.pv"
                    struct Function* func_info = Type__resolve_typedef(type)->function_value._0;
                    #line 419 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap* generic_map = Type__resolve_typedef(type)->function_value._1;
                    #line 420 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->type) {
                        #line 421 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__COROUTINE: {
                            #line 422 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_coroutine_invoke(self, file, expression, arguments, generics);
                        } break;
                        #line 424 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_TYPE__BUILTIN: {
                            #line 425 "src/compiler/ExpressionWriter.pv"
                            return ExpressionWriter__write_builtin_function_invoke(self, file, func_info, arguments, generic_map, generics);
                        } break;
                        #line 427 "src/compiler/ExpressionWriter.pv"
                        default: {
                        } break;
                    }

                    #line 430 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name->value;
                    #line 431 "src/compiler/ExpressionWriter.pv"
                    struct GenericMap resolved_generics = GenericMap__resolve_types(generic_map, generator->allocator, generics);
                    #line 432 "src/compiler/ExpressionWriter.pv"
                    struct Iter_ref_InvokeArgument args = Array_InvokeArgument__iter(arguments);
                    #line 433 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 434 "src/compiler/ExpressionWriter.pv"
                    bool first = true;

                    #line 436 "src/compiler/ExpressionWriter.pv"
                    switch (func_info->parent.type) {
                        #line 437 "src/compiler/ExpressionWriter.pv"
                        case FUNCTION_PARENT__TRAIT: {
                            #line 437 "src/compiler/ExpressionWriter.pv"
                            struct Trait* trait_info = func_info->parent.trait_value;
                            #line 438 "src/compiler/ExpressionWriter.pv"
                            if (!Iter_ref_InvokeArgument__next(&args)) {
                                #line 439 "src/compiler/ExpressionWriter.pv"
                                fprintf(stderr, "Trait function call missing instance argument\n");
                                #line 440 "src/compiler/ExpressionWriter.pv"
                                return false;
                            }

                            #line 443 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&args);

                            #line 445 "src/compiler/ExpressionWriter.pv"
                            if (Type__is_trait(Type__deref(&arg->value->return_type))) {
                                #line 446 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 447 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".vtable->fn_");
                                #line 448 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, name) && success;
                                #line 449 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 450 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 451 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ".instance");
                                #line 452 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 454 "src/compiler/ExpressionWriter.pv"
                                struct String parent_name = Naming__get_type_name(&generator->naming_ident, Type__deref(&arg->value->return_type), generics->self_type, generics);
                                #line 455 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, String__as_str(&parent_name)) && success;
                                #line 456 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 457 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, trait_info->name->value) && success;
                                #line 458 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "__");
                                #line 459 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, func_info->name->value) && success;
                                #line 460 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "(");
                                #line 461 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                                #line 462 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            }
                        } break;
                        #line 465 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 466 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_function_name(generator, file, func_info, &resolved_generics) && success;
                            #line 467 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                        } break;
                    }

                    #line 471 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = args;
                    #line 471 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 471 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 472 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 472 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 472 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 473 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }

                    #line 476 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 477 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 479 "src/compiler/ExpressionWriter.pv"
                case TYPE__FUNCTION_C: {
                    #line 479 "src/compiler/ExpressionWriter.pv"
                    struct FunctionC* func_info = Type__resolve_typedef(type)->functionc_value;
                    #line 480 "src/compiler/ExpressionWriter.pv"
                    struct str name = func_info->name;
                    #line 481 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_str(generator, file, name);
                    #line 482 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 483 "src/compiler/ExpressionWriter.pv"
                    bool first = true;
                    #line 484 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                    #line 484 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_InvokeArgument__next(&__iter)) {
                        #line 484 "src/compiler/ExpressionWriter.pv"
                        struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                        #line 485 "src/compiler/ExpressionWriter.pv"
                        if (first) {
                            #line 485 "src/compiler/ExpressionWriter.pv"
                            first = false;
                        } else {
                            #line 485 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ", ");
                        }
                        #line 486 "src/compiler/ExpressionWriter.pv"
                        success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                    } }
                    #line 488 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                    #line 489 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 491 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 491 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = Type__resolve_typedef(type)->sequence_value;
                    #line 492 "src/compiler/ExpressionWriter.pv"
                    bool success = true;
                    #line 493 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 494 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 495 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "{");
                            #line 496 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 497 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 497 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 497 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 498 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 498 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                } else {
                                    #line 498 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 499 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 501 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "}");
                        } break;
                        #line 503 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 504 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "(");
                            #line 505 "src/compiler/ExpressionWriter.pv"
                            Generator__write_type(generator, file, &expression->return_type, generics);
                            #line 506 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, ") {");
                            #line 507 "src/compiler/ExpressionWriter.pv"
                            bool first = true;
                            #line 508 "src/compiler/ExpressionWriter.pv"
                            { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                            #line 508 "src/compiler/ExpressionWriter.pv"
                            while (Iter_ref_InvokeArgument__next(&__iter)) {
                                #line 508 "src/compiler/ExpressionWriter.pv"
                                struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                                #line 509 "src/compiler/ExpressionWriter.pv"
                                if (first) {
                                    #line 509 "src/compiler/ExpressionWriter.pv"
                                    first = false;
                                    #line 509 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, " .");
                                } else {
                                    #line 509 "src/compiler/ExpressionWriter.pv"
                                    fprintf(file, ", .");
                                }
                                #line 510 "src/compiler/ExpressionWriter.pv"
                                success = Generator__write_str(generator, file, arg->name->value) && success;
                                #line 511 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " = ");
                                #line 512 "src/compiler/ExpressionWriter.pv"
                                success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                            } }
                            #line 514 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " }");
                        } break;
                    }
                    #line 517 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 519 "src/compiler/ExpressionWriter.pv"
                case TYPE__CLASS_CPP: {
                    #line 520 "src/compiler/ExpressionWriter.pv"
                    bool success = Generator__write_type(generator, file, type, generics);
                    #line 521 "src/compiler/ExpressionWriter.pv"
                    bool function_mode = (arguments->length > 0) && (arguments->data[0].name == 0);

                    #line 523 "src/compiler/ExpressionWriter.pv"
                    if (function_mode) {
                        #line 524 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "(");
                        #line 525 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 526 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 526 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 526 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 527 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 527 "src/compiler/ExpressionWriter.pv"
                                first = false;
                            } else {
                                #line 527 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 528 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 530 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ")");
                    } else {
                        #line 532 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " {");
                        #line 533 "src/compiler/ExpressionWriter.pv"
                        bool first = true;
                        #line 534 "src/compiler/ExpressionWriter.pv"
                        { struct Iter_ref_InvokeArgument __iter = Array_InvokeArgument__iter(arguments);
                        #line 534 "src/compiler/ExpressionWriter.pv"
                        while (Iter_ref_InvokeArgument__next(&__iter)) {
                            #line 534 "src/compiler/ExpressionWriter.pv"
                            struct InvokeArgument* arg = Iter_ref_InvokeArgument__value(&__iter);

                            #line 535 "src/compiler/ExpressionWriter.pv"
                            if (first) {
                                #line 535 "src/compiler/ExpressionWriter.pv"
                                first = false;
                                #line 535 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, " .");
                            } else {
                                #line 535 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, ", .");
                            }
                            #line 536 "src/compiler/ExpressionWriter.pv"
                            success = Generator__write_str(generator, file, arg->name->value) && success;
                            #line 537 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, " = ");
                            #line 538 "src/compiler/ExpressionWriter.pv"
                            success = ExpressionWriter__write_expression(self, file, arg->value, generics) && success;
                        } }
                        #line 540 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, " }");
                    }
                    #line 542 "src/compiler/ExpressionWriter.pv"
                    return success;
                } break;
                #line 544 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 545 "src/compiler/ExpressionWriter.pv"
                    fprintf(stderr, "Invoke unsupported expression type\n");
                    #line 546 "src/compiler/ExpressionWriter.pv"
                    return false;
                } break;
            }
        } break;
        #line 550 "src/compiler/ExpressionWriter.pv"
        default: {
        } break;
    }

    #line 553 "src/compiler/ExpressionWriter.pv"
    fprintf(stderr, "Invoke unsupported expression\n");
    #line 554 "src/compiler/ExpressionWriter.pv"
    return false;
}

#line 557 "src/compiler/ExpressionWriter.pv"
bool ExpressionWriter__write_expression(struct ExpressionWriter* self, FILE* file, struct Expression* expression, struct GenericMap* generics) {
    #line 558 "src/compiler/ExpressionWriter.pv"
    struct Generator* generator = self->generator;
    #line 559 "src/compiler/ExpressionWriter.pv"
    struct ExpressionData* data = &expression->data;

    #line 561 "src/compiler/ExpressionWriter.pv"
    switch (data->type) {
        #line 562 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__VARIABLE: {
            #line 562 "src/compiler/ExpressionWriter.pv"
            struct str name = data->variable_value;
            #line 563 "src/compiler/ExpressionWriter.pv"
            Generator__write_variable(generator, file, name);
            #line 564 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 566 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__LITERAL: {
            #line 566 "src/compiler/ExpressionWriter.pv"
            struct str value = data->literal_value;
            #line 567 "src/compiler/ExpressionWriter.pv"
            Generator__write_literal(generator, file, &expression->return_type, value);
            #line 568 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 570 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__NULL_LITERAL: {
            #line 571 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "0");
            #line 572 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 574 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INVOKE: {
            #line 574 "src/compiler/ExpressionWriter.pv"
            struct Expression* target = data->invoke_value._0;
            #line 574 "src/compiler/ExpressionWriter.pv"
            struct Array_InvokeArgument* arguments = &data->invoke_value._1;
            #line 575 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_invoke(self, file, target, arguments, generics);
        } break;
        #line 577 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__ENUM_VARIANT: {
            #line 577 "src/compiler/ExpressionWriter.pv"
            struct EnumVariant* variant = data->enumvariant_value;
            #line 578 "src/compiler/ExpressionWriter.pv"
            return ExpressionWriter__write_enum_variant(self, file, variant, &expression->return_type, 0, generics);
        } break;
        #line 580 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__UNARY_EXPRESSION: {
            #line 580 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->unaryexpression_value._0;
            #line 580 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner = data->unaryexpression_value._1;
            #line 581 "src/compiler/ExpressionWriter.pv"
            bool skip_operator = str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") }) && Type__is_fat_pointer(&expression->return_type);
            #line 582 "src/compiler/ExpressionWriter.pv"
            if (skip_operator) {
                #line 583 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, inner, generics);
                #line 584 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 587 "src/compiler/ExpressionWriter.pv"
            if (str__Eq_str__eq(&operator, (struct str){ .ptr = "&", .length = strlen("&") })) {
                #line 588 "src/compiler/ExpressionWriter.pv"
                bool is_rvalue = false;
                #line 589 "src/compiler/ExpressionWriter.pv"
                switch (inner->data.type) {
                    #line 590 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__INVOKE: {
                        #line 590 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 591 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__LITERAL: {
                        #line 591 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 592 "src/compiler/ExpressionWriter.pv"
                    case EXPRESSION_DATA__BINARY_EXPRESSION: {
                        #line 592 "src/compiler/ExpressionWriter.pv"
                        is_rvalue = true;
                    } break;
                    #line 593 "src/compiler/ExpressionWriter.pv"
                    default: {
                    } break;
                }

                #line 596 "src/compiler/ExpressionWriter.pv"
                if (is_rvalue) {
                    #line 599 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(");
                    #line 600 "src/compiler/ExpressionWriter.pv"
                    Generator__write_type(generator, file, &inner->return_type, generics);
                    #line 601 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "[]){");
                    #line 602 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner, generics);
                    #line 603 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "}");
                    #line 604 "src/compiler/ExpressionWriter.pv"
                    return true;
                }
            }

            #line 608 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, operator);
            #line 609 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, inner, generics);
            #line 610 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 612 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__BINARY_EXPRESSION: {
            #line 612 "src/compiler/ExpressionWriter.pv"
            struct Expression* left = data->binaryexpression_value._0;
            #line 612 "src/compiler/ExpressionWriter.pv"
            struct str operator = data->binaryexpression_value._1;
            #line 612 "src/compiler/ExpressionWriter.pv"
            struct Expression* right = data->binaryexpression_value._2;
            #line 613 "src/compiler/ExpressionWriter.pv"
            bool is_eq_or_ne = str__Eq_str__eq(&operator, (struct str){ .ptr = "==", .length = strlen("==") }) || str__Eq_str__eq(&operator, (struct str){ .ptr = "!=", .length = strlen("!=") });
            #line 614 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &left->return_type, generics)) {
                #line 615 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 616 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
                #line 617 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else {
                #line 619 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, left, generics);
            }

            #line 622 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " %.*s ", (int32_t)(operator.length), operator.ptr);

            #line 624 "src/compiler/ExpressionWriter.pv"
            if (is_eq_or_ne && Generator__type_is_discriminated_union_no_indirect(generator, &right->return_type, generics)) {
                #line 625 "src/compiler/ExpressionWriter.pv"
                fprintf(file, "(");
                #line 626 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
                #line 627 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ").type");
            } else {
                #line 629 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, right, generics);
            }

            #line 632 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 634 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IF_EXPRESSION: {
            #line 634 "src/compiler/ExpressionWriter.pv"
            struct Expression* cond = data->ifexpression_value._0;
            #line 634 "src/compiler/ExpressionWriter.pv"
            struct Expression* a = data->ifexpression_value._1;
            #line 634 "src/compiler/ExpressionWriter.pv"
            struct Expression* b = data->ifexpression_value._2;
            #line 635 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, cond, generics);
            #line 636 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " ? ");
            #line 637 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, a, generics);
            #line 638 "src/compiler/ExpressionWriter.pv"
            fprintf(file, " : ");
            #line 639 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, b, generics);
            #line 640 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 642 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_STATIC_EXPRESSION: {
            #line 642 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberstaticexpression_value._0;
            #line 642 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberstaticexpression_value._1;
            #line 643 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;
            #line 644 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 645 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 645 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = parent_type->struct_value._0;
                    #line 646 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&struct_info->impls);
                    #line 646 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 646 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 647 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 648 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 649 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 650 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 651 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 652 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 653 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 657 "src/compiler/ExpressionWriter.pv"
                case TYPE__ENUM: {
                    #line 657 "src/compiler/ExpressionWriter.pv"
                    struct Enum* enum_info = parent_type->enum_value._0;
                    #line 658 "src/compiler/ExpressionWriter.pv"
                    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&enum_info->impls);
                    #line 658 "src/compiler/ExpressionWriter.pv"
                    while (Iter_ref_ref_Impl__next(&__iter)) {
                        #line 658 "src/compiler/ExpressionWriter.pv"
                        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

                        #line 659 "src/compiler/ExpressionWriter.pv"
                        struct ImplConst** impl_const_ptr = HashMap_str_ref_ImplConst__find(&impl_info->consts, &member);
                        #line 660 "src/compiler/ExpressionWriter.pv"
                        if (impl_const_ptr != 0) {
                            #line 661 "src/compiler/ExpressionWriter.pv"
                            struct String parent_name = Naming__get_type_name(&generator->naming_ident, parent_type, parent_type, generics);
                            #line 662 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, String__as_str(&parent_name));
                            #line 663 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "_");
                            #line 664 "src/compiler/ExpressionWriter.pv"
                            Generator__write_str_title(generator, file, member);
                            #line 665 "src/compiler/ExpressionWriter.pv"
                            return true;
                        }
                    } }
                } break;
                #line 669 "src/compiler/ExpressionWriter.pv"
                default: {
                } break;
            }
            #line 671 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, parent, generics);
            #line 672 "src/compiler/ExpressionWriter.pv"
            Generator__write_static_member_accessor(generator, file, generics);
            #line 673 "src/compiler/ExpressionWriter.pv"
            Generator__write_str(generator, file, member);
            #line 674 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 676 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__MEMBER_INSTANCE_EXPRESSION: {
            #line 676 "src/compiler/ExpressionWriter.pv"
            struct Expression* parent = data->memberinstanceexpression_value._0;
            #line 676 "src/compiler/ExpressionWriter.pv"
            struct str member = data->memberinstanceexpression_value._1;
            #line 677 "src/compiler/ExpressionWriter.pv"
            struct Type* parent_type = &parent->return_type;

            #line 679 "src/compiler/ExpressionWriter.pv"
            if (Generator__is_type_single_value_struct(generator, parent_type, generics)) {
                #line 680 "src/compiler/ExpressionWriter.pv"
                bool is_ref = Generator__is_reference(parent_type);
                #line 681 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 681 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "(*");
                }
                #line 682 "src/compiler/ExpressionWriter.pv"
                ExpressionWriter__write_expression(self, file, parent, generics);
                #line 683 "src/compiler/ExpressionWriter.pv"
                if (is_ref) {
                    #line 683 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, ")");
                }
                #line 684 "src/compiler/ExpressionWriter.pv"
                return true;
            }

            #line 687 "src/compiler/ExpressionWriter.pv"
            switch (parent_type->type) {
                #line 688 "src/compiler/ExpressionWriter.pv"
                case TYPE__SEQUENCE: {
                    #line 688 "src/compiler/ExpressionWriter.pv"
                    struct Sequence* sequence = parent_type->sequence_value;
                    #line 689 "src/compiler/ExpressionWriter.pv"
                    switch (sequence->type.type) {
                        #line 690 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__FIXED_ARRAY: {
                            #line 690 "src/compiler/ExpressionWriter.pv"
                            struct Expression* length = sequence->type.fixedarray_value;
                            #line 691 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&member, (struct str){ .ptr = "length", .length = strlen("length") })) {
                                #line 692 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_expression(self, file, length, generics);
                            } else {
                                #line 694 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!ERROR NO MEMBER ");
                                #line 695 "src/compiler/ExpressionWriter.pv"
                                Generator__write_str(generator, file, member);
                                #line 696 "src/compiler/ExpressionWriter.pv"
                                fprintf(file, "!!");
                            }
                        } break;
                        #line 699 "src/compiler/ExpressionWriter.pv"
                        case SEQUENCE_TYPE__SLICE: {
                            #line 700 "src/compiler/ExpressionWriter.pv"
                            fprintf(file, "!!ERROR TODO MEMBERS FOR DYNAMIC SEQUENCES!!");
                        } break;
                    }
                } break;
                #line 704 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 705 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, parent, generics);
                    #line 706 "src/compiler/ExpressionWriter.pv"
                    Generator__write_instance_member_accessor(generator, file, &parent->return_type, generics);
                    #line 707 "src/compiler/ExpressionWriter.pv"
                    if (member.length > 0 && member.ptr[0] >= '0' && member.ptr[0] <= '9') {
                        #line 707 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "_");
                    }
                    #line 708 "src/compiler/ExpressionWriter.pv"
                    Generator__write_str(generator, file, member);
                } break;
            }

            #line 712 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 714 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__TYPE: {
            #line 714 "src/compiler/ExpressionWriter.pv"
            struct Type* type = data->type_value;
            #line 715 "src/compiler/ExpressionWriter.pv"
            Generator__write_type(generator, file, type, generics);
            #line 716 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 718 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__INDEX_EXPRESSION: {
            #line 718 "src/compiler/ExpressionWriter.pv"
            struct Expression* array_expr = data->indexexpression_value._0;
            #line 718 "src/compiler/ExpressionWriter.pv"
            struct Expression* index_expr = data->indexexpression_value._1;
            #line 719 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, array_expr, generics);
            #line 720 "src/compiler/ExpressionWriter.pv"
            if (Type__is_reference_sequence_dynamic(&array_expr->return_type)) {
                #line 721 "src/compiler/ExpressionWriter.pv"
                fprintf(file, ".data");
            }
            #line 723 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "[");
            #line 724 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, index_expr, generics);
            #line 725 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "]");
            #line 726 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 728 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__PARENTHESIZED_EXPRESSION: {
            #line 728 "src/compiler/ExpressionWriter.pv"
            struct Expression* expr = data->parenthesizedexpression_value;
            #line 729 "src/compiler/ExpressionWriter.pv"
            fprintf(file, "(");
            #line 730 "src/compiler/ExpressionWriter.pv"
            ExpressionWriter__write_expression(self, file, expr, generics);
            #line 731 "src/compiler/ExpressionWriter.pv"
            fprintf(file, ")");
            #line 732 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 734 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__CPP_EXPRESSION: {
            #line 734 "src/compiler/ExpressionWriter.pv"
            struct CppExpression cpp_expression = data->cppexpression_value;
            #line 735 "src/compiler/ExpressionWriter.pv"
            switch (cpp_expression.type) {
                #line 736 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__NEW: {
                    #line 736 "src/compiler/ExpressionWriter.pv"
                    struct Expression* placement = cpp_expression.new_value.placement;
                    #line 736 "src/compiler/ExpressionWriter.pv"
                    struct Expression* new_expression = cpp_expression.new_value.expression;
                    #line 737 "src/compiler/ExpressionWriter.pv"
                    if (placement != 0) {
                        #line 738 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new(");
                        #line 739 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_expression(self, file, placement, generics);
                        #line 740 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, ") ");
                    } else {
                        #line 742 "src/compiler/ExpressionWriter.pv"
                        fprintf(file, "new ");
                    }
                    #line 744 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, new_expression, generics);
                } break;
                #line 746 "src/compiler/ExpressionWriter.pv"
                case CPP_EXPRESSION__DELETE: {
                    #line 746 "src/compiler/ExpressionWriter.pv"
                    struct Expression* delete_expression = cpp_expression.delete_value;
                    #line 747 "src/compiler/ExpressionWriter.pv"
                    fprintf(file, "delete ");
                    #line 748 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, delete_expression, generics);
                } break;
            }
            #line 751 "src/compiler/ExpressionWriter.pv"
            return true;
        } break;
        #line 753 "src/compiler/ExpressionWriter.pv"
        case EXPRESSION_DATA__IMPLICIT_CAST: {
            #line 753 "src/compiler/ExpressionWriter.pv"
            struct Expression* inner_expr = data->implicitcast_value;
            #line 754 "src/compiler/ExpressionWriter.pv"
            switch (expression->return_type.type) {
                #line 755 "src/compiler/ExpressionWriter.pv"
                case TYPE__STRUCT: {
                    #line 755 "src/compiler/ExpressionWriter.pv"
                    struct Struct* struct_info = expression->return_type.struct_value._0;
                    #line 756 "src/compiler/ExpressionWriter.pv"
                    if (str__Eq_str__eq(&struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                        #line 757 "src/compiler/ExpressionWriter.pv"
                        ExpressionWriter__write_str_cast(self, file, inner_expr, generics, false);
                    }
                } break;
                #line 760 "src/compiler/ExpressionWriter.pv"
                case TYPE__INDIRECT: {
                    #line 760 "src/compiler/ExpressionWriter.pv"
                    struct Indirect* indirect = expression->return_type.indirect_value;
                    #line 761 "src/compiler/ExpressionWriter.pv"
                    switch (indirect->to.type) {
                        #line 762 "src/compiler/ExpressionWriter.pv"
                        case TYPE__STRUCT: {
                            #line 762 "src/compiler/ExpressionWriter.pv"
                            struct Struct* struct_info = indirect->to.struct_value._0;
                            #line 763 "src/compiler/ExpressionWriter.pv"
                            if (str__Eq_str__eq(&struct_info->name->value, (struct str){ .ptr = "str", .length = strlen("str") })) {
                                #line 764 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_str_cast(self, file, inner_expr, generics, true);
                            } else {
                                #line 766 "src/compiler/ExpressionWriter.pv"
                                ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                            }
                        } break;
                        #line 769 "src/compiler/ExpressionWriter.pv"
                        case TYPE__SEQUENCE: {
                            #line 769 "src/compiler/ExpressionWriter.pv"
                            struct Sequence* sequence = indirect->to.sequence_value;
                            #line 769 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_sequence_cast(self, file, inner_expr, sequence, generics);
                        } break;
                        #line 770 "src/compiler/ExpressionWriter.pv"
                        default: {
                            #line 770 "src/compiler/ExpressionWriter.pv"
                            ExpressionWriter__write_trait_cast(self, file, inner_expr, &indirect->to, generics);
                        } break;
                    }
                } break;
                #line 773 "src/compiler/ExpressionWriter.pv"
                default: {
                    #line 773 "src/compiler/ExpressionWriter.pv"
                    ExpressionWriter__write_expression(self, file, inner_expr, generics);
                } break;
            }
        } break;
    }

    #line 778 "src/compiler/ExpressionWriter.pv"
    return false;
}
