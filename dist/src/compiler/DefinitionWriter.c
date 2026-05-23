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
            struct Token parameter_name = *parameter_iter->name;
            #line 152 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, parameter_name.value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 156 "src/compiler/DefinitionWriter.pv"
    if (func_info->variadic) {
        #line 157 "src/compiler/DefinitionWriter.pv"
        if (!first) {
            #line 157 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 158 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "...");
    }

    #line 161 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ")");
    #line 162 "src/compiler/DefinitionWriter.pv"
    return success;
}

#line 165 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 166 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 167 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 168 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 169 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 170 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 172 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 173 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 175 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 176 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 177 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 179 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext* function_context = generator->function_context;
    #line 180 "src/compiler/DefinitionWriter.pv"
    if (function_context == 0) {
        #line 181 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing function context in write_function_coroutine\n");
        #line 182 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 185 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&function_context->coroutine.variables);
    #line 185 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 185 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 185 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 186 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 187 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 188 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 189 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, name);
        #line 190 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 193 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 194 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 196 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 198 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 199 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);

    #line 201 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 203 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 204 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 205 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 206 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 208 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "extern struct trait_Iter_");
    #line 209 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 210 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 212 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 213 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 214 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 216 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 219 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct UsageContext* function_usage_context) {
    #line 220 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 221 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = generator };

    #line 223 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 224 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 225 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 227 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 228 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 229 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 230 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 232 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 233 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");

        #line 235 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 236 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 237 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 239 "src/compiler/DefinitionWriter.pv"
        uintptr_t yield_count = 0;
        #line 240 "src/compiler/DefinitionWriter.pv"
        if (function_usage_context != 0) {
            #line 241 "src/compiler/DefinitionWriter.pv"
            yield_count = function_usage_context->function_context.coroutine.yield_count;
        }
        #line 243 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i < yield_count + 1; i++) {
            #line 244 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 245 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 248 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 249 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 251 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 252 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 253 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 255 "src/compiler/DefinitionWriter.pv"
        struct FunctionContext* function_context = generator->function_context;
        #line 256 "src/compiler/DefinitionWriter.pv"
        if (function_context == 0) {
            #line 257 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Missing function context in write_function_block\n");
            #line 258 "src/compiler/DefinitionWriter.pv"
            return false;
        }
        #line 260 "src/compiler/DefinitionWriter.pv"
        function_context->coroutine.yield_count = 0;
        #line 261 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 262 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 263 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 264 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 265 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 268 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 269 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 271 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 272 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 274 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &func_info->return_type, generics);
        #line 275 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 276 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 277 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 278 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 279 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 281 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 283 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 284 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, &name);
        #line 285 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 287 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 288 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);

        #line 290 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .fn_next = ");
        #line 291 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 292 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .fn_value = ");
        #line 293 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 294 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 296 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 299 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 300 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 301 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 302 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 303 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 304 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 307 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 310 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 311 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 312 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 313 "src/compiler/DefinitionWriter.pv"
    struct Token enum_name = *enum_info->name;
    #line 314 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 315 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 316 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 318 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, &enum_name);

    #line 320 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 321 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 322 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name.value);
        #line 323 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 324 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 326 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 328 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 329 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 331 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 333 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 334 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 335 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 336 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 337 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 338 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_name.value);
            #line 339 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 340 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 342 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 343 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, &enum_name);
            #line 344 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 345 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 347 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 349 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 351 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 352 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 353 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 354 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 357 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 358 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 360 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 361 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 362 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 363 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 365 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 365 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 365 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 366 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 367 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 368 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 371 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 372 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 373 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 374 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 376 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 377 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 378 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 379 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 380 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 383 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 384 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 384 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 384 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 385 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 388 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 389 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 390 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 391 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 394 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 394 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 394 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 395 "src/compiler/DefinitionWriter.pv"
            if (variant->names.length > 0) {
                #line 396 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 397 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 399 "src/compiler/DefinitionWriter.pv"
                uintptr_t i = 0;
                #line 400 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 400 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 400 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 401 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 402 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " ");
                    #line 403 "src/compiler/DefinitionWriter.pv"
                    Generator__write_str(generator, file, variant->names.data[i]);
                    #line 404 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "; ");
                    #line 405 "src/compiler/DefinitionWriter.pv"
                    i += 1;
                } }

                #line 408 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 409 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, variant->name->value);
                #line 410 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length == 1) {
                #line 412 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 413 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 414 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 415 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 416 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 417 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 419 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 420 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 422 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 422 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 422 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 423 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 424 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 427 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 428 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 429 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 430 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 434 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 435 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 436 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 437 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 440 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 441 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 444 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 445 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 447 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 447 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 447 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 447 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 448 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 449 "src/compiler/DefinitionWriter.pv"
        if (usage_context->impl_functions.length > impl_index) {
            #line 449 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage_context->impl_functions, impl_index);
        }

        #line 451 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 451 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 451 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 452 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 453 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 454 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 454 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 456 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 457 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 458 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 458 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 459 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");

                #line 461 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->impl_dynamic_function) {
                    #line 462 "src/compiler/DefinitionWriter.pv"
                    DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                }
            }

            #line 466 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 467 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage usage_info = *function_usage;
                #line 468 "src/compiler/DefinitionWriter.pv"
                if (func_info->generics.array.length > 0) {
                    #line 469 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage_info.usage_contexts);
                    #line 469 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 469 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext usage_context = *Iter_ref_UsageContext__value(&__iter);

                        #line 470 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context.signature, usage_context.generic_map, false);
                        #line 471 "src/compiler/DefinitionWriter.pv"
                        usage_context.generic_map->self_type = generics->self_type;
                        #line 472 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 473 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context.generic_map, 0)) {
                            #line 473 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }
                        #line 474 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, ";\n");

                        #line 476 "src/compiler/DefinitionWriter.pv"
                        if (usage_context.impl_dynamic_function) {
                            #line 477 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, enum_name.value, usage_context.generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                        }
                    } }
                }
            }
        } }

        #line 484 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 484 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 484 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 485 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 486 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 487 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 488 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 489 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 490 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 491 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 492 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 496 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 499 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 500 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 501 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 502 "src/compiler/DefinitionWriter.pv"
    struct Token struct_name = *struct_info->name;
    #line 503 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 504 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 505 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage_context->impl_functions;
    #line 506 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 508 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, &struct_name);

    #line 510 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 511 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 513 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 514 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 515 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 516 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 518 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 519 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 521 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 521 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 521 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 522 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 523 "src/compiler/DefinitionWriter.pv"
            struct Token field_name = *field->name;
            #line 524 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field_name.value, &field->type, generics);
            #line 525 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 528 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 529 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 532 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 532 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 533 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);

    #line 535 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 535 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 535 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 535 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 536 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 537 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 538 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 538 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 540 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 540 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 540 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 541 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 542 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 543 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 543 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 545 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 546 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 547 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0 && function_usage->usage_contexts.length > 0) {
                        #line 548 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &function_usage->usage_contexts.data[0].function_context;
                        #line 549 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 550 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 553 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 554 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 554 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 556 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 557 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 557 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }

                #line 560 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 563 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 564 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 565 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 566 "src/compiler/DefinitionWriter.pv"
                    if (func_info->generics.array.length > 0) {
                        #line 567 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                        #line 567 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_UsageContext__next(&__iter)) {
                            #line 567 "src/compiler/DefinitionWriter.pv"
                            struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                            #line 568 "src/compiler/DefinitionWriter.pv"
                            IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                            #line 571 "src/compiler/DefinitionWriter.pv"
                            usage_context->generic_map->self_type = generics->self_type;
                            #line 572 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "\n");
                            #line 573 "src/compiler/DefinitionWriter.pv"
                            if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                                #line 573 "src/compiler/DefinitionWriter.pv"
                                return false;
                            }
                            #line 574 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, ";\n");

                            #line 576 "src/compiler/DefinitionWriter.pv"
                            if (usage_context->impl_dynamic_function) {
                                #line 577 "src/compiler/DefinitionWriter.pv"
                                DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, usage_context->generic_map, func_info->type == FUNCTION_TYPE__COROUTINE);
                            }
                        } }
                    }

                    #line 582 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function && func_info->generics.array.length == 0) {
                        #line 583 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_name.value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 589 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 590 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 590 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 593 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 593 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 593 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 594 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 595 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 596 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 597 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 598 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 599 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 600 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 601 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 605 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 605 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 607 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 607 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 607 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 608 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 609 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 610 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 610 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 611 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 611 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 612 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 613 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 614 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 615 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 616 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 617 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 618 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 621 "src/compiler/DefinitionWriter.pv"
    if (usage != 0 && usage->impl_dynamic_usage) {
        #line 622 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 623 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 624 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 625 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 628 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 631 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 632 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 634 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 636 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 636 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 636 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 637 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 638 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 639 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 639 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 641 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
                    #line 641 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 644 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 648 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 649 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 649 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 652 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 655 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 656 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 657 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 659 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 659 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 659 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 660 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 663 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->impls.length > 0) {
        #line 663 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 665 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 665 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 665 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 666 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 667 "src/compiler/DefinitionWriter.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 667 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 669 "src/compiler/DefinitionWriter.pv"
        struct Token* trait_name = trait_info->name;
        #line 670 "src/compiler/DefinitionWriter.pv"
        if (trait_name == 0) {
            #line 670 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 672 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 672 "src/compiler/DefinitionWriter.pv"
            continue;
        }

        #line 674 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 675 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, &impl_info->trait_type, generics);
        #line 676 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 677 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 678 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 679 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_name->value);
        #line 680 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 683 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 686 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 687 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 688 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 689 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 691 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 692 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 694 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 695 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 697 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 698 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 700 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 700 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 700 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 701 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 702 "src/compiler/DefinitionWriter.pv"
            struct Token* name = func_info->name;
            #line 703 "src/compiler/DefinitionWriter.pv"
            if (name == 0) {
                #line 704 "src/compiler/DefinitionWriter.pv"
                fprintf(stderr, "Missing function name in write_trait_definition\n");
                #line 705 "src/compiler/DefinitionWriter.pv"
                return false;
            }

            #line 708 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 709 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*fn_", .length = strlen("(*fn_") });
            #line 710 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, name->value);
            #line 711 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 713 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 713 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 714 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 718 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 719 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 721 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 723 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 724 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 726 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 727 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 728 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 729 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 731 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 732 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 734 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 737 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_with_body(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct Trait* trait_info, struct Type* impl_trait_type, struct GenericMap* generics, struct Module* module, struct UsageContext* function_usage_context) {
    #line 738 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 739 "src/compiler/DefinitionWriter.pv"
    if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, impl_trait_type, func_info, generics)) {
        #line 740 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 741 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 742 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 743 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 744 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 747 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 748 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 750 "src/compiler/DefinitionWriter.pv"
    bool is_value_self = func_info->parameters.length > 0 && Type__is_self(&func_info->parameters.data[0].type);
    #line 751 "src/compiler/DefinitionWriter.pv"
    if (!is_value_self) {
        #line 752 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_self_cast(self, file, module, generics);
    }

    #line 755 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 756 "src/compiler/DefinitionWriter.pv"
    if (function_usage_context != 0) {
        #line 757 "src/compiler/DefinitionWriter.pv"
        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
    }
    #line 759 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;

    #line 761 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, file, &func_info->return_type, func_info->body, generics, false, true)) {
        #line 762 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 763 "src/compiler/DefinitionWriter.pv"
        struct Token func_name = *func_info->name;
        #line 764 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_name.value.length;
        #line 765 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_name.value.ptr);
        #line 766 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 769 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 770 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 771 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 773 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 774 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 777 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_size(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 778 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 779 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "uintptr_t ");
    #line 780 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 781 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__size(void* __self) {\n");

    #line 783 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 784 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 785 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return sizeof(struct ");
    #line 786 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 787 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__Instance);\n");
    #line 788 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 789 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 792 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_get_params(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 793 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 794 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/Array_TypeId.h>\n");
    #line 795 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct Array_TypeId* ");
    #line 796 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 798 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 799 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params(void* __self) {\n");
    } else {
        #line 801 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params(void* __self) {\n");
    }

    #line 804 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 805 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 806 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static TypeId type_ids[] = { ");

    #line 808 "src/compiler/DefinitionWriter.pv"
    bool first = true;
    #line 809 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 809 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 809 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 810 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 810 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 810 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 811 "src/compiler/DefinitionWriter.pv"
        Generator__write_typeid(generator, file, &param->type, generics);
    } }

    #line 814 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " };\n");
    #line 815 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 816 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
    #line 817 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 818 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return &result;\n");
    #line 819 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 820 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 823 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_set_arg(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 824 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 825 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "bool ");
    #line 826 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 828 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 829 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
    } else {
        #line 831 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
    }

    #line 834 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 836 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 837 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 838 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 840 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 841 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
    } else {
        #line 843 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 844 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 845 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 846 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 848 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }
    }

    #line 852 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 853 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "switch (index) {\n");
    #line 854 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 856 "src/compiler/DefinitionWriter.pv"
    uintptr_t i = 0;
    #line 857 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 857 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 857 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 858 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 859 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case %zu: self->", i);
        #line 860 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 861 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = ");

        #line 863 "src/compiler/DefinitionWriter.pv"
        if (!Generator__is_reference(&param->type)) {
            #line 864 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*(");
            #line 865 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 866 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*)");
        } else {
            #line 868 "src/compiler/DefinitionWriter.pv"
            if (module->mode_cpp) {
                #line 869 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "(");
                #line 870 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, &param->type, generics);
                #line 871 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ")");
            }
        }

        #line 875 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "value; return true;\n");
        #line 876 "src/compiler/DefinitionWriter.pv"
        i += 1;
    } }

    #line 879 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 880 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 881 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 883 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 884 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return false;\n");

    #line 886 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 887 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 890 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_execute_or_init(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 891 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 892 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 893 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct Iter_CoroutineStatus ");
        #line 894 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 895 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

        #line 897 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 899 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 900 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 901 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 902 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

        #line 904 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 905 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 906 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 907 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
        #line 908 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 909 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "));\n");

        #line 911 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 911 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 911 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 912 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 913 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "instance->");
            #line 914 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 915 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = self->");
            #line 916 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 917 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 920 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 921 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "return (struct trait_Iter_CoroutineStatus) { .vtable = &");
        #line 922 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 923 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

        #line 925 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 926 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    } else {
        #line 928 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "void ");
        #line 929 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 930 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute(void* __self) {\n");

        #line 932 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 934 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 935 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 936 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 937 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 938 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 939 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 940 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 942 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }

        #line 945 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 946 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 947 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");

        #line 949 "src/compiler/DefinitionWriter.pv"
        bool first = true;
        #line 950 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 950 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 950 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 951 "src/compiler/DefinitionWriter.pv"
            if (first) {
                #line 951 "src/compiler/DefinitionWriter.pv"
                first = false;
            } else {
                #line 951 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ", ");
            }
            #line 952 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "self->");
            #line 953 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
        } }

        #line 956 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ");\n");

        #line 958 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 959 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    }
}

#line 963 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_vtable(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 964 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 965 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 966 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_CoroutineStatusVTable ");
    } else {
        #line 968 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
    }

    #line 971 "src/compiler/DefinitionWriter.pv"
    Generator__write_dynamic_vtable_name(generator, file, func_info, generics);

    #line 973 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 974 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO");
    } else {
        #line 976 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN");
    }

    #line 979 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 980 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_get_params = &");
        #line 981 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 982 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params, .fn_set_arg = &");
        #line 983 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 984 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg, .fn_init = &");
        #line 985 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 986 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init };\n");
    } else {
        #line 988 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_size = &");
        #line 989 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 990 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__size, .fn_get_params = &");
        #line 991 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 992 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params, .fn_set_arg = &");
        #line 993 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 994 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg, .fn_execute = &");
        #line 995 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 996 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute };\n");
    }
}

#line 1000 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_impl(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 1001 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1002 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 1003 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 1004 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Allocator.h>\n");
    }
    #line 1006 "src/compiler/DefinitionWriter.pv"
    if (!Generator__is_coroutine(generator)) {
        #line 1006 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_dynamic_size(self, file, func_info, generics);
    }
    #line 1007 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_get_params(self, file, func_info, generics);
    #line 1008 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_set_arg(self, file, func_info, generics, module);
    #line 1009 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_execute_or_init(self, file, func_info, generics, module);
    #line 1010 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_vtable(self, file, func_info, generics);
}

#line 1013 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 1014 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 1015 "src/compiler/DefinitionWriter.pv"
    struct Type* self_type = generics->self_type;
    #line 1016 "src/compiler/DefinitionWriter.pv"
    if (self_type == 0) {
        #line 1017 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Missing self type in write_impls\n");
        #line 1018 "src/compiler/DefinitionWriter.pv"
        return false;
    }
    #line 1020 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, Type__deref(self_type), self_type, generics);
    #line 1021 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 1022 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 1024 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 1026 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 1026 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 1026 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 1026 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 1027 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 1028 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 1029 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 1029 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 1031 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 1031 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 1031 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 1032 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 1033 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 1034 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 1034 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 1036 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 1039 "src/compiler/DefinitionWriter.pv"
                struct UsageContext* function_usage_context = 0;
                #line 1040 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0 && function_usage->usage_contexts.length > 0) {
                    #line 1041 "src/compiler/DefinitionWriter.pv"
                    function_usage_context = &function_usage->usage_contexts.data[0];
                }

                #line 1044 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1045 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 1046 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, function_usage_context)) {
                        #line 1046 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 1048 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 1049 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1050 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1051 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1052 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1055 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 1056 "src/compiler/DefinitionWriter.pv"
                    if (function_usage_context != 0) {
                        #line 1057 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage_context->function_context.coroutine.yield_count;
                    }
                    #line 1059 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 1061 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage_context)) {
                        #line 1062 "src/compiler/DefinitionWriter.pv"
                        struct Token func_name = *func_info->name;
                        #line 1063 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_name.value.length;
                        #line 1064 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                        #line 1065 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1068 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 1069 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics, module);
                    }

                    #line 1072 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 1075 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 1076 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 1077 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 1079 "src/compiler/DefinitionWriter.pv"
                    for (uintptr_t i = 0; i < function_usage->usage_contexts.length; i++) {
                        #line 1080 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = &function_usage->usage_contexts.data[i];
                        #line 1081 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 1084 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 1086 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 1087 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 1088 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 1089 "src/compiler/DefinitionWriter.pv"
                            struct Token func_name = *func_info->name;
                            #line 1090 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_name.value.length;
                            #line 1091 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_name.value.ptr);
                            #line 1092 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 1095 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 1096 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = usage_context->function_context.coroutine.yield_count;
                        #line 1097 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 1099 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, usage_context);

                        #line 1101 "src/compiler/DefinitionWriter.pv"
                        if (usage_context->impl_dynamic_function) {
                            #line 1102 "src/compiler/DefinitionWriter.pv"
                            DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics3, module);
                        }

                        #line 1105 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }
                }
            }
        } }

        #line 1111 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 1112 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 1112 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 1112 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 1112 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 1113 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 1113 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 1115 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1116 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, 0)) {
                    #line 1116 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } }
        }

        #line 1120 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1120 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1120 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1121 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1122 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1123 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1124 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1125 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1126 "src/compiler/DefinitionWriter.pv"
            struct Token impl_const_name = *impl_const->name;
            #line 1127 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const_name.value);
            #line 1128 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1129 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, impl_const->value, generics);
            #line 1130 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1134 "src/compiler/DefinitionWriter.pv"
    return true;
}
