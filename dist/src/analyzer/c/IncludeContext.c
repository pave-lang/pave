#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/types/Type.h>
#include <std/str.h>
#include <std/HashMap_str_Type.h>
#include <stdbool.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/Include.h>
#include <analyzer/Root.h>
#include <stdint.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/ParentCpp.h>
#include <analyzer/c/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <std/ArenaAllocator.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/types/Indirect.h>
#include <std/Allocator.h>
#include <analyzer/c/IncludeObjectContext.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/types/Primitive.h>

#include <analyzer/c/IncludeContext.h>

#line 17 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__insert_type(struct IncludeContext* self, char const* name, struct Type type) {
    #line 18 "src/analyzer/c/IncludeContext.pv"
    HashMap_str_Type__insert(self->types, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 21 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__insert_value(struct IncludeContext* self, char const* name, struct Type type) {
    #line 22 "src/analyzer/c/IncludeContext.pv"
    HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, type);
}

#line 25 "src/analyzer/c/IncludeContext.pv"
bool IncludeContext__insert_function(struct IncludeContext* self, char const* name, struct Type* return_type) {
    #line 26 "src/analyzer/c/IncludeContext.pv"
    struct FunctionC* func_info = FunctionC__new(self->include, name);
    #line 27 "src/analyzer/c/IncludeContext.pv"
    func_info->return_type = *return_type;

    #line 29 "src/analyzer/c/IncludeContext.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info };
    #line 30 "src/analyzer/c/IncludeContext.pv"
    return HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 33 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 34 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 36 "src/analyzer/c/IncludeContext.pv"
    CXType cursor_return_type = clang_getCursorResultType(cursor);
    #line 37 "src/analyzer/c/IncludeContext.pv"
    struct Type* return_type = Include__parse_type(include, cursor_return_type);
    #line 38 "src/analyzer/c/IncludeContext.pv"
    if (return_type == 0) {
        #line 38 "src/analyzer/c/IncludeContext.pv"
        return_type = &include->root->type_void;
    }

    #line 40 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_function(self, name, return_type);
}

#line 43 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name) {
    #line 44 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_function(self, name, &self->include->root->type_void);
}

#line 47 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name) {
    #line 48 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 49 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });
    #line 50 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 53 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name) {
    #line 54 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 55 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info });
    #line 56 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 59 "src/analyzer/c/IncludeContext.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name) {
    #line 60 "src/analyzer/c/IncludeContext.pv"
    struct EnumC* enum_info = EnumC__new(self->include, name, self->parent);
    #line 61 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
    #line 62 "src/analyzer/c/IncludeContext.pv"
    return enum_info;
}

#line 65 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name) {
    #line 66 "src/analyzer/c/IncludeContext.pv"
    HashMap_str_EnumCValue__insert(&enum_info->values, (struct str){ .ptr = value_name, .length = strlen(value_name) }, (struct EnumCValue) { .parent = enum_info, .name = (struct str){ .ptr = value_name, .length = strlen(value_name) } });
    #line 67 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_value(self, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
}

#line 70 "src/analyzer/c/IncludeContext.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name) {
    #line 71 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 72 "src/analyzer/c/IncludeContext.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 74 "src/analyzer/c/IncludeContext.pv"
    struct Type* existing = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 75 "src/analyzer/c/IncludeContext.pv"
    if (existing != 0) {
        #line 76 "src/analyzer/c/IncludeContext.pv"
        switch (existing->type) {
            #line 77 "src/analyzer/c/IncludeContext.pv"
            case TYPE__NAMESPACE_CPP: {
                #line 77 "src/analyzer/c/IncludeContext.pv"
                struct NamespaceCpp* ns_info = existing->namespacecpp_value;
                #line 78 "src/analyzer/c/IncludeContext.pv"
                return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
                    .include = include,
                    .parent_context = self,
                    .types = &ns_info->types,
                    .values = &ns_info->values,
                    .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
                });
            } break;
            #line 86 "src/analyzer/c/IncludeContext.pv"
            default: {
            } break;
        }
    }

    #line 90 "src/analyzer/c/IncludeContext.pv"
    struct NamespaceCpp* ns_info = NamespaceCpp__new(include, name, self->parent);
    #line 91 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = ns_info });

    #line 93 "src/analyzer/c/IncludeContext.pv"
    return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext) {
        .include = include,
        .parent_context = self,
        .types = &ns_info->types,
        .values = &ns_info->values,
        .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
    });
}

#line 102 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 103 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 105 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 105 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 107 "src/analyzer/c/IncludeContext.pv"
    CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
    #line 108 "src/analyzer/c/IncludeContext.pv"
    struct Type* type = Include__parse_type(include, underlying_type);

    #line 110 "src/analyzer/c/IncludeContext.pv"
    if (type == 0) {
        #line 111 "src/analyzer/c/IncludeContext.pv"
        CXCursor underlying_decl = clang_getTypeDeclaration(underlying_type);
        #line 112 "src/analyzer/c/IncludeContext.pv"
        CXString underlying_name = clang_getCursorSpelling(underlying_decl);
        #line 113 "src/analyzer/c/IncludeContext.pv"
        char const* underlying_name_cstring = clang_getCString(underlying_name);

        #line 115 "src/analyzer/c/IncludeContext.pv"
        fprintf(stderr, "Missing typedef processing: %d %s %s\n", underlying_type.kind, name, underlying_name_cstring);

        #line 117 "src/analyzer/c/IncludeContext.pv"
        clang_disposeString(underlying_name);

        #line 119 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 122 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = TypedefC__new(include, name, type) });
}

#line 125 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name) {
    #line 126 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 127 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 128 "src/analyzer/c/IncludeContext.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info };

    #line 130 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 131 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 132 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 135 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 138 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name) {
    #line 139 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 140 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 141 "src/analyzer/c/IncludeContext.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info };

    #line 143 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 144 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&struct_type, include->root->allocator));
        #line 145 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 148 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 151 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name) {
    #line 152 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 153 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 154 "src/analyzer/c/IncludeContext.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });

    #line 156 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 157 "src/analyzer/c/IncludeContext.pv"
        struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 158 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 159 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 162 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 165 "src/analyzer/c/IncludeContext.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name) {
    #line 166 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 167 "src/analyzer/c/IncludeContext.pv"
    struct FunctionC* func_info = FunctionC__new(include, name);
    #line 168 "src/analyzer/c/IncludeContext.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info });
    #line 169 "src/analyzer/c/IncludeContext.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };

    #line 171 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 172 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 173 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 176 "src/analyzer/c/IncludeContext.pv"
    return func_info;
}

#line 179 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name) {
    #line 180 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 182 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 182 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 184 "src/analyzer/c/IncludeContext.pv"
    struct Indirect* indirect = ArenaAllocator__Allocator__alloc(include->root->allocator, sizeof(struct Indirect));
    #line 185 "src/analyzer/c/IncludeContext.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
    #line 186 "src/analyzer/c/IncludeContext.pv"
    struct TypedefC* typedef_ = TypedefC__new(include, name, Type__to_ptr(&indirect_type, include->root->allocator));

    #line 188 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
}

#line 191 "src/analyzer/c/IncludeContext.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    enum CXChildVisitResult __result;

    #line 192 "src/analyzer/c/IncludeContext.pv"
    struct IncludeContext* self = client_data;
    #line 193 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 195 "src/analyzer/c/IncludeContext.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 196 "src/analyzer/c/IncludeContext.pv"
    enum CXLanguageKind language = clang_getCursorLanguage(cursor);

    #line 198 "src/analyzer/c/IncludeContext.pv"
    CXString cursor_spelling = clang_getCursorSpelling(cursor);
    #line 199 "src/analyzer/c/IncludeContext.pv"
    char* name = Include__make_string(include, cursor_spelling);
    #line 200 "src/analyzer/c/IncludeContext.pv"
    clang_disposeString(cursor_spelling);

    #line 202 "src/analyzer/c/IncludeContext.pv"
    if (kind == CXCursor_Namespace) {
        #line 203 "src/analyzer/c/IncludeContext.pv"
        struct IncludeContext* ns_context = IncludeContext__add_namespace(self, name);
        #line 204 "src/analyzer/c/IncludeContext.pv"
        clang_visitChildren(cursor, IncludeContext__visitor, ns_context);
        #line 205 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_FunctionDecl) {
        #line 207 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__add_function(self, name, cursor);
        #line 208 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_EnumDecl) {
        #line 210 "src/analyzer/c/IncludeContext.pv"
        struct EnumC* enum_info = IncludeContext__add_enum(self, name);
        #line 211 "src/analyzer/c/IncludeContext.pv"
        clang_visitChildren(cursor, IncludeObjectContext__visitor_enum, &(struct IncludeObjectContext) { .context = self, .object = enum_info });
        #line 212 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if ((kind == CXCursor_StructDecl) || (kind == CXCursor_ClassDecl)) {
        #line 214 "src/analyzer/c/IncludeContext.pv"
        CXType type = clang_getCursorType(cursor);
        #line 215 "src/analyzer/c/IncludeContext.pv"
        CXString type_spelling = clang_getTypeSpelling(type);
        #line 216 "src/analyzer/c/IncludeContext.pv"
        char* type_name = Include__make_string(include, type_spelling);
        #line 217 "src/analyzer/c/IncludeContext.pv"
        clang_disposeString(type_spelling);

        #line 220 "src/analyzer/c/IncludeContext.pv"
        if (language == CXLanguage_CPlusPlus) {
            #line 221 "src/analyzer/c/IncludeContext.pv"
            struct ClassCpp* class_info = 0;
            #line 222 "src/analyzer/c/IncludeContext.pv"
            struct Type* class_type = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });

            #line 224 "src/analyzer/c/IncludeContext.pv"
            if (class_type != 0) {
                #line 225 "src/analyzer/c/IncludeContext.pv"
                switch (class_type->type) {
                    #line 226 "src/analyzer/c/IncludeContext.pv"
                    case TYPE__CLASS_CPP: {
                        #line 226 "src/analyzer/c/IncludeContext.pv"
                        struct ClassCpp* class_info2 = class_type->classcpp_value;
                        #line 227 "src/analyzer/c/IncludeContext.pv"
                        class_info = class_info2;
                    } break;
                    #line 229 "src/analyzer/c/IncludeContext.pv"
                    default: {
                    } break;
                }
            }

            #line 233 "src/analyzer/c/IncludeContext.pv"
            if (class_info == 0) {
                #line 234 "src/analyzer/c/IncludeContext.pv"
                class_info = ClassCpp__new(include, name, self->parent, kind == CXCursor_StructDecl);
                #line 235 "src/analyzer/c/IncludeContext.pv"
                IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = class_info });
            }

            #line 238 "src/analyzer/c/IncludeContext.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                .context = self,
                .object = class_info,
            });

            #line 243 "src/analyzer/c/IncludeContext.pv"
            __result = CXChildVisit_Continue;
            ArenaAllocator__Allocator__free(include->root->allocator, type_name);
            return __result;
        } else {
            #line 245 "src/analyzer/c/IncludeContext.pv"
            if (strncmp(type_name, "struct ", 7) == 0) {
                #line 246 "src/analyzer/c/IncludeContext.pv"
                struct StructC* struct_info = IncludeContext__add_struct(self, name);

                #line 248 "src/analyzer/c/IncludeContext.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });

                #line 253 "src/analyzer/c/IncludeContext.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }

            #line 256 "src/analyzer/c/IncludeContext.pv"
            if (strncmp(type_name, "union ", 7) == 0) {
                #line 257 "src/analyzer/c/IncludeContext.pv"
                struct StructC* union_info = IncludeContext__add_union(self, name);

                #line 259 "src/analyzer/c/IncludeContext.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = union_info,
                });

                #line 264 "src/analyzer/c/IncludeContext.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }
        }
        ArenaAllocator__Allocator__free(include->root->allocator, type_name);
    } else if (kind == CXCursor_TypedefDecl) {
        #line 268 "src/analyzer/c/IncludeContext.pv"
        CXType typedef_type = clang_getCursorType(cursor);
        #line 269 "src/analyzer/c/IncludeContext.pv"
        CXType canonical_type = clang_getCanonicalType(typedef_type);
        #line 270 "src/analyzer/c/IncludeContext.pv"
        CXCursor canonical_decl = clang_getTypeDeclaration(canonical_type);
        #line 271 "src/analyzer/c/IncludeContext.pv"
        enum CXCursorKind canonical_kind = clang_getCursorKind(canonical_decl);

        #line 273 "src/analyzer/c/IncludeContext.pv"
        if ((canonical_kind == CXCursor_StructDecl) || (canonical_kind == CXCursor_ClassDecl)) {
            #line 274 "src/analyzer/c/IncludeContext.pv"
            struct StructC* struct_info = IncludeContext__add_typedef_struct(self, name);

            #line 276 "src/analyzer/c/IncludeContext.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = struct_info,
            });
            #line 280 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        } else if (canonical_kind == CXCursor_UnionDecl) {
            #line 282 "src/analyzer/c/IncludeContext.pv"
            struct StructC* union_info = IncludeContext__add_typedef_union(self, name);

            #line 284 "src/analyzer/c/IncludeContext.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                .context = self,
                .object = union_info,
            });
            #line 288 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        } else if (canonical_type.kind == CXType_Pointer) {
            #line 290 "src/analyzer/c/IncludeContext.pv"
            CXType pointee_type = clang_getPointeeType(canonical_type);
            #line 291 "src/analyzer/c/IncludeContext.pv"
            CXCursor pointee_decl = clang_getTypeDeclaration(pointee_type);
            #line 292 "src/analyzer/c/IncludeContext.pv"
            enum CXCursorKind pointee_kind = clang_getCursorKind(pointee_decl);

            #line 294 "src/analyzer/c/IncludeContext.pv"
            if (pointee_type.kind == CXType_Void) {
                #line 295 "src/analyzer/c/IncludeContext.pv"
                IncludeContext__add_typedef_pointer(self, name);
            } else if (pointee_kind == CXCursor_StructDecl) {
                #line 297 "src/analyzer/c/IncludeContext.pv"
                struct StructC* struct_info = IncludeContext__add_typedef_struct_pointer(self, name);

                #line 299 "src/analyzer/c/IncludeContext.pv"
                clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, &(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                });
            } else if (pointee_type.kind == CXType_FunctionProto) {
                #line 304 "src/analyzer/c/IncludeContext.pv"
                IncludeContext__add_typedef_function_pointer(self, name);
            }
            #line 311 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        } else {
            #line 320 "src/analyzer/c/IncludeContext.pv"
            IncludeContext__add_typedef(self, name, cursor);
        }
    } else if (kind == CXCursor_VarDecl) {
        #line 323 "src/analyzer/c/IncludeContext.pv"
        CXType type = clang_getCursorType(cursor);
        #line 324 "src/analyzer/c/IncludeContext.pv"
        struct Type* resolved_type = Include__parse_type(include, type);
        #line 325 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_value(self, name, *resolved_type);

        #line 327 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_MacroDefinition) {
        #line 329 "src/analyzer/c/IncludeContext.pv"
        if (HashMap_str_Primitive__find(&include->root->primitives, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
            #line 329 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        }

        #line 331 "src/analyzer/c/IncludeContext.pv"
        if (Include__is_function_like_macro(include, cursor)) {
            #line 332 "src/analyzer/c/IncludeContext.pv"
            IncludeContext__add_basic_function(self, name);
        } else {
            #line 334 "src/analyzer/c/IncludeContext.pv"
            IncludeContext__insert_value(self, name, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = include->root->primitive_void });
        }

        #line 337 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    }

    #line 340 "src/analyzer/c/IncludeContext.pv"
    ArenaAllocator__Allocator__free(include->root->allocator, name);

    #line 342 "src/analyzer/c/IncludeContext.pv"
    return CXChildVisit_Continue;
}
