#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>
#include <compiler/DefinitionWriter.h>
#include <compiler/Generator.h>
#include <analyzer/Context.h>
#include <analyzer/types/Function.h>
#include <analyzer/Token.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/GenericMap.h>
#include <std/String.h>
#include <std/HashMap_str_usize.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Naming.h>
#include <std/Array_Parameter.h>
#include <std/Iter_ref_Parameter.h>
#include <analyzer/types/Parameter.h>
#include <std/str.h>
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
#include <analyzer/types/Enum.h>
#include <std/Array_char.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <analyzer/types/EnumVariant.h>
#include <analyzer/expression/Expression.h>
#include <compiler/ExpressionWriter.h>
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
#include <std/HashMap_str_Function.h>
#include <analyzer/Impl.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <std/Array_UsageContext.h>
#include <std/Iter_ref_UsageContext.h>
#include <compiler/TypeUsage_Struct.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Module.h>
#include <analyzer/types/StructType.h>
#include <analyzer/types/StructField.h>
#include <std/HashMapBucket_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_StructField.h>
#include <analyzer/types/Trait.h>
#include <analyzer/Root.h>
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
bool DefinitionWriter__write_function_definition(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics, struct String* custom_name) {
    #line 20 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 21 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(g, file, func_info->context, func_info->name);

    #line 23 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 24 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "bool");
    } else {
        #line 26 "src/compiler/DefinitionWriter.pv"
        if (!Generator__write_type(g, file, &func_info->return_type, generics)) {
            #line 26 "src/compiler/DefinitionWriter.pv"
            return false;
        }
    }

    #line 29 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 30 "src/compiler/DefinitionWriter.pv"
    if (custom_name != 0) {
        #line 31 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(g, file, custom_name);
    } else {
        #line 33 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.map.length > 0) {
            #line 34 "src/compiler/DefinitionWriter.pv"
            struct String name = Naming__get_type_name(&g->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);
            #line 35 "src/compiler/DefinitionWriter.pv"
            Generator__write_string(g, file, &name);
        } else {
            #line 37 "src/compiler/DefinitionWriter.pv"
            if (!Generator__write_function_name(g, file, func_info, generics)) {
                #line 37 "src/compiler/DefinitionWriter.pv"
                return false;
            }
        }
    }

    #line 41 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 42 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next(void* _ctx)");
        #line 43 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 46 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "(");

    #line 48 "src/compiler/DefinitionWriter.pv"
    bool success = true;
    #line 49 "src/compiler/DefinitionWriter.pv"
    bool first = true;

    #line 51 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
    #line 51 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_Parameter__next(&__iter)) {
        #line 51 "src/compiler/DefinitionWriter.pv"
        struct Parameter* parameter_iter = Iter_ref_Parameter__value(&__iter);

        #line 52 "src/compiler/DefinitionWriter.pv"
        if (first) {
            #line 52 "src/compiler/DefinitionWriter.pv"
            first = false;
        } else {
            #line 52 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ", ");
        }

        #line 54 "src/compiler/DefinitionWriter.pv"
        if (Generator__has_void_self_replacement(parameter_iter, generics)) {
            #line 55 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(g, file, (struct str){ .ptr = "__self", .length = strlen("__self") }, &parameter_iter->type, generics) && success;
        } else {
            #line 57 "src/compiler/DefinitionWriter.pv"
            success = Generator__write_variable_decl(g, file, parameter_iter->name->value, &parameter_iter->type, generics) && success;
        }
    } }

    #line 61 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ")");
    #line 62 "src/compiler/DefinitionWriter.pv"
    return success;
}

#line 65 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_coroutine(struct DefinitionWriter* self, FILE* file, struct Function* func_info, struct GenericMap* generics) {
    #line 66 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 67 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct ");
    #line 68 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(g, file, func_info, generics);
    #line 69 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " {\n");
    #line 70 "src/compiler/DefinitionWriter.pv"
    g->indent += 1;

    #line 72 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(g, file);
    #line 73 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "int32_t _state;\n");

    #line 75 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(g, file);
    #line 76 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(g, file, &func_info->return_type, generics);
    #line 77 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " _value;\n\n");

    #line 79 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Type __iter = HashMap_str_ref_Type__iter(&g->function_context->coroutine.variables);
    #line 79 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Type__next(&__iter)) {
        #line 79 "src/compiler/DefinitionWriter.pv"
        struct str name = HashMapIter_str_ref_Type__value(&__iter)->_0;
        #line 79 "src/compiler/DefinitionWriter.pv"
        struct Type* type = HashMapIter_str_ref_Type__value(&__iter)->_1;

        #line 80 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(g, file);
        #line 81 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(g, file, type, generics);
        #line 82 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 83 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(g, file, name);
        #line 84 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 87 "src/compiler/DefinitionWriter.pv"
    g->indent -= 1;
    #line 88 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 90 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <std/trait_Iter_");

    #line 92 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, &func_info->return_type, generics->self_type, generics);
    #line 93 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(g, file, &name);

    #line 95 "src/compiler/DefinitionWriter.pv"
    fprintf(file, ".h>\n");

    #line 97 "src/compiler/DefinitionWriter.pv"
    Generator__write_type(g, file, &func_info->return_type, generics);
    #line 98 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 99 "src/compiler/DefinitionWriter.pv"
    Generator__write_function_name(g, file, func_info, generics);
    #line 100 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__value(void* ctx);\n");

    #line 102 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "extern struct trait_Iter_");
    #line 103 "src/compiler/DefinitionWriter.pv"
    Generator__write_string(g, file, &name);
    #line 104 "src/compiler/DefinitionWriter.pv"
    String__release(&name);

    #line 106 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "VTable ");
    #line 107 "src/compiler/DefinitionWriter.pv"
    Generator__write_str_title(g, file, func_info->name->value);
    #line 108 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "__VTABLE__ITER;\n");

    #line 110 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 113 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_function_block(struct DefinitionWriter* self, FILE* file, struct str name, struct Function* func_info, struct GenericMap* generics, struct TypeFunctionUsage* function_usage) {
    #line 114 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 115 "src/compiler/DefinitionWriter.pv"
    struct BlockWriter blocks = (struct BlockWriter) { .generator = g };

    #line 117 "src/compiler/DefinitionWriter.pv"
    if (func_info->type == FUNCTION_TYPE__COROUTINE) {
        #line 118 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 119 "src/compiler/DefinitionWriter.pv"
        g->indent += 1;

        #line 121 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(g, file);
        #line 122 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct ");
        #line 123 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(g, file, func_info, generics);
        #line 124 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "* ctx = _ctx;\n");

        #line 126 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(g, file);
        #line 127 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "switch (ctx->_state) {\n");
        #line 128 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "case 0: break;\n");
        #line 129 "src/compiler/DefinitionWriter.pv"
        g->indent += 1;

        #line 131 "src/compiler/DefinitionWriter.pv"
        for (uintptr_t i = 1; i < function_usage->function_context.coroutine.yield_count + 1; i++) {
            #line 132 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 133 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "case %zu: goto yield_%zu;\n", i, i);
        }

        #line 136 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(g, file);
        #line 137 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "default: return false;\n");

        #line 139 "src/compiler/DefinitionWriter.pv"
        g->indent -= 1;
        #line 140 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(g, file);
        #line 141 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n\n");

        #line 143 "src/compiler/DefinitionWriter.pv"
        g->function_context->coroutine.yield_count = 0;
        #line 144 "src/compiler/DefinitionWriter.pv"
        if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, true)) {
            #line 145 "src/compiler/DefinitionWriter.pv"
            uint32_t name_length = name.length;
            #line 146 "src/compiler/DefinitionWriter.pv"
            fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
            #line 147 "src/compiler/DefinitionWriter.pv"
            fclose(file);
            #line 148 "src/compiler/DefinitionWriter.pv"
            return false;
        }

        #line 151 "src/compiler/DefinitionWriter.pv"
        Generator__write_indent(g, file);
        #line 152 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "ctx->_state = -1; return false;\n");

        #line 154 "src/compiler/DefinitionWriter.pv"
        g->indent -= 1;
        #line 155 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "}\n");

        #line 157 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(g, file, &func_info->return_type, generics);
        #line 158 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " ");
        #line 159 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(g, file, func_info, generics);
        #line 160 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value(void* ctx) { return ((struct ");
        #line 161 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(g, file, func_info, generics);
        #line 162 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "*)ctx)->_value; }\n");

        #line 164 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct trait_Iter_");

        #line 166 "src/compiler/DefinitionWriter.pv"
        struct String name = Naming__get_type_name(&g->naming_ident, &func_info->return_type, generics->self_type, generics);
        #line 167 "src/compiler/DefinitionWriter.pv"
        Generator__write_string(g, file, &name);
        #line 168 "src/compiler/DefinitionWriter.pv"
        String__release(&name);

        #line 170 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");

        #line 172 "src/compiler/DefinitionWriter.pv"
        switch (func_info->parent.type) {
            #line 173 "src/compiler/DefinitionWriter.pv"
            case FUNCTION_PARENT__STRUCT: {
                #line 173 "src/compiler/DefinitionWriter.pv"
                struct Struct* struct_info = func_info->parent.struct_value._0;
                #line 174 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_title(g, file, struct_info->name->value);
                #line 175 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "__");
            } break;
            #line 177 "src/compiler/DefinitionWriter.pv"
            default: {
            } break;
        }

        #line 180 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(g, file, func_info->name->value);

        #line 182 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__ITER = { .next = ");
        #line 183 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(g, file, func_info, generics);
        #line 184 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__next, .value = ");
        #line 185 "src/compiler/DefinitionWriter.pv"
        Generator__write_function_name(g, file, func_info, generics);
        #line 186 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__value };\n\n");

        #line 188 "src/compiler/DefinitionWriter.pv"
        return true;
    }

    #line 191 "src/compiler/DefinitionWriter.pv"
    fprintf(file, " ");
    #line 192 "src/compiler/DefinitionWriter.pv"
    if (!BlockWriter__write_block(&blocks, file, &func_info->return_type, func_info->body, generics, false, false)) {
        #line 193 "src/compiler/DefinitionWriter.pv"
        uint32_t name_length = name.length;
        #line 194 "src/compiler/DefinitionWriter.pv"
        fprintf(stderr, "Failed to write block for %.*s", name_length, name.ptr);
        #line 195 "src/compiler/DefinitionWriter.pv"
        fclose(file);
        #line 196 "src/compiler/DefinitionWriter.pv"
        return false;
    }

    #line 199 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 202 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_enum_definition(struct DefinitionWriter* self, FILE* file, struct Enum* enum_info, struct TypeUsage_Enum* usage, struct UsageContext* usage_context, struct IncludeWriter* include_writer) {
    #line 203 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 204 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 205 "src/compiler/DefinitionWriter.pv"
    struct Token* enum_name = enum_info->name;
    #line 206 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 207 "src/compiler/DefinitionWriter.pv"
    uint32_t name_length = name.array.length;
    #line 208 "src/compiler/DefinitionWriter.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);

    #line 210 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(g, file, enum_info->context, enum_info->name);

    #line 212 "src/compiler/DefinitionWriter.pv"
    if (!is_discriminated_union) {
        #line 213 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "enum ");
        #line 214 "src/compiler/DefinitionWriter.pv"
        Generator__write_str(g, file, enum_name->value);
        #line 215 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " {\n");
        #line 216 "src/compiler/DefinitionWriter.pv"
        g->indent += 1;

        #line 218 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 218 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 218 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 219 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 220 "src/compiler/DefinitionWriter.pv"
            Generator__write_enum_variant_name(g, file, generics->self_type, variant);

            #line 222 "src/compiler/DefinitionWriter.pv"
            if (variant->value != 0) {
                #line 223 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " = ");
                #line 224 "src/compiler/DefinitionWriter.pv"
                ExpressionWriter__write_expression(&(struct ExpressionWriter) { .generator = g }, file, variant->value, generics);
            }

            #line 227 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ",\n");
        } }

        #line 230 "src/compiler/DefinitionWriter.pv"
        g->indent -= 1;
        #line 231 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    } else {
        #line 233 "src/compiler/DefinitionWriter.pv"
        bool has_generics = enum_info->generics.array.length > 0;

        #line 235 "src/compiler/DefinitionWriter.pv"
        if (has_generics) {
            #line 236 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#ifndef PAVE_");
            #line 237 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, enum_info->name->value);
            #line 238 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, g->naming_ident.enum_generic_type_suffix);
            #line 239 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n#define PAVE_");
            #line 240 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, enum_info->name->value);
            #line 241 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, g->naming_ident.enum_generic_type_suffix);
            #line 242 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");

            #line 244 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 245 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(g, file, enum_info->name);
            #line 246 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(g, file, g->naming_ident.enum_generic_type_suffix);
            #line 247 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " {\n");

            #line 249 "src/compiler/DefinitionWriter.pv"
            g->indent += 1;

            #line 251 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 251 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 251 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 252 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(g, file);
                #line 253 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(g, file, generics->self_type, variant);

                #line 255 "src/compiler/DefinitionWriter.pv"
                if (variant->value != 0) {
                    #line 256 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " = ");
                    #line 257 "src/compiler/DefinitionWriter.pv"
                    ExpressionWriter__write_expression(&(struct ExpressionWriter) { .generator = g }, file, variant->value, generics);
                }

                #line 260 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 263 "src/compiler/DefinitionWriter.pv"
            g->indent -= 1;
            #line 264 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
            #line 265 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "#endif\n");
            #line 266 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        }

        #line 269 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 270 "src/compiler/DefinitionWriter.pv"
        g->indent += 1;

        #line 272 "src/compiler/DefinitionWriter.pv"
        if (!has_generics) {
            #line 273 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 274 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum {\n");
            #line 275 "src/compiler/DefinitionWriter.pv"
            g->indent += 1;

            #line 277 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 277 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 277 "src/compiler/DefinitionWriter.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 278 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(g, file);
                #line 279 "src/compiler/DefinitionWriter.pv"
                Generator__write_enum_variant_name(g, file, generics->self_type, variant);
                #line 280 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ",\n");
            } }

            #line 283 "src/compiler/DefinitionWriter.pv"
            g->indent -= 1;
            #line 284 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 285 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "} type;\n");
            #line 286 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
        } else {
            #line 288 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 289 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "enum ");
            #line 290 "src/compiler/DefinitionWriter.pv"
            Generator__write_token(g, file, enum_info->name);
            #line 291 "src/compiler/DefinitionWriter.pv"
            Generator__write_str(g, file, g->naming_ident.enum_generic_type_suffix);
            #line 292 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " type;\n");
        }

        #line 295 "src/compiler/DefinitionWriter.pv"
        uintptr_t variants_with_data = 0;
        #line 296 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 296 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 296 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 297 "src/compiler/DefinitionWriter.pv"
            variants_with_data += (uintptr_t)(variant->types.length > 0);
        } }

        #line 300 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 301 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 302 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "union {\n");
            #line 303 "src/compiler/DefinitionWriter.pv"
            g->indent += 1;
        }

        #line 306 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 306 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 306 "src/compiler/DefinitionWriter.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 307 "src/compiler/DefinitionWriter.pv"
            if (variant->types.length == 1) {
                #line 308 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(g, file);
                #line 309 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(g, file, variant->types.data, generics);
                #line 310 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " ");
                #line 311 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 312 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(g, file, name->value);
                #line 313 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            } else if (variant->types.length > 1) {
                #line 315 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(g, file);
                #line 316 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "struct { ");

                #line 318 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 318 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 318 "src/compiler/DefinitionWriter.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 319 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(g, file, type, generics);
                    #line 320 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " _%zu; ", type - variant->types.data);
                } }

                #line 323 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "} ");
                #line 324 "src/compiler/DefinitionWriter.pv"
                struct Token* name = variant->name;
                #line 325 "src/compiler/DefinitionWriter.pv"
                Generator__write_str_lowercase(g, file, name->value);
                #line 326 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "_value;\n");
            }
        } }

        #line 330 "src/compiler/DefinitionWriter.pv"
        if (variants_with_data > 1) {
            #line 331 "src/compiler/DefinitionWriter.pv"
            g->indent -= 1;
            #line 332 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 333 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "};\n");
        }

        #line 336 "src/compiler/DefinitionWriter.pv"
        g->indent -= 1;
        #line 337 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 340 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 341 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(include_writer, file, g, &usage_context->signature, generics, false);

    #line 343 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&enum_info->impls));
    #line 343 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 343 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 343 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 344 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 345 "src/compiler/DefinitionWriter.pv"
        if (usage != 0) {
            #line 345 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(&usage->impl_functions, impl_index);
        }

        #line 347 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 347 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 347 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 348 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 349 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 350 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 350 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 352 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 353 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 354 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 354 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 355 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 358 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0 && function_usage != 0) {
                #line 359 "src/compiler/DefinitionWriter.pv"
                { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                #line 359 "src/compiler/DefinitionWriter.pv"
                while (Iter_ref_UsageContext__next(&__iter)) {
                    #line 359 "src/compiler/DefinitionWriter.pv"
                    struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                    #line 360 "src/compiler/DefinitionWriter.pv"
                    IncludeWriter__write(include_writer, file, g, &usage_context->signature, usage_context->generic_map, false);
                    #line 361 "src/compiler/DefinitionWriter.pv"
                    usage_context->generic_map->self_type = generics->self_type;
                    #line 362 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 363 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                        #line 363 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                    #line 364 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, ";\n");
                } }
            }
        } }
    } }

    #line 370 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 373 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_struct_definition(struct DefinitionWriter* self, FILE* file, struct Struct* struct_info, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 374 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 375 "src/compiler/DefinitionWriter.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 376 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 377 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 378 "src/compiler/DefinitionWriter.pv"
    struct Array_HashMap_usize_TypeFunctionUsage* impl_functions = &usage->impl_functions;
    #line 379 "src/compiler/DefinitionWriter.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 381 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(g, file, &struct_info->module->context, struct_info->name);

    #line 383 "src/compiler/DefinitionWriter.pv"
    if (struct_info->type == STRUCT_TYPE__INCOMPLETE) {
        #line 384 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s;\n", name_length, name.array.data);
    } else if (Struct__is_newtype(struct_info)) {
        #line 386 "src/compiler/DefinitionWriter.pv"
        struct StructField* field = &struct_info->fields.data[0].value;
        #line 387 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "typedef ");
        #line 388 "src/compiler/DefinitionWriter.pv"
        Generator__write_type(g, file, &field->type, generics);
        #line 389 "src/compiler/DefinitionWriter.pv"
        fprintf(file, " %.*s;\n", name_length, name.array.data);
    } else {
        #line 391 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "struct %.*s {\n", name_length, name.array.data);
        #line 392 "src/compiler/DefinitionWriter.pv"
        g->indent += 1;

        #line 394 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 394 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 394 "src/compiler/DefinitionWriter.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 395 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 396 "src/compiler/DefinitionWriter.pv"
            Generator__write_variable_decl(g, file, field->name->value, &field->type, generics);
            #line 397 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }

        #line 400 "src/compiler/DefinitionWriter.pv"
        g->indent -= 1;
        #line 401 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "};\n");
    }

    #line 404 "src/compiler/DefinitionWriter.pv"
    if (usage_context->signature.length > 0) {
        #line 404 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }
    #line 405 "src/compiler/DefinitionWriter.pv"
    IncludeWriter__write(&include_writer, file, g, &usage_context->signature, generics, false);

    #line 407 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(&struct_info->impls));
    #line 407 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 407 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 407 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 408 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 409 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 410 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 410 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 412 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 412 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 412 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 413 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 414 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 415 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 415 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 417 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 418 "src/compiler/DefinitionWriter.pv"
                if (trait_info == 0) {
                    #line 419 "src/compiler/DefinitionWriter.pv"
                    if (func_info->type == FUNCTION_TYPE__COROUTINE && function_usage != 0) {
                        #line 420 "src/compiler/DefinitionWriter.pv"
                        g->function_context = &function_usage->function_context;
                        #line 421 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_coroutine(self, file, func_info, generics);
                        #line 422 "src/compiler/DefinitionWriter.pv"
                        g->function_context = 0;
                    }

                    #line 425 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 426 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 426 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                } else {
                    #line 428 "src/compiler/DefinitionWriter.pv"
                    struct GenericMap generics_void = *generics;
                    #line 429 "src/compiler/DefinitionWriter.pv"
                    generics_void.self_type = &g->root->type_void;

                    #line 431 "src/compiler/DefinitionWriter.pv"
                    struct String func_name = Generator__get_trait_function_name(g, String__as_str(&name), trait_info, func_info, generics);
                    #line 432 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "\n");
                    #line 433 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                        #line 433 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }
                }

                #line 436 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            }

            #line 439 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 440 "src/compiler/DefinitionWriter.pv"
                struct TypeFunctionUsage* function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                #line 441 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 442 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 442 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 442 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 443 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(&include_writer, file, g, &usage_context->signature, usage_context->generic_map, false);
                        #line 446 "src/compiler/DefinitionWriter.pv"
                        usage_context->generic_map->self_type = generics->self_type;
                        #line 447 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 448 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, usage_context->generic_map, 0)) {
                            #line 448 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }
                        #line 449 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, ";\n");
                    } }

                    #line 452 "src/compiler/DefinitionWriter.pv"
                    if (function_usage->impl_dynamic_function) {
                        #line 453 "src/compiler/DefinitionWriter.pv"
                        if (func_info->type == FUNCTION_TYPE__COROUTINE) {
                            #line 454 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "#include <std/trait_Co_CoroutineStatus.h>\n");
                            #line 455 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 456 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 457 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance { ");
                            #line 458 "src/compiler/DefinitionWriter.pv"
                            g->indent += 1;
                            #line 459 "src/compiler/DefinitionWriter.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 459 "src/compiler/DefinitionWriter.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 459 "src/compiler/DefinitionWriter.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 460 "src/compiler/DefinitionWriter.pv"
                                Generator__write_type(g, file, &param->type, generics);
                                #line 461 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, " ");
                                #line 462 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(g, file, param->name);
                                #line 463 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "; ");
                            } }
                            #line 465 "src/compiler/DefinitionWriter.pv"
                            g->indent -= 1;
                            #line 466 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "};\n");

                            #line 468 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "extern struct trait_Co_CoroutineStatusVTable ");
                            #line 469 "src/compiler/DefinitionWriter.pv"
                            Generator__write_str_title(g, file, struct_info->name->value);
                            #line 470 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__");
                            #line 471 "src/compiler/DefinitionWriter.pv"
                            Generator__write_str_title(g, file, func_info->name->value);
                            #line 472 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__CO;\n");
                        } else {
                            #line 474 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "#include <std/trait_Fn.h>\n");
                            #line 475 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 476 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 477 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__Instance { ");
                            #line 478 "src/compiler/DefinitionWriter.pv"
                            g->indent += 1;
                            #line 479 "src/compiler/DefinitionWriter.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 479 "src/compiler/DefinitionWriter.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 479 "src/compiler/DefinitionWriter.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 480 "src/compiler/DefinitionWriter.pv"
                                Generator__write_type(g, file, &param->type, generics);
                                #line 481 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, " ");
                                #line 482 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(g, file, param->name);
                                #line 483 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "; ");
                            } }
                            #line 485 "src/compiler/DefinitionWriter.pv"
                            g->indent -= 1;
                            #line 486 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "};\n");

                            #line 488 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "extern struct trait_FnVTable ");
                            #line 489 "src/compiler/DefinitionWriter.pv"
                            Generator__write_str_title(g, file, struct_info->name->value);
                            #line 490 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__");
                            #line 491 "src/compiler/DefinitionWriter.pv"
                            Generator__write_str_title(g, file, func_info->name->value);
                            #line 492 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__DYN_FN;\n");
                        }
                    }
                }
            }
        } }

        #line 499 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 500 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 500 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 500 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 500 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 501 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 501 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 503 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 504 "src/compiler/DefinitionWriter.pv"
                struct GenericMap generics_void = *generics;
                #line 505 "src/compiler/DefinitionWriter.pv"
                generics_void.self_type = &g->root->type_void;

                #line 507 "src/compiler/DefinitionWriter.pv"
                struct String func_name = Generator__get_trait_function_name(g, String__as_str(&name), trait_info, func_info, generics);
                #line 508 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                    #line 508 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
                #line 509 "src/compiler/DefinitionWriter.pv"
                fprintf(file, ";\n");
            } }
        }

        #line 513 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 513 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 513 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 514 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nextern const ");
            #line 515 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(g, file, &impl_const->type, generics);
            #line 516 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 517 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, String__as_str(&name));
            #line 518 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 519 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, impl_const->name->value);
            #line 520 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 524 "src/compiler/DefinitionWriter.pv"
    if (struct_info->traits.length > 0) {
        #line 524 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 526 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 526 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 526 "src/compiler/DefinitionWriter.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 527 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 528 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct ");
        #line 529 "src/compiler/DefinitionWriter.pv"
        Generator__write_type_name(g, file, trait_entry._1, generics);
        #line 530 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 531 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(g, file, String__as_str(&name));
        #line 532 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 533 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(g, file, trait_info->name->value);
        #line 534 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 537 "src/compiler/DefinitionWriter.pv"
    if (usage->impl_dynamic_usage) {
        #line 538 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "#include <std/trait_Struct.h>\n");
        #line 539 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_StructVTable ");
        #line 540 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(g, file, String__as_str(&name));
        #line 541 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__STRUCT;\n");
    }

    #line 544 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 547 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impl_definition(struct DefinitionWriter* self, FILE* file, struct str name, struct Impl* impl_info, struct GenericMap* generics) {
    #line 548 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 549 "src/compiler/DefinitionWriter.pv"
    struct Trait* trait_info = impl_info->trait_;

    #line 551 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");

    #line 553 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
    #line 553 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 553 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 554 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 555 "src/compiler/DefinitionWriter.pv"
            if (trait_info == 0) {
                #line 556 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                    #line 556 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            } else {
                #line 558 "src/compiler/DefinitionWriter.pv"
                struct GenericMap generics_void = *generics;
                #line 559 "src/compiler/DefinitionWriter.pv"
                generics_void.self_type = &g->root->type_void;

                #line 561 "src/compiler/DefinitionWriter.pv"
                struct String func_name = Generator__get_trait_function_name(g, name, trait_info, func_info, generics);
                #line 562 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                    #line 562 "src/compiler/DefinitionWriter.pv"
                    return false;
                }
            }

            #line 565 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 569 "src/compiler/DefinitionWriter.pv"
    if (trait_info != 0) {
        #line 570 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 570 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 570 "src/compiler/DefinitionWriter.pv"
            struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
            #line 570 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 571 "src/compiler/DefinitionWriter.pv"
            if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                #line 571 "src/compiler/DefinitionWriter.pv"
                continue;
            }

            #line 573 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\n");
            #line 574 "src/compiler/DefinitionWriter.pv"
            struct GenericMap generics_void = *generics;
            #line 575 "src/compiler/DefinitionWriter.pv"
            generics_void.self_type = &g->root->type_void;

            #line 577 "src/compiler/DefinitionWriter.pv"
            struct String func_name = Generator__get_trait_function_name(g, name, trait_info, func_info, generics);
            #line 578 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                #line 578 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 579 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    }

    #line 583 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 586 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_primitive_definition(struct DefinitionWriter* self, FILE* file, struct Primitive* primitive_info, struct GenericMap* generics) {
    #line 587 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 588 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);

    #line 590 "src/compiler/DefinitionWriter.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 590 "src/compiler/DefinitionWriter.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 590 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 591 "src/compiler/DefinitionWriter.pv"
        DefinitionWriter__write_impl_definition(self, file, String__as_str(&name), impl_info, generics);
    } }

    #line 594 "src/compiler/DefinitionWriter.pv"
    if (primitive_info->traits.length > 0) {
        #line 594 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "\n");
    }

    #line 596 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&primitive_info->traits);
    #line 596 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 596 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 597 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "extern struct trait_");
        #line 598 "src/compiler/DefinitionWriter.pv"
        Generator__write_token(g, file, trait_info->name);
        #line 599 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "VTable ");
        #line 600 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(g, file, String__as_str(&name));
        #line 601 "src/compiler/DefinitionWriter.pv"
        fprintf(file, "__VTABLE__");
        #line 602 "src/compiler/DefinitionWriter.pv"
        Generator__write_str_title(g, file, trait_info->name->value);
        #line 603 "src/compiler/DefinitionWriter.pv"
        fprintf(file, ";\n");
    } }

    #line 606 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 609 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_trait_definition(struct DefinitionWriter* self, FILE* file, struct Trait* trait_info, struct GenericMap* generics) {
    #line 610 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 611 "src/compiler/DefinitionWriter.pv"
    struct GenericMap void_self_generics = *generics;
    #line 612 "src/compiler/DefinitionWriter.pv"
    void_self_generics.self_type = &g->root->type_void;

    #line 614 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 615 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;

    #line 617 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "\n");
    #line 618 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(g, file, &trait_info->module->context, trait_info->name);

    #line 620 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*sVTable {\n", name_length, name.array.data);
    #line 621 "src/compiler/DefinitionWriter.pv"
    g->indent += 1;

    #line 623 "src/compiler/DefinitionWriter.pv"
    { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
    #line 623 "src/compiler/DefinitionWriter.pv"
    while (HashMapIter_str_Function__next(&__iter)) {
        #line 623 "src/compiler/DefinitionWriter.pv"
        struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

        #line 624 "src/compiler/DefinitionWriter.pv"
        if (func_info->generics.array.length == 0) {
            #line 625 "src/compiler/DefinitionWriter.pv"
            struct String func_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = g->allocator });
            #line 626 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = "(*", .length = strlen("(*") });
            #line 627 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, func_info->name->value);
            #line 628 "src/compiler/DefinitionWriter.pv"
            String__append(&func_name, (struct str){ .ptr = ")", .length = strlen(")") });

            #line 630 "src/compiler/DefinitionWriter.pv"
            Generator__write_indent(g, file);
            #line 631 "src/compiler/DefinitionWriter.pv"
            if (!DefinitionWriter__write_function_definition(self, file, func_info, &void_self_generics, &func_name)) {
                #line 631 "src/compiler/DefinitionWriter.pv"
                return false;
            }
            #line 632 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        }
    } }

    #line 636 "src/compiler/DefinitionWriter.pv"
    g->indent -= 1;
    #line 637 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n\n");

    #line 639 "src/compiler/DefinitionWriter.pv"
    Generator__write_line_directive(g, file, &trait_info->module->context, trait_info->name);

    #line 641 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "struct %.*s {\n", name_length, name.array.data);
    #line 642 "src/compiler/DefinitionWriter.pv"
    g->indent += 1;

    #line 644 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(g, file);
    #line 645 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "const struct %.*sVTable* vtable;\n", name_length, name.array.data);
    #line 646 "src/compiler/DefinitionWriter.pv"
    Generator__write_indent(g, file);
    #line 647 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "void* instance;\n");

    #line 649 "src/compiler/DefinitionWriter.pv"
    g->indent -= 1;
    #line 650 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "};\n");

    #line 652 "src/compiler/DefinitionWriter.pv"
    return true;
}

#line 655 "src/compiler/DefinitionWriter.pv"
bool DefinitionWriter__write_impls(struct DefinitionWriter* self, FILE* file, struct Module* module, struct Array_ref_Impl* impls, struct Array_HashMap_usize_TypeFunctionUsage* impl_functions, struct GenericMap* generics, struct IncludeWriter* include_writer) {
    #line 656 "src/compiler/DefinitionWriter.pv"
    struct Generator* g = self->generator;
    #line 657 "src/compiler/DefinitionWriter.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, Type__deref(generics->self_type), generics->self_type, generics);
    #line 658 "src/compiler/DefinitionWriter.pv"
    int32_t name_length = name.array.length;
    #line 659 "src/compiler/DefinitionWriter.pv"
    struct String path = Generator__make_rel_path(g, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });

    #line 661 "src/compiler/DefinitionWriter.pv"
    fprintf(file, "#include <%.*s>\n", (int32_t)(path.array.length), path.array.data);

    #line 663 "src/compiler/DefinitionWriter.pv"
    { struct IterEnumerate_ref_ref_Impl __iter = Iter_ref_ref_Impl__enumerate(Array_ref_Impl__iter(impls));
    #line 663 "src/compiler/DefinitionWriter.pv"
    while (IterEnumerate_ref_ref_Impl__next(&__iter)) {
        #line 663 "src/compiler/DefinitionWriter.pv"
        uintptr_t impl_index = IterEnumerate_ref_ref_Impl__value(&__iter)._0;
        #line 663 "src/compiler/DefinitionWriter.pv"
        struct Impl* impl_info = *IterEnumerate_ref_ref_Impl__value(&__iter)._1;

        #line 664 "src/compiler/DefinitionWriter.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 665 "src/compiler/DefinitionWriter.pv"
        struct HashMap_usize_TypeFunctionUsage* impl_functions_for_impl = 0;
        #line 666 "src/compiler/DefinitionWriter.pv"
        if (impl_functions != 0) {
            #line 666 "src/compiler/DefinitionWriter.pv"
            impl_functions_for_impl = Array_HashMap_usize_TypeFunctionUsage__get(impl_functions, impl_index);
        }

        #line 668 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&impl_info->functions);
        #line 668 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 668 "src/compiler/DefinitionWriter.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 669 "src/compiler/DefinitionWriter.pv"
            uintptr_t func_ptr = (uintptr_t)(func_info);
            #line 670 "src/compiler/DefinitionWriter.pv"
            struct TypeFunctionUsage* function_usage = 0;
            #line 671 "src/compiler/DefinitionWriter.pv"
            if (impl_functions_for_impl != 0) {
                #line 671 "src/compiler/DefinitionWriter.pv"
                function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
            }

            #line 673 "src/compiler/DefinitionWriter.pv"
            if (func_info->generics.array.length == 0) {
                #line 674 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 675 "src/compiler/DefinitionWriter.pv"
                if (trait_info != 0) {
                    #line 676 "src/compiler/DefinitionWriter.pv"
                    struct GenericMap generics_void = *generics;
                    #line 677 "src/compiler/DefinitionWriter.pv"
                    generics_void.self_type = &g->root->type_void;

                    #line 679 "src/compiler/DefinitionWriter.pv"
                    struct String func_name = Generator__get_trait_function_name(g, String__as_str(&name), trait_info, func_info, generics);
                    #line 680 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                        #line 681 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 682 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 683 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 686 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, " {\n");
                    #line 687 "src/compiler/DefinitionWriter.pv"
                    g->indent += 1;

                    #line 689 "src/compiler/DefinitionWriter.pv"
                    Generator__write_indent(g, file);
                    #line 690 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(g, file, generics->self_type, generics);
                    #line 691 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "* self = ");

                    #line 693 "src/compiler/DefinitionWriter.pv"
                    if (module != 0 && module->mode_cpp) {
                        #line 694 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "(");
                        #line 695 "src/compiler/DefinitionWriter.pv"
                        Generator__write_type(g, file, generics->self_type, generics);
                        #line 696 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "*)");
                    }

                    #line 699 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "__self");
                    #line 700 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "; (void)self;\n");

                    #line 702 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(g->allocator, func_info, true);
                    #line 703 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0) {
                        #line 703 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 704 "src/compiler/DefinitionWriter.pv"
                    g->function_context = &func_context;

                    #line 706 "src/compiler/DefinitionWriter.pv"
                    if (!BlockWriter__write_block(&(struct BlockWriter) { .generator = g }, file, &func_info->return_type, func_info->body, generics, false, true)) {
                        #line 707 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 708 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 709 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 712 "src/compiler/DefinitionWriter.pv"
                    g->indent -= 1;
                    #line 713 "src/compiler/DefinitionWriter.pv"
                    Generator__write_indent(g, file);
                    #line 714 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "}\n");

                    #line 716 "src/compiler/DefinitionWriter.pv"
                    g->function_context = 0;
                } else {
                    #line 718 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_definition(self, file, func_info, generics, 0)) {
                        #line 719 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 720 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 721 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 724 "src/compiler/DefinitionWriter.pv"
                    struct FunctionContext func_context = FunctionContext__new(g->allocator, func_info, true);
                    #line 725 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0) {
                        #line 725 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                    }
                    #line 726 "src/compiler/DefinitionWriter.pv"
                    g->function_context = &func_context;

                    #line 728 "src/compiler/DefinitionWriter.pv"
                    if (!DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics, function_usage)) {
                        #line 729 "src/compiler/DefinitionWriter.pv"
                        uint32_t func_name_length = func_info->name->value.length;
                        #line 730 "src/compiler/DefinitionWriter.pv"
                        fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                        #line 731 "src/compiler/DefinitionWriter.pv"
                        return false;
                    }

                    #line 734 "src/compiler/DefinitionWriter.pv"
                    struct TypeFunctionUsage* function_usage = 0;
                    #line 735 "src/compiler/DefinitionWriter.pv"
                    if (impl_functions_for_impl != 0) {
                        #line 735 "src/compiler/DefinitionWriter.pv"
                        function_usage = HashMap_usize_TypeFunctionUsage__find(impl_functions_for_impl, &func_ptr);
                    }

                    #line 737 "src/compiler/DefinitionWriter.pv"
                    if (function_usage != 0 && function_usage->impl_dynamic_function) {
                        #line 738 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 739 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 740 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "#include <std/trait_Allocator.h>\n");
                        }

                        #line 743 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "#include <std/Array_TypeId.h>\n");
                        #line 744 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "struct Array_TypeId* ");
                        #line 745 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(g, file, func_info, generics);

                        #line 747 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 748 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__get_params(void* __self) {\n");
                        } else {
                            #line 750 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__get_params(void* __self) {\n");
                        }

                        #line 753 "src/compiler/DefinitionWriter.pv"
                        g->indent += 1;
                        #line 754 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(g, file);
                        #line 755 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "static TypeId type_ids[] = { ");

                        #line 757 "src/compiler/DefinitionWriter.pv"
                        bool first = true;
                        #line 758 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 758 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_Parameter__next(&__iter)) {
                            #line 758 "src/compiler/DefinitionWriter.pv"
                            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                            #line 759 "src/compiler/DefinitionWriter.pv"
                            if (first) {
                                #line 759 "src/compiler/DefinitionWriter.pv"
                                first = false;
                            } else {
                                #line 759 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, ", ");
                            }
                            #line 760 "src/compiler/DefinitionWriter.pv"
                            Generator__write_typeid(g, file, &param->type, generics);
                        } }

                        #line 763 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, " };\n");
                        #line 764 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(g, file);
                        #line 765 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "static struct Array_TypeId result = { .data = type_ids, .length = %zu };\n", func_info->parameters.length);
                        #line 766 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(g, file);
                        #line 767 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "return &result;\n");
                        #line 768 "src/compiler/DefinitionWriter.pv"
                        g->indent -= 1;
                        #line 769 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "}\n");

                        #line 771 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "bool ");
                        #line 772 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(g, file, func_info, generics);

                        #line 774 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 775 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        } else {
                            #line 777 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__set_arg(void* __self, uintptr_t index, void* value) {\n");
                        }

                        #line 780 "src/compiler/DefinitionWriter.pv"
                        g->indent += 1;

                        #line 782 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(g, file);
                        #line 783 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "struct ");
                        #line 784 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(g, file, func_info, generics);

                        #line 786 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 787 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");
                        } else {
                            #line 789 "src/compiler/DefinitionWriter.pv"
                            if (module->mode_cpp) {
                                #line 790 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = (struct ");
                                #line 791 "src/compiler/DefinitionWriter.pv"
                                Generator__write_function_name(g, file, func_info, generics);
                                #line 792 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance*)__self;\n");
                            } else {
                                #line 794 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = __self;\n");
                            }
                        }

                        #line 798 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(g, file);
                        #line 799 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "switch (index) {\n");
                        #line 800 "src/compiler/DefinitionWriter.pv"
                        g->indent += 1;

                        #line 802 "src/compiler/DefinitionWriter.pv"
                        uintptr_t i = 0;
                        #line 803 "src/compiler/DefinitionWriter.pv"
                        { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                        #line 803 "src/compiler/DefinitionWriter.pv"
                        while (Iter_ref_Parameter__next(&__iter)) {
                            #line 803 "src/compiler/DefinitionWriter.pv"
                            struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                            #line 804 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(g, file);
                            #line 805 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "case %zu: self->", i);
                            #line 806 "src/compiler/DefinitionWriter.pv"
                            Generator__write_token(g, file, param->name);
                            #line 807 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, " = ");

                            #line 809 "src/compiler/DefinitionWriter.pv"
                            if (!Generator__is_reference(&param->type)) {
                                #line 810 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "*(");
                                #line 811 "src/compiler/DefinitionWriter.pv"
                                Generator__write_type(g, file, &param->type, generics);
                                #line 812 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "*)");
                            } else {
                                #line 814 "src/compiler/DefinitionWriter.pv"
                                if (module->mode_cpp) {
                                    #line 815 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, "(");
                                    #line 816 "src/compiler/DefinitionWriter.pv"
                                    Generator__write_type(g, file, &param->type, generics);
                                    #line 817 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, ")");
                                }
                            }

                            #line 821 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "value; return true;\n");
                            #line 822 "src/compiler/DefinitionWriter.pv"
                            i += 1;
                        } }

                        #line 825 "src/compiler/DefinitionWriter.pv"
                        g->indent -= 1;
                        #line 826 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(g, file);
                        #line 827 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "}\n");

                        #line 829 "src/compiler/DefinitionWriter.pv"
                        Generator__write_indent(g, file);
                        #line 830 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "return false;\n");

                        #line 832 "src/compiler/DefinitionWriter.pv"
                        g->indent -= 1;
                        #line 833 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "}\n");

                        #line 835 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 836 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct Iter_CoroutineStatus ");
                            #line 837 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 838 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__init(void* __self, struct Allocator allocator) {\n");

                            #line 840 "src/compiler/DefinitionWriter.pv"
                            g->indent += 1;

                            #line 842 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(g, file);
                            #line 843 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 844 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 845 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co_CoroutineStatus__Instance* self = __self;\n");

                            #line 847 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(g, file);
                            #line 848 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 849 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 850 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "* instance = allocator.vtable->alloc(allocator.instance, sizeof(struct ");
                            #line 851 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 852 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "));\n");

                            #line 854 "src/compiler/DefinitionWriter.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 854 "src/compiler/DefinitionWriter.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 854 "src/compiler/DefinitionWriter.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 855 "src/compiler/DefinitionWriter.pv"
                                Generator__write_indent(g, file);
                                #line 856 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "instance->");
                                #line 857 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(g, file, param->name);
                                #line 858 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, " = ");
                                #line 859 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "self->");
                                #line 860 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(g, file, param->name);
                                #line 861 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, ";\n");
                            } }

                            #line 864 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(g, file);
                            #line 865 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "return (struct trait_Iter_CoroutineStatus) { .vtable = &");

                            #line 867 "src/compiler/DefinitionWriter.pv"
                            switch (func_info->parent.type) {
                                #line 868 "src/compiler/DefinitionWriter.pv"
                                case FUNCTION_PARENT__STRUCT: {
                                    #line 868 "src/compiler/DefinitionWriter.pv"
                                    struct Struct* struct_info = func_info->parent.struct_value._0;
                                    #line 869 "src/compiler/DefinitionWriter.pv"
                                    Generator__write_str_title(g, file, struct_info->name->value);
                                    #line 870 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, "__");
                                } break;
                                #line 872 "src/compiler/DefinitionWriter.pv"
                                default: {
                                } break;
                            }
                            #line 874 "src/compiler/DefinitionWriter.pv"
                            Generator__write_str_title(g, file, func_info->name->value);

                            #line 876 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__ITER, .instance = instance };\n");

                            #line 878 "src/compiler/DefinitionWriter.pv"
                            g->indent -= 1;
                            #line 879 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "}\n");
                        } else {
                            #line 881 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "void ");
                            #line 882 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 883 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__execute(void* __self) {\n");

                            #line 885 "src/compiler/DefinitionWriter.pv"
                            g->indent += 1;

                            #line 887 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(g, file);
                            #line 888 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct ");
                            #line 889 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 890 "src/compiler/DefinitionWriter.pv"
                            if (module->mode_cpp) {
                                #line 891 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = (struct ");
                                #line 892 "src/compiler/DefinitionWriter.pv"
                                Generator__write_function_name(g, file, func_info, generics);
                                #line 893 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance*)__self;\n");
                            } else {
                                #line 895 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__Fn__Instance* self = __self;\n");
                            }

                            #line 898 "src/compiler/DefinitionWriter.pv"
                            Generator__write_indent(g, file);
                            #line 899 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 900 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "(");

                            #line 902 "src/compiler/DefinitionWriter.pv"
                            first = true;
                            #line 903 "src/compiler/DefinitionWriter.pv"
                            { struct Iter_ref_Parameter __iter = Array_Parameter__iter(&func_info->parameters);
                            #line 903 "src/compiler/DefinitionWriter.pv"
                            while (Iter_ref_Parameter__next(&__iter)) {
                                #line 903 "src/compiler/DefinitionWriter.pv"
                                struct Parameter* param = Iter_ref_Parameter__value(&__iter);

                                #line 904 "src/compiler/DefinitionWriter.pv"
                                if (first) {
                                    #line 904 "src/compiler/DefinitionWriter.pv"
                                    first = false;
                                } else {
                                    #line 904 "src/compiler/DefinitionWriter.pv"
                                    fprintf(file, ", ");
                                }
                                #line 905 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "self->");
                                #line 906 "src/compiler/DefinitionWriter.pv"
                                Generator__write_token(g, file, param->name);
                            } }

                            #line 909 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, ");\n");

                            #line 911 "src/compiler/DefinitionWriter.pv"
                            g->indent -= 1;
                            #line 912 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "}\n");
                        }

                        #line 915 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 916 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct trait_Co_CoroutineStatusVTable ");
                        } else {
                            #line 918 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "struct trait_FnVTable ");
                        }

                        #line 921 "src/compiler/DefinitionWriter.pv"
                        switch (func_info->parent.type) {
                            #line 922 "src/compiler/DefinitionWriter.pv"
                            case FUNCTION_PARENT__STRUCT: {
                                #line 922 "src/compiler/DefinitionWriter.pv"
                                struct Struct* struct_info = func_info->parent.struct_value._0;
                                #line 923 "src/compiler/DefinitionWriter.pv"
                                Generator__write_str_title(g, file, struct_info->name->value);
                                #line 924 "src/compiler/DefinitionWriter.pv"
                                fprintf(file, "__");
                            } break;
                            #line 926 "src/compiler/DefinitionWriter.pv"
                            default: {
                            } break;
                        }
                        #line 928 "src/compiler/DefinitionWriter.pv"
                        Generator__write_str_title(g, file, func_info->name->value);

                        #line 930 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 931 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__CO");
                        } else {
                            #line 933 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__VTABLE__DYN_FN");
                        }

                        #line 936 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, " = { .get_params = &");
                        #line 937 "src/compiler/DefinitionWriter.pv"
                        Generator__write_function_name(g, file, func_info, generics);

                        #line 939 "src/compiler/DefinitionWriter.pv"
                        if (Generator__is_coroutine(g)) {
                            #line 940 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__get_params, .set_arg = &");
                            #line 941 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 942 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__set_arg, .init = &");
                            #line 943 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 944 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Co__init };\n");
                        } else {
                            #line 946 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__get_params, .set_arg = &");
                            #line 947 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 948 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__set_arg, .execute = &");
                            #line 949 "src/compiler/DefinitionWriter.pv"
                            Generator__write_function_name(g, file, func_info, generics);
                            #line 950 "src/compiler/DefinitionWriter.pv"
                            fprintf(file, "__Fn__execute };\n");
                        }
                    }

                    #line 954 "src/compiler/DefinitionWriter.pv"
                    g->function_context = 0;
                }
            } else if (impl_functions_for_impl != 0) {
                #line 957 "src/compiler/DefinitionWriter.pv"
                if (function_usage != 0) {
                    #line 958 "src/compiler/DefinitionWriter.pv"
                    struct Function* func2 = ArenaAllocator__Allocator__alloc(g->allocator, sizeof(struct Function));
                    #line 959 "src/compiler/DefinitionWriter.pv"
                    *func2 = *func_info;

                    #line 961 "src/compiler/DefinitionWriter.pv"
                    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&function_usage->usage_contexts);
                    #line 961 "src/compiler/DefinitionWriter.pv"
                    while (Iter_ref_UsageContext__next(&__iter)) {
                        #line 961 "src/compiler/DefinitionWriter.pv"
                        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

                        #line 962 "src/compiler/DefinitionWriter.pv"
                        struct GenericMap* generics3 = usage_context->generic_map;
                        #line 965 "src/compiler/DefinitionWriter.pv"
                        generics3->self_type = generics->self_type;

                        #line 967 "src/compiler/DefinitionWriter.pv"
                        IncludeWriter__write(include_writer, file, g, &usage_context->body, generics3, true);
                        #line 968 "src/compiler/DefinitionWriter.pv"
                        fprintf(file, "\n");
                        #line 969 "src/compiler/DefinitionWriter.pv"
                        if (!DefinitionWriter__write_function_definition(self, file, func_info, generics3, 0)) {
                            #line 970 "src/compiler/DefinitionWriter.pv"
                            uint32_t func_name_length = func_info->name->value.length;
                            #line 971 "src/compiler/DefinitionWriter.pv"
                            fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                            #line 972 "src/compiler/DefinitionWriter.pv"
                            return false;
                        }

                        #line 975 "src/compiler/DefinitionWriter.pv"
                        struct FunctionContext func_context = FunctionContext__new(g->allocator, func_info, true);
                        #line 976 "src/compiler/DefinitionWriter.pv"
                        func_context.coroutine.yield_count = function_usage->function_context.coroutine.yield_count;
                        #line 977 "src/compiler/DefinitionWriter.pv"
                        g->function_context = &func_context;

                        #line 979 "src/compiler/DefinitionWriter.pv"
                        DefinitionWriter__write_function_block(self, file, String__as_str(&name), func_info, generics3, function_usage);

                        #line 981 "src/compiler/DefinitionWriter.pv"
                        g->function_context = 0;
                    } }
                }
            }
        } }

        #line 987 "src/compiler/DefinitionWriter.pv"
        if (trait_info != 0) {
            #line 988 "src/compiler/DefinitionWriter.pv"
            { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
            #line 988 "src/compiler/DefinitionWriter.pv"
            while (HashMapIter_str_Function__next(&__iter)) {
                #line 988 "src/compiler/DefinitionWriter.pv"
                struct str func_base_name = HashMapIter_str_Function__value(&__iter)->_0;
                #line 988 "src/compiler/DefinitionWriter.pv"
                struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

                #line 989 "src/compiler/DefinitionWriter.pv"
                if (HashMap_str_Function__find(&impl_info->functions, &func_base_name) != 0) {
                    #line 989 "src/compiler/DefinitionWriter.pv"
                    continue;
                }

                #line 991 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "\n");
                #line 992 "src/compiler/DefinitionWriter.pv"
                struct GenericMap generics_void = *generics;
                #line 993 "src/compiler/DefinitionWriter.pv"
                generics_void.self_type = &g->root->type_void;

                #line 995 "src/compiler/DefinitionWriter.pv"
                struct String func_name = Generator__get_trait_function_name(g, String__as_str(&name), trait_info, func_info, generics);
                #line 996 "src/compiler/DefinitionWriter.pv"
                if (!DefinitionWriter__write_function_definition(self, file, func_info, &generics_void, &func_name)) {
                    #line 997 "src/compiler/DefinitionWriter.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 998 "src/compiler/DefinitionWriter.pv"
                    fprintf(stderr, "Failed to write definition for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 999 "src/compiler/DefinitionWriter.pv"
                    return false;
                }

                #line 1002 "src/compiler/DefinitionWriter.pv"
                fprintf(file, " {\n");
                #line 1003 "src/compiler/DefinitionWriter.pv"
                g->indent += 1;

                #line 1005 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(g, file);
                #line 1006 "src/compiler/DefinitionWriter.pv"
                Generator__write_type(g, file, generics->self_type, generics);

                #line 1008 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "* self = ");

                #line 1010 "src/compiler/DefinitionWriter.pv"
                if (module != 0 && module->mode_cpp) {
                    #line 1011 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "(");
                    #line 1012 "src/compiler/DefinitionWriter.pv"
                    Generator__write_type(g, file, generics->self_type, generics);
                    #line 1013 "src/compiler/DefinitionWriter.pv"
                    fprintf(file, "*)");
                }

                #line 1016 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "__self; (void)self;\n");

                #line 1018 "src/compiler/DefinitionWriter.pv"
                struct FunctionContext func_context = FunctionContext__new(g->allocator, func_info, true);
                #line 1019 "src/compiler/DefinitionWriter.pv"
                g->function_context = &func_context;

                #line 1021 "src/compiler/DefinitionWriter.pv"
                if (!BlockWriter__write_block(&(struct BlockWriter) { .generator = g }, file, &func_info->return_type, func_info->body, generics, false, true)) {
                    #line 1022 "src/compiler/DefinitionWriter.pv"
                    uint32_t func_name_length = func_info->name->value.length;
                    #line 1023 "src/compiler/DefinitionWriter.pv"
                    fprintf(stderr, "Failed to write block for %.*s::%.*s\n ", name_length, name.array.data, func_name_length, func_info->name->value.ptr);
                    #line 1024 "src/compiler/DefinitionWriter.pv"
                    return false;
                }

                #line 1027 "src/compiler/DefinitionWriter.pv"
                g->indent -= 1;
                #line 1028 "src/compiler/DefinitionWriter.pv"
                Generator__write_indent(g, file);
                #line 1029 "src/compiler/DefinitionWriter.pv"
                fprintf(file, "}\n");

                #line 1031 "src/compiler/DefinitionWriter.pv"
                g->function_context = 0;
            } }
        }

        #line 1035 "src/compiler/DefinitionWriter.pv"
        { struct HashMapIter_str_ref_ImplConst __iter = HashMap_str_ref_ImplConst__iter(&impl_info->consts);
        #line 1035 "src/compiler/DefinitionWriter.pv"
        while (HashMapIter_str_ref_ImplConst__next(&__iter)) {
            #line 1035 "src/compiler/DefinitionWriter.pv"
            struct ImplConst* impl_const = HashMapIter_str_ref_ImplConst__value(&__iter)->_1;

            #line 1036 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "\nconst ");
            #line 1037 "src/compiler/DefinitionWriter.pv"
            Generator__write_type(g, file, &impl_const->type, generics);
            #line 1038 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " ");
            #line 1039 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, String__as_str(&name));
            #line 1040 "src/compiler/DefinitionWriter.pv"
            fprintf(file, "_");
            #line 1041 "src/compiler/DefinitionWriter.pv"
            Generator__write_str_title(g, file, impl_const->name->value);
            #line 1042 "src/compiler/DefinitionWriter.pv"
            fprintf(file, " = ");
            #line 1043 "src/compiler/DefinitionWriter.pv"
            ExpressionWriter__write_expression(&(struct ExpressionWriter) { .generator = g }, file, impl_const->value, generics);
            #line 1044 "src/compiler/DefinitionWriter.pv"
            fprintf(file, ";\n");
        } }
    } }

    #line 1048 "src/compiler/DefinitionWriter.pv"
    return true;
}
