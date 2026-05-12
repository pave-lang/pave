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
#include <analyzer/Root.h>
#include <std/String.h>
#include <std/str.h>
#include <analyzer/types/Trait.h>
#include <analyzer/types/Function.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <analyzer/Impl.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
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
#include <std/HashMap_str_ref_Trait.h>
#include <std/HashMapIter_str_ref_Trait.h>
#include <tuple_str_ref_Trait.h>
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
            ExpressionWriter__write_expression(&(struct ExpressionWriter) { .generator = generator }, file, variant->value, generics);
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
bool DefinitionWriter__write_trait_function_decl(struct DefinitionWriter* self, FILE* file, struct str name, struct Trait* trait_info, struct Function* func_info, struct GenericMap* generics) {
    #line 50 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 51 "src/compiler/DefinitionWriter.pv"
    struct GenericMap generics_void = *generics;
    #line 52 "src/compiler/DefinitionWriter.pv"
    generics_void.self_type = &generator->root->type_void;
    #line 53 "src/compiler/DefinitionWriter.pv"
    struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, func_info, generics);
    #line 54 "src/compiler/DefinitionWriter.pv"
    return DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name);
}

#line 57 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_default_decls(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct Trait* trait_info, struct GenericMap* generics) {
    #line 58 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 58 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 58 "src/compiler/DefinitionWriter.pv"
        struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
        #line 58 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 59 "src/compiler/DefinitionWriter.pv"
        if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
            #line 59 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 61 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
        #line 62 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, func_info, generics)) {
            #line 62 "src/compiler/DefinitionWriter.pv"
            return false;
        }
        #line 63 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }
    #line 65 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 68 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_instance_header(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct str struct_name, struct GenericMap* generics, bool is_coroutine) {
    #line 69 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 70 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 71 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Co_CoroutineStatus.h>\n");
    } else {
        #line 73 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Fn.h>\n");
    }
    #line 75 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 76 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 77 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 78 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance { ");
    } else {
        #line 80 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__Instance { ");
    }
    #line 82 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 83 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 83 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 83 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 84 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &param->type, generics);
        #line 85 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 86 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 87 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "; ");
    } }
    #line 89 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 90 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 92 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 93 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_Co_CoroutineStatusVTable ");
    } else {
        #line 95 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_FnVTable ");
    }
    #line 97 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(generator, file, struct_name);
    #line 98 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__");
    #line 99 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(generator, file, func_info->name->value);
    #line 100 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 101 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO;\n");
    } else {
        #line 103 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN;\n");
    }
}

#line 107 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_definition(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 108 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 109 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, func_info->context, func_info->name);

    #line 111 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 112 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "bool");
    } else {
        #line 114 "src/compiler/DefinitionWriter.pv"
        if (!Generator__write_type(generator, file, &func_info->return_type, generics)) {
            #line 114 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 117 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 118 "src/compiler/DefinitionWriter.pv"
    if (custom_name != 0) {
        #line 119 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, custom_name);
    } else {
        #line 121 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.map.length > 0) {
            #line 122 "src/compiler/DefinitionWriter.pv"
            struct String name = Naming__get_type_name(&generator->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);
            #line 123 "src/compiler/DefinitionWriter.pv"
            Generator__write_string(generator, file, &name);
        } else {
            #line 125 "src/compiler/DefinitionWriter.pv"
            if (!Generator__write_function_name(generator, file, func_info, generics)) {
                #line 125 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }
    }

    #line 129 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 130 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 131 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 134 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "(");

    #line 136 "src/compiler/DefinitionWriter.pv"
    bool success = true;
    #line 137 "src/compiler/DefinitionWriter.pv"
    bool first = true;

    #line 139 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 139 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 139 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter_iter = Iter_ref_Parameter__value(&__iter);

        #line 140 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 140 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 140 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }

        #line 142 "src/compiler/DefinitionWriter.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 143 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 145 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, parameter_iter->name->value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 149 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ")");
    #line 150 "src/compiler/DefinitionWriter.pv"
    return success;
}

#line 153 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 154 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 155 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 156 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 157 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 158 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 160 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 161 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 163 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 164 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 165 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 167 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&generator->function_context->coroutine.variables);
    #line 167 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 167 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 167 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 168 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 169 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 170 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 171 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, name);
        #line 172 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 175 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 176 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 178 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 180 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 181 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);

    #line 183 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 185 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 186 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 187 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 188 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 190 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "extern struct trait_Iter_");
    #line 191 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 192 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 194 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 195 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(generator, file, func_info->name->value);
    #line 196 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 198 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 201 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct TypeFunctionUsage* function_usage) {
    #line 202 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 203 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = generator };

    #line 205 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 206 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 207 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 209 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 210 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 211 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 212 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 214 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 215 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");
        #line 216 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 217 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 219 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i < function_usage->function_context.coroutine.yield_count + 1; i++) {
            #line 220 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 221 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 224 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 225 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 227 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 228 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 229 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 231 "src/compiler/DefinitionWriter.pv"
        generator->function_context->coroutine.yield_count = 0;
        #line 232 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 233 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 234 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 235 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 236 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 239 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 240 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 242 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 243 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 245 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &func_info->return_type, generics);
        #line 246 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 247 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 248 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 249 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 250 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 252 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 254 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 255 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &name);
        #line 256 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 258 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");

        #line 260 "src/compiler/DefinitionWriter.pv"
        switch (func_info->parent.type) {
            #line 261 "src/compiler/DefinitionWriter.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 261 "src/compiler/DefinitionWriter.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 262 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_title(generator, file, struct_info->name->value);
                #line 263 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "__");
            } break;
            #line 265 "src/compiler/DefinitionWriter.pv"
            default: {
            } break;
        }

        #line 268 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, func_info->name->value);

        #line 270 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .next = ");
        #line 271 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 272 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .value = ");
        #line 273 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 274 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 276 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 279 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 280 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 281 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 282 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 283 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 284 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 287 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 290 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 291 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 292 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 293 "src/compiler/DefinitionWriter.pv"
    struct Token* enum_name = enum_info->name;
    #line 294 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 295 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 296 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 298 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, enum_info->name);

    #line 300 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 301 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 302 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name->value);
        #line 303 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 304 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 306 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 308 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 309 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 311 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 313 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 314 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 315 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 316 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 317 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 318 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 319 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 320 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 322 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 323 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 324 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 325 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 327 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 329 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 331 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 332 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 333 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 334 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 337 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 338 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 340 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 341 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 342 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 343 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 345 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 345 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 345 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 346 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 347 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 348 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 351 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 352 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 353 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 354 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 356 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 357 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 358 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 359 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 360 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 363 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 364 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 364 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 364 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 365 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 368 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 369 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 370 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 371 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 374 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 374 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 374 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 375 "src/compiler/DefinitionWriter.pv"
            if (variant->types.length == 1) {
                #line 376 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 377 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 378 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 379 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 380 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 381 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 383 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 384 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 386 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 386 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 386 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 387 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 388 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 391 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 392 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 393 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 394 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 398 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 399 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 400 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 401 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 404 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 405 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 408 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 409 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 411 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 411 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 411 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 411 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 412 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 413 "src/compiler/DefinitionWriter.pv"
        if (usage != 0) {
            #line 413 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage->impl_functions, impl_index);
        }

        #line 415 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 415 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 415 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 416 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 417 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 418 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 418 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 420 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 421 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 422 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 422 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 423 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 426 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 427 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                #line 427 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_UsageContext__next(&__iter)) {
                    #line 427 "src/compiler/DefinitionWriter.pv"
                    struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                    #line 428 "src/compiler/DefinitionWriter.pv"
                    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                    #line 429 "src/compiler/DefinitionWriter.pv"
                    usage_context->generic_map->self_type = generics->self_type;
                    #line 430 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 431 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                        #line 431 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 432 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                } }
            }
        } }
    } }

    #line 438 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 441 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 442 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 443 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 444 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 445 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 446 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage->impl_functions;
    #line 447 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 449 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, struct_info->name);

    #line 451 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 452 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 454 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 455 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 456 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 457 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 459 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 460 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 462 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 462 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 462 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 463 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 464 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field->name->value, &field->type, generics);
            #line 465 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 468 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 469 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 472 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 472 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 473 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);

    #line 475 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 475 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 475 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 475 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 476 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 477 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 478 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 478 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 480 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 480 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 480 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 481 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 482 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 483 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 483 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 485 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 486 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 487 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0) {
                        #line 488 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &function_usage->function_context;
                        #line 489 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 490 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 493 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 494 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 494 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 496 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 497 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, func_info, generics)) {
                        #line 497 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }

                #line 500 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 503 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 504 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 505 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 506 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 506 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 506 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 507 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                        #line 510 "src/compiler/DefinitionWriter.pv"
                        usage_context->generic_map->self_type = generics->self_type;
                        #line 511 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 512 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                            #line 512 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }
                        #line 513 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, ";\n");
                    } }

                    #line 516 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function) {
                        #line 517 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_info->name->value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 523 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 524 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 524 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 527 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 527 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 527 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 528 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 529 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 530 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 531 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 532 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 533 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 534 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 538 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 538 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 540 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 540 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 540 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 541 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 542 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 543 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 544 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 545 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 546 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 547 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 548 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 551 "src/compiler/DefinitionWriter.pv"
    if (usage->impl_dynamic_usage) {
        #line 552 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 553 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 554 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 555 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 558 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 561 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 562 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 564 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 566 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 566 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 566 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 567 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 568 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 569 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 569 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 571 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, func_info, generics)) {
                    #line 571 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 574 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 578 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 579 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 579 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 582 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 585 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 586 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 587 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 589 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 589 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 589 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 590 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 593 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->traits.length > 0) {
        #line 593 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 595 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&primitive_info->traits);
    #line 595 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 595 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 596 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_");
        #line 597 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, trait_info->name);
        #line 598 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 599 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 600 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 601 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 602 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 605 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 608 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 609 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 610 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 611 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 613 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 614 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 616 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 617 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 619 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 620 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 622 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 622 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 622 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 623 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 624 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 625 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*", .length = strlen("(*") });
            #line 626 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, func_info->name->value);
            #line 627 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 629 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 630 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 630 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 631 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 635 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 636 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 638 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 640 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 641 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 643 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 644 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 645 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 646 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 648 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 649 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 651 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 654 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 655 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 656 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, Type__deref(generics->self_type), generics->self_type, generics);
    #line 657 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 658 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 660 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 662 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 662 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 662 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 662 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 663 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 664 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 665 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 665 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 667 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 667 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 667 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 668 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 669 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 670 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 670 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 672 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 673 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 674 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 675 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, func_info, generics)) {
                        #line 676 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 677 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 678 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 681 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " {\n");
                    #line 682 "src/compiler/DefinitionWriter.pv"
                    generator->indent += 1;

                    #line 684 "src/compiler/DefinitionWriter.pv"
                    DefinitionWriter__write_self_cast(self, file, module, generics);

                    #line 686 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 687 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0) {
                        #line 687 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 688 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 690 "src/compiler/DefinitionWriter.pv"
                    if (!BlockWriter__write_block(&(struct BlockWriter) { .generator = generator }, file, &func_info->return_type, func_info->body, generics, false, true)) {
                        #line 691 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 692 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 693 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 696 "src/compiler/DefinitionWriter.pv"
                    generator->indent -= 1;
                    #line 697 "src/compiler/DefinitionWriter.pv"
                    Generator__write_indent(generator, file);
                    #line 698 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "}\n");

                    #line 700 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                } else {
                    #line 702 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 703 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 704 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 705 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 708 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 709 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0) {
                        #line 709 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 710 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 712 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage)) {
                        #line 713 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 714 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 715 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 718 "src/compiler/DefinitionWriter.pv"
                    struct TypeFunctionUsage* function_usage = 0;
                    #line 719 "src/compiler/DefinitionWriter.pv"
                    if (impl_functions_for_impl != 0) {
                        #line 719 "src/compiler/DefinitionWriter.pv"
                        function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                    }

                    #line 721 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 722 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 723 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 724 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "#include <std/trait_Allocator.h>\n");
                        }

                        #line 727 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "#include <std/Array_TypeId.h>\n");
                        #line 728 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "struct Array_TypeId* ");
                        #line 729 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(generator, file, func_info, generics);

                        #line 731 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 732 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__get_params(void* __self) {\n");
                        } else {
                            #line 734 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__get_params(void* __self) {\n");
                        }

                        #line 737 "src/compiler/DefinitionWriter.pv"
                        generator->indent += 1;
                        #line 738 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 739 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "static TypeId type_ids[] = { ");

                        #line 741 "src/compiler/DefinitionWriter.pv"
                        bool first = true;
                        #line 742 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 742 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_Parameter__next(&__iter)) {
                            #line 742 "src/compiler/DefinitionWriter.pv"
                            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                            #line 743 "src/compiler/DefinitionWriter.pv"
                            if (first) {
                                #line 743 "src/compiler/DefinitionWriter.pv"
                                first = false;
                            } else {
                                #line 743 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 744 "src/compiler/DefinitionWriter.pv"
                            Generator__write_typeid(generator, file, &param->type, generics);
                        } }

                        #line 747 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, " };\n");
                        #line 748 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 749 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
                        #line 750 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 751 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "return &result;\n");
                        #line 752 "src/compiler/DefinitionWriter.pv"
                        generator->indent -= 1;
                        #line 753 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "}\n");

                        #line 755 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "bool ");
                        #line 756 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(generator, file, func_info, generics);

                        #line 758 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 759 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        } else {
                            #line 761 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        }

                        #line 764 "src/compiler/DefinitionWriter.pv"
                        generator->indent += 1;

                        #line 766 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 767 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "struct ");
                        #line 768 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(generator, file, func_info, generics);

                        #line 770 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 771 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
                        } else {
                            #line 773 "src/compiler/DefinitionWriter.pv"
                            if (module->mode_cpp) {
                                #line 774 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = (struct ");
                                #line 775 "src/compiler/DefinitionWriter.pv"
                                Generator__write_function_name(generator, file, func_info, generics);
                                #line 776 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance*)__self;\n");
                            } else {
                                #line 778 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = __self;\n");
                            }
                        }

                        #line 782 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 783 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "switch (index) {\n");
                        #line 784 "src/compiler/DefinitionWriter.pv"
                        generator->indent += 1;

                        #line 786 "src/compiler/DefinitionWriter.pv"
                        uintptr_t i = 0;
                        #line 787 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 787 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_Parameter__next(&__iter)) {
                            #line 787 "src/compiler/DefinitionWriter.pv"
                            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                            #line 788 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 789 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "case %zu: self->", i);
                            #line 790 "src/compiler/DefinitionWriter.pv"
                            Generator__write_token(generator, file, param->name);
                            #line 791 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, " = ");

                            #line 793 "src/compiler/DefinitionWriter.pv"
                            if (!Generator__is_reference(&param->type)) {
                                #line 794 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "*(");
                                #line 795 "src/compiler/DefinitionWriter.pv"
                                Generator__write_type(generator, file, &param->type, generics);
                                #line 796 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "*)");
                            } else {
                                #line 798 "src/compiler/DefinitionWriter.pv"
                                if (module->mode_cpp) {
                                    #line 799 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, "(");
                                    #line 800 "src/compiler/DefinitionWriter.pv"
                                    Generator__write_type(generator, file, &param->type, generics);
                                    #line 801 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, ")");
                                }
                            }

                            #line 805 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "value; return true;\n");
                            #line 806 "src/compiler/DefinitionWriter.pv"
                            i += 1;
                        } }

                        #line 809 "src/compiler/DefinitionWriter.pv"
                        generator->indent -= 1;
                        #line 810 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 811 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "}\n");

                        #line 813 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(generator, file);
                        #line 814 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "return false;\n");

                        #line 816 "src/compiler/DefinitionWriter.pv"
                        generator->indent -= 1;
                        #line 817 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "}\n");

                        #line 819 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 820 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct Iter_CoroutineStatus ");
                            #line 821 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 822 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

                            #line 824 "src/compiler/DefinitionWriter.pv"
                            generator->indent += 1;

                            #line 826 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 827 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 828 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 829 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

                            #line 831 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 832 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 833 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 834 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
                            #line 835 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 836 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "));\n");

                            #line 838 "src/compiler/DefinitionWriter.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 838 "src/compiler/DefinitionWriter.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 838 "src/compiler/DefinitionWriter.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 839 "src/compiler/DefinitionWriter.pv"
                                Generator__write_indent(generator, file);
                                #line 840 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "instance->");
                                #line 841 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(generator, file, param->name);
                                #line 842 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, " = ");
                                #line 843 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "self->");
                                #line 844 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(generator, file, param->name);
                                #line 845 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, ";\n");
                            } }

                            #line 848 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 849 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "return (struct trait_Iter_CoroutineStatus) { .vtable = &");

                            #line 851 "src/compiler/DefinitionWriter.pv"
                            switch (func_info->parent.type) {
                                #line 852 "src/compiler/DefinitionWriter.pv"
                                case FUNCTION_PARENT__STRUCT: {
                                    #line 852 "src/compiler/DefinitionWriter.pv"
                                    struct Struct* struct_info = func_info->parent.struct_value._0;
                                    #line 853 "src/compiler/DefinitionWriter.pv"
                                    Generator__write_str_title(generator, file, struct_info->name->value);
                                    #line 854 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, "__");
                                } break;
                                #line 856 "src/compiler/DefinitionWriter.pv"
                                default: {
                                } break;
                            }
                            #line 858 "src/compiler/DefinitionWriter.pv"
                            Generator__write_str_title(generator, file, func_info->name->value);

                            #line 860 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

                            #line 862 "src/compiler/DefinitionWriter.pv"
                            generator->indent -= 1;
                            #line 863 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "}\n");
                        } else {
                            #line 865 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "void ");
                            #line 866 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 867 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__execute(void* __self) {\n");

                            #line 869 "src/compiler/DefinitionWriter.pv"
                            generator->indent += 1;

                            #line 871 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 872 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 873 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 874 "src/compiler/DefinitionWriter.pv"
                            if (module->mode_cpp) {
                                #line 875 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = (struct ");
                                #line 876 "src/compiler/DefinitionWriter.pv"
                                Generator__write_function_name(generator, file, func_info, generics);
                                #line 877 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance*)__self;\n");
                            } else {
                                #line 879 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = __self;\n");
                            }

                            #line 882 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(generator, file);
                            #line 883 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 884 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "(");

                            #line 886 "src/compiler/DefinitionWriter.pv"
                            first = true;
                            #line 887 "src/compiler/DefinitionWriter.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 887 "src/compiler/DefinitionWriter.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 887 "src/compiler/DefinitionWriter.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 888 "src/compiler/DefinitionWriter.pv"
                                if (first) {
                                    #line 888 "src/compiler/DefinitionWriter.pv"
                                    first = false;
                                } else {
                                    #line 888 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 889 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "self->");
                                #line 890 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(generator, file, param->name);
                            } }

                            #line 893 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, ");\n");

                            #line 895 "src/compiler/DefinitionWriter.pv"
                            generator->indent -= 1;
                            #line 896 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "}\n");
                        }

                        #line 899 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 900 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct trait_Co_CoroutineStatusVTable ");
                        } else {
                            #line 902 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct trait_FnVTable ");
                        }

                        #line 905 "src/compiler/DefinitionWriter.pv"
                        switch (func_info->parent.type) {
                            #line 906 "src/compiler/DefinitionWriter.pv"
                            case FUNCTION_PARENT__STRUCT: {
                                #line 906 "src/compiler/DefinitionWriter.pv"
                                struct Struct* struct_info = func_info->parent.struct_value._0;
                                #line 907 "src/compiler/DefinitionWriter.pv"
                                Generator__write_str_title(generator, file, struct_info->name->value);
                                #line 908 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__");
                            } break;
                            #line 910 "src/compiler/DefinitionWriter.pv"
                            default: {
                            } break;
                        }
                        #line 912 "src/compiler/DefinitionWriter.pv"
                        Generator__write_str_title(generator, file, func_info->name->value);

                        #line 914 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 915 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__CO");
                        } else {
                            #line 917 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__DYN_FN");
                        }

                        #line 920 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, " = { .get_params = &");
                        #line 921 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(generator, file, func_info, generics);

                        #line 923 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(generator)) {
                            #line 924 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__get_params, .set_arg = &");
                            #line 925 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 926 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__set_arg, .init = &");
                            #line 927 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 928 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__init };\n");
                        } else {
                            #line 930 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__get_params, .set_arg = &");
                            #line 931 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 932 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__set_arg, .execute = &");
                            #line 933 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(generator, file, func_info, generics);
                            #line 934 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__execute };\n");
                        }
                    }

                    #line 938 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 941 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 942 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 943 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 945 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 945 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 945 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 946 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 949 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 951 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 952 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 953 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 954 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_info->name->value.length;
                            #line 955 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                            #line 956 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 959 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 960 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                        #line 961 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 963 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, function_usage);

                        #line 965 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    } }
                }
            }
        } }

        #line 971 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 972 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 972 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 972 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 972 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 973 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 973 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 975 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 976 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, func_info, generics)) {
                    #line 977 "src/compiler/DefinitionWriter.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 978 "src/compiler/DefinitionWriter.pv"
                    fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 979 "src/compiler/DefinitionWriter.pv"
                    return false;
                }

                #line 982 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " {\n");
                #line 983 "src/compiler/DefinitionWriter.pv"
                generator->indent += 1;

                #line 985 "src/compiler/DefinitionWriter.pv"
                DefinitionWriter__write_self_cast(self, file, module, generics);

                #line 987 "src/compiler/DefinitionWriter.pv"
                struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                #line 988 "src/compiler/DefinitionWriter.pv"
                generator->function_context = &func_context;

                #line 990 "src/compiler/DefinitionWriter.pv"
                if (!BlockWriter__write_block(&(struct BlockWriter) { .generator = generator }, file, &func_info->return_type, func_info->body, generics, false, true)) {
                    #line 991 "src/compiler/DefinitionWriter.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 992 "src/compiler/DefinitionWriter.pv"
                    fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 993 "src/compiler/DefinitionWriter.pv"
                    return false;
                }

                #line 996 "src/compiler/DefinitionWriter.pv"
                generator->indent -= 1;
                #line 997 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 998 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "}\n");

                #line 1000 "src/compiler/DefinitionWriter.pv"
                generator->function_context = 0;
            } }
        }

        #line 1004 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1004 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1004 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1005 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1006 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1007 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1008 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1009 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1010 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 1011 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1012 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression(&(struct ExpressionWriter) { .generator = generator }, file, impl_const->value, generics);
            #line 1013 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1017 "src/compiler/DefinitionWriter.pv"
    return true;
}
