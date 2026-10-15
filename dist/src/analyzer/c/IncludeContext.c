#include <string.h>
#include <stdint.h>

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>
#include <analyzer/types/Type.h>
#include <std/HashMap_str_Type.h>
#include <std/str.h>
#include <analyzer/c/FunctionC.h>
#include <analyzer/c/Include.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <analyzer/c/UnknownC.h>
#include <analyzer/c/StructC.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/EnumCValue.h>
#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/types/Indirect.h>
#include <std/trait_Allocator.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/IncludeObjectContext.h>
#include <i32.h>
#include <std/HashMap_str_ref_Primitive.h>
#include <std/HashMap_str_i64.h>
#include <analyzer/c/IncludeContext.h>

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
    struct FunctionC* func_info = FunctionC__new(self->include, name, return_type);
    #line 27 "src/analyzer/c/IncludeContext.pv"
    struct Type func_type = (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info };
    #line 28 "src/analyzer/c/IncludeContext.pv"
    return HashMap_str_Type__insert(self->values, (struct str){ .ptr = name, .length = strlen(name) }, func_type);
}

#line 31 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_function(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 32 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 34 "src/analyzer/c/IncludeContext.pv"
    CXType cursor_return_type = clang_getCursorResultType(cursor);
    #line 35 "src/analyzer/c/IncludeContext.pv"
    struct Type* return_type = Include__parse_type(include, cursor_return_type);
    #line 36 "src/analyzer/c/IncludeContext.pv"
    if (return_type == 0) {
        #line 36 "src/analyzer/c/IncludeContext.pv"
        return_type = ArenaAllocator__store_Type(include->root->allocator, (struct Type[]){(struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = UnknownC__new(include, "") }});
    }

    #line 38 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_function(self, name, return_type);
}

#line 41 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_basic_function(struct IncludeContext* self, char const* name) {
    #line 42 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 43 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_function(self, name, ArenaAllocator__store_Type(include->root->allocator, (struct Type[]){(struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = UnknownC__new(include, "") }}));
}

#line 46 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_struct(struct IncludeContext* self, char const* name) {
    #line 47 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 48 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });
    #line 49 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 52 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_union(struct IncludeContext* self, char const* name) {
    #line 53 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(self->include, name);
    #line 54 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info });
    #line 55 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 58 "src/analyzer/c/IncludeContext.pv"
struct EnumC* IncludeContext__add_enum(struct IncludeContext* self, char const* name) {
    #line 59 "src/analyzer/c/IncludeContext.pv"
    struct EnumC* enum_info = EnumC__new(self->include, name, self->parent);
    #line 60 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
    #line 61 "src/analyzer/c/IncludeContext.pv"
    return enum_info;
}

#line 64 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_enum_value(struct IncludeContext* self, struct EnumC* enum_info, char const* value_name, int64_t value) {
    #line 65 "src/analyzer/c/IncludeContext.pv"
    HashMap_str_EnumCValue__insert(&enum_info->values, (struct str){ .ptr = value_name, .length = strlen(value_name) }, (struct EnumCValue) { .parent = enum_info, .name = (struct str){ .ptr = value_name, .length = strlen(value_name) }, .value = value });
    #line 66 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_value(self, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });
}

#line 69 "src/analyzer/c/IncludeContext.pv"
struct IncludeContext* IncludeContext__add_namespace(struct IncludeContext* self, char const* name) {
    #line 70 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 71 "src/analyzer/c/IncludeContext.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 73 "src/analyzer/c/IncludeContext.pv"
    struct Type* existing = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });
    #line 74 "src/analyzer/c/IncludeContext.pv"
    if (existing != 0) {
        #line 75 "src/analyzer/c/IncludeContext.pv"
        switch (existing->type) {
            #line 76 "src/analyzer/c/IncludeContext.pv"
            case TYPE__NAMESPACE_CPP: {
                #line 76 "src/analyzer/c/IncludeContext.pv"
                struct NamespaceCpp* ns_info = existing->namespacecpp_value;
                #line 77 "src/analyzer/c/IncludeContext.pv"
                return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext[]){(struct IncludeContext) {
                    .include = include,
                    .parent_context = self,
                    .types = &ns_info->types,
                    .values = &ns_info->values,
                    .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
                }});
            } break;
            #line 85 "src/analyzer/c/IncludeContext.pv"
            default: {
            } break;
        }
    }

    #line 89 "src/analyzer/c/IncludeContext.pv"
    struct NamespaceCpp* ns_info = NamespaceCpp__new(include, name, self->parent);
    #line 90 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__NAMESPACE_CPP, .namespacecpp_value = ns_info });

    #line 92 "src/analyzer/c/IncludeContext.pv"
    return ArenaAllocator__store_IncludeContext(allocator, (struct IncludeContext[]){(struct IncludeContext) {
        .include = include,
        .parent_context = self,
        .types = &ns_info->types,
        .values = &ns_info->values,
        .parent = (struct ParentCpp) { .type = PARENT_CPP__NAMESPACE, .namespace_value = ns_info },
    }});
}

#line 101 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 102 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 104 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 104 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 106 "src/analyzer/c/IncludeContext.pv"
    CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
    #line 107 "src/analyzer/c/IncludeContext.pv"
    struct Type* type = Include__parse_type(include, underlying_type);

    #line 109 "src/analyzer/c/IncludeContext.pv"
    if (type == 0) {
        #line 110 "src/analyzer/c/IncludeContext.pv"
        CXCursor underlying_decl = clang_getTypeDeclaration(underlying_type);
        #line 111 "src/analyzer/c/IncludeContext.pv"
        CXString underlying_name = clang_getCursorSpelling(underlying_decl);
        #line 112 "src/analyzer/c/IncludeContext.pv"
        char const* underlying_name_cstring = clang_getCString(underlying_name);

        #line 114 "src/analyzer/c/IncludeContext.pv"
        fprintf(stderr, "Missing typedef processing: %d %s %s\n", underlying_type.kind, name, underlying_name_cstring);

        #line 116 "src/analyzer/c/IncludeContext.pv"
        clang_disposeString(underlying_name);

        #line 118 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 121 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = TypedefC__new(include, (struct str){ .ptr = name, .length = strlen(name) }, type) });
}

#line 124 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct(struct IncludeContext* self, char const* name) {
    #line 125 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 126 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 127 "src/analyzer/c/IncludeContext.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info };

    #line 129 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 130 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, (struct str){ .ptr = name, .length = strlen(name) }, Type__to_ptr(&struct_type, include->root->allocator));
        #line 131 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 134 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 137 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_union(struct IncludeContext* self, char const* name) {
    #line 138 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 139 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 140 "src/analyzer/c/IncludeContext.pv"
    struct Type struct_type = (struct Type) { .type = TYPE__UNION_C, .unionc_value = struct_info };

    #line 142 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 143 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, (struct str){ .ptr = name, .length = strlen(name) }, Type__to_ptr(&struct_type, include->root->allocator));
        #line 144 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 147 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 150 "src/analyzer/c/IncludeContext.pv"
struct StructC* IncludeContext__add_typedef_struct_pointer(struct IncludeContext* self, char const* name) {
    #line 151 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 152 "src/analyzer/c/IncludeContext.pv"
    struct StructC* struct_info = StructC__new(include, "");
    #line 153 "src/analyzer/c/IncludeContext.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__STRUCT_C, .structc_value = struct_info });

    #line 155 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 156 "src/analyzer/c/IncludeContext.pv"
        struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
        #line 157 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, (struct str){ .ptr = name, .length = strlen(name) }, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 158 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 161 "src/analyzer/c/IncludeContext.pv"
    return struct_info;
}

#line 164 "src/analyzer/c/IncludeContext.pv"
struct FunctionC* IncludeContext__add_typedef_function_pointer(struct IncludeContext* self, char const* name) {
    #line 165 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 166 "src/analyzer/c/IncludeContext.pv"
    struct FunctionC* func_info = FunctionC__new(include, name, ArenaAllocator__store_Type(include->root->allocator, (struct Type[]){(struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = UnknownC__new(include, "") }}));
    #line 167 "src/analyzer/c/IncludeContext.pv"
    struct Indirect* indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator }, (struct Type) { .type = TYPE__FUNCTION_C, .functionc_value = func_info });
    #line 168 "src/analyzer/c/IncludeContext.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };

    #line 170 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
        #line 171 "src/analyzer/c/IncludeContext.pv"
        struct TypedefC* typedef_ = TypedefC__new(include, (struct str){ .ptr = name, .length = strlen(name) }, Type__to_ptr(&indirect_type, include->root->allocator));
        #line 172 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
    }

    #line 175 "src/analyzer/c/IncludeContext.pv"
    return func_info;
}

#line 178 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_typedef_pointer(struct IncludeContext* self, char const* name) {
    #line 179 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 181 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 181 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 183 "src/analyzer/c/IncludeContext.pv"
    struct Indirect* indirect = ArenaAllocator__Allocator__alloc(include->root->allocator, sizeof(struct Indirect));
    #line 184 "src/analyzer/c/IncludeContext.pv"
    indirect->to = include->root->type_void;
    #line 185 "src/analyzer/c/IncludeContext.pv"
    struct Type indirect_type = (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect };
    #line 186 "src/analyzer/c/IncludeContext.pv"
    struct TypedefC* typedef_ = TypedefC__new(include, (struct str){ .ptr = name, .length = strlen(name) }, Type__to_ptr(&indirect_type, include->root->allocator));

    #line 188 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
}

#line 195 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_type_alias(struct IncludeContext* self, char const* name, CXCursor cursor) {
    #line 196 "src/analyzer/c/IncludeContext.pv"
    IncludeContext__add_type_alias_into(self, self->types, self->parent, name, cursor);
}

#line 201 "src/analyzer/c/IncludeContext.pv"
void IncludeContext__add_type_alias_into(struct IncludeContext* self, struct HashMap_str_Type* types, struct ParentCpp parent, char const* name, CXCursor cursor) {
    #line 202 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;
    #line 203 "src/analyzer/c/IncludeContext.pv"
    if (HashMap_str_Type__find(types, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
        #line 203 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 205 "src/analyzer/c/IncludeContext.pv"
    CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
    #line 206 "src/analyzer/c/IncludeContext.pv"
    CXType canonical_type = clang_getCanonicalType(underlying_type);
    #line 207 "src/analyzer/c/IncludeContext.pv"
    if (canonical_type.kind == CXType_Record && clang_Type_getNumTemplateArguments(canonical_type) > 0) {
        #line 208 "src/analyzer/c/IncludeContext.pv"
        struct ClassCpp* class_info = ClassCpp__new(include, name, parent, true);
        #line 209 "src/analyzer/c/IncludeContext.pv"
        HashMap_str_Type__insert(types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = class_info });
        #line 210 "src/analyzer/c/IncludeContext.pv"
        clang_Type_visitFields(canonical_type, IncludeObjectContext__visitor_alias_field, (struct IncludeObjectContext[]){(struct IncludeObjectContext) {
            .context = self,
            .object = class_info,
        }});
        #line 214 "src/analyzer/c/IncludeContext.pv"
        return;
    }

    #line 217 "src/analyzer/c/IncludeContext.pv"
    struct Type* resolved = Include__parse_type(include, underlying_type);
    #line 218 "src/analyzer/c/IncludeContext.pv"
    if (resolved == 0) {
        #line 218 "src/analyzer/c/IncludeContext.pv"
        return;
    }
    #line 219 "src/analyzer/c/IncludeContext.pv"
    switch (resolved->type) {
        #line 220 "src/analyzer/c/IncludeContext.pv"
        case TYPE__UNKNOWN_C: {
            #line 220 "src/analyzer/c/IncludeContext.pv"
            return;
        } break;
        #line 221 "src/analyzer/c/IncludeContext.pv"
        default: {
        } break;
    }
    #line 223 "src/analyzer/c/IncludeContext.pv"
    HashMap_str_Type__insert(types, (struct str){ .ptr = name, .length = strlen(name) }, *resolved);
}

#line 226 "src/analyzer/c/IncludeContext.pv"
enum CXChildVisitResult IncludeContext__visitor(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    enum CXChildVisitResult __result;

    #line 227 "src/analyzer/c/IncludeContext.pv"
    struct IncludeContext* self = client_data;
    #line 228 "src/analyzer/c/IncludeContext.pv"
    struct Include* include = self->include;

    #line 230 "src/analyzer/c/IncludeContext.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 231 "src/analyzer/c/IncludeContext.pv"
    enum CXLanguageKind language = clang_getCursorLanguage(cursor);

    #line 233 "src/analyzer/c/IncludeContext.pv"
    CXString cursor_spelling = clang_getCursorSpelling(cursor);
    #line 234 "src/analyzer/c/IncludeContext.pv"
    char* name = Include__make_string(include, cursor_spelling);
    #line 235 "src/analyzer/c/IncludeContext.pv"
    clang_disposeString(cursor_spelling);

    #line 237 "src/analyzer/c/IncludeContext.pv"
    if (kind == CXCursor_Namespace) {
        #line 238 "src/analyzer/c/IncludeContext.pv"
        struct IncludeContext* ns_context = IncludeContext__add_namespace(self, name);
        #line 239 "src/analyzer/c/IncludeContext.pv"
        clang_visitChildren(cursor, IncludeContext__visitor, ns_context);
        #line 240 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_LinkageSpec) {
        #line 242 "src/analyzer/c/IncludeContext.pv"
        clang_visitChildren(cursor, IncludeContext__visitor, self);
        #line 243 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_FunctionDecl) {
        #line 245 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__add_function(self, name, cursor);
        #line 246 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_TypeAliasDecl) {
        #line 248 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__add_type_alias(self, name, cursor);
        #line 249 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_EnumDecl) {
        #line 251 "src/analyzer/c/IncludeContext.pv"
        struct EnumC* enum_info = IncludeContext__add_enum(self, name);
        #line 252 "src/analyzer/c/IncludeContext.pv"
        clang_visitChildren(cursor, IncludeObjectContext__visitor_enum, (struct IncludeObjectContext[]){(struct IncludeObjectContext) { .context = self, .object = enum_info }});
        #line 253 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_StructDecl || kind == CXCursor_ClassDecl) {
        #line 255 "src/analyzer/c/IncludeContext.pv"
        CXType type = clang_getCursorType(cursor);
        #line 256 "src/analyzer/c/IncludeContext.pv"
        CXString type_spelling = clang_getTypeSpelling(type);
        #line 257 "src/analyzer/c/IncludeContext.pv"
        char* type_name = Include__make_string(include, type_spelling);
        #line 258 "src/analyzer/c/IncludeContext.pv"
        clang_disposeString(type_spelling);
        #line 259 "src/analyzer/c/IncludeContext.pv"

        #line 261 "src/analyzer/c/IncludeContext.pv"
        if (language == CXLanguage_CPlusPlus) {
            #line 262 "src/analyzer/c/IncludeContext.pv"
            struct ClassCpp* class_info = 0;
            #line 263 "src/analyzer/c/IncludeContext.pv"
            struct Type* class_type = HashMap_str_Type__find(self->types, &(struct str){ .ptr = name, .length = strlen(name) });

            #line 265 "src/analyzer/c/IncludeContext.pv"
            if (class_type != 0) {
                #line 266 "src/analyzer/c/IncludeContext.pv"
                switch (class_type->type) {
                    #line 267 "src/analyzer/c/IncludeContext.pv"
                    case TYPE__CLASS_CPP: {
                        #line 267 "src/analyzer/c/IncludeContext.pv"
                        struct ClassCpp* class_info2 = class_type->classcpp_value;
                        #line 268 "src/analyzer/c/IncludeContext.pv"
                        class_info = class_info2;
                    } break;
                    #line 270 "src/analyzer/c/IncludeContext.pv"
                    default: {
                    } break;
                }
            }

            #line 274 "src/analyzer/c/IncludeContext.pv"
            if (class_info == 0) {
                #line 275 "src/analyzer/c/IncludeContext.pv"
                class_info = ClassCpp__new(include, name, self->parent, kind == CXCursor_StructDecl);
                #line 276 "src/analyzer/c/IncludeContext.pv"
                IncludeContext__insert_type(self, name, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = class_info });
            }
            #line 280 "src/analyzer/c/IncludeContext.pv"
            if (class_info != 0 && clang_isCursorDefinition(cursor) != 0) {
                #line 280 "src/analyzer/c/IncludeContext.pv"
                class_info->include = include;
            }

            #line 282 "src/analyzer/c/IncludeContext.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_class, (struct IncludeObjectContext[]){(struct IncludeObjectContext) {
                .context = self,
                .object = class_info,
            }});

            #line 287 "src/analyzer/c/IncludeContext.pv"
            __result = CXChildVisit_Continue;
            ArenaAllocator__Allocator__free(include->root->allocator, type_name);
            return __result;
        } else {
            #line 289 "src/analyzer/c/IncludeContext.pv"
            if (i32__Eq_i32__eq(strncmp(type_name, "struct ", 7), 0)) {
                #line 290 "src/analyzer/c/IncludeContext.pv"
                struct StructC* struct_info = IncludeContext__add_struct(self, name);

                #line 292 "src/analyzer/c/IncludeContext.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, (struct IncludeObjectContext[]){(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                }});

                #line 297 "src/analyzer/c/IncludeContext.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }

            #line 300 "src/analyzer/c/IncludeContext.pv"
            if (i32__Eq_i32__eq(strncmp(type_name, "union ", 7), 0)) {
                #line 301 "src/analyzer/c/IncludeContext.pv"
                struct StructC* union_info = IncludeContext__add_union(self, name);

                #line 303 "src/analyzer/c/IncludeContext.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_struct, (struct IncludeObjectContext[]){(struct IncludeObjectContext) {
                    .context = self,
                    .object = union_info,
                }});

                #line 308 "src/analyzer/c/IncludeContext.pv"
                __result = CXChildVisit_Continue;
                ArenaAllocator__Allocator__free(include->root->allocator, type_name);
                return __result;
            }
        }
        ArenaAllocator__Allocator__free(include->root->allocator, type_name);
    } else if (kind == CXCursor_TypedefDecl) {
        #line 312 "src/analyzer/c/IncludeContext.pv"
        CXType typedef_type = clang_getCursorType(cursor);
        #line 313 "src/analyzer/c/IncludeContext.pv"
        CXType canonical_type = clang_getCanonicalType(typedef_type);
        #line 314 "src/analyzer/c/IncludeContext.pv"
        CXCursor canonical_decl = clang_getTypeDeclaration(canonical_type);
        #line 315 "src/analyzer/c/IncludeContext.pv"
        enum CXCursorKind canonical_kind = clang_getCursorKind(canonical_decl);
        #line 319 "src/analyzer/c/IncludeContext.pv"
        if (canonical_type.kind == CXType_Record && clang_Type_getNumTemplateArguments(canonical_type) > 0) {
            #line 320 "src/analyzer/c/IncludeContext.pv"
            IncludeContext__add_type_alias(self, name, cursor);
            #line 321 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        }

        #line 324 "src/analyzer/c/IncludeContext.pv"
        if (canonical_kind == CXCursor_StructDecl || canonical_kind == CXCursor_ClassDecl) {
            #line 325 "src/analyzer/c/IncludeContext.pv"
            struct StructC* struct_info = IncludeContext__add_typedef_struct(self, name);

            #line 327 "src/analyzer/c/IncludeContext.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, (struct IncludeObjectContext[]){(struct IncludeObjectContext) {
                .context = self,
                .object = struct_info,
            }});
            #line 331 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        } else if (canonical_kind == CXCursor_UnionDecl) {
            #line 333 "src/analyzer/c/IncludeContext.pv"
            struct StructC* union_info = IncludeContext__add_typedef_union(self, name);

            #line 335 "src/analyzer/c/IncludeContext.pv"
            clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, (struct IncludeObjectContext[]){(struct IncludeObjectContext) {
                .context = self,
                .object = union_info,
            }});
            #line 339 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        } else if (canonical_type.kind == CXType_Pointer) {
            #line 341 "src/analyzer/c/IncludeContext.pv"
            CXType pointee_type = clang_getPointeeType(canonical_type);
            #line 342 "src/analyzer/c/IncludeContext.pv"
            CXCursor pointee_decl = clang_getTypeDeclaration(pointee_type);
            #line 343 "src/analyzer/c/IncludeContext.pv"
            enum CXCursorKind pointee_kind = clang_getCursorKind(pointee_decl);

            #line 345 "src/analyzer/c/IncludeContext.pv"
            if (pointee_type.kind == CXType_Void) {
                #line 346 "src/analyzer/c/IncludeContext.pv"
                IncludeContext__add_typedef_pointer(self, name);
            } else if (pointee_kind == CXCursor_StructDecl) {
                #line 348 "src/analyzer/c/IncludeContext.pv"
                struct StructC* struct_info = IncludeContext__add_typedef_struct_pointer(self, name);

                #line 350 "src/analyzer/c/IncludeContext.pv"
                clang_visitChildren(canonical_decl, IncludeObjectContext__visitor_struct, (struct IncludeObjectContext[]){(struct IncludeObjectContext) {
                    .context = self,
                    .object = struct_info,
                }});
            } else if (pointee_type.kind == CXType_FunctionProto) {
                #line 355 "src/analyzer/c/IncludeContext.pv"
                IncludeContext__add_typedef_function_pointer(self, name);
            }
            #line 357 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        } else {
            #line 366 "src/analyzer/c/IncludeContext.pv"
            IncludeContext__add_typedef(self, name, cursor);
            #line 367 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        }
    } else if (kind == CXCursor_VarDecl) {
        #line 370 "src/analyzer/c/IncludeContext.pv"
        CXType type = clang_getCursorType(cursor);
        #line 371 "src/analyzer/c/IncludeContext.pv"
        struct Type* resolved_type = Include__parse_type(include, type);
        #line 372 "src/analyzer/c/IncludeContext.pv"
        IncludeContext__insert_value(self, name, *resolved_type);

        #line 374 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    } else if (kind == CXCursor_MacroDefinition) {
        #line 376 "src/analyzer/c/IncludeContext.pv"
        if (HashMap_str_ref_Primitive__find(&include->root->primitives, &(struct str){ .ptr = name, .length = strlen(name) }) != 0) {
            #line 376 "src/analyzer/c/IncludeContext.pv"
            return CXChildVisit_Continue;
        }

        #line 378 "src/analyzer/c/IncludeContext.pv"
        if (Include__is_function_like_macro(include, cursor)) {
            #line 379 "src/analyzer/c/IncludeContext.pv"
            IncludeContext__add_basic_function(self, name);
        } else {
            #line 381 "src/analyzer/c/IncludeContext.pv"
            int64_t macro_value = 0;
            #line 382 "src/analyzer/c/IncludeContext.pv"
            if (Include__try_parse_int_macro(include, cursor, &macro_value)) {
                #line 383 "src/analyzer/c/IncludeContext.pv"
                HashMap_str_i64__insert(&include->macro_values, (struct str){ .ptr = name, .length = strlen(name) }, macro_value);
            }
            #line 385 "src/analyzer/c/IncludeContext.pv"
            IncludeContext__insert_value(self, name, (struct Type) { .type = TYPE__UNKNOWN_C, .unknownc_value = UnknownC__new(include, name) });
        }

        #line 388 "src/analyzer/c/IncludeContext.pv"
        return CXChildVisit_Continue;
    }

    #line 391 "src/analyzer/c/IncludeContext.pv"
    ArenaAllocator__Allocator__free(include->root->allocator, name);

    #line 393 "src/analyzer/c/IncludeContext.pv"
    return CXChildVisit_Continue;
}
