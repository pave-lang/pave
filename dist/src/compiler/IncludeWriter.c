#include <string.h>
#include <stdint.h>

#include <stdio.h>
#include <compiler/IncludeWriter.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <analyzer/types/Type.h>
#include <analyzer/Context.h>
#include <analyzer/types/GenericMap.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <compiler/Generator.h>
#include <analyzer/Module.h>
#include <std/str.h>
#include <analyzer/types/Struct.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/types/StructField.h>
#include <std/HashMapBucket_str_StructField.h>
#include <std/HashMap_str_StructField.h>
#include <analyzer/types/Enum.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/ClassCpp.h>
#include <std/HashSetIter_str.h>
#include <compiler/IncludeWriter.h>

#include <compiler/IncludeWriter.h>

#line 16 "src/compiler/IncludeWriter.pv"
struct IncludeWriter IncludeWriter__new(struct ArenaAllocator* allocator) {
    #line 17 "src/compiler/IncludeWriter.pv"
    return (struct IncludeWriter) {
        .allocator = allocator,
        .c_includes = HashSet_str__new(allocator),
        .includes = HashSet_str__new(allocator),
        .type_declarations = HashSet_str__new(allocator),
    };
}

#line 25 "src/compiler/IncludeWriter.pv"
void IncludeWriter__write(struct IncludeWriter* self, FILE* file, struct Generator* generator, struct HashMap_str_Type* types, struct GenericMap* generics, bool deref) {
    #line 26 "src/compiler/IncludeWriter.pv"
    struct HashSet_str c_includes = HashSet_str__new(self->allocator);

    #line 28 "src/compiler/IncludeWriter.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);

    #line 30 "src/compiler/IncludeWriter.pv"
    struct HashSet_str type_declarations = HashSet_str__new(self->allocator);

    #line 33 "src/compiler/IncludeWriter.pv"
    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(types);
    #line 33 "src/compiler/IncludeWriter.pv"
    while (HashMapIter_str_Type__next(&__iter)) {
        #line 33 "src/compiler/IncludeWriter.pv"
        struct Type* type = &HashMapIter_str_Type__value(&__iter)->_1;

        #line 34 "src/compiler/IncludeWriter.pv"
        struct Type* resolved = Context__resolve_type(self->allocator, type, generics, 0);
        #line 35 "src/compiler/IncludeWriter.pv"
        if (deref) {
            #line 35 "src/compiler/IncludeWriter.pv"
            resolved = Type__deref_all(resolved);
        }

        #line 37 "src/compiler/IncludeWriter.pv"
        switch (resolved->type) {
            #line 38 "src/compiler/IncludeWriter.pv"
            case TYPE__INDIRECT: {
                #line 39 "src/compiler/IncludeWriter.pv"
                struct Type* type_deref = Type__deref_all(resolved);

                #line 41 "src/compiler/IncludeWriter.pv"
                switch (type_deref->type) {
                    #line 42 "src/compiler/IncludeWriter.pv"
                    case TYPE__TRAIT: {
                        #line 43 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                        #line 44 "src/compiler/IncludeWriter.pv"
                        struct Module* module = Type__get_module(type_deref);
                        #line 45 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 46 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 46 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 48 "src/compiler/IncludeWriter.pv"
                    case TYPE__STRUCT: {
                        #line 48 "src/compiler/IncludeWriter.pv"
                        struct Struct* struct_info = type_deref->struct_value._0;
                        #line 49 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);

                        #line 51 "src/compiler/IncludeWriter.pv"
                        if (Struct__is_newtype(struct_info)) {
                            #line 52 "src/compiler/IncludeWriter.pv"
                            struct TypedefC typedef_info = (struct TypedefC) { .name = String__as_str(&name), .type = &struct_info->fields.data[0].value.type };
                            #line 53 "src/compiler/IncludeWriter.pv"
                            struct Type typedef_type = (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = &typedef_info };
                            #line 54 "src/compiler/IncludeWriter.pv"
                            struct String type_declaration = Naming__get_type_decl(&generator->naming_c99, &typedef_type, generics->self_type, generics);
                            #line 55 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&type_declaration))) {
                                #line 55 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&type_declaration));
                            }
                        } else {
                            #line 57 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                                #line 57 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        }
                    } break;
                    #line 61 "src/compiler/IncludeWriter.pv"
                    case TYPE__ENUM: {
                        #line 61 "src/compiler/IncludeWriter.pv"
                        struct Enum* enum_info = type_deref->enum_value._0;
                        #line 62 "src/compiler/IncludeWriter.pv"
                        if (Enum__is_discriminated_union(enum_info)) {
                            #line 63 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                            #line 64 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&type_declarations, String__as_str(&name))) {
                                #line 64 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        } else {
                            #line 66 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                            #line 67 "src/compiler/IncludeWriter.pv"
                            struct Module* module = Type__get_module(type_deref);
                            #line 68 "src/compiler/IncludeWriter.pv"
                            struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                            #line 69 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                                #line 69 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&includes, String__as_str(&path));
                            }
                        }
                    } break;
                    #line 72 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 75 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION: {
                #line 75 "src/compiler/IncludeWriter.pv"
                struct Function* func_info = resolved->function_value._0;
                #line 76 "src/compiler/IncludeWriter.pv"
                switch (func_info->parent.type) {
                    #line 77 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 78 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, &(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = generics} }, generics->self_type, generics);
                        #line 79 "src/compiler/IncludeWriter.pv"
                        struct Module* module = func_info->context->module;
                        #line 80 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 81 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 81 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 83 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__PRIMITIVE: {
                        #line 83 "src/compiler/IncludeWriter.pv"
                        struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                        #line 84 "src/compiler/IncludeWriter.pv"
                        struct str name = primitive_info->name;
                        #line 85 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = "", .length = strlen("") });
                        #line 86 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 86 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 88 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__TRAIT: {
                    } break;
                    #line 89 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 93 "src/compiler/IncludeWriter.pv"
            case TYPE__ENUM_C: {
                #line 93 "src/compiler/IncludeWriter.pv"
                struct EnumC* info = resolved->enumc_value;
                #line 94 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 94 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 96 "src/compiler/IncludeWriter.pv"
            case TYPE__STRUCT_C: {
                #line 96 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved->structc_value;
                #line 97 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 97 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 99 "src/compiler/IncludeWriter.pv"
            case TYPE__UNION_C: {
                #line 99 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved->unionc_value;
                #line 100 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 100 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 102 "src/compiler/IncludeWriter.pv"
            case TYPE__TYPEDEF_C: {
                #line 102 "src/compiler/IncludeWriter.pv"
                struct TypedefC* info = resolved->typedefc_value;
                #line 103 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 103 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 105 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION_C: {
                #line 105 "src/compiler/IncludeWriter.pv"
                struct FunctionC* info = resolved->functionc_value;
                #line 106 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 106 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 108 "src/compiler/IncludeWriter.pv"
            case TYPE__CLASS_CPP: {
                #line 108 "src/compiler/IncludeWriter.pv"
                struct ClassCpp* info = resolved->classcpp_value;
                #line 109 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 109 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 111 "src/compiler/IncludeWriter.pv"
            default: {
                #line 112 "src/compiler/IncludeWriter.pv"
                struct String name = Naming__get_type_name(&generator->naming_ident, resolved, generics->self_type, generics);
                #line 113 "src/compiler/IncludeWriter.pv"
                struct Module* module = Type__get_module(resolved);

                #line 115 "src/compiler/IncludeWriter.pv"
                struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                #line 116 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                    #line 116 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&includes, String__as_str(&path));
                }
            } break;
        }
    } }

    #line 121 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&c_includes);
    #line 121 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 121 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 122 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s>\n", (int32_t)(include.length - 2), include.ptr + 1);
    } }

    #line 125 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 125 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 125 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 126 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 129 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&type_declarations);
    #line 129 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 129 "src/compiler/IncludeWriter.pv"
        struct str type_declaration = *HashSetIter_str__value(&__iter);

        #line 130 "src/compiler/IncludeWriter.pv"
        fprintf(file, "%.*s;\n", (int32_t)(type_declaration.length), type_declaration.ptr);
    } }
    HashSet_str__release(&c_includes);
    HashSet_str__release(&includes);
    HashSet_str__release(&type_declarations);
}

#line 134 "src/compiler/IncludeWriter.pv"
void IncludeWriter__release(struct IncludeWriter* self) {
    #line 135 "src/compiler/IncludeWriter.pv"
    HashSet_str__release(&self->includes);
}
