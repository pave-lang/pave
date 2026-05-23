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
    fprintf(header_file, "\n#endif\n");

    #line 168 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 169 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 170 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 172 "src/compiler/FileGenerator.pv"
    if (enum_info->impls.length == 0) {
        #line 172 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 174 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 176 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 177 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 178 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 178 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 178 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 180 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 181 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 182 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 184 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 185 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 186 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 187 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 189 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 190 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for enum %s\n", String__c_str(&name));
        #line 191 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 192 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 195 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 196 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 197 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 199 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 201 "src/compiler/FileGenerator.pv"
    return true;
}

#line 204 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 205 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 206 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 206 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 206 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 207 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 209 "src/compiler/FileGenerator.pv"
    return success;
}

#line 212 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 213 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 214 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 215 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 216 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 217 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 218 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 219 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 221 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 222 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 223 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 224 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 224 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 224 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 226 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 227 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 228 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 229 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 230 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 232 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 233 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 235 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 235 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 235 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 235 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 236 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 237 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 237 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 238 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 239 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 241 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 244 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 248 "src/compiler/FileGenerator.pv"
        if (struct_info->module->mode_cpp) {
            #line 249 "src/compiler/FileGenerator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 249 "src/compiler/FileGenerator.pv"
                fprintf(header_file, "\n");
            }
            #line 250 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 253 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 255 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 255 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 255 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 256 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 259 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (generator->root->mode_cpp) {
        #line 261 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 262 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 263 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 266 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 267 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 268 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 268 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }

    #line 270 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 271 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write struct definition for %s\n", String__c_str(&name));

        #line 273 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 274 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 277 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 278 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 279 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 280 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 283 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 285 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 286 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 287 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 289 "src/compiler/FileGenerator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage) {
        #line 290 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 293 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 294 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 295 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 297 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 300 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, struct_info->module, String__as_str(&name), ext);

    #line 302 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 303 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 304 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 304 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 304 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 306 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 307 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &struct_info->module->includes);
    #line 308 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 310 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 311 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 312 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 313 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 315 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 316 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for struct %s\n", String__c_str(&name));
        #line 317 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 318 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 321 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 322 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 325 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 325 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 325 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 326 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 327 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 328 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 328 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 329 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 329 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 330 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 331 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, trait_entry._1, generics);
        #line 332 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 333 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 334 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 335 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 336 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 338 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 339 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 339 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 339 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 340 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 340 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 341 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 343 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 344 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 345 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 346 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 347 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 350 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 353 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 354 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 356 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <tuple_usize_str_TypeId.h>\n");
        #line 357 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_tuple_usize_str_TypeId.h>\n");
        #line 358 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_tuple_usize_str_TypeId ");
        #line 359 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 360 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 362 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 363 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 364 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct tuple_usize_str_TypeId fields[] = { ");

        #line 366 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 367 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 367 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 367 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 368 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 368 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 369 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct tuple_usize_str_TypeId){ ._0 = %zu, ._1 = (struct str){ .ptr = \"", field_index);
            #line 370 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, field->name);
            #line 371 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, ._2 = ", field->name->value.length);
            #line 372 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, &field->type, generics);
            #line 373 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 374 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 377 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 378 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 379 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_tuple_usize_str_TypeId){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 380 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 381 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 383 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 384 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 385 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 387 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 389 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 390 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 392 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 393 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 394 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 395 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 397 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 400 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 401 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 402 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 404 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 405 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 405 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 405 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 406 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 407 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 409 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 410 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 412 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 413 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 416 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 417 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
            }

            #line 420 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 421 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 424 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 425 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 426 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 428 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 429 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 431 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 432 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 434 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 435 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 436 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 438 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

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
        fprintf(code_file, "switch (index) {\n");
        #line 453 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 455 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 456 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 456 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 456 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 457 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 457 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 459 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);

            #line 461 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 462 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 463 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, &field->type, generics);
                #line 464 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 466 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 467 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
                #line 468 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 470 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 471 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 472 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 473 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 475 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 476 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 477 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 481 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 482 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 485 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 486 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 487 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 489 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 490 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 492 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 493 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 495 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 496 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 497 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 498 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_fields = &");
        #line 499 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 500 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .fn_get_field = &");
        #line 501 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 502 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .fn_set_field = &");
        #line 503 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 504 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 507 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 508 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 509 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 511 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 513 "src/compiler/FileGenerator.pv"
    return true;
}

#line 516 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 517 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 518 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 518 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 518 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 519 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 521 "src/compiler/FileGenerator.pv"
    return success;
}

#line 524 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 525 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 526 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 527 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 528 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 529 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 530 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 532 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 533 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 534 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 535 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 535 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 535 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 537 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 538 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 539 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 540 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 541 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 543 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, header_file, &primitive_info->impls);
    #line 544 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 545 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 547 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 548 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write primitive definition for %.*s\n", (int32_t)(name.length), name.ptr);
        #line 549 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 550 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 553 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 555 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 556 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 557 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 559 "src/compiler/FileGenerator.pv"
    if (primitive_info->impls.length == 0) {
        #line 560 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 563 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 565 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 566 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 567 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 567 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 567 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 569 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, code_file, &primitive_info->impls);
    #line 570 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 571 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 573 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 574 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 575 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 576 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 578 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 579 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for primitive %.*s\n", (int32_t)(name.length), name.ptr);
        #line 580 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 581 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 584 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 584 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 584 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 585 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 586 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 586 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 588 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 589 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 589 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 591 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 591 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 593 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 594 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, &impl_info->trait_type, generics);
        #line 595 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 596 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, name);
        #line 597 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 598 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 599 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 601 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 602 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 602 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 602 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 603 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 603 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 604 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 606 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 607 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 608 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 609 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 610 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 613 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 616 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 617 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 618 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 620 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 622 "src/compiler/FileGenerator.pv"
    return true;
}

#line 625 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 626 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 627 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 627 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 627 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 628 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 629 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 630 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 632 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 635 "src/compiler/FileGenerator.pv"
    return success;
}

#line 638 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 639 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 640 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 641 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 642 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;

    #line 644 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 645 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 647 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 648 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &sequence_type, &sequence_type, generics);
    #line 649 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 651 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 652 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 653 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 654 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 654 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 654 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 656 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 657 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 658 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 659 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 660 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 662 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 663 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 665 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 666 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 667 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 669 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 670 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 671 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &generator->root->type_usize, generics);

    #line 673 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 675 "src/compiler/FileGenerator.pv"
    struct TypeImpl* hack_type_impl = generator->root->hack_type_impl;
    #line 676 "src/compiler/FileGenerator.pv"
    if (hack_type_impl == 0) {
        #line 677 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing hack type impl in generate_slice\n");
        #line 678 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 681 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), hack_type_impl->impl_info, generics);

    #line 683 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 685 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 686 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 687 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 689 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });

    #line 691 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 692 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 693 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 693 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 693 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 695 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 696 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 697 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 698 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 700 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {hack_type_impl->impl_info};
    #line 701 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };
    #line 702 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };

    #line 704 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 705 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Failed to write impls for slice %s\n", String__c_str(&name));
        #line 706 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 707 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 710 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 711 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 712 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 714 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 716 "src/compiler/FileGenerator.pv"
    return true;
}

#line 719 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 720 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 721 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 721 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 721 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 722 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 724 "src/compiler/FileGenerator.pv"
    return success;
}

#line 727 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 728 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 729 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 730 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 731 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 732 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 734 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &tuple_type, &tuple_type, generics);
    #line 735 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 737 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 738 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 739 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 740 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 740 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 740 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 742 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 743 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 744 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 745 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 746 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 748 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 749 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 751 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 752 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 753 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 754 "src/compiler/FileGenerator.pv"
    generator->indent += 1;

    #line 756 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 756 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 756 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 756 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 757 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 758 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 759 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 761 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, header_file);
        #line 762 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(generator, header_file, String__as_str(&element_name), element, generics);
        #line 763 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 764 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 767 "src/compiler/FileGenerator.pv"
    generator->indent -= 1;
    #line 768 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 770 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 772 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 773 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 774 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 776 "src/compiler/FileGenerator.pv"
    return true;
}

#line 779 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 780 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 781 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 781 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 781 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 782 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 784 "src/compiler/FileGenerator.pv"
    return success;
}

#line 787 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 788 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 789 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 790 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 791 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;

    #line 793 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 793 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 795 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 796 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 797 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 799 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 800 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 801 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 801 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 801 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 803 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 804 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 805 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 806 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 807 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 809 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 810 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 811 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 812 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 815 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 816 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 818 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 818 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 818 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 820 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 821 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 822 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 823 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 826 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 828 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 829 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 830 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 832 "src/compiler/FileGenerator.pv"
    return true;
}

#line 835 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 836 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 837 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 837 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 839 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;

    #line 841 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(generator->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 842 "src/compiler/FileGenerator.pv"
    if (blank_generics == 0) {
        #line 843 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing blank generics in generate_global\n");
        #line 844 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 846 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, generator->allocator);

    #line 848 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(generator->allocator);
    #line 849 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_ctx;

    #line 851 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(generator->allocator);

    #line 853 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(generator, &global->type, blank_generics, &primitive_includes);

    #line 855 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 856 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 857 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 858 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 858 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 858 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 860 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 861 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 862 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 863 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 864 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 866 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 866 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 866 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 867 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 870 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\nextern ");
    #line 871 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 871 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 872 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, name, &global->type, blank_generics);
    #line 873 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 875 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 877 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 878 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 879 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 881 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 882 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 883 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 884 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 884 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 884 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 886 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &global->module->includes);

    #line 888 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 889 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 890 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 891 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 893 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 893 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 894 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, code_file, name, &global->type, blank_generics);
    #line 895 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 896 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 897 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, code_file, global->value, blank_generics);
    }
    #line 899 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 901 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 902 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 903 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 905 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 907 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 909 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 912 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 913 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 913 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 913 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 914 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 914 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 914 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 915 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 915 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 915 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 916 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 920 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 924 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 925 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 927 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 927 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 927 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 928 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 928 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 928 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 928 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 929 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 929 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 929 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 930 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 931 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 932 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 934 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(generator, module, test_info->func_name, (struct str){ .ptr = ".test.h", .length = strlen(".test.h") });
                #line 935 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 937 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(generator, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 938 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 942 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 946 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 947 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 948 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 950 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 951 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 952 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 953 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 955 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 957 "src/compiler/FileGenerator.pv"
    if (func_names.length == 0) {
        #line 957 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 959 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 960 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = generator->path, .length = strlen(generator->path) });
    #line 961 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/main.test.c", .length = strlen("/main.test.c") });

    #line 963 "src/compiler/FileGenerator.pv"
    char const* runner_tmp = tmpnam(0);
    #line 964 "src/compiler/FileGenerator.pv"
    FILE* runner_file = fopen(runner_tmp, "w+");
    #line 965 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 965 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 967 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n\n");

    #line 969 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 970 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 971 "src/compiler/FileGenerator.pv"
        struct str hp = header_paths.data[i];
        #line 972 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 973 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, hp);
        #line 974 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 975 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 978 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\nint main(void) {\n");
    #line 979 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int passed = 0;\n");
    #line 980 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int failed = 0;\n\n");

    #line 982 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 983 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 984 "src/compiler/FileGenerator.pv"
        struct str desc = descriptions.data[i];
        #line 985 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 986 "src/compiler/FileGenerator.pv"
        struct str module_path = module_paths.data[i];

        #line 988 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    fputs(\"[TEST] ");
        #line 989 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, module_path);
        #line 990 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 991 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, desc);
        #line 992 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\\n\", stdout);\n");
        #line 993 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    ");
        #line 994 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 995 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "();\n");
        #line 996 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    passed++;\n\n");

        #line 998 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 1001 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    printf(\"[RESULT] %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 1002 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    return failed > 0 ? 1 : 0;\n");
    #line 1003 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "}\n");

    #line 1005 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&runner_path), runner_file);
    #line 1006 "src/compiler/FileGenerator.pv"
    fclose(runner_file);
    #line 1007 "src/compiler/FileGenerator.pv"
    remove(runner_tmp);

    #line 1009 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, runner_path);
}

#line 1012 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 1013 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 1015 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 1015 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 1015 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 1015 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 1016 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 1017 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 1018 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 1019 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 1020 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 1022 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
