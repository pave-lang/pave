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
#include <std/Array_String.h>
#include <std/HashSet_str.h>
#include <std/HashMap_str_ref_Include.h>
#include <std/HashMap_str_Type.h>
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
    Array_String__append(&generator->code_files, code);

    #line 64 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 64 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 64 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 66 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 67 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &context->module->includes);
    #line 68 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 70 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, context->module, name_str, header_ext);
    #line 71 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 72 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 73 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 75 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, code_file, func_info, generics, 0)) {
        #line 75 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 75 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 77 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_function_block(&defs, code_file, name_str, func_info, generics, usage_context);

    #line 79 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 80 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 81 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 83 "src/compiler/FileGenerator.pv"
    include_writer = IncludeWriter__new(generator->allocator);

    #line 85 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, context->module, name_str, header_ext);
    #line 86 "src/compiler/FileGenerator.pv"
    FILE* header_file = 0;
    #line 87 "src/compiler/FileGenerator.pv"
    char const* header_tmp = 0;
    #line 88 "src/compiler/FileGenerator.pv"
    header_tmp = tmpnam(0);
    #line 89 "src/compiler/FileGenerator.pv"
    header_file = fopen(header_tmp, "w+");

    #line 91 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 91 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 91 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 93 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 94 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 95 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 96 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name_str);
    #line 97 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 99 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_code, 0);
    #line 100 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 102 "src/compiler/FileGenerator.pv"
    if (Generator__is_coroutine(generator)) {
        #line 103 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_function_coroutine(&defs, header_file, func_info, generics);
    }

    #line 106 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, header_file, func_info, generics, 0)) {
        #line 106 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 106 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 107 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 109 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 111 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 112 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 113 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 115 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 117 "src/compiler/FileGenerator.pv"
    return true;
}

#line 120 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum_loop(struct FileGenerator* self, struct TypeUsage_Enum* usage) {
    #line 121 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 122 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 122 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 122 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 123 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_enum(self, usage, usage_context) && success;
    } }
    #line 125 "src/compiler/FileGenerator.pv"
    return success;
}

#line 128 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum(struct FileGenerator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context) {
    #line 129 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 130 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 131 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 132 "src/compiler/FileGenerator.pv"
    struct Enum* enum_info = usage->type;
    #line 133 "src/compiler/FileGenerator.pv"
    struct Module* module = enum_info->context->module;
    #line 134 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 136 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 137 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 138 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 139 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 140 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 140 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 140 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 142 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 143 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 144 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 145 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 146 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 148 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 149 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 151 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_enum_definition(&defs, header_file, enum_info, usage, usage_context, &include_writer)) {
        #line 151 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 151 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 153 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 155 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 156 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 157 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 159 "src/compiler/FileGenerator.pv"
    if (enum_info->impls.length == 0) {
        #line 159 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 161 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 162 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 164 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 165 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 166 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 166 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 166 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 168 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 169 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &module->includes);
    #line 170 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 172 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 173 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 174 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 175 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 177 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 177 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 177 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 179 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 180 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 181 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 183 "src/compiler/FileGenerator.pv"
    return true;
}

#line 186 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 187 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 188 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 188 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 188 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 189 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 191 "src/compiler/FileGenerator.pv"
    return success;
}

#line 194 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 195 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 196 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 197 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 198 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 199 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 200 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 201 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 203 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 204 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 205 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 206 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 206 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 206 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 208 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 209 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 210 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 211 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 212 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 214 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 215 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 217 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 217 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 217 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 217 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 218 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 219 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 219 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 220 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 221 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 223 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 226 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 230 "src/compiler/FileGenerator.pv"
        if (struct_info->module->mode_cpp) {
            #line 231 "src/compiler/FileGenerator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 231 "src/compiler/FileGenerator.pv"
                fprintf(header_file, "\n");
            }
            #line 232 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 235 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 237 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 237 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 237 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 238 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 241 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (generator->root->mode_cpp) {
        #line 243 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 244 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 245 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 248 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 249 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);
    #line 250 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 250 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }

    #line 252 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 252 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 252 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 254 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || generator->root->mode_cpp) {
        #line 255 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 256 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 257 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 260 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 262 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 263 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 264 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 266 "src/compiler/FileGenerator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage) {
        #line 267 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 270 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 271 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 272 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 274 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 277 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, struct_info->module, String__as_str(&name), ext);
    #line 278 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 280 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 281 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 282 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 282 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 282 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 284 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 285 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &struct_info->module->includes);
    #line 286 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 288 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 289 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 290 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 291 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 293 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 293 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 293 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 295 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 296 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 299 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 299 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 299 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 300 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 301 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 302 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 302 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 303 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 303 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 304 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 305 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, trait_entry._1, generics);
        #line 306 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 307 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 308 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 309 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 310 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 312 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 313 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 313 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 313 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 314 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 314 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 315 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 317 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 318 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 319 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 320 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 321 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 324 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 327 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 328 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 330 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <tuple_usize_str_TypeId.h>\n");
        #line 331 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_tuple_usize_str_TypeId.h>\n");
        #line 332 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_tuple_usize_str_TypeId ");
        #line 333 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 334 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 336 "src/compiler/FileGenerator.pv"
        generator->indent += 1;
        #line 337 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 338 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct tuple_usize_str_TypeId fields[] = { ");

        #line 340 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 341 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 341 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 341 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 342 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 342 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 343 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct tuple_usize_str_TypeId){ ._0 = %zu, ._1 = (struct str){ .ptr = \"", field_index);
            #line 344 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, field->name);
            #line 345 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, ._2 = ", field->name->value.length);
            #line 346 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(generator, code_file, &field->type, generics);
            #line 347 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 348 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 351 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 352 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 353 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_tuple_usize_str_TypeId){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 354 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 355 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 357 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 358 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 359 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 361 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 363 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 364 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 366 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 367 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 368 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 369 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 371 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 374 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 375 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 376 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 378 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 379 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 379 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 379 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 380 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);
            #line 381 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 383 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 384 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 386 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 387 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 390 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 391 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
            }

            #line 394 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 395 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 398 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 399 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 400 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 402 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 403 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 405 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 406 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 408 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 409 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 410 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 412 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 414 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 415 "src/compiler/FileGenerator.pv"
        Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 417 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 418 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 419 "src/compiler/FileGenerator.pv"
            Generator__write_type(generator, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 420 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 422 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 425 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 426 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 427 "src/compiler/FileGenerator.pv"
        generator->indent += 1;

        #line 429 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 430 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 430 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 430 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 431 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 431 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 433 "src/compiler/FileGenerator.pv"
            Generator__write_indent(generator, code_file);

            #line 435 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 436 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 437 "src/compiler/FileGenerator.pv"
                Generator__write_type(generator, code_file, &field->type, generics);
                #line 438 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 440 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 441 "src/compiler/FileGenerator.pv"
                Generator__write_token(generator, code_file, field->name);
                #line 442 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 444 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 445 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 446 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 447 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 449 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 450 "src/compiler/FileGenerator.pv"
                    Generator__write_type(generator, code_file, &field->type, generics);
                    #line 451 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 455 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 456 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 459 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 460 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 461 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 463 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, code_file);
        #line 464 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 466 "src/compiler/FileGenerator.pv"
        generator->indent -= 1;
        #line 467 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 469 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 470 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, String__as_str(&name));
        #line 471 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 472 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .fn_get_fields = &");
        #line 473 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 474 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .fn_get_field = &");
        #line 475 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 476 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .fn_set_field = &");
        #line 477 "src/compiler/FileGenerator.pv"
        Generator__write_string(generator, code_file, &name);
        #line 478 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 481 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 482 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 483 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 485 "src/compiler/FileGenerator.pv"
    return true;
}

#line 488 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 489 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 490 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 490 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 490 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 491 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 493 "src/compiler/FileGenerator.pv"
    return success;
}

#line 496 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 497 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 498 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 499 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 500 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 501 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 502 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 504 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 505 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 506 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 507 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 507 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 507 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 509 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 510 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 511 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 512 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 513 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 515 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, header_file, &primitive_info->impls);
    #line 516 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 517 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 519 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 519 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 519 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 521 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 523 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 524 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 525 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 527 "src/compiler/FileGenerator.pv"
    if (primitive_info->impls.length == 0) {
        #line 528 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 531 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 532 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 534 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 535 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 536 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 536 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 536 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 538 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(generator, code_file, &primitive_info->impls);
    #line 539 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 540 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, generator, &usage_context->body, generics, true);

    #line 542 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 543 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 544 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 545 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 547 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage_context->impl_functions, generics, &include_writer)) {
        #line 547 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 547 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 549 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 549 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 549 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 550 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 551 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || trait_info == 0) {
            #line 551 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 553 "src/compiler/FileGenerator.pv"
        struct Token* trait_name = trait_info->name;
        #line 554 "src/compiler/FileGenerator.pv"
        if (trait_name == 0) {
            #line 554 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 556 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 556 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 558 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 559 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(generator, code_file, &impl_info->trait_type, generics);
        #line 560 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 561 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, name);
        #line 562 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 563 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(generator, code_file, trait_name->value);
        #line 564 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 566 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 567 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 567 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 567 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 568 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 568 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 569 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 571 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".fn_");
            #line 572 "src/compiler/FileGenerator.pv"
            Generator__write_token(generator, code_file, func_info->name);
            #line 573 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 574 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(generator, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 575 "src/compiler/FileGenerator.pv"
            Generator__write_string(generator, code_file, &func_name);
        } }

        #line 578 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 581 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 582 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 583 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 585 "src/compiler/FileGenerator.pv"
    return true;
}

#line 588 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 589 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 590 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 590 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 590 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 591 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 592 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 593 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 595 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 598 "src/compiler/FileGenerator.pv"
    return success;
}

#line 601 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 602 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 603 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 604 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 605 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;

    #line 607 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 608 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 610 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 611 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &sequence_type, &sequence_type, generics);
    #line 612 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 614 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 615 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 616 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 617 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 617 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 617 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 619 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 620 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 621 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 622 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 623 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 625 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 626 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 628 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 629 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 630 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 632 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 633 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 634 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &generator->root->type_usize, generics);

    #line 636 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 638 "src/compiler/FileGenerator.pv"
    struct TypeImpl* hack_type_impl = generator->root->hack_type_impl;
    #line 639 "src/compiler/FileGenerator.pv"
    if (hack_type_impl == 0) {
        #line 640 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing hack type impl in generate_slice\n");
        #line 641 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 644 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), hack_type_impl->impl_info, generics);

    #line 646 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 648 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 649 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 650 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 652 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 653 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 655 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 656 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 657 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 657 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 657 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 659 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 660 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 661 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 662 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 664 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {hack_type_impl->impl_info};
    #line 665 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };
    #line 666 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0, .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->generator->allocator }, .capacity = 0 };

    #line 668 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 668 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 668 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 670 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 671 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 672 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 674 "src/compiler/FileGenerator.pv"
    return true;
}

#line 677 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 678 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 679 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 679 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 679 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 680 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 682 "src/compiler/FileGenerator.pv"
    return success;
}

#line 685 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 686 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 687 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 688 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 689 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 690 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 692 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, &tuple_type, &tuple_type, generics);
    #line 693 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 695 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 696 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 697 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 698 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 698 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 698 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 700 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 701 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 702 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 703 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 704 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 706 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 707 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->layout, generics, false);

    #line 709 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 710 "src/compiler/FileGenerator.pv"
    Generator__write_string(generator, header_file, &name);
    #line 711 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 712 "src/compiler/FileGenerator.pv"
    generator->indent += 1;

    #line 714 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 714 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 714 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 714 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 715 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 716 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 717 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 719 "src/compiler/FileGenerator.pv"
        Generator__write_indent(generator, header_file);
        #line 720 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(generator, header_file, String__as_str(&element_name), element, generics);
        #line 721 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 722 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 725 "src/compiler/FileGenerator.pv"
    generator->indent -= 1;
    #line 726 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 728 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 730 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 731 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 732 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 734 "src/compiler/FileGenerator.pv"
    return true;
}

#line 737 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 738 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 739 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 739 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 739 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 740 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 742 "src/compiler/FileGenerator.pv"
    return success;
}

#line 745 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 746 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 747 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = generator };
    #line 748 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 749 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;

    #line 751 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 751 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 753 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&generator->naming_ident, generics->self_type, generics->self_type, generics);
    #line 754 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 755 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(generator->allocator);

    #line 757 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 758 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 759 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 759 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 759 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 761 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 762 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 763 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 764 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, String__as_str(&name));
    #line 765 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 767 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 768 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 769 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 770 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 773 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(generator, header_file, &usage_context->primitive_header, 0);
    #line 774 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, generator, &usage_context->signature, generics, false);

    #line 776 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 776 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 776 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 778 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 779 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 780 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 781 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 784 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 786 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 787 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 788 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 790 "src/compiler/FileGenerator.pv"
    return true;
}

#line 793 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 794 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 795 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 795 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 797 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;

    #line 799 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(generator->allocator, (struct GenericMap[]){(struct GenericMap) { .self_type = 0, .array = (struct Array_Type) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .data = 0, .length = 0, .capacity = 0 }, .map = (struct HashMap_str_usize) { .allocator = (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator }, .buckets = 0, .data = 0, .capacity = 0, .length = 0 } }});
    #line 800 "src/compiler/FileGenerator.pv"
    if (blank_generics == 0) {
        #line 801 "src/compiler/FileGenerator.pv"
        fprintf(stderr, "Missing blank generics in generate_global\n");
        #line 802 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 804 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, generator->allocator);

    #line 806 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(generator->allocator);
    #line 807 "src/compiler/FileGenerator.pv"
    generator->function_context = &func_ctx;

    #line 809 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(generator->allocator);

    #line 811 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(generator, &global->type, blank_generics, &primitive_includes);

    #line 813 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 814 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 815 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 816 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 816 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 816 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 818 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 819 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 820 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 821 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(generator, header_file, name);
    #line 822 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 824 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 824 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 824 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 825 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 828 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\nextern ");
    #line 829 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 829 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 830 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, header_file, name, &global->type, blank_generics);
    #line 831 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 833 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 835 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&header), header_file);
    #line 836 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 837 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 839 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(generator, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 840 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 841 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 842 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 842 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 842 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 844 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(generator, code_file, &global->module->includes);

    #line 846 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(generator, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 847 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 848 "src/compiler/FileGenerator.pv"
    Generator__write_str(generator, code_file, String__as_str(&header_rel));
    #line 849 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 851 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 851 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 852 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(generator, code_file, name, &global->type, blank_generics);
    #line 853 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 854 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 855 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = generator }}, code_file, global->value, blank_generics);
    }
    #line 857 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 859 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&code), code_file);
    #line 860 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 861 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 863 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, code);

    #line 865 "src/compiler/FileGenerator.pv"
    generator->function_context = 0;

    #line 867 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 870 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 871 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 871 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 871 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 872 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 872 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 872 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 873 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 873 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 873 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 874 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 878 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 882 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 883 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 885 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 885 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 885 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 886 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 886 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 886 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 886 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 887 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 887 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 887 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 888 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 889 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 890 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 892 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(generator, module, test_info->func_name, (struct str){ .ptr = ".test.h", .length = strlen(".test.h") });
                #line 893 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 895 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(generator, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 896 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 900 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 904 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 905 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;
    #line 906 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = generator->allocator;

    #line 908 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 909 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 910 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 911 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 913 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 915 "src/compiler/FileGenerator.pv"
    if (func_names.length == 0) {
        #line 915 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 917 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 918 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = generator->path, .length = strlen(generator->path) });
    #line 919 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/main.test.c", .length = strlen("/main.test.c") });

    #line 921 "src/compiler/FileGenerator.pv"
    char const* runner_tmp = tmpnam(0);
    #line 922 "src/compiler/FileGenerator.pv"
    FILE* runner_file = fopen(runner_tmp, "w+");
    #line 923 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 923 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 925 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n\n");

    #line 927 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 928 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 929 "src/compiler/FileGenerator.pv"
        struct str hp = header_paths.data[i];
        #line 930 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 931 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, hp);
        #line 932 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 933 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 936 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\nint main(void) {\n");
    #line 937 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int passed = 0;\n");
    #line 938 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int failed = 0;\n\n");

    #line 940 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 941 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 942 "src/compiler/FileGenerator.pv"
        struct str desc = descriptions.data[i];
        #line 943 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 944 "src/compiler/FileGenerator.pv"
        struct str module_path = module_paths.data[i];

        #line 946 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    fputs(\"[TEST] ");
        #line 947 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, module_path);
        #line 948 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 949 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, desc);
        #line 950 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\\n\", stdout);\n");
        #line 951 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    ");
        #line 952 "src/compiler/FileGenerator.pv"
        Generator__write_str(generator, runner_file, func_name);
        #line 953 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "();\n");
        #line 954 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    passed++;\n\n");

        #line 956 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 959 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    printf(\"[RESULT] %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 960 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    return failed > 0 ? 1 : 0;\n");
    #line 961 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "}\n");

    #line 963 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(generator, String__c_str(&runner_path), runner_file);
    #line 964 "src/compiler/FileGenerator.pv"
    fclose(runner_file);
    #line 965 "src/compiler/FileGenerator.pv"
    remove(runner_tmp);

    #line 967 "src/compiler/FileGenerator.pv"
    Array_String__append(&generator->code_files, runner_path);
}

#line 970 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 971 "src/compiler/FileGenerator.pv"
    struct Generator* generator = self->generator;

    #line 973 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 973 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 973 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 973 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 974 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = generator->allocator });
        #line 975 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 976 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 977 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 978 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 980 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
