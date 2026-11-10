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
#include <std/ArenaAllocator.h>
#include <compiler/BlockWriter.h>
#include <analyzer/Block.h>
#include <std/HashMap_str_ref_Type.h>
#include <compiler/FunctionCoroutine.h>
#include <std/HashMapIter_str_ref_Type.h>
#include <tuple_str_ref_Type.h>
#include <compiler/UsageContext.h>
#include <std/Range_usize.h>
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

#line 187 "src/compiler/DefinitionWriter.pv"
struct FunctionContext DefinitionWriter__find_coroutine_variables(struct DefinitionWriter* self, struct Function* func_info, struct GenericMap* generics) {
    #line 188 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 189 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);

    #line 191 "src/compiler/DefinitionWriter.pv"
    FILE* scratch = Generator__scratch_file(generator);
    #line 192 "src/compiler/DefinitionWriter.pv"
    if (scratch == 0) {
        #line 192 "src/compiler/DefinitionWriter.pv"
        return func_context;
    }

    #line 194 "src/compiler/DefinitionWriter.pv"
    int16_t indent = generator->indent;
    #line 195 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;
    #line 196 "src/compiler/DefinitionWriter.pv"
    BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, scratch, &func_info->return_type, func_info->body, generics, false, true);
    #line 197 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 198 "src/compiler/DefinitionWriter.pv"
    generator->indent = indent;

    #line 200 "src/compiler/DefinitionWriter.pv"
    return func_context;
}

#line 203 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 204 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 205 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 206 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 207 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 208 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 210 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 211 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 213 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 214 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 215 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 217 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext* function_context = generator->function_context;
    #line 218 "src/compiler/DefinitionWriter.pv"
    if (function_context == 0) {
        #line 219 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing function context in write_function_coroutine\n");
        #line 220 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 223 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&function_context->coroutine.variables);
    #line 223 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 223 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 223 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 224 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 225 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 226 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 227 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, name);
        #line 228 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 231 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 232 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 234 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 236 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 237 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);

    #line 239 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 241 "src/compiler/DefinitionWriter.pv"
    if (generator->current_host) {
        #line 241 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "PAVE_HOST_API ");
    }
    #line 242 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 243 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 244 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 245 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 247 "src/compiler/DefinitionWriter.pv"
    Generator__write_extern(generator, file);
    #line 248 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct trait_Iter_");
    #line 249 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 250 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 252 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 253 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 254 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 256 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 259 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct UsageContext* function_usage_context) {
    #line 260 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 261 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = generator };

    #line 263 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 264 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 265 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 267 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 268 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 269 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 270 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 272 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 273 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");

        #line 275 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 276 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 277 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 279 "src/compiler/DefinitionWriter.pv"
        uintptr_t yield_count = 0;
        #line 280 "src/compiler/DefinitionWriter.pv"
        if (function_usage_context != 0) {
            #line 281 "src/compiler/DefinitionWriter.pv"
            yield_count = function_usage_context->function_context.coroutine.yield_count;
        }
        #line 283 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i != yield_count + 1; i < yield_count + 1 ? i++ : i--) {
            #line 284 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 285 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 288 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 289 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 291 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 292 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 293 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 295 "src/compiler/DefinitionWriter.pv"
        struct FunctionContext* function_context = generator->function_context;
        #line 296 "src/compiler/DefinitionWriter.pv"
        if (function_context == 0) {
            #line 297 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Missing function context in write_function_block\n");
            #line 298 "src/compiler/DefinitionWriter.pv"
            return false;
        }
        #line 300 "src/compiler/DefinitionWriter.pv"
        function_context->coroutine.yield_count = 0;
        #line 301 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 302 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 303 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 304 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 305 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 308 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 309 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 311 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 312 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 314 "src/compiler/DefinitionWriter.pv"
        if (generator->current_host) {
            #line 314 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "PAVE_HOST_API ");
        }
        #line 315 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &func_info->return_type, generics);
        #line 316 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 317 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 318 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 319 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 320 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 322 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 324 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 325 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &name);
        #line 326 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 328 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 329 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);

        #line 331 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .fn_next = ");
        #line 332 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 333 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .fn_value = ");
        #line 334 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 335 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 337 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 340 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 341 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 342 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 343 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 344 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 345 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 348 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 351 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 352 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 353 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 354 "src/compiler/DefinitionWriter.pv"
    struct Token enum_name = *enum_info->name;
    #line 355 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 356 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 357 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 359 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, &enum_name);

    #line 361 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 362 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 363 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name.value);
        #line 364 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 365 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 367 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 369 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 370 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 372 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 374 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 375 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 376 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 377 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 378 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 379 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 380 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 381 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 383 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 384 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, &enum_name);
            #line 385 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 386 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 388 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 390 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 392 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 393 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 394 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 395 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 398 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 399 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 401 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 402 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 403 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 404 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 406 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 406 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 406 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 407 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 408 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 409 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 412 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 413 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 414 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 415 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 417 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 418 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 419 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 420 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 421 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 424 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 425 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 425 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 425 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 426 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 429 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 430 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 431 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 432 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 435 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 435 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 435 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 436 "src/compiler/DefinitionWriter.pv"
            if (variant->names.length > 0) {
                #line 437 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 438 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 440 "src/compiler/DefinitionWriter.pv"
                uintptr_t i = 0;
                #line 441 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 441 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 441 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 442 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 443 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " ");
                    #line 444 "src/compiler/DefinitionWriter.pv"
                    Generator__write_str(generator, file, variant->names.data[i]);
                    #line 445 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "; ");
                    #line 446 "src/compiler/DefinitionWriter.pv"
                    i += 1;
                } }

                #line 449 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 450 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, variant->name->value);
                #line 451 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (usize__Eq_usize__eq(variant->types.length, 1)) {
                #line 453 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 454 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 455 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 456 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 457 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 458 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 460 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 461 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 463 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 463 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 463 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 464 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 465 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 468 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 469 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 470 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 471 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 475 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 476 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 477 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 478 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 481 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 482 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 485 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 486 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 488 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 488 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 488 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 488 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 489 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 490 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 491 "src/compiler/DefinitionWriter.pv"
        if (usage_context->impl_functions.length > impl_index) {
            #line 491 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage_context->impl_functions, impl_index);
        }

        #line 493 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 493 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 493 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 494 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 495 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 496 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 496 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 498 "src/compiler/DefinitionWriter.pv"
            if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                #line 499 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 500 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 501 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 501 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 503 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 503 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }
                #line 505 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");

                #line 507 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->impl_dynamic_function) {
                    #line 508 "src/compiler/DefinitionWriter.pv"
                    DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                }
            }

            #line 512 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 513 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage usage_info = *function_usage;
                #line 514 "src/compiler/DefinitionWriter.pv"
                if (func_info->generics.array.length > 0) {
                    #line 515 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage_info.usage_contexts);
                    #line 515 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 515 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext usage_context = *Iter_ref_UsageContext__value(&__iter);

                        #line 516 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context.signature, usage_context.generic_map, false);
                        #line 517 "src/compiler/DefinitionWriter.pv"
                        usage_context.generic_map->self_type = generics->self_type;
                        #line 518 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 519 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context.generic_map, 0)) {
                            #line 519 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }
                        #line 520 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, ";\n");

                        #line 522 "src/compiler/DefinitionWriter.pv"
                        if (usage_context.impl_dynamic_function) {
                            #line 523 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, usage_context.generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                        }
                    } }
                }
            }
        } }

        #line 530 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 531 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 531 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 534 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 534 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 534 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 535 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
            #line 536 "src/compiler/DefinitionWriter.pv"
            Generator__write_extern(generator, file);
            #line 537 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "const ");
            #line 538 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 539 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 540 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 541 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 542 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 543 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 544 "src/compiler/DefinitionWriter.pv"
            Generator__write_array_decl_suffix(generator, file, &impl_const->type, generics);
            #line 545 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 549 "src/compiler/DefinitionWriter.pv"
    if (usage != 0 && usage->impl_dynamic_usage) {
        #line 550 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Enum.h>\n");
        #line 551 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 552 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_EnumVTable ");
        #line 553 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 554 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ENUM;\n");
    }

    #line 557 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 562 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__is_cpp_type(struct Type* type) {
    #line 563 "src/compiler/DefinitionWriter.pv"
    switch (type->type) {
        #line 564 "src/compiler/DefinitionWriter.pv"
        case TYPE__CLASS_CPP: {
            #line 564 "src/compiler/DefinitionWriter.pv"
            return true;
        } break;
        #line 565 "src/compiler/DefinitionWriter.pv"
        case TYPE__NAMESPACE_CPP: {
            #line 565 "src/compiler/DefinitionWriter.pv"
            return true;
        } break;
        #line 566 "src/compiler/DefinitionWriter.pv"
        case TYPE__ENUM_C: {
            #line 566 "src/compiler/DefinitionWriter.pv"
            struct EnumC* enum_info = type->enumc_value;
            #line 566 "src/compiler/DefinitionWriter.pv"
            return !ParentCpp__is_none(&enum_info->parent);
        } break;
        #line 567 "src/compiler/DefinitionWriter.pv"
        case TYPE__TYPEDEF_C: {
            #line 567 "src/compiler/DefinitionWriter.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 567 "src/compiler/DefinitionWriter.pv"
            return DefinitionWriter__is_cpp_type(typedef_info->type);
        } break;
        #line 568 "src/compiler/DefinitionWriter.pv"
        case TYPE__INDIRECT: {
            #line 568 "src/compiler/DefinitionWriter.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 568 "src/compiler/DefinitionWriter.pv"
            return DefinitionWriter__is_cpp_type(&indirect->to);
        } break;
        #line 569 "src/compiler/DefinitionWriter.pv"
        default: {
        } break;
    }
    #line 571 "src/compiler/DefinitionWriter.pv"
    return false;
}

#line 575 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__is_cpp_pointer(struct Type* type) {
    #line 576 "src/compiler/DefinitionWriter.pv"
    switch (type->type) {
        #line 577 "src/compiler/DefinitionWriter.pv"
        case TYPE__INDIRECT: {
            #line 577 "src/compiler/DefinitionWriter.pv"
            return true;
        } break;
        #line 578 "src/compiler/DefinitionWriter.pv"
        case TYPE__TYPEDEF_C: {
            #line 578 "src/compiler/DefinitionWriter.pv"
            struct TypedefC* typedef_info = type->typedefc_value;
            #line 578 "src/compiler/DefinitionWriter.pv"
            return DefinitionWriter__is_cpp_pointer(typedef_info->type);
        } break;
        #line 579 "src/compiler/DefinitionWriter.pv"
        default: {
        } break;
    }
    #line 581 "src/compiler/DefinitionWriter.pv"
    return false;
}

#line 584 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__has_cpp_signature(struct Function* func_info) {
    #line 585 "src/compiler/DefinitionWriter.pv"
    if (DefinitionWriter__is_cpp_type(&func_info->return_type)) {
        #line 585 "src/compiler/DefinitionWriter.pv"
        return true;
    }
    #line 586 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 586 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 586 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter = Iter_ref_Parameter__value(&__iter);

        #line 587 "src/compiler/DefinitionWriter.pv"
        if (DefinitionWriter__is_cpp_type(&parameter->type)) {
            #line 587 "src/compiler/DefinitionWriter.pv"
            return true;
        }
    } }
    #line 589 "src/compiler/DefinitionWriter.pv"
    return false;
}

#line 592 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 593 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 594 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 595 "src/compiler/DefinitionWriter.pv"
    struct Token struct_name = *struct_info->name;
    #line 596 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 597 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 598 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage_context->impl_functions;
    #line 599 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 601 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, &struct_name);

    #line 603 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 604 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 606 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 607 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 608 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 609 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 611 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 612 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 614 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 614 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 614 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 615 "src/compiler/DefinitionWriter.pv"
            struct Token field_name = *field->name;
            #line 618 "src/compiler/DefinitionWriter.pv"
            if (DefinitionWriter__is_cpp_type(&field->type)) {
                #line 619 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__is_cpp_pointer(&field->type)) {
                    #line 620 "src/compiler/DefinitionWriter.pv"
                    fprintf(stderr, "%.*s.%.*s: a struct C can see holds a C++ type only by pointer\n", name_length, name.array.data, (int32_t)(field_name.value.length), field_name.value.ptr);
                    #line 622 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 624 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "#ifdef __cplusplus\n");
                #line 625 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 626 "src/compiler/DefinitionWriter.pv"
                Generator__write_variable_decl(generator, file, field_name.value, &field->type, generics);
                #line 627 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n#else\n");
                #line 628 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 629 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "void* ");
                #line 630 "src/compiler/DefinitionWriter.pv"
                Generator__write_str(generator, file, field_name.value);
                #line 631 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n#endif\n");
                #line 632 "src/compiler/DefinitionWriter.pv"
                continue;
            }
            #line 634 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 635 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field_name.value, &field->type, generics);
            #line 636 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 639 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 640 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 643 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 643 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 647 "src/compiler/DefinitionWriter.pv"
    bool reopen_c_linkage = usage_context->signature.length > 0 && (struct_info->module->mode_cpp || generator->root->mode_cpp);
    #line 648 "src/compiler/DefinitionWriter.pv"
    if (reopen_c_linkage) {
        #line 648 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#ifdef __cplusplus\n}\n#endif\n");
    }
    #line 649 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);
    #line 650 "src/compiler/DefinitionWriter.pv"
    if (reopen_c_linkage) {
        #line 650 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#ifdef __cplusplus\nextern \"C\" {\n#endif\n");
    }

    #line 652 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 652 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 652 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 652 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 653 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 654 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 655 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 655 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 657 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 657 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 657 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 658 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 659 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 660 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 660 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 662 "src/compiler/DefinitionWriter.pv"
            if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                #line 663 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 664 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0 && function_usage->usage_contexts.length > 0) {
                        #line 665 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = DefinitionWriter__find_coroutine_variables(self, func_info, generics);
                        #line 666 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;
                        #line 667 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 668 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 671 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 673 "src/compiler/DefinitionWriter.pv"
                    bool cpp_only = DefinitionWriter__has_cpp_signature(func_info);
                    #line 674 "src/compiler/DefinitionWriter.pv"
                    if (cpp_only) {
                        #line 674 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "#ifdef __cplusplus\n");
                    }
                    #line 675 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 675 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 676 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                    #line 677 "src/compiler/DefinitionWriter.pv"
                    if (cpp_only) {
                        #line 677 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "#endif\n");
                    }
                } else {
                    #line 679 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 680 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 680 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 681 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                }
            }

            #line 685 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 686 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 687 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 688 "src/compiler/DefinitionWriter.pv"
                    if (func_info->generics.array.length > 0) {
                        #line 689 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                        #line 689 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_UsageContext__next(&__iter)) {
                            #line 689 "src/compiler/DefinitionWriter.pv"
                            struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                            #line 690 "src/compiler/DefinitionWriter.pv"
                            IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                            #line 693 "src/compiler/DefinitionWriter.pv"
                            usage_context->generic_map->self_type = generics->self_type;
                            #line 694 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "\n");
                            #line 695 "src/compiler/DefinitionWriter.pv"
                            if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                                #line 695 "src/compiler/DefinitionWriter.pv"
                                return false;
                            }
                            #line 696 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, ";\n");

                            #line 698 "src/compiler/DefinitionWriter.pv"
                            if (usage_context->impl_dynamic_function) {
                                #line 699 "src/compiler/DefinitionWriter.pv"
                                DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, usage_context->generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                            }
                        } }
                    }

                    #line 704 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function && usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                        #line 705 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 711 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 712 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 712 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 715 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 715 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 715 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 716 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
            #line 717 "src/compiler/DefinitionWriter.pv"
            Generator__write_extern(generator, file);
            #line 718 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "const ");
            #line 719 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 720 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 721 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 722 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 723 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 724 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 725 "src/compiler/DefinitionWriter.pv"
            Generator__write_array_decl_suffix(generator, file, &impl_const->type, generics);
            #line 726 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 730 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 730 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 732 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 732 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 732 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 733 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 734 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 735 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 735 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 736 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 736 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 737 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 738 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 739 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 740 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 741 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 742 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 743 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 744 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 747 "src/compiler/DefinitionWriter.pv"
    if (usage != 0 && usage->impl_dynamic_usage) {
        #line 748 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 749 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 750 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_StructVTable ");
        #line 751 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 752 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 755 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 758 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 759 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 761 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 763 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 763 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 763 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 764 "src/compiler/DefinitionWriter.pv"
        if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
            #line 765 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 766 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 766 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 768 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
                    #line 768 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 771 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 775 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 776 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 776 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 779 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 782 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 783 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 784 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 786 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 786 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 786 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 787 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 790 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->impls.length > 0) {
        #line 790 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 792 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 792 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 792 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 793 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 794 "src/compiler/DefinitionWriter.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 794 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 796 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 797 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 797 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 799 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 799 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 801 "src/compiler/DefinitionWriter.pv"
        Generator__write_extern(generator, file);
        #line 802 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 803 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, &impl_info->trait_type, generics);
        #line 804 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 805 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 806 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 807 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 808 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 811 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 814 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 815 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 816 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 817 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 819 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 820 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 822 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 823 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 825 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 826 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 828 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 828 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 828 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 829 "src/compiler/DefinitionWriter.pv"
        if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
            #line 830 "src/compiler/DefinitionWriter.pv"
            struct Token* name = func_info->name;
            #line 831 "src/compiler/DefinitionWriter.pv"
            if (name == 0) {
                #line 832 "src/compiler/DefinitionWriter.pv"
                fprintf(stderr, "Missing function name in write_trait_definition\n");
                #line 833 "src/compiler/DefinitionWriter.pv"
                return false;
            }

            #line 836 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 837 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*fn_", .length = strlen("(*fn_") });
            #line 838 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, name->value);
            #line 839 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 841 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 841 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 842 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 846 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 847 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 849 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 851 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 852 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 854 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 855 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 856 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 857 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 859 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 860 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 862 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 865 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_with_body(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct Trait* trait_info, struct Type* impl_trait_type, struct GenericMap* generics, struct Module* module, struct UsageContext* function_usage_context) {
    #line 866 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 867 "src/compiler/DefinitionWriter.pv"
    if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, impl_trait_type, func_info, generics)) {
        #line 868 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 869 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 870 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 871 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 872 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 875 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 876 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 880 "src/compiler/DefinitionWriter.pv"
    struct GenericMap generics_void = *generics;
    #line 881 "src/compiler/DefinitionWriter.pv"
    generics_void.self_type = &generator->root->type_void;
    #line 882 "src/compiler/DefinitionWriter.pv"
    if (func_info->parameters.length > 0 && Generator__has_void_self_replacement(&func_info->parameters.data[0], &generics_void)) {
        #line 883 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_self_cast(self, file, module, generics);
    }

    #line 886 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 887 "src/compiler/DefinitionWriter.pv"
    if (function_usage_context != 0) {
        #line 888 "src/compiler/DefinitionWriter.pv"
        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
    }
    #line 890 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;

    #line 892 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, file, &func_info->return_type, func_info->body, generics, false, true)) {
        #line 893 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 894 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 895 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 896 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 897 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 900 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 901 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 902 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 904 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 905 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 908 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_size(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 909 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 910 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "uintptr_t ");
    #line 911 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 912 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__size(void* __self) {\n");

    #line 914 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 915 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 916 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return sizeof(struct ");
    #line 917 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 918 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__Instance);\n");
    #line 919 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 920 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 923 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_get_params(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 924 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 925 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/Array_TypeId.h>\n");
    #line 926 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct Array_TypeId* ");
    #line 927 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 929 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 930 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params(void* __self) {\n");
    } else {
        #line 932 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params(void* __self) {\n");
    }

    #line 935 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 936 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 937 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static TypeId type_ids[] = { ");

    #line 939 "src/compiler/DefinitionWriter.pv"
    bool first = true;
    #line 940 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 940 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 940 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 941 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 941 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 941 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 942 "src/compiler/DefinitionWriter.pv"
        Generator__write_typeid(generator, file, &param->type, generics);
    } }

    #line 945 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " };\n");
    #line 946 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 947 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
    #line 948 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 949 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return &result;\n");
    #line 950 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 951 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 954 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_set_arg(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 955 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 956 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "bool ");
    #line 957 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 959 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 960 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
    } else {
        #line 962 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
    }

    #line 965 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 967 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 968 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 969 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 971 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 972 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 973 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 974 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 975 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance* self = __self;\n");
    } else {
        #line 977 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 978 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 979 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 980 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 982 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }
    }

    #line 986 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 987 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "switch (index) {\n");
    #line 988 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 990 "src/compiler/DefinitionWriter.pv"
    uintptr_t i = 0;
    #line 991 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 991 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 991 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 992 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 993 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case %zu: self->", i);
        #line 994 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 995 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = ");

        #line 997 "src/compiler/DefinitionWriter.pv"
        if (!Generator__is_reference(&param->type)) {
            #line 998 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*(");
            #line 999 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 1000 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*)");
        } else {
            #line 1002 "src/compiler/DefinitionWriter.pv"
            if (module->mode_cpp) {
                #line 1003 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "(");
                #line 1004 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, &param->type, generics);
                #line 1005 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ")");
            }
        }

        #line 1009 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "value; return true;\n");
        #line 1010 "src/compiler/DefinitionWriter.pv"
        i += 1;
    } }

    #line 1013 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 1014 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 1015 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 1017 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 1018 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return false;\n");

    #line 1020 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 1021 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 1024 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_execute_or_init(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 1025 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1026 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1027 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 1028 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");
        #line 1029 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1030 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 1031 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1032 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init(void* __self, struct trait_Allocator allocator) {\n");

        #line 1034 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 1036 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1037 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 1038 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1039 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 1040 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1041 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance* self = __self;\n");

        #line 1043 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1044 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 1045 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1046 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* instance = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct ");
        #line 1047 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1048 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "));\n");

        #line 1050 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 1050 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 1050 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 1051 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 1052 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "instance->");
            #line 1053 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 1054 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = self->");
            #line 1055 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 1056 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 1059 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1060 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "return (struct trait_Iter_");
        #line 1061 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1062 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ") { .vtable = &");
        #line 1063 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1064 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

        #line 1066 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 1067 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    } else {
        #line 1069 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "void ");
        #line 1070 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1071 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute(void* __self) {\n");

        #line 1073 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 1075 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1076 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 1077 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1078 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 1079 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 1080 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 1081 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 1083 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }

        #line 1086 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 1087 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1088 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");

        #line 1090 "src/compiler/DefinitionWriter.pv"
        bool first = true;
        #line 1091 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 1091 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 1091 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 1092 "src/compiler/DefinitionWriter.pv"
            if (first) {
                #line 1092 "src/compiler/DefinitionWriter.pv"
                first = false;
            } else {
                #line 1092 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ", ");
            }
            #line 1093 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "self->");
            #line 1094 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
        } }

        #line 1097 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ");\n");

        #line 1099 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 1100 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    }
}

#line 1104 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_vtable(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 1105 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1106 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1107 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 1108 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_");
        #line 1109 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 1110 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
    } else {
        #line 1112 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
    }

    #line 1115 "src/compiler/DefinitionWriter.pv"
    Generator__write_dynamic_vtable_name(generator, file, func_info, generics);

    #line 1117 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1118 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO");
    } else {
        #line 1120 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN");
    }

    #line 1123 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1124 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_get_params = &");
        #line 1125 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1126 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params, .fn_set_arg = &");
        #line 1127 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1128 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg, .fn_init = &");
        #line 1129 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1130 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init };\n");
    } else {
        #line 1132 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_size = &");
        #line 1133 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1134 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__size, .fn_get_params = &");
        #line 1135 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1136 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params, .fn_set_arg = &");
        #line 1137 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1138 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg, .fn_execute = &");
        #line 1139 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1140 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute };\n");
    }
}

#line 1144 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_impl(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 1145 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1146 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 1147 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1148 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Allocator.h>\n");
    }
    #line 1150 "src/compiler/DefinitionWriter.pv"
    if (!Generator__is_coroutine(generator)) {
        #line 1150 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_dynamic_size(self, file, func_info, generics);
    }
    #line 1151 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_get_params(self, file, func_info, generics);
    #line 1152 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_set_arg(self, file, func_info, generics, module);
    #line 1153 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_execute_or_init(self, file, func_info, generics, module);
    #line 1154 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_vtable(self, file, func_info, generics);
}

#line 1157 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 1158 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1159 "src/compiler/DefinitionWriter.pv"
    struct Type* self_type = generics->self_type;
    #line 1160 "src/compiler/DefinitionWriter.pv"
    if (self_type == 0) {
        #line 1161 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing self type in write_impls\n");
        #line 1162 "src/compiler/DefinitionWriter.pv"
        return false;
    }
    #line 1164 "src/compiler/DefinitionWriter.pv"
    struct Type* named_self_type = self_type;
    #line 1165 "src/compiler/DefinitionWriter.pv"
    if (Type__is_fat_pointer(self_type)) {
        #line 1166 "src/compiler/DefinitionWriter.pv"
        named_self_type = Type__deref_1(self_type);
        #line 1167 "src/compiler/DefinitionWriter.pv"
        if (named_self_type == 0) {
            #line 1167 "src/compiler/DefinitionWriter.pv"
            named_self_type = self_type;
        }
    }
    #line 1169 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, named_self_type, self_type, generics);
    #line 1170 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 1171 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 1173 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 1175 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 1175 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 1175 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 1175 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 1176 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 1177 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 1178 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 1178 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 1180 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 1180 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 1180 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 1181 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 1182 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 1183 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 1183 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 1185 "src/compiler/DefinitionWriter.pv"
            if (usize__Eq_usize__eq(func_info->generics.array.length, 0)) {
                #line 1188 "src/compiler/DefinitionWriter.pv"
                struct UsageContext* function_usage_context = 0;
                #line 1189 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->usage_contexts.length > 0) {
                    #line 1190 "src/compiler/DefinitionWriter.pv"
                    function_usage_context = &function_usage->usage_contexts.data[0];
                }

                #line 1193 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1194 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 1195 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, function_usage_context)) {
                        #line 1195 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 1197 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 1198 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1199 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1200 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1201 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1204 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 1205 "src/compiler/DefinitionWriter.pv"
                    if (function_usage_context != 0) {
                        #line 1206 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
                    }
                    #line 1208 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 1210 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage_context)) {
                        #line 1211 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1212 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1213 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1214 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1217 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 1218 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics, module);
                    }

                    #line 1221 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 1224 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 1225 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 1226 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 1228 "src/compiler/DefinitionWriter.pv"
                    for (uintptr_t i = 0; i != function_usage->usage_contexts.length; i < function_usage->usage_contexts.length ? i++ : i--) {
                        #line 1229 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = &function_usage->usage_contexts.data[i];
                        #line 1230 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 1233 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 1235 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 1236 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 1237 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 1238 "src/compiler/DefinitionWriter.pv"
                            struct Token func_name = *func_info->name;
                            #line 1239 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_name.value.length;
                            #line 1240 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                            #line 1241 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 1244 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 1245 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = usage_context->function_context.coroutine.yield_count;
                        #line 1246 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 1248 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, usage_context);

                        #line 1250 "src/compiler/DefinitionWriter.pv"
                        if (usage_context->impl_dynamic_function) {
                            #line 1251 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics3, module);
                        }

                        #line 1254 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }
                }
            }
        } }

        #line 1260 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 1261 "src/compiler/DefinitionWriter.pv"
            struct GenericMap* default_generics = Generator__trait_default_generics(generator, impl_info, generics);
            #line 1262 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 1262 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 1262 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 1262 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 1263 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 1263 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 1265 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1266 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, default_generics, module, 0)) {
                    #line 1266 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } }
        }

        #line 1270 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1270 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1270 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1271 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1272 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1273 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1274 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1275 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1276 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 1277 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 1278 "src/compiler/DefinitionWriter.pv"
            Generator__write_array_decl_suffix(generator, file, &impl_const->type, generics);
            #line 1279 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1280 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, impl_const->value, generics);
            #line 1281 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1285 "src/compiler/DefinitionWriter.pv"
    return true;
}
