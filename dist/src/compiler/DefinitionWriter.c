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
#include <std/Range_usize.h>
#include <compiler/TypeFunctionUsage.h>
#include <analyzer/Block.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Struct.h>
#include <compiler/UsageContext.h>
#include <std/Array_char.h>
#include <std/Array_Generic.h>
#include <std/Array_Type.h>
#include <std/Iter_ref_Type.h>
#include <compiler/IncludeWriter.h>
#include <std/HashMap_str_Type.h>
#include <std/IterEnumerate_ref_ref_Impl.h>
#include <std/Iter_ref_ref_Impl.h>
#include <std/Array_ref_Impl.h>
#include <tuple_usize_ref_ref_Impl.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <compiler/TypeUsage_Enum.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/Array_UsageContext.h>
#include <std/Iter_ref_UsageContext.h>
#include <compiler/TypeUsage_Struct.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/StructType.h>
#include <analyzer/types/StructField.h>
#include <std/HashMapBucket_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_StructField.h>
#include <std/HashMap_str_ref_ImplConst.h>
#include <std/HashMapIter_str_ref_ImplConst.h>
#include <tuple_str_ref_ImplConst.h>
#include <analyzer/ImplConst.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <std/HashMapIter_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_ref_Trait_ref_Type.h>
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
    Generator__write_str_title(generator, file, struct_name);
    #line 104 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__");
    #line 105 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(generator, file, func_info->name->value);
    #line 106 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 107 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO;\n");
    } else {
        #line 109 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN;\n");
    }
}

#line 113 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_definition(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 114 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 115 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, func_info->context, func_info->name);

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
    Generator__write_str_title(generator, file, func_info->name->value);
    #line 202 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 204 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 207 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct TypeFunctionUsage* function_usage) {
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
        #line 222 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 223 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 225 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i < function_usage->function_context.coroutine.yield_count + 1; i++) {
            #line 226 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 227 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 230 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 231 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 233 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 234 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 235 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 237 "src/compiler/DefinitionWriter.pv"
        generator->function_context->coroutine.yield_count = 0;
        #line 238 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 239 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 240 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 241 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 242 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 245 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 246 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 248 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 249 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 251 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &func_info->return_type, generics);
        #line 252 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 253 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 254 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 255 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 256 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 258 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 260 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 261 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &name);
        #line 262 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 264 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");

        #line 266 "src/compiler/DefinitionWriter.pv"
        switch (func_info->parent.type) {
            #line 267 "src/compiler/DefinitionWriter.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 267 "src/compiler/DefinitionWriter.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 268 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_title(generator, file, struct_info->name->value);
                #line 269 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "__");
            } break;
            #line 271 "src/compiler/DefinitionWriter.pv"
            default: {
            } break;
        }

        #line 274 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, func_info->name->value);

        #line 276 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .next = ");
        #line 277 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 278 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .value = ");
        #line 279 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 280 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 282 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 285 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 286 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 287 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 288 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 289 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 290 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 293 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 296 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 297 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 298 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 299 "src/compiler/DefinitionWriter.pv"
    struct Token* enum_name = enum_info->name;
    #line 300 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 301 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 302 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 304 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, enum_info->name);

    #line 306 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 307 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 308 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name->value);
        #line 309 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 310 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 312 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 314 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 315 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 317 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 319 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 320 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 321 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 322 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 323 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 324 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 325 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 326 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 328 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 329 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 330 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 331 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 333 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 335 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 337 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 338 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 339 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 340 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 343 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 344 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 346 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 347 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 348 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 349 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 351 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 351 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 351 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 352 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 353 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 354 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 357 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 358 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 359 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 360 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 362 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 363 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 364 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 365 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 366 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 369 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 370 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 370 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 370 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 371 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 374 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 375 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 376 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 377 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 380 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 380 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 380 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 381 "src/compiler/DefinitionWriter.pv"
            if (variant->types.length == 1) {
                #line 382 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 383 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 384 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 385 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 386 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 387 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 389 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 390 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 392 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 392 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 392 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 393 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 394 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 397 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 398 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 399 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 400 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 404 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 405 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 406 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 407 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 410 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 411 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 414 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 415 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 417 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 417 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 417 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 417 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 418 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 419 "src/compiler/DefinitionWriter.pv"
        if (usage != 0) {
            #line 419 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage->impl_functions, impl_index);
        }

        #line 421 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 421 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 421 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 422 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 423 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 424 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 424 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 426 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 427 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 428 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 428 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 429 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 432 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 433 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                #line 433 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_UsageContext__next(&__iter)) {
                    #line 433 "src/compiler/DefinitionWriter.pv"
                    struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                    #line 434 "src/compiler/DefinitionWriter.pv"
                    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                    #line 435 "src/compiler/DefinitionWriter.pv"
                    usage_context->generic_map->self_type = generics->self_type;
                    #line 436 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 437 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                        #line 437 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 438 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                } }
            }
        } }
    } }

    #line 444 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 447 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 448 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 449 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 450 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 451 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 452 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage->impl_functions;
    #line 453 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 455 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, struct_info->name);

    #line 457 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 458 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 460 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 461 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 462 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 463 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 465 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 466 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 468 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 468 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 468 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 469 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 470 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field->name->value, &field->type, generics);
            #line 471 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 474 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 475 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 478 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 478 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 479 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);

    #line 481 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 481 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 481 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 481 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 482 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 483 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 484 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 484 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 486 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 486 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 486 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 487 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 488 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 489 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 489 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 491 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 492 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 493 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0) {
                        #line 494 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &function_usage->function_context;
                        #line 495 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 496 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 499 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 500 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 500 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 502 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 503 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 503 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }

                #line 506 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 509 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 510 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 511 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 512 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 512 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 512 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 513 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                        #line 516 "src/compiler/DefinitionWriter.pv"
                        usage_context->generic_map->self_type = generics->self_type;
                        #line 517 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 518 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                            #line 518 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }
                        #line 519 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, ";\n");
                    } }

                    #line 522 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function) {
                        #line 523 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_info->name->value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 529 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 530 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 530 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 533 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 533 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 533 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 534 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 535 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 536 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 537 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 538 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 539 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 540 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 544 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 544 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 546 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 546 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 546 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 547 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 548 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 548 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 549 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 550 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 551 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 552 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 553 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 554 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 555 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 558 "src/compiler/DefinitionWriter.pv"
    if (usage->impl_dynamic_usage) {
        #line 559 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 560 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 561 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 562 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 565 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 568 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 569 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 571 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 573 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 573 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 573 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 574 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 575 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 576 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 576 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 578 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
                    #line 578 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 581 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 585 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 586 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 586 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 589 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 592 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 593 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 594 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 596 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 596 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 596 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 597 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 600 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->impls.length > 0) {
        #line 600 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 602 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 602 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 602 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 603 "src/compiler/DefinitionWriter.pv"
        if (!impl_info->has_trait || impl_info->trait_ == 0) {
            #line 603 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 604 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 605 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 605 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 606 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 607 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, &impl_info->trait_type, generics);
        #line 608 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 609 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 610 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 611 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 612 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 615 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 618 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 619 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 620 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 621 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 623 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 624 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 626 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 627 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 629 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 630 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 632 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 632 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 632 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 633 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 634 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 635 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*", .length = strlen("(*") });
            #line 636 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, func_info->name->value);
            #line 637 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 639 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 640 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 640 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 641 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 645 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 646 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 648 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 650 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 651 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 653 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 654 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 655 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 656 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 658 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 659 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 661 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 664 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_with_body(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct Trait* trait_info, struct Type* impl_trait_type, struct GenericMap* generics, struct Module* module, struct TypeFunctionUsage* function_usage) {
    #line 665 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 666 "src/compiler/DefinitionWriter.pv"
    if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, impl_trait_type, func_info, generics)) {
        #line 667 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 668 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_info->name->value.length;
        #line 669 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_info->name->value.ptr);
        #line 670 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 673 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 674 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 676 "src/compiler/DefinitionWriter.pv"
    bool is_value_self = func_info->parameters.length > 0 && Type__is_self(&func_info->parameters.data[0].type);
    #line 677 "src/compiler/DefinitionWriter.pv"
    if (!is_value_self) {
        #line 678 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_self_cast(self, file, module, generics);
    }

    #line 681 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 682 "src/compiler/DefinitionWriter.pv"
    if (function_usage != 0) {
        #line 682 "src/compiler/DefinitionWriter.pv"
        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
    }
    #line 683 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;

    #line 685 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, file, &func_info->return_type, func_info->body, generics, false, true)) {
        #line 686 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 687 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_info->name->value.length;
        #line 688 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_info->name->value.ptr);
        #line 689 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 692 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 693 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 694 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 696 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 697 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 700 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_get_params(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 701 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 702 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/Array_TypeId.h>\n");
    #line 703 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct Array_TypeId* ");
    #line 704 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 706 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 707 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params(void* __self) {\n");
    } else {
        #line 709 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params(void* __self) {\n");
    }

    #line 712 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 713 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 714 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static TypeId type_ids[] = { ");

    #line 716 "src/compiler/DefinitionWriter.pv"
    bool first = true;
    #line 717 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 717 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 717 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 718 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 718 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 718 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 719 "src/compiler/DefinitionWriter.pv"
        Generator__write_typeid(generator, file, &param->type, generics);
    } }

    #line 722 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " };\n");
    #line 723 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 724 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
    #line 725 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 726 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return &result;\n");
    #line 727 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 728 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 731 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_set_arg(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 732 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 733 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "bool ");
    #line 734 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 736 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 737 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
    } else {
        #line 739 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
    }

    #line 742 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 744 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 745 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 746 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 748 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 749 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
    } else {
        #line 751 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 752 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 753 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 754 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 756 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }
    }

    #line 760 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 761 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "switch (index) {\n");
    #line 762 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 764 "src/compiler/DefinitionWriter.pv"
    uintptr_t i = 0;
    #line 765 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 765 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 765 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 766 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 767 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case %zu: self->", i);
        #line 768 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 769 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = ");

        #line 771 "src/compiler/DefinitionWriter.pv"
        if (!Generator__is_reference(&param->type)) {
            #line 772 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*(");
            #line 773 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 774 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*)");
        } else {
            #line 776 "src/compiler/DefinitionWriter.pv"
            if (module->mode_cpp) {
                #line 777 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "(");
                #line 778 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, &param->type, generics);
                #line 779 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ")");
            }
        }

        #line 783 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "value; return true;\n");
        #line 784 "src/compiler/DefinitionWriter.pv"
        i += 1;
    } }

    #line 787 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 788 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 789 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 791 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 792 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return false;\n");

    #line 794 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 795 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 798 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_execute_or_init(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 799 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 800 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 801 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct Iter_CoroutineStatus ");
        #line 802 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 803 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

        #line 805 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 807 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 808 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 809 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 810 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

        #line 812 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 813 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 814 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 815 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
        #line 816 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 817 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "));\n");

        #line 819 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 819 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 819 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 820 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 821 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "instance->");
            #line 822 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 823 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = self->");
            #line 824 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 825 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 828 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 829 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "return (struct trait_Iter_CoroutineStatus) { .vtable = &");

        #line 831 "src/compiler/DefinitionWriter.pv"
        switch (func_info->parent.type) {
            #line 832 "src/compiler/DefinitionWriter.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 832 "src/compiler/DefinitionWriter.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 833 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_title(generator, file, struct_info->name->value);
                #line 834 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "__");
            } break;
            #line 836 "src/compiler/DefinitionWriter.pv"
            default: {
            } break;
        }
        #line 838 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, func_info->name->value);

        #line 840 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

        #line 842 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 843 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    } else {
        #line 845 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "void ");
        #line 846 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 847 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute(void* __self) {\n");

        #line 849 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 851 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 852 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 853 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 854 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 855 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 856 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 857 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 859 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }

        #line 862 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 863 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 864 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");

        #line 866 "src/compiler/DefinitionWriter.pv"
        bool first = true;
        #line 867 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 867 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 867 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 868 "src/compiler/DefinitionWriter.pv"
            if (first) {
                #line 868 "src/compiler/DefinitionWriter.pv"
                first = false;
            } else {
                #line 868 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ", ");
            }
            #line 869 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "self->");
            #line 870 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
        } }

        #line 873 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ");\n");

        #line 875 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 876 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    }
}

#line 880 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_vtable(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 881 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 882 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 883 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_CoroutineStatusVTable ");
    } else {
        #line 885 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
    }

    #line 888 "src/compiler/DefinitionWriter.pv"
    switch (func_info->parent.type) {
        #line 889 "src/compiler/DefinitionWriter.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 889 "src/compiler/DefinitionWriter.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 890 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, struct_info->name->value);
            #line 891 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__");
        } break;
        #line 893 "src/compiler/DefinitionWriter.pv"
        default: {
        } break;
    }
    #line 895 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(generator, file, func_info->name->value);

    #line 897 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 898 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO");
    } else {
        #line 900 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN");
    }

    #line 903 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " = { .get_params = &");
    #line 904 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 906 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 907 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params, .set_arg = &");
        #line 908 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 909 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg, .init = &");
        #line 910 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 911 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init };\n");
    } else {
        #line 913 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params, .set_arg = &");
        #line 914 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 915 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg, .execute = &");
        #line 916 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 917 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute };\n");
    }
}

#line 921 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_impl(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 922 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 923 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 924 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 925 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Allocator.h>\n");
    }
    #line 927 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_get_params(self, file, func_info, generics);
    #line 928 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_set_arg(self, file, func_info, generics, module);
    #line 929 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_execute_or_init(self, file, func_info, generics, module);
    #line 930 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_vtable(self, file, func_info, generics);
}

#line 933 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 934 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 935 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, Type__deref(generics->self_type), generics->self_type, generics);
    #line 936 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 937 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 939 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 941 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 941 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 941 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 941 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 942 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 943 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 944 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 944 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 946 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 946 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 946 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 947 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 948 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 949 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 949 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 951 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 952 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 953 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 954 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, function_usage)) {
                        #line 954 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 956 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 957 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 958 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 959 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 962 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 963 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0) {
                        #line 963 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 964 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 966 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage)) {
                        #line 967 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 968 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 969 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 972 "src/compiler/DefinitionWriter.pv"
                    struct TypeFunctionUsage* function_usage = 0;
                    #line 973 "src/compiler/DefinitionWriter.pv"
                    if (impl_functions_for_impl != 0) {
                        #line 973 "src/compiler/DefinitionWriter.pv"
                        function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                    }

                    #line 975 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 976 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics, module);
                    }

                    #line 979 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 982 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 983 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 984 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 986 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 986 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 986 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 987 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 990 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 992 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 993 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 994 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 995 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_info->name->value.length;
                            #line 996 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                            #line 997 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 1000 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 1001 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                        #line 1002 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 1004 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, function_usage);

                        #line 1006 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    } }
                }
            }
        } }

        #line 1012 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 1013 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 1013 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 1013 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 1013 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 1014 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 1014 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 1016 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1017 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, 0)) {
                    #line 1017 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } }
        }

        #line 1021 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1021 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1021 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1022 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1023 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1024 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1025 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1026 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1027 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 1028 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1029 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, impl_const->value, generics);
            #line 1030 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1034 "src/compiler/DefinitionWriter.pv"
    return true;
}
