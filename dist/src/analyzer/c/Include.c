#include <stdint.h>
#include <string.h>

#include <clang-c/Index.h>
#include <string.h>

#include <clang-c/Index.h>
#include <string.h>
#include <analyzer/c/Include.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <std/trait_Allocator.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/types/Type.h>
#include <analyzer/types/Primitive.h>
#include <std/Array_ptrc_char.h>
#include <std/String.h>
#include <analyzer/c/IncludeContext.h>
#include <analyzer/c/ParentCpp.h>
#include <analyzer/types/Indirect.h>
#include <std/Array_CXCursor.h>
#include <analyzer/c/NamespaceCpp.h>
#include <analyzer/c/ClassCpp.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/Include.h>

#include <analyzer/c/Include.h>

#line 21 "src/analyzer/c/Include.pv"
struct Include* Include__new(struct Root* root, struct str path, bool mode_cpp) {
    #line 22 "src/analyzer/c/Include.pv"
    struct Include* self = ArenaAllocator__store_Include(root->allocator, (struct Include[]){(struct Include) {
        .root = root,
        .mode_cpp = mode_cpp,
        .path = path,
        .cxtype_to_type = HashMap_u32_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .typedef_to_type = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .types = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .values = HashMap_str_Type__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .macro_values = HashMap_str_i64__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
    }});

    #line 33 "src/analyzer/c/Include.pv"
    if (self == 0) {
        #line 34 "src/analyzer/c/Include.pv"
        Root__error(root, path, 0, 0, 0, 0, "Failed to allocate Include");
        #line 35 "src/analyzer/c/Include.pv"
        return 0;
    }

    #line 38 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Void, "void");

    #line 40 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Bool, "bool");

    #line 42 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Char_S, "char");
    #line 43 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Char_U, "char");

    #line 45 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_SChar, "i8");
    #line 46 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Short, "i16");
    #line 47 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Int, "i32");
    #line 48 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Long, "i32");
    #line 49 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_LongLong, "i64");

    #line 51 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UChar, "u8");
    #line 52 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UShort, "u16");
    #line 53 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UInt, "u32");
    #line 54 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_ULong, "u32");
    #line 55 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_ULongLong, "u64");

    #line 57 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Float, "f32");
    #line 58 "src/analyzer/c/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Double, "f64");

    #line 60 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "bool", "bool");

    #line 62 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "int8_t", "i8");
    #line 63 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "int16_t", "i16");
    #line 64 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "int32_t", "i32");
    #line 65 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "int64_t", "i64");

    #line 67 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "uint8_t", "u8");
    #line 68 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "uint16_t", "u16");
    #line 69 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "uint32_t", "u32");
    #line 70 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "uint64_t", "u64");

    #line 72 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "size_t", "usize");

    #line 74 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Sint8", "i8");
    #line 75 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Sint16", "i16");
    #line 76 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Sint32", "i32");
    #line 77 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Sint64", "i64");

    #line 79 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Uint8", "u8");
    #line 80 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Uint16", "u16");
    #line 81 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Uint32", "u32");
    #line 82 "src/analyzer/c/Include.pv"
    Include__add_typedef_primitive(self, "Uint64", "u64");

    #line 84 "src/analyzer/c/Include.pv"
    return self;
}

#line 87 "src/analyzer/c/Include.pv"
void Include__add_cxtype_primitive(struct Include* self, enum CXTypeKind kind, char const* name) {
    #line 88 "src/analyzer/c/Include.pv"
    struct HashMap_str_Primitive primitives = self->root->primitives;

    #line 90 "src/analyzer/c/Include.pv"
    HashMap_u32_Type__insert(&self->cxtype_to_type, (uint32_t)(kind), (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = HashMap_str_Primitive__find(&primitives, &(struct str){ .ptr = name, .length = strlen(name) }) });
}

#line 93 "src/analyzer/c/Include.pv"
void Include__add_typedef_primitive(struct Include* self, char const* type, char const* name) {
    #line 94 "src/analyzer/c/Include.pv"
    struct HashMap_str_Primitive* primitives = &self->root->primitives;
    #line 95 "src/analyzer/c/Include.pv"
    HashMap_str_Type__insert(&self->typedef_to_type, (struct str){ .ptr = type, .length = strlen(type) }, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = HashMap_str_Primitive__find(primitives, &(struct str){ .ptr = name, .length = strlen(name) }) });
}

#line 98 "src/analyzer/c/Include.pv"
bool Include__process(struct Include* self) {
    #line 99 "src/analyzer/c/Include.pv"
    struct Root* root = self->root;
    #line 100 "src/analyzer/c/Include.pv"
    struct Array_ptrc_char clang_args = root->clang_args;
    #line 101 "src/analyzer/c/Include.pv"
    bool release_clang_args = false;

    #line 103 "src/analyzer/c/Include.pv"
    struct String path = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
    #line 104 "src/analyzer/c/Include.pv"
    String__append(&path, str__slice(self->path, 1, self->path.length - 1));

    #line 106 "src/analyzer/c/Include.pv"
    struct String file_content = String__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
    #line 107 "src/analyzer/c/Include.pv"
    String__append(&file_content, (struct str){ .ptr = "#include <", .length = strlen("#include <") });
    #line 108 "src/analyzer/c/Include.pv"
    String__append(&file_content, String__as_str(&path));
    #line 109 "src/analyzer/c/Include.pv"
    String__append(&file_content, (struct str){ .ptr = ">", .length = strlen(">") });

    #line 111 "src/analyzer/c/Include.pv"
    char const* filename = "__temp.c";
    #line 112 "src/analyzer/c/Include.pv"
    if (self->mode_cpp) {
        #line 113 "src/analyzer/c/Include.pv"
        filename = "__temp.cpp";
        #line 114 "src/analyzer/c/Include.pv"
        clang_args = Array_ptrc_char__clone(&clang_args, (struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
        #line 115 "src/analyzer/c/Include.pv"
        Array_ptrc_char__append(&clang_args, "-std=c++17");
        #line 116 "src/analyzer/c/Include.pv"
        release_clang_args = true;
    }

    #line 119 "src/analyzer/c/Include.pv"
    struct CXUnsavedFile unsaved = (struct CXUnsavedFile) {
        .Filename = filename,
        .Contents = String__c_str(&file_content),
        .Length = String__length(&file_content),
    };

    #line 125 "src/analyzer/c/Include.pv"
    CXIndex index = clang_createIndex(0, 1);
    #line 126 "src/analyzer/c/Include.pv"
    if (index == (CXIndex)(0)) {
        #line 127 "src/analyzer/c/Include.pv"
        Root__error(self->root, self->path, 0, 0, 0, 0, "clang_createIndex failed\n");
        #line 128 "src/analyzer/c/Include.pv"
        return false;
    }

    #line 131 "src/analyzer/c/Include.pv"
    CXTranslationUnit unit;

    #line 133 "src/analyzer/c/Include.pv"
    enum CXErrorCode result = clang_parseTranslationUnit2(index, filename, clang_args.data, clang_args.length, &unsaved, 1, CXTranslationUnit_None | CXTranslationUnit_DetailedPreprocessingRecord | CXTranslationUnit_Incomplete | CXTranslationUnit_SkipFunctionBodies, &unit);

    #line 142 "src/analyzer/c/Include.pv"
    if (release_clang_args) {
        #line 143 "src/analyzer/c/Include.pv"
        Array_ptrc_char__release(&clang_args);
    }

    #line 151 "src/analyzer/c/Include.pv"
    switch (result) {
        #line 152 "src/analyzer/c/Include.pv"
        case CXError_Failure: {
            #line 153 "src/analyzer/c/Include.pv"
            uintptr_t num_errors = clang_getNumDiagnostics(unit);
            #line 154 "src/analyzer/c/Include.pv"
            uintptr_t display_options = clang_defaultDiagnosticDisplayOptions();

            #line 156 "src/analyzer/c/Include.pv"
            if (num_errors == 0) {
                #line 157 "src/analyzer/c/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Failure no errors");
            } else {
                #line 159 "src/analyzer/c/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Failure has errors");
            }

            #line 162 "src/analyzer/c/Include.pv"
            uintptr_t i = 0;
            #line 163 "src/analyzer/c/Include.pv"
            while (i < num_errors) {
                #line 164 "src/analyzer/c/Include.pv"
                CXDiagnostic diag = clang_getDiagnostic(unit, i);
                #line 165 "src/analyzer/c/Include.pv"
                CXString str = clang_formatDiagnostic(diag, display_options);

                #line 167 "src/analyzer/c/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, clang_getCString(str));

                #line 169 "src/analyzer/c/Include.pv"
                clang_disposeString(str);
                #line 170 "src/analyzer/c/Include.pv"
                clang_disposeDiagnostic(diag);
                #line 171 "src/analyzer/c/Include.pv"
                i += 1;
            }
        } break;
        #line 174 "src/analyzer/c/Include.pv"
        case CXError_Crashed: {
            #line 174 "src/analyzer/c/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Crashed");
        } break;
        #line 175 "src/analyzer/c/Include.pv"
        case CXError_InvalidArguments: {
            #line 175 "src/analyzer/c/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_InvalidArguments");
        } break;
        #line 176 "src/analyzer/c/Include.pv"
        case CXError_ASTReadError: {
            #line 176 "src/analyzer/c/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_ASTReadError");
        } break;
        #line 177 "src/analyzer/c/Include.pv"
        case CXError_Success: {
        } break;
    }

    #line 180 "src/analyzer/c/Include.pv"
    CXCursor cursor = clang_getTranslationUnitCursor(unit);
    #line 181 "src/analyzer/c/Include.pv"
    clang_visitChildren(cursor, IncludeContext__visitor, (struct IncludeContext[]){(struct IncludeContext) { .include = self, .parent_context = 0, .types = &self->types, .values = &self->values, .parent = (struct ParentCpp) { .type = PARENT_CPP__NONE } }});

    #line 183 "src/analyzer/c/Include.pv"
    clang_disposeTranslationUnit(unit);
    #line 184 "src/analyzer/c/Include.pv"
    clang_disposeIndex(index);

    #line 186 "src/analyzer/c/Include.pv"
    return true;
}

#line 189 "src/analyzer/c/Include.pv"
struct Type* Include__parse_type(struct Include* self, CXType type) {
    #line 190 "src/analyzer/c/Include.pv"
    uint32_t type_u32 = (uint32_t)(type.kind);
    #line 191 "src/analyzer/c/Include.pv"
    struct Type* lookup = HashMap_u32_Type__find(&self->cxtype_to_type, &type_u32);

    #line 193 "src/analyzer/c/Include.pv"
    if (lookup != 0) {
        #line 194 "src/analyzer/c/Include.pv"
        return lookup;
    }

    #line 197 "src/analyzer/c/Include.pv"
    if (type.kind == CXType_Pointer) {
        #line 198 "src/analyzer/c/Include.pv"
        CXType pointee_type = clang_getPointeeType(type);
        #line 199 "src/analyzer/c/Include.pv"
        bool is_pointee_const = clang_isConstQualifiedType(pointee_type) != 0;
        #line 200 "src/analyzer/c/Include.pv"
        struct Type* resolved_pointee_type = Include__parse_type(self, pointee_type);

        #line 202 "src/analyzer/c/Include.pv"
        struct Indirect* indirect;
        #line 203 "src/analyzer/c/Include.pv"
        if (is_pointee_const) {
            #line 204 "src/analyzer/c/Include.pv"
            indirect = Indirect__new_const_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator }, *resolved_pointee_type);
        } else {
            #line 206 "src/analyzer/c/Include.pv"
            indirect = Indirect__new_pointer((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator }, *resolved_pointee_type);
        }

        #line 209 "src/analyzer/c/Include.pv"
        return ArenaAllocator__store_Type(self->root->allocator, (struct Type[]){(struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect }});
    }

    #line 212 "src/analyzer/c/Include.pv"
    if (type.kind == CXType_Elaborated) {
        #line 213 "src/analyzer/c/Include.pv"
        CXCursor decl = clang_getTypeDeclaration(type);

        #line 215 "src/analyzer/c/Include.pv"
        struct Array_CXCursor path = Array_CXCursor__new((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
        #line 216 "src/analyzer/c/Include.pv"
        CXCursor parent = clang_getCursorSemanticParent(decl);
        #line 217 "src/analyzer/c/Include.pv"
        while (clang_getCursorKind(parent) == CXCursor_Namespace || clang_getCursorKind(parent) == CXCursor_ClassDecl || clang_getCursorKind(parent) == CXCursor_StructDecl) {
            #line 218 "src/analyzer/c/Include.pv"
            Array_CXCursor__append(&path, parent);
            #line 219 "src/analyzer/c/Include.pv"
            parent = clang_getCursorSemanticParent(parent);
        }

        #line 222 "src/analyzer/c/Include.pv"
        if (path.length > 0) {
            #line 223 "src/analyzer/c/Include.pv"
            struct HashMap_str_Type* current_types = &self->types;
            #line 224 "src/analyzer/c/Include.pv"
            uintptr_t i = path.length;
            #line 225 "src/analyzer/c/Include.pv"
            while (i > 0) {
                #line 226 "src/analyzer/c/Include.pv"
                i -= 1;
                #line 227 "src/analyzer/c/Include.pv"
                CXString ns_spelling = clang_getCursorSpelling(path.data[i]);
                #line 228 "src/analyzer/c/Include.pv"
                char const* ns_name = clang_getCString(ns_spelling);

                #line 230 "src/analyzer/c/Include.pv"
                struct Type* ns_type = HashMap_str_Type__find(current_types, &(struct str){ .ptr = ns_name, .length = strlen(ns_name) });
                #line 231 "src/analyzer/c/Include.pv"
                clang_disposeString(ns_spelling);

                #line 233 "src/analyzer/c/Include.pv"
                if (ns_type == 0) {
                    #line 233 "src/analyzer/c/Include.pv"
                    return &self->root->type_unknown;
                }

                #line 235 "src/analyzer/c/Include.pv"
                switch (ns_type->type) {
                    #line 236 "src/analyzer/c/Include.pv"
                    case TYPE__NAMESPACE_CPP: {
                        #line 236 "src/analyzer/c/Include.pv"
                        struct NamespaceCpp* ns_info = ns_type->namespacecpp_value;
                        #line 236 "src/analyzer/c/Include.pv"
                        current_types = &ns_info->types;
                    } break;
                    #line 237 "src/analyzer/c/Include.pv"
                    case TYPE__CLASS_CPP: {
                        #line 237 "src/analyzer/c/Include.pv"
                        struct ClassCpp* class_info = ns_type->classcpp_value;
                        #line 237 "src/analyzer/c/Include.pv"
                        current_types = &class_info->types;
                    } break;
                    #line 238 "src/analyzer/c/Include.pv"
                    default: {
                        #line 238 "src/analyzer/c/Include.pv"
                        return &self->root->type_unknown;
                    } break;
                }
            }

            #line 242 "src/analyzer/c/Include.pv"
            CXString name_spelling = clang_getCursorSpelling(decl);
            #line 243 "src/analyzer/c/Include.pv"
            char const* name = clang_getCString(name_spelling);
            #line 244 "src/analyzer/c/Include.pv"
            struct Type* lookup = HashMap_str_Type__find(current_types, &(struct str){ .ptr = name, .length = strlen(name) });
            #line 245 "src/analyzer/c/Include.pv"
            clang_disposeString(name_spelling);

            #line 247 "src/analyzer/c/Include.pv"
            if (lookup != 0) {
                #line 247 "src/analyzer/c/Include.pv"
                return lookup;
            }
            #line 248 "src/analyzer/c/Include.pv"
            return &self->root->type_unknown;
        }

        #line 251 "src/analyzer/c/Include.pv"
        CXString name_spelling = clang_getCursorSpelling(decl);
        #line 252 "src/analyzer/c/Include.pv"
        char const* name = clang_getCString(name_spelling);

        #line 254 "src/analyzer/c/Include.pv"
        struct Type* resolve = HashMap_str_Type__find(&self->typedef_to_type, &(struct str){ .ptr = name, .length = strlen(name) });
        #line 255 "src/analyzer/c/Include.pv"
        if (resolve != 0) {
            #line 256 "src/analyzer/c/Include.pv"
            clang_disposeString(name_spelling);
            #line 257 "src/analyzer/c/Include.pv"
            return resolve;
        }

        #line 260 "src/analyzer/c/Include.pv"
        struct Type* lookup = HashMap_str_Type__find(&self->types, &(struct str){ .ptr = name, .length = strlen(name) });
        #line 261 "src/analyzer/c/Include.pv"
        clang_disposeString(name_spelling);

        #line 263 "src/analyzer/c/Include.pv"
        if (lookup == 0) {
            #line 263 "src/analyzer/c/Include.pv"
            return &self->root->type_unknown;
        }
        #line 264 "src/analyzer/c/Include.pv"
        return lookup;
    }

    #line 267 "src/analyzer/c/Include.pv"
    return &self->root->type_unknown;
}

#line 270 "src/analyzer/c/Include.pv"
struct EnumC* Include__find_enum(struct Include* self, char const* name) {
    #line 271 "src/analyzer/c/Include.pv"
    struct Type* type_info = HashMap_str_Type__find(&self->types, &(struct str){ .ptr = name, .length = strlen(name) });

    #line 273 "src/analyzer/c/Include.pv"
    switch (type_info->type) {
        #line 274 "src/analyzer/c/Include.pv"
        case TYPE__ENUM_C: {
            #line 274 "src/analyzer/c/Include.pv"
            struct EnumC* enum_info = type_info->enumc_value;
            #line 274 "src/analyzer/c/Include.pv"
            return enum_info;
        } break;
        #line 275 "src/analyzer/c/Include.pv"
        default: {
        } break;
    }

    #line 278 "src/analyzer/c/Include.pv"
    return 0;
}

#line 281 "src/analyzer/c/Include.pv"
char* Include__make_string(struct Include* self, CXString s) {
    #line 282 "src/analyzer/c/Include.pv"
    uintptr_t length = strlen(clang_getCString(s));
    #line 283 "src/analyzer/c/Include.pv"
    char* result = ArenaAllocator__Allocator__alloc(self->root->allocator, length + 1);
    #line 284 "src/analyzer/c/Include.pv"
    memcpy(result, clang_getCString(s), length + 1);
    #line 285 "src/analyzer/c/Include.pv"
    return result;
}

#line 288 "src/analyzer/c/Include.pv"
struct str Include__make_str(struct Include* self, CXString s) {
    #line 289 "src/analyzer/c/Include.pv"
    uintptr_t length = strlen(clang_getCString(s));
    #line 290 "src/analyzer/c/Include.pv"
    char* ptr = ArenaAllocator__Allocator__alloc(self->root->allocator, length + 1);
    #line 291 "src/analyzer/c/Include.pv"
    memcpy(ptr, clang_getCString(s), length + 1);
    #line 292 "src/analyzer/c/Include.pv"
    return (struct str) { .ptr = ptr, .length = length };
}

#line 295 "src/analyzer/c/Include.pv"
bool Include__try_parse_int_macro(struct Include* self, CXCursor cursor, int64_t* out) {
    #line 296 "src/analyzer/c/Include.pv"
    CXSourceRange range = clang_getCursorExtent(cursor);
    #line 297 "src/analyzer/c/Include.pv"
    CXTranslationUnit tu = clang_Cursor_getTranslationUnit(cursor);

    #line 299 "src/analyzer/c/Include.pv"
    CXToken* tokens = 0;
    #line 300 "src/analyzer/c/Include.pv"
    uint32_t num_tokens = 0;
    #line 301 "src/analyzer/c/Include.pv"
    clang_tokenize(tu, range, &tokens, &num_tokens);

    #line 303 "src/analyzer/c/Include.pv"
    bool result = false;
    #line 304 "src/analyzer/c/Include.pv"
    bool negate = false;
    #line 305 "src/analyzer/c/Include.pv"
    uint32_t body_index = 1;

    #line 307 "src/analyzer/c/Include.pv"
    if (num_tokens == 2 || num_tokens == 3) {
        #line 308 "src/analyzer/c/Include.pv"
        if (num_tokens == 3) {
            #line 309 "src/analyzer/c/Include.pv"
            CXString sign_spelling = clang_getTokenSpelling(tu, tokens[1]);
            #line 310 "src/analyzer/c/Include.pv"
            char const* sign_txt = clang_getCString(sign_spelling);
            #line 311 "src/analyzer/c/Include.pv"
            if (strcmp(sign_txt, "-") == 0) {
                #line 312 "src/analyzer/c/Include.pv"
                negate = true;
                #line 313 "src/analyzer/c/Include.pv"
                body_index = 2;
            } else {
                #line 315 "src/analyzer/c/Include.pv"
                clang_disposeString(sign_spelling);
                #line 316 "src/analyzer/c/Include.pv"
                clang_disposeTokens(tu, tokens, num_tokens);
                #line 317 "src/analyzer/c/Include.pv"
                return false;
            }
            #line 319 "src/analyzer/c/Include.pv"
            clang_disposeString(sign_spelling);
        }

        #line 322 "src/analyzer/c/Include.pv"
        if (clang_getTokenKind(tokens[body_index]) == CXToken_Literal) {
            #line 323 "src/analyzer/c/Include.pv"
            CXString spelling = clang_getTokenSpelling(tu, tokens[body_index]);
            #line 324 "src/analyzer/c/Include.pv"
            char const* txt = clang_getCString(spelling);

            #line 326 "src/analyzer/c/Include.pv"
            int64_t value = 0;
            #line 327 "src/analyzer/c/Include.pv"
            bool parsed = false;
            #line 328 "src/analyzer/c/Include.pv"
            uintptr_t i = 0;
            #line 329 "src/analyzer/c/Include.pv"
            uintptr_t len = strlen(txt);

            #line 331 "src/analyzer/c/Include.pv"
            if (len > 2 && txt[0] == '0' && (txt[1] == 'x' || txt[1] == 'X')) {
                #line 332 "src/analyzer/c/Include.pv"
                i = 2;
                #line 333 "src/analyzer/c/Include.pv"
                parsed = true;
                #line 334 "src/analyzer/c/Include.pv"
                while (i < len) {
                    #line 335 "src/analyzer/c/Include.pv"
                    char c = txt[i];
                    #line 336 "src/analyzer/c/Include.pv"
                    int64_t digit = 0;
                    #line 337 "src/analyzer/c/Include.pv"
                    if (c >= '0' && c <= '9') {
                        #line 337 "src/analyzer/c/Include.pv"
                        digit = c - '0';
                    } else if (c >= 'a' && c <= 'f') {
                        #line 338 "src/analyzer/c/Include.pv"
                        digit = c - 'a' + 10;
                    } else if (c >= 'A' && c <= 'F') {
                        #line 339 "src/analyzer/c/Include.pv"
                        digit = c - 'A' + 10;
                    } else {
                        #line 340 "src/analyzer/c/Include.pv"
                        break;
                    }
                    #line 341 "src/analyzer/c/Include.pv"
                    value = value * 16 + digit;
                    #line 342 "src/analyzer/c/Include.pv"
                    i += 1;
                }
            } else if (len > 0 && txt[0] >= '0' && txt[0] <= '9') {
                #line 345 "src/analyzer/c/Include.pv"
                parsed = true;
                #line 346 "src/analyzer/c/Include.pv"
                while (i < len) {
                    #line 347 "src/analyzer/c/Include.pv"
                    char c = txt[i];
                    #line 348 "src/analyzer/c/Include.pv"
                    if (c >= '0' && c <= '9') {
                        #line 349 "src/analyzer/c/Include.pv"
                        value = value * 10 + (c - '0');
                    } else {
                        #line 351 "src/analyzer/c/Include.pv"
                        break;
                    }
                    #line 353 "src/analyzer/c/Include.pv"
                    i += 1;
                }
            }

            #line 357 "src/analyzer/c/Include.pv"
            if (parsed) {
                #line 358 "src/analyzer/c/Include.pv"
                while (i < len) {
                    #line 359 "src/analyzer/c/Include.pv"
                    char c = txt[i];
                    #line 360 "src/analyzer/c/Include.pv"
                    if (c == 'u' || c == 'U' || c == 'l' || c == 'L') {
                        #line 361 "src/analyzer/c/Include.pv"
                        i += 1;
                    } else {
                        #line 363 "src/analyzer/c/Include.pv"
                        parsed = false;
                        #line 364 "src/analyzer/c/Include.pv"
                        break;
                    }
                }
            }

            #line 369 "src/analyzer/c/Include.pv"
            if (parsed) {
                #line 370 "src/analyzer/c/Include.pv"
                if (negate) {
                    #line 370 "src/analyzer/c/Include.pv"
                    value = -value;
                }
                #line 371 "src/analyzer/c/Include.pv"
                *out = value;
                #line 372 "src/analyzer/c/Include.pv"
                result = true;
            }

            #line 375 "src/analyzer/c/Include.pv"
            clang_disposeString(spelling);
        }
    }

    #line 379 "src/analyzer/c/Include.pv"
    clang_disposeTokens(tu, tokens, num_tokens);
    #line 380 "src/analyzer/c/Include.pv"
    return result;
}

#line 383 "src/analyzer/c/Include.pv"
bool Include__is_function_like_macro(struct Include* self, CXCursor cursor) {
    #line 384 "src/analyzer/c/Include.pv"
    CXSourceRange range = clang_getCursorExtent(cursor);
    #line 385 "src/analyzer/c/Include.pv"
    CXTranslationUnit tu = clang_Cursor_getTranslationUnit(cursor);

    #line 387 "src/analyzer/c/Include.pv"
    CXToken* tokens = 0;
    #line 388 "src/analyzer/c/Include.pv"
    uint32_t num_tokens = 0;
    #line 389 "src/analyzer/c/Include.pv"
    clang_tokenize(tu, range, &tokens, &num_tokens);

    #line 391 "src/analyzer/c/Include.pv"
    if (num_tokens < 2) {
        #line 392 "src/analyzer/c/Include.pv"
        clang_disposeTokens(tu, tokens, num_tokens);
        #line 393 "src/analyzer/c/Include.pv"
        return false;
    }

    #line 396 "src/analyzer/c/Include.pv"
    CXString spelling = clang_getTokenSpelling(tu, tokens[1]);
    #line 397 "src/analyzer/c/Include.pv"
    char const* txt = clang_getCString(spelling);

    #line 399 "src/analyzer/c/Include.pv"
    bool result = false;

    #line 401 "src/analyzer/c/Include.pv"
    if (strcmp(txt, "(") == 0) {
        #line 402 "src/analyzer/c/Include.pv"
        CXSourceLocation loc_name_end = clang_getRangeEnd(clang_getTokenExtent(tu, tokens[0]));
        #line 403 "src/analyzer/c/Include.pv"
        CXSourceLocation loc_paren = clang_getTokenLocation(tu, tokens[1]);

        #line 405 "src/analyzer/c/Include.pv"
        uint32_t line1 = 0;
        #line 406 "src/analyzer/c/Include.pv"
        uint32_t col1 = 0;
        #line 407 "src/analyzer/c/Include.pv"
        uint32_t line2 = 0;
        #line 408 "src/analyzer/c/Include.pv"
        uint32_t col2 = 0;

        #line 410 "src/analyzer/c/Include.pv"
        clang_getSpellingLocation(loc_name_end, 0, &line1, &col1, 0);
        #line 411 "src/analyzer/c/Include.pv"
        clang_getSpellingLocation(loc_paren, 0, &line2, &col2, 0);

        #line 413 "src/analyzer/c/Include.pv"
        if (line1 == line2 && col1 == col2) {
            #line 414 "src/analyzer/c/Include.pv"
            result = true;
        }
    }

    #line 418 "src/analyzer/c/Include.pv"
    clang_disposeString(spelling);
    #line 419 "src/analyzer/c/Include.pv"
    clang_disposeTokens(tu, tokens, num_tokens);

    #line 421 "src/analyzer/c/Include.pv"
    return result;
}
