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
#include <std/Array_TypeImpl.h>
#include <analyzer/Root.h>
#include <compiler/Generator.h>
#include <std/Iter_ref_TypeImpl.h>
#include <analyzer/types/TypeImpl.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Impl.h>
#include <std/String.h>
#include <analyzer/Naming.h>
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
        bool found_type_impl_header = false;
        #line 39 "src/compiler/IncludeWriter.pv"
        { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&generator->root->type_impls);
        #line 39 "src/compiler/IncludeWriter.pv"
        while (Iter_ref_TypeImpl__next(&__iter)) {
            #line 39 "src/compiler/IncludeWriter.pv"
            struct TypeImpl type_impl = *Iter_ref_TypeImpl__value(&__iter);

            #line 40 "src/compiler/IncludeWriter.pv"
            if (type_impl.impl_info->generics.array.length != 0) {
                #line 40 "src/compiler/IncludeWriter.pv"
                continue;
            }
            #line 41 "src/compiler/IncludeWriter.pv"
            if (!Root__type_impl_target_eq(generator->root, &type_impl.type, resolved)) {
                #line 41 "src/compiler/IncludeWriter.pv"
                continue;
            }

            #line 43 "src/compiler/IncludeWriter.pv"
            found_type_impl_header = true;
            #line 44 "src/compiler/IncludeWriter.pv"
            struct Type* include_type = &type_impl.type;
            #line 45 "src/compiler/IncludeWriter.pv"
            if (Type__is_fat_pointer(include_type)) {
                #line 46 "src/compiler/IncludeWriter.pv"
                include_type = Type__deref_1(include_type);
                #line 47 "src/compiler/IncludeWriter.pv"
                if (include_type == 0) {
                    #line 47 "src/compiler/IncludeWriter.pv"
                    include_type = &type_impl.type;
                }
            }
            #line 49 "src/compiler/IncludeWriter.pv"
            struct String name = Naming__get_type_name(&generator->naming_ident, include_type, generics->self_type, generics);
            #line 50 "src/compiler/IncludeWriter.pv"
            struct String path = Generator__make_rel_path(generator, type_impl.impl_info->context->module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
            #line 51 "src/compiler/IncludeWriter.pv"
            if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                #line 51 "src/compiler/IncludeWriter.pv"
                HashSet_str__insert(&includes, String__as_str(&path));
            }
        } }
        #line 53 "src/compiler/IncludeWriter.pv"
        if (found_type_impl_header) {
            #line 53 "src/compiler/IncludeWriter.pv"
            continue;
        }

        #line 55 "src/compiler/IncludeWriter.pv"
        switch (resolved_nn->type) {
            #line 56 "src/compiler/IncludeWriter.pv"
            case TYPE__INDIRECT: {
                #line 57 "src/compiler/IncludeWriter.pv"
                struct Type* type_deref = Type__deref_all(resolved_nn);

                #line 59 "src/compiler/IncludeWriter.pv"
                switch (type_deref->type) {
                    #line 60 "src/compiler/IncludeWriter.pv"
                    case TYPE__TRAIT: {
                        #line 61 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                        #line 62 "src/compiler/IncludeWriter.pv"
                        struct Module* module = Type__get_module(type_deref);
                        #line 63 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 64 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 64 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 66 "src/compiler/IncludeWriter.pv"
                    case TYPE__STRUCT: {
                        #line 66 "src/compiler/IncludeWriter.pv"
                        struct Struct* struct_info = type_deref->struct_value._0;
                        #line 67 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);

                        #line 69 "src/compiler/IncludeWriter.pv"
                        if (Struct__is_newtype(struct_info)) {
                            #line 70 "src/compiler/IncludeWriter.pv"
                            struct TypedefC typedef_info = (struct TypedefC) { .include = 0, .name = String__as_str(&name), .type = &struct_info->fields.data[0].value.type };
                            #line 71 "src/compiler/IncludeWriter.pv"
                            struct Type typedef_type = (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = &typedef_info };
                            #line 72 "src/compiler/IncludeWriter.pv"
                            struct String type_declaration = Naming__get_type_decl(&generator->naming_c99, &typedef_type, generics->self_type, generics);
                            #line 73 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&type_declaration))) {
                                #line 73 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&type_declaration));
                            }
                        } else {
                            #line 75 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                                #line 75 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        }
                    } break;
                    #line 79 "src/compiler/IncludeWriter.pv"
                    case TYPE__ENUM: {
                        #line 79 "src/compiler/IncludeWriter.pv"
                        struct Enum* enum_info = type_deref->enum_value._0;
                        #line 80 "src/compiler/IncludeWriter.pv"
                        if (Enum__is_discriminated_union(enum_info)) {
                            #line 81 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                            #line 82 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&type_declarations, String__as_str(&name))) {
                                #line 82 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        } else {
                            #line 84 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                            #line 85 "src/compiler/IncludeWriter.pv"
                            struct Module* module = Type__get_module(type_deref);
                            #line 86 "src/compiler/IncludeWriter.pv"
                            struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                            #line 87 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                                #line 87 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&includes, String__as_str(&path));
                            }
                        }
                    } break;
                    #line 90 "src/compiler/IncludeWriter.pv"
                    case TYPE__STRUCT_C: {
                        #line 91 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 92 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 92 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 94 "src/compiler/IncludeWriter.pv"
                    case TYPE__ENUM_C: {
                        #line 95 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 96 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 96 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 98 "src/compiler/IncludeWriter.pv"
                    case TYPE__UNION_C: {
                        #line 99 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 100 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 100 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 102 "src/compiler/IncludeWriter.pv"
                    case TYPE__FUNCTION_C: {
                        #line 102 "src/compiler/IncludeWriter.pv"
                        struct FunctionC* info = type_deref->functionc_value;
                        #line 103 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 103 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 105 "src/compiler/IncludeWriter.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 105 "src/compiler/IncludeWriter.pv"
                        struct TypedefC* info = type_deref->typedefc_value;
                        #line 106 "src/compiler/IncludeWriter.pv"
                        if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 106 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 108 "src/compiler/IncludeWriter.pv"
                    case TYPE__CLASS_CPP: {
                        #line 108 "src/compiler/IncludeWriter.pv"
                        struct ClassCpp* info = type_deref->classcpp_value;
                        #line 109 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 109 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 111 "src/compiler/IncludeWriter.pv"
                    case TYPE__UNKNOWN_C: {
                        #line 111 "src/compiler/IncludeWriter.pv"
                        struct UnknownC* info = type_deref->unknownc_value;
                        #line 112 "src/compiler/IncludeWriter.pv"
                        if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 112 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 114 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 117 "src/compiler/IncludeWriter.pv"
            case TYPE__GLOBAL: {
                #line 117 "src/compiler/IncludeWriter.pv"
                struct Global* g = resolved_nn->global_value;
                #line 118 "src/compiler/IncludeWriter.pv"
                struct String path = Generator__make_rel_path(generator, g->module, g->name->value, (struct str){ .ptr = "", .length = strlen("") });
                #line 119 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                    #line 119 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&includes, String__as_str(&path));
                }
            } break;
            #line 121 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION: {
                #line 121 "src/compiler/IncludeWriter.pv"
                struct Function* func_info = resolved_nn->function_value._0;
                #line 121 "src/compiler/IncludeWriter.pv"
                struct GenericMap* func_generic_map = resolved_nn->function_value._1;
                #line 122 "src/compiler/IncludeWriter.pv"
                switch (func_info->parent.type) {
                    #line 123 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 124 "src/compiler/IncludeWriter.pv"
                        if (func_generic_map == 0) {
                            #line 124 "src/compiler/IncludeWriter.pv"
                            continue;
                        }
                        #line 125 "src/compiler/IncludeWriter.pv"
                        struct Context* context = func_info->context;
                        #line 126 "src/compiler/IncludeWriter.pv"
                        if (context == 0) {
                            #line 126 "src/compiler/IncludeWriter.pv"
                            continue;
                        }
                        #line 127 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = func_generic_map} }}, func_generic_map->self_type, func_generic_map);
                        #line 128 "src/compiler/IncludeWriter.pv"
                        struct Module* module = context->module;
                        #line 129 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 130 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 130 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 132 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__PRIMITIVE: {
                        #line 132 "src/compiler/IncludeWriter.pv"
                        struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                        #line 133 "src/compiler/IncludeWriter.pv"
                        struct str name = primitive_info->name;
                        #line 134 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = "", .length = strlen("") });
                        #line 135 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 135 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 137 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__TRAIT: {
                    } break;
                    #line 138 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__TYPE: {
                        #line 138 "src/compiler/IncludeWriter.pv"
                        struct Type* type_info = func_info->parent.type_value._0;
                        #line 138 "src/compiler/IncludeWriter.pv"
                        uintptr_t impl_index = func_info->parent.type_value._1;
                        #line 139 "src/compiler/IncludeWriter.pv"
                        struct Type* include_type = type_info;
                        #line 140 "src/compiler/IncludeWriter.pv"
                        if (Type__is_fat_pointer(type_info)) {
                            #line 141 "src/compiler/IncludeWriter.pv"
                            include_type = Type__deref_1(type_info);
                            #line 142 "src/compiler/IncludeWriter.pv"
                            if (include_type == 0) {
                                #line 142 "src/compiler/IncludeWriter.pv"
                                include_type = type_info;
                            }
                        }
                        #line 144 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, include_type, generics->self_type, generics);
                        #line 145 "src/compiler/IncludeWriter.pv"
                        struct Module* module = (include_type == 0 ? 0 : Type__get_module(include_type));
                        #line 146 "src/compiler/IncludeWriter.pv"
                        struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type_info, impl_index);
                        #line 147 "src/compiler/IncludeWriter.pv"
                        if (type_impl != 0) {
                            #line 147 "src/compiler/IncludeWriter.pv"
                            module = type_impl->impl_info->context->module;
                        }
                        #line 148 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 149 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 149 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 151 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 155 "src/compiler/IncludeWriter.pv"
            case TYPE__ENUM_C: {
                #line 155 "src/compiler/IncludeWriter.pv"
                struct EnumC* info = resolved_nn->enumc_value;
                #line 156 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 156 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 158 "src/compiler/IncludeWriter.pv"
            case TYPE__STRUCT_C: {
                #line 158 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved_nn->structc_value;
                #line 159 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 159 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 161 "src/compiler/IncludeWriter.pv"
            case TYPE__UNION_C: {
                #line 161 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved_nn->unionc_value;
                #line 162 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 162 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 164 "src/compiler/IncludeWriter.pv"
            case TYPE__TYPEDEF_C: {
                #line 164 "src/compiler/IncludeWriter.pv"
                struct TypedefC* info = resolved_nn->typedefc_value;
                #line 165 "src/compiler/IncludeWriter.pv"
                if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 165 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 167 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION_C: {
                #line 167 "src/compiler/IncludeWriter.pv"
                struct FunctionC* info = resolved_nn->functionc_value;
                #line 168 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 168 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 170 "src/compiler/IncludeWriter.pv"
            case TYPE__CLASS_CPP: {
                #line 170 "src/compiler/IncludeWriter.pv"
                struct ClassCpp* info = resolved_nn->classcpp_value;
                #line 171 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 171 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 173 "src/compiler/IncludeWriter.pv"
            case TYPE__UNKNOWN_C: {
                #line 173 "src/compiler/IncludeWriter.pv"
                struct UnknownC* info = resolved_nn->unknownc_value;
                #line 174 "src/compiler/IncludeWriter.pv"
                if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 174 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 176 "src/compiler/IncludeWriter.pv"
            default: {
                #line 177 "src/compiler/IncludeWriter.pv"
                struct String name = Naming__get_type_name(&generator->naming_ident, resolved_nn, generics->self_type, generics);
                #line 178 "src/compiler/IncludeWriter.pv"
                struct Module* module = Type__get_module(resolved_nn);

                #line 180 "src/compiler/IncludeWriter.pv"
                struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                #line 181 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                    #line 181 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&includes, String__as_str(&path));
                }
            } break;
        }
    } }

    #line 186 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&c_includes);
    #line 186 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 186 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 187 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s>\n", (int32_t)(include.length - 2), include.ptr + 1);
    } }

    #line 190 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 190 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 190 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 191 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 194 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&type_declarations);
    #line 194 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 194 "src/compiler/IncludeWriter.pv"
        struct str type_declaration = *HashSetIter_str__value(&__iter);

        #line 195 "src/compiler/IncludeWriter.pv"
        fprintf(file, "%.*s;\n", (int32_t)(type_declaration.length), type_declaration.ptr);
    } }
    HashSet_str__release(&c_includes);
    HashSet_str__release(&includes);
    HashSet_str__release(&type_declarations);
}

#line 199 "src/compiler/IncludeWriter.pv"
void IncludeWriter__release(struct IncludeWriter* self) {
    #line 200 "src/compiler/IncludeWriter.pv"
    HashSet_str__release(&self->includes);
}
