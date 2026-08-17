#ifndef PAVE_FILE_GENERATOR
#define PAVE_FILE_GENERATOR

#include <stdbool.h>

struct Generator;

#line 11 "src/compiler/FileGenerator.pv"
struct FileGenerator {
    struct Generator* generator;
};

#include <stdio.h>
#include <std/str.h>
struct Generator;
struct TypeFunctionUsage;
struct UsageContext;
struct TypeUsage_Enum;
struct TypeUsage_Struct;
struct Type;
struct GenericMap;
struct TypeUsage_Primitive;
struct TypeUsage_Sequence;
struct TypeUsage_Tuple;
struct TypeUsage_Trait;
struct TypeUsage_TypeImpl;
struct Global;
struct HashMap_str_ref_Namespace;
struct Array_str;

#line 16 "src/compiler/FileGenerator.pv"
struct FileGenerator FileGenerator__new(struct Generator* generator);

#line 20 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_function_loop(struct FileGenerator* self, struct TypeFunctionUsage* usage);

#line 28 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_function(struct FileGenerator* self, struct TypeFunctionUsage* usage, struct UsageContext* usage_context);

#line 120 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum_loop(struct FileGenerator* self, struct TypeUsage_Enum* usage);

#line 128 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_enum(struct FileGenerator* self, struct TypeUsage_Enum* usage, struct UsageContext* usage_context);

#line 529 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct_loop(struct FileGenerator* self, struct TypeUsage_Struct* usage);

#line 537 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_struct(struct FileGenerator* self, struct TypeUsage_Struct* usage, struct UsageContext* usage_context);

#line 907 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_extern(struct FileGenerator* self, FILE* file, struct str name);

#line 917 "src/compiler/FileGenerator.pv"
void FileGenerator__write_any_definition(struct FileGenerator* self, FILE* file, struct str name, struct Type* self_type, struct GenericMap* generics);

#line 934 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive_loop(struct FileGenerator* self, struct TypeUsage_Primitive* usage);

#line 942 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_primitive(struct FileGenerator* self, struct TypeUsage_Primitive* usage, struct UsageContext* usage_context);

#line 1046 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_sequence(struct FileGenerator* self, struct TypeUsage_Sequence* usage);

#line 1059 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_slice(struct FileGenerator* self, struct TypeUsage_Sequence* usage, struct UsageContext* usage_context);

#line 1136 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple_loop(struct FileGenerator* self, struct TypeUsage_Tuple* usage);

#line 1144 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_tuple(struct FileGenerator* self, struct TypeUsage_Tuple* usage, struct UsageContext* usage_context);

#line 1194 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait_loop(struct FileGenerator* self, struct TypeUsage_Trait* usage);

#line 1202 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl_loop(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage);

#line 1210 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_type_impl(struct FileGenerator* self, struct TypeUsage_TypeImpl* usage, struct UsageContext* usage_context);

#line 1273 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_trait(struct FileGenerator* self, struct TypeUsage_Trait* usage, struct UsageContext* usage_context);

#line 1319 "src/compiler/FileGenerator.pv"
bool FileGenerator__generate_global(struct FileGenerator* self, struct Global* global);

#line 1392 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_globals_namespace(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children);

#line 1404 "src/compiler/FileGenerator.pv"
void FileGenerator__collect_tests(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children, struct Array_str* func_names, struct Array_str* descriptions, struct Array_str* header_paths, struct Array_str* module_paths);

#line 1426 "src/compiler/FileGenerator.pv"
void FileGenerator__generate_test_runner(struct FileGenerator* self, struct HashMap_str_ref_Namespace* children);

#line 1490 "src/compiler/FileGenerator.pv"
void FileGenerator__create_directories(struct FileGenerator* self, struct str base_path, struct HashMap_str_ref_Namespace* children);

#endif
