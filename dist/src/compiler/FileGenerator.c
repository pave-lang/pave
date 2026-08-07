#include <string.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <stdio.h>
#include <fs.h>
#include <compiler/Generator.h>
#include <std/Array_UsageContext.h>
#include <compiler/TypeFunctionUsage.h>
#include <std/Iter_ref_UsageContext.h>
#include <compiler/UsageContext.h>
#include <compiler/DefinitionWriter.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/GenericMap.h>
#include <compiler/IncludeWriter.h>
#include <std/ArenaAllocator.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/types/Type.h>
#include <std/str.h>
#include <compiler/FunctionContext.h>
#include <analyzer/Context.h>
#include <analyzer/Module.h>
#include <std/HashSet_str.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMap_str_Type.h>
#include <std/Array_String.h>
#include <compiler/TypeUsage_Enum.h>
#include <analyzer/types/Enum.h>
#include <usize.h>
#include <std/Array_ref_Impl.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <std/Array_Type.h>
#include <analyzer/types/EnumVariant.h>
#include <std/Iter_ref_Type.h>
#include <std/Array_str.h>
#include <analyzer/Token.h>
#include <compiler/TypeUsage_Struct.h>
#include <analyzer/types/Struct.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/Root.h>
#include <std/HashMap_str_tuple_ref_Trait_ref_Type.h>
#include <std/HashMapIter_str_tuple_ref_Trait_ref_Type.h>
#include <tuple_str_tuple_ref_Trait_ref_Type.h>
#include <analyzer/types/Trait.h>
#include <tuple_ref_Trait_ref_Type.h>
#include <std/HashMap_str_Function.h>
#include <std/HashMapIter_str_Function.h>
#include <tuple_str_Function.h>
#include <analyzer/Namespace.h>
#include <std/HashMap_str_StructField.h>
#include <std/HashMapIter_str_StructField.h>
#include <tuple_str_StructField.h>
#include <analyzer/types/StructField.h>
#include <compiler/TypeUsage_Primitive.h>
#include <analyzer/types/Primitive.h>
#include <std/Iter_ref_ref_Impl.h>
#include <analyzer/Impl.h>
#include <compiler/TypeUsage_Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/types/TypeImpl.h>
#include <std/trait_Allocator.h>
#include <compiler/TypeUsage_Tuple.h>
#include <analyzer/types/Tuple.h>
#include <std/IterEnumerate_ref_Type.h>
#include <tuple_usize_ref_Type.h>
#include <compiler/TypeUsage_Trait.h>
#include <compiler/TypeUsage_TypeImpl.h>
#include <analyzer/types/Global.h>
#include <std/HashMap_str_usize.h>
#include <std/HashSetIter_str.h>
#include <analyzer/expression/Expression.h>
#include <compiler/ExpressionWriter.h>
#include <std/HashMap_str_ref_Namespace.h>
#include <std/HashMapIter_str_ref_Namespace.h>
#include <tuple_str_ref_Namespace.h>
#include <std/HashMap_str_ref_Module.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMap_str_ref_Global.h>
#include <std/HashMapIter_str_ref_Global.h>
#include <tuple_str_ref_Global.h>
#include <std/Array_TestInfo.h>
#include <std/Iter_ref_TestInfo.h>
#include <analyzer/TestInfo.h>
#include <compiler/FileGenerator.h>

#include <compiler/FileGenerator.h>

#line 16 "src/compiler/FileGenerator.pv"
struct FileGenerator FileGenerator__new(struct Generator* generator) {
    #line 17 "src/compiler/FileGenerator.pv"
    return (struct FileGenerator) { .generator = generator };
}

#line 20 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_function_loop(struct FileGenerator* self, struct TypeFunctionUsage* usage) {
    #line 21 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 22 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 22 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 22 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 23 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_function(self, usage, usage_context) && success;
    } }
    #line 25 "src/compiler/FileGenerator.pv"
    return success;
}

#line 28 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_function(struct FileGenerator* self, struct TypeFunctionUsage* usage, struct UsageContext* usage_context) {
    #line 29 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 30 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 31 "src/compiler/FileGenerator.pv"
    struct Function* func_info = usage->type;
    #line 32 "src/compiler/FileGenerator.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 32 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 34 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 35 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 37 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 38 "src/compiler/FileGenerator.pv"
    struct str name_str = String__as_str(&name);
    #line 39 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 40 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_context;

    #line 42 "src/compiler/FileGenerator.pv"
    struct str code_ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    #line 43 "src/compiler/FileGenerator.pv"
    struct str header_ext = (struct str){ .ptr = ".h", .length = strlen(".h") };
    #line 44 "src/compiler/FileGenerator.pv"
    if (func_info->type == FUNCTION_TYPE__TEST) {
        #line 45 "src/compiler/FileGenerator.pv"
        code_ext = (struct str){ .ptr = ".test.c", .length = strlen(".test.c") };
        #line 46 "src/compiler/FileGenerator.pv"
        header_ext = (struct str){ .ptr = ".test.h", .length = strlen(".test.h") };
    }

    #line 49 "src/compiler/FileGenerator.pv"
    struct Context* context = func_info->context;
    #line 50 "src/compiler/FileGenerator.pv"
    if (context == 0) {
        #line 51 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing function context in generate_function\n");
        #line 52 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 55 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, context->module, name_str, code_ext);
    #line 56 "src/compiler/FileGenerator.pv"
    FILE* code_file = 0;
    #line 57 "src/compiler/FileGenerator.pv"
    char const* code_tmp = 0;

    #line 59 "src/compiler/FileGenerator.pv"
    code_tmp = tmpnam(0);
    #line 60 "src/compiler/FileGenerator.pv"
    code_file = fopen(code_tmp, "w+");

    #line 62 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 62 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 62 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 64 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 65 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &context->module->includes);
    #line 66 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 68 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, context->module, name_str, header_ext);
    #line 69 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 70 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 71 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 73 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, code_file, func_info, generics, 0)) {
        #line 74 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write function definition for %s\n", String__c_str(&name));
        #line 75 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 76 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 79 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_function_block(&defs, code_file, name_str, func_info, generics, usage_context);

    #line 81 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 82 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 83 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 85 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 87 "src/compiler/FileGenerator.pv"
    include_writer = IncludeWriter__new(generator->allocator);

    #line 89 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, context->module, name_str, header_ext);
    #line 90 "src/compiler/FileGenerator.pv"
    FILE* header_file = 0;
    #line 91 "src/compiler/FileGenerator.pv"
    char const* header_tmp = 0;
    #line 92 "src/compiler/FileGenerator.pv"
    header_tmp = tmpnam(0);
    #line 93 "src/compiler/FileGenerator.pv"
    header_file = fopen(header_tmp, "w+");

    #line 95 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 95 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 95 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 97 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 98 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 99 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 100 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 101 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 103 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_code, 0);
    #line 104 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 106 "src/compiler/FileGenerator.pv"
    if (Generator__is_coroutine(generator)) {
        #line 107 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_function_coroutine(&defs, header_file, func_info, generics);
    }

    #line 110 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, header_file, func_info, generics, 0)) {
        #line 111 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write function definition for %s\n", String__c_str(&name));
        #line 112 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 113 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 116 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 118 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 120 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 121 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 122 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 124 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 126 "src/compiler/FileGenerator.pv"
    return true;
}

#line 129 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum_loop(struct FileGenerator* self, struct TypeUsage_Enum* usage) {
    #line 130 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 131 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 131 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 131 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 132 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_enum(self, usage, usage_context) && success;
    } }
    #line 134 "src/compiler/FileGenerator.pv"
    return success;
}

#line 137 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum(struct FileGenerator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context) {
    #line 138 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 139 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 140 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 141 "src/compiler/FileGenerator.pv"
    struct Enum* enum_info = usage->type;
    #line 142 "src/compiler/FileGenerator.pv"
    struct Module* module = enum_info->context->module;
    #line 143 "src/compiler/FileGenerator.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);
    #line 144 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 146 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 147 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 148 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 149 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 150 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 150 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 150 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 152 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 153 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 154 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 155 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 156 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 158 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 159 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 161 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_enum_definition(&defs, header_file, enum_info, usage, usage_context, &include_writer)) {
        #line 162 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write enum definition for %s\n", String__c_str(&name));
        #line 163 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 164 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 167 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 167 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 169 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 171 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 172 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 173 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 175 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(enum_info->impls.length, 0) && !usage->any_usage && !usage->impl_dynamic_usage) {
        #line 175 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 177 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 179 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 180 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 181 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 181 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 181 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 183 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 184 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 185 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 187 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 188 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 189 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 190 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 192 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 193 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for enum %s\n", String__c_str(&name));
        #line 194 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 195 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 198 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 199 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 200 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 203 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 204 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 206 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantInfo.h>\n");
        #line 207 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_EnumVariantInfo.h>\n");
        #line 208 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantParamInfo.h>\n");
        #line 209 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_EnumVariantParamInfo.h>\n");
        #line 210 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantKind.h>\n");
        #line 211 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_EnumVariantInfo ");
        #line 212 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 213 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants(void* __self) {\n");

        #line 215 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 216 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 217 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(void)__self;\n");

        #line 219 "src/compiler/FileGenerator.pv"
        uintptr_t variant_index = 0;
        #line 220 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 220 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 220 "src/compiler/FileGenerator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 221 "src/compiler/FileGenerator.pv"
            if (variant->types.length > 0) {
                #line 222 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 223 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "static struct EnumVariantParamInfo __params_%zu[] = { ", variant_index);

                #line 225 "src/compiler/FileGenerator.pv"
                uintptr_t param_index = 0;
                #line 226 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 226 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 226 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 227 "src/compiler/FileGenerator.pv"
                    if (param_index > 0) {
                        #line 227 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ", ");
                    }
                    #line 228 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(struct EnumVariantParamInfo){ .index = %zu, .name = ", param_index);

                    #line 230 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 231 "src/compiler/FileGenerator.pv"
                        struct str field_name = variant->names.data[param_index];
                        #line 232 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(struct str){ .ptr = \"");
                        #line 233 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, field_name);
                        #line 234 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "\", .length = %zu }", field_name.length);
                    } else {
                        #line 236 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(struct str){ .ptr = \"\", .length = 0 }");
                    }

                    #line 239 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ", .type_id = ");
                    #line 240 "src/compiler/FileGenerator.pv"
                    Generator__write_typeid(generator, code_file, type, generics);
                    #line 241 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ", .type_name = ");
                    #line 242 "src/compiler/FileGenerator.pv"
                    Generator__write_typename(generator, code_file, type, generics);
                    #line 243 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, " }");

                    #line 245 "src/compiler/FileGenerator.pv"
                    param_index += 1;
                } }

                #line 248 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " };\n");
            }
            #line 250 "src/compiler/FileGenerator.pv"
            variant_index += 1;
        } }

        #line 253 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 254 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct EnumVariantInfo variants[] = { ");

        #line 256 "src/compiler/FileGenerator.pv"
        variant_index = 0;
        #line 257 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 257 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 257 "src/compiler/FileGenerator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 258 "src/compiler/FileGenerator.pv"
            if (variant_index > 0) {
                #line 258 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 259 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct EnumVariantInfo){ .index = %zu, .key = (struct str){ .ptr = \"", variant_index);
            #line 260 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, variant->name);
            #line 261 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .label = (struct str){ .ptr = ", variant->name->value.length);
            #line 262 "src/compiler/FileGenerator.pv"
            if (variant->label != 0) {
                #line 263 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->label);
                #line 264 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .length = sizeof(");
                #line 265 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->label);
                #line 266 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ") - 1 }");
            } else {
                #line 268 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "\"");
                #line 269 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->name);
                #line 270 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "\", .length = %zu }", variant->name->value.length);
            }

            #line 273 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .kind = ");
            #line 274 "src/compiler/FileGenerator.pv"
            if (variant->names.length > 0) {
                #line 275 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__STRUCT");
            } else if (variant->types.length > 0) {
                #line 277 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__TUPLE");
            } else {
                #line 279 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__UNIT");
            }

            #line 282 "src/compiler/FileGenerator.pv"
            if (variant->types.length > 0) {
                #line 283 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .params = (struct slice_EnumVariantParamInfo){ .data = __params_%zu, .length = %zu }", variant_index, variant->types.length);
            } else {
                #line 285 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .params = (struct slice_EnumVariantParamInfo){ .data = 0, .length = 0 }");
            }

            #line 288 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 289 "src/compiler/FileGenerator.pv"
            variant_index += 1;
        } }

        #line 292 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 293 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 294 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_EnumVariantInfo){ .data = variants, .length = %zu };\n", enum_info->variants.length);
        #line 295 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 296 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 298 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "uintptr_t ");
        #line 299 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 300 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index(void* __self) {\n");

        #line 302 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 303 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 304 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 306 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 307 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 308 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 309 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 311 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 314 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 315 "src/compiler/FileGenerator.pv"
        if (is_discriminated_union) {
            #line 316 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)self->type;\n");
        } else {
            #line 318 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)*self;\n");
        }

        #line 321 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 322 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 324 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void ");
        #line 325 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 326 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_variant(void* __self, uintptr_t index) {\n");

        #line 328 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 329 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 330 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 332 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 333 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 334 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 335 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 337 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 340 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 341 "src/compiler/FileGenerator.pv"
        if (is_discriminated_union) {
            #line 342 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "self->type = index;\n");
        } else {
            #line 344 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*self = index;\n");
        }

        #line 347 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 348 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 350 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 351 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 352 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_param(void* __self, uintptr_t index) {\n");

        #line 354 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 356 "src/compiler/FileGenerator.pv"
        if (!is_discriminated_union) {
            #line 357 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 358 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(void)__self; (void)index;\n");
            #line 359 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 360 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return 0;\n");
        } else {
            #line 362 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 363 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

            #line 365 "src/compiler/FileGenerator.pv"
            if (module->mode_cpp) {
                #line 366 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = (");
                #line 367 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
                #line 368 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)__self;\n");
            } else {
                #line 370 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = __self;\n");
            }

            #line 373 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 374 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "switch (self->type) {\n");
            #line 375 "src/compiler/FileGenerator.pv"
            generator->indent += 1;

            #line 377 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 377 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 377 "src/compiler/FileGenerator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 378 "src/compiler/FileGenerator.pv"
                if (usize__Eq_usize__eq(variant->types.length, 0)) {
                    #line 378 "src/compiler/FileGenerator.pv"
                    continue;
                }

                #line 380 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 381 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case ");
                #line 382 "src/compiler/FileGenerator.pv"
                Generator__write_enum_variant_name(generator, code_file, generics->self_type, variant);
                #line 383 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ": switch (index) {\n");
                #line 384 "src/compiler/FileGenerator.pv"
                generator->indent += 1;

                #line 386 "src/compiler/FileGenerator.pv"
                uintptr_t i = 0;
                #line 387 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 387 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 387 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 388 "src/compiler/FileGenerator.pv"
                    Generator__write_indent(generator, code_file);
                    #line 389 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "case %zu: return ", i);

                    #line 391 "src/compiler/FileGenerator.pv"
                    if (!Generator__is_reference(type) || Type__is_fat_pointer(type)) {
                        #line 392 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "&");
                    }

                    #line 395 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "self->");
                    #line 396 "src/compiler/FileGenerator.pv"
                    Generator__write_str_lowercase(generator, code_file, variant->name->value);
                    #line 397 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "_value");

                    #line 399 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 400 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ".");
                        #line 401 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, variant->names.data[i]);
                    } else if (variant->types.length > 1) {
                        #line 403 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "._%zu", i);
                    }

                    #line 406 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ";\n");
                    #line 407 "src/compiler/FileGenerator.pv"
                    i += 1;
                } }

                #line 410 "src/compiler/FileGenerator.pv"
                generator->indent -= 1;
                #line 411 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 412 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "}\n");
                #line 413 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 414 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "break;\n");
            } }

            #line 417 "src/compiler/FileGenerator.pv"
            generator->indent -= 1;
            #line 418 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 419 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "}\n");

            #line 421 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 422 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return 0;\n");
        }

        #line 425 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 426 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 428 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 429 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 430 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_param(void* __self, uintptr_t index, void* value) {\n");

        #line 432 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 434 "src/compiler/FileGenerator.pv"
        if (!is_discriminated_union) {
            #line 435 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 436 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(void)__self; (void)index; (void)value;\n");
            #line 437 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 438 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return false;\n");
        } else {
            #line 440 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 441 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

            #line 443 "src/compiler/FileGenerator.pv"
            if (module->mode_cpp) {
                #line 444 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = (");
                #line 445 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
                #line 446 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)__self;\n");
            } else {
                #line 448 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = __self;\n");
            }

            #line 451 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 452 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "switch (self->type) {\n");
            #line 453 "src/compiler/FileGenerator.pv"
            generator->indent += 1;

            #line 455 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 455 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 455 "src/compiler/FileGenerator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 456 "src/compiler/FileGenerator.pv"
                if (usize__Eq_usize__eq(variant->types.length, 0)) {
                    #line 456 "src/compiler/FileGenerator.pv"
                    continue;
                }

                #line 458 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 459 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case ");
                #line 460 "src/compiler/FileGenerator.pv"
                Generator__write_enum_variant_name(generator, code_file, generics->self_type, variant);
                #line 461 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ": switch (index) {\n");
                #line 462 "src/compiler/FileGenerator.pv"
                generator->indent += 1;

                #line 464 "src/compiler/FileGenerator.pv"
                uintptr_t i = 0;
                #line 465 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 465 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 465 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 466 "src/compiler/FileGenerator.pv"
                    if (Type__is_sequence(type)) {
                        #line 467 "src/compiler/FileGenerator.pv"
                        i += 1;
                        #line 468 "src/compiler/FileGenerator.pv"
                        continue;
                    }

                    #line 471 "src/compiler/FileGenerator.pv"
                    Generator__write_indent(generator, code_file);
                    #line 472 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "case %zu: self->", i);
                    #line 473 "src/compiler/FileGenerator.pv"
                    Generator__write_str_lowercase(generator, code_file, variant->name->value);
                    #line 474 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "_value");

                    #line 476 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 477 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ".");
                        #line 478 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, variant->names.data[i]);
                    } else if (variant->types.length > 1) {
                        #line 480 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "._%zu", i);
                    }

                    #line 483 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, " = ");

                    #line 485 "src/compiler/FileGenerator.pv"
                    if (!Generator__is_reference(type) || Type__is_fat_pointer(type)) {
                        #line 486 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "*(");
                        #line 487 "src/compiler/FileGenerator.pv"
                        Generator__write_type(generator, code_file, type, generics);
                        #line 488 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "*)");
                    } else if (module->mode_cpp) {
                        #line 490 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(");
                        #line 491 "src/compiler/FileGenerator.pv"
                        Generator__write_type(generator, code_file, type, generics);
                        #line 492 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ")");
                    }

                    #line 495 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "value; return true;\n");
                    #line 496 "src/compiler/FileGenerator.pv"
                    i += 1;
                } }

                #line 499 "src/compiler/FileGenerator.pv"
                generator->indent -= 1;
                #line 500 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 501 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "}\n");
                #line 502 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 503 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "break;\n");
            } }

            #line 506 "src/compiler/FileGenerator.pv"
            generator->indent -= 1;
            #line 507 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 508 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "}\n");

            #line 510 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 511 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return false;\n");
        }

        #line 514 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 515 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 517 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_EnumVTable ");
        #line 518 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 519 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__ENUM");
        #line 520 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_variants = &");
        #line 521 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 522 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants, .fn_get_variant_index = &");
        #line 523 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 524 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index, .fn_set_variant = &");
        #line 525 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 526 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_variant, .fn_get_param = &");
        #line 527 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 528 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_param, .fn_set_param = &");
        #line 529 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 530 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_param };\n");
    }

    #line 533 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 534 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 535 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 537 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 539 "src/compiler/FileGenerator.pv"
    return true;
}

#line 542 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 543 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 544 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 544 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 544 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 545 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 547 "src/compiler/FileGenerator.pv"
    return success;
}

#line 550 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 551 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 552 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 553 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 554 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 555 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 556 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 557 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 559 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 560 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 561 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 562 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 562 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 562 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 564 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 565 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 566 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 567 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 568 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 570 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 571 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 573 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 573 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 573 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 573 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 574 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 575 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 575 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 576 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 577 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 579 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 582 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 586 "src/compiler/FileGenerator.pv"
        if (struct_info->module->mode_cpp) {
            #line 587 "src/compiler/FileGenerator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 587 "src/compiler/FileGenerator.pv"
                fprintf(header_file, "\n");
            }
            #line 588 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 591 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 593 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 593 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 593 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 594 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 597 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (generator->root->mode_cpp) {
        #line 599 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 600 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 601 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 604 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 605 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 606 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 606 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }

    #line 608 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 609 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write struct definition for %s\n", String__c_str(&name));

        #line 611 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 612 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 615 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 615 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 617 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 618 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 619 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 620 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 623 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 625 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 626 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 627 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 629 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(struct_info->impls.length, 0) && !usage->impl_dynamic_usage && !usage->any_usage) {
        #line 630 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 633 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 634 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 635 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 637 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 640 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, struct_info->module, String__as_str(&name), ext);

    #line 642 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 643 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 644 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 644 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 644 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 646 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 647 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &struct_info->module->includes);
    #line 648 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 650 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 651 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 652 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 653 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 655 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 656 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for struct %s\n", String__c_str(&name));
        #line 657 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 658 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 661 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 662 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 665 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 665 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 665 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 666 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 667 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 668 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 668 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 669 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 669 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 670 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 671 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, trait_entry._1, generics);
        #line 672 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 673 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 674 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 675 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 676 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 678 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 679 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 679 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 679 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 680 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 680 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 681 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 683 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 684 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 685 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 686 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 687 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 690 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 693 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 694 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 695 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 698 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 699 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 701 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructFieldInfo.h>\n");
        #line 702 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructFieldInfo.h>\n");
        #line 703 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructTraitInfo.h>\n");
        #line 704 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructTraitInfo.h>\n");
        #line 710 "src/compiler/FileGenerator.pv"
        struct Trait* struct_trait = 0;
        #line 711 "src/compiler/FileGenerator.pv"
        struct Namespace* std_namespace = Root__find_namespace(generator->root, (struct str){ .ptr = "std", .length = strlen("std") });
        #line 712 "src/compiler/FileGenerator.pv"
        if (std_namespace != 0) {
            #line 712 "src/compiler/FileGenerator.pv"
            struct_trait = Namespace__find_trait(std_namespace, (struct str){ .ptr = "Struct", .length = strlen("Struct") }, 0);
        }
        #line 713 "src/compiler/FileGenerator.pv"
        if (struct_trait == 0) {
            #line 714 "src/compiler/FileGenerator.pv"
            fprintf(stderr, "Missing std Struct trait for dynamic struct %s\n", String__c_str(&name));
            #line 715 "src/compiler/FileGenerator.pv"
            fclose(code_file);
            #line 716 "src/compiler/FileGenerator.pv"
            return false;
        }

        #line 719 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "extern struct trait_StructVTable ");
        #line 720 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 721 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT;\n");

        #line 723 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructTraitInfo ");
        #line 724 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 725 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_traits(void* __self) {\n");
        #line 726 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 727 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 728 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(void)__self;\n");
        #line 729 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 730 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructTraitInfo traits[] = { ");

        #line 732 "src/compiler/FileGenerator.pv"
        bool first_trait = true;
        #line 733 "src/compiler/FileGenerator.pv"
        uintptr_t trait_count = 1;
        #line 734 "src/compiler/FileGenerator.pv"
        struct Type struct_trait_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = struct_trait, ._1 = 0} };
        #line 735 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(struct StructTraitInfo){ .type_id = ");
        #line 736 "src/compiler/FileGenerator.pv"
        Generator__write_typeid(generator, code_file, &struct_trait_type, generics);
        #line 737 "src/compiler/FileGenerator.pv"
        fprintf(code_file, ", .vtable = (void*)&");
        #line 738 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 739 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT }");
        #line 740 "src/compiler/FileGenerator.pv"
        first_trait = false;

        #line 742 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
        #line 742 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
            #line 742 "src/compiler/FileGenerator.pv"
            struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

            #line 743 "src/compiler/FileGenerator.pv"
            struct Trait* trait_info = trait_entry._0;
            #line 744 "src/compiler/FileGenerator.pv"
            struct Token* trait_name = trait_info->name;
            #line 745 "src/compiler/FileGenerator.pv"
            if (trait_name == 0 || !Trait__has_dynamic_dispatch(trait_info)) {
                #line 745 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 746 "src/compiler/FileGenerator.pv"
            if (str__Eq_str__eq(trait_name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                #line 746 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 748 "src/compiler/FileGenerator.pv"
            if (!first_trait) {
                #line 748 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 749 "src/compiler/FileGenerator.pv"
            first_trait = false;
            #line 750 "src/compiler/FileGenerator.pv"
            trait_count += 1;
            #line 751 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructTraitInfo){ .type_id = ");
            #line 752 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, trait_entry._1, generics);
            #line 753 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .vtable = (void*)&");
            #line 754 "src/compiler/FileGenerator.pv"
            Generator__write_str_title(generator, code_file, String__as_str(&name));
            #line 755 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "__VTABLE__");
            #line 756 "src/compiler/FileGenerator.pv"
            Generator__write_str_title(generator, code_file, trait_name->value);
            #line 757 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
        } }

        #line 760 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 761 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 762 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructTraitInfo){ .data = traits, .length = %zu };\n", trait_count);
        #line 763 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 764 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n\n");

        #line 766 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructFieldInfo ");
        #line 767 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 768 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 770 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 771 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 772 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructFieldInfo fields[] = { ");

        #line 774 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 775 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 775 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 775 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 776 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 776 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 777 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructFieldInfo){ .index = %zu, .name = (struct str){ .ptr = \"", field_index);
            #line 778 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, field->name);
            #line 779 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .type_id = ", field->name->value.length);
            #line 780 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, &field->type, generics);
            #line 781 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .type_name = ");
            #line 782 "src/compiler/FileGenerator.pv"
            Generator__write_typename(generator, code_file, &field->type, generics);
            #line 783 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 784 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 787 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 788 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 789 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructFieldInfo){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 790 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 791 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 793 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 794 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 795 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 797 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 799 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 800 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 802 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 803 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 804 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 805 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 807 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 810 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 811 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 812 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 814 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 815 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 815 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 815 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 816 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 817 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 819 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 820 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 822 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 823 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 826 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 827 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
            }

            #line 830 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 831 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 834 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 835 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 836 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 838 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 839 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 841 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 842 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 844 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 845 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 846 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 848 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 850 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 851 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 853 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 854 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 855 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 856 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 858 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 861 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 862 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 863 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 865 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 866 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 866 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 866 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 867 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 867 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 869 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);

            #line 871 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 872 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 873 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, &field->type, generics);
                #line 874 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 876 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 877 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
                #line 878 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 880 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 881 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 882 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 883 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 885 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 886 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 887 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 891 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 892 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 895 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 896 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 897 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 899 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 900 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 902 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 903 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 905 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 906 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 907 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 908 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_fields = &");
        #line 909 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 910 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .fn_get_traits = &");
        #line 911 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 912 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_traits, .fn_get_field = &");
        #line 913 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 914 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .fn_set_field = &");
        #line 915 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 916 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 919 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 920 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 921 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 923 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 925 "src/compiler/FileGenerator.pv"
    return true;
}

#line 928 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_extern(struct FileGenerator* self, FILE* file, struct str name) {
    #line 929 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 930 "src/compiler/FileGenerator.pv"
    fprintf(file, "#include <std/trait_Any.h>\n");
    #line 931 "src/compiler/FileGenerator.pv"
    fprintf(file, "extern struct trait_AnyVTable ");
    #line 932 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 933 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 934 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 935 "src/compiler/FileGenerator.pv"
    fprintf(file, ";\n");
}

#line 938 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_definition(struct FileGenerator* self, FILE* file, struct str name, struct Type* self_type, struct GenericMap* generics) {
    #line 939 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 940 "src/compiler/FileGenerator.pv"
    fprintf(file, "\nuintptr_t ");
    #line 941 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 942 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size(void* __self) { (void)__self; return sizeof(");
    #line 943 "src/compiler/FileGenerator.pv"
    Generator__write_type(generator, file, self_type, generics);
    #line 944 "src/compiler/FileGenerator.pv"
    fprintf(file, "); }\n");

    #line 946 "src/compiler/FileGenerator.pv"
    fprintf(file, "struct trait_AnyVTable ");
    #line 947 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 948 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 949 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 950 "src/compiler/FileGenerator.pv"
    fprintf(file, " = { .fn_size = &");
    #line 951 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 952 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size };\n");
}

#line 955 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 956 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 957 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 957 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 957 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 958 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 960 "src/compiler/FileGenerator.pv"
    return success;
}

#line 963 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 964 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 965 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 966 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 967 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 968 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 969 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 971 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 972 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 973 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 974 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 974 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 974 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 976 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 977 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 978 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 979 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 980 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 982 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, header_file, &primitive_info->impls);
    #line 983 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 984 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 986 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 987 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write primitive definition for %.*s\n", (int32_t)(name.length), name.ptr);
        #line 988 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 989 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 992 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 992 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, name);
    }

    #line 994 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 996 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 997 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 998 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1000 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(primitive_info->impls.length, 0)) {
        #line 1001 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1004 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 1006 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 1007 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 1008 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1008 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1008 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1010 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, code_file, &primitive_info->impls);
    #line 1011 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 1012 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 1014 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1015 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1016 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1017 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 1019 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 1020 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for primitive %.*s\n", (int32_t)(name.length), name.ptr);
        #line 1021 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 1022 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1025 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 1025 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 1025 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 1026 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 1027 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 1027 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1029 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 1030 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 1030 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1032 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 1032 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1034 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 1035 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, &impl_info->trait_type, generics);
        #line 1036 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 1037 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, name);
        #line 1038 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 1039 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 1040 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 1042 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 1043 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 1043 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 1043 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 1044 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 1044 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 1045 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 1047 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 1048 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 1049 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 1050 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 1051 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 1054 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 1057 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 1058 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 1059 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, name, generics->self_type, generics);
    }

    #line 1062 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 1063 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 1064 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 1066 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 1068 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1071 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 1072 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1073 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1073 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1073 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1074 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 1075 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 1076 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 1078 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 1081 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1084 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 1085 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1086 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1087 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1088 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;

    #line 1090 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 1091 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 1093 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 1094 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &sequence_type, &sequence_type, generics);
    #line 1095 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1097 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1098 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 1099 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 1100 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1100 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1100 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1102 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1103 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1104 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1105 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1106 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1108 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1109 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 1111 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 1112 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 1113 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 1115 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 1116 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 1117 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &generator->root->type_usize, generics);

    #line 1119 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 1121 "src/compiler/FileGenerator.pv"
    struct TypeImpl* hack_type_impl = generator->root->hack_type_impl;
    #line 1122 "src/compiler/FileGenerator.pv"
    if (hack_type_impl == 0) {
        #line 1123 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing hack type impl in generate_slice\n");
        #line 1124 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1127 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), hack_type_impl->impl_info, generics);

    #line 1129 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1131 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 1132 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 1133 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1135 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 1137 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 1138 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 1139 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1139 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1139 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1141 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1142 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1143 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1144 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 1146 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {hack_type_impl->impl_info};
    #line 1147 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };
    #line 1148 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };

    #line 1150 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 1151 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for slice %s\n", String__c_str(&name));
        #line 1152 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 1153 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1156 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 1157 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 1158 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 1160 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 1162 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1165 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 1166 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1167 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1167 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1167 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1168 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 1170 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1173 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 1174 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1175 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1176 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 1177 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 1178 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 1180 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &tuple_type, &tuple_type, generics);
    #line 1181 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1183 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1184 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 1185 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 1186 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1186 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1186 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1188 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1189 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1190 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1191 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1192 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1194 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1195 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 1197 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 1198 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 1199 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 1200 "src/compiler/FileGenerator.pv"
    generator->indent += 1;

    #line 1202 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 1202 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 1202 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 1202 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 1203 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1204 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 1205 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 1207 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, header_file);
        #line 1208 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(generator, header_file, String__as_str(&element_name), element, generics);
        #line 1209 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 1210 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 1213 "src/compiler/FileGenerator.pv"
    generator->indent -= 1;
    #line 1214 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 1216 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1218 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 1219 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 1220 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1222 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1225 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 1226 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1227 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1227 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1227 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1228 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 1230 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1233 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl_loop(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage) {
    #line 1234 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1235 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1235 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1235 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1236 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_type_impl(self, usage, usage_context) && success;
    } }
    #line 1238 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1241 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage, struct UsageContext* usage_context) {
    #line 1242 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1243 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1244 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);
    #line 1245 "src/compiler/FileGenerator.pv"
    struct TypeImpl* type_impl = usage->type;
    #line 1246 "src/compiler/FileGenerator.pv"
    struct Impl* impl_info = type_impl->impl_info;
    #line 1247 "src/compiler/FileGenerator.pv"
    struct Context* context = impl_info->context;
    #line 1248 "src/compiler/FileGenerator.pv"
    struct Module* module = context->module;
    #line 1249 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1250 "src/compiler/FileGenerator.pv"
    struct Type* self_type = generics->self_type;
    #line 1251 "src/compiler/FileGenerator.pv"
    if (self_type == 0) {
        #line 1251 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1253 "src/compiler/FileGenerator.pv"
    struct Type* named_self_type = self_type;
    #line 1254 "src/compiler/FileGenerator.pv"
    if (Type__is_fat_pointer(self_type)) {
        #line 1255 "src/compiler/FileGenerator.pv"
        named_self_type = Type__deref_1(self_type);
        #line 1256 "src/compiler/FileGenerator.pv"
        if (named_self_type == 0) {
            #line 1256 "src/compiler/FileGenerator.pv"
            named_self_type = self_type;
        }
    }
    #line 1258 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, named_self_type, self_type, generics);

    #line 1260 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1261 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 1262 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 1263 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1263 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1263 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1265 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1266 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1267 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1268 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1269 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1271 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1272 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 1273 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), impl_info, generics);

    #line 1275 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1277 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 1278 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 1279 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1281 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 1282 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 1283 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 1284 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1284 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1284 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1286 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 1287 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 1288 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 1290 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {impl_info};
    #line 1291 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .capacity = 0 };

    #line 1293 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 1294 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for type %s\n", String__c_str(&name));
        #line 1295 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 1296 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1299 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 1300 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 1301 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 1303 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 1305 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1308 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 1309 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1310 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1311 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1312 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;

    #line 1314 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 1314 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1316 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 1317 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1318 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1320 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 1321 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 1322 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1322 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1322 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1324 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1325 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1326 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1327 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1328 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1330 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1331 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 1332 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 1333 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 1336 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1337 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 1339 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 1339 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 1339 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1341 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1342 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 1343 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 1344 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 1347 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1349 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 1350 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 1351 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1353 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1356 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 1357 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1358 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 1358 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1360 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;

    #line 1362 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(generator->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 1363 "src/compiler/FileGenerator.pv"
    if (blank_generics == 0) {
        #line 1364 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing blank generics in generate_global\n");
        #line 1365 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 1367 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, generator->allocator);

    #line 1369 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(generator->allocator);
    #line 1370 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_ctx;

    #line 1372 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(generator->allocator);
    #line 1373 "src/compiler/FileGenerator.pv"
    #line 1374 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(generator, &global->type, blank_generics, &primitive_includes);

    #line 1376 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1377 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 1378 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 1379 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1379 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1379 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1381 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1382 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1383 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1384 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1385 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1387 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 1387 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1387 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 1388 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 1391 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\nextern ");
    #line 1392 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1392 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 1393 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, name, &global->type, blank_generics);
    #line 1394 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 1396 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1398 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 1399 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 1400 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1402 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 1403 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 1404 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 1405 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1405 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1405 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1407 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &global->module->includes);

    #line 1409 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 1410 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1411 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1412 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 1414 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1414 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 1415 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, code_file, name, &global->type, blank_generics);
    #line 1416 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 1417 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 1418 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, code_file, global->value, blank_generics);
    }
    #line 1420 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 1422 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 1423 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 1424 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 1426 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 1428 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 1430 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 1433 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1434 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1434 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1434 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1435 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1435 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1435 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1436 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 1436 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 1436 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 1437 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 1441 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 1445 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 1446 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1448 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1448 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1448 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1449 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1449 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1449 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 1449 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1450 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 1450 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 1450 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 1451 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 1452 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 1453 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 1455 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(generator, module, test_info->func_name, (struct str){ .ptr = ".test.h", .length = strlen(".test.h") });
                #line 1456 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 1458 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(generator, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 1459 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 1463 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 1467 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1468 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1469 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 1471 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1472 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1473 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1474 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 1476 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 1478 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(func_names.length, 0)) {
        #line 1478 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1480 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1481 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = generator->path, .length = strlen(generator->path) });
    #line 1482 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/main.test.c", .length = strlen("/main.test.c") });

    #line 1484 "src/compiler/FileGenerator.pv"
    char const* runner_tmp = tmpnam(0);
    #line 1485 "src/compiler/FileGenerator.pv"
    FILE* runner_file = fopen(runner_tmp, "w+");
    #line 1486 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 1486 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1488 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n\n");

    #line 1490 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 1491 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 1492 "src/compiler/FileGenerator.pv"
        struct str hp = header_paths.data[i];
        #line 1493 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 1494 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, hp);
        #line 1495 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 1496 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1499 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\nint main(void) {\n");
    #line 1500 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int passed = 0;\n");
    #line 1501 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int failed = 0;\n\n");

    #line 1503 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 1504 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 1505 "src/compiler/FileGenerator.pv"
        struct str desc = descriptions.data[i];
        #line 1506 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 1507 "src/compiler/FileGenerator.pv"
        struct str module_path = module_paths.data[i];

        #line 1509 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    fputs(\"[TEST] ");
        #line 1510 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, module_path);
        #line 1511 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 1512 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, desc);
        #line 1513 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\\n\", stdout);\n");
        #line 1514 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    ");
        #line 1515 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 1516 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "();\n");
        #line 1517 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    passed++;\n\n");

        #line 1519 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1522 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    printf(\"[RESULT] %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 1523 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    return failed > 0 ? 1 : 0;\n");
    #line 1524 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "}\n");

    #line 1526 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&runner_path), runner_file);
    #line 1527 "src/compiler/FileGenerator.pv"
    fclose(runner_file);
    #line 1528 "src/compiler/FileGenerator.pv"
    remove(runner_tmp);

    #line 1530 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, runner_path);
}

#line 1533 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 1534 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1536 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1536 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1536 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 1536 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1537 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1538 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 1539 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 1540 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 1541 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 1543 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
