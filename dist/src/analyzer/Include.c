#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/Root.h>
#include <std/str.h>
#include <stdbool.h>
#include <analyzer/EnumC.h>
#include <std/ArenaAllocator.h>
#include <std/HashMap_u32_Type.h>
#include <stdint.h>
#include <analyzer/Type.h>
#include <std/Allocator.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/Primitive.h>
#include <std/Array_ptrc_char.h>
#include <std/String.h>
#include <analyzer/IncludeContext.h>
#include <analyzer/ParentCpp.h>
#include <analyzer/Indirect.h>
#include <std/Array_CXCursor.h>
#include <analyzer/NamespaceCpp.h>
#include <analyzer/ClassCpp.h>

#include <analyzer/Include.h>

#line 18 "src/analyzer/Include.pv"
struct Include* Include__new(struct Root* root, struct str path, bool mode_cpp) {
    #line 19 "src/analyzer/Include.pv"
    struct Include* self = ArenaAllocator__store_Include(root->allocator, (struct Include) {
        .root = root,
        .mode_cpp = mode_cpp,
        .path = path,
        .cxtype_to_type = HashMap_u32_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .typedef_to_type = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .values = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
    });

    #line 29 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Bool, "bool");

    #line 31 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Char_S, "char");
    #line 32 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Char_U, "char");

    #line 34 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_SChar, "i8");
    #line 35 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Short, "i16");
    #line 36 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Int, "i32");
    #line 37 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Long, "i32");
    #line 38 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_LongLong, "i64");

    #line 40 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UChar, "u8");
    #line 41 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UShort, "u16");
    #line 42 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UInt, "u32");
    #line 43 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_ULong, "u32");
    #line 44 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_ULongLong, "u64");

    #line 46 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Float, "f32");
    #line 47 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Double, "f64");

    #line 49 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "bool", "bool");

    #line 51 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int8_t", "i8");
    #line 52 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int16_t", "i16");
    #line 53 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int32_t", "i32");
    #line 54 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int64_t", "i64");

    #line 56 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint8_t", "u8");
    #line 57 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint16_t", "u16");
    #line 58 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint32_t", "u32");
    #line 59 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint64_t", "u64");

    #line 61 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "size_t", "usize");

    #line 63 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint8", "i8");
    #line 64 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint16", "i16");
    #line 65 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint32", "i32");
    #line 66 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint64", "i64");

    #line 68 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint8", "u8");
    #line 69 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint16", "u16");
    #line 70 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint32", "u32");
    #line 71 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint64", "u64");

    #line 73 "src/analyzer/Include.pv"
    return self;
}

#line 76 "src/analyzer/Include.pv"
void Include__add_cxtype_primitive(struct Include* self, enum CXTypeKind kind, char const* name) {
    #line 77 "src/analyzer/Include.pv"
    struct HashMap_str_Primitive primitives = self->root->primitives;

    #line 79 "src/analyzer/Include.pv"
    HashMap_u32_Type__insert(&self->cxtype_to_type, (uint32_t)(kind), (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = HashMap_str_Primitive__find(&primitives, &(struct str){ .ptr = name, .length = strlen(name) }) });
}

#line 82 "src/analyzer/Include.pv"
void Include__add_typedef_primitive(struct Include* self, char const* type, char const* name) {
    #line 83 "src/analyzer/Include.pv"
    struct HashMap_str_Primitive* primitives = &self->root->primitives;
    #line 84 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(&self->typedef_to_type, (struct str){ .ptr = type, .length = strlen(type) }, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = HashMap_str_Primitive__find(primitives, &(struct str){ .ptr = name, .length = strlen(name) }) });
}

#line 87 "src/analyzer/Include.pv"
bool Include__process(struct Include* self) {
    #line 88 "src/analyzer/Include.pv"
    struct Root* root = self->root;
    #line 89 "src/analyzer/Include.pv"
    struct Array_ptrc_char clang_args = root->clang_args;
    #line 90 "src/analyzer/Include.pv"
    bool release_clang_args = false;

    #line 92 "src/analyzer/Include.pv"
    struct String path = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
    #line 93 "src/analyzer/Include.pv"
    String__append(&path, str__slice(self->path, 1, self->path.length - 1));

    #line 95 "src/analyzer/Include.pv"
    struct String file_content = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
    #line 96 "src/analyzer/Include.pv"
    String__append(&file_content, (struct str){ .ptr = "#include <", .length = strlen("#include <") });
    #line 97 "src/analyzer/Include.pv"
    String__append(&file_content, String__as_str(&path));
    #line 98 "src/analyzer/Include.pv"
    String__append(&file_content, (struct str){ .ptr = ">", .length = strlen(">") });

    #line 100 "src/analyzer/Include.pv"
    char const* filename = "__temp.c";
    #line 101 "src/analyzer/Include.pv"
    if (self->mode_cpp) {
        #line 102 "src/analyzer/Include.pv"
        filename = "__temp.cpp";
        #line 103 "src/analyzer/Include.pv"
        clang_args = Array_ptrc_char__clone(&clang_args, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
        #line 104 "src/analyzer/Include.pv"
        Array_ptrc_char__append(&clang_args, "-std=c++17");
        #line 105 "src/analyzer/Include.pv"
        release_clang_args = true;
    }

    #line 108 "src/analyzer/Include.pv"
    struct CXUnsavedFile unsaved = (struct CXUnsavedFile) {
        .Filename = filename,
        .Contents = String__c_str(&file_content),
        .Length = String__length(&file_content),
    };

    #line 114 "src/analyzer/Include.pv"
    CXIndex index = clang_createIndex(0, 1);
    #line 115 "src/analyzer/Include.pv"
    if (index == 0) {
        #line 116 "src/analyzer/Include.pv"
        Root__error(self->root, self->path, 0, 0, 0, 0, "clang_createIndex failed\n");
        #line 117 "src/analyzer/Include.pv"
        return 0;
    }

    #line 120 "src/analyzer/Include.pv"
    struct CXTranslationUnitImpl* unit = 0;

    #line 122 "src/analyzer/Include.pv"
    enum CXErrorCode result = clang_parseTranslationUnit2(index, filename, clang_args.data, clang_args.length, &unsaved, 1, CXTranslationUnit_None | CXTranslationUnit_DetailedPreprocessingRecord | CXTranslationUnit_Incomplete | CXTranslationUnit_SkipFunctionBodies, &unit);

    #line 131 "src/analyzer/Include.pv"
    if (release_clang_args) {
        #line 132 "src/analyzer/Include.pv"
        Array_ptrc_char__release(&clang_args);
    }

    #line 140 "src/analyzer/Include.pv"
    switch (result) {
        #line 141 "src/analyzer/Include.pv"
        case CXError_Failure: {
            #line 142 "src/analyzer/Include.pv"
            uintptr_t num_errors = clang_getNumDiagnostics(unit);
            #line 143 "src/analyzer/Include.pv"
            uintptr_t display_options = clang_defaultDiagnosticDisplayOptions();

            #line 145 "src/analyzer/Include.pv"
            if (num_errors == 0) {
                #line 146 "src/analyzer/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Failure no errors");
            } else {
                #line 148 "src/analyzer/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Failure has errors");
            }

            #line 151 "src/analyzer/Include.pv"
            uintptr_t i = 0;
            #line 152 "src/analyzer/Include.pv"
            while (i < num_errors) {
                #line 153 "src/analyzer/Include.pv"
                CXDiagnostic diag = clang_getDiagnostic(unit, i);
                #line 154 "src/analyzer/Include.pv"
                CXString str = clang_formatDiagnostic(diag, display_options);

                #line 156 "src/analyzer/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, clang_getCString(str));

                #line 158 "src/analyzer/Include.pv"
                clang_disposeString(str);
                #line 159 "src/analyzer/Include.pv"
                clang_disposeDiagnostic(diag);
                #line 160 "src/analyzer/Include.pv"
                i += 1;
            }
        } break;
        #line 163 "src/analyzer/Include.pv"
        case CXError_Crashed: {
            #line 163 "src/analyzer/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Crashed");
        } break;
        #line 164 "src/analyzer/Include.pv"
        case CXError_InvalidArguments: {
            #line 164 "src/analyzer/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_InvalidArguments");
        } break;
        #line 165 "src/analyzer/Include.pv"
        case CXError_ASTReadError: {
            #line 165 "src/analyzer/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_ASTReadError");
        } break;
        #line 166 "src/analyzer/Include.pv"
        case CXError_Success: {
        } break;
    }

    #line 169 "src/analyzer/Include.pv"
    CXCursor cursor = clang_getTranslationUnitCursor(unit);
    #line 170 "src/analyzer/Include.pv"
    clang_visitChildren(cursor, IncludeContext__visitor, &(struct IncludeContext) { .include = self, .parent_context = 0, .types = &self->types, .values = &self->values, .parent = (struct ParentCpp) { .type = PARENT_CPP__NONE } });

    #line 172 "src/analyzer/Include.pv"
    clang_disposeTranslationUnit(unit);
    #line 173 "src/analyzer/Include.pv"
    clang_disposeIndex(index);

    #line 175 "src/analyzer/Include.pv"
    return 1;
}

#line 178 "src/analyzer/Include.pv"
struct Type* Include__parse_type(struct Include* self, CXType type) {
    #line 179 "src/analyzer/Include.pv"
    uint32_t type_u32 = (uint32_t)(type.kind);
    #line 180 "src/analyzer/Include.pv"
    struct Type* lookup = HashMap_u32_Type__find(&self->cxtype_to_type, &type_u32);

    #line 182 "src/analyzer/Include.pv"
    if (lookup != 0) {
        #line 183 "src/analyzer/Include.pv"
        return lookup;
    }

    #line 186 "src/analyzer/Include.pv"
    if (type.kind == CXType_Pointer) {
        #line 187 "src/analyzer/Include.pv"
        CXType pointee_type = clang_getPointeeType(type);
        #line 188 "src/analyzer/Include.pv"
        bool is_pointee_const = clang_isConstQualifiedType(pointee_type) != 0;
        #line 189 "src/analyzer/Include.pv"
        struct Type* resolved_pointee_type = Include__parse_type(self, pointee_type);

        #line 191 "src/analyzer/Include.pv"
        struct Indirect* indirect;
        #line 192 "src/analyzer/Include.pv"
        if (is_pointee_const) {
            #line 193 "src/analyzer/Include.pv"
            indirect = Indirect__new_const_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator }, *resolved_pointee_type);
        } else {
            #line 195 "src/analyzer/Include.pv"
            indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator }, *resolved_pointee_type);
        }

        #line 198 "src/analyzer/Include.pv"
        return ArenaAllocator__store_Type(self->root->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
    }

    #line 201 "src/analyzer/Include.pv"
    if (type.kind == CXType_Elaborated) {
        #line 202 "src/analyzer/Include.pv"
        CXCursor decl = clang_getTypeDeclaration(type);

        #line 204 "src/analyzer/Include.pv"
        struct Array_CXCursor path = Array_CXCursor__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
        #line 205 "src/analyzer/Include.pv"
        CXCursor parent = clang_getCursorSemanticParent(decl);
        #line 206 "src/analyzer/Include.pv"
        while (clang_getCursorKind(parent) == CXCursor_Namespace || clang_getCursorKind(parent) == CXCursor_ClassDecl || clang_getCursorKind(parent) == CXCursor_StructDecl) {
            #line 207 "src/analyzer/Include.pv"
            Array_CXCursor__append(&path, parent);
            #line 208 "src/analyzer/Include.pv"
            parent = clang_getCursorSemanticParent(parent);
        }

        #line 211 "src/analyzer/Include.pv"
        if (path.length > 0) {
            #line 212 "src/analyzer/Include.pv"
            struct HashMap_str_Type* current_types = &self->types;
            #line 213 "src/analyzer/Include.pv"
            uintptr_t i = path.length;
            #line 214 "src/analyzer/Include.pv"
            while (i > 0) {
                #line 215 "src/analyzer/Include.pv"
                i -= 1;
                #line 216 "src/analyzer/Include.pv"
                CXString ns_spelling = clang_getCursorSpelling(path.data[i]);
                #line 217 "src/analyzer/Include.pv"
                char const* ns_name = clang_getCString(ns_spelling);

                #line 219 "src/analyzer/Include.pv"
                struct Type* ns_type = HashMap_str_Type__find(current_types, &(struct str){ .ptr = ns_name, .length = strlen(ns_name) });
                #line 220 "src/analyzer/Include.pv"
                clang_disposeString(ns_spelling);

                #line 222 "src/analyzer/Include.pv"
                if (ns_type == 0) {
                    #line 222 "src/analyzer/Include.pv"
                    return &self->root->type_void;
                }

                #line 224 "src/analyzer/Include.pv"
                switch (ns_type->type) {
                    #line 225 "src/analyzer/Include.pv"
                    case TYPE__NAMESPACE_CPP: {
                        #line 225 "src/analyzer/Include.pv"
                        struct NamespaceCpp* ns_info = ns_type->namespacecpp_value;
                        #line 225 "src/analyzer/Include.pv"
                        current_types = &ns_info->types;
                    } break;
                    #line 226 "src/analyzer/Include.pv"
                    case TYPE__CLASS_CPP: {
                        #line 226 "src/analyzer/Include.pv"
                        struct ClassCpp* class_info = ns_type->classcpp_value;
                        #line 226 "src/analyzer/Include.pv"
                        current_types = &class_info->types;
                    } break;
                    #line 227 "src/analyzer/Include.pv"
                    default: {
                        #line 227 "src/analyzer/Include.pv"
                        return &self->root->type_void;
                    } break;
                }
            }

            #line 231 "src/analyzer/Include.pv"
            CXString name_spelling = clang_getCursorSpelling(decl);
            #line 232 "src/analyzer/Include.pv"
            char const* name = clang_getCString(name_spelling);
            #line 233 "src/analyzer/Include.pv"
            struct Type* lookup = HashMap_str_Type__find(current_types, &(struct str){ .ptr = name, .length = strlen(name) });
            #line 234 "src/analyzer/Include.pv"
            clang_disposeString(name_spelling);

            #line 236 "src/analyzer/Include.pv"
            if (lookup != 0) {
                #line 236 "src/analyzer/Include.pv"
                return lookup;
            }
            #line 237 "src/analyzer/Include.pv"
            return &self->root->type_void;
        }

        #line 240 "src/analyzer/Include.pv"
        CXString name_spelling = clang_getCursorSpelling(decl);
        #line 241 "src/analyzer/Include.pv"
        char const* name = clang_getCString(name_spelling);

        #line 243 "src/analyzer/Include.pv"
        struct Type* resolve = HashMap_str_Type__find(&self->typedef_to_type, &(struct str){ .ptr = name, .length = strlen(name) });
        #line 244 "src/analyzer/Include.pv"
        if (resolve != 0) {
            #line 245 "src/analyzer/Include.pv"
            clang_disposeString(name_spelling);
            #line 246 "src/analyzer/Include.pv"
            return resolve;
        }

        #line 249 "src/analyzer/Include.pv"
        struct Type* lookup = HashMap_str_Type__find(&self->types, &(struct str){ .ptr = name, .length = strlen(name) });
        #line 250 "src/analyzer/Include.pv"
        clang_disposeString(name_spelling);

        #line 252 "src/analyzer/Include.pv"
        if (lookup == 0) {
            #line 252 "src/analyzer/Include.pv"
            return &self->root->type_void;
        }
        #line 253 "src/analyzer/Include.pv"
        return lookup;
    }

    #line 256 "src/analyzer/Include.pv"
    return &self->root->type_void;
}

#line 259 "src/analyzer/Include.pv"
struct EnumC* Include__find_enum(struct Include* self, char const* name) {
    #line 260 "src/analyzer/Include.pv"
    struct Type* type_info = HashMap_str_Type__find(&self->types, &(struct str){ .ptr = name, .length = strlen(name) });

    #line 262 "src/analyzer/Include.pv"
    switch (type_info->type) {
        #line 263 "src/analyzer/Include.pv"
        case TYPE__ENUM_C: {
            #line 263 "src/analyzer/Include.pv"
            struct EnumC* enum_info = type_info->enumc_value;
            #line 263 "src/analyzer/Include.pv"
            return enum_info;
        } break;
        #line 264 "src/analyzer/Include.pv"
        default: {
        } break;
    }

    #line 267 "src/analyzer/Include.pv"
    return 0;
}

#line 270 "src/analyzer/Include.pv"
char* Include__make_string(struct Include* self, CXString s) {
    #line 271 "src/analyzer/Include.pv"
    uintptr_t length = strlen(clang_getCString(s));
    #line 272 "src/analyzer/Include.pv"
    char* result = ArenaAllocator__Allocator__alloc(self->root->allocator, length + 1);
    #line 273 "src/analyzer/Include.pv"
    memcpy(result, clang_getCString(s), length + 1);
    #line 274 "src/analyzer/Include.pv"
    return result;
}

#line 277 "src/analyzer/Include.pv"
struct str Include__make_str(struct Include* self, CXString s) {
    #line 278 "src/analyzer/Include.pv"
    uintptr_t length = strlen(clang_getCString(s));
    #line 279 "src/analyzer/Include.pv"
    char* ptr = ArenaAllocator__Allocator__alloc(self->root->allocator, length + 1);
    #line 280 "src/analyzer/Include.pv"
    memcpy(ptr, clang_getCString(s), length + 1);
    #line 281 "src/analyzer/Include.pv"
    return (struct str) { .ptr = ptr, .length = length };
}

#line 284 "src/analyzer/Include.pv"
bool Include__is_function_like_macro(struct Include* self, CXCursor cursor) {
    #line 285 "src/analyzer/Include.pv"
    CXSourceRange range = clang_getCursorExtent(cursor);
    #line 286 "src/analyzer/Include.pv"
    CXTranslationUnit tu = clang_Cursor_getTranslationUnit(cursor);

    #line 288 "src/analyzer/Include.pv"
    CXToken* tokens = 0;
    #line 289 "src/analyzer/Include.pv"
    uint32_t num_tokens = 0;
    #line 290 "src/analyzer/Include.pv"
    clang_tokenize(tu, range, &tokens, &num_tokens);

    #line 292 "src/analyzer/Include.pv"
    if (num_tokens < 2) {
        #line 293 "src/analyzer/Include.pv"
        clang_disposeTokens(tu, tokens, num_tokens);
        #line 294 "src/analyzer/Include.pv"
        return 0;
    }

    #line 297 "src/analyzer/Include.pv"
    CXString spelling = clang_getTokenSpelling(tu, tokens[1]);
    #line 298 "src/analyzer/Include.pv"
    char const* txt = clang_getCString(spelling);

    #line 300 "src/analyzer/Include.pv"
    bool result = 0;

    #line 302 "src/analyzer/Include.pv"
    if (strcmp(txt, "(") == 0) {
        #line 303 "src/analyzer/Include.pv"
        CXSourceLocation loc_name_end = clang_getRangeEnd(clang_getTokenExtent(tu, tokens[0]));
        #line 304 "src/analyzer/Include.pv"
        CXSourceLocation loc_paren = clang_getTokenLocation(tu, tokens[1]);

        #line 306 "src/analyzer/Include.pv"
        uint32_t line1 = 0;
        #line 307 "src/analyzer/Include.pv"
        uint32_t col1 = 0;
        #line 308 "src/analyzer/Include.pv"
        uint32_t line2 = 0;
        #line 309 "src/analyzer/Include.pv"
        uint32_t col2 = 0;

        #line 311 "src/analyzer/Include.pv"
        clang_getSpellingLocation(loc_name_end, 0, &line1, &col1, 0);
        #line 312 "src/analyzer/Include.pv"
        clang_getSpellingLocation(loc_paren, 0, &line2, &col2, 0);

        #line 314 "src/analyzer/Include.pv"
        if (line1 == line2 && col1 == col2) {
            #line 315 "src/analyzer/Include.pv"
            result = 1;
        }
    }

    #line 319 "src/analyzer/Include.pv"
    clang_disposeString(spelling);
    #line 320 "src/analyzer/Include.pv"
    clang_disposeTokens(tu, tokens, num_tokens);

    #line 322 "src/analyzer/Include.pv"
    return result;
}
