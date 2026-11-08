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

    #line 59 "src/compiler/FileGenerator.pv"
    struct Context* context = func_info->context;
    #line 60 "src/compiler/FileGenerator.pv"
    if (context == 0) {
        #line 61 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing function context in generate_function\n");
        #line 62 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 64 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, context->module);

    #line 66 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, context->module, name_str, code_ext);
    #line 67 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();

    #line 69 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 69 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 69 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 71 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 72 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &context->module->includes);
    #line 73 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 75 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, context->module, name_str, header_ext);
    #line 76 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 77 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 78 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 80 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, code_file, func_info, generics, 0)) {
        #line 81 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write function definition for %s\n", String__c_str(&name));
        #line 82 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 83 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 86 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_function_block(&defs, code_file, name_str, func_info, generics, usage_context);

    #line 88 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 89 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 91 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 93 "src/compiler/FileGenerator.pv"
    include_writer = IncludeWriter__new(generator->allocator);

    #line 95 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, context->module, name_str, header_ext);
    #line 96 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();

    #line 98 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 98 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 98 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 100 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 101 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 102 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 103 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 104 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 106 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_code, 0);
    #line 107 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 108 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 110 "src/compiler/FileGenerator.pv"
    if (Generator__is_coroutine(generator)) {
        #line 111 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_function_coroutine(&defs, header_file, func_info, generics);
    }

    #line 114 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, header_file, func_info, generics, 0)) {
        #line 115 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write function definition for %s\n", String__c_str(&name));
        #line 116 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 117 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 120 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 122 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 123 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 125 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 126 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 128 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 130 "src/compiler/FileGenerator.pv"
    return true;
}

#line 133 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum_loop(struct FileGenerator* self, struct TypeUsage_Enum* usage) {
    #line 134 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 135 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 135 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 135 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 136 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_enum(self, usage, usage_context) && success;
    } }
    #line 138 "src/compiler/FileGenerator.pv"
    return success;
}

#line 141 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum(struct FileGenerator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context) {
    #line 142 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 143 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 144 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 145 "src/compiler/FileGenerator.pv"
    struct Enum* enum_info = usage->type;
    #line 146 "src/compiler/FileGenerator.pv"
    struct Module* module = enum_info->context->module;
    #line 147 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, module);
    #line 148 "src/compiler/FileGenerator.pv"
    bool is_discriminated_union = Enum__is_discriminated_union(enum_info);
    #line 149 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 151 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 152 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 153 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 154 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 154 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 154 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 156 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 157 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 158 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 159 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 160 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 162 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 163 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 164 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 166 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_enum_definition(&defs, header_file, enum_info, usage, usage_context, &include_writer)) {
        #line 167 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write enum definition for %s\n", String__c_str(&name));
        #line 168 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 169 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 172 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 172 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 174 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 175 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 177 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 178 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 180 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(enum_info->impls.length, 0) && !usage->any_usage && !usage->impl_dynamic_usage) {
        #line 180 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 182 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 184 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 185 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 185 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 185 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 187 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 188 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 189 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 191 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 192 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 193 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 194 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 196 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 197 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for enum %s\n", String__c_str(&name));
        #line 198 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 199 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 202 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 203 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 204 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 207 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 208 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 210 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantInfo.h>\n");
        #line 211 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_EnumVariantInfo.h>\n");
        #line 212 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantParamInfo.h>\n");
        #line 213 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_EnumVariantParamInfo.h>\n");
        #line 214 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/EnumVariantKind.h>\n");
        #line 215 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_EnumVariantInfo ");
        #line 216 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 217 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants(void* __self) {\n");

        #line 219 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 220 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 221 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(void)__self;\n");

        #line 223 "src/compiler/FileGenerator.pv"
        uintptr_t variant_index = 0;
        #line 224 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 224 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 224 "src/compiler/FileGenerator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 225 "src/compiler/FileGenerator.pv"
            if (variant->types.length > 0) {
                #line 226 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 227 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "static struct EnumVariantParamInfo __params_%zu[] = { ", variant_index);

                #line 229 "src/compiler/FileGenerator.pv"
                uintptr_t param_index = 0;
                #line 230 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 230 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 230 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 231 "src/compiler/FileGenerator.pv"
                    if (param_index > 0) {
                        #line 231 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ", ");
                    }
                    #line 232 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(struct EnumVariantParamInfo){ .index = %zu, .name = ", param_index);

                    #line 234 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 235 "src/compiler/FileGenerator.pv"
                        struct str field_name = variant->names.data[param_index];
                        #line 236 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(struct str){ .ptr = \"");
                        #line 237 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, field_name);
                        #line 238 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "\", .length = %zu }", field_name.length);
                    } else {
                        #line 240 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(struct str){ .ptr = \"\", .length = 0 }");
                    }

                    #line 243 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ", .type_id = ");
                    #line 244 "src/compiler/FileGenerator.pv"
                    Generator__write_typeid(generator, code_file, type, generics);
                    #line 245 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ", .type_name = ");
                    #line 246 "src/compiler/FileGenerator.pv"
                    Generator__write_typename(generator, code_file, type, generics);
                    #line 247 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, " }");

                    #line 249 "src/compiler/FileGenerator.pv"
                    param_index += 1;
                } }

                #line 252 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " };\n");
            }
            #line 254 "src/compiler/FileGenerator.pv"
            variant_index += 1;
        } }

        #line 257 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 258 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct EnumVariantInfo variants[] = { ");

        #line 260 "src/compiler/FileGenerator.pv"
        variant_index = 0;
        #line 261 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
        #line 261 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_EnumVariant__next(&__iter)) {
            #line 261 "src/compiler/FileGenerator.pv"
            struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

            #line 262 "src/compiler/FileGenerator.pv"
            if (variant_index > 0) {
                #line 262 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 263 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct EnumVariantInfo){ .index = %zu, .key = (struct str){ .ptr = \"", variant_index);
            #line 264 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, variant->name);
            #line 265 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .label = (struct str){ .ptr = ", variant->name->value.length);
            #line 266 "src/compiler/FileGenerator.pv"
            if (variant->label != 0) {
                #line 267 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->label);
                #line 268 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .length = sizeof(");
                #line 269 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->label);
                #line 270 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ") - 1 }");
            } else {
                #line 272 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "\"");
                #line 273 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, variant->name);
                #line 274 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "\", .length = %zu }", variant->name->value.length);
            }

            #line 277 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .kind = ");
            #line 278 "src/compiler/FileGenerator.pv"
            if (variant->names.length > 0) {
                #line 279 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__STRUCT");
            } else if (variant->types.length > 0) {
                #line 281 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__TUPLE");
            } else {
                #line 283 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "ENUM_VARIANT_KIND__UNIT");
            }

            #line 286 "src/compiler/FileGenerator.pv"
            if (variant->types.length > 0) {
                #line 287 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .params = (struct slice_EnumVariantParamInfo){ .data = __params_%zu, .length = %zu }", variant_index, variant->types.length);
            } else {
                #line 289 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", .params = (struct slice_EnumVariantParamInfo){ .data = 0, .length = 0 }");
            }

            #line 292 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 293 "src/compiler/FileGenerator.pv"
            variant_index += 1;
        } }

        #line 296 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 297 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 298 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_EnumVariantInfo){ .data = variants, .length = %zu };\n", enum_info->variants.length);
        #line 299 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 300 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 302 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "uintptr_t ");
        #line 303 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 304 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index(void* __self) {\n");

        #line 306 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 307 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 308 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 310 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 311 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 312 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 313 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 315 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 318 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 319 "src/compiler/FileGenerator.pv"
        if (is_discriminated_union) {
            #line 320 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)self->type;\n");
        } else {
            #line 322 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return (uintptr_t)*self;\n");
        }

        #line 325 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 326 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 328 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void ");
        #line 329 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 330 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_variant(void* __self, uintptr_t index) {\n");

        #line 332 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 333 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 334 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 336 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 337 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 338 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 339 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 341 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 344 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 345 "src/compiler/FileGenerator.pv"
        if (is_discriminated_union) {
            #line 346 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "self->type = index;\n");
        } else {
            #line 348 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*self = index;\n");
        }

        #line 351 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 352 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 354 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 355 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 356 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_param(void* __self, uintptr_t index) {\n");

        #line 358 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 360 "src/compiler/FileGenerator.pv"
        if (!is_discriminated_union) {
            #line 361 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 362 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(void)__self; (void)index;\n");
            #line 363 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 364 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return 0;\n");
        } else {
            #line 366 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 367 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

            #line 369 "src/compiler/FileGenerator.pv"
            if (module->mode_cpp) {
                #line 370 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = (");
                #line 371 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
                #line 372 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)__self;\n");
            } else {
                #line 374 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = __self;\n");
            }

            #line 377 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 378 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "switch (self->type) {\n");
            #line 379 "src/compiler/FileGenerator.pv"
            generator->indent += 1;

            #line 381 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 381 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 381 "src/compiler/FileGenerator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 382 "src/compiler/FileGenerator.pv"
                if (usize__Eq_usize__eq(variant->types.length, 0)) {
                    #line 382 "src/compiler/FileGenerator.pv"
                    continue;
                }

                #line 384 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 385 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case ");
                #line 386 "src/compiler/FileGenerator.pv"
                Generator__write_enum_variant_name(generator, code_file, generics->self_type, variant);
                #line 387 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ": switch (index) {\n");
                #line 388 "src/compiler/FileGenerator.pv"
                generator->indent += 1;

                #line 390 "src/compiler/FileGenerator.pv"
                uintptr_t i = 0;
                #line 391 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 391 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 391 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 392 "src/compiler/FileGenerator.pv"
                    Generator__write_indent(generator, code_file);
                    #line 393 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "case %zu: return ", i);

                    #line 395 "src/compiler/FileGenerator.pv"
                    if (!Generator__is_reference(type) || Type__is_fat_pointer(type)) {
                        #line 396 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "&");
                    }

                    #line 399 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "self->");
                    #line 400 "src/compiler/FileGenerator.pv"
                    Generator__write_str_lowercase(generator, code_file, variant->name->value);
                    #line 401 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "_value");

                    #line 403 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 404 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ".");
                        #line 405 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, variant->names.data[i]);
                    } else if (variant->types.length > 1) {
                        #line 407 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "._%zu", i);
                    }

                    #line 410 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ";\n");
                    #line 411 "src/compiler/FileGenerator.pv"
                    i += 1;
                } }

                #line 414 "src/compiler/FileGenerator.pv"
                generator->indent -= 1;
                #line 415 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 416 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "}\n");
                #line 417 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 418 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "break;\n");
            } }

            #line 421 "src/compiler/FileGenerator.pv"
            generator->indent -= 1;
            #line 422 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 423 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "}\n");

            #line 425 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 426 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return 0;\n");
        }

        #line 429 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 430 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 432 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 433 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 434 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_param(void* __self, uintptr_t index, void* value) {\n");

        #line 436 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 438 "src/compiler/FileGenerator.pv"
        if (!is_discriminated_union) {
            #line 439 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 440 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(void)__self; (void)index; (void)value;\n");
            #line 441 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 442 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return false;\n");
        } else {
            #line 444 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 445 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

            #line 447 "src/compiler/FileGenerator.pv"
            if (module->mode_cpp) {
                #line 448 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = (");
                #line 449 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
                #line 450 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)__self;\n");
            } else {
                #line 452 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "* self = __self;\n");
            }

            #line 455 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 456 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "switch (self->type) {\n");
            #line 457 "src/compiler/FileGenerator.pv"
            generator->indent += 1;

            #line 459 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_EnumVariant __iter = HashMap_str_EnumVariant__iter(&enum_info->variants);
            #line 459 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_EnumVariant__next(&__iter)) {
                #line 459 "src/compiler/FileGenerator.pv"
                struct EnumVariant* variant = &HashMapIter_str_EnumVariant__value(&__iter)->_1;

                #line 460 "src/compiler/FileGenerator.pv"
                if (usize__Eq_usize__eq(variant->types.length, 0)) {
                    #line 460 "src/compiler/FileGenerator.pv"
                    continue;
                }

                #line 462 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 463 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case ");
                #line 464 "src/compiler/FileGenerator.pv"
                Generator__write_enum_variant_name(generator, code_file, generics->self_type, variant);
                #line 465 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ": switch (index) {\n");
                #line 466 "src/compiler/FileGenerator.pv"
                generator->indent += 1;

                #line 468 "src/compiler/FileGenerator.pv"
                uintptr_t i = 0;
                #line 469 "src/compiler/FileGenerator.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&variant->types);
                #line 469 "src/compiler/FileGenerator.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 469 "src/compiler/FileGenerator.pv"
                    struct Type* type = Iter_ref_Type__value(&__iter);

                    #line 470 "src/compiler/FileGenerator.pv"
                    if (Type__is_sequence(type)) {
                        #line 471 "src/compiler/FileGenerator.pv"
                        i += 1;
                        #line 472 "src/compiler/FileGenerator.pv"
                        continue;
                    }

                    #line 475 "src/compiler/FileGenerator.pv"
                    Generator__write_indent(generator, code_file);
                    #line 476 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "case %zu: self->", i);
                    #line 477 "src/compiler/FileGenerator.pv"
                    Generator__write_str_lowercase(generator, code_file, variant->name->value);
                    #line 478 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "_value");

                    #line 480 "src/compiler/FileGenerator.pv"
                    if (variant->names.length > 0) {
                        #line 481 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ".");
                        #line 482 "src/compiler/FileGenerator.pv"
                        Generator__write_str(generator, code_file, variant->names.data[i]);
                    } else if (variant->types.length > 1) {
                        #line 484 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "._%zu", i);
                    }

                    #line 487 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, " = ");

                    #line 489 "src/compiler/FileGenerator.pv"
                    if (!Generator__is_reference(type) || Type__is_fat_pointer(type)) {
                        #line 490 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "*(");
                        #line 491 "src/compiler/FileGenerator.pv"
                        Generator__write_type(generator, code_file, type, generics);
                        #line 492 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "*)");
                    } else if (module->mode_cpp) {
                        #line 494 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, "(");
                        #line 495 "src/compiler/FileGenerator.pv"
                        Generator__write_type(generator, code_file, type, generics);
                        #line 496 "src/compiler/FileGenerator.pv"
                        fprintf(code_file, ")");
                    }

                    #line 499 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "value; return true;\n");
                    #line 500 "src/compiler/FileGenerator.pv"
                    i += 1;
                } }

                #line 503 "src/compiler/FileGenerator.pv"
                generator->indent -= 1;
                #line 504 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 505 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "}\n");
                #line 506 "src/compiler/FileGenerator.pv"
                Generator__write_indent(generator, code_file);
                #line 507 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "break;\n");
            } }

            #line 510 "src/compiler/FileGenerator.pv"
            generator->indent -= 1;
            #line 511 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 512 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "}\n");

            #line 514 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 515 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "return false;\n");
        }

        #line 518 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 519 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 521 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_EnumVTable ");
        #line 522 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 523 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__ENUM");
        #line 524 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_variants = &");
        #line 525 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 526 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variants, .fn_get_variant_index = &");
        #line 527 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 528 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_variant_index, .fn_set_variant = &");
        #line 529 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 530 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_variant, .fn_get_param = &");
        #line 531 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 532 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__get_param, .fn_set_param = &");
        #line 533 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 534 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Enum__set_param };\n");
    }

    #line 537 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 538 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 540 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 542 "src/compiler/FileGenerator.pv"
    return true;
}

#line 545 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 546 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 547 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 547 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 547 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 548 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 550 "src/compiler/FileGenerator.pv"
    return success;
}

#line 553 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 554 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 555 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 556 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 557 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 558 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 559 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 560 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, module);
    #line 561 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 563 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 564 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 565 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 565 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 565 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 567 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 568 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 569 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 570 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 571 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 573 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 577 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 578 "src/compiler/FileGenerator.pv"
        Generator__write_includes_raw(generator, header_file, &struct_info->module->includes);
        #line 579 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (usage_context->cpp_usages.length > 0) {
        #line 581 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 583 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 583 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 583 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 583 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 584 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 585 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 585 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 586 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 587 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 589 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 592 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 596 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 598 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 598 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 598 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 599 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 602 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 605 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 606 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 607 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 607 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }
    #line 612 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 613 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 614 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 615 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 618 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 619 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write struct definition for %s\n", String__c_str(&name));

        #line 621 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 622 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 625 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 625 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 627 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 628 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 629 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 630 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 633 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 635 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 636 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 638 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(struct_info->impls.length, 0) && !usage->impl_dynamic_usage && !usage->any_usage) {
        #line 639 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 642 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 643 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 644 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 646 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 649 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, struct_info->module, String__as_str(&name), ext);

    #line 651 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 652 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 652 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 652 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 654 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 655 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &struct_info->module->includes);
    #line 656 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 658 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 659 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 660 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 661 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 663 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 664 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for struct %s\n", String__c_str(&name));
        #line 665 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 666 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 669 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 670 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 673 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 673 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 673 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 674 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 675 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 676 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 676 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 677 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 677 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 678 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 679 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, trait_entry._1, generics);
        #line 680 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 681 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 682 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 683 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 684 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 686 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 687 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 687 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 687 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 688 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 688 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 689 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 691 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 692 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 693 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 694 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 695 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 698 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 701 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 702 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 703 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 706 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 707 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 709 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructFieldInfo.h>\n");
        #line 710 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructFieldInfo.h>\n");
        #line 711 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructTraitInfo.h>\n");
        #line 712 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructTraitInfo.h>\n");

        #line 714 "src/compiler/FileGenerator.pv"
        struct Trait* struct_trait = 0;
        #line 715 "src/compiler/FileGenerator.pv"
        struct Namespace* std_namespace = Root__find_namespace(generator->root, (struct str){ .ptr = "std", .length = strlen("std") });
        #line 716 "src/compiler/FileGenerator.pv"
        if (std_namespace != 0) {
            #line 716 "src/compiler/FileGenerator.pv"
            struct_trait = Namespace__find_trait(std_namespace, (struct str){ .ptr = "Struct", .length = strlen("Struct") }, 0);
        }
        #line 717 "src/compiler/FileGenerator.pv"
        if (struct_trait == 0) {
            #line 718 "src/compiler/FileGenerator.pv"
            fprintf(stderr, "Missing std Struct trait for dynamic struct %s\n", String__c_str(&name));
            #line 719 "src/compiler/FileGenerator.pv"
            mem_file_close(code_file);
            #line 720 "src/compiler/FileGenerator.pv"
            return false;
        }

        #line 723 "src/compiler/FileGenerator.pv"
        Generator__write_extern(generator, code_file);
        #line 724 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 725 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 726 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT;\n");

        #line 728 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructTraitInfo ");
        #line 729 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 730 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_traits(void* __self) {\n");
        #line 731 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 732 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 733 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(void)__self;\n");
        #line 734 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 735 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructTraitInfo traits[] = { ");

        #line 737 "src/compiler/FileGenerator.pv"
        bool first_trait = true;
        #line 738 "src/compiler/FileGenerator.pv"
        uintptr_t trait_count = 1;
        #line 739 "src/compiler/FileGenerator.pv"
        struct Type struct_trait_type = (struct Type) { .type = TYPE__TRAIT, .trait_value = { ._0 = struct_trait, ._1 = 0} };
        #line 740 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "(struct StructTraitInfo){ .type_id = ");
        #line 741 "src/compiler/FileGenerator.pv"
        Generator__write_typeid(generator, code_file, &struct_trait_type, generics);
        #line 742 "src/compiler/FileGenerator.pv"
        fprintf(code_file, ", .vtable = (void*)&");
        #line 743 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 744 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT }");
        #line 745 "src/compiler/FileGenerator.pv"
        first_trait = false;

        #line 747 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
        #line 747 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
            #line 747 "src/compiler/FileGenerator.pv"
            struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

            #line 748 "src/compiler/FileGenerator.pv"
            struct Trait* trait_info = trait_entry._0;
            #line 749 "src/compiler/FileGenerator.pv"
            struct Token* trait_name = trait_info->name;
            #line 750 "src/compiler/FileGenerator.pv"
            if (trait_name == 0 || !Trait__has_dynamic_dispatch(trait_info)) {
                #line 750 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 751 "src/compiler/FileGenerator.pv"
            if (str__Eq_str__eq(trait_name->value, (struct str){ .ptr = "Struct", .length = strlen("Struct") })) {
                #line 751 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 753 "src/compiler/FileGenerator.pv"
            if (!first_trait) {
                #line 753 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 754 "src/compiler/FileGenerator.pv"
            first_trait = false;
            #line 755 "src/compiler/FileGenerator.pv"
            trait_count += 1;
            #line 756 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructTraitInfo){ .type_id = ");
            #line 757 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, trait_entry._1, generics);
            #line 758 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .vtable = (void*)&");
            #line 759 "src/compiler/FileGenerator.pv"
            Generator__write_str_title(generator, code_file, String__as_str(&name));
            #line 760 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "__VTABLE__");
            #line 761 "src/compiler/FileGenerator.pv"
            Generator__write_str_title(generator, code_file, trait_name->value);
            #line 762 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
        } }

        #line 765 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 766 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 767 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructTraitInfo){ .data = traits, .length = %zu };\n", trait_count);
        #line 768 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 769 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n\n");

        #line 771 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructFieldInfo ");
        #line 772 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 773 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 775 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 776 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 777 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructFieldInfo fields[] = { ");

        #line 779 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 780 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 780 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 780 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 781 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 781 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 782 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructFieldInfo){ .index = %zu, .name = (struct str){ .ptr = \"", field_index);
            #line 783 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, field->name);
            #line 784 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .type_id = ", field->name->value.length);
            #line 785 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, &field->type, generics);
            #line 786 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .type_name = ");
            #line 787 "src/compiler/FileGenerator.pv"
            Generator__write_typename(generator, code_file, &field->type, generics);
            #line 788 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 789 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 792 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 793 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 794 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructFieldInfo){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 795 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 796 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 798 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 799 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 800 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 802 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 804 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 805 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 807 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 808 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 809 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 810 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 812 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 815 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 816 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 817 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 819 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 820 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 820 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 820 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 821 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 822 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 824 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 825 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 827 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 828 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 831 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 832 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
            }

            #line 835 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 836 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 839 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 840 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 841 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 843 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 844 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 846 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 847 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 849 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 850 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 851 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 853 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 855 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 856 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 858 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 859 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 860 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 861 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 863 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 866 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 867 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 868 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 870 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 871 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 871 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 871 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 872 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 872 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 874 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);

            #line 876 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 877 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 878 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, &field->type, generics);
                #line 879 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 881 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 882 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
                #line 883 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 885 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 886 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 887 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 888 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 890 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 891 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 892 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 896 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 897 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 900 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 901 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 902 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 904 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 905 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 907 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 908 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 910 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 911 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 912 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 913 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_fields = &");
        #line 914 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 915 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .fn_get_traits = &");
        #line 916 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 917 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_traits, .fn_get_field = &");
        #line 918 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 919 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .fn_set_field = &");
        #line 920 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 921 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 924 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 925 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 927 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 929 "src/compiler/FileGenerator.pv"
    return true;
}

#line 932 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_extern(struct FileGenerator* self, FILE* file, struct str name) {
    #line 933 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 934 "src/compiler/FileGenerator.pv"
    fprintf(file, "#include <std/trait_Any.h>\n");
    #line 935 "src/compiler/FileGenerator.pv"
    Generator__write_extern(generator, file);
    #line 936 "src/compiler/FileGenerator.pv"
    fprintf(file, "struct trait_AnyVTable ");
    #line 937 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 938 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 939 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 940 "src/compiler/FileGenerator.pv"
    fprintf(file, ";\n");
}

#line 943 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_definition(struct FileGenerator* self, FILE* file, struct str name, struct Type* self_type, struct GenericMap* generics) {
    #line 944 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 945 "src/compiler/FileGenerator.pv"
    fprintf(file, "\nuintptr_t ");
    #line 946 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 947 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size(void* __self) { (void)__self; return sizeof(");
    #line 948 "src/compiler/FileGenerator.pv"
    Generator__write_type(generator, file, self_type, generics);
    #line 949 "src/compiler/FileGenerator.pv"
    fprintf(file, "); }\n");

    #line 951 "src/compiler/FileGenerator.pv"
    fprintf(file, "struct trait_AnyVTable ");
    #line 952 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 953 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 954 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 955 "src/compiler/FileGenerator.pv"
    fprintf(file, " = { .fn_size = &");
    #line 956 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 957 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size };\n");
}

#line 960 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 961 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 962 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 962 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 962 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 963 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 965 "src/compiler/FileGenerator.pv"
    return success;
}

#line 968 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 969 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 970 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 971 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 972 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 973 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, 0, 0, 0);
    #line 974 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 975 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 977 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 978 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 979 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 979 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 979 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 981 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 982 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 983 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 984 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 985 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 987 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, header_file, &primitive_info->impls);
    #line 988 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 989 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 990 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 992 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 993 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write primitive definition for %.*s\n", (int32_t)(name.length), name.ptr);
        #line 994 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 995 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 998 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 998 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, name);
    }

    #line 1000 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 1001 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1003 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1004 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1006 "src/compiler/FileGenerator.pv"
    if (usize__Eq_usize__eq(primitive_info->impls.length, 0)) {
        #line 1007 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1010 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 1012 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1013 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1013 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1013 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1015 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, code_file, &primitive_info->impls);
    #line 1016 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 1017 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 1019 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1020 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1021 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1022 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 1024 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 1025 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for primitive %.*s\n", (int32_t)(name.length), name.ptr);
        #line 1026 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 1027 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1030 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 1030 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 1030 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 1031 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 1032 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 1032 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1034 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 1035 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 1035 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1037 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 1037 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 1039 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 1040 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, &impl_info->trait_type, generics);
        #line 1041 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 1042 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, name);
        #line 1043 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 1044 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 1045 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 1047 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 1048 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 1048 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 1048 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 1049 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 1049 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 1050 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 1052 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 1053 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 1054 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 1055 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 1056 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 1059 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 1062 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 1063 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 1064 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, name, generics->self_type, generics);
    }

    #line 1067 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1068 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1070 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1072 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1075 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 1076 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1077 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1077 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1077 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1078 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 1079 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 1080 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 1082 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 1085 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1088 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 1089 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1090 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1091 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1092 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;
    #line 1093 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, element_type, generics, 0);

    #line 1095 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 1096 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 1098 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 1099 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &sequence_type, &sequence_type, generics);
    #line 1100 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1102 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1103 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1104 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1104 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1104 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1106 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1107 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1108 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1109 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1110 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1112 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1113 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 1114 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 1116 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 1117 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 1118 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 1120 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 1121 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 1122 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &generator->root->type_usize, generics);

    #line 1124 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 1126 "src/compiler/FileGenerator.pv"
    struct TypeImpl* hack_type_impl = generator->root->hack_type_impl;
    #line 1127 "src/compiler/FileGenerator.pv"
    if (hack_type_impl == 0) {
        #line 1128 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing hack type impl in generate_slice\n");
        #line 1129 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1132 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), hack_type_impl->impl_info, generics);

    #line 1134 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 1135 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1137 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1138 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1140 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 1142 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1143 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1143 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1143 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1145 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1146 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1147 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1148 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 1150 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {hack_type_impl->impl_info};
    #line 1151 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };
    #line 1152 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };

    #line 1154 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 1155 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for slice %s\n", String__c_str(&name));
        #line 1156 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 1157 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1160 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1161 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1163 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1165 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1168 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 1169 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1170 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1170 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1170 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1171 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 1173 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1176 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 1177 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1178 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1179 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 1180 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 1181 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };
    #line 1182 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, &tuple_type, generics, 0);

    #line 1184 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &tuple_type, &tuple_type, generics);
    #line 1185 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1187 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1188 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1189 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1189 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1189 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1191 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1192 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1193 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1194 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1195 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1197 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1198 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 1199 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);

    #line 1201 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 1202 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 1203 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 1204 "src/compiler/FileGenerator.pv"
    generator->indent += 1;

    #line 1206 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 1206 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 1206 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 1206 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 1207 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1208 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 1209 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 1211 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, header_file);
        #line 1212 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(generator, header_file, String__as_str(&element_name), element, generics);
        #line 1213 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 1214 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 1217 "src/compiler/FileGenerator.pv"
    generator->indent -= 1;
    #line 1218 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 1220 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);
    #line 1221 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1223 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1224 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1226 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1229 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 1230 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1231 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1231 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1231 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1232 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 1234 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1237 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl_loop(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage) {
    #line 1238 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 1239 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 1239 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 1239 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 1240 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_type_impl(self, usage, usage_context) && success;
    } }
    #line 1242 "src/compiler/FileGenerator.pv"
    return success;
}

#line 1245 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage, struct UsageContext* usage_context) {
    #line 1246 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1247 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1248 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);
    #line 1249 "src/compiler/FileGenerator.pv"
    struct TypeImpl* type_impl = usage->type;
    #line 1250 "src/compiler/FileGenerator.pv"
    struct Impl* impl_info = type_impl->impl_info;
    #line 1251 "src/compiler/FileGenerator.pv"
    struct Context* context = impl_info->context;
    #line 1252 "src/compiler/FileGenerator.pv"
    struct Module* module = context->module;
    #line 1253 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1254 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, module);
    #line 1255 "src/compiler/FileGenerator.pv"
    struct Type* self_type = generics->self_type;
    #line 1256 "src/compiler/FileGenerator.pv"
    if (self_type == 0) {
        #line 1256 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1258 "src/compiler/FileGenerator.pv"
    struct Type* named_self_type = self_type;
    #line 1259 "src/compiler/FileGenerator.pv"
    if (Type__is_fat_pointer(self_type)) {
        #line 1260 "src/compiler/FileGenerator.pv"
        named_self_type = Type__deref_1(self_type);
        #line 1261 "src/compiler/FileGenerator.pv"
        if (named_self_type == 0) {
            #line 1261 "src/compiler/FileGenerator.pv"
            named_self_type = self_type;
        }
    }
    #line 1263 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, named_self_type, self_type, generics);

    #line 1265 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1269 "src/compiler/FileGenerator.pv"
    if (!HashSet_str__insert(&generator->type_impl_paths, String__as_str(&header))) {
        #line 1269 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1271 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = Array_ref_Impl__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
    #line 1272 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = Array_HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
    #line 1273 "src/compiler/FileGenerator.pv"
    struct Array_ref_UsageContext contexts = Array_ref_UsageContext__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
    #line 1274 "src/compiler/FileGenerator.pv"
    Array_ref_Impl__append(&impls, impl_info);
    #line 1275 "src/compiler/FileGenerator.pv"
    Array_HashMap_usize_TypeFunctionUsage__append(&impl_functions, usage_context->impl_functions.length > 0 ? usage_context->impl_functions.data[0] : HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }));
    #line 1276 "src/compiler/FileGenerator.pv"
    Array_ref_UsageContext__append(&contexts, usage_context);
    #line 1277 "src/compiler/FileGenerator.pv"
    if (generator->type_impl_usages != 0) {
        #line 1278 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_usize_TypeUsage_TypeImpl __iter = HashMap_usize_TypeUsage_TypeImpl__iter(&*generator->type_impl_usages);
        #line 1278 "src/compiler/FileGenerator.pv"
        while (HashMapIter_usize_TypeUsage_TypeImpl__next(&__iter)) {
            #line 1278 "src/compiler/FileGenerator.pv"
            struct TypeUsage_TypeImpl* other = &HashMapIter_usize_TypeUsage_TypeImpl__value(&__iter)->_1;

            #line 1279 "src/compiler/FileGenerator.pv"
            if (usize__Eq_usize__eq((uintptr_t)(other->type), (uintptr_t)(type_impl)) || usize__Eq_usize__eq(other->usage_contexts.length, 0)) {
                #line 1279 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 1280 "src/compiler/FileGenerator.pv"
            struct Impl* other_impl = other->type->impl_info;
            #line 1281 "src/compiler/FileGenerator.pv"
            if ((uintptr_t)(other_impl->context->module) != (uintptr_t)(module)) {
                #line 1281 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 1282 "src/compiler/FileGenerator.pv"
            if (!Root__type_impl_target_eq(generator->root, &other->type->type, &type_impl->type)) {
                #line 1282 "src/compiler/FileGenerator.pv"
                continue;
            }
            #line 1283 "src/compiler/FileGenerator.pv"
            struct UsageContext* other_context = &other->usage_contexts.data[0];
            #line 1284 "src/compiler/FileGenerator.pv"
            Array_ref_Impl__append(&impls, other_impl);
            #line 1285 "src/compiler/FileGenerator.pv"
            Array_HashMap_usize_TypeFunctionUsage__append(&impl_functions, other_context->impl_functions.length > 0 ? other_context->impl_functions.data[0] : HashMap_usize_TypeFunctionUsage__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }));
            #line 1286 "src/compiler/FileGenerator.pv"
            Array_ref_UsageContext__append(&contexts, other_context);
        } }
    }

    #line 1290 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1291 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1291 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1291 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1293 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1294 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1295 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1296 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1297 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1299 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_UsageContext __iter = Array_ref_UsageContext__iter(&contexts);
    #line 1299 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_UsageContext__next(&__iter)) {
        #line 1299 "src/compiler/FileGenerator.pv"
        struct UsageContext* impl_context = *Iter_ref_ref_UsageContext__value(&__iter);

        #line 1300 "src/compiler/FileGenerator.pv"
        Generator__write_context_primitives(generator, header_file, &impl_context->primitive_header, 0);
        #line 1301 "src/compiler/FileGenerator.pv"
        IncludeWriter__write(&include_writer, header_file, generator, &impl_context->signature, generics, false);
    } }
    #line 1303 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);
    #line 1304 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&impls);
    #line 1304 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 1304 "src/compiler/FileGenerator.pv"
        struct Impl* each_impl = *Iter_ref_ref_Impl__value(&__iter);

        #line 1305 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), each_impl, generics);
    } }
    #line 1307 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);

    #line 1309 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1311 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1312 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1314 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 1315 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1316 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1316 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1316 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1318 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_UsageContext __iter = Array_ref_UsageContext__iter(&contexts);
    #line 1318 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_UsageContext__next(&__iter)) {
        #line 1318 "src/compiler/FileGenerator.pv"
        struct UsageContext* impl_context = *Iter_ref_ref_UsageContext__value(&__iter);

        #line 1319 "src/compiler/FileGenerator.pv"
        Generator__write_context_primitives(generator, code_file, &impl_context->primitive_code, &impl_context->primitive_header);
    } }
    #line 1321 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 1322 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_UsageContext __iter = Array_ref_UsageContext__iter(&contexts);
    #line 1322 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_UsageContext__next(&__iter)) {
        #line 1322 "src/compiler/FileGenerator.pv"
        struct UsageContext* impl_context = *Iter_ref_ref_UsageContext__value(&__iter);

        #line 1323 "src/compiler/FileGenerator.pv"
        IncludeWriter__write(&include_writer, code_file, generator, &impl_context->body, generics, true);
    } }

    #line 1326 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &impls, &impl_functions, generics, &include_writer)) {
        #line 1327 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for type %s\n", String__c_str(&name));
        #line 1328 "src/compiler/FileGenerator.pv"
        mem_file_close(code_file);
        #line 1329 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1332 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1333 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1335 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1337 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1340 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 1341 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1342 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 1343 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 1344 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;
    #line 1345 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, generics->self_type, generics, trait_info->module);

    #line 1347 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 1347 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1349 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 1350 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1351 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 1353 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1354 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1354 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1354 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1356 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1357 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1358 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1359 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 1360 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1362 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 1363 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);
    #line 1366 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1367 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 1368 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 1369 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 1372 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 1372 "src/compiler/FileGenerator.pv"
        mem_file_close(header_file);
        #line 1372 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 1374 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 1375 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 1376 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 1377 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 1380 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1382 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1383 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1385 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1388 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 1389 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1390 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 1390 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 1392 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;
    #line 1393 "src/compiler/FileGenerator.pv"
    Generator__begin_file(generator, 0, 0, global->module);

    #line 1395 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(generator->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 1396 "src/compiler/FileGenerator.pv"
    if (blank_generics == 0) {
        #line 1397 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing blank generics in generate_global\n");
        #line 1398 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 1400 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, generator->allocator);

    #line 1402 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(generator->allocator);
    #line 1403 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_ctx;

    #line 1405 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(generator->allocator);
    #line 1406 "src/compiler/FileGenerator.pv"
    #line 1407 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(generator, &global->type, blank_generics, &primitive_includes);

    #line 1409 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 1410 "src/compiler/FileGenerator.pv"
    FILE* header_file = mem_file_open();
    #line 1411 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 1411 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 1411 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1413 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 1414 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1415 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 1416 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 1417 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 1419 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 1419 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 1419 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 1420 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 1423 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n");
    #line 1424 "src/compiler/FileGenerator.pv"
    FileGenerator__open_c_linkage(self, header_file);
    #line 1425 "src/compiler/FileGenerator.pv"
    Generator__write_extern(generator, header_file);
    #line 1426 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "");
    #line 1427 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1427 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 1428 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, name, &global->type, blank_generics);
    #line 1429 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");
    #line 1430 "src/compiler/FileGenerator.pv"
    FileGenerator__close_c_linkage(self, header_file);

    #line 1432 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 1434 "src/compiler/FileGenerator.pv"
    mem_file_save(header_file, String__c_str(&header));
    #line 1435 "src/compiler/FileGenerator.pv"
    mem_file_close(header_file);

    #line 1437 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 1438 "src/compiler/FileGenerator.pv"
    FILE* code_file = mem_file_open();
    #line 1439 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 1439 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 1439 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 1441 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &global->module->includes);

    #line 1443 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 1444 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 1445 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 1446 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 1448 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 1448 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 1449 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, code_file, name, &global->type, blank_generics);
    #line 1450 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 1451 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 1452 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, code_file, global->value, blank_generics);
    }
    #line 1454 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 1456 "src/compiler/FileGenerator.pv"
    mem_file_save(code_file, String__c_str(&code));
    #line 1457 "src/compiler/FileGenerator.pv"
    mem_file_close(code_file);

    #line 1459 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, code);

    #line 1461 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 1463 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 1466 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1467 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1467 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1467 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1468 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1468 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1468 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1469 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 1469 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 1469 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 1470 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 1474 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 1478 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 1479 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1481 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1481 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1481 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1482 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 1482 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 1482 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 1482 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 1483 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 1483 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 1483 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 1484 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 1485 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 1486 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 1488 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(generator, module, test_info->func_name, (struct str){ .ptr = ".h", .length = strlen(".h") });
                #line 1489 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 1491 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(generator, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 1492 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 1496 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 1501 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 1502 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 1503 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 1505 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1506 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1507 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1508 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 1510 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 1512 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1513 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = generator->path, .length = strlen(generator->path) });
    #line 1514 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/pave_test_main.c", .length = strlen("/pave_test_main.c") });

    #line 1516 "src/compiler/FileGenerator.pv"
    FILE* runner_file = mem_file_open();
    #line 1517 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 1517 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&runner_path));
        #line 1517 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 1520 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#if defined(__linux__) && !defined(_DEFAULT_SOURCE)\n");
    #line 1521 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#define _DEFAULT_SOURCE\n");
    #line 1522 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#endif\n");
    #line 1523 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdint.h>\n");
    #line 1524 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n");
    #line 1525 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdlib.h>\n");
    #line 1526 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <string.h>\n");
    #line 1527 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#if defined(_WIN32)\n");
    #line 1528 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#define WIN32_LEAN_AND_MEAN\n");
    #line 1529 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <windows.h>\n");
    #line 1530 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <process.h>\n");
    #line 1531 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#else\n");
    #line 1532 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <sys/types.h>\n");
    #line 1533 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <sys/wait.h>\n");
    #line 1534 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <unistd.h>\n");
    #line 1535 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#endif\n\n");

    #line 1537 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 1538 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 1539 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 1540 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, header_paths.data[i]);
        #line 1541 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 1542 "src/compiler/FileGenerator.pv"
        i += 1;
    }
    #line 1547 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\ntypedef struct { const char* id; const char* name; void (*fn)(void); } PaveTest;\n\n");
    #line 1548 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "static const PaveTest pave_tests[] = {\n");
    #line 1549 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 1550 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 1551 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 1552 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    { \"");
        #line 1553 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 1554 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\", \"");
        #line 1555 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, module_paths.data[i]);
        #line 1556 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 1557 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, descriptions.data[i]);
        #line 1558 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\", ");
        #line 1559 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 1560 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, " },\n");
        #line 1561 "src/compiler/FileGenerator.pv"
        i += 1;
    }
    #line 1563 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    { 0, 0, 0 }\n");
    #line 1564 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "};\n");
    #line 1565 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "static const int pave_test_count = (int)(sizeof(pave_tests) / sizeof(pave_tests[0])) - 1;\n\n");

    #line 1567 "src/compiler/FileGenerator.pv"
    FileGenerator__write_test_runner_main(self, runner_file);

    #line 1569 "src/compiler/FileGenerator.pv"
    mem_file_save(runner_file, String__c_str(&runner_path));
    #line 1570 "src/compiler/FileGenerator.pv"
    mem_file_close(runner_file);

    #line 1572 "src/compiler/FileGenerator.pv"
    generator->current_host = true;
    #line 1573 "src/compiler/FileGenerator.pv"
    Generator__add_code_file(generator, runner_path);
    #line 1574 "src/compiler/FileGenerator.pv"
    return true;
}

#line 1583 "src/compiler/FileGenerator.pv"
void FileGenerator__write_test_runner_main(struct FileGenerator* self, FILE* file) {
    #line 1584 "src/compiler/FileGenerator.pv"
    fprintf(file, "static int pave_test_matches(const PaveTest* test, int exact, int argc, char** argv) {\n");
    #line 1585 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int i;\n");
    #line 1586 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int filters = 0;\n");
    #line 1587 "src/compiler/FileGenerator.pv"
    fprintf(file, "    for (i = 1; i < argc; i++) {\n");
    #line 1588 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (argv[i] == NULL) continue;\n");
    #line 1589 "src/compiler/FileGenerator.pv"
    fprintf(file, "        filters++;\n");
    #line 1590 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (exact) {\n");
    #line 1591 "src/compiler/FileGenerator.pv"
    fprintf(file, "            if (strcmp(test->id, argv[i]) == 0 || strcmp(test->name, argv[i]) == 0) return 1;\n");
    #line 1592 "src/compiler/FileGenerator.pv"
    fprintf(file, "        } else if (strstr(test->name, argv[i]) != NULL) {\n");
    #line 1593 "src/compiler/FileGenerator.pv"
    fprintf(file, "            return 1;\n");
    #line 1594 "src/compiler/FileGenerator.pv"
    fprintf(file, "        }\n");
    #line 1595 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n");
    #line 1596 "src/compiler/FileGenerator.pv"
    fprintf(file, "    return filters == 0;\n");
    #line 1597 "src/compiler/FileGenerator.pv"
    fprintf(file, "}\n\n");
    #line 1600 "src/compiler/FileGenerator.pv"
    fprintf(file, "static void pave_test_print_name(const char* name) {\n");
    #line 1601 "src/compiler/FileGenerator.pv"
    fprintf(file, "    for (; *name; name++) {\n");
    #line 1602 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (*name == '#') putchar('\\\\');\n");
    #line 1603 "src/compiler/FileGenerator.pv"
    fprintf(file, "        putchar(*name);\n");
    #line 1604 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n");
    #line 1605 "src/compiler/FileGenerator.pv"
    fprintf(file, "}\n\n");

    #line 1607 "src/compiler/FileGenerator.pv"
    fprintf(file, "static int pave_test_isolated(int index, char* reason, size_t reason_size) {\n");
    #line 1608 "src/compiler/FileGenerator.pv"
    fprintf(file, "    fflush(stdout);\n");
    #line 1609 "src/compiler/FileGenerator.pv"
    fprintf(file, "    fflush(stderr);\n");
    #line 1610 "src/compiler/FileGenerator.pv"
    fprintf(file, "#if defined(_WIN32)\n");
    #line 1611 "src/compiler/FileGenerator.pv"
    fprintf(file, "    {\n");
    #line 1612 "src/compiler/FileGenerator.pv"
    fprintf(file, "        char path[MAX_PATH];\n");
    #line 1613 "src/compiler/FileGenerator.pv"
    fprintf(file, "        char index_arg[16];\n");
    #line 1614 "src/compiler/FileGenerator.pv"
    fprintf(file, "        intptr_t status;\n");
    #line 1615 "src/compiler/FileGenerator.pv"
    fprintf(file, "        DWORD length = GetModuleFileNameA(NULL, path, MAX_PATH);\n");
    #line 1616 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (length == 0 || length >= MAX_PATH) { snprintf(reason, reason_size, \"could not find the test executable\"); return 1; }\n");
    #line 1617 "src/compiler/FileGenerator.pv"
    fprintf(file, "        snprintf(index_arg, sizeof(index_arg), \"%%d\", index);\n");
    #line 1618 "src/compiler/FileGenerator.pv"
    fprintf(file, "        status = _spawnl(_P_WAIT, path, \"pave-test\", \"--run-one\", index_arg, NULL);\n");
    #line 1619 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (status == -1) { snprintf(reason, reason_size, \"could not start the test process\"); return 1; }\n");
    #line 1620 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (status == 0) return 0;\n");
    #line 1621 "src/compiler/FileGenerator.pv"
    fprintf(file, "        snprintf(reason, reason_size, \"exit code %%ld (0x%%08lx)\", (long)status, (unsigned long)status);\n");
    #line 1622 "src/compiler/FileGenerator.pv"
    fprintf(file, "        return 1;\n");
    #line 1623 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n");
    #line 1624 "src/compiler/FileGenerator.pv"
    fprintf(file, "#else\n");
    #line 1625 "src/compiler/FileGenerator.pv"
    fprintf(file, "    {\n");
    #line 1626 "src/compiler/FileGenerator.pv"
    fprintf(file, "        int status = 0;\n");
    #line 1627 "src/compiler/FileGenerator.pv"
    fprintf(file, "        pid_t pid = fork();\n");
    #line 1628 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (pid < 0) { snprintf(reason, reason_size, \"could not start the test process\"); return 1; }\n");
    #line 1629 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (pid == 0) {\n");
    #line 1630 "src/compiler/FileGenerator.pv"
    fprintf(file, "            pave_tests[index].fn();\n");
    #line 1631 "src/compiler/FileGenerator.pv"
    fprintf(file, "            fflush(stdout);\n");
    #line 1632 "src/compiler/FileGenerator.pv"
    fprintf(file, "            fflush(stderr);\n");
    #line 1633 "src/compiler/FileGenerator.pv"
    fprintf(file, "            _exit(0);\n");
    #line 1634 "src/compiler/FileGenerator.pv"
    fprintf(file, "        }\n");
    #line 1635 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (waitpid(pid, &status, 0) < 0) { snprintf(reason, reason_size, \"could not wait for the test process\"); return 1; }\n");
    #line 1636 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) return 0;\n");
    #line 1637 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (WIFSIGNALED(status)) snprintf(reason, reason_size, \"signal %%d\", WTERMSIG(status));\n");
    #line 1638 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else snprintf(reason, reason_size, \"exit code %%d\", WEXITSTATUS(status));\n");
    #line 1639 "src/compiler/FileGenerator.pv"
    fprintf(file, "        return 1;\n");
    #line 1640 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n");
    #line 1641 "src/compiler/FileGenerator.pv"
    fprintf(file, "#endif\n");
    #line 1642 "src/compiler/FileGenerator.pv"
    fprintf(file, "}\n\n");

    #line 1644 "src/compiler/FileGenerator.pv"
    fprintf(file, "int main(int argc, char** argv) {\n");
    #line 1645 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int i;\n");
    #line 1646 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int exact = 0;\n");
    #line 1647 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int list = 0;\n");
    #line 1648 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int in_process = 0;\n");
    #line 1649 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int run_one = -1;\n");
    #line 1650 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int selected = 0;\n");
    #line 1651 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int filtered = 0;\n");
    #line 1652 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int number = 0;\n");
    #line 1653 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int passed = 0;\n");
    #line 1654 "src/compiler/FileGenerator.pv"
    fprintf(file, "    int failed = 0;\n\n");
    #line 1655 "src/compiler/FileGenerator.pv"
    fprintf(file, "    for (i = 1; i < argc; i++) {\n");
    #line 1656 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (strcmp(argv[i], \"--run-one\") == 0 && i + 1 < argc) { run_one = atoi(argv[i + 1]); argv[i] = NULL; argv[++i] = NULL; }\n");
    #line 1657 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else if (strcmp(argv[i], \"--exact\") == 0) { exact = 1; argv[i] = NULL; }\n");
    #line 1658 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else if (strcmp(argv[i], \"--list\") == 0) { list = 1; argv[i] = NULL; }\n");
    #line 1659 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else if (strcmp(argv[i], \"--in-process\") == 0) { in_process = 1; argv[i] = NULL; }\n");
    #line 1660 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else if (strcmp(argv[i], \"--help\") == 0) {\n");
    #line 1661 "src/compiler/FileGenerator.pv"
    fprintf(file, "            printf(\"usage: %%s [--exact] [--list] [--in-process] [filter...]\\n\", argv[0]);\n");
    #line 1662 "src/compiler/FileGenerator.pv"
    fprintf(file, "            return 0;\n");
    #line 1663 "src/compiler/FileGenerator.pv"
    fprintf(file, "        }\n");
    #line 1664 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else filtered = 1;\n");
    #line 1665 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n\n");

    #line 1667 "src/compiler/FileGenerator.pv"
    fprintf(file, "    if (run_one >= 0) {\n");
    #line 1668 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (run_one >= pave_test_count) return 2;\n");
    #line 1669 "src/compiler/FileGenerator.pv"
    fprintf(file, "#if defined(_MSC_VER)\n");
    #line 1670 "src/compiler/FileGenerator.pv"
    fprintf(file, "        _set_abort_behavior(0, _CALL_REPORTFAULT);\n");
    #line 1671 "src/compiler/FileGenerator.pv"
    fprintf(file, "#endif\n");
    #line 1672 "src/compiler/FileGenerator.pv"
    fprintf(file, "        pave_tests[run_one].fn();\n");
    #line 1673 "src/compiler/FileGenerator.pv"
    fprintf(file, "        return 0;\n");
    #line 1674 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n\n");

    #line 1676 "src/compiler/FileGenerator.pv"
    fprintf(file, "    for (i = 0; i < pave_test_count; i++) {\n");
    #line 1677 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (!pave_test_matches(&pave_tests[i], exact, argc, argv)) continue;\n");
    #line 1678 "src/compiler/FileGenerator.pv"
    fprintf(file, "        selected++;\n");
    #line 1679 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (list) printf(\"%%s\\t%%s\\n\", pave_tests[i].id, pave_tests[i].name);\n");
    #line 1680 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n");
    #line 1681 "src/compiler/FileGenerator.pv"
    fprintf(file, "    if (list) return 0;\n\n");

    #line 1683 "src/compiler/FileGenerator.pv"
    fprintf(file, "#if defined(_WIN32)\n");
    #line 1684 "src/compiler/FileGenerator.pv"
    fprintf(file, "    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);\n");
    #line 1685 "src/compiler/FileGenerator.pv"
    fprintf(file, "#endif\n");
    #line 1686 "src/compiler/FileGenerator.pv"
    fprintf(file, "    printf(\"TAP version 13\\n1..%%d\\n\", selected);\n");
    #line 1687 "src/compiler/FileGenerator.pv"
    fprintf(file, "    for (i = 0; i < pave_test_count; i++) {\n");
    #line 1688 "src/compiler/FileGenerator.pv"
    fprintf(file, "        char reason[128];\n");
    #line 1689 "src/compiler/FileGenerator.pv"
    fprintf(file, "        int result = 0;\n");
    #line 1690 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (!pave_test_matches(&pave_tests[i], exact, argc, argv)) continue;\n");
    #line 1691 "src/compiler/FileGenerator.pv"
    fprintf(file, "        number++;\n");
    #line 1692 "src/compiler/FileGenerator.pv"
    fprintf(file, "        reason[0] = 0;\n");
    #line 1693 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (in_process) pave_tests[i].fn();\n");
    #line 1694 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else result = pave_test_isolated(i, reason, sizeof(reason));\n");
    #line 1695 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (result == 0) { passed++; printf(\"ok %%d - \", number); }\n");
    #line 1696 "src/compiler/FileGenerator.pv"
    fprintf(file, "        else { failed++; printf(\"not ok %%d - \", number); }\n");
    #line 1697 "src/compiler/FileGenerator.pv"
    fprintf(file, "        pave_test_print_name(pave_tests[i].name);\n");
    #line 1698 "src/compiler/FileGenerator.pv"
    fprintf(file, "        putchar('\\n');\n");
    #line 1699 "src/compiler/FileGenerator.pv"
    fprintf(file, "        if (result != 0) printf(\"# %%s\\n\", reason);\n");
    #line 1700 "src/compiler/FileGenerator.pv"
    fprintf(file, "        fflush(stdout);\n");
    #line 1701 "src/compiler/FileGenerator.pv"
    fprintf(file, "    }\n\n");

    #line 1703 "src/compiler/FileGenerator.pv"
    fprintf(file, "    printf(\"# %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 1704 "src/compiler/FileGenerator.pv"
    fprintf(file, "    if (filtered && selected == 0) { printf(\"# no tests matched\\n\"); return 1; }\n");
    #line 1705 "src/compiler/FileGenerator.pv"
    fprintf(file, "    return failed > 0 ? 1 : 0;\n");
    #line 1706 "src/compiler/FileGenerator.pv"
    fprintf(file, "}\n");
}

#line 1709 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 1710 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1712 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1712 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1712 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 1712 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1713 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1714 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 1715 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 1716 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 1717 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 1719 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
