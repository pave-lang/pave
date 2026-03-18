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
#include <analyzer/types/Type.h>
#include <std/Allocator.h>
#include <std/HashMap_str_Type.h>
#include <std/HashMap_str_Primitive.h>
#include <analyzer/types/Primitive.h>
#include <std/Array_ptrc_char.h>
#include <std/String.h>
#include <analyzer/IncludeContext.h>
#include <analyzer/ParentCpp.h>
#include <analyzer/types/Indirect.h>
#include <std/Array_CXCursor.h>
#include <analyzer/NamespaceCpp.h>
#include <analyzer/ClassCpp.h>

#include <analyzer/Include.h>

#line 20 "src/analyzer/Include.pv"
struct Include* Include__new(struct Root* root, struct str path, bool mode_cpp) {
    #line 21 "src/analyzer/Include.pv"
    struct Include* self = ArenaAllocator__store_Include(root->allocator, (struct Include) {
        .root = root,
        .mode_cpp = mode_cpp,
        .path = path,
        .cxtype_to_type = HashMap_u32_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .typedef_to_type = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .types = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
        .values = HashMap_str_Type__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator }),
    });

    #line 31 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Bool, "bool");

    #line 33 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Char_S, "char");
    #line 34 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Char_U, "char");

    #line 36 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_SChar, "i8");
    #line 37 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Short, "i16");
    #line 38 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Int, "i32");
    #line 39 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Long, "i32");
    #line 40 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_LongLong, "i64");

    #line 42 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UChar, "u8");
    #line 43 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UShort, "u16");
    #line 44 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_UInt, "u32");
    #line 45 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_ULong, "u32");
    #line 46 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_ULongLong, "u64");

    #line 48 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Float, "f32");
    #line 49 "src/analyzer/Include.pv"
    Include__add_cxtype_primitive(self, CXType_Double, "f64");

    #line 51 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "bool", "bool");

    #line 53 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int8_t", "i8");
    #line 54 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int16_t", "i16");
    #line 55 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int32_t", "i32");
    #line 56 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "int64_t", "i64");

    #line 58 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint8_t", "u8");
    #line 59 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint16_t", "u16");
    #line 60 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint32_t", "u32");
    #line 61 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "uint64_t", "u64");

    #line 63 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "size_t", "usize");

    #line 65 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint8", "i8");
    #line 66 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint16", "i16");
    #line 67 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint32", "i32");
    #line 68 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Sint64", "i64");

    #line 70 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint8", "u8");
    #line 71 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint16", "u16");
    #line 72 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint32", "u32");
    #line 73 "src/analyzer/Include.pv"
    Include__add_typedef_primitive(self, "Uint64", "u64");

    #line 75 "src/analyzer/Include.pv"
    return self;
}

#line 78 "src/analyzer/Include.pv"
void Include__add_cxtype_primitive(struct Include* self, enum CXTypeKind kind, char const* name) {
    #line 79 "src/analyzer/Include.pv"
    struct HashMap_str_Primitive primitives = self->root->primitives;

    #line 81 "src/analyzer/Include.pv"
    HashMap_u32_Type__insert(&self->cxtype_to_type, (uint32_t)(kind), (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = HashMap_str_Primitive__find(&primitives, &(struct str){ .ptr = name, .length = strlen(name) }) });
}

#line 84 "src/analyzer/Include.pv"
void Include__add_typedef_primitive(struct Include* self, char const* type, char const* name) {
    #line 85 "src/analyzer/Include.pv"
    struct HashMap_str_Primitive* primitives = &self->root->primitives;
    #line 86 "src/analyzer/Include.pv"
    HashMap_str_Type__insert(&self->typedef_to_type, (struct str){ .ptr = type, .length = strlen(type) }, (struct Type) { .type = TYPE__PRIMITIVE, .primitive_value = HashMap_str_Primitive__find(primitives, &(struct str){ .ptr = name, .length = strlen(name) }) });
}

#line 89 "src/analyzer/Include.pv"
bool Include__process(struct Include* self) {
    #line 90 "src/analyzer/Include.pv"
    struct Root* root = self->root;
    #line 91 "src/analyzer/Include.pv"
    struct Array_ptrc_char clang_args = root->clang_args;
    #line 92 "src/analyzer/Include.pv"
    bool release_clang_args = false;

    #line 94 "src/analyzer/Include.pv"
    struct String path = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
    #line 95 "src/analyzer/Include.pv"
    String__append(&path, str__slice(self->path, 1, self->path.length - 1));

    #line 97 "src/analyzer/Include.pv"
    struct String file_content = String__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
    #line 98 "src/analyzer/Include.pv"
    String__append(&file_content, (struct str){ .ptr = "#include <", .length = strlen("#include <") });
    #line 99 "src/analyzer/Include.pv"
    String__append(&file_content, String__as_str(&path));
    #line 100 "src/analyzer/Include.pv"
    String__append(&file_content, (struct str){ .ptr = ">", .length = strlen(">") });

    #line 102 "src/analyzer/Include.pv"
    char const* filename = "__temp.c";
    #line 103 "src/analyzer/Include.pv"
    if (self->mode_cpp) {
        #line 104 "src/analyzer/Include.pv"
        filename = "__temp.cpp";
        #line 105 "src/analyzer/Include.pv"
        clang_args = Array_ptrc_char__clone(&clang_args, (struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = root->allocator });
        #line 106 "src/analyzer/Include.pv"
        Array_ptrc_char__append(&clang_args, "-std=c++17");
        #line 107 "src/analyzer/Include.pv"
        release_clang_args = true;
    }

    #line 110 "src/analyzer/Include.pv"
    struct CXUnsavedFile unsaved = (struct CXUnsavedFile) {
        .Filename = filename,
        .Contents = String__c_str(&file_content),
        .Length = String__length(&file_content),
    };

    #line 116 "src/analyzer/Include.pv"
    CXIndex index = clang_createIndex(0, 1);
    #line 117 "src/analyzer/Include.pv"
    if (index == (CXIndex)(0)) {
        #line 118 "src/analyzer/Include.pv"
        Root__error(self->root, self->path, 0, 0, 0, 0, "clang_createIndex failed\n");
        #line 119 "src/analyzer/Include.pv"
        return false;
    }

    #line 122 "src/analyzer/Include.pv"
    struct CXTranslationUnitImpl* unit = 0;

    #line 124 "src/analyzer/Include.pv"
    enum CXErrorCode result = clang_parseTranslationUnit2(index, filename, clang_args.data, clang_args.length, &unsaved, 1, CXTranslationUnit_None | CXTranslationUnit_DetailedPreprocessingRecord | CXTranslationUnit_Incomplete | CXTranslationUnit_SkipFunctionBodies, &unit);

    #line 133 "src/analyzer/Include.pv"
    if (release_clang_args) {
        #line 134 "src/analyzer/Include.pv"
        Array_ptrc_char__release(&clang_args);
    }

    #line 142 "src/analyzer/Include.pv"
    switch (result) {
        #line 143 "src/analyzer/Include.pv"
        case CXError_Failure: {
            #line 144 "src/analyzer/Include.pv"
            uintptr_t num_errors = clang_getNumDiagnostics(unit);
            #line 145 "src/analyzer/Include.pv"
            uintptr_t display_options = clang_defaultDiagnosticDisplayOptions();

            #line 147 "src/analyzer/Include.pv"
            if (num_errors == 0) {
                #line 148 "src/analyzer/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Failure no errors");
            } else {
                #line 150 "src/analyzer/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Failure has errors");
            }

            #line 153 "src/analyzer/Include.pv"
            uintptr_t i = 0;
            #line 154 "src/analyzer/Include.pv"
            while (i < num_errors) {
                #line 155 "src/analyzer/Include.pv"
                CXDiagnostic diag = clang_getDiagnostic(unit, i);
                #line 156 "src/analyzer/Include.pv"
                CXString str = clang_formatDiagnostic(diag, display_options);

                #line 158 "src/analyzer/Include.pv"
                Root__error(self->root, self->path, 0, 0, 0, 0, clang_getCString(str));

                #line 160 "src/analyzer/Include.pv"
                clang_disposeString(str);
                #line 161 "src/analyzer/Include.pv"
                clang_disposeDiagnostic(diag);
                #line 162 "src/analyzer/Include.pv"
                i += 1;
            }
        } break;
        #line 165 "src/analyzer/Include.pv"
        case CXError_Crashed: {
            #line 165 "src/analyzer/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_Crashed");
        } break;
        #line 166 "src/analyzer/Include.pv"
        case CXError_InvalidArguments: {
            #line 166 "src/analyzer/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_InvalidArguments");
        } break;
        #line 167 "src/analyzer/Include.pv"
        case CXError_ASTReadError: {
            #line 167 "src/analyzer/Include.pv"
            Root__error(self->root, self->path, 0, 0, 0, 0, "clang_parseTranslationUnit failed CXError_ASTReadError");
        } break;
        #line 168 "src/analyzer/Include.pv"
        case CXError_Success: {
        } break;
    }

    #line 171 "src/analyzer/Include.pv"
    CXCursor cursor = clang_getTranslationUnitCursor(unit);
    #line 172 "src/analyzer/Include.pv"
    clang_visitChildren(cursor, IncludeContext__visitor, &(struct IncludeContext) { .include = self, .parent_context = 0, .types = &self->types, .values = &self->values, .parent = (struct ParentCpp) { .type = PARENT_CPP__NONE } });

    #line 174 "src/analyzer/Include.pv"
    clang_disposeTranslationUnit(unit);
    #line 175 "src/analyzer/Include.pv"
    clang_disposeIndex(index);

    #line 177 "src/analyzer/Include.pv"
    return true;
}

#line 180 "src/analyzer/Include.pv"
struct Type* Include__parse_type(struct Include* self, CXType type) {
    #line 181 "src/analyzer/Include.pv"
    uint32_t type_u32 = (uint32_t)(type.kind);
    #line 182 "src/analyzer/Include.pv"
    struct Type* lookup = HashMap_u32_Type__find(&self->cxtype_to_type, &type_u32);

    #line 184 "src/analyzer/Include.pv"
    if (lookup != 0) {
        #line 185 "src/analyzer/Include.pv"
        return lookup;
    }

    #line 188 "src/analyzer/Include.pv"
    if (type.kind == CXType_Pointer) {
        #line 189 "src/analyzer/Include.pv"
        CXType pointee_type = clang_getPointeeType(type);
        #line 190 "src/analyzer/Include.pv"
        bool is_pointee_const = clang_isConstQualifiedType(pointee_type) != 0;
        #line 191 "src/analyzer/Include.pv"
        struct Type* resolved_pointee_type = Include__parse_type(self, pointee_type);

        #line 193 "src/analyzer/Include.pv"
        struct Indirect* indirect;
        #line 194 "src/analyzer/Include.pv"
        if (is_pointee_const) {
            #line 195 "src/analyzer/Include.pv"
            indirect = Indirect__new_const_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator }, *resolved_pointee_type);
        } else {
            #line 197 "src/analyzer/Include.pv"
            indirect = Indirect__new_pointer((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator }, *resolved_pointee_type);
        }

        #line 200 "src/analyzer/Include.pv"
        return ArenaAllocator__store_Type(self->root->allocator, (struct Type) { .type = TYPE__INDIRECT, .indirect_value = indirect });
    }

    #line 203 "src/analyzer/Include.pv"
    if (type.kind == CXType_Elaborated) {
        #line 204 "src/analyzer/Include.pv"
        CXCursor decl = clang_getTypeDeclaration(type);

        #line 206 "src/analyzer/Include.pv"
        struct Array_CXCursor path = Array_CXCursor__new((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = self->root->allocator });
        #line 207 "src/analyzer/Include.pv"
        CXCursor parent = clang_getCursorSemanticParent(decl);
        #line 208 "src/analyzer/Include.pv"
        while ((clang_getCursorKind(parent) == CXCursor_Namespace) || (clang_getCursorKind(parent) == CXCursor_ClassDecl) || (clang_getCursorKind(parent) == CXCursor_StructDecl)) {
            #line 209 "src/analyzer/Include.pv"
            Array_CXCursor__append(&path, parent);
            #line 210 "src/analyzer/Include.pv"
            parent = clang_getCursorSemanticParent(parent);
        }

        #line 213 "src/analyzer/Include.pv"
        if (path.length > 0) {
            #line 214 "src/analyzer/Include.pv"
            struct HashMap_str_Type* current_types = &self->types;
            #line 215 "src/analyzer/Include.pv"
            uintptr_t i = path.length;
            #line 216 "src/analyzer/Include.pv"
            while (i > 0) {
                #line 217 "src/analyzer/Include.pv"
                i -= 1;
                #line 218 "src/analyzer/Include.pv"
                CXString ns_spelling = clang_getCursorSpelling(path.data[i]);
                #line 219 "src/analyzer/Include.pv"
                char const* ns_name = clang_getCString(ns_spelling);

                #line 221 "src/analyzer/Include.pv"
                struct Type* ns_type = HashMap_str_Type__find(current_types, &(struct str){ .ptr = ns_name, .length = strlen(ns_name) });
                #line 222 "src/analyzer/Include.pv"
                clang_disposeString(ns_spelling);

                #line 224 "src/analyzer/Include.pv"
                if (ns_type == 0) {
                    #line 224 "src/analyzer/Include.pv"
                    return &self->root->type_void;
                }

                #line 226 "src/analyzer/Include.pv"
                switch (ns_type->type) {
                    #line 227 "src/analyzer/Include.pv"
                    case TYPE__NAMESPACE_CPP: {
                        #line 227 "src/analyzer/Include.pv"
                        struct NamespaceCpp* ns_info = ns_type->namespacecpp_value;
                        #line 227 "src/analyzer/Include.pv"
                        current_types = &ns_info->types;
                    } break;
                    #line 228 "src/analyzer/Include.pv"
                    case TYPE__CLASS_CPP: {
                        #line 228 "src/analyzer/Include.pv"
                        struct ClassCpp* class_info = ns_type->classcpp_value;
                        #line 228 "src/analyzer/Include.pv"
                        current_types = &class_info->types;
                    } break;
                    #line 229 "src/analyzer/Include.pv"
                    default: {
                        #line 229 "src/analyzer/Include.pv"
                        return &self->root->type_void;
                    } break;
                }
            }

            #line 233 "src/analyzer/Include.pv"
            CXString name_spelling = clang_getCursorSpelling(decl);
            #line 234 "src/analyzer/Include.pv"
            char const* name = clang_getCString(name_spelling);
            #line 235 "src/analyzer/Include.pv"
            struct Type* lookup = HashMap_str_Type__find(current_types, &(struct str){ .ptr = name, .length = strlen(name) });
            #line 236 "src/analyzer/Include.pv"
            clang_disposeString(name_spelling);

            #line 238 "src/analyzer/Include.pv"
            if (lookup != 0) {
                #line 238 "src/analyzer/Include.pv"
                return lookup;
            }
            #line 239 "src/analyzer/Include.pv"
            return &self->root->type_void;
        }

        #line 242 "src/analyzer/Include.pv"
        CXString name_spelling = clang_getCursorSpelling(decl);
        #line 243 "src/analyzer/Include.pv"
        char const* name = clang_getCString(name_spelling);

        #line 245 "src/analyzer/Include.pv"
        struct Type* resolve = HashMap_str_Type__find(&self->typedef_to_type, &(struct str){ .ptr = name, .length = strlen(name) });
        #line 246 "src/analyzer/Include.pv"
        if (resolve != 0) {
            #line 247 "src/analyzer/Include.pv"
            clang_disposeString(name_spelling);
            #line 248 "src/analyzer/Include.pv"
            return resolve;
        }

        #line 251 "src/analyzer/Include.pv"
        struct Type* lookup = HashMap_str_Type__find(&self->types, &(struct str){ .ptr = name, .length = strlen(name) });
        #line 252 "src/analyzer/Include.pv"
        clang_disposeString(name_spelling);

        #line 254 "src/analyzer/Include.pv"
        if (lookup == 0) {
            #line 254 "src/analyzer/Include.pv"
            return &self->root->type_void;
        }
        #line 255 "src/analyzer/Include.pv"
        return lookup;
    }

    #line 258 "src/analyzer/Include.pv"
    return &self->root->type_void;
}

#line 261 "src/analyzer/Include.pv"
struct EnumC* Include__find_enum(struct Include* self, char const* name) {
    #line 262 "src/analyzer/Include.pv"
    struct Type* type_info = HashMap_str_Type__find(&self->types, &(struct str){ .ptr = name, .length = strlen(name) });

    #line 264 "src/analyzer/Include.pv"
    switch (type_info->type) {
        #line 265 "src/analyzer/Include.pv"
        case TYPE__ENUM_C: {
            #line 265 "src/analyzer/Include.pv"
            struct EnumC* enum_info = type_info->enumc_value;
            #line 265 "src/analyzer/Include.pv"
            return enum_info;
        } break;
        #line 266 "src/analyzer/Include.pv"
        default: {
        } break;
    }

    #line 269 "src/analyzer/Include.pv"
    return 0;
}

#line 272 "src/analyzer/Include.pv"
char* Include__make_string(struct Include* self, CXString s) {
    #line 273 "src/analyzer/Include.pv"
    uintptr_t length = strlen(clang_getCString(s));
    #line 274 "src/analyzer/Include.pv"
    char* result = ArenaAllocator__Allocator__alloc(self->root->allocator, length + 1);
    #line 275 "src/analyzer/Include.pv"
    memcpy(result, clang_getCString(s), length + 1);
    #line 276 "src/analyzer/Include.pv"
    return result;
}

#line 279 "src/analyzer/Include.pv"
struct str Include__make_str(struct Include* self, CXString s) {
    #line 280 "src/analyzer/Include.pv"
    uintptr_t length = strlen(clang_getCString(s));
    #line 281 "src/analyzer/Include.pv"
    char* ptr = ArenaAllocator__Allocator__alloc(self->root->allocator, length + 1);
    #line 282 "src/analyzer/Include.pv"
    memcpy(ptr, clang_getCString(s), length + 1);
    #line 283 "src/analyzer/Include.pv"
    return (struct str) { .ptr = ptr, .length = length };
}

#line 286 "src/analyzer/Include.pv"
bool Include__is_function_like_macro(struct Include* self, CXCursor cursor) {
    #line 287 "src/analyzer/Include.pv"
    CXSourceRange range = clang_getCursorExtent(cursor);
    #line 288 "src/analyzer/Include.pv"
    CXTranslationUnit tu = clang_Cursor_getTranslationUnit(cursor);

    #line 290 "src/analyzer/Include.pv"
    CXToken* tokens = 0;
    #line 291 "src/analyzer/Include.pv"
    uint32_t num_tokens = 0;
    #line 292 "src/analyzer/Include.pv"
    clang_tokenize(tu, range, &tokens, &num_tokens);

    #line 294 "src/analyzer/Include.pv"
    if (num_tokens < 2) {
        #line 295 "src/analyzer/Include.pv"
        clang_disposeTokens(tu, tokens, num_tokens);
        #line 296 "src/analyzer/Include.pv"
        return false;
    }

    #line 299 "src/analyzer/Include.pv"
    CXString spelling = clang_getTokenSpelling(tu, tokens[1]);
    #line 300 "src/analyzer/Include.pv"
    char const* txt = clang_getCString(spelling);

    #line 302 "src/analyzer/Include.pv"
    bool result = false;

    #line 304 "src/analyzer/Include.pv"
    if (strcmp(txt, "(") == 0) {
        #line 305 "src/analyzer/Include.pv"
        CXSourceLocation loc_name_end = clang_getRangeEnd(clang_getTokenExtent(tu, tokens[0]));
        #line 306 "src/analyzer/Include.pv"
        CXSourceLocation loc_paren = clang_getTokenLocation(tu, tokens[1]);

        #line 308 "src/analyzer/Include.pv"
        uint32_t line1 = 0;
        #line 309 "src/analyzer/Include.pv"
        uint32_t col1 = 0;
        #line 310 "src/analyzer/Include.pv"
        uint32_t line2 = 0;
        #line 311 "src/analyzer/Include.pv"
        uint32_t col2 = 0;

        #line 313 "src/analyzer/Include.pv"
        clang_getSpellingLocation(loc_name_end, 0, &line1, &col1, 0);
        #line 314 "src/analyzer/Include.pv"
        clang_getSpellingLocation(loc_paren, 0, &line2, &col2, 0);

        #line 316 "src/analyzer/Include.pv"
        if ((line1 == line2) && (col1 == col2)) {
            #line 317 "src/analyzer/Include.pv"
            result = true;
        }
    }

    #line 321 "src/analyzer/Include.pv"
    clang_disposeString(spelling);
    #line 322 "src/analyzer/Include.pv"
    clang_disposeTokens(tu, tokens, num_tokens);

    #line 324 "src/analyzer/Include.pv"
    return result;
}
