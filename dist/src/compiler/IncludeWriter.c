#include <stdint.h>
#include <string.h>

#include <stdio.h>

#include <stdio.h>
#include <std/ArenaAllocator.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Indirect.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/types/Sequence.h>
#include <std/Array_Type.h>
#include <analyzer/types/Tuple.h>
#include <std/Iter_ref_Type.h>
#include <analyzer/Token.h>
#include <analyzer/types/Generic.h>
#include <std/str.h>
#include <analyzer/types/GenericTypedef.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMapIter_str_Type.h>
#include <tuple_str_Type.h>
#include <analyzer/Context.h>
#include <analyzer/Root.h>
#include <compiler/Generator.h>
#include <std/Array_TypeImpl.h>
#include <std/Iter_ref_TypeImpl.h>
#include <analyzer/types/TypeImpl.h>
#include <std/Array_Generic.h>
#include <analyzer/types/Generics.h>
#include <analyzer/Impl.h>
#include <std/String.h>
#include <analyzer/Naming.h>
#include <analyzer/Module.h>
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
bool IncludeWriter__has_unresolved_generic(struct Type* type, struct GenericMap* generics_map) {
    #line 26 "src/compiler/IncludeWriter.pv"
    switch (type->type) {
        #line 27 "src/compiler/IncludeWriter.pv"
        case TYPE__INDIRECT: {
            #line 27 "src/compiler/IncludeWriter.pv"
            struct Indirect* indirect = type->indirect_value;
            #line 28 "src/compiler/IncludeWriter.pv"
            return IncludeWriter__has_unresolved_generic(&indirect->to, generics_map);
        } break;
        #line 30 "src/compiler/IncludeWriter.pv"
        case TYPE__SEQUENCE: {
            #line 30 "src/compiler/IncludeWriter.pv"
            struct Sequence* sequence = type->sequence_value;
            #line 31 "src/compiler/IncludeWriter.pv"
            return IncludeWriter__has_unresolved_generic(&sequence->element, generics_map);
        } break;
        #line 33 "src/compiler/IncludeWriter.pv"
        case TYPE__TUPLE: {
            #line 33 "src/compiler/IncludeWriter.pv"
            struct Tuple* tuple = type->tuple_value;
            #line 34 "src/compiler/IncludeWriter.pv"
            { struct Iter_ref_Type __iter = Array_Type__iter(&tuple->elements);
            #line 34 "src/compiler/IncludeWriter.pv"
            while (Iter_ref_Type__next(&__iter)) {
                #line 34 "src/compiler/IncludeWriter.pv"
                struct Type* element = Iter_ref_Type__value(&__iter);

                #line 35 "src/compiler/IncludeWriter.pv"
                if (IncludeWriter__has_unresolved_generic(element, generics_map)) {
                    #line 35 "src/compiler/IncludeWriter.pv"
                    return true;
                }
            } }
        } break;
        #line 38 "src/compiler/IncludeWriter.pv"
        case TYPE__ENUM: {
            #line 38 "src/compiler/IncludeWriter.pv"
            struct GenericMap* type_generics = type->enum_value._1;
            #line 39 "src/compiler/IncludeWriter.pv"
            if (type_generics != 0) {
                #line 40 "src/compiler/IncludeWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&type_generics->array);
                #line 40 "src/compiler/IncludeWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 40 "src/compiler/IncludeWriter.pv"
                    struct Type* generic = Iter_ref_Type__value(&__iter);

                    #line 41 "src/compiler/IncludeWriter.pv"
                    if (IncludeWriter__has_unresolved_generic(generic, generics_map)) {
                        #line 41 "src/compiler/IncludeWriter.pv"
                        return true;
                    }
                } }
            }
        } break;
        #line 45 "src/compiler/IncludeWriter.pv"
        case TYPE__STRUCT: {
            #line 45 "src/compiler/IncludeWriter.pv"
            struct GenericMap* type_generics = type->struct_value._1;
            #line 46 "src/compiler/IncludeWriter.pv"
            if (type_generics != 0) {
                #line 47 "src/compiler/IncludeWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&type_generics->array);
                #line 47 "src/compiler/IncludeWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 47 "src/compiler/IncludeWriter.pv"
                    struct Type* generic = Iter_ref_Type__value(&__iter);

                    #line 48 "src/compiler/IncludeWriter.pv"
                    if (IncludeWriter__has_unresolved_generic(generic, generics_map)) {
                        #line 48 "src/compiler/IncludeWriter.pv"
                        return true;
                    }
                } }
            }
        } break;
        #line 52 "src/compiler/IncludeWriter.pv"
        case TYPE__TRAIT: {
            #line 52 "src/compiler/IncludeWriter.pv"
            struct GenericMap* type_generics = type->trait_value._1;
            #line 53 "src/compiler/IncludeWriter.pv"
            if (type_generics != 0) {
                #line 54 "src/compiler/IncludeWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&type_generics->array);
                #line 54 "src/compiler/IncludeWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 54 "src/compiler/IncludeWriter.pv"
                    struct Type* generic = Iter_ref_Type__value(&__iter);

                    #line 55 "src/compiler/IncludeWriter.pv"
                    if (IncludeWriter__has_unresolved_generic(generic, generics_map)) {
                        #line 55 "src/compiler/IncludeWriter.pv"
                        return true;
                    }
                } }
            }
        } break;
        #line 59 "src/compiler/IncludeWriter.pv"
        case TYPE__FUNCTION: {
            #line 59 "src/compiler/IncludeWriter.pv"
            struct GenericMap* type_generics = type->function_value._1;
            #line 60 "src/compiler/IncludeWriter.pv"
            if (type_generics != 0) {
                #line 61 "src/compiler/IncludeWriter.pv"
                { struct Iter_ref_Type __iter = Array_Type__iter(&type_generics->array);
                #line 61 "src/compiler/IncludeWriter.pv"
                while (Iter_ref_Type__next(&__iter)) {
                    #line 61 "src/compiler/IncludeWriter.pv"
                    struct Type* generic = Iter_ref_Type__value(&__iter);

                    #line 62 "src/compiler/IncludeWriter.pv"
                    if (IncludeWriter__has_unresolved_generic(generic, generics_map)) {
                        #line 62 "src/compiler/IncludeWriter.pv"
                        return true;
                    }
                } }
            }
        } break;
        #line 66 "src/compiler/IncludeWriter.pv"
        case TYPE__GENERIC: {
            #line 66 "src/compiler/IncludeWriter.pv"
            struct Generic* generic = type->generic_value;
            #line 67 "src/compiler/IncludeWriter.pv"
            struct Token* generic_name = generic->name;
            #line 68 "src/compiler/IncludeWriter.pv"
            if (generic_name == 0) {
                #line 68 "src/compiler/IncludeWriter.pv"
                return false;
            }
            #line 69 "src/compiler/IncludeWriter.pv"
            if (generics_map == 0) {
                #line 69 "src/compiler/IncludeWriter.pv"
                return true;
            }
            #line 70 "src/compiler/IncludeWriter.pv"
            struct Type* concrete_type = GenericMap__get(generics_map, generic_name->value);
            #line 71 "src/compiler/IncludeWriter.pv"
            if (concrete_type == 0) {
                #line 71 "src/compiler/IncludeWriter.pv"
                return true;
            }
            #line 72 "src/compiler/IncludeWriter.pv"
            switch (concrete_type->type) {
                #line 73 "src/compiler/IncludeWriter.pv"
                case TYPE__GENERIC: {
                    #line 73 "src/compiler/IncludeWriter.pv"
                    struct Generic* concrete_generic = concrete_type->generic_value;
                    #line 74 "src/compiler/IncludeWriter.pv"
                    struct Token* concrete_name = concrete_generic->name;
                    #line 75 "src/compiler/IncludeWriter.pv"
                    if (concrete_name != 0 && str__Eq_str__eq(concrete_name->value, generic_name->value)) {
                        #line 75 "src/compiler/IncludeWriter.pv"
                        return true;
                    }
                } break;
                #line 77 "src/compiler/IncludeWriter.pv"
                default: {
                } break;
            }
            #line 79 "src/compiler/IncludeWriter.pv"
            return IncludeWriter__has_unresolved_generic(concrete_type, generics_map);
        } break;
        #line 81 "src/compiler/IncludeWriter.pv"
        case TYPE__GENERIC_TYPEDEF: {
            #line 81 "src/compiler/IncludeWriter.pv"
            struct GenericTypedef* gt = type->generictypedef_value;
            #line 82 "src/compiler/IncludeWriter.pv"
            return IncludeWriter__has_unresolved_generic((struct Type[]){(struct Type) { .type = TYPE__GENERIC, .generic_value = gt->generic }}, generics_map);
        } break;
        #line 84 "src/compiler/IncludeWriter.pv"
        case TYPE__SELF: {
            #line 85 "src/compiler/IncludeWriter.pv"
            return generics_map == 0 || generics_map->self_type == 0;
        } break;
        #line 87 "src/compiler/IncludeWriter.pv"
        default: {
        } break;
    }

    #line 90 "src/compiler/IncludeWriter.pv"
    return false;
}

#line 93 "src/compiler/IncludeWriter.pv"
void IncludeWriter__write(struct IncludeWriter* self, FILE* file, struct Generator* generator, struct HashMap_str_Type* types, struct GenericMap* generics, bool deref) {
    #line 94 "src/compiler/IncludeWriter.pv"
    struct HashSet_str c_includes = HashSet_str__new(self->allocator);
    #line 95 "src/compiler/IncludeWriter.pv"
    #line 96 "src/compiler/IncludeWriter.pv"
    struct HashSet_str includes = HashSet_str__new(self->allocator);
    #line 97 "src/compiler/IncludeWriter.pv"
    #line 98 "src/compiler/IncludeWriter.pv"
    struct HashSet_str type_declarations = HashSet_str__new(self->allocator);
    #line 99 "src/compiler/IncludeWriter.pv"

    #line 101 "src/compiler/IncludeWriter.pv"
    { struct HashMapIter_str_Type __iter = HashMap_str_Type__iter(types);
    #line 101 "src/compiler/IncludeWriter.pv"
    while (HashMapIter_str_Type__next(&__iter)) {
        #line 101 "src/compiler/IncludeWriter.pv"
        struct Type* type = &HashMapIter_str_Type__value(&__iter)->_1;

        #line 102 "src/compiler/IncludeWriter.pv"
        struct Type* resolved = Context__resolve_type(self->allocator, type, generics, 0);
        #line 103 "src/compiler/IncludeWriter.pv"
        if (resolved == 0) {
            #line 103 "src/compiler/IncludeWriter.pv"
            continue;
        }
        #line 104 "src/compiler/IncludeWriter.pv"
        struct Type* resolved_nn = deref ? Type__deref_all(resolved) : resolved;

        #line 106 "src/compiler/IncludeWriter.pv"
        if (generics->self_type != 0 && Root__type_impl_target_eq(generator->root, Type__deref_all(resolved), generics->self_type)) {
            #line 106 "src/compiler/IncludeWriter.pv"
            continue;
        }

        #line 108 "src/compiler/IncludeWriter.pv"
        bool found_type_impl_header = false;
        #line 109 "src/compiler/IncludeWriter.pv"
        { struct Iter_ref_TypeImpl __iter = Array_TypeImpl__iter(&generator->root->type_impls);
        #line 109 "src/compiler/IncludeWriter.pv"
        while (Iter_ref_TypeImpl__next(&__iter)) {
            #line 109 "src/compiler/IncludeWriter.pv"
            struct TypeImpl type_impl = *Iter_ref_TypeImpl__value(&__iter);

            #line 110 "src/compiler/IncludeWriter.pv"
            if (type_impl.impl_info->generics.array.length != 0) {
                #line 110 "src/compiler/IncludeWriter.pv"
                continue;
            }
            #line 111 "src/compiler/IncludeWriter.pv"
            if (!Root__type_impl_target_eq(generator->root, &type_impl.type, resolved)) {
                #line 111 "src/compiler/IncludeWriter.pv"
                continue;
            }

            #line 113 "src/compiler/IncludeWriter.pv"
            found_type_impl_header = true;
            #line 114 "src/compiler/IncludeWriter.pv"
            struct Type* include_type = &type_impl.type;
            #line 115 "src/compiler/IncludeWriter.pv"
            if (Type__is_fat_pointer(include_type)) {
                #line 116 "src/compiler/IncludeWriter.pv"
                include_type = Type__deref_1(include_type);
                #line 117 "src/compiler/IncludeWriter.pv"
                if (include_type == 0) {
                    #line 117 "src/compiler/IncludeWriter.pv"
                    include_type = &type_impl.type;
                }
            }
            #line 119 "src/compiler/IncludeWriter.pv"
            struct String name = Naming__get_type_name(&generator->naming_ident, include_type, generics->self_type, generics);
            #line 120 "src/compiler/IncludeWriter.pv"
            struct String path = Generator__make_rel_path(generator, type_impl.impl_info->context->module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
            #line 121 "src/compiler/IncludeWriter.pv"
            if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                #line 121 "src/compiler/IncludeWriter.pv"
                HashSet_str__insert(&includes, String__as_str(&path));
            }
        } }
        #line 123 "src/compiler/IncludeWriter.pv"
        if (found_type_impl_header) {
            #line 123 "src/compiler/IncludeWriter.pv"
            continue;
        }

        #line 125 "src/compiler/IncludeWriter.pv"
        switch (resolved_nn->type) {
            #line 126 "src/compiler/IncludeWriter.pv"
            case TYPE__INDIRECT: {
                #line 127 "src/compiler/IncludeWriter.pv"
                struct Type* type_deref = Type__deref_all(resolved_nn);

                #line 129 "src/compiler/IncludeWriter.pv"
                switch (type_deref->type) {
                    #line 130 "src/compiler/IncludeWriter.pv"
                    case TYPE__TRAIT: {
                        #line 131 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                        #line 132 "src/compiler/IncludeWriter.pv"
                        struct Module* module = Type__get_module(type_deref);
                        #line 133 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 134 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 134 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 136 "src/compiler/IncludeWriter.pv"
                    case TYPE__STRUCT: {
                        #line 136 "src/compiler/IncludeWriter.pv"
                        struct Struct* struct_info = type_deref->struct_value._0;
                        #line 137 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);

                        #line 139 "src/compiler/IncludeWriter.pv"
                        if (Struct__is_newtype(struct_info)) {
                            #line 140 "src/compiler/IncludeWriter.pv"
                            struct TypedefC typedef_info = (struct TypedefC) { .include = 0, .name = String__as_str(&name), .type = &struct_info->fields.data[0].value.type };
                            #line 141 "src/compiler/IncludeWriter.pv"
                            struct Type typedef_type = (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = &typedef_info };
                            #line 142 "src/compiler/IncludeWriter.pv"
                            struct String type_declaration = Naming__get_type_decl(&generator->naming_c99, &typedef_type, generics->self_type, generics);
                            #line 143 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&type_declaration))) {
                                #line 143 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&type_declaration));
                            }
                        } else {
                            #line 145 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                                #line 145 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        }
                    } break;
                    #line 149 "src/compiler/IncludeWriter.pv"
                    case TYPE__ENUM: {
                        #line 149 "src/compiler/IncludeWriter.pv"
                        struct Enum* enum_info = type_deref->enum_value._0;
                        #line 150 "src/compiler/IncludeWriter.pv"
                        if (Enum__is_discriminated_union(enum_info)) {
                            #line 151 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                            #line 152 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&type_declarations, String__as_str(&name))) {
                                #line 152 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&type_declarations, String__as_str(&name));
                            }
                        } else {
                            #line 154 "src/compiler/IncludeWriter.pv"
                            struct String name = Naming__get_type_name(&generator->naming_ident, type_deref, generics->self_type, generics);
                            #line 155 "src/compiler/IncludeWriter.pv"
                            struct Module* module = Type__get_module(type_deref);
                            #line 156 "src/compiler/IncludeWriter.pv"
                            struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                            #line 157 "src/compiler/IncludeWriter.pv"
                            if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                                #line 157 "src/compiler/IncludeWriter.pv"
                                HashSet_str__insert(&includes, String__as_str(&path));
                            }
                        }
                    } break;
                    #line 160 "src/compiler/IncludeWriter.pv"
                    case TYPE__STRUCT_C: {
                        #line 161 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 162 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 162 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 164 "src/compiler/IncludeWriter.pv"
                    case TYPE__ENUM_C: {
                        #line 165 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 166 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 166 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 168 "src/compiler/IncludeWriter.pv"
                    case TYPE__UNION_C: {
                        #line 169 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_c99, type_deref, generics->self_type, generics);
                        #line 170 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->type_declarations, String__as_str(&name))) {
                            #line 170 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&type_declarations, String__as_str(&name));
                        }
                    } break;
                    #line 172 "src/compiler/IncludeWriter.pv"
                    case TYPE__FUNCTION_C: {
                        #line 172 "src/compiler/IncludeWriter.pv"
                        struct FunctionC* info = type_deref->functionc_value;
                        #line 173 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 173 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 175 "src/compiler/IncludeWriter.pv"
                    case TYPE__TYPEDEF_C: {
                        #line 175 "src/compiler/IncludeWriter.pv"
                        struct TypedefC* info = type_deref->typedefc_value;
                        #line 176 "src/compiler/IncludeWriter.pv"
                        if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 176 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 178 "src/compiler/IncludeWriter.pv"
                    case TYPE__CLASS_CPP: {
                        #line 178 "src/compiler/IncludeWriter.pv"
                        struct ClassCpp* info = type_deref->classcpp_value;
                        #line 179 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 179 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 181 "src/compiler/IncludeWriter.pv"
                    case TYPE__UNKNOWN_C: {
                        #line 181 "src/compiler/IncludeWriter.pv"
                        struct UnknownC* info = type_deref->unknownc_value;
                        #line 182 "src/compiler/IncludeWriter.pv"
                        if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                            #line 182 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&c_includes, info->include->path);
                        }
                    } break;
                    #line 184 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 187 "src/compiler/IncludeWriter.pv"
            case TYPE__GLOBAL: {
                #line 187 "src/compiler/IncludeWriter.pv"
                struct Global* g = resolved_nn->global_value;
                #line 188 "src/compiler/IncludeWriter.pv"
                struct String path = Generator__make_rel_path(generator, g->module, g->name->value, (struct str){ .ptr = "", .length = strlen("") });
                #line 189 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                    #line 189 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&includes, String__as_str(&path));
                }
            } break;
            #line 191 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION: {
                #line 191 "src/compiler/IncludeWriter.pv"
                struct Function* func_info = resolved_nn->function_value._0;
                #line 191 "src/compiler/IncludeWriter.pv"
                struct GenericMap* func_generic_map = resolved_nn->function_value._1;
                #line 192 "src/compiler/IncludeWriter.pv"
                switch (func_info->parent.type) {
                    #line 193 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__NONE: {
                        #line 194 "src/compiler/IncludeWriter.pv"
                        if (func_generic_map == 0) {
                            #line 194 "src/compiler/IncludeWriter.pv"
                            continue;
                        }
                        #line 195 "src/compiler/IncludeWriter.pv"
                        struct Context* context = func_info->context;
                        #line 196 "src/compiler/IncludeWriter.pv"
                        if (context == 0) {
                            #line 196 "src/compiler/IncludeWriter.pv"
                            continue;
                        }
                        #line 197 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, (struct Type[]){(struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = func_info, ._1 = func_generic_map} }}, func_generic_map->self_type, func_generic_map);
                        #line 198 "src/compiler/IncludeWriter.pv"
                        struct Module* module = context->module;
                        #line 199 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 200 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 200 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 202 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__PRIMITIVE: {
                        #line 202 "src/compiler/IncludeWriter.pv"
                        struct Primitive* primitive_info = func_info->parent.primitive_value._0;
                        #line 203 "src/compiler/IncludeWriter.pv"
                        struct str name = primitive_info->name;
                        #line 204 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, 0, name, (struct str){ .ptr = "", .length = strlen("") });
                        #line 205 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 205 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 207 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__TRAIT: {
                    } break;
                    #line 208 "src/compiler/IncludeWriter.pv"
                    case FUNCTION_PARENT__TYPE: {
                        #line 208 "src/compiler/IncludeWriter.pv"
                        struct Type* type_info = func_info->parent.type_value._0;
                        #line 208 "src/compiler/IncludeWriter.pv"
                        uintptr_t impl_index = func_info->parent.type_value._1;
                        #line 209 "src/compiler/IncludeWriter.pv"
                        struct GenericMap* include_generics = generics;
                        #line 210 "src/compiler/IncludeWriter.pv"
                        if (func_generic_map != 0) {
                            #line 211 "src/compiler/IncludeWriter.pv"
                            struct GenericMap resolved_generics = GenericMap__resolve_types(&(*func_generic_map), self->allocator, generics);
                            #line 212 "src/compiler/IncludeWriter.pv"
                            include_generics = &resolved_generics;
                        }

                        #line 215 "src/compiler/IncludeWriter.pv"
                        struct Type* include_type = type_info;
                        #line 216 "src/compiler/IncludeWriter.pv"
                        if (Type__is_fat_pointer(type_info)) {
                            #line 217 "src/compiler/IncludeWriter.pv"
                            include_type = Type__deref_1(type_info);
                            #line 218 "src/compiler/IncludeWriter.pv"
                            if (include_type == 0) {
                                #line 218 "src/compiler/IncludeWriter.pv"
                                include_type = type_info;
                            }
                        }

                        #line 221 "src/compiler/IncludeWriter.pv"
                        struct Type* resolved_include_type = Context__resolve_type(self->allocator, include_type, include_generics, generics);
                        #line 222 "src/compiler/IncludeWriter.pv"
                        if (resolved_include_type != 0) {
                            #line 222 "src/compiler/IncludeWriter.pv"
                            include_type = resolved_include_type;
                        }

                        #line 224 "src/compiler/IncludeWriter.pv"
                        if (IncludeWriter__has_unresolved_generic(include_type, include_generics)) {
                            #line 225 "src/compiler/IncludeWriter.pv"
                            fprintf(stderr, "IncludeWriter.write: unresolved generic while writing type impl include\n");
                        }

                        #line 228 "src/compiler/IncludeWriter.pv"
                        struct String name = Naming__get_type_name(&generator->naming_ident, include_type, include_generics->self_type, include_generics);
                        #line 229 "src/compiler/IncludeWriter.pv"
                        struct Module* module = (include_type == 0 ? 0 : Type__get_module(include_type));
                        #line 230 "src/compiler/IncludeWriter.pv"
                        struct TypeImpl* type_impl = Root__get_type_impl(generator->root, type_info, impl_index);
                        #line 231 "src/compiler/IncludeWriter.pv"
                        if (type_impl != 0) {
                            #line 231 "src/compiler/IncludeWriter.pv"
                            module = type_impl->impl_info->context->module;
                        }
                        #line 232 "src/compiler/IncludeWriter.pv"
                        struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                        #line 233 "src/compiler/IncludeWriter.pv"
                        if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                            #line 233 "src/compiler/IncludeWriter.pv"
                            HashSet_str__insert(&includes, String__as_str(&path));
                        }
                    } break;
                    #line 235 "src/compiler/IncludeWriter.pv"
                    default: {
                    } break;
                }
            } break;
            #line 239 "src/compiler/IncludeWriter.pv"
            case TYPE__ENUM_C: {
                #line 239 "src/compiler/IncludeWriter.pv"
                struct EnumC* info = resolved_nn->enumc_value;
                #line 240 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 240 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 242 "src/compiler/IncludeWriter.pv"
            case TYPE__STRUCT_C: {
                #line 242 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved_nn->structc_value;
                #line 243 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 243 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 245 "src/compiler/IncludeWriter.pv"
            case TYPE__UNION_C: {
                #line 245 "src/compiler/IncludeWriter.pv"
                struct StructC* info = resolved_nn->unionc_value;
                #line 246 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 246 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 248 "src/compiler/IncludeWriter.pv"
            case TYPE__TYPEDEF_C: {
                #line 248 "src/compiler/IncludeWriter.pv"
                struct TypedefC* info = resolved_nn->typedefc_value;
                #line 249 "src/compiler/IncludeWriter.pv"
                if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 249 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 251 "src/compiler/IncludeWriter.pv"
            case TYPE__FUNCTION_C: {
                #line 251 "src/compiler/IncludeWriter.pv"
                struct FunctionC* info = resolved_nn->functionc_value;
                #line 252 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 252 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 254 "src/compiler/IncludeWriter.pv"
            case TYPE__CLASS_CPP: {
                #line 254 "src/compiler/IncludeWriter.pv"
                struct ClassCpp* info = resolved_nn->classcpp_value;
                #line 255 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 255 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 257 "src/compiler/IncludeWriter.pv"
            case TYPE__UNKNOWN_C: {
                #line 257 "src/compiler/IncludeWriter.pv"
                struct UnknownC* info = resolved_nn->unknownc_value;
                #line 258 "src/compiler/IncludeWriter.pv"
                if (info->include != 0 && HashSet_str__insert(&self->c_includes, info->include->path)) {
                    #line 258 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&c_includes, info->include->path);
                }
            } break;
            #line 260 "src/compiler/IncludeWriter.pv"
            default: {
                #line 261 "src/compiler/IncludeWriter.pv"
                struct String name = Naming__get_type_name(&generator->naming_ident, resolved_nn, generics->self_type, generics);
                #line 262 "src/compiler/IncludeWriter.pv"
                struct Module* module = Type__get_module(resolved_nn);

                #line 264 "src/compiler/IncludeWriter.pv"
                struct String path = Generator__make_rel_path(generator, module, String__as_str(&name), (struct str){ .ptr = "", .length = strlen("") });
                #line 265 "src/compiler/IncludeWriter.pv"
                if (HashSet_str__insert(&self->includes, String__as_str(&path))) {
                    #line 265 "src/compiler/IncludeWriter.pv"
                    HashSet_str__insert(&includes, String__as_str(&path));
                }
            } break;
        }
    } }

    #line 270 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&c_includes);
    #line 270 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 270 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 271 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s>\n", (int32_t)(include.length - 2), include.ptr + 1);
    } }

    #line 274 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&includes);
    #line 274 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 274 "src/compiler/IncludeWriter.pv"
        struct str include = *HashSetIter_str__value(&__iter);

        #line 275 "src/compiler/IncludeWriter.pv"
        fprintf(file, "#include <%.*s.h>\n", (int32_t)(include.length), include.ptr);
    } }

    #line 278 "src/compiler/IncludeWriter.pv"
    { struct HashSetIter_str __iter = HashSet_str__iter(&type_declarations);
    #line 278 "src/compiler/IncludeWriter.pv"
    while (HashSetIter_str__next(&__iter)) {
        #line 278 "src/compiler/IncludeWriter.pv"
        struct str type_declaration = *HashSetIter_str__value(&__iter);

        #line 279 "src/compiler/IncludeWriter.pv"
        fprintf(file, "%.*s;\n", (int32_t)(type_declaration.length), type_declaration.ptr);
    } }
    HashSet_str__release(&c_includes);
    HashSet_str__release(&includes);
    HashSet_str__release(&type_declarations);
}

#line 283 "src/compiler/IncludeWriter.pv"
void IncludeWriter__release(struct IncludeWriter* self) {
    #line 284 "src/compiler/IncludeWriter.pv"
    HashSet_str__release(&self->includes);
}
