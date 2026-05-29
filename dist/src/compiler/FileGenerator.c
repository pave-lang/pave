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
#include <analyzer/Token.h>
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
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 145 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 146 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 147 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 148 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 149 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 149 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 149 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 151 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 152 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 153 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 154 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 155 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 157 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 158 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 160 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_enum_definition(&defs, header_file, enum_info, usage, usage_context, &include_writer)) {
        #line 161 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write enum definition for %s\n", String__c_str(&name));
        #line 162 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 163 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 166 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 166 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 168 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 170 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 171 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 172 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 174 "src/compiler/FileGenerator.pv"
    if (enum_info->impls.length == 0 && !usage->any_usage) {
        #line 174 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 176 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 178 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 179 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 180 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 180 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 180 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 182 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 183 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 184 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 186 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 187 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 188 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 189 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 191 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 192 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for enum %s\n", String__c_str(&name));
        #line 193 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 194 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 197 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 198 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 199 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 202 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 203 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 204 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 206 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 208 "src/compiler/FileGenerator.pv"
    return true;
}

#line 211 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 212 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 213 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 213 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 213 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 214 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 216 "src/compiler/FileGenerator.pv"
    return success;
}

#line 219 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 220 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 221 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 222 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 223 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 224 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 225 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 226 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 228 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 229 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 230 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 231 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 231 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 231 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 233 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 234 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 235 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 236 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 237 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 239 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 240 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 242 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 242 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 242 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 242 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 243 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 244 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 244 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 245 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 246 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 248 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 251 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 255 "src/compiler/FileGenerator.pv"
        if (struct_info->module->mode_cpp) {
            #line 256 "src/compiler/FileGenerator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 256 "src/compiler/FileGenerator.pv"
                fprintf(header_file, "\n");
            }
            #line 257 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 260 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 262 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 262 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 262 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 263 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 266 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (generator->root->mode_cpp) {
        #line 268 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 269 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 270 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 273 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 274 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 275 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 275 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }

    #line 277 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 278 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write struct definition for %s\n", String__c_str(&name));

        #line 280 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 281 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 284 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 284 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, String__as_str(&name));
    }

    #line 286 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 287 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 288 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 289 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 292 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 294 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 295 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 296 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 298 "src/compiler/FileGenerator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage && !usage->any_usage) {
        #line 299 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 302 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 303 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 304 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 306 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 309 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, struct_info->module, String__as_str(&name), ext);

    #line 311 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 312 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 313 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 313 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 313 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 315 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 316 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &struct_info->module->includes);
    #line 317 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 319 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 320 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 321 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 322 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 324 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 325 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for struct %s\n", String__c_str(&name));
        #line 326 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 327 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 330 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 331 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 334 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 334 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 334 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 335 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 336 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 337 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 337 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 338 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 338 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 339 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 340 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, trait_entry._1, generics);
        #line 341 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 342 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 343 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 344 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 345 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 347 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 348 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 348 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 348 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 349 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 349 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 350 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 352 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 353 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 354 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 355 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 356 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 359 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 362 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 363 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 364 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, String__as_str(&name), generics->self_type, generics);
    }

    #line 367 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 368 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 370 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/StructFieldInfo.h>\n");
        #line 371 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_StructFieldInfo.h>\n");
        #line 372 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_StructFieldInfo ");
        #line 373 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 374 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 376 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 377 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 378 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct StructFieldInfo fields[] = { ");

        #line 380 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 381 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 381 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 381 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 382 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 382 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 383 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct StructFieldInfo){ .index = %zu, .name = (struct str){ .ptr = \"", field_index);
            #line 384 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, field->name);
            #line 385 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, .type_id = ", field->name->value.length);
            #line 386 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, &field->type, generics);
            #line 387 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ", .type_name = ");
            #line 388 "src/compiler/FileGenerator.pv"
            Generator__write_typename(generator, code_file, &field->type, generics);
            #line 389 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 390 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 393 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 394 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 395 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_StructFieldInfo){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 396 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 397 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 399 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 400 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 401 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 403 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 405 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 406 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 408 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 409 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 410 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 411 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 413 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 416 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 417 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 418 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 420 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 421 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 421 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 421 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 422 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 423 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 425 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 426 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 428 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 429 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 432 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 433 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
            }

            #line 436 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 437 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 440 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 441 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 442 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 444 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 445 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 447 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 448 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 450 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 451 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 452 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 454 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 456 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 457 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 459 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 460 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 461 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 462 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 464 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 467 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 468 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 469 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 471 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 472 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 472 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 472 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 473 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 473 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 475 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);

            #line 477 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 478 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 479 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, &field->type, generics);
                #line 480 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 482 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 483 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
                #line 484 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 486 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 487 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 488 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 489 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 491 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 492 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 493 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 497 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 498 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 501 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 502 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 503 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 505 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 506 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 508 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 509 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 511 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 512 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 513 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 514 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_fields = &");
        #line 515 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 516 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .fn_get_field = &");
        #line 517 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 518 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .fn_set_field = &");
        #line 519 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 520 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 523 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 524 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 525 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 527 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 529 "src/compiler/FileGenerator.pv"
    return true;
}

#line 532 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_extern(struct FileGenerator* self, FILE* file, struct str name) {
    #line 533 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 534 "src/compiler/FileGenerator.pv"
    fprintf(file, "#include <std/trait_Any.h>\n");
    #line 535 "src/compiler/FileGenerator.pv"
    fprintf(file, "extern struct trait_AnyVTable ");
    #line 536 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 537 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 538 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 539 "src/compiler/FileGenerator.pv"
    fprintf(file, ";\n");
}

#line 542 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_definition(struct FileGenerator* self, FILE* file, struct str name, struct Type* self_type, struct GenericMap* generics) {
    #line 543 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 544 "src/compiler/FileGenerator.pv"
    fprintf(file, "\nuintptr_t ");
    #line 545 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 546 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size(void* __self) { (void)__self; return sizeof(");
    #line 547 "src/compiler/FileGenerator.pv"
    Generator__write_type(generator, file, self_type, generics);
    #line 548 "src/compiler/FileGenerator.pv"
    fprintf(file, "); }\n");

    #line 550 "src/compiler/FileGenerator.pv"
    fprintf(file, "struct trait_AnyVTable ");
    #line 551 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, name);
    #line 552 "src/compiler/FileGenerator.pv"
    fprintf(file, "__VTABLE__");
    #line 553 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, file, (struct str){ .ptr = "Any", .length = strlen("Any") });
    #line 554 "src/compiler/FileGenerator.pv"
    fprintf(file, " = { .fn_size = &");
    #line 555 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, file, name);
    #line 556 "src/compiler/FileGenerator.pv"
    fprintf(file, "__Any__size };\n");
}

#line 559 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 560 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 561 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 561 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 561 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 562 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 564 "src/compiler/FileGenerator.pv"
    return success;
}

#line 567 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 568 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 569 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 570 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 571 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 572 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 573 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 575 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 576 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 577 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 578 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 578 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 578 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 580 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 581 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 582 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 583 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 584 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 586 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, header_file, &primitive_info->impls);
    #line 587 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 588 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 590 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 591 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write primitive definition for %.*s\n", (int32_t)(name.length), name.ptr);
        #line 592 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 593 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 596 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 596 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_extern(self, header_file, name);
    }

    #line 598 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 600 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 601 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 602 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 604 "src/compiler/FileGenerator.pv"
    if (primitive_info->impls.length == 0) {
        #line 605 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 608 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 610 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 611 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 612 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 612 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 612 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 614 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, code_file, &primitive_info->impls);
    #line 615 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 616 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 618 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 619 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 620 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 621 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 623 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 624 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for primitive %.*s\n", (int32_t)(name.length), name.ptr);
        #line 625 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 626 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 629 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 629 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 629 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 630 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 631 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 631 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 633 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 634 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 634 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 636 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 636 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 638 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 639 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, &impl_info->trait_type, generics);
        #line 640 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 641 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, name);
        #line 642 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 643 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 644 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 646 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 647 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 647 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 647 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 648 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 648 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 649 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 651 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 652 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 653 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 654 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 655 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 658 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 661 "src/compiler/FileGenerator.pv"
    if (usage->any_usage) {
        #line 662 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <std/trait_Any.h>\n");
        #line 663 "src/compiler/FileGenerator.pv"
        FileGenerator__write_any_definition(self, code_file, name, generics->self_type, generics);
    }

    #line 666 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 667 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 668 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 670 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 672 "src/compiler/FileGenerator.pv"
    return true;
}

#line 675 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 676 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 677 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 677 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 677 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 678 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 679 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 680 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 682 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 685 "src/compiler/FileGenerator.pv"
    return success;
}

#line 688 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 689 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 690 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 691 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 692 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;

    #line 694 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 695 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 697 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 698 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &sequence_type, &sequence_type, generics);
    #line 699 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 701 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 702 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 703 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 704 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 704 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 704 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 706 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 707 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 708 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 709 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 710 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 712 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 713 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 715 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 716 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 717 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 719 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 720 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 721 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &generator->root->type_usize, generics);

    #line 723 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 725 "src/compiler/FileGenerator.pv"
    struct TypeImpl* hack_type_impl = generator->root->hack_type_impl;
    #line 726 "src/compiler/FileGenerator.pv"
    if (hack_type_impl == 0) {
        #line 727 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing hack type impl in generate_slice\n");
        #line 728 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 731 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), hack_type_impl->impl_info, generics);

    #line 733 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 735 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 736 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 737 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 739 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 741 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 742 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 743 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 743 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 743 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 745 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 746 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 747 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 748 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 750 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {hack_type_impl->impl_info};
    #line 751 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };
    #line 752 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };

    #line 754 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 755 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for slice %s\n", String__c_str(&name));
        #line 756 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 757 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 760 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 761 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 762 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 764 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 766 "src/compiler/FileGenerator.pv"
    return true;
}

#line 769 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 770 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 771 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 771 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 771 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 772 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 774 "src/compiler/FileGenerator.pv"
    return success;
}

#line 777 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 778 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 779 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 780 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 781 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 782 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 784 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &tuple_type, &tuple_type, generics);
    #line 785 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 787 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 788 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 789 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 790 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 790 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 790 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 792 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 793 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 794 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 795 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 796 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 798 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 799 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 801 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 802 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 803 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 804 "src/compiler/FileGenerator.pv"
    generator->indent += 1;

    #line 806 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 806 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 806 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 806 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 807 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 808 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 809 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 811 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, header_file);
        #line 812 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(generator, header_file, String__as_str(&element_name), element, generics);
        #line 813 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 814 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 817 "src/compiler/FileGenerator.pv"
    generator->indent -= 1;
    #line 818 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 820 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 822 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 823 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 824 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 826 "src/compiler/FileGenerator.pv"
    return true;
}

#line 829 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 830 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 831 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 831 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 831 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 832 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 834 "src/compiler/FileGenerator.pv"
    return success;
}

#line 837 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 838 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 839 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 840 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 841 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;

    #line 843 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 843 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 845 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 846 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 847 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 849 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 850 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 851 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 851 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 851 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 853 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 854 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 855 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 856 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 857 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 859 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 860 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 861 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 862 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 865 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 866 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 868 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 868 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 868 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 870 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 871 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 872 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 873 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 876 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 878 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 879 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 880 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 882 "src/compiler/FileGenerator.pv"
    return true;
}

#line 885 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 886 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 887 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 887 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 889 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;

    #line 891 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(generator->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 892 "src/compiler/FileGenerator.pv"
    if (blank_generics == 0) {
        #line 893 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing blank generics in generate_global\n");
        #line 894 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 896 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, generator->allocator);

    #line 898 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(generator->allocator);
    #line 899 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_ctx;

    #line 901 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(generator->allocator);

    #line 903 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(generator, &global->type, blank_generics, &primitive_includes);

    #line 905 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 906 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 907 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 908 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 908 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 908 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 910 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 911 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 912 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 913 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 914 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 916 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 916 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 916 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 917 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 920 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\nextern ");
    #line 921 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 921 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 922 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, name, &global->type, blank_generics);
    #line 923 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 925 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 927 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 928 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 929 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 931 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 932 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 933 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 934 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 934 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 934 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 936 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &global->module->includes);

    #line 938 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 939 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 940 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 941 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 943 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 943 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 944 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, code_file, name, &global->type, blank_generics);
    #line 945 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 946 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 947 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, code_file, global->value, blank_generics);
    }
    #line 949 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 951 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 952 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 953 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 955 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 957 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 959 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 962 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 963 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 963 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 963 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 964 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 964 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 964 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 965 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 965 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 965 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 966 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 970 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 974 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 975 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 977 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 977 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 977 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 978 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 978 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 978 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 978 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 979 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 979 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 979 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 980 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 981 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 982 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 984 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(generator, module, test_info->func_name, (struct str){ .ptr = ".test.h", .length = strlen(".test.h") });
                #line 985 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 987 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(generator, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 988 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 992 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 996 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 997 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 998 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 1000 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1001 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1002 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1003 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 1005 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 1007 "src/compiler/FileGenerator.pv"
    if (func_names.length == 0) {
        #line 1007 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1009 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 1010 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = generator->path, .length = strlen(generator->path) });
    #line 1011 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/main.test.c", .length = strlen("/main.test.c") });

    #line 1013 "src/compiler/FileGenerator.pv"
    char const* runner_tmp = tmpnam(0);
    #line 1014 "src/compiler/FileGenerator.pv"
    FILE* runner_file = fopen(runner_tmp, "w+");
    #line 1015 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 1015 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 1017 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n\n");

    #line 1019 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 1020 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 1021 "src/compiler/FileGenerator.pv"
        struct str hp = header_paths.data[i];
        #line 1022 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 1023 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, hp);
        #line 1024 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 1025 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1028 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\nint main(void) {\n");
    #line 1029 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int passed = 0;\n");
    #line 1030 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int failed = 0;\n\n");

    #line 1032 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 1033 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 1034 "src/compiler/FileGenerator.pv"
        struct str desc = descriptions.data[i];
        #line 1035 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 1036 "src/compiler/FileGenerator.pv"
        struct str module_path = module_paths.data[i];

        #line 1038 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    fputs(\"[TEST] ");
        #line 1039 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, module_path);
        #line 1040 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 1041 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, desc);
        #line 1042 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\\n\", stdout);\n");
        #line 1043 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    ");
        #line 1044 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 1045 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "();\n");
        #line 1046 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    passed++;\n\n");

        #line 1048 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1051 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    printf(\"[RESULT] %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 1052 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    return failed > 0 ? 1 : 0;\n");
    #line 1053 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "}\n");

    #line 1055 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&runner_path), runner_file);
    #line 1056 "src/compiler/FileGenerator.pv"
    fclose(runner_file);
    #line 1057 "src/compiler/FileGenerator.pv"
    remove(runner_tmp);

    #line 1059 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, runner_path);
}

#line 1062 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 1063 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1065 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1065 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1065 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 1065 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1066 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1067 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 1068 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 1069 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 1070 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 1072 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
