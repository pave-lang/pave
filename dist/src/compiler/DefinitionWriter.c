#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>
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
#include <analyzer/Impl.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <analyzer/Naming.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/Token.h>
#include <analyzer/Context.h>
#include <analyzer/types/FunctionType.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/Generics.h>
#include <compiler/FunctionContext.h>
#include <std/HashMap_str_ref_Type.h>
#include <compiler/FunctionCoroutine.h>
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
#include <usize.h>
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
#include <compiler/TypeUsage_Enum.h>
#include <analyzer/c/ParentCpp.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/Struct.h>
#include <std/ArenaAllocator.h>
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
    struct GenericMap* default_generics = Generator__trait_default_generics(self->generator, impl_info, generics);
    #line 65 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 65 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 65 "src/compiler/DefinitionWriter.pv"
        struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
        #line 65 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 66 "src/compiler/DefinitionWriter.pv"
        if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
            #line 66 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 68 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
        #line 69 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, default_generics)) {
            #line 69 "src/compiler/DefinitionWriter.pv"
            return false;
        }
        #line 70 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }
    #line 72 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 75 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_instance_header(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct str struct_name, struct GenericMap* generics, bool is_coroutine) {
    #line 76 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 77 "src/compiler/DefinitionWriter.pv"
    if (is_coroutine) {
        #line 78 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 79 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Co_");
        #line 80 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 81 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ".h>\n");
        #line 82 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 83 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 84 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 85 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 86 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance { ");
        #line 87 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;
        #line 88 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 88 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 88 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 89 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 90 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 91 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 92 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "; ");
        } }
        #line 94 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 95 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
        #line 96 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 97 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_");
        #line 98 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 99 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 100 "src/compiler/DefinitionWriter.pv"
        Generator__write_dynamic_vtable_name(generator, file, func_info, generics);
        #line 101 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO;\n");
    } else {
        #line 103 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Fn.h>\n");
        #line 104 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 105 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 106 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__Instance { ");
        #line 107 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;
        #line 108 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 108 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 108 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 109 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 110 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 111 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 112 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "; ");
        } }
        #line 114 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 115 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
        #line 116 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 117 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
        #line 118 "src/compiler/DefinitionWriter.pv"
        Generator__write_dynamic_vtable_name(generator, file, func_info, generics);
        #line 119 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN;\n");
    }
}

#line 123 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_definition(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 124 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 125 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, func_info->context, func_info->name);

    #line 127 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 129 "src/compiler/DefinitionWriter.pv"
    bool is_pointer_field = false;
    #line 130 "src/compiler/DefinitionWriter.pv"
    if (custom_name != 0) {
        #line 131 "src/compiler/DefinitionWriter.pv"
        struct String custom = *custom_name;
        #line 132 "src/compiler/DefinitionWriter.pv"
        is_pointer_field = str__starts_with(String__as_str(&custom), (struct str){ .ptr = "(*", .length = strlen("(*") });
    }
    #line 134 "src/compiler/DefinitionWriter.pv"
    if (generator->current_host && !is_pointer_field) {
        #line 134 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "PAVE_HOST_API ");
    }

    #line 136 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 137 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "bool");
    } else {
        #line 139 "src/compiler/DefinitionWriter.pv"
        if (!Generator__write_type(generator, file, &func_info->return_type, generics)) {
            #line 139 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 142 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 143 "src/compiler/DefinitionWriter.pv"
    if (custom_name != 0) {
        #line 144 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, custom_name);
    } else {
        #line 146 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.map.length > 0) {
            #line 147 "src/compiler/DefinitionWriter.pv"
            struct String name = Naming__get_type_name(&generator->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
            #line 148 "src/compiler/DefinitionWriter.pv"
            Generator__write_string(generator, file, &name);
        } else {
            #line 150 "src/compiler/DefinitionWriter.pv"
            if (!Generator__write_function_name(generator, file, func_info, generics)) {
                #line 150 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }
    }

    #line 154 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 155 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 156 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 159 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "(");

    #line 161 "src/compiler/DefinitionWriter.pv"
    bool success = true;
    #line 162 "src/compiler/DefinitionWriter.pv"
    bool first = true;

    #line 164 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 164 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 164 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter_iter = Iter_ref_Parameter__value(&__iter);

        #line 165 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 165 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 165 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }

        #line 167 "src/compiler/DefinitionWriter.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 168 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 170 "src/compiler/DefinitionWriter.pv"
            struct Token parameter_name = *parameter_iter->name;
            #line 171 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, parameter_name.value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 175 "src/compiler/DefinitionWriter.pv"
    if (func_info->variadic && !func_info->typed_variadic) {
        #line 176 "src/compiler/DefinitionWriter.pv"
        if (!first) {
            #line 176 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 177 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "...");
    }

    #line 180 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ")");
    #line 181 "src/compiler/DefinitionWriter.pv"
    return success;
}

#line 184 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 185 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 186 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 187 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 188 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 189 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 191 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 192 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 194 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 195 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 196 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 198 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext* function_context = generator->function_context;
    #line 199 "src/compiler/DefinitionWriter.pv"
    if (function_context == 0) {
        #line 200 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing function context in write_function_coroutine\n");
        #line 201 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 204 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&function_context->coroutine.variables);
    #line 204 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 204 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 204 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 205 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 206 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 207 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 208 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, name);
        #line 209 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 212 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 213 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 215 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 217 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 218 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);

    #line 220 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 222 "src/compiler/DefinitionWriter.pv"
    if (generator->current_host) {
        #line 222 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "PAVE_HOST_API ");
    }
    #line 223 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 224 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 225 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 226 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 228 "src/compiler/DefinitionWriter.pv"
    Generator__write_extern(generator, file);
    #line 229 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct trait_Iter_");
    #line 230 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 231 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 233 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 234 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 235 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 237 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 240 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct UsageContext* function_usage_context) {
    #line 241 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 242 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = generator };

    #line 244 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 245 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 246 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 248 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 249 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 250 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 251 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 253 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 254 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");

        #line 256 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 257 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 258 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 260 "src/compiler/DefinitionWriter.pv"
        uintptr_t yield_count = 0;
        #line 261 "src/compiler/DefinitionWriter.pv"
        if (function_usage_context != 0) {
            #line 262 "src/compiler/DefinitionWriter.pv"
            yield_count = function_usage_context->function_context.coroutine.yield_count;
        }
        #line 264 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i != yield_count + 1; i < yield_count + 1 ? i++ : i--) {
            #line 265 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 266 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 269 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 270 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 272 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 273 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 274 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 276 "src/compiler/DefinitionWriter.pv"
        struct FunctionContext* function_context = generator->function_context;
        #line 277 "src/compiler/DefinitionWriter.pv"
        if (function_context == 0) {
            #line 278 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Missing function context in write_function_block\n");
            #line 279 "src/compiler/DefinitionWriter.pv"
            return false;
        }
        #line 281 "src/compiler/DefinitionWriter.pv"
        function_context->coroutine.yield_count = 0;
        #line 282 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 283 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 284 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 285 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 286 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 289 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 290 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 292 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 293 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 295 "src/compiler/DefinitionWriter.pv"
        if (generator->current_host) {
            #line 295 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "PAVE_HOST_API ");
        }
        #line 296 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &func_info->return_type, generics);
        #line 297 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 298 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 299 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 300 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 301 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 303 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 305 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 306 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &name);
        #line 307 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 309 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 310 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);

        #line 312 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .fn_next = ");
        #line 313 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 314 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .fn_value = ");
        #line 315 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 316 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 318 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 321 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 322 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 323 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 324 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 325 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 326 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 329 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 332 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 333 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 334 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 335 "src/compiler/DefinitionWriter.pv"
    struct Token enum_name = *enum_info->name;
    #line 336 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 337 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 338 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 340 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, &enum_name);

    #line 342 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 343 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 344 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name.value);
        #line 345 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 346 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 348 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 350 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 351 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 353 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 355 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 356 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 357 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 358 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 359 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 360 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 361 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 362 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 364 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 365 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, &enum_name);
            #line 366 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 367 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 369 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 371 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 373 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 374 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 375 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 376 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 379 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 380 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 382 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 383 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 384 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 385 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 387 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 387 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 387 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 388 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 389 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 390 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 393 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 394 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 395 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 396 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 398 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 399 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 400 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 401 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 402 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 405 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 406 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 406 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 406 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 407 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 410 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 411 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 412 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 413 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 416 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 416 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 416 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 417 "src/compiler/DefinitionWriter.pv"
            if (variant->names.length > 0) {
                #line 418 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 419 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 421 "src/compiler/DefinitionWriter.pv"
                uintptr_t i = 0;
                #line 422 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 422 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 422 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 423 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 424 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " ");
                    #line 425 "src/compiler/DefinitionWriter.pv"
                    Generator__write_str(generator, file, variant->names.data[i]);
                    #line 426 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "; ");
                    #line 427 "src/compiler/DefinitionWriter.pv"
                    i += 1;
                } }

                #line 430 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 431 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, variant->name->value);
                #line 432 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (usize__Eq_usize__eq(variant->types.length, 1)) {
                #line 434 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 435 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 436 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 437 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 438 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 439 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 441 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 442 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 444 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 444 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 444 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 445 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 446 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 449 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 450 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 451 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 452 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 456 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 457 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 458 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 459 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 462 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 463 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 466 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 467 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 469 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 469 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 469 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 469 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 470 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 471 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 472 "src/compiler/DefinitionWriter.pv"
        if (usage_context->impl_functions.length > impl_index) {
            #line 472 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage_context->impl_functions, impl_index);
        }

        #line 474 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 474 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 474 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 475 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 476 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 477 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 477 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 479 "src/compiler/DefinitionWriter.pv"
            if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                #line 480 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 481 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 482 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 482 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 484 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 484 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }
                #line 486 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");

                #line 488 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->impl_dynamic_function) {
                    #line 489 "src/compiler/DefinitionWriter.pv"
                    DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                }
            }

            #line 493 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 494 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage usage_info = *function_usage;
                #line 495 "src/compiler/DefinitionWriter.pv"
                if (func_info->generics.array.length > 0) {
                    #line 496 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage_info.usage_contexts);
                    #line 496 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 496 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext usage_context = *Iter_ref_UsageContext__value(&__iter);

                        #line 497 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context.signature, usage_context.generic_map, false);
                        #line 498 "src/compiler/DefinitionWriter.pv"
                        usage_context.generic_map->self_type = generics->self_type;
                        #line 499 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 500 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context.generic_map, 0)) {
                            #line 500 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }
                        #line 501 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, ";\n");

                        #line 503 "src/compiler/DefinitionWriter.pv"
                        if (usage_context.impl_dynamic_function) {
                            #line 504 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, usage_context.generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                        }
                    } }
                }
            }
        } }

        #line 511 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 512 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 512 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 515 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 515 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 515 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 516 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
            #line 517 "src/compiler/DefinitionWriter.pv"
            Generator__write_extern(generator, file);
            #line 518 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "const ");
            #line 519 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 520 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 521 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 522 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 523 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 524 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 525 "src/compiler/DefinitionWriter.pv"
            Generator__write_array_decl_suffix(generator, file, &impl_const->type, generics);
            #line 526 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 530 "src/compiler/DefinitionWriter.pv"
    if (usage != 0 && usage->impl_dynamic_usage) {
        #line 531 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Enum.h>\n");
        #line 532 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 533 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_EnumVTable ");
        #line 534 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 535 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ENUM;\n");
    }

    #line 538 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 543 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__is_cpp_type(struct Type* type) {
    #line 544 "src/compiler/DefinitionWriter.pv"
    switch (type->type) {
        #line 545 "src/compiler/DefinitionWriter.pv"
        case TYPE__CLASS_CPP: {
            #line 545 "src/compiler/DefinitionWriter.pv"
            return true;
        } break;
        #line 546 "src/compiler/DefinitionWriter.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 546 "src/compiler/DefinitionWriter.pv"
            return true;
        } break;
        #line 547 "src/compiler/DefinitionWriter.pv"
        case TYPE__ENUM_C: {
            #line 547 "src/compiler/DefinitionWriter.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 547 "src/compiler/DefinitionWriter.pv"
            return !ParentCpp__is_none(&enum_info->parent);
        } break;
        #line 548 "src/compiler/DefinitionWriter.pv"
        case TYPE__TYPEDEF_C: {
            #line 548 "src/compiler/DefinitionWriter.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 548 "src/compiler/DefinitionWriter.pv"
            return DefinitionWriter__is_cpp_type(typedef_info->type);
        } break;
        #line 549 "src/compiler/DefinitionWriter.pv"
        case TYPE__INDIRECT: {
            #line 549 "src/compiler/DefinitionWriter.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 549 "src/compiler/DefinitionWriter.pv"
            return DefinitionWriter__is_cpp_type(&indirect->to);
        } break;
        #line 550 "src/compiler/DefinitionWriter.pv"
        default: {
        } break;
    }
    #line 552 "src/compiler/DefinitionWriter.pv"
    return false;
}

#line 556 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__is_cpp_pointer(struct Type* type) {
    #line 557 "src/compiler/DefinitionWriter.pv"
    switch (type->type) {
        #line 558 "src/compiler/DefinitionWriter.pv"
        case TYPE__INDIRECT: {
            #line 558 "src/compiler/DefinitionWriter.pv"
            return true;
        } break;
        #line 559 "src/compiler/DefinitionWriter.pv"
        case TYPE__TYPEDEF_C: {
            #line 559 "src/compiler/DefinitionWriter.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 559 "src/compiler/DefinitionWriter.pv"
            return DefinitionWriter__is_cpp_pointer(typedef_info->type);
        } break;
        #line 560 "src/compiler/DefinitionWriter.pv"
        default: {
        } break;
    }
    #line 562 "src/compiler/DefinitionWriter.pv"
    return false;
}

#line 565 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__has_cpp_signature(struct Function* func_info) {
    #line 566 "src/compiler/DefinitionWriter.pv"
    if (DefinitionWriter__is_cpp_type(&func_info->return_type)) {
        #line 566 "src/compiler/DefinitionWriter.pv"
        return true;
    }
    #line 567 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 567 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 567 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter = Iter_ref_Parameter__value(&__iter);

        #line 568 "src/compiler/DefinitionWriter.pv"
        if (DefinitionWriter__is_cpp_type(&parameter->type)) {
            #line 568 "src/compiler/DefinitionWriter.pv"
            return true;
        }
    } }
    #line 570 "src/compiler/DefinitionWriter.pv"
    return false;
}

#line 573 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 574 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 575 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 576 "src/compiler/DefinitionWriter.pv"
    struct Token struct_name = *struct_info->name;
    #line 577 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 578 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 579 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage_context->impl_functions;
    #line 580 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 582 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, &struct_name);

    #line 584 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 585 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 587 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 588 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 589 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 590 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 592 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 593 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 595 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 595 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 595 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 596 "src/compiler/DefinitionWriter.pv"
            struct Token field_name = *field->name;
            #line 599 "src/compiler/DefinitionWriter.pv"
            if (DefinitionWriter__is_cpp_type(&field->type)) {
                #line 600 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__is_cpp_pointer(&field->type)) {
                    #line 601 "src/compiler/DefinitionWriter.pv"
                    fprintf(stderr, "%.*s.%.*s: a struct C can see holds a C++ type only by pointer\n", name_length, name.array.data, (int32_t)(field_name.value.length), field_name.value.ptr);
                    #line 603 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 605 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "#ifdef __cplusplus\n");
                #line 606 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 607 "src/compiler/DefinitionWriter.pv"
                Generator__write_variable_decl(generator, file, field_name.value, &field->type, generics);
                #line 608 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n#else\n");
                #line 609 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 610 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "void* ");
                #line 611 "src/compiler/DefinitionWriter.pv"
                Generator__write_str(generator, file, field_name.value);
                #line 612 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n#endif\n");
                #line 613 "src/compiler/DefinitionWriter.pv"
                continue;
            }
            #line 615 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 616 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field_name.value, &field->type, generics);
            #line 617 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 620 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 621 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 624 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 624 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 628 "src/compiler/DefinitionWriter.pv"
    bool reopen_c_linkage = usage_context->signature.length > 0 && (struct_info->module->mode_cpp || generator->root->mode_cpp);
    #line 629 "src/compiler/DefinitionWriter.pv"
    if (reopen_c_linkage) {
        #line 629 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#ifdef __cplusplus\n}\n#endif\n");
    }
    #line 630 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);
    #line 631 "src/compiler/DefinitionWriter.pv"
    if (reopen_c_linkage) {
        #line 631 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    }

    #line 633 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 633 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 633 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 633 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 634 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 635 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 636 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 636 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 638 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 638 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 638 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 639 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 640 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 641 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 641 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 643 "src/compiler/DefinitionWriter.pv"
            if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                #line 644 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 645 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0 && function_usage->usage_contexts.length > 0) {
                        #line 646 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &function_usage->usage_contexts.data[0].function_context;
                        #line 647 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 648 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 651 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 653 "src/compiler/DefinitionWriter.pv"
                    bool cpp_only = DefinitionWriter__has_cpp_signature(func_info);
                    #line 654 "src/compiler/DefinitionWriter.pv"
                    if (cpp_only) {
                        #line 654 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "#ifdef __cplusplus\n");
                    }
                    #line 655 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 655 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 656 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                    #line 657 "src/compiler/DefinitionWriter.pv"
                    if (cpp_only) {
                        #line 657 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "#endif\n");
                    }
                } else {
                    #line 659 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 660 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 660 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 661 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                }
            }

            #line 665 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 666 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 667 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 668 "src/compiler/DefinitionWriter.pv"
                    if (func_info->generics.array.length > 0) {
                        #line 669 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                        #line 669 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_UsageContext__next(&__iter)) {
                            #line 669 "src/compiler/DefinitionWriter.pv"
                            struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                            #line 670 "src/compiler/DefinitionWriter.pv"
                            IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                            #line 673 "src/compiler/DefinitionWriter.pv"
                            usage_context->generic_map->self_type = generics->self_type;
                            #line 674 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "\n");
                            #line 675 "src/compiler/DefinitionWriter.pv"
                            if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                                #line 675 "src/compiler/DefinitionWriter.pv"
                                return false;
                            }
                            #line 676 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, ";\n");

                            #line 678 "src/compiler/DefinitionWriter.pv"
                            if (usage_context->impl_dynamic_function) {
                                #line 679 "src/compiler/DefinitionWriter.pv"
                                DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, usage_context->generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                            }
                        } }
                    }

                    #line 684 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function && usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                        #line 685 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 691 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 692 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 692 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 695 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 695 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 695 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 696 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
            #line 697 "src/compiler/DefinitionWriter.pv"
            Generator__write_extern(generator, file);
            #line 698 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "const ");
            #line 699 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 700 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 701 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 702 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 703 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 704 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 705 "src/compiler/DefinitionWriter.pv"
            Generator__write_array_decl_suffix(generator, file, &impl_const->type, generics);
            #line 706 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 710 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 710 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 712 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 712 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 712 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 713 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 714 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 715 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 715 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 716 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 716 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 717 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 718 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 719 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 720 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 721 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 722 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 723 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 724 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 727 "src/compiler/DefinitionWriter.pv"
    if (usage != 0 && usage->impl_dynamic_usage) {
        #line 728 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 729 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 730 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_StructVTable ");
        #line 731 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 732 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 735 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 738 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 739 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 741 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 743 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 743 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 743 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 744 "src/compiler/DefinitionWriter.pv"
        if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
            #line 745 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 746 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 746 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 748 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
                    #line 748 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 751 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 755 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 756 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 756 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 759 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 762 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 763 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 764 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 766 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 766 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 766 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 767 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 770 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->impls.length > 0) {
        #line 770 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 772 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 772 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 772 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 773 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 774 "src/compiler/DefinitionWriter.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 774 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 776 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 777 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 777 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 779 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 779 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 781 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 782 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 783 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, &impl_info->trait_type, generics);
        #line 784 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 785 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 786 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 787 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 788 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 791 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 794 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 795 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 796 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 797 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 799 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 800 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 802 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 803 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 805 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 806 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 808 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 808 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 808 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 809 "src/compiler/DefinitionWriter.pv"
        if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
            #line 810 "src/compiler/DefinitionWriter.pv"
            struct Token* name = func_info->name;
            #line 811 "src/compiler/DefinitionWriter.pv"
            if (name == 0) {
                #line 812 "src/compiler/DefinitionWriter.pv"
                fprintf(stderr, "Missing function name in write_trait_definition\n");
                #line 813 "src/compiler/DefinitionWriter.pv"
                return false;
            }

            #line 816 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 817 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*fn_", .length = strlen("(*fn_") });
            #line 818 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, name->value);
            #line 819 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 821 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 821 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 822 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 826 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 827 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 829 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 831 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 832 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 834 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 835 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 836 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 837 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 839 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 840 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 842 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 845 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_with_body(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct Trait* trait_info, struct Type* impl_trait_type, struct GenericMap* generics, struct Module* module, struct UsageContext* function_usage_context) {
    #line 846 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 847 "src/compiler/DefinitionWriter.pv"
    if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, impl_trait_type, func_info, generics)) {
        #line 848 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 849 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 850 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 851 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 852 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 855 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 856 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 860 "src/compiler/DefinitionWriter.pv"
    struct GenericMap generics_void = *generics;
    #line 861 "src/compiler/DefinitionWriter.pv"
    generics_void.self_type = &generator->root->type_void;
    #line 862 "src/compiler/DefinitionWriter.pv"
    if (func_info->parameters.length > 0 && Generator__has_void_self_replacement(&func_info->parameters.data[0], &generics_void)) {
        #line 863 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_self_cast(self, file, module, generics);
    }

    #line 866 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 867 "src/compiler/DefinitionWriter.pv"
    if (function_usage_context != 0) {
        #line 868 "src/compiler/DefinitionWriter.pv"
        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
    }
    #line 870 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;

    #line 872 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, file, &func_info->return_type, func_info->body, generics, false, true)) {
        #line 873 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 874 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 875 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 876 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 877 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 880 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 881 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 882 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 884 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 885 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 888 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_size(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 889 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 890 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "uintptr_t ");
    #line 891 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 892 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__size(void* __self) {\n");

    #line 894 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 895 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 896 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return sizeof(struct ");
    #line 897 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 898 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__Instance);\n");
    #line 899 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 900 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 903 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_get_params(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 904 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 905 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/Array_TypeId.h>\n");
    #line 906 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct Array_TypeId* ");
    #line 907 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 909 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 910 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params(void* __self) {\n");
    } else {
        #line 912 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params(void* __self) {\n");
    }

    #line 915 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 916 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 917 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static TypeId type_ids[] = { ");

    #line 919 "src/compiler/DefinitionWriter.pv"
    bool first = true;
    #line 920 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 920 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 920 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 921 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 921 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 921 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 922 "src/compiler/DefinitionWriter.pv"
        Generator__write_typeid(generator, file, &param->type, generics);
    } }

    #line 925 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " };\n");
    #line 926 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 927 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
    #line 928 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 929 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return &result;\n");
    #line 930 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 931 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 934 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_set_arg(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 935 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 936 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "bool ");
    #line 937 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 939 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 940 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
    } else {
        #line 942 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
    }

    #line 945 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 947 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 948 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 949 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 951 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 952 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 953 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 954 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 955 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance* self = __self;\n");
    } else {
        #line 957 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 958 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 959 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 960 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 962 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }
    }

    #line 966 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 967 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "switch (index) {\n");
    #line 968 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 970 "src/compiler/DefinitionWriter.pv"
    uintptr_t i = 0;
    #line 971 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 971 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 971 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 972 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 973 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case %zu: self->", i);
        #line 974 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 975 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = ");

        #line 977 "src/compiler/DefinitionWriter.pv"
        if (!Generator__is_reference(&param->type)) {
            #line 978 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*(");
            #line 979 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 980 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*)");
        } else {
            #line 982 "src/compiler/DefinitionWriter.pv"
            if (module->mode_cpp) {
                #line 983 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "(");
                #line 984 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, &param->type, generics);
                #line 985 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ")");
            }
        }

        #line 989 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "value; return true;\n");
        #line 990 "src/compiler/DefinitionWriter.pv"
        i += 1;
    } }

    #line 993 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 994 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 995 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 997 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 998 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return false;\n");

    #line 1000 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 1001 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 1004 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_execute_or_init(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 1005 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1006 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1007 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 1008 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");
        #line 1009 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1010 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 1011 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1012 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init(void* __self, struct trait_Allocator allocator) {\n");

        #line 1014 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 1016 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1017 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 1018 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1019 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 1020 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1021 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance* self = __self;\n");

        #line 1023 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1024 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 1025 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1026 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* instance = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct ");
        #line 1027 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1028 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "));\n");

        #line 1030 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 1030 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 1030 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 1031 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 1032 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "instance->");
            #line 1033 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 1034 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = self->");
            #line 1035 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 1036 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 1039 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1040 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "return (struct trait_Iter_");
        #line 1041 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1042 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ") { .vtable = &");
        #line 1043 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1044 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

        #line 1046 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 1047 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    } else {
        #line 1049 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "void ");
        #line 1050 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1051 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute(void* __self) {\n");

        #line 1053 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 1055 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1056 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 1057 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1058 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 1059 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 1060 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 1061 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 1063 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }

        #line 1066 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1067 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1068 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");

        #line 1070 "src/compiler/DefinitionWriter.pv"
        bool first = true;
        #line 1071 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 1071 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 1071 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 1072 "src/compiler/DefinitionWriter.pv"
            if (first) {
                #line 1072 "src/compiler/DefinitionWriter.pv"
                first = false;
            } else {
                #line 1072 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ", ");
            }
            #line 1073 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "self->");
            #line 1074 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
        } }

        #line 1077 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ");\n");

        #line 1079 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 1080 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    }
}

#line 1084 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_vtable(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 1085 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1086 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1087 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 1088 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_");
        #line 1089 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1090 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
    } else {
        #line 1092 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
    }

    #line 1095 "src/compiler/DefinitionWriter.pv"
    Generator__write_dynamic_vtable_name(generator, file, func_info, generics);

    #line 1097 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1098 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO");
    } else {
        #line 1100 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN");
    }

    #line 1103 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1104 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_get_params = &");
        #line 1105 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1106 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params, .fn_set_arg = &");
        #line 1107 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1108 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg, .fn_init = &");
        #line 1109 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1110 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init };\n");
    } else {
        #line 1112 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_size = &");
        #line 1113 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1114 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__size, .fn_get_params = &");
        #line 1115 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1116 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params, .fn_set_arg = &");
        #line 1117 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1118 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg, .fn_execute = &");
        #line 1119 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1120 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute };\n");
    }
}

#line 1124 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_impl(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 1125 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1126 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 1127 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1128 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Allocator.h>\n");
    }
    #line 1130 "src/compiler/DefinitionWriter.pv"
    if (!Generator__is_coroutine(generator)) {
        #line 1130 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_dynamic_size(self, file, func_info, generics);
    }
    #line 1131 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_get_params(self, file, func_info, generics);
    #line 1132 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_set_arg(self, file, func_info, generics, module);
    #line 1133 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_execute_or_init(self, file, func_info, generics, module);
    #line 1134 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_vtable(self, file, func_info, generics);
}

#line 1137 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 1138 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1139 "src/compiler/DefinitionWriter.pv"
    struct Type* self_type = generics->self_type;
    #line 1140 "src/compiler/DefinitionWriter.pv"
    if (self_type == 0) {
        #line 1141 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing self type in write_impls\n");
        #line 1142 "src/compiler/DefinitionWriter.pv"
        return false;
    }
    #line 1144 "src/compiler/DefinitionWriter.pv"
    struct Type* named_self_type = self_type;
    #line 1145 "src/compiler/DefinitionWriter.pv"
    if (Type__is_fat_pointer(self_type)) {
        #line 1146 "src/compiler/DefinitionWriter.pv"
        named_self_type = Type__deref_1(self_type);
        #line 1147 "src/compiler/DefinitionWriter.pv"
        if (named_self_type == 0) {
            #line 1147 "src/compiler/DefinitionWriter.pv"
            named_self_type = self_type;
        }
    }
    #line 1149 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, named_self_type, self_type, generics);
    #line 1150 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 1151 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 1153 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 1155 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 1155 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 1155 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 1155 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 1156 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 1157 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 1158 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 1158 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 1160 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 1160 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 1160 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 1161 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 1162 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 1163 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 1163 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 1165 "src/compiler/DefinitionWriter.pv"
            if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                #line 1168 "src/compiler/DefinitionWriter.pv"
                struct UsageContext* function_usage_context = 0;
                #line 1169 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->usage_contexts.length > 0) {
                    #line 1170 "src/compiler/DefinitionWriter.pv"
                    function_usage_context = &function_usage->usage_contexts.data[0];
                }

                #line 1173 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1174 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 1175 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, function_usage_context)) {
                        #line 1175 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 1177 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 1178 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1179 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1180 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1181 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1184 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 1185 "src/compiler/DefinitionWriter.pv"
                    if (function_usage_context != 0) {
                        #line 1186 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
                    }
                    #line 1188 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 1190 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage_context)) {
                        #line 1191 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1192 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1193 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1194 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1197 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 1198 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics, module);
                    }

                    #line 1201 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 1204 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 1205 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 1206 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 1208 "src/compiler/DefinitionWriter.pv"
                    for (uintptr_t i = 0; i != function_usage->usage_contexts.length; i < function_usage->usage_contexts.length ? i++ : i--) {
                        #line 1209 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = &function_usage->usage_contexts.data[i];
                        #line 1210 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 1213 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 1215 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 1216 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 1217 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 1218 "src/compiler/DefinitionWriter.pv"
                            struct Token func_name = *func_info->name;
                            #line 1219 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_name.value.length;
                            #line 1220 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                            #line 1221 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 1224 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 1225 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = usage_context->function_context.coroutine.yield_count;
                        #line 1226 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 1228 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, usage_context);

                        #line 1230 "src/compiler/DefinitionWriter.pv"
                        if (usage_context->impl_dynamic_function) {
                            #line 1231 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics3, module);
                        }

                        #line 1234 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }
                }
            }
        } }

        #line 1240 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 1241 "src/compiler/DefinitionWriter.pv"
            struct GenericMap* default_generics = Generator__trait_default_generics(generator, impl_info, generics);
            #line 1242 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 1242 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 1242 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 1242 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 1243 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 1243 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 1245 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1246 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, default_generics, module, 0)) {
                    #line 1246 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } }
        }

        #line 1250 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1250 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1250 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1251 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1252 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1253 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1254 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1255 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1256 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 1257 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 1258 "src/compiler/DefinitionWriter.pv"
            Generator__write_array_decl_suffix(generator, file, &impl_const->type, generics);
            #line 1259 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1260 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, impl_const->value, generics);
            #line 1261 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1265 "src/compiler/DefinitionWriter.pv"
    return true;
}
