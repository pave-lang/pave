#include <string.h>
#include <stdint.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <stdio.h>
#include <fs.h>
#include <compiler/FileGenerator.h>
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
#include <std/Array_ref_Impl.h>
#include <std/Array_HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_str_EnumVariant.h>
#include <std/HashMapIter_str_EnumVariant.h>
#include <tuple_str_EnumVariant.h>
#include <analyzer/Token.h>
#include <analyzer/types/EnumVariant.h>
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
#include <std/Array_Type.h>
#include <std/IterEnumerate_ref_Type.h>
#include <std/Iter_ref_Type.h>
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
#include <analyzer/Namespace.h>
#include <std/HashMapIter_str_ref_Module.h>
#include <tuple_str_ref_Module.h>
#include <std/HashMap_str_ref_Global.h>
#include <std/HashMapIter_str_ref_Global.h>
#include <tuple_str_ref_Global.h>
#include <std/Array_TestInfo.h>
#include <std/Iter_ref_TestInfo.h>
#include <analyzer/TestInfo.h>
#include <std/Array_str.h>
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
    if (enum_info->impls.length == 0 && !usage->any_usage && !usage->impl_dynamic_usage) {
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
        fprintf(code_file, "struct slice_EnumVariantInfo ");
        #line 209 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 210 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants(void* __self) {\n");

        #line 212 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 213 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 214 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(void)__self;\n");
        #line 215 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 216 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct EnumVariantInfo variants[] = { ");

        #line 218 "src/compiler/FileGenerator.pv"
        uintptr_t variant_index = 0;
        #line 219 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 219 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 219 "src/compiler/FileGenerator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 220 "src/compiler/FileGenerator.pv"
            if (variant_index > 0) {
                #line 220 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 221 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct EnumVariantInfo){ .index = %zu, .name = (struct str){ .ptr = \"", variant_index);
            #line 222 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, variant->name);
            #line 223 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu } }", variant->name->value.length);
            #line 224 "src/compiler/FileGenerator.pv"
            variant_index += 1;
        } }

        #line 227 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 228 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 229 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_EnumVariantInfo){ .data = variants, .length = %zu };\n", enum_info->variants.length);
        #line 230 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 231 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 233 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "uintptr_t ");
        #line 234 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 235 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index(void* __self) {\n");

        #line 237 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 238 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 239 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 241 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 242 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 243 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 244 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 246 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 249 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 250 "src/compiler/FileGenerator.pv"
        if (is_discriminated_union) {
            #line 251 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)self->type;\n");
        } else {
            #line 253 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)*self;\n");
        }

        #line 256 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 257 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 259 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_EnumVTable ");
        #line 260 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 261 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__ENUM");
        #line 262 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_variants = &");
        #line 263 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 264 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants, .fn_get_variant_index = &");
        #line 265 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 266 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index };\n");
    }

    #line 269 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 270 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 271 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 273 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 275 "src/compiler/FileGenerator.pv"
    return true;
}

#line 278 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 279 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 280 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 280 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 280 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 281 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 283 "src/compiler/FileGenerator.pv"
    return success;
}

#line 286 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 287 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 288 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 289 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 290 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 291 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 292 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 293 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 295 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 296 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 297 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 298 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 298 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 298 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 300 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 301 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 302 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 303 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 304 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 306 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 307 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 309 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 309 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 309 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 309 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 310 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 311 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 311 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 312 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 313 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 315 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 318 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 322 "src/compiler/FileGenerator.pv"
        if (struct_info->module->mode_cpp) {
            #line 323 "src/compiler/FileGenerator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 323 "src/compiler/FileGenerator.pv"
                fprintf(header_file, "\n");
            }
            #line 324 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 327 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 329 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 329 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 329 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 330 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 333 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (generator->root->mode_cpp) {
        #line 335 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 336 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 337 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 340 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 341 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 342 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 342 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }

    #line 344 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 345 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write struct definition for %s\n", String__c_str(&name));

        #line 347 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 348 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 351 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 351 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 353 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 354 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 355 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 356 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 359 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 361 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 362 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 363 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 365 "src/compiler/FileGenerator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage && !usage->any_usage) {
        #line 366 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 369 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 370 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 371 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 373 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 376 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, struct_info->module, String__as_str(&name), ext);

    #line 378 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 379 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 380 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 380 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 380 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 382 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 383 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &struct_info->module->includes);
    #line 384 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 386 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 387 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 388 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 389 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 391 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 392 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for struct %s\n", String__c_str(&name));
        #line 393 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 394 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 397 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 398 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 401 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 401 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 401 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 402 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 403 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 404 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 404 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 405 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 405 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 406 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 407 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, trait_entry._1, generics);
        #line 408 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 409 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 410 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 411 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 412 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 414 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 415 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 415 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 415 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 416 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 416 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 417 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 419 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 420 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 421 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 422 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 423 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 426 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 429 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 430 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 431 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 434 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 435 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 437 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructFieldInfo.h>\n");
        #line 438 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructFieldInfo.h>\n");
        #line 439 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructFieldInfo ");
        #line 440 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 441 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 443 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 444 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 445 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructFieldInfo fields[] = { ");

        #line 447 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 448 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 448 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 448 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 449 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 449 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 450 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructFieldInfo){ .index = %zu, .name = (struct str){ .ptr = \"", field_index);
            #line 451 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, field->name);
            #line 452 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .type_id = ", field->name->value.length);
            #line 453 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, &field->type, generics);
            #line 454 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .type_name = ");
            #line 455 "src/compiler/FileGenerator.pv"
            Generator__write_typename(generator, code_file, &field->type, generics);
            #line 456 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 457 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 460 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 461 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 462 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructFieldInfo){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 463 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 464 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 466 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 467 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 468 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 470 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 472 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 473 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 475 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 476 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 477 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 478 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 480 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 483 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 484 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 485 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 487 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 488 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 488 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 488 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 489 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 490 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 492 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 493 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 495 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 496 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 499 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 500 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
            }

            #line 503 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 504 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 507 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 508 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 509 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 511 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 512 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 514 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 515 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 517 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 518 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 519 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 521 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 523 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 524 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 526 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 527 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 528 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 529 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 531 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 534 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 535 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 536 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 538 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 539 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 539 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 539 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 540 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 540 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 542 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);

            #line 544 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 545 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 546 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, &field->type, generics);
                #line 547 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 549 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 550 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
                #line 551 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 553 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 554 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 555 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 556 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 558 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 559 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 560 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 564 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 565 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 568 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 569 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 570 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 572 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 573 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 575 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 576 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 578 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 579 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 580 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 581 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_fields = &");
        #line 582 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 583 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .fn_get_field = &");
        #line 584 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 585 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .fn_set_field = &");
        #line 586 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 587 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 590 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 591 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 592 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 594 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 596 "src/compiler/FileGenerator.pv"
    return true;
}

#line 599 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_extern(struct FileGenerator* self, FILE* file, struct str name) {
    #line 600 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 601 "src/compiler/FileGenerator.pv"
    fprintf(file, "#include <std/trait_Any.h>\n");
    #line 602 "src/compiler/FileGenerator.pv"
    fprintf(file, "extern struct trait_AnyVTable ");
    #line 603 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 604 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 605 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 606 "src/compiler/FileGenerator.pv"
    fprintf(file, ";\n");
}

#line 609 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_definition(struct FileGenerator* self, FILE* file, struct str name, struct Type* self_type, struct GenericMap* generics) {
    #line 610 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 611 "src/compiler/FileGenerator.pv"
    fprintf(file, "\nuintptr_t ");
    #line 612 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 613 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size(void* __self) { (void)__self; return sizeof(");
    #line 614 "src/compiler/FileGenerator.pv"
    Generator__write_type(generator, file, self_type, generics);
    #line 615 "src/compiler/FileGenerator.pv"
    fprintf(file, "); }\n");

    #line 617 "src/compiler/FileGenerator.pv"
    fprintf(file, "struct trait_AnyVTable ");
    #line 618 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 619 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 620 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 621 "src/compiler/FileGenerator.pv"
    fprintf(file, " = { .fn_size = &");
    #line 622 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 623 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size };\n");
}

#line 626 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 627 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 628 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 628 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 628 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 629 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 631 "src/compiler/FileGenerator.pv"
    return success;
}

#line 634 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 635 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 636 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 637 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 638 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 639 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 640 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 642 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 643 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 644 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 645 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 645 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 645 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 647 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 648 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 649 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 650 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 651 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 653 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, header_file, &primitive_info->impls);
    #line 654 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 655 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 657 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 658 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write primitive definition for %.*s\n", (int32_t)(name.length), name.ptr);
        #line 659 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 660 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 663 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 663 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, name);
    }

    #line 665 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 667 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 668 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 669 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 671 "src/compiler/FileGenerator.pv"
    if (primitive_info->impls.length == 0) {
        #line 672 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 675 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 677 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 678 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 679 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 679 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 679 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 681 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, code_file, &primitive_info->impls);
    #line 682 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 683 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 685 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 686 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 687 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 688 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 690 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 691 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for primitive %.*s\n", (int32_t)(name.length), name.ptr);
        #line 692 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 693 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 696 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 696 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 696 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 697 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 698 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 698 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 700 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 701 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 701 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 703 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 703 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 705 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 706 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, &impl_info->trait_type, generics);
        #line 707 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 708 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, name);
        #line 709 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 710 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 711 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 713 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 714 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 714 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 714 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 715 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 715 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 716 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 718 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 719 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 720 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 721 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 722 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 725 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 728 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 729 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 730 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, name, generics->self_type, generics);
    }

    #line 733 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 734 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 735 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 737 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 739 "src/compiler/FileGenerator.pv"
    return true;
}

#line 742 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 743 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 744 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 744 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 744 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 745 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 746 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 747 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 749 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 752 "src/compiler/FileGenerator.pv"
    return success;
}

#line 755 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 756 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 757 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 758 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 759 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;

    #line 761 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 762 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 764 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 765 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &sequence_type, &sequence_type, generics);
    #line 766 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 768 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 769 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 770 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 771 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 771 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 771 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 773 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 774 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 775 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 776 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 777 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 779 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 780 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 782 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 783 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 784 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 786 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 787 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 788 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &generator->root->type_usize, generics);

    #line 790 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 792 "src/compiler/FileGenerator.pv"
    struct TypeImpl* hack_type_impl = generator->root->hack_type_impl;
    #line 793 "src/compiler/FileGenerator.pv"
    if (hack_type_impl == 0) {
        #line 794 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing hack type impl in generate_slice\n");
        #line 795 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 798 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), hack_type_impl->impl_info, generics);

    #line 800 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 802 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 803 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 804 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 806 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 808 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 809 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 810 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 810 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 810 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 812 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 813 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 814 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 815 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 817 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {hack_type_impl->impl_info};
    #line 818 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };
    #line 819 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };

    #line 821 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 822 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for slice %s\n", String__c_str(&name));
        #line 823 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 824 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 827 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 828 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 829 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 831 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 833 "src/compiler/FileGenerator.pv"
    return true;
}

#line 836 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 837 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 838 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 838 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 838 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 839 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 841 "src/compiler/FileGenerator.pv"
    return success;
}

#line 844 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 845 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 846 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 847 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 848 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 849 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 851 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &tuple_type, &tuple_type, generics);
    #line 852 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 854 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 855 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 856 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 857 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 857 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 857 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 859 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 860 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 861 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 862 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 863 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 865 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 866 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 868 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 869 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 870 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 871 "src/compiler/FileGenerator.pv"
    generator->indent += 1;

    #line 873 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 873 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 873 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 873 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 874 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 875 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 876 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 878 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, header_file);
        #line 879 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(generator, header_file, String__as_str(&element_name), element, generics);
        #line 880 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 881 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 884 "src/compiler/FileGenerator.pv"
    generator->indent -= 1;
    #line 885 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 887 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 889 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 890 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 891 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 893 "src/compiler/FileGenerator.pv"
    return true;
}

#line 896 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 897 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 898 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 898 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 898 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 899 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 901 "src/compiler/FileGenerator.pv"
    return success;
}

#line 904 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl_loop(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage) {
    #line 905 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 906 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 906 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 906 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 907 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_type_impl(self, usage, usage_context) && success;
    } }
    #line 909 "src/compiler/FileGenerator.pv"
    return success;
}

#line 912 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage, struct UsageContext* usage_context) {
    #line 913 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 914 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 915 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);
    #line 916 "src/compiler/FileGenerator.pv"
    struct TypeImpl* type_impl = usage->type;
    #line 917 "src/compiler/FileGenerator.pv"
    struct Impl* impl_info = type_impl->impl_info;
    #line 918 "src/compiler/FileGenerator.pv"
    struct Context* context = impl_info->context;
    #line 919 "src/compiler/FileGenerator.pv"
    struct Module* module = context->module;
    #line 920 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 921 "src/compiler/FileGenerator.pv"
    struct Type* self_type = generics->self_type;
    #line 922 "src/compiler/FileGenerator.pv"
    if (self_type == 0) {
        #line 922 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 924 "src/compiler/FileGenerator.pv"
    struct Type* named_self_type = self_type;
    #line 925 "src/compiler/FileGenerator.pv"
    if (Type__is_fat_pointer(self_type)) {
        #line 926 "src/compiler/FileGenerator.pv"
        named_self_type = Type__deref_1(self_type);
        #line 927 "src/compiler/FileGenerator.pv"
        if (named_self_type == 0) {
            #line 927 "src/compiler/FileGenerator.pv"
            named_self_type = self_type;
        }
    }
    #line 929 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, named_self_type, self_type, generics);

    #line 931 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 932 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 933 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 934 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 934 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 934 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 936 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 937 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 938 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 939 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 940 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 942 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 943 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 944 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), impl_info, generics);

    #line 946 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 948 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 949 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 950 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 952 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 953 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 954 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 955 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 955 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 955 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 957 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 958 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 959 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 961 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {impl_info};
    #line 962 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .capacity = 0 };

    #line 964 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 965 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for type %s\n", String__c_str(&name));
        #line 966 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 967 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 970 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 971 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 972 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 974 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 976 "src/compiler/FileGenerator.pv"
    return true;
}

#line 979 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 980 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 981 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 982 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 983 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;

    #line 985 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 985 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 987 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 988 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 989 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 991 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 992 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 993 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 993 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 993 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 995 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 996 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 997 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 998 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 999 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1001 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1002 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 1003 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 1004 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 1007 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1008 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 1010 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 1010 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 1010 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1012 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1013 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 1014 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 1015 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 1018 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1020 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 1021 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 1022 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1024 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1027 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 1028 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1029 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 1029 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1031 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;

    #line 1033 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(generator->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 1034 "src/compiler/FileGenerator.pv"
    if (blank_generics == 0) {
        #line 1035 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing blank generics in generate_global\n");
        #line 1036 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 1038 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, generator->allocator);

    #line 1040 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(generator->allocator);
    #line 1041 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_ctx;

    #line 1043 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(generator->allocator);
    #line 1044 "src/compiler/FileGenerator.pv"
    #line 1045 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(generator, &global->type, blank_generics, &primitive_includes);

    #line 1047 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1048 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 1049 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 1050 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1050 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1050 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1052 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1053 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1054 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1055 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1056 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1058 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 1058 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1058 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 1059 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 1062 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\nextern ");
    #line 1063 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1063 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 1064 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, name, &global->type, blank_generics);
    #line 1065 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 1067 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1069 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 1070 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 1071 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 1073 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 1074 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 1075 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 1076 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1076 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1076 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1078 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &global->module->includes);

    #line 1080 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 1081 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1082 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1083 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 1085 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1085 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 1086 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, code_file, name, &global->type, blank_generics);
    #line 1087 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 1088 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 1089 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, code_file, global->value, blank_generics);
    }
    #line 1091 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 1093 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 1094 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 1095 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 1097 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 1099 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 1101 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 1104 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1105 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1105 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1105 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1106 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1106 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1106 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1107 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 1107 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 1107 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 1108 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 1112 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 1116 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 1117 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1119 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1119 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1119 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1120 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1120 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1120 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 1120 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1121 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 1121 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 1121 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 1122 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 1123 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 1124 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 1126 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(generator, module, test_info->func_name, (struct str){ .ptr = ".test.h", .length = strlen(".test.h") });
                #line 1127 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 1129 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(generator, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 1130 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 1134 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 1138 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1139 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1140 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 1142 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1143 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1144 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1145 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 1147 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 1149 "src/compiler/FileGenerator.pv"
    if (func_names.length == 0) {
        #line 1149 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1151 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1152 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = generator->path, .length = strlen(generator->path) });
    #line 1153 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/main.test.c", .length = strlen("/main.test.c") });

    #line 1155 "src/compiler/FileGenerator.pv"
    char const* runner_tmp = tmpnam(0);
    #line 1156 "src/compiler/FileGenerator.pv"
    FILE* runner_file = fopen(runner_tmp, "w+");
    #line 1157 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 1157 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1159 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n\n");

    #line 1161 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 1162 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 1163 "src/compiler/FileGenerator.pv"
        struct str hp = header_paths.data[i];
        #line 1164 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 1165 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, hp);
        #line 1166 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 1167 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1170 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\nint main(void) {\n");
    #line 1171 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int passed = 0;\n");
    #line 1172 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int failed = 0;\n\n");

    #line 1174 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 1175 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 1176 "src/compiler/FileGenerator.pv"
        struct str desc = descriptions.data[i];
        #line 1177 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 1178 "src/compiler/FileGenerator.pv"
        struct str module_path = module_paths.data[i];

        #line 1180 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    fputs(\"[TEST] ");
        #line 1181 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, module_path);
        #line 1182 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 1183 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, desc);
        #line 1184 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\\n\", stdout);\n");
        #line 1185 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    ");
        #line 1186 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 1187 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "();\n");
        #line 1188 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    passed++;\n\n");

        #line 1190 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1193 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    printf(\"[RESULT] %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 1194 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    return failed > 0 ? 1 : 0;\n");
    #line 1195 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "}\n");

    #line 1197 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&runner_path), runner_file);
    #line 1198 "src/compiler/FileGenerator.pv"
    fclose(runner_file);
    #line 1199 "src/compiler/FileGenerator.pv"
    remove(runner_tmp);

    #line 1201 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, runner_path);
}

#line 1204 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 1205 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1207 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1207 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1207 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 1207 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1208 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1209 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 1210 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 1211 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 1212 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 1214 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
