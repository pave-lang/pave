#include <clang-c/Index.h>
#include <stdio.h>
#include <string.h>

#include <std/HashMap_str_EnumCValue.h>
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
#include <analyzer/EnumC.h>
#include <analyzer/ParentCpp.h>
#include <analyzer/IncludeObjectEnumClass.h>
#include <analyzer/TypedefC.h>
#include <analyzer/EnumCValue.h>

#include <analyzer/IncludeObjectContext.h>

#line 670 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_struct(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 671 "src/analyzer/Include.pv"
    struct IncludeObjectContext* self = client_data;
    #line 672 "src/analyzer/Include.pv"
    struct Include* include = self->context->include;
    #line 673 "src/analyzer/Include.pv"
    struct StructC* struct_info = self->object;
    #line 674 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 676 "src/analyzer/Include.pv"
    if (kind == CXCursor_FieldDecl) {
        #line 677 "src/analyzer/Include.pv"
        CXString field_spelling = clang_getCursorSpelling(cursor);
        #line 678 "src/analyzer/Include.pv"
        char const* field_name = Include__make_string(include, field_spelling);
        #line 679 "src/analyzer/Include.pv"
        clang_disposeString(field_spelling);

        #line 681 "src/analyzer/Include.pv"
        CXType field_cx_type = clang_getCursorType(cursor);
        #line 682 "src/analyzer/Include.pv"
        struct Type field_type = *Include__parse_type(include, field_cx_type);

        #line 684 "src/analyzer/Include.pv"
        HashMap_str_StructCField__insert(&struct_info->fields, (struct str){ .ptr = field_name, .length = strlen(field_name) }, (struct StructCField) { .name = (struct str){ .ptr = field_name, .length = strlen(field_name) }, .type = field_type });
    }

    #line 687 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}

#line 690 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_class(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 691 "src/analyzer/Include.pv"
    struct IncludeObjectContext* self = client_data;
    #line 692 "src/analyzer/Include.pv"
    struct Include* include = self->context->include;
    #line 693 "src/analyzer/Include.pv"
    struct ClassCpp* class_info = self->object;
    #line 694 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);
    #line 695 "src/analyzer/Include.pv"
    struct ArenaAllocator* allocator = include->root->allocator;

    #line 697 "src/analyzer/Include.pv"
    switch (kind) {
        #line 698 "src/analyzer/Include.pv"
        case CXCursor_CXXBaseSpecifier: {
            #line 699 "src/analyzer/Include.pv"
            CXType base_cx_type = clang_getCursorType(cursor);
            #line 700 "src/analyzer/Include.pv"
            struct Type* base_type = Include__parse_type(include, base_cx_type);
            #line 701 "src/analyzer/Include.pv"
            if (base_type != 0) {
                #line 701 "src/analyzer/Include.pv"
                Array_Type__append(&class_info->bases, *base_type);
            }
        } break;
        #line 703 "src/analyzer/Include.pv"
        case CXCursor_FieldDecl: {
            #line 704 "src/analyzer/Include.pv"
            CXString field_spelling = clang_getCursorSpelling(cursor);
            #line 705 "src/analyzer/Include.pv"
            char const* field_name = Include__make_string(include, field_spelling);
            #line 706 "src/analyzer/Include.pv"
            clang_disposeString(field_spelling);

            #line 708 "src/analyzer/Include.pv"
            CXType field_cx_type = clang_getCursorType(cursor);
            #line 709 "src/analyzer/Include.pv"
            struct Type field_type = *Include__parse_type(include, field_cx_type);

            #line 711 "src/analyzer/Include.pv"
            HashMap_str_Type__insert(&class_info->fields, (struct str){ .ptr = field_name, .length = strlen(field_name) }, field_type);
        } break;
        #line 713 "src/analyzer/Include.pv"
        case CXCursor_VarDecl: {
            #line 714 "src/analyzer/Include.pv"
            enum CX_StorageClass storage = clang_Cursor_getStorageClass(cursor);
            #line 715 "src/analyzer/Include.pv"
            if (storage == CX_SC_Static) {
                #line 716 "src/analyzer/Include.pv"
                CXString spelling = clang_getCursorSpelling(cursor);
                #line 717 "src/analyzer/Include.pv"
                char* name = Include__make_string(include, spelling);
                #line 718 "src/analyzer/Include.pv"
                clang_disposeString(spelling);

                #line 720 "src/analyzer/Include.pv"
                CXType cx_type = clang_getCursorType(cursor);
                #line 721 "src/analyzer/Include.pv"
                struct Type ty = *Include__parse_type(include, cx_type);

                #line 723 "src/analyzer/Include.pv"
                HashMap_str_Type__insert(&class_info->values, (struct str){ .ptr = name, .length = strlen(name) }, ty);
            }
        } break;
        #line 726 "src/analyzer/Include.pv"
        case CXCursor_CXXMethod: {
            #line 727 "src/analyzer/Include.pv"
            CXString method_spelling = clang_getCursorSpelling(cursor);
            #line 728 "src/analyzer/Include.pv"
            char const* method_name = Include__make_string(include, method_spelling);
            #line 729 "src/analyzer/Include.pv"
            clang_disposeString(method_spelling);

            #line 731 "src/analyzer/Include.pv"
            CXType return_type = clang_getCursorResultType(cursor);
            #line 732 "src/analyzer/Include.pv"
            struct Type* return_type_resolved = Include__parse_type(include, return_type);

            #line 734 "src/analyzer/Include.pv"
            struct Function func_info = Function__new_allocator((struct Allocator) { .vtable = &ARENA_ALLOCATOR__VTABLE__ALLOCATOR, .instance = include->root->allocator });
            #line 735 "src/analyzer/Include.pv"
            func_info.name = ArenaAllocator__store_Token(allocator, (struct Token) { .value = (struct str){ .ptr = method_name, .length = strlen(method_name) } });
            #line 736 "src/analyzer/Include.pv"
            func_info.return_type = *return_type_resolved;
            #line 737 "src/analyzer/Include.pv"
            func_info.type = FUNCTION_TYPE__METHOD_CPP;

            #line 739 "src/analyzer/Include.pv"
            struct Type func_type = (struct Type) { .type = TYPE__FUNCTION, .function_value = { ._0 = ArenaAllocator__store_Function(allocator, func_info), ._1 = 0} };
            #line 740 "src/analyzer/Include.pv"
            HashMap_str_Type__insert(&class_info->fields, (struct str){ .ptr = method_name, .length = strlen(method_name) }, func_type);
        } break;
        #line 742 "src/analyzer/Include.pv"
        case CXCursor_EnumDecl: {
            #line 743 "src/analyzer/Include.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 744 "src/analyzer/Include.pv"
            char* name = Include__make_string(include, spelling);
            #line 745 "src/analyzer/Include.pv"
            clang_disposeString(spelling);

            #line 747 "src/analyzer/Include.pv"
            struct EnumC* enum_info = EnumC__new(include, name, (struct ParentCpp) { .type = PARENT_CPP__CLASS, .class_value = class_info });
            #line 748 "src/analyzer/Include.pv"
            HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = enum_info });

            #line 750 "src/analyzer/Include.pv"
            clang_visitChildren(cursor, IncludeObjectContext__visitor_enum_into_class, &(struct IncludeObjectContext) {
                .context = self->context,
                .object = &(struct IncludeObjectEnumClass) { .enum_info = enum_info, .class_info = class_info },
            });
        } break;
        #line 755 "src/analyzer/Include.pv"
        case CXCursor_StructDecl: {
            #line 756 "src/analyzer/Include.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 757 "src/analyzer/Include.pv"
            char* name = Include__make_string(include, spelling);
            #line 758 "src/analyzer/Include.pv"
            clang_disposeString(spelling);

            #line 760 "src/analyzer/Include.pv"
            if (strlen(name) == 0) {
                #line 761 "src/analyzer/Include.pv"
                ArenaAllocator__Allocator__free(include->root->allocator, name);
                #line 762 "src/analyzer/Include.pv"
                return CXChildVisit_Continue;
            }

            #line 765 "src/analyzer/Include.pv"
            struct Type* existing = HashMap_str_Type__find(&class_info->types, &(struct str){ .ptr = name, .length = strlen(name) });
            #line 766 "src/analyzer/Include.pv"
            if (existing == 0) {
                #line 767 "src/analyzer/Include.pv"
                struct ClassCpp* nested_class = ClassCpp__new(include, name, (struct ParentCpp) { .type = PARENT_CPP__CLASS, .class_value = class_info }, kind == CXCursor_StructDecl);
                #line 768 "src/analyzer/Include.pv"
                HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = nested_class });

                #line 770 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                    .context = self->context,
                    .object = nested_class,
                });
            }
        } break;
        #line 776 "src/analyzer/Include.pv"
        case CXCursor_ClassDecl: {
            #line 777 "src/analyzer/Include.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 778 "src/analyzer/Include.pv"
            char* name = Include__make_string(include, spelling);
            #line 779 "src/analyzer/Include.pv"
            clang_disposeString(spelling);

            #line 781 "src/analyzer/Include.pv"
            if (strlen(name) == 0) {
                #line 782 "src/analyzer/Include.pv"
                ArenaAllocator__Allocator__free(include->root->allocator, name);
                #line 783 "src/analyzer/Include.pv"
                return CXChildVisit_Continue;
            }

            #line 786 "src/analyzer/Include.pv"
            struct Type* existing = HashMap_str_Type__find(&class_info->types, &(struct str){ .ptr = name, .length = strlen(name) });
            #line 787 "src/analyzer/Include.pv"
            if (existing == 0) {
                #line 788 "src/analyzer/Include.pv"
                struct ClassCpp* nested_class = ClassCpp__new(include, name, (struct ParentCpp) { .type = PARENT_CPP__CLASS, .class_value = class_info }, kind == CXCursor_StructDecl);
                #line 789 "src/analyzer/Include.pv"
                HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__CLASS_CPP, .classcpp_value = nested_class });

                #line 791 "src/analyzer/Include.pv"
                clang_visitChildren(cursor, IncludeObjectContext__visitor_class, &(struct IncludeObjectContext) {
                    .context = self->context,
                    .object = nested_class,
                });
            }
        } break;
        #line 797 "src/analyzer/Include.pv"
        case CXCursor_TypedefDecl: {
            #line 798 "src/analyzer/Include.pv"
            CXString spelling = clang_getCursorSpelling(cursor);
            #line 799 "src/analyzer/Include.pv"
            char* name = Include__make_string(include, spelling);
            #line 800 "src/analyzer/Include.pv"
            clang_disposeString(spelling);

            #line 802 "src/analyzer/Include.pv"
            if (HashMap_str_Type__find(&class_info->types, &(struct str){ .ptr = name, .length = strlen(name) }) == 0) {
                #line 803 "src/analyzer/Include.pv"
                CXType underlying_type = clang_getTypedefDeclUnderlyingType(cursor);
                #line 804 "src/analyzer/Include.pv"
                struct Type* resolved = Include__parse_type(include, underlying_type);

                #line 806 "src/analyzer/Include.pv"
                if (resolved != 0) {
                    #line 807 "src/analyzer/Include.pv"
                    struct TypedefC* typedef_ = TypedefC__new(include, name, resolved);
                    #line 808 "src/analyzer/Include.pv"
                    HashMap_str_Type__insert(&class_info->types, (struct str){ .ptr = name, .length = strlen(name) }, (struct Type) { .type = TYPE__TYPEDEF_C, .typedefc_value = typedef_ });
                } else {
                    #line 810 "src/analyzer/Include.pv"
                    ArenaAllocator__Allocator__free(include->root->allocator, name);
                }
            } else {
                #line 813 "src/analyzer/Include.pv"
                ArenaAllocator__Allocator__free(include->root->allocator, name);
            }
        } break;
        #line 816 "src/analyzer/Include.pv"
        default: {
        } break;
    }

    #line 819 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}

#line 822 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 823 "src/analyzer/Include.pv"
    struct IncludeObjectContext* self = client_data;
    #line 824 "src/analyzer/Include.pv"
    struct EnumC* enum_info = self->object;
    #line 825 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 827 "src/analyzer/Include.pv"
    if (kind == CXCursor_EnumConstantDecl) {
        #line 828 "src/analyzer/Include.pv"
        CXString value_spelling = clang_getCursorSpelling(cursor);
        #line 829 "src/analyzer/Include.pv"
        char* value_name = Include__make_string(self->context->include, value_spelling);
        #line 830 "src/analyzer/Include.pv"
        clang_disposeString(value_spelling);

        #line 832 "src/analyzer/Include.pv"
        IncludeContext__add_enum_value(self->context, enum_info, value_name);
    }

    #line 835 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}

#line 838 "src/analyzer/Include.pv"
enum CXChildVisitResult IncludeObjectContext__visitor_enum_into_class(CXCursor cursor, CXCursor parent, CXClientData client_data) {
    #line 839 "src/analyzer/Include.pv"
    struct IncludeObjectContext* self = client_data;
    #line 840 "src/analyzer/Include.pv"
    struct IncludeObjectEnumClass* payload = self->object;
    #line 841 "src/analyzer/Include.pv"
    struct Include* include = self->context->include;
    #line 842 "src/analyzer/Include.pv"
    enum CXCursorKind kind = clang_getCursorKind(cursor);

    #line 844 "src/analyzer/Include.pv"
    if (kind == CXCursor_EnumConstantDecl) {
        #line 845 "src/analyzer/Include.pv"
        CXString value_spelling = clang_getCursorSpelling(cursor);
        #line 846 "src/analyzer/Include.pv"
        struct str value_name = Include__make_str(include, value_spelling);
        #line 847 "src/analyzer/Include.pv"
        clang_disposeString(value_spelling);

        #line 849 "src/analyzer/Include.pv"
        HashMap_str_EnumCValue__insert(&payload->enum_info->values, value_name, (struct EnumCValue) { .parent = payload->enum_info, .name = value_name });
        #line 850 "src/analyzer/Include.pv"
        HashMap_str_Type__insert(&payload->class_info->values, value_name, (struct Type) { .type = TYPE__ENUM_C, .enumc_value = payload->enum_info });
    }

    #line 853 "src/analyzer/Include.pv"
    return CXChildVisit_Continue;
}
