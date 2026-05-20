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
#include <std/Array_str.h>
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
#include <std/HashMap_str_ref_ImplConst.h>
#include <std/HashMapIter_str_ref_ImplConst.h>
#include <tuple_str_ref_ImplConst.h>
#include <analyzer/ImplConst.h>
#include <compiler/TypeUsage_Struct.h>
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
    Generator__write_indent(generator, file);

    #line 119 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 120 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "bool");
    } else {
        #line 122 "src/compiler/DefinitionWriter.pv"
        if (!Generator__write_type(generator, file, &func_info->return_type, generics)) {
            #line 122 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 125 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 126 "src/compiler/DefinitionWriter.pv"
    if (custom_name != 0) {
        #line 127 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(generator, file, custom_name);
    } else {
        #line 129 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.map.length > 0) {
            #line 130 "src/compiler/DefinitionWriter.pv"
            struct String name = Naming__get_type_name(&generator->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }}, generics->self_type, generics);
            #line 131 "src/compiler/DefinitionWriter.pv"
            Generator__write_string(generator, file, &name);
        } else {
            #line 133 "src/compiler/DefinitionWriter.pv"
            if (!Generator__write_function_name(generator, file, func_info, generics)) {
                #line 133 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }
    }

    #line 137 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 138 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 139 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 142 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "(");

    #line 144 "src/compiler/DefinitionWriter.pv"
    bool success = true;
    #line 145 "src/compiler/DefinitionWriter.pv"
    bool first = true;

    #line 147 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 147 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 147 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter_iter = Iter_ref_Parameter__value(&__iter);

        #line 148 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 148 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 148 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }

        #line 150 "src/compiler/DefinitionWriter.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 151 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 153 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(generator, file, parameter_iter->name->value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 157 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ")");
    #line 158 "src/compiler/DefinitionWriter.pv"
    return success;
}

#line 161 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 162 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 163 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 164 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 165 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 166 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 168 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 169 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 171 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 172 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 173 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 175 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&generator->function_context->coroutine.variables);
    #line 175 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 175 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 175 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 176 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 177 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, type, generics);
        #line 178 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 179 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, name);
        #line 180 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 183 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 184 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 186 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 188 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 189 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);

    #line 191 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 193 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(generator, file, &func_info->return_type, generics);
    #line 194 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 195 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 196 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 198 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "extern struct trait_Iter_");
    #line 199 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(generator, file, &name);
    #line 200 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 202 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 203 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(generator, file, func_info->name->value);
    #line 204 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 206 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 209 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct TypeFunctionUsage* function_usage) {
    #line 210 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 211 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = generator };

    #line 213 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 214 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 215 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 217 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 218 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 219 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 220 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 222 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 223 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");

        #line 225 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 226 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 227 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 229 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i < function_usage->function_context.coroutine.yield_count + 1; i++) {
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

        #line 270 "src/compiler/DefinitionWriter.pv"
        switch (func_info->parent.type) {
            #line 271 "src/compiler/DefinitionWriter.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 271 "src/compiler/DefinitionWriter.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 272 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_title(generator, file, struct_info->name->value);
                #line 273 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "__");
            } break;
            #line 275 "src/compiler/DefinitionWriter.pv"
            default: {
            } break;
        }

        #line 278 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, func_info->name->value);

        #line 280 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .fn_next = ");
        #line 281 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 282 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .fn_value = ");
        #line 283 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 284 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 286 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 289 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 290 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 291 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 292 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 293 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 294 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 297 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 300 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 301 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 302 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 303 "src/compiler/DefinitionWriter.pv"
    struct Token* enum_name = enum_info->name;
    #line 304 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 305 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 306 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 308 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, enum_info->context, enum_info->name);

    #line 310 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 311 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 312 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(generator, file, enum_name->value);
        #line 313 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 314 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 316 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

        #line 318 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 319 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 321 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 323 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 324 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 325 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 326 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 327 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 328 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, enum_info->name->value);
            #line 329 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 330 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 332 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 333 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 334 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 335 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 337 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 339 "src/compiler/DefinitionWriter.pv"
            DefinitionWriter__write_enum_variants(self, file, enum_info, generics);

            #line 341 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 342 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 343 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 344 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 347 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 348 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 350 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 351 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 352 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 353 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;

            #line 355 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 355 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 355 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 356 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 357 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(generator, file, generics->self_type, variant);
                #line 358 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 361 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 362 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 363 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 364 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 366 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 367 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 368 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, enum_info->name);
            #line 369 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(generator, file, generator->naming_ident.enum_generic_type_suffix);
            #line 370 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 373 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 374 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 374 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 374 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 375 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 378 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 379 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 380 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 381 "src/compiler/DefinitionWriter.pv"
            generator->indent += 1;
        }

        #line 384 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 384 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 384 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 385 "src/compiler/DefinitionWriter.pv"
            if (variant->names.length > 0) {
                #line 386 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 387 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 389 "src/compiler/DefinitionWriter.pv"
                uintptr_t i = 0;
                #line 390 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 390 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 390 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 391 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 392 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " ");
                    #line 393 "src/compiler/DefinitionWriter.pv"
                    Generator__write_str(generator, file, variant->names.data[i]);
                    #line 394 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "; ");
                    #line 395 "src/compiler/DefinitionWriter.pv"
                    i += 1;
                } }

                #line 398 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 399 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, variant->name->value);
                #line 400 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length == 1) {
                #line 402 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 403 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, variant->types.data, generics);
                #line 404 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 405 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 406 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 407 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 409 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(generator, file);
                #line 410 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 412 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 412 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 412 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 413 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(generator, file, type, generics);
                    #line 414 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 417 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 418 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 419 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(generator, file, name->value);
                #line 420 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 424 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 425 "src/compiler/DefinitionWriter.pv"
            generator->indent -= 1;
            #line 426 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 427 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 430 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 431 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 434 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 435 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, generics, false);

    #line 437 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 437 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 437 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 437 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 438 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 439 "src/compiler/DefinitionWriter.pv"
        if (usage != 0) {
            #line 439 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage->impl_functions, impl_index);
        }

        #line 441 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 441 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 441 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 442 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 443 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 444 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 444 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 446 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 447 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 448 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 448 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 449 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 452 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 453 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                #line 453 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_UsageContext__next(&__iter)) {
                    #line 453 "src/compiler/DefinitionWriter.pv"
                    struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                    #line 454 "src/compiler/DefinitionWriter.pv"
                    IncludeWriter__write(include_writer, file, generator, &usage_context->signature, usage_context->generic_map, false);
                    #line 455 "src/compiler/DefinitionWriter.pv"
                    usage_context->generic_map->self_type = generics->self_type;
                    #line 456 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 457 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                        #line 457 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 458 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                } }
            }
        } }

        #line 463 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 463 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 463 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 464 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 465 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 466 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 467 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 468 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 469 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 470 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 474 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 477 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 478 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 479 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 480 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 481 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 482 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage->impl_functions;
    #line 483 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 485 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &struct_info->module->context, struct_info->name);

    #line 487 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 488 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 490 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 491 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 492 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(generator, file, &field->type, generics);
        #line 493 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 495 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 496 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 498 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 498 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 498 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 499 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 500 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(generator, file, field->name->value, &field->type, generics);
            #line 501 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 504 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 505 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 508 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 508 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 509 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, generator, &usage_context->signature, generics, false);

    #line 511 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 511 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 511 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 511 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 512 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 513 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 514 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 514 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 516 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 516 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 516 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 517 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 518 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 519 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 519 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 521 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 522 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 523 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0) {
                        #line 524 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &function_usage->function_context;
                        #line 525 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 526 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    }

                    #line 529 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 530 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 530 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 532 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 533 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_decl(self, file, String__as_str(&name), trait_info, &impl_info->trait_type, func_info, generics)) {
                        #line 533 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }

                #line 536 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 539 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 540 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 541 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
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
                    } }

                    #line 552 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function) {
                        #line 553 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_instance_header(self, file, func_info, struct_info->name->value, generics, func_info->type == FUNCTION_TYPE__COROUTINE);
                    }
                }
            }
        } }

        #line 559 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 560 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_trait_default_decls(self, file, String__as_str(&name), impl_info, trait_info, generics)) {
                #line 560 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }

        #line 563 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 563 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 563 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 564 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 565 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 566 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 567 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 568 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 569 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 570 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 574 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 574 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 576 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 576 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 576 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 577 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 578 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 578 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 579 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 580 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, trait_entry._1, generics);
        #line 581 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 582 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 583 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 584 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 585 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 588 "src/compiler/DefinitionWriter.pv"
    if (usage->impl_dynamic_usage) {
        #line 589 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 590 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 591 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 592 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 595 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 598 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 599 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 601 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 603 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 603 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 603 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 604 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 605 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 606 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 606 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 608 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, &impl_info->trait_type, func_info, generics)) {
                    #line 608 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 611 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 615 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 616 "src/compiler/DefinitionWriter.pv"
        if (!DefinitionWriter__write_trait_default_decls(self, file, name, impl_info, trait_info, generics)) {
            #line 616 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 619 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 622 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 623 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 624 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);

    #line 626 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 626 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 626 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 627 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 630 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->impls.length > 0) {
        #line 630 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 632 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 632 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 632 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 633 "src/compiler/DefinitionWriter.pv"
        if (!impl_info->has_trait || impl_info->trait_ == 0) {
            #line 633 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 634 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 635 "src/compiler/DefinitionWriter.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 635 "src/compiler/DefinitionWriter.pv"
            continue;
        }
        #line 636 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 637 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(generator, file, &impl_info->trait_type, generics);
        #line 638 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 639 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, String__as_str(&name));
        #line 640 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 641 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, trait_info->name->value);
        #line 642 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 645 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 648 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 649 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 650 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 651 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &generator->root->type_void;

    #line 653 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 654 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 656 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 657 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 659 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 660 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 662 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 662 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 662 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 663 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 664 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
            #line 665 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*fn_", .length = strlen("(*fn_") });
            #line 666 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, func_info->name->value);
            #line 667 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 669 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 669 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 670 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 674 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 675 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 677 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(generator, file, &trait_info->module->context, trait_info->name);

    #line 679 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 680 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 682 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 683 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 684 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 685 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 687 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 688 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 690 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 693 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_function_with_body(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct Trait* trait_info, struct Type* impl_trait_type, struct GenericMap* generics, struct Module* module, struct TypeFunctionUsage* function_usage) {
    #line 694 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 695 "src/compiler/DefinitionWriter.pv"
    if (!DefinitionWriter__write_trait_function_decl(self, file, name, trait_info, impl_trait_type, func_info, generics)) {
        #line 696 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 697 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_info->name->value.length;
        #line 698 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_info->name->value.ptr);
        #line 699 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 702 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 703 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 705 "src/compiler/DefinitionWriter.pv"
    bool is_value_self = func_info->parameters.length > 0 && Type__is_self(&func_info->parameters.data[0].type);
    #line 706 "src/compiler/DefinitionWriter.pv"
    if (!is_value_self) {
        #line 707 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_self_cast(self, file, module, generics);
    }

    #line 710 "src/compiler/DefinitionWriter.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 711 "src/compiler/DefinitionWriter.pv"
    if (function_usage != 0) {
        #line 711 "src/compiler/DefinitionWriter.pv"
        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
    }
    #line 712 "src/compiler/DefinitionWriter.pv"
    generator->function_context = &func_context;

    #line 714 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block((struct BlockWriter[]){(struct BlockWriter) { .generator = generator }}, file, &func_info->return_type, func_info->body, generics, false, true)) {
        #line 715 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 716 "src/compiler/DefinitionWriter.pv"
        uint32_t func_name_length = func_info->name->value.length;
        #line 717 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.ptr, func_name_length, func_info->name->value.ptr);
        #line 718 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 721 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 722 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 723 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 725 "src/compiler/DefinitionWriter.pv"
    generator->function_context = 0;
    #line 726 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 729 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_size(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 730 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 731 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "uintptr_t ");
    #line 732 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 733 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__size(void* __self) {\n");

    #line 735 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 736 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 737 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return sizeof(struct ");
    #line 738 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);
    #line 739 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__Fn__Instance);\n");
    #line 740 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 741 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 744 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_get_params(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 745 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 746 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/Array_TypeId.h>\n");
    #line 747 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct Array_TypeId* ");
    #line 748 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 750 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 751 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params(void* __self) {\n");
    } else {
        #line 753 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params(void* __self) {\n");
    }

    #line 756 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;
    #line 757 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 758 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static TypeId type_ids[] = { ");

    #line 760 "src/compiler/DefinitionWriter.pv"
    bool first = true;
    #line 761 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 761 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 761 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 762 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 762 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 762 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }
        #line 763 "src/compiler/DefinitionWriter.pv"
        Generator__write_typeid(generator, file, &param->type, generics);
    } }

    #line 766 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " };\n");
    #line 767 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 768 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
    #line 769 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 770 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return &result;\n");
    #line 771 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 772 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 775 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_set_arg(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 776 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 777 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "bool ");
    #line 778 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 780 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 781 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
    } else {
        #line 783 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
    }

    #line 786 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 788 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 789 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 790 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(generator, file, func_info, generics);

    #line 792 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 793 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
    } else {
        #line 795 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 796 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 797 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 798 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 800 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }
    }

    #line 804 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 805 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "switch (index) {\n");
    #line 806 "src/compiler/DefinitionWriter.pv"
    generator->indent += 1;

    #line 808 "src/compiler/DefinitionWriter.pv"
    uintptr_t i = 0;
    #line 809 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 809 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 809 "src/compiler/DefinitionWriter.pv"
        struct Parameter* param = Iter_ref_Parameter__value(&__iter);

        #line 810 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 811 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case %zu: self->", i);
        #line 812 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(generator, file, param->name);
        #line 813 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = ");

        #line 815 "src/compiler/DefinitionWriter.pv"
        if (!Generator__is_reference(&param->type)) {
            #line 816 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*(");
            #line 817 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &param->type, generics);
            #line 818 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "*)");
        } else {
            #line 820 "src/compiler/DefinitionWriter.pv"
            if (module->mode_cpp) {
                #line 821 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "(");
                #line 822 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(generator, file, &param->type, generics);
                #line 823 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ")");
            }
        }

        #line 827 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "value; return true;\n");
        #line 828 "src/compiler/DefinitionWriter.pv"
        i += 1;
    } }

    #line 831 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 832 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 833 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");

    #line 835 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(generator, file);
    #line 836 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "return false;\n");

    #line 838 "src/compiler/DefinitionWriter.pv"
    generator->indent -= 1;
    #line 839 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "}\n");
}

#line 842 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_execute_or_init(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 843 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 844 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 845 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct Iter_CoroutineStatus ");
        #line 846 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 847 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

        #line 849 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 851 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 852 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 853 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 854 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

        #line 856 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 857 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 858 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 859 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
        #line 860 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 861 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "));\n");

        #line 863 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 863 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 863 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 864 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(generator, file);
            #line 865 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "instance->");
            #line 866 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 867 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = self->");
            #line 868 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
            #line 869 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 872 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 873 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "return (struct trait_Iter_CoroutineStatus) { .vtable = &");

        #line 875 "src/compiler/DefinitionWriter.pv"
        switch (func_info->parent.type) {
            #line 876 "src/compiler/DefinitionWriter.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 876 "src/compiler/DefinitionWriter.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 877 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_title(generator, file, struct_info->name->value);
                #line 878 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "__");
            } break;
            #line 880 "src/compiler/DefinitionWriter.pv"
            default: {
            } break;
        }
        #line 882 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(generator, file, func_info->name->value);

        #line 884 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

        #line 886 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 887 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    } else {
        #line 889 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "void ");
        #line 890 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 891 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute(void* __self) {\n");

        #line 893 "src/compiler/DefinitionWriter.pv"
        generator->indent += 1;

        #line 895 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 896 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 897 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 898 "src/compiler/DefinitionWriter.pv"
        if (module->mode_cpp) {
            #line 899 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = (struct ");
            #line 900 "src/compiler/DefinitionWriter.pv"
            Generator__write_function_name(generator, file, func_info, generics);
            #line 901 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance*)__self;\n");
        } else {
            #line 903 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__Fn__Instance* self = __self;\n");
        }

        #line 906 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(generator, file);
        #line 907 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 908 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "(");

        #line 910 "src/compiler/DefinitionWriter.pv"
        bool first = true;
        #line 911 "src/compiler/DefinitionWriter.pv"
        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
        #line 911 "src/compiler/DefinitionWriter.pv"
        while (Iter_ref_Parameter__next(&__iter)) {
            #line 911 "src/compiler/DefinitionWriter.pv"
            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

            #line 912 "src/compiler/DefinitionWriter.pv"
            if (first) {
                #line 912 "src/compiler/DefinitionWriter.pv"
                first = false;
            } else {
                #line 912 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ", ");
            }
            #line 913 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "self->");
            #line 914 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(generator, file, param->name);
        } }

        #line 917 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ");\n");

        #line 919 "src/compiler/DefinitionWriter.pv"
        generator->indent -= 1;
        #line 920 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");
    }
}

#line 924 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_vtable(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 925 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 926 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 927 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Co_CoroutineStatusVTable ");
    } else {
        #line 929 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_FnVTable ");
    }

    #line 932 "src/compiler/DefinitionWriter.pv"
    switch (func_info->parent.type) {
        #line 933 "src/compiler/DefinitionWriter.pv"
        case FUNCTION_PARENT__STRUCT: {
            #line 933 "src/compiler/DefinitionWriter.pv"
            struct Struct* struct_info = func_info->parent.struct_value._0;
            #line 934 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, struct_info->name->value);
            #line 935 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "__");
        } break;
        #line 937 "src/compiler/DefinitionWriter.pv"
        default: {
        } break;
    }
    #line 939 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(generator, file, func_info->name->value);

    #line 941 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 942 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__CO");
    } else {
        #line 944 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__DYN_FN");
    }

    #line 947 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 948 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_get_params = &");
        #line 949 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 950 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__get_params, .fn_set_arg = &");
        #line 951 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 952 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__set_arg, .fn_init = &");
        #line 953 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 954 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Co__init };\n");
    } else {
        #line 956 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " = { .fn_size = &");
        #line 957 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 958 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__size, .fn_get_params = &");
        #line 959 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 960 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__get_params, .fn_set_arg = &");
        #line 961 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 962 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__set_arg, .fn_execute = &");
        #line 963 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(generator, file, func_info, generics);
        #line 964 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__Fn__execute };\n");
    }
}

#line 968 "src/compiler/DefinitionWriter.pv"
void DefinitionWriter__write_dynamic_function_impl(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct Module* module) {
    #line 969 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 970 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 971 "src/compiler/DefinitionWriter.pv"
    if (Generator__is_coroutine(generator)) {
        #line 972 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Allocator.h>\n");
    }
    #line 974 "src/compiler/DefinitionWriter.pv"
    if (!Generator__is_coroutine(generator)) {
        #line 974 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_dynamic_size(self, file, func_info, generics);
    }
    #line 975 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_get_params(self, file, func_info, generics);
    #line 976 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_set_arg(self, file, func_info, generics, module);
    #line 977 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_execute_or_init(self, file, func_info, generics, module);
    #line 978 "src/compiler/DefinitionWriter.pv"
    DefinitionWriter__write_dynamic_vtable(self, file, func_info, generics);
}

#line 981 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 982 "src/compiler/DefinitionWriter.pv"
    struct Generator* generator = self->generator;
    #line 983 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, Type__deref(generics->self_type), generics->self_type, generics);
    #line 984 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 985 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 987 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 989 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 989 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 989 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 989 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 990 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 991 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 992 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 992 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 994 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 994 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 994 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 995 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 996 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 997 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 997 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 999 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 1000 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1001 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 1002 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, function_usage)) {
                        #line 1002 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 1004 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 1005 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 1006 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 1007 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1010 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                    #line 1011 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0) {
                        #line 1011 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 1012 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = &func_context;

                    #line 1014 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage)) {
                        #line 1015 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 1016 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 1017 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 1020 "src/compiler/DefinitionWriter.pv"
                    struct TypeFunctionUsage* function_usage = 0;
                    #line 1021 "src/compiler/DefinitionWriter.pv"
                    if (impl_functions_for_impl != 0) {
                        #line 1021 "src/compiler/DefinitionWriter.pv"
                        function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                    }

                    #line 1023 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 1024 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_dynamic_function_impl(self, file, func_info, generics, module);
                    }

                    #line 1027 "src/compiler/DefinitionWriter.pv"
                    generator->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 1030 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 1031 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(generator->allocator, sizeof(struct Function));
                    #line 1032 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 1034 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 1034 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 1034 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 1035 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 1038 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 1040 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, generator, &usage_context->body, generics3, true);
                        #line 1041 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 1042 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 1043 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_info->name->value.length;
                            #line 1044 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                            #line 1045 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 1048 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
                        #line 1049 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                        #line 1050 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = &func_context;

                        #line 1052 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, function_usage);

                        #line 1054 "src/compiler/DefinitionWriter.pv"
                        generator->function_context = 0;
                    } }
                }
            }
        } }

        #line 1060 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 1061 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 1061 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 1061 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 1061 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 1062 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 1062 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 1064 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 1065 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_trait_function_with_body(self, file, String__as_str(&name), func_info, trait_info, &impl_info->trait_type, generics, module, 0)) {
                    #line 1065 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } }
        }

        #line 1069 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1069 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1069 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1070 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1071 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(generator, file, &impl_const->type, generics);
            #line 1072 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1073 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, String__as_str(&name));
            #line 1074 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1075 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(generator, file, impl_const->name->value);
            #line 1076 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1077 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, file, impl_const->value, generics);
            #line 1078 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1082 "src/compiler/DefinitionWriter.pv"
    return true;
}
