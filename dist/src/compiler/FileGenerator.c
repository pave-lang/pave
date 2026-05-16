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
#include <analyzer/Module.h>
#include <analyzer/Context.h>
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
#include <compiler/TypeUsage_Tuple.h>
#include <analyzer/types/Tuple.h>
#include <std/Array_Type.h>
#include <std/IterEnumerate_ref_Type.h>
#include <std/Iter_ref_Type.h>
#include <tuple_usize_ref_Type.h>
#include <std/trait_Allocator.h>
#include <compiler/TypeUsage_Trait.h>
#include <analyzer/types/Global.h>
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
    struct Generator* g = self->generator;
    #line 30 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
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
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 37 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 38 "src/compiler/FileGenerator.pv"
    struct str name_str = String__as_str(&name);
    #line 39 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_context = FunctionContext__new(g->allocator, func_info, true);
    #line 40 "src/compiler/FileGenerator.pv"
    g->function_context = &func_context;

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
    struct String code = Generator__make_path(g, func_info->context->module, name_str, code_ext);
    #line 50 "src/compiler/FileGenerator.pv"
    FILE* code_file = 0;
    #line 51 "src/compiler/FileGenerator.pv"
    char const* code_tmp = 0;

    #line 53 "src/compiler/FileGenerator.pv"
    code_tmp = tmpnam(0);
    #line 54 "src/compiler/FileGenerator.pv"
    code_file = fopen(code_tmp, "w+");

    #line 56 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 58 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 58 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 58 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 60 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 61 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &func_info->context->module->includes);
    #line 62 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 64 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, func_info->context->module, name_str, header_ext);
    #line 65 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 66 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 67 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 69 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, code_file, func_info, generics, 0)) {
        #line 69 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 69 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 71 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_function_block(&defs, code_file, name_str, func_info, generics, usage);

    #line 73 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 74 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 75 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 77 "src/compiler/FileGenerator.pv"
    include_writer = IncludeWriter__new(g->allocator);

    #line 79 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, func_info->context->module, name_str, header_ext);
    #line 80 "src/compiler/FileGenerator.pv"
    FILE* header_file = 0;
    #line 81 "src/compiler/FileGenerator.pv"
    char const* header_tmp = 0;
    #line 82 "src/compiler/FileGenerator.pv"
    header_tmp = tmpnam(0);
    #line 83 "src/compiler/FileGenerator.pv"
    header_file = fopen(header_tmp, "w+");

    #line 85 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 85 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 85 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 87 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 88 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name_str);
    #line 89 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 90 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name_str);
    #line 91 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 93 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_code, 0);
    #line 94 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->signature, generics, false);

    #line 96 "src/compiler/FileGenerator.pv"
    if (Generator__is_coroutine(g)) {
        #line 97 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_function_coroutine(&defs, header_file, func_info, generics);
    }

    #line 100 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, header_file, func_info, generics, 0)) {
        #line 100 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 100 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 101 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 103 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 105 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 106 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 107 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 109 "src/compiler/FileGenerator.pv"
    g->function_context = 0;

    #line 111 "src/compiler/FileGenerator.pv"
    return true;
}

#line 114 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum_loop(struct FileGenerator* self, struct TypeUsage_Enum* usage) {
    #line 115 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 116 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 116 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 116 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 117 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_enum(self, usage, usage_context) && success;
    } }
    #line 119 "src/compiler/FileGenerator.pv"
    return success;
}

#line 122 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum(struct FileGenerator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context) {
    #line 123 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 124 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 125 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 126 "src/compiler/FileGenerator.pv"
    struct Enum* enum_info = usage->type;
    #line 127 "src/compiler/FileGenerator.pv"
    struct Module* module = enum_info->context->module;
    #line 128 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 130 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 131 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 132 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 133 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 134 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 134 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 134 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 136 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 137 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 138 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 139 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 140 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 142 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 143 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);

    #line 145 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_enum_definition(&defs, header_file, enum_info, usage, usage_context, &include_writer)) {
        #line 145 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 145 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 147 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 149 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 150 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 151 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 153 "src/compiler/FileGenerator.pv"
    if (enum_info->impls.length == 0) {
        #line 153 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 155 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 156 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 158 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 159 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 160 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 160 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 160 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 162 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 163 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &module->includes);
    #line 164 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 166 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 167 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 168 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 169 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 171 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage->impl_functions, generics, &include_writer)) {
        #line 171 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 171 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 173 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 174 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 175 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 177 "src/compiler/FileGenerator.pv"
    return true;
}

#line 180 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 181 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 182 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 182 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 182 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 183 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 185 "src/compiler/FileGenerator.pv"
    return success;
}

#line 188 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 189 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 190 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 191 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 192 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 193 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 194 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 195 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 197 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 198 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 199 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 200 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 200 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 200 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 202 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 203 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 204 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 205 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 206 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 208 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 209 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 211 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 211 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 211 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 211 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 212 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 213 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 213 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 214 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 215 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 217 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 220 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 224 "src/compiler/FileGenerator.pv"
        if (struct_info->module->mode_cpp) {
            #line 225 "src/compiler/FileGenerator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 225 "src/compiler/FileGenerator.pv"
                fprintf(header_file, "\n");
            }
            #line 226 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 229 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 231 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 231 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 231 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 232 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 235 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (g->root->mode_cpp) {
        #line 237 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 238 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 239 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 242 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 243 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);
    #line 244 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 244 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }

    #line 246 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 246 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 246 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 248 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || g->root->mode_cpp) {
        #line 249 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 250 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 251 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 254 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 256 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 257 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 258 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 260 "src/compiler/FileGenerator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage) {
        #line 261 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 264 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 265 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 266 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 268 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 271 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, struct_info->module, String__as_str(&name), ext);
    #line 272 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 274 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 275 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 276 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 276 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 276 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 278 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 279 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &struct_info->module->includes);
    #line 280 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 282 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 283 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 284 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 285 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 287 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage->impl_functions, generics, &include_writer)) {
        #line 287 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 287 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 289 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 290 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 293 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 293 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 293 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 294 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 295 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 295 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 296 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 297 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(g, code_file, trait_entry._1, generics);
        #line 298 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 299 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, String__as_str(&name));
        #line 300 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 301 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, trait_info->name->value);
        #line 302 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 304 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 305 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 305 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 305 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 306 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 306 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 307 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 309 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".");
            #line 310 "src/compiler/FileGenerator.pv"
            Generator__write_token(g, code_file, func_info->name);
            #line 311 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 312 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(g, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 313 "src/compiler/FileGenerator.pv"
            Generator__write_string(g, code_file, &func_name);
        } }

        #line 316 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 319 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 320 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 322 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <tuple_usize_str_TypeId.h>\n");
        #line 323 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_tuple_usize_str_TypeId.h>\n");
        #line 324 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_tuple_usize_str_TypeId ");
        #line 325 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 326 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 328 "src/compiler/FileGenerator.pv"
        g->indent += 1;
        #line 329 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 330 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct tuple_usize_str_TypeId fields[] = { ");

        #line 332 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 333 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 333 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 333 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 334 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 334 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 335 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct tuple_usize_str_TypeId){ ._0 = %zu, ._1 = (struct str){ .ptr = \"", field_index);
            #line 336 "src/compiler/FileGenerator.pv"
            Generator__write_token(g, code_file, field->name);
            #line 337 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, ._2 = ", field->name->value.length);
            #line 338 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(g, code_file, &field->type, generics);
            #line 339 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 340 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 343 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 344 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 345 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_tuple_usize_str_TypeId){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 346 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 347 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 349 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 350 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 351 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 353 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 355 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 356 "src/compiler/FileGenerator.pv"
        Generator__write_type(g, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 358 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 359 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 360 "src/compiler/FileGenerator.pv"
            Generator__write_type(g, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 361 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 363 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 366 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 367 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 368 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 370 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 371 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 371 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 371 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 372 "src/compiler/FileGenerator.pv"
            Generator__write_indent(g, code_file);
            #line 373 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 375 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 376 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 378 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 379 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 382 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 383 "src/compiler/FileGenerator.pv"
                Generator__write_token(g, code_file, field->name);
            }

            #line 386 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 387 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 390 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 391 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 392 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 394 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 395 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 397 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 398 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 400 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 401 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 402 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 404 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 406 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 407 "src/compiler/FileGenerator.pv"
        Generator__write_type(g, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);

        #line 409 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 410 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 411 "src/compiler/FileGenerator.pv"
            Generator__write_type(g, code_file, (struct Type[]){(struct Type) { .type = TYPE__SELF }}, generics);
            #line 412 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 414 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 417 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 418 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 419 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 421 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 422 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 422 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 422 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 423 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 423 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 425 "src/compiler/FileGenerator.pv"
            Generator__write_indent(g, code_file);

            #line 427 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 428 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 429 "src/compiler/FileGenerator.pv"
                Generator__write_type(g, code_file, &field->type, generics);
                #line 430 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 432 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 433 "src/compiler/FileGenerator.pv"
                Generator__write_token(g, code_file, field->name);
                #line 434 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 436 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 437 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 438 "src/compiler/FileGenerator.pv"
                    Generator__write_type(g, code_file, &field->type, generics);
                    #line 439 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 441 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 442 "src/compiler/FileGenerator.pv"
                    Generator__write_type(g, code_file, &field->type, generics);
                    #line 443 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 447 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 448 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 451 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 452 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 453 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 455 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 456 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 458 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 459 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 461 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 462 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, String__as_str(&name));
        #line 463 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 464 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .get_fields = &");
        #line 465 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 466 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .get_field = &");
        #line 467 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 468 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .set_field = &");
        #line 469 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 470 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 473 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 474 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 475 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 477 "src/compiler/FileGenerator.pv"
    return true;
}

#line 480 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 481 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 482 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 482 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 482 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 483 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 485 "src/compiler/FileGenerator.pv"
    return success;
}

#line 488 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 489 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 490 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 491 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 492 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 493 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 494 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 496 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 497 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 498 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 499 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 499 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 499 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 501 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 502 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 503 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 504 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 505 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 507 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(g, header_file, &primitive_info->impls);
    #line 508 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 509 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->signature, generics, false);

    #line 511 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 511 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 511 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 513 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 515 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 516 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 517 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 519 "src/compiler/FileGenerator.pv"
    if (primitive_info->impls.length == 0) {
        #line 520 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 523 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 524 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 526 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 527 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 528 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 528 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 528 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 530 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(g, code_file, &primitive_info->impls);
    #line 531 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 532 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 534 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 535 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 536 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 537 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 539 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage->impl_functions, generics, &include_writer)) {
        #line 539 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 539 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 541 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_ref_Impl __iter = Array_ref_Impl__iter(&primitive_info->impls);
    #line 541 "src/compiler/FileGenerator.pv"
    while (Iter_ref_ref_Impl__next(&__iter)) {
        #line 541 "src/compiler/FileGenerator.pv"
        struct Impl* impl_info = *Iter_ref_ref_Impl__value(&__iter);

        #line 542 "src/compiler/FileGenerator.pv"
        if (!impl_info->has_trait || impl_info->trait_ == 0) {
            #line 542 "src/compiler/FileGenerator.pv"
            continue;
        }
        #line 543 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = impl_info->trait_;
        #line 544 "src/compiler/FileGenerator.pv"
        if (!Trait__has_dynamic_dispatch(trait_info)) {
            #line 544 "src/compiler/FileGenerator.pv"
            continue;
        }

        #line 546 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct ");
        #line 547 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(g, code_file, &impl_info->trait_type, generics);
        #line 548 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 549 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, name);
        #line 550 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 551 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, trait_info->name->value);
        #line 552 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 554 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 555 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 555 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 555 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 556 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 556 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 557 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 559 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".");
            #line 560 "src/compiler/FileGenerator.pv"
            Generator__write_token(g, code_file, func_info->name);
            #line 561 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 562 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(g, name, trait_info, &impl_info->trait_type, func_info, generics);
            #line 563 "src/compiler/FileGenerator.pv"
            Generator__write_string(g, code_file, &func_name);
        } }

        #line 566 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 569 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 570 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 571 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 573 "src/compiler/FileGenerator.pv"
    return true;
}

#line 576 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 577 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 578 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 578 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 578 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 579 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 580 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 581 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 583 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 586 "src/compiler/FileGenerator.pv"
    return success;
}

#line 589 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 590 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 591 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 592 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 593 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;

    #line 595 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 596 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 598 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 599 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, &sequence_type, &sequence_type, generics);
    #line 600 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 602 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 603 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 604 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 605 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 605 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 605 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 607 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 608 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 609 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 610 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 611 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 613 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 614 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);

    #line 616 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 617 "src/compiler/FileGenerator.pv"
    Generator__write_string(g, header_file, &name);
    #line 618 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 620 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 621 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 622 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &g->root->type_usize, generics);

    #line 624 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 626 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), g->root->hack_type_impl->impl_info, generics);

    #line 628 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 630 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 631 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 632 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 634 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 635 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 637 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 638 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 639 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 639 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 639 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 641 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 642 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 643 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 644 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 646 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {g->root->hack_type_impl->impl_info};
    #line 647 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1 };
    #line 648 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0 };

    #line 650 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 650 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 650 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 652 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 653 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 654 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 656 "src/compiler/FileGenerator.pv"
    return true;
}

#line 659 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 660 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 661 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 661 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 661 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 662 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 664 "src/compiler/FileGenerator.pv"
    return success;
}

#line 667 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 668 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 669 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 670 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 671 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 672 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 674 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, &tuple_type, &tuple_type, generics);
    #line 675 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 677 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 678 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 679 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 680 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 680 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 680 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 682 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 683 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 684 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 685 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 686 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 688 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 689 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);

    #line 691 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 692 "src/compiler/FileGenerator.pv"
    Generator__write_string(g, header_file, &name);
    #line 693 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 694 "src/compiler/FileGenerator.pv"
    g->indent += 1;

    #line 696 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 696 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 696 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 696 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 697 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = g->allocator });
        #line 698 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 699 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 701 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, header_file);
        #line 702 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(g, header_file, String__as_str(&element_name), element, generics);
        #line 703 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 704 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 707 "src/compiler/FileGenerator.pv"
    g->indent -= 1;
    #line 708 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 710 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 712 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 713 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 714 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 716 "src/compiler/FileGenerator.pv"
    return true;
}

#line 719 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 720 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 721 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 721 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 721 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 722 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 724 "src/compiler/FileGenerator.pv"
    return success;
}

#line 727 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 728 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 729 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 730 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 731 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;

    #line 733 "src/compiler/FileGenerator.pv"
    if (!Trait__has_dynamic_dispatch(trait_info)) {
        #line 733 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 735 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 736 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 737 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 739 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 740 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 741 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 741 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 741 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 743 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 744 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 745 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 746 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 747 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 749 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 750 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 751 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 752 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 755 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 756 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->signature, generics, false);

    #line 758 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 758 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 758 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 760 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 761 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 762 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 763 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 766 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 768 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 769 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 770 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 772 "src/compiler/FileGenerator.pv"
    return true;
}

#line 775 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 776 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 777 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 777 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 779 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;

    #line 781 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(g->allocator, (struct GenericMap[]){(struct GenericMap) {}});
    #line 782 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr((struct Type[]){(struct Type) { .type = TYPE__SELF }}, g->allocator);

    #line 784 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(g->allocator);
    #line 785 "src/compiler/FileGenerator.pv"
    g->function_context = &func_ctx;

    #line 787 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(g->allocator);

    #line 789 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(g, &global->type, blank_generics, &primitive_includes);

    #line 791 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 792 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 793 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 794 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 794 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 794 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 796 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 797 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 798 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 799 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 800 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 802 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 802 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 802 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 803 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 806 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\nextern ");
    #line 807 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 807 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 808 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, header_file, name, &global->type, blank_generics);
    #line 809 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 811 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 813 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 814 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 815 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 817 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 818 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 819 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 820 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 820 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 820 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 822 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &global->module->includes);

    #line 824 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 825 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 826 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 827 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 829 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 829 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 830 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, code_file, name, &global->type, blank_generics);
    #line 831 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 832 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 833 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression((struct ExpressionWriter[]){(struct ExpressionWriter) { .generator = g }}, code_file, global->value, blank_generics);
    }
    #line 835 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 837 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 838 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 839 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 841 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 843 "src/compiler/FileGenerator.pv"
    g->function_context = 0;

    #line 845 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 848 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 849 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 849 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 849 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 850 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 850 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 850 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 851 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 851 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 851 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 852 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 856 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 860 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths) {
    #line 861 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;

    #line 863 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 863 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 863 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 864 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 864 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 864 "src/compiler/FileGenerator.pv"
            struct str module_name = HashMapIter_str_ref_Module__value(&__iter)->_0;
            #line 864 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 865 "src/compiler/FileGenerator.pv"
            { struct Iter_ref_TestInfo __iter = Array_TestInfo__iter(&module->tests);
            #line 865 "src/compiler/FileGenerator.pv"
            while (Iter_ref_TestInfo__next(&__iter)) {
                #line 865 "src/compiler/FileGenerator.pv"
                struct TestInfo* test_info = Iter_ref_TestInfo__value(&__iter);

                #line 866 "src/compiler/FileGenerator.pv"
                struct str desc = test_info->description->value;
                #line 867 "src/compiler/FileGenerator.pv"
                Array_str__append(descriptions, str__slice(desc, 1, desc.length - 1));
                #line 868 "src/compiler/FileGenerator.pv"
                Array_str__append(func_names, test_info->func_name);

                #line 870 "src/compiler/FileGenerator.pv"
                struct String header_path = Generator__make_rel_path(g, module, test_info->func_name, (struct str){ .ptr = ".test.h", .length = strlen(".test.h") });
                #line 871 "src/compiler/FileGenerator.pv"
                Array_str__append(header_paths, String__as_str(&header_path));

                #line 873 "src/compiler/FileGenerator.pv"
                struct String module_path = Generator__make_rel_path(g, module, module_name, (struct str){ .ptr = "", .length = strlen("") });
                #line 874 "src/compiler/FileGenerator.pv"
                Array_str__append(module_paths, String__as_str(&module_path));
            } }
        } }

        #line 878 "src/compiler/FileGenerator.pv"
        FileGenerator__collect_tests(self, &namespace->children, func_names, descriptions, header_paths, module_paths);
    } }
}

#line 882 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 883 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 884 "src/compiler/FileGenerator.pv"
    struct ArenaAllocator* allocator = g->allocator;

    #line 886 "src/compiler/FileGenerator.pv"
    struct Array_str func_names = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 887 "src/compiler/FileGenerator.pv"
    struct Array_str descriptions = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 888 "src/compiler/FileGenerator.pv"
    struct Array_str header_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 889 "src/compiler/FileGenerator.pv"
    struct Array_str module_paths = Array_str__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });

    #line 891 "src/compiler/FileGenerator.pv"
    FileGenerator__collect_tests(self, children, &func_names, &descriptions, &header_paths, &module_paths);

    #line 893 "src/compiler/FileGenerator.pv"
    if (func_names.length == 0) {
        #line 893 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 895 "src/compiler/FileGenerator.pv"
    struct String runner_path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = allocator });
    #line 896 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = g->path, .length = strlen(g->path) });
    #line 897 "src/compiler/FileGenerator.pv"
    String__append(&runner_path, (struct str){ .ptr = "/main.test.c", .length = strlen("/main.test.c") });

    #line 899 "src/compiler/FileGenerator.pv"
    char const* runner_tmp = tmpnam(0);
    #line 900 "src/compiler/FileGenerator.pv"
    FILE* runner_file = fopen(runner_tmp, "w+");
    #line 901 "src/compiler/FileGenerator.pv"
    if (runner_file == 0) {
        #line 901 "src/compiler/FileGenerator.pv"
        return;
    }

    #line 903 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "#include <stdio.h>\n\n");

    #line 905 "src/compiler/FileGenerator.pv"
    uintptr_t i = 0;
    #line 906 "src/compiler/FileGenerator.pv"
    while (i < header_paths.length) {
        #line 907 "src/compiler/FileGenerator.pv"
        struct str hp = header_paths.data[i];
        #line 908 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "#include <");
        #line 909 "src/compiler/FileGenerator.pv"
        Generator__write_str(g, runner_file, hp);
        #line 910 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ">\n");
        #line 911 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 914 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "\nint main(void) {\n");
    #line 915 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int passed = 0;\n");
    #line 916 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    int failed = 0;\n\n");

    #line 918 "src/compiler/FileGenerator.pv"
    i = 0;
    #line 919 "src/compiler/FileGenerator.pv"
    while (i < func_names.length) {
        #line 920 "src/compiler/FileGenerator.pv"
        struct str desc = descriptions.data[i];
        #line 921 "src/compiler/FileGenerator.pv"
        struct str func_name = func_names.data[i];
        #line 922 "src/compiler/FileGenerator.pv"
        struct str module_path = module_paths.data[i];

        #line 924 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    fputs(\"[TEST] ");
        #line 925 "src/compiler/FileGenerator.pv"
        Generator__write_str(g, runner_file, module_path);
        #line 926 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, ": ");
        #line 927 "src/compiler/FileGenerator.pv"
        Generator__write_str(g, runner_file, desc);
        #line 928 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "\\n\", stdout);\n");
        #line 929 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    ");
        #line 930 "src/compiler/FileGenerator.pv"
        Generator__write_str(g, runner_file, func_name);
        #line 931 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "();\n");
        #line 932 "src/compiler/FileGenerator.pv"
        fprintf(runner_file, "    passed++;\n\n");

        #line 934 "src/compiler/FileGenerator.pv"
        i += 1;
    }

    #line 937 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    printf(\"[RESULT] %%d passed, %%d failed\\n\", passed, failed);\n");
    #line 938 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "    return failed > 0 ? 1 : 0;\n");
    #line 939 "src/compiler/FileGenerator.pv"
    fprintf(runner_file, "}\n");

    #line 941 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&runner_path), runner_file);
    #line 942 "src/compiler/FileGenerator.pv"
    fclose(runner_file);
    #line 943 "src/compiler/FileGenerator.pv"
    remove(runner_tmp);

    #line 945 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, runner_path);
}

#line 948 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 949 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;

    #line 951 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 951 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 951 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 951 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 952 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = g->allocator });
        #line 953 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 954 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 955 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 956 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 958 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
