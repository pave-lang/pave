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
#include <std/HashMap_str_ref_Trait.h>
#include <std/HashMapIter_str_ref_Trait.h>
#include <tuple_str_ref_Trait.h>
#include <compiler/TypeUsage_Sequence.h>
#include <analyzer/types/SequenceType.h>
#include <analyzer/types/Sequence.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/IndirectType.h>
#include <analyzer/Impl.h>
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
    struct String code = Generator__make_path(g, func_info->context->module, name_str, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 43 "src/compiler/FileGenerator.pv"
    FILE* code_file = 0;
    #line 44 "src/compiler/FileGenerator.pv"
    char const* code_tmp = 0;

    #line 46 "src/compiler/FileGenerator.pv"
    code_tmp = tmpnam(0);
    #line 47 "src/compiler/FileGenerator.pv"
    code_file = fopen(code_tmp, "w+");

    #line 49 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 51 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 51 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 51 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 53 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 54 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &func_info->context->module->includes);
    #line 55 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 57 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, func_info->context->module, name_str, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 58 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 59 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 60 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 62 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, code_file, func_info, generics, 0)) {
        #line 62 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 62 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 64 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_function_block(&defs, code_file, name_str, func_info, generics, usage);

    #line 66 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 67 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 68 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 70 "src/compiler/FileGenerator.pv"
    include_writer = IncludeWriter__new(g->allocator);

    #line 72 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, func_info->context->module, name_str, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 73 "src/compiler/FileGenerator.pv"
    FILE* header_file = 0;
    #line 74 "src/compiler/FileGenerator.pv"
    char const* header_tmp = 0;
    #line 75 "src/compiler/FileGenerator.pv"
    header_tmp = tmpnam(0);
    #line 76 "src/compiler/FileGenerator.pv"
    header_file = fopen(header_tmp, "w+");

    #line 78 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 78 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 78 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 80 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 81 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name_str);
    #line 82 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 83 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name_str);
    #line 84 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 86 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_code, 0);
    #line 87 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->signature, generics, false);

    #line 89 "src/compiler/FileGenerator.pv"
    if (Generator__is_coroutine(g)) {
        #line 90 "src/compiler/FileGenerator.pv"
        DefinitionWriter__write_function_coroutine(&defs, header_file, func_info, generics);
    }

    #line 93 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_function_definition(&defs, header_file, func_info, generics, 0)) {
        #line 93 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 93 "src/compiler/FileGenerator.pv"
        return false;
    }
    #line 94 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 96 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 98 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 99 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 100 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 102 "src/compiler/FileGenerator.pv"
    g->function_context = 0;

    #line 104 "src/compiler/FileGenerator.pv"
    return true;
}

#line 107 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum_loop(struct FileGenerator* self, struct TypeUsage_Enum* usage) {
    #line 108 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 109 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 109 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 109 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 110 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_enum(self, usage, usage_context) && success;
    } }
    #line 112 "src/compiler/FileGenerator.pv"
    return success;
}

#line 115 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum(struct FileGenerator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context) {
    #line 116 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 117 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 118 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 119 "src/compiler/FileGenerator.pv"
    struct Enum* enum_info = usage->type;
    #line 120 "src/compiler/FileGenerator.pv"
    struct Module* module = enum_info->context->module;
    #line 121 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 123 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 124 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 125 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 126 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 127 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 127 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 127 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 129 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 130 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 131 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 132 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 133 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 135 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 136 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);

    #line 138 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_enum_definition(&defs, header_file, enum_info, usage, usage_context, &include_writer)) {
        #line 138 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 138 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 140 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 142 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 143 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 144 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 146 "src/compiler/FileGenerator.pv"
    if (enum_info->impls.length == 0) {
        #line 146 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 148 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, module, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 149 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 151 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 152 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 153 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 153 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 153 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 155 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 156 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &module->includes);
    #line 157 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 159 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 160 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 161 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 162 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 164 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, module, &enum_info->impls, &usage->impl_functions, generics, &include_writer)) {
        #line 164 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 164 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 166 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 167 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 168 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 170 "src/compiler/FileGenerator.pv"
    return true;
}

#line 173 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage) {
    #line 174 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 175 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 175 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 175 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 176 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_struct(self, usage, usage_context) && success;
    } }
    #line 178 "src/compiler/FileGenerator.pv"
    return success;
}

#line 181 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context) {
    #line 182 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 183 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 184 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 185 "src/compiler/FileGenerator.pv"
    struct Struct* struct_info = usage->type;
    #line 186 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 187 "src/compiler/FileGenerator.pv"
    struct Module* module = struct_info->module;
    #line 188 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 190 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 191 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 192 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 193 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 193 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 193 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 195 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 196 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 197 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 198 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 199 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 201 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || usage_context->cpp_usages.length > 0) {
        #line 202 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");

        #line 204 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 204 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 204 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;
            #line 204 "src/compiler/FileGenerator.pv"
            struct Type type = HashMapIter_str_Type__value(&__iter)->_1;

            #line 205 "src/compiler/FileGenerator.pv"
            switch (type.type) {
                #line 206 "src/compiler/FileGenerator.pv"
                case TYPE__CLASS_CPP: {
                    #line 206 "src/compiler/FileGenerator.pv"
                    struct ClassCpp* class_info = type.classcpp_value;
                    #line 207 "src/compiler/FileGenerator.pv"
                    if (class_info->is_struct) {
                        #line 208 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "struct %.*s;\n", (int32_t)(name.length), name.ptr);
                    } else {
                        #line 210 "src/compiler/FileGenerator.pv"
                        fprintf(header_file, "class %.*s;\n", (int32_t)(name.length), name.ptr);
                    }
                } break;
                #line 213 "src/compiler/FileGenerator.pv"
                default: {
                } break;
            }
        } }

        #line 217 "src/compiler/FileGenerator.pv"
        if (struct_info->module->mode_cpp) {
            #line 218 "src/compiler/FileGenerator.pv"
            if (usage_context->cpp_usages.length > 0) {
                #line 218 "src/compiler/FileGenerator.pv"
                fprintf(header_file, "\n");
            }
            #line 219 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "extern \"C\" {\n");
        }

        #line 222 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#else\n");

        #line 224 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(&usage_context->cpp_usages);
        #line 224 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Type__next(&__iter)) {
            #line 224 "src/compiler/FileGenerator.pv"
            struct str name = HashMapIter_str_Type__value(&__iter)->_0;

            #line 225 "src/compiler/FileGenerator.pv"
            fprintf(header_file, "typedef struct %.*s %.*s;\n", (int32_t)(name.length), name.ptr, (int32_t)(name.length), name.ptr);
        } }

        #line 228 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    } else if (g->root->mode_cpp) {
        #line 230 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 231 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 232 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 235 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 236 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);
    #line 237 "src/compiler/FileGenerator.pv"
    if (usage_context->layout.length > 0) {
        #line 237 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n");
    }

    #line 239 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_struct_definition(&defs, header_file, struct_info, usage, usage_context)) {
        #line 239 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 239 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 241 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp || g->root->mode_cpp) {
        #line 242 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 243 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 244 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 247 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 249 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 250 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 251 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 253 "src/compiler/FileGenerator.pv"
    if (struct_info->impls.length == 0 && !usage->impl_dynamic_usage) {
        #line 254 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 257 "src/compiler/FileGenerator.pv"
    struct str ext;
    #line 258 "src/compiler/FileGenerator.pv"
    if (struct_info->module->mode_cpp) {
        #line 259 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".cpp", .length = strlen(".cpp") };
    } else {
        #line 261 "src/compiler/FileGenerator.pv"
        ext = (struct str){ .ptr = ".c", .length = strlen(".c") };
    }

    #line 264 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, struct_info->module, String__as_str(&name), ext);
    #line 265 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 267 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 268 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 269 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 269 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 269 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 271 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 272 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &struct_info->module->includes);
    #line 273 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 275 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, struct_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 276 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 277 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 278 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 280 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, struct_info->module, &struct_info->impls, &usage->impl_functions, generics, &include_writer)) {
        #line 280 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 280 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 282 "src/compiler/FileGenerator.pv"
    if (struct_info->traits.length > 0) {
        #line 283 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");
    }

    #line 286 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_tuple_ref_Trait_ref_Type __iter = HashMap_str_tuple_ref_Trait_ref_Type__iter(&struct_info->traits);
    #line 286 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_tuple_ref_Trait_ref_Type__next(&__iter)) {
        #line 286 "src/compiler/FileGenerator.pv"
        struct tuple_ref_Trait_ref_Type trait_entry = HashMapIter_str_tuple_ref_Trait_ref_Type__value(&__iter)->_1;

        #line 287 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = trait_entry._0;
        #line 288 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct ");
        #line 289 "src/compiler/FileGenerator.pv"
        Generator__write_type_name(g, code_file, trait_entry._1, generics);
        #line 290 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 291 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, String__as_str(&name));
        #line 292 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 293 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, trait_info->name->value);
        #line 294 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 296 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 297 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 297 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 297 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 298 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 298 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 299 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 301 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".");
            #line 302 "src/compiler/FileGenerator.pv"
            Generator__write_token(g, code_file, func_info->name);
            #line 303 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 304 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(g, String__as_str(&name), trait_info, trait_entry._1, func_info, generics);
            #line 305 "src/compiler/FileGenerator.pv"
            Generator__write_string(g, code_file, &func_name);
        } }

        #line 308 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 311 "src/compiler/FileGenerator.pv"
    if (usage->impl_dynamic_usage) {
        #line 312 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\n");

        #line 314 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <tuple_usize_str_TypeId.h>\n");
        #line 315 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "#include <slice_tuple_usize_str_TypeId.h>\n");
        #line 316 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct slice_tuple_usize_str_TypeId ");
        #line 317 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 318 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields(void* __self) {\n");

        #line 320 "src/compiler/FileGenerator.pv"
        g->indent += 1;
        #line 321 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 322 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "static struct tuple_usize_str_TypeId fields[] = { ");

        #line 324 "src/compiler/FileGenerator.pv"
        uintptr_t field_index = 0;
        #line 325 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 325 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 325 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 326 "src/compiler/FileGenerator.pv"
            if (field_index > 0) {
                #line 326 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }
            #line 327 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "(struct tuple_usize_str_TypeId){ ._0 = %zu, ._1 = (struct str){ .ptr = \"", field_index);
            #line 328 "src/compiler/FileGenerator.pv"
            Generator__write_token(g, code_file, field->name);
            #line 329 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "\", .length = %zu }, ._2 = ", field->name->value.length);
            #line 330 "src/compiler/FileGenerator.pv"
            Generator__write_typeid(g, code_file, &field->type, generics);
            #line 331 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " }");
            #line 332 "src/compiler/FileGenerator.pv"
            field_index += 1;
        } }

        #line 335 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
        #line 336 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 337 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return (struct slice_tuple_usize_str_TypeId){ .data = fields, .length = %zu };\n", struct_info->fields.length);
        #line 338 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 339 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 341 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "void* ");
        #line 342 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 343 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field(void* __self, uintptr_t index) {\n");

        #line 345 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 347 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 348 "src/compiler/FileGenerator.pv"
        Generator__write_type(g, code_file, &(struct Type) { .type = TYPE__SELF }, generics);

        #line 350 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 351 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 352 "src/compiler/FileGenerator.pv"
            Generator__write_type(g, code_file, &(struct Type) { .type = TYPE__SELF }, generics);
            #line 353 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 355 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 358 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 359 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 360 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 362 "src/compiler/FileGenerator.pv"
        uintptr_t i = 0;
        #line 363 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 363 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 363 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 364 "src/compiler/FileGenerator.pv"
            Generator__write_indent(g, code_file);
            #line 365 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "case %zu: return ", i);

            #line 367 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 368 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self");
            } else {
                #line 370 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 371 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "&");
                }

                #line 374 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "self->");
                #line 375 "src/compiler/FileGenerator.pv"
                Generator__write_token(g, code_file, field->name);
            }

            #line 378 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ";\n");
            #line 379 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 382 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 383 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 384 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 386 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 387 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return 0;\n");

        #line 389 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 390 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 392 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "bool ");
        #line 393 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 394 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field(void* __self, uintptr_t index, void* value) {\n");

        #line 396 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 398 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 399 "src/compiler/FileGenerator.pv"
        Generator__write_type(g, code_file, &(struct Type) { .type = TYPE__SELF }, generics);

        #line 401 "src/compiler/FileGenerator.pv"
        if (module->mode_cpp) {
            #line 402 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = (");
            #line 403 "src/compiler/FileGenerator.pv"
            Generator__write_type(g, code_file, &(struct Type) { .type = TYPE__SELF }, generics);
            #line 404 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "*)__self;\n");
        } else {
            #line 406 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "* self = __self;\n");
        }

        #line 409 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 410 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "switch (index) {\n");
        #line 411 "src/compiler/FileGenerator.pv"
        g->indent += 1;

        #line 413 "src/compiler/FileGenerator.pv"
        i = 0;
        #line 414 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_StructField __iter = HashMap_str_StructField__iter(&struct_info->fields);
        #line 414 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_StructField__next(&__iter)) {
            #line 414 "src/compiler/FileGenerator.pv"
            struct StructField* field = &HashMapIter_str_StructField__value(&__iter)->_1;

            #line 415 "src/compiler/FileGenerator.pv"
            if (Type__is_sequence(&field->type)) {
                #line 415 "src/compiler/FileGenerator.pv"
                continue;
            }

            #line 417 "src/compiler/FileGenerator.pv"
            Generator__write_indent(g, code_file);

            #line 419 "src/compiler/FileGenerator.pv"
            if (Struct__is_newtype(struct_info)) {
                #line 420 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: *self = *(", i);
                #line 421 "src/compiler/FileGenerator.pv"
                Generator__write_type(g, code_file, &field->type, generics);
                #line 422 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "*)");
            } else {
                #line 424 "src/compiler/FileGenerator.pv"
                fprintf(code_file, "case %zu: self->", i);
                #line 425 "src/compiler/FileGenerator.pv"
                Generator__write_token(g, code_file, field->name);
                #line 426 "src/compiler/FileGenerator.pv"
                fprintf(code_file, " = ");

                #line 428 "src/compiler/FileGenerator.pv"
                if (!Generator__is_reference(&field->type) || Type__is_fat_pointer(&field->type)) {
                    #line 429 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*(");
                    #line 430 "src/compiler/FileGenerator.pv"
                    Generator__write_type(g, code_file, &field->type, generics);
                    #line 431 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "*)");
                } else if (module->mode_cpp) {
                    #line 433 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, "(");
                    #line 434 "src/compiler/FileGenerator.pv"
                    Generator__write_type(g, code_file, &field->type, generics);
                    #line 435 "src/compiler/FileGenerator.pv"
                    fprintf(code_file, ")");
                }
            }

            #line 439 "src/compiler/FileGenerator.pv"
            fprintf(code_file, "value; return true;\n");
            #line 440 "src/compiler/FileGenerator.pv"
            i += 1;
        } }

        #line 443 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 444 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 445 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 447 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, code_file);
        #line 448 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "return false;\n");

        #line 450 "src/compiler/FileGenerator.pv"
        g->indent -= 1;
        #line 451 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "}\n");

        #line 453 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "struct trait_StructVTable ");
        #line 454 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, String__as_str(&name));
        #line 455 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__STRUCT");
        #line 456 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { .get_fields = &");
        #line 457 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 458 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_fields, .get_field = &");
        #line 459 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 460 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__get_field, .set_field = &");
        #line 461 "src/compiler/FileGenerator.pv"
        Generator__write_string(g, code_file, &name);
        #line 462 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__Struct__set_field };\n");
    }

    #line 465 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 466 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 467 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 469 "src/compiler/FileGenerator.pv"
    return true;
}

#line 472 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage) {
    #line 473 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 474 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 474 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 474 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 475 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_primitive(self, usage, usage_context) && success;
    } }
    #line 477 "src/compiler/FileGenerator.pv"
    return success;
}

#line 480 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context) {
    #line 481 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 482 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 483 "src/compiler/FileGenerator.pv"
    struct Primitive* primitive_info = usage->type;
    #line 484 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 485 "src/compiler/FileGenerator.pv"
    struct str name = primitive_info->name;
    #line 486 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 488 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 489 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 490 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 491 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 491 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 491 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 493 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 494 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 495 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 496 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 497 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 499 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(g, header_file, &primitive_info->impls);
    #line 500 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 501 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->signature, generics, false);

    #line 503 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_primitive_definition(&defs, header_file, primitive_info, generics)) {
        #line 503 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 503 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 505 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 507 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 508 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 509 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 511 "src/compiler/FileGenerator.pv"
    if (primitive_info->impls.length == 0) {
        #line 512 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 515 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, 0, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 516 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 518 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 519 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 520 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 520 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 520 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 522 "src/compiler/FileGenerator.pv"
    Generator__write_impl_includes_raw(g, code_file, &primitive_info->impls);
    #line 523 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, code_file, &usage_context->primitive_code, &usage_context->primitive_header);
    #line 524 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, code_file, g, &usage_context->body, generics, true);

    #line 526 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, 0, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 527 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 528 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 529 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 531 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &primitive_info->impls, &usage->impl_functions, generics, &include_writer)) {
        #line 531 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 531 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 533 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Trait __iter = HashMap_str_ref_Trait__iter(&primitive_info->traits);
    #line 533 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Trait__next(&__iter)) {
        #line 533 "src/compiler/FileGenerator.pv"
        struct Trait* trait_info = HashMapIter_str_ref_Trait__value(&__iter)->_1;

        #line 534 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "\nstruct trait_");
        #line 535 "src/compiler/FileGenerator.pv"
        Generator__write_token(g, code_file, trait_info->name);
        #line 536 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "VTable ");
        #line 537 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, name);
        #line 538 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "__VTABLE__");
        #line 539 "src/compiler/FileGenerator.pv"
        Generator__write_str_title(g, code_file, trait_info->name->value);
        #line 540 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = { ");

        #line 542 "src/compiler/FileGenerator.pv"
        bool first = true;
        #line 543 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_Function __iter = HashMap_str_Function__iter(&trait_info->functions);
        #line 543 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_Function__next(&__iter)) {
            #line 543 "src/compiler/FileGenerator.pv"
            struct Function* func_info = &HashMapIter_str_Function__value(&__iter)->_1;

            #line 544 "src/compiler/FileGenerator.pv"
            if (first) {
                #line 544 "src/compiler/FileGenerator.pv"
                first = false;
            } else {
                #line 545 "src/compiler/FileGenerator.pv"
                fprintf(code_file, ", ");
            }

            #line 547 "src/compiler/FileGenerator.pv"
            fprintf(code_file, ".");
            #line 548 "src/compiler/FileGenerator.pv"
            Generator__write_token(g, code_file, func_info->name);
            #line 549 "src/compiler/FileGenerator.pv"
            fprintf(code_file, " = &");
            #line 550 "src/compiler/FileGenerator.pv"
            struct String func_name = Generator__get_trait_function_name(g, name, trait_info, 0, func_info, generics);
            #line 551 "src/compiler/FileGenerator.pv"
            Generator__write_string(g, code_file, &func_name);
        } }

        #line 554 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " };\n");
    } }

    #line 557 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 558 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 559 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 561 "src/compiler/FileGenerator.pv"
    return true;
}

#line 564 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage) {
    #line 565 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 566 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 566 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 566 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 567 "src/compiler/FileGenerator.pv"
        switch (usage->type->type.type) {
            #line 568 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__SLICE: {
                #line 569 "src/compiler/FileGenerator.pv"
                success = FileGenerator__generate_slice(self, usage, usage_context) && success;
            } break;
            #line 571 "src/compiler/FileGenerator.pv"
            case SEQUENCE_TYPE__FIXED_ARRAY: {
            } break;
        }
    } }
    #line 574 "src/compiler/FileGenerator.pv"
    return success;
}

#line 577 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context) {
    #line 578 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 579 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 580 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 581 "src/compiler/FileGenerator.pv"
    struct Type* element_type = &usage->type->element;

    #line 583 "src/compiler/FileGenerator.pv"
    struct Indirect element_indirect = (struct Indirect) { .type = INDIRECT_TYPE__REFERENCE, .to = *element_type };
    #line 584 "src/compiler/FileGenerator.pv"
    struct Type element_reference_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = &element_indirect };

    #line 586 "src/compiler/FileGenerator.pv"
    struct Type sequence_type = (struct Type) { .type = TYPE__SEQUENCE, .sequence_value = usage->type };
    #line 587 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, &sequence_type, &sequence_type, generics);
    #line 588 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 590 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 591 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 592 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 593 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 593 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 593 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 595 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 596 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 597 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 598 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 599 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 601 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 602 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);

    #line 604 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 605 "src/compiler/FileGenerator.pv"
    Generator__write_string(g, header_file, &name);
    #line 606 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " { ");

    #line 608 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, header_file, (struct str){ .ptr = "data", .length = strlen("data") }, &element_reference_type, generics);
    #line 609 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; ");
    #line 610 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, header_file, (struct str){ .ptr = "length", .length = strlen("length") }, &g->root->type_usize, generics);

    #line 612 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "; };\n");

    #line 614 "src/compiler/FileGenerator.pv"
    DefinitionWriter__write_impl_definition(&defs, header_file, String__as_str(&name), g->root->hack_type_impl->impl_info, generics);

    #line 616 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 618 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 619 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 620 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 622 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 623 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 625 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 626 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 627 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 627 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 627 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 629 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 630 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 631 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 632 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ">\n\n");

    #line 634 "src/compiler/FileGenerator.pv"
    struct Impl* impls_base[1] = {g->root->hack_type_impl->impl_info};
    #line 635 "src/compiler/FileGenerator.pv"
    struct Array_ref_Impl impls = (struct Array_ref_Impl) { .data = impls_base, .length = 1 };
    #line 636 "src/compiler/FileGenerator.pv"
    struct Array_HashMap_usize_TypeFunctionUsage impl_functions = (struct Array_HashMap_usize_TypeFunctionUsage) { .data = 0, .length = 0 };

    #line 638 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_impls(&defs, code_file, 0, &impls, &impl_functions, generics, &include_writer)) {
        #line 638 "src/compiler/FileGenerator.pv"
        fclose(code_file);
        #line 638 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 640 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 641 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 642 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 644 "src/compiler/FileGenerator.pv"
    return true;
}

#line 647 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage) {
    #line 648 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 649 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 649 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 649 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 650 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_tuple(self, usage, usage_context) && success;
    } }
    #line 652 "src/compiler/FileGenerator.pv"
    return success;
}

#line 655 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context) {
    #line 656 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 657 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 658 "src/compiler/FileGenerator.pv"
    struct Tuple* tuple = usage->type;
    #line 659 "src/compiler/FileGenerator.pv"
    struct Array_Type* element_types = &tuple->elements;
    #line 660 "src/compiler/FileGenerator.pv"
    struct Type tuple_type = (struct Type) { .type = TYPE__TUPLE, .tuple_value = tuple };

    #line 662 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, &tuple_type, &tuple_type, generics);
    #line 663 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 665 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, 0, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 666 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 667 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 668 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 668 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 668 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 670 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 671 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 672 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 673 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 674 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 676 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 677 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->layout, generics, false);

    #line 679 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "struct ");
    #line 680 "src/compiler/FileGenerator.pv"
    Generator__write_string(g, header_file, &name);
    #line 681 "src/compiler/FileGenerator.pv"
    fprintf(header_file, " {\n");
    #line 682 "src/compiler/FileGenerator.pv"
    g->indent += 1;

    #line 684 "src/compiler/FileGenerator.pv"
    { struct IterEnumerate_ref_Type __iter = Iter_ref_Type__enumerate(Array_Type__iter(element_types));
    #line 684 "src/compiler/FileGenerator.pv"
    while (IterEnumerate_ref_Type__next(&__iter)) {
        #line 684 "src/compiler/FileGenerator.pv"
        uintptr_t i = IterEnumerate_ref_Type__value(&__iter)._0;
        #line 684 "src/compiler/FileGenerator.pv"
        struct Type* element = IterEnumerate_ref_Type__value(&__iter)._1;

        #line 685 "src/compiler/FileGenerator.pv"
        struct String element_name = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = g->allocator });
        #line 686 "src/compiler/FileGenerator.pv"
        String__append(&element_name, (struct str){ .ptr = "_", .length = strlen("_") });
        #line 687 "src/compiler/FileGenerator.pv"
        String__append_usize(&element_name, i);

        #line 689 "src/compiler/FileGenerator.pv"
        Generator__write_indent(g, header_file);
        #line 690 "src/compiler/FileGenerator.pv"
        Generator__write_variable_decl(g, header_file, String__as_str(&element_name), element, generics);
        #line 691 "src/compiler/FileGenerator.pv"
        fprintf(header_file, ";\n");
        #line 692 "src/compiler/FileGenerator.pv"
        String__release(&element_name);
    } }

    #line 695 "src/compiler/FileGenerator.pv"
    g->indent -= 1;
    #line 696 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "};\n");

    #line 698 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 700 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 701 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 702 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 704 "src/compiler/FileGenerator.pv"
    return true;
}

#line 707 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage) {
    #line 708 "src/compiler/FileGenerator.pv"
    bool success = true;
    #line 709 "src/compiler/FileGenerator.pv"
    { struct Iter_ref_UsageContext __iter = Array_UsageContext__iter(&usage->usage_contexts);
    #line 709 "src/compiler/FileGenerator.pv"
    while (Iter_ref_UsageContext__next(&__iter)) {
        #line 709 "src/compiler/FileGenerator.pv"
        struct UsageContext* usage_context = Iter_ref_UsageContext__value(&__iter);

        #line 710 "src/compiler/FileGenerator.pv"
        success = FileGenerator__generate_trait(self, usage, usage_context) && success;
    } }
    #line 712 "src/compiler/FileGenerator.pv"
    return success;
}

#line 715 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context) {
    #line 716 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 717 "src/compiler/FileGenerator.pv"
    struct DefinitionWriter defs = (struct DefinitionWriter) { .generator = g };
    #line 718 "src/compiler/FileGenerator.pv"
    struct GenericMap* generics = usage_context->generic_map;
    #line 719 "src/compiler/FileGenerator.pv"
    struct Trait* trait_info = usage->type;

    #line 721 "src/compiler/FileGenerator.pv"
    struct String name = Naming__get_type_name(&g->naming_ident, generics->self_type, generics->self_type, generics);
    #line 722 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, trait_info->module, String__as_str(&name), (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 723 "src/compiler/FileGenerator.pv"
    struct IncludeWriter include_writer = IncludeWriter__new(g->allocator);

    #line 725 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 726 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 727 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 727 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 727 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 729 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 730 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 731 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 732 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, String__as_str(&name));
    #line 733 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 735 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 736 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#ifdef __cplusplus\n");
        #line 737 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "extern \"C\" {\n");
        #line 738 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n\n");
    }

    #line 741 "src/compiler/FileGenerator.pv"
    Generator__write_context_primitives(g, header_file, &usage_context->primitive_header, 0);
    #line 742 "src/compiler/FileGenerator.pv"
    IncludeWriter__write(&include_writer, header_file, g, &usage_context->signature, generics, false);

    #line 744 "src/compiler/FileGenerator.pv"
    if (!DefinitionWriter__write_trait_definition(&defs, header_file, trait_info, generics)) {
        #line 744 "src/compiler/FileGenerator.pv"
        fclose(header_file);
        #line 744 "src/compiler/FileGenerator.pv"
        return false;
    }

    #line 746 "src/compiler/FileGenerator.pv"
    if (trait_info->module->mode_cpp) {
        #line 747 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "\n#ifdef __cplusplus\n");
        #line 748 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "}\n");
        #line 749 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#endif\n");
    }

    #line 752 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 754 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 755 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 756 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 758 "src/compiler/FileGenerator.pv"
    return true;
}

#line 761 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global) {
    bool __result;

    #line 762 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 763 "src/compiler/FileGenerator.pv"
    if (Type__is_unknown(&global->type)) {
        #line 763 "src/compiler/FileGenerator.pv"
        return true;
    }

    #line 765 "src/compiler/FileGenerator.pv"
    struct str name = global->name->value;

    #line 767 "src/compiler/FileGenerator.pv"
    struct GenericMap* blank_generics = ArenaAllocator__store_GenericMap(g->allocator, &(struct GenericMap) {});
    #line 768 "src/compiler/FileGenerator.pv"
    blank_generics->self_type = Type__to_ptr(&(struct Type) { .type = TYPE__SELF }, g->allocator);

    #line 770 "src/compiler/FileGenerator.pv"
    struct FunctionContext func_ctx = FunctionContext__new_const(g->allocator);
    #line 771 "src/compiler/FileGenerator.pv"
    g->function_context = &func_ctx;

    #line 773 "src/compiler/FileGenerator.pv"
    struct HashSet_str primitive_includes = HashSet_str__new(g->allocator);

    #line 775 "src/compiler/FileGenerator.pv"
    Generator__collect_primitive_includes(g, &global->type, blank_generics, &primitive_includes);

    #line 777 "src/compiler/FileGenerator.pv"
    struct String header = Generator__make_path(g, global->module, name, (struct str){ .ptr = ".h", .length = strlen(".h") });
    #line 778 "src/compiler/FileGenerator.pv"
    char const* header_tmp = tmpnam(0);
    #line 779 "src/compiler/FileGenerator.pv"
    FILE* header_file = fopen(header_tmp, "w+");
    #line 780 "src/compiler/FileGenerator.pv"
    if (header_file == 0) {
        #line 780 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&header));
        #line 780 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 782 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "#ifndef PAVE_");
    #line 783 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 784 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#define PAVE_");
    #line 785 "src/compiler/FileGenerator.pv"
    Generator__write_str_title(g, header_file, name);
    #line 786 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n\n");

    #line 788 "src/compiler/FileGenerator.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&primitive_includes);
    #line 788 "src/compiler/FileGenerator.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 788 "src/compiler/FileGenerator.pv"
        struct str inc = *HashSetIter_str__value(&__iter);

        #line 789 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "#include <%.*s.h>\n", (int32_t)(inc.length), inc.ptr);
    } }

    #line 792 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\nextern ");
    #line 793 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 793 "src/compiler/FileGenerator.pv"
        fprintf(header_file, "const ");
    }
    #line 794 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, header_file, name, &global->type, blank_generics);
    #line 795 "src/compiler/FileGenerator.pv"
    fprintf(header_file, ";\n");

    #line 797 "src/compiler/FileGenerator.pv"
    fprintf(header_file, "\n#endif\n");

    #line 799 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&header), header_file);
    #line 800 "src/compiler/FileGenerator.pv"
    fclose(header_file);
    #line 801 "src/compiler/FileGenerator.pv"
    remove(header_tmp);

    #line 803 "src/compiler/FileGenerator.pv"
    struct String code = Generator__make_path(g, global->module, name, (struct str){ .ptr = ".c", .length = strlen(".c") });
    #line 804 "src/compiler/FileGenerator.pv"
    char const* code_tmp = tmpnam(0);
    #line 805 "src/compiler/FileGenerator.pv"
    FILE* code_file = fopen(code_tmp, "w+");
    #line 806 "src/compiler/FileGenerator.pv"
    if (code_file == 0) {
        #line 806 "src/compiler/FileGenerator.pv"
        perror(String__c_str(&code));
        #line 806 "src/compiler/FileGenerator.pv"
        __result = false;
        HashSet_str__release(&primitive_includes);
        return __result;
    }

    #line 808 "src/compiler/FileGenerator.pv"
    Generator__write_includes_raw(g, code_file, &global->module->includes);

    #line 810 "src/compiler/FileGenerator.pv"
    struct String header_rel = Generator__make_rel_path(g, global->module, name, (struct str){ .ptr = "", .length = strlen("") });
    #line 811 "src/compiler/FileGenerator.pv"
    fprintf(code_file, "#include <");
    #line 812 "src/compiler/FileGenerator.pv"
    Generator__write_str(g, code_file, String__as_str(&header_rel));
    #line 813 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ".h>\n\n");

    #line 815 "src/compiler/FileGenerator.pv"
    if (global->is_const) {
        #line 815 "src/compiler/FileGenerator.pv"
        fprintf(code_file, "const ");
    }
    #line 816 "src/compiler/FileGenerator.pv"
    Generator__write_variable_decl(g, code_file, name, &global->type, blank_generics);
    #line 817 "src/compiler/FileGenerator.pv"
    if (global->value != 0) {
        #line 818 "src/compiler/FileGenerator.pv"
        fprintf(code_file, " = ");
        #line 819 "src/compiler/FileGenerator.pv"
        ExpressionWriter__write_expression(&(struct ExpressionWriter) { .generator = g }, code_file, global->value, blank_generics);
    }
    #line 821 "src/compiler/FileGenerator.pv"
    fprintf(code_file, ";\n");

    #line 823 "src/compiler/FileGenerator.pv"
    Generator__overwrite_if_different(g, String__c_str(&code), code_file);
    #line 824 "src/compiler/FileGenerator.pv"
    fclose(code_file);
    #line 825 "src/compiler/FileGenerator.pv"
    remove(code_tmp);

    #line 827 "src/compiler/FileGenerator.pv"
    Array_String__append(&g->code_files, code);

    #line 829 "src/compiler/FileGenerator.pv"
    g->function_context = 0;

    #line 831 "src/compiler/FileGenerator.pv"
    __result = true;
    HashSet_str__release(&primitive_includes);
    return __result;
}

#line 834 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children) {
    #line 835 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 835 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 835 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 836 "src/compiler/FileGenerator.pv"
        { struct HashMapIter_str_ref_Module __iter = HashMap_str_ref_Module__iter(&namespace->modules);
        #line 836 "src/compiler/FileGenerator.pv"
        while (HashMapIter_str_ref_Module__next(&__iter)) {
            #line 836 "src/compiler/FileGenerator.pv"
            struct Module* module = HashMapIter_str_ref_Module__value(&__iter)->_1;

            #line 837 "src/compiler/FileGenerator.pv"
            { struct HashMapIter_str_ref_Global __iter = HashMap_str_ref_Global__iter(&module->globals);
            #line 837 "src/compiler/FileGenerator.pv"
            while (HashMapIter_str_ref_Global__next(&__iter)) {
                #line 837 "src/compiler/FileGenerator.pv"
                struct Global* global = HashMapIter_str_ref_Global__value(&__iter)->_1;

                #line 838 "src/compiler/FileGenerator.pv"
                FileGenerator__generate_global(self, global);
            } }
        } }

        #line 842 "src/compiler/FileGenerator.pv"
        FileGenerator__generate_globals_namespace(self, &namespace->children);
    } }
}

#line 846 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children) {
    #line 847 "src/compiler/FileGenerator.pv"
    struct Generator* g = self->generator;
    #line 848 "src/compiler/FileGenerator.pv"
    { struct HashMapIter_str_ref_Namespace __iter = HashMap_str_ref_Namespace__iter(children);
    #line 848 "src/compiler/FileGenerator.pv"
    while (HashMapIter_str_ref_Namespace__next(&__iter)) {
        #line 848 "src/compiler/FileGenerator.pv"
        struct str name = HashMapIter_str_ref_Namespace__value(&__iter)->_0;
        #line 848 "src/compiler/FileGenerator.pv"
        struct Namespace* namespace = HashMapIter_str_ref_Namespace__value(&__iter)->_1;

        #line 849 "src/compiler/FileGenerator.pv"
        struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = g->allocator });
        #line 850 "src/compiler/FileGenerator.pv"
        String__append(&path, base_path);
        #line 851 "src/compiler/FileGenerator.pv"
        String__append(&path, (struct str){ .ptr = "/", .length = strlen("/") });
        #line 852 "src/compiler/FileGenerator.pv"
        String__append(&path, name);
        #line 853 "src/compiler/FileGenerator.pv"
        create_directory(String__c_str(&path));

        #line 855 "src/compiler/FileGenerator.pv"
        FileGenerator__create_directories(self, String__as_str(&path), &namespace->children);
    } }
}
