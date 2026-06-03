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
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 78 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Co_");
        #line 79 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 80 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ".h>\n");
        #line 81 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 82 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 83 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 84 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 85 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance { ");
        #line 86 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;
        #line 87 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 87 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 87 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 88 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 89 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 90 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 91 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "; ");
        } }
        #line 93 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 94 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
        #line 95 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_Co_");
        #line 96 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 97 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 98 "src/compiler/DefinitionWriter.pv"
        Generator__write_dynamic_vtable_name(generator, file, func_info, generics);
        #line 99 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO;\n");
    } else {
        #line 101 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Fn.h>\n");
        #line 102 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 103 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 104 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__Instance { ");
        #line 105 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;
        #line 106 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 106 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 106 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 107 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 108 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 109 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 110 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "; ");
        } }
        #line 112 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 113 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
        #line 114 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_FnVTable ");
        #line 115 "src/compiler/DefinitionWriter.pv"
        Generator__write_dynamic_vtable_name(generator, file, func_info, generics);
        #line 116 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN;\n");
    }
}

#line 120 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_definition(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 121 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 122 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, func_info->context, func_info->name);

    #line 124 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);

    #line 126 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 127 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "bool");
    } else {
        #line 129 "src/compiler/DefinitionWriter.pv"
        if (!Generator__write_type(generator, file, &func_info->return_type, generics)) {
            #line 129 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 132 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 133 "src/compiler/DefinitionWriter.pv"
    if (custom_name != 0) {
        #line 134 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, custom_name);
    } else {
        #line 136 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.map.length > 0) {
            #line 137 "src/compiler/DefinitionWriter.pv"
            struct String name = Naming__get_type_name(&generator->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
            #line 138 "src/compiler/DefinitionWriter.pv"
            Generator__write_string(generator, file, &name);
        } else {
            #line 140 "src/compiler/DefinitionWriter.pv"
            if (!Generator__write_function_name(generator, file, func_info, generics)) {
                #line 140 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }
    }

    #line 144 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 145 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 146 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 149 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "(");

    #line 151 "src/compiler/DefinitionWriter.pv"
    bool success = true;
    #line 152 "src/compiler/DefinitionWriter.pv"
    bool first = true;

    #line 154 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 154 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 154 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter_iter = Iter_ref_Parameter__value(&__iter);

        #line 155 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 155 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 155 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }

        #line 157 "src/compiler/DefinitionWriter.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 158 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 160 "src/compiler/DefinitionWriter.pv"
            struct Token parameter_name = *parameter_iter->name;
            #line 161 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, parameter_name.value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 165 "src/compiler/DefinitionWriter.pv"
    if (func_info->variadic && !func_info->typed_variadic) {
        #line 166 "src/compiler/DefinitionWriter.pv"
        if (!first) {
            #line 166 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 167 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "...");
    }

    #line 170 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ")");
    #line 171 "src/compiler/DefinitionWriter.pv"
    return success;
}

#line 174 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 175 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 176 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 177 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 178 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 179 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 181 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 182 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 184 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 185 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 186 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 188 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext* function_context = generator->function_context;
    #line 189 "src/compiler/DefinitionWriter.pv"
    if (function_context == 0) {
        #line 190 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing function context in write_function_coroutine\n");
        #line 191 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 194 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&function_context->coroutine.variables);
    #line 194 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 194 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 194 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 195 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 196 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 197 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 198 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, name);
        #line 199 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 202 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 203 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 205 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 207 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 208 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);

    #line 210 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 212 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 213 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 214 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 215 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 217 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "extern struct trait_Iter_");
    #line 218 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 219 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 221 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 222 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 223 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 225 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 228 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct UsageContext* function_usage_context) {
    #line 229 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 230 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = generator };

    #line 232 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 233 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 234 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 236 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 237 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 238 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 239 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 241 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 242 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");

        #line 244 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 245 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 246 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 248 "src/compiler/DefinitionWriter.pv"
        uintptr_t yield_count = 0;
        #line 249 "src/compiler/DefinitionWriter.pv"
        if (function_usage_context != 0) {
            #line 250 "src/compiler/DefinitionWriter.pv"
            yield_count = function_usage_context->function_context.coroutine.yield_count;
        }
        #line 252 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i < yield_count + 1; i++) {
            #line 253 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 254 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 257 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 258 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 260 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 261 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 262 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 264 "src/compiler/DefinitionWriter.pv"
        struct FunctionContext* function_context = generator->function_context;
        #line 265 "src/compiler/DefinitionWriter.pv"
        if (function_context == 0) {
            #line 266 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Missing function context in write_function_block\n");
            #line 267 "src/compiler/DefinitionWriter.pv"
            return false;
        }
        #line 269 "src/compiler/DefinitionWriter.pv"
        function_context->coroutine.yield_count = 0;
        #line 270 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 271 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 272 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 273 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 274 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 277 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 278 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 280 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 281 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 283 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &func_info->return_type, generics);
        #line 284 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 285 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 286 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 287 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 288 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 290 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 292 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 293 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &name);
        #line 294 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 296 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 297 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);

        #line 299 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .fn_next = ");
        #line 300 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 301 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .fn_value = ");
        #line 302 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 303 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 305 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 308 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 309 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 310 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 311 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 312 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 313 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 316 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 319 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 320 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 321 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 322 "src/compiler/DefinitionWriter.pv"
    struct Token enum_name = *enum_info->name;
    #line 323 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 324 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 325 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 327 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, &enum_name);

    #line 329 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 330 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 331 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name.value);
        #line 332 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 333 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 335 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 337 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 338 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 340 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 342 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 343 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 344 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 345 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 346 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 347 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 348 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 349 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 351 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 352 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, &enum_name);
            #line 353 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 354 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 356 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 358 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 360 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 361 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 362 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 363 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 366 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 367 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 369 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 370 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 371 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 372 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 374 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 374 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 374 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 375 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 376 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 377 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 380 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 381 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 382 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 383 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 385 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 386 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 387 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 388 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 389 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 392 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 393 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 393 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 393 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 394 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 397 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 398 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 399 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 400 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 403 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 403 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 403 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 404 "src/compiler/DefinitionWriter.pv"
            if (variant->names.length > 0) {
                #line 405 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 406 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 408 "src/compiler/DefinitionWriter.pv"
                uintptr_t i = 0;
                #line 409 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 409 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 409 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 410 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 411 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " ");
                    #line 412 "src/compiler/DefinitionWriter.pv"
                    Generator__write_str(generator, file, variant->names.data[i]);
                    #line 413 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "; ");
                    #line 414 "src/compiler/DefinitionWriter.pv"
                    i += 1;
                } }

                #line 417 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 418 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, variant->name->value);
                #line 419 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length == 1) {
                #line 421 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 422 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 423 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 424 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 425 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 426 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 428 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 429 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 431 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 431 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 431 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 432 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 433 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 436 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 437 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 438 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 439 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 443 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 444 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 445 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 446 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 449 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 450 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 453 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 454 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 456 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 456 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 456 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 456 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 457 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 458 "src/compiler/DefinitionWriter.pv"
        if (usage_context->impl_functions.length > impl_index) {
            #line 458 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage_context->impl_functions, impl_index);
        }

        #line 460 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 460 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 460 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 461 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 462 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 463 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 463 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 465 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 466 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 467 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 467 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 468 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");

                #line 470 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->impl_dynamic_function) {
                    #line 471 "src/compiler/DefinitionWriter.pv"
                    DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                }
            }

            #line 475 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 476 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage usage_info = *function_usage;
                #line 477 "src/compiler/DefinitionWriter.pv"
                if (func_info->generics.array.length > 0) {
                    #line 478 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage_info.usage_contexts);
                    #line 478 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 478 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext usage_context = *Iter_ref_UsageContext__value(&__iter);

                        #line 479 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context.signature, usage_context.generic_map, false);
                        #line 480 "src/compiler/DefinitionWriter.pv"
                        usage_context.generic_map->self_type = generics->self_type;
                        #line 481 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 482 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context.generic_map, 0)) {
                            #line 482 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }
                        #line 483 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, ";\n");

                        #line 485 "src/compiler/DefinitionWriter.pv"
                        if (usage_context.impl_dynamic_function) {
                            #line 486 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, usage_context.generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                        }
                    } }
                }
            }
        } }

        #line 493 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 493 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 493 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 494 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 495 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 496 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 497 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 498 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 499 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 500 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 501 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 505 "src/compiler/DefinitionWriter.pv"
    if (usage != 0 && usage->impl_dynamic_usage) {
        #line 506 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Enum.h>\n");
        #line 507 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_EnumVTable ");
        #line 508 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 509 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ENUM;\n");
    }

    #line 512 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 515 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 516 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 517 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 518 "src/compiler/DefinitionWriter.pv"
    struct Token struct_name = *struct_info->name;
    #line 519 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 520 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 521 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage_context->impl_functions;
    #line 522 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 524 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, &struct_name);

    #line 526 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 527 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 529 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 530 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 531 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 532 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 534 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 535 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 537 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 537 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 537 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 538 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 539 "src/compiler/DefinitionWriter.pv"
            struct Token field_name = *field->name;
            #line 540 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field_name.value, &field->type, generics);
            #line 541 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 544 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 545 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 548 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 548 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 549 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);

    #line 551 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 551 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 551 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 551 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 552 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 553 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 554 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 554 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 556 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 556 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 556 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 557 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 558 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 559 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 559 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 561 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 562 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 563 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0 && function_usage->usage_contexts.length > 0) {
                        #line 564 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &function_usage->usage_contexts.data[0].function_context;
                        #line 565 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 566 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 569 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 570 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 570 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 572 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 573 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 573 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }

                #line 576 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 579 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 580 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 581 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 582 "src/compiler/DefinitionWriter.pv"
                    if (func_info->generics.array.length > 0) {
                        #line 583 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                        #line 583 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_UsageContext__next(&__iter)) {
                            #line 583 "src/compiler/DefinitionWriter.pv"
                            struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                            #line 584 "src/compiler/DefinitionWriter.pv"
                            IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                            #line 587 "src/compiler/DefinitionWriter.pv"
                            usage_context->generic_map->self_type = generics->self_type;
                            #line 588 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "\n");
                            #line 589 "src/compiler/DefinitionWriter.pv"
                            if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                                #line 589 "src/compiler/DefinitionWriter.pv"
                                return false;
                            }
                            #line 590 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, ";\n");

                            #line 592 "src/compiler/DefinitionWriter.pv"
                            if (usage_context->impl_dynamic_function) {
                                #line 593 "src/compiler/DefinitionWriter.pv"
                                DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, usage_context->generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                            }
                        } }
                    }

                    #line 598 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function && func_info->generics.array.length == 0) {
                        #line 599 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 605 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 606 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 606 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 609 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 609 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 609 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 610 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 611 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 612 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 613 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 614 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 615 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 616 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 617 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 621 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 621 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 623 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 623 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 623 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 624 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 625 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 626 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 626 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 627 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 627 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 628 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 629 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 630 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 631 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 632 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 633 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 634 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 637 "src/compiler/DefinitionWriter.pv"
    if (usage != 0 && usage->impl_dynamic_usage) {
        #line 638 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 639 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 640 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 641 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 644 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 647 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 648 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 650 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 652 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 652 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 652 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 653 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 654 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 655 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 655 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 657 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
                    #line 657 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 660 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 664 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 665 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 665 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 668 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 671 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 672 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 673 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 675 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 675 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 675 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 676 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 679 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->impls.length > 0) {
        #line 679 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 681 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 681 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 681 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 682 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 683 "src/compiler/DefinitionWriter.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 683 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 685 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 686 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 686 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 688 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 688 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 690 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 691 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, &impl_info->trait_type, generics);
        #line 692 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 693 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 694 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 695 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 696 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 699 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 702 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 703 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 704 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 705 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 707 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 708 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 710 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 711 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 713 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 714 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 716 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 716 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 716 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 717 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 718 "src/compiler/DefinitionWriter.pv"
            struct Token* name = func_info->name;
            #line 719 "src/compiler/DefinitionWriter.pv"
            if (name == 0) {
                #line 720 "src/compiler/DefinitionWriter.pv"
                fprintf(stderr, "Missing function name in write_trait_definition\n");
                #line 721 "src/compiler/DefinitionWriter.pv"
                return false;
            }

            #line 724 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 725 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*fn_", .length = strlen("(*fn_") });
            #line 726 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, name->value);
            #line 727 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 729 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 729 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 730 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 734 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 735 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 737 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 739 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 740 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 742 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 743 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 744 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 745 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 747 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 748 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 750 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 753 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_with_body(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct Trait* trait_info, struct Type* impl_trait_type, struct GenericMap* generics, struct Module* module, struct UsageContext* function_usage_context) {
    #line 754 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 755 "src/compiler/DefinitionWriter.pv"
    if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, impl_trait_type, func_info, generics)) {
        #line 756 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 757 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 758 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 759 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 760 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 763 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 764 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 766 "src/compiler/DefinitionWriter.pv"
    bool is_value_self = func_info->parameters.length > 0 && Type__is_self(&func_info->parameters.data[0].type);
    #line 767 "src/compiler/DefinitionWriter.pv"
    if (!is_value_self) {
        #line 768 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_self_cast(self, file, module, generics);
    }

    #line 771 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 772 "src/compiler/DefinitionWriter.pv"
    if (function_usage_context != 0) {
        #line 773 "src/compiler/DefinitionWriter.pv"
        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
    }
    #line 775 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;

    #line 777 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, file, &func_info->return_type, func_info->body, generics, false, true)) {
        #line 778 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 779 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 780 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 781 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 782 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 785 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 786 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 787 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 789 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 790 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 793 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_size(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 794 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 795 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "uintptr_t ");
    #line 796 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 797 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__size(void* __self) {\n");

    #line 799 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 800 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 801 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return sizeof(struct ");
    #line 802 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 803 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__Instance);\n");
    #line 804 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 805 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 808 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_get_params(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 809 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 810 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/Array_TypeId.h>\n");
    #line 811 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct Array_TypeId* ");
    #line 812 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 814 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 815 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params(void* __self) {\n");
    } else {
        #line 817 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params(void* __self) {\n");
    }

    #line 820 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 821 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 822 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static TypeId type_ids[] = { ");

    #line 824 "src/compiler/DefinitionWriter.pv"
    bool first = true;
    #line 825 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 825 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 825 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 826 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 826 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 826 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 827 "src/compiler/DefinitionWriter.pv"
        Generator__write_typeid(generator, file, &param->type, generics);
    } }

    #line 830 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " };\n");
    #line 831 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 832 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
    #line 833 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 834 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return &result;\n");
    #line 835 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 836 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 839 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_set_arg(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 840 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 841 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "bool ");
    #line 842 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 844 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 845 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
    } else {
        #line 847 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
    }

    #line 850 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 852 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 853 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 854 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 856 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 857 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 858 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 859 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 860 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance* self = __self;\n");
    } else {
        #line 862 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 863 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 864 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 865 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 867 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }
    }

    #line 871 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 872 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "switch (index) {\n");
    #line 873 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 875 "src/compiler/DefinitionWriter.pv"
    uintptr_t i = 0;
    #line 876 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 876 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 876 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 877 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 878 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case %zu: self->", i);
        #line 879 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 880 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = ");

        #line 882 "src/compiler/DefinitionWriter.pv"
        if (!Generator__is_reference(&param->type)) {
            #line 883 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*(");
            #line 884 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 885 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*)");
        } else {
            #line 887 "src/compiler/DefinitionWriter.pv"
            if (module->mode_cpp) {
                #line 888 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "(");
                #line 889 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, &param->type, generics);
                #line 890 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ")");
            }
        }

        #line 894 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "value; return true;\n");
        #line 895 "src/compiler/DefinitionWriter.pv"
        i += 1;
    } }

    #line 898 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 899 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 900 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 902 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 903 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return false;\n");

    #line 905 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 906 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 909 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_execute_or_init(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 910 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 911 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 912 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 913 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");
        #line 914 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 915 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 916 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 917 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init(void* __self, struct trait_Allocator allocator) {\n");

        #line 919 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 921 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 922 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 923 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 924 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_");
        #line 925 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 926 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Instance* self = __self;\n");

        #line 928 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 929 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 930 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 931 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* instance = allocator.vtable->fn_alloc(allocator.instance, sizeof(struct ");
        #line 932 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 933 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "));\n");

        #line 935 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 935 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 935 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 936 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 937 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "instance->");
            #line 938 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 939 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = self->");
            #line 940 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 941 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 944 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 945 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "return (struct trait_Iter_");
        #line 946 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 947 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ") { .vtable = &");
        #line 948 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 949 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

        #line 951 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 952 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    } else {
        #line 954 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "void ");
        #line 955 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 956 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute(void* __self) {\n");

        #line 958 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 960 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 961 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 962 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 963 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 964 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 965 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 966 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 968 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }

        #line 971 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 972 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 973 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");

        #line 975 "src/compiler/DefinitionWriter.pv"
        bool first = true;
        #line 976 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 976 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 976 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 977 "src/compiler/DefinitionWriter.pv"
            if (first) {
                #line 977 "src/compiler/DefinitionWriter.pv"
                first = false;
            } else {
                #line 977 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ", ");
            }
            #line 978 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "self->");
            #line 979 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
        } }

        #line 982 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ");\n");

        #line 984 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 985 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    }
}

#line 989 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_vtable(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 990 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 991 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 992 "src/compiler/DefinitionWriter.pv"
        struct String co_ret_name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 993 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_");
        #line 994 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &co_ret_name);
        #line 995 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
    } else {
        #line 997 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
    }

    #line 1000 "src/compiler/DefinitionWriter.pv"
    Generator__write_dynamic_vtable_name(generator, file, func_info, generics);

    #line 1002 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1003 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO");
    } else {
        #line 1005 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN");
    }

    #line 1008 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1009 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_get_params = &");
        #line 1010 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1011 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params, .fn_set_arg = &");
        #line 1012 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1013 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg, .fn_init = &");
        #line 1014 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1015 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init };\n");
    } else {
        #line 1017 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_size = &");
        #line 1018 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1019 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__size, .fn_get_params = &");
        #line 1020 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1021 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params, .fn_set_arg = &");
        #line 1022 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1023 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg, .fn_execute = &");
        #line 1024 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 1025 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute };\n");
    }
}

#line 1029 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_impl(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 1030 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1031 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 1032 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1033 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Allocator.h>\n");
    }
    #line 1035 "src/compiler/DefinitionWriter.pv"
    if (!Generator__is_coroutine(generator)) {
        #line 1035 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_dynamic_size(self, file, func_info, generics);
    }
    #line 1036 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_get_params(self, file, func_info, generics);
    #line 1037 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_set_arg(self, file, func_info, generics, module);
    #line 1038 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_execute_or_init(self, file, func_info, generics, module);
    #line 1039 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_vtable(self, file, func_info, generics);
}

#line 1042 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 1043 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1044 "src/compiler/DefinitionWriter.pv"
    struct Type* self_type = generics->self_type;
    #line 1045 "src/compiler/DefinitionWriter.pv"
    if (self_type == 0) {
        #line 1046 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing self type in write_impls\n");
        #line 1047 "src/compiler/DefinitionWriter.pv"
        return false;
    }
    #line 1049 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, Type__deref(self_type), self_type, generics);
    #line 1050 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 1051 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 1053 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 1055 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 1055 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 1055 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 1055 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 1056 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 1057 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 1058 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 1058 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 1060 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 1060 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 1060 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 1061 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 1062 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 1063 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 1063 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 1065 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 1068 "src/compiler/DefinitionWriter.pv"
                struct UsageContext* function_usage_context = 0;
                #line 1069 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->usage_contexts.length > 0) {
                    #line 1070 "src/compiler/DefinitionWriter.pv"
                    function_usage_context = &function_usage->usage_contexts.data[0];
                }

                #line 1073 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1074 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 1075 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, function_usage_context)) {
                        #line 1075 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 1077 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 1078 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1079 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1080 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1081 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1084 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 1085 "src/compiler/DefinitionWriter.pv"
                    if (function_usage_context != 0) {
                        #line 1086 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
                    }
                    #line 1088 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 1090 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage_context)) {
                        #line 1091 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1092 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1093 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1094 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1097 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 1098 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics, module);
                    }

                    #line 1101 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 1104 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 1105 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 1106 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 1108 "src/compiler/DefinitionWriter.pv"
                    for (uintptr_t i = 0; i < function_usage->usage_contexts.length; i++) {
                        #line 1109 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = &function_usage->usage_contexts.data[i];
                        #line 1110 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 1113 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 1115 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 1116 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 1117 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 1118 "src/compiler/DefinitionWriter.pv"
                            struct Token func_name = *func_info->name;
                            #line 1119 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_name.value.length;
                            #line 1120 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                            #line 1121 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 1124 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 1125 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = usage_context->function_context.coroutine.yield_count;
                        #line 1126 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 1128 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, usage_context);

                        #line 1130 "src/compiler/DefinitionWriter.pv"
                        if (usage_context->impl_dynamic_function) {
                            #line 1131 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics3, module);
                        }

                        #line 1134 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }
                }
            }
        } }

        #line 1140 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 1141 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 1141 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 1141 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 1141 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 1142 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 1142 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 1144 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1145 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, 0)) {
                    #line 1145 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } }
        }

        #line 1149 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1149 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1149 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1150 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1151 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1152 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1153 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1154 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1155 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 1156 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 1157 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1158 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, impl_const->value, generics);
            #line 1159 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1163 "src/compiler/DefinitionWriter.pv"
    return true;
}
