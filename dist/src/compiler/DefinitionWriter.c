#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>
#include <compiler/DefinitionWriter.h>
#include <compiler/Generator.h>
#include <std/HashMap_str_EnumVariant.h>
#include <analyzer/types/Enum.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/expression/Expression.h>
#include <compiler/ExpressionWriter.h>
#include <analyzer/Module.h>
#include <std/String.h>
#include <std/str.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Function.h>
#include <std/Array_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <analyzer/Root.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <analyzer/Impl.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/types/FunctionType.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Naming.h>
#include <std/HashMap_str_ref_Type.h>
#include <compiler/FunctionCoroutine.h>
#include <compiler/FunctionContext.h>
#include <std/HashMapIter_str_ref_Type.h>
#include <tuple_str_ref_Type.h>
#include <compiler/BlockWriter.h>
#include <compiler/UsageContext.h>
#include <std/Range_usize.h>
#include <analyzer/Block.h>
#include <std/Array_char.h>
#include <std/Array_Generic.h>
#include <std/Array_Type.h>
#include <std/Array_str.h>
#include <std/Iter_ref_Type.h>
#include <compiler/IncludeWriter.h>
#include <std/HashMap_str_Type.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/Array_UsageContext.h>
#include <std/Iter_ref_UsageContext.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <std/HashMapIter_str_ref_ImplConst.h>
#include <tuple_str_ref_ImplConst.h>
#include <analyzer/ImplConst.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Struct.h>
#include <analyzer/types/StructType.h>
#include <analyzer/types/StructField.h>
#include <std/HashMapBucket_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_StructField.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <std/HashMapIter_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <compiler/TypeUsage_Struct.h>
#include <analyzer/types/Primitive.h>
#include <std/trait_Allocator.h>
#include <compiler/DefinitionWriter.h>

#include <compiler/DefinitionWriter.h>

#line 15 "src/compiler/DefinitionWriter.pv"
struct DefinitionWriter DefinitionWriter__new(struct Generator* generator) {
    #line 16 "src/compiler/DefinitionWriter.pv"
    return (struct DefinitionWriter) { .generator = generator };
}

#line 19 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_enum_variants(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct GenericMap* generics) {
    #line 20 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 21 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
    #line 21 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_EnumVariant__next(&__iter)) {
        #line 21 "src/compiler/DefinitionWriter.pv"
        struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

        #line 22 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 23 "src/compiler/DefinitionWriter.pv"
        Generator__write_enum_variant_name(generator, file, generics->self_type, variant);

        #line 25 "src/compiler/DefinitionWriter.pv"
        if (variant->value != 0) {
            #line 26 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 27 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, variant->value, generics);
        }

        #line 30 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ",\n");
    } }
}

#line 34 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_self_cast(struct DefinitionWriter* self, FILE* file, struct Module* module, struct GenericMap* generics) {
    #line 35 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 36 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 37 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, generics->self_type, generics);
    #line 38 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "* self = ");

    #line 40 "src/compiler/DefinitionWriter.pv"
    if (module != 0 && module->mode_cpp) {
        #line 41 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");
        #line 42 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, generics->self_type, generics);
        #line 43 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)");
    }

    #line 46 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__self; (void)self;\n");
}

#line 49 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_decl(struct DefinitionWriter* self, FILE* file, struct str name, struct Trait* trait_info, struct Type* impl_trait_type, struct Function* func_info, struct GenericMap* generics) {
    #line 50 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 51 "src/compiler/DefinitionWriter.pv"
    struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, impl_trait_type, func_info, generics);

    #line 53 "src/compiler/DefinitionWriter.pv"
    bool is_value_self = func_info->parameters.length > 0 && Type__is_self(&func_info->parameters.data[0].type);
    #line 54 "src/compiler/DefinitionWriter.pv"
    if (is_value_self) {
        #line 55 "src/compiler/DefinitionWriter.pv"
        return DefinitionWriter__write_function_definition(self, file, func_info, generics, &func_name);
    }

    #line 58 "src/compiler/DefinitionWriter.pv"
    struct GenericMap generics_void = *generics;
    #line 59 "src/compiler/DefinitionWriter.pv"
    generics_void.self_type = &generator->root->type_void;
    #line 60 "src/compiler/DefinitionWriter.pv"
    return DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name);
}

#line 63 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_default_decls(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct Trait* trait_info, struct GenericMap* generics) {
    #line 64 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 64 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 64 "src/compiler/DefinitionWriter.pv"
        struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
        #line 64 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 65 "src/compiler/DefinitionWriter.pv"
        if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
            #line 65 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 67 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
        #line 68 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
            #line 68 "src/compiler/DefinitionWriter.pv"
            return false;
        }
        #line 69 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }
    #line 71 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 74 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_instance_header(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct str struct_name, struct GenericMap* generics, bool is_coroutine) {
    #line 75 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 76 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 77 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Co_CoroutineStatus.h>\n");
    } else {
        #line 79 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Fn.h>\n");
    }
    #line 81 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 82 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 83 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 84 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance { ");
    } else {
        #line 86 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__Instance { ");
    }
    #line 88 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 89 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 89 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 89 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 90 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &param->type, generics);
        #line 91 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 92 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 93 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "; ");
    } }
    #line 95 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 96 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 98 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 99 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_Co_CoroutineStatusVTable ");
    } else {
        #line 101 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_FnVTable ");
    }
    #line 103 "src/compiler/DefinitionWriter.pv"
    Generator__write_dynamic_vtable_name(generator, file, func_info, generics);
    #line 104 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 105 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO;\n");
    } else {
        #line 107 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN;\n");
    }
}

#line 111 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_definition(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 112 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 113 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, func_info->context, func_info->name);

    #line 115 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);

    #line 117 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 118 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "bool");
    } else {
        #line 120 "src/compiler/DefinitionWriter.pv"
        if (!Generator__write_type(generator, file, &func_info->return_type, generics)) {
            #line 120 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 123 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 124 "src/compiler/DefinitionWriter.pv"
    if (custom_name != 0) {
        #line 125 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, custom_name);
    } else {
        #line 127 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.map.length > 0) {
            #line 128 "src/compiler/DefinitionWriter.pv"
            struct String name = Naming__get_type_name(&generator->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
            #line 129 "src/compiler/DefinitionWriter.pv"
            Generator__write_string(generator, file, &name);
        } else {
            #line 131 "src/compiler/DefinitionWriter.pv"
            if (!Generator__write_function_name(generator, file, func_info, generics)) {
                #line 131 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }
    }

    #line 135 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 136 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 137 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 140 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "(");

    #line 142 "src/compiler/DefinitionWriter.pv"
    bool success = true;
    #line 143 "src/compiler/DefinitionWriter.pv"
    bool first = true;

    #line 145 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 145 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 145 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter_iter = Iter_ref_Parameter__value(&__iter);

        #line 146 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 146 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 146 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }

        #line 148 "src/compiler/DefinitionWriter.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 149 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 151 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, parameter_iter->name->value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 155 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ")");
    #line 156 "src/compiler/DefinitionWriter.pv"
    return success;
}

#line 159 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 160 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 161 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 162 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 163 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 164 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 166 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 167 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 169 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 170 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 171 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 173 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&generator->function_context->coroutine.variables);
    #line 173 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 173 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 173 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 174 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 175 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 176 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 177 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, name);
        #line 178 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 181 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 182 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 184 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 186 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 187 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);

    #line 189 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 191 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 192 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 193 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 194 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 196 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "extern struct trait_Iter_");
    #line 197 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 198 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 200 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 201 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 202 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 204 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 207 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct UsageContext* function_usage_context) {
    #line 208 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 209 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = generator };

    #line 211 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 212 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 213 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 215 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 216 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 217 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 218 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 220 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 221 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");

        #line 223 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 224 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 225 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 227 "src/compiler/DefinitionWriter.pv"
        uintptr_t yield_count = 0;
        #line 228 "src/compiler/DefinitionWriter.pv"
        if (function_usage_context != 0) {
            #line 228 "src/compiler/DefinitionWriter.pv"
            yield_count = function_usage_context->function_context.coroutine.yield_count;
        }
        #line 229 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i < yield_count + 1; i++) {
            #line 230 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 231 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 234 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 235 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 237 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 238 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 239 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 241 "src/compiler/DefinitionWriter.pv"
        generator->function_context->coroutine.yield_count = 0;
        #line 242 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 243 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 244 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 245 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 246 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 249 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 250 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 252 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 253 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 255 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &func_info->return_type, generics);
        #line 256 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 257 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 258 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 259 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 260 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 262 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 264 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 265 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &name);
        #line 266 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 268 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 269 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);

        #line 271 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .fn_next = ");
        #line 272 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 273 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .fn_value = ");
        #line 274 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 275 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 277 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 280 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 281 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 282 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 283 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 284 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 285 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 288 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 291 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 292 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 293 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 294 "src/compiler/DefinitionWriter.pv"
    struct Token* enum_name = enum_info->name;
    #line 295 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 296 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 297 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 299 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, enum_info->name);

    #line 301 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 302 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 303 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name->value);
        #line 304 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 305 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 307 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 309 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 310 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 312 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 314 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 315 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 316 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 317 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 318 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 319 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 320 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 321 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 323 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 324 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 325 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 326 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 328 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 330 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 332 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 333 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 334 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 335 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 338 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 339 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 341 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 342 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 343 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 344 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 346 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 346 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 346 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 347 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 348 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 349 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 352 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 353 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 354 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 355 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 357 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 358 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 359 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 360 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 361 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 364 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 365 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 365 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 365 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 366 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 369 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 370 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 371 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 372 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 375 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 375 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 375 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 376 "src/compiler/DefinitionWriter.pv"
            if (variant->names.length > 0) {
                #line 377 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 378 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 380 "src/compiler/DefinitionWriter.pv"
                uintptr_t i = 0;
                #line 381 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 381 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 381 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 382 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 383 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " ");
                    #line 384 "src/compiler/DefinitionWriter.pv"
                    Generator__write_str(generator, file, variant->names.data[i]);
                    #line 385 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "; ");
                    #line 386 "src/compiler/DefinitionWriter.pv"
                    i += 1;
                } }

                #line 389 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 390 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, variant->name->value);
                #line 391 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length == 1) {
                #line 393 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 394 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 395 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 396 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 397 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 398 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 400 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 401 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 403 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 403 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 403 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 404 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 405 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 408 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 409 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 410 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 411 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 415 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 416 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 417 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 418 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 421 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 422 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 425 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 426 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 428 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 428 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 428 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 428 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 429 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 430 "src/compiler/DefinitionWriter.pv"
        if (usage_context->impl_functions.length > impl_index) {
            #line 430 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage_context->impl_functions, impl_index);
        }

        #line 432 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 432 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 432 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 433 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 434 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 435 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 435 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 437 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 438 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 439 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 439 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 440 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");

                #line 442 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->impl_dynamic_function) {
                    #line 443 "src/compiler/DefinitionWriter.pv"
                    DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_info->name->value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                }
            }

            #line 447 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0 && func_info->generics.array.length > 0) {
                #line 448 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                #line 448 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_UsageContext__next(&__iter)) {
                    #line 448 "src/compiler/DefinitionWriter.pv"
                    struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                    #line 449 "src/compiler/DefinitionWriter.pv"
                    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                    #line 450 "src/compiler/DefinitionWriter.pv"
                    usage_context->generic_map->self_type = generics->self_type;
                    #line 451 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 452 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                        #line 452 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 453 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");

                    #line 455 "src/compiler/DefinitionWriter.pv"
                    if (usage_context->impl_dynamic_function) {
                        #line 456 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_info->name->value, usage_context->generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                } }
            }
        } }

        #line 462 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 462 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 462 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 463 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 464 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 465 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 466 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 467 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 468 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 469 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 473 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 476 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 477 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 478 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 479 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 480 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 481 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage_context->impl_functions;
    #line 482 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 484 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, struct_info->name);

    #line 486 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 487 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 489 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 490 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 491 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 492 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 494 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 495 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 497 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 497 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 497 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 498 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 499 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field->name->value, &field->type, generics);
            #line 500 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 503 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 504 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 507 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 507 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 508 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);

    #line 510 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 510 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 510 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 510 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 511 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 512 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 513 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 513 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 515 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 515 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 515 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 516 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 517 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 518 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 518 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 520 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 521 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 522 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0 && function_usage->usage_contexts.length > 0) {
                        #line 523 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &function_usage->usage_contexts.data[0].function_context;
                        #line 524 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 525 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 528 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 529 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 529 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 531 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 532 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 532 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }

                #line 535 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 538 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 539 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 540 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 541 "src/compiler/DefinitionWriter.pv"
                    if (func_info->generics.array.length > 0) {
                        #line 542 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                        #line 542 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_UsageContext__next(&__iter)) {
                            #line 542 "src/compiler/DefinitionWriter.pv"
                            struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                            #line 543 "src/compiler/DefinitionWriter.pv"
                            IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                            #line 546 "src/compiler/DefinitionWriter.pv"
                            usage_context->generic_map->self_type = generics->self_type;
                            #line 547 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "\n");
                            #line 548 "src/compiler/DefinitionWriter.pv"
                            if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                                #line 548 "src/compiler/DefinitionWriter.pv"
                                return false;
                            }
                            #line 549 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, ";\n");

                            #line 551 "src/compiler/DefinitionWriter.pv"
                            if (usage_context->impl_dynamic_function) {
                                #line 552 "src/compiler/DefinitionWriter.pv"
                                DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_info->name->value, usage_context->generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                            }
                        } }
                    }

                    #line 557 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function && func_info->generics.array.length == 0) {
                        #line 558 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_info->name->value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 564 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 565 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 565 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 568 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 568 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 568 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 569 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 570 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 571 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 572 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 573 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 574 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 575 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 579 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 579 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 581 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 581 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 581 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 582 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 583 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 583 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 584 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 585 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 586 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 587 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 588 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 589 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 590 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 593 "src/compiler/DefinitionWriter.pv"
    if (usage->impl_dynamic_usage) {
        #line 594 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 595 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 596 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 597 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 600 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 603 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 604 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 606 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 608 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 608 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 608 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 609 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 610 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 611 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 611 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 613 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
                    #line 613 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 616 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 620 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 621 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 621 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 624 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 627 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 628 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 629 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 631 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 631 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 631 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 632 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 635 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->impls.length > 0) {
        #line 635 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 637 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 637 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 637 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 638 "src/compiler/DefinitionWriter.pv"
        if (!impl_info->has_trait || impl_info->trait_ == 0) {
            #line 638 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 639 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 640 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 640 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 641 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 642 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, &impl_info->trait_type, generics);
        #line 643 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 644 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 645 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 646 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 647 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 650 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 653 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 654 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 655 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 656 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 658 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 659 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 661 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 662 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 664 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 665 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 667 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 667 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 667 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 668 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 669 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 670 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*fn_", .length = strlen("(*fn_") });
            #line 671 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, func_info->name->value);
            #line 672 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 674 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 674 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 675 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 679 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 680 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 682 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 684 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 685 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 687 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 688 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 689 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 690 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 692 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 693 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 695 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 698 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_with_body(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct Trait* trait_info, struct Type* impl_trait_type, struct GenericMap* generics, struct Module* module, struct UsageContext* function_usage_context) {
    #line 699 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 700 "src/compiler/DefinitionWriter.pv"
    if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, impl_trait_type, func_info, generics)) {
        #line 701 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 702 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_info->name->value.length;
        #line 703 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_info->name->value.ptr);
        #line 704 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 707 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 708 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 710 "src/compiler/DefinitionWriter.pv"
    bool is_value_self = func_info->parameters.length > 0 && Type__is_self(&func_info->parameters.data[0].type);
    #line 711 "src/compiler/DefinitionWriter.pv"
    if (!is_value_self) {
        #line 712 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_self_cast(self, file, module, generics);
    }

    #line 715 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 716 "src/compiler/DefinitionWriter.pv"
    if (function_usage_context != 0) {
        #line 716 "src/compiler/DefinitionWriter.pv"
        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
    }
    #line 717 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;

    #line 719 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, file, &func_info->return_type, func_info->body, generics, false, true)) {
        #line 720 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 721 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_info->name->value.length;
        #line 722 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_info->name->value.ptr);
        #line 723 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 726 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 727 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 728 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 730 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 731 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 734 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_size(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 735 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 736 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "uintptr_t ");
    #line 737 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 738 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__size(void* __self) {\n");

    #line 740 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 741 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 742 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return sizeof(struct ");
    #line 743 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 744 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__Instance);\n");
    #line 745 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 746 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 749 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_get_params(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 750 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 751 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/Array_TypeId.h>\n");
    #line 752 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct Array_TypeId* ");
    #line 753 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 755 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 756 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params(void* __self) {\n");
    } else {
        #line 758 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params(void* __self) {\n");
    }

    #line 761 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 762 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 763 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static TypeId type_ids[] = { ");

    #line 765 "src/compiler/DefinitionWriter.pv"
    bool first = true;
    #line 766 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 766 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 766 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 767 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 767 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 767 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 768 "src/compiler/DefinitionWriter.pv"
        Generator__write_typeid(generator, file, &param->type, generics);
    } }

    #line 771 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " };\n");
    #line 772 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 773 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
    #line 774 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 775 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return &result;\n");
    #line 776 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 777 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 780 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_set_arg(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 781 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 782 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "bool ");
    #line 783 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 785 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 786 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
    } else {
        #line 788 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
    }

    #line 791 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 793 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 794 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 795 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 797 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 798 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
    } else {
        #line 800 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 801 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 802 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 803 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 805 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }
    }

    #line 809 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 810 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "switch (index) {\n");
    #line 811 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 813 "src/compiler/DefinitionWriter.pv"
    uintptr_t i = 0;
    #line 814 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 814 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 814 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 815 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 816 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case %zu: self->", i);
        #line 817 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 818 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = ");

        #line 820 "src/compiler/DefinitionWriter.pv"
        if (!Generator__is_reference(&param->type)) {
            #line 821 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*(");
            #line 822 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 823 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*)");
        } else {
            #line 825 "src/compiler/DefinitionWriter.pv"
            if (module->mode_cpp) {
                #line 826 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "(");
                #line 827 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, &param->type, generics);
                #line 828 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ")");
            }
        }

        #line 832 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "value; return true;\n");
        #line 833 "src/compiler/DefinitionWriter.pv"
        i += 1;
    } }

    #line 836 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 837 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 838 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 840 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 841 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return false;\n");

    #line 843 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 844 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 847 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_execute_or_init(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 848 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 849 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 850 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct Iter_CoroutineStatus ");
        #line 851 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 852 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

        #line 854 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 856 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 857 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 858 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 859 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

        #line 861 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 862 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 863 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 864 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
        #line 865 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 866 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "));\n");

        #line 868 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 868 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 868 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 869 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 870 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "instance->");
            #line 871 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 872 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = self->");
            #line 873 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 874 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 877 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 878 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "return (struct trait_Iter_CoroutineStatus) { .vtable = &");
        #line 879 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 880 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

        #line 882 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 883 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    } else {
        #line 885 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "void ");
        #line 886 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 887 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute(void* __self) {\n");

        #line 889 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 891 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 892 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 893 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 894 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 895 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 896 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 897 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 899 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }

        #line 902 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 903 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 904 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");

        #line 906 "src/compiler/DefinitionWriter.pv"
        bool first = true;
        #line 907 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 907 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 907 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 908 "src/compiler/DefinitionWriter.pv"
            if (first) {
                #line 908 "src/compiler/DefinitionWriter.pv"
                first = false;
            } else {
                #line 908 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ", ");
            }
            #line 909 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "self->");
            #line 910 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
        } }

        #line 913 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ");\n");

        #line 915 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 916 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    }
}

#line 920 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_vtable(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 921 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 922 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 923 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_CoroutineStatusVTable ");
    } else {
        #line 925 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
    }

    #line 928 "src/compiler/DefinitionWriter.pv"
    Generator__write_dynamic_vtable_name(generator, file, func_info, generics);

    #line 930 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 931 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO");
    } else {
        #line 933 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN");
    }

    #line 936 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 937 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_get_params = &");
        #line 938 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 939 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params, .fn_set_arg = &");
        #line 940 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 941 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg, .fn_init = &");
        #line 942 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 943 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init };\n");
    } else {
        #line 945 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_size = &");
        #line 946 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 947 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__size, .fn_get_params = &");
        #line 948 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 949 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params, .fn_set_arg = &");
        #line 950 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 951 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg, .fn_execute = &");
        #line 952 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 953 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute };\n");
    }
}

#line 957 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_impl(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 958 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 959 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 960 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 961 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Allocator.h>\n");
    }
    #line 963 "src/compiler/DefinitionWriter.pv"
    if (!Generator__is_coroutine(generator)) {
        #line 963 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_dynamic_size(self, file, func_info, generics);
    }
    #line 964 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_get_params(self, file, func_info, generics);
    #line 965 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_set_arg(self, file, func_info, generics, module);
    #line 966 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_execute_or_init(self, file, func_info, generics, module);
    #line 967 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_vtable(self, file, func_info, generics);
}

#line 970 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 971 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 972 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, Type__deref(generics->self_type), generics->self_type, generics);
    #line 973 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 974 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 976 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 978 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 978 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 978 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 978 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 979 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 980 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 981 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 981 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 983 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 983 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 983 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 984 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 985 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 986 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 986 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 988 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 991 "src/compiler/DefinitionWriter.pv"
                struct UsageContext* function_usage_context = 0;
                #line 992 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->usage_contexts.length > 0) {
                    #line 993 "src/compiler/DefinitionWriter.pv"
                    function_usage_context = &function_usage->usage_contexts.data[0];
                }

                #line 996 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 997 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 998 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, function_usage_context)) {
                        #line 998 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 1000 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 1001 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 1002 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 1003 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1006 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 1007 "src/compiler/DefinitionWriter.pv"
                    if (function_usage_context != 0) {
                        #line 1007 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
                    }
                    #line 1008 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 1010 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage_context)) {
                        #line 1011 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 1012 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 1013 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1016 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 1017 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics, module);
                    }

                    #line 1020 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 1023 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 1024 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 1025 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 1027 "src/compiler/DefinitionWriter.pv"
                    for (uintptr_t i = 0; i < function_usage->usage_contexts.length; i++) {
                        #line 1028 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = &function_usage->usage_contexts.data[i];
                        #line 1029 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 1032 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 1034 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 1035 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 1036 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 1037 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_info->name->value.length;
                            #line 1038 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                            #line 1039 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 1042 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 1043 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = usage_context->function_context.coroutine.yield_count;
                        #line 1044 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 1046 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, usage_context);

                        #line 1048 "src/compiler/DefinitionWriter.pv"
                        if (usage_context->impl_dynamic_function) {
                            #line 1049 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics3, module);
                        }

                        #line 1052 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }
                }
            }
        } }

        #line 1058 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 1059 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 1059 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 1059 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 1059 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 1060 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 1060 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 1062 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1063 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, 0)) {
                    #line 1063 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } }
        }

        #line 1067 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1067 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1067 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1068 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1069 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1070 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1071 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1072 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1073 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 1074 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1075 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, impl_const->value, generics);
            #line 1076 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1080 "src/compiler/DefinitionWriter.pv"
    return true;
}
