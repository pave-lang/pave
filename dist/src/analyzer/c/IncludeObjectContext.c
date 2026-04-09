#include <clang-c/Index.h>
#include <string.h>

#include <std/HashMap_str_EnumCValue.h>
#include <analyzer/c/Include.h>
#include <analyzer/c/IncludeContext.h>
#include <analyzer/c/StructC.h>
#include <analyzer/types/Type.h>
#include <analyzer/c/StructCField.h>
#include <std/str.h>
#include <std/HashMap_str_StructCField.h>
#include <stdbool.h>
#include <analyzer/c/ClassCpp.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <stdint.h>
#include <std/Array_Type.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/types/Function.h>
#include <std/trait_Allocator.h>
#include <analyzer/Token.h>
#include <analyzer/types/FunctionType.h>
#include <analyzer/types/GenericMap.h>
#include <analyzer/c/EnumC.h>
#include <analyzer/c/ParentCpp.h>
#include <analyzer/c/IncludeObjectEnumClass.h>
#include <analyzer/c/TypedefC.h>
#include <analyzer/c/EnumCValue.h>

#include <analyzer/c/IncludeObjectContext.h>

#line 13 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_struct(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 14 "src/analyzer/c/IncludeObjectContext.pv"
    struct IncludeObjectContext* self = client_data;
    #line 15 "src/analyzer/c/IncludeObjectContext.pv"
    struct Include* include = self->context->include;
    #line 16 "src/analyzer/c/IncludeObjectContext.pv"
    struct StructC* struct_info = self->object;
    #line 17 "src/analyzer/c/IncludeObjectContext.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 19 "src/analyzer/c/IncludeObjectContext.pv"
    if (kind == CXCursor_FieldDecl) {
        #line 20 "src/analyzer/c/IncludeObjectContext.pv"
        CXString field_spelling = clang_getCursorSpelling(cursor);
        #line 21 "src/analyzer/c/IncludeObjectContext.pv"
        char const* field_name = Include__make_string(include, field_spelling);
        #line 22 "src/analyzer/c/IncludeObjectContext.pv"
        clang_disposeString(field_spelling);

        #line 24 "src/analyzer/c/IncludeObjectContext.pv"
        CXType field_cx_type = clang_getCursorType(cursor);
        #line 25 "src/analyzer/c/IncludeObjectContext.pv"
        struct Type field_type = *Include__parse_type(include, field_cx_type);

        #line 27 "src/analyzer/c/IncludeObjectContext.pv"
        HashMap_str_StructCField__insert(&struct_info->fields, (struct str){ .ptr = field_name, .length = strlen(field_name) }, (struct StructCField) { .name = (struct str){ .ptr = field_name, .length = strlen(field_name) }, .type = field_type });
    }

    #line 30 "src/analyzer/c/IncludeObjectContext.pv"
    return CXChildVisit_Continue;
}

#line 33 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_class(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 34 "src/analyzer/c/IncludeObjectContext.pv"
    struct IncludeObjectContext* self = client_data;
    #line 35 "src/analyzer/c/IncludeObjectContext.pv"
    struct Include* include = self->context->include;
    #line 36 "src/analyzer/c/IncludeObjectContext.pv"
    struct ClassCpp* class_info = self->object;
    #line 37 "src/analyzer/c/IncludeObjectContext.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 38 "src/analyzer/c/IncludeObjectContext.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 40 "src/analyzer/c/IncludeObjectContext.pv"
    switch (kind) {
        #line 41 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_CXXBaseSpecifier: {
            #line 42 "src/analyzer/c/IncludeObjectContext.pv"
            CXType base_cx_type = clang_getCursorType(cursor);
            #line 43 "src/analyzer/c/IncludeObjectContext.pv"
            struct Type* base_type = Include__parse_type(include, base_cx_type);
            #line 44 "src/analyzer/c/IncludeObjectContext.pv"
            if (base_type != 0) {
                #line 44 "src/analyzer/c/IncludeObjectContext.pv"
                Array_Type__append(&class_info->bases, *base_type);
            }
        } break;
        #line 46 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_FieldDecl: {
            #line 47 "src/analyzer/c/IncludeObjectContext.pv"
            CXString field_spelling = clang_getCursorSpelling(cursor);
            #line 48 "src/analyzer/c/IncludeObjectContext.pv"
            char const* field_name = Include__make_string(include, field_spelling);
            #line 49 "src/analyzer/c/IncludeObjectContext.pv"
            clang_disposeString(field_spelling);

            #line 51 "src/analyzer/c/IncludeObjectContext.pv"
            CXType field_cx_type = clang_getCursorType(cursor);
            #line 52 "src/analyzer/c/IncludeObjectContext.pv"
            struct Type field_type = *Include__parse_type(include, field_cx_type);

            #line 54 "src/analyzer/c/IncludeObjectContext.pv"
            HashMap_str_Type__insert(&class_info->fields, (struct str){ .ptr = field_name, .length = strlen(field_name) }, field_type);
        } break;
        #line 56 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_VarDecl: {
            #line 57 "src/analyzer/c/IncludeObjectContext.pv"
            enum CX_StorageClass storage = clang_Cursor_getStorageClass(cursor);
            #line 58 "src/analyzer/c/IncludeObjectContext.pv"
            if (storage == CX_SC_Static) {
                #line 59 "src/analyzer/c/IncludeObjectContext.pv"
                CXString spelling = clang_getCursorSpelling(cursor);
                #line 60 "src/analyzer/c/IncludeObjectContext.pv"
                char* name = Include__make_string(include, spelling);
                #line 61 "src/analyzer/c/IncludeObjectContext.pv"
                clang_disposeString(spelling);

                #line 63 "src/analyzer/c/IncludeObjectContext.pv"
                CXType cx_type = clang_getCursorType(cursor);
                #line 64 "src/analyzer/c/IncludeObjectContext.pv"
                struct Type ty = *Include__parse_type(include, cx_type);

                #line 66 "src/analyzer/c/IncludeObjectContext.pv"
                HashMap_str_Type__insert(&class_info->values, (struct str){ .ptr = name, .length = strlen(name) }, ty);
            }
        } break;
        #line 69 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_CXXMethod: {
            #line 70 "src/analyzer/c/IncludeObjectContext.pv"
            CXString method_spelling = clang_getCursorSpelling(cursor);
            #line 71 "src/analyzer/c/IncludeObjectContext.pv"
            char const* method_name = Include__make_string(include, method_spelling);
            #line 72 "src/analyzer/c/IncludeObjectContext.pv"
            clang_disposeString(method_spelling);

            #line 74 "src/analyzer/c/IncludeObjectContext.pv"
            CXType return_type = clang_getCursorResultType(cursor);
            #line 75 "src/analyzer/c/IncludeObjectContext.pv"
            struct Type* return_type_resolved = Include__parse_type(include, return_type);

            #line 77 "src/analyzer/c/IncludeObjectContext.pv"
            struct Function func_info = Function__new_allocator((struct trait_Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator });
            #line 78 "src/analyzer/c/IncludeObjectContext.pv"
            func_info.name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = method_name, .length = strlen(method_name) } });
            #line 79 "src/analyzer/c/IncludeObjectContext.pv"
            func_info.return_type = *return_type_resolved;
            #line 80 "src/analyzer/c/IncludeObjectContext.pv"
            func_info.type = FUNCTION_TYPE__METHOD_CPP;

            #line 82 "src/analyzer/c/IncludeObjectContext.pv"
            struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(allocator, func_info), ._1 = 0} };
            #line 83 "src/analyzer/c/IncludeObjectContext.pv"
            HashMap_str_Type__insert(&class_info->fields, (struct str){ .ptr = method_name, .length = strlen(method_name) }, func_type);
        } break;
        #line 85 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_EnumDecl: {
            #line 86 "src/analyzer/c/IncludeObjectContext.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 87 "src/analyzer/c/IncludeObjectContext.pv"
            char* name = Include__make_string(include, spelling);
            #line 88 "src/analyzer/c/IncludeObjectContext.pv"
            clang_disposeString(spelling);

            #line 90 "src/analyzer/c/IncludeObjectContext.pv"
            struct EnumC* enum_info = EnumC__new(include, name, (struct ParentCpp) { .type = PARENT_CPP__CLASS, .class_value = class_info });
            #line 91 "src/analyzer/c/IncludeObjectContext.pv"
            HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });

            #line 93 "src/analyzer/c/IncludeObjectContext.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_enum_into_class, &(struct IncludeObjectContext) {
                .context = self->context,
                .object = &(struct IncludeObjectEnumClass) { .enum_info = enum_info, .class_info = class_info },
            });
        } break;
        #line 98 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_StructDecl: {
            #line 99 "src/analyzer/c/IncludeObjectContext.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 100 "src/analyzer/c/IncludeObjectContext.pv"
            char* name = Include__make_string(include, spelling);
            #line 101 "src/analyzer/c/IncludeObjectContext.pv"
            clang_disposeString(spelling);

            #line 103 "src/analyzer/c/IncludeObjectContext.pv"
            if (strlen(name) == 0) {
                #line 104 "src/analyzer/c/IncludeObjectContext.pv"
                ArenaAllocator__Allocator__free(include->root->allocator, name);
                #line 105 "src/analyzer/c/IncludeObjectContext.pv"
                return CXChildVisit_Continue;
            }

            #line 108 "src/analyzer/c/IncludeObjectContext.pv"
            struct Type* existing = HashMap_str_Type__find(&class_info->types, &(struct str){ .ptr = name, .length = strlen(name) });
            #line 109 "src/analyzer/c/IncludeObjectContext.pv"
            if (existing == 0) {
                #line 110 "src/analyzer/c/IncludeObjectContext.pv"
                struct ClassCpp* nested_class = ClassCpp__new(include, name, (struct ParentCpp) { .type = PARENT_CPP__CLASS, .class_value = class_info }, kind == CXCursor_StructDecl);
                #line 111 "src/analyzer/c/IncludeObjectContext.pv"
                HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = nested_class });

                #line 113 "src/analyzer/c/IncludeObjectContext.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                    .context = self->context,
                    .object = nested_class,
                });
            }
        } break;
        #line 119 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_ClassDecl: {
            #line 120 "src/analyzer/c/IncludeObjectContext.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 121 "src/analyzer/c/IncludeObjectContext.pv"
            char* name = Include__make_string(include, spelling);
            #line 122 "src/analyzer/c/IncludeObjectContext.pv"
            clang_disposeString(spelling);

            #line 124 "src/analyzer/c/IncludeObjectContext.pv"
            if (strlen(name) == 0) {
                #line 125 "src/analyzer/c/IncludeObjectContext.pv"
                ArenaAllocator__Allocator__free(include->root->allocator, name);
                #line 126 "src/analyzer/c/IncludeObjectContext.pv"
                return CXChildVisit_Continue;
            }

            #line 129 "src/analyzer/c/IncludeObjectContext.pv"
            struct Type* existing = HashMap_str_Type__find(&class_info->types, &(struct str){ .ptr = name, .length = strlen(name) });
            #line 130 "src/analyzer/c/IncludeObjectContext.pv"
            if (existing == 0) {
                #line 131 "src/analyzer/c/IncludeObjectContext.pv"
                struct ClassCpp* nested_class = ClassCpp__new(include, name, (struct ParentCpp) { .type = PARENT_CPP__CLASS, .class_value = class_info }, kind == CXCursor_StructDecl);
                #line 132 "src/analyzer/c/IncludeObjectContext.pv"
                HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = nested_class });

                #line 134 "src/analyzer/c/IncludeObjectContext.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                    .context = self->context,
                    .object = nested_class,
                });
            }
        } break;
        #line 140 "src/analyzer/c/IncludeObjectContext.pv"
        case CXCursor_TypedefDecl: {
            #line 141 "src/analyzer/c/IncludeObjectContext.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 142 "src/analyzer/c/IncludeObjectContext.pv"
            char* name = Include__make_string(include, spelling);
            #line 143 "src/analyzer/c/IncludeObjectContext.pv"
            clang_disposeString(spelling);

            #line 145 "src/analyzer/c/IncludeObjectContext.pv"
            if (HashMap_str_Type__find(&class_info->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
                #line 146 "src/analyzer/c/IncludeObjectContext.pv"
                CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
                #line 147 "src/analyzer/c/IncludeObjectContext.pv"
                struct Type* resolved = Include__parse_type(include, underlying_type);

                #line 149 "src/analyzer/c/IncludeObjectContext.pv"
                if (resolved != 0) {
                    #line 150 "src/analyzer/c/IncludeObjectContext.pv"
                    struct TypedefC* typedef_ = TypedefC__new(include, name, resolved);
                    #line 151 "src/analyzer/c/IncludeObjectContext.pv"
                    HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
                } else {
                    #line 153 "src/analyzer/c/IncludeObjectContext.pv"
                    ArenaAllocator__Allocator__free(include->root->allocator, name);
                }
            } else {
                #line 156 "src/analyzer/c/IncludeObjectContext.pv"
                ArenaAllocator__Allocator__free(include->root->allocator, name);
            }
        } break;
        #line 159 "src/analyzer/c/IncludeObjectContext.pv"
        default: {
        } break;
    }

    #line 162 "src/analyzer/c/IncludeObjectContext.pv"
    return CXChildVisit_Continue;
}

#line 165 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 166 "src/analyzer/c/IncludeObjectContext.pv"
    struct IncludeObjectContext* self = client_data;
    #line 167 "src/analyzer/c/IncludeObjectContext.pv"
    struct EnumC* enum_info = self->object;
    #line 168 "src/analyzer/c/IncludeObjectContext.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 170 "src/analyzer/c/IncludeObjectContext.pv"
    if (kind == CXCursor_EnumConstantDecl) {
        #line 171 "src/analyzer/c/IncludeObjectContext.pv"
        CXString value_spelling = clang_getCursorSpelling(cursor);
        #line 172 "src/analyzer/c/IncludeObjectContext.pv"
        char* value_name = Include__make_string(self->context->include, value_spelling);
        #line 173 "src/analyzer/c/IncludeObjectContext.pv"
        clang_disposeString(value_spelling);

        #line 175 "src/analyzer/c/IncludeObjectContext.pv"
        IncludeContext__add_enum_value(self->context, enum_info, value_name);
    }

    #line 178 "src/analyzer/c/IncludeObjectContext.pv"
    return CXChildVisit_Continue;
}

#line 181 "src/analyzer/c/IncludeObjectContext.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum_into_class(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 182 "src/analyzer/c/IncludeObjectContext.pv"
    struct IncludeObjectContext* self = client_data;
    #line 183 "src/analyzer/c/IncludeObjectContext.pv"
    struct IncludeObjectEnumClass* payload = self->object;
    #line 184 "src/analyzer/c/IncludeObjectContext.pv"
    struct Include* include = self->context->include;
    #line 185 "src/analyzer/c/IncludeObjectContext.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 187 "src/analyzer/c/IncludeObjectContext.pv"
    if (kind == CXCursor_EnumConstantDecl) {
        #line 188 "src/analyzer/c/IncludeObjectContext.pv"
        CXString value_spelling = clang_getCursorSpelling(cursor);
        #line 189 "src/analyzer/c/IncludeObjectContext.pv"
        struct str value_name = Include__make_str(include, value_spelling);
        #line 190 "src/analyzer/c/IncludeObjectContext.pv"
        clang_disposeString(value_spelling);

        #line 192 "src/analyzer/c/IncludeObjectContext.pv"
        HashMap_str_EnumCValue__insert(&payload->enum_info->values, value_name, (struct EnumCValue) { .parent = payload->enum_info, .name = value_name });
        #line 193 "src/analyzer/c/IncludeObjectContext.pv"
        HashMap_str_Type__insert(&payload->class_info->values, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = payload->enum_info });
    }

    #line 196 "src/analyzer/c/IncludeObjectContext.pv"
    return CXChildVisit_Continue;
}
