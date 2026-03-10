#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <analyzer/EnumC.h>
#include <analyzer/Include.h>
#include <analyzer/IncludeContext.h>
#include <analyzer/StructC.h>
#include <analyzer/Type.h>
#include <analyzer/StructCField.h>
#include <std/str.h>
#include <std/HashMap_str_StructCField.h>
#include <stdbool.h>
#include <analyzer/ClassCpp.h>
#include <std/ArenaAllocator.h>
#include <analyzer/Root.h>
#include <stdint.h>
#include <std/Array_Type.h>
#include <std/HashMap_str_Type.h>
#include <analyzer/Function.h>
#include <std/Allocator.h>
#include <analyzer/Token.h>
#include <analyzer/FunctionType.h>
#include <analyzer/GenericMap.h>

#include <analyzer/IncludeObjectContext.h>

#line 649 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_struct(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 650 "src/analyzer/Include.pv"
    struct IncludeObjectContext* self = client_data;
    #line 651 "src/analyzer/Include.pv"
    struct Include* include = self->context->include;
    #line 652 "src/analyzer/Include.pv"
    struct StructC* struct_info = self->object;
    #line 653 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 655 "src/analyzer/Include.pv"
    if (kind == CXCursor_FieldDecl) {
        #line 656 "src/analyzer/Include.pv"
        CXString field_spelling = clang_getCursorSpelling(cursor);
        #line 657 "src/analyzer/Include.pv"
        char const* field_name = Include__make_string(include, field_spelling);
        #line 658 "src/analyzer/Include.pv"
        clang_disposeString(field_spelling);

        #line 660 "src/analyzer/Include.pv"
        CXType field_cx_type = clang_getCursorType(cursor);
        #line 661 "src/analyzer/Include.pv"
        struct Type field_type = *Include__parse_type(include, field_cx_type);

        #line 663 "src/analyzer/Include.pv"
        HashMap_str_StructCField__insert(&struct_info->fields, (struct str){ .ptr = field_name, .length = strlen(field_name) }, (struct StructCField) { .name = (struct str){ .ptr = field_name, .length = strlen(field_name) }, .type = field_type });
    }

    #line 666 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}

#line 669 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_class(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 670 "src/analyzer/Include.pv"
    struct IncludeObjectContext* self = client_data;
    #line 671 "src/analyzer/Include.pv"
    struct Include* include = self->context->include;
    #line 672 "src/analyzer/Include.pv"
    struct ClassCpp* class_info = self->object;
    #line 673 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 674 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 676 "src/analyzer/Include.pv"
    switch (kind) {
        #line 677 "src/analyzer/Include.pv"
        case CXCursor_CXXBaseSpecifier: {
            #line 678 "src/analyzer/Include.pv"
            CXType base_cx_type = clang_getCursorType(cursor);
            #line 679 "src/analyzer/Include.pv"
            struct Type* base_type = Include__parse_type(include, base_cx_type);
            #line 680 "src/analyzer/Include.pv"
            if (base_type != 0) {
                #line 680 "src/analyzer/Include.pv"
                Array_Type__append(&class_info->bases, *base_type);
            }
        } break;
        #line 682 "src/analyzer/Include.pv"
        case CXCursor_FieldDecl: {
            #line 683 "src/analyzer/Include.pv"
            CXString field_spelling = clang_getCursorSpelling(cursor);
            #line 684 "src/analyzer/Include.pv"
            char const* field_name = Include__make_string(include, field_spelling);
            #line 685 "src/analyzer/Include.pv"
            clang_disposeString(field_spelling);

            #line 687 "src/analyzer/Include.pv"
            CXType field_cx_type = clang_getCursorType(cursor);
            #line 688 "src/analyzer/Include.pv"
            struct Type field_type = *Include__parse_type(include, field_cx_type);

            #line 690 "src/analyzer/Include.pv"
            HashMap_str_Type__insert(&class_info->fields, (struct str){ .ptr = field_name, .length = strlen(field_name) }, field_type);
        } break;
        #line 692 "src/analyzer/Include.pv"
        case CXCursor_VarDecl: {
            #line 693 "src/analyzer/Include.pv"
            enum CX_StorageClass storage = clang_Cursor_getStorageClass(cursor);
            #line 694 "src/analyzer/Include.pv"
            if (storage == CX_SC_Static) {
                #line 695 "src/analyzer/Include.pv"
                CXString spelling = clang_getCursorSpelling(cursor);
                #line 696 "src/analyzer/Include.pv"
                char* name = Include__make_string(include, spelling);
                #line 697 "src/analyzer/Include.pv"
                clang_disposeString(spelling);

                #line 699 "src/analyzer/Include.pv"
                CXType cx_type = clang_getCursorType(cursor);
                #line 700 "src/analyzer/Include.pv"
                struct Type ty = *Include__parse_type(include, cx_type);

                #line 702 "src/analyzer/Include.pv"
                HashMap_str_Type__insert(&class_info->values, (struct str){ .ptr = name, .length = strlen(name) }, ty);
            }
        } break;
        #line 705 "src/analyzer/Include.pv"
        case CXCursor_CXXMethod: {
            #line 706 "src/analyzer/Include.pv"
            CXString method_spelling = clang_getCursorSpelling(cursor);
            #line 707 "src/analyzer/Include.pv"
            char const* method_name = Include__make_string(include, method_spelling);
            #line 708 "src/analyzer/Include.pv"
            clang_disposeString(method_spelling);

            #line 710 "src/analyzer/Include.pv"
            CXType return_type = clang_getCursorResultType(cursor);
            #line 711 "src/analyzer/Include.pv"
            struct Type* return_type_resolved = Include__parse_type(include, return_type);

            #line 713 "src/analyzer/Include.pv"
            struct Function func_info = Function__new_allocator((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator });
            #line 714 "src/analyzer/Include.pv"
            func_info.name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = method_name, .length = strlen(method_name) } });
            #line 715 "src/analyzer/Include.pv"
            func_info.return_type = *return_type_resolved;
            #line 716 "src/analyzer/Include.pv"
            func_info.type = FUNCTION_TYPE__METHOD_CPP;

            #line 718 "src/analyzer/Include.pv"
            struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(allocator, func_info), ._1 = 0} };
            #line 719 "src/analyzer/Include.pv"
            HashMap_str_Type__insert(&class_info->fields, (struct str){ .ptr = method_name, .length = strlen(method_name) }, func_type);
        } break;
        #line 725 "src/analyzer/Include.pv"
        default: {
        } break;
    }

    #line 728 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}

#line 731 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 732 "src/analyzer/Include.pv"
    struct IncludeObjectContext* self = client_data;
    #line 733 "src/analyzer/Include.pv"
    struct EnumC* enum_info = self->object;
    #line 734 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 736 "src/analyzer/Include.pv"
    if (kind == CXCursor_EnumConstantDecl) {
        #line 737 "src/analyzer/Include.pv"
        CXString value_spelling = clang_getCursorSpelling(cursor);
        #line 738 "src/analyzer/Include.pv"
        char const* value_name = Include__make_string(self->context->include, value_spelling);
        #line 739 "src/analyzer/Include.pv"
        clang_disposeString(value_spelling);

        #line 741 "src/analyzer/Include.pv"
        IncludeContext__add_enum_value(self->context, enum_info, value_name);
    }

    #line 744 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}
