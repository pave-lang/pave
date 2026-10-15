#include <stdint.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <fs.h>

#include <stdio.h>
#include <fs.h>
#include <compiler/Generator.h>
#include <analyzer/Root.h>
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
#include <std/Array_ref_UsageContext.h>
#include <std/HashMap_usize_TypeFunctionUsage.h>
#include <std/HashMap_usize_TypeUsage_TypeImpl.h>
#include <std/HashMapIter_usize_TypeUsage_TypeImpl.h>
#include <tuple_usize_TypeUsage_TypeImpl.h>
#include <std/Iter_ref_ref_UsageContext.h>
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

#line 24 "src/compiler/FileGenerator.pv"
void FileGenerator__open_c_linkage(struct FileGenerator* self, FILE* file) {
    #line 25 "src/compiler/FileGenerator.pv"
    if (!self->generator->root->mode_cpp) {
        #line 25 "src/compiler/FileGenerator.pv"
        return;
    }
    #line 26 "src/compiler/FileGenerator.pv"
    fprintf(file, "#ifdef __cplusplus\nextern \"C\" {\n#endif\n\n");
}

#line 29 "src/compiler/FileGenerator.pv"
void FileGenerator__close_c_linkage(struct FileGenerator* self, FILE* file) {
    #line 30 "src/compiler/FileGenerator.pv"
    if (!self->generator->root->mode_cpp) {
        #line 30 "src/compiler/FileGenerator.pv"
        return;
    }
    #line 31 "src/compiler/FileGenerator.pv"
    fprintf(file, "\n#ifdef __cplusplus\n}\n#endif\n");
}

#line 34 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_function_loop(struct FileGenerator* self, struct TypeFunctionUsage* usage) {
    #line 35 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 36 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 36 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 36 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 37 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_function(self, usage, usage_context) && success;
    } }
    #line 39 "src/compiler/FileGenerator.pv"
    return success;
}

#line 42 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_function(struct FileGenerator* self, struct TypeFunctionUsage* usage, struct UsageContext* usage_context) {
    #line 43 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 44 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 45 "src/compiler/FileGenerator.pv"
    struct Function* func_info = usage->type;
    #line 46 "src/compiler/FileGenerator.pv"
    if (func_info->type == FUNCTION_TYPE__BUILTIN) {
        #line 46 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 48 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 49 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 51 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 52 "src/compiler/FileGenerator.pv"
    struct str name_str = String__as_str(&name);
    #line 53 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_context = FunctionContext__new(generator->allocator, func_info, true);
    #line 54 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_context;

    #line 56 "src/compiler/FileGenerator.pv"
    struct str code_ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    #line 57 "src/compiler/FileGenerator.pv"
    struct str header_ext = (struct str){ .ptr = ".h", .length = strlen(".h") };
    #line 58 "src/compiler/FileGenerator.pv"
    if (func_info->type == FUNCTION_TYPE__TEST) {
        #line 59 "src/compiler/FileGenerator.pv"
        code_ext = (struct str){ .ptr = ".test.c", .length = strlen(".test.c") };
        #line 60 "src/compiler/FileGenerator.pv"
        header_ext = (struct str){ .ptr = ".test.h", .length = strlen(".test.h") };
    }

    #line 63 "src/compiler/FileGenerator.pv"
    struct Context* context = func_info->context;
    #line 64 "src/compiler/FileGenerator.pv"
    if (context == 0) {
        #line 65 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing function context in generate_function\n");
        #line 66 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 68 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, context->module);

    #line 70 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, context->module, name_str, code_ext);
    #line 71 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();

    #line 73 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 73 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 73 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 75 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 76 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &context->module->includes);
    #line 77 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 79 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, context->module, name_str, header_ext);
    #line 80 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 81 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 82 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 84 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, code_file, func_info, generics, 0)) {
        #line 85 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write function definition for %s\n", String__c_str(&name));
        #line 86 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 87 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 90 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_function_block(&defs, code_file, name_str, func_info, generics, usage_context);

    #line 92 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 93 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 95 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 97 "src/compiler/FileGenerator.pv"
    include_writer = IncludeWriter__new(generator->allocator);

    #line 99 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, context->module, name_str, header_ext);
    #line 100 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();

    #line 102 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 102 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 102 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 104 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 105 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 106 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 107 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 108 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 110 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_code, 0);
    #line 111 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 112 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 114 "src/compiler/FileGenerator.pv"
    if (Generator__is_coroutine(generator)) {
        #line 115 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_function_coroutine(&defs, header_file, func_info, generics);
    }

    #line 118 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, header_file, func_info, generics, 0)) {
        #line 119 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write function definition for %s\n", String__c_str(&name));
        #line 120 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 121 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 124 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 126 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 127 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 129 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 130 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 132 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 134 "src/compiler/FileGenerator.pv"
    return true;
}

#line 137 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum_loop(struct FileGenerator* self, struct TypeUsage_Enum* usage) {
    #line 138 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 139 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 139 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 139 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 140 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_enum(self, usage, usage_context) && success;
    } }
    #line 142 "src/compiler/FileGenerator.pv"
    return success;
}

#line 145 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum(struct FileGenerator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context) {
    #line 146 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 147 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 148 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 149 "src/compiler/FileGenerator.pv"
    struct Enum* enum_info = usage->type;
    #line 150 "src/compiler/FileGenerator.pv"
    struct Module* module = enum_info->context->module;
    #line 151 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, module);
    #line 152 "src/compiler/FileGenerator.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);
    #line 153 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 155 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 156 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 157 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 158 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 158 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 158 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 160 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 161 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 162 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 163 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 164 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 166 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 167 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 168 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 170 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_enum_definition(&defs, header_file, enum_info, usage, usage_context, &include_writer)) {
        #line 171 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write enum definition for %s\n", String__c_str(&name));
        #line 172 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 173 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 176 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 176 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 178 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 179 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 181 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 182 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 184 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(enum_info->impls.length, 0) && !usage->any_usage && !usage->impl_dynamic_usage) {
        #line 184 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 186 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 188 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 189 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 189 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 189 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 191 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 192 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 193 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 195 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 196 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 197 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 198 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 200 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 201 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for enum %s\n", String__c_str(&name));
        #line 202 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 203 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 206 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 207 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 208 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 211 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 212 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 214 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantInfo.h>\n");
        #line 215 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_EnumVariantInfo.h>\n");
        #line 216 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantParamInfo.h>\n");
        #line 217 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_EnumVariantParamInfo.h>\n");
        #line 218 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantKind.h>\n");
        #line 219 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_EnumVariantInfo ");
        #line 220 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 221 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants(void* __self) {\n");

        #line 223 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 224 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 225 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(void)__self;\n");

        #line 227 "src/compiler/FileGenerator.pv"
        uintptr_t variant_index = 0;
        #line 228 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 228 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 228 "src/compiler/FileGenerator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 229 "src/compiler/FileGenerator.pv"
            if (variant->types.length > 0) {
                #line 230 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 231 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "static struct EnumVariantParamInfo __params_%zu[] = { ", variant_index);

                #line 233 "src/compiler/FileGenerator.pv"
                uintptr_t param_index = 0;
                #line 234 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 234 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 234 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 235 "src/compiler/FileGenerator.pv"
                    if (param_index > 0) {
                        #line 235 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ", ");
                    }
                    #line 236 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(struct EnumVariantParamInfo){ .index = %zu, .name = ", param_index);

                    #line 238 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 239 "src/compiler/FileGenerator.pv"
                        struct str field_name = variant->names.data[param_index];
                        #line 240 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(struct str){ .ptr = \"");
                        #line 241 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, field_name);
                        #line 242 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "\", .length = %zu }", field_name.length);
                    } else {
                        #line 244 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(struct str){ .ptr = \"\", .length = 0 }");
                    }

                    #line 247 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ", .type_id = ");
                    #line 248 "src/compiler/FileGenerator.pv"
                    Generator__write_typeid(generator, code_file, type, generics);
                    #line 249 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ", .type_name = ");
                    #line 250 "src/compiler/FileGenerator.pv"
                    Generator__write_typename(generator, code_file, type, generics);
                    #line 251 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, " }");

                    #line 253 "src/compiler/FileGenerator.pv"
                    param_index += 1;
                } }

                #line 256 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " };\n");
            }
            #line 258 "src/compiler/FileGenerator.pv"
            variant_index += 1;
        } }

        #line 261 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 262 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct EnumVariantInfo variants[] = { ");

        #line 264 "src/compiler/FileGenerator.pv"
        variant_index = 0;
        #line 265 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 265 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 265 "src/compiler/FileGenerator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 266 "src/compiler/FileGenerator.pv"
            if (variant_index > 0) {
                #line 266 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 267 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct EnumVariantInfo){ .index = %zu, .key = (struct str){ .ptr = \"", variant_index);
            #line 268 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, variant->name);
            #line 269 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .label = (struct str){ .ptr = ", variant->name->value.length);
            #line 270 "src/compiler/FileGenerator.pv"
            if (variant->label != 0) {
                #line 271 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->label);
                #line 272 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .length = sizeof(");
                #line 273 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->label);
                #line 274 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ") - 1 }");
            } else {
                #line 276 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "\"");
                #line 277 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->name);
                #line 278 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "\", .length = %zu }", variant->name->value.length);
            }

            #line 281 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .kind = ");
            #line 282 "src/compiler/FileGenerator.pv"
            if (variant->names.length > 0) {
                #line 283 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__STRUCT");
            } else if (variant->types.length > 0) {
                #line 285 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__TUPLE");
            } else {
                #line 287 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__UNIT");
            }

            #line 290 "src/compiler/FileGenerator.pv"
            if (variant->types.length > 0) {
                #line 291 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .params = (struct slice_EnumVariantParamInfo){ .data = __params_%zu, .length = %zu }", variant_index, variant->types.length);
            } else {
                #line 293 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .params = (struct slice_EnumVariantParamInfo){ .data = 0, .length = 0 }");
            }

            #line 296 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 297 "src/compiler/FileGenerator.pv"
            variant_index += 1;
        } }

        #line 300 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 301 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 302 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_EnumVariantInfo){ .data = variants, .length = %zu };\n", enum_info->variants.length);
        #line 303 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 304 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 306 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "uintptr_t ");
        #line 307 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 308 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index(void* __self) {\n");

        #line 310 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 311 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 312 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 314 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 315 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 316 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 317 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 319 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 322 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 323 "src/compiler/FileGenerator.pv"
        if (is_discriminated_union) {
            #line 324 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)self->type;\n");
        } else {
            #line 326 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)*self;\n");
        }

        #line 329 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 330 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 332 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void ");
        #line 333 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 334 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_variant(void* __self, uintptr_t index) {\n");

        #line 336 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 337 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 338 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 340 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 341 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 342 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 343 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 345 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 348 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 349 "src/compiler/FileGenerator.pv"
        if (is_discriminated_union) {
            #line 350 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "self->type = index;\n");
        } else {
            #line 352 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*self = index;\n");
        }

        #line 355 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 356 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 358 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 359 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 360 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_param(void* __self, uintptr_t index) {\n");

        #line 362 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 364 "src/compiler/FileGenerator.pv"
        if (!is_discriminated_union) {
            #line 365 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 366 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(void)__self; (void)index;\n");
            #line 367 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 368 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return 0;\n");
        } else {
            #line 370 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 371 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

            #line 373 "src/compiler/FileGenerator.pv"
            if (module->mode_cpp) {
                #line 374 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = (");
                #line 375 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
                #line 376 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)__self;\n");
            } else {
                #line 378 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = __self;\n");
            }

            #line 381 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 382 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "switch (self->type) {\n");
            #line 383 "src/compiler/FileGenerator.pv"
            generator->indent += 1;

            #line 385 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 385 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 385 "src/compiler/FileGenerator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 386 "src/compiler/FileGenerator.pv"
                if (usize__Eq_usize__eq(variant->types.length, 0)) {
                    #line 386 "src/compiler/FileGenerator.pv"
                    continue;
                }

                #line 388 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 389 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case ");
                #line 390 "src/compiler/FileGenerator.pv"
                Generator__write_enum_variant_name(generator, code_file, generics->self_type, variant);
                #line 391 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ": switch (index) {\n");
                #line 392 "src/compiler/FileGenerator.pv"
                generator->indent += 1;

                #line 394 "src/compiler/FileGenerator.pv"
                uintptr_t i = 0;
                #line 395 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 395 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 395 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 396 "src/compiler/FileGenerator.pv"
                    Generator__write_indent(generator, code_file);
                    #line 397 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "case %zu: return ", i);

                    #line 399 "src/compiler/FileGenerator.pv"
                    if (!Generator__is_reference(type) || Type__is_fat_pointer(type)) {
                        #line 400 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "&");
                    }

                    #line 403 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "self->");
                    #line 404 "src/compiler/FileGenerator.pv"
                    Generator__write_str_lowercase(generator, code_file, variant->name->value);
                    #line 405 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "_value");

                    #line 407 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 408 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ".");
                        #line 409 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, variant->names.data[i]);
                    } else if (variant->types.length > 1) {
                        #line 411 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "._%zu", i);
                    }

                    #line 414 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ";\n");
                    #line 415 "src/compiler/FileGenerator.pv"
                    i += 1;
                } }

                #line 418 "src/compiler/FileGenerator.pv"
                generator->indent -= 1;
                #line 419 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 420 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "}\n");
                #line 421 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 422 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "break;\n");
            } }

            #line 425 "src/compiler/FileGenerator.pv"
            generator->indent -= 1;
            #line 426 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 427 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "}\n");

            #line 429 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 430 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return 0;\n");
        }

        #line 433 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 434 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 436 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 437 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 438 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_param(void* __self, uintptr_t index, void* value) {\n");

        #line 440 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 442 "src/compiler/FileGenerator.pv"
        if (!is_discriminated_union) {
            #line 443 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 444 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(void)__self; (void)index; (void)value;\n");
            #line 445 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 446 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return false;\n");
        } else {
            #line 448 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 449 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

            #line 451 "src/compiler/FileGenerator.pv"
            if (module->mode_cpp) {
                #line 452 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = (");
                #line 453 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
                #line 454 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)__self;\n");
            } else {
                #line 456 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = __self;\n");
            }

            #line 459 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 460 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "switch (self->type) {\n");
            #line 461 "src/compiler/FileGenerator.pv"
            generator->indent += 1;

            #line 463 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 463 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 463 "src/compiler/FileGenerator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 464 "src/compiler/FileGenerator.pv"
                if (usize__Eq_usize__eq(variant->types.length, 0)) {
                    #line 464 "src/compiler/FileGenerator.pv"
                    continue;
                }

                #line 466 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 467 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case ");
                #line 468 "src/compiler/FileGenerator.pv"
                Generator__write_enum_variant_name(generator, code_file, generics->self_type, variant);
                #line 469 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ": switch (index) {\n");
                #line 470 "src/compiler/FileGenerator.pv"
                generator->indent += 1;

                #line 472 "src/compiler/FileGenerator.pv"
                uintptr_t i = 0;
                #line 473 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 473 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 473 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 474 "src/compiler/FileGenerator.pv"
                    if (Type__is_sequence(type)) {
                        #line 475 "src/compiler/FileGenerator.pv"
                        i += 1;
                        #line 476 "src/compiler/FileGenerator.pv"
                        continue;
                    }

                    #line 479 "src/compiler/FileGenerator.pv"
                    Generator__write_indent(generator, code_file);
                    #line 480 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "case %zu: self->", i);
                    #line 481 "src/compiler/FileGenerator.pv"
                    Generator__write_str_lowercase(generator, code_file, variant->name->value);
                    #line 482 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "_value");

                    #line 484 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 485 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ".");
                        #line 486 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, variant->names.data[i]);
                    } else if (variant->types.length > 1) {
                        #line 488 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "._%zu", i);
                    }

                    #line 491 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, " = ");

                    #line 493 "src/compiler/FileGenerator.pv"
                    if (!Generator__is_reference(type) || Type__is_fat_pointer(type)) {
                        #line 494 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "*(");
                        #line 495 "src/compiler/FileGenerator.pv"
                        Generator__write_type(generator, code_file, type, generics);
                        #line 496 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "*)");
                    } else if (module->mode_cpp) {
                        #line 498 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(");
                        #line 499 "src/compiler/FileGenerator.pv"
                        Generator__write_type(generator, code_file, type, generics);
                        #line 500 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ")");
                    }

                    #line 503 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "value; return true;\n");
                    #line 504 "src/compiler/FileGenerator.pv"
                    i += 1;
                } }

                #line 507 "src/compiler/FileGenerator.pv"
                generator->indent -= 1;
                #line 508 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 509 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "}\n");
                #line 510 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 511 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "break;\n");
            } }

            #line 514 "src/compiler/FileGenerator.pv"
            generator->indent -= 1;
            #line 515 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 516 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "}\n");

            #line 518 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 519 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return false;\n");
        }

        #line 522 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 523 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 525 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_EnumVTable ");
        #line 526 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 527 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__ENUM");
        #line 528 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_variants = &");
        #line 529 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 530 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants, .fn_get_variant_index = &");
        #line 531 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 532 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index, .fn_set_variant = &");
        #line 533 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 534 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_variant, .fn_get_param = &");
        #line 535 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 536 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_param, .fn_set_param = &");
        #line 537 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 538 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_param };\n");
    }

    #line 541 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 542 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 544 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 546 "src/compiler/FileGenerator.pv"
    return true;
}

#line 549 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 550 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 551 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 551 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 551 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 552 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 554 "src/compiler/FileGenerator.pv"
    return success;
}

#line 557 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 558 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 559 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 560 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 561 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 562 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 563 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 564 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, module);
    #line 565 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 567 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 568 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 569 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 569 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 569 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 571 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 572 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 573 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 574 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 575 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 577 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 581 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 582 "src/compiler/FileGenerator.pv"
        Generator__write_includes_raw(generator, header_file, &struct_info->module->includes);
        #line 583 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (usage_context->cpp_usages.length > 0) {
        #line 585 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 587 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 587 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 587 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 587 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 588 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 589 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 589 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 590 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 591 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 593 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 596 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 600 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 602 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 602 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 602 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 603 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 606 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 609 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 610 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 611 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 611 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }
    #line 616 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 617 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 618 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 619 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 622 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 623 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write struct definition for %s\n", String__c_str(&name));

        #line 625 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 626 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 629 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 629 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 631 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 632 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 633 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 634 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 637 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 639 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 640 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 642 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(struct_info->impls.length, 0) && !usage->impl_dynamic_usage && !usage->any_usage) {
        #line 643 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 646 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 647 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 648 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 650 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 653 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, struct_info->module, String__as_str(&name), ext);

    #line 655 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 656 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 656 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 656 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 658 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 659 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &struct_info->module->includes);
    #line 660 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 662 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 663 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 664 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 665 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 667 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 668 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for struct %s\n", String__c_str(&name));
        #line 669 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 670 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 673 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 674 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 677 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 677 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 677 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 678 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 679 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 680 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 680 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 681 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 681 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 682 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 683 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, trait_entry._1, generics);
        #line 684 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 685 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 686 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 687 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 688 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 690 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 691 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 691 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 691 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 692 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 692 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 693 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 695 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 696 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 697 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 698 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 699 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 702 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 705 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 706 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 707 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 710 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 711 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 713 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructFieldInfo.h>\n");
        #line 714 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructFieldInfo.h>\n");
        #line 715 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructTraitInfo.h>\n");
        #line 716 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructTraitInfo.h>\n");

        #line 718 "src/compiler/FileGenerator.pv"
        struct Trait* struct_trait = 0;
        #line 719 "src/compiler/FileGenerator.pv"
        struct Namespace* std_namespace = Root__find_namespace(generator->root, (struct str){ .ptr = "std", .length = strlen("std") });
        #line 720 "src/compiler/FileGenerator.pv"
        if (std_namespace != 0) {
            #line 720 "src/compiler/FileGenerator.pv"
            struct_trait = Namespace__find_trait(std_namespace, (struct str){ .ptr = "Struct", .length = strlen("Struct") }, 0);
        }
        #line 721 "src/compiler/FileGenerator.pv"
        if (struct_trait == 0) {
            #line 722 "src/compiler/FileGenerator.pv"
            fprintf(stderr, "Missing std Struct trait for dynamic struct %s\n", String__c_str(&name));
            #line 723 "src/compiler/FileGenerator.pv"
            mem_file_close(code_file);
            #line 724 "src/compiler/FileGenerator.pv"
            return false;
        }

        #line 727 "src/compiler/FileGenerator.pv"
        Generator__write_extern(generator, code_file);
        #line 728 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 729 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 730 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT;\n");

        #line 732 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructTraitInfo ");
        #line 733 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 734 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_traits(void* __self) {\n");
        #line 735 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 736 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 737 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(void)__self;\n");
        #line 738 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 739 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructTraitInfo traits[] = { ");

        #line 741 "src/compiler/FileGenerator.pv"
        bool first_trait = true;
        #line 742 "src/compiler/FileGenerator.pv"
        uintptr_t trait_count = 1;
        #line 743 "src/compiler/FileGenerator.pv"
        struct Type struct_trait_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = struct_trait, ._1 = 0} };
        #line 744 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(struct StructTraitInfo){ .type_id = ");
        #line 745 "src/compiler/FileGenerator.pv"
        Generator__write_typeid(generator, code_file, &struct_trait_type, generics);
        #line 746 "src/compiler/FileGenerator.pv"
        fprintf(code_file, ", .vtable = (void*)&");
        #line 747 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 748 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT }");
        #line 749 "src/compiler/FileGenerator.pv"
        first_trait = false;

        #line 751 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
        #line 751 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
            #line 751 "src/compiler/FileGenerator.pv"
            struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

            #line 752 "src/compiler/FileGenerator.pv"
            struct Trait* trait_info = trait_entry._0;
            #line 753 "src/compiler/FileGenerator.pv"
            struct Token* trait_name = trait_info->name;
            #line 754 "src/compiler/FileGenerator.pv"
            if (trait_name == 0 || !Trait__has_dynamic_dispatch(trait_info)) {
                #line 754 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 755 "src/compiler/FileGenerator.pv"
            if (str__Eq_str__eq(trait_name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                #line 755 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 757 "src/compiler/FileGenerator.pv"
            if (!first_trait) {
                #line 757 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 758 "src/compiler/FileGenerator.pv"
            first_trait = false;
            #line 759 "src/compiler/FileGenerator.pv"
            trait_count += 1;
            #line 760 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructTraitInfo){ .type_id = ");
            #line 761 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, trait_entry._1, generics);
            #line 762 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .vtable = (void*)&");
            #line 763 "src/compiler/FileGenerator.pv"
            Generator__write_str_title(generator, code_file, String__as_str(&name));
            #line 764 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "__VTABLE__");
            #line 765 "src/compiler/FileGenerator.pv"
            Generator__write_str_title(generator, code_file, trait_name->value);
            #line 766 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
        } }

        #line 769 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 770 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 771 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructTraitInfo){ .data = traits, .length = %zu };\n", trait_count);
        #line 772 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 773 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n\n");

        #line 775 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructFieldInfo ");
        #line 776 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 777 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 779 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 780 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 781 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructFieldInfo fields[] = { ");

        #line 783 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 784 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 784 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 784 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 785 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 785 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 786 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructFieldInfo){ .index = %zu, .name = (struct str){ .ptr = \"", field_index);
            #line 787 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, field->name);
            #line 788 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .type_id = ", field->name->value.length);
            #line 789 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, &field->type, generics);
            #line 790 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .type_name = ");
            #line 791 "src/compiler/FileGenerator.pv"
            Generator__write_typename(generator, code_file, &field->type, generics);
            #line 792 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 793 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 796 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 797 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 798 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructFieldInfo){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 799 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 800 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 802 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 803 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 804 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 806 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 808 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 809 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 811 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 812 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 813 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 814 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 816 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 819 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 820 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 821 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 823 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 824 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 824 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 824 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 825 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 826 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 828 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 829 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 831 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 832 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 835 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 836 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
            }

            #line 839 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 840 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 843 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 844 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 845 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 847 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 848 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 850 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 851 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 853 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 854 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 855 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 857 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 859 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 860 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 862 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 863 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 864 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 865 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 867 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 870 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 871 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 872 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 874 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 875 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 875 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 875 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 876 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 876 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 878 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);

            #line 880 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 881 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 882 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, &field->type, generics);
                #line 883 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 885 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 886 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
                #line 887 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 889 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 890 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 891 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 892 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 894 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 895 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 896 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 900 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 901 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 904 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 905 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 906 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 908 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 909 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 911 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 912 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 914 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 915 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 916 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 917 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_fields = &");
        #line 918 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 919 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .fn_get_traits = &");
        #line 920 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 921 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_traits, .fn_get_field = &");
        #line 922 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 923 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .fn_set_field = &");
        #line 924 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 925 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 928 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 929 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 931 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 933 "src/compiler/FileGenerator.pv"
    return true;
}

#line 936 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_extern(struct FileGenerator* self, FILE* file, struct str name) {
    #line 937 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 938 "src/compiler/FileGenerator.pv"
    fprintf(file, "#include <std/trait_Any.h>\n");
    #line 939 "src/compiler/FileGenerator.pv"
    Generator__write_extern(generator, file);
    #line 940 "src/compiler/FileGenerator.pv"
    fprintf(file, "struct trait_AnyVTable ");
    #line 941 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 942 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 943 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 944 "src/compiler/FileGenerator.pv"
    fprintf(file, ";\n");
}

#line 947 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_definition(struct FileGenerator* self, FILE* file, struct str name, struct Type* self_type, struct GenericMap* generics) {
    #line 948 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 949 "src/compiler/FileGenerator.pv"
    fprintf(file, "\nuintptr_t ");
    #line 950 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 951 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size(void* __self) { (void)__self; return sizeof(");
    #line 952 "src/compiler/FileGenerator.pv"
    Generator__write_type(generator, file, self_type, generics);
    #line 953 "src/compiler/FileGenerator.pv"
    fprintf(file, "); }\n");

    #line 955 "src/compiler/FileGenerator.pv"
    fprintf(file, "struct trait_AnyVTable ");
    #line 956 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 957 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 958 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 959 "src/compiler/FileGenerator.pv"
    fprintf(file, " = { .fn_size = &");
    #line 960 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 961 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size };\n");
}

#line 964 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 965 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 966 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 966 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 966 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 967 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 969 "src/compiler/FileGenerator.pv"
    return success;
}

#line 972 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 973 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 974 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 975 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 976 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 977 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, 0, 0, 0);
    #line 978 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 979 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 981 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 982 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 983 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 983 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 983 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 985 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 986 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 987 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 988 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 989 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 991 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, header_file, &primitive_info->impls);
    #line 992 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 993 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 994 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 996 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 997 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write primitive definition for %.*s\n", (int32_t)(name.length), name.ptr);
        #line 998 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 999 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1002 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 1002 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, name);
    }

    #line 1004 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 1005 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1007 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1008 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1010 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(primitive_info->impls.length, 0)) {
        #line 1011 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1014 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 1016 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1017 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1017 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1017 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1019 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, code_file, &primitive_info->impls);
    #line 1020 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 1021 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 1023 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1024 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1025 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1026 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 1028 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 1029 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for primitive %.*s\n", (int32_t)(name.length), name.ptr);
        #line 1030 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 1031 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1034 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 1034 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 1034 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 1035 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 1036 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 1036 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1038 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 1039 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 1039 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1041 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 1041 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1043 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 1044 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, &impl_info->trait_type, generics);
        #line 1045 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 1046 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, name);
        #line 1047 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 1048 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 1049 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 1051 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 1052 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 1052 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 1052 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 1053 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 1053 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 1054 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 1056 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 1057 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 1058 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 1059 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 1060 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 1063 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 1066 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 1067 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 1068 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, name, generics->self_type, generics);
    }

    #line 1071 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1072 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1074 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1076 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1079 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 1080 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1081 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1081 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1081 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1082 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 1083 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 1084 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 1086 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 1089 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1092 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 1093 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1094 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1095 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1096 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;
    #line 1097 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, element_type, generics, 0);

    #line 1099 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 1100 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 1102 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 1103 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &sequence_type, &sequence_type, generics);
    #line 1104 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1106 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1107 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1108 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1108 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1108 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1110 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1111 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1112 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1113 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1114 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1116 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1117 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 1118 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 1120 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 1121 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 1122 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 1124 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 1125 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 1126 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &generator->root->type_usize, generics);

    #line 1128 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 1130 "src/compiler/FileGenerator.pv"
    struct TypeImpl* hack_type_impl = generator->root->hack_type_impl;
    #line 1131 "src/compiler/FileGenerator.pv"
    if (hack_type_impl == 0) {
        #line 1132 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing hack type impl in generate_slice\n");
        #line 1133 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1136 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), hack_type_impl->impl_info, generics);

    #line 1138 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 1139 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1141 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1142 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1144 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 1146 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1147 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1147 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1147 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1149 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1150 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1151 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1152 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 1154 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {hack_type_impl->impl_info};
    #line 1155 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };
    #line 1156 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };

    #line 1158 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 1159 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for slice %s\n", String__c_str(&name));
        #line 1160 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 1161 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1164 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1165 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1167 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1169 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1172 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 1173 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1174 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1174 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1174 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1175 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 1177 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1180 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 1181 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1182 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1183 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 1184 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 1185 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
    #line 1186 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, &tuple_type, generics, 0);

    #line 1188 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &tuple_type, &tuple_type, generics);
    #line 1189 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1191 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1192 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1193 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1193 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1193 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1195 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1196 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1197 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1198 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1199 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1201 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1202 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 1203 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 1205 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 1206 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 1207 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 1208 "src/compiler/FileGenerator.pv"
    generator->indent += 1;

    #line 1210 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 1210 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 1210 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 1210 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 1211 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1212 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 1213 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 1215 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, header_file);
        #line 1216 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(generator, header_file, String__as_str(&element_name), element, generics);
        #line 1217 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 1218 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 1221 "src/compiler/FileGenerator.pv"
    generator->indent -= 1;
    #line 1222 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 1224 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 1225 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1227 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1228 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1230 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1233 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 1234 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1235 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1235 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1235 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1236 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 1238 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1241 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl_loop(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage) {
    #line 1242 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1243 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1243 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1243 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1244 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_type_impl(self, usage, usage_context) && success;
    } }
    #line 1246 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1249 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage, struct UsageContext* usage_context) {
    #line 1250 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1251 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1252 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);
    #line 1253 "src/compiler/FileGenerator.pv"
    struct TypeImpl* type_impl = usage->type;
    #line 1254 "src/compiler/FileGenerator.pv"
    struct Impl* impl_info = type_impl->impl_info;
    #line 1255 "src/compiler/FileGenerator.pv"
    struct Context* context = impl_info->context;
    #line 1256 "src/compiler/FileGenerator.pv"
    struct Module* module = context->module;
    #line 1257 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1258 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, module);
    #line 1259 "src/compiler/FileGenerator.pv"
    struct Type* self_type = generics->self_type;
    #line 1260 "src/compiler/FileGenerator.pv"
    if (self_type == 0) {
        #line 1260 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1262 "src/compiler/FileGenerator.pv"
    struct Type* named_self_type = self_type;
    #line 1263 "src/compiler/FileGenerator.pv"
    if (Type__is_fat_pointer(self_type)) {
        #line 1264 "src/compiler/FileGenerator.pv"
        named_self_type = Type__deref_1(self_type);
        #line 1265 "src/compiler/FileGenerator.pv"
        if (named_self_type == 0) {
            #line 1265 "src/compiler/FileGenerator.pv"
            named_self_type = self_type;
        }
    }
    #line 1267 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, named_self_type, self_type, generics);

    #line 1269 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1273 "src/compiler/FileGenerator.pv"
    if (!HashSet_str__insert(&generator->type_impl_paths, String__as_str(&header))) {
        #line 1273 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1275 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = Array_ref_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
    #line 1276 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
    #line 1277 "src/compiler/FileGenerator.pv"
    struct Array_ref_UsageContext contexts = Array_ref_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
    #line 1278 "src/compiler/FileGenerator.pv"
    Array_ref_Impl__append(&impls, impl_info);
    #line 1279 "src/compiler/FileGenerator.pv"
    Array_HashMap_usize_TypeFunctionUsage__append(&impl_functions, usage_context->impl_functions.length > 0 ? usage_context->impl_functions.data[0] : HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }));
    #line 1280 "src/compiler/FileGenerator.pv"
    Array_ref_UsageContext__append(&contexts, usage_context);
    #line 1281 "src/compiler/FileGenerator.pv"
    if (generator->type_impl_usages != 0) {
        #line 1282 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_usize_TypeUsage_TypeImpl __iter = HashMap_usize_TypeUsage_TypeImpl__iter(&*generator->type_impl_usages);
        #line 1282 "src/compiler/FileGenerator.pv"
        while (HashMapIter_usize_TypeUsage_TypeImpl__next(&__iter)) {
            #line 1282 "src/compiler/FileGenerator.pv"
            struct TypeUsage_TypeImpl* other = &HashMapIter_usize_TypeUsage_TypeImpl__value(&__iter)->_1;

            #line 1283 "src/compiler/FileGenerator.pv"
            if (usize__Eq_usize__eq((uintptr_t)(other->type), (uintptr_t)(type_impl)) || usize__Eq_usize__eq(other->usage_contexts.length, 0)) {
                #line 1283 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 1284 "src/compiler/FileGenerator.pv"
            struct Impl* other_impl = other->type->impl_info;
            #line 1285 "src/compiler/FileGenerator.pv"
            if ((uintptr_t)(other_impl->context->module) != (uintptr_t)(module)) {
                #line 1285 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 1286 "src/compiler/FileGenerator.pv"
            if (!Root__type_impl_target_eq(generator->root, &other->type->type, &type_impl->type)) {
                #line 1286 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 1287 "src/compiler/FileGenerator.pv"
            struct UsageContext* other_context = &other->usage_contexts.data[0];
            #line 1288 "src/compiler/FileGenerator.pv"
            Array_ref_Impl__append(&impls, other_impl);
            #line 1289 "src/compiler/FileGenerator.pv"
            Array_HashMap_usize_TypeFunctionUsage__append(&impl_functions, other_context->impl_functions.length > 0 ? other_context->impl_functions.data[0] : HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }));
            #line 1290 "src/compiler/FileGenerator.pv"
            Array_ref_UsageContext__append(&contexts, other_context);
        } }
    }

    #line 1294 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1295 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1295 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1295 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1297 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1298 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1299 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1300 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1301 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1303 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_UsageContext __iter = Array_ref_UsageContext__iter(&contexts);
    #line 1303 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_UsageContext__next(&__iter)) {
        #line 1303 "src/compiler/FileGenerator.pv"
        struct UsageContext* impl_context = *Iter_ref_ref_UsageContext__value(&__iter);

        #line 1304 "src/compiler/FileGenerator.pv"
        Generator__write_context_primitives(generator, header_file, &impl_context->primitive_header, 0);
        #line 1305 "src/compiler/FileGenerator.pv"
        IncludeWriter__write(&include_writer, header_file, generator, &impl_context->signature, generics, false);
    } }
    #line 1307 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);
    #line 1308 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&impls);
    #line 1308 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 1308 "src/compiler/FileGenerator.pv"
        struct Impl* each_impl = *Iter_ref_ref_Impl__value(&__iter);

        #line 1309 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), each_impl, generics);
    } }
    #line 1311 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);

    #line 1313 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1315 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1316 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1318 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 1319 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1320 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1320 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1320 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1322 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_UsageContext __iter = Array_ref_UsageContext__iter(&contexts);
    #line 1322 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_UsageContext__next(&__iter)) {
        #line 1322 "src/compiler/FileGenerator.pv"
        struct UsageContext* impl_context = *Iter_ref_ref_UsageContext__value(&__iter);

        #line 1323 "src/compiler/FileGenerator.pv"
        Generator__write_context_primitives(generator, code_file, &impl_context->primitive_code, &impl_context->primitive_header);
    } }
    #line 1325 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 1326 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_UsageContext __iter = Array_ref_UsageContext__iter(&contexts);
    #line 1326 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_UsageContext__next(&__iter)) {
        #line 1326 "src/compiler/FileGenerator.pv"
        struct UsageContext* impl_context = *Iter_ref_ref_UsageContext__value(&__iter);

        #line 1327 "src/compiler/FileGenerator.pv"
        IncludeWriter__write(&include_writer, code_file, generator, &impl_context->body, generics, true);
    } }

    #line 1330 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &impls, &impl_functions, generics, &include_writer)) {
        #line 1331 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for type %s\n", String__c_str(&name));
        #line 1332 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 1333 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1336 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1337 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1339 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1341 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1344 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 1345 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1346 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1347 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1348 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;
    #line 1349 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, trait_info->module);

    #line 1351 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 1351 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1353 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 1354 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1355 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1357 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1358 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1358 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1358 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1360 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1361 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1362 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1363 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1364 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1366 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1367 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 1370 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1371 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 1372 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 1373 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 1376 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 1376 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 1376 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1378 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1379 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 1380 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 1381 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 1384 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1386 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1387 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1389 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1392 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 1393 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1394 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 1394 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1396 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;
    #line 1397 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, 0, 0, global->module);

    #line 1399 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(generator->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 1400 "src/compiler/FileGenerator.pv"
    if (blank_generics == 0) {
        #line 1401 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing blank generics in generate_global\n");
        #line 1402 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 1404 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, generator->allocator);

    #line 1406 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(generator->allocator);
    #line 1407 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_ctx;

    #line 1409 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(generator->allocator);
    #line 1410 "src/compiler/FileGenerator.pv"
    #line 1411 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(generator, &global->type, blank_generics, &primitive_includes);

    #line 1413 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1414 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1415 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1415 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1415 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1417 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1418 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1419 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1420 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1421 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1423 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 1423 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1423 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 1424 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 1427 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n");
    #line 1428 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);
    #line 1429 "src/compiler/FileGenerator.pv"
    Generator__write_extern(generator, header_file);
    #line 1430 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "");
    #line 1431 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1431 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 1432 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, name, &global->type, blank_generics);
    #line 1433 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");
    #line 1434 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);

    #line 1436 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1438 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1439 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1441 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 1442 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1443 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1443 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1443 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1445 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &global->module->includes);

    #line 1447 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 1448 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1449 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1450 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 1452 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1452 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 1453 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, code_file, name, &global->type, blank_generics);
    #line 1454 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 1455 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 1456 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, code_file, global->value, blank_generics);
    }
    #line 1458 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 1460 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1461 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1463 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1465 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 1467 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 1470 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1471 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1471 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1471 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1472 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1472 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1472 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1473 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 1473 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 1473 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 1474 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 1478 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 1482 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 1483 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1485 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1485 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1485 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1486 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1486 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1486 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 1486 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1487 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 1487 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 1487 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 1488 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 1489 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 1490 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 1492 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(generator, module, test_info->func_name, (struct str){ .ptr = ".test.h", .length = strlen(".test.h") });
                #line 1493 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 1495 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(generator, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 1496 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 1500 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 1504 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1505 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1506 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 1508 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1509 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1510 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1511 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 1513 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 1515 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(func_names.length, 0)) {
        #line 1515 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1517 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1518 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = generator->path, .length = strlen(generator->path) });
    #line 1519 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/main.test.c", .length = strlen("/main.test.c") });

    #line 1521 "src/compiler/FileGenerator.pv"
    FILE* runner_file = mem_file_open();
    #line 1522 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 1522 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1524 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n\n");

    #line 1526 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 1527 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 1528 "src/compiler/FileGenerator.pv"
        struct str hp = header_paths.data[i];
        #line 1529 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 1530 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, hp);
        #line 1531 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 1532 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1535 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\nint main(void) {\n");
    #line 1536 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int passed = 0;\n");
    #line 1537 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int failed = 0;\n\n");

    #line 1539 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 1540 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 1541 "src/compiler/FileGenerator.pv"
        struct str desc = descriptions.data[i];
        #line 1542 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 1543 "src/compiler/FileGenerator.pv"
        struct str module_path = module_paths.data[i];

        #line 1545 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    fputs(\"[TEST] ");
        #line 1546 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, module_path);
        #line 1547 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 1548 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, desc);
        #line 1549 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\\n\", stdout);\n");
        #line 1550 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    ");
        #line 1551 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 1552 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "();\n");
        #line 1553 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    passed++;\n\n");

        #line 1555 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1558 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    printf(\"[RESULT] %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 1559 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    return failed > 0 ? 1 : 0;\n");
    #line 1560 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "}\n");

    #line 1562 "src/compiler/FileGenerator.pv"
    mem_file_save(runner_file, String__c_str(&runner_path));
    #line 1563 "src/compiler/FileGenerator.pv"
    mem_file_close(runner_file);

    #line 1565 "src/compiler/FileGenerator.pv"
    generator->current_host = true;
    #line 1566 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, runner_path);
}

#line 1569 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 1570 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1572 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1572 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1572 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 1572 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1573 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1574 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 1575 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 1576 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 1577 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 1579 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
