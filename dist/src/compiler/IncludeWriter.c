#include <stdint.h>
#include <string.h>

#include <stdio.h>

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
#include <analyzer/c/Include.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/types/Global.h>
#include <analyzer/Token.h>
#include <analyzer/types/FunctionParent.h>
#include <analyzer/types/Function.h>
#include <analyzer/types/Primitive.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/StructC.h>
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
    #line 27 "src/compiler/IncludeWriter.pv"
    #line 28 "src/compiler/IncludeWriter.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);
    #line 29 "src/compiler/IncludeWriter.pv"
    #line 30 "src/compiler/IncludeWriter.pv"
    struct HashSet_str type_declarations = HashSet_str__new(self->allocator);
    #line 31 "src/compiler/IncludeWriter.pv"

    #line 33 "src/compiler/IncludeWriter.pv"
    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(types);
    #line 33 "src/compiler/IncludeWriter.pv"
    while (HashMapIter_str_Type__next(&__iter)) {
        #line 33 "src/compiler/IncludeWriter.pv"
        struct Type* type = &HashMapIter_str_Type__value(&__iter)->_1;

        #line 34 "src/compiler/IncludeWriter.pv"
        struct Type* resolved = Context__resolve_type(self->allocator, type, generics, 0);
        #line 35 "src/compiler/IncludeWriter.pv"
        if (resolved == 0) {
            #line 35 "src/compiler/IncludeWriter.pv"
            continue;
        }
        #line 36 "src/compiler/IncludeWriter.pv"
        struct Type* resolved_nn = deref ? Type__deref_all(resolved) : resolved;

        #line 38 "src/compiler/IncludeWriter.pv"
        switch (resolved_nn->type) {
            #line 39 "src/compiler/IncludeWriter.pv"
            case TYPE__INDIRECT: {
                #line 40 "src/compiler/IncludeWriter.pv"
                struct Type* type_deref = Type__deref_all(resolved_nn);

                #line 42 "src/compiler/IncludeWriter.pv"
                switch (type_deref->type) {
                    #line 43 "src/compiler/IncludeWriter.pv"
                    case TYPE__TRAIT: {
                        #line 44 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                        #line 45 "src/compiler/IncludeWriter.pv"
                        struct Module* module = Type__get_module(type_deref);
                        #line 46 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 47 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 47 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 49 "src/compiler/IncludeWriter.pv"
                    case TYPE__STRUCT: {
                        #line 49 "src/compiler/IncludeWriter.pv"
                        struct Struct* struct_info = type_deref->struct_value._0;
                        #line 50 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);

                        #line 52 "src/compiler/IncludeWriter.pv"
                        if (Struct__is_newtype(struct_info)) {
                            #line 53 "src/compiler/IncludeWriter.pv"
                            struct TypedefC typedef_info = (struct TypedefC) { .include = 0, .name = String__as_str(&name), .type = &struct_info->fields.data[0].value.type };
                            #line 54 "src/compiler/IncludeWriter.pv"
                            struct Type typedef_type = (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = &typedef_info };
                            #line 55 "src/compiler/IncludeWriter.pv"
                            struct String type_declaration = Naming__get_type_decl(&generator->naming_c99, &typedef_type, generics->self_type, generics);
                            #line 56 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&type_declaration))) {
                                #line 56 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&type_declaration));
                            }
                        } else {
                            #line 58 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                                #line 58 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        }
                    } break;
                    #line 62 "src/compiler/IncludeWriter.pv"
                    case TYPE__ENUM: {
                        #line 62 "src/compiler/IncludeWriter.pv"
                        struct Enum* enum_info = type_deref->enum_value._0;
                        #line 63 "src/compiler/IncludeWriter.pv"
                        if (Enum__is_discriminated_union(enum_info)) {
                            #line 64 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                            #line 65 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&type_declarations, String__as_str(&name))) {
                                #line 65 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        } else {
                            #line 67 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                            #line 68 "src/compiler/IncludeWriter.pv"
                            struct Module* module = Type__get_module(type_deref);
                            #line 69 "src/compiler/IncludeWriter.pv"
                            struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                            #line 70 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                                #line 70 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&includes, String__as_str(&path));
                            }
                        }
                    } break;
                    #line 73 "src/compiler/IncludeWriter.pv"
                    case TYPE__STRUCT_C: {
                        #line 74 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 75 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 75 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 77 "src/compiler/IncludeWriter.pv"
                    case TYPE__ENUM_C: {
                        #line 78 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 79 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 79 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 81 "src/compiler/IncludeWriter.pv"
                    case TYPE__UNION_C: {
                        #line 82 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 83 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 83 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 85 "src/compiler/IncludeWriter.pv"
                    case TYPE__FUNCTION_C: {
                        #line 85 "src/compiler/IncludeWriter.pv"
                        struct FunctionC* info = type_deref->functionc_value;
                        #line 86 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 86 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 88 "src/compiler/IncludeWriter.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 88 "src/compiler/IncludeWriter.pv"
                        struct TypedefC* info = type_deref->typedefc_value;
                        #line 89 "src/compiler/IncludeWriter.pv"
                        if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 89 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 91 "src/compiler/IncludeWriter.pv"
                    case TYPE__CLASS_CPP: {
                        #line 91 "src/compiler/IncludeWriter.pv"
                        struct ClassCpp* info = type_deref->classcpp_value;
                        #line 92 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 92 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 94 "src/compiler/IncludeWriter.pv"
                    case TYPE__UNKNOWN_C: {
                        #line 94 "src/compiler/IncludeWriter.pv"
                        struct UnknownC* info = type_deref->unknownc_value;
                        #line 95 "src/compiler/IncludeWriter.pv"
                        if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 95 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 97 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 100 "src/compiler/IncludeWriter.pv"
            case TYPE__GLOBAL: {
                #line 100 "src/compiler/IncludeWriter.pv"
                struct Global* g = resolved_nn->global_value;
                #line 101 "src/compiler/IncludeWriter.pv"
                struct String path = Generator__make_rel_path(generator, g->module, g->name->value, (struct str){ .ptr = "", .length = strlen("") });
                #line 102 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                    #line 102 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&includes, String__as_str(&path));
                }
            } break;
            #line 104 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION: {
                #line 104 "src/compiler/IncludeWriter.pv"
                struct Function* func_info = resolved_nn->function_value._0;
                #line 104 "src/compiler/IncludeWriter.pv"
                struct GenericMap* func_generic_map = resolved_nn->function_value._1;
                #line 105 "src/compiler/IncludeWriter.pv"
                switch (func_info->parent.type) {
                    #line 106 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 107 "src/compiler/IncludeWriter.pv"
                        if (func_generic_map == 0) {
                            #line 107 "src/compiler/IncludeWriter.pv"
                            continue;
                        }
                        #line 108 "src/compiler/IncludeWriter.pv"
                        struct Context* context = func_info->context;
                        #line 109 "src/compiler/IncludeWriter.pv"
                        if (context == 0) {
                            #line 109 "src/compiler/IncludeWriter.pv"
                            continue;
                        }
                        #line 110 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = func_generic_map} }}, func_generic_map->self_type, func_generic_map);
                        #line 111 "src/compiler/IncludeWriter.pv"
                        struct Module* module = context->module;
                        #line 112 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 113 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 113 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 115 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__PRIMITIVE: {
                        #line 115 "src/compiler/IncludeWriter.pv"
                        struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                        #line 116 "src/compiler/IncludeWriter.pv"
                        struct str name = primitive_info->name;
                        #line 117 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = "", .length = strlen("") });
                        #line 118 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 118 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 120 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__TRAIT: {
                    } break;
                    #line 121 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__TYPE: {
                        #line 121 "src/compiler/IncludeWriter.pv"
                        struct Type* type_info = func_info->parent.type_value._0;
                        #line 122 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, type_info, generics->self_type, generics);
                        #line 123 "src/compiler/IncludeWriter.pv"
                        struct Module* module = Type__get_module(type_info);
                        #line 124 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 125 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 125 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 127 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 131 "src/compiler/IncludeWriter.pv"
            case TYPE__ENUM_C: {
                #line 131 "src/compiler/IncludeWriter.pv"
                struct EnumC* info = resolved_nn->enumc_value;
                #line 132 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 132 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 134 "src/compiler/IncludeWriter.pv"
            case TYPE__STRUCT_C: {
                #line 134 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved_nn->structc_value;
                #line 135 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 135 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 137 "src/compiler/IncludeWriter.pv"
            case TYPE__UNION_C: {
                #line 137 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved_nn->unionc_value;
                #line 138 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 138 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 140 "src/compiler/IncludeWriter.pv"
            case TYPE__TYPEDEF_C: {
                #line 140 "src/compiler/IncludeWriter.pv"
                struct TypedefC* info = resolved_nn->typedefc_value;
                #line 141 "src/compiler/IncludeWriter.pv"
                if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 141 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 143 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION_C: {
                #line 143 "src/compiler/IncludeWriter.pv"
                struct FunctionC* info = resolved_nn->functionc_value;
                #line 144 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 144 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 146 "src/compiler/IncludeWriter.pv"
            case TYPE__CLASS_CPP: {
                #line 146 "src/compiler/IncludeWriter.pv"
                struct ClassCpp* info = resolved_nn->classcpp_value;
                #line 147 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 147 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 149 "src/compiler/IncludeWriter.pv"
            case TYPE__UNKNOWN_C: {
                #line 149 "src/compiler/IncludeWriter.pv"
                struct UnknownC* info = resolved_nn->unknownc_value;
                #line 150 "src/compiler/IncludeWriter.pv"
                if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 150 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 152 "src/compiler/IncludeWriter.pv"
            default: {
                #line 153 "src/compiler/IncludeWriter.pv"
                struct String name = Naming__get_type_name(&generator->naming_ident, resolved_nn, generics->self_type, generics);
                #line 154 "src/compiler/IncludeWriter.pv"
                struct Module* module = Type__get_module(resolved_nn);

                #line 156 "src/compiler/IncludeWriter.pv"
                struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                #line 157 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                    #line 157 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&includes, String__as_str(&path));
                }
            } break;
        }
    } }

    #line 162 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&c_includes);
    #line 162 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 162 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 163 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s>\n", (int32_t)(include.length - 2), include.ptr + 1);
    } }

    #line 166 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 166 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 166 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 167 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 170 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&type_declarations);
    #line 170 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 170 "src/compiler/IncludeWriter.pv"
        struct str type_declaration = *HashSetIter_str__value(&__iter);

        #line 171 "src/compiler/IncludeWriter.pv"
        fprintf(file, "%.*s;\n", (int32_t)(type_declaration.length), type_declaration.ptr);
    } }
    HashSet_str__release(&c_includes);
    HashSet_str__release(&includes);
    HashSet_str__release(&type_declarations);
}

#line 175 "src/compiler/IncludeWriter.pv"
void IncludeWriter__release(struct IncludeWriter* self) {
    #line 176 "src/compiler/IncludeWriter.pv"
    HashSet_str__release(&self->includes);
}
